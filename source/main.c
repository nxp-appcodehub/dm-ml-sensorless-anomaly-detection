/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_smartdma.h"
#include "fsl_inputmux_connections.h"
#include "fsl_inputmux.h"
#include "gui_events.h"

#include "mc_periph_init.h"
#include "freemaster.h"
#include "freemaster_serial_lpuart.h"
#include "peripherals.h"
#include "fsl_lpuart.h"
#include "fsl_device_registers.h"
#include "m1_sm_snsless_enc.h"
#include "clock_config.h"
#include "mid_sm_states.h"
#include "ml_universal_datalogger.h"

#include "events_init.h"
#include "TimeSeries.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define ENABLE_MLUD 0
#define ML_SAMPLES_PER_CHANNEL  1
#define ML_SAMPLE_STEP 200 // How many Fast loop iterations before taking another sample
#define ML_NUM_CHANNELS 2 // How many Fast loop iterations before taking another sample

/* Update frequencies for 1 kHz Timer cycle */
#define GUI_UPDATE_FREQ 500
#define GUI_TRAIN_STEP_FREQ 1
#define GUI_PREDICT_FREQ 500

#define I2C_RELEASE_SDA_PORT  PORT4
#define I2C_RELEASE_SCL_PORT  PORT4
#define I2C_RELEASE_SDA_GPIO  GPIO4
#define I2C_RELEASE_SDA_PIN   0U
#define I2C_RELEASE_SCL_GPIO  GPIO4
#define I2C_RELEASE_SCL_PIN   1U
#define I2C_RELEASE_BUS_COUNT 100U
/* 1 ms per tick. */
#ifndef LVGL_TICK_MS
#define LVGL_TICK_MS 1U
#endif

/* lv_task_handler is called every 5-tick. */
#ifndef LVGL_TASK_PERIOD_TICK
#define LVGL_TASK_PERIOD_TICK 5U
#endif

/* Version info */
#define MCRSP_VER "2.0.0" /* motor control package version */

/* Example's feature set in form of bits inside ui16featureSet.
   This feature set is expected to be growing over time.
   ... | FEATURE_S_RAMP | FEATURE_FIELD_WEAKENING | FEATURE_ENC
*/
#define FEATURE_ENC (1)               /* Encoder feature flag */
#define FEATURE_FIELD_WEAKENING (0)   /* Field weakening feature flag */
#define FEATURE_S_RAMP (0)            /* S-ramp feature flag */

#define FEATURE_SET (FEATURE_ENC << (0) | \
                     FEATURE_FIELD_WEAKENING << (1) | \
                     FEATURE_S_RAMP << (2))

#define BOARD_USER_BUTTON_PRIORITY 4

/* Three instruction added after interrupt flag clearing as required */
#define M1_END_OF_ISR \
    {                 \
        __DSB();      \
        __ISB();      \
    }

/* CPU load measurement SysTick START / STOP macros */
#define SYSTICK_START_COUNT() (SysTick->VAL = SysTick->LOAD)
#define SYSTICK_STOP_COUNT(par1)   \
    uint32_t val  = SysTick->VAL;  \
    uint32_t load = SysTick->LOAD; \
    par1          = load - val

/*******************************************************************************
 * Variables
 ******************************************************************************/
lv_ui guider_ui;
static volatile uint32_t s_tick        = 0U;
static volatile bool s_lvglTaskPending = false;
static volatile bool guiUpdateFlag = false;
static volatile bool guiTrainStepFlag = false;
static volatile bool guiPredictFlag = false;
static volatile uint32_t guiUpdateCounter = 0;
static volatile uint32_t guiPredictCounter = 0;
static volatile uint32_t guiTrainStepCounter = 0;
static volatile int sentValues = 0;
static volatile int skip = 0;

volatile float ml_channels[2*ML_SAMPLES_PER_CHANNEL] = {};
volatile uint32_t ml_samples_ready = 0;
volatile uint32_t ml_samples_counter = 0;
volatile bool ml_samples_ready_flag = false;

int ml_samples_per_channel = ML_SAMPLES_PER_CHANNEL;

/* CPU load measurement using Systick */
uint32_t g_ui32NumberOfCycles    = 0U;
uint32_t g_ui32MaxNumberOfCycles = 0U;

/* Used for demo mode */
static uint32_t ui32SpeedStimulatorCnt    = 0U;
static uint32_t ui32PositionStimulatorCnt = 0U;

/* Structure used in FM to get required ID's */
app_ver_t g_sAppIdFM = {
    "../boards/frdmmcxn947/mc_pmsm/pmsm_enc",                       /* User Path 1- the highest priority */
    "../../../boards/frdmmcxn947/demo_apps/mc_pmsm/pmsm_enc/cm33_core0",       /* User Path 2 */
    "frdmmcxn947", /* board id */
    "pmsm_enc", /* example id */
    MCRSP_VER,      /* sw version */
    FEATURE_SET,    /* example's feature-set */
};

mid_app_cmd_t g_eMidCmd;                  /* Start/Stop MID command */
ctrl_m1_mid_t g_sSpinMidSwitch;           /* Control Spin/MID switching */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_SetupTick(void);

static void BOARD_Init(void);
static void BOARD_InitSysTick(void);
static void Application_Control_BL(void);
static void BOARD_InitGPIO(void);
static void init_freemaster_lpuart(void);
void BOARD_I2C_ReleaseBus(void);
static void BOARD_InitSmartDMA(void);
static void i2c_release_bus_delay(void);
void BOARD_I2C_ReleaseBus(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

int main(void)
{
	if (ENABLE_MLUD){
		ml_samples_per_channel = ML_SAMPLES_PER_CHANNEL;
	}

    /*Accessing ID structure to prevent optimization*/
    g_sAppIdFM.ui16FeatureSet = FEATURE_SET;

    uint32_t ui32PrimaskReg;

    /* Disable all interrupts before peripherals are initialized */
    ui32PrimaskReg = DisableGlobalIRQ();

    /* Disable demo mode after reset */
    ui32SpeedStimulatorCnt = 0U;
    
    /* Init board hardware. */
    BOARD_Init();
    
    /* FreeMASTER communication layer initialization */
    init_freemaster_lpuart();
    
    /* FreeMASTER initialization */
    FMSTR_Init();

    /* Initialize peripheral motor control driver for motor M1 */
    MCDRV_Init_M1();

    /* Initialize RTCESL PQ */
    RTCESL_PQ_Init();

    /* SysTick initialization for CPU load measurement */
    BOARD_InitSysTick();

    /* Turn off application */
    M1_SetAppSwitch(FALSE);

    /* Init application state - Spin or MID */
    g_sSpinMidSwitch.eAppState = kAppStateMID;

    if(g_sSpinMidSwitch.eAppState == kAppStateMID)
    {
      MID_Init_AR();
    }

    /* Spin state machine is default */
    g_sSpinMidSwitch.eAppState = kAppStateSpin;


    /* Enable interrupts  */
    EnableGlobalIRQ(ui32PrimaskReg);

    /* Init board hardware. */

	/* Init smartdma. */
	BOARD_InitSmartDMA();
	DEMO_SetupTick();

	/* Init LVGL */
	lv_port_pre_init();
	lv_init();

	/* Init Display and Touchscreen */
	lv_port_disp_init();
	lv_port_indev_init();

	/* Setup GUI elements */
	setup_ui(&guider_ui);
	events_init(&guider_ui);
	custom_init(&guider_ui);

	InitGuiUpdate();

    /* Start PWM */
    g_sM1Pwm3ph.pui32PwmBaseAddress->MCTRL |= PWM_MCTRL_RUN(0xF);

    /* Initialize Datalogger */
    MLUD_Initialize(ML_READ_BUFFER_TOTAL_SIZE);

    /* Infinite loop */
    while (1)
    {
    	if (s_lvglTaskPending)
    	{
    		s_lvglTaskPending = false;
    		lv_task_handler();
    	}
        Application_Control_BL();

        /* FreeMASTER Polling function */
        FMSTR_Poll();
        if (guiUpdateFlag){
        	guiUpdateFlag = false;
            GuiUpdateQuantities();
        }

        /* Go through a single train step */
        /* Cycle len is defined by GUI_TRAIN_STEP_FREQ*/
        if (guiTrainStepFlag){
			guiTrainStepFlag = false;
			GuiStepTrain(ml_channels, &ml_samples_ready_flag);
		}

        /* Do a model prediction */
		/* Cycle len is defined by GUI_PREDICT_FREQ*/
		if (guiPredictFlag)
		{
			guiPredictFlag = false;
			GuiProcessModel(ml_channels, &ml_samples_ready_flag);
		}

		if (ENABLE_MLUD){
			GuiResetFlag(&ml_samples_ready_flag);
		}

    }
}

/*!
 * @brief   This runs at 1 kHz frequency as defined in gui_events.c InitGuiUpdate
 *
 * @param   void
 *
 * @return  none
 */
void CTIMER1_IRQHandler(void)
{
	if (guiUpdateCounter > GUI_UPDATE_FREQ)
	{
		guiUpdateFlag = true;
		guiUpdateCounter = 0;
	}

	if (guiTrainStepCounter > GUI_TRAIN_STEP_FREQ)
	{
		guiTrainStepFlag = true;
		guiTrainStepCounter = 0;
	}

	if (guiPredictCounter > GUI_PREDICT_FREQ)
	{
		guiPredictFlag = true;
		guiPredictCounter = 0;
	}

	/* Increment counters */
    guiUpdateCounter++;
    guiTrainStepCounter++;
    guiPredictCounter++;

    /* Clear the match interrupt flag. */
    CTIMER1->IR |= CTIMER_IR_MR0INT(1U);

    /* Add empty instructions for correct interrupt flag clearing */
    __DSB();
	__ISB();
}

/*!
 * @brief   ADC ISR called with 100us period processes
 *           - motor M1 fast application machine function
 *           - demo mode if enabled
 *
 * @param   void
 *
 * @return  none
 */
void ADC1_IRQHandler(void)
{
    uint32_t ui32PrimaskReg;

    /* Disable all interrupts before peripherals are initialized */
    ui32PrimaskReg = DisableGlobalIRQ();

    switch(g_sSpinMidSwitch.eAppState)
    {
    case kAppStateSpin:
        /* M1 state machine */
        SM_StateMachineFast(&g_sM1Ctrl);
      break;
    default:
        /* MID state machine */
        MID_ProcessFast_FL();
      break;
    }


    if(!ml_samples_ready_flag){
		if (ml_samples_ready < ML_SAMPLES_PER_CHANNEL){
			if (ml_samples_counter > ML_SAMPLE_STEP){
				ml_samples_counter = 0;
				ml_channels[ml_samples_ready*ML_NUM_CHANNELS+0] = g_sM1Drive.sFocPMSM.sIDQ.fltQ;
				ml_channels[ml_samples_ready*ML_NUM_CHANNELS+1] = g_sM1Drive.sSpeed.fltSpeedFilt / g_fltM1speedAngularScale;
				ml_samples_ready++;
				/* Process MLUD sampling */
				if (ENABLE_MLUD){
					MLUD_HandleSamplingEvent();
				}
			}
			else{
				ml_samples_counter++;
			}
		}
		else{
			ml_samples_ready_flag = true;
			ml_samples_ready = 0;
		}
    }

    /* Enable interrupts  */
    EnableGlobalIRQ(ui32PrimaskReg);

    /* Call FreeMASTER recorder */
    FMSTR_Recorder(0);

    /* Clear the TCOMP INT flag */
    ADC1->STAT |= (uint32_t)(1U << 9);

    /* Add empty instructions for correct interrupt flag clearing */
    M1_END_OF_ISR;
}


/*!
 * @brief   Slow loop interrupt handler (1ms period)
 *           - motor M1 slow application machine function
 *
 * @param   void
 *
 * @return  none
 */
void CTIMER0_IRQHandler(void)
{
    static int16_t ui16i = 0;

    /* M1 Slow StateMachine call */
    SM_StateMachineSlow(&g_sM1Ctrl);

    /* If in STOP state turn on RED */
    if (M1_GetAppState() == 2)
    {
        LED_RED_ON();
        LED_GREEN_OFF();
    }

    /* If in FAULT state RED blinking*/
    else if (M1_GetAppState() == 0)
    {
        if (ui16i-- < 0)
        {
            LED_RED_TOGGLE();
            ui16i = 125;
        }
        LED_GREEN_OFF();
    }

    /* If in RUN or INIT state turn on green */
    else
    {
        LED_RED_OFF();
        LED_GREEN_ON();
    }

    /* Call FreeMASTER recorder */
    FMSTR_Recorder(0);

    /* Clear the match interrupt flag. */
    CTIMER0->IR |= CTIMER_IR_MR0INT(1U);

    /* Add empty instructions for correct interrupt flag clearing */
    M1_END_OF_ISR;
}

/*!
 * @brief   Application_Control_BL
 *           - Control switching between Spin and MID
 *
 * @param   void
 *
 * @return  none
 */
static void Application_Control_BL(void)
{
  switch(g_sSpinMidSwitch.eAppState)
  {
    case kAppStateSpin:
        /* M1 state machine */
        if(g_sSpinMidSwitch.bCmdRunMid == TRUE)
        {
          if((kSM_AppStop == M1_GetAppState()) && (FALSE == M1_GetAppSwitch()) )
          {
            MID_Init_AR();
            g_sSpinMidSwitch.sFaultCtrlM1_Mid &= ~(FAULT_APP_SPIN);
            g_eMidCmd = kMID_Cmd_Stop;                          /* Reset MID control command */
            g_sSpinMidSwitch.eAppState = kAppStateMID;          /* MID routines will be processed */
          }
          else
            g_sSpinMidSwitch.sFaultCtrlM1_Mid |= FAULT_APP_SPIN;

          g_sSpinMidSwitch.bCmdRunMid = FALSE;                  /* Always clear request */
        }

        g_sSpinMidSwitch.bCmdRunM1 = FALSE;
        break;
    default:
        /* MID state machine */
        if(g_sSpinMidSwitch.bCmdRunM1 == TRUE)
        {
          if((g_eMidCmd == kMID_Cmd_Stop) && (kMID_Stop == MID_GetActualState()))
          {
            g_sSpinMidSwitch.sFaultCtrlM1_Mid &= ~(FAULT_APP_MID);
            g_sM1Ctrl.eState = kSM_AppInit;                      /* Set Init state for M1 state machine */
            g_sSpinMidSwitch.eAppState = kAppStateSpin;          /* Switch application state to Spin */
          }
          else
            g_sSpinMidSwitch.sFaultCtrlM1_Mid |= FAULT_APP_MID;

           /* Always clear request */
          g_sSpinMidSwitch.bCmdRunM1 = FALSE;
          g_sSpinMidSwitch.bCmdRunMid = FALSE;
          break;
        }

        g_sSpinMidSwitch.bCmdRunMid = FALSE;
        MID_Process_BL(&g_eMidCmd);
        break;
  }
}

/*!
 *@brief      SysTick initialization for CPU cycle measurement
 */
static void BOARD_InitSysTick(void)
{
    /* Initialize SysTick core timer to run free */
    /* Set period to maximum value 2^24*/
    SysTick->LOAD = 0xFFFFFF;

    /*Clock source - System Clock*/
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

    /*Start Sys Timer*/
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/*!
 * @brief LPUART Module initialization (LPUART is a the standard block included e.g. in K66F)
 */
static void init_freemaster_lpuart(void)
{
    lpuart_config_t config;

    /*
     * config.baudRate_Bps = 115200U;
     * config.parityMode = kUART_ParityDisabled;
     * config.stopBitCount = kUART_OneStopBit;
     * config.txFifoWatermark = 0;
     * config.rxFifoWatermark = 1;
     * config.enableTx = false;
     * config.enableRx = false;
     */
    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = 115200U;
    config.enableTx     = false;
    config.enableRx     = false;

    LPUART_Init((LPUART_Type *)BOARD_DEBUG_UART_BASEADDR, &config, BOARD_DEBUG_UART_CLK_FREQ);

    /* Register communication module used by FreeMASTER driver. */
    FMSTR_SerialSetBaseAddress((LPUART_Type *)BOARD_DEBUG_UART_BASEADDR);
}

/*!
 *@brief      Initialization of the Clocks and Pins
 *
 *@param      none
 *
 *@return     none
 */
static void BOARD_Init(void)
{
    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

	/* attach FRO 12M to FLEXCOMM2 */
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);
	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);

	CLOCK_SetClkDiv(kCLOCK_DivFlexioClk, 1u);
	CLOCK_AttachClk(kPLL0_to_FLEXIO);

    /* Initialize clock configuration */
    BOARD_InitBootClocks();
	BOARD_I2C_ReleaseBus();
    /* Init pins set in pin_mux file */
    BOARD_InitBootPins();
    /* Init GPIO pins */
    BOARD_InitGPIO();

	BOARD_InitDebugConsole();
}

/*!
 * @brief   static void BOARD_InitGPIO(void)
 *           - Initialization of the GPIO peripherals
 *
 * @param   void
 *
 * @return  none
 */
static void BOARD_InitGPIO(void)
{
    /* Define the init structure for the input switch pin */
    gpio_pin_config_t sw_config = {
        kGPIO_DigitalInput,
        0,
    };

    /* Define the init structure for the output LED pin */
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };

    /* enable clock for GPIO*/
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio3);

    /* Init input switch GPIO. */
    GPIO_SetPinInterruptConfig(GPIO0, 6U, kGPIO_InterruptFallingEdge);
    GPIO_PinInit(GPIO0, 6U, &sw_config);

    /* Init output LED GPIO. */
    GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &led_config);
    GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &led_config);
    GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &led_config);

    /* Enable GPIO pin interrupt for SW3 button */
    EnableIRQ(GPIO00_IRQn);
    NVIC_SetPriority(GPIO00_IRQn, BOARD_USER_BUTTON_PRIORITY);

}

static void DEMO_SetupTick(void)
{
    if (0 != SysTick_Config(SystemCoreClock / (LVGL_TICK_MS * 1000U)))
    {
        PRINTF("Tick initialization failed\r\n");
        while (1)
            ;
    }
}

void SysTick_Handler(void)
{
    s_tick++;
    lv_tick_inc(LVGL_TICK_MS);

    if ((s_tick % LVGL_TASK_PERIOD_TICK) == 0U)
    {
        s_lvglTaskPending = true;
    }
}

static void BOARD_InitSmartDMA(void)
{
    RESET_ClearPeripheralReset(kMUX_RST_SHIFT_RSTn);

    INPUTMUX_Init(INPUTMUX0);
    INPUTMUX_AttachSignal(INPUTMUX0, 0, kINPUTMUX_FlexioToSmartDma);

    /* Turnoff clock to inputmux to save power. Clock is only needed to make changes */
    INPUTMUX_Deinit(INPUTMUX0);

    SMARTDMA_InitWithoutFirmware();

    NVIC_EnableIRQ(SMARTDMA_IRQn);
    NVIC_SetPriority(SMARTDMA_IRQn, 3);
}


static void i2c_release_bus_delay(void)
{
    SDK_DelayAtLeastUs(100U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

void BOARD_I2C_ReleaseBus(void)
{
    uint8_t i = 0;
    gpio_pin_config_t pin_config;
    port_pin_config_t i2c_pin_config = {0};

    /* Config pin mux as gpio */
    i2c_pin_config.pullSelect = kPORT_PullUp;
    i2c_pin_config.mux        = kPORT_MuxAsGpio;

    pin_config.pinDirection = kGPIO_DigitalOutput;
    pin_config.outputLogic  = 1U;
    CLOCK_EnableClock(kCLOCK_Port4);
    PORT_SetPinConfig(I2C_RELEASE_SCL_PORT, I2C_RELEASE_SCL_PIN, &i2c_pin_config);
    PORT_SetPinConfig(I2C_RELEASE_SCL_PORT, I2C_RELEASE_SDA_PIN, &i2c_pin_config);

    GPIO_PinInit(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, &pin_config);
    GPIO_PinInit(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, &pin_config);

    /* Drive SDA low first to simulate a start */
    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    /* Send 9 pulses on SCL and keep SDA high */
    for (i = 0; i < 9; i++)
    {
        GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
        i2c_release_bus_delay();

        GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
        i2c_release_bus_delay();

        GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
        i2c_release_bus_delay();
        i2c_release_bus_delay();
    }

    /* Send stop */
    GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 0U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SCL_GPIO, I2C_RELEASE_SCL_PIN, 1U);
    i2c_release_bus_delay();

    GPIO_PinWrite(I2C_RELEASE_SDA_GPIO, I2C_RELEASE_SDA_PIN, 1U);
    i2c_release_bus_delay();
}

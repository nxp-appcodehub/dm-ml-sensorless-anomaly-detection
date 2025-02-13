/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "gui_events.h"

#define GUI_UPDATE_FREQ 1000
#define LEARNING_SAMPLE_COUNT TSS_RECOMMEND_LEARNING_SAMPLE_NUM/8
#define MOTOR_SPEED_SCALE -400

// External Motor control and GUI variables
extern mcdef_pmsm_t g_sM1Drive;
extern lv_ui guider_ui;
extern tss_status status;
extern volatile float g_fltM1speedAngularScale;

// Motor status variables bounded to GUI
static bool evntMotorRunning = false;
static float evntMotorSpeed = 0;

// Text variables for physical quantities that will be printed to the GUI
static char textCurA[] = "000.00 A";
static char textCurB[] = "000.00 A";
static char textCurC[] = "000.00 A";
static char textSpeed[] = "000.00 RPM";
static char textDCBus[] = "000.00 V";

// ML status variables
static bool incrementalLearning = false;
static bool runTraining = false;
static tss_status ml_status;
static int trainProgress = 0;

// Prediction result containing anomality of the input (1 - normal, 0 - anomaly)
static float ml_normal_score;

// To ensure proper initialization of the model
static bool firstMLRun = true;

/*!
 * @brief   Initializes GUI flag update timer at 1 kHz
 *
 * @param   void
 *
 * @return  none
 */
void InitGuiUpdate(void)
{
    /* Use 96 MHz clock for some of the Ctimer0. */
    CLOCK_SetClkDiv(kCLOCK_DivCtimer1Clk, 1u);
    CLOCK_AttachClk(kFRO_HF_to_CTIMER1);

    /* Enable Timer1 clock. */
    SYSCON->AHBCLKCTRLSET[1] |= SYSCON_AHBCLKCTRL1_TIMER1_MASK;

    /* Enable Timer1 clock reset. */
    SYSCON->PRESETCTRLSET[1] = SYSCON_PRESETCTRL1_TIMER1_RST_MASK;             /* Set bit. */
    while (0u == (SYSCON->PRESETCTRL1 & SYSCON_PRESETCTRL1_TIMER1_RST_MASK))   /* Wait until it reads 0b1 */
    {
    }

    /* Clear Timer1 clock reset. */
    SYSCON->PRESETCTRLCLR[1] = SYSCON_PRESETCTRL1_TIMER1_RST_MASK;             /* Clear bit */
    while (SYSCON_PRESETCTRL1_TIMER1_RST_MASK ==                               /* Wait until it reads 0b0 */
          (SYSCON->PRESETCTRL1 & SYSCON_PRESETCTRL1_TIMER1_RST_MASK))
    {
    }

    /* Configure match control register. */
    CTIMER1->MCR |= CTIMER_MCR_MR0R(1U)  |   /* Enable reset of TC after it matches with MR0. */
                    CTIMER_MCR_MR0I(1U);     /* Enable interrupt generation after TC matches with MR0. */

    /* Configure match register. */
    CTIMER1->MR[0] = (CLOCK_GetFreq(kCLOCK_FroHf))  /* Get CTimer0 frequency for correct set Match register value. */
					  / GUI_UPDATE_FREQ;           /* Set slow control loop frequency in Hz. */

    /* Configure interrupt register. */
    CTIMER1->IR = CTIMER_IR_MR0INT_MASK;     /* Set interrupt flag for match channel 0. */
    NVIC_SetPriority(CTIMER1_IRQn, 1U);
    NVIC_EnableIRQ(CTIMER1_IRQn);            /* Enable LEVEL1 interrupt and update the call back function. */

    /* Configure timer control register. */
    CTIMER1->TCR |= CTIMER_TCR_CEN_MASK;     /* Start the timer counter. */
}

/*!
 * @brief   Initializes Anomaly Detection model
 *
 * @param   void
 *
 * @return  none
 */
void InitML(void){
	ml_status = tss_ad_init(NULL);
	if (status != TSS_SUCCESS)
	{
		/* Handle the initialization failure cases */
	}
}

/*!
 * @brief   Set motor speed
 *
 * @param   speed RPM value without angular scale applied
 *
 * @return  none
 */
void GuiMotorSpeed(float speed){
	// Save new desired speed
	evntMotorSpeed = speed;

	// If motor should run
	if(evntMotorRunning){
		// Set motor speed according to speed input val
		g_sM1Drive.sSpeed.fltSpeedCmd = evntMotorSpeed / g_fltM1speedAngularScale;
	}
	else{
		g_sM1Drive.sSpeed.fltSpeedCmd = 0.0F;
		// else set motor speed to 0
	}
}

/*!
 * @brief   Change running state of the motor
 *
 * @param   newState State the motor should be switched to.
 *
 * @return  none
 */
void GuiMotorToggle(bool newState){
	evntMotorRunning = newState;

	// Start the motor to desired speed
	GuiMotorSpeed(evntMotorSpeed);
}

/*!
 * @brief   Updates GUI elements for current physical quantities that are measured.
 *
 * @param   void
 *
 * @return  none
 */
void GuiUpdateQuantities(void){
	snprintf(textCurA, sizeof(textCurA)/sizeof(textCurA[0]), "%+.1f", g_sM1Drive.sFocPMSM.sIABC.fltA);
	snprintf(textCurB, sizeof(textCurB)/sizeof(textCurB[0]), "%+.1f", g_sM1Drive.sFocPMSM.sIABC.fltB);
	snprintf(textCurC, sizeof(textCurC)/sizeof(textCurC[0]), "%+.1f", g_sM1Drive.sFocPMSM.sIABC.fltC);
	snprintf(textSpeed, sizeof(textSpeed)/sizeof(textSpeed[0]), "%d RPM", (int)(-g_sM1Drive.sSpeed.fltSpeedFilt * g_fltM1speedAngularScale));
	snprintf(textDCBus, sizeof(textDCBus)/sizeof(textDCBus[0]), "%+.1f", g_sM1Drive.sFocPMSM.fltUDcBusFilt);

	lv_label_set_text_static(guider_ui.mainScr_label_ctrl_curA_val, textCurA);
	lv_label_set_text_static(guider_ui.mainScr_label_ctrl_curB_val, textCurB);
	lv_label_set_text_static(guider_ui.mainScr_label_ctrl_curC_val, textCurC);
	lv_label_set_text_static(guider_ui.mainScr_label_speed_current, textSpeed);
	lv_label_set_text_static(guider_ui.mainScr_label_ctrl_dcbus_val, textDCBus);
}

/*!
 * @brief   Setups model for training. Starts motor. Based on Incremental Learning GUI toggle setups incremental learning.
 *
 * @param   void
 *
 * @return  none
 */
void GuiStartTrain(void){
	// set training speed
	GuiMotorSpeed(MOTOR_SPEED_SCALE * lv_slider_get_value(guider_ui.mainScr_slider_train_speed));

	// start motor
	GuiMotorToggle(true);

	// if training should not be incremental -> reinitialize AD model
	if (!lv_obj_has_state(guider_ui.mainScr_sw_train_incremental, LV_STATE_CHECKED) || firstMLRun){
		ml_status = tss_ad_init(NULL);
		firstMLRun = false;
	}

	// reset progress bar
	lv_bar_set_range(guider_ui.mainScr_bar_train_progress, 0, LEARNING_SAMPLE_COUNT);
	lv_bar_set_value(guider_ui.mainScr_bar_train_progress, 0, LV_ANIM_OFF);
	trainProgress = 0;

	// set training flag (the training in itself will run in the main loop
	runTraining = true;
}

/*!
 * @brief   Processes a single train step. Checks if training should finish.
 *
 * @param   data_input array with input quantities
 * 			ready_flag flag signaling if data is ready to be processed
 *
 * @return  none
 */
void GuiStepTrain(volatile float data_input[], volatile bool *ready_flag)
{
	if (runTraining && *ready_flag)
	{
		trainProgress++;
		// add value to progress bar
		lv_bar_set_value(guider_ui.mainScr_bar_train_progress,
					trainProgress,
					LV_ANIM_ON);

		// Process one step of training
		ml_status = tss_ad_learn(data_input);
		if (ml_status != TSS_SUCCESS && ml_status != TSS_LEARNING_NOT_ENOUGH)
		{
			/* Handle the learning failure cases */
		}

		// if learning finished, stop it
		if (trainProgress >= LEARNING_SAMPLE_COUNT)
		{
			GuiStopTrain();
		}

		*ready_flag = false;
	}

}

/*!
 * @brief   Resets ready flag if both train and predict is off for MLUD
 *
 * @param   ready_flag flag signaling if data is ready to be processed
 *
 * @return  none
 */
void GuiResetFlag(volatile bool *ready_flag)
{
	if (!runTraining && !lv_obj_has_state(guider_ui.mainScr_sw_det_run_ml, LV_STATE_CHECKED))
	{
		*ready_flag = false;
	}
}

/*!
 * @brief   Processes training stop and GUI update
 *
 * @param   void
 *
 * @return  none
 */
void GuiStopTrain(void){
	lv_label_set_text(guider_ui.mainScr_btn_train_train_label, "Train");
	runTraining = false;
	GuiMotorToggle(false);
}

/*!
 * @brief   Processes flag change on GUI element switch
 *
 * @param   void
 *
 * @return  none
 */
void GuiIncrementalLearningToggle(void){
	if (incrementalLearning){
		incrementalLearning = false;
	}
	else{
		incrementalLearning = true;
	}
}

/*!
 * @brief   Processes GUI element refresh and state changes when changing screens. Also stops motor.
 *
 * @param   void
 *
 * @return  none
 */
void GuiScreenChange(void){
	GuiStopTrain();

	// Reset switch and slider states to initial values
	lv_obj_clear_state(guider_ui.mainScr_sw_ctrl_run_motor, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.mainScr_sw_det_run_ml, LV_STATE_CHECKED);
	lv_obj_clear_state(guider_ui.mainScr_sw_det_run_motor, LV_STATE_CHECKED);

	lv_slider_set_value(guider_ui.mainScr_slider_ctrl_speed, 0, LV_ANIM_OFF);
	lv_slider_set_value(guider_ui.mainScr_slider_det_speed, 0, LV_ANIM_OFF);
	lv_slider_set_value(guider_ui.mainScr_slider_train_speed, 0, LV_ANIM_OFF);

	// Stop motor
	evntMotorRunning = false;
	evntMotorSpeed = 0;

	// Reset labels to default values and colors
	lv_obj_set_style_bg_color(guider_ui.mainScr_bar_det_anomaly_score, lv_color_hex(0xb6bab7), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(guider_ui.mainScr_bar_det_anomaly_score, lv_color_hex(0xb6bab7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(guider_ui.mainScr_btn_det_classification, lv_color_hex(0xb6bab7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_label_set_text(guider_ui.mainScr_btn_det_classification_label, "Idle");
}

/*!
 * @brief   Does a single prediction on a model if prediction is enabled in the GUI
 *
 * @param   data_input array with input quantities
 * 			ready_flag flag signaling if data is ready to be processed
 *
 * @return  none
 */
void GuiProcessModel(volatile float data_input[], volatile bool *ready_flag){
	// Put current speed and current values to the input of the model
	if (lv_obj_has_state(guider_ui.mainScr_sw_det_run_ml, LV_STATE_CHECKED) && *ready_flag){

		ml_status = tss_ad_predict(data_input, &ml_normal_score);
		if (ml_status != TSS_SUCCESS)
		{
			/* Handle the prediction failure cases */
		}
		else
		{
			lv_bar_set_value(guider_ui.mainScr_bar_det_anomaly_score, (int)(ml_normal_score*100), LV_ANIM_OFF);

			// If score under threshold -> anomaly, else -> normal
			if (ml_normal_score < TSS_RECOMMEND_THRESHOLD){
				// Set colors to red and text to "ANOMALY"
				lv_obj_set_style_bg_color(guider_ui.mainScr_btn_det_classification, lv_color_hex(0xF54D4D), LV_PART_MAIN);
				lv_label_set_text(guider_ui.mainScr_btn_det_classification_label, "Anomaly");
				lv_obj_set_style_bg_color(guider_ui.mainScr_bar_det_anomaly_score, lv_color_hex(0xF54D4D), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.mainScr_bar_det_anomaly_score, lv_color_hex(0xF54D4D), LV_PART_INDICATOR|LV_STATE_DEFAULT);

			}
			else{
				// Set colors to green and text to "Normal"
				lv_obj_set_style_bg_color(guider_ui.mainScr_btn_det_classification, lv_color_hex(0x10bf1f), LV_PART_MAIN);
				lv_label_set_text(guider_ui.mainScr_btn_det_classification_label, "Normal");
				lv_obj_set_style_bg_color(guider_ui.mainScr_bar_det_anomaly_score, lv_color_hex(0x10bf1f), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.mainScr_bar_det_anomaly_score, lv_color_hex(0x10bf1f), LV_PART_INDICATOR|LV_STATE_DEFAULT);
			}
		}

		*ready_flag = false;
	}
}


/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <ml_universal_datalogger.h>

#define MLUD_STATUS_IDLE 		0
#define MLUD_STATUS_ENABLED 	1
#define MLUD_STATUS_RESET 		2

static uint8_t mlud_status = MLUD_STATUS_IDLE;
static uint32_t mlud_progressCurrent = 0;
static uint32_t mlud_progressTotal = 0;

// Buffer variables
float_t ml_xBuffer[ML_READ_BUFFER_TOTAL_SIZE] = {0};
frac16_t ml_yBuffer[ML_READ_BUFFER_TOTAL_SIZE] = {0};

// Scenario variables
uint32_t ml_bufferIndex = 0;

// Application specific variables
volatile ml_myAppStates_t ml_myAppState = 0;
volatile float_t ml_myAppSpeed = 0;
volatile uint32_t ml_myRequiredSpeed = 0;
volatile uint32_t ml_msTimer = 0;

void MLUD_Initialize(uint32_t progressTotal)
{
	// Make sure the variables are used (to appear in FreeMaster)
	mlud_status = MLUD_STATUS_IDLE;
	mlud_progressTotal = progressTotal;
}

void MLUD_HandleSamplingEvent(void)
{
	// Check for reset
	if(mlud_status == MLUD_STATUS_RESET)
	{
		// Clear progress
		mlud_progressCurrent = 0;

		// Reset all values
		MLUD_UserCleanUp();

		// Reset flag
		mlud_status = MLUD_STATUS_IDLE;
	}

	// Is enabled?
	if(mlud_status == MLUD_STATUS_ENABLED)
	{
		mlud_progressCurrent = MLUD_UserScenario();
		if(mlud_progressCurrent >= mlud_progressTotal)
		{
			mlud_status = MLUD_STATUS_IDLE;
		}
	}
}

uint32_t MLUD_UserScenario(void){
	// If APP is enabled
	if (ml_myAppState == ML_MYAPP_STATE_ON)
	{
		// If buffer is not full
		if(ml_bufferIndex < ML_READ_BUFFER_TOTAL_SIZE)
		{
			// Save data to buffers
			ml_xBuffer[ml_bufferIndex] = g_sM1Drive.sFocPMSM.sIDQ.fltQ;
			ml_yBuffer[ml_bufferIndex] = g_sM1Drive.sSpeed.fltSpeedFilt / g_fltM1speedAngularScale;

			// Increment buffer (and update progress)
			ml_bufferIndex++;
		}
	}

	// Return current progress value (in this case it is buffer size)
	return ml_bufferIndex;
}

void MLUD_UserCleanUp(void)
{
    // Clear buffer by setting index to zero
	ml_bufferIndex = 0;
}


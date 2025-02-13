/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef ML_UNIVERSAL_DATALOGGER_H_
#define ML_UNIVERSAL_DATALOGGER_H_

#include "mlib_FP.h"
#include "m1_sm_snsless_enc.h"


#if defined(__cplusplus)
extern "C" {
#endif

#define ML_READ_BUFFER_TOTAL_SIZE 2000

typedef enum {
	ML_MYAPP_STATE_OFF = 0,
	ML_MYAPP_STATE_ON,
	ML_MYAPP_STATE_FAULT
} ml_myAppStates_t;

// User scenario functions
extern void MLUD_UserCleanUp(void);
extern uint32_t MLUD_UserScenario(void);

// Internally handled functions
void MLUD_Initialize(uint32_t progressTotal);
void MLUD_HandleSamplingEvent(void);
uint32_t MLUD_UserScenario(void);
void MLUD_UserCleanUp(void);

#if defined(__cplusplus)
}
#endif

#endif /* ML_UNIVERSAL_DATALOGGER_H_ */

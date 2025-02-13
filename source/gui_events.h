/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef GUI_EVENTS_H_
#define GUI_EVENTS_H_

#include "sm_common.h"
#include "stdbool.h"
#include "lvgl.h"
#include "gui_guider.h"
#include <stdio.h>

#include "peripherals.h"
#include "fsl_common.h"

#include "TimeSeries.h"

/*!
 * @brief   Initializes GUI flag update timer at 1 kHz
 *
 * @param   void
 *
 * @return  none
 */
void InitGuiUpdate(void);

/*!
 * @brief   Initializes Anomaly Detection model
 *
 * @param   void
 *
 * @return  none
 */
void InitML(void);

/*!
 * @brief   Set motor speed
 *
 * @param   speed RPM value without angular scale applied
 *
 * @return  none
 */
void GuiMotorSpeed(float speed);

/*!
 * @brief   Change running state of the motor
 *
 * @param   newState State the motor should be switched to.
 *
 * @return  none
 */
void GuiMotorToggle(bool newState);

/*!
 * @brief   Updates GUI elements for current physical quantities that are measured.
 *
 * @param   void
 *
 * @return  none
 */
void GuiUpdateQuantities(void);

/*!
 * @brief   Setups model for training. Starts motor. Based on Incremental Learning GUI toggle setups incremental learning.
 *
 * @param   void
 *
 * @return  none
 */
void GuiStartTrain(void);

/*!
 * @brief   Processes a single train step. Checks if training should finish.
 *
 * @param   data_input array with input quantities
 * 			ready_flag flag signaling if data is ready to be processed
 *
 * @return  none
 */
void GuiStepTrain(volatile float data_input[], volatile bool *ready_flag);

/*!
 * @brief   Processes training stop and GUI update
 *
 * @param   void
 *
 * @return  none
 */
void GuiStopTrain(void);

/*!
 * @brief   Processes flag change on GUI element switch
 *
 * @param   void
 *
 * @return  none
 */
void GuiIncrementalLearningToggle(void);

/*!
 * @brief   Processes GUI element refresh and state changes when changing screens. Also stops motor.
 *
 * @param   void
 *
 * @return  none
 */
void GuiScreenChange(void);

/*!
 * @brief   Resets ready flag if both train and predict is off for MLUD
 *
 * @param   ready_flag flag signaling if data is ready to be processed
 *
 * @return  none
 */
void GuiResetFlag(volatile bool *ready_flag);

/*!
 * @brief   Does a single prediction on a model if prediction is enabled in the GUI
 *
 * @param   data_input array with input quantities
 * 			ready_flag flag signaling if data is ready to be processed
 *
 * @return  none
 */
void GuiProcessModel(volatile float data_input[], volatile bool *ready_flag);



#endif /* GUI_EVENTS_H_ */

/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#define MOTOR_SPEED_SCALE -400
#include "stdbool.h"
#include "gui_events.h"
#include "sm_common.h"

static void mainScr_btn_menu_train_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.mainScr_container_control, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.mainScr_container_train, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.mainScr_container_detect, LV_OBJ_FLAG_HIDDEN);
        GuiMotorToggle(false);
        GuiScreenChange();
        break;
    }
    default:
        break;
    }
}

static void mainScr_btn_menu_detect_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.mainScr_container_control, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.mainScr_container_train, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.mainScr_container_detect, LV_OBJ_FLAG_HIDDEN);
        GuiMotorToggle(false);
        GuiScreenChange();
        break;
    }
    default:
        break;
    }
}

static void mainScr_btn_menu_control_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.mainScr_container_train, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.mainScr_container_detect, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.mainScr_container_control, LV_OBJ_FLAG_HIDDEN);
        GuiMotorToggle(false);
        GuiScreenChange();
        break;
    }
    default:
        break;
    }
}

static void mainScr_slider_det_speed_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        GuiMotorSpeed(MOTOR_SPEED_SCALE * (float)lv_slider_get_value(guider_ui.mainScr_slider_det_speed));
        break;
    }
    default:
        break;
    }
}

static void mainScr_sw_det_run_motor_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? 1 : 0;
        GuiMotorToggle(lv_obj_has_state(guider_ui.mainScr_sw_det_run_motor, LV_STATE_CHECKED) ? true : false);
        break;
    }
    default:
        break;
    }
}

static void mainScr_btn_det_classification_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_set_style_bg_color(guider_ui.mainScr_btn_det_classification, lv_color_hex(0x000000), LV_PART_MAIN);
        break;
    }
    default:
        break;
    }
}

static void mainScr_btn_train_train_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (lv_label_get_text(lv_obj_get_child(guider_ui.mainScr_btn_train_train, NULL))[0] == 'S') {
            GuiStopTrain();
            lv_label_set_text(guider_ui.mainScr_btn_train_train_label, "Train");
        } else {
            lv_label_set_text(guider_ui.mainScr_btn_train_train_label, "Stop");
            GuiStartTrain();
        }
        break;
    }
    default:
        break;
    }
}

static void mainScr_slider_ctrl_speed_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        GuiMotorSpeed(MOTOR_SPEED_SCALE * (float)lv_slider_get_value(guider_ui.mainScr_slider_ctrl_speed));
        break;
    }
    default:
        break;
    }
}

static void mainScr_sw_ctrl_run_motor_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? 1 : 0;
        GuiMotorToggle(lv_obj_has_state(guider_ui.mainScr_sw_ctrl_run_motor, LV_STATE_CHECKED) ? true : false);
        break;
    }
    default:
        break;
    }
}

void events_init_mainScr (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->mainScr_btn_menu_train, mainScr_btn_menu_train_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_btn_menu_detect, mainScr_btn_menu_detect_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_btn_menu_control, mainScr_btn_menu_control_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_slider_det_speed, mainScr_slider_det_speed_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_sw_det_run_motor, mainScr_sw_det_run_motor_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_btn_det_classification, mainScr_btn_det_classification_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_btn_train_train, mainScr_btn_train_train_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_slider_ctrl_speed, mainScr_slider_ctrl_speed_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->mainScr_sw_ctrl_run_motor, mainScr_sw_ctrl_run_motor_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}

/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *mainScr;
	bool mainScr_del;
	lv_obj_t *mainScr_bckg_mid;
	lv_obj_t *mainScr_bckg_right;
	lv_obj_t *mainScr_bckg_left;
	lv_obj_t *mainScr_bckg_top;
	lv_obj_t *mainScr_bckg_bot;
	lv_obj_t *mainScr_container_menu;
	lv_obj_t *mainScr_btn_menu_train;
	lv_obj_t *mainScr_btn_menu_train_label;
	lv_obj_t *mainScr_btn_menu_detect;
	lv_obj_t *mainScr_btn_menu_detect_label;
	lv_obj_t *mainScr_btn_menu_control;
	lv_obj_t *mainScr_btn_menu_control_label;
	lv_obj_t *mainScr_label_1;
	lv_obj_t *mainScr_container_detect;
	lv_obj_t *mainScr_slider_det_speed;
	lv_obj_t *mainScr_sw_det_run_motor;
	lv_obj_t *mainScr_sw_det_run_ml;
	lv_obj_t *mainScr_bar_det_anomaly_score;
	lv_obj_t *mainScr_label_det_fan_status;
	lv_obj_t *mainScr_btn_det_classification;
	lv_obj_t *mainScr_btn_det_classification_label;
	lv_obj_t *mainScr_label_det_run_motor;
	lv_obj_t *mainScr_label_det_run_ml;
	lv_obj_t *mainScr_label_det_motor_speed;
	lv_obj_t *mainScr_container_train;
	lv_obj_t *mainScr_bar_train_progress;
	lv_obj_t *mainScr_slider_train_speed;
	lv_obj_t *mainScr_label_train_motor_speed;
	lv_obj_t *mainScr_btn_train_train;
	lv_obj_t *mainScr_btn_train_train_label;
	lv_obj_t *mainScr_label_train_training_progress;
	lv_obj_t *mainScr_sw_train_incremental;
	lv_obj_t *mainScr_label_train_incremental;
	lv_obj_t *mainScr_container_control;
	lv_obj_t *mainScr_slider_ctrl_speed;
	lv_obj_t *mainScr_sw_ctrl_run_motor;
	lv_obj_t *mainScr_label_ctrl_run_motor;
	lv_obj_t *mainScr_label_ctrl_motor_speed;
	lv_obj_t *mainScr_label_ctrl_curA;
	lv_obj_t *mainScr_label_ctrl_curB;
	lv_obj_t *mainScr_label_ctrl_curC;
	lv_obj_t *mainScr_label_ctrl_curC_val;
	lv_obj_t *mainScr_label_ctrl_curA_val;
	lv_obj_t *mainScr_label_ctrl_curB_val;
	lv_obj_t *mainScr_label_ctrl_dcbus;
	lv_obj_t *mainScr_label_ctrl_dcbus_val;
	lv_obj_t *mainScr_img_speed;
	lv_obj_t *mainScr_label_speed_current;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_mainScr(lv_ui *ui);
LV_IMG_DECLARE(_mid_alpha_460x9);
LV_IMG_DECLARE(_right_alpha_10x320);
LV_IMG_DECLARE(_left_alpha_10x320);
LV_IMG_DECLARE(_top_alpha_460x14);
LV_IMG_DECLARE(_bot_alpha_460x6);
LV_IMG_DECLARE(_Picture1_alpha_48x48);

LV_FONT_DECLARE(lv_font_montserratMedium_22)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)


#ifdef __cplusplus
}
#endif
#endif

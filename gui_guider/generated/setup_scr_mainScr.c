/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_mainScr(lv_ui *ui)
{
    //Write codes mainScr
    ui->mainScr = lv_obj_create(NULL);
    lv_obj_set_size(ui->mainScr, 480, 320);
    lv_obj_set_scrollbar_mode(ui->mainScr, LV_SCROLLBAR_MODE_OFF);

    //Write style for mainScr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_bckg_mid
    ui->mainScr_bckg_mid = lv_img_create(ui->mainScr);
    lv_obj_add_flag(ui->mainScr_bckg_mid, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->mainScr_bckg_mid, &_mid_alpha_460x9);
    lv_img_set_pivot(ui->mainScr_bckg_mid, 50,50);
    lv_img_set_angle(ui->mainScr_bckg_mid, 0);
    lv_obj_set_pos(ui->mainScr_bckg_mid, 10, 243);
    lv_obj_set_size(ui->mainScr_bckg_mid, 460, 9);

    //Write style for mainScr_bckg_mid, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->mainScr_bckg_mid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->mainScr_bckg_mid, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bckg_mid, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->mainScr_bckg_mid, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_bckg_right
    ui->mainScr_bckg_right = lv_img_create(ui->mainScr);
    lv_obj_add_flag(ui->mainScr_bckg_right, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->mainScr_bckg_right, &_right_alpha_10x320);
    lv_img_set_pivot(ui->mainScr_bckg_right, 50,50);
    lv_img_set_angle(ui->mainScr_bckg_right, 0);
    lv_obj_set_pos(ui->mainScr_bckg_right, 470, 0);
    lv_obj_set_size(ui->mainScr_bckg_right, 10, 320);

    //Write style for mainScr_bckg_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->mainScr_bckg_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->mainScr_bckg_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bckg_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->mainScr_bckg_right, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_bckg_left
    ui->mainScr_bckg_left = lv_img_create(ui->mainScr);
    lv_obj_add_flag(ui->mainScr_bckg_left, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->mainScr_bckg_left, &_left_alpha_10x320);
    lv_img_set_pivot(ui->mainScr_bckg_left, 50,50);
    lv_img_set_angle(ui->mainScr_bckg_left, 0);
    lv_obj_set_pos(ui->mainScr_bckg_left, 0, 0);
    lv_obj_set_size(ui->mainScr_bckg_left, 10, 320);

    //Write style for mainScr_bckg_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->mainScr_bckg_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->mainScr_bckg_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bckg_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->mainScr_bckg_left, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_bckg_top
    ui->mainScr_bckg_top = lv_img_create(ui->mainScr);
    lv_obj_add_flag(ui->mainScr_bckg_top, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->mainScr_bckg_top, &_top_alpha_460x14);
    lv_img_set_pivot(ui->mainScr_bckg_top, 50,50);
    lv_img_set_angle(ui->mainScr_bckg_top, 0);
    lv_obj_set_pos(ui->mainScr_bckg_top, 10, 0);
    lv_obj_set_size(ui->mainScr_bckg_top, 460, 14);

    //Write style for mainScr_bckg_top, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->mainScr_bckg_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->mainScr_bckg_top, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bckg_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->mainScr_bckg_top, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_bckg_bot
    ui->mainScr_bckg_bot = lv_img_create(ui->mainScr);
    lv_obj_add_flag(ui->mainScr_bckg_bot, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->mainScr_bckg_bot, &_bot_alpha_460x6);
    lv_img_set_pivot(ui->mainScr_bckg_bot, 50,50);
    lv_img_set_angle(ui->mainScr_bckg_bot, 0);
    lv_obj_set_pos(ui->mainScr_bckg_bot, 10, 314);
    lv_obj_set_size(ui->mainScr_bckg_bot, 460, 6);

    //Write style for mainScr_bckg_bot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->mainScr_bckg_bot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->mainScr_bckg_bot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bckg_bot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->mainScr_bckg_bot, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_container_menu
    ui->mainScr_container_menu = lv_obj_create(ui->mainScr);
    lv_obj_set_pos(ui->mainScr_container_menu, 5, 252);
    lv_obj_set_size(ui->mainScr_container_menu, 470, 63);
    lv_obj_set_scrollbar_mode(ui->mainScr_container_menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for mainScr_container_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->mainScr_container_menu, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_container_menu, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->mainScr_container_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->mainScr_container_menu, lv_color_hex(0xEBE7DD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->mainScr_container_menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_container_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_container_menu, lv_color_hex(0xF7F5F1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_container_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_container_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_container_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_container_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_container_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_container_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_btn_menu_train
    ui->mainScr_btn_menu_train = lv_btn_create(ui->mainScr_container_menu);
    ui->mainScr_btn_menu_train_label = lv_label_create(ui->mainScr_btn_menu_train);
    lv_label_set_text(ui->mainScr_btn_menu_train_label, "Train");
    lv_label_set_long_mode(ui->mainScr_btn_menu_train_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->mainScr_btn_menu_train_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->mainScr_btn_menu_train, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->mainScr_btn_menu_train_label, LV_PCT(100));
    lv_obj_set_pos(ui->mainScr_btn_menu_train, 4, 4);
    lv_obj_set_size(ui->mainScr_btn_menu_train, 140, 49);

    //Write style for mainScr_btn_menu_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_btn_menu_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_btn_menu_train, lv_color_hex(0x1F87FF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_btn_menu_train, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_btn_menu_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_btn_menu_train, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_btn_menu_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_btn_menu_train, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_btn_menu_train, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_btn_menu_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_btn_menu_train, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_btn_menu_detect
    ui->mainScr_btn_menu_detect = lv_btn_create(ui->mainScr_container_menu);
    ui->mainScr_btn_menu_detect_label = lv_label_create(ui->mainScr_btn_menu_detect);
    lv_label_set_text(ui->mainScr_btn_menu_detect_label, "Detect");
    lv_label_set_long_mode(ui->mainScr_btn_menu_detect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->mainScr_btn_menu_detect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->mainScr_btn_menu_detect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->mainScr_btn_menu_detect_label, LV_PCT(100));
    lv_obj_set_pos(ui->mainScr_btn_menu_detect, 162, 4);
    lv_obj_set_size(ui->mainScr_btn_menu_detect, 140, 49);

    //Write style for mainScr_btn_menu_detect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_btn_menu_detect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_btn_menu_detect, lv_color_hex(0x1F87FF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_btn_menu_detect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_btn_menu_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_btn_menu_detect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_btn_menu_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_btn_menu_detect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_btn_menu_detect, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_btn_menu_detect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_btn_menu_detect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_btn_menu_control
    ui->mainScr_btn_menu_control = lv_btn_create(ui->mainScr_container_menu);
    ui->mainScr_btn_menu_control_label = lv_label_create(ui->mainScr_btn_menu_control);
    lv_label_set_text(ui->mainScr_btn_menu_control_label, "Control");
    lv_label_set_long_mode(ui->mainScr_btn_menu_control_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->mainScr_btn_menu_control_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->mainScr_btn_menu_control, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->mainScr_btn_menu_control_label, LV_PCT(100));
    lv_obj_set_pos(ui->mainScr_btn_menu_control, 320, 4);
    lv_obj_set_size(ui->mainScr_btn_menu_control, 140, 49);

    //Write style for mainScr_btn_menu_control, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_btn_menu_control, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_btn_menu_control, lv_color_hex(0x1F87FF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_btn_menu_control, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_btn_menu_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_btn_menu_control, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_btn_menu_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_btn_menu_control, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_btn_menu_control, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_btn_menu_control, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_btn_menu_control, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_1
    ui->mainScr_label_1 = lv_label_create(ui->mainScr_container_menu);
    lv_label_set_text(ui->mainScr_label_1, "Training Progress");
    lv_label_set_long_mode(ui->mainScr_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_1, 166, 215);
    lv_obj_set_size(ui->mainScr_label_1, 186, 16);
    lv_obj_add_flag(ui->mainScr_label_1, LV_OBJ_FLAG_PRESS_LOCK);

    //Write style for mainScr_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_container_detect
    ui->mainScr_container_detect = lv_obj_create(ui->mainScr);
    lv_obj_set_pos(ui->mainScr_container_detect, 5, 5);
    lv_obj_set_size(ui->mainScr_container_detect, 470, 242);
    lv_obj_set_scrollbar_mode(ui->mainScr_container_detect, LV_SCROLLBAR_MODE_OFF);

    //Write style for mainScr_container_detect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->mainScr_container_detect, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_container_detect, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->mainScr_container_detect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->mainScr_container_detect, lv_color_hex(0xEBE7DD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->mainScr_container_detect, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_container_detect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_container_detect, lv_color_hex(0xF7F5F1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_container_detect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_container_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_container_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_container_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_container_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_container_detect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_slider_det_speed
    ui->mainScr_slider_det_speed = lv_slider_create(ui->mainScr_container_detect);
    lv_slider_set_range(ui->mainScr_slider_det_speed, 0, 10);
    lv_slider_set_mode(ui->mainScr_slider_det_speed, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->mainScr_slider_det_speed, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->mainScr_slider_det_speed, 34, 189);
    lv_obj_set_size(ui->mainScr_slider_det_speed, 160, 8);

    //Write style for mainScr_slider_det_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_det_speed, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_det_speed, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_det_speed, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_det_speed, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->mainScr_slider_det_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_slider_det_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_slider_det_speed, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_det_speed, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_det_speed, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_det_speed, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_det_speed, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for mainScr_slider_det_speed, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_det_speed, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_det_speed, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_det_speed, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_det_speed, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_sw_det_run_motor
    ui->mainScr_sw_det_run_motor = lv_switch_create(ui->mainScr_container_detect);
    lv_obj_set_pos(ui->mainScr_sw_det_run_motor, 160, 86);
    lv_obj_set_size(ui->mainScr_sw_det_run_motor, 40, 20);

    //Write style for mainScr_sw_det_run_motor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_det_run_motor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_det_run_motor, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_det_run_motor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_det_run_motor, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_sw_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_sw_det_run_motor, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_det_run_motor, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->mainScr_sw_det_run_motor, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_det_run_motor, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->mainScr_sw_det_run_motor, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for mainScr_sw_det_run_motor, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_det_run_motor, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_det_run_motor, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_det_run_motor, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_det_run_motor, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_det_run_motor, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_sw_det_run_ml
    ui->mainScr_sw_det_run_ml = lv_switch_create(ui->mainScr_container_detect);
    lv_obj_set_pos(ui->mainScr_sw_det_run_ml, 160, 121);
    lv_obj_set_size(ui->mainScr_sw_det_run_ml, 40, 20);

    //Write style for mainScr_sw_det_run_ml, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_det_run_ml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_det_run_ml, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_det_run_ml, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_det_run_ml, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_sw_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_sw_det_run_ml, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_det_run_ml, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->mainScr_sw_det_run_ml, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_det_run_ml, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->mainScr_sw_det_run_ml, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for mainScr_sw_det_run_ml, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_det_run_ml, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_det_run_ml, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_det_run_ml, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_det_run_ml, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_det_run_ml, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_bar_det_anomaly_score
    ui->mainScr_bar_det_anomaly_score = lv_bar_create(ui->mainScr_container_detect);
    lv_obj_set_style_anim_time(ui->mainScr_bar_det_anomaly_score, 1000, 0);
    lv_bar_set_mode(ui->mainScr_bar_det_anomaly_score, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->mainScr_bar_det_anomaly_score, 0, 100);
    lv_bar_set_value(ui->mainScr_bar_det_anomaly_score, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->mainScr_bar_det_anomaly_score, 266, 137);
    lv_obj_set_size(ui->mainScr_bar_det_anomaly_score, 168, 20);

    //Write style for mainScr_bar_det_anomaly_score, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_bar_det_anomaly_score, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_bar_det_anomaly_score, lv_color_hex(0x00ff16), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_bar_det_anomaly_score, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bar_det_anomaly_score, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_bar_det_anomaly_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_bar_det_anomaly_score, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_bar_det_anomaly_score, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_bar_det_anomaly_score, lv_color_hex(0x10bf1f), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_bar_det_anomaly_score, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bar_det_anomaly_score, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes mainScr_label_det_fan_status
    ui->mainScr_label_det_fan_status = lv_label_create(ui->mainScr_container_detect);
    lv_label_set_text(ui->mainScr_label_det_fan_status, "Fan Status");
    lv_label_set_long_mode(ui->mainScr_label_det_fan_status, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_det_fan_status, 278, 105);
    lv_obj_set_size(ui->mainScr_label_det_fan_status, 144, 20);

    //Write style for mainScr_label_det_fan_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_det_fan_status, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_det_fan_status, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_det_fan_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_det_fan_status, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_det_fan_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_det_fan_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_btn_det_classification
    ui->mainScr_btn_det_classification = lv_btn_create(ui->mainScr_container_detect);
    ui->mainScr_btn_det_classification_label = lv_label_create(ui->mainScr_btn_det_classification);
    lv_label_set_text(ui->mainScr_btn_det_classification_label, "Anomaly");
    lv_label_set_long_mode(ui->mainScr_btn_det_classification_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->mainScr_btn_det_classification_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->mainScr_btn_det_classification, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->mainScr_btn_det_classification_label, LV_PCT(100));
    lv_obj_set_pos(ui->mainScr_btn_det_classification, 295, 169);
    lv_obj_set_size(ui->mainScr_btn_det_classification, 110, 36);
    lv_obj_add_flag(ui->mainScr_btn_det_classification, LV_OBJ_FLAG_PRESS_LOCK);

    //Write style for mainScr_btn_det_classification, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_btn_det_classification, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_btn_det_classification, lv_color_hex(0xF54D4D), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_btn_det_classification, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_btn_det_classification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_btn_det_classification, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_btn_det_classification, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_btn_det_classification, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_btn_det_classification, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_btn_det_classification, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_btn_det_classification, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_det_run_motor
    ui->mainScr_label_det_run_motor = lv_label_create(ui->mainScr_container_detect);
    lv_label_set_text(ui->mainScr_label_det_run_motor, "Run Motor");
    lv_label_set_long_mode(ui->mainScr_label_det_run_motor, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_det_run_motor, 20, 89);
    lv_obj_set_size(ui->mainScr_label_det_run_motor, 144, 20);

    //Write style for mainScr_label_det_run_motor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_det_run_motor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_det_run_motor, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_det_run_motor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_det_run_motor, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_det_run_motor, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_det_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_det_run_ml
    ui->mainScr_label_det_run_ml = lv_label_create(ui->mainScr_container_detect);
    lv_label_set_text(ui->mainScr_label_det_run_ml, "Run ML");
    lv_label_set_long_mode(ui->mainScr_label_det_run_ml, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_det_run_ml, 20, 124);
    lv_obj_set_size(ui->mainScr_label_det_run_ml, 152, 20);

    //Write style for mainScr_label_det_run_ml, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_det_run_ml, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_det_run_ml, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_det_run_ml, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_det_run_ml, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_det_run_ml, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_det_run_ml, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_det_motor_speed
    ui->mainScr_label_det_motor_speed = lv_label_create(ui->mainScr_container_detect);
    lv_label_set_text(ui->mainScr_label_det_motor_speed, "Motor Speed");
    lv_label_set_long_mode(ui->mainScr_label_det_motor_speed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_det_motor_speed, 20, 159);
    lv_obj_set_size(ui->mainScr_label_det_motor_speed, 144, 20);

    //Write style for mainScr_label_det_motor_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_det_motor_speed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_det_motor_speed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_det_motor_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_det_motor_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_det_motor_speed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_det_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_container_train
    ui->mainScr_container_train = lv_obj_create(ui->mainScr);
    lv_obj_set_pos(ui->mainScr_container_train, 5, 5);
    lv_obj_set_size(ui->mainScr_container_train, 470, 242);
    lv_obj_set_scrollbar_mode(ui->mainScr_container_train, LV_SCROLLBAR_MODE_OFF);

    //Write style for mainScr_container_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_container_train, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->mainScr_container_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->mainScr_container_train, lv_color_hex(0xEBE7DD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->mainScr_container_train, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_container_train, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_container_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_container_train, lv_color_hex(0xF7F5F1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_container_train, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_container_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_container_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_container_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_container_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_container_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_bar_train_progress
    ui->mainScr_bar_train_progress = lv_bar_create(ui->mainScr_container_train);
    lv_obj_set_style_anim_time(ui->mainScr_bar_train_progress, 1000, 0);
    lv_bar_set_mode(ui->mainScr_bar_train_progress, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->mainScr_bar_train_progress, 0, 100);
    lv_bar_set_value(ui->mainScr_bar_train_progress, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->mainScr_bar_train_progress, 20, 194);
    lv_obj_set_size(ui->mainScr_bar_train_progress, 430, 20);

    //Write style for mainScr_bar_train_progress, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_bar_train_progress, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_bar_train_progress, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_bar_train_progress, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bar_train_progress, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_bar_train_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_bar_train_progress, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_bar_train_progress, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_bar_train_progress, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_bar_train_progress, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_bar_train_progress, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes mainScr_slider_train_speed
    ui->mainScr_slider_train_speed = lv_slider_create(ui->mainScr_container_train);
    lv_slider_set_range(ui->mainScr_slider_train_speed, 0, 10);
    lv_slider_set_mode(ui->mainScr_slider_train_speed, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->mainScr_slider_train_speed, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->mainScr_slider_train_speed, 165, 122);
    lv_obj_set_size(ui->mainScr_slider_train_speed, 160, 8);

    //Write style for mainScr_slider_train_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_train_speed, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_train_speed, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_train_speed, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_train_speed, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_slider_train_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->mainScr_slider_train_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_slider_train_speed, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_train_speed, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_train_speed, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_train_speed, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_train_speed, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for mainScr_slider_train_speed, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_train_speed, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_train_speed, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_train_speed, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_train_speed, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_label_train_motor_speed
    ui->mainScr_label_train_motor_speed = lv_label_create(ui->mainScr_container_train);
    lv_label_set_text(ui->mainScr_label_train_motor_speed, "Motor Speed");
    lv_label_set_long_mode(ui->mainScr_label_train_motor_speed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_train_motor_speed, 26, 118);
    lv_obj_set_size(ui->mainScr_label_train_motor_speed, 139, 17);

    //Write style for mainScr_label_train_motor_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_train_motor_speed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_train_motor_speed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_train_motor_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_train_motor_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_train_motor_speed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_train_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_btn_train_train
    ui->mainScr_btn_train_train = lv_btn_create(ui->mainScr_container_train);
    ui->mainScr_btn_train_train_label = lv_label_create(ui->mainScr_btn_train_train);
    lv_label_set_text(ui->mainScr_btn_train_train_label, "Train");
    lv_label_set_long_mode(ui->mainScr_btn_train_train_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->mainScr_btn_train_train_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->mainScr_btn_train_train, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->mainScr_btn_train_train_label, LV_PCT(100));
    lv_obj_set_pos(ui->mainScr_btn_train_train, 20, 151);
    lv_obj_set_size(ui->mainScr_btn_train_train, 430, 33);

    //Write style for mainScr_btn_train_train, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_btn_train_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_btn_train_train, lv_color_hex(0x1F87FF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_btn_train_train, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_btn_train_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_btn_train_train, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_btn_train_train, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_btn_train_train, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_btn_train_train, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_btn_train_train, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_btn_train_train, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_train_training_progress
    ui->mainScr_label_train_training_progress = lv_label_create(ui->mainScr_container_train);
    lv_label_set_text(ui->mainScr_label_train_training_progress, "Training Progress");
    lv_label_set_long_mode(ui->mainScr_label_train_training_progress, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_train_training_progress, 144, 196);
    lv_obj_set_size(ui->mainScr_label_train_training_progress, 182, 16);
    lv_obj_add_flag(ui->mainScr_label_train_training_progress, LV_OBJ_FLAG_PRESS_LOCK);

    //Write style for mainScr_label_train_training_progress, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_train_training_progress, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_train_training_progress, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_train_training_progress, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_train_training_progress, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_train_training_progress, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_train_training_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_sw_train_incremental
    ui->mainScr_sw_train_incremental = lv_switch_create(ui->mainScr_container_train);
    lv_obj_set_pos(ui->mainScr_sw_train_incremental, 260, 85);
    lv_obj_set_size(ui->mainScr_sw_train_incremental, 40, 20);

    //Write style for mainScr_sw_train_incremental, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_train_incremental, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_train_incremental, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_train_incremental, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_train_incremental, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_sw_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_sw_train_incremental, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_train_incremental, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->mainScr_sw_train_incremental, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_train_incremental, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->mainScr_sw_train_incremental, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for mainScr_sw_train_incremental, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_train_incremental, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_train_incremental, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_train_incremental, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_train_incremental, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_train_incremental, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_label_train_incremental
    ui->mainScr_label_train_incremental = lv_label_create(ui->mainScr_container_train);
    lv_label_set_text(ui->mainScr_label_train_incremental, "Incremental Learning");
    lv_label_set_long_mode(ui->mainScr_label_train_incremental, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_train_incremental, 26, 86);
    lv_obj_set_size(ui->mainScr_label_train_incremental, 223, 17);

    //Write style for mainScr_label_train_incremental, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_train_incremental, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_train_incremental, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_train_incremental, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_train_incremental, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_train_incremental, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_train_incremental, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_container_control
    ui->mainScr_container_control = lv_obj_create(ui->mainScr);
    lv_obj_set_pos(ui->mainScr_container_control, 5, 5);
    lv_obj_set_size(ui->mainScr_container_control, 470, 242);
    lv_obj_set_scrollbar_mode(ui->mainScr_container_control, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->mainScr_container_control, LV_OBJ_FLAG_HIDDEN);

    //Write style for mainScr_container_control, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_container_control, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->mainScr_container_control, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->mainScr_container_control, lv_color_hex(0xEBE7DD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->mainScr_container_control, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_container_control, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_container_control, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_container_control, lv_color_hex(0xF7F5F1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_container_control, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_container_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_container_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_container_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_container_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_container_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_slider_ctrl_speed
    ui->mainScr_slider_ctrl_speed = lv_slider_create(ui->mainScr_container_control);
    lv_slider_set_range(ui->mainScr_slider_ctrl_speed, 0, 10);
    lv_slider_set_mode(ui->mainScr_slider_ctrl_speed, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->mainScr_slider_ctrl_speed, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->mainScr_slider_ctrl_speed, 33, 147);
    lv_obj_set_size(ui->mainScr_slider_ctrl_speed, 160, 8);

    //Write style for mainScr_slider_ctrl_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_ctrl_speed, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_ctrl_speed, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_ctrl_speed, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_ctrl_speed, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->mainScr_slider_ctrl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_slider_ctrl_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_slider_ctrl_speed, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_ctrl_speed, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_ctrl_speed, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_ctrl_speed, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_ctrl_speed, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for mainScr_slider_ctrl_speed, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_slider_ctrl_speed, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_slider_ctrl_speed, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_slider_ctrl_speed, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_slider_ctrl_speed, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_sw_ctrl_run_motor
    ui->mainScr_sw_ctrl_run_motor = lv_switch_create(ui->mainScr_container_control);
    lv_obj_set_pos(ui->mainScr_sw_ctrl_run_motor, 160, 86);
    lv_obj_set_size(ui->mainScr_sw_ctrl_run_motor, 40, 20);

    //Write style for mainScr_sw_ctrl_run_motor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_ctrl_run_motor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_ctrl_run_motor, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_ctrl_run_motor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_ctrl_run_motor, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_sw_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for mainScr_sw_ctrl_run_motor, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_ctrl_run_motor, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->mainScr_sw_ctrl_run_motor, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_ctrl_run_motor, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->mainScr_sw_ctrl_run_motor, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for mainScr_sw_ctrl_run_motor, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_sw_ctrl_run_motor, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->mainScr_sw_ctrl_run_motor, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->mainScr_sw_ctrl_run_motor, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_sw_ctrl_run_motor, 10, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_sw_ctrl_run_motor, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_run_motor
    ui->mainScr_label_ctrl_run_motor = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_run_motor, "Run Motor");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_run_motor, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_run_motor, 20, 89);
    lv_obj_set_size(ui->mainScr_label_ctrl_run_motor, 144, 20);

    //Write style for mainScr_label_ctrl_run_motor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_run_motor, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_run_motor, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_run_motor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_run_motor, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_run_motor, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_run_motor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_motor_speed
    ui->mainScr_label_ctrl_motor_speed = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_motor_speed, "Motor Speed");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_motor_speed, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_motor_speed, 20, 117);
    lv_obj_set_size(ui->mainScr_label_ctrl_motor_speed, 144, 20);

    //Write style for mainScr_label_ctrl_motor_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_motor_speed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_motor_speed, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_motor_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_motor_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_motor_speed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_motor_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_curA
    ui->mainScr_label_ctrl_curA = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_curA, "Phase Current A (A)");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_curA, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_curA, 210, 77);
    lv_obj_set_size(ui->mainScr_label_ctrl_curA, 216, 20);

    //Write style for mainScr_label_ctrl_curA, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_curA, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_curA, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_curA, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_curA, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_curA, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_curA, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_curB
    ui->mainScr_label_ctrl_curB = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_curB, "Phase Current B (A)");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_curB, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_curB, 210, 116);
    lv_obj_set_size(ui->mainScr_label_ctrl_curB, 205, 20);

    //Write style for mainScr_label_ctrl_curB, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_curB, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_curB, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_curB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_curB, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_curB, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_curB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_curC
    ui->mainScr_label_ctrl_curC = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_curC, "Phase Current C (A)");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_curC, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_curC, 210, 155);
    lv_obj_set_size(ui->mainScr_label_ctrl_curC, 221, 18);

    //Write style for mainScr_label_ctrl_curC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_curC, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_curC, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_curC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_curC, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_curC, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_curC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_curC_val
    ui->mainScr_label_ctrl_curC_val = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_curC_val, "0.0");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_curC_val, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_curC_val, 412, 154);
    lv_obj_set_size(ui->mainScr_label_ctrl_curC_val, 49, 20);

    //Write style for mainScr_label_ctrl_curC_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_curC_val, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_curC_val, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_curC_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_curC_val, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_curC_val, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_curC_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_curA_val
    ui->mainScr_label_ctrl_curA_val = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_curA_val, "0.0");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_curA_val, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_curA_val, 412, 78);
    lv_obj_set_size(ui->mainScr_label_ctrl_curA_val, 48, 20);

    //Write style for mainScr_label_ctrl_curA_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_curA_val, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_curA_val, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_curA_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_curA_val, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_curA_val, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_curA_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_curB_val
    ui->mainScr_label_ctrl_curB_val = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_curB_val, "0.0");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_curB_val, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_curB_val, 412, 116);
    lv_obj_set_size(ui->mainScr_label_ctrl_curB_val, 49, 20);

    //Write style for mainScr_label_ctrl_curB_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_curB_val, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_curB_val, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_curB_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_curB_val, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_curB_val, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_curB_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_dcbus
    ui->mainScr_label_ctrl_dcbus = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_dcbus, "DCBus Voltage (V)");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_dcbus, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_dcbus, 210, 192);
    lv_obj_set_size(ui->mainScr_label_ctrl_dcbus, 187, 20);

    //Write style for mainScr_label_ctrl_dcbus, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_dcbus, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_dcbus, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_dcbus, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_dcbus, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_dcbus, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_dcbus, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_ctrl_dcbus_val
    ui->mainScr_label_ctrl_dcbus_val = lv_label_create(ui->mainScr_container_control);
    lv_label_set_text(ui->mainScr_label_ctrl_dcbus_val, "0.0");
    lv_label_set_long_mode(ui->mainScr_label_ctrl_dcbus_val, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_ctrl_dcbus_val, 412, 192);
    lv_obj_set_size(ui->mainScr_label_ctrl_dcbus_val, 50, 20);

    //Write style for mainScr_label_ctrl_dcbus_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_ctrl_dcbus_val, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_ctrl_dcbus_val, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_ctrl_dcbus_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_ctrl_dcbus_val, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_ctrl_dcbus_val, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_ctrl_dcbus_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_img_speed
    ui->mainScr_img_speed = lv_img_create(ui->mainScr);
    lv_obj_add_flag(ui->mainScr_img_speed, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->mainScr_img_speed, &_Picture1_alpha_48x48);
    lv_img_set_pivot(ui->mainScr_img_speed, 50,50);
    lv_img_set_angle(ui->mainScr_img_speed, 0);
    lv_obj_set_pos(ui->mainScr_img_speed, 320, 5);
    lv_obj_set_size(ui->mainScr_img_speed, 48, 48);

    //Write style for mainScr_img_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->mainScr_img_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->mainScr_img_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_img_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->mainScr_img_speed, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes mainScr_label_speed_current
    ui->mainScr_label_speed_current = lv_label_create(ui->mainScr);
    lv_label_set_text(ui->mainScr_label_speed_current, "0 RPM");
    lv_label_set_long_mode(ui->mainScr_label_speed_current, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->mainScr_label_speed_current, 365, 23);
    lv_obj_set_size(ui->mainScr_label_speed_current, 100, 14);

    //Write style for mainScr_label_speed_current, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->mainScr_label_speed_current, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->mainScr_label_speed_current, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->mainScr_label_speed_current, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->mainScr_label_speed_current, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->mainScr_label_speed_current, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->mainScr_label_speed_current, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of mainScr.


    //Update current screen layout.
    lv_obj_update_layout(ui->mainScr);

    //Init events for screen.
    events_init_mainScr(ui);
}

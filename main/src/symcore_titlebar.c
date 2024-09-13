#include "lvgl/lvgl.h"
#include "symcore_titlebar.h"

lv_obj_t * titlebarObj;
lv_obj_t * lv_lbl_Title;
lv_obj_t * lv_datetime;

#define TITLEBAR_FLEX_LAYOUT_WIDTH 1280

#define MENU_ITEMS_HEIGHT_FIXED 100
#define MENU_TITLE_FIELD_WIDTH  200


void symcore_titlebar_create(void)
{
    titlebarObj = lv_obj_create(NULL);
    lv_obj_set_size(titlebarObj, TITLEBAR_FLEX_LAYOUT_WIDTH, MENU_ITEMS_HEIGHT_FIXED);
    lv_obj_set_style_bg_opa(titlebarObj, LV_OPA_COVER, 0);
    lv_obj_align(titlebarObj, LV_ALIGN_TOP_LEFT, 0, 0);

    /* Show Menu Title */
    lv_lbl_Title = lv_label_create(titlebarObj);
    lv_obj_set_size(lv_lbl_Title, MENU_TITLE_FIELD_WIDTH, MENU_ITEMS_HEIGHT_FIXED);

    lv_obj_set_style_text_color(lv_lbl_Title, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_text_opa(lv_lbl_Title, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(lv_lbl_Title, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_label_set_text(lv_lbl_Title, "Dashboard");
    lv_obj_align(lv_lbl_Title, LV_ALIGN_TOP_LEFT, 10, 10);

    /* Show Date & Time */
    lv_datetime = lv_label_create(titlebarObj);
    lv_obj_set_size(lv_datetime, 100, MENU_ITEMS_HEIGHT_FIXED);

    lv_obj_set_style_text_color(lv_datetime, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_text_opa(lv_datetime, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(lv_datetime, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_label_set_text(lv_datetime, "00:01:38");  // set text
    lv_obj_align(lv_datetime, LV_ALIGN_CENTER, 10, 10);

    /* Show Network Status */

    /* Show Operation Status */

}

void * APP_GetTitleBarHandle(void)
{
    return (void *)lv_lbl_Title;
}

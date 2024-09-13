#include "lvgl/lvgl.h"
#include "symcore_lv_splash_screen.h"

#define FW_VERSION  "v1.0.0"

lv_obj_t * lv_appInitProgressBar;
lv_obj_t * lv_productName;
lv_obj_t * lv_fwVersion;
LV_IMAGE_DECLARE(img_skew_strip);
lv_style_t style_indic;
lv_obj_t * splashScreenObj;
extern uint8_t bAppInitStatus;

void symcore_lv_spash_screen(void)
{
    splashScreenObj = lv_obj_create(NULL);

    /* Show product name in the center */
    lv_productName = lv_label_create(splashScreenObj);
    lv_obj_set_width( lv_productName, LV_SIZE_CONTENT);
	lv_obj_set_height( lv_productName, LV_SIZE_CONTENT);
    lv_obj_set_style_text_color(lv_productName, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_text_opa(lv_productName, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(lv_productName, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_label_set_text(lv_productName, "Oil Rig Monitoring System");

    lv_obj_set_width(lv_productName, 300);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(lv_productName, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(lv_productName, LV_ALIGN_CENTER, 0, -40);

    /* Show application firmware version */
    lv_fwVersion = lv_label_create(splashScreenObj);
    lv_obj_set_width( lv_fwVersion, LV_SIZE_CONTENT);
	lv_obj_set_height( lv_fwVersion, LV_SIZE_CONTENT);
    lv_obj_set_style_text_color(lv_fwVersion, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_text_opa(lv_fwVersion, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(lv_fwVersion, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_label_set_text_fmt(lv_fwVersion, "%s", FW_VERSION);

    lv_obj_set_width(lv_fwVersion, 300);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(lv_fwVersion, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(lv_fwVersion, LV_ALIGN_BOTTOM_MID, 0, -40);

    /* Progress bar for application initialization */
    lv_style_init(&style_indic);
    lv_style_set_bg_image_src(&style_indic, &img_skew_strip);
    lv_style_set_bg_image_tiled(&style_indic, true);
    lv_style_set_bg_image_opa(&style_indic, LV_OPA_30);

    lv_appInitProgressBar = lv_bar_create(splashScreenObj);
    lv_obj_add_style(lv_appInitProgressBar, &style_indic, LV_PART_INDICATOR);

    lv_obj_set_size(lv_appInitProgressBar, 260, 20);
    lv_obj_center(lv_appInitProgressBar);
    lv_bar_set_mode(lv_appInitProgressBar, LV_BAR_MODE_NORMAL);
    lv_bar_set_start_value(lv_appInitProgressBar, 0, LV_ANIM_OFF);
}

void * APP_GetSplashScreenHandle(void)
{
    return (void *)splashScreenObj;
}

void APP_UpdateInitProgress(void)
{
    static uint8_t progressPercentage = 0;

    if(progressPercentage >= 100)
    {
        bAppInitStatus = true;
        return;
    }

    progressPercentage += 20;
    lv_bar_set_value(lv_appInitProgressBar, progressPercentage, LV_ANIM_OFF);
}

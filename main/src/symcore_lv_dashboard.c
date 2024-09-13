#include "lvgl/lvgl.h"
#include "symcore_lv_dashboard.h"

LV_IMAGE_DECLARE(img_hand);


lv_obj_t *dashboardscreenObj;
lv_obj_t *spmMeterObj;
lv_obj_t *spm1MeterObj;

lv_obj_t *spmLable;
lv_style_t spmMeterStyle;
lv_obj_t *scale_line;
lv_obj_t * needle_line;
lv_obj_t * needle_img;

lv_obj_t *rpmMeterObj;
lv_style_t indicator_style;

static void set_needle_line_value(void * obj, int32_t v)
{
    lv_scale_set_line_needle_value(obj, needle_line, 60, v);
}

static void set_needle_img_value(void * obj, int32_t v)
{
    lv_scale_set_image_needle_value(obj, needle_img, v);
}

/**
 * A simple round scale
 */
void create_spm_meter_obj(uint8_t id, lv_obj_t *spmObj, lv_obj_t *parentObj)
{
    spmObj = lv_obj_create(parentObj);
    lv_style_init(&spmMeterStyle);

    lv_obj_set_pos(spmObj, 40 + (id * (250 + 40)), 100);
    lv_obj_set_style_bg_opa(spmObj, LV_OPA_COVER, 0);
    lv_style_set_border_opa(&spmMeterStyle, 0);
    lv_obj_add_style(spmObj, &spmMeterStyle, 0);
    //lv_obj_set_style_bg_color(spmObj, lv_palette_lighten(LV_PALETTE_NONE, 0), 0);

    lv_obj_set_size(spmObj, 250, 370);
    lv_obj_set_flex_flow(spmObj, LV_FLEX_FLOW_COLUMN_REVERSE);

    spmLable = lv_label_create(spmObj);
    lv_obj_set_size(spmLable, 200, 100);
    lv_obj_set_style_text_color(spmLable, lv_color_hex(0), LV_PART_MAIN | LV_STATE_DEFAULT );
	lv_obj_set_style_text_opa(spmLable, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(spmLable, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_label_set_text_fmt(spmLable, "SPM-%d\nStatus-OK", id);

    lv_obj_set_style_text_align(spmLable, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(spmLable, LV_ALIGN_BOTTOM_MID, LV_PCT(4), 10);

    scale_line = lv_scale_create(spmObj);

    lv_obj_set_size(scale_line, 200, 200);
    lv_scale_set_mode(scale_line, LV_SCALE_MODE_ROUND_INNER);
    lv_obj_set_style_bg_opa(scale_line, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(scale_line, lv_palette_lighten(LV_PALETTE_RED, 5), 0);
    lv_obj_set_style_radius(scale_line, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(scale_line, true, 0);
    lv_obj_align(scale_line, LV_ALIGN_BOTTOM_MID, LV_PCT(4), 10);

    lv_scale_set_label_show(scale_line, true);

    lv_scale_set_total_tick_count(scale_line, 21);
    lv_scale_set_major_tick_every(scale_line, 5);

    lv_obj_set_style_length(scale_line, 5, LV_PART_ITEMS);
    lv_obj_set_style_length(scale_line, 10, LV_PART_INDICATOR);
    lv_scale_set_range(scale_line, 0, 1000);

    lv_scale_set_angle_range(scale_line, 270);
    lv_scale_set_rotation(scale_line, 135);

    needle_line = lv_line_create(scale_line);

    lv_obj_set_style_line_width(needle_line, 6, LV_PART_MAIN);
    lv_obj_set_style_line_rounded(needle_line, true, LV_PART_MAIN);

    lv_scale_set_line_needle_value(scale_line, needle_line, 60, 500 + (id * 200));
}

void symcore_lv_dashboard_screen(void)
{
    dashboardscreenObj = lv_obj_create(NULL);

    /* Show SPM Meter Reading */
    create_spm_meter_obj(0, spmMeterObj, dashboardscreenObj);
    create_spm_meter_obj(1, spm1MeterObj, dashboardscreenObj);
    /* Show Rotary Torque Meter Reading */
    /* Show RPM Meter Reading */
    /* Show Hookload Meter Reading */
    /* Show Mud Pump Pressure Meter Reading*/
    /* Show Tonmiles */
    /* Show Flow Totalizer */
}

void * APP_GetDashboardScreenHandle(void)
{
    return (void *)dashboardscreenObj;
}

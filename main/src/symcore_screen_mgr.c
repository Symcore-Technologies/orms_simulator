#include "lvgl/lvgl.h"
#include "symcore_screen_mgr.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define SET_CURRENT_SCREEN(x) gCurrentScreenId=x
#define GET_CURRENT_SCREEN(x) gCurrentScreenId

static uint8_t gCurrentScreenId;
uint8_t bAppInitStatus=false;

void load_screen(void *screenObj)
{
    lv_scr_load((lv_obj_t*)screenObj);
}


void APP_InitializeUI(void)
{
    /* Setting up splash screen. */
    symcore_lv_spash_screen();

    /* Dashboard Screen */
    symcore_lv_dashboard_screen();

    /* Titlebar */
    symcore_titlebar_create();

    SET_CURRENT_SCREEN(SPLASH_SCREEN);
    load_screen(APP_GetSplashScreenHandle());
}

void APP_UiEventHandler(void)
{
    static uint8_t prevScreen=MAX_SCREENS;
    lv_obj_t *screenObj;

    switch(GET_CURRENT_SCREEN())
    {
        case SPLASH_SCREEN:
            screenObj = APP_GetSplashScreenHandle();
            APP_UpdateInitProgress();
            if (bAppInitStatus == true)
            {
                SET_CURRENT_SCREEN(DASHBOARD_SCREEN);
                screenObj = APP_GetDashboardScreenHandle();
            }
            break;

        case DASHBOARD_SCREEN:
            screenObj = APP_GetDashboardScreenHandle();
            break;

    };

    if (prevScreen != GET_CURRENT_SCREEN())
    {
        load_screen(screenObj);
        #if 1
        if (GET_CURRENT_SCREEN() != SPLASH_SCREEN)
        {
            lv_obj_set_parent((lv_obj_t*)APP_GetTitleBarHandle(), screenObj);
        }
        else
        {
            lv_obj_set_parent((lv_obj_t*)APP_GetTitleBarHandle(), NULL);
        }
        #endif
    }

}

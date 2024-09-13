#ifndef _SYMCORE_SCREEN_MGR_
#define _SYMCORE_SCREEN_MGR_

#include "symcore_lv_splash_screen.h"
#include "symcore_lv_dashboard.h"
#include "symcore_titlebar.h"

typedef enum _enSCREENS {

    SPLASH_SCREEN = 0,
    MAIN_SCREEN = 1,
    DASHBOARD_SCREEN,

    /* Add new screens above this line */
    MAX_SCREENS

}enSCREENS;

extern uint8_t bAppInitStatus;

void APP_InitializeUI(void);
void APP_UiEventHandler(void);

#endif /*_SYMCORE_LV_SPLASH_SCREEN_H_ */

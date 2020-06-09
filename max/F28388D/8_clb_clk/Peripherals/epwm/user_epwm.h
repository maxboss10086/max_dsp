//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_epwm.h
// Descriptions:    
// Author:          Max
// Creation Date:   2020年6月2日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//



#ifndef PERIPHERALS_EPWM_USER_EPWM_H_
#define PERIPHERALS_EPWM_USER_EPWM_H_



//define
#define EPWM1_TIMER_TBPRD   2000U
#define EPWM1_CMPA          1000U
#define EPWM1_CMPB           667U

#define EPWM2_TIMER_TBPRD   2000U
#define EPWM2_CMPA          1333U
#define EPWM2_CMPB           667U

#define EPWM4_TIMER_TBPRD   2000U
#define EPWM4_CMPA          1000U
#define EPWM4_CMPB           667U
//function
void initEPWM1(void);
void initEPWM2(void);
void initEPWM4(void);
#endif /* PERIPHERALS_EPWM_USER_EPWM_H_ */

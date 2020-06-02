//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_epwm.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020年6月2日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include "driverlib.h"
#include "device.h"
#include "user_interrupt.h"

#include "user_epwm.h"




//EPWM1:
//使用了中断，中断为计数器为0的时候触发，触发时设定CLB工作模式
//设定输出的GPIO为0和1
//设定为计数器0的时候为高电平
//启用了两个比较器，计数器采样向上计数方式
//EPWMA计数到A的时候置低，EPWMB计数到B的时候反转电平
void initEPWM1(void)
{
    epwm1_interrupt_set();
//EPWM1的GPIO设置
    GPIO_setPadConfig(0, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_0_EPWM1A);
    GPIO_setPadConfig(1, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_1_EPWM1B);

    EPWM_setTimeBasePeriod(EPWM1_BASE, EPWM1_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM1_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0U);

    EPWM_enableSyncOutPulseSource(EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);

    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM1_CMPA);
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM1_CMPB);

    EPWM_disablePhaseShiftLoad(EPWM1_BASE);
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);

    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    //EPWM计数器向上计数
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
}


void initEPWM2(void)
{
    GPIO_setPadConfig(2, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_2_EPWM2A);
    GPIO_setPadConfig(3, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_3_EPWM2B);

    EPWM_setTimeBasePeriod(EPWM2_BASE, EPWM2_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM2_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM2_BASE, 0U);

    EPWM_enablePhaseShiftLoad(EPWM2_BASE);
    EPWM_setPhaseShift(EPWM2_BASE, 0U);
//使用比较钳位A和钳位B，钳位A的值为1333，钳位B的值为667
    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM2_CMPA);
    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM2_CMPB);

    EPWM_setClockPrescaler(EPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
//在钳位的时候进行动作
    //PWM2A在计数器0的时候置高
    EPWM_setActionQualifierAction(EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM2A计数到A的时候置低
    EPWM_setActionQualifierAction(EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //PWM2B计数到B的时候反转
    EPWM_setActionQualifierAction(EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
//EPWM计数器向上计数
    EPWM_setTimeBaseCounterMode(EPWM2_BASE, EPWM_COUNTER_MODE_UP);
}

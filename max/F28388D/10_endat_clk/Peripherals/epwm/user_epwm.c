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


//void epwm1_interrupt_set(void){
//    Interrupt_register(INT_EPWM1, &epwm1ISR);
//    Interrupt_enable(INT_EPWM1);
//    EPWM_setInterruptSource(EPWM1_BASE, EPWM_INT_TBCTR_ZERO);
//    EPWM_enableInterrupt(EPWM1_BASE);
//    EPWM_setInterruptEventCount(EPWM1_BASE, 3U);
//}


//EPWM1:
//EPWM100M时钟(默认系统时钟2分频进入epwm)
//使用了中断，中断为计数器为0的时候触发，触发时设定CLB工作模式
//设定输出的GPIO为0和1
//设定为计数器0的时候为高电平
//启用了两个比较器，计数器采样向上计数方式,计数到最大值后归0
//EPWMA计数到A的时候置低，归0后又拉高
void initEPWM1(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
//    epwm1_interrupt_set();
//EPWM1的输出GPIO设置
    GPIO_setDirectionMode(0, GPIO_DIR_MODE_OUT);//引脚设置为输出
    GPIO_setPadConfig(0, GPIO_PIN_TYPE_PULLUP);//spi_clk默认低电平，所以推挽输出
    GPIO_setPinConfig(GPIO_0_EPWM1A);//引脚复用为EPWM1A

    GPIO_setDirectionMode(1, GPIO_DIR_MODE_OUT);//引脚设置为输出
    GPIO_setPadConfig(1, GPIO_PIN_TYPE_PULLUP);//endat_clk默认高电平，上拉输出
    GPIO_setPinConfig(GPIO_1_EPWM1B);//引脚复用为EPWM1B
    //计数周期2000下
    EPWM_setTimeBasePeriod(EPWM1_BASE, EPWM1_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM1_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0U);
//在计数器0时产生中断
    EPWM_enableSyncOutPulseSource(EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM1_CMPA);
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM1_CMPB);

    EPWM_disablePhaseShiftLoad(EPWM1_BASE);
    //EPWM默认100M，设置时基计数器时钟不分频，即EPWM时钟是多少M，计数器时钟就是多少
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
//在钳位的时候进行动作
    //PWM2A在计数器0的时候置高
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM1A计数到A的时候置低
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //PWM1B计数到1的时候置低
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM1A计数到A的时候置高
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);


    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
    // start PWMs
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}


void initEPWM2(void)
{
    GPIO_setDirectionMode(2, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(2, GPIO_PIN_TYPE_STD);//推完输出或浮空输入
    GPIO_setPinConfig(GPIO_2_EPWM2A);

    GPIO_setDirectionMode(3, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(3, GPIO_PIN_TYPE_STD);//推完输出或浮空输入
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
// start PWMs
    EPWM_setTimeBaseCounterMode(EPWM2_BASE, EPWM_COUNTER_MODE_UP);
}




//EPWM1:
                //EPWM100M时钟(默认系统时钟2分频进入epwm)
                //使用了中断，中断为计数器为0的时候触发，触发时设定CLB工作模式
                //设定输出的GPIO为0和1
                //设定为计数器0的时候为高电平
                //启用了两个比较器，计数器采样向上计数方式,计数到最大值后归0
                //EPWMA计数到A的时候置低，归0后又拉高
void initEPWM4(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
//    epwm1_interrupt_set();
//EPWM1的输出GPIO设置
    GPIO_setDirectionMode(6, GPIO_DIR_MODE_OUT);//引脚设置为输出
    GPIO_setPadConfig(6, GPIO_PIN_TYPE_STD);//推完输出
    GPIO_setPinConfig(GPIO_6_EPWM4A);//引脚复用为EPWM1A

    GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);//引脚设置为输出
    GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);//推完输出
    GPIO_setPinConfig(GPIO_7_EPWM4B);//引脚复用为EPWM1B

    EPWM_setTimeBasePeriod(EPWM4_BASE, EPWM4_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM4_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM4_BASE, 0U);
//在计数器0时产生中断
    EPWM_enableSyncOutPulseSource(EPWM4_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM4_CMPA);
    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM4_CMPB);

    EPWM_disablePhaseShiftLoad(EPWM4_BASE);
    //EPWM默认100M，设置时基计数器时钟不分频，即EPWM时钟是多少M，计数器时钟就是多少
    EPWM_setClockPrescaler(EPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
//在钳位的时候进行动作
    //PWM4A在计数器0的时候置高
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM4A计数到A的时候置低
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //PWM4B计数到1的时候置低
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM4B计数到A的时候置高
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);


    EPWM_setTimeBaseCounterMode(EPWM4_BASE, EPWM_COUNTER_MODE_UP);
    // start PWMs
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

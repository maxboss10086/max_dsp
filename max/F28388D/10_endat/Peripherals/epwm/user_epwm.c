//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_epwm.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020��6��2��
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
//EPWM100Mʱ��(Ĭ��ϵͳʱ��2��Ƶ����epwm)
//ʹ�����жϣ��ж�Ϊ������Ϊ0��ʱ�򴥷�������ʱ�趨CLB����ģʽ
//�趨�����GPIOΪ0��1
//�趨Ϊ������0��ʱ��Ϊ�ߵ�ƽ
//�����������Ƚ������������������ϼ�����ʽ,���������ֵ���0
//EPWMA������A��ʱ���õͣ���0��������
void initEPWM1(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
//    epwm1_interrupt_set();
//EPWM1�����GPIO����
    GPIO_setDirectionMode(0, GPIO_DIR_MODE_OUT);//��������Ϊ���
    GPIO_setPadConfig(0, GPIO_PIN_TYPE_PULLUP);//spi_clkĬ�ϵ͵�ƽ�������������
    GPIO_setPinConfig(GPIO_0_EPWM1A);//���Ÿ���ΪEPWM1A

    GPIO_setDirectionMode(1, GPIO_DIR_MODE_OUT);//��������Ϊ���
    GPIO_setPadConfig(1, GPIO_PIN_TYPE_PULLUP);//endat_clkĬ�ϸߵ�ƽ���������
    GPIO_setPinConfig(GPIO_1_EPWM1B);//���Ÿ���ΪEPWM1B
    //��������2000��
    EPWM_setTimeBasePeriod(EPWM1_BASE, EPWM1_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM1_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0U);
//�ڼ�����0ʱ�����ж�
    EPWM_enableSyncOutPulseSource(EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM1_CMPA);
    EPWM_setCounterCompareValue(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM1_CMPB);

    EPWM_disablePhaseShiftLoad(EPWM1_BASE);
    //EPWMĬ��100M������ʱ��������ʱ�Ӳ���Ƶ����EPWMʱ���Ƕ���M��������ʱ�Ӿ��Ƕ���
    EPWM_setClockPrescaler(EPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
//��ǯλ��ʱ����ж���
    //PWM2A�ڼ�����0��ʱ���ø�
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM1A������A��ʱ���õ�
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //PWM1B������1��ʱ���õ�
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM1A������A��ʱ���ø�
    EPWM_setActionQualifierAction(EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);


    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
    // start PWMs
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}


void initEPWM2(void)
{
    GPIO_setDirectionMode(2, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(2, GPIO_PIN_TYPE_STD);//��������򸡿�����
    GPIO_setPinConfig(GPIO_2_EPWM2A);

    GPIO_setDirectionMode(3, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(3, GPIO_PIN_TYPE_STD);//��������򸡿�����
    GPIO_setPinConfig(GPIO_3_EPWM2B);

    EPWM_setTimeBasePeriod(EPWM2_BASE, EPWM2_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM2_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM2_BASE, 0U);

    EPWM_enablePhaseShiftLoad(EPWM2_BASE);
    EPWM_setPhaseShift(EPWM2_BASE, 0U);
//ʹ�ñȽ�ǯλA��ǯλB��ǯλA��ֵΪ1333��ǯλB��ֵΪ667
    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM2_CMPA);
    EPWM_setCounterCompareValue(EPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM2_CMPB);

    EPWM_setClockPrescaler(EPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
//��ǯλ��ʱ����ж���
    //PWM2A�ڼ�����0��ʱ���ø�
    EPWM_setActionQualifierAction(EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM2A������A��ʱ���õ�
    EPWM_setActionQualifierAction(EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //PWM2B������B��ʱ��ת
    EPWM_setActionQualifierAction(EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_TOGGLE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
// start PWMs
    EPWM_setTimeBaseCounterMode(EPWM2_BASE, EPWM_COUNTER_MODE_UP);
}




//EPWM1:
                //EPWM100Mʱ��(Ĭ��ϵͳʱ��2��Ƶ����epwm)
                //ʹ�����жϣ��ж�Ϊ������Ϊ0��ʱ�򴥷�������ʱ�趨CLB����ģʽ
                //�趨�����GPIOΪ0��1
                //�趨Ϊ������0��ʱ��Ϊ�ߵ�ƽ
                //�����������Ƚ������������������ϼ�����ʽ,���������ֵ���0
                //EPWMA������A��ʱ���õͣ���0��������
void initEPWM4(void)
{
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
//    epwm1_interrupt_set();
//EPWM1�����GPIO����
    GPIO_setDirectionMode(6, GPIO_DIR_MODE_OUT);//��������Ϊ���
    GPIO_setPadConfig(6, GPIO_PIN_TYPE_STD);//�������
    GPIO_setPinConfig(GPIO_6_EPWM4A);//���Ÿ���ΪEPWM1A

    GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);//��������Ϊ���
    GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);//�������
    GPIO_setPinConfig(GPIO_7_EPWM4B);//���Ÿ���ΪEPWM1B

    EPWM_setTimeBasePeriod(EPWM4_BASE, EPWM4_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM4_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM4_BASE, 0U);
//�ڼ�����0ʱ�����ж�
    EPWM_enableSyncOutPulseSource(EPWM4_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);

    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM4_CMPA);
    EPWM_setCounterCompareValue(EPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM4_CMPB);

    EPWM_disablePhaseShiftLoad(EPWM4_BASE);
    //EPWMĬ��100M������ʱ��������ʱ�Ӳ���Ƶ����EPWMʱ���Ƕ���M��������ʱ�Ӿ��Ƕ���
    EPWM_setClockPrescaler(EPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);
//��ǯλ��ʱ����ж���
    //PWM4A�ڼ�����0��ʱ���ø�
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM4A������A��ʱ���õ�
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    //PWM4B������1��ʱ���õ�
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    //PWM4B������A��ʱ���ø�
    EPWM_setActionQualifierAction(EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);


    EPWM_setTimeBaseCounterMode(EPWM4_BASE, EPWM_COUNTER_MODE_UP);
    // start PWMs
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

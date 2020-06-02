//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    SPIB��Ϊ������SPIA��Ϊ�ӻ���������
// Author:          Max
// Creation Date:   2020��5��22��
//----------------------------------------------------------------------------------------//
//note: 1�жϵ����ã���ʣ�����ݶ���������SPI��ʱ���ͺ�ʱ���գ���������CPU�������ʽ�������ʱSPI����
//
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"
//
#include "user_epwm.h"
#include "user_clb.h"

//

// Main
void main(void)
{
//***********************************************ϵͳ��ʼ��**********************************\\
// Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();

//***********************************************�����ʼ������**********************************\\
//
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    initEPWM1();//EPWM1:
                //ʹ�����жϣ��ж�Ϊ������Ϊ0��ʱ�򴥷�������ʱ�趨CLB����ģʽ
                //�趨�����GPIOΪ0��1
                //�趨Ϊ������0��ʱ��Ϊ�ߵ�ƽ
                //�����������Ƚ������������������ϼ�����ʽ
                //EPWMA������A��ʱ���õͣ�EPWMB������B��ʱ��ת��ƽ
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);

    clb1_init_set();//ģʽ0��clb���޸������epwm����ֱ�����
                    //ģʽ1������������PWMͬʱ�͵�ƽ��ŵ���־ͷ�ת
                    //ģʽ2������������PWMͬʱ���ָߵ�ƽ��ŵ���־ͷ�ת
                    //ģʽ3��������״
                    //23���룬����EPWM�����źţ�12����Ϊģʽѡ�񣬲���GP_REG�ź�
                    //4���������clb���п�ŵͼ����
EINT;
////***********************************************����ִ��***************************************\\
////����ִ��
//
//
     while(1){

       }
//
//
//
//
//
//
//
//
//

}

//
// End of File
//

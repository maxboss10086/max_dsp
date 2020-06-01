//****************************************Copyright (c)***********************************//
// ��վ����: NC
// ��Ȩ����, ����ؾ�
// Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
// File name:       xxx.v
// Descriptions:    ������оƬ�������ݣ�оƬ���յ����ݺ�����Է�����ͬ������
// Author:          Max
// Creation Date:   Wed May 06 2020 11:45:09 GMT+0800
//----------------------------------------------------------------------------------------//
// Note:
//
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include <F2838X_lib/device/device.h>//��������
#include <F2838X_lib/device/driverlib.h>
//
#include "led.h"
//
//***********************************************main*********************************************************\\
//
void main(void)
{
//    // Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    Interrupt_initModule();
//      // Initialize the PIE vector table with pointers to the shell Interrupt
//      // Service Routines (ISR).
    Interrupt_initVectorTable();
//      // Enables CPU interrupts
//    Interrupt_enableMaster();
    EINT;
    ERTM;

//***********************************************�����ʼ������**********************************\\
//��GPIO34��Ϊ����led��
    led_init_set();
//***********************************************����ִ��***************************************\\
//����ִ��
    while(1) {

        led_H();//��������Ҫ������

        DEVICE_DELAY_US(500000);

        led_L();

        DEVICE_DELAY_US(500000);
    }











}

//
// End of File
//

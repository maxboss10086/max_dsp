//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    ��λ����оƬ�������ݣ��������κ󣬴���FIFO�жϣ���ȡFIFO�е����ݴ���rData���飬ʹFIFOΪ��
// Author:          Max
// Creation Date:   2020��5��22��
//----------------------------------------------------------------------------------------//
//note:������initSCIAFIFO�������Ͷ�����FIFO�е�����
//
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
//
#include "user_led.h"

// Main
void main(void)
{
//***********************************************ϵͳ��ʼ��**********************************\\
// Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();
    EINT;
    ERTM;

//***********************************************�����ʼ������**********************************\\

    led_init_set();

//***********************************************����ִ��***************************************\\
//����ִ��

     while(1){
         led_H();//��������Ҫ������

         DEVICE_DELAY_US(500000);

         led_L();

         DEVICE_DELAY_US(500000);
       }










}

//
// End of File
//

//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    SPIa��Ϊ������SPIb��Ϊ�ӻ���������,spib�����жϽ�������
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
//
#include "user_led.h"
#include "user_spi.h"
#include "user_interrupt.h"
//

uint16_t    spi_data=0;
uint16_t    receive_data=0;
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


//SPIa����Ϊ������ʱ��500k������16λ
//SPIaģʽRising edge without delay.
//GPIO19 is the SPIASTE
//GPIO18 is the SPIACLK
//GPIO16 is the SPIASIMO.
//GPIO17 is the SPIASOMI.
//û���ж�
    SPIa_init_set();
//SPIb����Ϊ�ӻ���ʱ��500k������16λ
//SPIbģʽRising edge without delay.
//GPIO27 is the SPIBSTE
//GPIO26 is the SPIBCLK
//GPIO24 is the SPIBSIMO.
//GPIO25 is the SPIBSOMI.
//����2��16λFIFO�󣬿����ж϶�ȡ����
    SPIb_init_set();
EINT;
ERTM;
//***********************************************����ִ��***************************************\\
//����ִ��

//
     while(1){
         //0x88=0000_0000_1000_1000
         spia_send_data(spi_data);//���͵���16λ���ݣ�δ��16λǰ���Զ���
         DEVICE_DELAY_US(500000);
         spi_data=spi_data+1;
         spia_send_data(spi_data);
         DEVICE_DELAY_US(500000);
       }








}

//
// End of File
//

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
//
#include "user_led.h"
#include "user_spi.h"
#include "user_interrupt.h"
//
uint16_t  receivedChar;
bool      ack_data;

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


//SPIa����Ϊ������ʱ��1M������16λ
//SPIaģʽRising edge without delay.
//GPIO19 is the SPIASTE
//GPIO18 is the SPIACLK
//GPIO16 is the SPIASIMO.
//GPIO17 is the SPIASOMI.
//û���ж�
    SPIa_init_set();
EINT;
ERTM;
//***********************************************����ִ��***************************************\\
//����ִ��

//for(spi_i = 0; spi_i < 2; spi_i++)
//{
//    spib_sData[spi_i] = spi_i;
//    spia_rData[spi_i]= 0;
//}
     while(1){
         //0x88=0000_0000_1000_1000
         spia_send_data(0x88);//���͵���16λ���ݣ�δ��16λǰ���Զ���
         DEVICE_DELAY_US(500000);
       }










}

//
// End of File
//

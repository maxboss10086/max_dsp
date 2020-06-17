//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    ������
// Author:          Max
// Creation Date:   2020��5��24��
//----------------------------------------------------------------------------------------//
//note: ����CLBʱ����ʼ��DMA�ᱨ�ڴ����

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"
//
#include "user_led.h"
#include "user_epwm.h"
#include "user_clb.h"
#include "user_spi.h"
#include "user_gpio.h"
#include "endat_cmd.h"
#include "user_dma.h"


//
// Main
//

uint16_t    i=0;
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
//GPIO66 is the SPIBSTE
//GPIO65 is the SPIBCLK
//GPIO63 is the SPIBSIMO.
//GPIO64 is the SPIBSOMI.
//����2��16λFIFO�󣬿����ж϶�ȡ����
    SPIb_init_set();
EINT;
ERTM;
//***********************************************����ִ��***************************************\\
//����ִ��


    spia_sData[0] = 0xaa;
    spib_rData[i]= 0;

//���ú�Ҫ���͵����ݺ���ʹ��SPI�жϣ���SPIͣ�£�CPU����������FIFO
SPI_enableInterrupt(SPIA_BASE, SPI_INT_TXFF);

     while(1){

       }


}



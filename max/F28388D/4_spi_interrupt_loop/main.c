//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    主函数
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//
//note: 启用CLB时，初始化DMA会报内存错误

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
//***********************************************系统初始化**********************************\\
// Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();

//***********************************************外设初始化设置**********************************\\


//SPIa设置为主机，时钟500k，数据16位
//SPIa模式Rising edge without delay.
//GPIO19 is the SPIASTE
//GPIO18 is the SPIACLK
//GPIO16 is the SPIASIMO.
//GPIO17 is the SPIASOMI.
//没有中断
    SPIa_init_set();
//SPIb设置为从机，时钟500k，数据16位
//SPIb模式Rising edge without delay.
//GPIO66 is the SPIBSTE
//GPIO65 is the SPIBCLK
//GPIO63 is the SPIBSIMO.
//GPIO64 is the SPIBSOMI.
//填满2个16位FIFO后，开启中断读取数据
    SPIb_init_set();
EINT;
ERTM;
//***********************************************函数执行***************************************\\
//函数执行


    spia_sData[0] = 0xaa;
    spib_rData[i]= 0;

//设置好要发送的数据后，再使能SPI中断，令SPI停下，CPU将数据填入FIFO
SPI_enableInterrupt(SPIA_BASE, SPI_INT_TXFF);

     while(1){

       }


}



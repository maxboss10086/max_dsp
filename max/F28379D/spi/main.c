//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    SPIB作为主机向SPIA作为从机发送数据
// Author:          Max
// Creation Date:   2020年5月22日
//----------------------------------------------------------------------------------------//
//note: 1中断的作用，用剩余数据多少来控制SPI何时发送何时接收，而不是以CPU命令的形式来命令何时SPI启动
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
//***********************************************系统初始化**********************************\\
// Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();

//***********************************************外设初始化设置**********************************\\


//SPIa设置为主机，时钟1M，数据16位
//SPIa模式Rising edge without delay.
//GPIO19 is the SPIASTE
//GPIO18 is the SPIACLK
//GPIO16 is the SPIASIMO.
//GPIO17 is the SPIASOMI.
//没有中断
    SPIa_init_set();
EINT;
ERTM;
//***********************************************函数执行***************************************\\
//函数执行

//for(spi_i = 0; spi_i < 2; spi_i++)
//{
//    spib_sData[spi_i] = spi_i;
//    spia_rData[spi_i]= 0;
//}
     while(1){
         //0x88=0000_0000_1000_1000
         spia_send_data(0x88);//发送的是16位数据，未满16位前面自动补
         DEVICE_DELAY_US(500000);
       }










}

//
// End of File
//

//****************************************Copyright (c)***********************************//
// 网站博客: NC
// 版权所有, 盗版必究
// Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
// File name:       xxx.v
// Descriptions:    串口向芯片发送数据，芯片接收到数据后向电脑发送相同的数据
// Author:          Max
// Creation Date:   Wed May 06 2020 11:45:09 GMT+0800
//----------------------------------------------------------------------------------------//
// Note:
//
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include <F2838X_lib/device/device.h>//引入外设
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

//***********************************************外设初始化设置**********************************\\
//将GPIO34作为控制led灯
    led_init_set();
//***********************************************函数执行***************************************\\
//无限执行
    while(1) {

        led_H();//函数调用要加括号

        DEVICE_DELAY_US(500000);

        led_L();

        DEVICE_DELAY_US(500000);
    }











}

//
// End of File
//

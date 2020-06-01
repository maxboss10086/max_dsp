//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    上位机向芯片发送数据，发送两次后，触发FIFO中断，读取FIFO中的数据存入rData数组，使FIFO为空
// Author:          Max
// Creation Date:   2020年5月22日
//----------------------------------------------------------------------------------------//
//note:不启用initSCIAFIFO函数，就读不到FIFO中的数据
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
//***********************************************系统初始化**********************************\\
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

//***********************************************外设初始化设置**********************************\\

    led_init_set();

//***********************************************函数执行***************************************\\
//函数执行

     while(1){
         led_H();//函数调用要加括号

         DEVICE_DELAY_US(500000);

         led_L();

         DEVICE_DELAY_US(500000);
       }










}

//
// End of File
//

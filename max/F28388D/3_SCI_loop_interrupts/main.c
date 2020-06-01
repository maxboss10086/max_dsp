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
#include <F2838X_lib/device/device.h>//引入外设
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/common_include/f28x_project.h>
#include <stdbool.h>
//
#include "user_scl.h"
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
    EINT;
    ERTM;

//***********************************************外设初始化设置**********************************\\
//串口设置为9600,接收和发送串口都打开
//scia中断设置为小于2个直接启动发送中断，多于两个字节启动接收中断
    scia_init_set();


//***********************************************函数执行***************************************\\
//函数执行

     while(1){
            ack_data=sci_reveive_ack();
            while(!sci_reveive_ack()){
                //没有响应则一直停留在这
            }
    // 接收到数据之后,读取FIFO中的数据
       }










}

//
// End of File
//

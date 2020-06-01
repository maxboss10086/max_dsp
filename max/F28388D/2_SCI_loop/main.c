//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020年5月22日
//----------------------------------------------------------------------------------------//
//note:不启用initSCIAFIFO函数，就读不到FIFO中的数据

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

//
// Included Files
//
#include <F2838X_lib/device/device.h>//引入外设
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/common_include/f28x_project.h>
//
#include "user_scl.h"
//
uint16_t  receivedChar;
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
//      // Initialize the PIE vector table with pointers to the shell Interrupt
//      // Service Routines (ISR).
    Interrupt_initVectorTable();
//      // Enables CPU interrupts
    Interrupt_enableMaster();
    EINT;
    ERTM;



//***********************************************外设初始化设置**********************************\\
//串口设置为9600,接收和发送串口都打开，发送FIFO为空开启中断，接收到4字节开启中断
    scia_init_set();
//***********************************************函数执行***************************************\\
//函数执行

     while(1){
            while(SCI_getRxFIFOStatus(SCIA_BASE) == SCI_FIFO_RX0){
                //读取 接收FIFO的状态寄存器，判定是否为空，如果FIFO一直是空则一直等待，如果读到了数据就跳出来
            }
    // 接收到数据之后，读取FIFO中的数据
       receivedChar = scia_receive();
       scia_send(receivedChar);//读取FIFO中的数据进行发送
       }










}

//
// End of File
//

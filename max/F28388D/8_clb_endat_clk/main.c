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
#include "user_interrupt.h"
//
#include "user_epwm.h"
#include "user_clb.h"
#include "user_spi.h"
//

// Main
void main(void)
{
//***********************************************系统初始化**********************************\\
// Initialize device clock and peripherals
    // PLLSYSCLK = 20MHz (XTAL_OSC) * 40 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 1(SYSDIV))=200M
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();

//***********************************************外设初始化设置**********************************\\
//


    initEPWM1();//EPWM1:
                //EPWM100M时钟(默认系统时钟2分频进入epwm)
                //使用了中断，中断为计数器为0的时候触发，触发时设定CLB工作模式
                //设定输出的GPIO为0和1
                //设定为计数器0的时候为高电平
                //启用了两个比较器，计数器采样向上计数方式,计数到最大值后归0
                //EPWMA计数到A的时候置低，归0后又拉高

    clb1_init_set();//时钟200M
                    //状态机S0低电平时输出时钟，S0高电平不输出时钟
                    //23输入，采样EPWM输入信号，12输入为模式选择，采用GP_REG信号
                    //4个输入进入clb进行卡诺图运算

    SPIb_init_set();//SPIB设定为从机
                    //设置SPI时钟为1M，时钟个数是16个
                    //时钟默认低电平，下降沿接收数据
                    //GPIO66是cs_n,GPIO65是scl,GPIO63是mosi,GPIO64是miso

EINT;
////***********************************************函数执行***************************************\\
////函数执行
//
//
     while(1){

       }
//
//
//
//
//
//
//
//
//

}

//
// End of File
//

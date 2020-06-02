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

//

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
//
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    initEPWM1();//EPWM1:
                //使用了中断，中断为计数器为0的时候触发，触发时设定CLB工作模式
                //设定输出的GPIO为0和1
                //设定为计数器0的时候为高电平
                //启用了两个比较器，计数器采样向上计数方式
                //EPWMA计数到A的时候置低，EPWMB计数到B的时候反转电平
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);

    clb1_init_set();//模式0：clb不修改输入的epwm波形直接输出
                    //模式1：不允许两个PWM同时低电平，诺出现就反转
                    //模式2：不允许两个PWM同时出现高电平，诺出现就反转
                    //模式3：保留现状
                    //23输入，采样EPWM输入信号，12输入为模式选择，采用GP_REG信号
                    //4个输入进入clb进行卡诺图运算
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

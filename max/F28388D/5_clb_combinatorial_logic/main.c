//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    EPWM信号输入clb，且在每次epwm计数器0时产生中断，是否改变clb的逻辑模式
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

uint32_t clock;
//

// Main
void main(void)
{
//***********************************************系统初始化**********************************\\
// Initialize device clock and peripherals
    //得到系统时钟200M
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();

//***********************************************外设初始化设置**********************************\\
//

    initEPWM1();//EPWM1:
                //默认系统时钟2分频，系统时钟200M
                //使用了中断，中断为计数器为0的时候触发，触发时设定CLB工作模式
                //设定输出的GPIO为0和1
                //设定为计数器0的时候为高电平
                //启用了两个比较器，计数器采样向上计数方式
                //EPWMA计数到A的时候置低，EPWMB计数到B的时候反转电平

    clb1_init_set();//时钟100M
                    //模式0：clb不修改输入的epwm波形直接输出
                    //模式1：不允许两个PWM同时低电平，诺出现就反转
                    //模式2：不允许两个PWM同时出现高电平，诺出现就反转
                    //模式3：保留现状
                    //in2和in3输入，采样EPWM输入信号，in0和in1输入为模式选择，采用GP_REG信号
                    //4个输入进入clb进行卡诺图运算
EINT;
////***********************************************函数执行***************************************\\
////函数执行
//
//
     while(1){
         clock = SysCtl_getClock(20000000);//调试中确认系统时钟
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

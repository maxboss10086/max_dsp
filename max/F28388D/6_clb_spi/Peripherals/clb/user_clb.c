//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_clb.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020年6月1日
//----------------------------------------------------------------------------------------//
//note:CLB默认输出信号从模块输出，诺想要CLB产生的信号直接用GPIO输出，就要用xbar

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"
#include "clb_config.h"
#include "clb.h"

#include "user_clb.h"


//clb1设置：
//模式0：clb不修改输入的epwm波形直接输出
//模式1：不允许两个PWM同时低电平，诺出现就反转
//模式2：不允许两个PWM同时出现高电平，诺出现就反转
//模式3：保留现状
//模式在user_clb.h中设置
//23输入，采样EPWM输入信号，12输入为模式选择，采用GP_REG信号
//4个输入进入clb进行卡诺图运算

void clb1_init_set(){
    CLB_enableCLB(CLB1_BASE);
    initTILE1(CLB1_BASE);

    // Inputs set to GP register
    //选择使用外部信号还是寄存器GP_REG信号
    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);//clb以EPWM的下降沿计数
    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);//没有时钟时的默认电平
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);//输入epwm经过修改得到endat_clk
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);//输入epwm经过修改得到spi_clk
    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);//控制信号，低电平时输出修改时钟，高电平时输出0
    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_GP_REG);
    //
    // Select Global input instead of local input for all CLB IN
    //使用全局输入，不使用本地输入
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);

    //全局输入的in2和in3输入EPWM1的信号
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM1_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM1_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM1_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_EPWM1_CTRDIR);

//设置CLB状态机
    CLB_setGPREG(CLB1_BASE, clb_mode);//设置输入CLB的信号

//将clb的out4输出接入output xabr
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_OUT_MUX01_CLB1_OUT4);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_MUX01);

// 将GPIO9设置为output xbar，信号就从GPIO9输出
    GPIO_setDirectionMode(9, GPIO_DIR_MODE_OUT);//配置为输出模式
    GPIO_setPadConfig(9, GPIO_PIN_TYPE_STD);//推完输出
    GPIO_setPinConfig(GPIO_9_OUTPUTXBAR6);//引脚复用为outxbar


 //设置CLB的输出
    //1的时候使能CLB输出，0不是能CLB输出
    //为什么时out0和out2接入epwm的输出
    CLB_setOutputMask(CLB1_BASE, 0x5, true);//0xb=0101
}

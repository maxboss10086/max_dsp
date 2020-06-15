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
#include "endat_cmd.h"


//unsigned char clb_input = 0x01;//0000_0001,in0输入1，使得时钟默认为高电平

void clb1_used_input_init_set(void){
    //CLB输入信号
        //EPWMA信号输入in2
        CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);//输入epwm经过修改得到endat_clk
        CLB_configLocalInputMux(CLB1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
        CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
        CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);

        //EPWMB信号输入in3
        CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);//输入epwm经过修改得到spi_clk
        CLB_configLocalInputMux(CLB1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);

        //GPIO62接入in6用作endat启动信号
        //1输入端口复用为GPIO
        GPIO_setMasterCore(62, GPIO_CORE_CPU1);
        GPIO_setPinConfig(GPIO_62_GPIO62);
        GPIO_setPadConfig(62, GPIO_PIN_TYPE_PULLUP);
        //GPIO62信号接入input-xbar
        XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT2, 62);
        //input-xbar接入clb_xbar
        XBAR_setCLBMuxConfig(XBAR_AUXSIG1, XBAR_CLB_MUX03_INPUTXBAR2);
        XBAR_enableCLBMux(XBAR_AUXSIG1, XBAR_MUX03);
        //GPIO62信号输入clb设置
        CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_EXTERNAL);
        CLB_configLocalInputMux(CLB1_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
        CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_CLB_AUXSIG1);

        //GPIO63接入in7是endat数据线返回的S位高电平，使得clb生成时钟
        //GPIO63端口复用为SPI，所以不用设置
        //GPIO63信号接入input-xbar
        XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 63);
        //input-xbar接入clb_xbar
        XBAR_setCLBMuxConfig(XBAR_AUXSIG0, XBAR_CLB_MUX01_INPUTXBAR1);
        XBAR_enableCLBMux(XBAR_AUXSIG0, XBAR_MUX01);
        //GPIO63信号输入clb设置
        CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_EXTERNAL);
        CLB_configLocalInputMux(CLB1_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);
        CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);//外来信号接入clb_xbar


}

void clb1_output_xbar_init_set(void){
    //clb输出信号
        //将clb的out4输出接入output xabr
        XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_OUT_MUX01_CLB1_OUT4);
        XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_MUX01);
        //将GPIO9复用为output xbar，信号就从GPIO9输出
        GPIO_setDirectionMode(9, GPIO_DIR_MODE_OUT);//配置为输出模式
        GPIO_setPadConfig(9, GPIO_PIN_TYPE_STD);//推完输出
        GPIO_setPinConfig(GPIO_9_OUTPUTXBAR6);//引脚复用为outxbar

        //将clb的out5输出接入output xabr
        XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT5, XBAR_OUT_MUX03_CLB1_OUT5);
        XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT5, XBAR_MUX03);
        //将GPIO7复用为output xbar，信号就从GPIO7输出
        GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);//配置为输出模式
        GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);//推完输出
        GPIO_setPinConfig(GPIO_7_OUTPUTXBAR5);//引脚复用为outxbar
}
void clb1_no_used_input_init_set(void){
    // Inputs set to GP register
    //选择使用外部信号还是寄存器GP_REG信号
    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);//clb以EPWM的高电平递增，以EPWM的电平递减
    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);//没有时钟时的默认电平
    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);//控制信号，低电平时输出修改时钟，高电平时输出0
    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    //
    // Select Global input instead of local input for all CLB IN
    //使用全局输入，不使用本地输入
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);

    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}



//clb1设置：
//时钟100M
void clb1_init_set(){

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    //clb不使能中断
//    clb1_interrupt_set();
    CLB_enableCLB(CLB1_BASE);
    initTILE1(CLB1_BASE);

    clb1_no_used_input_init_set();

//用GP_REG寄存器设置clb的输入0-7的输入信号
    CLB_setGPREG(CLB1_BASE, clb_input);//设置输入CLB的信号

    clb1_used_input_init_set();//

    clb1_output_xbar_init_set();//out4接入GPIO9，用以控制数据收发

 //设置CLB的输出
    //选择CLB修改后的模块信号(如EPWM)从哪个out出去，该函数管不到xbar
    CLB_setOutputMask(CLB1_BASE, 0x5, true);//0xb=0101
}












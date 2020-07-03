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


void clb1_in0_init_set(){
//    GPIO_setPadConfig(2, GPIO_PIN_TYPE_PULLUP);
//    GPIO_setDirectionMode(16, GPIO_DIR_MODE_IN);//16引脚配置为上拉输出模式
//    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT3, 2);
//    //input-xbar接入clb_xbar
//    XBAR_setCLBMuxConfig(XBAR_AUXSIG1, XBAR_CLB_MUX05_INPUTXBAR3);
//    XBAR_enableCLBMux(XBAR_AUXSIG1, XBAR_MUX05);

    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);//endat时钟的默认电平
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG1);
}
void clb1_in1_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);//
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}
void clb1_in2_init_set(){

    //EPWMA信号输入in2
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);//输入epwm经过修改得到endat_clk
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
}

void clb1_in3_init_set(){

    //EPWMB信号输入in3
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);//输入epwm经过修改得到spi_clk
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);
}
//还没用到
void clb1_in4_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//还没用到
void clb1_in5_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//还没用到
void clb1_in6_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//编码器的输入线接入clb的in7
void clb1_in7_init_set(){

    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 63);
    //input-xbar接入clb_xbar
    XBAR_setCLBMuxConfig(XBAR_AUXSIG0, XBAR_CLB_MUX01_INPUTXBAR1);
    XBAR_enableCLBMux(XBAR_AUXSIG0, XBAR_MUX01);
    //GPIO63信号输入clb设置
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_EXTERNAL);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);//外来信号接入clb_xbar
}


//设置CLB的输入信号，如果不使用GPIO外部输入信号，那么就用GPREG的寄存器值作为输入信号
void clb1_input_init_set(){
    CLB_setGPREG(CLB1_BASE, clb_input);
    clb1_in0_init_set();
    clb1_in1_init_set();
    clb1_in2_init_set();
    clb1_in3_init_set();
    clb1_in4_init_set();
    clb1_in5_init_set();
    clb1_in6_init_set();
    clb1_in7_init_set();
}

void clb1_ou4_init_set(){
    //将clb的out4输出接入output xabr
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_OUT_MUX01_CLB1_OUT4);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_MUX01);
    //将GPIO9复用为output xbar，信号就从GPIO9输出
    GPIO_setDirectionMode(9, GPIO_DIR_MODE_OUT);//配置为输出模式
    GPIO_setPadConfig(9, GPIO_PIN_TYPE_STD);//推完输出
    GPIO_setPinConfig(GPIO_9_OUTPUTXBAR6);//引脚复用为outxbar
}

void clb1_ou5_init_set(){

    //将clb的out5输出接入output xabr
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT5, XBAR_OUT_MUX03_CLB1_OUT5);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT5, XBAR_MUX03);
    //将GPIO7复用为output xbar，信号就从GPIO7输出
    GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);//配置为输出模式
    GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);//推完输出
    GPIO_setPinConfig(GPIO_7_OUTPUTXBAR5);//引脚复用为outxbar
}
//设置CLB的输出,clb修改模块的信号，用CLB_setOutputMask函数输出
//clb自己经过逻辑产生的信号，用outxbar输出
void clb1_output_init_set(){
    clb1_ou4_init_set();
    clb1_ou5_init_set();
       //选择CLB修改后的模块信号(如EPWM)从哪个out出去，该函数管不到xbar
    CLB_setOutputMask(CLB1_BASE, 0x5, true);//0xb=0101
}

void clb1_init_set(){

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    //clb不使能中断
//    clb1_interrupt_set();
    CLB_enableCLB(CLB1_BASE);
    initTILE1(CLB1_BASE);

    clb1_input_init_set();
    clb1_output_init_set();//out4接入GPIO9，用以控制数据收发
}












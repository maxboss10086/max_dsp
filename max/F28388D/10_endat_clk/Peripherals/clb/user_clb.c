//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_clb.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020��6��1��
//----------------------------------------------------------------------------------------//
//note:CLBĬ������źŴ�ģ�������ŵ��ҪCLB�������ź�ֱ����GPIO�������Ҫ��xbar

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
//    GPIO_setDirectionMode(16, GPIO_DIR_MODE_IN);//16��������Ϊ�������ģʽ
//    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT3, 2);
//    //input-xbar����clb_xbar
//    XBAR_setCLBMuxConfig(XBAR_AUXSIG1, XBAR_CLB_MUX05_INPUTXBAR3);
//    XBAR_enableCLBMux(XBAR_AUXSIG1, XBAR_MUX05);

    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_GP_REG);//endatʱ�ӵ�Ĭ�ϵ�ƽ
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG1);
}
void clb1_in1_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);//
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}
void clb1_in2_init_set(){

    //EPWMA�ź�����in2
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);//����epwm�����޸ĵõ�endat_clk
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
}

void clb1_in3_init_set(){

    //EPWMB�ź�����in3
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);//����epwm�����޸ĵõ�spi_clk
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);
}
//��û�õ�
void clb1_in4_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//��û�õ�
void clb1_in5_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//��û�õ�
void clb1_in6_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//�������������߽���clb��in7
void clb1_in7_init_set(){

    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 63);
    //input-xbar����clb_xbar
    XBAR_setCLBMuxConfig(XBAR_AUXSIG0, XBAR_CLB_MUX01_INPUTXBAR1);
    XBAR_enableCLBMux(XBAR_AUXSIG0, XBAR_MUX01);
    //GPIO63�ź�����clb����
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_EXTERNAL);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);//�����źŽ���clb_xbar
}


//����CLB�������źţ������ʹ��GPIO�ⲿ�����źţ���ô����GPREG�ļĴ���ֵ��Ϊ�����ź�
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
    //��clb��out4�������output xabr
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_OUT_MUX01_CLB1_OUT4);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_MUX01);
    //��GPIO9����Ϊoutput xbar���źžʹ�GPIO9���
    GPIO_setDirectionMode(9, GPIO_DIR_MODE_OUT);//����Ϊ���ģʽ
    GPIO_setPadConfig(9, GPIO_PIN_TYPE_STD);//�������
    GPIO_setPinConfig(GPIO_9_OUTPUTXBAR6);//���Ÿ���Ϊoutxbar
}

void clb1_ou5_init_set(){

    //��clb��out5�������output xabr
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT5, XBAR_OUT_MUX03_CLB1_OUT5);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT5, XBAR_MUX03);
    //��GPIO7����Ϊoutput xbar���źžʹ�GPIO7���
    GPIO_setDirectionMode(7, GPIO_DIR_MODE_OUT);//����Ϊ���ģʽ
    GPIO_setPadConfig(7, GPIO_PIN_TYPE_STD);//�������
    GPIO_setPinConfig(GPIO_7_OUTPUTXBAR5);//���Ÿ���Ϊoutxbar
}
//����CLB�����,clb�޸�ģ����źţ���CLB_setOutputMask�������
//clb�Լ������߼��������źţ���outxbar���
void clb1_output_init_set(){
    clb1_ou4_init_set();
    clb1_ou5_init_set();
       //ѡ��CLB�޸ĺ��ģ���ź�(��EPWM)���ĸ�out��ȥ���ú����ܲ���xbar
    CLB_setOutputMask(CLB1_BASE, 0x5, true);//0xb=0101
}

void clb1_init_set(){

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    //clb��ʹ���ж�
//    clb1_interrupt_set();
    CLB_enableCLB(CLB1_BASE);
    initTILE1(CLB1_BASE);

    clb1_input_init_set();
    clb1_output_init_set();//out4����GPIO9�����Կ��������շ�
}












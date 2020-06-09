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

void clb1_input_xbar_init_set(void){
    //CLB�����ź�
        //GPIO63�źŽ���input-xbar
        XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 63);
        //input-xbar����clb_xbar
        XBAR_setCLBMuxConfig(XBAR_AUXSIG0, XBAR_CLB_MUX01_INPUTXBAR1);
        //clb-xabr����clb��in7
        CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);
        XBAR_enableCLBMux(XBAR_AUXSIG0, XBAR_MUX01);
}

void clb1_output_xbar_init_set(void){
    //clb����ź�
        //��clb��out4�������output xabr
        XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_OUT_MUX01_CLB1_OUT4);
        XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT6, XBAR_MUX01);
        //��GPIO9����Ϊoutput xbar���źžʹ�GPIO9���
        GPIO_setDirectionMode(9, GPIO_DIR_MODE_OUT);//����Ϊ���ģʽ
        GPIO_setPadConfig(9, GPIO_PIN_TYPE_STD);//�������
        GPIO_setPinConfig(GPIO_9_OUTPUTXBAR6);//���Ÿ���Ϊoutxbar
}


//clb1���ã�
//ʱ��100M
//״̬��S0�͵�ƽʱ���ʱ�ӣ�S0�ߵ�ƽ�����ʱ��
//23���룬����EPWM�����źţ�12����Ϊģʽѡ�񣬲���GP_REG�ź�
//4���������clb���п�ŵͼ����
void clb1_init_set(){

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    //clbʹ���ж�
    clb1_interrupt_set();
    CLB_enableCLB(CLB1_BASE);
    initTILE1(CLB1_BASE);

    // Inputs set to GP register
    //ѡ��ʹ���ⲿ�źŻ��ǼĴ���GP_REG�ź�
    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);//clb��EPWM�ĸߵ�ƽ��������EPWM�ĵ�ƽ�ݼ�
    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);//û��ʱ��ʱ��Ĭ�ϵ�ƽ
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_EXTERNAL);//����epwm�����޸ĵõ�endat_clk
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_EXTERNAL);//����epwm�����޸ĵõ�spi_clk
    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);//�����źţ��͵�ƽʱ����޸�ʱ�ӣ��ߵ�ƽʱ���0
    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_EXTERNAL);
    //
    // Select Global input instead of local input for all CLB IN
    //ʹ��ȫ�����룬��ʹ�ñ�������
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);

    //ȫ�������in2��in3����EPWM1���ź�
    //ȫ�������in7ѡ��clb_xbar�����ź�
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
//    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);//�����źŽ���clb_xbar

//��GP_REG�Ĵ�������clb������0-7�������ź�
    CLB_setGPREG(CLB1_BASE, clb_mode);//��������CLB���ź�

    clb1_input_xbar_init_set();//GPIO63����in7�����CLB�����Դ����ж�

    clb1_output_xbar_init_set();//out4����GPIO9�����Կ��������շ�

 //����CLB�����
    //1��ʱ��ʹ��CLB�����0��ʹ��CLB���
    //Ϊʲôʱout0��out2����epwm�����
    CLB_setOutputMask(CLB1_BASE, 0x5, true);//0xb=0101
}













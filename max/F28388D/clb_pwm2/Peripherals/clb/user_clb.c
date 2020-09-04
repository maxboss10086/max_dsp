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
#include "clb_config.h"
#include "clb.h"

#include "user_clb.h"





void clb1_in0_init_set(){

    //input-xbar����clb_xbar
//    XBAR_setCLBMuxConfig(XBAR_AUXSIG2, XBAR_CLB_MUX07_CLB2_OUT5);
//    XBAR_enableCLBMux(XBAR_AUXSIG2, XBAR_MUX07);
    CLB_PRESCALE_set(CLB1_BASE,100);
    CLB_PRESCALE_en(CLB1_BASE, 1);


    CLB_configGPInputMux(CLB1_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);//endatʱ�ӵ�Ĭ�ϵ�ƽ
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_CLB_PSCLK);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG2);
}
//SPI���½����ź�
void clb1_in1_init_set(){
    CLB_configGPInputMux(CLB1_BASE, CLB_IN1, CLB_GP_IN_MUX_GP_REG);//
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
}
void clb1_in2_init_set(){

    //EPWMA�ź�����in2
    CLB_configGPInputMux(CLB1_BASE, CLB_IN2, CLB_GP_IN_MUX_GP_REG);//����epwm�����޸ĵõ�endat_clk
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM1A);
}

void clb1_in3_init_set(){

    //EPWMB�ź�����in3
    CLB_configGPInputMux(CLB1_BASE, CLB_IN3, CLB_GP_IN_MUX_GP_REG);//����epwm�����޸ĵõ�spi_clk
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM1B);
}
//epwmA���½����ź�,�൱��SPI��������
void clb1_in4_init_set(){
    CLB_selectInputFilter(CLB1_BASE,CLB_IN4,CLB_FILTER_FALLING_EDGE);
    CLB_configGPInputMux(CLB1_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM1A);
}

//ģʽѡ��
void clb1_in5_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
    //�趨��������ֵ����ģʽ�ı�ʱͨ��HLCģ�齫ֵд�������
    HWREG(CLB1_BASE + CLB_DATAEXCH + CLB_O_PULL(0)) = 10U;
    HWREG(CLB1_BASE + CLB_DATAEXCH + CLB_O_PULL(1)) = 54U;
    HWREG(CLB1_BASE + CLB_DATAEXCH + CLB_O_PULL(2)) = 10U;
}

//endat�����ź�
void clb1_in6_init_set(){

    CLB_configGPInputMux(CLB1_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//���������������������˲������clb��in7
void clb1_in7_init_set(){
    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT1, 63);
    //input-xbar����clb_xbar
    XBAR_setCLBMuxConfig(XBAR_AUXSIG0, XBAR_CLB_MUX01_INPUTXBAR1);
    XBAR_enableCLBMux(XBAR_AUXSIG0, XBAR_MUX01);
    //�����ؼ�⹦�ܿ���
    CLB_enableSynchronization(CLB1_BASE,CLB_IN7);
    CLB_selectInputFilter(CLB1_BASE,CLB_IN7,CLB_FILTER_RISING_EDGE);
    //GPIO63�ź�����clb����
    CLB_configGPInputMux(CLB1_BASE, CLB_IN7, CLB_GP_IN_MUX_EXTERNAL);
    CLB_configLocalInputMux(CLB1_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB1_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);//�����źŽ���clb_xbar

}


//����CLB�������źţ������ʹ��GPIO�ⲿ�����źţ���ô����GPREG�ļĴ���ֵ��Ϊ�����ź�
void clb1_input_init_set(){
    CLB_setGPREG(CLB1_BASE, 1);
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
//    CLB_out5_mux(CLB1_BASE,1);
//    CLB_out5_inverted(CLB1_BASE,1);
//   CLB_out5_logic_en(CLB1_BASE,1);
}
//����CLB�����,clb�޸�ģ����źţ���CLB_setOutputMask�������
//clb�Լ������߼��������źţ���outxbar���
void clb1_output_init_set(){
    clb1_ou4_init_set();
    clb1_ou5_init_set();
       //ѡ��CLB�޸ĺ��ģ���ź�(��EPWM)���ĸ�out��ȥ���ú����ܲ���xbar
    CLB_setOutputMask(CLB1_BASE, 0x5, true);//0xb=0101
}


//**********************************************************CLB2*************************
void clb2_in0_init_set(){
    XBAR_setInputPin(INPUTXBAR_BASE, XBAR_INPUT2, 17);
    //input-xbar����clb_xbar
    XBAR_setCLBMuxConfig(XBAR_AUXSIG1, XBAR_CLB_MUX03_INPUTXBAR2);
    XBAR_enableCLBMux(XBAR_AUXSIG1, XBAR_MUX03);

    CLB_configGPInputMux(CLB2_BASE, CLB_IN0, CLB_GP_IN_MUX_EXTERNAL);//endatʱ�ӵ�Ĭ�ϵ�ƽ
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN0, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN0, CLB_GLOBAL_IN_MUX_CLB_AUXSIG1);
}
void clb2_in1_init_set(){
    CLB_selectInputFilter(CLB2_BASE,CLB_IN1,CLB_FILTER_RISING_EDGE);
    CLB_configGPInputMux(CLB2_BASE, CLB_IN1, CLB_GP_IN_MUX_EXTERNAL);//
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN1, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN1, CLB_GLOBAL_IN_MUX_EPWM1A);
}
void clb2_in2_init_set(){

    //EPWMA�ź�����in2
    CLB_configGPInputMux(CLB2_BASE, CLB_IN2, CLB_GP_IN_MUX_GP_REG);//����epwm�����޸ĵõ�endat_clk
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN2, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN2, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

void clb2_in3_init_set(){

    //EPWMB�ź�����in3
    CLB_configGPInputMux(CLB2_BASE, CLB_IN3, CLB_GP_IN_MUX_GP_REG);//����epwm�����޸ĵõ�spi_clk
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN3, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN3, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}
//��û�õ�
void clb2_in4_init_set(){
    CLB_configGPInputMux(CLB2_BASE, CLB_IN4, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN4, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN4, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//��û�õ�
void clb2_in5_init_set(){

    CLB_configGPInputMux(CLB2_BASE, CLB_IN5, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN5, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN5, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//��û�õ�
void clb2_in6_init_set(){

    CLB_configGPInputMux(CLB2_BASE, CLB_IN6, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN6, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN6, CLB_GLOBAL_IN_MUX_EPWM4_CTRDIR);
}

//
void clb2_in7_init_set(){


    CLB_configGPInputMux(CLB2_BASE, CLB_IN7, CLB_GP_IN_MUX_GP_REG);
    CLB_configLocalInputMux(CLB2_BASE, CLB_IN7, CLB_LOCAL_IN_MUX_GLOBAL_IN);
    CLB_configGlobalInputMux(CLB2_BASE, CLB_IN7, CLB_GLOBAL_IN_MUX_CLB_AUXSIG0);//�����źŽ���clb_xbar
}


//����CLB�������źţ������ʹ��GPIO�ⲿ�����źţ���ô����GPREG�ļĴ���ֵ��Ϊ�����ź�
void clb2_input_init_set(){
    CLB_setGPREG(CLB2_BASE, 1);
    clb2_in0_init_set();
    clb2_in1_init_set();
    clb2_in2_init_set();
    clb2_in3_init_set();
    clb2_in4_init_set();
    clb2_in5_init_set();
    clb2_in6_init_set();
    clb2_in7_init_set();
}

void clb2_ou4_init_set(){
////    ��clb��out4�������output xabr
//    XBAR_setOutputMuxConfig(XBAR_BASE, XBAR_OUTPUT8, XBAR_OUT_MUX05_CLB2_OUT4);
//    XBAR_enableOutputMux(XBAR_BASE, XBAR_OUTPUT8, XBAR_MUX05);
////    ��GPIO9����Ϊoutput xbar���źžʹ�GPIO���
//    GPIO_setDirectionMode(17, GPIO_DIR_MODE_OUT);//����Ϊ���ģʽ
//    GPIO_setPadConfig(17, GPIO_PIN_TYPE_STD);//�������
//    GPIO_setPinConfig(GPIO_17_OUTPUTXBAR8);//���Ÿ���Ϊoutxbar
}

void clb2_ou5_init_set(){

    //��clb��out5�������output xabr
    XBAR_setOutputMuxConfig(OUTPUTXBAR_BASE, XBAR_OUTPUT3, XBAR_OUT_MUX07_CLB2_OUT5);
    XBAR_enableOutputMux(OUTPUTXBAR_BASE, XBAR_OUTPUT3, XBAR_MUX07);
    //��GPIO7����Ϊoutput xbar���źžʹ�GPIO7���
    GPIO_setDirectionMode(26, GPIO_DIR_MODE_OUT);//����Ϊ���ģʽ
    GPIO_setPadConfig(26, GPIO_PIN_TYPE_STD);//�������
    GPIO_setPinConfig(GPIO_26_OUTPUTXBAR3);//���Ÿ���Ϊoutxbar
}
//����CLB�����,clb�޸�ģ����źţ���CLB_setOutputMask�������
//clb�Լ������߼��������źţ���outxbar���
void clb2_output_init_set(){
    clb2_ou4_init_set();
    clb2_ou5_init_set();
       //ѡ��CLB�޸ĺ��ģ���ź�(��EPWM)���ĸ�out��ȥ���ú����ܲ���xbar
    //CLB_setOutputMask(CLB2_BASE, 0x5, true);//0xb=0101
}

void clb1_en(){
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    CLB_enableCLB(CLB1_BASE);
    initTILE1(CLB1_BASE);
    clb1_input_init_set();
    clb1_output_init_set();//out4����GPIO9�����Կ��������շ�
}

void clb2_en(){
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB2);
    CLB_enableCLB(CLB2_BASE);
    initTILE1(CLB2_BASE);
    clb2_input_init_set();
    clb2_output_init_set();
}

void clb_init_set(){
    clb1_en();

   // clb2_en();

}












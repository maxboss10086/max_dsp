//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_clb.c
// Descriptions:    ���������ڵ�GPIO�����ڴ�����
// Author:          Max
// Creation Date:   2020��6��1��
//----------------------------------------------------------------------------------------//
//note:

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"


//******************GPIO�ж�ʹ������************************
//void gpio_interrupt_set(){
////1���Ƚ�CPU���ж���������
//    Interrupt_register(INT_XINT1, &xint1ISR);
//    Interrupt_register(INT_XINT2, &xint2ISR);
////2ʹ���ж�����
//    GPIO_enableInterrupt(GPIO_INT_XINT1);         // Enable XINT1
//    GPIO_enableInterrupt(GPIO_INT_XINT2);         // Enable XINT2
////3�����ж������GPIO
//    GPIO_setInterruptPin(0,GPIO_INT_XINT1);
//    GPIO_setInterruptPin(1,GPIO_INT_XINT2);
//    // Configure falling edge trigger for XINT1
////4�����жϴ�������
//    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);
//    // Configure rising edge trigger for XINT2
//    GPIO_setInterruptType(GPIO_INT_XINT2, GPIO_INT_TYPE_RISING_EDGE);
//
//}

void GPIO16_init_set(void){
    EALLOW;
    GPIO_setPadConfig(16, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(16, GPIO_DIR_MODE_OUT);//16��������Ϊ�������ģʽ
    EDIS;
}
void GPIO16_H(void){
    GPIO_writePin(16, 1);
};
void GPIO16_L(void){
    GPIO_writePin(16, 0);
};



void GPIO61_init_set(void){
    EALLOW;
    GPIO_setPadConfig(61, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(61, GPIO_DIR_MODE_OUT);//
    EDIS;
}



void GPIO61_H(void){
    GPIO_writePin(61, 1);
};
void GPIO61_L(void){
    GPIO_writePin(61, 0);
};

void user_gpio_init_set(void){
    GPIO61_init_set();
    GPIO16_init_set();
}



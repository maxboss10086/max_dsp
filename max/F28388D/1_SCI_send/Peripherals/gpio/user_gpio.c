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
#include "user_gpio.h"

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

void GPIO_OUT_init_set(uint32_t pin){
    EALLOW;
    GPIO_setPadConfig( pin, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode( pin, GPIO_DIR_MODE_OUT);
    EDIS;
}







void GPIO_PULL_H(uint32_t pin){
    GPIO_writePin(pin, 1);
};
void GPIO_PULL_L(uint32_t pin){
    GPIO_writePin(pin, 0);
};





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



void GPIO15_init_set(void){
    EALLOW;
    GPIO_setPadConfig(15, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(15, GPIO_DIR_MODE_OUT);//16��������Ϊ�������ģʽ
    EDIS;
}
void GPIO15_H(void){
    GPIO_writePin(15, 1);
};
void GPIO15_L(void){
    GPIO_writePin(15, 0);
};

void user_gpio_init_set(void){
    GPIO15_init_set();
    GPIO16_init_set();
}



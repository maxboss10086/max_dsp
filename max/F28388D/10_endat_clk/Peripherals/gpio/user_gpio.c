//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_clb.c
// Descriptions:    不在外设内的GPIO设置在此运行
// Author:          Max
// Creation Date:   2020年6月1日
//----------------------------------------------------------------------------------------//
//note:

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"


//******************GPIO中断使能设置************************
//void gpio_interrupt_set(){
////1，先将CPU和中断外设链接
//    Interrupt_register(INT_XINT1, &xint1ISR);
//    Interrupt_register(INT_XINT2, &xint2ISR);
////2使能中断外设
//    GPIO_enableInterrupt(GPIO_INT_XINT1);         // Enable XINT1
//    GPIO_enableInterrupt(GPIO_INT_XINT2);         // Enable XINT2
////3连接中断外设和GPIO
//    GPIO_setInterruptPin(0,GPIO_INT_XINT1);
//    GPIO_setInterruptPin(1,GPIO_INT_XINT2);
//    // Configure falling edge trigger for XINT1
////4配置中断触发类型
//    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);
//    // Configure rising edge trigger for XINT2
//    GPIO_setInterruptType(GPIO_INT_XINT2, GPIO_INT_TYPE_RISING_EDGE);
//
//}

void GPIO16_init_set(void){
    EALLOW;
    GPIO_setPadConfig(16, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(16, GPIO_DIR_MODE_OUT);//16引脚配置为上拉输出模式
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



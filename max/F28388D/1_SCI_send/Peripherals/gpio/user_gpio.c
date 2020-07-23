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
#include "user_gpio.h"

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





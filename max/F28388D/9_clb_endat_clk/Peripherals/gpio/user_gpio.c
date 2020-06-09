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



void GPIO15_init_set(void){
    EALLOW;
    GPIO_setPadConfig(15, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(15, GPIO_DIR_MODE_OUT);//16引脚配置为上拉输出模式
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



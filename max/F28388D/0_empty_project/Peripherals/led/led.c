//****************************************Copyright (c)***********************************//
// 网站博客: NC
// 版权所有, 盗版必究
// Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
// File name:       xxx.v
// Descriptions:
// Author:          Max
// Creation Date:   Wed May 06 2020 11:45:09 GMT+0800
//----------------------------------------------------------------------------------------//
// Note:
//
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include <F2838X_lib/device/device.h>//引入外设
#include <F2838X_lib/device/driverlib.h>

#include "led.h"


void led_init_set(void){
    EALLOW;
    GPIO_setPadConfig(34, GPIO_PIN_TYPE_STD);//选择3引脚,cpu1控制，引脚复用位通用GPIO模式
    GPIO_setDirectionMode(34, GPIO_DIR_MODE_OUT);//34引脚配置为上拉输出模式
    EDIS;
}
void led_H(void){
    GPIO_writePin(34, 1);
};
void led_L(void){
    GPIO_writePin(34, 0);
};

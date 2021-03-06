/*
 * led.c
 *
 *  Created on: 2020年5月15日
 *      Author: 57315
 */


#include "device.h"//引入外设
#include "driverlib.h"

#include <user_led.h>


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

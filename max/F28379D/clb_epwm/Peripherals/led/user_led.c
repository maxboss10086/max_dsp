//****************************************Copyright (c)***********************************//
// ��վ����: NC
// ��Ȩ����, ����ؾ�
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

#include <Peripherals/led/user_led.h>
#include "driverlib.h"
#include "device.h"



void led_init_set(void){
    EALLOW;
    GPIO_setPadConfig(led_gpio, GPIO_PIN_TYPE_STD);//ѡ��3����,cpu1���ƣ����Ÿ���λͨ��GPIOģʽ
    GPIO_setDirectionMode(led_gpio, GPIO_DIR_MODE_OUT);//34��������Ϊ�������ģʽ
    EDIS;
}
void led_H(void){
    GPIO_writePin(led_gpio, 1);
};
void led_L(void){
    GPIO_writePin(led_gpio, 0);
};

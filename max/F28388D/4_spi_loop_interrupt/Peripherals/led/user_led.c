/*
 * led.c
 *
 *  Created on: 2020��5��15��
 *      Author: 57315
 */


#include <F2838X_lib/device/device.h>//��������
#include <F2838X_lib/device/driverlib.h>

#include <user_led.h>


void led_init_set(void){
    EALLOW;
    GPIO_setPadConfig(34, GPIO_PIN_TYPE_STD);//ѡ��3����,cpu1���ƣ����Ÿ���λͨ��GPIOģʽ
    GPIO_setDirectionMode(34, GPIO_DIR_MODE_OUT);//34��������Ϊ�������ģʽ
    EDIS;
}
void led_H(void){
    GPIO_writePin(34, 1);
};
void led_L(void){
    GPIO_writePin(34, 0);
};

/*
 * led.h
 *
 *  Created on: 2020年5月15日
 *      Author: 57315
 */

#ifndef PERIPHERALS_LED_USER_LED_H_
#define PERIPHERALS_LED_USER_LED_H_

#define led_gpio            19





void    led_init_set(void);//函数声明，main文件会从中抽取函数
void    led_H(void);
void    led_L(void);
#endif /* PERIPHERALS_LED_USER_LED_H_ */

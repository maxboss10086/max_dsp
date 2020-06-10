//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    endat��ȡ����������
// Author:          Max
// Creation Date:   2020��5��22��
//----------------------------------------------------------------------------------------//
//note: 1������endat֡����endat_clk������endat_clk�£�ֻ�ڷ������ݺͽ�������ʱclb������spi_clk
//      2�ȳ�ʼ��EPWM�ٳ�ʼ��clb����ô�������һ��EPWM���Σ����clb��ʼ������˲Ž�epwm�޸ģ�Ӧ�ȳ�ʼ��clb�ٳ�ʼ��epwm
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"
//
#include "user_led.h"
#include "user_epwm.h"
#include "user_clb.h"
#include "user_spi.h"
#include "user_gpio.h"
//

// Main
void main(void)
{
//***********************************************ϵͳ��ʼ��**********************************\\
// Initialize device clock and peripherals
    // PLLSYSCLK = 20MHz (XTAL_OSC) * 40 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 1(SYSDIV))=200M
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();

//***********************************************�����ʼ������**********************************\\
//
    user_gpio_init_set();//GPIO19��������Ϊ���

//    led_init_set();//34��������ΪGPIO���

    DEVICE_DELAY_US(2000000);//�������豸������ʼ����Ҫ2s

    clb1_init_set();//ʱ��100M
                    //����clb�߼�����

    initEPWM1();//EPWM100Mʱ��(Ĭ��ϵͳʱ��2��Ƶ����epwm)
                //��ʹ���ж�
                //�趨Ϊ������0��ʱ��Ϊ�ߵ�ƽ
                //������1���Ƚ������������������ϼ�����ʽ,���������ֵ��0
                //EPWMA������2000�£�������AΪ1000ʱ���õͣ���0��������

    SPIb_init_set();//SPIB�趨Ϊ�ӻ�
                    //����SPIʱ��Ϊ1M��ʱ�Ӹ�����16��
                    //ʱ��Ĭ�ϵ͵�ƽ���½��ؽ�������
                    //GPIO66��cs_n,GPIO65��scl,GPIO63��mosi,GPIO64��miso
                    //mosiΪ�������룬���ͷ����ߵȴ����������ź�
EINT;
ERTM;
////***********************************************����ִ��***************************************\\
////����ִ��
//
//

while(1){
         endat_en();//��CLB�����ź� 0100 0001

         DEVICE_DELAY_US(800);//endat�������ݣ����������ź�

         GPIO16_L();

         DEVICE_DELAY_US(100);//�������ݷ�����ϣ��������������ͣ���ѯ�ߵ�ƽ

         GPIO16_H();

         DEVICE_DELAY_US(20);//�����������߿�ʼ��������

         GPIO16_L();

         DEVICE_DELAY_US(10000);//������յ����ݶ���0

}
//
//
//
//
//
//
//
//
//

}

//
// End of File
//
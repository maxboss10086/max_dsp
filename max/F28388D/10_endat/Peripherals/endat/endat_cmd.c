//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_clb.c
// Descriptions:    ʵ��endat������
// Author:          Max
// Creation Date:   2020��6��11��
//----------------------------------------------------------------------------------------//
//note:ȫ�ֱ����������޸ĺ�����ģ��

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//


#include <stdbool.h>
#include "device.h"//��������
#include "driverlib.h"
#include "user_interrupt.h"

#include "endat_cmd.h"
#include "user_spi.h"//����spi����
#include "user_gpio.h"
unsigned char clb_input = 0x01;//0000_0001,in0����1��ʹ��ʱ��Ĭ��Ϊ�ߵ�ƽ
                               //clb��ʼ��ʱ����ʹ��0x01��������clb
                               //endat_en���ı�����clb���ź���������endat

//���������ź�ʹ��endat,ֱ��ʹ�ûᱨ�ڴ�������ں����о�
//void endat_en (void){
//    clb_input= clb_input|0x40;       //clb��8����˿ڵ�7���˿�����1
//    CLB_setGPREG(CLB1_BASE, clb_input);//��������CLB���ź�
//    DEVICE_DELAY_US(1);
//    clb_input= clb_input&0xbf;       //clb��8����˿ڵ�7���˿�����0
//    CLB_setGPREG(CLB1_BASE, clb_input);//��������CLB���ź�*/
//}

//���������ź�ʹ��endat��ͨ���ⲿGPIO�̽�
void endat_en (void){
    GPIO61_H();       //clb��8����˿ڵ�7���˿ڼ�in6����1
    DEVICE_DELAY_US(1);
    GPIO61_L();//clb��8����˿ڵ�7���˿ڼ�in6����0
}


void endat_send_position(){
    spib_sData[0]=0x07;//000_111
     DMA_startChannel(DMA_CH5_BASE);
}








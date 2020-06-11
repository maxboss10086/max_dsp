/*
 * endat_cmd.c
 *
 *  Created on: 2020��6��11��
 *      Author: 57315
 */



#include <stdbool.h>
#include "device.h"//��������
#include "driverlib.h"
#include "user_interrupt.h"

#include "endat_cmd.h"

unsigned char clb_input = 0x01;//0000_0001,in0����1��ʹ��ʱ��Ĭ��Ϊ�ߵ�ƽ
                               //clb��ʼ��ʱ����ʹ��0x01��������clb
                               //endat_en���ı�����clb���ź���������endat

//���������ź�ʹ��endat
unsigned char endat_en (void){
    clb_input= clb_input|0x40;       //clb��8����˿ڵ�7���˿�����1
    CLB_setGPREG(CLB1_BASE, clb_input);//��������CLB���ź�
    DEVICE_DELAY_US(1);
    clb_input= clb_input&0xbf;       //clb��8����˿ڵ�7���˿�����0
    CLB_setGPREG(CLB1_BASE, clb_input);//��������CLB���ź�
    return clb_input;
}










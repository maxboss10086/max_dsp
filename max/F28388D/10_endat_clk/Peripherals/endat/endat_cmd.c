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
uint16_t init_cmd1_sData[4];
uint16_t init_cmd2_sData[4];


//���������ź�ʹ��endat,ֱ��ʹ�ûᱨ�ڴ�������ں����о�
//��CLB�����ź� 0100 0001,CLB����ʱ�ӣ�����SPI����
void endat_en (void){
    clb_input= clb_input|0x40;       //clb��8����˿ڵ�7���˿ڼ�in6����1
    CLB_setGPREG(CLB1_BASE, clb_input);//��������CLB���ź�
    DEVICE_DELAY_US(1);
    clb_input= clb_input&0xbf;       //clb��8����˿ڵ�7���˿ڼ�in6����0
    CLB_setGPREG(CLB1_BASE, clb_input);//��������CLB���ź�*/
}

////���������ź�ʹ��endat��ͨ���ⲿGPIO�̽�
//void endat_en (void){
//    GPIO61_H();       //clb��8����˿ڵ�7���˿ڼ�in6����1
//    DEVICE_DELAY_US(1);
//    GPIO61_L();//clb��8����˿ڵ�7���˿ڼ�in6����0
//}

//��һ����ʼ�������ɱ�����ѡ�д洢���Ͷ�Ӧ��MRS�����
uint16_t endat_selection_of_memory_area_cmd(void){
        uint16_t    init_cmd1_selection_of_memory_area = 0;
        //init_cmd1_selection_of_memory_area = selection_of_memory_area;
        //init_cmd1_selection_of_memory_area = init_cmd1_selection_of_memory_area<<8;
        //init_cmd1_selection_of_memory_area = init_cmd1_selection_of_memory_area | MRS_Select_Parameters_of_Encoder_Manufacturer;
        init_cmd1_selection_of_memory_area = (uint16_t)selection_of_memory_area;
        init_cmd1_selection_of_memory_area = init_cmd1_selection_of_memory_area << 8;
        init_cmd1_selection_of_memory_area |= (uint16_t)MRS_Select_Parameters_of_Encoder_Manufacturer;
        return init_cmd1_selection_of_memory_area;
}

void endat_selection_of_memory_area(){
    init_cmd1_sData[0]=endat_selection_of_memory_area_cmd();//00_001110_A1=0000_1110_1010_0001ѡ��洢�����MRS��
    init_cmd1_sData[1]=0xaaaa;//16λ�������
    init_cmd1_sData[2]=0x0000;
    init_cmd1_sData[3]=0xffff;
}


//�ڶ�����ʼ�������ɱ��������Ͳ�������Ͷ�Ӧ�ĵ�ַ���
uint16_t endat_send_clock_pulses_cmd(void){
        uint16_t    init_cmd2_endat_send_clock_pulses;
        init_cmd2_endat_send_clock_pulses = (uint16_t)encoder_send_parameter;
        init_cmd2_endat_send_clock_pulses = init_cmd2_endat_send_clock_pulses<<8;
        init_cmd2_endat_send_clock_pulses = init_cmd2_endat_send_clock_pulses | (uint16_t)MRS_address_clock_pulses;
        return init_cmd2_endat_send_clock_pulses;
}

void endat_send_clock_pulses(){
    init_cmd2_sData[0]=endat_send_clock_pulses_cmd();//endat_send_clock_pulses_cmd();//0010_0011_0000_1101
    init_cmd2_sData[1]=0xaaaa;//16λ�������
    init_cmd2_sData[2]=0x0000;
    init_cmd2_sData[3]=0xffff;
}


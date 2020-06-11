/*
 * endat_cmd.c
 *
 *  Created on: 2020年6月11日
 *      Author: 57315
 */



#include <stdbool.h>
#include "device.h"//引入外设
#include "driverlib.h"
#include "user_interrupt.h"

#include "endat_cmd.h"

unsigned char clb_input = 0x01;//0000_0001,in0输入1，使得时钟默认为高电平
                               //clb初始化时，将使用0x01数据输入clb
                               //endat_en将改变输入clb的信号用以启动endat

//输入脉冲信号使能endat
unsigned char endat_en (void){
    clb_input= clb_input|0x40;       //clb的8输入端口第7个端口输入1
    CLB_setGPREG(CLB1_BASE, clb_input);//设置输入CLB的信号
    DEVICE_DELAY_US(1);
    clb_input= clb_input&0xbf;       //clb的8输入端口第7个端口输入0
    CLB_setGPREG(CLB1_BASE, clb_input);//设置输入CLB的信号
    return clb_input;
}










//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_clb.c
// Descriptions:    实现endat的命令
// Author:          Max
// Creation Date:   2020年6月11日
//----------------------------------------------------------------------------------------//
//note:全局变量在这里修改后进入各模块

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//


#include <stdbool.h>
#include "device.h"//引入外设
#include "driverlib.h"
#include "user_interrupt.h"

#include "endat_cmd.h"
#include "user_spi.h"//引入spi数据

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

void endat_send_position(){
    spib_sData[0]=0x07;//000_111
     DMA_startChannel(DMA_CH5_BASE);
}








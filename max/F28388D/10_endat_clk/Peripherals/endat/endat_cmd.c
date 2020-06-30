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
//note: 1：全局变量在这里修改后进入各模块
//      2：8位赋值给16位，要强转成16位先，然后再赋值
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//


#include <stdbool.h>
#include "device.h"//引入外设
#include "driverlib.h"
#include "user_interrupt.h"

#include "endat_cmd.h"
#include "user_spi.h"//引入spi数据
#include "user_gpio.h"
unsigned char clb_input = 0x21;//0000_0001,in0输入1，使得时钟默认为高电平
                               //0010_0001,in5输入1，使得LU1选择计数器match2
                               //clb初始化时，将使用0x01数据输入clb
                               //endat_en将改变输入clb的信号用以启动endat

ENDAT_DATA_STRUCT endat22Data;

//输入脉冲信号使能endat,直接使用会报内存错误，留在后续研究
//向CLB输入信号 0100 0001,CLB发出时钟，启动SPI传输
void endat_en (void){
    clb_input= clb_input|0x40;       //clb的8输入端口第7个端口即in6输入1
    CLB_setGPREG(CLB1_BASE, clb_input);//设置输入CLB的信号
    DEVICE_DELAY_US(1);
    clb_input= clb_input&0xbf;       //clb的8输入端口第7个端口即in6输入0
    CLB_setGPREG(CLB1_BASE, clb_input);//设置输入CLB的信号*/
}

////输入脉冲信号使能endat，通过外部GPIO短接
//void endat_en (void){
//    GPIO61_H();       //clb的8输入端口第7个端口即in6输入1
//    DEVICE_DELAY_US(1);
//    GPIO61_L();//clb的8输入端口第7个端口即in6输入0
//}

//第一个初始化命令由编码器选中存储区和对应的MRS码组成
uint16_t endat_selection_of_memory_area_cmd(void){
        uint16_t    init_cmd1 = 0;
        init_cmd1 = selection_of_memory_area;
        init_cmd1 = init_cmd1 << 8;
        init_cmd1 = init_cmd1 | MRS_Select_Parameters_of_Encoder_Manufacturer;
        return init_cmd1;
}

void endat_selection_of_memory_area(){
    endat22Data.sdata[0]=endat_selection_of_memory_area_cmd();//00_001110_A1=0000_1110_1010_0001选择存储区命令及MRS码
    endat22Data.sdata[1]=0xaaaa;//16位任意参数
    endat22Data.sdata[2]=0x0000;
    endat22Data.sdata[3]=0xffff;
}


//第二个初始化命令由编码器发送参数命令和对应的地址组成
uint16_t endat_send_clock_pulses_cmd(void){
        uint16_t    init_cmd2=0;
        init_cmd2 = encoder_send_parameter;
        init_cmd2 = init_cmd2<<8;
        init_cmd2 = init_cmd2 | MRS_address_clock_pulses;
        return init_cmd2;
}

void endat_send_clock_pulses(){
    endat22Data.sdata[0]=endat_send_clock_pulses_cmd();//0010_0011_0000_1101
    endat22Data.sdata[1]=0xaaaa;//16位任意参数
    endat22Data.sdata[2]=0x0000;
    endat22Data.sdata[3]=0xffff;
}


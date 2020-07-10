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
//      3：剩下的数组全部初始化为0,一定要初始化为0，不写不会默认0，会出现问题
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//


#include <stdbool.h>
#include "device.h"//引入外设
#include "driverlib.h"
#include "user_interrupt.h"

#include "endat_cmd.h"
#include "user_spi.h"//引入spi数据
#include "user_gpio.h"


ENDAT_DATA endat22Data={1};//类比int a;
                           //CLB的GP_REG输入信号设置
                           //0000_0001,in0输入1，使得时钟默认为高电平
                           //0010_0001,in5输入1，使得LU1选择计数器match2，从而改变endat运行模式
                           //in6输入脉冲波形用于启动第一个状态机，从而启动endat的一帧数据
                           //clb初始化时，将使用0x01数据输入clb
                           //将endat_mode赋值为0x21，运行读取位置模式

//输入脉冲信号使能endat,直接使用会报内存错误，留在后续研究
//向CLB输入信号 0100 0001,CLB发出时钟，启动SPI传输
void endat_en (void){
    endat22Data.endat_mode = endat22Data.endat_mode|0x40;       //clb的8输入端口第7个端口即in6输入1
    CLB_setGPREG(CLB2_BASE, endat22Data.endat_mode);
    CLB_setGPREG(CLB1_BASE, endat22Data.endat_mode);//设置输入CLB的信号
    endat22Data.endat_mode = endat22Data.endat_mode&0xbf;       //clb的8输入端口第7个端口即in6输入0
    CLB_setGPREG(CLB1_BASE, endat22Data.endat_mode);//设置输入CLB的信号*/
    CLB_setGPREG(CLB2_BASE, endat22Data.endat_mode);
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
    uint16_t i;
    endat22Data.sdata[0]=endat_selection_of_memory_area_cmd();//00_001110_A1=0000_1110_1010_0001选择存储区命令及MRS码
    for(i=1;i<=sizeof(endat22Data.sdata)/sizeof(uint16_t)-1;i++){
        endat22Data.sdata[i]=0x0;//剩下的数组全部初始化为0,一定要初始化为0，不写不会默认0，会出现问题
    }
}


//第二个初始化命令由编码器发送参数命令和对应的地址组成
uint16_t endat_send_position_clocks_cmd(void){
        uint16_t    init_cmd2=0;
        init_cmd2 = encoder_send_parameter;
        init_cmd2 = init_cmd2<<8;
        init_cmd2 = init_cmd2 | MRS_address_clock_pulses;
        return init_cmd2;
}

void endat_send_position_clocks(){
    uint16_t i;
    endat22Data.sdata[0]=endat_send_position_clocks_cmd();//0010_0011_0000_1101
    for(i=1;i<=sizeof(endat22Data.sdata)/sizeof(uint16_t)-1;i++){
        endat22Data.sdata[i]=0x0;//剩下的数组全部初始化为0
    }
}

//第二个初始化命令由编码器发送参数命令和对应的地址组成
uint16_t endat_send_position_cmd(void){
        uint16_t    work_cmd1=0;
        work_cmd1 = encoder_transmit_position_values;
        work_cmd1 = work_cmd1<<8;
        return work_cmd1;
}

void endat_send_position(){
    uint16_t i;
    endat22Data.sdata[0]=endat_send_position_cmd();//0000_0111_0000_0000
    for(i=1;i<=sizeof(endat22Data.sdata)/sizeof(uint16_t)-1;i++){
        endat22Data.sdata[i]=0x0;//剩下的数组全部初始化为0
    }
}

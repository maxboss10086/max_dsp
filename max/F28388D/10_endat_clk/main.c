//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    主函数
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//
//note: 1启用CLB时，初始化DMA会报内存错误
//      2SPI时钟与endat时钟呈反向关系
//      3发送命令阶段：SPI上升沿发送命令数据，编码器用endat的上升沿(相当于SPI的下降沿)接收命令数据
//      4接收命令阶段：编码器用endat的上升沿发送位置数据，cpu应用spi的上升沿接收数据，但实际上SPI设置为下降沿接收，这样会有一个小问题
//  需要注意，就是接收数据最高位的S位数据会接收不到，而最低位总是读取到已经拉高的信号，也就是读取的数据会向左移动移位，最低位补上了1，这样在
//  在截取数据的时候要注意
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
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
#include "endat_cmd.h"
#include "user_dma.h"




// Main

void main(void)
{
//    uint16_t i;
    //***********************************************系统初始化**********************************\\
    // Initialize device clock and peripherals
        // PLLSYSCLK = 20MHz (XTAL_OSC) * 40 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 1(SYSDIV))=200M
        Device_init();
    //    // Setup GPIO by disabling pin locks and enabling pullups
        Device_initGPIO();
    //    // Initialize PIE and clear PIE registers. Disables CPU interrupts
        interrupt_init_set();

    //***********************************************外设初始化设置**********************************\\
    //

    user_gpio_init_set();

    DEVICE_DELAY_US(2000000);//编码器设备自身初始化需要2s

    clb_init_set();//时钟100M
                    //设置clb逻辑程序

    initEPWM1();//EPWM100M时钟(默认系统时钟2分频进入epwm)
                //不使用中断
                //设定为计数器0的时候为高电平
                //启用了1个比较器，计数器采样向上计数方式,计数到最大值归0
                //EPWMA共计数2000下，计数到A为1000时候置低，归0后又拉高
    //
//    initDMA();

//    init_SPI_enableLoopback(SPIB);
    SPIb_init_set();

    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    EINT;
    ERTM;
////***********************************************函数执行***************************************\\
////函数执行



//先设置好要发送的数组数据，再开启DMA通道
//DMA_startChannel(DMA_CH5_BASE);
//DMA_startChannel(DMA_CH6_BASE);



    while(1){
               endat_en();//endat每隔1000传输一次,向CLB输入信号 0100 0001,发出时钟，启动SPI传输
               DEVICE_DELAY_US(1000);//假设接收的数据都是0
               //if(endat22Data.init_done)
    }

//
//    endat_en();//endat每隔1000传输一次,向CLB输入信号 0100 0001,发出时钟，启动SPI传输
//    DEVICE_DELAY_US(1000);//假设接收的数据都是0





}





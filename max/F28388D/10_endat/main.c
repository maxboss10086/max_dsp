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
//note: 启用CLB时，初始化DMA会报内存错误

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


//
// Main
//
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

//    led_init_set();//34引脚设置为GPIO输出

    DEVICE_DELAY_US(2000000);//编码器设备自身初始化需要2s

    clb1_init_set();//时钟100M
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
//    DMA_startChannel(DMA_CH6_BASE);
//    //
//    // Initialize the data buffers
//    //
//    for(i = 0; i < 50; i++)
//    {
//        spib_sData[i] = i;
//        spib_rData[i]= 0;
//    }
//    //一定在数据赋值完成后开启发送通道
//    DMA_startChannel(DMA_CH5_BASE);
//
//    //
//    // Enable interrupts required for this example
//    //
//
//
//    //
//    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
//
//
//    //
//    // Start the DMA channels
//    //
//
//
//    //
//    // Wait until the DMA transfer is complete
//    //
//    while(!done);
//
//    //
//    // When the DMA transfer is complete the program will stop here
//    //
//    ESTOP0;
//}

endat_send_position();
//先设置好要发送的数组数据，再开启DMA通道
//DMA_startChannel(DMA_CH5_BASE);
//DMA_startChannel(DMA_CH6_BASE);

    while(1){
        endat_en();//向CLB输入信号 0100 0001
        DEVICE_DELAY_US(800);//endat发送数据，拉高命令信号

        GPIO16_L();

        DEVICE_DELAY_US(100);//命令数据发送完毕，数据输入线拉低，轮询高电平

        GPIO16_H();

        DEVICE_DELAY_US(20);//命令数据拉高开始接收数据

        GPIO16_L();

        DEVICE_DELAY_US(10000);//假设接收的数据都是0
    }

}




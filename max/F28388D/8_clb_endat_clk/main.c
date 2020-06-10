//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    endat读取编码器数据
// Author:          Max
// Creation Date:   2020年5月22日
//----------------------------------------------------------------------------------------//
//note: 1再整个endat帧生成endat_clk，而在endat_clk下，只在发送数据和接收数据时clb才生成spi_clk
//      2先初始化EPWM再初始化clb，那么会先输出一段EPWM波形，随后clb初始化完成了才将epwm修改，应先初始化clb再初始化epwm
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
    user_gpio_init_set();//GPIO19引脚设置为输出

//    led_init_set();//34引脚设置为GPIO输出

    DEVICE_DELAY_US(2000000);//编码器设备自身初始化需要2s

    clb1_init_set();//时钟100M
                    //设置clb逻辑程序

    initEPWM1();//EPWM100M时钟(默认系统时钟2分频进入epwm)
                //不使用中断
                //设定为计数器0的时候为高电平
                //启用了1个比较器，计数器采样向上计数方式,计数到最大值归0
                //EPWMA共计数2000下，计数到A为1000时候置低，归0后又拉高

    SPIb_init_set();//SPIB设定为从机
                    //设置SPI时钟为1M，时钟个数是16个
                    //时钟默认低电平，下降沿接收数据
                    //GPIO66是cs_n,GPIO65是scl,GPIO63是mosi,GPIO64是miso
                    //mosi为浮空输入，即释放总线等待主机输入信号
EINT;
ERTM;
////***********************************************函数执行***************************************\\
////函数执行
//
//

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

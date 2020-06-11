//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.c
// Descriptions:    所有中断设置与服务在此运行
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//
//note:启用了SPI中断

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "clb_config.h"
#include "clb.h"
#include "user_clb.h"

#include "user_interrupt.h"

uint16_t sci_rDataA[2];//定义函数在这里，h文件只是用extern把定义的函数发送出去
uint16_t sci_sDataA[2];
uint16_t spia_sData[2];
uint16_t spia_rData[2];
uint16_t spib_sData[2];
uint16_t spib_rData[2];
uint16_t spi_i;

// Place buffers in GSRAM
#pragma DATA_SECTION(spib_sData, "ramgs0");
#pragma DATA_SECTION(spib_rData, "ramgs1");



void interrupt_init_set(void){
    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
}
//***********************************************外设中断设置**********************************\\
//******************GPIO中断使能设置************************
//void gpio_interrupt_set(){
////1，先将CPU和中断外设链接
//    Interrupt_register(INT_XINT1, &xint1ISR);
//    Interrupt_register(INT_XINT2, &xint2ISR);
////2使能中断外设
//    GPIO_enableInterrupt(GPIO_INT_XINT1);         // Enable XINT1
//    GPIO_enableInterrupt(GPIO_INT_XINT2);         // Enable XINT2
////3连接中断外设和GPIO
//    GPIO_setInterruptPin(0,GPIO_INT_XINT1);
//    GPIO_setInterruptPin(1,GPIO_INT_XINT2);
//    // Configure falling edge trigger for XINT1
////4配置中断触发类型
//    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);
//    // Configure rising edge trigger for XINT2
//    GPIO_setInterruptType(GPIO_INT_XINT2, GPIO_INT_TYPE_RISING_EDGE);
//
//}






//void epwm1_interrupt_set(void){
//    Interrupt_register(INT_EPWM1, &epwm1ISR);
//    Interrupt_enable(INT_EPWM1);
//    EPWM_setInterruptSource(EPWM1_BASE, EPWM_INT_TBCTR_ZERO);
//    EPWM_enableInterrupt(EPWM1_BASE);
//    EPWM_setInterruptEventCount(EPWM1_BASE, 3U);
//}

//void clb1_interrupt_set(void){
//    Interrupt_register(INT_CLB1, &clb1ISR);
//    Interrupt_enable(INT_CLB1);
//}

//************************************************************************************************\\
//



//*************************************************中断服务函数***********************************************\\
//***********************************************scl中断服务函数**********************************\\
//
__interrupt void sciaRXFIFOISR(void)
{
//    uint16_t i;
//读取FIFO中的数据向rDataA写入2个字节
    SCI_readCharArray(SCIA_BASE, sci_rDataA, 2);
//读取2字节后，FIFO就空了，如果再次发送数据串口进行接收，就能再次触发中断

    SCI_clearOverflowStatus(SCIA_BASE);

    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_RXFF);
    // Issue PIE ack
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}


// sciaTXFIFOISR - SCIA Transmit FIFO ISR
//
__interrupt void sciaTXFIFOISR(void)
{
//    uint16_t i;
//从sDataA向FIFO写入两个字节
    sci_sDataA[0]  =0x66;
    sci_sDataA[1]  =0x77;
    SCI_writeCharArray(SCIA_BASE, sci_sDataA, 2);

    //
    // Increment send data for next cycle
    //
    //for(i = 0; i < 2; i++)
    //{
    //    sDataA[i] = (sDataA[i] + 1) & 0x00FF;
    //}

    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF);
    // Issue PIE ACK
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}
//**************************************************GPIO中断服务函数**********************************************\\
//
// xint1ISR - External Interrupt 1 ISR
//
interrupt void xint1ISR(void)
{
    GPIO_clearPortPins(GPIO_PORT_B,GPIO_GPBDIR_GPIO34); // GPIO34 is lowered

    // Acknowledge this interrupt to get more from group 1
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

//
// xint2ISR - External Interrupt 2 ISR
//
interrupt void xint2ISR(void)
{
    GPIO_clearPortPins(GPIO_PORT_B,GPIO_GPBDIR_GPIO34); // GPIO34 is lowered

    // Acknowledge this interrupt to get more from group 1
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}

//**************************************************spi中断服务函数**********************************************\\
//SPI a send FIFO ISR
__interrupt void spiaTxFIFOISR(void)
{
    // Send data
    for(spi_i = 0; spi_i < 2; spi_i++)
    {
       SPI_writeDataNonBlocking(SPIA_BASE, spia_sData[spi_i]);
    }
    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}
// SPI a Receive FIFO ISR
 __interrupt void spiaRxFIFOISR(void)
{
    //uint16_t spia_rDataPoint = 0;
    //
    // Read data
    //
    for(spi_i = 0; spi_i < 2; spi_i++)
    {
        spia_rData[spi_i] = SPI_readDataNonBlocking(SPIA_BASE);
    }
    // Check received data
    //这里可以编写接收后进行校验

    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}
//SPI b send FIFO ISR
__interrupt void spibTxFIFOISR(void)
{
    // Send data
    for(spi_i = 0; spi_i < 2; spi_i++)
    {
       SPI_writeDataNonBlocking(SPIB_BASE, spib_sData[spi_i]);
    }
    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}

//SPI b receive FIFO ISR
__interrupt void spibRxFIFOISR(void)
{
   //uint16_t spib_rDataPoint = 0;
   // Read data
   for(spi_i = 0; spi_i < 2; spi_i++)
   {//这里好像不能像串口一样,一个函数读取全部数据,需要一帧一帧读出来存入数组
       spib_rData[spi_i] = SPI_readDataNonBlocking(SPIB_BASE);
   }
   // Check received data
   //这里可以编写接收后进行校验

   // Clear interrupt flag and issue ACK
   SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF);
   Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);

}

////epwm中断
//__interrupt void epwm1ISR(void)
//{
//    EPWM_clearEventTriggerInterruptFlag(EPWM1_BASE);
//    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);
//    CLB_setGPREG(CLB1_BASE, clb_input & 3UL);
//    asm(" NOP");
//}


////由clb中HLC模块引起的CLB中断
////猜想可能在该中断使能SPI接收
//uint32_t  cnt_clb=0;
//__interrupt void clb1ISR(void)
//{
//
//    cnt_clb = cnt_clb+1;
//    CLB_clearInterruptTag(CLB1_BASE);
//    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP5);
//}
// DMA Channel 5 ISR
//
__interrupt void dmaCh5ISR(void)
{
    DMA_stopChannel(DMA_CH5_BASE);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP7);
    return;
}

//
// DMA Channel 6 ISR
//
 __interrupt void dmaCh6ISR(void)
{
//    uint16_t i;

    //DMA_stopChannel(DMA_CH6_BASE);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP7);

    //
    // Check for data integrity
    //
//    for(i = 0; i < 128; i++)
//    {
//        if (rData[i] != i)
//        {
//            // Something went wrong. rData doesn't contain expected data.
//            ESTOP0;
//        }
//    }
//
//    done = 1;
    return;
}

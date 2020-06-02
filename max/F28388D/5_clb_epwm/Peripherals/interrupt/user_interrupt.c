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

//******************SCL中断使能设置************************
//void scl_interrupt_set(void){
//    //将CPU和外设中断链接起来
//        Interrupt_register(INT_SCIA_RX, sciaRXFIFOISR);
//        Interrupt_register(INT_SCIA_TX, sciaTXFIFOISR);
//    //使能中断
//        Interrupt_enable(INT_SCIA_RX);
//        Interrupt_enable(INT_SCIA_TX);
//        // 选择使能要中断的类型，选择FIFO中断，而不是数据ready中断等
//        SCI_enableInterrupt(SCIA_BASE, (SCI_INT_RXFF));//使能接收中断，不使能发送中断，如果接收和发送都使能，就SCI_INT_RXFF|SCI_INT_TXFF
//        SCI_disableInterrupt(SCIA_BASE, SCI_INT_RXERR);//关闭接收错误中断，开启FIFO中断
//    //设置中断触发条件
//        //设置FIFO中断
//        // The transmit FIFO generates an interrupt when FIFO status
//        // bits are less than or equal to 2 out of 16 words
//        // The receive FIFO generates an interrupt when FIFO status
//        // bits are greater than equal to 2 out of 16 words
//        SCI_setFIFOInterruptLevel(SCIA_BASE, SCI_FIFO_TX2, SCI_FIFO_RX2);
//
//}

//******************SPI中断使能设置************************
//使能spia发送中断并设置
//void spia_tx_interrupt_set(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_TXFF);
//    SPI_setFIFOInterruptLevel(SPIA_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_TXFF);
//
//}
//使能spia接收中断并设置
//void spia_rx_interrupt_set(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_RXFF);
//    SPI_setFIFOInterruptLevel(SPIA_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_RXFF);
//
//}
//使能spib发送中断并设置
//void spib_tx_interrupt_set(void){
//    Interrupt_register(INT_SPIB_TX, &spibTxFIFOISR);
//    Interrupt_enable(INT_SPIB_TX);
//    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
//    SPI_setFIFOInterruptLevel(SPIB_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIB_BASE, SPI_INT_TXFF);
//}
//使能spib接收中断并设置
//void spib_rx_interrupt_set(void){
//    Interrupt_register(INT_SPIB_RX, &spibRxFIFOISR);
//    Interrupt_enable(INT_SPIB_RX);
//    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF);
//    SPI_setFIFOInterruptLevel(SPIB_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIB_BASE, SPI_INT_RXFF);
//}


void epwm1_interrupt_set(void){
    Interrupt_register(INT_EPWM1, &epwm1ISR);
    Interrupt_enable(INT_EPWM1);
    EPWM_setInterruptSource(EPWM1_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(EPWM1_BASE);
    EPWM_setInterruptEventCount(EPWM1_BASE, 3U);
}
//************************************************************************************************\\
//




//***********************************************scl中断服务函数**********************************\\
//
uint16_t sDataA[2];// Send data for SCI-A
uint16_t rDataA[2];// Received data for SCI-A
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
__interrupt void epwm1ISR(void)
{
    EPWM_clearEventTriggerInterruptFlag(EPWM1_BASE);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);
    CLB_setGPREG(CLB1_BASE, clb_mode & 3UL);
    asm(" NOP");
}

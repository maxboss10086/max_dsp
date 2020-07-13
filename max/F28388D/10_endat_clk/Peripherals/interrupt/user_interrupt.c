//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.c
// Descriptions:    所有中断服务在此运行
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//
//note: 1中断所做的事：向FIFO填入数据供硬件发送，抽取FIFO中的数据进行处理和校验

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "clb_config.h"
#include "clb.h"
#include "user_clb.h"

#include "user_interrupt.h"
#include "user_spi.h"//引入SPI数据
#include "endat_cmd.h"//引入SPI数据




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
//CPU将数组深度2填入FIFO
__interrupt void spiaTxFIFOISR(void)
{
    uint16_t spi_send_i = 0;
    // Send data
    for(spi_send_i = 0; spi_send_i < 2; spi_send_i++)
    {
       SPI_writeDataNonBlocking(SPIA_BASE, spia_sData[spi_send_i]);
    }
    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}

// SPI a Receive FIFO ISR
 __interrupt void spiaRxFIFOISR(void)
{
     uint16_t spia_read_i = 0;
    //
    // Read data
    //
    for(spia_read_i = 0; spia_read_i < 2; spia_read_i++)
    {
        spia_rData[spia_read_i] = SPI_readDataNonBlocking(SPIA_BASE);
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
    uint16_t spib_send_i = 0;
    static unsigned char send_step = 0;
        switch(send_step){
        case 0:
                endat_selection_of_memory_area();
                for(spib_send_i = 0; spib_send_i <= sizeof(endat22Data.sdata)/sizeof(uint16_t)-1; )
                {
                    SPI_writeDataNonBlocking(SPIB_BASE, endat22Data.sdata[spib_send_i]);
                    spib_send_i++;
                }
                send_step++;
        break;
        case 1:
                endat_send_position_clocks();
                for(spib_send_i = 0; spib_send_i <= sizeof(endat22Data.sdata)/sizeof(uint16_t)-1; )
                    {//一直发送
                        SPI_writeDataNonBlocking(SPIB_BASE, endat22Data.sdata[spib_send_i]);
                        spib_send_i++;
                    }
                if(endat22Data.init_done==1){
                    send_step++;
                }
        break;
        case 2:
               endat_send_position();
               for(spib_send_i = 0; spib_send_i <= sizeof(endat22Data.sdata)/sizeof(uint16_t)-1; ){
                        SPI_writeDataNonBlocking(SPIB_BASE, endat22Data.sdata[spib_send_i]);
                        spib_send_i++;
               }
        break;
       }

    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}

//SPI b receive FIFO ISR
//中断接收数据后，对数据进行处理，可以校验，也可以抽取分类

__interrupt void spibRxFIFOISR(void)
{
    uint16_t i = 0;
    uint16_t j = 24;
    uint16_t spib_rx_i = 0;
    uint32_t result=0;
   // Read data
   for(spib_rx_i = 0; spib_rx_i <= sizeof(endat22Data.rdata)/sizeof(uint16_t)-1; spib_rx_i++)
   {
       endat22Data.rdata[spib_rx_i] = SPI_readDataNonBlocking(SPIB_BASE);
   }
   // 接收后处理数据
   static unsigned char rx_step = 0;
   switch(rx_step){
       case 0:
               rx_step++;//选择编码器MRS帧返回的数据不用做处理
       break;
       case 1:
               endat22Data.address = endat22Data.rdata[2] & 0x1fe0;
               endat22Data.address = endat22Data.address>>5;
               endat22Data.position_clocks = endat22Data.rdata[3] & 0xffe0;
               endat22Data.position_clocks = endat22Data.position_clocks>>5;
               if(endat22Data.position_clocks == 25){
                   endat22Data.endat_mode = 0x21;
                   endat22Data.init_done=1;
                   rx_step++;
               }
       break;
       case 2:
               endat22Data.error1 = endat22Data.rdata[0]&0x0008;//错误位脉冲是13个,即接收数据的低4位
               endat22Data.error1 = endat22Data.error1>>3;
               endat22Data.dataReady = endat22Data.rdata[0]&0x0010;//S位脉冲是12个,即接收数据的低5位
               endat22Data.dataReady = endat22Data.dataReady>>4;
               for(i=1;i<=3;i++){//第一个数组循环执行3次，取出低3位
                   result = (endat22Data.rdata[0] & 0x0004) ? 1 :0;//取出数组的倒数第3位
                   result = result<<j;//左移J位，把这个数据放在位置数据的最高位
                   endat22Data.position_lo = endat22Data.position_lo | result;
                   endat22Data.position_lo = endat22Data.position_lo>>1;//然后位置数据右移
                   endat22Data.rdata[0] = endat22Data.rdata[0]<<1;
               }
               for( i=1;i<=16;i++){//第二个数组循环执行15次
                   result = (endat22Data.rdata[1] & 0x8000) ? 1 :0 ;//取出数组的最高位
                   result = result<<j;
                   endat22Data.position_lo = endat22Data.position_lo | result;
                   endat22Data.position_lo = endat22Data.position_lo>>1;
                   endat22Data.rdata[1] = endat22Data.rdata[1]<<1;
               }
               for(i=10;i<=15;i++){//第三个数组循环执行6次,取出高6位
                   result = (endat22Data.rdata[2] & 0x8000) ? 1 :0 ;
                   if(i<=14){
                       result = result<<j;
                       endat22Data.position_lo = endat22Data.position_lo | result;
                       endat22Data.position_lo = endat22Data.position_lo>>1;
                   }
                   if(i==15){
                       result = result<<j;
                       endat22Data.position_lo = endat22Data.position_lo | result;
                       //最后一位数据插入位置数据的最高位后数据就完成了，不需要再右移
                   }
                   endat22Data.rdata[2] = endat22Data.rdata[2]<<1;
               }
        break;
   }

//*****校验数据******\\


   // Clear interrupt flag and issue ACK
   SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF);
   Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
//   SPI_disableModule(SPIB_BASE);

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
volatile uint16_t done = 0;         // Flag to set when all data transfered
 __interrupt void dmaCh6ISR(void)
{
//    uint16_t i;

    //DMA_stopChannel(DMA_CH6_BASE);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP7);

    //
    // Check for data integrity
    //中断接收数据后，对数据进行处理
//    for(i = 0; i < 128; i++)
//    {
//        if (spib_rData[i] != i)
//        {
//            // Something went wrong. rData doesn't contain expected data.
//            ESTOP0;
//        }
//    }
//
//    done = 1;
    return;
}

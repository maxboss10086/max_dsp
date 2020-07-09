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
//note:

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
 uint16_t flag = 0;
 uint16_t init_done = 0;
 uint16_t position_clocks_cmd_done;
 uint16_t endat_send_position_cmd_done=0;
__interrupt void spibTxFIFOISR(void)
{
    uint16_t spib_send_i = 0;
    static unsigned char step = 0;
        switch(step){
        case 0:
                endat_selection_of_memory_area();
                for(spib_send_i = 0; spib_send_i <= sizeof(endat22Data.sdata)/sizeof(uint16_t)-1; )
                {
                    SPI_writeDataNonBlocking(SPIB_BASE, endat22Data.sdata[spib_send_i]);
                    spib_send_i++;
                }
                step++;
            break;
        case 1:
                endat_send_position_clocks();
                for(spib_send_i = 0; spib_send_i <= sizeof(endat22Data.sdata)/sizeof(uint16_t)-1; )
                    {//一直发送
                        SPI_writeDataNonBlocking(SPIB_BASE, endat22Data.sdata[spib_send_i]);
                        spib_send_i++;
                    }
                position_clocks_cmd_done=1;
            //step++;
            break;
//        case 0:
//               position_clocks_cmd_done=0;
//               endat_send_position();
//               for(spib_send_i = 0; spib_send_i <= sizeof(endat22Data.sdata)/sizeof(uint16_t)-1; )
//                  {//一直发送
//                        SPI_writeDataNonBlocking(SPIB_BASE, endat22Data.sdata[spib_send_i]);
//                        spib_send_i++;
//                   }
//               endat_send_position_cmd_done=1;
//            break;
       }

    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}

//SPI b receive FIFO ISR
//中断接收数据后，对数据进行处理，可以校验，也可以抽取分类
__interrupt void spibRxFIFOISR(void)
{
    uint16_t spib_read_i = 0;
   // Read data
   for(spib_read_i = 0; spib_read_i <= sizeof(endat22Data.rdata)/sizeof(uint16_t)-1; spib_read_i++)
   {//这里好像不能像串口一样,一个函数读取全部数据,需要一帧一帧读出来存入数组
       endat22Data.rdata[spib_read_i] = SPI_readDataNonBlocking(SPIB_BASE);
   }
   // 接收后处理数据
   if(position_clocks_cmd_done){
       endat22Data.position_clocks = endat22Data.rdata[3]&0xffe0;//截取数据的时候要注意，不是截取5-15，而是截取6-15，因为SPI采用下降沿接收
       endat22Data.position_clocks = endat22Data.position_clocks>>5;
       init_done=1;
   }
   if(endat_send_position_cmd_done){
       endat22Data.error1 = endat22Data.rdata[0]&0x800;//SPI发送命令脉冲是11个
       endat22Data.error1 = endat22Data.error1>>11;
       endat22Data.position_lo = endat22Data.rdata[0]&0xe000;//
       endat22Data.position_lo = endat22Data.position_lo>>13;
       endat22Data.position_hi = endat22Data.rdata[1]&0x07ff;
       endat22Data.position_hi = endat22Data.position_hi<<3;
       endat22Data.position_data = endat22Data.position_hi | endat22Data.position_lo;
   }
//   //校验数据
//   if(init_done>=2){
//       if((endat22Data.position_clocks!=25)||(endat22Data.position_clocks!=13)){
//           ESTOP0;
//       }
//   }


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

//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.c
// Descriptions:    �����жϷ����ڴ�����
// Author:          Max
// Creation Date:   2020��5��24��
//----------------------------------------------------------------------------------------//
//note: 1�ж��������£���FIFO�������ݹ�Ӳ�����ͣ���ȡFIFO�е����ݽ��д����У��

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "clb_config.h"
#include "clb.h"
#include "user_clb.h"

#include "user_interrupt.h"
#include "user_spi.h"//����SPI����
#include "endat_cmd.h"//����SPI����




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




//*************************************************�жϷ�����***********************************************\\
//***********************************************scl�жϷ�����**********************************\\
//
__interrupt void sciaRXFIFOISR(void)
{
//    uint16_t i;
//��ȡFIFO�е�������rDataAд��2���ֽ�
    SCI_readCharArray(SCIA_BASE, sci_rDataA, 2);
//��ȡ2�ֽں�FIFO�Ϳ��ˣ�����ٴη������ݴ��ڽ��н��գ������ٴδ����ж�

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
//��sDataA��FIFOд�������ֽ�
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
//**************************************************GPIO�жϷ�����**********************************************\\
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

//**************************************************spi�жϷ�����**********************************************\\
//SPI a send FIFO ISR
//CPU���������2����FIFO
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
    //������Ա�д���պ����У��

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
                    {//һֱ����
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
//�жϽ������ݺ󣬶����ݽ��д�������У�飬Ҳ���Գ�ȡ����

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
   // ���պ�������
   static unsigned char rx_step = 0;
   switch(rx_step){
       case 0:
               rx_step++;//ѡ�������MRS֡���ص����ݲ���������
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
               endat22Data.error1 = endat22Data.rdata[0]&0x0008;//����λ������13��,���������ݵĵ�4λ
               endat22Data.error1 = endat22Data.error1>>3;
               endat22Data.dataReady = endat22Data.rdata[0]&0x0010;//Sλ������12��,���������ݵĵ�5λ
               endat22Data.dataReady = endat22Data.dataReady>>4;
               for(i=1;i<=3;i++){//��һ������ѭ��ִ��3�Σ�ȡ����3λ
                   result = (endat22Data.rdata[0] & 0x0004) ? 1 :0;//ȡ������ĵ�����3λ
                   result = result<<j;//����Jλ����������ݷ���λ�����ݵ����λ
                   endat22Data.position_lo = endat22Data.position_lo | result;
                   endat22Data.position_lo = endat22Data.position_lo>>1;//Ȼ��λ����������
                   endat22Data.rdata[0] = endat22Data.rdata[0]<<1;
               }
               for( i=1;i<=16;i++){//�ڶ�������ѭ��ִ��15��
                   result = (endat22Data.rdata[1] & 0x8000) ? 1 :0 ;//ȡ����������λ
                   result = result<<j;
                   endat22Data.position_lo = endat22Data.position_lo | result;
                   endat22Data.position_lo = endat22Data.position_lo>>1;
                   endat22Data.rdata[1] = endat22Data.rdata[1]<<1;
               }
               for(i=10;i<=15;i++){//����������ѭ��ִ��6��,ȡ����6λ
                   result = (endat22Data.rdata[2] & 0x8000) ? 1 :0 ;
                   if(i<=14){
                       result = result<<j;
                       endat22Data.position_lo = endat22Data.position_lo | result;
                       endat22Data.position_lo = endat22Data.position_lo>>1;
                   }
                   if(i==15){
                       result = result<<j;
                       endat22Data.position_lo = endat22Data.position_lo | result;
                       //���һλ���ݲ���λ�����ݵ����λ�����ݾ�����ˣ�����Ҫ������
                   }
                   endat22Data.rdata[2] = endat22Data.rdata[2]<<1;
               }
        break;
   }

//*****У������******\\


   // Clear interrupt flag and issue ACK
   SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF);
   Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
//   SPI_disableModule(SPIB_BASE);

}

////epwm�ж�
//__interrupt void epwm1ISR(void)
//{
//    EPWM_clearEventTriggerInterruptFlag(EPWM1_BASE);
//    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);
//    CLB_setGPREG(CLB1_BASE, clb_input & 3UL);
//    asm(" NOP");
//}


////��clb��HLCģ�������CLB�ж�
////��������ڸ��ж�ʹ��SPI����
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
    //�жϽ������ݺ󣬶����ݽ��д���
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

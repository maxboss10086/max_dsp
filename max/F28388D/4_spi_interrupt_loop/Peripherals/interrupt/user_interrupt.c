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
#include "user_spi.h"//����SPI����





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
    for(spib_send_i = 0; spib_send_i < 2; spib_send_i++)
    {
       SPI_writeDataNonBlocking(SPIB_BASE, spib_sData[spib_send_i]);
    }
    // Clear interrupt flag and issue ACK
    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);
}

//SPI b receive FIFO ISR
__interrupt void spibRxFIFOISR(void)
{
    uint16_t spib_read_i = 0;
   // Read data
   for(spib_read_i = 0; spib_read_i < 2; spib_read_i++)
   {//����������񴮿�һ��,һ��������ȡȫ������,��Ҫһ֡һ֡��������������
       spib_rData[spib_read_i] = SPI_readDataNonBlocking(SPIB_BASE);
   }
   // Check received data
   //������Ա�д���պ����У��

   // Clear interrupt flag and issue ACK
   SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF);
   Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP6);

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
    //
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

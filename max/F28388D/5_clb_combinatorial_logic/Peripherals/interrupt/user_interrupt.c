//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.c
// Descriptions:    �����ж�����������ڴ�����
// Author:          Max
// Creation Date:   2020��5��24��
//----------------------------------------------------------------------------------------//
//note:������SPI�ж�

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "clb_config.h"
#include "clb.h"
#include "user_clb.h"

#include "user_interrupt.h"

uint16_t sci_rDataA[2];//���庯�������h�ļ�ֻ����extern�Ѷ���ĺ������ͳ�ȥ
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
//***********************************************�����ж�����**********************************\\
//******************GPIO�ж�ʹ������************************
//void gpio_interrupt_set(){
////1���Ƚ�CPU���ж���������
//    Interrupt_register(INT_XINT1, &xint1ISR);
//    Interrupt_register(INT_XINT2, &xint2ISR);
////2ʹ���ж�����
//    GPIO_enableInterrupt(GPIO_INT_XINT1);         // Enable XINT1
//    GPIO_enableInterrupt(GPIO_INT_XINT2);         // Enable XINT2
////3�����ж������GPIO
//    GPIO_setInterruptPin(0,GPIO_INT_XINT1);
//    GPIO_setInterruptPin(1,GPIO_INT_XINT2);
//    // Configure falling edge trigger for XINT1
////4�����жϴ�������
//    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);
//    // Configure rising edge trigger for XINT2
//    GPIO_setInterruptType(GPIO_INT_XINT2, GPIO_INT_TYPE_RISING_EDGE);
//
//}

//******************SCL�ж�ʹ������************************
//void scl_interrupt_set(void){
//    //��CPU�������ж���������
//        Interrupt_register(INT_SCIA_RX, sciaRXFIFOISR);
//        Interrupt_register(INT_SCIA_TX, sciaTXFIFOISR);
//    //ʹ���ж�
//        Interrupt_enable(INT_SCIA_RX);
//        Interrupt_enable(INT_SCIA_TX);
//        // ѡ��ʹ��Ҫ�жϵ����ͣ�ѡ��FIFO�жϣ�����������ready�жϵ�
//        SCI_enableInterrupt(SCIA_BASE, (SCI_INT_RXFF));//ʹ�ܽ����жϣ���ʹ�ܷ����жϣ�������պͷ��Ͷ�ʹ�ܣ���SCI_INT_RXFF|SCI_INT_TXFF
//        SCI_disableInterrupt(SCIA_BASE, SCI_INT_RXERR);//�رս��մ����жϣ�����FIFO�ж�
//    //�����жϴ�������
//        //����FIFO�ж�
//        // The transmit FIFO generates an interrupt when FIFO status
//        // bits are less than or equal to 2 out of 16 words
//        // The receive FIFO generates an interrupt when FIFO status
//        // bits are greater than equal to 2 out of 16 words
//        SCI_setFIFOInterruptLevel(SCIA_BASE, SCI_FIFO_TX2, SCI_FIFO_RX2);
//
//}

//******************SPI�ж�ʹ������************************
//ʹ��spia�����жϲ�����
//void spia_tx_interrupt_set(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_TXFF);
//    SPI_setFIFOInterruptLevel(SPIA_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_TXFF);
//
//}
//ʹ��spia�����жϲ�����
//void spia_rx_interrupt_set(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_RXFF);
//    SPI_setFIFOInterruptLevel(SPIA_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_RXFF);
//
//}
//ʹ��spib�����жϲ�����
//void spib_tx_interrupt_set(void){
//    Interrupt_register(INT_SPIB_TX, &spibTxFIFOISR);
//    Interrupt_enable(INT_SPIB_TX);
//    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
//    SPI_setFIFOInterruptLevel(SPIB_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIB_BASE, SPI_INT_TXFF);
//}
//ʹ��spib�����жϲ�����
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




//***********************************************scl�жϷ�����**********************************\\
//
uint16_t sDataA[2];// Send data for SCI-A
uint16_t rDataA[2];// Received data for SCI-A
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
    //������Ա�д���պ����У��

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
   {//����������񴮿�һ��,һ��������ȡȫ������,��Ҫһ֡һ֡��������������
       spib_rData[spi_i] = SPI_readDataNonBlocking(SPIB_BASE);
   }
   // Check received data
   //������Ա�д���պ����У��

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

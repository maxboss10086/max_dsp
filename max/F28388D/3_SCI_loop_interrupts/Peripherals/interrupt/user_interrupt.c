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


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#include <F2838X_lib/device/device.h>//��������
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/common_include/f28x_project.h>
#include <F2838X_lib/user_JTAG.h>


#include "user_interrupt.h"


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
//GPIO�ж�����
void gpio_interrupt_set(){
//1���Ƚ�CPU���ж���������
    Interrupt_register(INT_XINT1, &xint1ISR);
    Interrupt_register(INT_XINT2, &xint2ISR);
//2ʹ���ж�����
    GPIO_enableInterrupt(GPIO_INT_XINT1);         // Enable XINT1
    GPIO_enableInterrupt(GPIO_INT_XINT2);         // Enable XINT2
//3�����ж������GPIO
    GPIO_setInterruptPin(0,GPIO_INT_XINT1);
    GPIO_setInterruptPin(1,GPIO_INT_XINT2);
    // Configure falling edge trigger for XINT1
//4�����жϴ�������
    GPIO_setInterruptType(GPIO_INT_XINT1, GPIO_INT_TYPE_FALLING_EDGE);
    // Configure rising edge trigger for XINT2
    GPIO_setInterruptType(GPIO_INT_XINT2, GPIO_INT_TYPE_RISING_EDGE);

}

//scl
void scl_interrupt_set(void){
    //��CPU�������ж���������
        Interrupt_register(INT_SCIA_RX, sciaRXFIFOISR);
        Interrupt_register(INT_SCIA_TX, sciaTXFIFOISR);
    //ʹ���ж�
        Interrupt_enable(INT_SCIA_RX);
        Interrupt_enable(INT_SCIA_TX);
        // ѡ��ʹ��Ҫ�жϵ����ͣ�ѡ��FIFO�жϣ�����������ready�жϵ�
        SCI_enableInterrupt(SCIA_BASE, (SCI_INT_RXFF));//ʹ�ܽ����жϣ���ʹ�ܷ����жϣ�������պͷ��Ͷ�ʹ�ܣ���SCI_INT_RXFF|SCI_INT_TXFF
        SCI_disableInterrupt(SCIA_BASE, SCI_INT_RXERR);//�رս��մ����жϣ�����FIFO�ж�
    //�����жϴ�������
        //����FIFO�ж�
        // The transmit FIFO generates an interrupt when FIFO status
        // bits are less than or equal to 2 out of 16 words
        // The receive FIFO generates an interrupt when FIFO status
        // bits are greater than equal to 2 out of 16 words
        SCI_setFIFOInterruptLevel(SCIA_BASE, SCI_FIFO_TX2, SCI_FIFO_RX2);

}

//************************************************************************************************\\
//

//***********************************************scl�жϷ�����**********************************\\
//
uint16_t sci_sDataA[2];// Send data for SCI-A
uint16_t sci_rDataA[2];// Received data for SCI-A
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





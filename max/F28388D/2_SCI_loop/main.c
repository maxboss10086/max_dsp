//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020��5��22��
//----------------------------------------------------------------------------------------//
//note:������initSCIAFIFO�������Ͷ�����FIFO�е�����

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

//
// Included Files
//
#include <F2838X_lib/device/device.h>//��������
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/common_include/f28x_project.h>
//
#include "user_scl.h"
//
uint16_t  receivedChar;
// Main
void main(void)
{
//***********************************************ϵͳ��ʼ��**********************************\\
// Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    Interrupt_initModule();
//      // Initialize the PIE vector table with pointers to the shell Interrupt
//      // Service Routines (ISR).
    Interrupt_initVectorTable();
//      // Enables CPU interrupts
    Interrupt_enableMaster();
    EINT;
    ERTM;



//***********************************************�����ʼ������**********************************\\
//��������Ϊ9600,���պͷ��ʹ��ڶ��򿪣�����FIFOΪ�տ����жϣ����յ�4�ֽڿ����ж�
    scia_init_set();
//***********************************************����ִ��***************************************\\
//����ִ��

     while(1){
            while(SCI_getRxFIFOStatus(SCIA_BASE) == SCI_FIFO_RX0){
                //��ȡ ����FIFO��״̬�Ĵ������ж��Ƿ�Ϊ�գ����FIFOһֱ�ǿ���һֱ�ȴ���������������ݾ�������
            }
    // ���յ�����֮�󣬶�ȡFIFO�е�����
       receivedChar = scia_receive();
       scia_send(receivedChar);//��ȡFIFO�е����ݽ��з���
       }










}

//
// End of File
//

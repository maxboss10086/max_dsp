//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    ��λ����оƬ�������ݣ��������κ󣬴���FIFO�жϣ���ȡFIFO�е����ݴ���rData���飬ʹFIFOΪ��
// Author:          Max
// Creation Date:   2020��5��22��
//----------------------------------------------------------------------------------------//
//note:������initSCIAFIFO�������Ͷ�����FIFO�е�����
//
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

//
// Included Files
//
#include <F2838X_lib/device/device.h>//��������
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/common_include/f28x_project.h>
#include <stdbool.h>
//
#include "user_scl.h"
#include "user_interrupt.h"
//
uint16_t  receivedChar;
bool      ack_data;
// Main
void main(void)
{
//***********************************************ϵͳ��ʼ��**********************************\\
// Initialize device clock and peripherals
    Device_init();
//    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
//    // Initialize PIE and clear PIE registers. Disables CPU interrupts
    interrupt_init_set();
    EINT;
    ERTM;

//***********************************************�����ʼ������**********************************\\
//��������Ϊ9600,���պͷ��ʹ��ڶ���
//scia�ж�����ΪС��2��ֱ�����������жϣ����������ֽ����������ж�
    scia_init_set();


//***********************************************����ִ��***************************************\\
//����ִ��

     while(1){
            ack_data=sci_reveive_ack();
            while(!sci_reveive_ack()){
                //û����Ӧ��һֱͣ������
            }
    // ���յ�����֮��,��ȡFIFO�е�����
       }










}

//
// End of File
//

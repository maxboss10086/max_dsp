

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
//��������Ϊ9600
    scia_init_set();
//***********************************************����ִ��***************************************\\
//����ִ��
    while(1) {
        scia_send('g');//��ȡFIFO�е����ݽ��з���
        DELAY_US(500000);
    }









}

//
// End of File
//

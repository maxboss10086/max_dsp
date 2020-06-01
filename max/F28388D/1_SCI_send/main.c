

//
// Included Files
//
#include <F2838X_lib/device/device.h>//引入外设
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/device/driverlib.h>
#include <F2838X_lib/common_include/f28x_project.h>
//
#include "user_scl.h"
//
// Main
void main(void)
{
//***********************************************系统初始化**********************************\\
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



//***********************************************外设初始化设置**********************************\\
//串口设置为9600
    scia_init_set();
//***********************************************函数执行***************************************\\
//函数执行
    while(1) {
        scia_send('g');//读取FIFO中的数据进行发送
        DELAY_US(500000);
    }









}

//
// End of File
//

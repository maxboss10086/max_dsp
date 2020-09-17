//#############################################################################
//
// FILE:   empty_bitfield_driverlib_main.c
//
// TITLE:  Empty Example
//
// Empty Bit-Field & Driverlib Example
//
// This example is an empty project setup for Bit-Field and Driverlib 
// development.
//
//#############################################################################
// $TI Release: F2838x Support Library v3.02.00.00 $
// $Release Date: Tue May 26 17:21:56 IST 2020 $
// $Copyright:
// Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "f28x_project.h"
#include "driverlib.h"
#include "device.h"
//
// Main
//
void main(void)
{

    //***********************************************系统初始化**********************************\\
    // Initialize device clock and peripherals
        // PLLSYSCLK = 20MHz (XTAL_OSC) * 40 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 1(SYSDIV))=200M
    //
    // Initialize device clock and peripherals
    //


    Device_init();
    // Setup GPIO by disabling pin locks and enabling pullups
    Device_initGPIO();
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initModule();

    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();


    //***********************************************外设初始化设置**********************************\\

    EALLOW;
    GPIO_setPadConfig( 62, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode( 62, GPIO_DIR_MODE_OUT);
    EDIS;


    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
        EINT;
        ERTM;
    ////***********************************************函数执行***************************************\\
    ////函数执行
    while(1){
        GpioDataRegs.GPBDAT.bit.GPIO62 = 1;
        DELAY_US(5000);
        GpioDataRegs.GPBDAT.bit.GPIO62 = 0;
        DELAY_US(5000);
    }
}

//
// End of File
//
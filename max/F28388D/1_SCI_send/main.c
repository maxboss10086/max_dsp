//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
// TITLE:  Empty Project
//
// Empty Project Example
//
// This example is an empty project setup for Driverlib development.
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

#include "driverlib.h"
#include "device.h"
#include "user_interrupt.h"

#include "user_sci.h"
//
// Main
void main(void)
{
//***********************************************ϵͳ��ʼ��**********************************\\
    // Initialize device clock and peripherals
        // PLLSYSCLK = 20MHz (XTAL_OSC) * 40 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 1(SYSDIV))=200M
        Device_init();
    //    // Setup GPIO by disabling pin locks and enabling pullups
        Device_initGPIO();
    //    // Initialize PIE and clear PIE registers. Disables CPU interrupts
        interrupt_init_set();
//***********************************************�����ʼ������**********************************\\
//��������Ϊ9600,GPIO29���ͣ�28����
    sci_init_set(SCIA);


// Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    EINT;
    ERTM;
//***********************************************����ִ��***************************************\\
//����ִ��
    while(1) {
        sci_send(SCIA,'a');//��ȡFIFO�е����ݽ��з���
        DEVICE_DELAY_US(500000);
    }













}

//
// End of File
//

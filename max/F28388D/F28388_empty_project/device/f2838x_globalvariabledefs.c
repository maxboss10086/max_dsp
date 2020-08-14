//###########################################################################
//
// FILE:    f2838x_globalvariabledefs.c
//
// TITLE:   f2838x Global Variables and Data Section Pragmas.
//
//###########################################################################
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
//###########################################################################

#include "f2838x_device.h"     // f2838x Headerfile Include File

//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcaRegsFile")
#else
#pragma DATA_SECTION(AdcaRegs,"AdcaRegsFile");
#endif
volatile struct ADC_REGS AdcaRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("AdcbRegsFile")
#else
#pragma DATA_SECTION(AdcbRegs,"AdcbRegsFile");
#endif
volatile struct ADC_REGS AdcbRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("AdccRegsFile")
#else
#pragma DATA_SECTION(AdccRegs,"AdccRegsFile");
#endif
volatile struct ADC_REGS AdccRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("AdcdRegsFile")
#else
#pragma DATA_SECTION(AdcdRegs,"AdcdRegsFile");
#endif
volatile struct ADC_REGS AdcdRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcaResultFile")
#else
#pragma DATA_SECTION(AdcaResultRegs,"AdcaResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcaResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcbResultFile")
#else
#pragma DATA_SECTION(AdcbResultRegs,"AdcbResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcbResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdccResultFile")
#else
#pragma DATA_SECTION(AdccResultRegs,"AdccResultFile");
#endif
volatile struct ADC_RESULT_REGS AdccResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcdResultFile")
#else
#pragma DATA_SECTION(AdcdResultRegs,"AdcdResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcdResultRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("AnalogSubsysRegsFile")
#else
#pragma DATA_SECTION(AnalogSubsysRegs,"AnalogSubsysRegsFile");
#endif
volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("BgcrcRegsFile")
#else
#pragma DATA_SECTION(BgcrcCpuRegs,"BgcrcRegsFile");
#endif
volatile struct BGCRC_REGS BgcrcCpuRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("BgcrcRegsFile")
#else
#pragma DATA_SECTION(BgcrcCla1Regs,"BgcrcRegsFile");
#endif
volatile struct BGCRC_REGS BgcrcCla1Regs;
//----------------------------------------

#if __TI_COMPILER_VERSION__ >= 16006000
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CanaRegsFile")
#else
#pragma DATA_SECTION(CanaRegs,"CanaRegsFile");
#endif
volatile struct CAN_REGS CanaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CanbRegsFile")
#else
#pragma DATA_SECTION(CanbRegs,"CanbRegsFile");
#endif
volatile struct CAN_REGS CanbRegs;
#endif

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("CmConfRegsFile")
#else
#pragma DATA_SECTION(CmConfRegs,"CmConfRegsFile");
#endif
volatile struct CM_CONF_REGS CmConfRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss1RegsFile")
#else
#pragma DATA_SECTION(Cmpss1Regs,"Cmpss1RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss2RegsFile")
#else
#pragma DATA_SECTION(Cmpss2Regs,"Cmpss2RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss3RegsFile")
#else
#pragma DATA_SECTION(Cmpss3Regs,"Cmpss3RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss4RegsFile")
#else
#pragma DATA_SECTION(Cmpss4Regs,"Cmpss4RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss5RegsFile")
#else
#pragma DATA_SECTION(Cmpss5Regs,"Cmpss5RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss6RegsFile")
#else
#pragma DATA_SECTION(Cmpss6Regs,"Cmpss6RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss7RegsFile")
#else
#pragma DATA_SECTION(Cmpss7Regs,"Cmpss7RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss8RegsFile")
#else
#pragma DATA_SECTION(Cmpss8Regs,"Cmpss8RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss8Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DacaRegsFile")
#else
#pragma DATA_SECTION(DacaRegs,"DacaRegsFile");
#endif
volatile struct DAC_REGS DacaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DacbRegsFile")
#else
#pragma DATA_SECTION(DacbRegs,"DacbRegsFile");
#endif
volatile struct DAC_REGS DacbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DaccRegsFile")
#else
#pragma DATA_SECTION(DaccRegs,"DaccRegsFile");
#endif
volatile struct DAC_REGS DaccRegs;
//----------------------------------------

#ifdef __cplusplus
#pragma DATA_SECTION("Cla1RegsFile")
#else
#pragma DATA_SECTION(Cla1Regs,"Cla1RegsFile");
#endif
volatile struct CLA_REGS Cla1Regs;

//----------------------------------------

#ifdef __cplusplus
#pragma DATA_SECTION("ClkCfgRegsFile")
#else
#pragma DATA_SECTION(ClkCfgRegs,"ClkCfgRegsFile");
#endif
volatile struct CLK_CFG_REGS ClkCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuSysRegsFile")
#else
#pragma DATA_SECTION(CpuSysRegs,"CpuSysRegsFile");
#endif
volatile struct CPU_SYS_REGS CpuSysRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer0RegsFile")
#else
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer1RegsFile")
#else
#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer2RegsFile")
#else
#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer2Regs;

//----------------------------------------

#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ1RegsFile")
#else
#pragma DATA_SECTION(DcsmZ1Regs,"DcsmZ1RegsFile");
#endif
volatile struct DCSM_Z1_REGS DcsmZ1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ2RegsFile")
#else
#pragma DATA_SECTION(DcsmZ2Regs,"DcsmZ2RegsFile");
#endif
volatile struct DCSM_Z2_REGS DcsmZ2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmCommonRegsFile")
#else
#pragma DATA_SECTION(DcsmCommonRegs,"DcsmCommonRegsFile");
#endif
volatile struct DCSM_COMMON_REGS DcsmCommonRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ1OtpFile")
#else
#pragma DATA_SECTION(DcsmZ1Otp,"DcsmZ1OtpFile");
#endif
volatile struct DCSM_Z1_OTP DcsmZ1Otp;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmZ2OtpFile")
#else
#pragma DATA_SECTION(DcsmZ2Otp,"DcsmZ2OtpFile");
#endif
volatile struct DCSM_Z2_OTP DcsmZ2Otp;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Dcc0RegsFile")
#else
#pragma DATA_SECTION(Dcc0Regs,"Dcc0RegsFile");
#endif
volatile struct DCC_REGS Dcc0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Dcc1RegsFile")
#else
#pragma DATA_SECTION(Dcc1Regs,"Dcc1RegsFile");
#endif
volatile struct DCC_REGS Dcc1Regs;

//----------------------------------------

#ifdef __cplusplus
#pragma DATA_SECTION("Dcc2RegsFile")
#else
#pragma DATA_SECTION(Dcc2Regs,"Dcc2RegsFile");
#endif
volatile struct DCC_REGS Dcc2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaRegsFile")
#else
#pragma DATA_SECTION(DmaRegs,"DmaRegsFile");
#endif
volatile struct DMA_REGS DmaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaClaSrcSelRegsFile")
#else
#pragma DATA_SECTION(DmaClaSrcSelRegs,"DmaClaSrcSelRegsFile");
#endif
volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("DevCfgRegsFile")
#else
#pragma DATA_SECTION(DevCfgRegs,"DevCfgRegsFile");
#endif
volatile struct DEV_CFG_REGS DevCfgRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap1RegsFile")
#else
#pragma DATA_SECTION(ECap1Regs,"ECap1RegsFile");
#endif
volatile struct ECAP_REGS ECap1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap2RegsFile")
#else
#pragma DATA_SECTION(ECap2Regs,"ECap2RegsFile");
#endif
volatile struct ECAP_REGS ECap2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap3RegsFile")
#else
#pragma DATA_SECTION(ECap3Regs,"ECap3RegsFile");
#endif
volatile struct ECAP_REGS ECap3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap4RegsFile")
#else
#pragma DATA_SECTION(ECap4Regs,"ECap4RegsFile");
#endif
volatile struct ECAP_REGS ECap4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap5RegsFile")
#else
#pragma DATA_SECTION(ECap5Regs,"ECap5RegsFile");
#endif
volatile struct ECAP_REGS ECap5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap6RegsFile")
#else
#pragma DATA_SECTION(ECap6Regs,"ECap6RegsFile");
#endif
volatile struct ECAP_REGS ECap6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap7RegsFile")
#else
#pragma DATA_SECTION(ECap7Regs,"ECap7RegsFile");
#endif
volatile struct ECAP_REGS ECap7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif1RegsFile")
#else
#pragma DATA_SECTION(Emif1Regs,"Emif1RegsFile");
#endif
volatile struct EMIF_REGS  Emif1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif2RegsFile")
#else
#pragma DATA_SECTION(Emif2Regs,"Emif2RegsFile");
#endif
volatile struct EMIF_REGS  Emif2Regs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("EcatssConfigRegsFile")
#else
#pragma DATA_SECTION(EcatssConfigRegs,"EcatssConfigRegsFile");
#endif
volatile struct ECATSS_CONFIG_REGS EcatssConfigRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EcatssRegsFile")
#else
#pragma DATA_SECTION(EcatssRegs,"EcatssRegsFile");
#endif
volatile struct ECATSS_REGS EcatssRegs;
#endif
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep1RegsFile")
#else
#pragma DATA_SECTION(EQep1Regs,"EQep1RegsFile");
#endif
volatile struct EQEP_REGS EQep1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep2RegsFile")
#else
#pragma DATA_SECTION(EQep2Regs,"EQep2RegsFile");
#endif
volatile struct EQEP_REGS EQep2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep3RegsFile")
#else
#pragma DATA_SECTION(EQep3Regs,"EQep3RegsFile");
#endif
volatile struct EQEP_REGS EQep3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm1RegsFile")
#else
#pragma DATA_SECTION(EPwm1Regs,"EPwm1RegsFile");
#endif
volatile struct EPWM_REGS EPwm1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm2RegsFile")
#else
#pragma DATA_SECTION(EPwm2Regs,"EPwm2RegsFile");
#endif
volatile struct EPWM_REGS EPwm2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm3RegsFile")
#else
#pragma DATA_SECTION(EPwm3Regs,"EPwm3RegsFile");
#endif
volatile struct EPWM_REGS EPwm3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm4RegsFile")
#else
#pragma DATA_SECTION(EPwm4Regs,"EPwm4RegsFile");
#endif
volatile struct EPWM_REGS EPwm4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm5RegsFile")
#else
#pragma DATA_SECTION(EPwm5Regs,"EPwm5RegsFile");
#endif
volatile struct EPWM_REGS EPwm5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm6RegsFile")
#else
#pragma DATA_SECTION(EPwm6Regs,"EPwm6RegsFile");
#endif
volatile struct EPWM_REGS EPwm6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm7RegsFile")
#else
#pragma DATA_SECTION(EPwm7Regs,"EPwm7RegsFile");
#endif
volatile struct EPWM_REGS EPwm7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm8RegsFile")
#else
#pragma DATA_SECTION(EPwm8Regs,"EPwm8RegsFile");
#endif
volatile struct EPWM_REGS EPwm8Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm9RegsFile")
#else
#pragma DATA_SECTION(EPwm9Regs,"EPwm9RegsFile");
#endif
volatile struct EPWM_REGS EPwm9Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm10RegsFile")
#else
#pragma DATA_SECTION(EPwm10Regs,"EPwm10RegsFile");
#endif
volatile struct EPWM_REGS EPwm10Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm11RegsFile")
#else
#pragma DATA_SECTION(EPwm11Regs,"EPwm11RegsFile");
#endif
volatile struct EPWM_REGS EPwm11Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm12RegsFile")
#else
#pragma DATA_SECTION(EPwm12Regs,"EPwm12RegsFile");
#endif
volatile struct EPWM_REGS EPwm12Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm13RegsFile")
#else
#pragma DATA_SECTION(EPwm13Regs,"EPwm13RegsFile");
#endif
volatile struct EPWM_REGS EPwm13Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm14RegsFile")
#else
#pragma DATA_SECTION(EPwm14Regs,"EPwm14RegsFile");
#endif
volatile struct EPWM_REGS EPwm14Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm15RegsFile")
#else
#pragma DATA_SECTION(EPwm15Regs,"EPwm15RegsFile");
#endif
volatile struct EPWM_REGS EPwm15Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm16RegsFile")
#else
#pragma DATA_SECTION(EPwm16Regs,"EPwm16RegsFile");
#endif
volatile struct EPWM_REGS EPwm16Regs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("EPwmXbarRegsFile")
#else
#pragma DATA_SECTION(EPwmXbarRegs,"EPwmXbarRegsFile");
#endif
volatile struct EPWM_XBAR_REGS EPwmXbarRegs;
#endif
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EradGlobalRegsFile")
#else
#pragma DATA_SECTION(EradGlobalRegs,"EradGlobalRegsFile");
#endif
volatile struct ERAD_GLOBAL_REGS EradGlobalRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EradHwbpRegsFile")
#else
#pragma DATA_SECTION(EradHwbpRegs,"EradHwbpRegsFile");
#endif
volatile struct ERAD_HWBP_REGS EradHwbpRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EradCounterRegsFile")
#else
#pragma DATA_SECTION(EradCounterRegs,"EradCounterRegsFile");
#endif
volatile struct ERAD_COUNTER_REGS EradCounterRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EradCrcRegsFile")
#else
#pragma DATA_SECTION(EradCrcRegs,"EradCrcRegsFile");
#endif
volatile struct ERAD_CRC_REGS EradCrcRegs;


//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiTxaRegsFile")
#else
#pragma DATA_SECTION(FsiTxaRegs,"FsiTxaRegsFile");
#endif
volatile struct FSI_TX_REGS FsiTxaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiTxbRegsFile")
#else
#pragma DATA_SECTION(FsiTxbRegs,"FsiTxbRegsFile");
#endif
volatile struct FSI_TX_REGS FsiTxbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxaRegsFile")
#else
#pragma DATA_SECTION(FsiRxaRegs,"FsiRxaRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxbRegsFile")
#else
#pragma DATA_SECTION(FsiRxbRegs,"FsiRxbRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxbRegs;
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxcRegsFile")
#else
#pragma DATA_SECTION(FsiRxcRegs,"FsiRxcRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxcRegs;
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxdRegsFile")
#else
#pragma DATA_SECTION(FsiRxdRegs,"FsiRxdRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxdRegs;
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxeRegsFile")
#else
#pragma DATA_SECTION(FsiRxeRegs,"FsiRxeRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxeRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxfRegsFile")
#else
#pragma DATA_SECTION(FsiRxfRegs,"FsiRxfRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxfRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxgRegsFile")
#else
#pragma DATA_SECTION(FsiRxgRegs,"FsiRxgRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxhRegsFile")
#else
#pragma DATA_SECTION(FsiRxhRegs,"FsiRxhRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxhRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("GpioCtrlRegsFile")
#else
#pragma DATA_SECTION(GpioCtrlRegs,"GpioCtrlRegsFile");
#endif
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioDataRegsFile")
#else
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------

#ifdef __cplusplus
#pragma DATA_SECTION("HRCap6RegsFile")
#else
#pragma DATA_SECTION(HRCap6Regs,"HRCap6RegsFile");
#endif
volatile struct HRCAP_REGS HRCap6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("HRCap7RegsFile")
#else
#pragma DATA_SECTION(HRCap7Regs,"HRCap7RegsFile");
#endif
volatile struct HRCAP_REGS HRCap7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("HwbistRegsFile")
#else
#pragma DATA_SECTION(HwbistRegs,"HwbistRegsFile");
#endif
volatile struct HWBIST_REGS HwbistRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("InputXbarRegsFile")
#else
#pragma DATA_SECTION(InputXbarRegs,"InputXbarRegsFile");
#endif
volatile struct INPUT_XBAR_REGS InputXbarRegs;
#endif

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("XbarRegsFile")
#else
#pragma DATA_SECTION(XbarRegs,"XbarRegsFile");
#endif
volatile struct XBAR_REGS XbarRegs;
#endif

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("OutputXbarRegsFile")
#else
#pragma DATA_SECTION(OutputXbarRegs,"OutputXbarRegsFile");
#endif
volatile struct OUTPUT_XBAR_REGS OutputXbarRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2caRegsFile")
#else
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
#endif
volatile struct I2C_REGS I2caRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2cbRegsFile")
#else
#pragma DATA_SECTION(I2cbRegs,"I2cbRegsFile");
#endif
volatile struct I2C_REGS I2cbRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("IpcRegsCPUFile")
#else
#pragma DATA_SECTION(Cpu1toCpu2IpcRegs,"IpcRegsCPUFile");
#endif
volatile struct CPU1TOCPU2_IPC_REGS_CPU1VIEW Cpu1toCpu2IpcRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("IpcRegsCMFile")
#else
#pragma DATA_SECTION(Cpu1toCmIpcRegs,"IpcRegsCMFile");
#endif
volatile struct CPU1TOCM_IPC_REGS_CPU1VIEW Cpu1toCmIpcRegs;
#endif

//----------------------------------------
#ifdef CPU2
#ifdef __cplusplus
#pragma DATA_SECTION("IpcRegsCPUFile")
#else
#pragma DATA_SECTION(Cpu2toCpu1IpcRegs,"IpcRegsCPUFile");
#endif
volatile struct CPU1TOCPU2_IPC_REGS_CPU2VIEW Cpu2toCpu1IpcRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("IpcRegsCMFile")
#else
#pragma DATA_SECTION(Cpu2toCmIpcRegs,"IpcRegsCMFile");
#endif
volatile struct CPU2TOCM_IPC_REGS_CPU2VIEW Cpu2toCmIpcRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspaRegsFile")
#else
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
#endif
volatile struct McBSP_REGS McbspaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McbspbRegsFile")
#else
#pragma DATA_SECTION(McbspbRegs,"McbspbRegsFile");
#endif
volatile struct McBSP_REGS McbspbRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("McanErrorRegsFile")
#else
#pragma DATA_SECTION(McanErrorRegs,"McanErrorRegsFile");
#endif
volatile struct MCAN_ERROR_REGS McanErrorRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McanRegsFile")
#else
#pragma DATA_SECTION(McanRegs,"McanRegsFile");
#endif
volatile struct MCAN_REGS McanRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("McanssRegsFile")
#else
#pragma DATA_SECTION(McanssRegs,"McanssRegsFile");
#endif
volatile struct MCANSS_REGS McanssRegs;
#endif
//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("RomPrefetchRegsFile")
#else
#pragma DATA_SECTION(RomPrefetchRegs,"RomPrefetchRegsFile");
#endif
volatile struct ROM_PREFETCH_REGS RomPrefetchRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("MemCfgRegsFile")
#else
#pragma DATA_SECTION(MemCfgRegs,"MemCfgRegsFile");
#endif
volatile struct MEM_CFG_REGS MemCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Emif1ConfigRegsFile")
#else
#pragma DATA_SECTION(Emif1ConfigRegs,"Emif1ConfigRegsFile");
#endif
volatile struct EMIF1_CONFIG_REGS Emif1ConfigRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("Emif2ConfigRegsFile")
#else
#pragma DATA_SECTION(Emif2ConfigRegs,"Emif2ConfigRegsFile");
#endif
volatile struct EMIF2_CONFIG_REGS Emif2ConfigRegs;
#endif

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("RomWaitStateRegsFile")
#else
#pragma DATA_SECTION(RomWaitStateRegs,"RomWaitStateRegsFile");
#endif
volatile struct ROM_WAIT_STATE_REGS RomWaitStateRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AccessProtectionRegsFile")
#else
#pragma DATA_SECTION(AccessProtectionRegs,"AccessProtectionRegsFile");
#endif
volatile struct ACCESS_PROTECTION_REGS AccessProtectionRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("MemoryErrorRegsFile")
#else
#pragma DATA_SECTION(MemoryErrorRegs,"MemoryErrorRegsFile");
#endif
volatile struct MEMORY_ERROR_REGS MemoryErrorRegs;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("TestErrorRegsFile")
#else
#pragma DATA_SECTION(TestErrorRegs,"TestErrorRegsFile");
#endif
volatile struct TEST_ERROR_REGS TestErrorRegs;
#endif
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("NmiIntruptRegsFile")
#else
#pragma DATA_SECTION(NmiIntruptRegs,"NmiIntruptRegsFile");
#endif
volatile struct NMI_INTRUPT_REGS NmiIntruptRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieCtrlRegsFile")
#else
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
#endif
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieVectTableFile")
#else
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
#endif
volatile struct PIE_VECT_TABLE PieVectTable;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PmbusaRegsFile")
#else
#pragma DATA_SECTION(PmbusaRegs,"PmbusaRegsFile");
#endif
volatile struct PMBUS_REGS PmbusaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SciaRegsFile")
#else
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
#endif
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScibRegsFile")
#else
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
#endif
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScicRegsFile")
#else
#pragma DATA_SECTION(ScicRegs,"ScicRegsFile");
#endif
volatile struct SCI_REGS ScicRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScidRegsFile")
#else
#pragma DATA_SECTION(ScidRegs,"ScidRegsFile");
#endif
volatile struct SCI_REGS ScidRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpiaRegsFile")
#else
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
#endif
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpibRegsFile")
#else
#pragma DATA_SECTION(SpibRegs,"SpibRegsFile");
#endif
volatile struct SPI_REGS SpibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpicRegsFile")
#else
#pragma DATA_SECTION(SpicRegs,"SpicRegsFile");
#endif
volatile struct SPI_REGS SpicRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpidRegsFile")
#else
#pragma DATA_SECTION(SpidRegs,"SpidRegsFile");
#endif
volatile struct SPI_REGS SpidRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Sdfm1RegsFile")
#else
#pragma DATA_SECTION(Sdfm1Regs,"Sdfm1RegsFile");
#endif
volatile struct SDFM_REGS Sdfm1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Sdfm2RegsFile")
#else
#pragma DATA_SECTION(Sdfm2Regs,"Sdfm2RegsFile");
#endif
volatile struct SDFM_REGS Sdfm2Regs;

//----------------------------------------

#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("SysPeriphAcRegsFile")
#else
#pragma DATA_SECTION(SysPeriphAcRegs,"SysPeriphAcRegsFile");
#endif
volatile struct CPU1_PERIPH_AC_REGS SysPeriphAcRegs;
#endif

//----------------------------------------

#ifdef CPU2
#ifdef __cplusplus
#pragma DATA_SECTION("SysPeriphAcRegsFile")
#else
#pragma DATA_SECTION(SysPeriphAcRegs,"SysPeriphAcRegsFile");
#endif
volatile struct CPU2_PERIPH_AC_REGS SysPeriphAcRegs;
#endif

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("SyncSocRegsFile")
#else
#pragma DATA_SECTION(SyncSocRegs,"SyncSocRegsFile");
#endif
volatile struct SYNC_SOC_REGS SyncSocRegs;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SysStatusRegsFile")
#else
#pragma DATA_SECTION(SysStatusRegs,"SysStatusRegsFile");
#endif
volatile struct SYS_STATUS_REGS SysStatusRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("WdRegsFile")
#else
#pragma DATA_SECTION(WdRegs,"WdRegsFile");
#endif
volatile struct WD_REGS WdRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XintRegsFile")
#else
#pragma DATA_SECTION(XintRegs,"XintRegsFile");
#endif
volatile struct XINT_REGS XintRegs;

//--------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EmuBModeVar");
#else
#pragma DATA_SECTION(EmuBMode,"EmuBModeVar");
#endif
Uint16 EmuBMode;

//----------------------------------------
#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("EmuBootPinsVar");
#else
#pragma DATA_SECTION(EmuBootPins,"EmuBootPinsVar");
#endif
Uint16 EmuBootPins;
#endif

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash0EccRegsFile")
#else
#pragma DATA_SECTION(Flash0EccRegs,"Flash0EccRegsFile");
#endif
volatile struct FLASH_ECC_REGS Flash0EccRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash0CtrlRegsFile")
#else
#pragma DATA_SECTION(Flash0CtrlRegs,"Flash0CtrlRegsFile");
#endif
volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;


//===========================================================================
// End of file.
//===========================================================================


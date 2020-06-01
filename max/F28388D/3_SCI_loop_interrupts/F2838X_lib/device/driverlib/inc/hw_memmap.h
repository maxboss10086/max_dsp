//###########################################################################
//
// FILE:    hw_memmap.h
//
// TITLE:   Macros defining the memory map of the C28x.
//
//###########################################################################
// $TI Release: F2838x Support Library v3.01.00.00 $
// $Release Date: Thu Mar 19 07:48:04 IST 2020 $
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

#ifndef HW_MEMMAP_H
#define HW_MEMMAP_H

//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals.
//
//*****************************************************************************
#define  ADCA_BASE                0x00007400U    //ADCA Registers
#define  ADCB_BASE                0x00007480U    //ADCB Registers
#define  ADCC_BASE                0x00007500U    //ADCC Registers
#define  ADCD_BASE                0x00007580U    //ADCD Registers
#define  ADCARESULT_BASE          0x00000B00U    //ADCA Result Registers
#define  ADCBRESULT_BASE          0x00000B20U    //ADCB Result Registers
#define  ADCCRESULT_BASE          0x00000B40U    //ADCC Result Registers
#define  ADCDRESULT_BASE          0x00000B60U    //ADCD Result Registers
#define  CPUTIMER0_BASE           0x00000C00U    // CPU Timer 0 Registers
#define  CPUTIMER1_BASE           0x00000C08U    // CPU Timer 1 Registers
#define  CPUTIMER2_BASE           0x00000C10U    // CPU Timer 2 Registers
#define  PIECTRL_BASE             0x00000CE0U    // PIE Registers
#define  DMA_BASE                 0x00001000U    // DMA Control Registers
#define  DMA_CH1_BASE             0x00001020U    // DMA Channel Registers
#define  DMA_CH2_BASE             0x00001040U    // DMA Channel Registers
#define  DMA_CH3_BASE             0x00001060U    // DMA Channel Registers
#define  DMA_CH4_BASE             0x00001080U    // DMA Channel Registers
#define  DMA_CH5_BASE             0x000010A0U    // DMA Channel Registers
#define  DMA_CH6_BASE             0x000010C0U    // DMA Channel Registers
#define  CLA1_BASE                0x00001400U    // CPU1.CLA1 Registers
#define  MCBSPA_BASE              0x00006000U    // McBSP A Registers
#define  MCBSPB_BASE              0x00006040U    // McBSP B Registers
#define  SPIA_BASE                0x00006100U    // SPI A Registers
#define  SPIB_BASE                0x00006110U    // SPI B Registers
#define  SPIC_BASE                0x00006120U    // SPI C Registers
#define  SPID_BASE                0x00006130U    // SPI D Registers
#define  BGCRC_CLA1_BASE          0x00006380U    //CLA1 Background CRC Registers
#define  BGCRC_CPU_BASE           0x00006340U    //CPU Background CRC Registers
#define  PMBUSA_BASE              0x00006400U    //PMBUSA Registers
#define  FSITXA_BASE              0x00006600U    // FSITX A Configuration Registers
#define  FSIRXA_BASE              0x00006680U    // FSIRX AConfiguration Registers
#define  FSITXB_BASE              0x00006700U    // FSITX B Configuration Registers
#define  FSIRXB_BASE              0x00006780U    // FSIRX B Configuration Registers
#define  FSIRXC_BASE              0x00006880U    // FSIRX C Configuration Registers
#define  FSIRXD_BASE              0x00006980U    // FSIRX D Configuration Registers
#define  FSIRXE_BASE              0x00006A80U    // FSIRX E Configuration Registers
#define  FSIRXF_BASE              0x00006B80U    // FSIRX F Configuration Registers
#define  FSIRXG_BASE              0x00006C80U    // FSIRX G Configuration Registers
#define  FSIRXH_BASE              0x00006D80U    // FSIRX H Configuration Registers
#define  CANA_BASE                0x00048000U    // CAN-A Registers
#define  CANA_MSG_RAM_BASE        0x00049000U    // CAN-A Message RAM
#define  CANB_BASE                0x0004A000U    // CAN-B Registers
#define  CANB_MSG_RAM_BASE        0x0004B000U    // CAN-B Message RAM
#define  ESC_SS_BASE              0x00057E00U    //Ethercat Sub-System Registers
#define  ESC_SS_CONFIG_BASE       0x00057F00U    //Ethercat Sub-System configuration Registers
#define  CLB1_BASE                0x00003000U    //CLB1 Registers
#define  CLB1_LOGICCFG_BASE       0x00003000U    // CLB 1 Logic Config Registers
#define  CLB1_LOGICCTL_BASE       0x00003100U    // CLB 1 Logic Control Registers
#define  CLB1_DATAEXCH_BASE       0x00003180U    // CLB 1 Data Exchange Registers
#define  CLB2_BASE                0x00003200U    //CLB2 Registers
#define  CLB2_LOGICCFG_BASE       0x00003200U    // CLB 2 Logic Config Registers
#define  CLB2_LOGICCTL_BASE       0x00003300U    // CLB 2 Logic Control Registers
#define  CLB2_DATAEXCH_BASE       0x00003380U    // CLB 2 Data Exchange Registers
#define  CLB3_BASE                0x00003400U    //CLB3 Registers
#define  CLB3_LOGICCFG_BASE       0x00003400U    // CLB 3 Logic Config Registers
#define  CLB3_LOGICCTL_BASE       0x00003500U    // CLB 3 Logic Control Registers
#define  CLB3_DATAEXCH_BASE       0x00003580U    // CLB 3 Data Exchange Registers
#define  CLB4_BASE                0x00003600U    //CLB4 Registers
#define  CLB4_LOGICCFG_BASE       0x00003600U    // CLB 4 Logic Config Registers
#define  CLB4_LOGICCTL_BASE       0x00003700U    // CLB 4 Logic Control Registers
#define  CLB4_DATAEXCH_BASE       0x00003780U    // CLB 4 Data Exchange Registers
#define  CLB5_BASE                0x00003000U    //CLB5 Registers
#define  CLB5_LOGICCFG_BASE       0x00003000U    // CLB 5 Logic Config Registers
#define  CLB5_LOGICCTL_BASE       0x00003100U    // CLB 5 Logic Control Registers
#define  CLB5_DATAEXCH_BASE       0x00003180U    // CLB 5 Data Exchange Registers
#define  CLB6_BASE                0x00003200U    //CLB6 Registers
#define  CLB6_LOGICCFG_BASE       0x00003200U    // CLB 6 Logic Config Registers
#define  CLB6_LOGICCTL_BASE       0x00003300U    // CLB 6 Logic Control Registers
#define  CLB6_DATAEXCH_BASE       0x00003380U    // CLB 6 Data Exchange Registers
#define  CLB7_BASE                0x00003400U    //CLB7 Registers
#define  CLB7_LOGICCFG_BASE       0x00003400U    // CLB 7 Logic Config Registers
#define  CLB7_LOGICCTL_BASE       0x00003500U    // CLB 7 Logic Control Registers
#define  CLB7_DATAEXCH_BASE       0x00003580U    // CLB 7 Data Exchange Registers
#define  CLB8_BASE                0x00003600U    //CLB8 Registers
#define  CLB8_LOGICCFG_BASE       0x00003600U    // CLB 8 Logic Config Registers
#define  CLB8_LOGICCTL_BASE       0x00003700U    // CLB 8 Logic Control Registers
#define  CLB8_DATAEXCH_BASE       0x00003780U    // CLB 8 Data Exchange Registers
#define  EPWM1_BASE               0x00004000U    // EPWM1 Registers
#define  EPWM2_BASE               0x00004100U    // EPWM2  Registers
#define  EPWM3_BASE               0x00004200U    // EPWM3  Registers
#define  EPWM4_BASE               0x00004300U    // EPWM4 Registers
#define  EPWM5_BASE               0x00004400U    // EPWM5 Registers
#define  EPWM6_BASE               0x00004500U    // EPWM6 Registers
#define  EPWM7_BASE               0x00004600U    // EPWM7 Registers
#define  EPWM8_BASE               0x00004700U    // EPWM8 Registers
#define  EPWM9_BASE               0x00004800U    // EPWM9 Registers
#define  EPWM10_BASE              0x00004900U    // EPWM10 Registers
#define  EPWM11_BASE              0x00004A00U    // EPWM11 Registers
#define  EPWM12_BASE              0x00004B00U    // EPWM12 Registers
#define  EPWM13_BASE              0x00004C00U    // EPWM13 Registers
#define  EPWM14_BASE              0x00004D00U    // EPWM14 Registers
#define  EPWM15_BASE              0x00004E00U    // EPWM15 Registers
#define  EPWM16_BASE              0x00004F00U    // EPWM16 Registers
#define  EQEP1_BASE               0x00005100U    // EQEP1 Registers
#define  EQEP2_BASE               0x00005140U    // EQEP2 Registers
#define  EQEP3_BASE               0x00005180U    // EQEP3 Registers
#define  ECAP1_BASE               0x00005200U    // ECAP1 Registers
#define  ECAP2_BASE               0x00005240U    // ECAP2 Registers
#define  ECAP3_BASE               0x00005280U    // ECAP3 Registers
#define  ECAP4_BASE               0x000052C0U    // ECAP4 Registers
#define  ECAP5_BASE               0x00005300U    // ECAP5 Registers
#define  ECAP6_BASE               0x00005340U    // ECAP6 Registers
#define  HRCAP6_BASE              0x00005360U    //HRCAP6 Registers
#define  ECAP7_BASE               0x00005380U    // ECAP7 Registers
#define  HRCAP7_BASE              0x000053A0U    //HRCAP7 Registers
#define  DACA_BASE                0x00005C00U    // DACA Registers
#define  DACB_BASE                0x00005C10U    // DACB Registers
#define  DACC_BASE                0x00005C20U    // DACC Registers
#define  CMPSS1_BASE              0x00005C80U    // CMPSS1 Registers
#define  CMPSS2_BASE              0x00005CA0U    // CMPSS2 Registers
#define  CMPSS3_BASE              0x00005CC0U    // CMPSS3 Registers
#define  CMPSS4_BASE              0x00005CE0U    // CMPSS4 Registers
#define  CMPSS5_BASE              0x00005D00U    // CMPSS5 Registers
#define  CMPSS6_BASE              0x00005D20U    // CMPSS6 Registers
#define  CMPSS7_BASE              0x00005D40U    // CMPSS7 Registers
#define  CMPSS8_BASE              0x00005D60U    // CMPSS8 Registers
#define  SDFM1_BASE               0x00005E00U    //SDFM1 Configuration Registers
#define  SDFM2_BASE               0x00005E80U    //SDFM2 Configuration Registers
#define  HWBIST_BASE              0x0005E000U    //CPU BIST Registers
#define  VMT_SPARE_MMR_BASE       0x0005E600U    //Visibility Mode Registers
#define  DCC0_BASE                0x0005E700U    // Dual Clk Comparator-0 Registers
#define  DCC1_BASE                0x0005E740U    // Dual Clk Comparator-1 Registers
#define  DCC2_BASE                0x0005E780U    // Dual Clk Comparator-2 Registers
#define  ERAD_GLOBAL_BASE         0x0005E800U    //ERAD Global Registers
#define  ERAD_HWBP1_BASE          0x0005E900U    //ERAD Hardware Break Point1 Registers
#define  ERAD_HWBP2_BASE          0x0005E908U    //ERAD Hardware Break Point2 Registers
#define  ERAD_HWBP3_BASE          0x0005E910U    //ERAD Hardware Break Point3 Registers
#define  ERAD_HWBP4_BASE          0x0005E918U    //ERAD Hardware Break Point4 Registers
#define  ERAD_HWBP5_BASE          0x0005E920U    //ERAD Hardware Break Point5 Registers
#define  ERAD_HWBP6_BASE          0x0005E928U    //ERAD Hardware Break Point6 Registers
#define  ERAD_HWBP7_BASE          0x0005E930U    //ERAD Hardware Break Point7 Registers
#define  ERAD_HWBP8_BASE          0x0005E938U    //ERAD Hardware Break Point8 Registers
#define  ERAD_COUNTER1_BASE       0x0005E980U    //ERAD Counter1 Registers
#define  ERAD_COUNTER2_BASE       0x0005E990U    //ERAD Counter2 Registers
#define  ERAD_COUNTER3_BASE       0x0005E9A0U    //ERAD Counter3 Registers
#define  ERAD_COUNTER4_BASE       0x0005E9B0U    //ERAD Counter4 Registers
#define  ERAD_CRC_GLOBAL_BASE     0x0005EA00U    //ERAD CRC Global Registers
#define  ERAD_CRC1_BASE           0x0005EA10U    //ERAD CRC1 Registers
#define  ERAD_CRC2_BASE           0x0005EA20U    //ERAD CRC2 Registers
#define  ERAD_CRC3_BASE           0x0005EA30U    //ERAD CRC3 Registers
#define  ERAD_CRC4_BASE           0x0005EA40U    //ERAD CRC4 Registers
#define  ERAD_CRC5_BASE           0x0005EA50U    //ERAD CRC5 Registers
#define  ERAD_CRC6_BASE           0x0005EA60U    //ERAD CRC6 Registers
#define  ERAD_CRC7_BASE           0x0005EA70U    //ERAD CRC7 Registers
#define  ERAD_CRC8_BASE           0x0005EA80U    //ERAD CRC8 Registers
#define  EPWMXBAR_BASE            0x00007A00U    //PWM Crossbar Registers
#define  INPUTXBAR_BASE           0x00007900U    //Input Cross Bar 1 Registers
#define  XBAR_BASE                0x00007920U    //Cross Bar Status Register
#define  DMACLASRCSEL_BASE        0x00007980U    // DMA CLA Triggers Source Select Registers
#define  OUTPUTXBAR_BASE          0x00007A80U    //Output Cross Bar 1 Registers
#define  GPIOCTRL_BASE            0x00007C00U    //GPIO Control Registers
#define  GPIODATA_BASE            0x00007F00U    //GPIO Data Registers
#define  GPIODATAREAD_BASE        0x00007F80U    //GPIO Data Read Registers 
#define  USBA_BASE                0x00040000U    // USB Registers
#define  WD_BASE                  0x00007000U    // Watchdog Registers
#define  NMI_BASE                 0x00007060U    // NMI Registers
#define  XINT_BASE                0x00007070U    //External Interrupt Registers
#define  SCIA_BASE                0x00007200U    // SCI A Registers
#define  SCIB_BASE                0x00007210U    // SCI B Registers
#define  SCIC_BASE                0x00007220U    // SCI C Registers
#define  SCID_BASE                0x00007230U    // SCI D Registers
#define  I2CA_BASE                0x00007300U    // I2C A Registers
#define  I2CB_BASE                0x00007340U    // I2C B Registers
#define  IPC_CPUXTOCM_BASE        0x0005CE40U    //CPU to CM IPC Registers
#define  IPC_CPUXTOCPUX_BASE      0x0005CE00U    //CPU To CPU IPC Registers
#define  FLASH0CTRL_BASE          0x0005F800U    // Flash control registers
#define  FLASH0ECC_BASE           0x0005FB00U    // Flash ECC error log registers
#define  MEMCFG_BASE              0x0005F400U    // RAM Configuration Registers
#define  EMIF1CONFIG_BASE         0x0005F4C0U    // EMIF-1 Configuration Registers
#define  EMIF2CONFIG_BASE         0x0005F4E0U    // EMIF-2 Configuration Registers
#define  ACCESSPROTECTION_BASE    0x0005F500U    //EMIF Access Protection Registers
#define  MEMORYERROR_BASE         0x0005F540U    // Memory error registers
#define  ROMWAITSTATE_BASE        0x0005F580U    // ROM Wait State Control
#define  ROMPREFETCH_BASE         0x0005F588U    // ROM Prefetch Control
#define  TESTERROR_BASE           0x0005F590U    //Test Error Registers
#define  DCSM_Z1_BASE             0x0005F000U    //DCSM Zone1 Registers
#define  DCSM_Z2_BASE             0x0005F080U    //DCSM Zone2 Registers
#define  DCSMCOMMON_BASE          0x0005F0C0U    //DCSM Common Registers
#define  DCSM_Z1OTP_BASE          0x00078000U    //DCSM Common Registers
#define  DCSM_Z2OTP_BASE          0x00078200U    //DCSM Common Registers
#define  EMIF1_BASE               0x00047000U    // EMIF1 Configuration Registers
#define  EMIF2_BASE               0x00047800U    // EMIF2 Configuration Registers
#define  CLKCFG_BASE              0x0005D200U    // Clock Configuration Registers
#define  CPUSYS_BASE              0x0005D300U    // CPU System Configuration Registers
#define  DEVCFG_BASE              0x0005D000U    // Device Configuration Registers
#define  PERIPHAC_BASE            0x0005D500U    // Access protection registers
#define  CMCONF_BASE              0x0005DC00U    // CM configuration Registers
#define  SYSSTAT_BASE             0x0005D400U    // System Status Registers
#define  SYNCSOC_BASE             0x00007940U    //External SYNC and SOC Select Registers
#define  ANALOGSUBSYS_BASE        0x0005D700U    // Analog System Control Registers
#define  M0_RAM_BASE              0x00000000U    //M0 RAM
#define  M1_RAM_BASE              0x00000400U    //M1 RAM
#define  PIEVECTTABLE_BASE        0x00000D00U    //PIE Vector Table
#define  CLATOCPU_RAM_BASE        0x00001480U    //CLA1 to CPU MSG RAM
#define  CPUTOCLA_RAM_BASE        0x00001500U    //CPU to CLA1 MSG RAM
#define  CLATODMA_RAM_BASE        0x00001680U    //CLA1 to DMA MSG RAM
#define  DMATOCLA_RAM_BASE        0x00001700U    //DMA to CLA1 MSG RAM
#define  LS0_RAM_BASE             0x00008000U    //LS0 RAM
#define  LS1_RAM_BASE             0x00008800U    //LS1 RAM
#define  LS2_RAM_BASE             0x00009000U    //LS2 RAM
#define  LS3_RAM_BASE             0x00009800U    //LS3 RAM
#define  LS4_RAM_BASE             0x0000A000U    //LS4 RAM
#define  LS5_RAM_BASE             0x0000A800U    //LS5 RAM
#define  LS6_RAM_BASE             0x0000B000U    //LS6 RAM
#define  LS7_RAM_BASE             0x0000B800U    //LS7 RAM
#define  D0_RAM_BASE              0x0000C000U    //D0 RAM
#define  D1_RAM_BASE              0x0000C800U    //D1 RAM
#define  GS0_RAM_BASE             0x0000D000U    //GS0 RAM
#define  GS1_RAM_BASE             0x0000E000U    //GS1 RAM
#define  GS2_RAM_BASE             0x0000F000U    //GS2 RAM
#define  GS3_RAM_BASE             0x00010000U    //GS3 RAM
#define  GS4_RAM_BASE             0x00011000U    //GS4 RAM
#define  GS5_RAM_BASE             0x00012000U    //GS5 RAM
#define  GS6_RAM_BASE             0x00013000U    //GS6 RAM
#define  GS7_RAM_BASE             0x00014000U    //GS7 RAM
#define  GS8_RAM_BASE             0x00015000U    //GS8 RAM
#define  GS9_RAM_BASE             0x00016000U    //GS9 RAM
#define  GS10_RAM_BASE            0x00017000U    //GS10 RAM
#define  GS11_RAM_BASE            0x00018000U    //GS11 RAM
#define  GS12_RAM_BASE            0x00019000U    //GS12 RAM
#define  GS13_RAM_BASE            0x0001A000U    //GS13 RAM
#define  GS14_RAM_BASE            0x0001B000U    //GS14 RAM
#define  GS15_RAM_BASE            0x0001C000U    //GS15 RAM
#define  CMTOCPUXMSGRAM0_BASE     0x00038000U    //CM to CPU MSGRAM0
#define  CMTOCPUXMSGRAM1_BASE     0x00038400U    //CM to CPU MSGRAM1
#define  CPUXTOCMMSGRAM0_BASE     0x00039000U    //CPU to CM MSGRAM0
#define  CPUXTOCMMSGRAM1_BASE     0x00039400U    //CPU to CM MSGRAM1
#define  CPU1TOCPU2MSGRAM0_BASE   0x0003A000U    //CPU1 to CPU2 MSGRAM0
#define  CPU1TOCPU2MSGRAM1_BASE   0x0003A400U    //CPU1 to CPU2 MSGRAM1
#define  CPU2TOCPU1MSGRAM0_BASE   0x0003B000U    //CPU2 to CPU1 MSGRAM0
#define  CPU2TOCPU1MSGRAM1_BASE   0x0003B400U    //CPU2 to CPU1 MSGRAM1
#define  CLBXBAR_BASE             0x00007A40U    //CLB Crossbar Registers

#if defined(__TMS320C28XX_CLA2__)
#define CLA1_ONLY_BASE            0x00000C00U // CLA Accessible Registers
#endif

#endif // HW_MEMMAP_H

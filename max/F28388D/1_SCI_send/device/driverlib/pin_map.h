//###########################################################################
//
// FILE:   pin_map.h
//
// TITLE:  Definitions of pin mux info for gpio.c.
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

#ifndef __PIN_MAP_H__
#define __PIN_MAP_H__
                                                                               
//*****************************************************************************
// 0x00000003 = MUX register value                                             
// 0x0000000C = GMUX register value                                            
// 0x0000FF00 = Shift amount within mux registers                              
// 0xFFFF0000 = Offset of MUX register                                         
//*****************************************************************************

//*****************************************************************************
// Latest pinmuxing MACROS - Recommended for new users                         
//*****************************************************************************
#define GPIO_0_GPIO0                    0x00060000U
#define GPIO_0_EPWM1A                   0x00060001U
#define GPIO_0_I2CA_SDA                 0x00060006U
#define GPIO_0_CM_I2CA_SDA              0x00060009U
#define GPIO_0_ESC_GPI0                 0x0006000AU
#define GPIO_0_FSITXA_D0                0x0006000DU

#define GPIO_1_GPIO1                    0x00060200U
#define GPIO_1_EPWM1B                   0x00060201U
#define GPIO_1_MFSRB                    0x00060203U
#define GPIO_1_I2CA_SCL                 0x00060206U
#define GPIO_1_CM_I2CA_SCL              0x00060209U
#define GPIO_1_ESC_GPI1                 0x0006020AU
#define GPIO_1_FSITXA_D1                0x0006020DU

#define GPIO_2_GPIO2                    0x00060400U
#define GPIO_2_EPWM2A                   0x00060401U
#define GPIO_2_OUTPUTXBAR1              0x00060405U
#define GPIO_2_I2CB_SDA                 0x00060406U
#define GPIO_2_ESC_GPI2                 0x0006040AU
#define GPIO_2_FSITXA_CLK               0x0006040DU

#define GPIO_3_GPIO3                    0x00060600U
#define GPIO_3_EPWM2B                   0x00060601U
#define GPIO_3_OUTPUTXBAR2              0x00060602U
#define GPIO_3_MCLKRB                   0x00060603U
#define GPIO_3_I2CB_SCL                 0x00060606U
#define GPIO_3_ESC_GPI3                 0x0006060AU
#define GPIO_3_FSIRXA_D0                0x0006060DU

#define GPIO_4_GPIO4                    0x00060800U
#define GPIO_4_EPWM3A                   0x00060801U
#define GPIO_4_OUTPUTXBAR3              0x00060805U
#define GPIO_4_CANA_TX                  0x00060806U
#define GPIO_4_MCAN_TX                  0x00060809U
#define GPIO_4_ESC_GPI4                 0x0006080AU
#define GPIO_4_FSIRXA_D1                0x0006080DU

#define GPIO_5_GPIO5                    0x00060A00U
#define GPIO_5_EPWM3B                   0x00060A01U
#define GPIO_5_MFSRA                    0x00060A02U
#define GPIO_5_OUTPUTXBAR3              0x00060A03U
#define GPIO_5_CANA_RX                  0x00060A06U
#define GPIO_5_MCAN_RX                  0x00060A09U
#define GPIO_5_ESC_GPI5                 0x00060A0AU
#define GPIO_5_FSIRXA_CLK               0x00060A0DU

#define GPIO_6_GPIO6                    0x00060C00U
#define GPIO_6_EPWM4A                   0x00060C01U
#define GPIO_6_OUTPUTXBAR4              0x00060C02U
#define GPIO_6_EXTSYNCOUT               0x00060C03U
#define GPIO_6_EQEP3_A                  0x00060C05U
#define GPIO_6_CANB_TX                  0x00060C06U
#define GPIO_6_ESC_GPI6                 0x00060C0AU
#define GPIO_6_FSITXB_D0                0x00060C0DU

#define GPIO_7_GPIO7                    0x00060E00U
#define GPIO_7_EPWM4B                   0x00060E01U
#define GPIO_7_MCLKRA                   0x00060E02U
#define GPIO_7_OUTPUTXBAR5              0x00060E03U
#define GPIO_7_EQEP3_B                  0x00060E05U
#define GPIO_7_CANB_RX                  0x00060E06U
#define GPIO_7_ESC_GPI7                 0x00060E0AU
#define GPIO_7_FSITXB_D1                0x00060E0DU

#define GPIO_8_GPIO8                    0x00061000U
#define GPIO_8_EPWM5A                   0x00061001U
#define GPIO_8_CANB_TX                  0x00061002U
#define GPIO_8_ADCSOCAO                 0x00061003U
#define GPIO_8_EQEP3_STROBE             0x00061005U
#define GPIO_8_SCIA_TX                  0x00061006U
#define GPIO_8_MCAN_TX                  0x00061009U
#define GPIO_8_ESC_GPO0                 0x0006100AU
#define GPIO_8_FSITXB_CLK               0x0006100DU
#define GPIO_8_FSITXA_D1                0x0006100EU
#define GPIO_8_FSIRXA_D0                0x0006100FU

#define GPIO_9_GPIO9                    0x00061200U
#define GPIO_9_EPWM5B                   0x00061201U
#define GPIO_9_SCIB_TX                  0x00061202U
#define GPIO_9_OUTPUTXBAR6              0x00061203U
#define GPIO_9_EQEP3_INDEX              0x00061205U
#define GPIO_9_SCIA_RX                  0x00061206U
#define GPIO_9_ESC_GPO1                 0x0006120AU
#define GPIO_9_FSIRXB_D0                0x0006120DU
#define GPIO_9_FSITXA_D0                0x0006120EU
#define GPIO_9_FSIRXA_CLK               0x0006120FU

#define GPIO_10_GPIO10                   0x00061400U
#define GPIO_10_EPWM6A                   0x00061401U
#define GPIO_10_CANB_RX                  0x00061402U
#define GPIO_10_ADCSOCBO                 0x00061403U
#define GPIO_10_EQEP1_A                  0x00061405U
#define GPIO_10_SCIB_TX                  0x00061406U
#define GPIO_10_MCAN_RX                  0x00061409U
#define GPIO_10_ESC_GPO2                 0x0006140AU
#define GPIO_10_FSIRXB_D1                0x0006140DU
#define GPIO_10_FSITXA_CLK               0x0006140EU
#define GPIO_10_FSIRXA_D1                0x0006140FU

#define GPIO_11_GPIO11                   0x00061600U
#define GPIO_11_EPWM6B                   0x00061601U
#define GPIO_11_SCIB_RX                  0x00061602U
#define GPIO_11_OUTPUTXBAR7              0x00061603U
#define GPIO_11_EQEP1_B                  0x00061605U
#define GPIO_11_ESC_GPO3                 0x0006160AU
#define GPIO_11_FSIRXB_CLK               0x0006160DU
#define GPIO_11_FSIRXA_D1                0x0006160EU

#define GPIO_12_GPIO12                   0x00061800U
#define GPIO_12_EPWM7A                   0x00061801U
#define GPIO_12_CANB_TX                  0x00061802U
#define GPIO_12_MDXB                     0x00061803U
#define GPIO_12_EQEP1_STROBE             0x00061805U
#define GPIO_12_SCIC_TX                  0x00061806U
#define GPIO_12_ESC_GPO4                 0x0006180AU
#define GPIO_12_FSIRXC_D0                0x0006180DU
#define GPIO_12_FSIRXA_D0                0x0006180EU

#define GPIO_13_GPIO13                   0x00061A00U
#define GPIO_13_EPWM7B                   0x00061A01U
#define GPIO_13_CANB_RX                  0x00061A02U
#define GPIO_13_MDRB                     0x00061A03U
#define GPIO_13_EQEP1_INDEX              0x00061A05U
#define GPIO_13_SCIC_RX                  0x00061A06U
#define GPIO_13_ESC_GPO5                 0x00061A0AU
#define GPIO_13_FSIRXC_D1                0x00061A0DU
#define GPIO_13_FSIRXA_CLK               0x00061A0EU

#define GPIO_14_GPIO14                   0x00061C00U
#define GPIO_14_EPWM8A                   0x00061C01U
#define GPIO_14_SCIB_TX                  0x00061C02U
#define GPIO_14_MCLKXB                   0x00061C03U
#define GPIO_14_OUTPUTXBAR3              0x00061C06U
#define GPIO_14_ESC_GPO6                 0x00061C0AU
#define GPIO_14_FSIRXC_CLK               0x00061C0DU

#define GPIO_15_GPIO15                   0x00061E00U
#define GPIO_15_EPWM8B                   0x00061E01U
#define GPIO_15_SCIB_RX                  0x00061E02U
#define GPIO_15_MFSXB                    0x00061E03U
#define GPIO_15_OUTPUTXBAR4              0x00061E06U
#define GPIO_15_ESC_GPO7                 0x00061E0AU
#define GPIO_15_FSIRXD_D0                0x00061E0DU

#define GPIO_16_GPIO16                   0x00080000U
#define GPIO_16_SPIA_SIMO                0x00080001U
#define GPIO_16_CANB_TX                  0x00080002U
#define GPIO_16_OUTPUTXBAR7              0x00080003U
#define GPIO_16_EPWM9A                   0x00080005U
#define GPIO_16_SD1_D1                   0x00080007U
#define GPIO_16_SSIA_TX                  0x0008000BU
#define GPIO_16_FSIRXD_D1                0x0008000DU

#define GPIO_17_GPIO17                   0x00080200U
#define GPIO_17_SPIA_SOMI                0x00080201U
#define GPIO_17_CANB_RX                  0x00080202U
#define GPIO_17_OUTPUTXBAR8              0x00080203U
#define GPIO_17_EPWM9B                   0x00080205U
#define GPIO_17_SD1_C1                   0x00080207U
#define GPIO_17_SSIA_RX                  0x0008020BU
#define GPIO_17_FSIRXD_CLK               0x0008020DU

#define GPIO_18_GPIO18                   0x00080400U
#define GPIO_18_SPIA_CLK                 0x00080401U
#define GPIO_18_SCIB_TX                  0x00080402U
#define GPIO_18_CANA_RX                  0x00080403U
#define GPIO_18_EPWM10A                  0x00080405U
#define GPIO_18_SD1_D2                   0x00080407U
#define GPIO_18_MCAN_RX                  0x00080409U
#define GPIO_18_EMIF1_CS2N               0x0008040AU
#define GPIO_18_SSIA_CLK                 0x0008040BU
#define GPIO_18_FSIRXE_D0                0x0008040DU

#define GPIO_19_GPIO19                   0x00080600U
#define GPIO_19_SPIA_STEN                0x00080601U
#define GPIO_19_SCIB_RX                  0x00080602U
#define GPIO_19_CANA_TX                  0x00080603U
#define GPIO_19_EPWM10B                  0x00080605U
#define GPIO_19_SD1_C2                   0x00080607U
#define GPIO_19_MCAN_TX                  0x00080609U
#define GPIO_19_EMIF1_CS3N               0x0008060AU
#define GPIO_19_SSIA_FSS                 0x0008060BU
#define GPIO_19_FSIRXE_D1                0x0008060DU

#define GPIO_20_GPIO20                   0x00080800U
#define GPIO_20_EQEP1_A                  0x00080801U
#define GPIO_20_MDXA                     0x00080802U
#define GPIO_20_CANB_TX                  0x00080803U
#define GPIO_20_EPWM11A                  0x00080805U
#define GPIO_20_SD1_D3                   0x00080807U
#define GPIO_20_EMIF1_BA0                0x0008080AU
#define GPIO_20_TRACE_DATA0              0x0008080BU
#define GPIO_20_FSIRXE_CLK               0x0008080DU
#define GPIO_20_SPIC_SIMO                0x0008080EU

#define GPIO_21_GPIO21                   0x00080A00U
#define GPIO_21_EQEP1_B                  0x00080A01U
#define GPIO_21_MDRA                     0x00080A02U
#define GPIO_21_CANB_RX                  0x00080A03U
#define GPIO_21_EPWM11B                  0x00080A05U
#define GPIO_21_SD1_C3                   0x00080A07U
#define GPIO_21_EMIF1_BA1                0x00080A0AU
#define GPIO_21_TRACE_DATA1              0x00080A0BU
#define GPIO_21_FSIRXF_D0                0x00080A0DU
#define GPIO_21_SPIC_SOMI                0x00080A0EU

#define GPIO_22_GPIO22                   0x00080C00U
#define GPIO_22_EQEP1_STROBE             0x00080C01U
#define GPIO_22_MCLKXA                   0x00080C02U
#define GPIO_22_SCIB_TX                  0x00080C03U
#define GPIO_22_EPWM12A                  0x00080C05U
#define GPIO_22_SPIB_CLK                 0x00080C06U
#define GPIO_22_SD1_D4                   0x00080C07U
#define GPIO_22_MCAN_TX                  0x00080C09U
#define GPIO_22_EMIF1_RAS                0x00080C0AU
#define GPIO_22_TRACE_DATA2              0x00080C0BU
#define GPIO_22_FSIRXF_D1                0x00080C0DU
#define GPIO_22_SPIC_CLK                 0x00080C0EU

#define GPIO_23_GPIO23                   0x00080E00U
#define GPIO_23_EQEP1_INDEX              0x00080E01U
#define GPIO_23_MFSXA                    0x00080E02U
#define GPIO_23_SCIB_RX                  0x00080E03U
#define GPIO_23_EPWM12B                  0x00080E05U
#define GPIO_23_SPIB_STEN                0x00080E06U
#define GPIO_23_SD1_C4                   0x00080E07U
#define GPIO_23_MCAN_RX                  0x00080E09U
#define GPIO_23_EMIF1_CAS                0x00080E0AU
#define GPIO_23_TRACE_DATA3              0x00080E0BU
#define GPIO_23_FSIRXF_CLK               0x00080E0DU
#define GPIO_23_SPIC_STEN                0x00080E0EU

#define GPIO_24_GPIO24                   0x00081000U
#define GPIO_24_OUTPUTXBAR1              0x00081001U
#define GPIO_24_EQEP2_A                  0x00081002U
#define GPIO_24_MDXB                     0x00081003U
#define GPIO_24_SPIB_SIMO                0x00081006U
#define GPIO_24_SD2_D1                   0x00081007U
#define GPIO_24_PMBUSA_SCL               0x00081009U
#define GPIO_24_EMIF1_DQM0               0x0008100AU
#define GPIO_24_TRACE_CLK                0x0008100BU
#define GPIO_24_EPWM13A                  0x0008100DU
#define GPIO_24_FSIRXG_D0                0x0008100FU

#define GPIO_25_GPIO25                   0x00081200U
#define GPIO_25_OUTPUTXBAR2              0x00081201U
#define GPIO_25_EQEP2_B                  0x00081202U
#define GPIO_25_MDRB                     0x00081203U
#define GPIO_25_SPIB_SOMI                0x00081206U
#define GPIO_25_SD2_C1                   0x00081207U
#define GPIO_25_PMBUSA_SDA               0x00081209U
#define GPIO_25_EMIF1_DQM1               0x0008120AU
#define GPIO_25_TRACE_SWO                0x0008120BU
#define GPIO_25_EPWM13B                  0x0008120DU
#define GPIO_25_FSITXA_D1                0x0008120EU
#define GPIO_25_FSIRXG_D1                0x0008120FU

#define GPIO_26_GPIO26                   0x00081400U
#define GPIO_26_OUTPUTXBAR3              0x00081401U
#define GPIO_26_EQEP2_INDEX              0x00081402U
#define GPIO_26_MCLKXB                   0x00081403U
#define GPIO_26_SPIB_CLK                 0x00081406U
#define GPIO_26_SD2_D2                   0x00081407U
#define GPIO_26_PMBUSA_ALERT             0x00081409U
#define GPIO_26_EMIF1_DQM2               0x0008140AU
#define GPIO_26_ESC_MDIO_CLK             0x0008140BU
#define GPIO_26_EPWM14A                  0x0008140DU
#define GPIO_26_FSITXA_D0                0x0008140EU
#define GPIO_26_FSIRXG_CLK               0x0008140FU

#define GPIO_27_GPIO27                   0x00081600U
#define GPIO_27_OUTPUTXBAR4              0x00081601U
#define GPIO_27_EQEP2_STROBE             0x00081602U
#define GPIO_27_MFSXB                    0x00081603U
#define GPIO_27_SPIB_STEN                0x00081606U
#define GPIO_27_SD2_C2                   0x00081607U
#define GPIO_27_PMBUSA_CTL               0x00081609U
#define GPIO_27_EMIF1_DQM3               0x0008160AU
#define GPIO_27_ESC_MDIO_DATA            0x0008160BU
#define GPIO_27_EPWM14B                  0x0008160DU
#define GPIO_27_FSITXA_CLK               0x0008160EU
#define GPIO_27_FSIRXH_D0                0x0008160FU

#define GPIO_28_GPIO28                   0x00081800U
#define GPIO_28_SCIA_RX                  0x00081801U
#define GPIO_28_EMIF1_CS4N               0x00081802U
#define GPIO_28_OUTPUTXBAR5              0x00081805U
#define GPIO_28_EQEP3_A                  0x00081806U
#define GPIO_28_SD2_D3                   0x00081807U
#define GPIO_28_EMIF1_CS2N               0x00081809U
#define GPIO_28_EPWM15A                  0x0008180DU
#define GPIO_28_FSIRXH_D1                0x0008180FU

#define GPIO_29_GPIO29                   0x00081A00U
#define GPIO_29_SCIA_TX                  0x00081A01U
#define GPIO_29_EMIF1_SDCKE              0x00081A02U
#define GPIO_29_OUTPUTXBAR6              0x00081A05U
#define GPIO_29_EQEP3_B                  0x00081A06U
#define GPIO_29_SD2_C3                   0x00081A07U
#define GPIO_29_EMIF1_CS3N               0x00081A09U
#define GPIO_29_ESC_LATCH0               0x00081A0AU
#define GPIO_29_ESC_I2C_SDA              0x00081A0BU
#define GPIO_29_EPWM15B                  0x00081A0DU
#define GPIO_29_ESC_SYNC0                0x00081A0EU
#define GPIO_29_FSIRXH_CLK               0x00081A0FU

#define GPIO_30_GPIO30                   0x00081C00U
#define GPIO_30_CANA_RX                  0x00081C01U
#define GPIO_30_EMIF1_CLK                0x00081C02U
#define GPIO_30_MCAN_RX                  0x00081C03U
#define GPIO_30_OUTPUTXBAR7              0x00081C05U
#define GPIO_30_EQEP3_STROBE             0x00081C06U
#define GPIO_30_SD2_D4                   0x00081C07U
#define GPIO_30_EMIF1_CS4N               0x00081C09U
#define GPIO_30_ESC_LATCH1               0x00081C0AU
#define GPIO_30_ESC_I2C_SCL              0x00081C0BU
#define GPIO_30_EPWM16A                  0x00081C0DU
#define GPIO_30_ESC_SYNC1                0x00081C0EU
#define GPIO_30_SPID_SIMO                0x00081C0FU

#define GPIO_31_GPIO31                   0x00081E00U
#define GPIO_31_CANA_TX                  0x00081E01U
#define GPIO_31_EMIF1_WEN                0x00081E02U
#define GPIO_31_MCAN_TX                  0x00081E03U
#define GPIO_31_OUTPUTXBAR8              0x00081E05U
#define GPIO_31_EQEP3_INDEX              0x00081E06U
#define GPIO_31_SD2_C4                   0x00081E07U
#define GPIO_31_EMIF1_RNW                0x00081E09U
#define GPIO_31_I2CA_SDA                 0x00081E0AU
#define GPIO_31_CM_I2CA_SDA              0x00081E0BU
#define GPIO_31_EPWM16B                  0x00081E0DU
#define GPIO_31_SPID_SOMI                0x00081E0FU

#define GPIO_32_GPIO32                   0x00460000U
#define GPIO_32_I2CA_SDA                 0x00460001U
#define GPIO_32_EMIF1_CS0N               0x00460002U
#define GPIO_32_SPIA_SIMO                0x00460003U
#define GPIO_32_CLB_OUTPUTXBAR1          0x00460007U
#define GPIO_32_EMIF1_OEN                0x00460009U
#define GPIO_32_I2CA_SCL                 0x0046000AU
#define GPIO_32_CM_I2CA_SCL              0x0046000BU
#define GPIO_32_SPID_CLK                 0x0046000FU

#define GPIO_33_GPIO33                   0x00460200U
#define GPIO_33_I2CA_SCL                 0x00460201U
#define GPIO_33_EMIF1_RNW                0x00460202U
#define GPIO_33_SPIA_SOMI                0x00460203U
#define GPIO_33_CLB_OUTPUTXBAR2          0x00460207U
#define GPIO_33_EMIF1_BA0                0x00460209U
#define GPIO_33_SPID_STEN                0x0046020FU

#define GPIO_34_GPIO34                   0x00460400U
#define GPIO_34_OUTPUTXBAR1              0x00460401U
#define GPIO_34_EMIF1_CS2N               0x00460402U
#define GPIO_34_SPIA_CLK                 0x00460403U
#define GPIO_34_I2CB_SDA                 0x00460406U
#define GPIO_34_CLB_OUTPUTXBAR3          0x00460407U
#define GPIO_34_EMIF1_BA1                0x00460409U
#define GPIO_34_ESC_LATCH0               0x0046040AU
#define GPIO_34_ENET_MII_CRS             0x0046040BU
#define GPIO_34_SCIA_TX                  0x0046040DU
#define GPIO_34_ESC_SYNC0                0x0046040EU

#define GPIO_35_GPIO35                   0x00460600U
#define GPIO_35_SCIA_RX                  0x00460601U
#define GPIO_35_EMIF1_CS3N               0x00460602U
#define GPIO_35_SPIA_STEN                0x00460603U
#define GPIO_35_I2CB_SCL                 0x00460606U
#define GPIO_35_CLB_OUTPUTXBAR4          0x00460607U
#define GPIO_35_EMIF1_A0                 0x00460609U
#define GPIO_35_ESC_LATCH1               0x0046060AU
#define GPIO_35_ENET_MII_COL             0x0046060BU
#define GPIO_35_ESC_SYNC1                0x0046060EU

#define GPIO_36_GPIO36                   0x00460800U
#define GPIO_36_SCIA_TX                  0x00460801U
#define GPIO_36_EMIF1_WAIT               0x00460802U
#define GPIO_36_CANA_RX                  0x00460806U
#define GPIO_36_CLB_OUTPUTXBAR5          0x00460807U
#define GPIO_36_EMIF1_A1                 0x00460809U
#define GPIO_36_MCAN_RX                  0x0046080AU
#define GPIO_36_SD1_D1                   0x0046080DU

#define GPIO_37_GPIO37                   0x00460A00U
#define GPIO_37_OUTPUTXBAR2              0x00460A01U
#define GPIO_37_EMIF1_OEN                0x00460A02U
#define GPIO_37_CANA_TX                  0x00460A06U
#define GPIO_37_CLB_OUTPUTXBAR6          0x00460A07U
#define GPIO_37_EMIF1_A2                 0x00460A09U
#define GPIO_37_MCAN_TX                  0x00460A0AU
#define GPIO_37_SD1_D2                   0x00460A0DU

#define GPIO_38_GPIO38                   0x00460C00U
#define GPIO_38_EMIF1_A0                 0x00460C02U
#define GPIO_38_SCIC_TX                  0x00460C05U
#define GPIO_38_CANB_TX                  0x00460C06U
#define GPIO_38_CLB_OUTPUTXBAR7          0x00460C07U
#define GPIO_38_EMIF1_A3                 0x00460C09U
#define GPIO_38_ENET_MII_RX_DV           0x00460C0AU
#define GPIO_38_ENET_MII_CRS             0x00460C0BU
#define GPIO_38_SD1_D3                   0x00460C0DU

#define GPIO_39_GPIO39                   0x00460E00U
#define GPIO_39_EMIF1_A1                 0x00460E02U
#define GPIO_39_SCIC_RX                  0x00460E05U
#define GPIO_39_CANB_RX                  0x00460E06U
#define GPIO_39_CLB_OUTPUTXBAR8          0x00460E07U
#define GPIO_39_EMIF1_A4                 0x00460E09U
#define GPIO_39_ENET_MII_RX_ERR          0x00460E0AU
#define GPIO_39_ENET_MII_COL             0x00460E0BU
#define GPIO_39_SD1_D4                   0x00460E0DU

#define GPIO_40_GPIO40                   0x00461000U
#define GPIO_40_EMIF1_A2                 0x00461002U
#define GPIO_40_I2CB_SDA                 0x00461006U
#define GPIO_40_ENET_MII_CRS             0x0046100BU
#define GPIO_40_ESC_I2C_SDA              0x0046100EU

#define GPIO_41_GPIO41                   0x00461200U
#define GPIO_41_EMIF1_A3                 0x00461202U
#define GPIO_41_I2CB_SCL                 0x00461206U
#define GPIO_41_ENET_REVMII_MDIO_RST     0x0046120AU
#define GPIO_41_ENET_MII_COL             0x0046120BU
#define GPIO_41_ESC_I2C_SCL              0x0046120EU

#define GPIO_42_GPIO42                   0x00461400U
#define GPIO_42_I2CA_SDA                 0x00461406U
#define GPIO_42_ENET_MDIO_CLK            0x0046140AU
#define GPIO_42_UARTA_TX                 0x0046140BU
#define GPIO_42_SCIA_TX                  0x0046140FU

#define GPIO_43_GPIO43                   0x00461600U
#define GPIO_43_I2CA_SCL                 0x00461606U
#define GPIO_43_ENET_MDIO_DATA           0x0046160AU
#define GPIO_43_UARTA_RX                 0x0046160BU
#define GPIO_43_SCIA_RX                  0x0046160FU

#define GPIO_44_GPIO44                   0x00461800U
#define GPIO_44_EMIF1_A4                 0x00461802U
#define GPIO_44_ENET_MII_TX_CLK          0x0046180BU
#define GPIO_44_ESC_TX1_CLK              0x0046180EU

#define GPIO_45_GPIO45                   0x00461A00U
#define GPIO_45_EMIF1_A5                 0x00461A02U
#define GPIO_45_ENET_MII_TX_EN           0x00461A0BU
#define GPIO_45_ESC_TX1_ENA              0x00461A0EU

#define GPIO_46_GPIO46                   0x00461C00U
#define GPIO_46_EMIF1_A6                 0x00461C02U
#define GPIO_46_SCID_RX                  0x00461C06U
#define GPIO_46_ENET_MII_TX_ERR          0x00461C0BU
#define GPIO_46_ESC_MDIO_CLK             0x00461C0EU

#define GPIO_47_GPIO47                   0x00461E00U
#define GPIO_47_EMIF1_A7                 0x00461E02U
#define GPIO_47_SCID_TX                  0x00461E06U
#define GPIO_47_ENET_PPS0                0x00461E0BU
#define GPIO_47_ESC_MDIO_DATA            0x00461E0EU

#define GPIO_48_GPIO48                   0x00480000U
#define GPIO_48_OUTPUTXBAR3              0x00480001U
#define GPIO_48_EMIF1_A8                 0x00480002U
#define GPIO_48_SCIA_TX                  0x00480006U
#define GPIO_48_SD1_D1                   0x00480007U
#define GPIO_48_ENET_PPS1                0x0048000BU
#define GPIO_48_ESC_PHY_CLK              0x0048000EU

#define GPIO_49_GPIO49                   0x00480200U
#define GPIO_49_OUTPUTXBAR4              0x00480201U
#define GPIO_49_EMIF1_A9                 0x00480202U
#define GPIO_49_SCIA_RX                  0x00480206U
#define GPIO_49_SD1_C1                   0x00480207U
#define GPIO_49_EMIF1_A5                 0x00480209U
#define GPIO_49_ENET_MII_RX_CLK          0x0048020BU
#define GPIO_49_SD2_D1                   0x0048020DU
#define GPIO_49_FSITXA_D0                0x0048020EU

#define GPIO_50_GPIO50                   0x00480400U
#define GPIO_50_EQEP1_A                  0x00480401U
#define GPIO_50_EMIF1_A10                0x00480402U
#define GPIO_50_SPIC_SIMO                0x00480406U
#define GPIO_50_SD1_D2                   0x00480407U
#define GPIO_50_EMIF1_A6                 0x00480409U
#define GPIO_50_ENET_MII_RX_DV           0x0048040BU
#define GPIO_50_SD2_D2                   0x0048040DU
#define GPIO_50_FSITXA_D1                0x0048040EU

#define GPIO_51_GPIO51                   0x00480600U
#define GPIO_51_EQEP1_B                  0x00480601U
#define GPIO_51_EMIF1_A11                0x00480602U
#define GPIO_51_SPIC_SOMI                0x00480606U
#define GPIO_51_SD1_C2                   0x00480607U
#define GPIO_51_EMIF1_A7                 0x00480609U
#define GPIO_51_ENET_MII_RX_ERR          0x0048060BU
#define GPIO_51_SD2_D3                   0x0048060DU
#define GPIO_51_FSITXA_CLK               0x0048060EU

#define GPIO_52_GPIO52                   0x00480800U
#define GPIO_52_EQEP1_STROBE             0x00480801U
#define GPIO_52_EMIF1_A12                0x00480802U
#define GPIO_52_SPIC_CLK                 0x00480806U
#define GPIO_52_SD1_D3                   0x00480807U
#define GPIO_52_EMIF1_A8                 0x00480809U
#define GPIO_52_ENET_MII_RX_DATA0        0x0048080BU
#define GPIO_52_SD2_D4                   0x0048080DU
#define GPIO_52_FSIRXA_D0                0x0048080EU

#define GPIO_53_GPIO53                   0x00480A00U
#define GPIO_53_EQEP1_INDEX              0x00480A01U
#define GPIO_53_EMIF1_D31                0x00480A02U
#define GPIO_53_EMIF2_D15                0x00480A03U
#define GPIO_53_SPIC_STEN                0x00480A06U
#define GPIO_53_SD1_C3                   0x00480A07U
#define GPIO_53_EMIF1_A9                 0x00480A09U
#define GPIO_53_ENET_MII_RX_DATA1        0x00480A0BU
#define GPIO_53_SD1_C1                   0x00480A0DU
#define GPIO_53_FSIRXA_D1                0x00480A0EU

#define GPIO_54_GPIO54                   0x00480C00U
#define GPIO_54_SPIA_SIMO                0x00480C01U
#define GPIO_54_EMIF1_D30                0x00480C02U
#define GPIO_54_EMIF2_D14                0x00480C03U
#define GPIO_54_EQEP2_A                  0x00480C05U
#define GPIO_54_SCIB_TX                  0x00480C06U
#define GPIO_54_SD1_D4                   0x00480C07U
#define GPIO_54_EMIF1_A10                0x00480C09U
#define GPIO_54_ENET_MII_RX_DATA2        0x00480C0BU
#define GPIO_54_SD1_C2                   0x00480C0DU
#define GPIO_54_FSIRXA_CLK               0x00480C0EU
#define GPIO_54_SSIA_TX                  0x00480C0FU

#define GPIO_55_GPIO55                   0x00480E00U
#define GPIO_55_SPIA_SOMI                0x00480E01U
#define GPIO_55_EMIF1_D29                0x00480E02U
#define GPIO_55_EMIF2_D13                0x00480E03U
#define GPIO_55_EQEP2_B                  0x00480E05U
#define GPIO_55_SCIB_RX                  0x00480E06U
#define GPIO_55_SD1_C4                   0x00480E07U
#define GPIO_55_EMIF1_D0                 0x00480E09U
#define GPIO_55_ENET_MII_RX_DATA3        0x00480E0BU
#define GPIO_55_SD1_C3                   0x00480E0DU
#define GPIO_55_FSITXB_D0                0x00480E0EU
#define GPIO_55_SSIA_RX                  0x00480E0FU

#define GPIO_56_GPIO56                   0x00481000U
#define GPIO_56_SPIA_CLK                 0x00481001U
#define GPIO_56_EMIF1_D28                0x00481002U
#define GPIO_56_EMIF2_D12                0x00481003U
#define GPIO_56_EQEP2_STROBE             0x00481005U
#define GPIO_56_SCIC_TX                  0x00481006U
#define GPIO_56_SD2_D1                   0x00481007U
#define GPIO_56_EMIF1_D1                 0x00481009U
#define GPIO_56_I2CA_SDA                 0x0048100AU
#define GPIO_56_ENET_MII_TX_EN           0x0048100BU
#define GPIO_56_SD1_C4                   0x0048100DU
#define GPIO_56_FSITXB_CLK               0x0048100EU
#define GPIO_56_SSIA_CLK                 0x0048100FU

#define GPIO_57_GPIO57                   0x00481200U
#define GPIO_57_SPIA_STEN                0x00481201U
#define GPIO_57_EMIF1_D27                0x00481202U
#define GPIO_57_EMIF2_D11                0x00481203U
#define GPIO_57_EQEP2_INDEX              0x00481205U
#define GPIO_57_SCIC_RX                  0x00481206U
#define GPIO_57_SD2_C1                   0x00481207U
#define GPIO_57_EMIF1_D2                 0x00481209U
#define GPIO_57_I2CA_SCL                 0x0048120AU
#define GPIO_57_ENET_MII_TX_ERR          0x0048120BU
#define GPIO_57_FSITXB_D1                0x0048120EU
#define GPIO_57_SSIA_FSS                 0x0048120FU

#define GPIO_58_GPIO58                   0x00481400U
#define GPIO_58_MCLKRA                   0x00481401U
#define GPIO_58_EMIF1_D26                0x00481402U
#define GPIO_58_EMIF2_D10                0x00481403U
#define GPIO_58_OUTPUTXBAR1              0x00481405U
#define GPIO_58_SPIB_CLK                 0x00481406U
#define GPIO_58_SD2_D2                   0x00481407U
#define GPIO_58_EMIF1_D3                 0x00481409U
#define GPIO_58_ESC_LED_LINK0_ACTIVE     0x0048140AU
#define GPIO_58_ENET_MII_TX_CLK          0x0048140BU
#define GPIO_58_SD2_C2                   0x0048140DU
#define GPIO_58_FSIRXB_D0                0x0048140EU
#define GPIO_58_SPIA_SIMO                0x0048140FU

#define GPIO_59_GPIO59                   0x00481600U
#define GPIO_59_MFSRA                    0x00481601U
#define GPIO_59_EMIF1_D25                0x00481602U
#define GPIO_59_EMIF2_D9                 0x00481603U
#define GPIO_59_OUTPUTXBAR2              0x00481605U
#define GPIO_59_SPIB_STEN                0x00481606U
#define GPIO_59_SD2_C2                   0x00481607U
#define GPIO_59_EMIF1_D4                 0x00481609U
#define GPIO_59_ESC_LED_LINK1_ACTIVE     0x0048160AU
#define GPIO_59_ENET_MII_TX_DATA0        0x0048160BU
#define GPIO_59_SD2_C3                   0x0048160DU
#define GPIO_59_FSIRXB_D1                0x0048160EU
#define GPIO_59_SPIA_SOMI                0x0048160FU

#define GPIO_60_GPIO60                   0x00481800U
#define GPIO_60_MCLKRB                   0x00481801U
#define GPIO_60_EMIF1_D24                0x00481802U
#define GPIO_60_EMIF2_D8                 0x00481803U
#define GPIO_60_OUTPUTXBAR3              0x00481805U
#define GPIO_60_SPIB_SIMO                0x00481806U
#define GPIO_60_SD2_D3                   0x00481807U
#define GPIO_60_EMIF1_D5                 0x00481809U
#define GPIO_60_ESC_LED_ERR              0x0048180AU
#define GPIO_60_ENET_MII_TX_DATA1        0x0048180BU
#define GPIO_60_SD2_C4                   0x0048180DU
#define GPIO_60_FSIRXB_CLK               0x0048180EU
#define GPIO_60_SPIA_CLK                 0x0048180FU

#define GPIO_61_GPIO61                   0x00481A00U
#define GPIO_61_MFSRB                    0x00481A01U
#define GPIO_61_EMIF1_D23                0x00481A02U
#define GPIO_61_EMIF2_D7                 0x00481A03U
#define GPIO_61_OUTPUTXBAR4              0x00481A05U
#define GPIO_61_SPIB_SOMI                0x00481A06U
#define GPIO_61_SD2_C3                   0x00481A07U
#define GPIO_61_EMIF1_D6                 0x00481A09U
#define GPIO_61_ESC_LED_RUN              0x00481A0AU
#define GPIO_61_ENET_MII_TX_DATA2        0x00481A0BU
#define GPIO_61_CANA_RX                  0x00481A0EU
#define GPIO_61_SPIA_STEN                0x00481A0FU

#define GPIO_62_GPIO62                   0x00481C00U
#define GPIO_62_SCIC_RX                  0x00481C01U
#define GPIO_62_EMIF1_D22                0x00481C02U
#define GPIO_62_EMIF2_D6                 0x00481C03U
#define GPIO_62_EQEP3_A                  0x00481C05U
#define GPIO_62_CANA_RX                  0x00481C06U
#define GPIO_62_SD2_D4                   0x00481C07U
#define GPIO_62_EMIF1_D7                 0x00481C09U
#define GPIO_62_ESC_LED_STATE_RUN        0x00481C0AU
#define GPIO_62_ENET_MII_TX_DATA3        0x00481C0BU
#define GPIO_62_CANA_TX                  0x00481C0EU

#define GPIO_63_GPIO63                   0x00481E00U
#define GPIO_63_SCIC_TX                  0x00481E01U
#define GPIO_63_EMIF1_D21                0x00481E02U
#define GPIO_63_EMIF2_D5                 0x00481E03U
#define GPIO_63_EQEP3_B                  0x00481E05U
#define GPIO_63_CANA_TX                  0x00481E06U
#define GPIO_63_SD2_C4                   0x00481E07U
#define GPIO_63_SSIA_TX                  0x00481E09U
#define GPIO_63_ENET_MII_RX_DATA0        0x00481E0BU
#define GPIO_63_SD1_D1                   0x00481E0DU
#define GPIO_63_ESC_RX1_DATA0            0x00481E0EU
#define GPIO_63_SPIB_SIMO                0x00481E0FU

#define GPIO_64_GPIO64                   0x00860000U
#define GPIO_64_EMIF1_D20                0x00860002U
#define GPIO_64_EMIF2_D4                 0x00860003U
#define GPIO_64_EQEP3_STROBE             0x00860005U
#define GPIO_64_SCIA_RX                  0x00860006U
#define GPIO_64_SSIA_RX                  0x00860009U
#define GPIO_64_ENET_MII_RX_DV           0x0086000AU
#define GPIO_64_ENET_MII_RX_DATA1        0x0086000BU
#define GPIO_64_SD1_C1                   0x0086000DU
#define GPIO_64_ESC_RX1_DATA1            0x0086000EU
#define GPIO_64_SPIB_SOMI                0x0086000FU

#define GPIO_65_GPIO65                   0x00860200U
#define GPIO_65_EMIF1_D19                0x00860202U
#define GPIO_65_EMIF2_D3                 0x00860203U
#define GPIO_65_EQEP3_INDEX              0x00860205U
#define GPIO_65_SCIA_TX                  0x00860206U
#define GPIO_65_SSIA_CLK                 0x00860209U
#define GPIO_65_ENET_MII_RX_ERR          0x0086020AU
#define GPIO_65_ENET_MII_RX_DATA2        0x0086020BU
#define GPIO_65_SD1_D2                   0x0086020DU
#define GPIO_65_ESC_RX1_DATA2            0x0086020EU
#define GPIO_65_SPIB_CLK                 0x0086020FU

#define GPIO_66_GPIO66                   0x00860400U
#define GPIO_66_EMIF1_D18                0x00860402U
#define GPIO_66_EMIF2_D2                 0x00860403U
#define GPIO_66_I2CB_SDA                 0x00860406U
#define GPIO_66_SSIA_FSS                 0x00860409U
#define GPIO_66_ENET_MII_RX_DATA0        0x0086040AU
#define GPIO_66_ENET_MII_RX_DATA3        0x0086040BU
#define GPIO_66_SD1_C2                   0x0086040DU
#define GPIO_66_ESC_RX1_DATA3            0x0086040EU
#define GPIO_66_SPIB_STEN                0x0086040FU

#define GPIO_67_GPIO67                   0x00860600U
#define GPIO_67_EMIF1_D17                0x00860602U
#define GPIO_67_EMIF2_D1                 0x00860603U
#define GPIO_67_ENET_MII_RX_CLK          0x0086060AU
#define GPIO_67_ENET_REVMII_MDIO_RST     0x0086060BU
#define GPIO_67_SD1_D3                   0x0086060DU

#define GPIO_68_GPIO68                   0x00860800U
#define GPIO_68_EMIF1_D16                0x00860802U
#define GPIO_68_EMIF2_D0                 0x00860803U
#define GPIO_68_ENET_MII_INTR            0x0086080BU
#define GPIO_68_SD1_C3                   0x0086080DU
#define GPIO_68_ESC_PHY1_LINKSTATUS      0x0086080EU

#define GPIO_69_GPIO69                   0x00860A00U
#define GPIO_69_EMIF1_D15                0x00860A02U
#define GPIO_69_I2CB_SCL                 0x00860A06U
#define GPIO_69_ENET_MII_TX_EN           0x00860A0AU
#define GPIO_69_ENET_MII_RX_CLK          0x00860A0BU
#define GPIO_69_SD1_D4                   0x00860A0DU
#define GPIO_69_ESC_RX1_CLK              0x00860A0EU
#define GPIO_69_SPIC_SIMO                0x00860A0FU

#define GPIO_70_GPIO70                   0x00860C00U
#define GPIO_70_EMIF1_D14                0x00860C02U
#define GPIO_70_CANA_RX                  0x00860C05U
#define GPIO_70_SCIB_TX                  0x00860C06U
#define GPIO_70_MCAN_RX                  0x00860C09U
#define GPIO_70_ENET_MII_RX_DV           0x00860C0BU
#define GPIO_70_SD1_C4                   0x00860C0DU
#define GPIO_70_ESC_RX1_DV               0x00860C0EU
#define GPIO_70_SPIC_SOMI                0x00860C0FU

#define GPIO_71_GPIO71                   0x00860E00U
#define GPIO_71_EMIF1_D13                0x00860E02U
#define GPIO_71_CANA_TX                  0x00860E05U
#define GPIO_71_SCIB_RX                  0x00860E06U
#define GPIO_71_MCAN_TX                  0x00860E09U
#define GPIO_71_ENET_MII_RX_DATA0        0x00860E0AU
#define GPIO_71_ENET_MII_RX_ERR          0x00860E0BU
#define GPIO_71_ESC_RX1_ERR              0x00860E0EU
#define GPIO_71_SPIC_CLK                 0x00860E0FU

#define GPIO_72_GPIO72                   0x00861000U
#define GPIO_72_EMIF1_D12                0x00861002U
#define GPIO_72_CANB_TX                  0x00861005U
#define GPIO_72_SCIC_TX                  0x00861006U
#define GPIO_72_ENET_MII_RX_DATA1        0x0086100AU
#define GPIO_72_ENET_MII_TX_DATA3        0x0086100BU
#define GPIO_72_ESC_TX1_DATA3            0x0086100EU
#define GPIO_72_SPIC_STEN                0x0086100FU

#define GPIO_73_GPIO73                   0x00861200U
#define GPIO_73_EMIF1_D11                0x00861202U
#define GPIO_73_XCLKOUT                  0x00861203U
#define GPIO_73_CANB_RX                  0x00861205U
#define GPIO_73_SCIC_RX                  0x00861206U
#define GPIO_73_ENET_RMII_CLK            0x0086120AU
#define GPIO_73_ENET_MII_TX_DATA2        0x0086120BU
#define GPIO_73_SD2_D2                   0x0086120DU
#define GPIO_73_ESC_TX1_DATA2            0x0086120EU

#define GPIO_74_GPIO74                   0x00861400U
#define GPIO_74_EMIF1_D10                0x00861402U
#define GPIO_74_MCAN_TX                  0x00861409U
#define GPIO_74_ENET_MII_TX_DATA1        0x0086140BU
#define GPIO_74_SD2_C2                   0x0086140DU
#define GPIO_74_ESC_TX1_DATA1            0x0086140EU

#define GPIO_75_GPIO75                   0x00861600U
#define GPIO_75_EMIF1_D9                 0x00861602U
#define GPIO_75_MCAN_RX                  0x00861609U
#define GPIO_75_ENET_MII_TX_DATA0        0x0086160BU
#define GPIO_75_SD2_D3                   0x0086160DU
#define GPIO_75_ESC_TX1_DATA0            0x0086160EU

#define GPIO_76_GPIO76                   0x00861800U
#define GPIO_76_EMIF1_D8                 0x00861802U
#define GPIO_76_SCID_TX                  0x00861806U
#define GPIO_76_ENET_MII_RX_ERR          0x0086180AU
#define GPIO_76_SD2_C3                   0x0086180DU
#define GPIO_76_ESC_PHY_RESETN           0x0086180EU

#define GPIO_77_GPIO77                   0x00861A00U
#define GPIO_77_EMIF1_D7                 0x00861A02U
#define GPIO_77_SCID_RX                  0x00861A06U
#define GPIO_77_SD2_D4                   0x00861A0DU
#define GPIO_77_ESC_RX0_CLK              0x00861A0EU

#define GPIO_78_GPIO78                   0x00861C00U
#define GPIO_78_EMIF1_D6                 0x00861C02U
#define GPIO_78_EQEP2_A                  0x00861C06U
#define GPIO_78_SD2_C4                   0x00861C0DU
#define GPIO_78_ESC_RX0_DV               0x00861C0EU

#define GPIO_79_GPIO79                   0x00861E00U
#define GPIO_79_EMIF1_D5                 0x00861E02U
#define GPIO_79_EQEP2_B                  0x00861E06U
#define GPIO_79_SD2_D1                   0x00861E0DU
#define GPIO_79_ESC_RX0_ERR              0x00861E0EU

#define GPIO_80_GPIO80                   0x00880000U
#define GPIO_80_EMIF1_D4                 0x00880002U
#define GPIO_80_EQEP2_STROBE             0x00880006U
#define GPIO_80_SD2_C1                   0x0088000DU
#define GPIO_80_ESC_RX0_DATA0            0x0088000EU

#define GPIO_81_GPIO81                   0x00880200U
#define GPIO_81_EMIF1_D3                 0x00880202U
#define GPIO_81_EQEP2_INDEX              0x00880206U
#define GPIO_81_ESC_RX0_DATA1            0x0088020EU

#define GPIO_82_GPIO82                   0x00880400U
#define GPIO_82_EMIF1_D2                 0x00880402U
#define GPIO_82_ESC_RX0_DATA2            0x0088040EU

#define GPIO_83_GPIO83                   0x00880600U
#define GPIO_83_EMIF1_D1                 0x00880602U
#define GPIO_83_ESC_RX0_DATA3            0x0088060EU

#define GPIO_84_GPIO84                   0x00880800U
#define GPIO_84_SCIA_TX                  0x00880805U
#define GPIO_84_MDXB                     0x00880806U
#define GPIO_84_UARTA_TX                 0x0088080BU
#define GPIO_84_ESC_TX0_ENA              0x0088080EU
#define GPIO_84_MDXA                     0x0088080FU

#define GPIO_85_GPIO85                   0x00880A00U
#define GPIO_85_EMIF1_D0                 0x00880A02U
#define GPIO_85_SCIA_RX                  0x00880A05U
#define GPIO_85_MDRB                     0x00880A06U
#define GPIO_85_UARTA_RX                 0x00880A0BU
#define GPIO_85_ESC_TX0_CLK              0x00880A0EU
#define GPIO_85_MDRA                     0x00880A0FU

#define GPIO_86_GPIO86                   0x00880C00U
#define GPIO_86_EMIF1_A13                0x00880C02U
#define GPIO_86_EMIF1_CAS                0x00880C03U
#define GPIO_86_SCIB_TX                  0x00880C05U
#define GPIO_86_MCLKXB                   0x00880C06U
#define GPIO_86_ESC_PHY0_LINKSTATUS      0x00880C0EU
#define GPIO_86_MCLKXA                   0x00880C0FU

#define GPIO_87_GPIO87                   0x00880E00U
#define GPIO_87_EMIF1_A14                0x00880E02U
#define GPIO_87_EMIF1_RAS                0x00880E03U
#define GPIO_87_SCIB_RX                  0x00880E05U
#define GPIO_87_MFSXB                    0x00880E06U
#define GPIO_87_EMIF1_DQM3               0x00880E09U
#define GPIO_87_ESC_TX0_DATA0            0x00880E0EU
#define GPIO_87_MFSXA                    0x00880E0FU

#define GPIO_88_GPIO88                   0x00881000U
#define GPIO_88_EMIF1_A15                0x00881002U
#define GPIO_88_EMIF1_DQM0               0x00881003U
#define GPIO_88_EMIF1_DQM1               0x00881009U
#define GPIO_88_ESC_TX0_DATA1            0x0088100EU

#define GPIO_89_GPIO89                   0x00881200U
#define GPIO_89_EMIF1_A16                0x00881202U
#define GPIO_89_EMIF1_DQM1               0x00881203U
#define GPIO_89_SCIC_TX                  0x00881206U
#define GPIO_89_EMIF1_CAS                0x00881209U
#define GPIO_89_ESC_TX0_DATA2            0x0088120EU

#define GPIO_90_GPIO90                   0x00881400U
#define GPIO_90_EMIF1_A17                0x00881402U
#define GPIO_90_EMIF1_DQM2               0x00881403U
#define GPIO_90_SCIC_RX                  0x00881406U
#define GPIO_90_EMIF1_RAS                0x00881409U
#define GPIO_90_ESC_TX0_DATA3            0x0088140EU

#define GPIO_91_GPIO91                   0x00881600U
#define GPIO_91_EMIF1_A18                0x00881602U
#define GPIO_91_EMIF1_DQM3               0x00881603U
#define GPIO_91_I2CA_SDA                 0x00881606U
#define GPIO_91_EMIF1_DQM2               0x00881609U
#define GPIO_91_PMBUSA_SCL               0x0088160AU
#define GPIO_91_SSIA_TX                  0x0088160BU
#define GPIO_91_FSIRXF_D0                0x0088160DU
#define GPIO_91_CLB_OUTPUTXBAR1          0x0088160EU
#define GPIO_91_SPID_SIMO                0x0088160FU

#define GPIO_92_GPIO92                   0x00881800U
#define GPIO_92_EMIF1_A19                0x00881802U
#define GPIO_92_EMIF1_BA1                0x00881803U
#define GPIO_92_I2CA_SCL                 0x00881806U
#define GPIO_92_EMIF1_DQM0               0x00881809U
#define GPIO_92_PMBUSA_SDA               0x0088180AU
#define GPIO_92_SSIA_RX                  0x0088180BU
#define GPIO_92_FSIRXF_D1                0x0088180DU
#define GPIO_92_CLB_OUTPUTXBAR2          0x0088180EU
#define GPIO_92_SPID_SOMI                0x0088180FU

#define GPIO_93_GPIO93                   0x00881A00U
#define GPIO_93_EMIF1_BA0                0x00881A03U
#define GPIO_93_SCID_TX                  0x00881A06U
#define GPIO_93_PMBUSA_ALERT             0x00881A0AU
#define GPIO_93_SSIA_CLK                 0x00881A0BU
#define GPIO_93_FSIRXF_CLK               0x00881A0DU
#define GPIO_93_CLB_OUTPUTXBAR3          0x00881A0EU
#define GPIO_93_SPID_CLK                 0x00881A0FU

#define GPIO_94_GPIO94                   0x00881C00U
#define GPIO_94_SCID_RX                  0x00881C06U
#define GPIO_94_EMIF1_BA1                0x00881C09U
#define GPIO_94_PMBUSA_CTL               0x00881C0AU
#define GPIO_94_SSIA_FSS                 0x00881C0BU
#define GPIO_94_FSIRXG_D0                0x00881C0DU
#define GPIO_94_CLB_OUTPUTXBAR4          0x00881C0EU
#define GPIO_94_SPID_STEN                0x00881C0FU

#define GPIO_95_GPIO95                   0x00881E00U
#define GPIO_95_EMIF2_A12                0x00881E03U
#define GPIO_95_FSIRXG_D1                0x00881E0DU
#define GPIO_95_CLB_OUTPUTXBAR5          0x00881E0EU

#define GPIO_96_GPIO96                   0x00C60000U
#define GPIO_96_EMIF2_DQM1               0x00C60003U
#define GPIO_96_EQEP1_A                  0x00C60005U
#define GPIO_96_FSIRXG_CLK               0x00C6000DU
#define GPIO_96_CLB_OUTPUTXBAR6          0x00C6000EU

#define GPIO_97_GPIO97                   0x00C60200U
#define GPIO_97_EMIF2_DQM0               0x00C60203U
#define GPIO_97_EQEP1_B                  0x00C60205U
#define GPIO_97_FSIRXH_D0                0x00C6020DU
#define GPIO_97_CLB_OUTPUTXBAR7          0x00C6020EU

#define GPIO_98_GPIO98                   0x00C60400U
#define GPIO_98_EMIF2_A0                 0x00C60403U
#define GPIO_98_EQEP1_STROBE             0x00C60405U
#define GPIO_98_FSIRXH_D1                0x00C6040DU
#define GPIO_98_CLB_OUTPUTXBAR8          0x00C6040EU

#define GPIO_99_GPIO99                   0x00C60600U
#define GPIO_99_EMIF2_A1                 0x00C60603U
#define GPIO_99_EQEP1_INDEX              0x00C60605U
#define GPIO_99_FSIRXH_CLK               0x00C6060DU

#define GPIO_100_GPIO100                  0x00C60800U
#define GPIO_100_EMIF2_A2                 0x00C60803U
#define GPIO_100_EQEP2_A                  0x00C60805U
#define GPIO_100_SPIC_SIMO                0x00C60806U
#define GPIO_100_ESC_GPI0                 0x00C6080AU
#define GPIO_100_FSITXA_D0                0x00C6080DU

#define GPIO_101_GPIO101                  0x00C60A00U
#define GPIO_101_EMIF2_A3                 0x00C60A03U
#define GPIO_101_EQEP2_B                  0x00C60A05U
#define GPIO_101_SPIC_SOMI                0x00C60A06U
#define GPIO_101_ESC_GPI1                 0x00C60A0AU
#define GPIO_101_FSITXA_D1                0x00C60A0DU

#define GPIO_102_GPIO102                  0x00C60C00U
#define GPIO_102_EMIF2_A4                 0x00C60C03U
#define GPIO_102_EQEP2_STROBE             0x00C60C05U
#define GPIO_102_SPIC_CLK                 0x00C60C06U
#define GPIO_102_ESC_GPI2                 0x00C60C0AU
#define GPIO_102_FSITXA_CLK               0x00C60C0DU

#define GPIO_103_GPIO103                  0x00C60E00U
#define GPIO_103_EMIF2_A5                 0x00C60E03U
#define GPIO_103_EQEP2_INDEX              0x00C60E05U
#define GPIO_103_SPIC_STEN                0x00C60E06U
#define GPIO_103_ESC_GPI3                 0x00C60E0AU
#define GPIO_103_FSIRXA_D0                0x00C60E0DU

#define GPIO_104_GPIO104                  0x00C61000U
#define GPIO_104_I2CA_SDA                 0x00C61001U
#define GPIO_104_EMIF2_A6                 0x00C61003U
#define GPIO_104_EQEP3_A                  0x00C61005U
#define GPIO_104_SCID_TX                  0x00C61006U
#define GPIO_104_ESC_GPI4                 0x00C6100AU
#define GPIO_104_CM_I2CA_SDA              0x00C6100BU
#define GPIO_104_FSIRXA_D1                0x00C6100DU

#define GPIO_105_GPIO105                  0x00C61200U
#define GPIO_105_I2CA_SCL                 0x00C61201U
#define GPIO_105_EMIF2_A7                 0x00C61203U
#define GPIO_105_EQEP3_B                  0x00C61205U
#define GPIO_105_SCID_RX                  0x00C61206U
#define GPIO_105_ESC_GPI5                 0x00C6120AU
#define GPIO_105_CM_I2CA_SCL              0x00C6120BU
#define GPIO_105_FSIRXA_CLK               0x00C6120DU
#define GPIO_105_ENET_MDIO_CLK            0x00C6120EU

#define GPIO_106_GPIO106                  0x00C61400U
#define GPIO_106_EMIF2_A8                 0x00C61403U
#define GPIO_106_EQEP3_STROBE             0x00C61405U
#define GPIO_106_SCIC_TX                  0x00C61406U
#define GPIO_106_ESC_GPI6                 0x00C6140AU
#define GPIO_106_FSITXB_D0                0x00C6140DU
#define GPIO_106_ENET_MDIO_DATA           0x00C6140EU

#define GPIO_107_GPIO107                  0x00C61600U
#define GPIO_107_EMIF2_A9                 0x00C61603U
#define GPIO_107_EQEP3_INDEX              0x00C61605U
#define GPIO_107_SCIC_RX                  0x00C61606U
#define GPIO_107_ESC_GPI7                 0x00C6160AU
#define GPIO_107_FSITXB_D1                0x00C6160DU
#define GPIO_107_ENET_REVMII_MDIO_RST     0x00C6160EU

#define GPIO_108_GPIO108                  0x00C61800U
#define GPIO_108_EMIF2_A10                0x00C61803U
#define GPIO_108_ESC_GPI8                 0x00C6180AU
#define GPIO_108_FSITXB_CLK               0x00C6180DU
#define GPIO_108_ENET_MII_INTR            0x00C6180EU

#define GPIO_109_GPIO109                  0x00C61A00U
#define GPIO_109_EMIF2_A11                0x00C61A03U
#define GPIO_109_ESC_GPI9                 0x00C61A0AU
#define GPIO_109_ENET_MII_CRS             0x00C61A0EU

#define GPIO_110_GPIO110                  0x00C61C00U
#define GPIO_110_EMIF2_WAIT               0x00C61C03U
#define GPIO_110_ESC_GPI10                0x00C61C0AU
#define GPIO_110_FSIRXB_D0                0x00C61C0DU
#define GPIO_110_ENET_MII_COL             0x00C61C0EU

#define GPIO_111_GPIO111                  0x00C61E00U
#define GPIO_111_EMIF2_BA0                0x00C61E03U
#define GPIO_111_ESC_GPI11                0x00C61E0AU
#define GPIO_111_FSIRXB_D1                0x00C61E0DU
#define GPIO_111_ENET_MII_RX_CLK          0x00C61E0EU

#define GPIO_112_GPIO112                  0x00C80000U
#define GPIO_112_EMIF2_BA1                0x00C80003U
#define GPIO_112_ESC_GPI12                0x00C8000AU
#define GPIO_112_FSIRXB_CLK               0x00C8000DU
#define GPIO_112_ENET_MII_RX_DV           0x00C8000EU

#define GPIO_113_GPIO113                  0x00C80200U
#define GPIO_113_EMIF2_CAS                0x00C80203U
#define GPIO_113_ESC_GPI13                0x00C8020AU
#define GPIO_113_ENET_MII_RX_ERR          0x00C8020EU

#define GPIO_114_GPIO114                  0x00C80400U
#define GPIO_114_EMIF2_RAS                0x00C80403U
#define GPIO_114_ESC_GPI14                0x00C8040AU
#define GPIO_114_ENET_MII_RX_DATA0        0x00C8040EU

#define GPIO_115_GPIO115                  0x00C80600U
#define GPIO_115_EMIF2_CS0N               0x00C80603U
#define GPIO_115_OUTPUTXBAR5              0x00C80605U
#define GPIO_115_ESC_GPI15                0x00C8060AU
#define GPIO_115_FSIRXC_D0                0x00C8060DU
#define GPIO_115_ENET_MII_RX_DATA1        0x00C8060EU

#define GPIO_116_GPIO116                  0x00C80800U
#define GPIO_116_EMIF2_CS2N               0x00C80803U
#define GPIO_116_OUTPUTXBAR6              0x00C80805U
#define GPIO_116_ESC_GPI16                0x00C8080AU
#define GPIO_116_FSIRXC_D1                0x00C8080DU
#define GPIO_116_ENET_MII_RX_DATA2        0x00C8080EU

#define GPIO_117_GPIO117                  0x00C80A00U
#define GPIO_117_EMIF2_SDCKE              0x00C80A03U
#define GPIO_117_ESC_GPI17                0x00C80A0AU
#define GPIO_117_FSIRXC_CLK               0x00C80A0DU
#define GPIO_117_ENET_MII_RX_DATA3        0x00C80A0EU

#define GPIO_118_GPIO118                  0x00C80C00U
#define GPIO_118_EMIF2_CLK                0x00C80C03U
#define GPIO_118_ESC_GPI18                0x00C80C0AU
#define GPIO_118_FSIRXD_D0                0x00C80C0DU
#define GPIO_118_ENET_MII_TX_EN           0x00C80C0EU

#define GPIO_119_GPIO119                  0x00C80E00U
#define GPIO_119_EMIF2_RNW                0x00C80E03U
#define GPIO_119_ESC_GPI19                0x00C80E0AU
#define GPIO_119_FSIRXD_D1                0x00C80E0DU
#define GPIO_119_ENET_MII_TX_ERR          0x00C80E0EU

#define GPIO_120_GPIO120                  0x00C81000U
#define GPIO_120_EMIF2_WEN                0x00C81003U
#define GPIO_120_ESC_GPI20                0x00C8100AU
#define GPIO_120_FSIRXD_CLK               0x00C8100DU
#define GPIO_120_ENET_MII_TX_CLK          0x00C8100EU

#define GPIO_121_GPIO121                  0x00C81200U
#define GPIO_121_EMIF2_OEN                0x00C81203U
#define GPIO_121_ESC_GPI21                0x00C8120AU
#define GPIO_121_FSIRXE_D0                0x00C8120DU
#define GPIO_121_ENET_MII_TX_DATA0        0x00C8120EU

#define GPIO_122_GPIO122                  0x00C81400U
#define GPIO_122_EMIF2_D15                0x00C81403U
#define GPIO_122_SPIC_SIMO                0x00C81406U
#define GPIO_122_SD1_D1                   0x00C81407U
#define GPIO_122_ESC_GPI22                0x00C8140AU
#define GPIO_122_ENET_MII_TX_DATA1        0x00C8140EU

#define GPIO_123_GPIO123                  0x00C81600U
#define GPIO_123_EMIF2_D14                0x00C81603U
#define GPIO_123_SPIC_SOMI                0x00C81606U
#define GPIO_123_SD1_C1                   0x00C81607U
#define GPIO_123_ESC_GPI23                0x00C8160AU
#define GPIO_123_ENET_MII_TX_DATA2        0x00C8160EU

#define GPIO_124_GPIO124                  0x00C81800U
#define GPIO_124_EMIF2_D13                0x00C81803U
#define GPIO_124_SPIC_CLK                 0x00C81806U
#define GPIO_124_SD1_D2                   0x00C81807U
#define GPIO_124_ESC_GPI24                0x00C8180AU
#define GPIO_124_ENET_MII_TX_DATA3        0x00C8180EU

#define GPIO_125_GPIO125                  0x00C81A00U
#define GPIO_125_EMIF2_D12                0x00C81A03U
#define GPIO_125_SPIC_STEN                0x00C81A06U
#define GPIO_125_SD1_C2                   0x00C81A07U
#define GPIO_125_ESC_GPI25                0x00C81A0AU
#define GPIO_125_FSIRXE_D1                0x00C81A0DU
#define GPIO_125_ESC_LATCH0               0x00C81A0EU

#define GPIO_126_GPIO126                  0x00C81C00U
#define GPIO_126_EMIF2_D11                0x00C81C03U
#define GPIO_126_SD1_D3                   0x00C81C07U
#define GPIO_126_ESC_GPI26                0x00C81C0AU
#define GPIO_126_FSIRXE_CLK               0x00C81C0DU
#define GPIO_126_ESC_LATCH1               0x00C81C0EU

#define GPIO_127_GPIO127                  0x00C81E00U
#define GPIO_127_EMIF2_D10                0x00C81E03U
#define GPIO_127_SD1_C3                   0x00C81E07U
#define GPIO_127_ESC_GPI27                0x00C81E0AU
#define GPIO_127_ESC_SYNC0                0x00C81E0EU

#define GPIO_128_GPIO128                  0x01060000U
#define GPIO_128_EMIF2_D9                 0x01060003U
#define GPIO_128_SD1_D4                   0x01060007U
#define GPIO_128_ESC_GPI28                0x0106000AU
#define GPIO_128_ESC_SYNC1                0x0106000EU

#define GPIO_129_GPIO129                  0x01060200U
#define GPIO_129_EMIF2_D8                 0x01060203U
#define GPIO_129_SD1_C4                   0x01060207U
#define GPIO_129_ESC_GPI29                0x0106020AU
#define GPIO_129_ESC_TX1_ENA              0x0106020EU

#define GPIO_130_GPIO130                  0x01060400U
#define GPIO_130_EMIF2_D7                 0x01060403U
#define GPIO_130_SD2_D1                   0x01060407U
#define GPIO_130_ESC_GPI30                0x0106040AU
#define GPIO_130_ESC_TX1_CLK              0x0106040EU

#define GPIO_131_GPIO131                  0x01060600U
#define GPIO_131_EMIF2_D6                 0x01060603U
#define GPIO_131_SD2_C1                   0x01060607U
#define GPIO_131_ESC_GPI31                0x0106060AU
#define GPIO_131_ESC_TX1_DATA0            0x0106060EU

#define GPIO_132_GPIO132                  0x01060800U
#define GPIO_132_EMIF2_D5                 0x01060803U
#define GPIO_132_SD2_D2                   0x01060807U
#define GPIO_132_ESC_GPO0                 0x0106080AU
#define GPIO_132_ESC_TX1_DATA1            0x0106080EU

#define GPIO_133_GPIO133                  0x01060A00U
#define GPIO_133_SD2_C2                   0x01060A07U

#define GPIO_134_GPIO134                  0x01060C00U
#define GPIO_134_EMIF2_D4                 0x01060C03U
#define GPIO_134_SD2_D3                   0x01060C07U
#define GPIO_134_ESC_GPO1                 0x01060C0AU
#define GPIO_134_ESC_TX1_DATA2            0x01060C0EU

#define GPIO_135_GPIO135                  0x01060E00U
#define GPIO_135_EMIF2_D3                 0x01060E03U
#define GPIO_135_SCIA_TX                  0x01060E06U
#define GPIO_135_SD2_C3                   0x01060E07U
#define GPIO_135_ESC_GPO2                 0x01060E0AU
#define GPIO_135_ESC_TX1_DATA3            0x01060E0EU

#define GPIO_136_GPIO136                  0x01061000U
#define GPIO_136_EMIF2_D2                 0x01061003U
#define GPIO_136_SCIA_RX                  0x01061006U
#define GPIO_136_SD2_D4                   0x01061007U
#define GPIO_136_ESC_GPO3                 0x0106100AU
#define GPIO_136_ESC_RX1_DV               0x0106100EU

#define GPIO_137_GPIO137                  0x01061200U
#define GPIO_137_EPWM13A                  0x01061201U
#define GPIO_137_EMIF2_D1                 0x01061203U
#define GPIO_137_SCIB_TX                  0x01061206U
#define GPIO_137_SD2_C4                   0x01061207U
#define GPIO_137_ESC_GPO4                 0x0106120AU
#define GPIO_137_ESC_RX1_CLK              0x0106120EU

#define GPIO_138_GPIO138                  0x01061400U
#define GPIO_138_EPWM13B                  0x01061401U
#define GPIO_138_EMIF2_D0                 0x01061403U
#define GPIO_138_SCIB_RX                  0x01061406U
#define GPIO_138_ESC_GPO5                 0x0106140AU
#define GPIO_138_ESC_RX1_ERR              0x0106140EU

#define GPIO_139_GPIO139                  0x01061600U
#define GPIO_139_EPWM14A                  0x01061601U
#define GPIO_139_SCIC_RX                  0x01061606U
#define GPIO_139_ESC_GPO6                 0x0106160AU
#define GPIO_139_ESC_RX1_DATA0            0x0106160EU

#define GPIO_140_GPIO140                  0x01061800U
#define GPIO_140_EPWM14B                  0x01061801U
#define GPIO_140_SCIC_TX                  0x01061806U
#define GPIO_140_ESC_GPO7                 0x0106180AU
#define GPIO_140_ESC_RX1_DATA1            0x0106180EU

#define GPIO_141_GPIO141                  0x01061A00U
#define GPIO_141_EPWM15A                  0x01061A01U
#define GPIO_141_SCID_RX                  0x01061A06U
#define GPIO_141_ESC_GPO8                 0x01061A0AU
#define GPIO_141_ESC_RX1_DATA2            0x01061A0EU

#define GPIO_142_GPIO142                  0x01061C00U
#define GPIO_142_EPWM15B                  0x01061C01U
#define GPIO_142_SCID_TX                  0x01061C06U
#define GPIO_142_ESC_GPO9                 0x01061C0AU
#define GPIO_142_ESC_RX1_DATA3            0x01061C0EU

#define GPIO_143_GPIO143                  0x01061E00U
#define GPIO_143_EPWM16A                  0x01061E01U
#define GPIO_143_ESC_GPO10                0x01061E0AU
#define GPIO_143_ESC_LED_LINK0_ACTIVE     0x01061E0EU

#define GPIO_144_GPIO144                  0x01080000U
#define GPIO_144_EPWM16B                  0x01080001U
#define GPIO_144_ESC_GPO11                0x0108000AU
#define GPIO_144_ESC_LED_LINK1_ACTIVE     0x0108000EU

#define GPIO_145_GPIO145                  0x01080200U
#define GPIO_145_EPWM1A                   0x01080201U
#define GPIO_145_ESC_GPO12                0x0108020AU
#define GPIO_145_ESC_LED_ERR              0x0108020EU

#define GPIO_146_GPIO146                  0x01080400U
#define GPIO_146_EPWM1B                   0x01080401U
#define GPIO_146_ESC_GPO13                0x0108040AU
#define GPIO_146_ESC_LED_RUN              0x0108040EU

#define GPIO_147_GPIO147                  0x01080600U
#define GPIO_147_EPWM2A                   0x01080601U
#define GPIO_147_ESC_GPO14                0x0108060AU
#define GPIO_147_ESC_LED_STATE_RUN        0x0108060EU

#define GPIO_148_GPIO148                  0x01080800U
#define GPIO_148_EPWM2B                   0x01080801U
#define GPIO_148_ESC_GPO15                0x0108080AU
#define GPIO_148_ESC_PHY0_LINKSTATUS      0x0108080EU

#define GPIO_149_GPIO149                  0x01080A00U
#define GPIO_149_EPWM3A                   0x01080A01U
#define GPIO_149_ESC_GPO16                0x01080A0AU
#define GPIO_149_ESC_PHY1_LINKSTATUS      0x01080A0EU

#define GPIO_150_GPIO150                  0x01080C00U
#define GPIO_150_EPWM3B                   0x01080C01U
#define GPIO_150_ESC_GPO17                0x01080C0AU
#define GPIO_150_ESC_I2C_SDA              0x01080C0EU

#define GPIO_151_GPIO151                  0x01080E00U
#define GPIO_151_EPWM4A                   0x01080E01U
#define GPIO_151_ESC_GPO18                0x01080E0AU
#define GPIO_151_ESC_I2C_SCL              0x01080E0EU

#define GPIO_152_GPIO152                  0x01081000U
#define GPIO_152_EPWM4B                   0x01081001U
#define GPIO_152_ESC_GPO19                0x0108100AU
#define GPIO_152_ESC_MDIO_CLK             0x0108100EU

#define GPIO_153_GPIO153                  0x01081200U
#define GPIO_153_EPWM5A                   0x01081201U
#define GPIO_153_ESC_GPO20                0x0108120AU
#define GPIO_153_ESC_MDIO_DATA            0x0108120EU

#define GPIO_154_GPIO154                  0x01081400U
#define GPIO_154_EPWM5B                   0x01081401U
#define GPIO_154_ESC_GPO21                0x0108140AU
#define GPIO_154_ESC_PHY_CLK              0x0108140EU

#define GPIO_155_GPIO155                  0x01081600U
#define GPIO_155_EPWM6A                   0x01081601U
#define GPIO_155_ESC_GPO22                0x0108160AU
#define GPIO_155_ESC_PHY_RESETN           0x0108160EU

#define GPIO_156_GPIO156                  0x01081800U
#define GPIO_156_EPWM6B                   0x01081801U
#define GPIO_156_ESC_GPO23                0x0108180AU
#define GPIO_156_ESC_TX0_ENA              0x0108180EU

#define GPIO_157_GPIO157                  0x01081A00U
#define GPIO_157_EPWM7A                   0x01081A01U
#define GPIO_157_ESC_GPO24                0x01081A0AU
#define GPIO_157_ESC_TX0_CLK              0x01081A0EU

#define GPIO_158_GPIO158                  0x01081C00U
#define GPIO_158_EPWM7B                   0x01081C01U
#define GPIO_158_ESC_GPO25                0x01081C0AU
#define GPIO_158_ESC_TX0_DATA0            0x01081C0EU

#define GPIO_159_GPIO159                  0x01081E00U
#define GPIO_159_EPWM8A                   0x01081E01U
#define GPIO_159_ESC_GPO26                0x01081E0AU
#define GPIO_159_ESC_TX0_DATA1            0x01081E0EU

#define GPIO_160_GPIO160                  0x01460000U
#define GPIO_160_EPWM8B                   0x01460001U
#define GPIO_160_ESC_GPO27                0x0146000AU
#define GPIO_160_ESC_TX0_DATA2            0x0146000EU

#define GPIO_161_GPIO161                  0x01460200U
#define GPIO_161_EPWM9A                   0x01460201U
#define GPIO_161_ESC_GPO28                0x0146020AU
#define GPIO_161_ESC_TX0_DATA3            0x0146020EU

#define GPIO_162_GPIO162                  0x01460400U
#define GPIO_162_EPWM9B                   0x01460401U
#define GPIO_162_ESC_GPO29                0x0146040AU
#define GPIO_162_ESC_RX0_DV               0x0146040EU

#define GPIO_163_GPIO163                  0x01460600U
#define GPIO_163_EPWM10A                  0x01460601U
#define GPIO_163_ESC_GPO30                0x0146060AU
#define GPIO_163_ESC_RX0_CLK              0x0146060EU

#define GPIO_164_GPIO164                  0x01460800U
#define GPIO_164_EPWM10B                  0x01460801U
#define GPIO_164_ESC_GPO31                0x0146080AU
#define GPIO_164_ESC_RX0_ERR              0x0146080EU

#define GPIO_165_GPIO165                  0x01460A00U
#define GPIO_165_EPWM11A                  0x01460A01U
#define GPIO_165_MDXA                     0x01460A0AU
#define GPIO_165_ESC_RX0_DATA0            0x01460A0EU

#define GPIO_166_GPIO166                  0x01460C00U
#define GPIO_166_EPWM11B                  0x01460C01U
#define GPIO_166_MDRA                     0x01460C0AU
#define GPIO_166_ESC_RX0_DATA1            0x01460C0EU

#define GPIO_167_GPIO167                  0x01460E00U
#define GPIO_167_EPWM12A                  0x01460E01U
#define GPIO_167_MCLKXA                   0x01460E0AU
#define GPIO_167_ESC_RX0_DATA2            0x01460E0EU

#define GPIO_168_GPIO168                  0x01461000U
#define GPIO_168_EPWM12B                  0x01461001U
#define GPIO_168_MFSXA                    0x0146100AU
#define GPIO_168_ESC_RX0_DATA3            0x0146100EU

//*****************************************************************************
// Legacy pinmuxing MACROS - Retained for portability across devices ONLY      
// Not recommended for new users                                               
//*****************************************************************************
#define GPIO_0_SDAA                     GPIO_0_I2CA_SDA
#define GPIO_0_FSITXD0A                 GPIO_0_FSITXA_D0

#define GPIO_1_SCLA                     GPIO_1_I2CA_SCL
#define GPIO_1_FSITXD1A                 GPIO_1_FSITXA_D1

#define GPIO_2_SDAB                     GPIO_2_I2CB_SDA
#define GPIO_2_FSITXCLKA                GPIO_2_FSITXA_CLK

#define GPIO_3_SCLB                     GPIO_3_I2CB_SCL
#define GPIO_3_FSIRXD0A                 GPIO_3_FSIRXA_D0

#define GPIO_4_CANTXA                   GPIO_4_CANA_TX
#define GPIO_4_FSIRXD1A                 GPIO_4_FSIRXA_D1

#define GPIO_5_CANRXA                   GPIO_5_CANA_RX
#define GPIO_5_FSIRXCLKA                GPIO_5_FSIRXA_CLK

#define GPIO_6_EPWMSYNCO                GPIO_6_EXTSYNCOUT
#define GPIO_6_EQEP3A                   GPIO_6_EQEP3_A
#define GPIO_6_CANTXB                   GPIO_6_CANB_TX
#define GPIO_6_FSITXD0B                 GPIO_6_FSITXB_D0

#define GPIO_7_EQEP3B                   GPIO_7_EQEP3_B
#define GPIO_7_CANRXB                   GPIO_7_CANB_RX
#define GPIO_7_FSITXD1B                 GPIO_7_FSITXB_D1

#define GPIO_8_CANTXB                   GPIO_8_CANB_TX
#define GPIO_8_EQEP3S                   GPIO_8_EQEP3_STROBE
#define GPIO_8_SCITXDA                  GPIO_8_SCIA_TX
#define GPIO_8_FSITXCLKB                GPIO_8_FSITXB_CLK
#define GPIO_8_FSITXD1A                 GPIO_8_FSITXA_D1
#define GPIO_8_FSIRXD0A                 GPIO_8_FSIRXA_D0

#define GPIO_9_SCITXDB                  GPIO_9_SCIB_TX
#define GPIO_9_EQEP3I                   GPIO_9_EQEP3_INDEX
#define GPIO_9_SCIRXDA                  GPIO_9_SCIA_RX
#define GPIO_9_FSIRXD0B                 GPIO_9_FSIRXB_D0
#define GPIO_9_FSITXD0A                 GPIO_9_FSITXA_D0
#define GPIO_9_FSIRXCLKA                GPIO_9_FSIRXA_CLK

#define GPIO_10_CANRXB                   GPIO_10_CANB_RX
#define GPIO_10_EQEP1A                   GPIO_10_EQEP1_A
#define GPIO_10_SCITXDB                  GPIO_10_SCIB_TX
#define GPIO_10_FSIRXD1B                 GPIO_10_FSIRXB_D1
#define GPIO_10_FSITXCLKA                GPIO_10_FSITXA_CLK
#define GPIO_10_FSIRXD1A                 GPIO_10_FSIRXA_D1

#define GPIO_11_SCIRXDB                  GPIO_11_SCIB_RX
#define GPIO_11_EQEP1B                   GPIO_11_EQEP1_B
#define GPIO_11_FSIRXCLKB                GPIO_11_FSIRXB_CLK
#define GPIO_11_FSIRXD1A                 GPIO_11_FSIRXA_D1

#define GPIO_12_CANTXB                   GPIO_12_CANB_TX
#define GPIO_12_EQEP1S                   GPIO_12_EQEP1_STROBE
#define GPIO_12_SCITXDC                  GPIO_12_SCIC_TX
#define GPIO_12_FSIRXD0C                 GPIO_12_FSIRXC_D0
#define GPIO_12_FSIRXD0A                 GPIO_12_FSIRXA_D0

#define GPIO_13_CANRXB                   GPIO_13_CANB_RX
#define GPIO_13_EQEP1I                   GPIO_13_EQEP1_INDEX
#define GPIO_13_SCIRXDC                  GPIO_13_SCIC_RX
#define GPIO_13_FSIRXD1C                 GPIO_13_FSIRXC_D1
#define GPIO_13_FSIRXCLKA                GPIO_13_FSIRXA_CLK

#define GPIO_14_SCITXDB                  GPIO_14_SCIB_TX
#define GPIO_14_FSIRXCLKC                GPIO_14_FSIRXC_CLK

#define GPIO_15_SCIRXDB                  GPIO_15_SCIB_RX
#define GPIO_15_FSIRXD0D                 GPIO_15_FSIRXD_D0

#define GPIO_16_SPISIMOA                 GPIO_16_SPIA_SIMO
#define GPIO_16_CANTXB                   GPIO_16_CANB_TX
#define GPIO_16_SD_D1                    GPIO_16_SD1_D1
#define GPIO_16_FSIRXD1D                 GPIO_16_FSIRXD_D1

#define GPIO_17_SPISOMIA                 GPIO_17_SPIA_SOMI
#define GPIO_17_CANRXB                   GPIO_17_CANB_RX
#define GPIO_17_SD_C1                    GPIO_17_SD1_C1
#define GPIO_17_FSIRXCLKD                GPIO_17_FSIRXD_CLK

#define GPIO_18_SPICLKA                  GPIO_18_SPIA_CLK
#define GPIO_18_SCITXDB                  GPIO_18_SCIB_TX
#define GPIO_18_CANRXA                   GPIO_18_CANA_RX
#define GPIO_18_SD_D2                    GPIO_18_SD1_D2
#define GPIO_18_EM1CS2N                  GPIO_18_EMIF1_CS2N
#define GPIO_18_FSIRXD0E                 GPIO_18_FSIRXE_D0

#define GPIO_19_SPISTEA                  GPIO_19_SPIA_STEN
#define GPIO_19_SCIRXDB                  GPIO_19_SCIB_RX
#define GPIO_19_CANTXA                   GPIO_19_CANA_TX
#define GPIO_19_SD_C2                    GPIO_19_SD1_C2
#define GPIO_19_EM1CS3N                  GPIO_19_EMIF1_CS3N
#define GPIO_19_FSIRXD1E                 GPIO_19_FSIRXE_D1

#define GPIO_20_EQEP1A                   GPIO_20_EQEP1_A
#define GPIO_20_CANTXB                   GPIO_20_CANB_TX
#define GPIO_20_SD_D3                    GPIO_20_SD1_D3
#define GPIO_20_EM1BA0                   GPIO_20_EMIF1_BA0
#define GPIO_20_TRACEDATA0               GPIO_20_TRACE_DATA0
#define GPIO_20_FSIRXCLKE                GPIO_20_FSIRXE_CLK
#define GPIO_20_SPISIMOC                 GPIO_20_SPIC_SIMO

#define GPIO_21_EQEP1B                   GPIO_21_EQEP1_B
#define GPIO_21_CANRXB                   GPIO_21_CANB_RX
#define GPIO_21_SD_C3                    GPIO_21_SD1_C3
#define GPIO_21_EM1BA1                   GPIO_21_EMIF1_BA1
#define GPIO_21_TRACEDATA1               GPIO_21_TRACE_DATA1
#define GPIO_21_FSIRXD0F                 GPIO_21_FSIRXF_D0
#define GPIO_21_SPISOMIC                 GPIO_21_SPIC_SOMI

#define GPIO_22_EQEP1S                   GPIO_22_EQEP1_STROBE
#define GPIO_22_SCITXDB                  GPIO_22_SCIB_TX
#define GPIO_22_SPICLKB                  GPIO_22_SPIB_CLK
#define GPIO_22_SD_D4                    GPIO_22_SD1_D4
#define GPIO_22_EM1RAS                   GPIO_22_EMIF1_RAS
#define GPIO_22_TRACEDATA2               GPIO_22_TRACE_DATA2
#define GPIO_22_FSIRXD1F                 GPIO_22_FSIRXF_D1
#define GPIO_22_SPICLKC                  GPIO_22_SPIC_CLK

#define GPIO_23_EQEP1I                   GPIO_23_EQEP1_INDEX
#define GPIO_23_SCIRXDB                  GPIO_23_SCIB_RX
#define GPIO_23_SPISTEB                  GPIO_23_SPIB_STEN
#define GPIO_23_SD_C4                    GPIO_23_SD1_C4
#define GPIO_23_EM1CAS                   GPIO_23_EMIF1_CAS
#define GPIO_23_TRACEDATA3               GPIO_23_TRACE_DATA3
#define GPIO_23_FSIRXCLKF                GPIO_23_FSIRXF_CLK
#define GPIO_23_SPISTEC                  GPIO_23_SPIC_STEN

#define GPIO_24_EQEP2A                   GPIO_24_EQEP2_A
#define GPIO_24_SPISIMOB                 GPIO_24_SPIB_SIMO
#define GPIO_24_SD_D5                    GPIO_24_SD2_D1
#define GPIO_24_PMBCLK                   GPIO_24_PMBUSA_SCL
#define GPIO_24_EM1DQM0                  GPIO_24_EMIF1_DQM0
#define GPIO_24_TRACECLK                 GPIO_24_TRACE_CLK
#define GPIO_24_FSIRXD0G                 GPIO_24_FSIRXG_D0

#define GPIO_25_EQEP2B                   GPIO_25_EQEP2_B
#define GPIO_25_SPISOMIB                 GPIO_25_SPIB_SOMI
#define GPIO_25_SD_C5                    GPIO_25_SD2_C1
#define GPIO_25_PMBDAT                   GPIO_25_PMBUSA_SDA
#define GPIO_25_EM1DQM1                  GPIO_25_EMIF1_DQM1
#define GPIO_25_TRACESWO                 GPIO_25_TRACE_SWO
#define GPIO_25_FSITXD1A                 GPIO_25_FSITXA_D1
#define GPIO_25_FSIRXD1G                 GPIO_25_FSIRXG_D1

#define GPIO_26_EQEP2I                   GPIO_26_EQEP2_INDEX
#define GPIO_26_SPICLKB                  GPIO_26_SPIB_CLK
#define GPIO_26_SD_D6                    GPIO_26_SD2_D2
#define GPIO_26_PMBALERT                 GPIO_26_PMBUSA_ALERT
#define GPIO_26_EM1DQM2                  GPIO_26_EMIF1_DQM2
#define GPIO_26_FSITXD0A                 GPIO_26_FSITXA_D0
#define GPIO_26_FSIRXCLKG                GPIO_26_FSIRXG_CLK

#define GPIO_27_EQEP2S                   GPIO_27_EQEP2_STROBE
#define GPIO_27_SPISTEB                  GPIO_27_SPIB_STEN
#define GPIO_27_SD_C6                    GPIO_27_SD2_C2
#define GPIO_27_PMBCTRL                  GPIO_27_PMBUSA_CTL
#define GPIO_27_EM1DQM3                  GPIO_27_EMIF1_DQM3
#define GPIO_27_FSITXCLKA                GPIO_27_FSITXA_CLK
#define GPIO_27_FSIRXD0H                 GPIO_27_FSIRXH_D0

#define GPIO_28_SCIRXDA                  GPIO_28_SCIA_RX
#define GPIO_28_EM1CS4N                  GPIO_28_EMIF1_CS4N
#define GPIO_28_EQEP3A                   GPIO_28_EQEP3_A
#define GPIO_28_SD_D7                    GPIO_28_SD2_D3
#define GPIO_28_EM1CS2N                  GPIO_28_EMIF1_CS2N
#define GPIO_28_FSIRXD1H                 GPIO_28_FSIRXH_D1

#define GPIO_29_SCITXDA                  GPIO_29_SCIA_TX
#define GPIO_29_EM1SDCKE                 GPIO_29_EMIF1_SDCKE
#define GPIO_29_EQEP3B                   GPIO_29_EQEP3_B
#define GPIO_29_SD_C7                    GPIO_29_SD2_C3
#define GPIO_29_EM1CS3N                  GPIO_29_EMIF1_CS3N
#define GPIO_29_FSIRXCLKH                GPIO_29_FSIRXH_CLK

#define GPIO_30_CANRXA                   GPIO_30_CANA_RX
#define GPIO_30_EM1CLK                   GPIO_30_EMIF1_CLK
#define GPIO_30_MCANRXA                  GPIO_30_MCAN_RX
#define GPIO_30_EQEP3S                   GPIO_30_EQEP3_STROBE
#define GPIO_30_SD_D8                    GPIO_30_SD2_D4
#define GPIO_30_EM1CS4N                  GPIO_30_EMIF1_CS4N
#define GPIO_30_SPISIMOD                 GPIO_30_SPID_SIMO

#define GPIO_31_CANTXA                   GPIO_31_CANA_TX
#define GPIO_31_EM1WEN                   GPIO_31_EMIF1_WEN
#define GPIO_31_MCANTXA                  GPIO_31_MCAN_TX
#define GPIO_31_EQEP3I                   GPIO_31_EQEP3_INDEX
#define GPIO_31_SD_C8                    GPIO_31_SD2_C4
#define GPIO_31_EM1RNW                   GPIO_31_EMIF1_RNW
#define GPIO_31_SDAA                     GPIO_31_I2CA_SDA
#define GPIO_31_SPISOMID                 GPIO_31_SPID_SOMI

#define GPIO_32_SDAA                     GPIO_32_I2CA_SDA
#define GPIO_32_EM1CS0N                  GPIO_32_EMIF1_CS0N
#define GPIO_32_SPISIMOA                 GPIO_32_SPIA_SIMO
#define GPIO_32_EM1OEN                   GPIO_32_EMIF1_OEN
#define GPIO_32_SCLA                     GPIO_32_I2CA_SCL
#define GPIO_32_SPICLKD                  GPIO_32_SPID_CLK

#define GPIO_33_SCLA                     GPIO_33_I2CA_SCL
#define GPIO_33_EM1RNW                   GPIO_33_EMIF1_RNW
#define GPIO_33_SPISOMIA                 GPIO_33_SPIA_SOMI
#define GPIO_33_EM1BA0                   GPIO_33_EMIF1_BA0
#define GPIO_33_SPISTED                  GPIO_33_SPID_STEN

#define GPIO_34_EM1CS2N                  GPIO_34_EMIF1_CS2N
#define GPIO_34_SPICLKA                  GPIO_34_SPIA_CLK
#define GPIO_34_SDAB                     GPIO_34_I2CB_SDA
#define GPIO_34_EM1BA1                   GPIO_34_EMIF1_BA1
#define GPIO_34_SCITXDA                  GPIO_34_SCIA_TX

#define GPIO_35_SCIRXDA                  GPIO_35_SCIA_RX
#define GPIO_35_EM1CS3N                  GPIO_35_EMIF1_CS3N
#define GPIO_35_SPISTEA                  GPIO_35_SPIA_STEN
#define GPIO_35_SCLB                     GPIO_35_I2CB_SCL
#define GPIO_35_EM1A0                    GPIO_35_EMIF1_A0

#define GPIO_36_SCITXDA                  GPIO_36_SCIA_TX
#define GPIO_36_EM1WAIT0                 GPIO_36_EMIF1_WAIT
#define GPIO_36_CANRXA                   GPIO_36_CANA_RX
#define GPIO_36_EM1A1                    GPIO_36_EMIF1_A1
#define GPIO_36_SD_D1                    GPIO_36_SD1_D1

#define GPIO_37_EM1OEN                   GPIO_37_EMIF1_OEN
#define GPIO_37_CANTXA                   GPIO_37_CANA_TX
#define GPIO_37_EM1A2                    GPIO_37_EMIF1_A2
#define GPIO_37_SD_D2                    GPIO_37_SD1_D2

#define GPIO_38_EM1A0                    GPIO_38_EMIF1_A0
#define GPIO_38_SCITXDC                  GPIO_38_SCIC_TX
#define GPIO_38_CANTXB                   GPIO_38_CANB_TX
#define GPIO_38_EM1A3                    GPIO_38_EMIF1_A3
#define GPIO_38_SD_D3                    GPIO_38_SD1_D3

#define GPIO_39_EM1A1                    GPIO_39_EMIF1_A1
#define GPIO_39_SCIRXDC                  GPIO_39_SCIC_RX
#define GPIO_39_CANRXB                   GPIO_39_CANB_RX
#define GPIO_39_EM1A4                    GPIO_39_EMIF1_A4
#define GPIO_39_SD_D4                    GPIO_39_SD1_D4

#define GPIO_40_EM1A2                    GPIO_40_EMIF1_A2
#define GPIO_40_SDAB                     GPIO_40_I2CB_SDA

#define GPIO_41_EM1A3                    GPIO_41_EMIF1_A3
#define GPIO_41_SCLB                     GPIO_41_I2CB_SCL

#define GPIO_42_SDAA                     GPIO_42_I2CA_SDA
#define GPIO_42_SCITXDA                  GPIO_42_SCIA_TX

#define GPIO_43_SCLA                     GPIO_43_I2CA_SCL
#define GPIO_43_SCIRXDA                  GPIO_43_SCIA_RX

#define GPIO_44_EM1A4                    GPIO_44_EMIF1_A4

#define GPIO_45_EM1A5                    GPIO_45_EMIF1_A5

#define GPIO_46_EM1A6                    GPIO_46_EMIF1_A6
#define GPIO_46_SCIRXDD                  GPIO_46_SCID_RX

#define GPIO_47_EM1A7                    GPIO_47_EMIF1_A7
#define GPIO_47_SCITXDD                  GPIO_47_SCID_TX

#define GPIO_48_EM1A8                    GPIO_48_EMIF1_A8
#define GPIO_48_SCITXDA                  GPIO_48_SCIA_TX
#define GPIO_48_SD_D1                    GPIO_48_SD1_D1

#define GPIO_49_EM1A9                    GPIO_49_EMIF1_A9
#define GPIO_49_SCIRXDA                  GPIO_49_SCIA_RX
#define GPIO_49_SD_C1                    GPIO_49_SD1_C1
#define GPIO_49_EM1A5                    GPIO_49_EMIF1_A5
#define GPIO_49_SD_D5                    GPIO_49_SD2_D1
#define GPIO_49_FSITXD0A                 GPIO_49_FSITXA_D0

#define GPIO_50_EQEP1A                   GPIO_50_EQEP1_A
#define GPIO_50_EM1A10                   GPIO_50_EMIF1_A10
#define GPIO_50_SPISIMOC                 GPIO_50_SPIC_SIMO
#define GPIO_50_SD_D2                    GPIO_50_SD1_D2
#define GPIO_50_EM1A6                    GPIO_50_EMIF1_A6
#define GPIO_50_SD_D6                    GPIO_50_SD2_D2
#define GPIO_50_FSITXD1A                 GPIO_50_FSITXA_D1

#define GPIO_51_EQEP1B                   GPIO_51_EQEP1_B
#define GPIO_51_EM1A11                   GPIO_51_EMIF1_A11
#define GPIO_51_SPISOMIC                 GPIO_51_SPIC_SOMI
#define GPIO_51_SD_C2                    GPIO_51_SD1_C2
#define GPIO_51_EM1A7                    GPIO_51_EMIF1_A7
#define GPIO_51_SD_D7                    GPIO_51_SD2_D3
#define GPIO_51_FSITXCLKA                GPIO_51_FSITXA_CLK

#define GPIO_52_EQEP1S                   GPIO_52_EQEP1_STROBE
#define GPIO_52_EM1A12                   GPIO_52_EMIF1_A12
#define GPIO_52_SPICLKC                  GPIO_52_SPIC_CLK
#define GPIO_52_SD_D3                    GPIO_52_SD1_D3
#define GPIO_52_EM1A8                    GPIO_52_EMIF1_A8
#define GPIO_52_SD_D8                    GPIO_52_SD2_D4
#define GPIO_52_FSIRXD0A                 GPIO_52_FSIRXA_D0

#define GPIO_53_EQEP1I                   GPIO_53_EQEP1_INDEX
#define GPIO_53_EM1D31                   GPIO_53_EMIF1_D31
#define GPIO_53_EM2D15                   GPIO_53_EMIF2_D15
#define GPIO_53_SPISTEC                  GPIO_53_SPIC_STEN
#define GPIO_53_SD_C3                    GPIO_53_SD1_C3
#define GPIO_53_EM1A9                    GPIO_53_EMIF1_A9
#define GPIO_53_SD_C1                    GPIO_53_SD1_C1
#define GPIO_53_FSIRXD1A                 GPIO_53_FSIRXA_D1

#define GPIO_54_SPISIMOA                 GPIO_54_SPIA_SIMO
#define GPIO_54_EM1D30                   GPIO_54_EMIF1_D30
#define GPIO_54_EM2D14                   GPIO_54_EMIF2_D14
#define GPIO_54_EQEP2A                   GPIO_54_EQEP2_A
#define GPIO_54_SCITXDB                  GPIO_54_SCIB_TX
#define GPIO_54_SD_D4                    GPIO_54_SD1_D4
#define GPIO_54_EM1A10                   GPIO_54_EMIF1_A10
#define GPIO_54_SD_C2                    GPIO_54_SD1_C2
#define GPIO_54_FSIRXCLKA                GPIO_54_FSIRXA_CLK

#define GPIO_55_SPISOMIA                 GPIO_55_SPIA_SOMI
#define GPIO_55_EM1D29                   GPIO_55_EMIF1_D29
#define GPIO_55_EM2D13                   GPIO_55_EMIF2_D13
#define GPIO_55_EQEP2B                   GPIO_55_EQEP2_B
#define GPIO_55_SCIRXDB                  GPIO_55_SCIB_RX
#define GPIO_55_SD_C4                    GPIO_55_SD1_C4
#define GPIO_55_EM1D0                    GPIO_55_EMIF1_D0
#define GPIO_55_SD_C3                    GPIO_55_SD1_C3
#define GPIO_55_FSITXD0B                 GPIO_55_FSITXB_D0

#define GPIO_56_SPICLKA                  GPIO_56_SPIA_CLK
#define GPIO_56_EM1D28                   GPIO_56_EMIF1_D28
#define GPIO_56_EM2D12                   GPIO_56_EMIF2_D12
#define GPIO_56_EQEP2S                   GPIO_56_EQEP2_STROBE
#define GPIO_56_SCITXDC                  GPIO_56_SCIC_TX
#define GPIO_56_SD_D5                    GPIO_56_SD2_D1
#define GPIO_56_EM1D1                    GPIO_56_EMIF1_D1
#define GPIO_56_SDAA                     GPIO_56_I2CA_SDA
#define GPIO_56_SD_C4                    GPIO_56_SD1_C4
#define GPIO_56_FSITXCLKB                GPIO_56_FSITXB_CLK

#define GPIO_57_SPISTEA                  GPIO_57_SPIA_STEN
#define GPIO_57_EM1D27                   GPIO_57_EMIF1_D27
#define GPIO_57_EM2D11                   GPIO_57_EMIF2_D11
#define GPIO_57_EQEP2I                   GPIO_57_EQEP2_INDEX
#define GPIO_57_SCIRXDC                  GPIO_57_SCIC_RX
#define GPIO_57_SD_C5                    GPIO_57_SD2_C1
#define GPIO_57_EM1D2                    GPIO_57_EMIF1_D2
#define GPIO_57_SCLA                     GPIO_57_I2CA_SCL
#define GPIO_57_FSITXD1B                 GPIO_57_FSITXB_D1

#define GPIO_58_EM1D26                   GPIO_58_EMIF1_D26
#define GPIO_58_EM2D10                   GPIO_58_EMIF2_D10
#define GPIO_58_SPICLKB                  GPIO_58_SPIB_CLK
#define GPIO_58_SD_D6                    GPIO_58_SD2_D2
#define GPIO_58_EM1D3                    GPIO_58_EMIF1_D3
#define GPIO_58_SD_C6                    GPIO_58_SD2_C2
#define GPIO_58_FSIRXD0B                 GPIO_58_FSIRXB_D0
#define GPIO_58_SPISIMOA                 GPIO_58_SPIA_SIMO

#define GPIO_59_EM1D25                   GPIO_59_EMIF1_D25
#define GPIO_59_EM2D9                    GPIO_59_EMIF2_D9
#define GPIO_59_SPISTEB                  GPIO_59_SPIB_STEN
#define GPIO_59_SD_C6                    GPIO_59_SD2_C2
#define GPIO_59_EM1D4                    GPIO_59_EMIF1_D4
#define GPIO_59_SD_C7                    GPIO_59_SD2_C3
#define GPIO_59_FSIRXD1B                 GPIO_59_FSIRXB_D1
#define GPIO_59_SPISOMIA                 GPIO_59_SPIA_SOMI

#define GPIO_60_EM1D24                   GPIO_60_EMIF1_D24
#define GPIO_60_EM2D8                    GPIO_60_EMIF2_D8
#define GPIO_60_SPISIMOB                 GPIO_60_SPIB_SIMO
#define GPIO_60_SD_D7                    GPIO_60_SD2_D3
#define GPIO_60_EM1D5                    GPIO_60_EMIF1_D5
#define GPIO_60_SD_C8                    GPIO_60_SD2_C4
#define GPIO_60_FSIRXCLKB                GPIO_60_FSIRXB_CLK
#define GPIO_60_SPICLKA                  GPIO_60_SPIA_CLK

#define GPIO_61_EM1D23                   GPIO_61_EMIF1_D23
#define GPIO_61_EM2D7                    GPIO_61_EMIF2_D7
#define GPIO_61_SPISOMIB                 GPIO_61_SPIB_SOMI
#define GPIO_61_SD_C7                    GPIO_61_SD2_C3
#define GPIO_61_EM1D6                    GPIO_61_EMIF1_D6
#define GPIO_61_CANRXA                   GPIO_61_CANA_RX
#define GPIO_61_SPISTEA                  GPIO_61_SPIA_STEN

#define GPIO_62_SCIRXDC                  GPIO_62_SCIC_RX
#define GPIO_62_EM1D22                   GPIO_62_EMIF1_D22
#define GPIO_62_EM2D6                    GPIO_62_EMIF2_D6
#define GPIO_62_EQEP3A                   GPIO_62_EQEP3_A
#define GPIO_62_CANRXA                   GPIO_62_CANA_RX
#define GPIO_62_SD_D8                    GPIO_62_SD2_D4
#define GPIO_62_EM1D7                    GPIO_62_EMIF1_D7
#define GPIO_62_CANTXA                   GPIO_62_CANA_TX

#define GPIO_63_SCITXDC                  GPIO_63_SCIC_TX
#define GPIO_63_EM1D21                   GPIO_63_EMIF1_D21
#define GPIO_63_EM2D5                    GPIO_63_EMIF2_D5
#define GPIO_63_EQEP3B                   GPIO_63_EQEP3_B
#define GPIO_63_CANTXA                   GPIO_63_CANA_TX
#define GPIO_63_SD_C8                    GPIO_63_SD2_C4
#define GPIO_63_SD_D1                    GPIO_63_SD1_D1
#define GPIO_63_SPISIMOB                 GPIO_63_SPIB_SIMO

#define GPIO_64_EM1D20                   GPIO_64_EMIF1_D20
#define GPIO_64_EM2D4                    GPIO_64_EMIF2_D4
#define GPIO_64_EQEP3S                   GPIO_64_EQEP3_STROBE
#define GPIO_64_SCIRXDA                  GPIO_64_SCIA_RX
#define GPIO_64_SD_C1                    GPIO_64_SD1_C1
#define GPIO_64_SPISOMIB                 GPIO_64_SPIB_SOMI

#define GPIO_65_EM1D19                   GPIO_65_EMIF1_D19
#define GPIO_65_EM2D3                    GPIO_65_EMIF2_D3
#define GPIO_65_EQEP3I                   GPIO_65_EQEP3_INDEX
#define GPIO_65_SCITXDA                  GPIO_65_SCIA_TX
#define GPIO_65_SD_D2                    GPIO_65_SD1_D2
#define GPIO_65_SPICLKB                  GPIO_65_SPIB_CLK

#define GPIO_66_EM1D18                   GPIO_66_EMIF1_D18
#define GPIO_66_EM2D2                    GPIO_66_EMIF2_D2
#define GPIO_66_SDAB                     GPIO_66_I2CB_SDA
#define GPIO_66_SD_C2                    GPIO_66_SD1_C2
#define GPIO_66_SPISTEB                  GPIO_66_SPIB_STEN

#define GPIO_67_EM1D17                   GPIO_67_EMIF1_D17
#define GPIO_67_EM2D1                    GPIO_67_EMIF2_D1
#define GPIO_67_SD_D3                    GPIO_67_SD1_D3

#define GPIO_68_EM1D16                   GPIO_68_EMIF1_D16
#define GPIO_68_EM2D0                    GPIO_68_EMIF2_D0
#define GPIO_68_SD_C3                    GPIO_68_SD1_C3

#define GPIO_69_EM1D15                   GPIO_69_EMIF1_D15
#define GPIO_69_SCLB                     GPIO_69_I2CB_SCL
#define GPIO_69_SD_D4                    GPIO_69_SD1_D4
#define GPIO_69_SPISIMOC                 GPIO_69_SPIC_SIMO

#define GPIO_70_EM1D14                   GPIO_70_EMIF1_D14
#define GPIO_70_CANRXA                   GPIO_70_CANA_RX
#define GPIO_70_SCITXDB                  GPIO_70_SCIB_TX
#define GPIO_70_SD_C4                    GPIO_70_SD1_C4
#define GPIO_70_SPISOMIC                 GPIO_70_SPIC_SOMI

#define GPIO_71_EM1D13                   GPIO_71_EMIF1_D13
#define GPIO_71_CANTXA                   GPIO_71_CANA_TX
#define GPIO_71_SCIRXDB                  GPIO_71_SCIB_RX
#define GPIO_71_SPICLKC                  GPIO_71_SPIC_CLK

#define GPIO_72_EM1D12                   GPIO_72_EMIF1_D12
#define GPIO_72_CANTXB                   GPIO_72_CANB_TX
#define GPIO_72_SCITXDC                  GPIO_72_SCIC_TX
#define GPIO_72_SPISTEC                  GPIO_72_SPIC_STEN

#define GPIO_73_EM1D11                   GPIO_73_EMIF1_D11
#define GPIO_73_CANRXB                   GPIO_73_CANB_RX
#define GPIO_73_SCIRXDC                  GPIO_73_SCIC_RX
#define GPIO_73_SD_D6                    GPIO_73_SD2_D2

#define GPIO_74_EM1D10                   GPIO_74_EMIF1_D10
#define GPIO_74_SD_C6                    GPIO_74_SD2_C2

#define GPIO_75_EM1D9                    GPIO_75_EMIF1_D9
#define GPIO_75_SD_D7                    GPIO_75_SD2_D3

#define GPIO_76_EM1D8                    GPIO_76_EMIF1_D8
#define GPIO_76_SCITXDD                  GPIO_76_SCID_TX
#define GPIO_76_SD_C7                    GPIO_76_SD2_C3

#define GPIO_77_EM1D7                    GPIO_77_EMIF1_D7
#define GPIO_77_SCIRXDD                  GPIO_77_SCID_RX
#define GPIO_77_SD_D8                    GPIO_77_SD2_D4

#define GPIO_78_EM1D6                    GPIO_78_EMIF1_D6
#define GPIO_78_EQEP2A                   GPIO_78_EQEP2_A
#define GPIO_78_SD_C8                    GPIO_78_SD2_C4

#define GPIO_79_EM1D5                    GPIO_79_EMIF1_D5
#define GPIO_79_EQEP2B                   GPIO_79_EQEP2_B
#define GPIO_79_SD_D5                    GPIO_79_SD2_D1

#define GPIO_80_EM1D4                    GPIO_80_EMIF1_D4
#define GPIO_80_EQEP2S                   GPIO_80_EQEP2_STROBE
#define GPIO_80_SD_C5                    GPIO_80_SD2_C1

#define GPIO_81_EM1D3                    GPIO_81_EMIF1_D3
#define GPIO_81_EQEP2I                   GPIO_81_EQEP2_INDEX

#define GPIO_82_EM1D2                    GPIO_82_EMIF1_D2

#define GPIO_83_EM1D1                    GPIO_83_EMIF1_D1

#define GPIO_84_SCITXDA                  GPIO_84_SCIA_TX
#define GPIO_84_CMUARTTXA                GPIO_84_UARTA_TX

#define GPIO_85_EM1D0                    GPIO_85_EMIF1_D0
#define GPIO_85_SCIRXDA                  GPIO_85_SCIA_RX
#define GPIO_85_CMUARTRXA                GPIO_85_UARTA_RX

#define GPIO_86_EM1A13                   GPIO_86_EMIF1_A13
#define GPIO_86_EM1CAS                   GPIO_86_EMIF1_CAS
#define GPIO_86_SCITXDB                  GPIO_86_SCIB_TX

#define GPIO_87_EM1A14                   GPIO_87_EMIF1_A14
#define GPIO_87_EM1RAS                   GPIO_87_EMIF1_RAS
#define GPIO_87_SCIRXDB                  GPIO_87_SCIB_RX
#define GPIO_87_EM1DQM3                  GPIO_87_EMIF1_DQM3

#define GPIO_88_EM1A15                   GPIO_88_EMIF1_A15
#define GPIO_88_EM1DQM0                  GPIO_88_EMIF1_DQM0
#define GPIO_88_EM1DQM1                  GPIO_88_EMIF1_DQM1

#define GPIO_89_EM1A16                   GPIO_89_EMIF1_A16
#define GPIO_89_EM1DQM1                  GPIO_89_EMIF1_DQM1
#define GPIO_89_SCITXDC                  GPIO_89_SCIC_TX
#define GPIO_89_EM1CAS                   GPIO_89_EMIF1_CAS

#define GPIO_90_EM1A17                   GPIO_90_EMIF1_A17
#define GPIO_90_EM1DQM2                  GPIO_90_EMIF1_DQM2
#define GPIO_90_SCIRXDC                  GPIO_90_SCIC_RX
#define GPIO_90_EM1RAS                   GPIO_90_EMIF1_RAS

#define GPIO_91_EM1A18                   GPIO_91_EMIF1_A18
#define GPIO_91_EM1DQM3                  GPIO_91_EMIF1_DQM3
#define GPIO_91_SDAA                     GPIO_91_I2CA_SDA
#define GPIO_91_EM1DQM2                  GPIO_91_EMIF1_DQM2
#define GPIO_91_PMBCLK                   GPIO_91_PMBUSA_SCL
#define GPIO_91_FSIRXD0F                 GPIO_91_FSIRXF_D0
#define GPIO_91_SPISIMOD                 GPIO_91_SPID_SIMO

#define GPIO_92_EM1A19                   GPIO_92_EMIF1_A19
#define GPIO_92_EM1BA1                   GPIO_92_EMIF1_BA1
#define GPIO_92_SCLA                     GPIO_92_I2CA_SCL
#define GPIO_92_EM1DQM0                  GPIO_92_EMIF1_DQM0
#define GPIO_92_PMBDAT                   GPIO_92_PMBUSA_SDA
#define GPIO_92_FSIRXD1F                 GPIO_92_FSIRXF_D1
#define GPIO_92_SPISOMID                 GPIO_92_SPID_SOMI

#define GPIO_93_EM1BA0                   GPIO_93_EMIF1_BA0
#define GPIO_93_SCITXDD                  GPIO_93_SCID_TX
#define GPIO_93_PMBALERT                 GPIO_93_PMBUSA_ALERT
#define GPIO_93_FSIRXCLKF                GPIO_93_FSIRXF_CLK
#define GPIO_93_SPICLKD                  GPIO_93_SPID_CLK

#define GPIO_94_SCIRXDD                  GPIO_94_SCID_RX
#define GPIO_94_EM1BA1                   GPIO_94_EMIF1_BA1
#define GPIO_94_PMBCTRL                  GPIO_94_PMBUSA_CTL
#define GPIO_94_FSIRXD0G                 GPIO_94_FSIRXG_D0
#define GPIO_94_SPISTED                  GPIO_94_SPID_STEN

#define GPIO_95_EM2A12                   GPIO_95_EMIF2_A12
#define GPIO_95_FSIRXD1G                 GPIO_95_FSIRXG_D1

#define GPIO_96_EM2DQM1                  GPIO_96_EMIF2_DQM1
#define GPIO_96_EQEP1A                   GPIO_96_EQEP1_A
#define GPIO_96_FSIRXCLKG                GPIO_96_FSIRXG_CLK

#define GPIO_97_EM2DQM0                  GPIO_97_EMIF2_DQM0
#define GPIO_97_EQEP1B                   GPIO_97_EQEP1_B
#define GPIO_97_FSIRXD0H                 GPIO_97_FSIRXH_D0

#define GPIO_98_EM2A0                    GPIO_98_EMIF2_A0
#define GPIO_98_EQEP1S                   GPIO_98_EQEP1_STROBE
#define GPIO_98_FSIRXD1H                 GPIO_98_FSIRXH_D1

#define GPIO_99_EM2A1                    GPIO_99_EMIF2_A1
#define GPIO_99_EQEP1I                   GPIO_99_EQEP1_INDEX
#define GPIO_99_FSIRXCLKH                GPIO_99_FSIRXH_CLK

#define GPIO_100_EM2A2                    GPIO_100_EMIF2_A2
#define GPIO_100_EQEP2A                   GPIO_100_EQEP2_A
#define GPIO_100_SPISIMOC                 GPIO_100_SPIC_SIMO
#define GPIO_100_FSITXD0A                 GPIO_100_FSITXA_D0

#define GPIO_101_EM2A3                    GPIO_101_EMIF2_A3
#define GPIO_101_EQEP2B                   GPIO_101_EQEP2_B
#define GPIO_101_SPISOMIC                 GPIO_101_SPIC_SOMI
#define GPIO_101_FSITXD1A                 GPIO_101_FSITXA_D1

#define GPIO_102_EM2A4                    GPIO_102_EMIF2_A4
#define GPIO_102_EQEP2S                   GPIO_102_EQEP2_STROBE
#define GPIO_102_SPICLKC                  GPIO_102_SPIC_CLK
#define GPIO_102_FSITXCLKA                GPIO_102_FSITXA_CLK

#define GPIO_103_EM2A5                    GPIO_103_EMIF2_A5
#define GPIO_103_EQEP2I                   GPIO_103_EQEP2_INDEX
#define GPIO_103_SPISTEC                  GPIO_103_SPIC_STEN
#define GPIO_103_FSIRXD0A                 GPIO_103_FSIRXA_D0

#define GPIO_104_SDAA                     GPIO_104_I2CA_SDA
#define GPIO_104_EM2A6                    GPIO_104_EMIF2_A6
#define GPIO_104_EQEP3A                   GPIO_104_EQEP3_A
#define GPIO_104_SCITXDD                  GPIO_104_SCID_TX
#define GPIO_104_FSIRXD1A                 GPIO_104_FSIRXA_D1

#define GPIO_105_SCLA                     GPIO_105_I2CA_SCL
#define GPIO_105_EM2A7                    GPIO_105_EMIF2_A7
#define GPIO_105_EQEP3B                   GPIO_105_EQEP3_B
#define GPIO_105_SCIRXDD                  GPIO_105_SCID_RX
#define GPIO_105_FSIRXCLKA                GPIO_105_FSIRXA_CLK

#define GPIO_106_EM2A8                    GPIO_106_EMIF2_A8
#define GPIO_106_EQEP3S                   GPIO_106_EQEP3_STROBE
#define GPIO_106_SCITXDC                  GPIO_106_SCIC_TX
#define GPIO_106_FSITXD0B                 GPIO_106_FSITXB_D0

#define GPIO_107_EM2A9                    GPIO_107_EMIF2_A9
#define GPIO_107_EQEP3I                   GPIO_107_EQEP3_INDEX
#define GPIO_107_SCIRXDC                  GPIO_107_SCIC_RX
#define GPIO_107_FSITXD1B                 GPIO_107_FSITXB_D1

#define GPIO_108_EM2A10                   GPIO_108_EMIF2_A10
#define GPIO_108_FSITXCLKB                GPIO_108_FSITXB_CLK

#define GPIO_109_EM2A11                   GPIO_109_EMIF2_A11

#define GPIO_110_EM2WAIT0                 GPIO_110_EMIF2_WAIT
#define GPIO_110_FSIRXD0B                 GPIO_110_FSIRXB_D0

#define GPIO_111_EM2BA0                   GPIO_111_EMIF2_BA0
#define GPIO_111_FSIRXD1B                 GPIO_111_FSIRXB_D1

#define GPIO_112_EM2BA1                   GPIO_112_EMIF2_BA1
#define GPIO_112_FSIRXCLKB                GPIO_112_FSIRXB_CLK

#define GPIO_113_EM2CAS                   GPIO_113_EMIF2_CAS

#define GPIO_114_EM2RAS                   GPIO_114_EMIF2_RAS

#define GPIO_115_EM2CS0N                  GPIO_115_EMIF2_CS0N
#define GPIO_115_FSIRXD0C                 GPIO_115_FSIRXC_D0

#define GPIO_116_EM2CS2N                  GPIO_116_EMIF2_CS2N
#define GPIO_116_FSIRXD1C                 GPIO_116_FSIRXC_D1

#define GPIO_117_EM2SDCKE                 GPIO_117_EMIF2_SDCKE
#define GPIO_117_FSIRXCLKC                GPIO_117_FSIRXC_CLK

#define GPIO_118_EM2CLK                   GPIO_118_EMIF2_CLK
#define GPIO_118_FSIRXD0D                 GPIO_118_FSIRXD_D0

#define GPIO_119_EM2RNW                   GPIO_119_EMIF2_RNW
#define GPIO_119_FSIRXD1D                 GPIO_119_FSIRXD_D1

#define GPIO_120_EM2WEN                   GPIO_120_EMIF2_WEN
#define GPIO_120_FSIRXCLKD                GPIO_120_FSIRXD_CLK

#define GPIO_121_EM2OEN                   GPIO_121_EMIF2_OEN
#define GPIO_121_FSIRXD0E                 GPIO_121_FSIRXE_D0

#define GPIO_122_EM2D15                   GPIO_122_EMIF2_D15
#define GPIO_122_SPISIMOC                 GPIO_122_SPIC_SIMO
#define GPIO_122_SD_D1                    GPIO_122_SD1_D1

#define GPIO_123_EM2D14                   GPIO_123_EMIF2_D14
#define GPIO_123_SPISOMIC                 GPIO_123_SPIC_SOMI
#define GPIO_123_SD_C1                    GPIO_123_SD1_C1

#define GPIO_124_EM2D13                   GPIO_124_EMIF2_D13
#define GPIO_124_SPICLKC                  GPIO_124_SPIC_CLK
#define GPIO_124_SD_D2                    GPIO_124_SD1_D2

#define GPIO_125_EM2D12                   GPIO_125_EMIF2_D12
#define GPIO_125_SPISTEC                  GPIO_125_SPIC_STEN
#define GPIO_125_SD_C2                    GPIO_125_SD1_C2
#define GPIO_125_FSIRXD1E                 GPIO_125_FSIRXE_D1
#define GPIO_125_ECAT_LATCH0              GPIO_125_ESC_LATCH0

#define GPIO_126_EM2D11                   GPIO_126_EMIF2_D11
#define GPIO_126_SD_D3                    GPIO_126_SD1_D3
#define GPIO_126_FSIRXCLKE                GPIO_126_FSIRXE_CLK
#define GPIO_126_ECAT_LATCH1              GPIO_126_ESC_LATCH1

#define GPIO_127_EM2D10                   GPIO_127_EMIF2_D10
#define GPIO_127_SD_C3                    GPIO_127_SD1_C3
#define GPIO_127_ECAT_SYNC0               GPIO_127_ESC_SYNC0

#define GPIO_128_EM2D9                    GPIO_128_EMIF2_D9
#define GPIO_128_SD_D4                    GPIO_128_SD1_D4
#define GPIO_128_ECAT_SYNC1               GPIO_128_ESC_SYNC1

#define GPIO_129_EM2D8                    GPIO_129_EMIF2_D8
#define GPIO_129_SD_C4                    GPIO_129_SD1_C4
#define GPIO_129_ECAT_TX1_ENA             GPIO_129_ESC_TX1_ENA

#define GPIO_130_EM2D7                    GPIO_130_EMIF2_D7
#define GPIO_130_SD_D5                    GPIO_130_SD2_D1
#define GPIO_130_ECAT_TX1_CLK             GPIO_130_ESC_TX1_CLK

#define GPIO_131_EM2D6                    GPIO_131_EMIF2_D6
#define GPIO_131_SD_C5                    GPIO_131_SD2_C1
#define GPIO_131_ECAT_TX1_DATA0           GPIO_131_ESC_TX1_DATA0

#define GPIO_132_EM2D5                    GPIO_132_EMIF2_D5
#define GPIO_132_SD_D6                    GPIO_132_SD2_D2
#define GPIO_132_ECAT_TX1_DATA1           GPIO_132_ESC_TX1_DATA1

#define GPIO_133_SD_C6                    GPIO_133_SD2_C2

#define GPIO_134_EM2D4                    GPIO_134_EMIF2_D4
#define GPIO_134_SD_D7                    GPIO_134_SD2_D3
#define GPIO_134_ECAT_TX1_DATA2           GPIO_134_ESC_TX1_DATA2

#define GPIO_135_EM2D3                    GPIO_135_EMIF2_D3
#define GPIO_135_SCITXDA                  GPIO_135_SCIA_TX
#define GPIO_135_SD_C7                    GPIO_135_SD2_C3
#define GPIO_135_ECAT_TX1_DATA3           GPIO_135_ESC_TX1_DATA3

#define GPIO_136_EM2D2                    GPIO_136_EMIF2_D2
#define GPIO_136_SCIRXDA                  GPIO_136_SCIA_RX
#define GPIO_136_SD_D8                    GPIO_136_SD2_D4
#define GPIO_136_ECAT_RX1_DV              GPIO_136_ESC_RX1_DV

#define GPIO_137_EM2D1                    GPIO_137_EMIF2_D1
#define GPIO_137_SCITXDB                  GPIO_137_SCIB_TX
#define GPIO_137_SD_C8                    GPIO_137_SD2_C4
#define GPIO_137_ECAT_RX1_CLK             GPIO_137_ESC_RX1_CLK

#define GPIO_138_EM2D0                    GPIO_138_EMIF2_D0
#define GPIO_138_SCIRXDB                  GPIO_138_SCIB_RX
#define GPIO_138_ECAT_RX1_ERR             GPIO_138_ESC_RX1_ERR

#define GPIO_139_SCIRXDC                  GPIO_139_SCIC_RX
#define GPIO_139_ECAT_RX1_DATA0           GPIO_139_ESC_RX1_DATA0

#define GPIO_140_SCITXDC                  GPIO_140_SCIC_TX
#define GPIO_140_ECAT_RX1_DATA1           GPIO_140_ESC_RX1_DATA1

#define GPIO_141_SCIRXDD                  GPIO_141_SCID_RX
#define GPIO_141_ECAT_RX1_DATA2           GPIO_141_ESC_RX1_DATA2

#define GPIO_142_SCITXDD                  GPIO_142_SCID_TX
#define GPIO_142_ECAT_RX1_DATA3           GPIO_142_ESC_RX1_DATA3

#define GPIO_143_ECAT_LED_LINK0_ACTIVE    GPIO_143_ESC_LED_LINK0_ACTIVE

#define GPIO_144_ECAT_LED_LINK1_ACTIVE    GPIO_144_ESC_LED_LINK1_ACTIVE

#define GPIO_148_ECAT_PHY0_LINKSTATUS     GPIO_148_ESC_PHY0_LINKSTATUS

#define GPIO_149_ECAT_PHY1_LINKSTATUS     GPIO_149_ESC_PHY1_LINKSTATUS

#define GPIO_150_ECAT_I2C_SDA             GPIO_150_ESC_I2C_SDA

#define GPIO_151_ECAT_I2C_SCL             GPIO_151_ESC_I2C_SCL

#define GPIO_152_ECAT_MDIO_CLK            GPIO_152_ESC_MDIO_CLK

#define GPIO_153_ECAT_MDIO_DATA           GPIO_153_ESC_MDIO_DATA

#define GPIO_154_ECAT_PHY_CLK             GPIO_154_ESC_PHY_CLK

#define GPIO_155_ECAT_PHY_RESETN          GPIO_155_ESC_PHY_RESETN

#define GPIO_156_ECAT_TX0_ENA             GPIO_156_ESC_TX0_ENA

#define GPIO_157_ECAT_TX0_CLK             GPIO_157_ESC_TX0_CLK

#define GPIO_158_ECAT_TX0_DATA0           GPIO_158_ESC_TX0_DATA0

#define GPIO_159_ECAT_TX0_DATA1           GPIO_159_ESC_TX0_DATA1

#define GPIO_160_ECAT_TX0_DATA2           GPIO_160_ESC_TX0_DATA2

#define GPIO_161_ECAT_TX0_DATA3           GPIO_161_ESC_TX0_DATA3

#define GPIO_162_ECAT_RX0_DV              GPIO_162_ESC_RX0_DV

#define GPIO_163_ECAT_RX0_CLK             GPIO_163_ESC_RX0_CLK

#define GPIO_164_ECAT_RX0_ERR             GPIO_164_ESC_RX0_ERR

#define GPIO_165_ECAT_RX0_DATA0           GPIO_165_ESC_RX0_DATA0

#define GPIO_166_ECAT_RX0_DATA1           GPIO_166_ESC_RX0_DATA1

#define GPIO_167_ECAT_RX0_DATA2           GPIO_167_ESC_RX0_DATA2

#define GPIO_168_ECAT_RX0_DATA3           GPIO_168_ESC_RX0_DATA3

#endif // __PIN_MAP_H__                                                        
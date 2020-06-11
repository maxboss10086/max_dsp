//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.h
// Descriptions:    
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//



#ifndef PERIPHERALS_INTERRUPT_USER_INTERRUPT_H_
#define PERIPHERALS_INTERRUPT_USER_INTERRUPT_H_



//define
extern uint16_t sci_rDataA[2];
extern uint16_t sci_sDataA[2];
extern uint16_t spia_sData[2];
extern uint16_t spia_rData[2];
extern uint16_t spib_sData[2];
extern uint16_t spib_rData[2];
extern uint16_t spi_i;
//function
//中断使能设置
void interrupt_init_set(void);
//void scl_interrupt_set(void);
//void spia_tx_interrupt_set(void);
//void spia_rx_interrupt_set(void);
//void spib_tx_interrupt_set(void);
//void epwm1_interrupt_set(void);
//void clb1_interrupt_set(void);
//void dma_interrupt_set(void);


//中断服务函数
__interrupt void sciaTXFIFOISR(void);
__interrupt void sciaRXFIFOISR(void);
interrupt void xint1ISR(void);
interrupt void xint2ISR(void);
__interrupt void spiaTxFIFOISR(void);
__interrupt void spiaRxFIFOISR(void);
__interrupt void spibTxFIFOISR(void);
__interrupt void spibRxFIFOISR(void);
__interrupt void epwm1ISR(void);
//__interrupt void clb1ISR(void);
__interrupt void dmaCh5ISR(void);
__interrupt void dmaCh6ISR(void);




#endif /* PERIPHERALS_INTERRUPT_USER_INTERRUPT_H_ */

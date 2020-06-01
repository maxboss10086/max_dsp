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
extern uint16_t sci_sDataA[2];
extern uint16_t sci_rDataA[2];


//function
void interrupt_init_set(void);//系统中断设置
void scl_interrupt_set(void);//sci中断设置

__interrupt void sciaTXFIFOISR(void);
__interrupt void sciaRXFIFOISR(void);

interrupt void xint1ISR(void);
interrupt void xint2ISR(void);



#endif /* PERIPHERALS_INTERRUPT_USER_INTERRUPT_H_ */

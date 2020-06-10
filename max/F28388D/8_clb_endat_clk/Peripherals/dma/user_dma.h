/*
 * user_dma.h
 *
 *  Created on: 2020��6��10��
 *      Author: 57315
 */

#ifndef PERIPHERALS_DMA_USER_DMA_H_
#define PERIPHERALS_DMA_USER_DMA_H_


#define FIFO_LVL    8               // FIFO interrupt level
#define BURST       FIFO_LVL        // Each burst will empty the FIFO     ÿ��ͻ�� ��������FIFO
#define TRANSFER    16              // It will take 16 bursts of 8 to transfer
                                    // all data in rData


void initDMA(void);



#endif /* PERIPHERALS_DMA_USER_DMA_H_ */

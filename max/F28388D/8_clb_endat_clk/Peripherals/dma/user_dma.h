/*
 * user_dma.h
 *
 *  Created on: 2020年6月10日
 *      Author: 57315
 */

#ifndef PERIPHERALS_DMA_USER_DMA_H_
#define PERIPHERALS_DMA_USER_DMA_H_


#define FIFO_LVL    8               // FIFO interrupt level
#define BURST       FIFO_LVL        // Each burst will empty the FIFO     每次突发 传输会清空FIFO
#define TRANSFER    16              // It will take 16 bursts of 8 to transfer
                                    // all data in rData


void initDMA(void);



#endif /* PERIPHERALS_DMA_USER_DMA_H_ */

/*
 * user_dma.h
 *
 *  Created on: 2020Äê6ÔÂ10ÈÕ
 *      Author: 57315
 */

#ifndef PERIPHERALS_DMA_USER_DMA_H_
#define PERIPHERALS_DMA_USER_DMA_H_

#define dma_5           SPIB_BASE
#define dma_6           SPIB_BASE
#define dma_5_TRIGGER   DMA_TRIGGER_SPIBTX
#define dma_6_TRIGGER   DMA_TRIGGER_SPIBRX
void initDMA(void);



#endif /* PERIPHERALS_DMA_USER_DMA_H_ */

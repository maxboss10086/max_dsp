//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.h
// Descriptions:    将spi的数组送入FIFO或从FIFO中读取数据送入数组
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"

#include "user_dma.h"


void initDMA()
{
    //
    // Initialize DMA
    //
    DMA_initController();
    dma_interrupt_set();
    //
    // Configure DMA Ch5 for TX. When there is enough space in the FIFO, data
    // will be transferred from the sData buffer to the SPI module's transmit
    // buffer register.
    //DMA通道5将Sdata送入发送FIFO
    DMA_configAddresses(DMA_CH5_BASE, (uint16_t *)(SPIA_BASE + SPI_O_TXBUF),
                        spib_sData);
    DMA_configBurst(DMA_CH5_BASE, BURST, 1, 0);
    DMA_configTransfer(DMA_CH5_BASE, TRANSFER, 1, 0);

    // Configure DMA Ch6 for RX. When the FIFO contains at least 8 words to
    // read, data will be transferred from the SPI module's receive buffer
    // register to the rData buffer.
    //当接收FIFO至少有8个字节时，DMA将数据从FIFO搬入全局变量
    DMA_configAddresses(DMA_CH6_BASE, spib_rData,
                        (uint16_t *)(SPIA_BASE + SPI_O_RXBUF));
    //BURST==8
    DMA_configBurst(DMA_CH6_BASE, BURST, 0, 1);
    DMA_configTransfer(DMA_CH6_BASE, TRANSFER, 0, 1);


}

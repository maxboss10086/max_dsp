//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_interrupt.h
// Descriptions:    ��spi����������FIFO���FIFO�ж�ȡ������������
// Author:          Max
// Creation Date:   2020��5��24��
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
    //DMAͨ��5��Sdata���뷢��FIFO
    DMA_configAddresses(DMA_CH5_BASE, (uint16_t *)(SPIA_BASE + SPI_O_TXBUF),
                        spib_sData);
    DMA_configBurst(DMA_CH5_BASE, BURST, 1, 0);
    DMA_configTransfer(DMA_CH5_BASE, TRANSFER, 1, 0);

    // Configure DMA Ch6 for RX. When the FIFO contains at least 8 words to
    // read, data will be transferred from the SPI module's receive buffer
    // register to the rData buffer.
    //������FIFO������8���ֽ�ʱ��DMA�����ݴ�FIFO����ȫ�ֱ���
    DMA_configAddresses(DMA_CH6_BASE, spib_rData,
                        (uint16_t *)(SPIA_BASE + SPI_O_RXBUF));
    //BURST==8
    DMA_configBurst(DMA_CH6_BASE, BURST, 0, 1);
    DMA_configTransfer(DMA_CH6_BASE, TRANSFER, 0, 1);


}

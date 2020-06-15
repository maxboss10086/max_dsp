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
//note:1spi�ķ���FIFO�źŲ��ٴ���SPI�жϣ����Ǵ���DMA�ж�
//     2dma������sdram����������FIFO�����Ϲ����ο�����ԭ��SDRAM������
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"

#include "user_dma.h"
#include "user_spi.h"

#define BURST       FIFO_LVL        // Each burst will empty the FIFO     ÿ��ͻ�� ��������FIFO
#define TRANSFER    16              // It will take 16 bursts of 8 to transfer
                                    // all data in rData


void dma_5_interrupt_en(){
    Interrupt_register(INT_DMA_CH5, &dmaCh5ISR);
    Interrupt_enable(INT_DMA_CH5);
}

void dma_6_interrupt_en(){
    Interrupt_register(INT_DMA_CH6, &dmaCh6ISR);
    Interrupt_enable(INT_DMA_CH6);
}

void init_dma_5(){
    dma_5_interrupt_en();
    // Configure DMA Ch5 for TX. When there is enough space in the FIFO, data
    // will be transferred from the sData buffer to the SPI module's transmit
    // buffer register.
    //DMAͨ��5��Sdata���뷢��FIFO
    DMA_configAddresses(DMA_CH5_BASE, (uint16_t *)(dma_5 + SPI_O_TXBUF),spia_sData);
    DMA_configBurst(DMA_CH5_BASE, BURST, 1, 0);//ͻ���������Ϊ8,�û��˼�����û�дﵽ8���ܲ������ͻ��
    DMA_configTransfer(DMA_CH5_BASE, TRANSFER, 1, 0);//TRANSFER=16������λ��16λ
    //DMAͨ��5����ģʽ��SPIb�Ľ���FIFO����DMA��ÿ�δ���ͻ��һ�Σ��������ͨ���رգ��������ݴ�С16λ
    DMA_configMode(DMA_CH5_BASE, DMA_TRIGGER_SPIATX, DMA_CFG_ONESHOT_DISABLE |
                   DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    // Configure DMA Ch5 interrupts
    DMA_setInterruptMode(DMA_CH5_BASE, DMA_INT_AT_END);
    DMA_enableInterrupt(DMA_CH5_BASE);//������ϣ���DMAֹͣ
    DMA_enableTrigger(DMA_CH5_BASE);

//    DMA_startChannel(DMA_CH5_BASE);
}

void init_dma_6(){
   dma_6_interrupt_en();
    // Configure DMA Ch6 for RX. When the FIFO contains at least 8 words to
    // read, data will be transferred from the SPI module's receive buffer
    // register to the rData buffer.
    //������FIFO�����趨�����ʱ��DMA�����ݴ�FIFO�����û���(����)
    DMA_configAddresses(DMA_CH6_BASE, spib_rData,(uint16_t *)(dma_6 + SPI_O_RXBUF));
    DMA_configBurst(DMA_CH6_BASE, BURST, 0, 1);//ͻ���������ΪFIFO����ȣ�ͻ��һ�Σ�����FIFO
    DMA_configTransfer(DMA_CH6_BASE, TRANSFER, 0, 1);//TRANSFER=16������λ��16λ
    //DMAͨ��6����ģʽ��SPIb����FIFO����DMA��ÿ�δ���ͻ��һ�Σ��������ͨ���رգ��������ݴ�С16λ
    DMA_configMode(DMA_CH6_BASE, DMA_TRIGGER_SPIBRX, DMA_CFG_ONESHOT_DISABLE |
                   DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    //������ϴ���DMA�ж�
    DMA_setInterruptMode(DMA_CH6_BASE, DMA_INT_AT_END);
    //����DMA�жϽ���У�����
    DMA_enableInterrupt(DMA_CH6_BASE);
    DMA_enableTrigger(DMA_CH6_BASE);

//    DMA_startChannel(DMA_CH6_BASE);
}

void initDMA(){
    DMA_initController();
    init_dma_5();
    init_dma_6();

}

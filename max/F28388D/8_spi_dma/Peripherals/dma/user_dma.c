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
//note:1spi的发送FIFO信号不再触发SPI中断，而是触发DMA中断
//     2dma，就是sdram控制器，与FIFO的联合工作参考正点原子SDRAM控制器
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"

#include "user_dma.h"
#include "user_spi.h"

#define BURST       FIFO_LVL        // Each burst will empty the FIFO     每次突发 传输会清空FIFO
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
    //DMA通道5将Sdata送入发送FIFO
    DMA_configAddresses(DMA_CH5_BASE, (uint16_t *)(dma_5 + SPI_O_TXBUF),spia_sData);
    DMA_configBurst(DMA_CH5_BASE, BURST, 1, 0);//突发传输深度为8,用户端即数组没有达到8可能不会进行突发
    DMA_configTransfer(DMA_CH5_BASE, TRANSFER, 1, 0);//TRANSFER=16，数据位宽16位
    //DMA通道5传输模式，SPIb的接收FIFO触发DMA，每次触发突发一次，传输结束通道关闭，传输数据大小16位
    DMA_configMode(DMA_CH5_BASE, DMA_TRIGGER_SPIATX, DMA_CFG_ONESHOT_DISABLE |
                   DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    // Configure DMA Ch5 interrupts
    DMA_setInterruptMode(DMA_CH5_BASE, DMA_INT_AT_END);
    DMA_enableInterrupt(DMA_CH5_BASE);//传输完毕，令DMA停止
    DMA_enableTrigger(DMA_CH5_BASE);

//    DMA_startChannel(DMA_CH5_BASE);
}

void init_dma_6(){
   dma_6_interrupt_en();
    // Configure DMA Ch6 for RX. When the FIFO contains at least 8 words to
    // read, data will be transferred from the SPI module's receive buffer
    // register to the rData buffer.
    //当接收FIFO等于设定的深度时，DMA将数据从FIFO搬入用户端(数组)
    DMA_configAddresses(DMA_CH6_BASE, spib_rData,(uint16_t *)(dma_6 + SPI_O_RXBUF));
    DMA_configBurst(DMA_CH6_BASE, BURST, 0, 1);//突发传输深度为FIFO的深度，突发一次，读空FIFO
    DMA_configTransfer(DMA_CH6_BASE, TRANSFER, 0, 1);//TRANSFER=16，数据位宽16位
    //DMA通道6传输模式，SPIb接收FIFO触发DMA，每次触发突发一次，传输结束通道关闭，传输数据大小16位
    DMA_configMode(DMA_CH6_BASE, DMA_TRIGGER_SPIBRX, DMA_CFG_ONESHOT_DISABLE |
                   DMA_CFG_CONTINUOUS_ENABLE | DMA_CFG_SIZE_16BIT);
    //传输完毕触发DMA中断
    DMA_setInterruptMode(DMA_CH6_BASE, DMA_INT_AT_END);
    //触发DMA中断进入校验程序
    DMA_enableInterrupt(DMA_CH6_BASE);
    DMA_enableTrigger(DMA_CH6_BASE);

//    DMA_startChannel(DMA_CH6_BASE);
}

void initDMA(){
    DMA_initController();
    init_dma_5();
    init_dma_6();

}

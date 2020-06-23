//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        spi.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020年5月26日
//----------------------------------------------------------------------------------------//
//SPI中断就是令SPI停止传输数据

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"

#include "user_spi.h"

uint16_t sci_rDataA[2];//定义函数在这里，h文件只是用extern把定义的函数发送出去
uint16_t sci_sDataA[2];
uint16_t spia_sData[2];
uint16_t spia_rData[2];
uint16_t spib_sData[4];//深度+1
uint16_t spib_rData[4];
uint16_t spi_i;
// Place buffers in GSRAM
//给DMA分配sdram，否则DMA无法正确传输
#pragma DATA_SECTION(spib_sData, "ramgs0");
#pragma DATA_SECTION(spib_rData, "ramgs1");


//******************SPI中断使能************************
//使能spia发送中断
void spia_tx_interrupt_en(void){
    Interrupt_register(INT_SPIA_TX, &spiaTxFIFOISR);
    Interrupt_enable(INT_SPIA_TX);
    SPI_enableInterrupt(SPIA_BASE, SPI_INT_TXFF);

}
////使能spia接收中断
//void spia_rx_interrupt_en(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_RXFF);
//
//}
//使能spib发送中断
void spib_tx_interrupt_en(void){
    Interrupt_register(INT_SPIB_TX, &spibTxFIFOISR);
    Interrupt_enable(INT_SPIB_TX);//SPI的FIFO触发SPI中断
//    SPI_enableInterrupt(SPIB_BASE, SPI_INT_TXFF);
}
//spib接收中断使能
void spib_rx_interrupt_en(void){
    Interrupt_register(INT_SPIB_RX, &spibRxFIFOISR);
    Interrupt_enable(INT_SPIB_RX);
    SPI_enableInterrupt(SPIB_BASE, SPI_INT_RXFF);
}



void SPIa_init_set(void)
{
    spia_tx_interrupt_en();
//    spia_rx_interrupt_en();
    // GPIO17 is the SPISOMIA.
    GPIO_setMasterCore(spi_a_miso_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_17_SPISOMIA);
    GPIO_setPadConfig(spi_a_miso_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_a_miso_gpio, GPIO_QUAL_ASYNC);
    // GPIO16 is the SPISIMOA clock pin.
    GPIO_setMasterCore(spi_a_mosi_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_16_SPISIMOA);
    GPIO_setPadConfig(spi_a_mosi_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_a_mosi_gpio, GPIO_QUAL_ASYNC);
    // GPIO19 is the SPISTEA.
    GPIO_setMasterCore(spi_a_csn_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_19_SPISTEA);
    GPIO_setPadConfig(spi_a_csn_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_a_csn_gpio, GPIO_QUAL_ASYNC);
    // GPIO18 is the SPICLKA.
    GPIO_setMasterCore(spi_a_clk_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_18_SPICLKA);
    GPIO_setPadConfig(spi_a_clk_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_a_clk_gpio, GPIO_QUAL_ASYNC);

    // Must put SPI into reset before configuring it
    SPI_disableModule(SPIA_BASE);
    // SPI configuration. Use a 5MHz SPICLK and 16-bit word size.
    SPI_setConfig(SPIA_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
                  SPI_MODE_MASTER, 5000000, 16);
    SPI_disableLoopback(SPIA_BASE);
    SPI_setEmulationMode(SPIA_BASE, SPI_EMULATION_STOP_AFTER_TRANSMIT);
    SPI_resetTxFIFO(SPIA_BASE);
// FIFO and interrupt configuration
    SPI_enableFIFO(SPIA_BASE);
    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_RXFF | SPI_INT_TXFF);//清除SPI中断FIFO设置
    //设置触发SPI中断的FIFO深度
    SPI_setFIFOInterruptLevel(SPIB_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
    //设置触发DMA的FIFO深度
//    SPI_setFIFOInterruptLevel(SPIB_BASE, (SPI_TxFIFOLevel)FIFO_LVL,(SPI_RxFIFOLevel)FIFO_LVL);
    // Configuration complete. Enable the module.
    SPI_enableModule(SPIA_BASE);
}

void init_SPI_enableLoopback(SPI_PORT spiPort)
{
    uint32_t p = (uint32_t)spiPort;
    //
    // Must put SPI into reset before configuring it
    //
    SPI_disableModule(p);

    // FIFO configuratio
    SPI_enableFIFO(p);
    SPI_clearInterruptStatus(p, SPI_INT_RXFF | SPI_INT_TXFF);
    SPI_setFIFOInterruptLevel(p, (SPI_TxFIFOLevel)FIFO_LVL,
                             (SPI_RxFIFOLevel)FIFO_LVL);


    //
    // SPI configuration. Use a 5mHz SPICLK and 16-bit word size.
    //
    SPI_setConfig(p, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
                  SPI_MODE_MASTER, 5000000, 16);
    SPI_enableLoopback(p);
    SPI_enableModule(p);
}

// SPIa发送一帧数据
void spia_send_data( uint16_t data){
    SPI_writeDataNonBlocking(SPIA_BASE, data);
}

// SPIa接收一帧数据
uint16_t spia_receive_data(){
    return SPI_readDataBlockingNonFIFO(SPIA_BASE);
}


//
void SPIb_init_set(void)
{
    spib_tx_interrupt_en();
    spib_rx_interrupt_en();
    // GPIO64 is the SPISOMIB.
    GPIO_setMasterCore(64, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_64_SPISOMIB);
    GPIO_setPadConfig(64, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(64, GPIO_QUAL_ASYNC);
    // GPIO63 is the SPISIMOB clock pin.
    GPIO_setMasterCore(63, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_63_SPISIMOB);
    GPIO_setPadConfig(63, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(63, GPIO_QUAL_ASYNC);
    // GPIO66 is the SPISTEB.
    GPIO_setMasterCore(66, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_66_SPISTEB);
    GPIO_setPadConfig(66, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(66, GPIO_QUAL_ASYNC);
    // GPIO65 is the SPICLKB.
    GPIO_setMasterCore(65, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_65_SPICLKB);
    GPIO_setPadConfig(65, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(65, GPIO_QUAL_ASYNC);

    // Must put SPI into reset before configuring it
    SPI_disableModule(SPIB_BASE);
    // SPI configuration. Use a 5MHz SPICLK and 16-bit word size.
    SPI_setConfig(SPIB_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
                  SPI_MODE_SLAVE, 5000000, 16);//移位寄存器设置
    SPI_disableLoopback(SPIB_BASE);
    SPI_setEmulationMode(SPIB_BASE, SPI_EMULATION_STOP_AFTER_TRANSMIT);
//FIFO设置
    // 使能FIFO以及用FIFO产生中断触发信号，可以用来触发SPI中断，也可以触发DMA
    SPI_enableFIFO(SPIB_BASE);
    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF | SPI_INT_TXFF);//清除之前的SPI中断FIFO设置
    //设置触发SPI中断的FIFO深度
    //SPI_FIFO_TX2表示FIFO中小于2时填入数据
    //SPI_FIFO_TXEMPTY表示FIFO为空时填入数据
    SPI_setFIFOInterruptLevel(SPIB_BASE, SPI_FIFO_TXEMPTY, SPI_FIFO_RX3);
    //设置触发DMA的FIFO深度
//    SPI_setFIFOInterruptLevel(SPIB_BASE, (SPI_TxFIFOLevel)FIFO_LVL,(SPI_RxFIFOLevel)FIFO_LVL);

    // Configuration complete. Enable the module.
    SPI_enableModule(SPIB_BASE);

}
// SPIa接收一帧数据
uint16_t spib_receive_data(){
    return SPI_readDataBlockingNonFIFO(SPIB_BASE);
}

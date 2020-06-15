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


//******************SPI中断使能************************
////使能spia发送中断
//void spia_tx_interrupt_set(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_TXFF);
//    SPI_setFIFOInterruptLevel(SPIA_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_TXFF);
//
//}
////使能spia接收中断
//void spia_rx_interrupt_set(void){
//    Interrupt_register(INT_SPIA_RX, &spiaRxFIFOISR);
//    Interrupt_enable(INT_SPIA_RX);
//    SPI_clearInterruptStatus(SPIA_BASE, SPI_INT_RXFF);
//    SPI_setFIFOInterruptLevel(SPIA_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIA_BASE, SPI_INT_RXFF);
//
//}
////使能spib发送中断
//void spib_tx_interrupt_set(void){
//    Interrupt_register(INT_SPIB_TX, &spibTxFIFOISR);
//    Interrupt_enable(INT_SPIB_TX);//SPI的FIFO触发SPI中断
//    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_TXFF);
//    SPI_setFIFOInterruptLevel(SPIB_BASE, SPI_FIFO_TX2, SPI_FIFO_RX2);
//    SPI_enableInterrupt(SPIB_BASE, SPI_INT_TXFF);
//}
//使能spib接收中断
//void spib_rx_interrupt_set(void){
//    Interrupt_register(INT_SPIB_RX, &spibRxFIFOISR);
//    Interrupt_enable(INT_SPIB_RX);
//    SPI_enableInterrupt(SPIB_BASE, SPI_INT_RXFF);
//}


                    //SPIA设定为主机
                    //设置SPI时钟为5M，时钟个数是16个
                    //时钟默认低电平，下降沿接收数据
                    //GPIO19是cs_n,GPIO18是scl,GPIO16是mosi,GPIO17是miso
                    //
void SPIa_init_set(void)
{
//    spia_tx_interrupt_set();
//    spia_rx_interrupt_set();
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
    //SPI_disableLoopback(SPIA_BASE);
    SPI_setEmulationMode(SPIA_BASE, SPI_EMULATION_FREE_RUN);
    SPI_resetTxFIFO(SPIA_BASE);
    // FIFO and interrupt configuration
    SPI_enableFIFO(SPIA_BASE);
    // Configuration complete. Enable the module.
    SPI_enableModule(SPIA_BASE);
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
// Function to configure SPI B as slave with FIFO enabled.
//
void SPIb_init_set(void)
{
//    spib_tx_interrupt_set();
//    spib_rx_interrupt_set();
    // GPIO25 is the SPISOMIB.
    GPIO_setMasterCore(64, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_64_SPISOMIB);
    GPIO_setPadConfig(64, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(64, GPIO_QUAL_ASYNC);
    // GPIO24 is the SPISIMOB clock pin.
    GPIO_setMasterCore(63, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_63_SPISIMOB);
    GPIO_setPadConfig(63, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(63, GPIO_QUAL_ASYNC);
    // GPIO27 is the SPISTEB.
    GPIO_setMasterCore(66, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_66_SPISTEB);
    GPIO_setPadConfig(66, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(66, GPIO_QUAL_ASYNC);
    // GPIO26 is the SPICLKB.
    GPIO_setMasterCore(65, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_65_SPICLKB);
    GPIO_setPadConfig(65, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(65, GPIO_QUAL_ASYNC);

    // Must put SPI into reset before configuring it
    SPI_disableModule(SPIB_BASE);
    // SPI configuration. Use a 5MHz SPICLK and 16-bit word size.
    SPI_setConfig(SPIB_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
                  SPI_MODE_SLAVE, 5000000, 16);
    SPI_disableLoopback(SPIB_BASE);
    SPI_setEmulationMode(SPIB_BASE, SPI_EMULATION_FREE_RUN);
//FIFO设置
    // 使能FIFO以及用FIFO产生中断触发信号，可以用来触发SPI中断，也可以触发DMA
    SPI_enableFIFO(SPIB_BASE);
    SPI_clearInterruptStatus(SPIB_BASE, SPI_INT_RXFF | SPI_INT_TXFF);//清除SPI中断FIFO设置
    //设置触发DMA的FIFO深度
    SPI_setFIFOInterruptLevel(SPIB_BASE, (SPI_TxFIFOLevel)FIFO_LVL,(SPI_RxFIFOLevel)FIFO_LVL);

    // Configuration complete. Enable the module.
    SPI_enableModule(SPIB_BASE);

}
// SPIa接收一帧数据
uint16_t spib_receive_data(){
    return SPI_readDataBlockingNonFIFO(SPIB_BASE);
}

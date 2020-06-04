//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        spi.c
// Descriptions:    
// Author:          Max
// Creation Date:   2020��5��26��
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//

#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"

#include "user_spi.h"


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
    // SPI configuration. Use a 500kHz SPICLK and 16-bit word size.
    SPI_setConfig(SPIA_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
                  SPI_MODE_MASTER, 500000, 16);
    //SPI_disableLoopback(SPIA_BASE);
    SPI_setEmulationMode(SPIA_BASE, SPI_EMULATION_FREE_RUN);
    SPI_resetTxFIFO(SPIA_BASE);
    // FIFO and interrupt configuration
    SPI_enableFIFO(SPIA_BASE);
    // Configuration complete. Enable the module.
    SPI_enableModule(SPIA_BASE);
}

// SPIa����һ֡����
void spia_send_data( uint16_t data){
    SPI_writeDataNonBlocking(SPIA_BASE, data);
}

// SPIa����һ֡����
uint16_t spia_receive_data(){
    return SPI_readDataBlockingNonFIFO(SPIA_BASE);
}

//SPIB�趨Ϊ�ӻ�
//����SPIʱ��Ϊ1M��ʱ�Ӹ�����16��
//ʱ��Ĭ�ϵ͵�ƽ���½��ؽ�������
//GPIO66��cs_n��GPIO65��scl��GPIO63��mosi,GPIO64��miso
void SPIb_init_set(void)
{
//    spib_tx_interrupt_set();
    spib_rx_interrupt_set();
    // SPISTEB.
    GPIO_setMasterCore(spi_b_csn_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_66_SPISTEB);//���Ÿ���ΪSPIB��cs_n
    GPIO_setPadConfig(spi_b_csn_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_b_csn_gpio, GPIO_QUAL_ASYNC);
    // SPICLKB.
    GPIO_setMasterCore(spi_b_clk_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_65_SPICLKB);
    GPIO_setPadConfig(spi_b_clk_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_b_clk_gpio, GPIO_QUAL_ASYNC);
    //  SPISIMOB
    GPIO_setMasterCore(spi_b_mosi_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_63_SPISIMOB);
    GPIO_setPadConfig(spi_b_mosi_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_b_mosi_gpio, GPIO_QUAL_ASYNC);
    // SPISOMIB.
    GPIO_setMasterCore(spi_b_miso_gpio, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_64_SPISOMIB);
    GPIO_setPadConfig(spi_b_miso_gpio, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(spi_b_miso_gpio, GPIO_QUAL_ASYNC);




    // Must put SPI into reset before configuring it
    SPI_disableModule(SPIB_BASE);
    // SPI configuration. Use a 1MHz SPICLK and 16-bit word size.
    SPI_setConfig(SPIB_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
                  SPI_MODE_SLAVE, 1000000, 16);
    SPI_disableLoopback(SPIB_BASE);
    SPI_setEmulationMode(SPIB_BASE, SPI_EMULATION_FREE_RUN);
    // FIFO and interrupt configuration
    SPI_enableFIFO(SPIB_BASE);
    // Configuration complete. Enable the module.
    SPI_enableModule(SPIB_BASE);

}

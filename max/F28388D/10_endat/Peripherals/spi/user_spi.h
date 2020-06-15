//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        spi.h
// Descriptions:    
// Author:          Max
// Creation Date:   2020年5月26日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//***************************************include******************************************//



#ifndef PERIPHERALS_SPI_USER_SPI_H_
#define PERIPHERALS_SPI_USER_SPI_H_



#define FIFO_LVL    8               // FIFO interrupt level
extern uint16_t sci_rDataA[2];
extern uint16_t sci_sDataA[2];
extern uint16_t spia_sData[2];
extern uint16_t spia_rData[8];
extern uint16_t spib_sData[2];
extern uint16_t spib_rData[2];
extern uint16_t spi_i;
//define
#define spi_a               SPIA_BASE;
#define spi_b               SPIB_BASE;
#define spi_c               SPIC_BASE;
#define spi_d               SPID_BASE;

#define spi_a_csn_gpio      19
#define spi_a_clk_gpio      18
#define spi_a_mosi_gpio     16
#define spi_a_miso_gpio     17

typedef enum SPI_PORT{
    SPIA = 0x00006100U,
    SPIB = 0x00006110U,
    SPIC = 0x00006120U,
    SPID = 0x00006100U
}SPI_PORT;
//F28388Dspi

#define spi_b_csn_gpio       66  //27
#define spi_b_clk_gpio       65   //26
#define spi_b_mosi_gpio      63   //24
#define spi_b_miso_gpio      64   //25


//function
void                        SPIa_init_set(void);
void                        spia_send_data( uint16_t data);
uint16_t                    spia_receive_data(void);
void                        SPIa_init_set(void);
void                        SPIb_init_set(void);
uint16_t                    spib_receive_data(void);
void                        init_SPI_enableLoopback(SPI_PORT spiPort);

#endif /* PERIPHERALS_SPI_USER_SPI_H_ */


// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "user_spi.h"
#include "user_interrupt.h"
#include "user_dma.h"


//
// Main
//
void main(void)
{
    uint16_t i;

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pullups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    //
    // Interrupts that are used in this example are re-mapped to ISR functions
    // found within this file.
    //


    //
    // Set up DMA for SPI use, initialize the SPI for FIFO mode
    //
    initDMA();
    init_SPI_enableLoopback(SPIB);
    //SPIb_init_set();
    DMA_startChannel(DMA_CH6_BASE);
    //
    // Initialize the data buffers
    //
    for(i = 0; i < 128; i++)
    {
        spib_sData[i] = i;
        spib_rData[i]= 0;
    }
    //一定在数据赋值完成后开启发送通道
    DMA_startChannel(DMA_CH5_BASE);

    //
    // Enable interrupts required for this example
    //


    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

    //
    // Start the DMA channels
    //


    //
    // Wait until the DMA transfer is complete
    //
    while(!done);

    //
    // When the DMA transfer is complete the program will stop here
    //
    ESTOP0;
}







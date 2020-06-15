
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "user_spi.h"
#include "user_interrupt.h"
//
// Defines
//
#define FIFO_LVL    8               // FIFO interrupt level
#define BURST       FIFO_LVL        // Each burst will empty the FIFO
#define TRANSFER    16              // It will take 16 bursts of 8 to transfer
                                    // all data in rData

////
//// Globals
////
//uint16_t sData[128];                // Send data buffer
//uint16_t rData[128];                // Receive data buffer
//
//// Place buffers in GSRAM
//#pragma DATA_SECTION(sData, "ramgs0");
//#pragma DATA_SECTION(rData, "ramgs1");

//
// Function Prototypes
//
void initDMA(void);
void initSPIFIFO(void);

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
    SPIa_init_set();
    SPIb_init_set();
    DMA_startChannel(DMA_CH6_BASE);
    //
    // Initialize the data buffers
    //
    for(i = 0; i < 128; i++)
    {
        spia_sData[i] = i;
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







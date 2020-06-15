//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        main.c
// Descriptions:    ������
// Author:          Max
// Creation Date:   2020��5��24��
//----------------------------------------------------------------------------------------//
//note: ����CLBʱ����ʼ��DMA�ᱨ�ڴ����

//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include <stdbool.h>
#include "user_interrupt.h"
//
#include "user_led.h"
#include "user_epwm.h"
#include "user_clb.h"
#include "user_spi.h"
#include "user_gpio.h"
#include "endat_cmd.h"
#include "user_dma.h"


//
// Main
//
void main(void)
{
//    uint16_t i;
    //***********************************************ϵͳ��ʼ��**********************************\\
    // Initialize device clock and peripherals
        // PLLSYSCLK = 20MHz (XTAL_OSC) * 40 (IMULT) / (2 (REFDIV) * 2 (ODIV) * 1(SYSDIV))=200M
        Device_init();
    //    // Setup GPIO by disabling pin locks and enabling pullups
        Device_initGPIO();
    //    // Initialize PIE and clear PIE registers. Disables CPU interrupts
        interrupt_init_set();

    //***********************************************�����ʼ������**********************************\\
    //

    user_gpio_init_set();

//    led_init_set();//34��������ΪGPIO���

    DEVICE_DELAY_US(2000000);//�������豸�����ʼ����Ҫ2s

    clb1_init_set();//ʱ��100M
                    //����clb�߼�����

    initEPWM1();//EPWM100Mʱ��(Ĭ��ϵͳʱ��2��Ƶ����epwm)
                //��ʹ���ж�
                //�趨Ϊ������0��ʱ��Ϊ�ߵ�ƽ
                //������1���Ƚ������������������ϼ�����ʽ,���������ֵ��0
                //EPWMA������2000�£�������AΪ1000ʱ���õͣ���0��������
    //
//    initDMA();

//    init_SPI_enableLoopback(SPIB);
    SPIb_init_set();

    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    EINT;
    ERTM;
////***********************************************����ִ��***************************************\\
////����ִ��
//    DMA_startChannel(DMA_CH6_BASE);
//    //
//    // Initialize the data buffers
//    //
//    for(i = 0; i < 50; i++)
//    {
//        spib_sData[i] = i;
//        spib_rData[i]= 0;
//    }
//    //һ�������ݸ�ֵ��ɺ�������ͨ��
//    DMA_startChannel(DMA_CH5_BASE);
//
//    //
//    // Enable interrupts required for this example
//    //
//
//
//    //
//    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
//
//
//    //
//    // Start the DMA channels
//    //
//
//
//    //
//    // Wait until the DMA transfer is complete
//    //
//    while(!done);
//
//    //
//    // When the DMA transfer is complete the program will stop here
//    //
//    ESTOP0;
//}

endat_send_position();
//�����ú�Ҫ���͵��������ݣ��ٿ���DMAͨ��
//DMA_startChannel(DMA_CH5_BASE);
//DMA_startChannel(DMA_CH6_BASE);

    while(1){
        endat_en();//��CLB�����ź� 0100 0001
        DEVICE_DELAY_US(800);//endat�������ݣ����������ź�

        GPIO16_L();

        DEVICE_DELAY_US(100);//�������ݷ�����ϣ��������������ͣ���ѯ�ߵ�ƽ

        GPIO16_H();

        DEVICE_DELAY_US(20);//�����������߿�ʼ��������

        GPIO16_L();

        DEVICE_DELAY_US(10000);//������յ����ݶ���0
    }

}




//****************************************Copyright (c)***********************************//
//��վ����: NC
//��Ȩ����, ����ؾ�
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_scl.c
// Descriptions:    scl������д�ļ�
// Author:          Max
// Creation Date:   2020��5��24��
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
#include <stdbool.h>
#include <user_sci.h>
#include "device.h"//��������
#include "driverlib.h"
#include "user_interrupt.h"



sci_init_all_para sci = sci_init_para;

//******************SCL�ж�ʹ������************************
void scl_interrupt_set(SCI_PORT_enum sci_port){
    //��CPU�������ж���������
        Interrupt_register(INT_SCIA_RX, sciaRXFIFOISR);
        Interrupt_register(INT_SCIA_TX, sciaTXFIFOISR);
    //ʹ���ж�
        Interrupt_enable(INT_SCIA_RX);
        Interrupt_enable(INT_SCIA_TX);
        // ѡ��ʹ��Ҫ�жϵ����ͣ�ѡ��FIFO�жϣ�����������ready�жϵ�
        SCI_enableInterrupt(sci_port, (SCI_INT_RXFF));//ʹ�ܽ����жϣ���ʹ�ܷ����жϣ�������պͷ��Ͷ�ʹ�ܣ���SCI_INT_RXFF|SCI_INT_TXFF
        SCI_disableInterrupt( sci_port, SCI_INT_RXERR);//�رս��մ����жϣ�����FIFO�ж�
    //�����жϴ�������
        //����FIFO�ж�
        // The transmit FIFO generates an interrupt when FIFO status
        // bits are less than or equal to 2 out of 16 words
        // The receive FIFO generates an interrupt when FIFO status
        // bits are greater than equal to 2 out of 16 words
        SCI_setFIFOInterruptLevel( sci_port, SCI_FIFO_TX2, SCI_FIFO_RX2);

}

void initSCIFIFO(SCI_PORT_enum sci_port)//�趨���жϴ���������
{
    SCI_clearInterruptStatus(sci_port, SCI_INT_TXFF);
    SCI_enableFIFO(sci_port);
    SCI_resetChannels(sci_port);

    SCI_resetTxFIFO(sci_port);
    SCI_resetRxFIFO(sci_port);
}

void sci_tx_init_set(void){
    // GPIO29 is the SCI Tx pin.
    GPIO_setMasterCore(sci.SEND_GPIO, GPIO_CORE_CPU1);
    GPIO_setPinConfig(sci.gpio_mux_tx);
    GPIO_setDirectionMode(sci.SEND_GPIO, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(sci.SEND_GPIO, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(sci.SEND_GPIO, GPIO_QUAL_ASYNC);
}
void sci_rx_init_set(void){
    // GPIO28 is the SCI Rx pin.
    GPIO_setMasterCore(sci.RECEIVE_GPIO, GPIO_CORE_CPU1);
    GPIO_setPinConfig(sci.gpio_mux_rx);//���Ÿ���ѡ��Ϊ���ڣ�������ͨ��GPIO
    GPIO_setDirectionMode(sci.RECEIVE_GPIO, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(sci.RECEIVE_GPIO, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(sci.RECEIVE_GPIO, GPIO_QUAL_ASYNC);//GPIO��ʹ��ʱ�ӽ��գ������첽����
}

void sci_init_set(SCI_PORT_enum sci_port){
    //����Ѳ��������÷���FIFO��ʼ�����ú���,���ݾͽ��ղ�����
    SCI_setConfig(sci_port, DEVICE_LSPCLK_FREQ, sci.baud_rate , (SCI_CONFIG_WLEN_8 |//����Ϊ9600
                                                            SCI_CONFIG_STOP_ONE |
                                                            SCI_CONFIG_PAR_NONE));
    sci_rx_init_set();
    sci_tx_init_set();
    scl_interrupt_set(sci_port);
    initSCIFIFO(sci_port);

}









void sci_send(SCI_PORT_enum sci_port, uint16_t data)
{
    SCI_writeCharNonBlocking(sci_port, data);//��SCI��A���ڷ�������,һ����ABCD4������
}


uint16_t sci_received(SCI_PORT_enum sci_port ){
    return SCI_readCharBlockingFIFO(sci_port);
}



//�õ���bool����Ҫinclude<stdbootl.h>
bool sci_reveive_ack(SCI_PORT_enum sci_port){
    //��ȡFIFO�Ĵ���״̬������ǿգ�����0��������ǿգ�����1
    return SCI_getRxFIFOStatus(sci_port) == SCI_FIFO_RX0 ? false:true;

}





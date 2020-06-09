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
#include "device.h"//��������
#include "driverlib.h"
#include "user_interrupt.h"


#include "user_scl.h"



void scia_init_set(void){
    //����Ѳ��������÷���FIFO��ʼ�����ú���,���ݾͽ��ղ�����
    SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, RECEIVE_Baud_rate_9600, (SCI_CONFIG_WLEN_8 |//����Ϊ9600
                                                            SCI_CONFIG_STOP_ONE |
                                                            SCI_CONFIG_PAR_NONE));
    scia_rx_init_set();
    scia_tx_init_set();
    scl_interrupt_set();
    initSCIAFIFO();

}



void scia_tx_init_set(void){
    // GPIO29 is the SCI Tx pin.
    GPIO_setMasterCore(SCI_SEND_GPIO, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_29_SCITXDA);
    GPIO_setDirectionMode(SCI_SEND_GPIO, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(SCI_SEND_GPIO, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(SCI_SEND_GPIO, GPIO_QUAL_ASYNC);
}
void scia_rx_init_set(void){
    // GPIO28 is the SCI Rx pin.
    GPIO_setMasterCore(SCI_RECEIVE_GPIO, GPIO_CORE_CPU1);
    GPIO_setPinConfig(GPIO_28_SCIRXDA);//���Ÿ���ѡ��Ϊ���ڣ�������ͨ��GPIO
    GPIO_setDirectionMode(SCI_RECEIVE_GPIO, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(SCI_RECEIVE_GPIO, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(SCI_RECEIVE_GPIO, GPIO_QUAL_ASYNC);//GPIO��ʹ��ʱ�ӽ��գ������첽����
}

void initSCIAFIFO()//�趨���жϴ���������
{
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF);
    SCI_enableFIFO(SCIA_BASE);
    SCI_resetChannels(SCIA_BASE);

    SCI_resetTxFIFO(SCIA_BASE);
    SCI_resetRxFIFO(SCIA_BASE);
}

void scia_send(uint16_t a)
{
    SCI_writeCharNonBlocking(SCIA_BASE, a);//��SCI��A���ڷ�������,һ����ABCD4������
}


uint16_t scia_received(){
    return SCI_readCharBlockingFIFO(SCIA_BASE);
}



//�õ���bool����Ҫinclude<stdbootl.h>
bool sci_reveive_ack(void){
    //��ȡFIFO�Ĵ���״̬������ǿգ�����0��������ǿգ�����1
    return SCI_getRxFIFOStatus(SCIA_BASE) == SCI_FIFO_RX0 ? false:true;

}





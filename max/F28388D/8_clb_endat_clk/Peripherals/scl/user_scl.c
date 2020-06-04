//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        user_scl.c
// Descriptions:    scl函数编写文件
// Author:          Max
// Creation Date:   2020年5月24日
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
#include <stdbool.h>
#include "device.h"//引入外设
#include "driverlib.h"
#include "user_interrupt.h"


#include "user_scl.h"



void scia_init_set(void){
    //如果把波特率设置放在FIFO初始化设置后面,数据就接收不到了
    SCI_setConfig(SCIA_BASE, DEVICE_LSPCLK_FREQ, RECEIVE_Baud_rate_9600, (SCI_CONFIG_WLEN_8 |//配置为9600
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
    GPIO_setPinConfig(GPIO_28_SCIRXDA);//引脚复用选择为串口，而不是通用GPIO
    GPIO_setDirectionMode(SCI_RECEIVE_GPIO, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(SCI_RECEIVE_GPIO, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(SCI_RECEIVE_GPIO, GPIO_QUAL_ASYNC);//GPIO不使用时钟接收，采用异步输入
}

void initSCIAFIFO()//设定了中断触发的条件
{
    SCI_clearInterruptStatus(SCIA_BASE, SCI_INT_TXFF);
    SCI_enableFIFO(SCIA_BASE);
    SCI_resetChannels(SCIA_BASE);

    SCI_resetTxFIFO(SCIA_BASE);
    SCI_resetRxFIFO(SCIA_BASE);
}

void scia_send(uint16_t a)
{
    SCI_writeCharNonBlocking(SCIA_BASE, a);//用SCI的A串口发送数据,一共有ABCD4个串口
}


uint16_t scia_received(){
    return SCI_readCharBlockingFIFO(SCIA_BASE);
}



//用到了bool，则要include<stdbootl.h>
bool sci_reveive_ack(void){
    //读取FIFO寄存器状态，如果是空，返回0，如果不是空，返回1
    return SCI_getRxFIFOStatus(SCIA_BASE) == SCI_FIFO_RX0 ? false:true;

}





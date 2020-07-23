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
#include <user_sci.h>
#include "device.h"//引入外设
#include "driverlib.h"
#include "user_interrupt.h"



sci_init_all_para sci = sci_init_para;

//******************SCL中断使能设置************************
void scl_interrupt_set(SCI_PORT_enum sci_port){
    //将CPU和外设中断链接起来
        Interrupt_register(INT_SCIA_RX, sciaRXFIFOISR);
        Interrupt_register(INT_SCIA_TX, sciaTXFIFOISR);
    //使能中断
        Interrupt_enable(INT_SCIA_RX);
        Interrupt_enable(INT_SCIA_TX);
        // 选择使能要中断的类型，选择FIFO中断，而不是数据ready中断等
        SCI_enableInterrupt(sci_port, (SCI_INT_RXFF));//使能接收中断，不使能发送中断，如果接收和发送都使能，就SCI_INT_RXFF|SCI_INT_TXFF
        SCI_disableInterrupt( sci_port, SCI_INT_RXERR);//关闭接收错误中断，开启FIFO中断
    //设置中断触发条件
        //设置FIFO中断
        // The transmit FIFO generates an interrupt when FIFO status
        // bits are less than or equal to 2 out of 16 words
        // The receive FIFO generates an interrupt when FIFO status
        // bits are greater than equal to 2 out of 16 words
        SCI_setFIFOInterruptLevel( sci_port, SCI_FIFO_TX2, SCI_FIFO_RX2);

}

void initSCIFIFO(SCI_PORT_enum sci_port)//设定了中断触发的条件
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
    GPIO_setPinConfig(sci.gpio_mux_rx);//引脚复用选择为串口，而不是通用GPIO
    GPIO_setDirectionMode(sci.RECEIVE_GPIO, GPIO_DIR_MODE_IN);
    GPIO_setPadConfig(sci.RECEIVE_GPIO, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(sci.RECEIVE_GPIO, GPIO_QUAL_ASYNC);//GPIO不使用时钟接收，采用异步输入
}

void sci_init_set(SCI_PORT_enum sci_port){
    //如果把波特率设置放在FIFO初始化设置后面,数据就接收不到了
    SCI_setConfig(sci_port, DEVICE_LSPCLK_FREQ, sci.baud_rate , (SCI_CONFIG_WLEN_8 |//配置为9600
                                                            SCI_CONFIG_STOP_ONE |
                                                            SCI_CONFIG_PAR_NONE));
    sci_rx_init_set();
    sci_tx_init_set();
    scl_interrupt_set(sci_port);
    initSCIFIFO(sci_port);

}









void sci_send(SCI_PORT_enum sci_port, uint16_t data)
{
    SCI_writeCharNonBlocking(sci_port, data);//用SCI的A串口发送数据,一共有ABCD4个串口
}


uint16_t sci_received(SCI_PORT_enum sci_port ){
    return SCI_readCharBlockingFIFO(sci_port);
}



//用到了bool，则要include<stdbootl.h>
bool sci_reveive_ack(SCI_PORT_enum sci_port){
    //读取FIFO寄存器状态，如果是空，返回0，如果不是空，返回1
    return SCI_getRxFIFOStatus(sci_port) == SCI_FIFO_RX0 ? false:true;

}





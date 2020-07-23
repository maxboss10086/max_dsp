/*
 * scl.h
 *
 *  Created on: 2020年5月21日
 *      Author: 57315
 */

#ifndef USER_SCI_H_
#define USER_SCI_H_

#include "stdint.h"

//define
typedef enum {
    SCIA = 0x00007200U,
    SCIB = 0x00007210U,
    SCIC = 0x00007220U,
    SCID = 0x00007230U
}SCI_PORT_enum;

//define
typedef enum {
    Baud_rate_9600      = 9600,
    Baud_rate_115200    = 115200
}SCI_Baud_rate ;

typedef struct {
    SCI_PORT_enum   sci_port;
    uint16_t        SEND_GPIO;
    uint16_t        RECEIVE_GPIO;
    uint32_t        gpio_mux_tx;
    uint32_t        gpio_mux_rx;
    SCI_Baud_rate   baud_rate;
}sci_init_all_para;
extern sci_init_all_para sci;

#define sci_init_para  {    SCIA,\
                            29,\
                            28,\
                            GPIO_29_SCITXDA,\
                            GPIO_28_SCIRXDA,\
                            Baud_rate_9600\
                        }



//function
void        scia_tx_init_set(void);
void        scia_rx_init_set(void);
void        sci_send(SCI_PORT_enum sci ,uint16_t data);//串口发送一帧数据
uint16_t    sci_received(SCI_PORT_enum sci_port);//串口接收一帧数据
void        sci_init_set(SCI_PORT_enum sci_port);
bool        sci_reveive_ack(SCI_PORT_enum sci_port);






#endif /* USER_SCL_H_ */

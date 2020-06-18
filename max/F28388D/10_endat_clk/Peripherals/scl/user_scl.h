/*
 * scl.h
 *
 *  Created on: 2020年5月21日
 *      Author: 57315
 */

#ifndef USER_SCL_H_
#define USER_SCL_H_



//define
#define SCI_SEND_GPIO               29
#define SCI_RECEIVE_GPIO            28
#define SEND_Baud_rate_9600         9600
#define RECEIVE_Baud_rate_9600      9600

//function
void        scia_tx_init_set(void);
void        scia_rx_init_set(void);
void        scia_send(uint16_t a);//串口发送一帧数据
uint16_t    scia_received();//串口接收一帧数据
void        initSCIAFIFO();
void        scia_init_set(void);
bool        sci_reveive_ack(void);






#endif /* USER_SCL_H_ */

//****************************************Copyright (c)***********************************//
//网站博客: NC
//版权所有, 盗版必究
//Copyright (c) 2020
// ALL right reserved
//----------------------------------------------------------------------------------------//
//File name:        xxx.h
// Descriptions:
// Author:          Max
// Creation Date:   2020年6月11日
//----------------------------------------------------------------------------------------//
//note:
//----------------------------------------------------------------------------------------//
//***************************************include******************************************//
#ifndef PERIPHERALS_ENDAT_ENDAT_CMD_H_
#define PERIPHERALS_ENDAT_ENDAT_CMD_H_


//define
extern unsigned char clb_input;
//编码器命令
#define     encoder_transmit_position_values                                0x07//6'b00_0111
#define     selection_of_memory_area                                        0x0e//6'b00_1110
#define     encoder_receive_parameter                                       0x1c//6'b01_1100
#define     encoder_send_parameter                                          0x23//6'b10_0011
#define     encoder_reset                                                   0x2a//6'b10_1010
#define     encoder_send_test_values                                        0x25//6'b01_0101
#define     encoder_receive_test_command                                    0x31//6'b11_0001
#define     enconer_send_position_values_with_additional_data               0x38//6'b11_1000
#define     enconer_send_position_values_and_selection_of_the_memory_area   0x09//6'b00_1001
#define     enconer_send_position_values_and_receive_parameter              0x1b//6'b01_1011
#define     enconer_send_position_values_and_send_parameter                 0x24//6'b10_0100
#define     enconer_send_position_values_and_reset_error                    0x2d//6'b10_1101
//MRS存储区选择
#define     MRS_Select_Parameters_of_Encoder_Manufacturer                   0xa1//‭8'b1010_0001
//存储区地址
#define     MRS_address_clock_pulses                                        0xd//8'd13//no.of clock pulses needed to shift out position data
#define     MRS_address_endat_versions                                      0x8//8'd8//versions of endat
#define     MRS_address_max_clk                                             0x19//8'd25//Maximum clock frequency
#define     MRS_address_model_number                                        0xe//8'd14//编码器型号

//additional information 1 address
#define         transmit_add_information_1_without_data_content             0x40//8'b0100_0000
#define         transmit_diagnosis                                          0x41//8'b0100_0001
#define         transmit_position_values_2_word_1_LSB                       0x42//8'b0100_0010
#define         transmit_position_values_2_word_2                           0x43//8'b0100_0011
#define         transmit_position_values_2_word_3_MSB                       0x44//8'b0100_0100
#define         acknowledge_memory_content_LSB                              0x45//8'b0100_0101
#define         acknowledge_memory_content_MSB                              0x46//8'b0100_0110
#define         acknowledge_MRS_code                                        0x47//8'b0100_0111
#define         acknowledge_test_command                                    0x48//8'b0100_1000
#define         transmit_test_values_word_1_LSB                             0x49//8'b0100_1001
#define         transmit_test_values_word_2                                 0x4a//8'b0100_1010
#define         transmit_test_values_word_3_MSB                             0x4b//8'b0100_1011
#define         transmit_temperature_1                                      0x4c//8'b0100_1100
#define         transmit_temperature_2                                      0x4d//8'b0100_1101
#define         additional_sensors                                          0x4e//8'b0100_1110
#define         transmit_no_more_add_informationa_1                         0x4f//8'b0100_1111
//additional information 2 address
#define         transmit_add_information_2_without_data_content             0x50//8'b0101_0000
#define         transmit_commutation                                        0x51//8'b0101_0001
#define         transmit_acceleration                                       0x52//8'b0101_0010
#define         transmit_commutation_and_acceleration                       0x53//8'b0101_0011
#define         transmit_limit_position_signal                              0x54//8'b0101_0100
#define         transmit_limit_position_signal_and_acceleration             0x55//8'b0101_0101
#define         asynchronous_position_value_word_1_LSB                      0x56//8'b0101_0110
#define         asynchronous_position_value_word_2                          0x57//8'b0101_0111
#define         asynchronous_position_value_word_3_MSB                      0x58//8'b0101_1000
#define         operating_status_error_sources                              0x59//8'b0101_1001
#define         not_used_at_present1                                        0x5a//8'b0101_1010
#define         not_used_at_present2                                        0x5b//8'b0101_1011
#define         not_used_at_present3                                        0x5c//8'b0101_1100
#define         not_used_at_present4                                        0x5d//8'b0101_1101
#define         not_used_at_present5                                        0x5e//8'b0101_1110
#define         transmit_no_more_add_informationa_2                         0x5f//8'b0101_1111


//function
void endat_en (void);
void endat_selection_of_memory_area(void);
void endat_send_position(void);

#endif /* PERIPHERALS_ENDAT_ENDAT_CMD_H_ */

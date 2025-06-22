/*
 * Test.c
 *
 *  Created on: Jun 21, 2025
 *      Author: vanqu
 */

#include <Tx.h>
////===========================================================================================================
CAN_TxHeaderTypeDef Txheader;
uint8_t tx_data[8];
uint32_t Txmailbox;
////===========================================================================================================
extern CAN_HandleTypeDef hcan2;

////===========================================================================================================
void Hyp_CAN_Tx_Initialize(){
	Txheader.IDE = CAN_ID_STD;
	Txheader.ExtId = 0;
	Txheader.StdId = 0x446;
	Txheader.RTR = CAN_RTR_DATA;
	Txheader.DLC = 2;
	Txheader.TransmitGlobalTime = DISABLE;

	tx_data[0] = 0x50;
	tx_data[1] = 0xAA;
}
uint8_t Hyp_CAN_Transmit_data(){
	if((HAL_CAN_AddTxMessage(&hcan2, &Txheader, tx_data, &Txmailbox))==HAL_OK){
		return 0;
	}else{
		return 1;
	}
}
////===========================================================================================================

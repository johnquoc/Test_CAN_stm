/*
 * Rx.c
 *
 *  Created on: Jun 22, 2025
 *      Author: Admin
 */

#include "Rx.h"

CAN_RxHeaderTypeDef Rxheader;
uint8_t rx_data[8];
extern CAN_HandleTypeDef hcan2;

void Hyp_filter(){
	  CAN_FilterTypeDef canfilterconfig;

	  canfilterconfig.FilterActivation = ENABLE;
	  canfilterconfig.FilterBank = 10;  // anything between 0 to SlaveStartFilterBank
	  canfilterconfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	  canfilterconfig.FilterIdHigh = 0x446<<5;
	  canfilterconfig.FilterIdLow = 0x0000;
	  canfilterconfig.FilterMaskIdHigh = 0x446<<5;
	  canfilterconfig.FilterMaskIdLow = 0x0000;
	  canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
	  canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;
	  canfilterconfig.SlaveStartFilterBank = 13;  // 13 to 27 are assigned to slave CAN (CAN 2) OR 0 to 12 are assgned to CAN1

	  HAL_CAN_ConfigFilter(&hcan2, &canfilterconfig);

}
uint8_t Hyp_CAN_Receive_data(){
	if((HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &Rxheader, rx_data))==HAL_OK){
		return 0;
	}else{
		return 1;
	}
}

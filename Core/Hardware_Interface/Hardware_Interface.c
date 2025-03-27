#include "Hardware_Interface.h"

//communication buffers
uint8_t TxBuffer[TxRxBufferSize];
uint8_t RxBuffer[TxRxBufferSize];

extern DataFrame F;

void SbW_Protocol_Reply(uint8_t *data, uint16_t len) {
	HAL_UART_Transmit_DMA(&huart1, data, len);
}

//when data is recieved from the PC
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	SbW_Request_Received_CB(&S, RxBuffer, Size);
	HAL_UARTEx_ReceiveToIdle_DMA(huart, RxBuffer, sizeof(RxBuffer));
}

//to notify the application layer
void App_User_Callback(SbW_Err_Codes_t Error_Code) {
}

//sampling timer callback
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	F.G[0]++;
	SbW_Timer_Callback(&S);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	//notify the driver about the completion of a frame transmission
	SbW_TxCPLt(&S);
}

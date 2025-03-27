#ifndef HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_
#define HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "../../USB_DEVICE/App/usbd_cdc_if.h"

#include "../../Drivers/SbW_Protocol/SbW_protocol.h"

#define TxRxBufferSize 256

typedef struct {
	float Id;
	float Iq;
	float Vd;
	float Vq;
	float T;
	uint8_t G[4];
} DataFrame;

extern UART_HandleTypeDef huart1;
extern SbW_Protocol_t S;

void SbW_Protocol_Reply(uint8_t *data, uint16_t len);
void App_User_Callback(SbW_Err_Codes_t Error_Code);

#endif /* HARDWARE_INTERFACE_HARDWARE_INTERFACE_H_ */

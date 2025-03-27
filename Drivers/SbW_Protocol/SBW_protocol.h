#ifndef SbW_PROTOCOL_SbW_PROTOCOL_H_
#define SbW_PROTOCOL_SbW_PROTOCOL_H_

#include <stdint.h>
#include "../FIFO/FIFO.h"

typedef enum SbW_Err_Codes {
	SbW_ERROR_NoERROR, SbW_ERROR_CRC,
} SbW_Err_Codes_t;


typedef struct SbW_Protocol {
	uint8_t Stream_ON :1;
	// user frame length
	uint8_t Frame_Len;
	//pointer tothe user frame base address
	uint8_t *FrameDataBaseAddress;
	uint16_t SamplingFreq;
	uint8_t R_W :1;
	uint8_t CMD;

	//fifo containing the head and tail
	fifo_T MessageFifo;

	//pointer to the frame buffer where the
	//data will be placed
	uint8_t *Fifo_Buffer;
	//size of the buffer
	uint16_t Fifo_Buffer_Size;

	//pointer to the communication TX buffer where data will be placed
	uint8_t *P_TXBuffer;

	struct Hw_Interface {
		void (*Send_Reply)(uint8_t *data, uint16_t len);
		void (*User_Callback)(SbW_Err_Codes_t Error_Code);
	} HW_Interface_t;

	uint8_t RemainingFrames;

	uint8_t Mutex;
} SbW_Protocol_t;

void SbW_Request_Received_CB(SbW_Protocol_t *S, uint8_t *data, uint16_t len); //to send the received data from the USB to the protocol
//This function will be called back in CDC_Receive_FS to pass the data to the Software driver to do its purpose for this function
void SbW_Reply_Transmit(SbW_Protocol_t *S, uint8_t *data, uint16_t len); //to reply to the USB from the protocol

//to be called from the timer ISR, inside, the data will be enqueued inside the FIFO
void SbW_Timer_Callback(SbW_Protocol_t *S);

void SbW_Init(SbW_Protocol_t *S);
void SbW_TxCPLt(SbW_Protocol_t *S);
void SbW_TxFrame_processor(SbW_Protocol_t *S);
#endif /* SbW_PROTOCOL_SbW_PROTOCOL_H_ */

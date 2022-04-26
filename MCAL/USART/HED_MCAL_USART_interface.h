#ifndef HED_MCAL_USART_INTERFACE_H_
#define HED_MCAL_USART_INTERFACE_H_

#define ERROR           0
#define VALID           1

typedef struct ERROR_FLAGS {
	u8 FRAME_ERROR;
	u8 DATA_OVER_RUN;
	u8 PARITY_ERROR;
} ERROR_FLAGS;

void USART_INIT(void);

void USART_sendData(u8 USART_TDATA);
void USART_sendString(const char * USART_STRING);

u8 USART_receiveData(ERROR_FLAGS * COPY_ERROR_FLAGS);
void USART_receiveBuffer(u32 * USART_BUFFER, u32 BUFFER_SIZE);

void USART_enable2xSPEED(void);
void USART_disable2xSPEED(void);

#endif
#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../LIB/LIB_VRT_BIT_MATH.h"
#include "HED_MCAL_USART_interface.h"
#include "HED_MCAL_USART_register.h"
#include "HED_MCAL_USART_private.h"
#include "HED_MCAL_USART_config.h"

void USART_INIT()
{
    u8_PRV_MCAL_USART_UBRRH = (unsigned char)BAUD_RATE >> 8;
    u8_PRV_MCAL_USART_UBRRL = (unsigned char)BAUD_RATE;

    u8_PRV_MCAL_USART_UCSRC = UCSRC_URSEL | COMM_MODE | PARITY_MODE | STOP_BIT | DATA_SIZEC | CLK_POLARITY;
    u8_PRV_MCAL_USART_UCSRB = 0x00;
    u8_PRV_MCAL_USART_UCSRB = ENB_RX_INT | ENB_TX_INT | ENB_DE_INT | DATA_SIZEB | UCSRB_TXEN | UCSRB_RXEN;
}

void USART_sendData(u8 USART_TDATA)
{
	while(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 5) == 0);
	u8_PRV_MCAL_USART_UDR = USART_TDATA;
	u8_PRV_MCAL_USART_UCSRA |= UCSRA_TXC;
}

void USART_sendString(const char * USART_STRING)
{
    while(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 5) == 0);
    u8_PRV_MCAL_USART_UDR = USART_STRING[0];
    u8 i = 1;
    while (USART_STRING[i] != '\0')
    {
        while(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 5) == 0);
        u8_PRV_MCAL_USART_UDR = USART_STRING[i];
        i++;
    }
}

u8 USART_receiveData(ERROR_FLAGS * COPY_ERROR_FLAGS)
{
    while(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 7) == 0);

    if(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 4) == 1)
    {
        COPY_ERROR_FLAGS->FRAME_ERROR = 1;
    }

    if(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 3) == 1)
    {
        COPY_ERROR_FLAGS->DATA_OVER_RUN = 1;
    }

    if(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 2) == 1)
    {
        COPY_ERROR_FLAGS->PARITY_ERROR = 1;
    }

    return u8_PRV_MCAL_USART_UDR;
}

void USART_receiveBuffer(u32 * USART_BUFFER, u32 BUFFER_SIZE)
{
    u8 i = 0;
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        while(GET_BIT(u8_PRV_MCAL_USART_UCSRA, 7) == 0);
        *USART_BUFFER = u8_PRV_MCAL_USART_UDR << 8;
    }
}

void USART_enable2xSPEED()
{
    u8_PRV_MCAL_USART_UCSRA |= UCSRA_U2X;
}

void USART_disable2xSPEED()
{
    u8_PRV_MCAL_USART_UCSRA &= ~UCSRA_U2X;
}

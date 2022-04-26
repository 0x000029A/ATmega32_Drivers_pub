#ifndef HED_MCAL_USART_REGISTER_H_
#define HED_MCAL_USART_REGISTER_H_

#define u8_PRV_MCAL_USART_UDR       *((volatile u8*)0x2C)

#define u8_PRV_MCAL_USART_UCSRA     *((volatile u8*)0x2B)
#define UCSRA_RXC                   (0b10000000)
#define UCSRA_TXC                   (0b01000000)
#define UCSRA_UDRE                  (0b00100000)
#define UCSRA_FE                    (0b00010000)
#define UCSRA_DOR                   (0b00001000)
#define UCSRA_PE                    (0b00000100)
#define UCSRA_U2X                   (0b00000010)
#define UCSRA_MPCM                  (0b00000001)

#define u8_PRV_MCAL_USART_UCSRB     *((volatile u8*)0x2A)
#define UCSRB_RXCIE                 (0b10000000)
#define UCSRB_TXCIE                 (0b01000000)
#define UCSRB_UDRIE                 (0b00100000)
#define UCSRB_RXEN                  (0b00010000)
#define UCSRB_TXEN                  (0b00001000)
#define UCSRB_UCSZ2                 (0b00000100)
#define UCSRB_RXB8                  (0b00000010)
#define UCSRB_TXB8                  (0b00000001)

#define u8_PRV_MCAL_USART_UCSRC     *((volatile u8*)0x40)
#define UCSRC_URSEL                 (0b10000000)
#define UCSRC_UMSEL                 (0b01000000)
#define UCSRC_UPM1                  (0b00100000)
#define UCSRC_UPM0                  (0b00010000)
#define UCSRC_USBS                  (0b00001000)
#define UCSRC_UCSZ1                 (0b00000100)
#define UCSRC_UCSZ0                 (0b00000010)
#define UCSRC_UCPOL                 (0b00000001)

#define u8_PRV_MCAL_USART_UBRRL     *((volatile u8*)0x29)
#define u8_PRV_MCAL_USART_UBRRH     *((volatile u8*)0x40)

#endif
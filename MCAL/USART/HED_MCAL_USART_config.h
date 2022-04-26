#ifndef HED_MCAL_USART_CONFIG_H_
#define HED_MCAL_USART_CONFIG_H_

/* Double the USART Transmission Speed
 * This only has effect for the asynchronous operation.
 * Writing this bit to one will reduce the divisor of the baud rate divider from 16 to 8.
 */
#define x2SPEED         U2X_OFF

#define MULTI_SLAVE     MPCM_OFF

#define ENB_RX_INT      RXCIE_OFF

#define ENB_TX_INT      TXCIE_OFF

#define ENB_DE_INT      UDRIE_OFF

#define COMM_MODE       ASYNC

#define PARITY_MODE     PARITY_OFF

#define STOP_BIT        BIT2STOP

#define DATA_SIZEB      SIZE8BITB
#define DATA_SIZEC      SIZE8BITC

#define CLK_POLARITY    CLK_PLOARITY_OFF

#define BAUD_RATE       MHZ8_BPS9600

#endif
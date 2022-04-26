#ifndef HED_MCAL_USART_PRIVATE_H_
#define HED_MCAL_USART_PRIVATE_H_
/*2x speed*/
#define U2X_OFF     (0)
#define U2X_ON      UCSRA_U2X

/*multi slave*/
#define MPCM_OFF    (0)
#define MPCM_ON     UCSRA_MPCM

#define RXCIE_OFF   (0)
#define RXCIE_ON    UCSRB_RXCIE

#define TXCIE_OFF   (0)
#define TXCIE_ON    UCSRB_TXCIE

#define UDRIE_OFF   (0)
#define UDRIE_ON    UCSRB_UDRIE

#define ASYNC       (0)
#define SYNC        UCSRC_UMSEL

#define PARITY_OFF  (0)
#define EVEN_PARITY UCSRC_UPM1  
#define ODD_PARITY  (UCSRC_UPM0 | UCSRC_UPM1)

#define BIT1STOP    (0)
#define BIT2STOP    UCSRC_USBS

#define SIZE5BITB   (0)
#define SIZE6BITB   (0)
#define SIZE7BITB   (0)
#define SIZE8BITB   (0)
#define SIZE9BITB   (UCSRB_UCSZ2)

#define SIZE5BITC   (0)
#define SIZE6BITC   (UCSRC_UCSZ0)
#define SIZE7BITC   (UCSRC_UCSZ1)
#define SIZE8BITC   (UCSRC_UCSZ0 | UCSRC_UCSZ1)
#define SIZE9BITC   (UCSRC_UCSZ0 | UCSRC_UCSZ1)

#define CLK_PLOARITY_OFF        (0)
#define TD_RISING_RD_FALLING    (0)
#define TD_FALLING_RD_RISING    UCSRC_UCPOL

#define MHZ8_BPS9600            51

#endif
#ifndef HED_MCAL_SPI_PRIVATE_H_
#define HED_MCAL_SPI_PRIVATE_H_

#define INT_OFF             0
#define INT_ON              SPCR_SPIE
    
#define LSB_FIRST           SPCR_DORD
#define MSB_FIRST           0
    
#define MASTER              SPCR_MSTR
#define SLAVE               0
    
#define HIGH_IDLE           SPCR_CPOL
#define LOW_IDLE            0
    
#define SEND_ON_LEAD        SPCR_CPHA
#define RECEIVE_ON_LEAD     0
    
#define DIV_BY_4            0
#define DIV_BY_16           SPCR_SPR0
#define DIV_BY_64           SPCR_SPR1
#define DIV_BY_128          (SPCR_SPR0 | SPCR_SPR1)
        
#define ENB_2X              SPSR_SPI2X
#define DIS_2X              0

#endif
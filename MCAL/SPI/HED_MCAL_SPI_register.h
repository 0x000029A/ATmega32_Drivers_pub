#ifndef HED_MCAL_SPI_REGISTER_H_
#define HED_MCAL_SPI_REGISTER_H_

#define u8_PRV_MCAL_SPI_SPCR    *((volatile u8*)0x2D)
#define SPCR_SPIE               0b10000000
#define SPCR_SPE                0b01000000
#define SPCR_DORD               0b00100000
#define SPCR_MSTR               0b00010000
#define SPCR_CPOL               0b00001000
#define SPCR_CPHA               0b00000100
#define SPCR_SPR1               0b00000010
#define SPCR_SPR0               0b00000001

#define u8_PRV_MCAL_SPI_SPSR    *((volatile u8*)0x2E)
#define SPSR_SPIF               0b10000000
#define SPSR_WCOL               0b01000000
#define SPSR_SPI2X              0b00000001

#define u8_PRV_MCAL_SPI_SPDR    *((volatile u8*)0x2F)

#define u8_PRV_MCAL_DIO_PORTB   *((volatile u8*)0x38)
#define u8_PRV_MCAL_DIO_DDRB    *((volatile u8*)0x37)
#define u8_PRV_MCAL_DIO_PINB    *((volatile u8*)0x36)

#endif

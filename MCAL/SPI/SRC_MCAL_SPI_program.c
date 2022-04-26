#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../LIB/LIB_VRT_BIT_MATH.h"
#include "HED_MCAL_SPI_interface.h"
#include "HED_MCAL_SPI_register.h"
#include "HED_MCAL_SPI_config.h"
#include "HED_MCAL_SPI_private.h"

void SPI_MASTER_INIT()
{
	u8_PRV_MCAL_DIO_DDRB |= 0b10110000;
	SET_BIT(u8_PRV_MCAL_DIO_PORTB, 4);
    u8_PRV_MCAL_SPI_SPCR |= INT_STATE | DATA_ORDER | SPCR_MSTR | CLK_POLARITY | CLK_PHASE | SCK_FREQ;
    u8_PRV_MCAL_SPI_SPSR |= SPSR_SPI2X;
    u8_PRV_MCAL_SPI_SPCR |= SPCR_SPE;
}

void SPI_SLAVE_INIT()
{
    u8_PRV_MCAL_SPI_SPCR &= ~SPCR_MSTR;

    u8_PRV_MCAL_SPI_SPCR |= INT_STATE | DATA_ORDER | CLK_POLARITY | CLK_PHASE;

    u8_PRV_MCAL_SPI_SPCR |= SPCR_SPE;
}

void SPI_MASTER_TRANSMIT(u8 COPY_u8_PRV_MCAL_SPI_TDATA)
{
    u8 flush_buffer;
    u8_PRV_MCAL_SPI_SPDR = COPY_u8_PRV_MCAL_SPI_TDATA;
    while (!GET_BIT(u8_PRV_MCAL_SPI_SPSR, 7));
    flush_buffer = u8_PRV_MCAL_SPI_SPDR;
}

u8 SPI_SLAVE_RECEIVE()
{
    while (!GET_BIT(u8_PRV_MCAL_SPI_SPSR, 7));
    return u8_PRV_MCAL_SPI_SPDR;
}

u8 SPI_WRITE_COLLISION_FLAG()
{
    return u8_PRV_MCAL_SPI_SPSR >> 6;
}

void SPI_SS_ENB_void(void) {
	CLR_BIT(u8_PRV_MCAL_DIO_PORTB, 4);
}

void SPI_SS_DIS_void(void) {
	SET_BIT(u8_PRV_MCAL_DIO_PORTB, 4);
}

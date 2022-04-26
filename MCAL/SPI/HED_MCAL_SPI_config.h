#ifndef HED_MCAL_SPI_CONFIG_H_
#define HED_MCAL_SPI_CONFIG_H_

/* This enables (INT_ON) or disable (INT_OFF) the SPI interrupt. */
#define INT_STATE  INT_OFF

/* 
 * LSB_FIRST: LSB of the data word is transmitted first.
 * MSB_FIRST: MSB of the data word is transmitted first.
 */
#define DATA_ORDER  MSB_FIRST

/*--------------+---------------+-------------------+-------------------+
 |  OPTIONS     |   SCK IDLE    |   Leading Edge    |   Trailing Edge   |
 +--------------+---------------+-------------------+-------------------+
 |  HIGH_IDLE   |   HIGH        |   Falling         |   Rising          |
 +--------------+---------------+-------------------+-------------------+
 |  LOW_IDLE    |   LOW         |   Rising          |   Falling         |
 +--------------+---------------+-------------------+-------------------*/
#define CLK_POLARITY    HIGH_IDLE

/*------------------+-------------------+-------------------+
 |  OPTIONS         |   Leading Edge    |   Trailing Edge   |
 +------------------+-------------------+-------------------+
 |  RECEIVE_ON_LEAD |   Receive         |   Send            |
 +------------------+-------------------+-------------------+
 |  SEND_ON_LEAD    |   Send            |   Receive         |
 +------------------+-------------------+-------------------*/
#define CLK_PHASE   SEND_ON_LEAD

/*--------------+---------------+
 |  OPTIONS     |   Clock Rate  |
 +--------------+---------------+
 |  DIV_BY_4    |   fosc/4      |
 +--------------+---------------+
 |  DIV_BY_16   |   fosc/16     |
 +--------------+---------------+
 |  DIV_BY_64   |   fosc/64     |
 +--------------+---------------+
 |  DIV_BY_128  |   fosc/128    |
 +--------------+---------------
 |  You can divide every clock  |
 |  above by 2, by enabling     |
 |  SPI2X with (ENB_2X) or      |
 |  use regular speed by leving |
 |  it disabled (DIS_2X)        |
 +------------------------------*/
#define SCK_FREQ    DIV_BY_4
#define SPI2X       DIS_2X

#endif

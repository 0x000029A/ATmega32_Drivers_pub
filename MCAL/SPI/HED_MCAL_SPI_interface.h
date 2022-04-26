#ifndef HED_MCAL_SPI_INTERFACE_H_
#define HED_MCAL_SPI_INTERFACE_H_

/*****************************************
 * Arguments:                            *
 *           Void                        *
 * Return:                               *
 *        Void                           *
 * Description: initialize SPI as master *
 *****************************************/
void SPI_MASTER_INIT(void);

/*****************************************
 * Arguments:                            *
 *           Void                        *
 * Return:                               *
 *        Void                           *
 * Description: initialize SPI as slave  *
 *****************************************/
void SPI_SLAVE_INIT(void);

/*****************************************
 * Arguments:                            *
 *           SPI_TDATA                   *
 * Return:                               *
 *        Void                           *
 * Description: transmit SPI_TDATA, an   * 
 *              8-bit data to slave      *
 *****************************************/
void SPI_MASTER_TRANSMIT(u8 COPY_u8_PRV_MCAL_SPI_TDATA);

/*****************************************
 * Arguments:                            *
 *           Void                        *
 * Return:                               *
 *        The received 8-bit             *
 *        data from master               *
 * Description: Receive data from master *
 *****************************************/
u8 SPI_SLAVE_RECEIVE(void);

/*******************************************
 * Arguments:                              *
 *           Void                          *
 * Return:                                 *
 *        1: If write collision flag       *
 *           is set.                       *
 *        0: If write collision flag       *
 *           is clear.                     *
 * Description: Return 1 if written during *
 *              a data transfer.           *
 *******************************************/
u8 SPI_WRITE_COLLISION_FLAG(void);

void SPI_SS_ENB_void(void);
void SPI_SS_DIS_void(void);

#endif

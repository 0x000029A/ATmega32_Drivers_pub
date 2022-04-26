#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "../../MCAL/DIO/HED_MCAL_DIO_interface.h"
#include "HED_HAL_KPD_config.h"
#include "HED_HAL_KPD_private.h"
#include "HED_HAL_KPD_interface.h"

u8 getPressedKey_u8_KPD(void)
{
    u8 LOC_u8_PRESSED_KEY = NOT_PRESSED_KPD_u8;
    u8 LOC_u8_COL_IND, LOC_u8_ROW_IND;
    u8 LOC_u8_PIN_STATE;

    static u8 LOC_u8_KPD_ARR[PRV_ROW_NUM][PRV_COL_NUM] = KPD_ARR_VAL_KPD_u8;
    static u8 LOC_u8_KPD_ROW_ARR[PRV_ROW_NUM] = KPD_ROW_PINS;
    static u8 LOC_u8_KPD_COL_ARR[PRV_COL_NUM] = KPD_COL_PINS;
    
    for (LOC_u8_COL_IND = 0; LOC_u8_COL_IND < PRV_COL_NUM; LOC_u8_COL_IND++)
    {
        DIO_setPinStatus_u8(PORT_KPD_u8, LOC_u8_KPD_COL_ARR[LOC_u8_COL_IND], OUTPUT);
        DIO_setPinValue_u8(PORT_KPD_u8, LOC_u8_KPD_COL_ARR[LOC_u8_COL_IND], LOW);
        for (LOC_u8_ROW_IND = 0; LOC_u8_ROW_IND < PRV_ROW_NUM; LOC_u8_ROW_IND++)
        {
            DIO_setPinStatus_u8(PORT_KPD_u8, LOC_u8_KPD_ROW_ARR[LOC_u8_ROW_IND], INPUT);
            DIO_setPinValue_u8(PORT_KPD_u8, LOC_u8_KPD_ROW_ARR[LOC_u8_ROW_IND], HIGH);
            DIO_getPinValue_u8(PORT_KPD_u8, LOC_u8_KPD_ROW_ARR[LOC_u8_ROW_IND], &LOC_u8_PIN_STATE);
            if (!LOC_u8_PIN_STATE)
            {
                LOC_u8_PRESSED_KEY = LOC_u8_KPD_ARR[LOC_u8_ROW_IND][LOC_u8_COL_IND];
                while (!LOC_u8_PIN_STATE)
                {
                    DIO_getPinValue_u8(PORT_KPD_u8, LOC_u8_KPD_ROW_ARR[LOC_u8_ROW_IND], &LOC_u8_PIN_STATE);
                }
                return LOC_u8_PRESSED_KEY;
            }
        }
        DIO_setPinValue_u8(PORT_KPD_u8, LOC_u8_KPD_COL_ARR[LOC_u8_COL_IND], HIGH);
    }
    return LOC_u8_PRESSED_KEY;
}
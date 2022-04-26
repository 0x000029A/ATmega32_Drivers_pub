#include "../../LIB/LIB_VRT_STD_TYPES.h"
#include "HED_MCAL_WDT_interface.h"
#include "HED_MCAL_WDT_register.h"
#include "HED_MCAL_WDT_private.h"
#include "HED_MCAL_WDT_config.h"

void WDT_ON()
{
    u8_PRV_MCAL_WATCHDOG_WDTCR |= WD_WDTCR_WDE | WDT_PRS_SLCT;
}

void WDT_OFF()
{
    u8_PRV_MCAL_WATCHDOG_WDTCR |= WD_WDTCR_WDTOE | WD_WDTCR_WDE;
    u8_PRV_MCAL_WATCHDOG_WDTCR = WDTCR_OFF;
}
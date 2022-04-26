#ifndef HED_MCAL_WDT_REGISTER_H_
#define HED_MCAL_WDT_REGISTER_H_

#define u8_PRV_MCAL_WATCHDOG_MCUCSR *((volatile u8*)0x54)
#define WD_MCUCSR_WDRF              (0b00001000)

#define u8_PRV_MCAL_WATCHDOG_WDTCR  *((volatile u8*)0x41)
#define WD_WDTCR_WDTOE              (0b00010000)
#define WD_WDTCR_WDE                (0b00001000)
#define WD_WDTCR_WDP2               (0b00000100)
#define WD_WDTCR_WDP1               (0b00000010)
#define WD_WDTCR_WDP0               (0b00000001)

#endif
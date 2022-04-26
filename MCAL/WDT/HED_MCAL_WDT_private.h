#ifndef HED_MCAL_WDT_PRIVATE_H_
#define HED_MCAL_WDT_PRIVATE_H_

#define MODE0       (0)
#define MODE1       (WD_WDTCR_WDP0)
#define MODE2       (WD_WDTCR_WDP1)
#define MODE3       (WD_WDTCR_WDP0 | WD_WDTCR_WDP1)
#define MODE4       (WD_WDTCR_WDP2)
#define MODE5       (WD_WDTCR_WDP0 | WD_WDTCR_WDP2)
#define MODE6       (WD_WDTCR_WDP1 | WD_WDTCR_WDP2)
#define MODE7       (WD_WDTCR_WDP0 | WD_WDTCR_WDP1 | WD_WDTCR_WDP2)

#define WDTCR_OFF   0x00

#endif
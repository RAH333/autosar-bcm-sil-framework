#ifndef BCM_WINDOW_CONTROL_SWC_H
#define BCM_WINDOW_CONTROL_SWC_H

#include "../rte/Rte_BcmControl.h"

/* Anti-Pinch Safety Current Threshold (MISRA-C Constant) */
#define BCM_ANTI_PINCH_THRESHOLD_MA ((MotorCurrent_mA_t)12000U)

void BcmWindow_Init(void);
void BcmWindow_MainFunction_10ms(void);

#endif /* BCM_WINDOW_CONTROL_SWC_H */

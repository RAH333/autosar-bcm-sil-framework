#ifndef DCM_UDS_H
#define DCM_UDS_H

#include "../rte/Rte_Type.h"

/* ISO 14229 UDS Service IDs */
#define UDS_SID_READ_DATA_BY_ID     ((uint8_t)0x22U)
#define UDS_SID_CLEAR_DIAG_INFO     ((uint8_t)0x14U)
#define UDS_POSITIVE_RESPONSE_OFFSET ((uint8_t)0x40U)
#define UDS_NEGATIVE_RESPONSE_SID   ((uint8_t)0x7FU)

/* Data Identifiers (DIDs) */
#define DID_WINDOW_MOTOR_STATE      ((uint16_t)0xF190U)
#define DID_PINCH_FAULT_COUNT       ((uint16_t)0xF191U)

void Dcm_ReportPinchFault(void);
uint8_t Dcm_GetPinchFaultCount(void);
uint8_t Dcm_ProcessUdsRequest(const uint8_t* reqData, uint8_t reqLen, uint8_t* respData);

#endif /* DCM_UDS_H */

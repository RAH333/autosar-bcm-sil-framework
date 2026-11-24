#include "Dcm_Uds.h"
#include "../rte/Rte_BcmControl.h"

static uint8_t pinchFaultCounter = 0U;

void Dcm_ReportPinchFault(void) {
    if (pinchFaultCounter < 255U) {
        pinchFaultCounter++;
    }
}

uint8_t Dcm_GetPinchFaultCount(void) {
    return pinchFaultCounter;
}

uint8_t Dcm_ProcessUdsRequest(const uint8_t* reqData, uint8_t reqLen, uint8_t* respData) {
    if ((reqData == NULL) || (respData == NULL) || (reqLen == 0U)) {
        return 0U;
    }

    uint8_t sid = reqData[0];

    /* Service 0x22: ReadDataByIdentifier */
    if ((sid == UDS_SID_READ_DATA_BY_ID) && (reqLen >= 3U)) {
        uint16_t did = ((uint16_t)reqData[1] << 8U) | (uint16_t)reqData[2];
        respData[0] = sid + UDS_POSITIVE_RESPONSE_OFFSET; /* 0x62 */
        respData[1] = reqData[1];
        respData[2] = reqData[2];

        if (did == DID_WINDOW_MOTOR_STATE) {
            respData[3] = (uint8_t)Rte_Sim_ReadMotorState();
            return 4U;
        } else if (did == DID_PINCH_FAULT_COUNT) {
            respData[3] = pinchFaultCounter;
            return 4U;
        }
    }

    /* Service 0x14: ClearDiagnosticInformation */
    if (sid == UDS_SID_CLEAR_DIAG_INFO) {
        pinchFaultCounter = 0U;
        respData[0] = sid + UDS_POSITIVE_RESPONSE_OFFSET; /* 0x54 */
        return 1U;
    }

    /* Negative Response (NRC 0x11: Service Not Supported) */
    respData[0] = UDS_NEGATIVE_RESPONSE_SID;
    respData[1] = sid;
    respData[2] = 0x11U;
    return 3U;
}

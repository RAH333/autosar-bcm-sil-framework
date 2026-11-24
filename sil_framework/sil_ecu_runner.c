#include <stdio.h>
#include <stdlib.h>
#include "../swc/BcmWindowControl_SWC.h"
#include "../bsw/Dcm_Uds.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <switch_cmd> <motor_current_mA>\n", argv[0]);
        return 1;
    }

    WindowCmd_t       cmd     = (WindowCmd_t)atoi(argv[1]);
    MotorCurrent_mA_t current = (MotorCurrent_mA_t)atoi(argv[2]);

    /* Initialize BCM Software Component */
    BcmWindow_Init();

    /* Inject Test Stimulus into RTE */
    Rte_Sim_InjectSwitchCmd(cmd);
    Rte_Sim_InjectMotorCurrent(current);

    /* Execute 10ms Cyclic Runnable */
    BcmWindow_MainFunction_10ms();

    /* Send UDS 0x22 ReadDataByIdentifier (DID 0xF190: Motor State) */
    uint8_t udsReq[3]  = {0x22U, 0xF1U, 0x90U};
    uint8_t udsResp[8] = {0U};
    uint8_t respLen    = Dcm_ProcessUdsRequest(udsReq, 3U, udsResp);

    printf("SIL_TELEMETRY|MOTOR_STATE:%u|PINCH_FAULTS:%u|UDS_SID:0x%02X|UDS_VAL:%u|RESP_LEN:%u\n",
           Rte_Sim_ReadMotorState(),
           Dcm_GetPinchFaultCount(),
           udsResp[0],
           udsResp[3],
           respLen);

    return 0;
}

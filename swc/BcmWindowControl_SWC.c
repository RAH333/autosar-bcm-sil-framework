#include "BcmWindowControl_SWC.h"
#include "../bsw/Dcm_Uds.h"

void BcmWindow_Init(void) {
    (void)Rte_Write_PpMotorControl_State(MOTOR_STOPPED);
}

void BcmWindow_MainFunction_10ms(void) {
    WindowCmd_t        switchCmd    = WIN_CMD_IDLE;
    MotorCurrent_mA_t  motorCurrent = 0U;
    WindowMotorState_t targetState  = MOTOR_STOPPED;

    if ((Rte_Read_RpWindowSwitch_Cmd(&switchCmd) == E_OK) &&
        (Rte_Read_RpMotorCurrent_Value(&motorCurrent) == E_OK)) {

        if (switchCmd == WIN_CMD_UP) {
            /* Safety Check: Anti-pinch obstacle detection during upward travel */
            if (motorCurrent > BCM_ANTI_PINCH_THRESHOLD_MA) {
                targetState = MOTOR_PINCH_REVERSE;
                Dcm_ReportPinchFault();
            } else {
                targetState = MOTOR_MOVING_UP;
            }
        } else if (switchCmd == WIN_CMD_DOWN) {
            targetState = MOTOR_MOVING_DOWN;
        } else {
            targetState = MOTOR_STOPPED;
        }

        (void)Rte_Write_PpMotorControl_State(targetState);
    }
}

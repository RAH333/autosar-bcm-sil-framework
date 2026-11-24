#include "Rte_BcmControl.h"
#include "../bsw/CanIf.h"

static WindowCmd_t        Rte_Buf_SwitchCmd    = WIN_CMD_IDLE;
static MotorCurrent_mA_t  Rte_Buf_MotorCurrent = 0U;
static WindowMotorState_t Rte_Buf_MotorState   = MOTOR_STOPPED;

Std_ReturnType Rte_Read_RpWindowSwitch_Cmd(WindowCmd_t* cmd) {
    if (cmd == NULL) {
        return E_NOT_OK;
    }
    *cmd = Rte_Buf_SwitchCmd;
    return E_OK;
}

Std_ReturnType Rte_Read_RpMotorCurrent_Value(MotorCurrent_mA_t* current) {
    if (current == NULL) {
        return E_NOT_OK;
    }
    *current = Rte_Buf_MotorCurrent;
    return E_OK;
}

Std_ReturnType Rte_Write_PpMotorControl_State(WindowMotorState_t state) {
    Rte_Buf_MotorState = state;
    uint8_t canFrame[4];
    canFrame[0] = state;
    canFrame[1] = Rte_Buf_SwitchCmd;
    canFrame[2] = (uint8_t)(Rte_Buf_MotorCurrent >> 8U);
    canFrame[3] = (uint8_t)(Rte_Buf_MotorCurrent & 0xFFU);
    return CanIf_Transmit(0x210U, canFrame, 4U);
}

void Rte_Sim_InjectSwitchCmd(WindowCmd_t cmd) {
    Rte_Buf_SwitchCmd = cmd;
}

void Rte_Sim_InjectMotorCurrent(MotorCurrent_mA_t current) {
    Rte_Buf_MotorCurrent = current;
}

WindowMotorState_t Rte_Sim_ReadMotorState(void) {
    return Rte_Buf_MotorState;
}

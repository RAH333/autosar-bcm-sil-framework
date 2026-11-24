#ifndef RTE_BCM_CONTROL_H
#define RTE_BCM_CONTROL_H

#include "Rte_Type.h"

/* Sender-Receiver Read Interfaces (From LIN/CAN Switch & Current Sensor) */
Std_ReturnType Rte_Read_RpWindowSwitch_Cmd(WindowCmd_t* cmd);
Std_ReturnType Rte_Read_RpMotorCurrent_Value(MotorCurrent_mA_t* current);

/* Sender-Receiver Write Interfaces (To Window Actuator & CAN Bus) */
Std_ReturnType Rte_Write_PpMotorControl_State(WindowMotorState_t state);

/* SIL Simulation Injection & Inspection Helpers */
void Rte_Sim_InjectSwitchCmd(WindowCmd_t cmd);
void Rte_Sim_InjectMotorCurrent(MotorCurrent_mA_t current);
WindowMotorState_t Rte_Sim_ReadMotorState(void);

#endif /* RTE_BCM_CONTROL_H */

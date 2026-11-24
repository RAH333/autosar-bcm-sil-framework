#ifndef RTE_TYPE_H
#define RTE_TYPE_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t Std_ReturnType;

#define E_OK        ((Std_ReturnType)0x00U)
#define E_NOT_OK    ((Std_ReturnType)0x01U)

/* BCM Window Switch Commands */
typedef uint8_t WindowCmd_t;
#define WIN_CMD_IDLE        ((WindowCmd_t)0x00U)
#define WIN_CMD_UP          ((WindowCmd_t)0x01U)
#define WIN_CMD_DOWN        ((WindowCmd_t)0x02U)

/* BCM Window Motor States */
typedef uint8_t WindowMotorState_t;
#define MOTOR_STOPPED       ((WindowMotorState_t)0x00U)
#define MOTOR_MOVING_UP     ((WindowMotorState_t)0x01U)
#define MOTOR_MOVING_DOWN   ((WindowMotorState_t)0x02U)
#define MOTOR_PINCH_REVERSE ((WindowMotorState_t)0x03U)

/* Motor Current in Milliamps (for Anti-Pinch Detection) */
typedef uint16_t MotorCurrent_mA_t;

#endif /* RTE_TYPE_H */

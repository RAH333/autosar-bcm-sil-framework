#include "CanIf.h"
#include <stdio.h>

Std_ReturnType CanIf_Transmit(uint16_t CanTxPduId, const uint8_t* PduDataPtr, uint8_t Length) {
    if ((PduDataPtr == NULL) || (Length < 4U)) {
        return E_NOT_OK;
    }
    printf("[CAN-TX] ID:0x%03X DLC:%u DATA:%02X %02X %02X %02X\n",
           CanTxPduId, Length, PduDataPtr[0], PduDataPtr[1], PduDataPtr[2], PduDataPtr[3]);
    return E_OK;
}

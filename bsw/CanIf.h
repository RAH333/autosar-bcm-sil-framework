#ifndef CANIF_H
#define CANIF_H

#include "../rte/Rte_Type.h"

Std_ReturnType CanIf_Transmit(uint16_t CanTxPduId, const uint8_t* PduDataPtr, uint8_t Length);

#endif /* CANIF_H */

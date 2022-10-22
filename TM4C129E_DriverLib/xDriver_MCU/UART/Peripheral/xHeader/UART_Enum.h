/**
 *
 * @file UART_Enum.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 22 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_UART_PERIPHERAL_XHEADER_UART_ENUM_H_
#define XDRIVER_MCU_UART_PERIPHERAL_XHEADER_UART_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    UART_enERROR_OK = (UBase_t) MCU_enERROR_OK,
    UART_enERROR_POINTER = (UBase_t) MCU_enERROR_POINTER,
    UART_enERROR_VALUE = (UBase_t) MCU_enERROR_VALUE,
    UART_enERROR_RANGE = (UBase_t) MCU_enERROR_RANGE,
    UART_enERROR_EMPTY = (UBase_t) MCU_enERROR_EMPTY,
    UART_enERROR_FULL = (UBase_t) MCU_enERROR_FULL,
    UART_enERROR_TIMEOUT = (UBase_t) MCU_enERROR_TIMEOUT,
    UART_enERROR_UNDEF = (UBase_t) MCU_enERROR_UNDEF,
}UART_nERROR;

typedef enum
{
    UART_enSTATE_DIS = (UBase_t) MCU_enSTATE_DIS,
    UART_enSTATE_ENA = (UBase_t) MCU_enSTATE_ENA,
    UART_enSTATE_UNDEF = (UBase_t) MCU_enSTATE_UNDEF,
}UART_nSTATE;

typedef enum
{
    UART_enSTATUS_INACTIVE = (UBase_t) MCU_enSTATUS_INACTIVE,
    UART_enSTATUS_ACTIVE = (UBase_t) MCU_enSTATUS_ACTIVE,
    UART_enSTATUS_UNDEF = (UBase_t) MCU_enSTATUS_UNDEF,
}UART_nSTATUS;

typedef enum
{
    UART_enFALSE = (UBase_t) FALSE,
    UART_enTRUE = (UBase_t) TRUE,
    UART_enPENDSTATE_UNDEF = UNDEF_VALUE,
}UART_nBOOLEAN;

typedef enum
{
    UART_enPRI0 = (UBase_t) MCU_enPRI0,
    UART_enPRI1 = (UBase_t) MCU_enPRI1,
    UART_enPRI2 = (UBase_t) MCU_enPRI2,
    UART_enPRI3 = (UBase_t) MCU_enPRI3,
    UART_enPRI4 = (UBase_t) MCU_enPRI4,
    UART_enPRI5 = (UBase_t) MCU_enPRI5,
    UART_enPRI6 = (UBase_t) MCU_enPRI6,
    UART_enPRI7 = (UBase_t) MCU_enPRI7,
    UART_enPRIMAX = (UBase_t) MCU_enPRIMAX,
    UART_enDEFAULT = (UBase_t) MCU_enDEFAULT,
}UART_nPRIORITY;

typedef enum
{
    UART_enMODULE_0 = 0UL,
    UART_enMODULE_1 = 1UL,
    UART_enMODULE_2 = 2UL,
    UART_enMODULE_3 = 3UL,
    UART_enMODULE_4 = 4UL,
    UART_enMODULE_5 = 5UL,
    UART_enMODULE_6 = 6UL,
    UART_enMODULE_7 = 7UL,
    UART_enMODULE_MAX = 8UL,
}UART_nMODULE;

typedef enum
{
    UART_enINT_RING_INDICATOR = 0UL,
    UART_enINT_CLEAR_TO_SEND = 1UL,
    UART_enINT_DATA_CARRIER_DETECT = 2UL,
    UART_enINT_DATA_SET_READY = 3UL,
    UART_enINT_RECEIVE = 4UL,
    UART_enINT_TRANSMIT = 5UL,
    UART_enINT_RECEIVE_TIMEOUT = 6UL,
    UART_enINT_FRAME_ERROR = 7UL,
    UART_enINT_PARITY_ERROR = 8UL,
    UART_enINT_BREAK_ERROR = 9UL,
    UART_enINT_OVERRUN_ERROR = 10UL,
    UART_enINT_END_OF_TRANSMISSION = 11UL,
    UART_enINT_BIT9_MODE = 12UL,
    UART_enINT_DMA_RECEIVE = 13UL,
    UART_enINT_DMA_TRANSMIT = 14UL,
    UART_enINT_SW = 15UL,
    UART_enINT_MAX = 16UL,
    UART_enINT_UNDEF = UNDEF_VALUE,
}UART_nINT;

typedef enum
{
    UART_enINTMASK_NONE = 0x0UL,
    UART_enINTMASK_RING_INDICATOR = 0x1UL,
    UART_enINTMASK_CLEAR_TO_SEND = 0x2UL,
    UART_enINTMASK_DATA_CARRIER_DETECT = 0x4UL,
    UART_enINTMASK_DATA_SET_READY = 0x8UL,
    UART_enINTMASK_RECEIVE = 0x10UL,
    UART_enINTMASK_TRANSMIT = 0x20UL,
    UART_enINTMASK_RECEIVE_TIMEOUT = 0x40UL,
    UART_enINTMASK_FRAME_ERROR = 0x80UL,
    UART_enINTMASK_PARITY_ERROR = 0x100UL,
    UART_enINTMASK_BREAK_ERROR = 0x200UL,
    UART_enINTMASK_OVERRUN_ERROR = 0x400UL,
    UART_enINTMASK_END_OF_TRANSMISSION = 0x800UL,
    UART_enINTMASK_BIT9_MODE = 0x1000UL,
    UART_enINTMASK_DMA_RECEIVE = 0x10000UL,
    UART_enINTMASK_DMA_TRANSMIT = 0x20000UL,
    UART_enINTMASK_ALL = 0x31FFFUL,
    UART_enINTMASK_MAX = 0x40000UL,
    UART_enINTMASK_UNDEF = UNDEF_VALUE,
}UART_nINTMASK;

typedef enum
{
    UART_enBUSY_IDLE = 0UL,
    UART_enBUSY_BUSY = 1UL,
    UART_enBUSY_UNDEF = UNDEF_VALUE,
}UART_nBUSY;

typedef enum
{
    UART_enCTS_NOASSERT = 0UL,
    UART_enCTS_ASSERT = 1UL,
    UART_enCTS_UNDEF = UNDEF_VALUE,
}UART_nCTS;

typedef enum
{
    UART_enFIFO_NO_EMPTY = 0UL,
    UART_enFIFO_EMPTY = 1UL,
    UART_enFIFO_EMPTY_UNDEF = UNDEF_VALUE,
}UART_nFIFO_EMPTY;

typedef enum
{
    UART_enFIFO_NO_FULL = 0UL,
    UART_enFIFO_FULL = 1UL,
    UART_enFIFO_FULL_UNDEF = UNDEF_VALUE,
}UART_nFIFO_FULL;

typedef enum
{
    UART_enBREAK_DIS = 0UL,
    UART_enBREAK_ACTIVE = 1UL,
    UART_enBREAK_UNDEF = UNDEF_VALUE,
}UART_nBREAK;

typedef enum
{
    UART_enPARITY_TYPE_ODD = 0UL,
    UART_enPARITY_TYPE_ADDRESS = 0UL,
    UART_enPARITY_TYPE_EVEN = 1UL,
    UART_enPARITY_TYPE_DATA = 1UL,
    UART_enPARITY_TYPE_UNDEF = UNDEF_VALUE,
}UART_nPARITY_TYPE;

typedef enum
{
    UART_enSTOP_ONE = 0UL,
    UART_enSTOP_TWO = 1UL,
    UART_enSTOP_UNDEF = UNDEF_VALUE,
}UART_nSTOP;

typedef enum
{
    UART_enLENGTH_5BITS = 0UL,
    UART_enLENGTH_6BITS = 1UL,
    UART_enLENGTH_7BITS = 2UL,
    UART_enLENGTH_8BITS = 3UL,
    UART_enLENGTH_UNDEF = UNDEF_VALUE,
}UART_nLENGTH;

typedef enum
{
    UART_enFIFO_LEVEL_2_16 = 0UL,
    UART_enFIFO_LEVEL_4_16 = 1UL,
    UART_enFIFO_LEVEL_8_16 = 2UL,
    UART_enFIFO_LEVEL_12_16 = 3UL,
    UART_enFIFO_LEVEL_14_16 = 4UL,
    UART_enFIFO_LEVEL_UNDEF = UNDEF_VALUE,
}UART_nFIFO_LEVEL;

typedef enum
{
    UART_enMODE_NORMAL = 0UL,
    UART_enMODE_NORMAL_MP = 1UL,
    UART_enMODE_MODEM = 2UL,
    UART_enMODE_MODEM_MP = 3UL,
    UART_enMODE_SIR = 4UL,
    UART_enMODE_SIR_LP = 5UL,
    UART_enMODE_SIR_MP = 6UL,
    UART_enMODE_SIR_LP_MP = 7UL,
    UART_enMODE_SMART_CARD = 8UL,
    UART_enMODE_UNDEF = UNDEF_VALUE,
}UART_nMODE;

typedef enum
{
    UART_enCLOCK_SYSCLK = 0UL,
    UART_enCLOCK_PIOSC = 5UL,
    UART_enCLOCK_UNDEF = UNDEF_VALUE,
}UART_nCLOCK;

typedef enum
{
    UART_enEOT_FIFO = 0UL,
    UART_enEOT_ALL = 1UL,
    UART_enEOT_UNDEF = UNDEF_VALUE,
}UART_nEOT;

typedef enum
{
    UART_enLINE_MODE_SOFT = 0UL,
    UART_enLINE_MODE_HARD = 1UL,
    UART_enLINE_MODE_UNDEF = UNDEF_VALUE,
}UART_nLINE_MODE;

typedef enum
{
    UART_enLEVEL_LOW = 0UL,
    UART_enLEVEL_HIGH = 1UL,
    UART_enLEVEL_UNDEF = UNDEF_VALUE,
}UART_nLEVEL;

typedef enum
{
    UART_enLINE_SELECT_PRIMARY = 0UL,
    UART_enLINE_SELECT_ALT = 1UL,
    UART_enLINE_SELECT_ALT2 = 2UL,
    UART_enLINE_SELECT_UNDEF = UNDEF_VALUE,
}UART_nLINE_SELECT;

typedef struct
{
    UART_nSTATE enParity;
    UART_nPARITY_TYPE enParityType;
    UART_nSTATE enParityStick;
}UART_PARITY_t;

typedef struct
{
    UART_nEOT enEndOfTransmission;
    UART_nSTATE enLoopback;
    UART_nSTATE enRxLine;
    UART_nSTATE enTxLine;
    UART_nLINE_MODE enRTSMode;
    UART_nLINE_MODE enCTSMode;
    UART_nSTATE enDCDLine;
    UART_nSTATE enDSRLine;
    UART_nSTATE enDTRLine;
    UART_nSTATE enRILine;
}UART_CONTROL_t;

typedef struct
{
    UART_nLINE_SELECT enRx;
    UART_nLINE_SELECT enTx;
    UART_nLINE_SELECT enCTS;
    UART_nLINE_SELECT enRTS;
    UART_nLINE_SELECT enDCD;
    UART_nLINE_SELECT enDSR;
    UART_nLINE_SELECT enDTR;
    UART_nLINE_SELECT enRI;
}UART_LINE_t;

typedef struct
{
    UART_nSTATE enFifo;
    UART_nSTOP enStop;
    UART_nSTATE enParity;
    UART_nPARITY_TYPE enParityType;
    UART_nSTATE enParityStick;
    UART_nLENGTH enLength;
}UART_LINE_CONTROL_t;

typedef MCU_Register_t UART_Register_t;
typedef MCU_pvfIRQVectorHandler_t UART_pvfIRQVectorHandler_t;
typedef MCU_pvfIRQSourceHandler_t UART_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_UART_PERIPHERAL_XHEADER_UART_ENUM_H_ */

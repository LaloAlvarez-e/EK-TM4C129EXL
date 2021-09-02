/**
 *
 * @file I2C_Enum.h
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
 * @verbatim 3 mar. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 3 mar. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_I2C_PERIPHERAL_XHEADER_I2C_ENUM_H_
#define XDRIVER_MCU_I2C_PERIPHERAL_XHEADER_I2C_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

/**
 * Status Definitions
 */
typedef enum
{
    I2C_enSTATUS_OK = 0UL,            /*!< I2C_enSTATUS_OK */
    I2C_enSTATUS_ERROR = 1UL,         /*!< I2C_enSTATUS_ERROR */
    I2C_enSTATUS_UNDEF = 0xFFFFFFFFUL,/*!< I2C_enSTATUS_UNDEF */
}I2C_nSTATUS;

/**
 * Module Ready
 */
typedef enum
{
    I2C_enNOREADY = 0UL,/*!< I2C_enNOREADY */
    I2C_enREADY = 1UL,  /*!< I2C_enREADY */
}I2C_nREADY;

/**
 * Module numbers
 */
typedef enum
{
    I2C_enMODULE_0 = 0UL,   /*!< I2C_enMODULE_0 */
    I2C_enMODULE_1 = 1UL,   /*!< I2C_enMODULE_1 */
    I2C_enMODULE_2 = 2UL,   /*!< I2C_enMODULE_2 */
    I2C_enMODULE_3 = 3UL,   /*!< I2C_enMODULE_3 */
    I2C_enMODULE_4 = 4UL,   /*!< I2C_enMODULE_4 */
    I2C_enMODULE_5 = 5UL,   /*!< I2C_enMODULE_5 */
    I2C_enMODULE_6 = 6UL,   /*!< I2C_enMODULE_6 */
    I2C_enMODULE_7 = 7UL,   /*!< I2C_enMODULE_7 */
    I2C_enMODULE_8 = 8UL,   /*!< I2C_enMODULE_8 */
    I2C_enMODULE_9 = 9UL,   /*!< I2C_enMODULE_9 */
    I2C_enMODULE_MAX = 10UL,/*!< I2C_enMODULE_MAX */
}I2C_nMODULE;

/**
 * Module Priority
 */
typedef enum
{
    I2C_enPRI0 = 0UL,            /*!< I2C_enPRI0 */
    I2C_enPRI1 = 1UL,            /*!< I2C_enPRI1 */
    I2C_enPRI2 = 2UL,            /*!< I2C_enPRI2 */
    I2C_enPRI3 = 3UL,            /*!< I2C_enPRI3 */
    I2C_enPRI4 = 4UL,            /*!< I2C_enPRI4 */
    I2C_enPRI5 = 5UL,            /*!< I2C_enPRI5 */
    I2C_enPRI6 = 6UL,            /*!< I2C_enPRI6 */
    I2C_enPRI7 = 7UL,            /*!< I2C_enPRI7 */
    I2C_enDEFAULT = 0xFFFFFFFFUL,/*!< I2C_enDEFAULT */
}I2C_nPRIORITY;

/**
 * I2C Master interrupts
 */
typedef enum
{
    I2C_enMASTER_INTERRUPT_SW = 0UL,
    I2C_enMASTER_INTERRUPT_MASTER = 1UL,
    I2C_enMASTER_INTERRUPT_CLOCK_TIMEOUT = 2UL,
    I2C_enMASTER_INTERRUPT_RECEIVE_DMA = 3UL,
    I2C_enMASTER_INTERRUPT_TRANSMIT_DMA = 4UL,
    I2C_enMASTER_INTERRUPT_ADDR_DATA_NACK = 5UL,
    I2C_enMASTER_INTERRUPT_START_DETECTION = 6UL,
    I2C_enMASTER_INTERRUPT_STOP_DETECTION = 7UL,
    I2C_enMASTER_INTERRUPT_ARBITRATION_LOST = 8UL,
    I2C_enMASTER_INTERRUPT_TRANSMIT_FIFO_REQ = 9UL,
    I2C_enMASTER_INTERRUPT_RECEIVE_FIFO_REQ = 10UL,
    I2C_enMASTER_INTERRUPT_TRANSMIT_FIFO_EMPTY = 11UL,
    I2C_enMASTER_INTERRUPT_RECEIVE_FIFO_FULL = 12UL,
    I2C_enMASTER_INTERRUPT_MAX = 13UL,
}I2C_nMASTER_INTERRUPT;

typedef enum
{
    I2C_enMASTER_INT_SOURCE_MASTER = 0x1UL,
    I2C_enMASTER_INT_SOURCE_CLOCK_TIMEOUT = 0x2UL,
    I2C_enMASTER_INT_SOURCE_RECEIVE_DMA = 0x4UL,
    I2C_enMASTER_INT_SOURCE_TRANSMIT_DMA = 0x8UL,
    I2C_enMASTER_INT_SOURCE_ADDR_DATA_NACK = 0x10UL,
    I2C_enMASTER_INT_SOURCE_START_DETECTION = 0x20UL,
    I2C_enMASTER_INT_SOURCE_STOP_DETECTION = 0x40UL,
    I2C_enMASTER_INT_SOURCE_ARBITRATION_LOST = 0x80UL,
    I2C_enMASTER_INT_SOURCE_TRANSMIT_FIFO_REQ = 0x100UL,
    I2C_enMASTER_INT_SOURCE_RECEIVE_FIFO_REQ = 0x200UL,
    I2C_enMASTER_INT_SOURCE_TRANSMIT_FIFO_EMPTY = 0x400UL,
    I2C_enMASTER_INT_SOURCE_RECEIVE_FIFO_FULL = 0x800UL,
    I2C_enMASTER_INT_SOURCE_ALL = 0xFFFUL,
}I2C_nMASTER_INT_SOURCE;

/**
 * I2C Slave interrupts
 */
typedef enum
{
    I2C_enSLAVE_INTERRUPT_SW = 0UL,               /*!< I2C_enSLAVE_INTERRUPT_SW */
    I2C_enSLAVE_INTERRUPT_DATA = 1UL,               /*!< I2C_enSLAVE_INTERRUPT_DATA */
    I2C_enSLAVE_INTERRUPT_START_CONDITION = 2UL,    /*!< I2C_enSLAVE_INTERRUPT_START_CONDITION */
    I2C_enSLAVE_INTERRUPT_STOP_CONDITION = 3UL,     /*!< I2C_enSLAVE_INTERRUPT_STOP_CONDITION */
    I2C_enSLAVE_INTERRUPT_RECEIVE_DMA = 4UL,        /*!< I2C_enSLAVE_INTERRUPT_RECEIVE_DMA */
    I2C_enSLAVE_INTERRUPT_TRANSMIT_DMA = 5UL,       /*!< I2C_enSLAVE_INTERRUPT_TRANSMIT_DMA */
    I2C_enSLAVE_INTERRUPT_TRANSMIT_FIFO_REQ = 6UL,  /*!< I2C_enSLAVE_INTERRUPT_TRANSMIT_FIFO_REQ */
    I2C_enSLAVE_INTERRUPT_RECEIVE_FIFO_REQ = 7UL,   /*!< I2C_enSLAVE_INTERRUPT_RECEIVE_FIFO_REQ */
    I2C_enSLAVE_INTERRUPT_TRANSMIT_FIFO_EMPTY = 8UL,/*!< I2C_enSLAVE_INTERRUPT_TRANSMIT_FIFO_EMPTY */
    I2C_enSLAVE_INTERRUPT_RECEIVE_FIFO_FULL = 9UL,  /*!< I2C_enSLAVE_INTERRUPT_RECEIVE_FIFO_FULL */
    I2C_enSLAVE_INTERRUPT_MAX = 10UL,                /*!< I2C_enSLAVE_INTERRUPT_MAX */
}I2C_nSLAVE_INTERRUPT;

typedef enum
{
    I2C_enSLAVE_INT_SOURCE_DATA = 0x1UL,
    I2C_enSLAVE_INT_SOURCE_START_CONDITION = 0x2UL,
    I2C_enSLAVE_INT_SOURCE_STOP_CONDITION = 0x4UL,
    I2C_enSLAVE_INT_SOURCE_RECEIVE_DMA = 0x8UL,
    I2C_enSLAVE_INT_SOURCE_TRANSMIT_DMA = 0x10UL,
    I2C_enSLAVE_INT_SOURCE_TRANSMIT_FIFO_REQ = 0x20UL,
    I2C_enSLAVE_INT_SOURCE_RECEIVE_FIFO_REQ = 0x40UL,
    I2C_enSLAVE_INT_SOURCE_TRANSMIT_FIFO_EMPTY = 0x80UL,
    I2C_enSLAVE_INT_SOURCE_RECEIVE_FIFO_FULL = 0x100UL,
    I2C_enSLAVE_INT_SOURCE_ALL = 0x1FFUL,
}I2C_nSLAVE_INT_SOURCE;

/**
 * I2C interrupt status
 */
typedef enum
{
    I2C_enINT_NOOCCUR = 0UL,              /*!< I2C_enINT_NOOCCUR */
    I2C_enINT_OCCUR = 1UL,                /*!< I2C_enINT_OCCUR */
    I2C_enINT_STATUS_UNDEF = 0xFFFFFFFFUL,/*!< I2C_enINT_STATUS_UNDEF */
} I2C_nINT_STATUS;

/**
 * Master Status controllers
 */

typedef enum
{
    I2C_enMASTER_BUSY_IDLE = 0UL,          /*!< I2C_enMASTER_BUSY_IDLE */
    I2C_enMASTER_BUSY_BUSY = 1UL,          /*!< I2C_enMASTER_BUSY_BUSY */
    I2C_enMASTER_BUSY_UNDEF = 0xFFFFFFFFUL,/*!< I2C_enMASTER_BUSY_UNDEF */
}I2C_nMASTER_BUSY;

typedef enum
{
    I2C_enMASTER_ERROR_NO = 0UL,
    I2C_enMASTER_ERROR_OCCUR = 1UL,
    I2C_enMASTER_ERROR_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_ERROR;

typedef enum
{
    I2C_enMASTER_ACK_ADDR_NO = 0UL,
    I2C_enMASTER_ACK_ADDR_OCCUR = 1UL,
    I2C_enMASTER_ACK_ADDR_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_ACK_ADDR;

typedef enum
{
    I2C_enMASTER_ACK_DATA_NO = 0UL,
    I2C_enMASTER_ACK_DATA_OCCUR = 1UL,
    I2C_enMASTER_ACK_DATA_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_ACK_DATA;

typedef enum
{
    I2C_enMASTER_ARB_WON = 0UL,
    I2C_enMASTER_ARB_LOST = 1UL,
    I2C_enMASTER_ARB_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_ARB;

typedef enum
{
    I2C_enMASTER_IDLE_BUSY = 0UL,
    I2C_enMASTER_IDLE_IDLE = 1UL,
    I2C_enMASTER_IDLE_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_IDLE;

typedef enum
{
    I2C_enMASTER_BUS_BSY_IDLE = 0UL,
    I2C_enMASTER_BUS_BSY_BUSY = 1UL,
    I2C_enMASTER_BUS_BSY_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_BUS_BSY;

typedef enum
{
    I2C_enMASTER_CLOCK_TIMEOUT_NO = 0UL,
    I2C_enMASTER_CLOCK_TIMEOUT_OCCUR = 1UL,
    I2C_enMASTER_CLOCK_TIMEOUT_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_CLOCK_TIMEOUT;

typedef enum
{
    I2C_enMASTER_DMA_ACTIVE_NO = 0UL,
    I2C_enMASTER_DMA_ACTIVE_ACTIVE = 1UL,
    I2C_enMASTER_DMA_ACTIVE_UNDEF = 0xFFFFFFFFUL,
}I2C_nMASTER_DMA_ACTIVE;

typedef enum
{
    I2C_enMASTER_CONTROL_NONE = 0x0UL,

    I2C_enMASTER_CONTROL_RUN = 0x01UL,
    I2C_enMASTER_CONTROL_START = 0x02UL,
    I2C_enMASTER_CONTROL_RUN_START = 0x03UL,
    I2C_enMASTER_CONTROL_STOP = 0x04UL,
    I2C_enMASTER_CONTROL_RUN_STOP = 0x05UL,
    I2C_enMASTER_CONTROL_START_STOP = 0x06UL,
    I2C_enMASTER_CONTROL_RUN_START_STOP = 0x07UL,
    I2C_enMASTER_CONTROL_QUICK_COMMAND = 0x27UL,
    I2C_enMASTER_CONTROL_ACK = 0x08UL,
    I2C_enMASTER_CONTROL_RUN_ACK = 0x09UL,
    I2C_enMASTER_CONTROL_START_ACK = 0x0AUL,
    I2C_enMASTER_CONTROL_RUN_START_ACK = 0x0BUL,
    I2C_enMASTER_CONTROL_STOP_ACK = 0x0CUL,
    I2C_enMASTER_CONTROL_RUN_STOP_ACK = 0x0DUL,
    I2C_enMASTER_CONTROL_START_STOP_ACK = 0x0EUL,
    I2C_enMASTER_CONTROL_RUN_START_STOP_ACK = 0x0FUL,
    I2C_enMASTER_CONTROL_QUICK_COMMAND_ACK = 0x2FUL,

    I2C_enMASTER_CONTROL_RUN_HS = 0x11UL,
    I2C_enMASTER_CONTROL_START_HS = 0x12UL,
    I2C_enMASTER_CONTROL_RUN_START_HS = 0x13UL,
    I2C_enMASTER_CONTROL_STOP_HS = 0x14UL,
    I2C_enMASTER_CONTROL_RUN_STOP_HS = 0x15UL,
    I2C_enMASTER_CONTROL_START_STOP_HS = 0x16UL,
    I2C_enMASTER_CONTROL_RUN_START_STOP_HS = 0x17UL,
    I2C_enMASTER_CONTROL_QUICK_COMMAND_HS = 0x37UL,
    I2C_enMASTER_CONTROL_ACK_HS = 0x18UL,
    I2C_enMASTER_CONTROL_RUN_ACK_HS = 0x19UL,
    I2C_enMASTER_CONTROL_START_ACK_HS = 0x1AUL,
    I2C_enMASTER_CONTROL_RUN_START_ACK_HS = 0x1BUL,
    I2C_enMASTER_CONTROL_STOP_ACK_HS = 0x1CUL,
    I2C_enMASTER_CONTROL_RUN_STOP_ACK_HS = 0x1DUL,
    I2C_enMASTER_CONTROL_START_STOP_ACK_HS = 0x1EUL,
    I2C_enMASTER_CONTROL_RUN_START_STOP_ACK_HS = 0x1FUL,
    I2C_enMASTER_CONTROL_QUICK_COMMAND_ACK_HS = 0x3FUL,

    I2C_enMASTER_CONTROL_BURST = 0x40UL,
    I2C_enMASTER_CONTROL_BURST_START = 0x42UL,
    I2C_enMASTER_CONTROL_BURST_STOP = 0x44UL,
    I2C_enMASTER_CONTROL_BURST_START_STOP = 0x46UL,
    I2C_enMASTER_CONTROL_BURST_ACK = 0x48UL,
    I2C_enMASTER_CONTROL_BURST_START_ACK = 0x4AUL,
    I2C_enMASTER_CONTROL_BURST_STOP_ACK = 0x4CUL,
    I2C_enMASTER_CONTROL_BURST_START_STOP_ACK = 0x4EUL,

    I2C_enMASTER_CONTROL_BURST_HS = 0x50UL,
    I2C_enMASTER_CONTROL_BURST_START_HS = 0x52UL,
    I2C_enMASTER_CONTROL_BURST_STOP_HS = 0x54UL,
    I2C_enMASTER_CONTROL_BURST_START_STOP_HS = 0x56UL,
    I2C_enMASTER_CONTROL_BURST_ACK_HS = 0x58UL,
    I2C_enMASTER_CONTROL_BURST_START_ACK_HS = 0x5AUL,
    I2C_enMASTER_CONTROL_BURST_STOP_ACK_HS = 0x5CUL,
    I2C_enMASTER_CONTROL_BURST_START_STOP_ACK_HS = 0x5EUL,

    I2C_enMASTER_CONTROL_UNDEF = 0xFFFFFFFFUL,
} I2C_nMASTER_CONTROL;

typedef enum
{
    I2C_enMASTER_HIGHSPEED_CAPABLE_DIS = 0UL,
    I2C_enMASTER_HIGHSPEED_CAPABLE_ENA = 1UL,
    I2C_enMASTER_HIGHSPEED_CAPABLE_UNDEF = 0xFFFFFFFFUL,
} I2C_nMASTER_HIGHSPEED_CAPABLE;

typedef enum
{
    I2C_enMASTER_HIGHSPEED_DIS = 0UL,
    I2C_enMASTER_HIGHSPEED_ENA = 1UL,
    I2C_enMASTER_HIGHSPEED_UNDEF = 0xFFFFFFFFUL,
} I2C_nMASTER_HIGHSPEED;

typedef enum
{
    I2C_enMASTER_GLITCH_CLOCK_BYPASS = 0UL,
    I2C_enMASTER_GLITCH_CLOCK_1 = 1UL,
    I2C_enMASTER_GLITCH_CLOCK_2 = 2UL,
    I2C_enMASTER_GLITCH_CLOCK_3 = 3UL,
    I2C_enMASTER_GLITCH_CLOCK_4 = 4UL,
    I2C_enMASTER_GLITCH_CLOCK_8 = 5UL,
    I2C_enMASTER_GLITCH_CLOCK_16 = 6UL,
    I2C_enMASTER_GLITCH_CLOCK_31 = 7UL,
    I2C_enMASTER_GLITCH_CLOCK_UNDEF = 0xFFFFFFFFUL,
} I2C_nMASTER_GLITCH_CLOCK;

/**
 * General control
 */
typedef enum
{
    I2C_enMODE_NONE = 0x0UL,                  /*!< I2C_enMODE_NONE */
    I2C_enMODE_LOOPBACK = 0x1UL,              /*!< I2C_enMODE_LOOPBACK */
    I2C_enMODE_MASTER = 0x10UL,               /*!< I2C_enMODE_MASTER */
    I2C_enMODE_LOOPBACK_MASTER = 0x11UL,      /*!< I2C_enMODE_LOOPBACK_MASTER */
    I2C_enMODE_SLAVE = 0x20UL,                /*!< I2C_enMODE_SLAVE */
    I2C_enMODE_LOOPBACK_SLAVE = 0x21UL,       /*!< I2C_enMODE_LOOPBACK_SLAVE */
    I2C_enMODE_MASTER_SLAVE = 0x30UL,         /*!< I2C_enMODE_MASTER_SLAVE */
    I2C_enMODE_LOOPBACK_MASTER_SLAVE = 0x31UL,/*!< I2C_enMODE_LOOPBACK_MASTER_SLAVE */
    I2C_enMODE_UNDEF = 0xFFFFFFFFUL,          /*!< I2C_enMODE_UNDEF */
} I2C_nMODE;

typedef enum
{
    I2C_enLINE_SCL= 0UL,
    I2C_enLINE_SDA = 1UL,
    I2C_enLINE_UNDEF = 0xFFFFFFFFUL,
} I2C_nLINE;

typedef enum
{
    I2C_enLINE_STATE_LOW = 0UL,
    I2C_enLINE_STATE_HIGH = 1UL,
    I2C_enLINE_STATE_UNDEF = 0xFFFFFFFFUL,
} I2C_nLINE_STATE;

typedef enum
{
    I2C_enOPERATION_TRANSMIT = 0UL,
    I2C_enOPERATION_RECEIVE = 1UL,
    I2C_enOPERATION_UNDEF = 0xFFFFFFFFUL,
} I2C_nOPERATION;

typedef enum
{
    I2C_enMULTIMASTER_DIS = 0UL,
    I2C_enMULTIMASTER_ENA = 1UL,
    I2C_enMULTIMASTER_UNDEF = 0xFFFFFFFFUL,
} I2C_nMULTIMASTER;

typedef enum
{
    I2C_enSTOPCONDITION_DIS = 0UL,
    I2C_enSTOPCONDITION_ENA = 1UL,
    I2C_enSTOPCONDITION_UNDEF = 0xFFFFFFFFUL,
} I2C_nSTOPCONDITION;

typedef enum
{
    I2C_enALT_ADDRESS_DIS = 0UL,
    I2C_enALT_ADDRESS_ENA = 1UL,
    I2C_enALT_ADDRESS_UNDEF = 0xFFFFFFFFUL,
} I2C_nALT_ADDRESS;

typedef enum
{
    I2C_enACK_ENABLE_DIS = 0UL,
    I2C_enACK_ENABLE_ENA = 1UL,
    I2C_enACK_ENABLE_UNDEF = 0xFFFFFFFFUL,
} I2C_nACK_ENABLE;


typedef enum
{
    I2C_enACK_ACK = 0UL,
    I2C_enACK_NACK = 1UL,
    I2C_enACK_UNDEF = 0xFFFFFFFFUL,
} I2C_nACK;

typedef enum
{
    I2C_enSLAVE_ENABLE_DIS = 0UL,
    I2C_enSLAVE_ENABLE_ENA = 1UL,
    I2C_enSLAVE_ENABLE_UNDEF = 0xFFFFFFFFUL,
} I2C_nSLAVE_ENABLE;

typedef enum
{
    I2C_enSLAVE_REQUEST_NONE = 0x0UL,
    I2C_enSLAVE_REQUEST_RECEIVE = 0x1UL,
    I2C_enSLAVE_REQUEST_TRANSMIT = 0x2UL,
    I2C_enSLAVE_REQUEST_RECEIVE_TRANSMIT = 0x3UL,
    I2C_enSLAVE_REQUEST_FIRSTBYTE = 0x4UL,
    I2C_enSLAVE_REQUEST_RECEIVE_FIRSTBYTE = 0x5UL,
    I2C_enSLAVE_REQUEST_TRANSMIT_FIRSTBYTE = 0x6UL,
    I2C_enSLAVE_REQUEST_RECEIVE_TRANSMIT_FIRSTBYTE = 0x7UL,
    I2C_enSLAVE_REQUEST_ALTADDRESS = 0x8UL,
    I2C_enSLAVE_REQUEST_RECEIVE_ALTADDRESS = 0x9UL,
    I2C_enSLAVE_REQUEST_TRANSMIT_ALTADDRESS = 0xAUL,
    I2C_enSLAVE_REQUEST_RECEIVE_TRANSMIT_ALTADDRESS = 0xBUL,
    I2C_enSLAVE_REQUEST_FIRSTBYTE_ALTADDRESS = 0xCUL,
    I2C_enSLAVE_REQUEST_RECEIVE_FIRSTBYTE_ALTADDRESS = 0xDUL,
    I2C_enSLAVE_REQUEST_TRANSMIT_FIRSTBYTE_ALTADDRESS = 0xEUL,
    I2C_enSLAVE_REQUEST_RECEIVE_TRANSMIT_FIRSTBYTE_ALTADDRESS = 0xFUL,
    I2C_enSLAVE_REQUEST_UNDEF = 0xFFFFFFFFUL,
} I2C_nSLAVE_REQUEST;

typedef enum
{
    I2C_enSLAVE_REQUEST_STATUS_NORECEIVED = 0UL,
    I2C_enSLAVE_REQUEST_STATUS_RECEIVED = 1UL,
    I2C_enSLAVE_REQUEST_STATUS_UNDEF = 0xFFFFFFFFUL,
}I2C_nSLAVE_REQUEST_STATUS;

#endif /* XDRIVER_MCU_I2C_PERIPHERAL_XHEADER_I2C_ENUM_H_ */
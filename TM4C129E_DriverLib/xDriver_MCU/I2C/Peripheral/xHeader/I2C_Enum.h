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

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    I2C_enERROR_OK = (UBase_t) MCU_enERROR_OK,
    I2C_enERROR_POINTER = (UBase_t) MCU_enERROR_POINTER,
    I2C_enERROR_VALUE = (UBase_t) MCU_enERROR_VALUE,
    I2C_enERROR_RANGE = (UBase_t) MCU_enERROR_RANGE,
    I2C_enERROR_EMPTY = (UBase_t) MCU_enERROR_EMPTY,
    I2C_enERROR_TIMEOUT = (UBase_t) MCU_enERROR_TIMEOUT,
    I2C_enERROR_UNDEF = (UBase_t) MCU_enERROR_UNDEF,
}I2C_nERROR;

typedef enum
{
    I2C_enSTATE_DIS = (UBase_t) MCU_enSTATE_DIS,
    I2C_enSTATE_ENA = (UBase_t) MCU_enSTATE_ENA,
    I2C_enSTATE_UNDEF = (UBase_t) MCU_enSTATE_UNDEF,
} I2C_nSTATE;

typedef enum
{
    I2C_enSTATUS_INACTIVE = (UBase_t) MCU_enSTATUS_INACTIVE,
    I2C_enSTATUS_ACTIVE = (UBase_t) MCU_enSTATUS_ACTIVE,
    I2C_enSTATUS_UNDEF = (UBase_t) MCU_enSTATUS_UNDEF,
} I2C_nSTATUS;

typedef enum
{
    I2C_enFALSE = (UBase_t) FALSE,
    I2C_enTRUE = (UBase_t) TRUE,
    I2C_enPENDSTATE_UNDEF = UNDEF_VALUE,
}I2C_nBOOLEAN;

typedef enum
{
    I2C_enPRI0 = (UBase_t) MCU_enPRI0,
    I2C_enPRI1 = (UBase_t) MCU_enPRI1,
    I2C_enPRI2 = (UBase_t) MCU_enPRI2,
    I2C_enPRI3 = (UBase_t) MCU_enPRI3,
    I2C_enPRI4 = (UBase_t) MCU_enPRI4,
    I2C_enPRI5 = (UBase_t) MCU_enPRI5,
    I2C_enPRI6 = (UBase_t) MCU_enPRI6,
    I2C_enPRI7 = (UBase_t) MCU_enPRI7,
    I2C_enPRIMAX = (UBase_t) MCU_enPRIMAX,
    I2C_enDEFAULT = (UBase_t) MCU_enDEFAULT,
}I2C_nPRIORITY;

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
    I2C_enMODULE_UNDEF = UNDEF_VALUE,
}I2C_nMODULE;

/**
 * I2C Master interrupts
 */
typedef enum
{
    I2C_enMASTER_INT_MASTER = 0UL,
    I2C_enMASTER_INT_CLOCK_TIMEOUT = 1UL,
    I2C_enMASTER_INT_RECEIVE_DMA = 2UL,
    I2C_enMASTER_INT_TRANSMIT_DMA = 3UL,
    I2C_enMASTER_INT_ADDR_DATA_NACK = 4UL,
    I2C_enMASTER_INT_START_DETECTION = 5UL,
    I2C_enMASTER_INT_STOP_DETECTION = 6UL,
    I2C_enMASTER_INT_ARBITRATION_LOST = 7UL,
    I2C_enMASTER_INT_TRANSMIT_FIFO_REQ = 8UL,
    I2C_enMASTER_INT_RECEIVE_FIFO_REQ = 9UL,
    I2C_enMASTER_INT_TRANSMIT_FIFO_EMPTY = 10UL,
    I2C_enMASTER_INT_RECEIVE_FIFO_FULL = 11UL,
    I2C_enMASTER_INT_SW = 12UL,
    I2C_enMASTER_INT_MAX = 13UL,
    I2C_enMASTER_INT_UNDEF = UNDEF_VALUE,
}I2C_nMASTER_INT;

typedef enum
{
    I2C_enMASTER_INTMASK_NONE = 0x0UL,
    I2C_enMASTER_INTMASK_MASTER = 0x1UL,
    I2C_enMASTER_INTMASK_CLOCK_TIMEOUT = 0x2UL,
    I2C_enMASTER_INTMASK_RECEIVE_DMA = 0x4UL,
    I2C_enMASTER_INTMASK_TRANSMIT_DMA = 0x8UL,
    I2C_enMASTER_INTMASK_ADDR_DATA_NACK = 0x10UL,
    I2C_enMASTER_INTMASK_START_DETECTION = 0x20UL,
    I2C_enMASTER_INTMASK_STOP_DETECTION = 0x40UL,
    I2C_enMASTER_INTMASK_ARBITRATION_LOST = 0x80UL,
    I2C_enMASTER_INTMASK_TRANSMIT_FIFO_REQ = 0x100UL,
    I2C_enMASTER_INTMASK_RECEIVE_FIFO_REQ = 0x200UL,
    I2C_enMASTER_INTMASK_TRANSMIT_FIFO_EMPTY = 0x400UL,
    I2C_enMASTER_INTMASK_RECEIVE_FIFO_FULL = 0x800UL,
    I2C_enMASTER_INTMASK_ALL = 0xFFFUL,
    I2C_enMASTER_INTMASK_MAX = 0x1000UL,
    I2C_enMASTER_INTMASK_UNDEF = UNDEF_VALUE,
}I2C_nMASTER_INTMASK;

/**
 * I2C Slave interrupts
 */
typedef enum
{
    I2C_enSLAVE_INT_DATA = 0UL,               /*!< I2C_enSLAVE_INT_DATA */
    I2C_enSLAVE_INT_START_CONDITION = 1UL,    /*!< I2C_enSLAVE_INT_START_CONDITION */
    I2C_enSLAVE_INT_STOP_CONDITION = 2UL,     /*!< I2C_enSLAVE_INT_STOP_CONDITION */
    I2C_enSLAVE_INT_RECEIVE_DMA = 3UL,        /*!< I2C_enSLAVE_INT_RECEIVE_DMA */
    I2C_enSLAVE_INT_TRANSMIT_DMA = 4UL,       /*!< I2C_enSLAVE_INT_TRANSMIT_DMA */
    I2C_enSLAVE_INT_TRANSMIT_FIFO_REQ = 5UL,  /*!< I2C_enSLAVE_INT_TRANSMIT_FIFO_REQ */
    I2C_enSLAVE_INT_RECEIVE_FIFO_REQ = 6UL,   /*!< I2C_enSLAVE_INT_RECEIVE_FIFO_REQ */
    I2C_enSLAVE_INT_TRANSMIT_FIFO_EMPTY = 7UL,/*!< I2C_enSLAVE_INT_TRANSMIT_FIFO_EMPTY */
    I2C_enSLAVE_INT_RECEIVE_FIFO_FULL = 8UL,  /*!< I2C_enSLAVE_INT_RECEIVE_FIFO_FULL */
    I2C_enSLAVE_INT_SW = 9UL,               /*!< I2C_enSLAVE_INT_SW */
    I2C_enSLAVE_INT_MAX = 10UL,                /*!< I2C_enSLAVE_INT_MAX */
    I2C_enSLAVE_INT_UNDEF = UNDEF_VALUE,
}I2C_nSLAVE_INT;

typedef enum
{
    I2C_enSLAVE_INTMASK_NONE = 0x0UL,
    I2C_enSLAVE_INTMASK_DATA = 0x1UL,
    I2C_enSLAVE_INTMASK_START_CONDITION = 0x2UL,
    I2C_enSLAVE_INTMASK_STOP_CONDITION = 0x4UL,
    I2C_enSLAVE_INTMASK_RECEIVE_DMA = 0x8UL,
    I2C_enSLAVE_INTMASK_TRANSMIT_DMA = 0x10UL,
    I2C_enSLAVE_INTMASK_TRANSMIT_FIFO_REQ = 0x20UL,
    I2C_enSLAVE_INTMASK_RECEIVE_FIFO_REQ = 0x40UL,
    I2C_enSLAVE_INTMASK_TRANSMIT_FIFO_EMPTY = 0x80UL,
    I2C_enSLAVE_INTMASK_RECEIVE_FIFO_FULL = 0x100UL,
    I2C_enSLAVE_INTMASK_ALL = 0x1FFUL,
    I2C_enSLAVE_INTMASK_MAX = 0x200UL,
    I2C_enSLAVE_INTMASK_UNDEF = UNDEF_VALUE,
}I2C_nSLAVE_INTMASK;

/**
 * Master Status controllers
 */

typedef enum
{
    I2C_enARBITRATION_WON = 0UL,
    I2C_enARBITRATION_LOST = 1UL,
    I2C_enARBITRATION_UNDEF = UNDEF_VALUE,
}I2C_nARBITRATION;

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
    /* I2C_enMASTER_CONTROL_START = 0x02UL, */
    I2C_enMASTER_CONTROL_BURST_START = 0x42UL,
    /* I2C_enMASTER_CONTROL_STOP = 0x04UL, */
    I2C_enMASTER_CONTROL_BURST_STOP = 0x44UL,
    /* I2C_enMASTER_CONTROL_START_STOP = 0x06UL, */
    I2C_enMASTER_CONTROL_BURST_START_STOP = 0x46UL,
    /* I2C_enMASTER_CONTROL_ACK = 0x08UL, */
    I2C_enMASTER_CONTROL_BURST_ACK = 0x48UL,
    /* I2C_enMASTER_CONTROL_START_ACK = 0x0AUL, */
    I2C_enMASTER_CONTROL_BURST_START_ACK = 0x4AUL,
    /* I2C_enMASTER_CONTROL_STOP_ACK = 0x0CUL, */
    I2C_enMASTER_CONTROL_BURST_STOP_ACK = 0x4CUL,
    /* I2C_enMASTER_CONTROL_START_STOP_ACK = 0x0EUL, */
    I2C_enMASTER_CONTROL_BURST_START_STOP_ACK = 0x4EUL,

    I2C_enMASTER_CONTROL_BURST_HS = 0x50UL,
    /* I2C_enMASTER_CONTROL_RUN_HS = 0x11UL, */
    I2C_enMASTER_CONTROL_BURST_START_HS = 0x52UL,
    /* I2C_enMASTER_CONTROL_STOP_HS = 0x14UL, */
    I2C_enMASTER_CONTROL_BURST_STOP_HS = 0x54UL,
    /* I2C_enMASTER_CONTROL_START_STOP_HS = 0x16UL, */
    I2C_enMASTER_CONTROL_BURST_START_STOP_HS = 0x56UL,
    /* I2C_enMASTER_CONTROL_ACK_HS = 0x18UL, */
    I2C_enMASTER_CONTROL_BURST_ACK_HS = 0x58UL,
    /* I2C_enMASTER_CONTROL_START_ACK_HS = 0x1AUL, */
    I2C_enMASTER_CONTROL_BURST_START_ACK_HS = 0x5AUL,
    /* I2C_enMASTER_CONTROL_STOP_ACK_HS = 0x1CUL, */
    I2C_enMASTER_CONTROL_BURST_STOP_ACK_HS = 0x5CUL,
    /* I2C_enMASTER_CONTROL_START_STOP_ACK_HS = 0x1EUL, */
    I2C_enMASTER_CONTROL_BURST_START_STOP_ACK_HS = 0x5EUL,

    I2C_enMASTER_CONTROL_UNDEF = UNDEF_VALUE,
} I2C_nMASTER_CONTROL;

typedef enum
{
    I2C_enGLITCH_CLOCK_BYPASS = 0UL,
    I2C_enGLITCH_CLOCK_1 = 1UL,
    I2C_enGLITCH_CLOCK_2 = 2UL,
    I2C_enGLITCH_CLOCK_3 = 3UL,
    I2C_enGLITCH_CLOCK_4 = 4UL,
    I2C_enGLITCH_CLOCK_8 = 5UL,
    I2C_enGLITCH_CLOCK_16 = 6UL,
    I2C_enGLITCH_CLOCK_31 = 7UL,
    I2C_enGLITCH_CLOCK_UNDEF = UNDEF_VALUE,
} I2C_nGLITCH_CLOCK;

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
    I2C_enMODE_UNDEF = UNDEF_VALUE,          /*!< I2C_enMODE_UNDEF */
} I2C_nMODE;

typedef enum
{
    I2C_enLINE_SCL= 0UL,
    I2C_enLINE_SDA = 1UL,
    I2C_enLINE_UNDEF = UNDEF_VALUE,
} I2C_nLINE;

typedef enum
{
    I2C_enLEVEL_LOW = 0UL,
    I2C_enLEVEL_HIGH = 1UL,
    I2C_enLEVEL_UNDEF = UNDEF_VALUE,
} I2C_nLEVEL;

typedef enum
{
    I2C_enOPERATION_TRANSMIT = 0UL,
    I2C_enOPERATION_RECEIVE = 1UL,
    I2C_enOPERATION_UNDEF = UNDEF_VALUE,
} I2C_nOPERATION;

typedef enum
{
    I2C_enOPERATION_ERROR_NONE = 0UL,
    I2C_enOPERATION_ERROR_ADDRESS = 1UL,
    I2C_enOPERATION_ERROR_DATA = 2UL,
    I2C_enOPERATION_ERROR_UNDEF = UNDEF_VALUE,
} I2C_nOPERATION_ERROR;


typedef enum
{
    I2C_enACK_ACK = 0UL,
    I2C_enACK_NACK = 1UL,
    I2C_enACK_UNDEF = UNDEF_VALUE,
} I2C_nACK;

typedef MCU_Register_t I2C_Register_t;
typedef MCU_pvfIRQVectorHandler_t I2C_pvfIRQVectorHandler_t;
typedef MCU_pvfIRQSourceHandler_t I2C_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_I2C_PERIPHERAL_XHEADER_I2C_ENUM_H_ */

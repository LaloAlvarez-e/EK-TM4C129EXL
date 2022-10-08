/*
 * SYSTICK_Enum.h
 *
 *  Created on: 18 jun. 2020
 *      Author: vyldram
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSTICK_SYSTICK_PERIPHERAL_SYSTICK_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSTICK_SYSTICK_PERIPHERAL_SYSTICK_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    SYSTICK_enERROR_OK = (UBase_t) MCU_enERROR_OK,
    SYSTICK_enERROR_POINTER = (UBase_t) MCU_enERROR_POINTER,
    SYSTICK_enERROR_VALUE = (UBase_t) MCU_enERROR_VALUE,
    SYSTICK_enERROR_RANGE = (UBase_t) MCU_enERROR_RANGE,
    SYSTICK_enERROR_UNDEF = (UBase_t) MCU_enERROR_UNDEF,
}SYSTICK_nERROR;

typedef enum
{
    SYSTICK_enSTATUS_INACTIVE = (UBase_t) MCU_enSTATUS_INACTIVE,
    SYSTICK_enSTATUS_ACTIVE = (UBase_t) MCU_enSTATUS_ACTIVE,
} SYSTICK_nSTATUS;

typedef enum
{
    SYSTICK_enSTATE_DIS = (UBase_t) MCU_enSTATE_DIS,
    SYSTICK_enSTATE_ENA = (UBase_t) MCU_enSTATE_ENA,
}SYSTICK_nSTATE;

typedef enum
{
    SYSTICK_enPRI0 = (UBase_t) MCU_enPRI0,
    SYSTICK_enPRI1 = (UBase_t) MCU_enPRI1,
    SYSTICK_enPRI2 = (UBase_t) MCU_enPRI2,
    SYSTICK_enPRI3 = (UBase_t) MCU_enPRI3,
    SYSTICK_enPRI4 = (UBase_t) MCU_enPRI4,
    SYSTICK_enPRI5 = (UBase_t) MCU_enPRI5,
    SYSTICK_enPRI6 = (UBase_t) MCU_enPRI6,
    SYSTICK_enPRI7 = (UBase_t) MCU_enPRI7,
    SYSTICK_enPRIMAX = (UBase_t) MCU_enPRIMAX,
    SYSTICK_enDEFAULT = (UBase_t) MCU_enDEFAULT,
}SYSTICK_nPRIORITY;

typedef enum
{
    SYSTICK_enMODULE_0 = 0UL,
    SYSTICK_enMODULE_MAX = 1UL,
}SYSTICK_nMODULE;

typedef enum
{
    SYSTICK_enPIOSC4 = 0UL,
    SYSTICK_enSYSCLK = 1UL,
}SYSTICK_nCLKSOURCE;

typedef MCU_Register_t SYSTICK_Register_t;
typedef MCU_pvfIRQVectorHandler_t SYSTICK_pvfIRQVectorHandler_t;
typedef MCU_pvfIRQSourceHandler_t SYSTICK_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSTICK_SYSTICK_PERIPHERAL_SYSTICK_ENUM_H_ */

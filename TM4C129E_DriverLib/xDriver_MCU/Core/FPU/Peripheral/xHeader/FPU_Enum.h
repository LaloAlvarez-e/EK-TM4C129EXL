/*
 * FPU_Enum.h
 *
 *  Created on: 17 jun. 2020
 *      Author: vyldram
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_FPU_FPU_PERIPHERAL_FPU_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_FPU_FPU_PERIPHERAL_FPU_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    FPU_enERROR_OK = (uint32_t) MCU_enERROR_OK,
    FPU_enERROR_POINTER = (uint32_t) MCU_enERROR_POINTER,
    FPU_enERROR_VALUE = (uint32_t) MCU_enERROR_VALUE,
    FPU_enERROR_UNDEF = (uint32_t) MCU_enERROR_UNDEF,
}FPU_nERROR;

typedef enum
{
    FPU_enMODULE_0 = 0UL,
    FPU_enMODULE_MAX = 1UL,
}FPU_nMODULE;

typedef enum
{
    FPU_enACCESS_DENIED = 0UL,
    FPU_enACCESS_ONLY_PRIVILEGED = 1UL,
    FPU_enACCESS_FULL = 3UL,
}FPU_nACCESS;

typedef enum
{
    FPU_enSTATE_DIS = 0UL,
    FPU_enSTATE_ENA = 1UL,
}FPU_nSTATE;

typedef enum
{
    FPU_enSTATUS_NOACTIVE = 0UL,
    FPU_enSTATUS_ACTIVE = 1UL,
}FPU_nSTATUS;

typedef enum
{
    FPU_enHALF_PRECISION_IEEE = 0UL,
    FPU_enHALF_PRECISION_ALT = 1UL,
}FPU_nHALF_PRECISION;

typedef enum
{
    FPU_enNAN_PROPAGATE = 0UL,
    FPU_enNAN_NAN = 1UL,
}FPU_nNAN;

typedef enum
{
    FPU_enMODE_DENORMAL = 0UL,
    FPU_enMODE_FLUSH_ZERO = 1UL,
}FPU_nMODE;

typedef enum
{
    FPU_enROUNDING_NEAREST = 0UL,
    FPU_enROUNDING_PLUSINF = 1UL,
    FPU_enROUNDING_MINUSINF = 2UL,
    FPU_enROUNDING_ZERO = 3UL,
}FPU_nROUNDING;

typedef enum
{
    FPU_enEXCEPTION_INVALID = 0x01UL,
    FPU_enEXCEPTION_DIV0 = 0x02UL,
    FPU_enEXCEPTION_OVERFLOW = 0x04UL,
    FPU_enEXCEPTION_UNDERFLOW = 0x08UL,
    FPU_enEXCEPTION_INEXACT = 0x10UL,
    FPU_enEXCEPTION_DENORMAL = 0x80UL,
}FPU_nEXCEPTION;

typedef MCU_Register_t FPU_Register_t;
typedef MCU_pvfIRQSourceHandler_t FPU_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_FPU_FPU_PERIPHERAL_FPU_ENUM_H_ */

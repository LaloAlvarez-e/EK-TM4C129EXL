/**
 *
 * @file EEPROM_Enum.h
 * @ingroup Peripheral Driver
 * @brief This files is part of EEPROM Peripheral Driver.
 * This File contains the enumerations used in the Driver
 *
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
 * @verbatim 2020.06.17 @endverbatim
 *
 * @author
 * @verbatim Vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 2020.06.17     Vyldram    1.0         initial Version@endverbatim
 *
 * @remarks File required to get the enumerations requires in all  EEPROM peripheral files.
 * @remarks Any further enumerations required in any
 * EEPROM functions must to be implemented here
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_EEPROM_EEPROM_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_EEPROM_EEPROM_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

#define EEPROM_TIMEOUT_MAX (500000UL)

typedef enum
{
    EEPROM_enERROR_OK = (UBase_t) MCU_enERROR_OK,
    EEPROM_enERROR_POINTER = (UBase_t) MCU_enERROR_POINTER,
    EEPROM_enERROR_VALUE = (UBase_t) MCU_enERROR_VALUE,
    EEPROM_enERROR_RANGE = (UBase_t) MCU_enERROR_RANGE,
    EEPROM_enERROR_EMPTY = (UBase_t) MCU_enERROR_EMPTY,
    EEPROM_enERROR_BUSY = (UBase_t) MCU_enERROR_BUSY,
    EEPROM_enERROR_TIMEOUT = (UBase_t) MCU_enERROR_TIMEOUT,
    EEPROM_enERROR_UNDEF = (UBase_t) MCU_enERROR_UNDEF,
}EEPROM_nERROR;

typedef enum
{
    EEPROM_enSTATE_DIS = (UBase_t) MCU_enSTATE_DIS,
    EEPROM_enSTATE_ENA = (UBase_t) MCU_enSTATE_ENA,
    EEPROM_enSTATE_UNDEF = (UBase_t) MCU_enSTATE_UNDEF,
} EEPROM_nSTATE;

typedef enum
{
    EEPROM_enSTATUS_INACTIVE = (UBase_t) MCU_enSTATUS_INACTIVE,
    EEPROM_enSTATUS_ACTIVE = (UBase_t) MCU_enSTATUS_ACTIVE,
    EEPROM_enSTATUS_UNDEF = (UBase_t) MCU_enSTATUS_UNDEF,
} EEPROM_nSTATUS;

typedef enum
{
    EEPROM_enFALSE = (UBase_t) FALSE,
    EEPROM_enTRUE = (UBase_t) TRUE,
    EEPROM_enPENDSTATE_UNDEF = (UBase_t) BOOLEAN_UNDEF,
}EEPROM_nBOOLEAN;

typedef enum
{
    EEPROM_enPRI0 = (UBase_t) MCU_enPRI0,
    EEPROM_enPRI1 = (UBase_t) MCU_enPRI1,
    EEPROM_enPRI2 = (UBase_t) MCU_enPRI2,
    EEPROM_enPRI3 = (UBase_t) MCU_enPRI3,
    EEPROM_enPRI4 = (UBase_t) MCU_enPRI4,
    EEPROM_enPRI5 = (UBase_t) MCU_enPRI5,
    EEPROM_enPRI6 = (UBase_t) MCU_enPRI6,
    EEPROM_enPRI7 = (UBase_t) MCU_enPRI7,
    EEPROM_enPRIMAX = (UBase_t) MCU_enPRIMAX,
    EEPROM_enDEFAULT = (UBase_t) MCU_enDEFAULT,
}EEPROM_nPRIORITY;

typedef enum
{
    EEPROM_enMODULE_0 = 0UL,
    EEPROM_enMODULE_MAX = 1UL,
    EEPROM_enMODULE_UNDEF = UNDEF_VALUE,
}EEPROM_nMODULE;

typedef enum
{
    EEPROM_enINT_ERASE = 0UL,
    EEPROM_enINT_COPY = 1UL,
    EEPROM_enINT_NOPERMISSION = 2UL,
    EEPROM_enINT_WRITE = 3UL,
    EEPROM_enINT_SW = 4UL,
    EEPROM_enINT_MAX = 5UL,
    EEPROM_enINT_UNDEF = UNDEF_VALUE,
}EEPROM_nINT;

typedef enum
{
    EEPROM_enINTMASK_ERASE = 0x04UL,
    EEPROM_enINTMASK_COPY = 0x08UL,
    EEPROM_enINTMASK_NOPERMISSION = 0x10UL,

    EEPROM_enINTMASK_WRITE = 0x20UL,
    EEPROM_enINTMASK_ALL = 0x003CUL,
    EEPROM_enINTMASK_UNDEF = UNDEF_VALUE,
}EEPROM_nINTMASK;

typedef enum
{
    EEPROM_enVARIABLE_BYTE = 0UL,
    EEPROM_enVARIABLE_HALFWORD = 1UL,
    EEPROM_enVARIABLE_WORD = 2UL,
    EEPROM_enVARIABLE_UNDEF = UNDEF_VALUE,
}EEPROM_nVARIABLE;

typedef enum
{
    EEPROM_enCONSTANT_OFF = 0UL,
    EEPROM_enCONSTANT_ON = 1UL,
    EEPROM_enCONSTANT_UNDEF = UNDEF_VALUE,
}EEPROM_nCONSTANT;

typedef MCU_Register_t EEPROM_Register_t;
typedef MCU_pvfIRQSourceHandler_t EEPROM_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_EEPROM_EEPROM_ENUM_H_ */

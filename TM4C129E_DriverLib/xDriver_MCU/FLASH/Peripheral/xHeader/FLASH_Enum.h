/*
 * FLASH_Enum.h
 *
 *  Created on: 16 jun. 2020
 *      Author: vyldram
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_FLASH_FLASH_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_FLASH_FLASH_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

typedef enum
{
    FLASH_enOK = 0UL,
    FLASH_enERROR = 1UL,
}FLASH_nSTATUS;

typedef enum
{
    FLASH_enINTERRUPT_SW = 0UL,
    FLASH_enINTERRUPT_ACCESS = 1UL,
    FLASH_enINTERRUPT_PROGRAMMING = 2UL,
    FLASH_enINTERRUPT_EEPROM = 3UL,
    FLASH_enINTERRUPT_PUMP_VOL = 4UL,
    FLASH_enINTERRUPT_INVALID_DATA = 5UL,
    FLASH_enINTERRUPT_ERRASE_ERROR = 6UL,
    FLASH_enINTERRUPT_PROGRAM_ERROR = 7UL,
    FLASH_enINTERRUPT_MAX = 8UL,
}FLASH_nINTERRUPT;

typedef enum
{
    FLASH_enINT_NONE = 0x00UL,
    FLASH_enINT_ACCESS = 0x01UL,
    FLASH_enINT_PROGRAMMING = 0x02UL,
    FLASH_enINT_EEPROM = 0x04UL,

    FLASH_enINT_PUMP_VOL = 0x200UL,
    FLASH_enINT_INVALID_DATA = 0x400UL,
    FLASH_enINT_ERRASE_ERROR = 0x800UL,
    FLASH_enINT_PROGRAM_ERROR = 0x2000UL,
    FLASH_enINT_ALL = 0x2E07UL,
    FLASH_enINT_UNDEF = 0xFFFFFUL,
}FLASH_nINT;

typedef enum
{
    FLASH_enINT_STATUS_NOOCCUR = 0UL,
    FLASH_enINT_STATUS_OCCUR = 1UL,
    FLASH_enINT_STATUS_UNDEF = 0xFFFFFFFFUL,
}FLASH_nINT_STATUS;

typedef enum
{
    FLASH_enPREFETCH_MODE_TWO = 0UL,
    FLASH_enPREFETCH_MODE_SINGLE = 1UL,
}FLASH_nPREFETCH_MODE;

typedef enum
{
    FLASH_enMIRROR_DIS = 0UL,
    FLASH_enMIRROR_ENA = 1UL,
}FLASH_nMIRROR;

typedef enum
{
    FLASH_enPREFETCH_ENABLE_ON = 0UL,
    FLASH_enPREFETCH_ENABLE_OFF = 1UL,
}FLASH_nPREFETCH_ENABLE;

typedef enum
{
    FLASH_enPRI0 = 0UL,
    FLASH_enPRI1 = 1UL,
    FLASH_enPRI2 = 2UL,
    FLASH_enPRI3 = 3UL,
    FLASH_enPRI4 = 4UL,
    FLASH_enPRI5 = 5UL,
    FLASH_enPRI6 = 6UL,
    FLASH_enPRI7 = 7UL,
    FLASH_enPRI_MIN = 7UL,
    FLASH_enDEFAULT = 0xFFFFFFFFUL,
}FLASH_nPRIORITY;

typedef enum
{
    FLASH_enVARIABLE_BYTE = 0UL,
    FLASH_enVARIABLE_HALFWORD = 1UL,
    FLASH_enVARIABLE_WORD = 2UL,
}FLASH_nVARIABLE;

typedef enum
{
    FLASH_enCONSTANT_OFF = 0UL,
    FLASH_enCONSTANT_ON = 1UL,
}FLASH_nCONSTANT;

#endif /* XDRIVER_MCU_DRIVER_HEADER_FLASH_FLASH_ENUM_H_ */

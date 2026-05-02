/**
 *
 * @file HIB_Enum.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 5 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 5 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_XHEADER_HIB_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_XHEADER_HIB_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    HIB_enERROR_OK = (UBase_t) MCU_enERROR_OK,
    HIB_enERROR_POINTER = (UBase_t) MCU_enERROR_POINTER,
    HIB_enERROR_VALUE = (UBase_t) MCU_enERROR_VALUE,
    HIB_enERROR_RANGE = (UBase_t) MCU_enERROR_RANGE,
    HIB_enERROR_EMPTY = (UBase_t) MCU_enERROR_EMPTY,
    HIB_enERROR_FULL = (UBase_t) MCU_enERROR_FULL,
    HIB_enERROR_TIMEOUT = (UBase_t) MCU_enERROR_TIMEOUT,
    HIB_enERROR_UNDEF = (UBase_t) MCU_enERROR_UNDEF,
}HIB_nERROR;

typedef enum
{
    HIB_enSTATE_DIS = (UBase_t) MCU_enSTATE_DIS,
    HIB_enSTATE_ENA = (UBase_t) MCU_enSTATE_ENA,
    HIB_enSTATE_UNDEF = (UBase_t) MCU_enSTATE_UNDEF,
}HIB_nSTATE;

typedef enum
{
    HIB_enSTATUS_INACTIVE = (UBase_t) MCU_enSTATUS_INACTIVE,
    HIB_enSTATUS_ACTIVE = (UBase_t) MCU_enSTATUS_ACTIVE,
    HIB_enSTATUS_UNDEF = (UBase_t) MCU_enSTATUS_UNDEF,
}HIB_nSTATUS;

typedef enum
{
    HIB_enPRI0 = (UBase_t) MCU_enPRI0,
    HIB_enPRI1 = (UBase_t) MCU_enPRI1,
    HIB_enPRI2 = (UBase_t) MCU_enPRI2,
    HIB_enPRI3 = (UBase_t) MCU_enPRI3,
    HIB_enPRI4 = (UBase_t) MCU_enPRI4,
    HIB_enPRI5 = (UBase_t) MCU_enPRI5,
    HIB_enPRI6 = (UBase_t) MCU_enPRI6,
    HIB_enPRI7 = (UBase_t) MCU_enPRI7,
    HIB_enPRIMAX = (UBase_t) MCU_enPRIMAX,
    HIB_enDEFAULT = (UBase_t) MCU_enDEFAULT,
}HIB_nPRIORITY;

typedef enum
{
    HIB_enFALSE = (UBase_t) FALSE,
    HIB_enTRUE = (UBase_t) TRUE,
    HIB_enBOOLEAN_UNDEF = UNDEF_VALUE,
}HIB_nBOOLEAN;

typedef enum
{
    HIB_enMODULE_0 = 0UL,
    HIB_enMODULE_MAX = 1UL,
    HIB_enMODULE_UNDEF = UNDEF_VALUE,
}HIB_nMODULE;

typedef enum
{
    HIB_enDATA_0 = 0UL,
    HIB_enDATA_1 = 1UL,
    HIB_enDATA_2 = 2UL,
    HIB_enDATA_3 = 3UL,
    HIB_enDATA_4 = 4UL,
    HIB_enDATA_5 = 5UL,
    HIB_enDATA_6 = 6UL,
    HIB_enDATA_7 = 7UL,
    HIB_enDATA_8 = 8UL,
    HIB_enDATA_9 = 9UL,
    HIB_enDATA_10 = 10UL,
    HIB_enDATA_11 = 11UL,
    HIB_enDATA_12 = 12UL,
    HIB_enDATA_13 = 13UL,
    HIB_enDATA_14 = 14UL,
    HIB_enDATA_15 = 15UL,
    HIB_enDATA_MAX = 16UL,
    HIB_enDATA_UNDEF = UNDEF_VALUE,
}HIB_nDATA;

typedef enum
{
    HIB_enWRITE_STATUS_BUSY = 0UL,
    HIB_enWRITE_STATUS_READY = 1UL,
    HIB_enWRITE_STATUS_UNDEF = UNDEF_VALUE,
}HIB_nWRITE_STATUS;

typedef enum
{
    HIB_enINT_RTCALT0 = 0UL,
    HIB_enINT_LOWBAT = 2UL,
    HIB_enINT_EXTW = 3UL,
    HIB_enINT_WC = 4UL,
    HIB_enINT_PADIOWK = 5UL,
    HIB_enINT_RSTWK = 6UL,
    HIB_enINT_VDDFAIL = 7UL,
    HIB_enINT_MAX = 8UL,
    HIB_enINT_UNDEF = UNDEF_VALUE,
}HIB_nINT;

typedef enum
{
    HIB_enINTMASK_NONE = 0x0UL,
    HIB_enINTMASK_RTCALT0 = 0x1UL,
    HIB_enINTMASK_LOWBAT = 0x4UL,
    HIB_enINTMASK_EXTW = 0x8UL,
    HIB_enINTMASK_WC = 0x10UL,
    HIB_enINTMASK_PADIOWK = 0x20UL,
    HIB_enINTMASK_RSTWK = 0x40UL,
    HIB_enINTMASK_VDDFAIL = 0x80UL,
    HIB_enINTMASK_ALL = 0xFDUL,
    HIB_enINTMASK_MAX = 0x100UL,
    HIB_enINTMASK_UNDEF = UNDEF_VALUE,
}HIB_nINTMASK;

typedef enum
{
    HIB_enOSC_EXTERNAL = 0UL,
    HIB_enOSC_LFIOSC = 1UL,
    HIB_enOSC_UNDEF = UNDEF_VALUE,
}HIB_nOSC;

typedef enum
{
    HIB_enOSC_DRIVE_LOW = 0UL,
    HIB_enOSC_DRIVE_HIGH = 1UL,
    HIB_enOSC_DRIVE_UNDEF = UNDEF_VALUE,
}HIB_nOSC_DRIVE;

typedef enum
{
    HIB_enVBAT_1_9V = 0UL,
    HIB_enVBAT_2_1V = 1UL,
    HIB_enVBAT_2_3V = 2UL,
    HIB_enVBAT_2_5V = 3UL,
    HIB_enVBAT_UNDEF = UNDEF_VALUE,
}HIB_nVBAT;

typedef enum
{
    HIB_enCALENDAR_COUNTER = 0UL,
    HIB_enCALENDAR_MODE = 1UL,
    HIB_enCALENDAR_UNDEF = UNDEF_VALUE,
}HIB_nCALENDAR_MODE;

typedef enum
{
    HIB_enHOUR_12 = 0UL,
    HIB_enHOUR_24 = 1UL,
    HIB_enHOUR_UNDEF = UNDEF_VALUE,
}HIB_nHOUR_MODE;

typedef enum
{
    HIB_enAM = 0UL,
    HIB_enPM = 1UL,
    HIB_enAMPM_UNDEF = UNDEF_VALUE,
}HIB_nAMPM;

typedef enum
{
    HIB_enTAMPER_0 = 0UL,
    HIB_enTAMPER_1 = 1UL,
    HIB_enTAMPER_2 = 2UL,
    HIB_enTAMPER_3 = 3UL,
    HIB_enTAMPER_MAX = 4UL,
    HIB_enTAMPER_UNDEF = UNDEF_VALUE,
}HIB_nTAMPER;

typedef enum
{
    HIB_enTAMPER_GLITCH_SHORT = 0UL,
    HIB_enTAMPER_GLITCH_LONG = 1UL,
    HIB_enTAMPER_GLITCH_UNDEF = UNDEF_VALUE,
}HIB_nTAMPER_GLITCH;

typedef enum
{
    HIB_enTAMPER_LEVEL_LOW = 0UL,
    HIB_enTAMPER_LEVEL_HIGH = 1UL,
    HIB_enTAMPER_LEVEL_UNDEF = UNDEF_VALUE,
}HIB_nTAMPER_LEVEL;

typedef enum
{
    HIB_enTAMPER_MEMCLR_NONE = 0UL,
    HIB_enTAMPER_MEMCLR_LOWER = 1UL,
    HIB_enTAMPER_MEMCLR_UPPER = 2UL,
    HIB_enTAMPER_MEMCLR_ALL = 3UL,
    HIB_enTAMPER_MEMCLR_UNDEF = UNDEF_VALUE,
}HIB_nTAMPER_MEMCLR;

typedef enum
{
    HIB_enTAMPER_STATUS_DIS = 0UL,
    HIB_enTAMPER_STATUS_CONFIG = 1UL,
    HIB_enTAMPER_STATUS_EVENT = 2UL,
    HIB_enTAMPER_STATUS_UNDEF = UNDEF_VALUE,
}HIB_nTAMPER_STATUS;

typedef enum
{
    HIB_enWAKE_PIN_PRESENT = 0UL,
    HIB_enWAKE_PIN_ABSENT = 1UL,
    HIB_enWAKE_PIN_UNDEF = UNDEF_VALUE,
}HIB_nWAKE_PIN;

typedef struct
{
    UBase_t uxSecond;
    UBase_t uxMinute;
    UBase_t uxHour;
    HIB_nAMPM enAMPM;
    UBase_t uxDayOfMonth;
    UBase_t uxMonth;
    UBase_t uxYear;
    UBase_t uxDayOfWeek;
    HIB_nSTATUS enValid;
}HIB_CALENDAR_t;

typedef struct
{
    UBase_t uxSecond;
    UBase_t uxMinute;
    UBase_t uxHour;
    UBase_t uxDayOfMonth;
    UBase_t uxMonth;
    UBase_t uxYear;
    UBase_t uxTriggerMask;
    HIB_nSTATUS enXOscFailure;
}HIB_TAMPER_LOG_t;

typedef MCU_Register_t HIB_Register_t;
typedef MCU_pvfIRQVectorHandler_t HIB_pvfIRQVectorHandler_t;
typedef MCU_pvfIRQSourceHandler_t HIB_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_XHEADER_HIB_ENUM_H_ */

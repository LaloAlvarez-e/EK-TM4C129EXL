/**
 *
 * @file SYSCTL_Enum.h
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
 * @verbatim 20 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Enum.h>

typedef enum
{
    SYSCTL_enERROR_OK = (UBase_t) MCU_enERROR_OK,
    SYSCTL_enERROR_POINTER = (UBase_t) MCU_enERROR_POINTER,
    SYSCTL_enERROR_VALUE = (UBase_t) MCU_enERROR_VALUE,
    SYSCTL_enERROR_RANGE = (UBase_t) MCU_enERROR_RANGE,
    SYSCTL_enERROR_EMPTY = (UBase_t) MCU_enERROR_EMPTY,
    SYSCTL_enERROR_FULL = (UBase_t) MCU_enERROR_FULL,
    SYSCTL_enERROR_TIMEOUT = (UBase_t) MCU_enERROR_TIMEOUT,
    SYSCTL_enERROR_UNDEF = (UBase_t) MCU_enERROR_UNDEF,
}SYSCTL_nERROR;

typedef enum
{
    SYSCTL_enSTATE_DIS = (UBase_t) MCU_enSTATE_DIS,
    SYSCTL_enSTATE_ENA = (UBase_t) MCU_enSTATE_ENA,
    SYSCTL_enSTATE_UNDEF = (UBase_t) MCU_enSTATE_UNDEF,
} SYSCTL_nSTATE;

typedef enum
{
    SYSCTL_enSTATUS_INACTIVE = (UBase_t) MCU_enSTATUS_INACTIVE,
    SYSCTL_enSTATUS_ACTIVE = (UBase_t) MCU_enSTATUS_ACTIVE,
    SYSCTL_enSTATUS_UNDEF = (UBase_t) MCU_enSTATUS_UNDEF,
} SYSCTL_nSTATUS;

typedef enum
{
    SYSCTL_enFALSE = (UBase_t) FALSE,
    SYSCTL_enTRUE = (UBase_t) TRUE,
    SYSCTL_enPENDSTATE_UNDEF = UNDEF_VALUE,
}SYSCTL_nBOOLEAN;

typedef enum
{
    SYSCTL_enPRI0 = (UBase_t) MCU_enPRI0,
    SYSCTL_enPRI1 = (UBase_t) MCU_enPRI1,
    SYSCTL_enPRI2 = (UBase_t) MCU_enPRI2,
    SYSCTL_enPRI3 = (UBase_t) MCU_enPRI3,
    SYSCTL_enPRI4 = (UBase_t) MCU_enPRI4,
    SYSCTL_enPRI5 = (UBase_t) MCU_enPRI5,
    SYSCTL_enPRI6 = (UBase_t) MCU_enPRI6,
    SYSCTL_enPRI7 = (UBase_t) MCU_enPRI7,
    SYSCTL_enPRIMAX = (UBase_t) MCU_enPRIMAX,
    SYSCTL_enDEFAULT = (UBase_t) MCU_enDEFAULT,
}SYSCTL_nPRIORITY;

typedef enum
{
    SYSCTL_enMODULE_0 = 0UL,
    SYSCTL_enMODULE_MAX = 1UL,
    SYSCTL_enMODULE_UNDEF = UNDEF_VALUE,
}SYSCTL_nMODULE;

typedef enum
{
    SYSCTL_enINT_BOR = 0UL,
    SYSCTL_enINT_MOSC_FAILURE = 1UL,
    SYSCTL_enINT_PLL_LOCK = 2UL,
    SYSCTL_enINT_MOSC_POWERUP = 3UL,
    SYSCTL_enINT_SW = 4UL,
    SYSCTL_enINT_MAX = 5UL,
    SYSCTL_enINT_UNDEF = UNDEF_VALUE,
}SYSCTL_nINT;

typedef enum
{
    SYSCTL_enINTMASK_NONE = 0x0UL,
    SYSCTL_enINTMASK_BOR = 0x2UL,
    SYSCTL_enINTMASK_MOSC_FAILURE = 0x8UL,
    SYSCTL_enINTMASK_PLL_LOCK = 0x40UL,
    SYSCTL_enINTMASK_MOSC_POWERUP = 0x100UL,
    SYSCTL_enINTMASK_ALL = 0x14AUL,
    SYSCTL_enINTMASK_MAX = 0x200UL,
    SYSCTL_enINTMASK_UNDEF = UNDEF_VALUE,
}SYSCTL_nINTMASK;

typedef enum
{
    SYSCTL_enVCO_320MHZ = 0UL,
    SYSCTL_enVCO_480MHZ = 1UL,
    SYSCTL_enVCO_MAX = 2UL,
    SYSCTL_enVCO_UNDEF = UNDEF_VALUE,
}SYSCTL_nVCO;

typedef enum
{
    SYSCTL_enNMI_EXTERNAL = 0x00000001UL,
    SYSCTL_enNMI_POWER = 0x00000004UL,
    SYSCTL_enNMI_WDT0 = 0x00000008UL,
    SYSCTL_enNMI_WDT1 = 0x00000020UL,
    SYSCTL_enNMI_TAMPER = 0x00000200UL,
    SYSCTL_enNMI_MOSC_FAILURE = 0x00001000UL,
    SYSCTL_enNMI_ALL = 0x0000122DUL,
    SYSCTL_enNMI_UNDEF = UNDEF_VALUE,
}SYSCTL_nNMI;

typedef enum
{
    SYSCTL_enRESET_EXTERNAL = 0x00001UL,
    SYSCTL_enRESET_POR = 0x00002UL,
    SYSCTL_enRESET_BOR = 0x00004UL,
    SYSCTL_enRESET_WDT0 = 0x00008UL,
    SYSCTL_enRESET_SW = 0x00010UL,
    SYSCTL_enRESET_WDT1 = 0x00020UL,
    SYSCTL_enRESET_HSSR = 0x01000UL,
    SYSCTL_enRESET_MOSC_FAILURE = 0x10000UL,
    SYSCTL_enRESET_ALL = 0x1103FUL,
    SYSCTL_enRESET_UNDEF = UNDEF_VALUE,
}SYSCTL_nRESET;

typedef enum
{
    SYSCTL_enRESET_BEHAVIOR_SYSRESET = 0x00002UL,
    SYSCTL_enRESET_BEHAVIOR_POR = 0x00003UL,
    SYSCTL_enRESET_BEHAVIOR_UNDEF = UNDEF_VALUE,
}SYSCTL_nRESET_BEHAVIOR;

typedef enum
{
    SYSCTL_enXTAL_1MHZ = 0UL,
    SYSCTL_enXTAL_1_8432MHZ = 1UL,
    SYSCTL_enXTAL_2MHZ = 2UL,
    SYSCTL_enXTAL_2_4576MHZ = 3UL,
    SYSCTL_enXTAL_3_579545MHZ = 4UL,
    SYSCTL_enXTAL_3_6864MHZ = 5UL,
    SYSCTL_enXTAL_4MHZ = 6UL,
    SYSCTL_enXTAL_4_0960MHZ = 7UL,
    SYSCTL_enXTAL_4_9152MHZ = 8UL,
    SYSCTL_enXTAL_5MHZ = 9UL,
    SYSCTL_enXTAL_5_1200MHZ = 10UL,
    SYSCTL_enXTAL_6MHZ = 11UL,
    SYSCTL_enXTAL_6_1440MHZ = 12UL,
    SYSCTL_enXTAL_7_3728MHZ = 13UL,
    SYSCTL_enXTAL_8MHZ = 14UL,
    SYSCTL_enXTAL_8_1920MHZ = 15UL,
    SYSCTL_enXTAL_10MHZ = 16UL,
    SYSCTL_enXTAL_12MHZ = 17UL,
    SYSCTL_enXTAL_12_2880MHZ = 18UL,
    SYSCTL_enXTAL_13_5600MHZ = 19UL,
    SYSCTL_enXTAL_14_318180MHZ = 20UL,
    SYSCTL_enXTAL_16MHZ = 21UL,
    SYSCTL_enXTAL_16_33840MHZ = 22UL,
    SYSCTL_enXTAL_18MHZ = 23UL,
    SYSCTL_enXTAL_20MHZ = 24UL,
    SYSCTL_enXTAL_24MHZ = 25UL,
    SYSCTL_enXTAL_25MHZ = 26UL,
    SYSCTL_enXTAL_MAX = 27UL,
    SYSCTL_enXTAL_UNDEF = UNDEF_VALUE,
}SYSCTL_nXTAL;

typedef enum
{
    SYSCTL_enSYSCLK_SRC_OSCCLK = 0UL,
    SYSCTL_enSYSCLK_SRC_PLLCLK = 1UL,
    SYSCTL_enSYSCLK_SRC_UNDEF = UNDEF_VALUE,
}SYSCTL_nSYSCLK_SRC;

typedef enum
{
    SYSCTL_enOSCCLK_SRC_PIOSC = 0UL,
    SYSCTL_enOSCCLK_SRC_LFIOSC = 2UL,
    SYSCTL_enOSCCLK_SRC_MOSC = 3UL,
    SYSCTL_enOSCCLK_SRC_RTCOSC = 4UL,
    SYSCTL_enOSCCLK_SRC_UNDEF = UNDEF_VALUE,
}SYSCTL_nOSCCLK_SRC;

typedef enum
{
    SYSCTL_enOUTCLK_SRC_SYSCLK = 0UL,
    SYSCTL_enOUTCLK_SRC_PIOSC = 1UL,
    SYSCTL_enOUTCLK_SRC_MOSC = 2UL,
    SYSCTL_enOUTCLK_SRC_UNDEF = UNDEF_VALUE,
}SYSCTL_nOUTCLK_SRC;

typedef enum
{
    SYSCTL_enALTCLK_SRC_PIOSC = 0UL,
    SYSCTL_enALTCLK_SRC_RTCOSC = 3UL,
    SYSCTL_enALTCLK_SRC_LFIOSC = 4UL,
    SYSCTL_enALTCLK_SRC_UNDEF = UNDEF_VALUE,
}SYSCTL_nALTCLK_SRC;

typedef enum
{
    SYSCTL_enBOR_EVENT_NONE = 0UL,
    SYSCTL_enBOR_EVENT_SYSINT = 1UL,
    SYSCTL_enBOR_EVENT_NMI = 2UL,
    SYSCTL_enBOR_EVENT_RESET = 3UL,
    SYSCTL_enBOR_EVENT_UNDEF = UNDEF_VALUE,
}SYSCTL_nBOR_EVENT;

typedef enum
{
    SYSCTL_enMOSC_FAILURE_RESET = 0UL,
    SYSCTL_enMOSC_FAILURE_SYSINT = 1UL,
    SYSCTL_enMOSC_FAILURE_UNDEF = UNDEF_VALUE,
}SYSCTL_nMOSC_FAILURE;

typedef enum
{
    SYSCTL_enLDO_VOTAGE_0_90V = 0x12UL,
    SYSCTL_enLDO_VOTAGE_0_95V = 0x13UL,
    SYSCTL_enLDO_VOTAGE_1_00V = 0x14UL,
    SYSCTL_enLDO_VOTAGE_1_05V = 0x15UL,
    SYSCTL_enLDO_VOTAGE_1_10V = 0x16UL,
    SYSCTL_enLDO_VOTAGE_1_15V = 0x17UL,
    SYSCTL_enLDO_VOTAGE_1_20V = 0x18UL,
    SYSCTL_enLDO_VOTAGE_UNDEF = UNDEF_VALUE,
}SYSCTL_nLDO_VOTAGE;

typedef enum
{
    SYSCTL_enSRAM_POWER_MODE_ACTIVE = 0UL,
    SYSCTL_enSRAM_POWER_MODE_STANDBY = 1UL,
    SYSCTL_enSRAM_POWER_MODE_LOW_POWER = 3UL,
    SYSCTL_enSRAM_POWER_MODE_MAX = 4UL,
    SYSCTL_enSRAM_POWER_MODE_UNDEF = UNDEF_VALUE,
}SYSCTL_nSRAM_POWER_MODE;

typedef enum
{
    SYSCTL_enFLASH_POWER_MODE_ACTIVE = 0UL,
    SYSCTL_enFLASH_POWER_MODE_LOW_POWER = 2UL,
    SYSCTL_enFLASH_POWER_MODE_MAX = 3UL,
    SYSCTL_enFLASH_POWER_MODE_UNDEF = UNDEF_VALUE,
}SYSCTL_nFLASH_POWER_MODE;

typedef enum
{
    SYSCTL_enMODULE_MEMORY_POWER_OFF = 0UL,
    SYSCTL_enMODULE_MEMORY_POWER_RETENTION = 1UL,
    SYSCTL_enMODULE_MEMORY_POWER_ON = 3UL,
    SYSCTL_enMODULE_MEMORY_POWER_UNDEF = UNDEF_VALUE,
}SYSCTL_nMODULE_MEMORY_POWER;

typedef enum
{
    SYSCTL_enMODULE_POWER_STATUS_OFF = 0UL,
    SYSCTL_enMODULE_POWER_STATUS_ON = 3UL,
    SYSCTL_enMODULE_POWER_STATUS_UNDEF = UNDEF_VALUE,
}SYSCTL_nMODULE_POWER_STATUS;

typedef enum
{
    SYSCTL_enPIOSC_RESULT_NOTSTARTED = 0UL,
    SYSCTL_enPIOSC_RESULT_SUCCESS = 1UL,
    SYSCTL_enPIOSC_RESULT_FAILED = 2UL,
    SYSCTL_enPIOSC_RESULT_UNDEF = UNDEF_VALUE,
}SYSCTL_nPIOSC_RESULT;

typedef enum
{
    SYSCTL_enMOSC_RANGE_LOW = 0UL,
    SYSCTL_enMOSC_RANGE_HIGH = 1UL,
    SYSCTL_enMOSC_RANGE_UNDEF = UNDEF_VALUE,
}SYSCTL_nMOSC_RANGE;

typedef enum
{
    SYSCTL_enMEM_HIGHTIME_0_5= 0UL,
    SYSCTL_enMEM_HIGHTIME_1_0= 1UL,
    SYSCTL_enMEM_HIGHTIME_1_5= 2UL,
    SYSCTL_enMEM_HIGHTIME_2_0= 3UL,
    SYSCTL_enMEM_HIGHTIME_2_5= 4UL,
    SYSCTL_enMEM_HIGHTIME_3_0= 5UL,
    SYSCTL_enMEM_HIGHTIME_3_5= 6UL,
    SYSCTL_enMEM_HIGHTIME_4_0= 7UL,
    SYSCTL_enMEM_HIGHTIME_4_5= 8UL,
    SYSCTL_enMEM_HIGHTIME_UNDEF = UNDEF_VALUE,
}SYSCTL_nMEM_HIGHTIME;

typedef enum
{
    SYSCTL_enMEM_WAITSTATE_0= 0UL,
    SYSCTL_enMEM_WAITSTATE_1= 1UL,
    SYSCTL_enMEM_WAITSTATE_2= 2UL,
    SYSCTL_enMEM_WAITSTATE_3= 3UL,
    SYSCTL_enMEM_WAITSTATE_4= 4UL,
    SYSCTL_enMEM_WAITSTATE_5= 5UL,
    SYSCTL_enMEM_WAITSTATE_6= 6UL,
    SYSCTL_enMEM_WAITSTATE_7= 7UL,
    SYSCTL_enMEM_WAITSTATE_UNDEF = UNDEF_VALUE,
}SYSCTL_nMEM_WAITSTATE;

typedef enum
{
    SYSCTL_enMEM_CLOCKEDGE_RISING= 0UL,
    SYSCTL_enMEM_CLOCKEDGE_FAILING= 1UL,
    SYSCTL_enMEM_CLOCKEDGE_UNDEF = UNDEF_VALUE,
}SYSCTL_nMEM_CLOCKEDGE;

typedef enum
{
    SYSCTL_enWDT0 = (UBase_t) (((UBase_t) 0UL << 8UL) | (0UL)),
    SYSCTL_enWDT1 = (UBase_t) (((UBase_t) 0UL << 8UL) | (1UL)),

    SYSCTL_enTIMER0 = (UBase_t) (((UBase_t) 1UL << 8UL) | (0UL)),
    SYSCTL_enTIMER1 = (UBase_t) (((UBase_t) 1UL << 8UL) | (1UL)),
    SYSCTL_enTIMER2 = (UBase_t) (((UBase_t) 1UL << 8UL) | (2UL)),
    SYSCTL_enTIMER3 = (UBase_t) (((UBase_t) 1UL << 8UL) | (3UL)),
    SYSCTL_enTIMER4 = (UBase_t) (((UBase_t) 1UL << 8UL) | (4UL)),
    SYSCTL_enTIMER5 = (UBase_t) (((UBase_t) 1UL << 8UL) | (5UL)),
    SYSCTL_enTIMER6 = (UBase_t) (((UBase_t) 1UL << 8UL) | (6UL)),
    SYSCTL_enTIMER7 = (UBase_t) (((UBase_t) 1UL << 8UL) | (7UL)),

    SYSCTL_enGPIOA = (UBase_t) (((UBase_t) 2UL << 8UL) | (0UL)),
    SYSCTL_enGPIOB = (UBase_t) (((UBase_t) 2UL << 8UL) | (1UL)),
    SYSCTL_enGPIOC = (UBase_t) (((UBase_t) 2UL << 8UL) | (2UL)),
    SYSCTL_enGPIOD = (UBase_t) (((UBase_t) 2UL << 8UL) | (3UL)),
    SYSCTL_enGPIOE = (UBase_t) (((UBase_t) 2UL << 8UL) | (4UL)),
    SYSCTL_enGPIOF = (UBase_t) (((UBase_t) 2UL << 8UL) | (5UL)),
    SYSCTL_enGPIOG = (UBase_t) (((UBase_t) 2UL << 8UL) | (6UL)),
    SYSCTL_enGPIOH = (UBase_t) (((UBase_t) 2UL << 8UL) | (7UL)),
    SYSCTL_enGPIOJ = (UBase_t) (((UBase_t) 2UL << 8UL) | (8UL)),
    SYSCTL_enGPIOK = (UBase_t) (((UBase_t) 2UL << 8UL) | (9UL)),
    SYSCTL_enGPIOL = (UBase_t) (((UBase_t) 2UL << 8UL) | (10UL)),
    SYSCTL_enGPIOM = (UBase_t) (((UBase_t) 2UL << 8UL) | (11UL)),
    SYSCTL_enGPION = (UBase_t) (((UBase_t) 2UL << 8UL) | (12UL)),
    SYSCTL_enGPIOP = (UBase_t) (((UBase_t) 2UL << 8UL) | (13UL)),
    SYSCTL_enGPIOQ = (UBase_t) (((UBase_t) 2UL << 8UL) | (14UL)),

    SYSCTL_enDMA = (UBase_t) (((UBase_t) 3UL << 8UL) | (0UL)),

    SYSCTL_enEPI = (UBase_t) (((UBase_t) 4UL << 8UL) | (0UL)),

    SYSCTL_enHIB = (UBase_t) (((UBase_t) 5UL << 8UL) | (0UL)),

    SYSCTL_enUART0 = (UBase_t) (((UBase_t) 6UL << 8UL) | (0UL)),
    SYSCTL_enUART1 = (UBase_t) (((UBase_t) 6UL << 8UL) | (1UL)),
    SYSCTL_enUART2 = (UBase_t) (((UBase_t) 6UL << 8UL) | (2UL)),
    SYSCTL_enUART3 = (UBase_t) (((UBase_t) 6UL << 8UL) | (3UL)),
    SYSCTL_enUART4 = (UBase_t) (((UBase_t) 6UL << 8UL) | (4UL)),
    SYSCTL_enUART5 = (UBase_t) (((UBase_t) 6UL << 8UL) | (5UL)),
    SYSCTL_enUART6 = (UBase_t) (((UBase_t) 6UL << 8UL) | (6UL)),
    SYSCTL_enUART7 = (UBase_t) (((UBase_t) 6UL << 8UL) | (7UL)),

    SYSCTL_enSSI0 = (UBase_t) (((UBase_t) 7UL << 8UL) | (0UL)),
    SYSCTL_enSSI1 = (UBase_t) (((UBase_t) 7UL << 8UL) | (1UL)),
    SYSCTL_enSSI2 = (UBase_t) (((UBase_t) 7UL << 8UL) | (2UL)),
    SYSCTL_enSSI3 = (UBase_t) (((UBase_t) 7UL << 8UL) | (3UL)),

    SYSCTL_enI2C0 = (UBase_t) (((UBase_t) 8UL << 8UL) | (0UL)),
    SYSCTL_enI2C1 = (UBase_t) (((UBase_t) 8UL << 8UL) | (1UL)),
    SYSCTL_enI2C2 = (UBase_t) (((UBase_t) 8UL << 8UL) | (2UL)),
    SYSCTL_enI2C3 = (UBase_t) (((UBase_t) 8UL << 8UL) | (3UL)),
    SYSCTL_enI2C4 = (UBase_t) (((UBase_t) 8UL << 8UL) | (4UL)),
    SYSCTL_enI2C5 = (UBase_t) (((UBase_t) 8UL << 8UL) | (5UL)),
    SYSCTL_enI2C6 = (UBase_t) (((UBase_t) 8UL << 8UL) | (6UL)),
    SYSCTL_enI2C7 = (UBase_t) (((UBase_t) 8UL << 8UL) | (7UL)),
    SYSCTL_enI2C8 = (UBase_t) (((UBase_t) 8UL << 8UL) | (8UL)),
    SYSCTL_enI2C9 = (UBase_t) (((UBase_t) 8UL << 8UL) | (9UL)),

    SYSCTL_enUSB = (UBase_t) (((UBase_t) 10UL << 8UL) | (0UL)),

    SYSCTL_enEPHY = (UBase_t) (((UBase_t) 12UL << 8UL) | (0UL)),

    SYSCTL_enCAN0 = (UBase_t) (((UBase_t) 13UL << 8UL) | (0UL)),
    SYSCTL_enCAN1 = (UBase_t) (((UBase_t) 13UL << 8UL) | (1UL)),

    SYSCTL_enADC0 = (UBase_t) (((UBase_t) 14UL << 8UL) | (0UL)),
    SYSCTL_enADC1 = (UBase_t) (((UBase_t) 14UL << 8UL) | (1UL)),

    SYSCTL_enACMP = (UBase_t) (((UBase_t) 15UL << 8UL) | (0UL)),

    SYSCTL_enPWM0 = (UBase_t) (((UBase_t) 16UL << 8UL) | (0UL)),

    SYSCTL_enQEI0 = (UBase_t) (((UBase_t) 17UL << 8UL) | (0UL)),

    SYSCTL_enLPC = (UBase_t) (((UBase_t) 18UL << 8UL) | (0UL)),

    SYSCTL_enPECI = (UBase_t) (((UBase_t) 20UL << 8UL) | (0UL)),

    SYSCTL_enFAN = (UBase_t) (((UBase_t) 21UL << 8UL) | (0UL)),

    SYSCTL_enEEPROM = (UBase_t) (((UBase_t) 22UL << 8UL) | (0UL)),

    SYSCTL_enRTS = (UBase_t) (((UBase_t) 28UL << 8UL) | (0UL)),

    SYSCTL_enCCM = (UBase_t) (((UBase_t) 29UL << 8UL) | (0UL)),

    SYSCTL_enLCD = (UBase_t) (((UBase_t) 36UL << 8UL) | (0UL)),

    SYSCTL_enOWIRE = (UBase_t) (((UBase_t) 38UL << 8UL) | (0UL)),

    SYSCTL_enEMAC = (UBase_t) (((UBase_t) 39UL << 8UL) | (0UL)),

    SYSCTL_enPRB = (UBase_t) (((UBase_t) 40UL << 8UL) | (0UL)),

    SYSCTL_enHIM = (UBase_t) (((UBase_t) 41UL << 8UL) | (0UL)),
    SYSCTL_enPERIPHERAL_UNDEF = UNDEF_VALUE,
}SYSCTL_nPERIPHERAL;



typedef struct
{
    SYSCTL_nXTAL enExternalCrystal;
    SYSCTL_nOSCCLK_SRC enOscillatorSource;
    SYSCTL_nSYSCLK_SRC enSystemClockSource;
    SYSCTL_nVCO enVCORange;
}SYSCTL_CONFIG_t;

typedef MCU_Register_t SYSCTL_Register_t;
typedef MCU_pvfIRQVectorHandler_t SYSCTL_pvfIRQVectorHandler_t;
typedef MCU_pvfIRQSourceHandler_t SYSCTL_pvfIRQSourceHandler_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_ENUM_H_ */

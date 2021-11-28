/**
 *
 * @file TIMER_Enum.h
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
 * @verbatim 4 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date Author Version Description
 * 4 jul. 2020 vyldram 1.0 initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_ENUM_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_ENUM_H_

#include <xDriver_MCU/Common/xHeader/MCU_Variables.h>

typedef enum
{
    TIMER_enINT_NOOCCUR = 0UL,
    TIMER_enINT_OCCUR = 1UL,
    TIMER_enINT_STATUS_UNDEF = 0xFFFFFFFFUL,
}TIMER_nINT_STATUS;

typedef enum
{
    TIMER_enSTATUS_OK = 0UL,
    TIMER_enSTATUS_ERROR = 1UL,
    TIMER_enSTATUS_UNDEF = 0xFFFFFFFFUL,
}TIMER_nSTATUS;

typedef enum
{
    TIMER_enNOREADY = 0UL,
    TIMER_enREADY = 1UL,
}TIMER_nREADY;

typedef enum
{
    TIMER_enSUBMODULE_A = 0UL,
    TIMER_enSUBMODULE_B = 1UL,
    TIMER_enSUBMODULE_W = 2UL,
    TIMER_enSUBMODULE_MAX = 3UL,
}TIMER_nSUBMODULE;

typedef enum
{
    TIMER_enMODULE_NUM_0 = 0UL,
    TIMER_enMODULE_NUM_1 = 1UL,
    TIMER_enMODULE_NUM_2 = 2UL,
    TIMER_enMODULE_NUM_3 = 3UL,
    TIMER_enMODULE_NUM_4 = 4UL,
    TIMER_enMODULE_NUM_5 = 5UL,
    TIMER_enMODULE_NUM_6 = 6UL,
    TIMER_enMODULE_NUM_7 = 7UL,
    TIMER_enMODULE_NUM_MAX = 8UL,
}TIMER_nMODULE_NUM;

typedef enum
{
    TIMER_enT0A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_0),
    TIMER_enT1A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_1),
    TIMER_enT2A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_2),
    TIMER_enT3A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_3),
    TIMER_enT4A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_4),
    TIMER_enT5A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_5),
    TIMER_enT6A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_6),
    TIMER_enT7A = (((uint32_t) TIMER_enSUBMODULE_A << 8UL) | (uint32_t) TIMER_enMODULE_NUM_7),

    TIMER_enT0B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_0),
    TIMER_enT1B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_1),
    TIMER_enT2B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_2),
    TIMER_enT3B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_3),
    TIMER_enT4B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_4),
    TIMER_enT5B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_5),
    TIMER_enT6B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_6),
    TIMER_enT7B = (((uint32_t) TIMER_enSUBMODULE_B << 8UL) | (uint32_t) TIMER_enMODULE_NUM_7),

    TIMER_enT0W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_0),
    TIMER_enT1W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_1),
    TIMER_enT2W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_2),
    TIMER_enT3W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_3),
    TIMER_enT4W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_4),
    TIMER_enT5W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_5),
    TIMER_enT6W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_6),
    TIMER_enT7W = (((uint32_t) TIMER_enSUBMODULE_W << 8UL) | (uint32_t) TIMER_enMODULE_NUM_7),

    TIMER_enMODULE_UNDEF = 0xFFFFFFFF,
}TIMER_nMODULE;


typedef enum
{
    TIMER_enINTERRUPT_SW = 0UL,
    TIMER_enINTERRUPT_TIMEOUT = 1UL,
    TIMER_enINTERRUPT_CAPTURE_MATCH = 2UL,
    TIMER_enINTERRUPT_CAPTURE_EVENT = 3UL,
    TIMER_enINTERRUPT_RTC = 4UL,
    TIMER_enINTERRUPT_MATCH = 5UL,
    TIMER_enINTERRUPT_DMA = 6UL,
    TIMER_enINTERRUPT_MAX = 7UL,
}TIMER_nINTERRUPT;

typedef enum
{
    TIMER_enINT_TIMEOUT = 0x01UL,
    TIMER_enINT_CAPTURE_MATCH = 0x02UL,
    TIMER_enINT_CAPTURE_EVENT = 0x04UL,

    TIMER_enINT_RTC = 0x08UL,
    TIMER_enINT_MATCH = 0x10UL,
    TIMER_enINT_DMA = 0x20UL,
    TIMER_enINT_ALL = 0x3FUL,
    TIMER_enINT_UNDEF = 0xFFFFFUL,
}TIMER_nINT;

typedef enum
{
    TIMER_enINT_TA_TIMEOUT = 0x1UL,
    TIMER_enINT_TA_CAPTURE_MATCH = 0x2UL,
    /*TAPWMIE needs to be enabled with PWM mode*/
    TIMER_enINT_TA_CAPTURE_EVENT = 0x4UL,
    /*TAMIE needs to enabled with MATCH_TA*/
    TIMER_enINT_TA_MATCH = 0x10UL,
    TIMER_enINT_TA_DMA = 0x20UL,
    TIMER_enINT_TA_ALL = 0x37UL,
}TIMER_nINT_TA;

typedef enum
{
    TIMER_enINT_TW_TIMEOUT = 0x1UL,
    TIMER_enINT_TW_CAPTURE_MATCH = 0x2UL,
    TIMER_enINT_TW_CAPTURE_EVENT = 0x4UL,
    TIMER_enINT_TW_RTC = 0x8UL,
    /*TWMIE needs to enabled with MATCH_TW*/
    TIMER_enINT_TW_MATCH = 0x10UL,
    TIMER_enINT_TW_DMA = 0x20UL,
    TIMER_enINT_TW_ALL = 0x3FUL,
}TIMER_nINT_TW;

typedef enum
{
    TIMER_enINT_TB_TIMEOUT = (uint32_t) 0x1UL << 8UL,
    TIMER_enINT_TB_CAPTURE_MATCH = (uint32_t) 0x2UL << 8UL,
    /*TBPWMIE needs to be enabled with PWM mode*/
    TIMER_enINT_TB_CAPTURE_EVENT = (uint32_t) 0x4UL << 8UL,
    /*TBMIE needs to enabled with MATCH_TB*/
    TIMER_enINT_TB_MATCH = (uint32_t) 0x8UL << 8UL,
    TIMER_enINT_TB_DMA = (uint32_t) 0x20UL << 8UL,
    TIMER_enINT_TB_ALL = (uint32_t) 0x2F00UL,
}TIMER_nINT_TB;

typedef enum
{
    TIMER_enEVENT_TIMEOUT = 0x01UL,
    TIMER_enEVENT_CAPTURE_MATCH = 0x02UL,
    TIMER_enEVENT_CAPTURE_EVENT = 0x04UL,

    TIMER_enEVENT_RTC = 0x08UL,
    TIMER_enEVENT_MATCH = 0x10UL,
    TIMER_enEVENT_ALL = 0x3FUL,
    TIMER_enEVENT_UNDEF = 0xFFFFFUL,
}TIMER_nEVENT;

typedef enum
{
    TIMER_enEVENT_TA_TIMEOUT = 0x1UL,
    TIMER_enEVENT_TA_CAPTURE_MATCH = 0x2UL,
    /*TAPWMIE needs to be enabled with PWM mode*/
    TIMER_enEVENT_TA_CAPTURE_EVENT = 0x4UL,
    /*TAMIE needs to enabled with MATCH_TA*/
    TIMER_enEVENT_TA_MATCH = 0x10UL,
    TIMER_enEVENT_TA_ALL = 0x17UL,
}TIMER_nEVENT_TA;

typedef enum
{
    TIMER_enEVENT_TW_TIMEOUT = 0x1UL,
    TIMER_enEVENT_TW_CAPTURE_MATCH = 0x2UL,
    TIMER_enEVENT_TW_CAPTURE_EVENT = 0x4UL,
    TIMER_enEVENT_TW_RTC = 0x8UL,
    /*TWMIE needs to enabled with MATCH_TW*/
    TIMER_enEVENT_TW_MATCH = 0x10UL,
    TIMER_enEVENT_TW_ALL = 0x1FUL,
}TIMER_nEVENT_TW;

typedef enum
{
    TIMER_enEVENT_TB_TIMEOUT = (uint32_t) 0x1UL << 8UL,
    TIMER_enEVENT_TB_CAPTURE_MATCH = (uint32_t) 0x2UL << 8UL,
    /*TBPWMIE needs to be enabled with PWM mode*/
    TIMER_enEVENT_TB_CAPTURE_EVENT = (uint32_t) 0x4UL << 8UL,
    /*TBMIE needs to enabled with MATCH_TB*/
    TIMER_enEVENT_TB_MATCH = (uint32_t) 0x8UL << 8UL,
    TIMER_enEVENT_TB_ALL = (uint32_t) 0x0F00UL,
}TIMER_nEVENT_TB;

typedef enum
{
    TIMER_enPRI0 = 0UL,
    TIMER_enPRI1 = 1UL,
    TIMER_enPRI2 = 2UL,
    TIMER_enPRI3 = 3UL,
    TIMER_enPRI4 = 4UL,
    TIMER_enPRI5 = 5UL,
    TIMER_enPRI6 = 6UL,
    TIMER_enPRI7 = 7UL,
    TIMER_enPRI_MIN = 7UL,
    TIMER_enDEFAULT = 0xFFFFFFFFUL,
}TIMER_nPRIORITY;

typedef enum
{
    TIMER_enCONFIG_WIDE = 0UL,
    TIMER_enCONFIG_RTC = 1UL,
    TIMER_enCONFIG_INDIVIDUAL = 4UL,
    TIMER_enCONFIG_UNDEF = 0xFFFFFFFFUL,
}TIMER_nCONFIG;

typedef enum
{
    TIMER_enSUB_MODE_RESERVED = 0UL,
    TIMER_enSUB_MODE_ONE_SHOT = 1UL,
    TIMER_enSUB_MODE_PERIODIC = 2UL,
    TIMER_enSUB_MODE_CAPTURE = 3UL,
    TIMER_enSUB_MODE_UNDEF = 0xFFFFFFFFUL,
}TIMER_nSUB_MODE;

typedef enum
{
    TIMER_enEDGE_MODE_COUNT = 0UL,
    TIMER_enEDGE_MODE_TIME = 1UL,
    TIMER_enEDGE_MODE_UNDEF = 0xFFFFFFFFUL,
}TIMER_nEDGE_MODE;

typedef enum
{
    TIMER_enALT_MODE_CC = 0UL,
    TIMER_enALT_MODE_PWM = 1UL,
    TIMER_enALT_MODE_UNDEF = 0xFFFFFFFFUL,
}TIMER_nALT_MODE;

typedef enum
{
    TIMER_enCOUNT_DIR_DOWN = 0UL,
    TIMER_enCOUNT_DIR_UP = 1UL,
    TIMER_enCOUNT_DIR_UNDEF = 0xFFFFFFFFUL,
}TIMER_nCOUNT_DIR;

typedef enum
{
    TIMER_enWAIT_NOTRIGGER = 0UL,
    TIMER_enWAIT_DAISY = 1UL,
    TIMER_enWAIT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nWAIT;

typedef enum
{
    TIMER_enSNAPSHOT_DIS = 0UL,
    TIMER_enSNAPSHOT_ENA = 1UL,
    TIMER_enSNAPSHOT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nSNAPSHOT;

typedef enum
{
    TIMER_enPWM_INT_DIS = 0UL,
    TIMER_enPWM_INT_ENA = 1UL,
    TIMER_enPWM_INT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nPWM_INT;

typedef enum
{
    TIMER_enEVENT_INT_DIS = 0UL,
    TIMER_enEVENT_INT_ENA = 1UL,
    TIMER_enEVENT_INT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nEVENT_INT;

typedef enum
{
    TIMER_enUPDATE_INTERVAL_CYCLE = 0UL,
    TIMER_enUPDATE_INTERVAL_TIMEOUT = 1UL,
    TIMER_enUPDATE_INTERVAL_UNDEF = 0xFFFFFFFFUL,
}TIMER_nUPDATE_INTERVAL;

typedef enum
{
    TIMER_enTIMEOUT_INT_NORMAL = 0UL,
    TIMER_enTIMEOUT_INT_DISABLE = 1UL,
    TIMER_enTIMEOUT_INT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nTIMEOUT_INT;

typedef enum
{
    TIMER_enMATCH_EVENT_DISABLE = 0UL,
    TIMER_enMATCH_EVENT_TOGGLE = 1UL,
    TIMER_enMATCH_EVENT_CLEAR = 2UL,
    TIMER_enMATCH_EVENT_SET = 3UL,
    TIMER_enMATCH_EVENT_SET_TOGGLE = 4UL,
    TIMER_enMATCH_EVENT_CLEAR_TOGGLE = 5UL,
    TIMER_enMATCH_EVENT_SET_CLEAR = 6UL,
    TIMER_enMATCH_EVENT_CLEAR_SET = 7UL,
    TIMER_enMATCH_EVENT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nMATCH_EVENT;

typedef enum
{
    TIMER_enUPDATE_MATCH_CYCLE = 0UL,
    TIMER_enUPDATE_MATCH_TIMEOUT = 1UL,
    TIMER_enUPDATE_MATCH_UNDEF = 0xFFFFFFFFUL,
}TIMER_nUPDATE_MATCH;

typedef enum
{
    TIMER_enPWM_OUT_INIT_LOW = 0UL,
    TIMER_enPWM_OUT_INIT_HIGH = 1UL,
    TIMER_enPWM_OUT_INIT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nPWM_OUT_INIT;

typedef enum
{
    TIMER_enENABLE_STOP = 0UL,
    TIMER_enENABLE_START = 1UL,
    TIMER_enENABLE_UNDEF = 0xFFFFFFFFUL,
}TIMER_nENABLE;

typedef enum
{
    TIMER_enSTALL_CONTINUE = 0UL,
    TIMER_enSTALL_FREEZE = 1UL,
    TIMER_enSTALL_UNDEF = 0xFFFFFFFFUL,
}TIMER_nSTALL;

typedef enum
{
    TIMER_enRTC_STALL_FREEZE = 0UL,
    TIMER_enRTC_STALL_CONTINUE = 1UL,
    TIMER_enRTC_STALL_UNDEF = 0xFFFFFFFFUL,
}TIMER_nRTC_STALL;

typedef enum
{
    TIMER_enADC_TRIGGER_DIS = 0UL,
    TIMER_enADC_TRIGGER_ENA = 1UL,
    TIMER_enADC_TRIGGER_UNDEF = 0xFFFFFFFFUL,
}TIMER_nADC_TRIGGER;

typedef enum
{
    TIMER_enPWM_OUTPUT_STRAIGHT = 0UL,
    TIMER_enPWM_OUTPUT_INVERTED = 1UL,
    TIMER_enPWM_OUTPUT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nPWM_OUTPUT;

typedef enum
{
    TIMER_enEDGE_EVENT_POSITIVE = 0UL,
    TIMER_enEDGE_EVENT_NEGATIVE = 1UL,
    TIMER_enEDGE_EVENT_BOTH = 3UL,
    TIMER_enEDGE_EVENT_UNDEF = 0xFFFFFFFFUL,
}TIMER_nEDGE_EVENT;

typedef enum
{
    TIMER_enCLOCK_SYSCLK = 0UL,
    TIMER_enCLOCK_ALTCLK = 1UL,
    TIMER_enCLOCK_UNDEF = 0xFFFFFFFFUL,
}TIMER_nCLOCK;

typedef enum
{
    TIMER_enSYNC_T0A = (uint32_t) ((uint32_t) 1UL << 0UL),
    TIMER_enSYNC_T0W = (uint32_t) ((uint32_t) 1UL << 0UL),
    TIMER_enSYNC_T0B = (uint32_t) ((uint32_t) 2UL << 0UL),
    TIMER_enSYNC_T1A = (uint32_t) ((uint32_t) 1UL << 2UL),
    TIMER_enSYNC_T1W = (uint32_t) ((uint32_t) 1UL << 2UL),
    TIMER_enSYNC_T1B = (uint32_t) ((uint32_t) 2UL << 2UL),
    TIMER_enSYNC_T2A = (uint32_t) ((uint32_t) 1UL << 4UL),
    TIMER_enSYNC_T2W = (uint32_t) ((uint32_t) 1UL << 4UL),
    TIMER_enSYNC_T2B = (uint32_t) ((uint32_t) 2UL << 4UL),
    TIMER_enSYNC_T3A = (uint32_t) ((uint32_t) 1UL << 6UL),
    TIMER_enSYNC_T3W = (uint32_t) ((uint32_t) 1UL << 6UL),
    TIMER_enSYNC_T3B = (uint32_t) ((uint32_t) 2UL << 6UL),
    TIMER_enSYNC_T4A = (uint32_t) ((uint32_t) 1UL << 8UL),
    TIMER_enSYNC_T4W = (uint32_t) ((uint32_t) 1UL << 8UL),
    TIMER_enSYNC_T4B = (uint32_t) ((uint32_t) 2UL << 8UL),
    TIMER_enSYNC_T5A = (uint32_t) ((uint32_t) 1UL << 10UL),
    TIMER_enSYNC_T5W = (uint32_t) ((uint32_t) 1UL << 10UL),
    TIMER_enSYNC_T5B = (uint32_t) ((uint32_t) 2UL << 10UL),
    TIMER_enSYNC_T6A = (uint32_t) ((uint32_t) 1UL << 12UL),
    TIMER_enSYNC_T6W = (uint32_t) ((uint32_t) 1UL << 12UL),
    TIMER_enSYNC_T6B = (uint32_t) ((uint32_t) 2UL << 12UL),
    TIMER_enSYNC_T7A = (uint32_t) ((uint32_t) 1UL << 14UL),
    TIMER_enSYNC_T7W = (uint32_t) ((uint32_t) 1UL << 14UL),
    TIMER_enSYNC_T7B = (uint32_t) ((uint32_t) 2UL << 14UL),

    TIMER_enSYNC_ALL = (uint32_t) ((uint32_t) 0xFFFFFFFFUL),
}TIMER_nSYNC;

typedef enum
{
    /*  DIR*/
    TIMER_enMODE_ONE_SHOT_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_ONE_SHOT << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_ONE_SHOT_WIDE_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_WIDE << 16UL) | ((uint32_t) TIMER_enSUB_MODE_ONE_SHOT << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_ONE_SHOT_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_ONE_SHOT << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_ONE_SHOT_WIDE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_WIDE << 16UL) | ((uint32_t) TIMER_enSUB_MODE_ONE_SHOT << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,

    TIMER_enMODE_PERIODIC_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_PERIODIC_INDIVIDUAL_SNAPSHOT_UP = ((uint32_t) TIMER_enSNAPSHOT_ENA << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_PERIODIC_WIDE_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_WIDE << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_PERIODIC_WIDE_SNAPSHOT_UP = ((uint32_t) TIMER_enSNAPSHOT_ENA << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_WIDE << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_PERIODIC_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PERIODIC_INDIVIDUAL_SNAPSHOT_DOWN = ((uint32_t) TIMER_enSNAPSHOT_ENA << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PERIODIC_WIDE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_WIDE << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PERIODIC_WIDE_SNAPSHOT_DOWN = ((uint32_t) TIMER_enSNAPSHOT_ENA << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_WIDE << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,

    TIMER_enMODE_RTC_WIDE_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_RTC << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,

    TIMER_enMODE_EDGE_COUNT_POSITIVE_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_EDGE_COUNT_NEGATIVE_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_EDGE_COUNT_BOTH_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_EDGE_COUNT_POSITIVE_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_EDGE_COUNT_NEGATIVE_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_EDGE_COUNT_BOTH_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,

    TIMER_enMODE_EDGE_TIME_POSITIVE_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_TIME << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_EDGE_TIME_NEGATIVE_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_TIME << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_EDGE_TIME_BOTH_INDIVIDUAL_UP = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_TIME << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_UP,
    TIMER_enMODE_EDGE_TIME_POSITIVE_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_TIME << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_EDGE_TIME_NEGATIVE_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_TIME << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_EDGE_TIME_BOTH_INDIVIDUAL_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_CAPTURE << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_TIME << 8UL) | ((uint32_t) TIMER_enALT_MODE_CC << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,

    TIMER_enMODE_PWM_INDIVIDUAL_LOW_POSITIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_LOW_NEGATIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_LOW_BOTH_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_LOW_INVERTED_POSITIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_INVERTED << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_LOW_INVERTED_NEGATIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_INVERTED << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_LOW_INVERTED_BOTH_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_LOW << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_INVERTED << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_HIGH_POSITIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_HIGH << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_HIGH_NEGATIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_HIGH << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_HIGH_BOTH_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_HIGH << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_STRAIGHT << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_HIGH_INVERTED_POSITIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_POSITIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_HIGH << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_INVERTED << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_HIGH_INVERTED_NEGATIVE_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_NEGATIVE << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_HIGH << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_INVERTED << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,
    TIMER_enMODE_PWM_INDIVIDUAL_HIGH_INVERTED_BOTH_DOWN = ((uint32_t) TIMER_enSNAPSHOT_DIS << 30UL) | ((uint32_t) TIMER_enEDGE_EVENT_BOTH << 28UL) | ((uint32_t) TIMER_enPWM_OUT_INIT_HIGH << 24UL) | ((uint32_t) TIMER_enPWM_OUTPUT_INVERTED << 20UL) | ((uint32_t) TIMER_enCONFIG_INDIVIDUAL << 16UL) | ((uint32_t) TIMER_enSUB_MODE_PERIODIC << 12UL) | ((uint32_t) TIMER_enEDGE_MODE_COUNT << 8UL) | ((uint32_t) TIMER_enALT_MODE_PWM << 4UL) | (uint32_t) TIMER_enCOUNT_DIR_DOWN,

    TIMER_enMODE_UNDEF = 0xFFFFFFFF,
}TIMER_nMODE;

typedef enum
{
    TIMER_enPRESCALER_NA = 0UL,
    TIMER_enPRESCALER_PRESCALER = 1UL,
    TIMER_enPRESCALER_EXTENSION = 2UL,
    TIMER_enPRESCALER_UNDEF = 0xFFFFFFFFUL,
}TIMER_nPRESCALER;

/*ONESHOT OR PERIODIC and CONTINUES check DIR*/
/* PWM*/
/* CAPTURE*/
typedef struct
{
    TIMER_nCONFIG enConfig;
    TIMER_nSUB_MODE enSubMode;
    TIMER_nEDGE_MODE enEdgeMode;
    TIMER_nALT_MODE enAltMode;
    TIMER_nCOUNT_DIR enDirection;
    TIMER_nSNAPSHOT enSnapShot;
    TIMER_nPWM_OUT_INIT enPWMOutInit;
    TIMER_nPWM_OUTPUT enPWMOut;
    TIMER_nEDGE_EVENT enEdgeEvent;
}TIMER_MODE_t;

typedef struct
{
    TIMER_nWAIT enWaitTrigger;
    TIMER_nUPDATE_INTERVAL enUpdateInterval;
    TIMER_nUPDATE_MATCH enUpdateMatch;
    TIMER_nPWM_INT enPWMInterrupt;
    TIMER_nEVENT_INT enEventInterrupt;
    TIMER_nSTALL enStall;
    TIMER_nRTC_STALL enRTCStall;
    TIMER_nADC_TRIGGER enADCTrigger;
    TIMER_nTIMEOUT_INT enTimeOutInterrupt;
    TIMER_nMATCH_EVENT enMatchEvent;
}TIMER_EXTRAMODE_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_ENUM_H_ */

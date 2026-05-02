/**
 *
 * @file HIB_StructRegister_Bitbanding.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTREGISTER_BITBANDING_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTREGISTER_BITBANDING_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

typedef volatile struct
{
    volatile const UBase_t RTCC [32UL];
}HIB_BITBANDING_RTCC_t;

typedef volatile struct
{
    volatile UBase_t RTCM0 [32UL];
}HIB_BITBANDING_RTCM0_t;

typedef volatile struct
{
    volatile UBase_t RTCLD [32UL];
}HIB_BITBANDING_RTCLD_t;

typedef volatile struct
{
    volatile UBase_t RTCEN;
    volatile UBase_t HIBREQ;
    const UBase_t reserved [1UL];
    volatile UBase_t RTCWEN;
    volatile UBase_t PINWEN;
    const UBase_t reserved1 [1UL];
    volatile UBase_t CLK32EN;
    volatile UBase_t VABORT;
    volatile UBase_t VDD3ON;
    volatile UBase_t BATWKEN;
    volatile UBase_t BATCHK;
    const UBase_t reserved2 [2UL];
    volatile UBase_t VBATSEL [2UL];
    const UBase_t reserved3 [1UL];
    volatile UBase_t OSCBYP;
    volatile UBase_t OSCDRV;
    const UBase_t reserved4 [1UL];
    volatile UBase_t OSCSEL;
    const UBase_t reserved5 [10UL];
    volatile UBase_t RETCLR;
    volatile const UBase_t WRC;
}HIB_BITBANDING_CTL_t;

typedef volatile struct
{
    volatile UBase_t RTCALT0;
    const UBase_t reserved [1UL];
    volatile UBase_t LOWBAT;
    volatile UBase_t EXTW;
    volatile UBase_t WC;
    volatile UBase_t PADIOWK;
    volatile UBase_t RSTWK;
    volatile UBase_t VDDFAIL;
    const UBase_t reserved1 [24UL];
}HIB_BITBANDING_IM_t;

typedef volatile struct
{
    volatile const UBase_t RTCALT0;
    const UBase_t reserved [1UL];
    volatile const UBase_t LOWBAT;
    volatile const UBase_t EXTW;
    volatile const UBase_t WC;
    volatile const UBase_t PADIOWK;
    volatile const UBase_t RSTWK;
    volatile const UBase_t VDDFAIL;
    const UBase_t reserved1 [24UL];
}HIB_BITBANDING_RIS_t;

typedef volatile struct
{
    volatile const UBase_t RTCALT0;
    const UBase_t reserved [1UL];
    volatile const UBase_t LOWBAT;
    volatile const UBase_t EXTW;
    volatile const UBase_t WC;
    volatile const UBase_t PADIOWK;
    volatile const UBase_t RSTWK;
    volatile const UBase_t VDDFAIL;
    const UBase_t reserved1 [24UL];
}HIB_BITBANDING_MIS_t;

typedef volatile struct
{
    volatile UBase_t RTCALT0;
    const UBase_t reserved [1UL];
    volatile UBase_t LOWBAT;
    volatile UBase_t EXTW;
    volatile UBase_t WC;
    volatile UBase_t PADIOWK;
    volatile UBase_t RSTWK;
    volatile UBase_t VDDFAIL;
    const UBase_t reserved1 [24UL];
}HIB_BITBANDING_IC_t;

typedef volatile struct
{
    volatile UBase_t TRIM [16UL];
    const UBase_t reserved [16UL];
}HIB_BITBANDING_RTCT_t;

typedef volatile struct
{
    volatile const UBase_t RTCSSC [15UL];
    const UBase_t reserved [1UL];
    volatile UBase_t RTCSSM [15UL];
    const UBase_t reserved1 [1UL];
}HIB_BITBANDING_RTCSS_t;

typedef volatile struct
{
    volatile UBase_t WUUNLK;
    const UBase_t reserved [3UL];
    volatile UBase_t WURSTEN;
    const UBase_t reserved1 [26UL];
    volatile const UBase_t IOWRC;
}HIB_BITBANDING_IO_t;

typedef volatile struct
{
    volatile UBase_t RTD [32UL];
}HIB_BITBANDING_DATA_t;

typedef volatile struct
{
    volatile UBase_t CALEN;
    const UBase_t reserved [1UL];
    volatile UBase_t CAL24;
    const UBase_t reserved1 [29UL];
}HIB_BITBANDING_CALCTL_t;

typedef volatile struct
{
    volatile const UBase_t SEC [6UL];
    const UBase_t reserved [2UL];
    volatile const UBase_t MIN [6UL];
    const UBase_t reserved1 [2UL];
    volatile const UBase_t HR [5UL];
    const UBase_t reserved2 [1UL];
    volatile const UBase_t AMPM;
    const UBase_t reserved3 [8UL];
    volatile const UBase_t VALID;
}HIB_BITBANDING_CAL0_t;

typedef volatile struct
{
    volatile const UBase_t DOM [5UL];
    const UBase_t reserved [3UL];
    volatile const UBase_t MON [4UL];
    const UBase_t reserved1 [4UL];
    volatile const UBase_t YEAR [7UL];
    const UBase_t reserved2 [1UL];
    volatile const UBase_t DOW [3UL];
    const UBase_t reserved3 [4UL];
    volatile const UBase_t VALID;
}HIB_BITBANDING_CAL1_t;

typedef volatile struct
{
    volatile UBase_t SEC [6UL];
    const UBase_t reserved [2UL];
    volatile UBase_t MIN [6UL];
    const UBase_t reserved1 [2UL];
    volatile UBase_t HR [5UL];
    const UBase_t reserved2 [1UL];
    volatile UBase_t AMPM;
    const UBase_t reserved3 [9UL];
}HIB_BITBANDING_CALLD0_t;

typedef volatile struct
{
    volatile UBase_t DOM [5UL];
    const UBase_t reserved [3UL];
    volatile UBase_t MON [4UL];
    const UBase_t reserved1 [4UL];
    volatile UBase_t YEAR [7UL];
    const UBase_t reserved2 [1UL];
    volatile UBase_t DOW [3UL];
    const UBase_t reserved3 [5UL];
}HIB_BITBANDING_CALLD1_t;

typedef volatile struct
{
    volatile UBase_t SEC [6UL];
    const UBase_t reserved [2UL];
    volatile UBase_t MIN [6UL];
    const UBase_t reserved1 [2UL];
    volatile UBase_t HR [5UL];
    const UBase_t reserved2 [1UL];
    volatile UBase_t AMPM;
    const UBase_t reserved3 [9UL];
}HIB_BITBANDING_CALM0_t;

typedef volatile struct
{
    volatile UBase_t DOM [5UL];
    const UBase_t reserved [27UL];
}HIB_BITBANDING_CALM1_t;

typedef volatile struct
{
    volatile UBase_t HIBLOCK [32UL];
}HIB_BITBANDING_LOCK_t;

typedef volatile struct
{
    volatile UBase_t TPEN;
    const UBase_t reserved [3UL];
    volatile UBase_t TPCLR;
    const UBase_t reserved1 [3UL];
    volatile UBase_t MEMCLR [2UL];
    const UBase_t reserved2 [1UL];
    volatile UBase_t WAKE;
    const UBase_t reserved3 [20UL];
}HIB_BITBANDING_TPCTL_t;

typedef volatile struct
{
    volatile UBase_t XOSCFAIL;
    volatile const UBase_t XOSCST;
    volatile const UBase_t STATE [2UL];
    const UBase_t reserved [28UL];
}HIB_BITBANDING_TPSTAT_t;

typedef volatile struct
{
    volatile UBase_t EN0;
    volatile UBase_t LEV0;
    volatile UBase_t PUEN0;
    volatile UBase_t GFLTR0;
    const UBase_t reserved [4UL];
    volatile UBase_t EN1;
    volatile UBase_t LEV1;
    volatile UBase_t PUEN1;
    volatile UBase_t GFLTR1;
    const UBase_t reserved1 [4UL];
    volatile UBase_t EN2;
    volatile UBase_t LEV2;
    volatile UBase_t PUEN2;
    volatile UBase_t GFLTR2;
    const UBase_t reserved2 [4UL];
    volatile UBase_t EN3;
    volatile UBase_t LEV3;
    volatile UBase_t PUEN3;
    volatile UBase_t GFLTR3;
    const UBase_t reserved3 [4UL];
}HIB_BITBANDING_TPIO_t;


typedef volatile struct
{
    volatile UBase_t EN;
    volatile UBase_t LEV;
    volatile UBase_t PUEN;
    volatile UBase_t GFLTR;
    const UBase_t reserved [4UL];
}HIB_BITBANDING_TAMPER_IO_t;

typedef volatile struct
{
    volatile HIB_BITBANDING_TAMPER_IO_t TAMPER[4UL];
}HIB_BITBANDING_TP_IO_t;


typedef volatile struct
{
    volatile const UBase_t SEC [6UL];
    volatile const UBase_t MIN [6UL];
    volatile const UBase_t HR [5UL];
    volatile const UBase_t DOM [5UL];
    volatile const UBase_t MON [4UL];
    volatile const UBase_t YEAR [6UL];
}HIB_BITBANDING_TPLOGTIME_t;

typedef volatile struct
{
    volatile const UBase_t TRIG0;
    volatile const UBase_t TRIG1;
    volatile const UBase_t TRIG2;
    volatile const UBase_t TRIG3;
    const UBase_t reserved [12UL];
    volatile const UBase_t XOSC;
    const UBase_t reserved1 [15UL];
}HIB_BITBANDING_TPLOGTRIG_t;

typedef volatile struct
{
    HIB_BITBANDING_TPLOGTIME_t TPLOGTIME;
    HIB_BITBANDING_TPLOGTRIG_t TPLOGTRIG;
}HIB_BITBANDING_TPLOG_t;


typedef volatile struct
{
    volatile const UBase_t WAKENC;
    volatile const UBase_t TAMPER;
    const UBase_t reserved [30UL];
}HIB_BITBANDING_PP_t;

typedef volatile struct
{
    volatile UBase_t SYSCLKEN;
    const UBase_t reserved [31UL];
}HIB_BITBANDING_CC_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTREGISTER_BITBANDING_H_ */

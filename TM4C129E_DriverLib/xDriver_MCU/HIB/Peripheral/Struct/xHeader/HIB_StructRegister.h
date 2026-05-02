/**
 *
 * @file HIB_StructRegister.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTREGISTER_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTREGISTER_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

typedef volatile struct
{
    volatile const UBase_t RTCC :32;
}HIB_RTCC_t;

typedef volatile struct
{
    volatile UBase_t RTCM0 :32;
}HIB_RTCM0_t;

typedef volatile struct
{
    volatile UBase_t RTCLD :32;
}HIB_RTCLD_t;

typedef volatile struct
{
    volatile UBase_t RTCEN :1;
    volatile UBase_t HIBREQ :1;
    const UBase_t reserved :1;
    volatile UBase_t RTCWEN :1;
    volatile UBase_t PINWEN :1;
    const UBase_t reserved1 :1;
    volatile UBase_t CLK32EN :1;
    volatile UBase_t VABORT :1;
    volatile UBase_t VDD3ON :1;
    volatile UBase_t BATWKEN :1;
    volatile UBase_t BATCHK :1;
    const UBase_t reserved2 :2;
    volatile UBase_t VBATSEL :2;
    const UBase_t reserved3 :1;
    volatile UBase_t OSCBYP :1;
    volatile UBase_t OSCDRV :1;
    const UBase_t reserved4 :1;
    volatile UBase_t OSCSEL :1;
    const UBase_t reserved5 :10;
    volatile UBase_t RETCLR :1;
    volatile const UBase_t WRC :1;
}HIB_CTL_t;

typedef volatile struct
{
    volatile UBase_t RTCALT0 :1;
    const UBase_t reserved :1;
    volatile UBase_t LOWBAT :1;
    volatile UBase_t EXTW :1;
    volatile UBase_t WC :1;
    volatile UBase_t PADIOWK :1;
    volatile UBase_t RSTWK :1;
    volatile UBase_t VDDFAIL :1;
    const UBase_t reserved1 :24;
}HIB_IM_t;

typedef volatile struct
{
    volatile const UBase_t RTCALT0 :1;
    const UBase_t reserved :1;
    volatile const UBase_t LOWBAT :1;
    volatile const UBase_t EXTW :1;
    volatile const UBase_t WC :1;
    volatile const UBase_t PADIOWK :1;
    volatile const UBase_t RSTWK :1;
    volatile const UBase_t VDDFAIL :1;
    const UBase_t reserved1 :24;
}HIB_RIS_t;

typedef volatile struct
{
    volatile const UBase_t RTCALT0 :1;
    const UBase_t reserved :1;
    volatile const UBase_t LOWBAT :1;
    volatile const UBase_t EXTW :1;
    volatile const UBase_t WC :1;
    volatile const UBase_t PADIOWK :1;
    volatile const UBase_t RSTWK :1;
    volatile const UBase_t VDDFAIL :1;
    const UBase_t reserved1 :24;
}HIB_MIS_t;

typedef volatile struct
{
    volatile UBase_t RTCALT0 :1;
    const UBase_t reserved :1;
    volatile UBase_t LOWBAT :1;
    volatile UBase_t EXTW :1;
    volatile UBase_t WC :1;
    volatile UBase_t PADIOWK :1;
    volatile UBase_t RSTWK :1;
    volatile UBase_t VDDFAIL :1;
    const UBase_t reserved1 :24;
}HIB_IC_t;

typedef volatile struct
{
    volatile UBase_t TRIM :16;
    const UBase_t reserved :16;
}HIB_RTCT_t;

typedef volatile struct
{
    volatile const UBase_t RTCSSC :15;
    const UBase_t reserved :1;
    volatile UBase_t RTCSSM :15;
    const UBase_t reserved1 :1;
}HIB_RTCSS_t;

typedef volatile struct
{
    volatile UBase_t WUUNLK :1;
    const UBase_t reserved :3;
    volatile UBase_t WURSTEN :1;
    const UBase_t reserved1 :26;
    volatile const UBase_t IOWRC :1;
}HIB_IO_t;

typedef volatile struct
{
    volatile UBase_t RTD :32;
}HIB_DATA_t;

typedef volatile struct
{
    volatile UBase_t CALEN :1;
    const UBase_t reserved :1;
    volatile UBase_t CAL24 :1;
    const UBase_t reserved1 :29;
}HIB_CALCTL_t;

typedef volatile struct
{
    volatile const UBase_t SEC :6;
    const UBase_t reserved :2;
    volatile const UBase_t MIN :6;
    const UBase_t reserved1 :2;
    volatile const UBase_t HR :5;
    const UBase_t reserved2 :1;
    volatile const UBase_t AMPM :1;
    const UBase_t reserved3 :8;
    volatile const UBase_t VALID :1;
}HIB_CAL0_t;

typedef volatile struct
{
    volatile const UBase_t DOM :5;
    const UBase_t reserved :3;
    volatile const UBase_t MON :4;
    const UBase_t reserved1 :4;
    volatile const UBase_t YEAR :7;
    const UBase_t reserved2 :1;
    volatile const UBase_t DOW :3;
    const UBase_t reserved3 :4;
    volatile const UBase_t VALID :1;
}HIB_CAL1_t;

typedef volatile struct
{
    volatile UBase_t SEC :6;
    const UBase_t reserved :2;
    volatile UBase_t MIN :6;
    const UBase_t reserved1 :2;
    volatile UBase_t HR :5;
    const UBase_t reserved2 :1;
    volatile UBase_t AMPM :1;
    const UBase_t reserved3 :9;
}HIB_CALLD0_t;

typedef volatile struct
{
    volatile UBase_t DOM :5;
    const UBase_t reserved :3;
    volatile UBase_t MON :4;
    const UBase_t reserved1 :4;
    volatile UBase_t YEAR :7;
    const UBase_t reserved2 :1;
    volatile UBase_t DOW :3;
    const UBase_t reserved3 :5;
}HIB_CALLD1_t;

typedef volatile struct
{
    volatile UBase_t SEC :6;
    const UBase_t reserved :2;
    volatile UBase_t MIN :6;
    const UBase_t reserved1 :2;
    volatile UBase_t HR :5;
    const UBase_t reserved2 :1;
    volatile UBase_t AMPM :1;
    const UBase_t reserved3 :9;
}HIB_CALM0_t;

typedef volatile struct
{
    volatile UBase_t DOM :5;
    const UBase_t reserved :27;
}HIB_CALM1_t;

typedef volatile struct
{
    volatile UBase_t HIBLOCK :32;
}HIB_LOCK_t;

typedef volatile struct
{
    volatile UBase_t TPEN :1;
    const UBase_t reserved :3;
    volatile UBase_t TPCLR :1;
    const UBase_t reserved1 :3;
    volatile UBase_t MEMCLR :2;
    const UBase_t reserved2 :1;
    volatile UBase_t WAKE :1;
    const UBase_t reserved3 :20;
}HIB_TPCTL_t;

typedef volatile struct
{
    volatile UBase_t XOSCFAIL :1;
    volatile const UBase_t XOSCST :1;
    volatile const UBase_t STATE :2;
    const UBase_t reserved :28;
}HIB_TPSTAT_t;

typedef volatile struct
{
    volatile UBase_t EN0 :1;
    volatile UBase_t LEV0 :1;
    volatile UBase_t PUEN0 :1;
    volatile UBase_t GFLTR0 :1;
    const UBase_t reserved :4;
    volatile UBase_t EN1 :1;
    volatile UBase_t LEV1 :1;
    volatile UBase_t PUEN1 :1;
    volatile UBase_t GFLTR1 :1;
    const UBase_t reserved1 :4;
    volatile UBase_t EN2 :1;
    volatile UBase_t LEV2 :1;
    volatile UBase_t PUEN2 :1;
    volatile UBase_t GFLTR2 :1;
    const UBase_t reserved2 :4;
    volatile UBase_t EN3 :1;
    volatile UBase_t LEV3 :1;
    volatile UBase_t PUEN3 :1;
    volatile UBase_t GFLTR3 :1;
    const UBase_t reserved3 :4;
}HIB_TPIO_t;

typedef volatile struct
{
    volatile const UBase_t SEC :6;
    volatile const UBase_t MIN :6;
    volatile const UBase_t HR :5;
    volatile const UBase_t DOM :5;
    volatile const UBase_t MON :4;
    volatile const UBase_t YEAR :6;
}HIB_TPLOGTIME_t;

typedef volatile struct
{
    volatile const UBase_t TRIG0 :1;
    volatile const UBase_t TRIG1 :1;
    volatile const UBase_t TRIG2 :1;
    volatile const UBase_t TRIG3 :1;
    const UBase_t reserved :12;
    volatile const UBase_t XOSC :1;
    const UBase_t reserved1 :15;
}HIB_TPLOGTRIG_t;


typedef volatile struct
{
    union
    {
        volatile const UBase_t TIME;
        HIB_TPLOGTIME_t TIME_Bit;
    };
    union
    {
        volatile const UBase_t TRIG;
        HIB_TPLOGTRIG_t TRIG_Bit;
    };
}HIB_TPLOG_t;

typedef volatile struct
{
    volatile const UBase_t WAKENC :1;
    volatile const UBase_t TAMPER :1;
    const UBase_t reserved :30;
}HIB_PP_t;

typedef volatile struct
{
    volatile UBase_t SYSCLKEN :1;
    const UBase_t reserved :31;
}HIB_CC_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTREGISTER_H_ */

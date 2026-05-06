/**
 *
 * @file HIB_StructPeripheral_Bitbanding.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTPERIPHERAL_BITBANDING_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTPERIPHERAL_BITBANDING_H_

#include <xDriver_MCU/HIB/Peripheral/Struct/xHeader/HIB_StructRegister_Bitbanding.h>

typedef volatile struct
{
    union
    {
        volatile const UBase_t RTCC[32UL];
        HIB_BITBANDING_RTCC_t RTCC_Bit;
    };
    union
    {
        volatile UBase_t RTCM0[32UL];
        HIB_BITBANDING_RTCM0_t RTCM0_Bit;
    };
    const UBase_t reserved0[1UL * 32UL];
    union
    {
        volatile UBase_t RTCLD[32UL];
        HIB_BITBANDING_RTCLD_t RTCLD_Bit;
    };
    union
    {
        volatile UBase_t CTL[32UL];
        HIB_BITBANDING_CTL_t CTL_Bit;
    };
    union
    {
        volatile UBase_t IM[32UL];
        HIB_BITBANDING_IM_t IM_Bit;
    };
    union
    {
        volatile const UBase_t RIS[32UL];
        HIB_BITBANDING_RIS_t RIS_Bit;
    };
    union
    {
        volatile const UBase_t MIS[32UL];
        HIB_BITBANDING_MIS_t MIS_Bit;
    };
    union
    {
        volatile UBase_t IC[32UL];
        HIB_BITBANDING_IC_t IC_Bit;
    };
    union
    {
        volatile UBase_t RTCT[32UL];
        HIB_BITBANDING_RTCT_t RTCT_Bit;
    };
    union
    {
        volatile UBase_t RTCSS[32UL];
        HIB_BITBANDING_RTCSS_t RTCSS_Bit;
    };
    union
    {
        volatile UBase_t IO[32UL];
        HIB_BITBANDING_IO_t IO_Bit;
    };
    union
    {
        volatile UBase_t DATA[16UL][32UL];
        HIB_BITBANDING_DATA_t DATA_Bit[16UL];
    };
    const UBase_t reserved1[164UL * 32UL];
    union
    {
        volatile UBase_t CALCTL[32UL];
        HIB_BITBANDING_CALCTL_t CALCTL_Bit;
    };
    const UBase_t reserved2[3UL * 32UL];
    union
    {
        volatile const UBase_t CAL0[32UL];
        HIB_BITBANDING_CAL0_t CAL0_Bit;
    };
    union
    {
        volatile const UBase_t CAL1[32UL];
        HIB_BITBANDING_CAL1_t CAL1_Bit;
    };
    const UBase_t reserved3[2UL * 32UL];
    union
    {
        volatile UBase_t CALLD0[32UL];
        HIB_BITBANDING_CALLD0_t CALLD0_Bit;
    };
    union
    {
        volatile UBase_t CALLD1[32UL];
        HIB_BITBANDING_CALLD1_t CALLD1_Bit;
    };
    const UBase_t reserved4[2UL * 32UL];
    union
    {
        volatile UBase_t CALM0[32UL];
        HIB_BITBANDING_CALM0_t CALM0_Bit;
    };
    union
    {
        volatile UBase_t CALM1[32UL];
        HIB_BITBANDING_CALM1_t CALM1_Bit;
    };
    const UBase_t reserved5[10UL * 32UL];
    union
    {
        volatile UBase_t LOCK[32UL];
        HIB_BITBANDING_LOCK_t LOCK_Bit;
    };
    const UBase_t reserved6[39UL * 32UL];
    union
    {
        volatile UBase_t TPCTL[32UL];
        HIB_BITBANDING_TPCTL_t TPCTL_Bit;
    };
    union
    {
        volatile UBase_t TPSTAT[32UL];
        HIB_BITBANDING_TPSTAT_t TPSTAT_Bit;
    };
    const UBase_t reserved7[2UL * 32UL];
    union
    {
        volatile UBase_t TPIO[32UL];
        HIB_BITBANDING_TP_IO_t TP_IO_Bit;
        HIB_BITBANDING_TPIO_t TPIO_Bit;
    };
    const UBase_t reserved8[51UL * 32UL];
    HIB_BITBANDING_TPLOG_t TPLOG[4];
    const UBase_t reserved9[688UL * 32UL];
    union
    {
        volatile const UBase_t PP[32UL];
        HIB_BITBANDING_PP_t PP_Bit;
    };
    const UBase_t reserved10[1UL * 32UL];
    union
    {
        volatile UBase_t CC[32UL];
        HIB_BITBANDING_CC_t CC_Bit;
    };
}HIB_BITBANDING_t;

typedef volatile struct
{
    HIB_BITBANDING_t MODULE[(UBase_t) HIB_enMODULE_MAX];
}HIBS_BITBANDING_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTPERIPHERAL_BITBANDING_H_ */

/**
 *
 * @file HIB_StructPeripheral.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTPERIPHERAL_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTPERIPHERAL_H_

#include <xDriver_MCU/HIB/Peripheral/Struct/xHeader/HIB_StructRegister.h>

typedef volatile struct
{
    union
    {
        volatile const UBase_t RTCC;
        HIB_RTCC_t RTCC_Bit;
    };
    union
    {
        volatile UBase_t RTCM0;
        HIB_RTCM0_t RTCM0_Bit;
    };
    const UBase_t reserved0;
    union
    {
        volatile UBase_t RTCLD;
        HIB_RTCLD_t RTCLD_Bit;
    };
    union
    {
        volatile UBase_t CTL;
        HIB_CTL_t CTL_Bit;
    };
    union
    {
        volatile UBase_t IM;
        HIB_IM_t IM_Bit;
    };
    union
    {
        volatile const UBase_t RIS;
        HIB_RIS_t RIS_Bit;
    };
    union
    {
        volatile const UBase_t MIS;
        HIB_MIS_t MIS_Bit;
    };
    union
    {
        volatile UBase_t IC;
        HIB_IC_t IC_Bit;
    };
    union
    {
        volatile UBase_t RTCT;
        HIB_RTCT_t RTCT_Bit;
    };
    union
    {
        volatile UBase_t RTCSS;
        HIB_RTCSS_t RTCSS_Bit;
    };
    union
    {
        volatile UBase_t IO;
        HIB_IO_t IO_Bit;
    };
    union
    {
        volatile UBase_t DATA[16UL];
        HIB_DATA_t DATA_Bit[16UL];
    };
    const UBase_t reserved1[164UL];
    union
    {
        volatile UBase_t CALCTL;
        HIB_CALCTL_t CALCTL_Bit;
    };
    const UBase_t reserved2[3UL];
    union
    {
        volatile const UBase_t CAL0;
        HIB_CAL0_t CAL0_Bit;
    };
    union
    {
        volatile const UBase_t CAL1;
        HIB_CAL1_t CAL1_Bit;
    };
    const UBase_t reserved3[2UL];
    union
    {
        volatile UBase_t CALLD0;
        HIB_CALLD0_t CALLD0_Bit;
    };
    union
    {
        volatile UBase_t CALLD1;
        HIB_CALLD1_t CALLD1_Bit;
    };
    const UBase_t reserved4[2UL];
    union
    {
        volatile UBase_t CALM0;
        HIB_CALM0_t CALM0_Bit;
    };
    union
    {
        volatile UBase_t CALM1;
        HIB_CALM1_t CALM1_Bit;
    };
    const UBase_t reserved5[10UL];
    union
    {
        volatile UBase_t LOCK;
        HIB_LOCK_t LOCK_Bit;
    };
    const UBase_t reserved6[39UL];
    union
    {
        volatile UBase_t TPCTL;
        HIB_TPCTL_t TPCTL_Bit;
    };
    union
    {
        volatile UBase_t TPSTAT;
        HIB_TPSTAT_t TPSTAT_Bit;
    };
    const UBase_t reserved7[2UL];
    union
    {
        volatile UBase_t TPIO;
        HIB_TPIO_t TPIO_Bit;
    };
    const UBase_t reserved8[51UL];
    HIB_TPLOG_t TPLOG[4];
    const UBase_t reserved9[688UL];
    union
    {
        volatile const UBase_t PP;
        HIB_PP_t PP_Bit;
    };
    const UBase_t reserved10;
    union
    {
        volatile UBase_t CC;
        HIB_CC_t CC_Bit;
    };
}HIB_t;

typedef volatile struct
{
    HIB_t MODULE[(UBase_t) HIB_enMODULE_MAX];
}HIBS_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_PERIPHERAL_STRUCT_XHEADER_HIB_STRUCTPERIPHERAL_H_ */

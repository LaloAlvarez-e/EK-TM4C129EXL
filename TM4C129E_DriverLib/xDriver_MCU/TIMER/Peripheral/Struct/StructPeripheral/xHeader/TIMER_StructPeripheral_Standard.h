/**
 *
 * @file TIMER_StructPeripheral_Standard.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_STRUCT_TIMER_STRUCTPERIPHERAL_TIMER_STRUCTPERIPHERAL_STANDARD_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_STRUCT_TIMER_STRUCTPERIPHERAL_TIMER_STRUCTPERIPHERAL_STANDARD_H_

#include <xDriver_MCU/TIMER/Peripheral/Struct/StructRegister/xHeader/TIMER_StructRegister_Control.h>
#include <xDriver_MCU/TIMER/Peripheral/Struct/StructRegister/xHeader/TIMER_StructRegister_Standard.h>

typedef volatile struct
{
    union
    {
        volatile uint32_t CFG;
        GPTMCFG_t CFG_Bit;
    };
    union
    {
        volatile uint32_t TAMR;
        GPTMTAMR_t TAMR_Bit;
    };
    union
    {
        volatile uint32_t TBMR;
        GPTMTBMR_t TBMR_Bit;
    };
    union
    {
        volatile uint32_t CTL;
        GPTMCTL_t CTL_Bit;
    };
    union
    {
        volatile uint32_t SYNC;
        GPTMSYNC_t SYNC_Bit;
    };
    const uint32_t reserved;

    union
    {
        volatile uint32_t IMR;
        GPTMIMR_t IMR_Bit;
    };
    union
    {
        volatile const uint32_t RIS;
        GPTMRIS_t RIS_Bit;
    };
    union
    {
        volatile const uint32_t MIS;
        GPTMMIS_t MIS_Bit;
    };
    union
    {
        volatile uint32_t ICR;
        GPTMICR_t ICR_Bit;
    };
    union
    {
        volatile uint32_t TAILR;
        GPTMTAILR_t TAILR_Bit;
    };
    union
    {
        volatile uint32_t TBILR;
        GPTMTBILR_t TBILR_Bit;
    };
    union
    {
        volatile uint32_t TAMATCHR;
        GPTMTAMATCHR_t TAMATCHR_Bit;
    };

    union
    {
        volatile uint32_t TBMATCHR;
        GPTMTBMATCHR_t TBMATCHR_Bit;
    };
    union
    {
        volatile uint32_t TAPR;
        GPTMTAPR_t TAPR_Bit;
    };

    union
    {
        volatile uint32_t TBPR;
        GPTMTBPR_t TBPR_Bit;
    };
    union
    {
        volatile uint32_t TAPMR;
        GPTMTAPMR_t TAPMR_Bit;
    };
    union
    {
        volatile uint32_t TBPMR;
        GPTMTBPMR_t TBPMR_Bit;
    };
    union
    {
        volatile const uint32_t TAR;
        GPTMTAR_t TAR_Bit;
    };
    union
    {
        volatile const uint32_t TBR;
        GPTMTBR_t TBR_Bit;
    };
    union
    {
        volatile uint32_t TAV;
        GPTMTAV_t TAV_Bit;
    };
    union
    {
        volatile uint32_t TBV;
        GPTMTBV_t TBV_Bit;
    };
    union
    {
        volatile const uint32_t RTCPD;
        GPTMRTCPD_t RTCPD_Bit;
    };
    union
    {
        volatile const uint32_t TAPS;
        GPTMTAPS_t TAPS_Bit;
    };
    union
    {
        volatile const uint32_t TBPS;
        GPTMTBPS_t TBPS_Bit;
    };
    const uint32_t reserved1 [2UL];
    union
    {
        volatile const uint32_t DMAEV;
        GPTMDMAEV_t DMAEV_Bit;
    };
    union
    {
        volatile const uint32_t ADCEV;
        GPTMADCEV_t ADCEV_Bit;
    };

    const uint32_t reserved2 [979UL];

    union
    {
        volatile const uint32_t PP;
        GPTMPP_t PP_Bit;
    };
    const uint32_t reserved3;
    union
    {
        volatile const uint32_t CC;
        GPTMCC_t CC_Bit;
    };

    const uint32_t reserved4 [13UL];
}GPTM_t;



#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_STRUCT_TIMER_STRUCTPERIPHERAL_TIMER_STRUCTPERIPHERAL_STANDARD_H_ */

/**
 *
 * @file TIMER_StructPeripheral_ModuleB_16.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_STRUCT_TIMER_STRUCTPERIPHERAL_TIMER_STRUCTPERIPHERAL_MODULEB_16_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_STRUCT_TIMER_STRUCTPERIPHERAL_TIMER_STRUCTPERIPHERAL_MODULEB_16_H_

#include <xDriver_MCU/TIMER/Peripheral/Struct/StructRegister/xHeader/TIMER_StructRegister_ModuleB_16.h>

typedef volatile struct
{
    const uint32_t reserved [2UL];
    union
    {
        volatile uint32_t TnMR;
        TB_GPTMMR_t TnMR_Bit;
    };
    union
    {
        volatile uint32_t TnCTL;
        TB_GPTMCTL_t TnCTL_Bit;
    };
    const uint32_t reserved3 [2UL];
    union
    {
        volatile uint32_t TnIMR;
        TB_GPTMIMR_t TnIMR_Bit;
    };
    union
    {
        volatile uint32_t TnRIS;
        TB_GPTMRIS_t TnRIS_Bit;
    };
    union
    {
        volatile uint32_t TnMIS;
        TB_GPTMMIS_t TnMIS_Bit;
    };
    union
    {
        volatile uint32_t TnICR;
        TB_GPTMICR_t TnICR_Bit;
    };
    const uint32_t reserved9;
    union
    {
        volatile uint32_t TnILR;
        TB_GPTMILR_t TnILR_Bit;
    };
    const uint32_t reserved11;
    union
    {
        volatile uint32_t TnMATCHR;
        TB_GPTMMATCHR_t TnMATCHR_Bit;
    };
    const uint32_t reserved13;
    union
    {
        volatile uint32_t TnPR;
        TB_GPTMPR_t TnPR_Bit;
    };
    const uint32_t reserved15;
    union
    {
        volatile uint32_t TnPMR;
        TB_GPTMPMR_t TnPMR_Bit;
    };
    const uint32_t reserved17;
    union
    {
        volatile const uint32_t TnR;
        TB_GPTMR_t TnR_Bit;
    };
    const uint32_t reserved18;
    union
    {
        volatile uint32_t TnV;
        TB_GPTMV_t TnV_Bit;
    };
    const uint32_t reserved19 [2UL];
    union
    {
        volatile const uint32_t TnPS;
        TB_GPTMPS_t TnPS_Bit;
    };
    const uint32_t reserved20 [2UL];
    union
    {
        volatile const uint32_t DMAEV;
        TB_GPTMDMAEV_t DMAEV_Bit;
    };
    union
    {
        volatile const uint32_t ADCEV;
        TB_GPTMADCEV_t ADCEV_Bit;
    };
    const uint32_t reserved21 [995UL];
}GPTM_TB_t;

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_PERIPHERAL_TIMER_STRUCT_TIMER_STRUCTPERIPHERAL_TIMER_STRUCTPERIPHERAL_MODULEB_16_H_ */

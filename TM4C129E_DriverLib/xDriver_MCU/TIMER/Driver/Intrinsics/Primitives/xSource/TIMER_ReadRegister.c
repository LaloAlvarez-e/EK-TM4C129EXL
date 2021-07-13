/**
 *
 * @file TIMER_ReadRegister.c
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
 * @verbatim 31 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 31 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/xHeader/TIMER_ReadRegister.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/xHeader/TIMER_CheckParams.h>
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/xHeader/TIMER_Ready.h>
#include <xDriver_MCU/TIMER/Peripheral/TIMER_Peripheral.h>

TIMER_nSTATUS TIMER__enReadRegister(TIMER_nMODULE_NUM enModuleNumber, uint32_t u32OffsetRegister, uint32_t* pu32FeatureValue, uint32_t u32MaskFeature, uint32_t u32BitFeature)
{
    TIMER_nSTATUS enStatus = TIMER_enSTATUS_UNDEF;
    TIMER_nREADY enReady = TIMER_enNOREADY;
    uint32_t u32TimerBase = 0UL;
    uint32_t u32ModuleNumber = 0UL;
    TIMER__vCheckParams(0UL, (uint32_t) enModuleNumber, (uint32_t*)0UL, &u32ModuleNumber);
    enReady = TIMER__enIsReady((TIMER_nMODULE_NUM) u32ModuleNumber);
    if((TIMER_enREADY == enReady) && (0UL != (uint32_t) pu32FeatureValue))
    {
        enStatus = TIMER_enSTATUS_OK;
        u32TimerBase = TIMER__u32BlockBaseAddress((TIMER_nMODULE_NUM) u32ModuleNumber);
        *pu32FeatureValue = MCU__u32ReadRegister(u32TimerBase, u32OffsetRegister, u32MaskFeature, u32BitFeature);
    }
    return enStatus;
}
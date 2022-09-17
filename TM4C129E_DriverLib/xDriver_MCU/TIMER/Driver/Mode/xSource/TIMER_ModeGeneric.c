/**
 *
 * @file TIMER_ModeGeneric.c
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
 * @verbatim 15 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/TIMER/Driver/Mode/xHeader/TIMER_ModeGeneric.h>

#include <xDriver_MCU/TIMER/Peripheral/TIMER_Peripheral.h>
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/TIMER_Primitives.h>

void TIMER__vSetModeGeneric(TIMER_nMODULE enModule, uint32_t u32FeatureValue,
                            uint32_t u32MaskFeature, uint32_t u32BitFeature)
{
    TIMER_nENABLE enTimerEnable = TIMER_enENABLE_STOP;
    uint32_t u32SubModule = 0UL;
    uint32_t u32ModuleNumber = 0UL;
    uint32_t u32ShiftReg = 0UL;
    uint32_t u32Register = GPTM_TA_TnMR_OFFSET;
    uint32_t u32RegisterOffset = 0UL;
    TIMER__vGetSubParams(enModule, &u32SubModule, &u32ModuleNumber);
    u32SubModule &= 0x1UL;
    u32ShiftReg = 8UL * u32SubModule;
    enTimerEnable = (TIMER_nENABLE) TIMER__u32ReadRegister((TIMER_nMODULE_NUM) u32ModuleNumber,
                                               GPTM_CTL_OFFSET, GPTM_CTL_TAEN_MASK, u32ShiftReg);
    if(TIMER_enENABLE_START == enTimerEnable)
    {
        TIMER__vWriteRegister((TIMER_nMODULE_NUM) u32ModuleNumber,
                  GPTM_CTL_OFFSET, GPTM_CTL_TAEN_DIS, GPTM_CTL_TAEN_MASK, u32ShiftReg);
    }
    u32RegisterOffset = 4UL;
    u32RegisterOffset *= u32SubModule;
    u32Register += u32RegisterOffset;
    TIMER__vWriteRegister((TIMER_nMODULE_NUM) u32ModuleNumber, u32Register,
                          u32FeatureValue, u32MaskFeature, u32BitFeature);
    if(TIMER_enENABLE_START == enTimerEnable)
    {
        TIMER__vWriteRegister((TIMER_nMODULE_NUM) u32ModuleNumber,
                  GPTM_CTL_OFFSET, GPTM_CTL_TAEN_ENA, GPTM_CTL_TAEN_MASK, u32ShiftReg);
    }
}

uint32_t TIMER__u32GetModeGeneric(TIMER_nMODULE enModule, uint32_t u32MaskFeature,
                                  uint32_t u32BitFeature)
{
    uint32_t u32FeatureValue = 0UL;
    uint32_t u32SubModule = 0UL;
    uint32_t u32ModuleNumber = 0UL;
    uint32_t u32Register = GPTM_TA_TnMR_OFFSET;
    uint32_t u32RegisterOffset = 0UL;
    TIMER__vGetSubParams(enModule, &u32SubModule, &u32ModuleNumber);
    u32SubModule &= 0x1UL;
    u32RegisterOffset = 4UL;
    u32RegisterOffset *= u32SubModule;
    u32Register += u32RegisterOffset;
    u32FeatureValue = TIMER__u32ReadRegister((TIMER_nMODULE_NUM) u32ModuleNumber,
                                     u32Register, u32MaskFeature, u32BitFeature);
    return (u32FeatureValue);
}

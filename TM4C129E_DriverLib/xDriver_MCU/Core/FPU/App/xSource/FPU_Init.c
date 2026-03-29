/**
 *
 * @file FPU_Init.c
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 2 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 2 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/FPU/App/xHeader/FPU_Init.h>

#include <xDriver_MCU/Common/xHeader/MCU_FloatingPoint.h>
#include <xDriver_MCU/Core/FPU/Driver/FPU_Driver.h>

FPU_nERROR FPU__enInit(FPU_nMODULE enModuleArg)
{
    FPU_nERROR enErrorReg;
    enErrorReg = FPU__enSetAccessType(enModuleArg, FPU_enACCESS_FULL);
    if(FPU_enERROR_OK == enErrorReg)
    {
        enErrorReg = FPU__enSetAutoPreservationState(enModuleArg, FPU_enSTATE_ENA);
    }
    if(FPU_enERROR_OK == enErrorReg)
    {
        enErrorReg = FPU__enSetLazyPreservationState(enModuleArg, FPU_enSTATE_ENA);
    }
    if(FPU_enERROR_OK == enErrorReg)
    {
        FPU__vSetMode(enModuleArg, FPU_enMODE_DENORMAL);
        FPU__vSetHalfPrecision(enModuleArg, FPU_enHALF_PRECISION_IEEE);
        FPU__vSetNAN(enModuleArg, FPU_enNAN_PROPAGATE);
        FPU__vSetRoundingMode(enModuleArg, FPU_enROUNDING_NEAREST);
        MCU__vClearFPUStatusControlMask((UBase_t) FPU_enEXCEPTION_INVALID |
                                        (UBase_t) FPU_enEXCEPTION_DIV0 |
                                        (UBase_t) FPU_enEXCEPTION_OVERFLOW |
                                        (UBase_t) FPU_enEXCEPTION_UNDERFLOW |
                                        (UBase_t) FPU_enEXCEPTION_INEXACT |
                                        (UBase_t) FPU_enEXCEPTION_DENORMAL);
    }
    return (enErrorReg);
}

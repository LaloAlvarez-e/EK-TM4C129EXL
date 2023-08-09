/*
 * FPU_LazyPreservation.c
 *
 *  Created on: 17 jun. 2020
 *      Author: vyldram
 */
#include <xDriver_MCU/Core/FPU/Driver/xHeader/FPU_LazyPreservation.h>

#include <xDriver_MCU/Core/FPU/Peripheral/FPU_Peripheral.h>
#include <xDriver_MCU/Core/FPU/Driver/Intrinsics/Primitives/FPU_Primitives.h>

FPU_nERROR FPU__enSetLazyPreservationState(FPU_nMODULE enModuleArg,
                                           FPU_nSTATE enStateArg)
{
    FPU_Register_t stRegister;
    stRegister.uxShift = FPU_CCR_R_LSPEN_BIT;
    stRegister.uxMask = FPU_CCR_LSPEN_MASK;
    stRegister.uptrAddress = FPU_CCR_OFFSET;
    stRegister.uxValue = (UBase_t) enStateArg;

    FPU_nERROR enErrorReg;
    enErrorReg = FPU__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

FPU_nERROR FPU__enGetLazyPreservationState(FPU_nMODULE enModuleArg,
                                           FPU_nSTATE* penStateArg)
{
    FPU_Register_t stRegister;
    FPU_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) FPU_enERROR_POINTER ? : FPU_enERROR_OK;
    if(FPU_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = FPU_CCR_R_LSPEN_BIT;
        stRegister.uxMask = FPU_CCR_LSPEN_MASK;
        stRegister.uptrAddress = FPU_CCR_OFFSET;
        enErrorReg = FPU__enReadRegister(enModuleArg, &stRegister);
    }
    if(FPU_enERROR_OK == enErrorReg)
    {
        *penStateArg = (FPU_nSTATE) stRegister.uxValue;
    }
    return (enErrorReg);
}

FPU_nERROR FPU__enGetLazyPreservationStatus(FPU_nMODULE enModuleArg, FPU_nSTATUS* penStatusArg)
{
    FPU_Register_t stRegister;
    FPU_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) FPU_enERROR_POINTER ? : FPU_enERROR_OK;
    if(FPU_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = FPU_CCR_R_LSPACT_BIT;
        stRegister.uxMask = FPU_CCR_LSPACT_MASK;
        stRegister.uptrAddress = FPU_CCR_OFFSET;
        enErrorReg = FPU__enReadRegister(enModuleArg, &stRegister);
    }
    if(FPU_enERROR_OK == enErrorReg)
    {
        *penStatusArg = (FPU_nSTATUS) stRegister.uxValue;
    }
    return (enErrorReg);
}

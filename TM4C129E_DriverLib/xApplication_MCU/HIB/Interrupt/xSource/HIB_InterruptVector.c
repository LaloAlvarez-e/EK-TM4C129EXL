/**
 *
 * @file HIB_InterruptVector.c
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/HIB/Interrupt/xHeader/HIB_InterruptVector.h>

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Dependencies.h>

static HIB_nERROR HIB__enGetInterruptVector(HIB_nMODULE enModuleArg, NVIC_nVECTOR* penVectorArg);

static HIB_nERROR HIB__enGetInterruptVector(HIB_nMODULE enModuleArg, NVIC_nVECTOR* penVectorArg)
{
    static const NVIC_nVECTOR NVIC_VECTOR_HIB[(UBase_t) HIB_enMODULE_MAX] =
    {
        NVIC_enVECTOR_HIB,
    };
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        *penVectorArg = NVIC_VECTOR_HIB[(UBase_t) enModuleArg];
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetInterruptVectorState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    HIB_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_HIB;
    enErrorReg = HIB__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enSetInterruptVectorStateWithPriority(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg, HIB_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    HIB_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_HIB;
    enErrorReg = HIB__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

HIB_nERROR HIB__enGetInterruptVectorState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    HIB_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_HIB;
    enErrorReg = HIB_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = HIB_enERROR_POINTER;
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enGetInterruptVectorStateWithPriority(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg, HIB_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    HIB_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_HIB;
    enErrorReg = HIB_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = HIB_enERROR_POINTER;
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = HIB__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }
    
    return (enErrorReg);
}

HIB_nERROR HIB__enEnableInterruptVector(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetInterruptVectorState(enModuleArg, HIB_enSTATE_ENA);
    return (enErrorReg);
}

HIB_nERROR HIB__enEnableInterruptVectorWithPriority(HIB_nMODULE enModuleArg, HIB_nPRIORITY enPriorityArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetInterruptVectorStateWithPriority(enModuleArg, HIB_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

HIB_nERROR HIB__enDisableInterruptVector(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetInterruptVectorState(enModuleArg, HIB_enSTATE_DIS);
    return (enErrorReg);
}

HIB_nERROR HIB__enDisableInterruptVectorWithPriority(HIB_nMODULE enModuleArg, HIB_nPRIORITY enPriorityArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetInterruptVectorStateWithPriority(enModuleArg, HIB_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}
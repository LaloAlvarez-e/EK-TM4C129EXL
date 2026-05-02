/**
 *
 * @file SYSEXC_InterruptVector.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SYSEXC/Interrupt/xHeader/SYSEXC_InterruptVector.h>
#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Dependencies.h>

static SYSEXC_nERROR SYSEXC__enGetInterruptVector(SYSEXC_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static SYSEXC_nERROR SYSEXC__enGetInterruptVector(SYSEXC_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_SYSEXC[(UBase_t) SYSEXC_enMODULE_MAX]=
    {
        NVIC_enVECTOR_SYSEXC
    };
    SYSEXC_nERROR enErrorReg;

    enErrorReg = (SYSEXC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSEXC_enMODULE_MAX);
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_SYSEXC[(UBase_t) enModuleArg];

    }
    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enSetInterruptVectorState(SYSEXC_nMODULE enModuleArg, SYSEXC_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    SYSEXC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SYSEXC;
    enErrorReg = SYSEXC__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enSetInterruptVectorStateWithPriority(SYSEXC_nMODULE enModuleArg, SYSEXC_nSTATE enStateArg, SYSEXC_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    SYSEXC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SYSEXC;
    enErrorReg = SYSEXC__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enGetInterruptVectorState(SYSEXC_nMODULE enModuleArg, SYSEXC_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    SYSEXC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SYSEXC;
    enErrorReg = SYSEXC_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = SYSEXC_enERROR_POINTER;
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSEXC__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enGetInterruptVectorStateWithPriority(SYSEXC_nMODULE enModuleArg, SYSEXC_nSTATE* penStateArg, SYSEXC_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    SYSEXC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SYSEXC;
    enErrorReg = SYSEXC_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = SYSEXC_enERROR_POINTER;
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSEXC__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SYSEXC_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enEnableInterruptVector(SYSEXC_nMODULE enModuleArg)
{
    SYSEXC_nERROR enErrorReg;
    enErrorReg = SYSEXC__enSetInterruptVectorState(enModuleArg, SYSEXC_enSTATE_ENA);
    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enEnableInterruptVectorWithPriority(SYSEXC_nMODULE enModuleArg, SYSEXC_nPRIORITY enPriorityArg)
{
    SYSEXC_nERROR enErrorReg;
    enErrorReg = SYSEXC__enSetInterruptVectorStateWithPriority(enModuleArg, SYSEXC_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enDisableInterruptVector(SYSEXC_nMODULE enModuleArg)
{
    SYSEXC_nERROR enErrorReg;
    enErrorReg = SYSEXC__enSetInterruptVectorState(enModuleArg, SYSEXC_enSTATE_DIS);
    return (enErrorReg);
}

SYSEXC_nERROR SYSEXC__enDisableInterruptVectorWithPriority(SYSEXC_nMODULE enModuleArg, SYSEXC_nPRIORITY enPriorityArg)
{
    SYSEXC_nERROR enErrorReg;
    enErrorReg = SYSEXC__enSetInterruptVectorStateWithPriority(enModuleArg, SYSEXC_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

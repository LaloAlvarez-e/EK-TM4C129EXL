/**
 *
 * @file SSI_InterruptVector.c
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
#include <xApplication_MCU/SSI/Interrupt/xHeader/SSI_InterruptVector.h>

#include <xApplication_MCU/SSI/Intrinsics/xHeader/SSI_Dependencies.h>

static SSI_nERROR SSI__enGetInterruptVector(SSI_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static SSI_nERROR SSI__enGetInterruptVector(SSI_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_SSI[(UBase_t) SSI_enMODULE_MAX]=
    {
     NVIC_enVECTOR_SSI0, NVIC_enVECTOR_SSI1, NVIC_enVECTOR_SSI2, NVIC_enVECTOR_SSI3,
    };
    SSI_nERROR enErrorReg;

    enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SSI_enMODULE_MAX);
    if(SSI_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_SSI[(UBase_t) enModuleArg];
    }
    return (enErrorReg);
}

SSI_nERROR SSI__enSetInterruptVectorState(SSI_nMODULE enModuleArg, SSI_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    SSI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SSI0;
    enErrorReg = SSI__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

SSI_nERROR SSI__enSetInterruptVectorStateWithPriority(SSI_nMODULE enModuleArg, SSI_nSTATE enStateArg, SSI_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    SSI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SSI0;
    enErrorReg = SSI__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

SSI_nERROR SSI__enGetInterruptVectorState(SSI_nMODULE enModuleArg, SSI_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    SSI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SSI0;
    enErrorReg = SSI_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = SSI_enERROR_POINTER;
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

SSI_nERROR SSI__enGetInterruptVectorStateWithPriority(SSI_nMODULE enModuleArg, SSI_nSTATE* penStateArg, SSI_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    SSI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_SSI0;
    enErrorReg = SSI_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = SSI_enERROR_POINTER;
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = SSI__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

SSI_nERROR SSI__enEnableInterruptVector(SSI_nMODULE enModuleArg)
{
    SSI_nERROR enErrorReg;
    enErrorReg = SSI__enSetInterruptVectorState(enModuleArg, SSI_enSTATE_ENA);
    return (enErrorReg);
}

SSI_nERROR SSI__enEnableInterruptVectorWithPriority(SSI_nMODULE enModuleArg, SSI_nPRIORITY enPriorityArg)
{
    SSI_nERROR enErrorReg;
    enErrorReg = SSI__enSetInterruptVectorStateWithPriority(enModuleArg, SSI_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

SSI_nERROR SSI__enDisableInterruptVector(SSI_nMODULE enModuleArg)
{
    SSI_nERROR enErrorReg;
    enErrorReg = SSI__enSetInterruptVectorState(enModuleArg, SSI_enSTATE_DIS);
    return (enErrorReg);
}

SSI_nERROR SSI__enDisableInterruptVectorWithPriority(SSI_nMODULE enModuleArg, SSI_nPRIORITY enPriorityArg)
{
    SSI_nERROR enErrorReg;
    enErrorReg = SSI__enSetInterruptVectorStateWithPriority(enModuleArg, SSI_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

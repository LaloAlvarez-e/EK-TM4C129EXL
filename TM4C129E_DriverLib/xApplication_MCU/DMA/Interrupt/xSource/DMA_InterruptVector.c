/**
 *
 * @file DMA_InterruptVector.c
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
 * @verbatim 10 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/DMA/Interrupt/xHeader/DMA_InterruptVector.h>

#include <xApplication_MCU/DMA/Intrinsics/xHeader/DMA_Dependencies.h>

static DMA_nERROR DMA__enGetInterruptVector(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, NVIC_nVECTOR* enVectorArg);

static DMA_nERROR DMA__enGetInterruptVector(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_DMA[(UBase_t) DMA_enMODULE_MAX][(UBase_t) DMA_enVECTOR_MAX] =
    {
     { NVIC_enVECTOR_UDMASOFT, NVIC_enVECTOR_UDMAERROR},
    };
    DMA_nERROR enErrorReg;

    enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) DMA_enMODULE_MAX);
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enInterruptArg, (UBase_t) DMA_enVECTOR_MAX);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_DMA[(UBase_t) enModuleArg][(UBase_t) enInterruptArg];
    }
    return (enErrorReg);
}

DMA_nERROR DMA__enSetInterruptVectorState(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, DMA_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    DMA_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UDMASOFT;
    enErrorReg = DMA__enGetInterruptVector(enModuleArg, enInterruptArg, &enVectorReg);
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

DMA_nERROR DMA__enSetInterruptVectorStateWithPriority(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, DMA_nSTATE enStateArg, DMA_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    DMA_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UDMASOFT;
    enErrorReg = DMA__enGetInterruptVector(enModuleArg, enInterruptArg, &enVectorReg);
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

DMA_nERROR DMA__enGetInterruptVectorState(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, DMA_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    DMA_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UDMASOFT;
    enErrorReg = DMA_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = DMA_enERROR_POINTER;
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = DMA__enGetInterruptVector(enModuleArg, enInterruptArg, &enVectorReg);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

DMA_nERROR DMA__enGetInterruptVectorStateWithPriority(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, DMA_nSTATE* penStateArg, DMA_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    DMA_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_UDMASOFT;
    enErrorReg = DMA_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = DMA_enERROR_POINTER;
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = DMA__enGetInterruptVector(enModuleArg, enInterruptArg, &enVectorReg);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

DMA_nERROR DMA__enEnableInterruptVector(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg)
{
    DMA_nERROR enErrorReg;
    enErrorReg = DMA__enSetInterruptVectorState(enModuleArg, enInterruptArg, DMA_enSTATE_ENA);
    return (enErrorReg);
}

DMA_nERROR DMA__enEnableInterruptVectorWithPriority(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, DMA_nPRIORITY enPriorityArg)
{
    DMA_nERROR enErrorReg;
    enErrorReg = DMA__enSetInterruptVectorStateWithPriority(enModuleArg, enInterruptArg, DMA_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

DMA_nERROR DMA__enDisableInterruptVector(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg)
{
    DMA_nERROR enErrorReg;
    enErrorReg = DMA__enSetInterruptVectorState(enModuleArg, enInterruptArg, DMA_enSTATE_DIS);
    return (enErrorReg);
}

DMA_nERROR DMA__enDisableInterruptVectorWithPriority(DMA_nMODULE enModuleArg, DMA_nVECTOR enInterruptArg, DMA_nPRIORITY enPriorityArg)
{
    DMA_nERROR enErrorReg;
    enErrorReg = DMA__enSetInterruptVectorStateWithPriority(enModuleArg, enInterruptArg, DMA_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}


/**
 *
 * @file WDT_InterruptVector.c
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
 * @verbatim 26 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 26 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/WDT/Interrupt/xHeader/WDT_InterruptVector.h>

#include <xApplication_MCU/WDT/Intrinsics/xHeader/WDT_Dependencies.h>

static WDT_nERROR WDT__enGetInterruptVector(WDT_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static WDT_nERROR WDT__enGetInterruptVector(WDT_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_WDT[(UBase_t) WDT_enMODULE_MAX]=
    {
        NVIC_enVECTOR_WDT01, NVIC_enVECTOR_WDT01,
    };
    WDT_nERROR enErrorReg;

    enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) WDT_enMODULE_MAX);
    if(WDT_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_WDT[(UBase_t) enModuleArg];
    }
    return (enErrorReg);
}

WDT_nERROR WDT__enSetInterruptVectorState(WDT_nMODULE enModuleArg, WDT_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    WDT_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_WDT01;
    enErrorReg = WDT__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

WDT_nERROR WDT__enSetInterruptVectorStateWithPriority(WDT_nMODULE enModuleArg, WDT_nSTATE enStateArg, WDT_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    WDT_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_WDT01;
    enErrorReg = WDT__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

WDT_nERROR WDT__enGetInterruptVectorState(WDT_nMODULE enModuleArg, WDT_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    WDT_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_WDT01;
    enErrorReg = WDT_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = WDT_enERROR_POINTER;
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = WDT__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

WDT_nERROR WDT__enGetInterruptVectorStateWithPriority(WDT_nMODULE enModuleArg, WDT_nSTATE* penStateArg, WDT_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    WDT_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_WDT01;
    enErrorReg = WDT_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = WDT_enERROR_POINTER;
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = WDT__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

WDT_nERROR WDT__enEnableInterruptVector(WDT_nMODULE enModuleArg)
{
    WDT_nERROR enErrorReg;
    enErrorReg = WDT__enSetInterruptVectorState(enModuleArg, WDT_enSTATE_ENA);
    return (enErrorReg);
}

WDT_nERROR WDT__enEnableInterruptVectorWithPriority(WDT_nMODULE enModuleArg, WDT_nPRIORITY enPriorityArg)
{
    WDT_nERROR enErrorReg;
    enErrorReg = WDT__enSetInterruptVectorStateWithPriority(enModuleArg, WDT_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

WDT_nERROR WDT__enDisableInterruptVector(WDT_nMODULE enModuleArg)
{
    WDT_nERROR enErrorReg;
    enErrorReg = WDT__enSetInterruptVectorState(enModuleArg, WDT_enSTATE_DIS);
    return (enErrorReg);
}

WDT_nERROR WDT__enDisableInterruptVectorWithPriority(WDT_nMODULE enModuleArg, WDT_nPRIORITY enPriorityArg)
{
    WDT_nERROR enErrorReg;
    enErrorReg = WDT__enSetInterruptVectorStateWithPriority(enModuleArg, WDT_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

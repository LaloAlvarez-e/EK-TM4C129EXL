/**
 *
 * @file FLASH_InterruptVector.c
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
#include <xApplication_MCU/FLASH/Interrupt/xHeader/FLASH_InterruptVector.h>

#include <xApplication_MCU/FLASH/Intrinsics/xHeader/FLASH_Dependencies.h>


static FLASH_nERROR FLASH__enGetInterruptVector(FLASH_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static FLASH_nERROR FLASH__enGetInterruptVector(FLASH_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_FLASH[(UBase_t) FLASH_enMODULE_MAX] = 
    { 
        NVIC_enVECTOR_FLASH 
    };
    FLASH_nERROR enErrorReg;

    enErrorReg = (FLASH_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) FLASH_enMODULE_MAX);
    if(FLASH_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_FLASH[(UBase_t) enModuleArg];

    }
    return (enErrorReg);
}

FLASH_nERROR FLASH__enSetInterruptVectorState(FLASH_nMODULE enModuleArg, FLASH_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    FLASH_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_FLASH;
    enErrorReg = FLASH__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

FLASH_nERROR FLASH__enSetInterruptVectorStateWithPriority(FLASH_nMODULE enModuleArg, FLASH_nSTATE enStateArg, FLASH_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    FLASH_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_FLASH;
    enErrorReg = FLASH__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

FLASH_nERROR FLASH__enGetInterruptVectorState(FLASH_nMODULE enModuleArg, FLASH_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    FLASH_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_FLASH;
    enErrorReg = FLASH_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = FLASH_enERROR_POINTER;
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

FLASH_nERROR FLASH__enGetInterruptVectorStateWithPriority(FLASH_nMODULE enModuleArg, FLASH_nSTATE* penStateArg, FLASH_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    FLASH_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_FLASH;
    enErrorReg = FLASH_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = FLASH_enERROR_POINTER;
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = FLASH__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

FLASH_nERROR FLASH__enEnableInterruptVector(FLASH_nMODULE enModuleArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptVectorState(enModuleArg, FLASH_enSTATE_ENA);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enEnableInterruptVectorWithPriority(FLASH_nMODULE enModuleArg, FLASH_nPRIORITY enPriorityArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptVectorStateWithPriority(enModuleArg, FLASH_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enDisableInterruptVector(FLASH_nMODULE enModuleArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptVectorState(enModuleArg, FLASH_enSTATE_DIS);
    return (enErrorReg);
}

FLASH_nERROR FLASH__enDisableInterruptVectorWithPriority(FLASH_nMODULE enModuleArg, FLASH_nPRIORITY enPriorityArg)
{
    FLASH_nERROR enErrorReg;
    enErrorReg = FLASH__enSetInterruptVectorStateWithPriority(enModuleArg, FLASH_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

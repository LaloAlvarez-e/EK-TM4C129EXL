/**
 *
 * @file I2C_InterruptVector.c
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/I2C/Interrupt/xHeader/I2C_InterruptVector.h>

#include <xApplication_MCU/I2C/Intrinsics/xHeader/I2C_Dependencies.h>

static I2C_nERROR I2C__enGetInterruptVector(I2C_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static I2C_nERROR I2C__enGetInterruptVector(I2C_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_I2C[(UBase_t) I2C_enMODULE_MAX]=
    {
     NVIC_enVECTOR_I2C0, NVIC_enVECTOR_I2C1, NVIC_enVECTOR_I2C2, NVIC_enVECTOR_I2C3, NVIC_enVECTOR_I2C4,
     NVIC_enVECTOR_I2C5, NVIC_enVECTOR_I2C6, NVIC_enVECTOR_I2C7, NVIC_enVECTOR_I2C8, NVIC_enVECTOR_I2C9
    };
    I2C_nERROR enErrorReg;

    enErrorReg = (I2C_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) I2C_enMODULE_MAX);
    if(I2C_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_I2C[(UBase_t) enModuleArg];

    }
    return (enErrorReg);
}

I2C_nERROR I2C__enSetInterruptVectorState(I2C_nMODULE enModuleArg, I2C_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    I2C_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_I2C0;
    enErrorReg = I2C__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

I2C_nERROR I2C__enSetInterruptVectorStateWithPriority(I2C_nMODULE enModuleArg, I2C_nSTATE enStateArg, I2C_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    I2C_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_I2C0;
    enErrorReg = I2C__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

I2C_nERROR I2C__enGetInterruptVectorState(I2C_nMODULE enModuleArg, I2C_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    I2C_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_I2C0;
    enErrorReg = I2C_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = I2C_enERROR_POINTER;
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = I2C__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

I2C_nERROR I2C__enGetInterruptVectorStateWithPriority(I2C_nMODULE enModuleArg, I2C_nSTATE* penStateArg, I2C_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    I2C_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_I2C0;
    enErrorReg = I2C_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = I2C_enERROR_POINTER;
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = I2C__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

I2C_nERROR I2C__enEnableInterruptVector(I2C_nMODULE enModuleArg)
{
    I2C_nERROR enErrorReg;
    enErrorReg = I2C__enSetInterruptVectorState(enModuleArg, I2C_enSTATE_ENA);
    return (enErrorReg);
}

I2C_nERROR I2C__enEnableInterruptVectorWithPriority(I2C_nMODULE enModuleArg, I2C_nPRIORITY enPriorityArg)
{
    I2C_nERROR enErrorReg;
    enErrorReg = I2C__enSetInterruptVectorStateWithPriority(enModuleArg, I2C_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

I2C_nERROR I2C__enDisableInterruptVector(I2C_nMODULE enModuleArg)
{
    I2C_nERROR enErrorReg;
    enErrorReg = I2C__enSetInterruptVectorState(enModuleArg, I2C_enSTATE_DIS);
    return (enErrorReg);
}

I2C_nERROR I2C__enDisableInterruptVectorWithPriority(I2C_nMODULE enModuleArg, I2C_nPRIORITY enPriorityArg)
{
    I2C_nERROR enErrorReg;
    enErrorReg = I2C__enSetInterruptVectorStateWithPriority(enModuleArg, I2C_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

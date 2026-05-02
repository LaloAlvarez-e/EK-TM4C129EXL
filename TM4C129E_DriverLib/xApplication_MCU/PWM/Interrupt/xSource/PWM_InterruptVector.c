/**
 *
 * @file PWM_InterruptVector.c
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
 * @verbatim 9 ene. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 ene. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/PWM/Interrupt/xHeader/PWM_InterruptVector.h>

#include <xApplication_MCU/PWM/Intrinsics/xHeader/PWM_Dependencies.h>

static PWM_nERROR PWM_Generator__enGetInterruptVector(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, NVIC_nVECTOR* enVectorArg);

static PWM_nERROR PWM_Generator__enGetInterruptVector(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_PWM[(UBase_t) PWM_enMODULE_MAX][(UBase_t) PWM_enGEN_MAX] =
    {
     { NVIC_enVECTOR_PWM0GEN0, NVIC_enVECTOR_PWM0GEN1, NVIC_enVECTOR_PWM0GEN2, NVIC_enVECTOR_PWM0GEN3},
    };
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) PWM_enMODULE_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enGeneratorArg, (UBase_t) PWM_enGEN_MAX);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_PWM[(UBase_t) enModuleArg][(UBase_t) enGeneratorArg];

    }
    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enSetInterruptVectorState(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_Generator__enGetInterruptVector(enModuleArg, enGeneratorArg, &enVectorReg);
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enSetInterruptVectorStateWithPriority(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nSTATE enStateArg, PWM_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_Generator__enGetInterruptVector(enModuleArg, enGeneratorArg, &enVectorReg);
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enGetInterruptVectorState(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = PWM_Generator__enGetInterruptVector(enModuleArg, enGeneratorArg, &enVectorReg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enGetInterruptVectorStateWithPriority(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nSTATE* penStateArg, PWM_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = PWM_Generator__enGetInterruptVector(enModuleArg, enGeneratorArg, &enVectorReg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enEnableInterruptVector(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Generator__enSetInterruptVectorState(enModuleArg, enGeneratorArg, PWM_enSTATE_ENA);
    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enEnableInterruptVectorWithPriority(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nPRIORITY enPriorityArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Generator__enSetInterruptVectorStateWithPriority(enModuleArg, enGeneratorArg, PWM_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enDisableInterruptVector(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Generator__enSetInterruptVectorState(enModuleArg, enGeneratorArg, PWM_enSTATE_DIS);
    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enDisableInterruptVectorWithPriority(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nPRIORITY enPriorityArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Generator__enSetInterruptVectorStateWithPriority(enModuleArg, enGeneratorArg, PWM_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}



static PWM_nERROR PWM_Fault__enGetInterruptVector(PWM_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static PWM_nERROR PWM_Fault__enGetInterruptVector(PWM_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_PWM[(UBase_t) PWM_enMODULE_MAX]=
    {
     NVIC_enVECTOR_PWM0FAULT
    };
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) PWM_enMODULE_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_PWM[(UBase_t) enModuleArg];
    }
    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enSetInterruptVectorState(PWM_nMODULE enModuleArg, PWM_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_Fault__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enSetInterruptVectorStateWithPriority(PWM_nMODULE enModuleArg, PWM_nSTATE enStateArg, PWM_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_Fault__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enGetInterruptVectorState(PWM_nMODULE enModuleArg, PWM_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = PWM_Fault__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enGetInterruptVectorStateWithPriority(PWM_nMODULE enModuleArg, PWM_nSTATE* penStateArg, PWM_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    PWM_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_PWM0GEN0;
    enErrorReg = PWM_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = PWM_Fault__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enEnableInterruptVector(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Fault__enSetInterruptVectorState(enModuleArg, PWM_enSTATE_ENA);
    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enEnableInterruptVectorWithPriority(PWM_nMODULE enModuleArg, PWM_nPRIORITY enPriorityArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Fault__enSetInterruptVectorStateWithPriority(enModuleArg, PWM_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enDisableInterruptVector(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Fault__enSetInterruptVectorState(enModuleArg, PWM_enSTATE_DIS);
    return (enErrorReg);
}

PWM_nERROR PWM_Fault__enDisableInterruptVectorWithPriority(PWM_nMODULE enModuleArg, PWM_nPRIORITY enPriorityArg)
{
    PWM_nERROR enErrorReg;
    enErrorReg = PWM_Fault__enSetInterruptVectorStateWithPriority(enModuleArg, PWM_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}

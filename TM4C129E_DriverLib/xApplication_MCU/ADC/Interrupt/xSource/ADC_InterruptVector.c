/**
 *
 * @file ADC_InterruptVector.c
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
#include <xApplication_MCU/ADC/Interrupt/xHeader/ADC_InterruptVector.h>

#include <xApplication_MCU/ADC/Intrinsics/xHeader/ADC_Dependencies.h>

static ADC_nERROR ADC__enGetInterruptVector(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, NVIC_nVECTOR* enVectorArg);

static ADC_nERROR ADC__enGetInterruptVector(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_ADC[(UBase_t) ADC_enMODULE_MAX][(UBase_t) ADC_enSEQ_MAX] =
    {
     { NVIC_enVECTOR_ADC0SEQ0, NVIC_enVECTOR_ADC0SEQ1, NVIC_enVECTOR_ADC0SEQ2, NVIC_enVECTOR_ADC0SEQ3},
     { NVIC_enVECTOR_ADC1SEQ0, NVIC_enVECTOR_ADC1SEQ1, NVIC_enVECTOR_ADC1SEQ2, NVIC_enVECTOR_ADC1SEQ3}
    };
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_ADC[(UBase_t) enModuleArg][(UBase_t) enSequencerArg];

    }
    return (enErrorReg);
}

ADC_nERROR ADC__enSetInterruptVectorState(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, ADC_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    ADC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_ADC0SEQ0;
    enErrorReg = ADC__enGetInterruptVector(enModuleArg, enSequencerArg, &enVectorReg);
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

ADC_nERROR ADC__enSetInterruptVectorStateWithPriority(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, ADC_nSTATE enStateArg, ADC_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    ADC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_ADC0SEQ0;
    enErrorReg = ADC__enGetInterruptVector(enModuleArg, enSequencerArg, &enVectorReg);
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

ADC_nERROR ADC__enGetInterruptVectorState(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, ADC_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    ADC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_ADC0SEQ0;
    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = ADC__enGetInterruptVector(enModuleArg, enSequencerArg, &enVectorReg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

ADC_nERROR ADC__enGetInterruptVectorStateWithPriority(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, ADC_nSTATE* penStateArg, ADC_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    ADC_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_ADC0SEQ0;
    enErrorReg = ADC_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = ADC__enGetInterruptVector(enModuleArg, enSequencerArg, &enVectorReg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

ADC_nERROR ADC__enEnableInterruptVector(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC__enSetInterruptVectorState(enModuleArg, enSequencerArg, ADC_enSTATE_ENA);
    return (enErrorReg);
}

ADC_nERROR ADC__enEnableInterruptVectorWithPriority(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, ADC_nPRIORITY enPriorityArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC__enSetInterruptVectorStateWithPriority(enModuleArg, enSequencerArg, ADC_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

ADC_nERROR ADC__enDisableInterruptVector(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC__enSetInterruptVectorState(enModuleArg, enSequencerArg, ADC_enSTATE_DIS);
    return (enErrorReg);
}

ADC_nERROR ADC__enDisableInterruptVectorWithPriority(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg, ADC_nPRIORITY enPriorityArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = ADC__enSetInterruptVectorStateWithPriority(enModuleArg, enSequencerArg, ADC_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}


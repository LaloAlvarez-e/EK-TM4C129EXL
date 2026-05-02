/**
 *
 * @file ADC_Ready.c
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
#include <xApplication_MCU/ADC/Intrinsics/xHeader/ADC_Ready.h>

#include <xApplication_MCU/ADC/Intrinsics/xHeader/ADC_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_ADC[(UBase_t) ADC_enMODULE_MAX] =
{
 SYSCTL_enADC0, SYSCTL_enADC1
};

ADC_nERROR ADC__enSetReadyOnRunMode(ADC_nMODULE enModuleArg)
{
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ADC[(UBase_t) enModuleArg];
        enErrorReg = (ADC_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

ADC_nERROR ADC__enClearReadyOnRunMode(ADC_nMODULE enModuleArg)
{
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ADC[(UBase_t) enModuleArg];
        enErrorReg = (ADC_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

ADC_nERROR ADC__enReset(ADC_nMODULE enModuleArg)
{
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ADC[(UBase_t) enModuleArg];
        enErrorReg = (ADC_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

ADC_nERROR ADC__enIsReady(ADC_nMODULE enModuleArg, ADC_nBOOLEAN* penReadyArg)
{
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ADC[(UBase_t) enModuleArg];
        enErrorReg = (ADC_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}


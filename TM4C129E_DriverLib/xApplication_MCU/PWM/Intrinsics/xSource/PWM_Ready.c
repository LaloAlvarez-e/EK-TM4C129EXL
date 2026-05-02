/**
 *
 * @file PWM_Ready.c
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
#include <xApplication_MCU/PWM/Intrinsics/xHeader/PWM_Ready.h>

#include <xApplication_MCU/PWM/Intrinsics/xHeader/PWM_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_PWM[(UBase_t) PWM_enMODULE_MAX] =
{
 SYSCTL_enPWM0
};

PWM_nERROR PWM__enSetReadyOnRunMode(PWM_nMODULE enModuleArg)
{
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) PWM_enMODULE_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_PWM[(UBase_t) enModuleArg];
        enErrorReg = (PWM_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

PWM_nERROR PWM__enClearReadyOnRunMode(PWM_nMODULE enModuleArg)
{
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) PWM_enMODULE_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_PWM[(UBase_t) enModuleArg];
        enErrorReg = (PWM_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

PWM_nERROR PWM__enReset(PWM_nMODULE enModuleArg)
{
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) PWM_enMODULE_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_PWM[(UBase_t) enModuleArg];
        enErrorReg = (PWM_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

PWM_nERROR PWM__enIsReady(PWM_nMODULE enModuleArg, PWM_nBOOLEAN* penReadyArg)
{
    PWM_nERROR enErrorReg;

    enErrorReg = PWM_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) PWM_enMODULE_MAX);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_PWM[(UBase_t) enModuleArg];
        enErrorReg = (PWM_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

/**
 *
 * @file GPIO_Ready.c
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
#include <xApplication_MCU/GPIO/Intrinsics/xHeader/GPIO_Ready.h>

#include <xApplication_MCU/GPIO/Intrinsics/xHeader/GPIO_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_GPIO[(UBase_t) GPIO_enPORT_MAX] =
{
 SYSCTL_enGPIOA, SYSCTL_enGPIOB, SYSCTL_enGPIOC, SYSCTL_enGPIOD,
 SYSCTL_enGPIOE, SYSCTL_enGPIOF, SYSCTL_enGPIOG, SYSCTL_enGPIOH,
 SYSCTL_enGPIOJ, SYSCTL_enGPIOK, SYSCTL_enGPIOL, SYSCTL_enGPIOM,
 SYSCTL_enGPION, SYSCTL_enGPIOP, SYSCTL_enGPIOQ
};

GPIO_nERROR GPIO__enSetReadyOnRunMode(GPIO_nPORT enPortArg)
{
    GPIO_nERROR enErrorReg;

    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPortArg, (UBase_t) GPIO_enPORT_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_GPIO[(UBase_t) enPortArg];
        enErrorReg = (GPIO_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enClearReadyOnRunMode(GPIO_nPORT enPortArg)
{
    GPIO_nERROR enErrorReg;

    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPortArg, (UBase_t) GPIO_enPORT_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_GPIO[(UBase_t) enPortArg];
        enErrorReg = (GPIO_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enReset(GPIO_nPORT enPortArg)
{
    GPIO_nERROR enErrorReg;

    enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPortArg, (UBase_t) GPIO_enPORT_MAX);
    if(GPIO_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_GPIO[(UBase_t) enPortArg];
        enErrorReg = (GPIO_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

GPIO_nERROR GPIO__enIsReady(GPIO_nPORT enPortArg, GPIO_nBOOLEAN* penReadyArg)
{
    GPIO_nERROR enErrorReg;

    enErrorReg = GPIO_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = GPIO_enERROR_POINTER;
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        enErrorReg = (GPIO_nERROR) MCU__enCheckParams((UBase_t) enPortArg, (UBase_t) GPIO_enPORT_MAX);
    }
    if(GPIO_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_GPIO[(UBase_t) enPortArg];
        enErrorReg = (GPIO_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}


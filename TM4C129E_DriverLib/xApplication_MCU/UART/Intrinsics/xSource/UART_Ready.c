/**
 *
 * @file UART_Ready.c
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
#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Ready.h>

#include <xApplication_MCU/UART/Intrinsics/xHeader/UART_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_UART[(UBase_t) UART_enMODULE_MAX] =
{
 SYSCTL_enUART0, SYSCTL_enUART1, SYSCTL_enUART2, SYSCTL_enUART3,
 SYSCTL_enUART4, SYSCTL_enUART5, SYSCTL_enUART6, SYSCTL_enUART7
};

UART_nERROR UART__enSetReadyOnRunMode(UART_nMODULE enModuleArg)
{
    UART_nERROR enErrorReg;

    enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    if(UART_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_UART[(UBase_t) enModuleArg];
        enErrorReg = (UART_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

UART_nERROR UART__enClearReadyOnRunMode(UART_nMODULE enModuleArg)
{
    UART_nERROR enErrorReg;

    enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    if(UART_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_UART[(UBase_t) enModuleArg];
        enErrorReg = (UART_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

UART_nERROR UART__enReset(UART_nMODULE enModuleArg)
{
    UART_nERROR enErrorReg;

    enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    if(UART_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_UART[(UBase_t) enModuleArg];
        enErrorReg = (UART_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

UART_nERROR UART__enIsReady(UART_nMODULE enModuleArg, UART_nBOOLEAN* penReadyArg)
{
    UART_nERROR enErrorReg;

    enErrorReg = UART_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = UART_enERROR_POINTER;
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        enErrorReg = (UART_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) UART_enMODULE_MAX);
    }
    if(UART_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_UART[(UBase_t) enModuleArg];
        enErrorReg = (UART_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

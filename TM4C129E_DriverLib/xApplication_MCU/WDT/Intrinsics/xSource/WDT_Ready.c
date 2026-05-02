/**
 *
 * @file WDT_Ready.c
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
#include <xApplication_MCU/WDT/Intrinsics/xHeader/WDT_Ready.h>

#include <xApplication_MCU/WDT/Intrinsics/xHeader/WDT_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_WDT[(UBase_t) WDT_enMODULE_MAX] =
{
 SYSCTL_enWDT0, SYSCTL_enWDT1
};

WDT_nERROR WDT__enSetReadyOnRunMode(WDT_nMODULE enModuleArg)
{
    WDT_nERROR enErrorReg;

    enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) WDT_enMODULE_MAX);
    if(WDT_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_WDT[(UBase_t) enModuleArg];
        enErrorReg = (WDT_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

WDT_nERROR WDT__enClearReadyOnRunMode(WDT_nMODULE enModuleArg)
{
    WDT_nERROR enErrorReg;

    enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) WDT_enMODULE_MAX);
    if(WDT_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_WDT[(UBase_t) enModuleArg];
        enErrorReg = (WDT_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

WDT_nERROR WDT__enReset(WDT_nMODULE enModuleArg)
{
    WDT_nERROR enErrorReg;

    enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) WDT_enMODULE_MAX);
    if(WDT_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_WDT[(UBase_t) enModuleArg];
        enErrorReg = (WDT_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

WDT_nERROR WDT__enIsReady(WDT_nMODULE enModuleArg, WDT_nBOOLEAN* penReadyArg)
{
    WDT_nERROR enErrorReg;

    enErrorReg = WDT_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = WDT_enERROR_POINTER;
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) WDT_enMODULE_MAX);
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_WDT[(UBase_t) enModuleArg];
        enErrorReg = (WDT_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}


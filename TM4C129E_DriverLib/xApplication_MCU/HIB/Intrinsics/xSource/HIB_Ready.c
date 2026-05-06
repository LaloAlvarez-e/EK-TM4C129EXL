/**
 *
 * @file HIB_Ready.c
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Ready.h>

#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_HIB[(UBase_t) HIB_enMODULE_MAX] =
{
    SYSCTL_enHIB,
};

HIB_nERROR HIB__enSetReadyOnRunMode(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_HIB[(UBase_t) enModuleArg];
        enErrorReg = (HIB_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enClearReadyOnRunMode(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_HIB[(UBase_t) enModuleArg];
        enErrorReg = (HIB_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enReset(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_HIB[(UBase_t) enModuleArg];
        enErrorReg = (HIB_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enIsReady(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penReadyArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penReadyArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_HIB[(UBase_t) enModuleArg];
        enErrorReg = (HIB_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

/**
 *
 * @file ACMP_Ready.c
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
 * @verbatim 20 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Ready.h>

#include <xApplication_MCU/ACMP/Intrinsics/xHeader/ACMP_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_ACMP[(UBase_t) ACMP_enMODULE_MAX] =
{
 SYSCTL_enACMP
};

ACMP_nERROR ACMP__enSetReadyOnRunMode(ACMP_nMODULE enModuleArg)
{
    ACMP_nERROR enErrorReg;

    enErrorReg = (ACMP_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ACMP_enMODULE_MAX);
    if(ACMP_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ACMP[(UBase_t) enModuleArg];
        enErrorReg = (ACMP_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

ACMP_nERROR ACMP__enClearReadyOnRunMode(ACMP_nMODULE enModuleArg)
{
    ACMP_nERROR enErrorReg;

    enErrorReg = (ACMP_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ACMP_enMODULE_MAX);
    if(ACMP_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ACMP[(UBase_t) enModuleArg];
        enErrorReg = (ACMP_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

ACMP_nERROR ACMP__enReset(ACMP_nMODULE enModuleArg)
{
    ACMP_nERROR enErrorReg;

    enErrorReg = (ACMP_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ACMP_enMODULE_MAX);
    if(ACMP_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ACMP[(UBase_t) enModuleArg];
        enErrorReg = (ACMP_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

ACMP_nERROR ACMP__enIsReady(ACMP_nMODULE enModuleArg, ACMP_nBOOLEAN* penReadyArg)
{
    ACMP_nERROR enErrorReg;

    enErrorReg = ACMP_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = ACMP_enERROR_POINTER;
    }
    if(ACMP_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ACMP_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ACMP_enMODULE_MAX);
    }
    if(ACMP_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_ACMP[(UBase_t) enModuleArg];
        enErrorReg = (ACMP_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

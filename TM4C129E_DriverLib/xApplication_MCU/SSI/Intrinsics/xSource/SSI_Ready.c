/**
 *
 * @file SSI_Ready.c
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
#include <xApplication_MCU/SSI/Intrinsics/xHeader/SSI_Ready.h>

#include <xApplication_MCU/SSI/Intrinsics/xHeader/SSI_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_SSI[(UBase_t) SSI_enMODULE_MAX] =
{
 SYSCTL_enSSI0, SYSCTL_enSSI1, SYSCTL_enSSI2, SYSCTL_enSSI3
};

SSI_nERROR SSI__enSetReadyOnRunMode(SSI_nMODULE enModuleArg)
{
    SSI_nERROR enErrorReg;

    enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SSI_enMODULE_MAX);
    if(SSI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_SSI[(UBase_t) enModuleArg];
        enErrorReg = (SSI_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

SSI_nERROR SSI__enClearReadyOnRunMode(SSI_nMODULE enModuleArg)
{
    SSI_nERROR enErrorReg;

    enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SSI_enMODULE_MAX);
    if(SSI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_SSI[(UBase_t) enModuleArg];
        enErrorReg = (SSI_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

SSI_nERROR SSI__enReset(SSI_nMODULE enModuleArg)
{
    SSI_nERROR enErrorReg;

    enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SSI_enMODULE_MAX);
    if(SSI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_SSI[(UBase_t) enModuleArg];
        enErrorReg = (SSI_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

SSI_nERROR SSI__enIsReady(SSI_nMODULE enModuleArg, SSI_nBOOLEAN* penReadyArg)
{
    SSI_nERROR enErrorReg;

    enErrorReg = SSI_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = SSI_enERROR_POINTER;
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (SSI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SSI_enMODULE_MAX);
    }
    if(SSI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_SSI[(UBase_t) enModuleArg];
        enErrorReg = (SSI_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

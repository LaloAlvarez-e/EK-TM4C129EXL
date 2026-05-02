/**
 *
 * @file DMA_Ready.c
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
#include <xApplication_MCU/DMA/Intrinsics/xHeader/DMA_Ready.h>

#include <xApplication_MCU/DMA/Intrinsics/xHeader/DMA_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_DMA[(UBase_t) DMA_enMODULE_MAX] =
{
 SYSCTL_enDMA
};

DMA_nERROR DMA__enSetReadyOnRunMode(DMA_nMODULE enModuleArg)
{
    DMA_nERROR enErrorReg;

    enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) DMA_enMODULE_MAX);
    if(DMA_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_DMA[(UBase_t) enModuleArg];
        enErrorReg = (DMA_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

DMA_nERROR DMA__enClearReadyOnRunMode(DMA_nMODULE enModuleArg)
{
    DMA_nERROR enErrorReg;
    enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) DMA_enMODULE_MAX);
    if(DMA_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_DMA[(UBase_t) enModuleArg];
        enErrorReg = (DMA_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

DMA_nERROR DMA__enReset(DMA_nMODULE enModuleArg)
{
    DMA_nERROR enErrorReg;

    enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) DMA_enMODULE_MAX);
    if(DMA_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_DMA[(UBase_t) enModuleArg];
        enErrorReg = (DMA_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

DMA_nERROR DMA__enIsReady(DMA_nMODULE enModuleArg, DMA_nBOOLEAN* penReadyArg)
{
    DMA_nERROR enErrorReg;

    enErrorReg = DMA_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = DMA_enERROR_POINTER;
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) DMA_enMODULE_MAX);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_DMA[(UBase_t) enModuleArg];
        enErrorReg = (DMA_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}


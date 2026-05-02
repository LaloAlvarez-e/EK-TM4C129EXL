/**
 *
 * @file TIMER_Ready.c
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
#include <xApplication_MCU/TIMER/Intrinsics/xHeader/TIMER_Ready.h>

#include <xApplication_MCU/TIMER/Intrinsics/xHeader/TIMER_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_TIMER[(UBase_t) TIMER_enMODULE_NUM_MAX] =
{
 SYSCTL_enTIMER0, SYSCTL_enTIMER1, SYSCTL_enTIMER2, SYSCTL_enTIMER3,
 SYSCTL_enTIMER4, SYSCTL_enTIMER5, SYSCTL_enTIMER6, SYSCTL_enTIMER7
};

TIMER_nERROR TIMER__enSetReadyOnRunMode(TIMER_nMODULE_NUM enModuleArg)
{
    TIMER_nERROR enErrorReg;

    enErrorReg = (TIMER_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) TIMER_enMODULE_NUM_MAX);
    if(TIMER_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_TIMER[(UBase_t) enModuleArg];
        enErrorReg = (TIMER_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

TIMER_nERROR TIMER__enClearReadyOnRunMode(TIMER_nMODULE_NUM enModuleArg)
{
    TIMER_nERROR enErrorReg;

    enErrorReg = (TIMER_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) TIMER_enMODULE_NUM_MAX);
    if(TIMER_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_TIMER[(UBase_t) enModuleArg];
        enErrorReg = (TIMER_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

TIMER_nERROR TIMER__enReset(TIMER_nMODULE enModuleArg)
{
    TIMER_nERROR enErrorReg;

    enErrorReg = (TIMER_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) TIMER_enMODULE_NUM_MAX);
    if(TIMER_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_TIMER[(UBase_t) enModuleArg];
        enErrorReg = (TIMER_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

TIMER_nERROR TIMER__enIsReady(TIMER_nMODULE_NUM enModuleArg, TIMER_nBOOLEAN* penReadyArg)
{
    TIMER_nERROR enErrorReg;

    enErrorReg = TIMER_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = TIMER_enERROR_POINTER;
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        enErrorReg = (TIMER_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) TIMER_enMODULE_NUM_MAX);
    }
    if(TIMER_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_TIMER[(UBase_t) enModuleArg];
        enErrorReg = (TIMER_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}


/**
 *
 * @file QEI_Ready.c
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
 * @verbatim 24 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/QEI/Intrinsics/xHeader/QEI_Ready.h>

#include <xApplication_MCU/QEI/Intrinsics/xHeader/QEI_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_QEI[(UBase_t) QEI_enMODULE_MAX] =
{
 SYSCTL_enQEI0
};

QEI_nERROR QEI__enSetReadyOnRunMode(QEI_nMODULE enModuleArg)
{
    QEI_nERROR enErrorReg;

    enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    if(QEI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_QEI[(UBase_t) enModuleArg];
        enErrorReg = (QEI_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

QEI_nERROR QEI__enClearReadyOnRunMode(QEI_nMODULE enModuleArg)
{
    QEI_nERROR enErrorReg;

    enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    if(QEI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_QEI[(UBase_t) enModuleArg];
        enErrorReg = (QEI_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

QEI_nERROR QEI__enReset(QEI_nMODULE enModuleArg)
{
    QEI_nERROR enErrorReg;

    enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    if(QEI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_QEI[(UBase_t) enModuleArg];
        enErrorReg = (QEI_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

QEI_nERROR QEI__enIsReady(QEI_nMODULE enModuleArg, QEI_nBOOLEAN* penReadyArg)
{
    QEI_nERROR enErrorReg;

    enErrorReg = QEI_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = QEI_enERROR_POINTER;
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_QEI[(UBase_t) enModuleArg];
        enErrorReg = (QEI_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

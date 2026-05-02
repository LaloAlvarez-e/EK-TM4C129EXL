/**
 *
 * @file QEI_InterruptVector.c
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
#include <xApplication_MCU/QEI/Interrupt/xHeader/QEI_InterruptVector.h>

#include <xApplication_MCU/QEI/Intrinsics/xHeader/QEI_Dependencies.h>

static QEI_nERROR QEI__enGetInterruptVector(QEI_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg);

static QEI_nERROR QEI__enGetInterruptVector(QEI_nMODULE enModuleArg, NVIC_nVECTOR* enVectorArg)
{
    const NVIC_nVECTOR NVIC_VECTOR_QEI[(UBase_t) QEI_enMODULE_MAX]=
    {
     NVIC_enVECTOR_QEI0
    };
    QEI_nERROR enErrorReg;

    enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    if(QEI_enERROR_OK == enErrorReg)
    {
        *enVectorArg = NVIC_VECTOR_QEI[(UBase_t) enModuleArg];

    }
    return (enErrorReg);
}

QEI_nERROR QEI__enSetInterruptVectorState(QEI_nMODULE enModuleArg, QEI_nSTATE enStateArg)
{
    NVIC_nVECTOR enVectorReg;
    QEI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_QEI0;
    enErrorReg = QEI__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

QEI_nERROR QEI__enSetInterruptVectorStateWithPriority(QEI_nMODULE enModuleArg, QEI_nSTATE enStateArg, QEI_nPRIORITY enPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    QEI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_QEI0;
    enErrorReg = QEI__enGetInterruptVector(enModuleArg, &enVectorReg);
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) NVIC__enSetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY) enPriorityArg);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) NVIC__enSetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE) enStateArg);
    }

    return (enErrorReg);
}

QEI_nERROR QEI__enGetInterruptVectorState(QEI_nMODULE enModuleArg, QEI_nSTATE* penStateArg)
{
    NVIC_nVECTOR enVectorReg;
    QEI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_QEI0;
    enErrorReg = QEI_enERROR_OK;
    if(0UL == (uintptr_t) penStateArg)
    {
        enErrorReg = QEI_enERROR_POINTER;
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

QEI_nERROR QEI__enGetInterruptVectorStateWithPriority(QEI_nMODULE enModuleArg, QEI_nSTATE* penStateArg, QEI_nPRIORITY* penPriorityArg)
{
    NVIC_nVECTOR enVectorReg;
    QEI_nERROR enErrorReg;

    enVectorReg = NVIC_enVECTOR_QEI0;
    enErrorReg = QEI_enERROR_OK;
    if((0UL == (uintptr_t) penStateArg) || (0UL == (uintptr_t) penPriorityArg))
    {
        enErrorReg = QEI_enERROR_POINTER;
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enGetInterruptVector(enModuleArg, &enVectorReg);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) NVIC__enGetVectorPriority(NVIC_enMODULE_0, enVectorReg, (NVIC_nPRIORITY*) penPriorityArg);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) NVIC__enGetVectorState(NVIC_enMODULE_0, enVectorReg, (NVIC_nSTATE*) penStateArg);
    }

    return (enErrorReg);
}

QEI_nERROR QEI__enEnableInterruptVector(QEI_nMODULE enModuleArg)
{
    QEI_nERROR enErrorReg;
    enErrorReg = QEI__enSetInterruptVectorState(enModuleArg, QEI_enSTATE_ENA);
    return (enErrorReg);
}

QEI_nERROR QEI__enEnableInterruptVectorWithPriority(QEI_nMODULE enModuleArg, QEI_nPRIORITY enPriorityArg)
{
    QEI_nERROR enErrorReg;
    enErrorReg = QEI__enSetInterruptVectorStateWithPriority(enModuleArg, QEI_enSTATE_ENA, enPriorityArg);
    return (enErrorReg);
}

QEI_nERROR QEI__enDisableInterruptVector(QEI_nMODULE enModuleArg)
{
    QEI_nERROR enErrorReg;
    enErrorReg = QEI__enSetInterruptVectorState(enModuleArg, QEI_enSTATE_DIS);
    return (enErrorReg);
}

QEI_nERROR QEI__enDisableInterruptVectorWithPriority(QEI_nMODULE enModuleArg, QEI_nPRIORITY enPriorityArg)
{
    QEI_nERROR enErrorReg;
    enErrorReg = QEI__enSetInterruptVectorStateWithPriority(enModuleArg, QEI_enSTATE_DIS, enPriorityArg);
    return (enErrorReg);
}


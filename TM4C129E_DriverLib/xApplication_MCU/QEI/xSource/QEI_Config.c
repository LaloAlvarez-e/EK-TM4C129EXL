/**
 *
 * @file QEI_Config.c
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
#include <xApplication_MCU/QEI/xHeader/QEI_Config.h>

#include <xApplication_MCU/QEI/Intrinsics/xHeader/QEI_Dependencies.h>

#define PHA_SIGNAL (0UL)
#define PHB_SIGNAL (1UL)
#define IDX_SIGNAL (2UL)

#define MAX_CONFIG (2UL)

GPIO_nDIGITAL_FUNCTION QEI_enGpioInput[MAX_CONFIG] [(UBase_t) QEI_enMODULE_MAX][(UBase_t) 3UL] =
{
    {
        {GPIO_enPhA0_L1, GPIO_enPhB0_L2, GPIO_enIDX0_L3},
    },
    {
        {GPIO_enPhA0_L1, GPIO_enPhB0_L2, GPIO_enIDX0_L3},
    },
 };

QEI_nERROR QEI__enSetConfig(QEI_nMODULE enModuleArg,
                             const QEI_CONTROL_t* pstControlConfigArg,
                             const QEI_INPUT_t* pstInputConfigArg,
                             UBase_t uxInitialPosArg,
                             UBase_t uxMaxPositionArg,
                             UBase_t uxTimerLoadArg)
{
    QEI_nERROR enErrorReg;

    enErrorReg = QEI_enERROR_OK;
    if((0UL == (uintptr_t) pstControlConfigArg) || (0UL == (uintptr_t) pstInputConfigArg))
    {
        enErrorReg = QEI_enERROR_POINTER;
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) QEI_enMODULE_MAX);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__uxCheckParams((UBase_t) pstInputConfigArg->enPhA, MAX_CONFIG);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__uxCheckParams((UBase_t) pstInputConfigArg->enPhB, MAX_CONFIG);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) MCU__uxCheckParams((UBase_t) pstInputConfigArg->enIDX, MAX_CONFIG);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        if(QEI_enRESET_INDEX == pstControlConfigArg->enResetMode)
        {
            enErrorReg = (QEI_nERROR) GPIO__enSetDigitalConfig(QEI_enGpioInput[(UBase_t) pstInputConfigArg->enIDX]
                                                                              [(UBase_t) enModuleArg]
                                                                              [IDX_SIGNAL],
                                                               GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
        }
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) GPIO__enSetDigitalConfig(QEI_enGpioInput[(UBase_t) pstInputConfigArg->enPhA]
                                                [(UBase_t) enModuleArg]
                                                [PHA_SIGNAL],
                                GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = (QEI_nERROR) GPIO__enSetDigitalConfig(QEI_enGpioInput[(UBase_t) pstInputConfigArg->enPhB]
                                                [(UBase_t) enModuleArg]
                                                [PHB_SIGNAL],
                                GPIO_enCONFIG_INPUT_2MA_PUSHPULL);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetInvertInputStateByNumber(enModuleArg, QEI_enINPUT_PhA, pstInputConfigArg->enPhAInvert);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetInvertInputStateByNumber(enModuleArg, QEI_enINPUT_PhB,  pstInputConfigArg->enPhBInvert);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetInvertInputStateByNumber(enModuleArg, QEI_enINPUT_INDEX, pstInputConfigArg->enIDXInvert);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetStallMode(enModuleArg, pstControlConfigArg->enStall);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetResetMode(enModuleArg, pstControlConfigArg->enResetMode);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSwapPhaseInput(enModuleArg, pstControlConfigArg->enSwapPhaseInput);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetMode(enModuleArg, pstControlConfigArg->enMode);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetPulsePerPeriodState(enModuleArg, pstControlConfigArg->enVelocity);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetInputFilterState(enModuleArg, pstControlConfigArg->enInputFilter);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        if(QEI_enMODE_QUADRATURE == pstControlConfigArg->enMode)
        {
            enErrorReg = QEI__enSetInputCapture(enModuleArg, pstControlConfigArg->enCaptureMode);
        }
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        if(QEI_enSTATE_ENA == pstControlConfigArg->enVelocity)
        {
            enErrorReg = QEI__enSetPulsePerPeriodPredivider(enModuleArg, pstControlConfigArg->enVelocityPrediv);
        }
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        if(QEI_enSTATE_ENA == pstControlConfigArg->enInputFilter)
        {
            enErrorReg = QEI__enSetInputFilterCount(enModuleArg, pstControlConfigArg->enInputFilterCount);
        }
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetMaximumPositionIntegrator(enModuleArg, uxMaxPositionArg);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetLoadTimerValue(enModuleArg, uxTimerLoadArg);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetState(enModuleArg, pstControlConfigArg->enEnableModule);
    }
    if(QEI_enERROR_OK == enErrorReg)
    {
        enErrorReg = QEI__enSetCurrentPositionIntegrator(enModuleArg, uxInitialPosArg);
    }
    return (enErrorReg);
}

/**
 *
 * @file ADC_InterruptRegisterIRQSource.c
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 19 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/ADC_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/ADC_InterruptRoutine_Source.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_SW__enRegisterIRQSourceHandler(ADC_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                              ADC_nMODULE enModuleArg,
                                              ADC_nSEQUENCER enSequencerArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_pvfIRQSourceHandler_t* pvfIrqHandler = ADC_SW__pvfGetIRQSourceHandlerPointer(enModuleArg, enSequencerArg);
        enErrorReg = (ADC_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Sequencer__enRegisterIRQSourceHandler(ADC_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                     ADC_nMODULE enModuleArg,
                                                     ADC_nSEQUENCER enSequencerArg,
                                                     ADC_nINT_TYPE enInterruptSourceArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) ADC_enINT_TYPE_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_pvfIRQSourceHandler_t* pvfIrqHandler = ADC_Sequencer__pvfGetIRQSourceHandlerPointer(enModuleArg, enSequencerArg, enInterruptSourceArg);
        enErrorReg = (ADC_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Comparator__enRegisterIRQSourceHandler(ADC_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                      ADC_nMODULE enModuleArg,
                                                      ADC_nSEQUENCER enSequencerArg,
                                                      ADC_nCOMPARATOR enComparatorArg)
{
    ADC_nERROR enErrorReg;
    enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) ADC_enMODULE_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enComparatorArg, (UBase_t) ADC_enCOMPARATOR_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        ADC_pvfIRQSourceHandler_t* pvfIrqHandler = ADC_Comparator__pvfGetIRQSourceHandlerPointer(enModuleArg, enSequencerArg, enComparatorArg);
        enErrorReg = (ADC_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }
    return (enErrorReg);
}

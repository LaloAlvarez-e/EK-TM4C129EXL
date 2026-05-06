
/**
 *
 * @file ADC_InterruptRegisterIRQSource.h
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

#ifndef XDRIVER_MCU_ADC_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_ADC_INTERRUPTREGISTERIRQSOURCE_H_
#define XDRIVER_MCU_ADC_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_ADC_INTERRUPTREGISTERIRQSOURCE_H_

#include <xDriver_MCU/ADC/Peripheral/xHeader/ADC_Enum.h>

ADC_nERROR ADC_SW__enRegisterIRQSourceHandler(ADC_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                              ADC_nMODULE enModuleArg,
                                              ADC_nSEQUENCER enSequencerArg);
ADC_nERROR ADC_Sequencer__enRegisterIRQSourceHandler(ADC_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                     ADC_nMODULE enModuleArg,
                                                     ADC_nSEQUENCER enSequencerArg,
                                                     ADC_nINT_TYPE enInterruptSourceArg);
ADC_nERROR ADC_Comparator__enRegisterIRQSourceHandler(ADC_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                      ADC_nMODULE enModuleArg,
                                                      ADC_nSEQUENCER enSequencerArg,
                                                      ADC_nCOMPARATOR enComparatorArg);

#endif /* XDRIVER_MCU_ADC_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_ADC_INTERRUPTREGISTERIRQSOURCE_H_ */

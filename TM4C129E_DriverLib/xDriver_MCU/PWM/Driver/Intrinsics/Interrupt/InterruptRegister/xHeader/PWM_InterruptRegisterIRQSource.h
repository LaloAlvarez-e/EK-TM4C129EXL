/**
 *
 * @file PWM_InterruptRegisterIRQSource.h
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
 * @verbatim 28 dic. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 dic. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_PWM_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_PWM_INTERRUPTREGISTERIRQSOURCE_H_
#define XDRIVER_MCU_PWM_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_PWM_INTERRUPTREGISTERIRQSOURCE_H_

#include <xDriver_MCU/PWM/Peripheral/xHeader/PWM_Enum.h>


PWM_nERROR PWM_Generator__enRegisterIRQSourceHandler(PWM_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                     PWM_nMODULE enModuleArg,
                                                     PWM_nGENERATOR enGeneratorArg,
                                                     PWM_nEVENT enEventArg);
PWM_nERROR PWM_FaultSW__enRegisterIRQSourceHandler(PWM_pvfIRQSourceHandler_t pfIrqSourceHandler, PWM_nMODULE enModuleArg);

PWM_nERROR PWM_FaultInput__enRegisterIRQSourceHandler(PWM_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                      PWM_nMODULE enModuleArg,
                                                      PWM_nGENERATOR enGeneratorArg,
                                                      PWM_nFAULT_INPUT enInputArg);
PWM_nERROR PWM_FaultDComp__enRegisterIRQSourceHandler(PWM_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                      PWM_nMODULE enModuleArg,
                                                      PWM_nGENERATOR enGeneratorArg,
                                                      PWM_nFAULT_DCOMP enDCompArg);

#endif /* XDRIVER_MCU_PWM_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_PWM_INTERRUPTREGISTERIRQSOURCE_H_ */

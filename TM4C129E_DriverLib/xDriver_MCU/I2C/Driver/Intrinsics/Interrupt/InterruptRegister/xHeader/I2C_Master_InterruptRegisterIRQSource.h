/**
 *
 * @file I2C_Master_InterruptRegisterIRQSource.h
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
 * @verbatim Mar 24, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Mar 24, 2021        indevicemex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_I2C_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_I2C_MASTER_INTERRUPTREGISTERIRQSOURCE_H_
#define XDRIVER_MCU_I2C_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_I2C_MASTER_INTERRUPTREGISTERIRQSOURCE_H_

#include <xDriver_MCU/I2C/Peripheral/xHeader/I2C_Enum.h>

I2C_nERROR I2C_Master__enRegisterIRQSourceHandler(I2C_nMODULE enModuleArg, I2C_nMASTER_INT enInterruptSourceArg, I2C_pvfIRQSourceHandler_t pfIrqSourceHandler);

#endif /* XDRIVER_MCU_I2C_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTREGISTER_XHEADER_I2C_MASTER_INTERRUPTREGISTERIRQSOURCE_H_ */

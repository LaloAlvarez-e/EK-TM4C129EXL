/**
 *
 * @file I2C_Slave_InterruptRoutine_Source.h
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

#ifndef XDRIVER_MCU_I2C_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_I2C_SLAVE_INTERRUPTROUTINE_SOURCE_H_
#define XDRIVER_MCU_I2C_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_I2C_SLAVE_INTERRUPTROUTINE_SOURCE_H_

#include <xDriver_MCU/I2C/Peripheral/xHeader/I2C_Enum.h>

void (*I2C_Slave__pvfGetIRQSourceHandler(I2C_nMODULE enI2CPort,
                                    I2C_nSLAVE_INTERRUPT enInterruptNumber))(void);
void (**I2C_Slave__pvfGetIRQSourceHandlerPointer(I2C_nMODULE enI2CPort,
                                            I2C_nSLAVE_INTERRUPT enInterruptNumber))(void);

#endif /* XDRIVER_MCU_I2C_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_I2C_SLAVE_INTERRUPTROUTINE_SOURCE_H_ */

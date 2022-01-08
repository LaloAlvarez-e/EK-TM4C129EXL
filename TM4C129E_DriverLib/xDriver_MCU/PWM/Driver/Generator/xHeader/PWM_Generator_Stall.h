/**
 *
 * @file PWM_Generator_Stall.h
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
 * @verbatim 7 ene. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 ene. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_PWM_DRIVER_GENERATOR_XHEADER_PWM_GENERATOR_STALL_H_
#define XDRIVER_MCU_PWM_DRIVER_GENERATOR_XHEADER_PWM_GENERATOR_STALL_H_

#include <xDriver_MCU/PWM/Peripheral/xHeader/PWM_Enum.h>

void PWM_Generator__vSetStall(PWM_nMODULE enModule, PWM_nGENERATOR enGenerator,
                               PWM_nSTALL enStallArg);
PWM_nSTALL PWM_Generator__enGetStall(PWM_nMODULE enModule, PWM_nGENERATOR enGenerator);

#endif /* XDRIVER_MCU_PWM_DRIVER_GENERATOR_XHEADER_PWM_GENERATOR_STALL_H_ */

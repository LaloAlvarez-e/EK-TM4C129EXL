/**
 *
 * @file TIMER_SubParams.h
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
 * @verbatim 31 ene. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 31 ene. 2021     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_TIMER_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_TIMER_SUBPARAMS_H_
#define XDRIVER_MCU_TIMER_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_TIMER_SUBPARAMS_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

void TIMER__vGetSubParams(TIMER_nMODULE enModule, uint32_t* pu32SubModule,
                          uint32_t* pu32ModuleNumber);

#endif /* XDRIVER_MCU_TIMER_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_TIMER_SUBPARAMS_H_ */

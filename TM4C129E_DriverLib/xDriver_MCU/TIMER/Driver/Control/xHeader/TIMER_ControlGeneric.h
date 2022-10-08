/**
 *
 * @file TIMER_ControlGeneric.h
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
 * @verbatim 15 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_DRIVER_TIMER_INTRINSICS_TIMER_CONTROLGENERIC_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_DRIVER_TIMER_INTRINSICS_TIMER_CONTROLGENERIC_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

UBase_t TIMER__uxGetControlGeneric(TIMER_nMODULE enModule, UBase_t uxMaskFeature,
                                     UBase_t uxBitFeature);
void TIMER__vSetControlGeneric(TIMER_nMODULE enModule, UBase_t uxFeatureValue,
                               UBase_t uxMaskFeature, UBase_t uxBitFeature);

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_DRIVER_TIMER_INTRINSICS_TIMER_CONTROLGENERIC_H_ */

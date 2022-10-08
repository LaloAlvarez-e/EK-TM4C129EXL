/**
 *
 * @file TIMER_Match.h
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
 * @verbatim 16 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 16 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_DRIVER_TIMER_MATCH_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_DRIVER_TIMER_MATCH_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

void TIMER__vSetMatch(TIMER_nMODULE enModule, UBase_t uxMatch);
UBase_t TIMER__uxGetMatch(TIMER_nMODULE enModule);

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_DRIVER_TIMER_MATCH_H_ */

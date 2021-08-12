/**
 *
 * @file TIMER_ModeReloadMatch.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_APP_TIMER_MODERELOADMATCH_TIMER_MODERELOADMATCH_H_
#define XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_APP_TIMER_MODERELOADMATCH_TIMER_MODERELOADMATCH_H_

#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Enum.h>

TIMER_nSTATUS TIMER__enSetMode_ReloadMatch(TIMER_nMODULE enModule, TIMER_nMODE enModeArg, uint32_t u32Reload, uint32_t u32Match);
TIMER_nSTATUS TIMER__enSetModeStruct_ReloadMatch(TIMER_nMODULE enModule, const TIMER_MODE_Typedef* pstMode, uint32_t u32Reload, uint32_t u32Match);

#endif /* XDRIVER_MCU_DRIVER_HEADER_TIMER_TIMER_APP_TIMER_MODERELOADMATCH_TIMER_MODERELOADMATCH_H_ */

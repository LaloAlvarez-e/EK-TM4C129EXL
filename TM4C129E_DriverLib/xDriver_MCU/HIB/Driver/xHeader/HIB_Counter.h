/**
 *
 * @file HIB_Counter.h
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_COUNTER_H_
#define XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_COUNTER_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enSetRTCCounterMatch(HIB_nMODULE enModuleArg, UBase_t uxSecondsArg, UBase_t uxSubSecondsArg);
HIB_nERROR HIB__enGetRTCCounterMatch(HIB_nMODULE enModuleArg, UBase_t* puxSecondsArg, UBase_t* puxSubSecondsArg);

HIB_nERROR HIB__enSetRTCCounterTrim(HIB_nMODULE enModuleArg, UBase_t uxSubSecondsArg);
HIB_nERROR HIB__enSetRTCCounterTrimRelative(HIB_nMODULE enModuleArg, int16_t s16ChangeArg);
HIB_nERROR HIB__enGetRTCCounterTrim(HIB_nMODULE enModuleArg, UBase_t* uxSubSecondsArg);

HIB_nERROR HIB__enSetRTCCounterValue(HIB_nMODULE enModuleArg, UBase_t uxValueArg);
HIB_nERROR HIB__enGetRTCCounterValue(HIB_nMODULE enModuleArg, UBase_t* puxSecondsArg, UBase_t* puxSubSecondsArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_COUNTER_H_ */

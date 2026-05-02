/**
 *
 * @file HIB_Calendar.h
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

#ifndef XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_CALENDAR_H_
#define XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_CALENDAR_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enSetCalendarMode(HIB_nMODULE enModuleArg, HIB_nCALENDAR_MODE enModeArg);
HIB_nERROR HIB__enGetCalendarMode(HIB_nMODULE enModuleArg, HIB_nCALENDAR_MODE* penModeArg);

HIB_nERROR HIB__enSetHourMode(HIB_nMODULE enModuleArg, HIB_nHOUR_MODE enModeArg);
HIB_nERROR HIB__enGetHourMode(HIB_nMODULE enModuleArg, HIB_nHOUR_MODE* penModeArg);

HIB_nERROR HIB__enGetCalendarValue(HIB_nMODULE enModuleArg, HIB_CALENDAR_t* pstCalendarArg);

HIB_nERROR HIB__enSetCalendarLoad(HIB_nMODULE enModuleArg, const HIB_CALENDAR_t* pstCalendarArg);
HIB_nERROR HIB__enGetCalendarLoad(HIB_nMODULE enModuleArg, HIB_CALENDAR_t* pstCalendarArg);

HIB_nERROR HIB__enSetCalendarMatch(HIB_nMODULE enModuleArg, const HIB_CALENDAR_t* pstCalendarArg);
HIB_nERROR HIB__enGetCalendarMatch(HIB_nMODULE enModuleArg, HIB_CALENDAR_t* pstCalendarArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_CALENDAR_H_ */

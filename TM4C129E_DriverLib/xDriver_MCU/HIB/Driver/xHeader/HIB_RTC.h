/**
 *
 * @file HIB_RTC.h
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

#ifndef XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_RTC_H_
#define XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_RTC_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enSetRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enGetRTCState(HIB_nMODULE enModuleArg, HIB_nSTATE* penStateArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_XHEADER_HIB_RTC_H_ */

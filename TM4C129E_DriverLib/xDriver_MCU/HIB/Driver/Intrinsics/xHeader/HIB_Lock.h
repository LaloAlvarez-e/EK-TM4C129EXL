/**
 *
 * @file HIB_Lock.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_XHEADER_HIB_LOCK_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_XHEADER_HIB_LOCK_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enIsLocked(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockedArg);
HIB_nERROR HIB__enSetLockState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enLock(HIB_nMODULE enModuleArg);
HIB_nERROR HIB__enUnlock(HIB_nMODULE enModuleArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_XHEADER_HIB_LOCK_H_ */

/**
 *
 * @file HIB_Wait.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_HIB_WAIT_H_
#define XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_HIB_WAIT_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enIsWriteOngoing(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penStatusArg);
HIB_nERROR HIB__enWaitWrite(HIB_nMODULE enModuleArg, UBase_t uxTimeoutArg);

#endif /* XDRIVER_MCU_DRIVER_HEADER_HIB_HIB_DRIVER_INTRINSICS_PRIMITIVES_XHEADER_HIB_WAIT_H_ */

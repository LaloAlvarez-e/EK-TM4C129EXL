/**
 *
 * @file HIB_InterruptSource.h
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

#ifndef XDRIVER_MCU_HIB_DRIVER_INTRINSICS_INTERRUPT_XHEADER_HIB_INTERRUPTSOURCE_H_
#define XDRIVER_MCU_HIB_DRIVER_INTRINSICS_INTERRUPT_XHEADER_HIB_INTERRUPTSOURCE_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

HIB_nERROR HIB__enSetInterruptSourceStateByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nSTATE enStateArg);
HIB_nERROR HIB__enSetInterruptSourceStateByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATE enStateArg);

HIB_nERROR HIB__enGetInterruptSourceStateByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nINTMASK* penInterruptGetArg);
HIB_nERROR HIB__enGetInterruptSourceStateByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATE* penStateArg);

HIB_nERROR HIB__enEnableInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg);
HIB_nERROR HIB__enEnableInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg);

HIB_nERROR HIB__enClearInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg);
HIB_nERROR HIB__enClearInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg);

HIB_nERROR HIB__enStatusInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nINTMASK* penInterruptStatusArg);
HIB_nERROR HIB__enStatusInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATUS* penStatusArg);

HIB_nERROR HIB__enStatusMaskedInterruptSourceByMask(HIB_nMODULE enModuleArg, HIB_nINTMASK enInterruptMaskArg, HIB_nINTMASK* penInterruptStatusArg);
HIB_nERROR HIB__enStatusMaskedInterruptSourceByNumber(HIB_nMODULE enModuleArg, HIB_nINT enInterruptArg, HIB_nSTATUS* penStatusArg);

#endif /* XDRIVER_MCU_HIB_DRIVER_INTRINSICS_INTERRUPT_XHEADER_HIB_INTERRUPTSOURCE_H_ */

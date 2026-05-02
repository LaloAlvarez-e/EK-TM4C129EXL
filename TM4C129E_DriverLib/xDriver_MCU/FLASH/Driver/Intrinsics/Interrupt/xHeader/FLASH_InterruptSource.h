/**
 *
 * @file FLASH_InterruptSource.h
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
 * @verbatim 10 ago. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ago. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_FLASH_DRIVER_INTRINSICS_INTERRUPT_XHEADER_FLASH_INTERRUPTSOURCE_H_
#define XDRIVER_MCU_FLASH_DRIVER_INTRINSICS_INTERRUPT_XHEADER_FLASH_INTERRUPTSOURCE_H_

#include <xDriver_MCU/FLASH/Peripheral/xHeader/FLASH_Enum.h>
#if defined (__TI_ARM__ ) || defined (__MSP430__ )

#pragma  CODE_SECTION(FLASH__enSetInterruptSourceStateByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enSetInterruptSourceStateByNumber, ".ramcode")

#pragma  CODE_SECTION(FLASH__enGetInterruptSourceStateByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enGetInterruptSourceStateByNumber, ".ramcode")

#pragma  CODE_SECTION(FLASH__enEnableInterruptSourceByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enEnableInterruptSourceByNumber, ".ramcode")
#pragma  CODE_SECTION(FLASH__enDisableInterruptSourceByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enDisableInterruptSourceByNumber, ".ramcode")

#pragma  CODE_SECTION(FLASH__enClearInterruptSourceByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enClearInterruptSourceByNumber, ".ramcode")

#pragma  CODE_SECTION(FLASH__enStatusInterruptSourceByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enStatusInterruptSourceByNumber, ".ramcode")

#pragma  CODE_SECTION(FLASH__enStatusMaskedInterruptSourceByMask, ".ramcode")
#pragma  CODE_SECTION(FLASH__enStatusMaskedInterruptSourceByNumber, ".ramcode")

#pragma  CODE_SECTION(FLASH__enGetInterruptSourceShift, ".ramcode")

FLASH_nERROR FLASH__enSetInterruptSourceStateByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nSTATE enStateArg);
FLASH_nERROR FLASH__enSetInterruptSourceStateByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATE enStateArg);

FLASH_nERROR FLASH__enGetInterruptSourceStateByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptGetArg);
FLASH_nERROR FLASH__enGetInterruptSourceStateByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATE* penStateArg);

FLASH_nERROR FLASH__enEnableInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg);
FLASH_nERROR FLASH__enEnableInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg);
FLASH_nERROR FLASH__enDisableInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg);
FLASH_nERROR FLASH__enDisableInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg);

FLASH_nERROR FLASH__enClearInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg);
FLASH_nERROR FLASH__enClearInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg);

FLASH_nERROR FLASH__enStatusInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptStatusArg);
FLASH_nERROR FLASH__enStatusInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATUS* penStatusArg);

FLASH_nERROR FLASH__enStatusMaskedInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptStatusArg);
FLASH_nERROR FLASH__enStatusMaskedInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATUS* penStatusArg);

FLASH_nERROR FLASH__enGetInterruptSourceShift(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, UBase_t* puxShiftArg);
#else

FLASH_nERROR FLASH__enSetInterruptSourceStateByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nSTATE enStateArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enSetInterruptSourceStateByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATE enStateArg) __attribute__((section(".ramcode")));

FLASH_nERROR FLASH__enGetInterruptSourceStateByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptGetArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enGetInterruptSourceStateByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATE* penStateArg) __attribute__((section(".ramcode")));

FLASH_nERROR FLASH__enEnableInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enEnableInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enDisableInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enDisableInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg) __attribute__((section(".ramcode")));

FLASH_nERROR FLASH__enClearInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enClearInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg) __attribute__((section(".ramcode")));

FLASH_nERROR FLASH__enStatusInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptStatusArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enStatusInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATUS* penStatusArg) __attribute__((section(".ramcode")));

FLASH_nERROR FLASH__enStatusMaskedInterruptSourceByMask(FLASH_nMODULE enModuleArg, FLASH_nINTMASK enInterruptMaskArg, FLASH_nINTMASK* penInterruptStatusArg) __attribute__((section(".ramcode")));
FLASH_nERROR FLASH__enStatusMaskedInterruptSourceByNumber(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, FLASH_nSTATUS* penStatusArg) __attribute__((section(".ramcode")));

FLASH_nERROR FLASH__enGetInterruptSourceShift(FLASH_nMODULE enModuleArg, FLASH_nINT enInterruptArg, UBase_t* puxShiftArg) __attribute__((section(".ramcode")));
#endif

#endif /* XDRIVER_MCU_FLASH_DRIVER_INTRINSICS_INTERRUPT_XHEADER_FLASH_INTERRUPTSOURCE_H_ */

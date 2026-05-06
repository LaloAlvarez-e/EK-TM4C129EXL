/**
 *
 * @file FLASH_InterruptRoutine_Source.h
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

#ifndef XDRIVER_MCU_FLASH_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_FLASH_INTERRUPTROUTINE_SOURCE_H_
#define XDRIVER_MCU_FLASH_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_FLASH_INTERRUPTROUTINE_SOURCE_H_

#include <xDriver_MCU/FLASH/Peripheral/xHeader/FLASH_Enum.h>

#if defined (__TI_ARM__ ) || defined (__MSP430__ )

#pragma  CODE_SECTION(FLASH__pvfGetIRQSourceHandler, ".ramcode")
#pragma  CODE_SECTION(FLASH__pvfGetIRQSourceHandlerPointer, ".ramcode")

FLASH_pvfIRQSourceHandler_t FLASH__pvfGetIRQSourceHandler(FLASH_nMODULE enModuleArg,
                                                          FLASH_nINT enInterruptSourceArg);
FLASH_pvfIRQSourceHandler_t* FLASH__pvfGetIRQSourceHandlerPointer(FLASH_nMODULE enModuleArg,
                                                                  FLASH_nINT enInterruptSourceArg);
#elif defined (__GNUC__ ) && !defined(_MSC_VER)

FLASH_pvfIRQSourceHandler_t FLASH__pvfGetIRQSourceHandler(FLASH_nMODULE enModuleArg,
                                                          FLASH_nINT enInterruptSourceArg) __attribute__((section(".ramcode")));
FLASH_pvfIRQSourceHandler_t* FLASH__pvfGetIRQSourceHandlerPointer(FLASH_nMODULE enModuleArg,
                                                                  FLASH_nINT enInterruptSourceArg) __attribute__((section(".ramcode")));
#else

FLASH_pvfIRQSourceHandler_t FLASH__pvfGetIRQSourceHandler(FLASH_nMODULE enModuleArg,
                                                          FLASH_nINT enInterruptSourceArg);
FLASH_pvfIRQSourceHandler_t* FLASH__pvfGetIRQSourceHandlerPointer(FLASH_nMODULE enModuleArg,
                                                                  FLASH_nINT enInterruptSourceArg);
#endif


#endif /* XDRIVER_MCU_FLASH_DRIVER_INTRINSICS_INTERRUPT_INTERRUPTROUTINE_XHEADER_FLASH_INTERRUPTROUTINE_SOURCE_H_ */

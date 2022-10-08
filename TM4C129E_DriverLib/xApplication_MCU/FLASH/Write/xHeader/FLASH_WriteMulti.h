/**
 *
 * @file FLASH_WriteMulti.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 14 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 14 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_FLASH_WRITE_XHEADER_FLASH_WRITEMULTI_H_
#define XAPPLICATION_MCU_FLASH_WRITE_XHEADER_FLASH_WRITEMULTI_H_

#include <xApplication_MCU/FLASH/Intrinsics/xHeader/FLASH_Defines.h>
#if 0
#if defined (__TI_ARM__ ) || defined (__MSP430__ )

#pragma  CODE_SECTION(FLASH__enWriteMultiWorld, ".ramcode")
#pragma  CODE_SECTION(FLASH__enWriteMultiHalfWorld, ".ramcode")
#pragma  CODE_SECTION(FLASH__enWriteMultiByte, ".ramcode")
#pragma  CODE_SECTION(FLASH__enWriteMultiWorldConstant, ".ramcode")
#pragma  CODE_SECTION(FLASH__enWriteMultiHalfWorldConstant, ".ramcode")
#pragma  CODE_SECTION(FLASH__enWriteMultiByteConstant, ".ramcode")

FLASH_nERROR FLASH__enWriteMultiWorld(UBase_t* puxData,
                                       UBase_t uxAddress,
                                       UBase_t uxCount);
FLASH_nERROR FLASH__enWriteMultiHalfWorld(uint16_t* pu16Data,
                                           UBase_t uxAddress,
                                           UBase_t uxCount);
FLASH_nERROR FLASH__enWriteMultiByte(uint8_t* pu8Data,
                                      UBase_t uxAddress,
                                      UBase_t uxCount);

FLASH_nERROR FLASH__enWriteMultiWorldConstant(UBase_t uxData,
                                               UBase_t uxAddress,
                                               UBase_t uxCount);
FLASH_nERROR FLASH__enWriteMultiHalfWorldConstant(uint16_t u16Data,
                                                   UBase_t uxAddress,
                                                   UBase_t uxCount);
FLASH_nERROR FLASH__enWriteMultiByteConstant(uint8_t u8Data,
                                              UBase_t uxAddress,
                                              UBase_t uxCount);

#elif defined (__GNUC__ )

__attribute__((section(".ramcode")))
FLASH_nERROR FLASH__enWriteMultiWorld(UBase_t* puxData,
                                       UBase_t uxAddress,
                                       UBase_t uxCount) ;
__attribute__((section(".ramcode")))
FLASH_nERROR FLASH__enWriteMultiHalfWorld(uint16_t* pu16Data,
                                           UBase_t uxAddress,
                                           UBase_t uxCount);
__attribute__((section(".ramcode")))
FLASH_nERROR FLASH__enWriteMultiByte(uint8_t* pu8Data,
                                      UBase_t uxAddress,
                                      UBase_t uxCount);

__attribute__((section(".ramcode")))
FLASH_nERROR FLASH__enWriteMultiWorldConstant(UBase_t uxData,
                                               UBase_t uxAddress,
                                               UBase_t uxCount);
__attribute__((section(".ramcode")))
FLASH_nERROR FLASH__enWriteMultiHalfWorldConstant(uint16_t u16Data,
                                                   UBase_t uxAddress,
                                                   UBase_t uxCount);
__attribute__((section(".ramcode")))
FLASH_nERROR FLASH__enWriteMultiByteConstant(uint8_t u8Data,
                                              UBase_t uxAddress,
                                              UBase_t uxCount);

#endif

#endif
#endif /* XAPPLICATION_MCU_FLASH_WRITE_XHEADER_FLASH_WRITEMULTI_H_ */

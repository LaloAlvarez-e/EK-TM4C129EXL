/**
 *
 * @file HIB_RegisterDefines_IO.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_IO_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_IO_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 11 IO ***********************************************
******************************************************************************************/
/*--------*/
#define HIB_IO_R_IOWRC_MASK    ((UBase_t) 0x80000000UL)
#define HIB_IO_R_IOWRC_BIT    ((UBase_t) 31UL)
#define HIB_IO_R_IOWRC_PROGRESS    ((UBase_t) 0x00000000UL)
#define HIB_IO_R_IOWRC_DONE    ((UBase_t) 0x80000000UL)

#define HIB_IO_IOWRC_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IO_IOWRC_PROGRESS    ((UBase_t) 0x00000000UL)
#define HIB_IO_IOWRC_DONE    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IO_R_WURSTEN_MASK    ((UBase_t) 0x00000010UL)
#define HIB_IO_R_WURSTEN_BIT    ((UBase_t) 4UL)
#define HIB_IO_R_WURSTEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_IO_R_WURSTEN_ENA    ((UBase_t) 0x00000010UL)

#define HIB_IO_WURSTEN_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IO_WURSTEN_DIS    ((UBase_t) 0x00000000UL)
#define HIB_IO_WURSTEN_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_IO_R_WUUNLK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IO_R_WUUNLK_BIT    ((UBase_t) 0UL)
#define HIB_IO_R_WUUNLK_DIS    ((UBase_t) 0x00000000UL)
#define HIB_IO_R_WUUNLK_ENA    ((UBase_t) 0x00000001UL)

#define HIB_IO_WUUNLK_MASK    ((UBase_t) 0x00000001UL)
#define HIB_IO_WUUNLK_DIS    ((UBase_t) 0x00000000UL)
#define HIB_IO_WUUNLK_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_IO_H_ */


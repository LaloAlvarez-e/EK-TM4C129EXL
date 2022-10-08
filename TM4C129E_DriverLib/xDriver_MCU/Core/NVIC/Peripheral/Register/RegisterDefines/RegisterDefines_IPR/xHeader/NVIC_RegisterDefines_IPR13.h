/**
 *
 * @file NVIC_RegisterDefines_IPR13.h
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
 * @verbatim 22 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date    Author    Version    Description
 * 22 jun. 2020    vyldram    1.0    initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_NVIC_NVIC_PERIPHERAL_NVIC_REGISTER_NVIC_REGISTERDEFINES_NVIC_REGISTERDEFINES_IPR_NVIC_REGISTERDEFINES_IPR13_H_
#define XDRIVER_MCU_DRIVER_HEADER_NVIC_NVIC_PERIPHERAL_NVIC_REGISTER_NVIC_REGISTERDEFINES_NVIC_REGISTERDEFINES_IPR_NVIC_REGISTERDEFINES_IPR13_H_

#include <xDriver_MCU/Core/NVIC/Peripheral/xHeader/NVIC_Enum.h>

/********************************************************************************************/
/************************************* IPR13 ***********************************************/
/******************************************************************************************/

/*----------*/
#define NVIC_IPR13_R_NVIC_GPIOK_MASK    ((UBase_t) 0x000000E0UL)
#define NVIC_IPR13_R_NVIC_GPIOK_BIT    (5UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP1    ((UBase_t) 0x00000020UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP2    ((UBase_t) 0x00000040UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP3    ((UBase_t) 0x00000060UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP4    ((UBase_t) 0x00000080UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP5    ((UBase_t) 0x000000A0UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP6    ((UBase_t) 0x000000C0UL)
#define NVIC_IPR13_R_NVIC_GPIOK_IP7    ((UBase_t) 0x000000E0UL)

#define NVIC_IPR13_NVIC_GPIOK_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR13_NVIC_GPIOK_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_NVIC_GPIOK_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR13_NVIC_GPIOK_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR13_NVIC_GPIOK_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR13_NVIC_GPIOK_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR13_NVIC_GPIOK_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR13_NVIC_GPIOK_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR13_NVIC_GPIOK_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

/*----------*/
#define NVIC_IPR13_R_NVIC_GPIOL_MASK    ((UBase_t) 0x0000E000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_BIT    (13UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP1    ((UBase_t) 0x00002000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP2    ((UBase_t) 0x00004000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP3    ((UBase_t) 0x00006000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP4    ((UBase_t) 0x00008000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP5    ((UBase_t) 0x0000A000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP6    ((UBase_t) 0x0000C000UL)
#define NVIC_IPR13_R_NVIC_GPIOL_IP7    ((UBase_t) 0x0000E000UL)

#define NVIC_IPR13_NVIC_GPIOL_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR13_NVIC_GPIOL_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_NVIC_GPIOL_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR13_NVIC_GPIOL_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR13_NVIC_GPIOL_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR13_NVIC_GPIOL_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR13_NVIC_GPIOL_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR13_NVIC_GPIOL_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR13_NVIC_GPIOL_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

/*----------*/
#define NVIC_IPR13_R_NVIC_SSI2_MASK    ((UBase_t) 0x00E00000UL)
#define NVIC_IPR13_R_NVIC_SSI2_BIT    (21UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP1    ((UBase_t) 0x00200000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP2    ((UBase_t) 0x00400000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP3    ((UBase_t) 0x00600000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP4    ((UBase_t) 0x00800000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP5    ((UBase_t) 0x00A00000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP6    ((UBase_t) 0x00C00000UL)
#define NVIC_IPR13_R_NVIC_SSI2_IP7    ((UBase_t) 0x00E00000UL)

#define NVIC_IPR13_NVIC_SSI2_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR13_NVIC_SSI2_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_NVIC_SSI2_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR13_NVIC_SSI2_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR13_NVIC_SSI2_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR13_NVIC_SSI2_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR13_NVIC_SSI2_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR13_NVIC_SSI2_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR13_NVIC_SSI2_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

/*----------*/
#define NVIC_IPR13_R_NVIC_SSI3_MASK    ((UBase_t) 0xE0000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_BIT    (29UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP1    ((UBase_t) 0x20000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP2    ((UBase_t) 0x40000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP3    ((UBase_t) 0x60000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP4    ((UBase_t) 0x80000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP5    ((UBase_t) 0xA0000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP6    ((UBase_t) 0xC0000000UL)
#define NVIC_IPR13_R_NVIC_SSI3_IP7    ((UBase_t) 0xE0000000UL)

#define NVIC_IPR13_NVIC_SSI3_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR13_NVIC_SSI3_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR13_NVIC_SSI3_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR13_NVIC_SSI3_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR13_NVIC_SSI3_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR13_NVIC_SSI3_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR13_NVIC_SSI3_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR13_NVIC_SSI3_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR13_NVIC_SSI3_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_NVIC_NVIC_PERIPHERAL_NVIC_REGISTER_NVIC_REGISTERDEFINES_NVIC_REGISTERDEFINES_IPR_NVIC_REGISTERDEFINES_IPR13_H_ */

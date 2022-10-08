/**
 *
 * @file NVIC_RegisterDefines_IPR23.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_NVIC_NVIC_PERIPHERAL_NVIC_REGISTER_NVIC_REGISTERDEFINES_NVIC_REGISTERDEFINES_IPR_NVIC_REGISTERDEFINES_IPR23_H_
#define XDRIVER_MCU_DRIVER_HEADER_NVIC_NVIC_PERIPHERAL_NVIC_REGISTER_NVIC_REGISTERDEFINES_NVIC_REGISTERDEFINES_IPR_NVIC_REGISTERDEFINES_IPR23_H_

#include <xDriver_MCU/Core/NVIC/Peripheral/xHeader/NVIC_Enum.h>

/********************************************************************************************/
/************************************* IPR23 ***********************************************/
/******************************************************************************************/

/*----------*/
#define NVIC_IPR23_R_NVIC_GPIOR_MASK    ((UBase_t) 0x000000E0UL)
#define NVIC_IPR23_R_NVIC_GPIOR_BIT    (5UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP1    ((UBase_t) 0x00000020UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP2    ((UBase_t) 0x00000040UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP3    ((UBase_t) 0x00000060UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP4    ((UBase_t) 0x00000080UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP5    ((UBase_t) 0x000000A0UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP6    ((UBase_t) 0x000000C0UL)
#define NVIC_IPR23_R_NVIC_GPIOR_IP7    ((UBase_t) 0x000000E0UL)

#define NVIC_IPR23_NVIC_GPIOR_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR23_NVIC_GPIOR_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_NVIC_GPIOR_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR23_NVIC_GPIOR_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR23_NVIC_GPIOR_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR23_NVIC_GPIOR_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR23_NVIC_GPIOR_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR23_NVIC_GPIOR_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR23_NVIC_GPIOR_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

/*----------*/
#define NVIC_IPR23_R_NVIC_GPIOS_MASK    ((UBase_t) 0x0000E000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_BIT    (13UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP1    ((UBase_t) 0x00002000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP2    ((UBase_t) 0x00004000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP3    ((UBase_t) 0x00006000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP4    ((UBase_t) 0x00008000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP5    ((UBase_t) 0x0000A000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP6    ((UBase_t) 0x0000C000UL)
#define NVIC_IPR23_R_NVIC_GPIOS_IP7    ((UBase_t) 0x0000E000UL)

#define NVIC_IPR23_NVIC_GPIOS_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR23_NVIC_GPIOS_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_NVIC_GPIOS_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR23_NVIC_GPIOS_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR23_NVIC_GPIOS_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR23_NVIC_GPIOS_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR23_NVIC_GPIOS_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR23_NVIC_GPIOS_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR23_NVIC_GPIOS_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

/*----------*/
#define NVIC_IPR23_R_NVIC_SHA_MD5_MASK    ((UBase_t) 0x00E00000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_BIT    (21UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP1    ((UBase_t) 0x00200000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP2    ((UBase_t) 0x00400000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP3    ((UBase_t) 0x00600000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP4    ((UBase_t) 0x00800000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP5    ((UBase_t) 0x00A00000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP6    ((UBase_t) 0x00C00000UL)
#define NVIC_IPR23_R_NVIC_SHA_MD5_IP7    ((UBase_t) 0x00E00000UL)

#define NVIC_IPR23_NVIC_SHA_MD5_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR23_NVIC_SHA_MD5_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

/*----------*/
#define NVIC_IPR23_R_NVIC_AES_MASK    ((UBase_t) 0xE0000000UL)
#define NVIC_IPR23_R_NVIC_AES_BIT    (29UL)
#define NVIC_IPR23_R_NVIC_AES_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP1    ((UBase_t) 0x20000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP2    ((UBase_t) 0x40000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP3    ((UBase_t) 0x60000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP4    ((UBase_t) 0x80000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP5    ((UBase_t) 0xA0000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP6    ((UBase_t) 0xC0000000UL)
#define NVIC_IPR23_R_NVIC_AES_IP7    ((UBase_t) 0xE0000000UL)

#define NVIC_IPR23_NVIC_AES_MASK    ((UBase_t) 0x00000007UL)
#define NVIC_IPR23_NVIC_AES_IP0    ((UBase_t) 0x00000000UL)
#define NVIC_IPR23_NVIC_AES_IP1    ((UBase_t) 0x00000001UL)
#define NVIC_IPR23_NVIC_AES_IP2    ((UBase_t) 0x00000002UL)
#define NVIC_IPR23_NVIC_AES_IP3    ((UBase_t) 0x00000003UL)
#define NVIC_IPR23_NVIC_AES_IP4    ((UBase_t) 0x00000004UL)
#define NVIC_IPR23_NVIC_AES_IP5    ((UBase_t) 0x00000005UL)
#define NVIC_IPR23_NVIC_AES_IP6    ((UBase_t) 0x00000006UL)
#define NVIC_IPR23_NVIC_AES_IP7    ((UBase_t) 0x00000007UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_NVIC_NVIC_PERIPHERAL_NVIC_REGISTER_NVIC_REGISTERDEFINES_NVIC_REGISTERDEFINES_IPR_NVIC_REGISTERDEFINES_IPR23_H_ */

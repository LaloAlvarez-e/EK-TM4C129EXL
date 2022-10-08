/**
 *
 * @file SYSCTL_RegisterDefines_SCGC_Legacy.h
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
 * @verbatim 24 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_SCGC_LEGACY_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_SCGC_LEGACY_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

/**********************************************************************************
************************************137 SCGC0 *********************************************
******************************************************************************************/
/*----------*/
#define SYSCTL_SCGC0_R_SCGCWDT0_MASK    ((UBase_t) 0x00000008UL)
#define SYSCTL_SCGC0_R_SCGCWDT0_BIT    (3UL)
#define SYSCTL_SCGC0_R_SCGCWDT0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCWDT0_CLOCK    ((UBase_t) 0x00000008UL)

#define SYSCTL_SCGC0_SCGCWDT0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCWDT0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCWDT0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCHIB_MASK    ((UBase_t) 0x00000040UL)
#define SYSCTL_SCGC0_R_SCGCHIB_BIT    (6UL)
#define SYSCTL_SCGC0_R_SCGCHIB_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCHIB_CLOCK    ((UBase_t) 0x00000040UL)

#define SYSCTL_SCGC0_SCGCHIB_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCHIB_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCHIB_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCMAXADC0SPD_MASK    ((UBase_t) 0x00000030UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC0SPD_BIT    (8UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC0SPD_125K    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC0SPD_250K    ((UBase_t) 0x00000010UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC0SPD_500K    ((UBase_t) 0x00000020UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC0SPD_1M    ((UBase_t) 0x00000030UL)

#define SYSCTL_SCGC0_SCGCMAXADC0SPD_MASK    ((UBase_t) 0x00000003UL)
#define SYSCTL_SCGC0_SCGCMAXADC0SPD_125K    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCMAXADC0SPD_250K    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCMAXADC0SPD_500K    ((UBase_t) 0x00000002UL)
#define SYSCTL_SCGC0_SCGCMAXADC0SPD_1M    ((UBase_t) 0x00000003UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCMAXADC1SPD_MASK    ((UBase_t) 0x000000C0UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC1SPD_BIT    (10UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC1SPD_125K    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC1SPD_250K    ((UBase_t) 0x00000040UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC1SPD_500K    ((UBase_t) 0x00000080UL)
#define SYSCTL_SCGC0_R_SCGCMAXADC1SPD_1M    ((UBase_t) 0x000000C0UL)

#define SYSCTL_SCGC0_SCGCMAXADC1SPD_MASK    ((UBase_t) 0x00000003UL)
#define SYSCTL_SCGC0_SCGCMAXADC1SPD_125K    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCMAXADC1SPD_250K    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCMAXADC1SPD_500K    ((UBase_t) 0x00000002UL)
#define SYSCTL_SCGC0_SCGCMAXADC1SPD_1M    ((UBase_t) 0x00000003UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCADC0_MASK    ((UBase_t) 0x00010000UL)
#define SYSCTL_SCGC0_R_SCGCADC0_BIT    (16UL)
#define SYSCTL_SCGC0_R_SCGCADC0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCADC0_CLOCK    ((UBase_t) 0x00010000UL)

#define SYSCTL_SCGC0_SCGCADC0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCADC0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCADC0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCADC1_MASK    ((UBase_t) 0x00020000UL)
#define SYSCTL_SCGC0_R_SCGCADC1_BIT    (17UL)
#define SYSCTL_SCGC0_R_SCGCADC1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCADC1_CLOCK    ((UBase_t) 0x00020000UL)

#define SYSCTL_SCGC0_SCGCADC1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCADC1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCADC1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCPWM0_MASK    ((UBase_t) 0x00100000UL)
#define SYSCTL_SCGC0_R_SCGCPWM0_BIT    (20UL)
#define SYSCTL_SCGC0_R_SCGCPWM0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCPWM0_CLOCK    ((UBase_t) 0x00100000UL)

#define SYSCTL_SCGC0_SCGCPWM0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCPWM0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCPWM0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCCAN0_MASK    ((UBase_t) 0x01000000UL)
#define SYSCTL_SCGC0_R_SCGCCAN0_BIT    (24UL)
#define SYSCTL_SCGC0_R_SCGCCAN0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCCAN0_CLOCK    ((UBase_t) 0x01000000UL)

#define SYSCTL_SCGC0_SCGCCAN0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCCAN0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCCAN0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCCAN1_MASK    ((UBase_t) 0x02000000UL)
#define SYSCTL_SCGC0_R_SCGCCAN1_BIT    (25UL)
#define SYSCTL_SCGC0_R_SCGCCAN1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCCAN1_CLOCK    ((UBase_t) 0x02000000UL)

#define SYSCTL_SCGC0_SCGCCAN1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCCAN1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCCAN1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC0_R_SCGCWDT1_MASK    ((UBase_t) 0x10000000UL)
#define SYSCTL_SCGC0_R_SCGCWDT1_BIT    (28UL)
#define SYSCTL_SCGC0_R_SCGCWDT1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_R_SCGCWDT1_CLOCK    ((UBase_t) 0x10000000UL)

#define SYSCTL_SCGC0_SCGCWDT1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC0_SCGCWDT1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC0_SCGCWDT1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/**********************************************************************************
************************************138 SCGC1 *********************************************
******************************************************************************************/
/*----------*/
#define SYSCTL_SCGC1_R_SCGCUART0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_R_SCGCUART0_BIT    (0UL)
#define SYSCTL_SCGC1_R_SCGCUART0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCUART0_CLOCK    ((UBase_t) 0x00000001UL)

#define SYSCTL_SCGC1_SCGCUART0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCUART0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCUART0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCUART1_MASK    ((UBase_t) 0x00000002UL)
#define SYSCTL_SCGC1_R_SCGCUART1_BIT    (1UL)
#define SYSCTL_SCGC1_R_SCGCUART1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCUART1_CLOCK    ((UBase_t) 0x00000002UL)

#define SYSCTL_SCGC1_SCGCUART1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCUART1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCUART1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCUART2_MASK    ((UBase_t) 0x00000004UL)
#define SYSCTL_SCGC1_R_SCGCUART2_BIT    (2UL)
#define SYSCTL_SCGC1_R_SCGCUART2_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCUART2_CLOCK    ((UBase_t) 0x00000004UL)

#define SYSCTL_SCGC1_SCGCUART2_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCUART2_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCUART2_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCSSI0_MASK    ((UBase_t) 0x00000010UL)
#define SYSCTL_SCGC1_R_SCGCSSI0_BIT    (4UL)
#define SYSCTL_SCGC1_R_SCGCSSI0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCSSI0_CLOCK    ((UBase_t) 0x00000010UL)

#define SYSCTL_SCGC1_SCGCSSI0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCSSI0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCSSI0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCSSI1_MASK    ((UBase_t) 0x00000020UL)
#define SYSCTL_SCGC1_R_SCGCSSI1_BIT    (5UL)
#define SYSCTL_SCGC1_R_SCGCSSI1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCSSI1_CLOCK    ((UBase_t) 0x00000010UL)

#define SYSCTL_SCGC1_SCGCSSI1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCSSI1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCSSI1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCQEI0_MASK    ((UBase_t) 0x00000100UL)
#define SYSCTL_SCGC1_R_SCGCQEI0_BIT    (8UL)
#define SYSCTL_SCGC1_R_SCGCQEI0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCQEI0_CLOCK    ((UBase_t) 0x00000100UL)

#define SYSCTL_SCGC1_SCGCQEI0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCQEI0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCQEI0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCQEI1_MASK    ((UBase_t) 0x00000200UL)
#define SYSCTL_SCGC1_R_SCGCQEI1_BIT    (9UL)
#define SYSCTL_SCGC1_R_SCGCQEI1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCQEI1_CLOCK    ((UBase_t) 0x00000200UL)

#define SYSCTL_SCGC1_SCGCQEI1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCQEI1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCQEI1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCI2C0_MASK    ((UBase_t) 0x00001000UL)
#define SYSCTL_SCGC1_R_SCGCI2C0_BIT    (12UL)
#define SYSCTL_SCGC1_R_SCGCI2C0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCI2C0_CLOCK    ((UBase_t) 0x00001000UL)

#define SYSCTL_SCGC1_SCGCI2C0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCI2C0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCI2C0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCI2C1_MASK    ((UBase_t) 0x00004000UL)
#define SYSCTL_SCGC1_R_SCGCI2C1_BIT    (14UL)
#define SYSCTL_SCGC1_R_SCGCI2C1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCI2C1_CLOCK    ((UBase_t) 0x00004000UL)

#define SYSCTL_SCGC1_SCGCI2C1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCI2C1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCI2C1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCTIMER0_MASK    ((UBase_t) 0x00010000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER0_BIT    (16UL)
#define SYSCTL_SCGC1_R_SCGCTIMER0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER0_CLOCK    ((UBase_t) 0x00010000UL)

#define SYSCTL_SCGC1_SCGCTIMER0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCTIMER0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCTIMER0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCTIMER1_MASK    ((UBase_t) 0x00020000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER1_BIT    (17UL)
#define SYSCTL_SCGC1_R_SCGCTIMER1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER1_CLOCK    ((UBase_t) 0x00020000UL)

#define SYSCTL_SCGC1_SCGCTIMER1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCTIMER1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCTIMER1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCTIMER2_MASK    ((UBase_t) 0x00040000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER2_BIT    (18UL)
#define SYSCTL_SCGC1_R_SCGCTIMER2_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER2_CLOCK    ((UBase_t) 0x00040000UL)

#define SYSCTL_SCGC1_SCGCTIMER2_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCTIMER2_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCTIMER2_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCTIMER3_MASK    ((UBase_t) 0x00080000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER3_BIT    (19UL)
#define SYSCTL_SCGC1_R_SCGCTIMER3_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCTIMER3_CLOCK    ((UBase_t) 0x00080000UL)

#define SYSCTL_SCGC1_SCGCTIMER3_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCTIMER3_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCTIMER3_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/


/*----------*/
#define SYSCTL_SCGC1_R_SCGCCOMP0_MASK    ((UBase_t) 0x01000000UL)
#define SYSCTL_SCGC1_R_SCGCCOMP0_BIT    (24UL)
#define SYSCTL_SCGC1_R_SCGCCOMP0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCCOMP0_CLOCK    ((UBase_t) 0x01000000UL)

#define SYSCTL_SCGC1_SCGCCOMP0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCCOMP0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCCOMP0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC1_R_SCGCCOMP1_MASK    ((UBase_t) 0x02000000UL)
#define SYSCTL_SCGC1_R_SCGCCOMP1_BIT    (25UL)
#define SYSCTL_SCGC1_R_SCGCCOMP1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_R_SCGCCOMP1_CLOCK    ((UBase_t) 0x02000000UL)

#define SYSCTL_SCGC1_SCGCCOMP1_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC1_SCGCCOMP1_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC1_SCGCCOMP1_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/**********************************************************************************
************************************139 SCGC2 *********************************************
******************************************************************************************/
/*----------*/
#define SYSCTL_SCGC2_R_SCGCGPIOA_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_R_SCGCGPIOA_BIT    (0UL)
#define SYSCTL_SCGC2_R_SCGCGPIOA_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCGPIOA_CLOCK    ((UBase_t) 0x00000001UL)

#define SYSCTL_SCGC2_SCGCGPIOA_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCGPIOA_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCGPIOA_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCGPIOB_MASK    ((UBase_t) 0x00000002UL)
#define SYSCTL_SCGC2_R_SCGCGPIOB_BIT    (1UL)
#define SYSCTL_SCGC2_R_SCGCGPIOB_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCGPIOB_CLOCK    ((UBase_t) 0x00000002UL)

#define SYSCTL_SCGC2_SCGCGPIOB_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCGPIOB_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCGPIOB_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCGPIOC_MASK    ((UBase_t) 0x00000004UL)
#define SYSCTL_SCGC2_R_SCGCGPIOC_BIT    (2UL)
#define SYSCTL_SCGC2_R_SCGCGPIOC_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCGPIOC_CLOCK    ((UBase_t) 0x00000004UL)

#define SYSCTL_SCGC2_SCGCGPIOC_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCGPIOC_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCGPIOC_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCGPIOD_MASK    ((UBase_t) 0x00000008UL)
#define SYSCTL_SCGC2_R_SCGCGPIOD_BIT    (3UL)
#define SYSCTL_SCGC2_R_SCGCGPIOD_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCGPIOD_CLOCK    ((UBase_t) 0x00000008UL)

#define SYSCTL_SCGC2_SCGCGPIOD_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCGPIOD_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCGPIOD_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCGPIOE_MASK    ((UBase_t) 0x00000010UL)
#define SYSCTL_SCGC2_R_SCGCGPIOE_BIT    (4UL)
#define SYSCTL_SCGC2_R_SCGCGPIOE_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCGPIOE_CLOCK    ((UBase_t) 0x00000010UL)

#define SYSCTL_SCGC2_SCGCGPIOE_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCGPIOE_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCGPIOE_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCGPIOF_MASK    ((UBase_t) 0x00000020UL)
#define SYSCTL_SCGC2_R_SCGCGPIOF_BIT    (5UL)
#define SYSCTL_SCGC2_R_SCGCGPIOF_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCGPIOF_CLOCK    ((UBase_t) 0x00000020UL)

#define SYSCTL_SCGC2_SCGCGPIOF_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCGPIOF_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCGPIOF_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCUDMA_MASK    ((UBase_t) 0x00002000UL)
#define SYSCTL_SCGC2_R_SCGCUDMA_BIT    (13UL)
#define SYSCTL_SCGC2_R_SCGCUDMA_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCUDMA_CLOCK    ((UBase_t) 0x00002000UL)

#define SYSCTL_SCGC2_SCGCUDMA_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCUDMA_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCUDMA_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSCTL_SCGC2_R_SCGCUSB0_MASK    ((UBase_t) 0x00010000UL)
#define SYSCTL_SCGC2_R_SCGCUSB0_BIT    (16UL)
#define SYSCTL_SCGC2_R_SCGCUSB0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_R_SCGCUSB0_CLOCK    ((UBase_t) 0x00010000UL)

#define SYSCTL_SCGC2_SCGCUSB0_MASK    ((UBase_t) 0x00000001UL)
#define SYSCTL_SCGC2_SCGCUSB0_UNCLOCK    ((UBase_t) 0x00000000UL)
#define SYSCTL_SCGC2_SCGCUSB0_CLOCK    ((UBase_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_SCGC_LEGACY_H_ */

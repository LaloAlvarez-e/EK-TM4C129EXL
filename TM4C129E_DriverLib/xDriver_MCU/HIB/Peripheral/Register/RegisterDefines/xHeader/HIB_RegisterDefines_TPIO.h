/**
 *
 * @file HIB_RegisterDefines_TPIO.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPIO_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPIO_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 23 TPIO *********************************************
******************************************************************************************/
/*--------*/
#define HIB_TPIO_R_GFLTR3_MASK    ((UBase_t) 0x08000000UL)
#define HIB_TPIO_R_GFLTR3_BIT    ((UBase_t) 27UL)
#define HIB_TPIO_R_GFLTR3_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_GFLTR3_LONG    ((UBase_t) 0x08000000UL)

#define HIB_TPIO_GFLTR3_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_GFLTR3_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_GFLTR3_LONG    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_PUEN3_MASK    ((UBase_t) 0x04000000UL)
#define HIB_TPIO_R_PUEN3_BIT    ((UBase_t) 26UL)
#define HIB_TPIO_R_PUEN3_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_PUEN3_ENA    ((UBase_t) 0x04000000UL)

#define HIB_TPIO_PUEN3_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_PUEN3_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_PUEN3_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_LEV3_MASK    ((UBase_t) 0x02000000UL)
#define HIB_TPIO_R_LEV3_BIT    ((UBase_t) 25UL)
#define HIB_TPIO_R_LEV3_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_LEV3_HIGH    ((UBase_t) 0x02000000UL)

#define HIB_TPIO_LEV3_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_LEV3_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_LEV3_HIGH    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_EN3_MASK    ((UBase_t) 0x01000000UL)
#define HIB_TPIO_R_EN3_BIT    ((UBase_t) 24UL)
#define HIB_TPIO_R_EN3_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_EN3_ENA    ((UBase_t) 0x01000000UL)

#define HIB_TPIO_EN3_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_EN3_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_EN3_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_GFLTR2_MASK    ((UBase_t) 0x00080000UL)
#define HIB_TPIO_R_GFLTR2_BIT    ((UBase_t) 19UL)
#define HIB_TPIO_R_GFLTR2_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_GFLTR2_LONG    ((UBase_t) 0x00080000UL)

#define HIB_TPIO_GFLTR2_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_GFLTR2_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_GFLTR2_LONG    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_PUEN2_MASK    ((UBase_t) 0x00040000UL)
#define HIB_TPIO_R_PUEN2_BIT    ((UBase_t) 18UL)
#define HIB_TPIO_R_PUEN2_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_PUEN2_ENA    ((UBase_t) 0x00040000UL)

#define HIB_TPIO_PUEN2_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_PUEN2_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_PUEN2_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_LEV2_MASK    ((UBase_t) 0x00020000UL)
#define HIB_TPIO_R_LEV2_BIT    ((UBase_t) 17UL)
#define HIB_TPIO_R_LEV2_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_LEV2_HIGH    ((UBase_t) 0x00020000UL)

#define HIB_TPIO_LEV2_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_LEV2_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_LEV2_HIGH    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_EN2_MASK    ((UBase_t) 0x00010000UL)
#define HIB_TPIO_R_EN2_BIT    ((UBase_t) 16UL)
#define HIB_TPIO_R_EN2_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_EN2_ENA    ((UBase_t) 0x00010000UL)

#define HIB_TPIO_EN2_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_EN2_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_EN2_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_GFLTR1_MASK    ((UBase_t) 0x00000800UL)
#define HIB_TPIO_R_GFLTR1_BIT    ((UBase_t) 11UL)
#define HIB_TPIO_R_GFLTR1_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_GFLTR1_LONG    ((UBase_t) 0x00000800UL)

#define HIB_TPIO_GFLTR1_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_GFLTR1_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_GFLTR1_LONG    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_PUEN1_MASK    ((UBase_t) 0x00000400UL)
#define HIB_TPIO_R_PUEN1_BIT    ((UBase_t) 10UL)
#define HIB_TPIO_R_PUEN1_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_PUEN1_ENA    ((UBase_t) 0x00000400UL)

#define HIB_TPIO_PUEN1_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_PUEN1_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_PUEN1_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_LEV1_MASK    ((UBase_t) 0x00000200UL)
#define HIB_TPIO_R_LEV1_BIT    ((UBase_t) 9UL)
#define HIB_TPIO_R_LEV1_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_LEV1_HIGH    ((UBase_t) 0x00000200UL)

#define HIB_TPIO_LEV1_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_LEV1_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_LEV1_HIGH    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_EN1_MASK    ((UBase_t) 0x00000100UL)
#define HIB_TPIO_R_EN1_BIT    ((UBase_t) 8UL)
#define HIB_TPIO_R_EN1_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_EN1_ENA    ((UBase_t) 0x00000100UL)

#define HIB_TPIO_EN1_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_EN1_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_EN1_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_GFLTR0_MASK    ((UBase_t) 0x00000008UL)
#define HIB_TPIO_R_GFLTR0_BIT    ((UBase_t) 3UL)
#define HIB_TPIO_R_GFLTR0_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_GFLTR0_LONG    ((UBase_t) 0x00000008UL)

#define HIB_TPIO_GFLTR0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_GFLTR0_SHORT    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_GFLTR0_LONG    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_PUEN0_MASK    ((UBase_t) 0x00000004UL)
#define HIB_TPIO_R_PUEN0_BIT    ((UBase_t) 2UL)
#define HIB_TPIO_R_PUEN0_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_PUEN0_ENA    ((UBase_t) 0x00000004UL)

#define HIB_TPIO_PUEN0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_PUEN0_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_PUEN0_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_LEV0_MASK    ((UBase_t) 0x00000002UL)
#define HIB_TPIO_R_LEV0_BIT    ((UBase_t) 1UL)
#define HIB_TPIO_R_LEV0_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_LEV0_HIGH    ((UBase_t) 0x00000002UL)

#define HIB_TPIO_LEV0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_LEV0_LOW    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_LEV0_HIGH    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPIO_R_EN0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_R_EN0_BIT    ((UBase_t) 0UL)
#define HIB_TPIO_R_EN0_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_R_EN0_ENA    ((UBase_t) 0x00000001UL)

#define HIB_TPIO_EN0_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPIO_EN0_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPIO_EN0_ENA    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPIO_H_ */

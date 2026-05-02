/**
 *
 * @file HIB_RegisterDefines_TPSTAT.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPSTAT_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPSTAT_H_

#include <xDriver_MCU/HIB/Peripheral/xHeader/HIB_Enum.h>

/******************************************************************************************
************************************ 22 TPSTAT *******************************************
******************************************************************************************/
/*--------*/
#define HIB_TPSTAT_R_STATE_MASK    ((UBase_t) 0x0000000CUL)
#define HIB_TPSTAT_R_STATE_BIT    ((UBase_t) 2UL)
#define HIB_TPSTAT_R_STATE_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPSTAT_R_STATE_CONFIG    ((UBase_t) 0x00000004UL)
#define HIB_TPSTAT_R_STATE_EVENT    ((UBase_t) 0x00000008UL)

#define HIB_TPSTAT_STATE_MASK    ((UBase_t) 0x00000003UL)
#define HIB_TPSTAT_STATE_DIS    ((UBase_t) 0x00000000UL)
#define HIB_TPSTAT_STATE_CONFIG    ((UBase_t) 0x00000001UL)
#define HIB_TPSTAT_STATE_EVENT    ((UBase_t) 0x00000002UL)
/*--------*/

/*--------*/
#define HIB_TPSTAT_R_XOSCST_MASK    ((UBase_t) 0x00000002UL)
#define HIB_TPSTAT_R_XOSCST_BIT    ((UBase_t) 1UL)
#define HIB_TPSTAT_R_XOSCST_ACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_TPSTAT_R_XOSCST_STOPPED    ((UBase_t) 0x00000002UL)

#define HIB_TPSTAT_XOSCST_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPSTAT_XOSCST_ACTIVE    ((UBase_t) 0x00000000UL)
#define HIB_TPSTAT_XOSCST_STOPPED    ((UBase_t) 0x00000001UL)
/*--------*/

/*--------*/
#define HIB_TPSTAT_R_XOSCFAIL_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPSTAT_R_XOSCFAIL_BIT    ((UBase_t) 0UL)
#define HIB_TPSTAT_R_XOSCFAIL_NOFAIL    ((UBase_t) 0x00000000UL)
#define HIB_TPSTAT_R_XOSCFAIL_FAIL    ((UBase_t) 0x00000001UL)

#define HIB_TPSTAT_XOSCFAIL_MASK    ((UBase_t) 0x00000001UL)
#define HIB_TPSTAT_XOSCFAIL_NOFAIL    ((UBase_t) 0x00000000UL)
#define HIB_TPSTAT_XOSCFAIL_FAIL    ((UBase_t) 0x00000001UL)
/*--------*/

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERDEFINES_XHEADER_HIB_REGISTERDEFINES_TPSTAT_H_ */

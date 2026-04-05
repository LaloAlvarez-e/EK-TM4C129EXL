/**
 *
 * @file SYSCTL_RegisterDefines_LDO.h
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

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_LDO_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_LDO_H_

#include <xDriver_MCU/SYSCTL/Peripheral/xHeader/SYSCTL_Enum.h>

/******************************************************************************************
************************************21 LDOSPCTL *********************************************
******************************************************************************************/
/*--------*/
#define LDO_SPCTL_R_VLDO_MASK    ((UBase_t) 0x000000FFUL)
#define LDO_SPCTL_R_VLDO_BIT    (0UL)

#define LDO_SPCTL_VLDO_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define LDO_SPCTL_R_VADJEN_MASK    ((UBase_t) 0x80000000UL)
#define LDO_SPCTL_R_VADJEN_BIT    (31UL)

#define LDO_SPCTL_VADJEN_MASK    ((UBase_t) 0x00000001UL)
/*--------*/

/******************************************************************************************
************************************22 LDOSPCAL *********************************************
******************************************************************************************/
/*--------*/
#define LDO_SPCAL_R_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
#define LDO_SPCAL_R_NOPLL_BIT    (0UL)

#define LDO_SPCAL_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define LDO_SPCAL_R_WITHPLL_MASK    ((UBase_t) 0x0000FF00UL)
#define LDO_SPCAL_R_WITHPLL_BIT    (8UL)

#define LDO_SPCAL_WITHPLL_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/******************************************************************************************
************************************23 LDODPCTL *********************************************
******************************************************************************************/
/*--------*/
#define LDO_DPCTL_R_VLDO_MASK    ((UBase_t) 0x000000FFUL)
#define LDO_DPCTL_R_VLDO_BIT    (0UL)

#define LDO_DPCTL_VLDO_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define LDO_DPCTL_R_VADJEN_MASK    ((UBase_t) 0x80000000UL)
#define LDO_DPCTL_R_VADJEN_BIT    (31UL)

#define LDO_DPCTL_VADJEN_MASK    ((UBase_t) 0x00000001UL)
/*--------*/

/******************************************************************************************
************************************24 LDODPCAL *********************************************
******************************************************************************************/
/*--------*/
#define LDO_DPCAL_R_KHZ30_MASK    ((UBase_t) 0x000000FFUL)
#define LDO_DPCAL_R_KHZ30_BIT    (0UL)

#define LDO_DPCAL_KHZ30_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/
/*--------*/
#define LDO_DPCAL_R_NOPLL_MASK    ((UBase_t) 0x0000FF00UL)
#define LDO_DPCAL_R_NOPLL_BIT    (8UL)

#define LDO_DPCAL_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_LDO_H_ */

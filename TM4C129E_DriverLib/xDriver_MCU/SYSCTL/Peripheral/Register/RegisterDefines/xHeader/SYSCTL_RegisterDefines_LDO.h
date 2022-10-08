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
#define SYSCTL_LDOSPCTL_R_VLDO_MASK    ((UBase_t) 0x000000FFUL)
#define SYSCTL_LDOSPCTL_R_VLDO_BIT    (0UL)

#define SYSCTL_LDOSPCTL_VLDO_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define SYSCTL_LDOSPCTL_R_VADJEN_MASK    ((UBase_t) 0x80000000UL)
#define SYSCTL_LDOSPCTL_R_VADJEN_BIT    (31UL)

#define SYSCTL_LDOSPCTL_VADJEN_MASK    ((UBase_t) 0x000000F01UL)
/*--------*/

/******************************************************************************************
************************************22 LDOSPCAL *********************************************
******************************************************************************************/
/*--------*/
#define SYSCTL_LDOSPCAL_R_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
#define SYSCTL_LDOSPCAL_R_NOPLL_BIT    (0UL)

#define SYSCTL_LDOSPCAL_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define SYSCTL_LDOSPCAL_R_WITHPLL_MASK    ((UBase_t) 0x0000FF00UL)
#define SYSCTL_LDOSPCAL_R_WITHPLL_BIT    (8UL)

#define SYSCTL_LDOSPCAL_WITHPLL_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/******************************************************************************************
************************************23 LDODPCTL *********************************************
******************************************************************************************/
/*--------*/
#define SYSCTL_LDODPCTL_R_VLDO_MASK    ((UBase_t) 0x000000FFUL)
#define SYSCTL_LDODPCTL_R_VLDO_BIT    (0UL)

#define SYSCTL_LDODPCTL_VLDO_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define SYSCTL_LDODPCTL_R_VADJEN_MASK    ((UBase_t) 0x80000000UL)
#define SYSCTL_LDODPCTL_R_VADJEN_BIT    (31UL)

#define SYSCTL_LDODPCTL_VADJEN_MASK    ((UBase_t) 0x000000F01UL)
/*--------*/

/******************************************************************************************
************************************24 LDODPCAL *********************************************
******************************************************************************************/
/*--------*/
#define SYSCTL_LDODPCAL_R_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
#define SYSCTL_LDODPCAL_R_NOPLL_BIT    (0UL)

#define SYSCTL_LDODPCAL_NOPLL_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

/*--------*/
#define SYSCTL_LDODPCAL_R_KHZ30_MASK    ((UBase_t) 0x0000FF00UL)
#define SYSCTL_LDODPCAL_R_KHZ30_BIT    (8UL)

#define SYSCTL_LDODPCAL_KHZ30_MASK    ((UBase_t) 0x000000FFUL)
/*--------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSCTL_SYSCTL_PERIPHERAL_SYSCTL_REGISTER_SYSCTL_REGISTERDEFINES_SYSCTL_REGISTERDEFINES_LDO_H_ */

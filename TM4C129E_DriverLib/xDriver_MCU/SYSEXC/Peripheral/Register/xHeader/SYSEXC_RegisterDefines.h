/**
 *
 * @file SYSEXC_RegisterDefines.h
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
 * Date           Author     Version     Description
 * 22 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_DRIVER_HEADER_SYSEXC_SYSEXC_PERIPHERAL_SYSEXC_REGISTER_SYSEXC_REGISTERDEFINES_H_
#define XDRIVER_MCU_DRIVER_HEADER_SYSEXC_SYSEXC_PERIPHERAL_SYSEXC_REGISTER_SYSEXC_REGISTERDEFINES_H_

#include <xDriver_MCU/SYSEXC/Peripheral/xHeader/SYSEXC_Enum.h>

/******************************************************************************************
************************************ 1 RIS *********************************************
******************************************************************************************/
/*----------*/
#define SYSEXC_RIS_R_FPIDC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_R_FPIDC_BIT    (0UL)
#define SYSEXC_RIS_R_FPIDC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_R_FPIDC_ACTIVE    ((UBase_t) 0x00000001UL)

#define SYSEXC_RIS_FPIDC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_FPIDC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_FPIDC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_RIS_R_FPDZC_MASK    ((UBase_t) 0x00000002UL)
#define SYSEXC_RIS_R_FPDZC_BIT    (1UL)
#define SYSEXC_RIS_R_FPDZC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_R_FPDZC_ACTIVE    ((UBase_t) 0x00000002UL)

#define SYSEXC_RIS_FPDZC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_FPDZC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_FPDZC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_RIS_R_FPIOC_MASK    ((UBase_t) 0x00000004UL)
#define SYSEXC_RIS_R_FPIOC_BIT    (2UL)
#define SYSEXC_RIS_R_FPIOC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_R_FPIOC_ACTIVE    ((UBase_t) 0x00000004UL)

#define SYSEXC_RIS_FPIOC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_FPIOC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_FPIOC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_RIS_R_FPUFC_MASK    ((UBase_t) 0x00000008UL)
#define SYSEXC_RIS_R_FPUFC_BIT    (3UL)
#define SYSEXC_RIS_R_FPUFC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_R_FPUFC_ACTIVE    ((UBase_t) 0x00000008UL)

#define SYSEXC_RIS_FPUFC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_FPUFC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_FPUFC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_RIS_R_FPOFC_MASK    ((UBase_t) 0x00000010UL)
#define SYSEXC_RIS_R_FPOFC_BIT    (4UL)
#define SYSEXC_RIS_R_FPOFC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_R_FPOFC_ACTIVE    ((UBase_t) 0x00000010UL)

#define SYSEXC_RIS_FPOFC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_FPOFC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_FPOFC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_RIS_R_FPIXC_MASK    ((UBase_t) 0x00000020UL)
#define SYSEXC_RIS_R_FPIXC_BIT    (5UL)
#define SYSEXC_RIS_R_FPIXC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_R_FPIXC_ACTIVE    ((UBase_t) 0x00000020UL)

#define SYSEXC_RIS_FPIXC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_RIS_FPIXC_NOACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_RIS_FPIXC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/******************************************************************************************
************************************ 2 IM *********************************************
******************************************************************************************/
/*----------*/
#define SYSEXC_IM_R_FPIDC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_R_FPIDC_BIT    ((UBase_t) 0)
#define SYSEXC_IM_R_FPIDC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_R_FPIDC_ENA    ((UBase_t) 0x00000001UL)

#define SYSEXC_IM_FPIDC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_FPIDC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_FPIDC_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IM_R_FPDZC_MASK    ((UBase_t) 0x00000002UL)
#define SYSEXC_IM_R_FPDZC_BIT    ((UBase_t) 1)
#define SYSEXC_IM_R_FPDZC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_R_FPDZC_ENA    ((UBase_t) 0x00000002UL)

#define SYSEXC_IM_FPDZC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_FPDZC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_FPDZC_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IM_R_FPIOC_MASK    ((UBase_t) 0x00000004UL)
#define SYSEXC_IM_R_FPIOC_BIT    (2UL)
#define SYSEXC_IM_R_FPIOC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_R_FPIOC_ENA    ((UBase_t) 0x00000004UL)

#define SYSEXC_IM_FPIOC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_FPIOC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_FPIOC_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IM_R_FPUFC_MASK    ((UBase_t) 0x00000008UL)
#define SYSEXC_IM_R_FPUFC_BIT    (3UL)
#define SYSEXC_IM_R_FPUFC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_R_FPUFC_ENA    ((UBase_t) 0x00000008UL)

#define SYSEXC_IM_FPUFC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_FPUFC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_FPUFC_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IM_R_FPOFC_MASK    ((UBase_t) 0x00000010UL)
#define SYSEXC_IM_R_FPOFC_BIT    (4UL)
#define SYSEXC_IM_R_FPOFC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_R_FPOFC_ENA    ((UBase_t) 0x00000010UL)

#define SYSEXC_IM_FPOFC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_FPOFC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_FPOFC_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IM_R_FPIXC_MASK    ((UBase_t) 0x00000020UL)
#define SYSEXC_IM_R_FPIXC_BIT    (5UL)
#define SYSEXC_IM_R_FPIXC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_R_FPIXC_ENA    ((UBase_t) 0x00000020UL)

#define SYSEXC_IM_FPIXC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IM_FPIXC_DIS    ((UBase_t) 0x00000000UL)
#define SYSEXC_IM_FPIXC_ENA    ((UBase_t) 0x00000001UL)
/*----------*/

/******************************************************************************************
************************************ 3 MIS *********************************************
******************************************************************************************/
/*----------*/
#define SYSEXC_MIS_R_FPIDC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_R_FPIDC_BIT    (0UL)
#define SYSEXC_MIS_R_FPIDC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_R_FPIDC_ACTIVE    ((UBase_t) 0x00000001UL)

#define SYSEXC_MIS_FPIDC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_FPIDC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_FPIDC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_MIS_R_FPDZC_MASK    ((UBase_t) 0x00000002UL)
#define SYSEXC_MIS_R_FPDZC_BIT    (1UL)
#define SYSEXC_MIS_R_FPDZC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_R_FPDZC_ACTIVE    ((UBase_t) 0x00000002UL)

#define SYSEXC_MIS_FPDZC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_FPDZC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_FPDZC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_MIS_R_FPIOC_MASK    ((UBase_t) 0x00000004UL)
#define SYSEXC_MIS_R_FPIOC_BIT    (2UL)
#define SYSEXC_MIS_R_FPIOC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_R_FPIOC_ACTIVE    ((UBase_t) 0x00000004UL)

#define SYSEXC_MIS_FPIOC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_FPIOC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_FPIOC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_MIS_R_FPUFC_MASK    ((UBase_t) 0x00000008UL)
#define SYSEXC_MIS_R_FPUFC_BIT    (3UL)
#define SYSEXC_MIS_R_FPUFC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_R_FPUFC_ACTIVE    ((UBase_t) 0x00000008UL)

#define SYSEXC_MIS_FPUFC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_FPUFC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_FPUFC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_MIS_R_FPOFC_MASK    ((UBase_t) 0x00000010UL)
#define SYSEXC_MIS_R_FPOFC_BIT    (4UL)
#define SYSEXC_MIS_R_FPOFC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_R_FPOFC_ACTIVE    ((UBase_t) 0x00000010UL)

#define SYSEXC_MIS_FPOFC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_FPOFC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_FPOFC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_MIS_R_FPIXC_MASK    ((UBase_t) 0x00000020UL)
#define SYSEXC_MIS_R_FPIXC_BIT    (5UL)
#define SYSEXC_MIS_R_FPIXC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_R_FPIXC_ACTIVE    ((UBase_t) 0x00000020UL)

#define SYSEXC_MIS_FPIXC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_MIS_FPIXC_INACTIVE    ((UBase_t) 0x00000000UL)
#define SYSEXC_MIS_FPIXC_ACTIVE    ((UBase_t) 0x00000001UL)
/*----------*/

/******************************************************************************************
************************************ 4 IC *********************************************
******************************************************************************************/
/*----------*/
#define SYSEXC_IC_R_FPIDCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_R_FPIDCIC_BIT    (0UL)
#define SYSEXC_IC_R_FPIDCIC_CLEAR    ((UBase_t) 0x00000001UL)

#define SYSEXC_IC_FPIDCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_FPIDCIC_CLEAR    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IC_R_FPDZCIC_MASK    ((UBase_t) 0x00000002UL)
#define SYSEXC_IC_R_FPDZCIC_BIT    (1UL)
#define SYSEXC_IC_R_FPDZCIC_CLEAR    ((UBase_t) 0x00000002UL)

#define SYSEXC_IC_FPDZCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_FPDZCIC_CLEAR    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IC_R_FPIOCIC_MASK    ((UBase_t) 0x00000004UL)
#define SYSEXC_IC_R_FPIOCIC_BIT    (2UL)
#define SYSEXC_IC_R_FPIOCIC_CLEAR    ((UBase_t) 0x00000004UL)

#define SYSEXC_IC_FPIOCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_FPIOCIC_CLEAR    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IC_R_FPUFCIC_MASK    ((UBase_t) 0x00000008UL)
#define SYSEXC_IC_R_FPUFCIC_BIT    (3UL)
#define SYSEXC_IC_R_FPUFCIC_CLEAR    ((UBase_t) 0x00000008UL)

#define SYSEXC_IC_FPUFCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_FPUFCIC_CLEAR    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IC_R_FPOFCIC_MASK    ((UBase_t) 0x00000010UL)
#define SYSEXC_IC_R_FPOFCIC_BIT    (4UL)
#define SYSEXC_IC_R_FPOFCIC_CLEAR    ((UBase_t) 0x00000010UL)

#define SYSEXC_IC_FPOFCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_FPOFCIC_CLEAR    ((UBase_t) 0x00000001UL)
/*----------*/

/*----------*/
#define SYSEXC_IC_R_FPIXCIC_MASK    ((UBase_t) 0x00000020UL)
#define SYSEXC_IC_R_FPIXCIC_BIT    (5UL)
#define SYSEXC_IC_R_FPIXCIC_CLEAR    ((UBase_t) 0x00000020UL)

#define SYSEXC_IC_FPIXCIC_MASK    ((UBase_t) 0x00000001UL)
#define SYSEXC_IC_FPIXCIC_CLEAR    ((UBase_t) 0x00000001UL)
/*----------*/

#endif /* XDRIVER_MCU_DRIVER_HEADER_SYSEXC_SYSEXC_PERIPHERAL_SYSEXC_REGISTER_SYSEXC_REGISTERDEFINES_H_ */

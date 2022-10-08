/**
 *
 * @file ACMP_RegisterAddress.h
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
 * @verbatim 28 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#ifndef XDRIVER_MCU_ACMP_PERIPHERAL_REGISTER_XHEADER_ACMP_REGISTERADDRESS_H_
#define XDRIVER_MCU_ACMP_PERIPHERAL_REGISTER_XHEADER_ACMP_REGISTERADDRESS_H_

#include <xDriver_MCU/ACMP/Peripheral/xHeader/ACMP_Enum.h>

#define ACMP_COMP_REGISTER_NUM    ((UBase_t) 8UL)

#define ACMP_BASE    ((UBase_t) 0x4003C000UL)
#define ACMP0_BASE    ((UBase_t) 0x4003C000UL)

#define ACMP_OFFSET    ((UBase_t) 0x0003C000UL)
#define ACMP0_OFFSET    ((UBase_t) 0x0003C000UL)

#define ACMP_BITBANDING_BASE    ((UBase_t) 0x42000000UL)

#define ACMP_MIS_OFFSET    ((UBase_t) 0x0000UL)
#define ACMP_RIS_OFFSET    ((UBase_t) 0x0004UL)
#define ACMP_INTEN_OFFSET    ((UBase_t) 0x0008UL)
#define ACMP_REFCTL_OFFSET    ((UBase_t) 0x0010UL)
#define ACMP_STAT_OFFSET    ((UBase_t) 0x0020UL)
#define ACMP_CTL_OFFSET    ((UBase_t) 0x0024UL)
#define ACMP_STAT0_OFFSET    ((UBase_t) 0x0020UL)
#define ACMP_CTL0_OFFSET    ((UBase_t) 0x0024UL)
#define ACMP_STAT1_OFFSET    ((UBase_t) 0x0040UL)
#define ACMP_CTL1_OFFSET    ((UBase_t) 0x0044UL)
#define ACMP_STAT2_OFFSET    ((UBase_t) 0x0060UL)
#define ACMP_CTL2_OFFSET    ((UBase_t) 0x0064UL)
#define ACMP_PP_OFFSET    ((UBase_t) 0x0FC0UL)

#endif /* XDRIVER_MCU_ACMP_PERIPHERAL_REGISTER_XHEADER_ACMP_REGISTERADDRESS_H_ */

/**
 *
 * @file SYSCTL_InterruptVector.h
 * @copyright
 * @verbatim InDeviceMex 2021 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 12 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XAPPLICATION_MCU_SYSCTL_INTERRUPT_XHEADER_SYSCTL_INTERRUPTVECTOR_H_
#define XAPPLICATION_MCU_SYSCTL_INTERRUPT_XHEADER_SYSCTL_INTERRUPTVECTOR_H_

#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Defines.h>

SYSCTL_nERROR SYSCTL__enEnableInterruptVector(SYSCTL_nPRIORITY enSYSCTLPriority);
SYSCTL_nERROR SYSCTL__enDisableInterruptVector(void);

#endif /* XAPPLICATION_MCU_SYSCTL_INTERRUPT_XHEADER_SYSCTL_INTERRUPTVECTOR_H_ */

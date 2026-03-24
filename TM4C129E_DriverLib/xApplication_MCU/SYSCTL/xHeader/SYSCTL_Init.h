/**
 *
 * @file SYSCTL_Init.h
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
 * @verbatim 24 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author         Version     Description
 * 24 mar. 2026   InDeviceMex    1.0         initial Version@endverbatim
 */
#ifndef XAPPLICATION_MCU_SYSCTL_XHEADER_SYSCTL_INIT_H_
#define XAPPLICATION_MCU_SYSCTL_XHEADER_SYSCTL_INIT_H_

#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Defines.h>

SYSCTL_nERROR SYSCTL__enInit(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg, SYSCTL_nPRIORITY enPriorityArg);

#endif /* XAPPLICATION_MCU_SYSCTL_XHEADER_SYSCTL_INIT_H_ */

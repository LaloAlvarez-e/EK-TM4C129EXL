/**
 *
 * @file SYSCTL_Dependencies.h
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
 * @verbatim 3 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 3 abr. 2026    GitHub Copilot   1.0         initial Version@endverbatim
 */

#ifndef AB43E769_D116_4E05_82C6_EBB6EA305EB3
#define AB43E769_D116_4E05_82C6_EBB6EA305EB3

#ifndef EEA2A298_8907_47D4_A370_10F4787A74D2
#define EEA2A298_8907_47D4_A370_10F4787A74D2

#ifndef XAPPLICATION_MCU_SYSCTL_INTRINSICS_XHEADER_SYSCTL_DEPENDENCIES_H_
#define XAPPLICATION_MCU_SYSCTL_INTRINSICS_XHEADER_SYSCTL_DEPENDENCIES_H_

#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Defines.h>

#ifdef __cplusplus
extern "C"
{
#endif

#include <xApplication_MCU/Core/SCB/SCB.h>
#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>
#include <xDriver_MCU/Core/NVIC/NVIC.h>
#include <xDriver_MCU/SYSCTL/SYSCTL.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

extern UBase_t TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue;

#ifdef __cplusplus
}
#endif

#ifdef SYSCTL_MISC_R
#undef SYSCTL_MISC_R
#endif

#define SYSCTL_MISC_R (TM4C129E_DriverLib_Test__u32HostSYSCTLMISCValue)

#endif /* XAPPLICATION_MCU_SYSCTL_INTRINSICS_XHEADER_SYSCTL_DEPENDENCIES_H_ */

#endif /* EEA2A298_8907_47D4_A370_10F4787A74D2 */


#endif /* AB43E769_D116_4E05_82C6_EBB6EA305EB3 */

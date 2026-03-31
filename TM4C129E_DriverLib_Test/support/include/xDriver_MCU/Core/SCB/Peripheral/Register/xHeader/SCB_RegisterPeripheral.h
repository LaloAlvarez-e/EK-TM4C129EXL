/**
 *
 * @file SCB_RegisterPeripheral.h
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
 * @verbatim 30 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 30 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_XDRIVER_MCU_CORE_SCB_PERIPHERAL_REGISTER_XHEADER_SCB_REGISTERPERIPHERAL_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_XDRIVER_MCU_CORE_SCB_PERIPHERAL_REGISTER_XHEADER_SCB_REGISTERPERIPHERAL_H_

#include <xDriver_MCU/Core/SCB/Peripheral/xHeader/SCB_Enum.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Struct/xHeader/SCB_StructPeripheral.h>
#include <xDriver_MCU/Core/SCB/Peripheral/Register/xHeader/SCB_RegisterAddress.h>

#ifdef __cplusplus
extern "C"
{
#endif
extern UBase_t TM4C129E_DriverLib_Test__u32HostSCBICSRValue;
#ifdef __cplusplus
}
#endif

#define SCB (((SCB_t*) (SCB_BASE)))

#define SCB_ICTLR (((ICTLR_t*) (SCB_BASE + SCB_ICTLR_OFFSET)))
#define SCB_ICTLR_R (*((volatile const UBase_t*) (SCB_BASE + SCB_ICTLR_OFFSET)))

#define SCB_ACTLR (((ACTLR_t*) (SCB_BASE + SCB_ACTLR_OFFSET)))
#define SCB_ACTLR_R (*((volatile UBase_t*) (SCB_BASE + SCB_ACTLR_OFFSET)))

#define SCB_CPUID (((CPUID_t*) (SCB_BASE + SCB_CPUID_OFFSET)))
#define SCB_CPUID_R (*((volatile const UBase_t*) (SCB_BASE + SCB_CPUID_OFFSET)))

#define SCB_ICSR (((ICSR_t*) (SCB_BASE + SCB_ICSR_OFFSET)))
#define SCB_ICSR_R (TM4C129E_DriverLib_Test__u32HostSCBICSRValue)

#define SCB_VTOR (((VTOR_t*) (SCB_BASE + SCB_VTOR_OFFSET)))
#define SCB_VTOR_R (*((volatile UBase_t*) (SCB_BASE + SCB_VTOR_OFFSET)))

#define SCB_AIRCR (((AIRCR_t*) (SCB_BASE + SCB_AIRCR_OFFSET)))
#define SCB_AIRCR_R (*((volatile UBase_t*) (SCB_BASE + SCB_AIRCR_OFFSET)))

#define SCB_SCR (((SCR_t*) (SCB_BASE + SCB_SCR_OFFSET)))
#define SCB_SCR_R (*((volatile UBase_t*) (SCB_BASE + SCB_SCR_OFFSET)))

#define SCB_CCR (((CCR_t*) (SCB_BASE + SCB_CCR_OFFSET)))
#define SCB_CCR_R (*((volatile UBase_t*) (SCB_BASE + SCB_CCR_OFFSET)))

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_XDRIVER_MCU_CORE_SCB_PERIPHERAL_REGISTER_XHEADER_SCB_REGISTERPERIPHERAL_H_ */

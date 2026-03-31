/**
 *
 * @file SYSEXC_Dependencies.h
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

#ifndef C710430E_B875_460F_A663_613E46695799
#define C710430E_B875_460F_A663_613E46695799

#ifndef TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_XAPPLICATION_MCU_SYSEXC_INTRINSICS_XHEADER_SYSEXC_DEPENDENCIES_H_
#define TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_XAPPLICATION_MCU_SYSEXC_INTRINSICS_XHEADER_SYSEXC_DEPENDENCIES_H_

#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Defines.h>
#include <xDriver_MCU/SYSEXC/SYSEXC.h>
#include <xDriver_MCU/SYSEXC/Peripheral/SYSEXC_Peripheral.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include <xDriver_MCU/Common/xHeader/MCU_CheckParams.h>

#ifdef __cplusplus
}
#endif

SYSEXC_pvfIRQVectorHandler_t SYSEXC__pvfGetIRQVectorHandler(SYSEXC_nMODULE enModuleArg);
SYSEXC_pvfIRQSourceHandler_t SYSEXC__pvfGetIRQSourceHandler(SYSEXC_nMODULE enModuleArg, SYSEXC_nINT enIntSourceArg);
SYSEXC_nERROR SYSEXC__enRegisterIRQVectorHandler(SYSEXC_nMODULE enModuleArg, SYSEXC_pvfIRQVectorHandler_t pfIrqVectorHandlerArg);
SYSEXC_nERROR SYSEXC__enDisableInterruptSourceByMask(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg);
SYSEXC_nERROR SYSEXC__enClearInterruptSourceByMask(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg);
SYSEXC_nERROR SYSEXC__enEnableInterruptSourceByMask(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg);
SYSEXC_nERROR SYSEXC__enEnableInterruptVectorWithPriority(SYSEXC_nMODULE enModuleArg, SYSEXC_nPRIORITY enPriorityArg);

#endif /* TM4C129E_DRIVERLIB_TEST_SUPPORT_INCLUDE_XAPPLICATION_MCU_SYSEXC_INTRINSICS_XHEADER_SYSEXC_DEPENDENCIES_H_ */


#endif /* C710430E_B875_460F_A663_613E46695799 */
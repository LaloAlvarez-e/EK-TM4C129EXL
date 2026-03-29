/**
 *
 * @file SYSEXC_Init.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/SYSEXC/xHeader/SYSEXC_Init.h>

#include <xApplication_MCU/SYSEXC/Intrinsics/xHeader/SYSEXC_Dependencies.h>
#include <xApplication_MCU/SYSEXC/Interrupt/SYSEXC_Interrupt.h>

SYSEXC_nERROR SYSEXC__enInit(SYSEXC_nMODULE enModuleArg, SYSEXC_nINTMASK enInterruptMaskArg, SYSEXC_nPRIORITY enPriorityArg)
{
    SYSEXC_nERROR enErrorReg;
    SYSEXC_pvfIRQVectorHandler_t pfIrqVectorHandlerReg;

    enErrorReg = (SYSEXC_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSEXC_enMODULE_MAX);
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = SYSEXC__pvfGetIRQVectorHandler(enModuleArg);
        enErrorReg = SYSEXC__enRegisterIRQVectorHandler(enModuleArg, pfIrqVectorHandlerReg);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSEXC__enDisableInterruptSourceByMask(enModuleArg, SYSEXC_enINTMASK_ALL);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSEXC__enClearInterruptSourceByMask(enModuleArg, SYSEXC_enINTMASK_ALL);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSEXC__enEnableInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
    }
    if(SYSEXC_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSEXC__enEnableInterruptVectorWithPriority(enModuleArg, enPriorityArg);
    }

    return (enErrorReg);
}

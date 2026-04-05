/**
 *
 * @file SYSCTL_Init.c
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
#include <xApplication_MCU/SYSCTL/xHeader/SYSCTL_Init.h>

#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Dependencies.h>
#include <xApplication_MCU/SYSCTL/Interrupt/SYSCTL_Interrupt.h>

SYSCTL_nERROR SYSCTL__enInit(SYSCTL_nMODULE enModuleArg, SYSCTL_nINTMASK enInterruptMaskArg, SYSCTL_nPRIORITY enPriorityArg)
{
    SYSCTL_nERROR enErrorReg;
    void (*pfIrqVectorHandlerReg) (void);

    enErrorReg = (SYSCTL_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) SYSCTL_enMODULE_MAX);
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        pfIrqVectorHandlerReg = SYSCTL__pvfGetIRQVectorHandler();
        enErrorReg = SYSCTL__enRegisterIRQVectorHandler(pfIrqVectorHandlerReg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enDisableInterruptSourceByMask(enModuleArg, SYSCTL_enINTMASK_ALL);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enClearInterruptSourceByMask(enModuleArg, SYSCTL_enINTMASK_ALL);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        enErrorReg = SYSCTL__enEnableInterruptSourceByMask(enModuleArg, enInterruptMaskArg);
    }
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        if(SYSCTL_enINTMASK_NONE != enInterruptMaskArg)
        {
            enErrorReg = SYSCTL__enEnableInterruptVector(enPriorityArg);
        }
        else
        {
            enErrorReg = SYSCTL__enDisableInterruptVector();
        }
    }

    return (enErrorReg);
}

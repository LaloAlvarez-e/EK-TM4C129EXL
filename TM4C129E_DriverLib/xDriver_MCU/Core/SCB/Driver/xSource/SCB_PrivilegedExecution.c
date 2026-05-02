/**
 *
 * @file SCB_PrivilegedExecution.c
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
 * @verbatim 12 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 12 abr. 2026   vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_PrivilegedExecution.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SCB/Driver/Exception/xHeader/SCB_ISR.h>

SCB_nERROR SCB__enIsPrivilegedExecution(SCB_nMODULE enModuleArg, SCB_nSTATE* penStateArg)
{
    SCB_nERROR enErrorReg;
    SCB_nVECISR enVectorActiveReg;

    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SCB_enERROR_POINTER : SCB_enERROR_OK;
    enVectorActiveReg = SCB_enVECISR_THREAD;
    if(SCB_enERROR_OK == enErrorReg)
    {
        enErrorReg = SCB_ISR__enGetVectorActive(enModuleArg, &enVectorActiveReg);
    }
    
    if(SCB_enERROR_OK == enErrorReg)
    {
        if(SCB_enVECISR_THREAD != enVectorActiveReg)
        {
            *penStateArg = SCB_enSTATE_ENA;
        }
        else
        {
            MCU_nTHREAD_LEVEL enThreadLevelReg = MCU__enGetThreadLevel();
            *penStateArg = (MCU_enTHREAD_LEVEL_PRIV == enThreadLevelReg) ? SCB_enSTATE_ENA : SCB_enSTATE_DIS;
        }
    }
    
    return (enErrorReg);
}
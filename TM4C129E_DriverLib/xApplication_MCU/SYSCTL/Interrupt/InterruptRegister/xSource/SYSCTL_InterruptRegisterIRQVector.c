/**
 *
 * @file SYSCTL_InterruptRegisterIRQVector.c
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
#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRegister/xHeader/SYSCTL_InterruptRegisterIRQVector.h>

#include <xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/SYSCTL_InterruptRoutine.h>
#include <xApplication_MCU/SYSCTL/Intrinsics/xHeader/SYSCTL_Dependencies.h>

SYSCTL_nERROR SYSCTL__enRegisterIRQVectorHandler(SYSCTL_pvfIRQVectorHandler_t pfIrqVectorHandlerArg)
{
    SCB_nVECISR enVector = SCB_enVECISR_SYSCTL;
    SYSCTL_nERROR enErrorReg;

    enErrorReg = SYSCTL_enERROR_OK;
    if((SYSCTL_pvfIRQVectorHandler_t) 0UL != pfIrqVectorHandlerArg)
    {
        enErrorReg = (SYSCTL_nERROR) SCB__enRegisterIRQVectorHandler(SCB_enMODULE_0,
                                                                     enVector,
                                                                     pfIrqVectorHandlerArg,
                                                                     SYSCTL__pvfGetIRQVectorHandlerPointer());
    }

    return (enErrorReg);
}

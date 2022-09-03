/**
 *
 * @file SCB_Systick.c
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
 * @verbatim 19 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/SCB/Driver/Exception/xHeader/SCB_Systick.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SCB/Peripheral/SCB_Peripheral.h>

void SCB_Systick__vSetPriority(SCB_nPRIORITY enSystickPriority)
{
    MCU__vDataSyncBarrier();
    MCU__vWriteRegister(SCB_BASE, SCB_SHPR3_OFFSET, (uint32_t) enSystickPriority,
                        SCB_SHPR3_SYSTICK_MASK, SCB_SHPR3_R_SYSTICK_BIT);
    MCU__vDataSyncBarrier();
}

SCB_nPRIORITY SCB_Systick__enGetPriority(void)
{
    SCB_nPRIORITY enPriReg = SCB_enPRI0;
    enPriReg = (SCB_nPRIORITY) MCU__u32ReadRegister(SCB_BASE, SCB_SHPR3_OFFSET,
                                                SCB_SHPR3_SYSTICK_MASK, SCB_SHPR3_R_SYSTICK_BIT);
    return (enPriReg);

}

void SCB_Systick__vSetPending(void)
{
    MCU__vWriteRegister(SCB_BASE, SCB_ICSR_OFFSET, SCB_ICSR_PENDSTSET_SET,
                        SCB_ICSR_PENDSTSET_MASK, SCB_ICSR_R_PENDSTSET_BIT);
}

void SCB_Systick__vClearPending(void)
{
    MCU__vWriteRegister(SCB_BASE, SCB_ICSR_OFFSET, SCB_ICSR_PENDSTCLR_REMOVE,
                        SCB_ICSR_PENDSTCLR_MASK, SCB_ICSR_R_PENDSTCLR_BIT);
}

SCB_nPENDSTATE SCB_Systick__enGetPending(void)
{
    SCB_nPENDSTATE enPendReg = SCB_enNOPENDING;
    enPendReg = (SCB_nPENDSTATE) MCU__u32ReadRegister(SCB_BASE, SCB_ICSR_OFFSET,
                                     SCB_ICSR_PENDSTSET_MASK, SCB_ICSR_R_PENDSTSET_BIT);
    return (enPendReg);
}

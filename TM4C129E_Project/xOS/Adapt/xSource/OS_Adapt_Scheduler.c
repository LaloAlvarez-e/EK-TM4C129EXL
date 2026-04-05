/**
 *
 * @file OS_Adapt_Scheduler.c
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
 * @verbatim 9 sep. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 sep. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xOS/Adapt/xHeader/OS_Adapt_Scheduler.h>

#include <xApplication_MCU/Core/SCB/SCB.h>
#include <xApplication_MCU/Core/SYSTICK/SYSTICK.h>
#include <xDriver_MCU/Core/SCB/SCB.h>
#include <xDriver_MCU/Core/FPU/FPU.h>

#include <xOS/Adapt/xHeader/OS_Adapt_Critical.h>
#include <xOS/Adapt/xHeader/OS_Adapt_Interrupt.h>
#include <xOS/Task/xHeader/OS_Task_Scheduler.h>
#include <xOS/Task/Intrinsics/xHeader/OS_Task_TCB_.h>
#include <xOS/Task/xHeader/OS_Task_TCB.h>

static void OS_Adapt_vSetupTimerInterrupt(OS_UBase_t uxUsPeriod);
static void OS_Adapt_vSysTickHandler( void );

OS_Task_TCB_t* volatile* OS_Adapt_ppstCurrentTCB;
const OS_UBase_t OS_Adapt_uxMaxSyscallInterruptPriority = OS_ADAPT_MAX_SYSCALL_INTERRUPT_PRIORITY;

static void OS_Adapt_vSetupTimerInterrupt(OS_UBase_t uxUsPeriod)
{
    SYSTICK__enInitUsVector(SYSTICK_enMODULE_0, uxUsPeriod, SYSTICK_enPRI7, &OS_Adapt_vSysTickHandler);
}

void OS_Adapt__vStartScheduler(OS_UBase_t uxUsPeriod)
{
    FPU__enInit(FPU_enMODULE_0);
    SCB__enRegisterIRQVectorHandler(SCB_enMODULE_0, SCB_enVECISR_PENDSV, &OS_Adapt_vPendSVHandler, (SCB_pvfIRQVectorHandler_t*) 0UL);
    SCB_SVCall__enRegisterIRQSourceHandler(SCB_enMODULE_0, 0UL, &OS_Adapt_vSVCHandler);
    SCB_PendSV__enSetPriority(SCB_enMODULE_0, SCB_enPRI7);
    SCB_SYSTICK__enSetPriority(SCB_enMODULE_0, SCB_enPRI7);

    OS_Adapt_vSetupTimerInterrupt(uxUsPeriod);
    OS_Adapt__vSetCriticalNesting(0UL);

    MCU__vSetFPUContextActive(MCU_enSTATUS_INACTIVE);
    OS_Adapt_ppstCurrentTCB = OS_Task__pstGetCurrentTCBAddress();
    OS_Adapt_vStartFirstTask();
}

static void OS_Adapt_vSysTickHandler( void )
{
    (void) OS_Adapt__uxSetInterruptMaskFromISR();
    {
        OS_Boolean_t boSwitchRequired = OS_Task__boIncrementTick();
        if(FALSE !=  boSwitchRequired)
        {
            SCB_PendSV__enSetPending(SCB_enMODULE_0);
        }
    }
    OS_Adapt__vClearInterruptMaskFromISR(0UL);
}

void OS_Adapt__vEndScheduler(void)
{
    OS_UBase_t uxCriticalNestingReg;
    uxCriticalNestingReg = OS_Adapt__uxGetCriticalNesting();
    if(1000UL != uxCriticalNestingReg)
    {
        OS_Adapt__vDisableInterrupts();
        while(1UL);
    }
}

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
#include <xOS/Task/xHeader/OS_Task_Scheduler.h>
#include <xOS/Task/Intrinsics/xHeader/OS_Task_TCB.h>
#include <xOS/Task/xHeader/OS_Task_TCB.h>

static void OS_Adapt_vSetupTimerInterrupt(OS_UBase_t uxUsPeriod);

__attribute__ (( naked ))
static void OS_Adapt_vStartFirstTask(void);
__attribute__ (( naked ))
static void OS_Adapt_vSVCHandler(void);
__attribute__ (( naked ))
static void OS_Adapt_vPendSVHandler(void);

static void OS_Adapt_vSysTickHandler( void );

OS_Task_TCB_t* volatile* OS_Adapt_ppstCurrentTCB = (OS_Task_TCB_t**) 0UL;
const OS_UBase_t OS_Adapt_uxMaxSyscallInterruptPriority = OS_ADAPT_MAX_SYSCALL_INTERRUPT_PRIORITY;

static void OS_Adapt_vSetupTimerInterrupt(OS_UBase_t uxUsPeriod)
{
    SYSTICK__enInitUsVector(uxUsPeriod, SYSTICK_enPRI7, &OS_Adapt_vSysTickHandler);
}

void OS_Adapt__vStartScheduler(OS_UBase_t uxUsPeriod)
{
    SCB__enRegisterIRQVectorHandler(SCB_enMODULE_0,
                                    SCB_enVECISR_PENDSV,
                                    &OS_Adapt_vPendSVHandler,
                                    (void (**) (void)) 0UL);
    SCB_SVCall__vRegisterIRQSourceHandler(&OS_Adapt_vSVCHandler, 0UL);
    SCB_PendSV__vSetPriority(SCB_enSHPR7);
    SCB_Systick__vSetPriority(SCB_enSHPR7);

    OS_Adapt_vSetupTimerInterrupt(uxUsPeriod);
    OS_Adapt__vSetCriticalNesting(0UL);

    FPU__vInit();
    OS_Adapt_ppstCurrentTCB = OS_Task__pstGetCurrentTCBAddress();
    OS_Adapt_vStartFirstTask();
}


__attribute__ (( naked ))
static void OS_Adapt_vStartFirstTask(void)
{
     __asm volatile(
#if defined (__TI_ARM__ )
                    " movw r0, #0xED08      \n"/* Use the NVIC offset register to locate the stack. */
                    " movt r0, #0xE000      \n"
#elif defined (__GNUC__ )
                    " ldr r0, = 0xE000ED08 \n"
#endif
                    " ldr r0, [r0]          \n"
                    " ldr r0, [r0]          \n"
                    " msr msp, r0           \n" /* Set the msp back to the start of the stack. */
                    " cpsie i               \n" /* Globally enable interrupts. */
                    " cpsie f               \n"
                    " dsb                   \n"
                    " isb                   \n"
                    " svc #0                \n" /* System call to start first task. */
                    " nop                   \n"
                    " bx r14                \n"
                );
}

__attribute__ (( naked ))
static void OS_Adapt_vSVCHandler(void)
{
__asm volatile (
#if defined (__TI_ARM__ )
                "   movw r3, OS_Adapt_ppstCurrentTCB     \n"/* Get the location of the current TCB. */
                "   movt r3, OS_Adapt_ppstCurrentTCB     \n"
#elif defined (__GNUC__ )
                " ldr r3, = OS_Adapt_ppstCurrentTCB      \n"
#endif
                "   ldr r1, [r3]                    \n" /* Use pxCurrentTCBConst to get the pxCurrentTCB address. */
                "   ldr r2, [r1]                    \n" /* Use pxCurrentTCBConst to get the pxCurrentTCB address. */
                "   ldr r0, [r2]                    \n" /* The first item in OS_Kernel_psCurrentTask is the task top of stack. */
                "   ldmia r0!, {r4-r11, r14}        \n" /* Pop the registers that are not automatically saved on exception entry and the critical nesting count. */
                "   msr psp, r0                     \n" /* Restore the task stack pointer. */
                "   isb                             \n"
                "   mov r0, #0                      \n"
                "   msr basepri, r0                 \n"
                "   bx r14                          \n"
            );
}

__attribute__ (( naked ))
static void OS_Adapt_vPendSVHandler (void)
{
     __asm volatile
    (
    "   mrs r0, psp                         \n"
    "   isb                                 \n"
    "                                       \n"
#if defined (__TI_ARM__ )
    "   movw r3, OS_Adapt_ppstCurrentTCB    \n"/* Get the location of the current TCB. */
    "   movt r3, OS_Adapt_ppstCurrentTCB    \n"
#elif defined (__GNUC__ )
    "   ldr r3, = OS_Adapt_ppstCurrentTCB   \n"
#endif
    "   ldr r1, [r3]                        \n" /* Use pxCurrentTCBConst to get the pxCurrentTCB address. */
    "   ldr r2, [r1]                        \n"
    "                                       \n"
    "   tst r14, #0x10                      \n" /* Is the task using the FPU context?  If so, push high vfp registers. */
    "   it eq                               \n"
    "   vstmdbeq r0!, {s16-s31}             \n"
    "                                       \n"
    "   stmdb r0!, {r4-r11, r14}            \n" /* Save the core registers. */
    "                                       \n"
    "   str r0, [r2]                        \n" /* Save the new top of stack into the first member of the TCB. */
    "                                       \n"
    "   stmdb sp!, {r3}                     \n"
#if defined (__TI_ARM__ )
    "   movw r0, OS_Adapt_uxMaxSyscallInterruptPriority         \n"/* Get the location of the current TCB. */
    "   movt r0, OS_Adapt_uxMaxSyscallInterruptPriority         \n"
#elif defined (__GNUC__ )
    "   ldr r0, = OS_Adapt_uxMaxSyscallInterruptPriority        \n"
#endif
    "   ldr r1, [r0]                        \n"
    "   msr basepri, r1                     \n"
    "   dsb                                 \n"
    "   isb                                 \n");

    OS_Task__vSwitchContext();

     __asm volatile
    (
    "   mov r0, #0                          \n"
    "   msr basepri, r0                     \n"
    "   ldmia sp!, {r3}                     \n"
    "                                       \n"
    "   ldr r2, [r3]                        \n" /* The first item in pxCurrentTCB is the task top of stack. */
    "   ldr r1, [r2]                        \n"
    "   ldr r0, [r1]                        \n"
    "                                       \n"
    "   ldmia r0!, {r4-r11, r14}            \n" /* Pop the core registers. */
    "                                       \n"
    "   tst r14, #0x10                      \n" /* Is the task using the FPU context?  If so, pop the high vfp registers too. */
    "   it eq                               \n"
    "   vldmiaeq r0!, {s16-s31}             \n"
    "                                       \n"
    "   msr psp, r0                         \n"
    "   isb                                 \n"
    "                                       \n"
    "                                       \n"
    "   bx r14                              \n"
    "                                       \n"
    );
}


static void OS_Adapt_vSysTickHandler( void )
{
    OS_Boolean_t boSwitchRequired = FALSE;

    (void) OS_Adapt__uxSetInterruptMaskFromISR();
    {
        boSwitchRequired = OS_Task__boIncrementTick();
        if(FALSE !=  boSwitchRequired)
        {
            SCB_PendSV__vSetPending();
        }
    }
    OS_Adapt__vClearInterruptMaskFromISR(0UL);
}

void OS_Adapt__vEndScheduler(void)
{
    OS_UBase_t uxCriticalNestingReg = 0UL;

    uxCriticalNestingReg = OS_Adapt__uxGetCriticalNesting();
    if(1000UL != uxCriticalNestingReg)
    {
        OS_Adapt__vDisableInterrupts();
        while(1UL);
    }
}

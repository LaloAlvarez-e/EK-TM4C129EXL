/**
 *
 * @file TIMER_InterruptRegisterIRQVector.c
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
 * @verbatim 15 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/TIMER_InterruptRegisterIRQVector.h>

#include <xDriver_MCU/TIMER/Driver/Intrinsics/Primitives/TIMER_Primitives.h>
#include <xDriver_MCU/TIMER/Peripheral/xHeader/TIMER_Dependencies.h>
#include <xDriver_MCU/TIMER/Driver/Intrinsics/Interrupt/InterruptRoutine/TIMER_InterruptRoutine.h>


void TIMER__vRegisterIRQVectorHandler(void (*pfIrqVectorHandler) (void),TIMER_nMODULE enModule)
{
    SCB_nVECISR enVector = SCB_enVECISR_TIMER0A;
    uint32_t u32ModuleNumber = 0UL;
    uint32_t u32SubModule = 0UL;

    const SCB_nVECISR SCB_enVECISR_TIMER[(uint32_t) TIMER_enSUBMODULE_MAX - 1UL][(uint32_t) TIMER_enMODULE_NUM_MAX] =
    {
        { SCB_enVECISR_TIMER0A, SCB_enVECISR_TIMER1A, SCB_enVECISR_TIMER2A, SCB_enVECISR_TIMER3A,
          SCB_enVECISR_TIMER4A, SCB_enVECISR_TIMER5A, SCB_enVECISR_TIMER6A, SCB_enVECISR_TIMER7A},
        { SCB_enVECISR_TIMER0B, SCB_enVECISR_TIMER1B, SCB_enVECISR_TIMER2B, SCB_enVECISR_TIMER3B,
          SCB_enVECISR_TIMER4B, SCB_enVECISR_TIMER5B, SCB_enVECISR_TIMER6B, SCB_enVECISR_TIMER7B}
    };

    if(0UL != (uint32_t) pfIrqVectorHandler)
    {
        TIMER__vGetSubParams(enModule, &u32SubModule, &u32ModuleNumber);
        u32SubModule &= 0x1UL;
        enVector = SCB_enVECISR_TIMER[u32SubModule][u32ModuleNumber];
        SCB__vRegisterIRQVectorHandler(pfIrqVectorHandler,
                                       TIMER__pvfGetIRQVectorHandlerPointer((TIMER_nSUBMODULE) u32SubModule,
                                                                            (TIMER_nMODULE_NUM) u32ModuleNumber),
                                        enVector);
    }
}
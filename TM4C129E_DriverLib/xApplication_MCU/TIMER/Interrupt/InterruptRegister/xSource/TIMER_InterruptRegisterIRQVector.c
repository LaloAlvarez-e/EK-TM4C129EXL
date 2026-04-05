/**
 *
 * @file TIMER_InterruptRegisterIRQVector.c
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/TIMER/Interrupt/InterruptRegister/xHeader/TIMER_InterruptRegisterIRQVector.h>

#include <xApplication_MCU/TIMER/Interrupt/InterruptRoutine/TIMER_InterruptRoutine.h>
#include <xApplication_MCU/TIMER/Intrinsics/xHeader/TIMER_Dependencies.h>

TIMER_nERROR TIMER__enRegisterIRQVectorHandler(void (*pfIrqVectorHandlerArg) (void), TIMER_nMODULE enModuleArg)
{
  SCB_nVECISR enVectorReg = SCB_enVECISR_TIMER0A;
  UBase_t uxModuleNumberReg = 0UL;
  UBase_t uxSubModuleReg = 0UL;
  TIMER_nERROR enErrorReg = TIMER_enERROR_OK;

    const SCB_nVECISR SCB_enVECISR_TIMER[(UBase_t) TIMER_enSUBMODULE_MAX - 1UL][(UBase_t) TIMER_enMODULE_NUM_MAX] =
    {
        { SCB_enVECISR_TIMER0A, SCB_enVECISR_TIMER1A, SCB_enVECISR_TIMER2A, SCB_enVECISR_TIMER3A,
          SCB_enVECISR_TIMER4A, SCB_enVECISR_TIMER5A, SCB_enVECISR_TIMER6A, SCB_enVECISR_TIMER7A},
        { SCB_enVECISR_TIMER0B, SCB_enVECISR_TIMER1B, SCB_enVECISR_TIMER2B, SCB_enVECISR_TIMER3B,
          SCB_enVECISR_TIMER4B, SCB_enVECISR_TIMER5B, SCB_enVECISR_TIMER6B, SCB_enVECISR_TIMER7B}
    };

  if(0UL != (UBase_t) pfIrqVectorHandlerArg)
    {
    TIMER__vGetSubParams(enModuleArg, &uxSubModuleReg, &uxModuleNumberReg);
    uxSubModuleReg &= 0x1UL;
    enVectorReg = SCB_enVECISR_TIMER[uxSubModuleReg][uxModuleNumberReg];
    enErrorReg = (TIMER_nERROR) SCB__enRegisterIRQVectorHandler(SCB_enMODULE_0,
                                  enVectorReg,
                                  pfIrqVectorHandlerArg,
                                  TIMER__pvfGetIRQVectorHandlerPointer((TIMER_nSUBMODULE) uxSubModuleReg,
                                                     (TIMER_nMODULE_NUM) uxModuleNumberReg));
    }
  return (enErrorReg);
}

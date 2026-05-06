/**
 *
 * @file HIB_InterruptRegisterIRQVector.c
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/HIB/Interrupt/InterruptRegister/xHeader/HIB_InterruptRegisterIRQVector.h>

#include <xApplication_MCU/HIB/Interrupt/InterruptRoutine/HIB_InterruptRoutine.h>
#include <xApplication_MCU/HIB/Intrinsics/xHeader/HIB_Dependencies.h>

HIB_nERROR HIB__enRegisterIRQVectorHandler(HIB_nMODULE enModuleArg, HIB_pvfIRQVectorHandler_t pfIrqVectorHandlerArg)
{
    static const SCB_nVECISR SCB_VECTOR_HIB[(UBase_t) HIB_enMODULE_MAX] =
    {
        SCB_enVECISR_HIB,
    };
    SCB_nVECISR enVectorReg;
    HIB_nERROR enErrorReg;
    HIB_pvfIRQVectorHandler_t* pfIrqVectorHandlerReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enVectorReg = SCB_VECTOR_HIB[(UBase_t) enModuleArg];
        pfIrqVectorHandlerReg = HIB__pvfGetIRQVectorHandlerPointer(enModuleArg);
        enErrorReg = (HIB_nERROR) SCB__enRegisterIRQVectorHandler(SCB_enMODULE_0, enVectorReg, pfIrqVectorHandlerArg, pfIrqVectorHandlerReg);
    }
    return (enErrorReg);
}

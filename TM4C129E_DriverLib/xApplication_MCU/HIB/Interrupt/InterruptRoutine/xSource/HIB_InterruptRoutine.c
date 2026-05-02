/**
 *
 * @file HIB_InterruptRoutine.c
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
#include <xApplication_MCU/HIB/Interrupt/InterruptRoutine/HIB_InterruptRoutine.h>

static HIB_pvfIRQVectorHandler_t HIB__pvIRQVectorHandler[(UBase_t) HIB_enMODULE_MAX] =
{
    &HIB__vIRQVectorHandler,
};

HIB_pvfIRQVectorHandler_t HIB__pvfGetIRQVectorHandler(HIB_nMODULE enModuleArg)
{
    HIB_pvfIRQVectorHandler_t pfIrqVectorHandlerReg;

    pfIrqVectorHandlerReg = HIB__pvIRQVectorHandler[(UBase_t) enModuleArg];
    return (pfIrqVectorHandlerReg);
}

HIB_pvfIRQVectorHandler_t* HIB__pvfGetIRQVectorHandlerPointer(HIB_nMODULE enModuleArg)
{
    HIB_pvfIRQVectorHandler_t* pfIrqVectorHandlerReg;

    pfIrqVectorHandlerReg = &HIB__pvIRQVectorHandler[(UBase_t) enModuleArg];
    return (pfIrqVectorHandlerReg);
}
/**
 *
 * @file HIB_InterruptRoutine_Source.c
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
#include <xDriver_MCU/HIB/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/HIB_InterruptRoutine_Source.h>

static HIB_pvfIRQSourceHandler_t HIB__pvIRQSourceHandler[(UBase_t) HIB_enMODULE_MAX][(UBase_t) HIB_enINT_MAX] =
{
    {
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
    },
};

HIB_pvfIRQSourceHandler_t HIB__pvfGetIRQSourceHandler(HIB_nMODULE enModuleArg, HIB_nINT enInterruptSourceArg)
{
    HIB_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (HIB_pvfIRQSourceHandler_t) 0;
    if((HIB_enMODULE_MAX > enModuleArg) && (HIB_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = HIB__pvIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

HIB_pvfIRQSourceHandler_t* HIB__pvfGetIRQSourceHandlerPointer(HIB_nMODULE enModuleArg, HIB_nINT enInterruptSourceArg)
{
    HIB_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (HIB_pvfIRQSourceHandler_t*) 0;
    if((HIB_enMODULE_MAX > enModuleArg) && (HIB_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &HIB__pvIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

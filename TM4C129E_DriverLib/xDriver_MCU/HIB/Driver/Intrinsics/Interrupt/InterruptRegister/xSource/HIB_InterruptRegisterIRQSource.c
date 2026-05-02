/**
 *
 * @file HIB_InterruptRegisterIRQSource.c
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
#include <xDriver_MCU/HIB/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/HIB_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Driver/Intrinsics/Interrupt/InterruptRoutine/HIB_InterruptRoutine.h>

HIB_nERROR HIB__enRegisterIRQSourceHandler(HIB_nMODULE enModuleArg, HIB_nINT enInterruptSourceArg, HIB_pvfIRQSourceHandler_t pfIrqSourceHandlerArg)
{
    HIB_nERROR enErrorReg;
    HIB_pvfIRQSourceHandler_t* pfIrqSourceHandlerReg;

    enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) HIB_enINT_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (0UL == (uintptr_t) pfIrqSourceHandlerArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        pfIrqSourceHandlerReg = HIB__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);        
        enErrorReg = (HIB_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandlerArg, pfIrqSourceHandlerReg, 0UL, 1UL);
    }
    return (enErrorReg);
}

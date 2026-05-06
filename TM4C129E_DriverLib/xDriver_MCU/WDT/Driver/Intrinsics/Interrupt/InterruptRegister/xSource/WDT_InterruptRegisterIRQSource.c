/**
 *
 * @file WDT_InterruptRegisterIRQSource.c
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
 * @verbatim 22 jul. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 jul. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/WDT/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/WDT_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/WDT/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/WDT_InterruptRoutine_Source.h>
#include <xDriver_MCU/WDT/Peripheral/WDT_Peripheral.h>

WDT_nERROR WDT__enRegisterIRQSourceHandler(WDT_nMODULE enModuleArg, WDT_nINT enInterruptSourceArg, WDT_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    WDT_nERROR enErrorReg;
    enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) WDT_enMODULE_MAX);
    if(WDT_enERROR_OK == enErrorReg)
    {
        enErrorReg = (WDT_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) WDT_enINT_MAX);
    }
    if(WDT_enERROR_OK == enErrorReg)
    {
        WDT_pvfIRQSourceHandler_t* pvfIrqHandler = WDT__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (WDT_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }
    return (enErrorReg);
}

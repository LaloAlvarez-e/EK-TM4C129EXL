/**
 *
 * @file WDT_InterruptRoutine_Source.c
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
#include <xDriver_MCU/WDT/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/WDT_InterruptRoutine_Source.h>

static WDT_pvfIRQSourceHandler_t WDT_vIRQSourceHandler[(UBase_t) WDT_enMODULE_MAX][(UBase_t) WDT_enINT_MAX] =
{
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_DummyNonBlocking,
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_DummyNonBlocking,
    },
};

WDT_pvfIRQSourceHandler_t WDT__pvfGetIRQSourceHandler(WDT_nMODULE enModuleArg, WDT_nINT enInterruptSourceArg)
{
    WDT_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (WDT_pvfIRQSourceHandler_t) 0;
    if((WDT_enMODULE_MAX > enModuleArg) && (WDT_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = WDT_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

WDT_pvfIRQSourceHandler_t* WDT__pvfGetIRQSourceHandlerPointer(WDT_nMODULE enModuleArg, WDT_nINT enInterruptSourceArg)
{
    WDT_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (WDT_pvfIRQSourceHandler_t*) 0;
    if((WDT_enMODULE_MAX > enModuleArg) && (WDT_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &WDT_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}


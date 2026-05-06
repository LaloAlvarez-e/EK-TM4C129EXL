/**
 *
 * @file SYSEXC_InterruptRoutine_Source.c
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
 * @verbatim 19 oct. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 oct. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSEXC_InterruptRoutine_Source.h>

static SYSEXC_pvfIRQSourceHandler_t SYSEXC_vIRQSourceHandler[(UBase_t) SYSEXC_enMODULE_MAX][(UBase_t) SYSEXC_enINT_MAX] =
{
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy
    },
};

SYSEXC_pvfIRQSourceHandler_t SYSEXC__pvfGetIRQSourceHandler(SYSEXC_nMODULE enModuleArg, SYSEXC_nINT enInterruptSourceArg)
{
    SYSEXC_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (SYSEXC_pvfIRQSourceHandler_t) 0;
    if((SYSEXC_enMODULE_MAX > enModuleArg) && (SYSEXC_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = SYSEXC_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

SYSEXC_pvfIRQSourceHandler_t* SYSEXC__pvfGetIRQSourceHandlerPointer(SYSEXC_nMODULE enModuleArg, SYSEXC_nINT enInterruptSourceArg)
{
    SYSEXC_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (SYSEXC_pvfIRQSourceHandler_t*) 0;
    if((SYSEXC_enMODULE_MAX > enModuleArg) && (SYSEXC_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &SYSEXC_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}





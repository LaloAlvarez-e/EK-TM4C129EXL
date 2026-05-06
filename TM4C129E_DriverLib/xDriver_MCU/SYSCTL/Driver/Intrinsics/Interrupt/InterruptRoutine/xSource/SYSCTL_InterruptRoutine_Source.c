/**
 *
 * @file SYSCTL_InterruptRoutine_Source.c
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
 * @verbatim 17 feb. 2021 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 17 feb. 2021     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SYSCTL_InterruptRoutine_Source.h>

static SYSCTL_pvfIRQSourceHandler_t SYSCTL_vIRQSourceHandler[(UBase_t) SYSCTL_enMODULE_MAX][(UBase_t) SYSCTL_enINT_MAX] =
{
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy
    },
};

SYSCTL_pvfIRQSourceHandler_t SYSCTL__pvfGetIRQSourceHandler(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptSourceArg)
{
    SYSCTL_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (SYSCTL_pvfIRQSourceHandler_t) 0;
    if((SYSCTL_enMODULE_MAX > enModuleArg) && (SYSCTL_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = SYSCTL_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

SYSCTL_pvfIRQSourceHandler_t* SYSCTL__pvfGetIRQSourceHandlerPointer(SYSCTL_nMODULE enModuleArg, SYSCTL_nINT enInterruptSourceArg)
{
    SYSCTL_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (SYSCTL_pvfIRQSourceHandler_t*) 0;
    if((SYSCTL_enMODULE_MAX > enModuleArg) && (SYSCTL_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &SYSCTL_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}


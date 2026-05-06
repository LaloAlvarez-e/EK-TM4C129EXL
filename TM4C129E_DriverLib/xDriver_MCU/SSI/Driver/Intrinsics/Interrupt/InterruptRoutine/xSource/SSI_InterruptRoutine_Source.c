/**
 *
 * @file SSI_InterruptRoutine_Source.c
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
#include <xDriver_MCU/SSI/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/SSI_InterruptRoutine_Source.h>

static SSI_pvfIRQSourceHandler_t SSI_vIRQSourceHandler[(UBase_t) SSI_enMODULE_MAX][(UBase_t) SSI_enINT_MAX] =
{
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
    {
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
         &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy
    },
};

SSI_pvfIRQSourceHandler_t SSI__pvfGetIRQSourceHandler(SSI_nMODULE enModuleArg, SSI_nINT enInterruptSourceArg)
{
    SSI_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (SSI_pvfIRQSourceHandler_t) 0;
    if((SSI_enMODULE_MAX > enModuleArg) && (SSI_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = SSI_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

SSI_pvfIRQSourceHandler_t* SSI__pvfGetIRQSourceHandlerPointer(SSI_nMODULE enModuleArg, SSI_nINT enInterruptSourceArg)
{
    SSI_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (SSI_pvfIRQSourceHandler_t*) 0;
    if((SSI_enMODULE_MAX > enModuleArg) && (SSI_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &SSI_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}


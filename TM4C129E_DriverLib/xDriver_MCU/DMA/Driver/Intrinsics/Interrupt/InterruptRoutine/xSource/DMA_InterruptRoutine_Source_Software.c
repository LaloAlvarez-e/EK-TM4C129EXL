/**
 *
 * @file DMA_InterruptRoutine_Source_Software.c
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
 * @verbatim 1 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/DMA_InterruptRoutine_Source_Software.h>

static DMA_pvfIRQSourceHandler_t DMA_CH_vIRQSourceHandler_Software[(UBase_t)DMA_enMODULE_MAX]
                                                                  [(UBase_t) DMA_enCH_MAX + 1UL] =
{
    {
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,&MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy
    }
};

static DMA_pvfIRQSourceHandler_t DMA_vIRQSourceHandler_Error[(UBase_t)DMA_enMODULE_MAX]
                                                            [(UBase_t) DMA_enINT_ERROR_MAX] =
{
    {
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy
    }
};

DMA_pvfIRQSourceHandler_t DMA__pvfGetIRQSourceHandler_Error(DMA_nMODULE enModuleArg,
                                                            DMA_nINT_ERROR enInterruptSourceArg)
{
    DMA_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (DMA_pvfIRQSourceHandler_t) 0;
    if((DMA_enMODULE_MAX > enModuleArg) && (DMA_enINT_ERROR_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = DMA_vIRQSourceHandler_Error[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}


DMA_pvfIRQSourceHandler_t* DMA__pvfGetIRQSourceHandlerPointer_Error(DMA_nMODULE enModuleArg,
                                                                    DMA_nINT_ERROR enInterruptSourceArg)
{
    DMA_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (DMA_pvfIRQSourceHandler_t*) 0;
    if((DMA_enMODULE_MAX > enModuleArg) && (DMA_enINT_ERROR_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &DMA_vIRQSourceHandler_Error[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}


DMA_pvfIRQSourceHandler_t DMA_CH__pvfGetIRQSourceHandler_Software(DMA_nMODULE enModuleArg,
                                                                  DMA_nCH enChannelArg)
{
    DMA_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (DMA_pvfIRQSourceHandler_t) 0;
    if((DMA_enMODULE_MAX > enModuleArg) && ((DMA_enCH_MAX + 1UL) > enChannelArg))
    {
        pvfFunctionReg = DMA_CH_vIRQSourceHandler_Software[(UBase_t) enModuleArg][(UBase_t) enChannelArg];
    }
    return (pvfFunctionReg);
}


DMA_pvfIRQSourceHandler_t* DMA_CH__pvfGetIRQSourceHandlerPointer_Software(DMA_nMODULE enModuleArg,
                                                                 DMA_nCH enChannelArg)
{
    DMA_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (DMA_pvfIRQSourceHandler_t*) 0;
    if((DMA_enMODULE_MAX > enModuleArg) && ((DMA_enCH_MAX + 1UL) > enChannelArg))
    {
        pvfFunctionReg = &DMA_CH_vIRQSourceHandler_Software[(UBase_t) enModuleArg][(UBase_t) enChannelArg];
    }
    return (pvfFunctionReg);
}

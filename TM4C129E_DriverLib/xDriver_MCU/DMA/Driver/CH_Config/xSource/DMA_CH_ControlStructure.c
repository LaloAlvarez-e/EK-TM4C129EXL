/**
 *
 * @file DMA_CH_ControlStructure.c
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
 * @verbatim 20 sep. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 sep. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/DMA/Driver/CH_Config/xHeader/DMA_CH_ControlStructure.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/DMA/Driver/Intrinsics/DMA_Intrinsics.h>
#include <xDriver_MCU/DMA/Peripheral/DMA_Peripheral.h>

DMA_nERROR DMA_CH__enSetActiveControStructureByMask(DMA_nMODULE enModuleArg, DMA_nCHMASK enChannelMaskArg,
                                                    DMA_nCH_CONTROL enActiveControStructureArg)
{
    DMA_Register_t stRegister;
    DMA_nERROR enErrorReg;

    if(DMA_enCH_CONTROL_PRIMARY == enActiveControStructureArg)
    {
        stRegister.uptrAddress = DMA_CH_ALTCLR_OFFSET;
    }
    else
    {
        stRegister.uptrAddress = DMA_CH_ALTSET_OFFSET;
    }
    stRegister.uxShift = 0UL;
    stRegister.uxMask = MCU_MASK_BASE;
    stRegister.uxValue = (UBase_t) enChannelMaskArg;
    enErrorReg = DMA__enWriteRegister_Direct(enModuleArg, &stRegister);

    return (enErrorReg);
}

DMA_nERROR DMA_CH__enSetActiveControStructureByNumber(DMA_nMODULE enModuleArg, DMA_nCH enChannelArg,
                                      DMA_nCH_CONTROL enActiveControStructureArg)
{
    DMA_Register_t stRegister;
    UBase_t uxValueReg;
    DMA_nERROR enErrorReg;

    enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enChannelArg, (UBase_t) DMA_enCH_MAX);
    if(DMA_enERROR_OK == enErrorReg)
    {
        if(DMA_enCH_CONTROL_PRIMARY == enActiveControStructureArg)
        {
            stRegister.uptrAddress = DMA_CH_ALTCLR_OFFSET;
        }
        else
        {
            stRegister.uptrAddress = DMA_CH_ALTSET_OFFSET;
        }
        uxValueReg = (UBase_t) 1UL << (UBase_t) enChannelArg;
        stRegister.uxShift = 0UL;
        stRegister.uxMask = MCU_MASK_32;
        stRegister.uxValue = uxValueReg;
        enErrorReg = DMA__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}


DMA_nERROR DMA_CH__enGetActiveControStructureByMask(DMA_nMODULE enModuleArg, DMA_nCHMASK enChannelMaskArg,
                                    DMA_nCHMASK* penCHMaskReqArg)
{
    DMA_Register_t stRegister;
    DMA_nERROR enErrorReg;

    enErrorReg = DMA_enERROR_OK;
    if(0UL == (uintptr_t) penCHMaskReqArg)
    {
        enErrorReg = DMA_enERROR_POINTER;
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = DMA_CH_ALTSET_R_SET0_BIT;
        stRegister.uxMask = (UBase_t) enChannelMaskArg;
        stRegister.uptrAddress = DMA_CH_ALTSET_OFFSET;
        enErrorReg = DMA__enReadRegister(enModuleArg, &stRegister);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        *penCHMaskReqArg = (DMA_nCHMASK) stRegister.uxValue;
    }
    return (enErrorReg);
}

DMA_nERROR DMA_CH__enGetActiveControStructureByNumber(DMA_nMODULE enModuleArg, DMA_nCH enChannelArg,
                                    DMA_nCH_CONTROL* penActiveControStructureArg)
{
    DMA_Register_t stRegister;
    DMA_nERROR enErrorReg;

    enErrorReg = DMA_enERROR_OK;
    if(0UL == (uintptr_t) penActiveControStructureArg)
    {
        enErrorReg = DMA_enERROR_POINTER;
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        enErrorReg = (DMA_nERROR) MCU__enCheckParams((UBase_t) enChannelArg, (UBase_t) DMA_enCH_MAX);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        stRegister.uxShift = (UBase_t) enChannelArg;
        stRegister.uxShift += DMA_CH_ALTSET_R_SET0_BIT;
        stRegister.uxMask = DMA_CH_ALTSET_SET0_MASK;
        stRegister.uptrAddress = DMA_CH_ALTSET_OFFSET;
        enErrorReg = DMA__enReadRegister(enModuleArg, &stRegister);
    }
    if(DMA_enERROR_OK == enErrorReg)
    {
        *penActiveControStructureArg = (DMA_nCH_CONTROL) stRegister.uxValue;
    }
    return (enErrorReg);
}

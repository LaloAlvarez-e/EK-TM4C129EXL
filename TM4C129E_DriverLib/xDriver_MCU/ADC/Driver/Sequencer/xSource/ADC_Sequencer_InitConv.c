/**
 *
 * @file ADC_Sequencer_InitConv.c
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
 * @verbatim 22 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 22 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Sequencer/xHeader/ADC_Sequencer_InitConv.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/ADC_Intrinsics.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_Sequencer__enInitConversionByMask(ADC_nMODULE enModuleArg, ADC_nSEQMASK enSequencerMaskArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((uint32_t) enSequencerMaskArg, (uint32_t) ADC_enSEQMASK_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.u32Shift = ADC_PSSI_R_SS0_BIT;
        stRegister.u32Mask = (uint32_t) enSequencerMaskArg;
        stRegister.uptrAddress = ADC_PSSI_OFFSET;
        stRegister.u32Value = (uint32_t) enSequencerMaskArg;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Sequencer__enInitConversionByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg)
{
    ADC_Register_t stRegister;
    ADC_nERROR enErrorReg;

    enErrorReg = (ADC_nERROR) MCU__enCheckParams((uint32_t) enSequencerArg, (uint32_t) ADC_enSEQ_MAX);
    if(ADC_enERROR_OK == enErrorReg)
    {
        stRegister.u32Shift = (uint32_t) enSequencerArg;
        stRegister.u32Shift += ADC_PSSI_R_SS0_BIT;
        stRegister.u32Mask = ADC_PSSI_SS0_MASK;
        stRegister.uptrAddress = ADC_PSSI_OFFSET;
        stRegister.u32Value = ADC_PSSI_SS0_INIT;
        enErrorReg = ADC__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}


/**
 *
 * @file ADC_Sequencer_Fifo.c
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
 * @verbatim 7 sep. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 sep. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/ADC/Driver/Sequencer/xHeader/ADC_Sequencer_Fifo.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/ADC/Driver/Intrinsics/ADC_Intrinsics.h>
#include <xDriver_MCU/ADC/Peripheral/ADC_Peripheral.h>

ADC_nERROR ADC_Sequencer__enGetFifoStatusByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                  ADC_nFIFO* penFifoStatusArg)
{
    ADC_Register_t stRegister;
    UBase_t uxOffsetReg;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) penFifoStatusArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enSequencerArg;
        uxOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
        uxOffsetReg <<= 2UL;
        uxOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
        uxOffsetReg += ADC_SS_FSTAT_OFFSET;

        stRegister.uxShift = 0UL;
        stRegister.uxMask = ADC_SS_FSTAT_R_EMPTY_MASK | ADC_SS_FSTAT_R_FULL_MASK;
        stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        if(0U == stRegister.uxValue)
        {
            *penFifoStatusArg = ADC_enFIFO_VALUES;
        }
        else if (ADC_SS_FSTAT_R_FULL_MASK == stRegister.uxValue)
        {
            *penFifoStatusArg = ADC_enFIFO_FULL;
        }
        else
        {
            *penFifoStatusArg = ADC_enFIFO_EMPTY;
        }
    }
    return (enErrorReg);
}

ADC_nERROR ADC_Sequencer__enGetFifoHeadByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                UBase_t* puxFifoHeadArg)
{
    ADC_Register_t stRegister;
    UBase_t uxOffsetReg;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) puxFifoHeadArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enSequencerArg;
        uxOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
        uxOffsetReg <<= 2UL;
        uxOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
        uxOffsetReg += ADC_SS_FSTAT_OFFSET;

        stRegister.uxShift = ADC_SS_FSTAT_R_HPTR_BIT;
        stRegister.uxMask = ADC_SS_FSTAT_HPTR_MASK;
        stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *puxFifoHeadArg = stRegister.uxValue;
    }

    return (enErrorReg);
}


ADC_nERROR ADC_Sequencer__enGetFifoTailByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                UBase_t* puxFifoTailArg)
{
    ADC_Register_t stRegister;
    UBase_t uxOffsetReg;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) puxFifoTailArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enSequencerArg;
        uxOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
        uxOffsetReg <<= 2UL;
        uxOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
        uxOffsetReg += ADC_SS_FSTAT_OFFSET;

        stRegister.uxShift = ADC_SS_FSTAT_R_TPTR_BIT;
        stRegister.uxMask = ADC_SS_FSTAT_TPTR_MASK;
        stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *puxFifoTailArg = stRegister.uxValue;
    }
    return (enErrorReg);
}


ADC_nERROR ADC_Sequencer__enGetFifoDataByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                UBase_t* puxFifoDataArg)
{
    ADC_Register_t stRegister;
    UBase_t uxOffsetReg;
    ADC_nERROR enErrorReg;
    ADC_nFIFO enFifoStatusReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) puxFifoDataArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (ADC_nERROR) MCU__enCheckParams((UBase_t) enSequencerArg, (UBase_t) ADC_enSEQ_MAX);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        enFifoStatusReg = ADC_enFIFO_INT_UNDEF;
        enErrorReg = ADC_Sequencer__enGetFifoStatusByNumber(enModuleArg, enSequencerArg, &enFifoStatusReg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        if(ADC_enFIFO_EMPTY == enFifoStatusReg)
        {
            enErrorReg = ADC_enERROR_EMPTY;
        }
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enSequencerArg;
        uxOffsetReg *= ADC_SS_REGISTER_NUM; /*Add offset for input sequencer*/
        uxOffsetReg <<= 2UL;
        uxOffsetReg += ADC_SS_REGISTER_BASE_OFFSET;
        uxOffsetReg += ADC_SS_FIFO_OFFSET;

        stRegister.uxShift = ADC_SS_FIFO_R_DATA_BIT;
        stRegister.uxMask = MCU_MASK_BASE;
        stRegister.uptrAddress = (uintptr_t) uxOffsetReg;
        enErrorReg = ADC__enReadRegister(enModuleArg, &stRegister);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *puxFifoDataArg = stRegister.uxValue;
    }

    return (enErrorReg);
}

ADC_nERROR ADC_Sequencer__enGetAllFifoDataByNumber(ADC_nMODULE enModuleArg, ADC_nSEQUENCER enSequencerArg,
                                                   UBase_t* puxFifoDataArg, UBase_t* puxNumberArg)
{
    UBase_t uxCountReg;
    ADC_nERROR enErrorReg;

    enErrorReg = ADC_enERROR_OK;
    if(0UL == (uintptr_t) puxNumberArg)
    {
        enErrorReg = ADC_enERROR_POINTER;
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        uxCountReg = 0U;
        do
        {
            enErrorReg = ADC_Sequencer__enGetFifoDataByNumber(enModuleArg, enSequencerArg, puxFifoDataArg);
            if(ADC_enERROR_OK == enErrorReg)
            {
                puxFifoDataArg += 1U;
                uxCountReg++;
            }
        }while(ADC_enERROR_OK == enErrorReg);
    }
    if(ADC_enERROR_OK == enErrorReg)
    {
        *puxNumberArg = (UBase_t) uxCountReg;
    }
    return (enErrorReg);
}


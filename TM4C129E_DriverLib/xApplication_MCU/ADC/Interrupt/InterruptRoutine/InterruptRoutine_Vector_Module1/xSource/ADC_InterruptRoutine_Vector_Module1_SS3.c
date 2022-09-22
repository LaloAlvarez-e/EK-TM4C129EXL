/**
 *
 * @file ADC_InterruptRoutine_Vector_Module1_SS3.c
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
 * @verbatim 20 nov. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 nov. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/ADC/Interrupt/InterruptRoutine/InterruptRoutine_Vector_Module1/xHeader/ADC_InterruptRoutine_Vector_Module1_SS3.h>

#include <xApplication_MCU/ADC/Intrinsics/xHeader/ADC_Dependencies.h>

void ADC1_SS3__vIRQVectorHandler(void)
{
    uint32_t u32Reg;
    uint32_t u32Ready;
    uint32_t u32RegCompInterrupt;
    uint32_t u32RegCompSelect;
    uint32_t u32RegCompMux;
    uint32_t u32RegCompEnable;
    uint32_t u32RegCompMuxBit;
    uint32_t u32OffsetReg;
    uint32_t u32Pos;
    uint32_t u32ShiftReg;
    uint32_t u32TempReg;
    ADC_pvfIRQSourceHandler_t pvfCallback;

    u32Ready = SYSCTL_PRADC_R;
    if(SYSCTL_PRADC_R_ADC1_NOREADY == (SYSCTL_PRADC_R_ADC1_MASK & u32Ready))
    {
        pvfCallback = ADC_SW__pvfGetIRQSourceHandler(ADC_enMODULE_1, ADC_enSEQ_3);
        pvfCallback(ADC1_BASE, (void*) ADC_enSEQ_3);
    }
    else
    {
        u32Reg = ADC1_ISC_R;
        if(0UL == ((ADC_ISC_R_DMAIN3_MASK | ADC_ISC_R_IN3_MASK | ADC_ISC_R_DCINSS3_MASK ) &u32Reg))
        {
            pvfCallback = ADC_SW__pvfGetIRQSourceHandler(ADC_enMODULE_1, ADC_enSEQ_3);
            pvfCallback(ADC1_BASE, (void*) ADC_enSEQ_3);
        }
        else
        {
            if(u32Reg & ADC_ISC_R_DMAIN3_MASK)
            {
                ADC1_ISC_R =  ADC_ISC_R_DMAIN3_CLEAR;
                pvfCallback = ADC_Sequencer__pvfGetIRQSourceHandler(ADC_enMODULE_1, ADC_enSEQ_3, ADC_enINT_TYPE_DMA);
                pvfCallback(ADC1_BASE, (void*) ADC_enSEQ_3);
            }
            if(u32Reg & ADC_ISC_R_IN3_MASK)
            {
                ADC1_ISC_R =  ADC_ISC_R_IN3_MASK;
                pvfCallback = ADC_Sequencer__pvfGetIRQSourceHandler(ADC_enMODULE_1, ADC_enSEQ_3, ADC_enINT_TYPE_SAMPLE);
                pvfCallback(ADC1_BASE, (void*) ADC_enSEQ_3);
            }
            if(u32Reg & ADC_ISC_R_DCINSS3_MASK)
            {
                ADC1_ISC_R = ADC_ISC_R_DCINSS3_CLEAR;
                pvfCallback = ADC_Sequencer__pvfGetIRQSourceHandler(ADC_enMODULE_1, ADC_enSEQ_3, ADC_enINT_TYPE_COMP);
                pvfCallback(ADC1_BASE, (void*) ADC_enSEQ_3);

                u32RegCompInterrupt = ADC1_DCISC_R;
                u32OffsetReg = ADC_DC_CTL_OFFSET;
                u32RegCompMux = ADC1_SS3_DC_R;
                u32RegCompSelect = ADC1_SS3_OP_R;
                u32ShiftReg = 0x1UL;
                for(u32Pos = (uint32_t) ADC_enSAMPLE_0; u32Pos < (uint32_t) ADC_enSAMPLE_1; u32Pos++)
                {
                    if(u32RegCompSelect & u32ShiftReg)
                    {
                        u32TempReg = u32RegCompMux;
                        u32TempReg &= 0xFUL;
                        u32RegCompMuxBit = 1UL;
                        u32RegCompMuxBit <<= u32TempReg;
                        if(u32RegCompInterrupt & u32RegCompMuxBit)
                        {
                            u32RegCompEnable = *((uint32_t*) u32OffsetReg);

                            if(u32RegCompEnable & ADC_DC_CTL_R_CIE_MASK)
                            {
                                ADC1_DCISC_R = (uint32_t) u32RegCompMuxBit;
                                pvfCallback = ADC_Comparator__pvfGetIRQSourceHandler(ADC_enMODULE_1, ADC_enSEQ_3, (ADC_nCOMPARATOR) u32TempReg);
                                pvfCallback(ADC1_BASE, (void*) u32TempReg);
                            }
                        }
                    }
                    u32OffsetReg += 4UL;
                    u32RegCompMux >>= 2UL;
                    u32ShiftReg <<= 4UL;
                }
            }
        }
    }
}

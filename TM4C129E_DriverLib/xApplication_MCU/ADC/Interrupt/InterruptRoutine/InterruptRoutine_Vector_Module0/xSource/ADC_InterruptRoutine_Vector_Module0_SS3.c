/**
 *
 * @file ADC_InterruptRoutine_Vector_Module0_SS3.c
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
#include <xApplication_MCU/ADC/Interrupt/InterruptRoutine/InterruptRoutine_Vector_Module0/xHeader/ADC_InterruptRoutine_Vector_Module0_SS3.h>

#include <xApplication_MCU/ADC/Intrinsics/xHeader/ADC_Dependencies.h>

void ADC0_SS3__vIRQVectorHandler(void)
{
    UBase_t uxReg;
    UBase_t uxReady;
    UBase_t uxRegCompInterrupt;
    UBase_t uxRegCompSelect;
    UBase_t uxRegCompMux;
    UBase_t uxRegCompEnable;
    UBase_t uxRegCompMuxBit;
    UBase_t uxOffsetReg;
    UBase_t uxPos;
    UBase_t uxShiftReg;
    UBase_t uxTempReg;
    ADC_pvfIRQSourceHandler_t pvfCallback;

    uxReady = SYSCTL_PRADC_R;
    if(SYSCTL_PRADC_R_ADC0_NOREADY == (SYSCTL_PRADC_R_ADC0_MASK & uxReady))
    {
        pvfCallback = ADC_SW__pvfGetIRQSourceHandler(ADC_enMODULE_0, ADC_enSEQ_3);
        pvfCallback(ADC0_BASE, (void*) ADC_enSEQ_3);
    }
    else
    {
        uxReg = ADC0_ISC_R;
        if(0UL == ((ADC_ISC_R_DMAIN3_MASK | ADC_ISC_R_IN3_MASK | ADC_ISC_R_DCINSS3_MASK ) &uxReg))
        {
            pvfCallback = ADC_SW__pvfGetIRQSourceHandler(ADC_enMODULE_0, ADC_enSEQ_3);
            pvfCallback(ADC0_BASE, (void*) ADC_enSEQ_3);
        }
        else
        {
            if(uxReg & ADC_ISC_R_DMAIN3_MASK)
            {
                ADC0_ISC_R =  ADC_ISC_R_DMAIN3_CLEAR;
                pvfCallback = ADC_Sequencer__pvfGetIRQSourceHandler(ADC_enMODULE_0, ADC_enSEQ_3, ADC_enINT_TYPE_DMA);
                pvfCallback(ADC0_BASE, (void*) ADC_enSEQ_3);
            }
            if(uxReg & ADC_ISC_R_IN3_MASK)
            {
                ADC0_ISC_R =  ADC_ISC_R_IN3_MASK;
                pvfCallback = ADC_Sequencer__pvfGetIRQSourceHandler(ADC_enMODULE_0, ADC_enSEQ_3, ADC_enINT_TYPE_SAMPLE);
                pvfCallback(ADC0_BASE, (void*) ADC_enSEQ_3);
            }
            if(uxReg & ADC_ISC_R_DCINSS3_MASK)
            {
                ADC0_ISC_R = ADC_ISC_R_DCINSS3_CLEAR;
                pvfCallback = ADC_Sequencer__pvfGetIRQSourceHandler(ADC_enMODULE_0, ADC_enSEQ_3, ADC_enINT_TYPE_COMP);
                pvfCallback(ADC0_BASE, (void*) ADC_enSEQ_3);

                uxRegCompInterrupt = ADC0_DCISC_R;
                uxOffsetReg = ADC0_DC0_CTL_R;
                uxRegCompMux = ADC0_SS3_DC_R;
                uxRegCompSelect = ADC0_SS3_OP_R;
                uxShiftReg = 0x1UL;
                for(uxPos = (UBase_t) ADC_enSAMPLE_0; uxPos < (UBase_t) ADC_enSAMPLE_1; uxPos++)
                {
                    if(uxRegCompSelect & uxShiftReg)
                    {
                        uxTempReg = uxRegCompMux;
                        uxTempReg &= 0xFUL;
                        uxRegCompMuxBit = 1UL;
                        uxRegCompMuxBit <<= uxTempReg;
                        if(uxRegCompInterrupt & uxRegCompMuxBit)
                        {
                            uxRegCompEnable = *((volatile UBase_t*) uxOffsetReg);

                            if(uxRegCompEnable & ADC_DC_CTL_R_CIE_MASK)
                            {
                                ADC0_DCISC_R = (UBase_t) uxRegCompMuxBit;
                                pvfCallback = ADC_Comparator__pvfGetIRQSourceHandler(ADC_enMODULE_0, ADC_enSEQ_3, (ADC_nCOMPARATOR) uxTempReg);
                                pvfCallback(ADC0_BASE, (void*) uxTempReg);
                            }
                        }
                    }
                    uxOffsetReg += 4UL;
                    uxRegCompMux >>= 2UL;
                    uxShiftReg <<= 4UL;
                }
            }
        }
    }
}

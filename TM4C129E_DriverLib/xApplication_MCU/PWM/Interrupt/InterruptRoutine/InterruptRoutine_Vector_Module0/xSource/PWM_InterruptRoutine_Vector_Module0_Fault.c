/**
 *
 * @file PWM_InterruptRoutine_Vector_Module0_Fault.c
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
 * @verbatim 9 ene. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 ene. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/PWM/Interrupt/InterruptRoutine/InterruptRoutine_Vector_Module0/xHeader/PWM_InterruptRoutine_Vector_Module0_Fault.h>

#include <xApplication_MCU/PWM/Intrinsics/xHeader/PWM_Dependencies.h>

void PWM0_Fault__vIRQVectorHandler(void)
{
    volatile uint32_t u32Reg = 0UL;
    volatile uint32_t u32Ready = 0U;
    void(*pvfCallback)(void)  = (void(*)(void)) 0UL;

    u32Ready = SYSCTL_PRPWM_R;
    if(SYSCTL_PRPWM_R_PWM0_NOREADY == (SYSCTL_PRPWM_R_PWM0_MASK & u32Ready))
    {
        pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                     PWM_enFAULT_0, PWM_enFAULT_INTERRUPT_SW);
        pvfCallback();

        pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                     PWM_enFAULT_1, PWM_enFAULT_INTERRUPT_SW);
        pvfCallback();

        pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                     PWM_enFAULT_2, PWM_enFAULT_INTERRUPT_SW);
        pvfCallback();

        pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                     PWM_enFAULT_3, PWM_enFAULT_INTERRUPT_SW);
        pvfCallback();
    }
    else
    {
        u32Reg = PWM0_ISC_R;
        if(0UL == (PWM_enFAULTMASK_ALL & u32Reg))
        {
            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                         PWM_enFAULT_0, PWM_enFAULT_INTERRUPT_SW);
            pvfCallback();

            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                         PWM_enFAULT_1, PWM_enFAULT_INTERRUPT_SW);
            pvfCallback();

            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                         PWM_enFAULT_2, PWM_enFAULT_INTERRUPT_SW);
            pvfCallback();

            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                         PWM_enFAULT_3, PWM_enFAULT_INTERRUPT_SW);
            pvfCallback();
        }
        else
        {
            if(PWM_enFAULTMASK_0 & u32Reg)
            {
                PWM0_ISC_R = (uint32_t) PWM_enFAULTMASK_0;

                volatile uint32_t u32SourceReg = PWM0_GEN0_CTL_R;
                u32SourceReg &= (PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK);
                if(((PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK) == u32SourceReg))
                {
                    uint32_t u32Count = 0UL;
                    volatile uint32_t u32InputValueReg = PWM0_GEN0_EXT_FLTSTAT0_R;
                    volatile uint32_t u32DCompValueReg = PWM0_GEN0_EXT_FLTSTAT1_R;
                    volatile uint32_t u32InputEnableReg = PWM0_GEN0_FLTSRC0_R;
                    volatile uint32_t u32DCompEnableReg = PWM0_GEN0_FLTSRC1_R;
                    PWM0_GEN0_EXT_FLTSTAT0_R = PWM_enFAULT_INPUT_ALL;
                    PWM0_GEN0_EXT_FLTSTAT1_R = PWM_enFAULT_DCOMP_ALL;


                    u32InputEnableReg &= u32InputValueReg;
                    u32DCompEnableReg &= u32DCompValueReg;

                    while(0UL != u32InputEnableReg)
                    {
                        uint32_t u32Temp = u32InputEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_FAULT;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_0,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32InputEnableReg >>= 1UL;
                        u32Count++;
                    }

                    u32Count = 0UL;
                    while(0UL != u32DCompEnableReg)
                    {
                        uint32_t u32Temp = u32DCompEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_DCMP0;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_0,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32DCompEnableReg >>= 1UL;
                        u32Count++;
                    }
                }
                else
                {
                    pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                     PWM_enFAULT_0,
                                                                     PWM_enFAULT_INTERRUPT_FAULT);
                    pvfCallback();
                }
            }
            if(PWM_enFAULTMASK_1 & u32Reg)
            {
                PWM0_ISC_R = (uint32_t) PWM_enFAULTMASK_1;

                volatile uint32_t u32SourceReg = (uint32_t) PWM0_GEN1_CTL_R;
                u32SourceReg &= (PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK);
                if(((PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK) == u32SourceReg))
                {
                    uint32_t u32Count = 0UL;
                    volatile uint32_t u32InputValueReg = (uint32_t) PWM0_GEN1_EXT_FLTSTAT0_R;
                    volatile uint32_t u32DCompValueReg = (uint32_t) PWM0_GEN1_EXT_FLTSTAT1_R;
                    volatile uint32_t u32InputEnableReg = (uint32_t) PWM0_GEN1_FLTSRC0_R;
                    volatile uint32_t u32DCompEnableReg = (uint32_t) PWM0_GEN1_FLTSRC1_R;
                    PWM0_GEN1_EXT_FLTSTAT0_R = PWM_enFAULT_INPUT_ALL;
                    PWM0_GEN1_EXT_FLTSTAT1_R = PWM_enFAULT_DCOMP_ALL;


                    u32InputEnableReg &= u32InputValueReg;
                    u32DCompEnableReg &= u32DCompValueReg;

                    while(0UL != u32InputEnableReg)
                    {
                        uint32_t u32Temp = u32InputEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_FAULT;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_1,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32InputEnableReg >>= 1UL;
                        u32Count++;
                    }

                    u32Count = 0UL;
                    while(0UL != u32DCompEnableReg)
                    {
                        uint32_t u32Temp = u32DCompEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_DCMP0;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_1,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32DCompEnableReg >>= 1UL;
                        u32Count++;
                    }
                }
                else
                {
                    pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                     PWM_enFAULT_1,
                                                                     PWM_enFAULT_INTERRUPT_FAULT);
                    pvfCallback();
                }
            }
            if(PWM_enFAULTMASK_2 & u32Reg)
            {
                PWM0_ISC_R = (uint32_t) PWM_enFAULTMASK_2;

                volatile uint32_t u32SourceReg = (uint32_t) PWM0_GEN2_CTL_R;
                u32SourceReg &= (PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK);
                if(((PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK) == u32SourceReg))
                {
                    uint32_t u32Count = 0UL;
                    volatile uint32_t u32InputValueReg = (uint32_t) PWM0_GEN2_EXT_FLTSTAT0_R;
                    volatile uint32_t u32DCompValueReg = (uint32_t) PWM0_GEN2_EXT_FLTSTAT1_R;
                    volatile uint32_t u32InputEnableReg = (uint32_t) PWM0_GEN2_FLTSRC0_R;
                    volatile uint32_t u32DCompEnableReg = (uint32_t) PWM0_GEN2_FLTSRC1_R;
                    PWM0_GEN2_EXT_FLTSTAT0_R = PWM_enFAULT_INPUT_ALL;
                    PWM0_GEN2_EXT_FLTSTAT1_R = PWM_enFAULT_DCOMP_ALL;


                    u32InputEnableReg &= u32InputValueReg;
                    u32DCompEnableReg &= u32DCompValueReg;

                    while(0UL != u32InputEnableReg)
                    {
                        uint32_t u32Temp = u32InputEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_FAULT;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_2,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32InputEnableReg >>= 1UL;
                        u32Count++;
                    }

                    u32Count = 0UL;
                    while(0UL != u32DCompEnableReg)
                    {
                        uint32_t u32Temp = u32DCompEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_DCMP0;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_2,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32DCompEnableReg >>= 1UL;
                        u32Count++;
                    }
                }
                else
                {
                    pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                     PWM_enFAULT_2,
                                                                     PWM_enFAULT_INTERRUPT_FAULT);
                    pvfCallback();
                }
            }
            if(PWM_enFAULTMASK_3 & u32Reg)
            {
                PWM0_ISC_R = (uint32_t) PWM_enFAULTMASK_3;

                volatile uint32_t u32SourceReg = (uint32_t) PWM0_GEN3_CTL_R;
                u32SourceReg &= (PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK);
                if(((PWM_GEN_CTL_R_FLTSRC_MASK | PWM_GEN_CTL_R_LATCH_MASK) == u32SourceReg))
                {
                    uint32_t u32Count = 0UL;
                    volatile uint32_t u32InputValueReg = (uint32_t) PWM0_GEN3_EXT_FLTSTAT0_R;
                    volatile uint32_t u32DCompValueReg = (uint32_t) PWM0_GEN3_EXT_FLTSTAT1_R;
                    volatile uint32_t u32InputEnableReg = (uint32_t) PWM0_GEN3_FLTSRC0_R;
                    volatile uint32_t u32DCompEnableReg = (uint32_t) PWM0_GEN3_FLTSRC1_R;
                    PWM0_GEN3_EXT_FLTSTAT0_R = PWM_enFAULT_INPUT_ALL;
                    PWM0_GEN3_EXT_FLTSTAT1_R = PWM_enFAULT_DCOMP_ALL;


                    u32InputEnableReg &= u32InputValueReg;
                    u32DCompEnableReg &= u32DCompValueReg;

                    while(0UL != u32InputEnableReg)
                    {
                        uint32_t u32Temp = u32InputEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_FAULT;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_3,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32InputEnableReg >>= 1UL;
                        u32Count++;
                    }

                    u32Count = 0UL;
                    while(0UL != u32DCompEnableReg)
                    {
                        uint32_t u32Temp = u32DCompEnableReg;
                        u32Temp &= 0x1UL;
                        if(0UL != u32Temp)
                        {
                            uint32_t u32Index = (uint32_t) PWM_enFAULT_INTERRUPT_DCMP0;
                            u32Index += u32Count;
                            pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                             PWM_enFAULT_3,
                                                                             (PWM_nFAULT_INTERRUPT) u32Index);
                            pvfCallback();

                        }
                        u32DCompEnableReg >>= 1UL;
                        u32Count++;
                    }
                }
                else
                {
                    pvfCallback = PWM_Fault__pvfGetIRQSourceHandler(PWM_enMODULE_0,
                                                                     PWM_enFAULT_3,
                                                                     PWM_enFAULT_INTERRUPT_FAULT);
                    pvfCallback();
                }
            }
        }
    }
}

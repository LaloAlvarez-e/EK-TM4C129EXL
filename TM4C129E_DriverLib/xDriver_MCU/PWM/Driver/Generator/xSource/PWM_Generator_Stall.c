/**
 *
 * @file PWM_Generator_Stall.c
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
 * @verbatim 7 ene. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 7 ene. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/PWM/Driver/Generator/xHeader/PWM_Generator_Stall.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/PWM/Driver/Intrinsics/PWM_Intrinsics.h>
#include <xDriver_MCU/PWM/Peripheral/PWM_Peripheral.h>

PWM_nERROR PWM_Generator__enSetStallModeByNumber(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nSTALL enStallArg)
{
    PWM_Register_t stRegister;
    UBase_t uxOffsetReg;
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enGeneratorArg, (UBase_t) PWM_enGEN_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enGeneratorArg;
        uxOffsetReg *= PWM_GEN_REGISTER_NUM; /*Add offset for input sequencer*/
        uxOffsetReg *= 4UL;
        uxOffsetReg += PWM_GEN_REGISTER_BASE_OFFSET;
        uxOffsetReg += PWM_GEN_CTL_OFFSET;

        stRegister.uxShift = PWM_GEN_CTL_R_DEBUG_BIT;
        stRegister.uxMask = PWM_GEN_CTL_DEBUG_MASK;
        stRegister.uptrAddress = (UBase_t) uxOffsetReg;
        stRegister.uxValue = (UBase_t) enStallArg;
        enErrorReg = PWM__enWriteRegister(enModuleArg, &stRegister);
    }

    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enSetStallModeByMask(PWM_nMODULE enModuleArg, PWM_nGENMASK enGeneratorMaskArg, PWM_nSTALL enStallArg)
{
    UBase_t uxGenMaskReg;
    UBase_t uxGenerator;
    PWM_nERROR enErrorReg;

    enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enGeneratorMaskArg, (UBase_t) PWM_enGENMASK_MAX);
    if(PWM_enERROR_OK == enErrorReg)
    {
        uxGenerator = 0UL;
        uxGenMaskReg = (UBase_t) enGeneratorMaskArg;
        while((0UL != uxGenMaskReg) && (PWM_enERROR_OK == enErrorReg))
        {
            if(0UL != (1UL & uxGenMaskReg))
            {
                enErrorReg = PWM_Generator__enSetStallModeByNumber(enModuleArg, (PWM_nGENERATOR) uxGenerator, enStallArg);
            }
            uxGenMaskReg >>= 1UL;
            uxGenerator++;
        }
    }
    return (enErrorReg);
}


PWM_nERROR PWM_Generator__enGetStallModeByNumber(PWM_nMODULE enModuleArg, PWM_nGENERATOR enGeneratorArg, PWM_nSTALL* penStallArg)
{
    PWM_Register_t stRegister;
    UBase_t uxOffsetReg;
    PWM_nERROR enErrorReg;

    enErrorReg = PWM_enERROR_OK;
    if(0UL == (uintptr_t) penStallArg)
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enGeneratorArg, (UBase_t) PWM_enGEN_MAX);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        uxOffsetReg = (UBase_t) enGeneratorArg;
        uxOffsetReg *= PWM_GEN_REGISTER_NUM; /*Add offset for input sequencer*/
        uxOffsetReg *= 4UL;
        uxOffsetReg += PWM_GEN_REGISTER_BASE_OFFSET;
        uxOffsetReg += PWM_GEN_CTL_OFFSET;

        stRegister.uxShift = PWM_GEN_CTL_R_DEBUG_BIT;
        stRegister.uxMask = PWM_GEN_CTL_DEBUG_MASK;
        stRegister.uptrAddress = (UBase_t) uxOffsetReg;
        enErrorReg = PWM__enReadRegister(enModuleArg, &stRegister);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        *penStallArg = (PWM_nSTALL) stRegister.uxValue;
    }
    return (enErrorReg);
}

PWM_nERROR PWM_Generator__enGetStallModeByMask(PWM_nMODULE enModuleArg, PWM_nGENMASK enGeneratorMaskArg, PWM_nGENMASK* penStallArg)
{
    UBase_t uxGenMaskReg;
    UBase_t uxGenerator;
    UBase_t uxGeneratorGetReg;
    UBase_t uxValueReg;
    PWM_nSTALL enTempReg;
    PWM_nERROR enErrorReg;

    uxGeneratorGetReg = 0UL;
    enErrorReg = PWM_enERROR_OK;
    if(0UL == (uintptr_t) penStallArg)
    {
        enErrorReg = PWM_enERROR_POINTER;
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (PWM_nERROR) MCU__enCheckParams((UBase_t) enGeneratorMaskArg, (UBase_t) PWM_enGENMASK_MAX);
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        uxGenerator = 0UL;
        uxValueReg = 1UL;
        uxGenMaskReg = (UBase_t) enGeneratorMaskArg;
        while((0UL != uxGenMaskReg) && (PWM_enERROR_OK == enErrorReg))
        {
            if(0UL != (1UL & uxGenMaskReg))
            {
                enTempReg = PWM_enSTALL_FREEZE;
                enErrorReg = PWM_Generator__enGetStallModeByNumber(enModuleArg, (PWM_nGENERATOR) uxGenerator, &enTempReg);
                if(PWM_enERROR_OK == enErrorReg)
                {
                    if(PWM_enSTALL_FREEZE != enTempReg)
                    {
                        uxGeneratorGetReg |= uxValueReg;
                    }
                }
            }
            uxValueReg <<= 1UL;
            uxGenMaskReg >>= 1UL;
            uxGenerator++;
        }
    }
    if(PWM_enERROR_OK == enErrorReg)
    {
        *penStallArg = (PWM_nGENMASK) uxGeneratorGetReg;
    }
    return (enErrorReg);
}

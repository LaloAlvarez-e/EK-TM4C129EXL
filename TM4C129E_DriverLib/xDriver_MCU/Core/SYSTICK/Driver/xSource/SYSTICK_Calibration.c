/**
 *
 * @file SYSTICK_Calibration.c
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 29 mar. 2026     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/SYSTICK/Driver/xHeader/SYSTICK_Calibration.h>

#include <xDriver_MCU/Core/SYSTICK/Peripheral/SYSTICK_Peripheral.h>
#include <xDriver_MCU/Core/SYSTICK/Driver/Intrinsics/Primitives/SYSTICK_Primitives.h>

SYSTICK_nERROR SYSTICK__enGetCalibrationValue(SYSTICK_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    SYSTICK_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        SYSTICK_Register_t stRegister;
        stRegister.uxShift = SYSTICK_CR_R_TENMS_BIT;
        stRegister.uxMask = SYSTICK_CR_TENMS_MASK;
        stRegister.uptrAddress = SYSTICK_CR_OFFSET;
        enErrorReg = SYSTICK__enReadRegister(enModuleArg, &stRegister);
        if(SYSTICK_enERROR_OK == enErrorReg)
        {
            *puxValueArg = stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetCalibrationSkew(SYSTICK_nMODULE enModuleArg, SYSTICK_nSKEW* penValueArg)
{
    SYSTICK_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penValueArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        SYSTICK_Register_t stRegister;
        stRegister.uxShift = SYSTICK_CR_R_SKEW_BIT;
        stRegister.uxMask = SYSTICK_CR_SKEW_MASK;
        stRegister.uptrAddress = SYSTICK_CR_OFFSET;
        enErrorReg = SYSTICK__enReadRegister(enModuleArg, &stRegister);
        if(SYSTICK_enERROR_OK == enErrorReg)
        {
            *penValueArg = (SYSTICK_nSKEW) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSTICK_nERROR SYSTICK__enGetCalibrationReference(SYSTICK_nMODULE enModuleArg, SYSTICK_nREFERENCE* penValueArg)
{
    SYSTICK_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penValueArg) ? SYSTICK_enERROR_POINTER : SYSTICK_enERROR_OK;
    if(SYSTICK_enERROR_OK == enErrorReg)
    {
        SYSTICK_Register_t stRegister;
        stRegister.uxShift = SYSTICK_CR_R_NOREF_BIT;
        stRegister.uxMask = SYSTICK_CR_NOREF_MASK;
        stRegister.uptrAddress = SYSTICK_CR_OFFSET;
        enErrorReg = SYSTICK__enReadRegister(enModuleArg, &stRegister);
        if(SYSTICK_enERROR_OK == enErrorReg)
        {
            *penValueArg = (SYSTICK_nREFERENCE) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

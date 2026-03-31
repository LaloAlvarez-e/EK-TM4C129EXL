/**
 *
 * @file SYSCTL_InternalOsc.c
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
 * @verbatim 28 oct. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 28 oct. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_InternalOsc.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/SYSCTL_Primitives.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

SYSCTL_nERROR SYSCTL__enGetPIOSCCalibrationResult(SYSCTL_nMODULE enModuleArg, SYSCTL_nPIOSC_RESULT* puxResultArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxResultArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_STAT_R_RESULT_BIT;
        stRegister.uxMask = PIOSC_STAT_RESULT_MASK;
        stRegister.uptrAddress = PIOSC_STAT_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxResultArg = (SYSCTL_nPIOSC_RESULT) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPIOSCCalibrationValue(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_STAT_R_CT_BIT;
        stRegister.uxMask = PIOSC_STAT_CT_MASK;
        stRegister.uptrAddress = PIOSC_STAT_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = (UBase_t) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPIOSCDefaultCalibrationValue(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_STAT_R_DT_BIT;
        stRegister.uxMask = PIOSC_STAT_DT_MASK;
        stRegister.uptrAddress = PIOSC_STAT_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = (UBase_t) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enSetPIOSCUserCalibrationValue(SYSCTL_nMODULE enModuleArg, UBase_t uxValueArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = PIOSC_CAL_R_UT_BIT;
    stRegister.uxMask = PIOSC_CAL_UT_MASK;
    stRegister.uptrAddress = PIOSC_CAL_OFFSET;
    stRegister.uxValue = (UBase_t) uxValueArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enGetPIOSCUserCalibrationValue(SYSCTL_nMODULE enModuleArg, UBase_t* puxValueArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) puxValueArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_CAL_R_UT_BIT;
        stRegister.uxMask = PIOSC_CAL_UT_MASK;
        stRegister.uptrAddress = PIOSC_CAL_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *puxValueArg = (UBase_t) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enUsePIOSCUserCalibrationValue(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN enStatusArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = PIOSC_CAL_R_UTEN_BIT;
    stRegister.uxMask = PIOSC_CAL_UTEN_MASK;
    stRegister.uptrAddress = PIOSC_CAL_OFFSET;
    stRegister.uxValue = (UBase_t) enStatusArg;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enIsPIOSCUserCalibrationValueUsed(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_CAL_R_UTEN_BIT;
        stRegister.uxMask = PIOSC_CAL_UTEN_MASK;
        stRegister.uptrAddress = PIOSC_CAL_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (SYSCTL_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enUpdatePIOSCCalibrationValue(SYSCTL_nMODULE enModuleArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = PIOSC_CAL_R_UPDATE_BIT;
    stRegister.uxMask = PIOSC_CAL_UPDATE_MASK;
    stRegister.uptrAddress = PIOSC_CAL_OFFSET;
    stRegister.uxValue = PIOSC_CAL_UPDATE_UPDATE;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enIsPIOCCalibrationValueUpdateOngoing(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_CAL_R_UPDATE_BIT;
        stRegister.uxMask = PIOSC_CAL_UPDATE_MASK;
        stRegister.uptrAddress = PIOSC_CAL_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (SYSCTL_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}


SYSCTL_nERROR SYSCTL__enStartPIOSCCalibration(SYSCTL_nMODULE enModuleArg)
{
    SYSCTL_Register_t stRegister;
    stRegister.uxShift = PIOSC_CAL_R_CAL_BIT;
    stRegister.uxMask = PIOSC_CAL_CAL_MASK;
    stRegister.uptrAddress = PIOSC_CAL_OFFSET;
    stRegister.uxValue = PIOSC_CAL_CAL_START;

    SYSCTL_nERROR enErrorReg;
    enErrorReg = SYSCTL__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

SYSCTL_nERROR SYSCTL__enIsPIOCCalibrationOngoing(SYSCTL_nMODULE enModuleArg, SYSCTL_nBOOLEAN* penStatusArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK == enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uxShift = PIOSC_CAL_R_CAL_BIT;
        stRegister.uxMask = PIOSC_CAL_CAL_MASK;
        stRegister.uptrAddress = PIOSC_CAL_OFFSET;
        enErrorReg = SYSCTL__enReadRegister(enModuleArg, &stRegister);
        if(SYSCTL_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (SYSCTL_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

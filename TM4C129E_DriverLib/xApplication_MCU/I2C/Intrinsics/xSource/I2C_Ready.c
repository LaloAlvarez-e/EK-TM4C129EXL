/**
 *
 * @file I2C_Ready.c
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
 * @verbatim 13 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 13 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/I2C/Intrinsics/xHeader/I2C_Ready.h>

#include <xApplication_MCU/I2C/Intrinsics/xHeader/I2C_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_I2C[(UBase_t) I2C_enMODULE_MAX] =
{
 SYSCTL_enI2C0, SYSCTL_enI2C1, SYSCTL_enI2C2, SYSCTL_enI2C3, SYSCTL_enI2C4,
 SYSCTL_enI2C5, SYSCTL_enI2C6, SYSCTL_enI2C7, SYSCTL_enI2C8, SYSCTL_enI2C9
};

I2C_nERROR I2C__enSetReadyOnRunMode(I2C_nMODULE enModuleArg)
{
    I2C_nERROR enErrorReg;

    enErrorReg = (I2C_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) I2C_enMODULE_MAX);
    if(I2C_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_I2C[(UBase_t) enModuleArg];
        enErrorReg = (I2C_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

I2C_nERROR I2C__enClearReadyOnRunMode(I2C_nMODULE enModuleArg)
{
    I2C_nERROR enErrorReg;

    enErrorReg = (I2C_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) I2C_enMODULE_MAX);
    if(I2C_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_I2C[(UBase_t) enModuleArg];
        enErrorReg = (I2C_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

I2C_nERROR I2C__enReset(I2C_nMODULE enModuleArg)
{
    I2C_nERROR enErrorReg;

    enErrorReg = (I2C_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) I2C_enMODULE_MAX);
    if(I2C_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_I2C[(UBase_t) enModuleArg];
        enErrorReg = (I2C_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

I2C_nERROR I2C__enIsReady(I2C_nMODULE enModuleArg, I2C_nBOOLEAN* penReadyArg)
{
    I2C_nERROR enErrorReg;

    enErrorReg = I2C_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = I2C_enERROR_POINTER;
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        enErrorReg = (I2C_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) I2C_enMODULE_MAX);
    }
    if(I2C_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_I2C[(UBase_t) enModuleArg];
        enErrorReg = (I2C_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

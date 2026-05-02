/**
 *
 * @file EEPROM_Ready.c
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
 * @verbatim 11 ago. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 11 ago. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xApplication_MCU/EEPROM/Intrinsics/xHeader/EEPROM_Ready.h>

#include <xApplication_MCU/EEPROM/Intrinsics/xHeader/EEPROM_Dependencies.h>

static const SYSCTL_nPERIPHERAL SYSCTL_VECTOR_EEPROM[(UBase_t) EEPROM_enMODULE_MAX] =
{
 SYSCTL_enEEPROM
};

EEPROM_nERROR EEPROM__enSetReadyOnRunMode(EEPROM_nMODULE enModuleArg)
{
    EEPROM_nERROR enErrorReg;

    enErrorReg = (EEPROM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) EEPROM_enMODULE_MAX);
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_EEPROM[(UBase_t) enModuleArg];
        enErrorReg = (EEPROM_nERROR) SYSCTL__enSetReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

EEPROM_nERROR EEPROM__enClearReadyOnRunMode(EEPROM_nMODULE enModuleArg)
{
    EEPROM_nERROR enErrorReg;

    enErrorReg = (EEPROM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) EEPROM_enMODULE_MAX);
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_EEPROM[(UBase_t) enModuleArg];
        enErrorReg = (EEPROM_nERROR) SYSCTL__enClearReadyOnRunMode(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

EEPROM_nERROR EEPROM__enReset(EEPROM_nMODULE enModuleArg)
{
    EEPROM_nERROR enErrorReg;

    enErrorReg = (EEPROM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) EEPROM_enMODULE_MAX);
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_EEPROM[(UBase_t) enModuleArg];
        enErrorReg = (EEPROM_nERROR) SYSCTL__enSetPeripheralReset(SYSCTL_enMODULE_0, enPeripheralReg);
    }
    return (enErrorReg);
}

EEPROM_nERROR EEPROM__enIsReady(EEPROM_nMODULE enModuleArg, EEPROM_nBOOLEAN* penReadyArg)
{
    EEPROM_nERROR enErrorReg;

    enErrorReg = EEPROM_enERROR_OK;
    if(0UL == (uintptr_t) penReadyArg)
    {
        enErrorReg = EEPROM_enERROR_POINTER;
    }
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (EEPROM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) EEPROM_enMODULE_MAX);
    }
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        SYSCTL_nPERIPHERAL enPeripheralReg = SYSCTL_VECTOR_EEPROM[(UBase_t) enModuleArg];
        enErrorReg = (EEPROM_nERROR) SYSCTL__enIsReady(SYSCTL_enMODULE_0, enPeripheralReg, (SYSCTL_nBOOLEAN*) penReadyArg);
    }
    return (enErrorReg);
}

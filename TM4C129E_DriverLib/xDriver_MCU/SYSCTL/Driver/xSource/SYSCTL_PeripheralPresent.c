/**
 *
 * @file SYSCTL_PeripheralPresent.c
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
 * @verbatim 24 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 24 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralPresent.h>

#include <xDriver_MCU/SYSCTL/Driver/xHeader/SYSCTL_PeripheralGeneric.h>
#include <xDriver_MCU/SYSCTL/Peripheral/SYSCTL_Peripheral.h>

SYSCTL_nERROR SYSCTL__enIsPeripheralPresent(SYSCTL_nMODULE enModuleArg, SYSCTL_nPERIPHERAL enPeripheralArg, SYSCTL_nBOOLEAN* penStateArg)
{
    SYSCTL_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penStateArg) ? SYSCTL_enERROR_POINTER : SYSCTL_enERROR_OK;
    if(SYSCTL_enERROR_OK ==  enErrorReg)
    {
        SYSCTL_Register_t stRegister;
        stRegister.uptrAddress = SYSCTL_PP_OFFSET;
        enErrorReg =SYSCTL__enReadPeripheral(enModuleArg, enPeripheralArg, &stRegister);
        if(SYSCTL_enERROR_OK ==  enErrorReg)
        {
            *penStateArg = (SYSCTL_nBOOLEAN) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

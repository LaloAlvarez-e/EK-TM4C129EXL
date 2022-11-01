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

SYSCTL_nBOOLEAN SYSCTL__enIsPeripheralPresent(SYSCTL_nPERIPHERAL enPeripheral)
{
    SYSCTL_nBOOLEAN enPresentReg = SYSCTL_enFALSE;
    enPresentReg = (SYSCTL_nBOOLEAN) SYSCTL__uxReadPeripheral(enPeripheral,
                                                                      SYSCTL_PP_OFFSET);
    return (enPresentReg);
}

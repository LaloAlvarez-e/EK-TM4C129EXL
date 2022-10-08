/**
 *
 * @file CAN_RegisterPeripheral.c
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
 * @verbatim Apr 15, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 15, 2021        indevicemex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/CAN/Peripheral/Register/RegisterPeripheral/CAN_RegisterPeripheral.h>

uintptr_t CAN__uptrBlockBaseAddress(CAN_nMODULE enModuleArg)
{
    const uintptr_t CAN_BLOCK_BASE[(UBase_t) CAN_enMODULE_MAX] =
    {
     CAN0_BASE, CAN1_BASE
    };
    return (CAN_BLOCK_BASE[(UBase_t) enModuleArg]);
}

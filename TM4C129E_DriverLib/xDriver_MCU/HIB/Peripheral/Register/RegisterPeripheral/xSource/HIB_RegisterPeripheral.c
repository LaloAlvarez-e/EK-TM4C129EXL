/**
 *
 * @file HIB_RegisterPeripheral.c
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
 * @verbatim 15 nov. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 nov. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/HIB/Peripheral/Register/RegisterPeripheral/HIB_RegisterPeripheral.h>

uintptr_t HIB__uptrBlockBaseAddress(HIB_nMODULE enModuleArg)
{
    const uintptr_t HIB_BLOCK_BASE[(UBase_t) HIB_enMODULE_MAX] =
    {
     HIB0_BASE
    };
    return (HIB_BLOCK_BASE[(UBase_t) enModuleArg]);
}

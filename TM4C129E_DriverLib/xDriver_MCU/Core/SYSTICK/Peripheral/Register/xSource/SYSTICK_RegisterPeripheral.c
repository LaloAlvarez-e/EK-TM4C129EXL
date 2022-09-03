/**
 *
 * @file SYSTICK_RegisterPeripheral.c
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
 * @verbatim 1 sep. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 1 sep. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/SYSTICK/Peripheral/Register/xHeader/SYSTICK_RegisterPeripheral.h>

uintptr_t SYSTICK__uptrBlockBaseAddress(SYSTICK_nMODULE enModuleArg)
{
    uintptr_t SYSTICK_BLOCK_BASE[(uint32_t) SYSTICK_enMODULE_MAX] =
    {
     SYSTICK_BASE
    };
    return (SYSTICK_BLOCK_BASE[(uint32_t) enModuleArg]);
}





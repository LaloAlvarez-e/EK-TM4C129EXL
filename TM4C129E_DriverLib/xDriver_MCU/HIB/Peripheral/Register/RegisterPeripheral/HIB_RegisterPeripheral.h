/**
 *
 * @file HIB_RegisterPeripheral.h
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

#ifndef XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_HIB_REGISTERPERIPHERAL_H_
#define XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_HIB_REGISTERPERIPHERAL_H_

#include <xDriver_MCU/HIB/Peripheral/Register/RegisterPeripheral/xHeader/HIB_RegisterPeripheral_Module0.h>

#define HIB    ((HIBS_t*) (HIB_BASE))

uintptr_t HIB__uptrBlockBaseAddress(HIB_nMODULE enModuleArg);

#endif /* XDRIVER_MCU_HIB_PERIPHERAL_REGISTER_REGISTERPERIPHERAL_HIB_REGISTERPERIPHERAL_H_ */

/**
 *
 * @file QEI_SignalMode.h
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
 * @verbatim Apr 8, 2021 @endverbatim
 *
 * @author
 * @verbatim indevicemex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * Apr 8, 2021        indevicemex    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_QEI_DRIVER_CONTROL_XHEADER_QEI_SIGNALMODE_H_
#define XDRIVER_MCU_QEI_DRIVER_CONTROL_XHEADER_QEI_SIGNALMODE_H_

#include <xDriver_MCU/QEI/Peripheral/xHeader/QEI_Enum.h>

QEI_nERROR QEI__enSetMode(QEI_nMODULE enModuleArg, QEI_nMODE enModeArg);
QEI_nERROR QEI__enGetMode(QEI_nMODULE enModuleArg, QEI_nMODE* penModeArg);

#endif /* XDRIVER_MCU_QEI_DRIVER_CONTROL_XHEADER_QEI_SIGNALMODE_H_ */

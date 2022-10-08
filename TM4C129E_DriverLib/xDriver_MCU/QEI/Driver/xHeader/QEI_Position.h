/**
 *
 * @file QEI_Position.h
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

#ifndef XDRIVER_MCU_QEI_DRIVER_XHEADER_QEI_POSITION_H_
#define XDRIVER_MCU_QEI_DRIVER_XHEADER_QEI_POSITION_H_

#include <xDriver_MCU/QEI/Peripheral/xHeader/QEI_Enum.h>

void QEI__vSetPosition(QEI_nMODULE enModule, UBase_t uxPositionArg);
UBase_t QEI__uxGetPosition(QEI_nMODULE enModule);

#endif /* XDRIVER_MCU_QEI_DRIVER_XHEADER_QEI_POSITION_H_ */

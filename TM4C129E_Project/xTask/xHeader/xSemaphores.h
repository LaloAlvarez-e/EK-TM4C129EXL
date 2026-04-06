/**
 *
 * @file xSemaphores.h
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
 * @verbatim 20 ene. 2022 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 ene. 2022     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XTASK_XHEADER_XSEMAPHORES_H_
#define XTASK_XHEADER_XSEMAPHORES_H_

#include <xOS/xOS.h>

extern OS_Queue_SetHandle_t TFTQueueSetHandle;
extern OS_Queue_Handle_t TFTSemaphoreHandle;
extern OS_Queue_Handle_t UARTSemaphoreHandle;
extern OS_Queue_Handle_t DMASemaphoreHandle;
extern OS_Queue_Handle_t ST7735SemaphoreHandle;
extern OS_Queue_Handle_t MainSemaphoreHandle;
extern OS_Queue_Handle_t DebugDataSemaphoreHandle;
extern OS_Queue_Handle_t YoystickQueueHandle;
extern OS_Queue_Handle_t AccelerometerQueueHandle;
extern OS_Queue_Handle_t ButtonQueueHandle;

#endif /* XTASK_XHEADER_XSEMAPHORES_H_ */

/**
 *
 * @file xSemaphores.c
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

#include <xTask/xHeader/xSemaphores.h>

OS_Queue_SetHandle_t TFTQueueSetHandle = (OS_Queue_SetHandle_t) 0UL;
OS_Queue_Handle_t TFTSemaphoreHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t UARTSemaphoreHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t DMASemaphoreHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t ST7735SemaphoreHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t MainSemaphoreHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t DebugDataSemaphoreHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t YoystickQueueHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t AccelerometerQueueHandle = (OS_Queue_Handle_t) 0UL;
OS_Queue_Handle_t ButtonQueueHandle = (OS_Queue_Handle_t) 0UL;


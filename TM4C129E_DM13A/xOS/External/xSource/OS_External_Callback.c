/**
 *
 * @file OS_External_Callback.c
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
 * @verbatim 15 jul. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 15 jul. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xOS/External/xHeader/OS_External_Callback.h>

void OS_External__vApplicationStackOverflowHook( void* pvTaskArg, char *pcTaskNameArg )
{
    (void) pvTaskArg;
    (void) (pcTaskNameArg);
}

void OS_External__vApplicationTickHook( void )
{

}

void OS_External__vApplicationIdleHook( void )
{

}

/**
 *
 * @file OS_Adapt_Defines.h
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
 * @verbatim 9 sep. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 9 sep. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */

#ifndef XOS_TASK_ADAPT_XHEADER_OS_ADAPT_DEFINES_H_
#define XOS_TASK_ADAPT_XHEADER_OS_ADAPT_DEFINES_H_

#include <xOS/Variables/OS_Variables.h>

#define OS_KERNEL_INITIAL_XPSR  ( 0x01000000UL )
#define OS_KERNEL_EXEC_RETURN  ( 0xFFFFFFFDUL )

#define OS_ADAPT_MAX_DELAY ((OS_UBase_t) 0xFFFFFFFFUL)

#define OS_ADAPT_BYTE_ALIGNMENT_MASK ((OS_UBase_t) 0x7UL)

#define OS_ADAPT_SYSCALL_INTERRUPT_PRIORITY (7UL)
#define OS_ADAPT_MAX_SYSCALL_INTERRUPT_PRIORITY (5UL)
#define OS_ADAPT_MIN_SYSCALL_INTERRUPT_PRIORITY (OS_ADAPT_SYSCALL_INTERRUPT_PRIORITY - 5UL)

#endif /* XOS_TASK_ADAPT_XHEADER_OS_ADAPT_DEFINES_H_ */

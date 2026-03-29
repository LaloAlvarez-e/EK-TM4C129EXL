/**
 *
 * @file syscalls.c
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
 * @verbatim 28 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author         Version     Description
 * 28 mar. 2026   InDeviceMex    1.0         initial Version@endverbatim
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>

extern uint8_t __heap_start__;
extern uint8_t __HeapLimit;

static uint8_t* SYSCALLS_pu8HeapCurrent = (uint8_t*) 0UL;

int _close(int iFileArg)
{
    (void) iFileArg;
    errno = EBADF;
    return (-1);
}

int _fstat(int iFileArg, struct stat* pstStatArg)
{
    (void) iFileArg;
    int rc = 0;

    if((struct stat*) 0UL != pstStatArg)
    {
        pstStatArg->st_mode = S_IFCHR;
        rc = 0;
    }
    else
    {
        errno = EFAULT;
        rc = -1;
    }

    return (rc);
}

int _getpid(void)
{
    int rc = 1;
    return (rc);
}

int _isatty(int iFileArg)
{
    (void) iFileArg;
    int rc = 1;
    return (rc);
}

int _kill(int iPidArg, int iSignalArg)
{
    (void) iPidArg;
    (void) iSignalArg;
    int rc = -1;
    errno = EINVAL;
    return (rc);
}

int _lseek(int iFileArg, int iOffsetArg, int iWhenceArg)
{
    (void) iFileArg;
    (void) iOffsetArg;
    (void) iWhenceArg;
    int rc = 0;
    return (rc);
}

int _open(const char* pcNameArg, int iFlagsArg, int iModeArg)
{
    (void) pcNameArg;
    (void) iFlagsArg;
    (void) iModeArg;
    int rc = -1;
    errno = ENOSYS;
    return (rc);
}

int _read(int iFileArg, char* pcBufferArg, int iLengthArg)
{
    (void) iFileArg;
    (void) pcBufferArg;
    (void) iLengthArg;
    int rc = 0;
    return (rc);
}

void* _sbrk(int iIncrementArg)
{
    uintptr_t uptrHeapCurrent;
    uintptr_t uptrHeapNext;
    uintptr_t uptrHeapStart;
    uintptr_t uptrHeapLimit;
    uint8_t* pu8HeapPrevious;
    void* rc = 0;

    uptrHeapStart = (uintptr_t) &__heap_start__;
    uptrHeapLimit = (uintptr_t) &__HeapLimit;
    if((uint8_t*) 0UL == SYSCALLS_pu8HeapCurrent)
    {
        SYSCALLS_pu8HeapCurrent = &__heap_start__;
    }

    uptrHeapCurrent = (uintptr_t) SYSCALLS_pu8HeapCurrent;
    pu8HeapPrevious = SYSCALLS_pu8HeapCurrent;
    uptrHeapNext = uptrHeapCurrent + (intptr_t) iIncrementArg;
    if((uptrHeapNext < uptrHeapStart) || (uptrHeapNext > uptrHeapLimit))
    {
        errno = ENOMEM;
        rc = (void*) -1;
    }
    else
    {
        SYSCALLS_pu8HeapCurrent = (uint8_t*) uptrHeapNext;
        rc = (void*) pu8HeapPrevious;

    }

    return (rc);
}

void _exit(int iStatusArg)
{
    (void) iStatusArg;
    while(1U)
    {
    }
}

int _write(int iFileArg, const char* pcBufferArg, int iLengthArg)
{
    (void) iFileArg;
    (void) pcBufferArg;
    int rc = iLengthArg;
    return (rc);
}
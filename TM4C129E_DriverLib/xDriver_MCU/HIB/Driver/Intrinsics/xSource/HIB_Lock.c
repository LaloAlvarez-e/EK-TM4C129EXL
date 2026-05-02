/**
 *
 * @file HIB_Lock.c
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
 * @verbatim 6 abr. 2026 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 6 abr. 2026    vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/HIB/Driver/Intrinsics/xHeader/HIB_Lock.h>

#include <xDriver_MCU/HIB/Driver/Intrinsics/Primitives/HIB_Primitives.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

HIB_nERROR HIB__enIsLocked(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penLockedArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penLockedArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        HIB_Register_t stRegister;

        stRegister.uxShift = HIB_LOCK_R_HIBLOCK_BIT;
        stRegister.uxMask = HIB_LOCK_HIBLOCK_MASK;
        stRegister.uptrAddress = HIB_LOCK_OFFSET;
        stRegister.uxValue = 0UL;

        enErrorReg = HIB__enReadRegister(enModuleArg, &stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penLockedArg = (HIB_LOCK_HIBLOCK_UNLOCK == stRegister.uxValue) ? HIB_enFALSE : HIB_enTRUE;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enSetLockState(HIB_nMODULE enModuleArg, HIB_nSTATE enStateArg)
{
    HIB_nERROR enErrorReg;
    HIB_Register_t stRegister;
    UBase_t uxValueReg;

    uxValueReg = (HIB_enSTATE_DIS == enStateArg) ? HIB_LOCK_HIBLOCK_KEY : HIB_LOCK_HIBLOCK_LOCK;

    stRegister.uxShift = HIB_LOCK_R_HIBLOCK_BIT;
    stRegister.uxMask = HIB_LOCK_HIBLOCK_MASK;
    stRegister.uptrAddress = HIB_LOCK_OFFSET;
    stRegister.uxValue = uxValueReg;

    enErrorReg = HIB__enWriteRegister(enModuleArg, &stRegister);
    return (enErrorReg);
}

HIB_nERROR HIB__enLock(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetLockState(enModuleArg, HIB_enSTATE_ENA);
    return (enErrorReg);
}

HIB_nERROR HIB__enUnlock(HIB_nMODULE enModuleArg)
{
    HIB_nERROR enErrorReg;
    enErrorReg = HIB__enSetLockState(enModuleArg, HIB_enSTATE_DIS);
    return (enErrorReg);
}
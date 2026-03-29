/**
 *
 * @file SCB_PriorityGroup.c
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
 * @verbatim 19 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 19 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_PriorityGroup.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SCB/Peripheral/SCB_Peripheral.h>
#include <xDriver_MCU/Core/SCB/Driver/Intrinsics/Primitives/SCB_Primitives.h>

SCB_nERROR SCB__enSetPriorityGroup(SCB_nMODULE enModuleArg, SCB_nPRIGROUP enGroupArg)
{
    SCB_nERROR enErrorReg;
    enErrorReg = (SCB_nERROR) MCU__enCheckParams( (UBase_t) enGroupArg, (UBase_t) SCB_enPRIGROUP_MAX);
    if(SCB_enERROR_OK == enErrorReg)
    {
        UBase_t uxValueReg = (UBase_t) enGroupArg;
        uxValueReg <<= SCB_AIRCR_R_PRIGROUP_BIT;
        uxValueReg |= SCB_AIRCR_R_VECTKEY_WRITE;

        SCB_Register_t stRegister;
        stRegister.uxShift = 0UL;
        stRegister.uxMask = SCB_AIRCR_R_VECTKEY_MASK | SCB_AIRCR_R_PRIGROUP_MASK;
        stRegister.uptrAddress = SCB_AIRCR_OFFSET;
        stRegister.uxValue = uxValueReg;
        MCU__vDataSyncBarrier();
        enErrorReg = SCB__enWriteRegister(enModuleArg, &stRegister);
        MCU__vDataSyncBarrier();
    }

    return (enErrorReg);
}

SCB_nERROR SCB__enGetPriorityGroup(SCB_nMODULE enModuleArg, SCB_nPRIGROUP* penGroupArg)
{
    SCB_nERROR enErrorReg;
    enErrorReg = (0UL == (uintptr_t) penGroupArg) ? SCB_enERROR_POINTER : SCB_enERROR_OK;
    if(SCB_enERROR_OK == enErrorReg)
    {
        SCB_Register_t stRegister;
        stRegister.uxShift = SCB_AIRCR_R_PRIGROUP_BIT;
        stRegister.uxMask = SCB_AIRCR_PRIGROUP_MASK;
        stRegister.uptrAddress = SCB_AIRCR_OFFSET;
        enErrorReg = SCB__enReadRegister(enModuleArg, &stRegister);
        if(SCB_enERROR_OK == enErrorReg)
        {
            *penGroupArg = (SCB_nPRIGROUP) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}

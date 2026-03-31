/**
 *
 * @file SCB_SysReset.c
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
#include <xDriver_MCU/Core/SCB/Driver/xHeader/SCB_SysReset.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/SCB/Peripheral/SCB_Peripheral.h>
#include <xDriver_MCU/Core/SCB/Driver/Intrinsics/Primitives/SCB_Primitives.h>

SCB_nERROR SCB__enRequestSystemReset(SCB_nMODULE enModuleArg)
{
    SCB_Register_t stRegister;
    stRegister.uxShift = SCB_AIRCR_R_VECTKEY_BIT;
    stRegister.uxMask = SCB_AIRCR_VECTKEY_MASK ;
    stRegister.uptrAddress = SCB_AIRCR_OFFSET;

    SCB_nERROR enErrorReg;
    enErrorReg = SCB__enReadRegister(enModuleArg, &stRegister);
    if(SCB_enERROR_OK == enErrorReg)
    {
        if(SCB_AIRCR_VECTKEY_READ == stRegister.uxValue)
        {
            stRegister.uxShift = 0UL;
            stRegister.uxMask = MCU_MASK_32;
            stRegister.uptrAddress = SCB_AIRCR_OFFSET;
            stRegister.uxValue = SCB_AIRCR_R_VECTKEY_WRITE | SCB_AIRCR_R_SYSRESETREQ_RESET;
            MCU__vDataSyncBarrier();
            enErrorReg = SCB__enWriteRegister(enModuleArg, &stRegister);
            if(SCB_enERROR_OK == enErrorReg)
            {
                MCU__vDataSyncBarrier();
                while(1U)
                {
                    MCU__vNoOperation();
                }
            }
        }
        else
        {
            enErrorReg = SCB_enERROR_VALUE;
        }
    }

    return (enErrorReg);
}

SCB_nERROR SCB__enRequestSystemReset_Debug(SCB_nMODULE enModuleArg)
{
    SCB_Register_t stRegister;
    stRegister.uxShift = SCB_AIRCR_R_VECTKEY_BIT;
    stRegister.uxMask = SCB_AIRCR_VECTKEY_MASK;
    stRegister.uptrAddress = SCB_AIRCR_OFFSET;

    SCB_nERROR enErrorReg;
    enErrorReg = SCB__enReadRegister(enModuleArg, &stRegister);
    if(SCB_enERROR_OK == enErrorReg)
    {
        if(SCB_AIRCR_VECTKEY_READ == stRegister.uxValue)
        {
            stRegister.uxShift = 0UL;
            stRegister.uxMask = MCU_MASK_32;
            stRegister.uptrAddress = SCB_AIRCR_OFFSET;
            stRegister.uxValue = SCB_AIRCR_R_VECTKEY_WRITE | SCB_AIRCR_R_VECTRESET_NOUSE;
            MCU__vDataSyncBarrier();
            enErrorReg = SCB__enWriteRegister(enModuleArg, &stRegister);
            if(SCB_enERROR_OK == enErrorReg)
            {
                MCU__vDataSyncBarrier();
                while(1U)
                {
                    MCU__vNoOperation();
                }
            }
        }
        else
        {
            enErrorReg = SCB_enERROR_VALUE;
        }
    }
    return (enErrorReg);
}


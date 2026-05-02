/**
 *
 * @file HIB_Wait.c
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
#include <xDriver_MCU/HIB/Driver/Intrinsics/Primitives/xHeader/HIB_Wait.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/HIB/Peripheral/HIB_Peripheral.h>

HIB_nERROR HIB__enIsWriteOngoing(HIB_nMODULE enModuleArg, HIB_nBOOLEAN* penStatusArg)
{
    HIB_nERROR enErrorReg;

    enErrorReg = (0UL == (uintptr_t) penStatusArg) ? HIB_enERROR_POINTER : HIB_enERROR_OK;
    if(HIB_enERROR_OK == enErrorReg)
    {
        enErrorReg = (HIB_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) HIB_enMODULE_MAX);
    }
    if(HIB_enERROR_OK == enErrorReg)
    {
        uintptr_t uptrModuleBase;
        HIB_Register_t stRegister;

        uptrModuleBase = HIB__uptrBlockBaseAddress(enModuleArg);

        stRegister.uxShift = HIB_CTL_R_WRC_BIT;
        stRegister.uxMask = HIB_CTL_WRC_MASK;
        stRegister.uptrAddress = HIB_CTL_OFFSET + uptrModuleBase;
        stRegister.uxValue = 0UL;

        enErrorReg = (HIB_nERROR) MCU__enReadRegister(&stRegister);
        if(HIB_enERROR_OK == enErrorReg)
        {
            *penStatusArg = (HIB_CTL_WRC_PROGRESS == stRegister.uxValue) ? HIB_enTRUE : HIB_enFALSE;
        }
    }
    return (enErrorReg);
}

HIB_nERROR HIB__enWaitWrite(HIB_nMODULE enModuleArg, UBase_t uxTimeoutArg)
{
    HIB_nERROR enErrorReg;
    HIB_nBOOLEAN enWriteBusyReg;

    enErrorReg = HIB_enERROR_OK;
    if(0UL < uxTimeoutArg)
    {
        do
        {
            
            enErrorReg = HIB__enIsWriteOngoing(enModuleArg, &enWriteBusyReg);
            uxTimeoutArg--;
        }while((HIB_enTRUE == enWriteBusyReg) && (HIB_enERROR_OK == enErrorReg) && (0UL < uxTimeoutArg));

    }
    else
    {
        do
        {
            enErrorReg = HIB__enIsWriteOngoing(enModuleArg, &enWriteBusyReg);
        } while((HIB_enTRUE == enWriteBusyReg) && (HIB_enERROR_OK == enErrorReg));
    }
            
    if(HIB_enERROR_OK == enErrorReg) 
    {
        if((HIB_enTRUE == enWriteBusyReg) && (0UL == uxTimeoutArg))
        {
            enErrorReg = HIB_enERROR_TIMEOUT;
        }
    }

    return (enErrorReg);
}

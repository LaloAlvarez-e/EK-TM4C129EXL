/**
 *
 * @file NVIC_Priority.c
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
 * @verbatim 20 jun. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 20 jun. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/Core/NVIC/Driver/xHeader/NVIC_Priority.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/Core/NVIC/Driver/Intrinsics/NVIC_Intrinsics.h>
#include <xDriver_MCU/Core/NVIC/Peripheral/NVIC_Peripheral.h>

NVIC_nERROR NVIC__enGetVectorPriority(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY* penPriorityArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = (0U == (uintptr_t) penPriorityArg) ? NVIC_enERROR_POINTER : NVIC_enERROR_OK;
    if(NVIC_enERROR_OK == enErrorReg)
    {
        enErrorReg = (NVIC_nERROR) MCU__enCheckParams((UBase_t) enVectorArg, (UBase_t) NVIC_enVECTOR_MAX);
    }
    if(NVIC_enERROR_OK == enErrorReg)
    {
        uintptr_t uptrRegisterOffset = NVIC_IPR_OFFSET;
        UBase_t uxVectorBit = (UBase_t) enVectorArg;
        uxVectorBit %= 4UL;
        uxVectorBit <<= 3U;
        uxVectorBit += NVIC_PRI_BIT_OFFSET;

        UBase_t uxVectorIndex = (UBase_t) enVectorArg;
        uxVectorIndex &= ~((UBase_t) 0x00000003UL);

        uptrRegisterOffset += uxVectorIndex;

        NVIC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) uxVectorBit;
        stRegister.uxMask = NVIC_PRI_MASK;
        stRegister.uptrAddress = (UBase_t) uptrRegisterOffset;
        enErrorReg = NVIC__enReadRegister(enModuleArg, &stRegister);
        if(NVIC_enERROR_OK == enErrorReg)
        {
            *penPriorityArg = (NVIC_nPRIORITY) stRegister.uxValue;
        }
    }
    return (enErrorReg);
}


NVIC_nERROR NVIC__enSetVectorPriority(NVIC_nMODULE enModuleArg, NVIC_nVECTOR enVectorArg, NVIC_nPRIORITY enPriorityArg)
{
    NVIC_nERROR enErrorReg;
    enErrorReg = (NVIC_nERROR) MCU__enCheckParams((UBase_t) enVectorArg, (UBase_t) NVIC_enVECTOR_MAX);
    if(NVIC_enERROR_OK == enErrorReg)
    {
        uintptr_t uptrRegisterOffset = NVIC_IPR_OFFSET;
        UBase_t uxVectorBit = (UBase_t) enVectorArg;
        uxVectorBit %= 4UL;
        uxVectorBit <<= 3U;
        uxVectorBit += NVIC_PRI_BIT_OFFSET;

        UBase_t uxVectorIndex = (UBase_t) enVectorArg;
        uxVectorIndex &= ~((UBase_t) 0x00000003UL);

        uptrRegisterOffset += uxVectorIndex;

        NVIC_Register_t stRegister;
        stRegister.uxShift = (UBase_t) uxVectorBit;
        stRegister.uxMask = NVIC_PRI_MASK;
        stRegister.uptrAddress = (UBase_t) uptrRegisterOffset;
        stRegister.uxValue = (UBase_t) enPriorityArg;
        enErrorReg = NVIC__enWriteRegister(enModuleArg, &stRegister);
    }
    return (enErrorReg);
}


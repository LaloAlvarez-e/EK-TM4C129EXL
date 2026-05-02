/**
 *
 * @file FLASH_InterruptRegisterIRQSource.c
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
 * @verbatim 10 ago. 2020 @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 10 ago. 2020     vyldram    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/FLASH_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/FLASH_InterruptRoutine_Source.h>

FLASH_nERROR FLASH__enRegisterIRQSourceHandler(FLASH_nMODULE enModuleArg, FLASH_nINT enIntSourceArg, FLASH_pvfIRQSourceHandler_t pfIrqSourceHandler)
{
    FLASH_nERROR enErrorReg;
    FLASH_pvfIRQSourceHandler_t* pfIrqSourceHandlerReg;

    enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enModuleArg, (UBase_t) FLASH_enMODULE_MAX);
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (FLASH_nERROR) MCU__enCheckParams_RAM((UBase_t) enIntSourceArg, (UBase_t) FLASH_enINT_MAX);
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        enErrorReg = (0UL == (uintptr_t) pfIrqSourceHandler) ? FLASH_enERROR_POINTER : FLASH_enERROR_OK;
    }
    if(FLASH_enERROR_OK == enErrorReg)
    {
        pfIrqSourceHandlerReg = FLASH__pvfGetIRQSourceHandlerPointer(enModuleArg, enIntSourceArg);
        enErrorReg = (FLASH_nERROR) MCU__enRegisterIRQSourceHandler_RAM(pfIrqSourceHandler, pfIrqSourceHandlerReg, 0UL, 1UL);
    }
    return (enErrorReg);
}

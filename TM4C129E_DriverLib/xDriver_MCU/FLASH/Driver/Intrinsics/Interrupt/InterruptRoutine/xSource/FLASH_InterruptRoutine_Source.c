/**
 *
 * @file FLASH_InterruptRoutine_Source.c
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
#include <xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/FLASH_InterruptRoutine_Source.h>

static FLASH_pvfIRQSourceHandler_t FLASH_vIRQSourceHandler[(UBase_t) FLASH_enMODULE_MAX][(UBase_t) FLASH_enINT_MAX] =
{
    {
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy,
        &MCU_vIRQSourceHandler_Dummy
    }
};

FLASH_pvfIRQSourceHandler_t FLASH__pvfGetIRQSourceHandler(FLASH_nMODULE enModuleArg, FLASH_nINT enIntSourceArg)
{
    FLASH_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = FLASH_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enIntSourceArg];
    return (pvfFunctionReg);
}

FLASH_pvfIRQSourceHandler_t* FLASH__pvfGetIRQSourceHandlerPointer(FLASH_nMODULE enModuleArg, FLASH_nINT enIntSourceArg)
{
    FLASH_pvfIRQSourceHandler_t* pvfFunctionReg;
    
    pvfFunctionReg = &FLASH_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enIntSourceArg];
    return (pvfFunctionReg);
}

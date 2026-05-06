/**
 *
 * @file EEPROM_InterruptRegisterIRQSource.c
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
 * @verbatim 25 jun. 2021 @endverbatim
 *
 * @author
 * @verbatim InDeviceMex @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * 25 jun. 2021     InDeviceMex    1.0         initial Version@endverbatim
 */
#include <xDriver_MCU/EEPROM/Driver/Intrinsics/Interrupt/InterruptRegister/xHeader/EEPROM_InterruptRegisterIRQSource.h>

#include <xDriver_MCU/Common/MCU_Common.h>
#include <xDriver_MCU/EEPROM/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/EEPROM_InterruptRoutine_Source.h>
#include <xDriver_MCU/EEPROM/Peripheral/EEPROM_Peripheral.h>

EEPROM_nERROR EEPROM__enRegisterIRQSourceHandler(EEPROM_pvfIRQSourceHandler_t pfIrqSourceHandler,
                                                 EEPROM_nMODULE enModuleArg,
                                                 EEPROM_nINT enInterruptSourceArg)
{
    EEPROM_nERROR enErrorReg;
    enErrorReg = (EEPROM_nERROR) MCU__enCheckParams((UBase_t) enModuleArg, (UBase_t) EEPROM_enMODULE_MAX);
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        enErrorReg = (EEPROM_nERROR) MCU__enCheckParams((UBase_t) enInterruptSourceArg, (UBase_t) EEPROM_enINT_MAX);
    }
    if(EEPROM_enERROR_OK == enErrorReg)
    {
        EEPROM_pvfIRQSourceHandler_t* pvfIrqHandler = EEPROM__pvfGetIRQSourceHandlerPointer(enModuleArg, enInterruptSourceArg);
        enErrorReg = (EEPROM_nERROR) MCU__enRegisterIRQSourceHandler(pfIrqSourceHandler, pvfIrqHandler, 0UL, 1UL);
    }

    return (enErrorReg);
}

/**
 *
 * @file EEPROM_InterruptRoutine_Source.c
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
#include <xDriver_MCU/EEPROM/Driver/Intrinsics/Interrupt/InterruptRoutine/xHeader/EEPROM_InterruptRoutine_Source.h>

static EEPROM_pvfIRQSourceHandler_t EEPROM_vIRQSourceHandler[(UBase_t)EEPROM_enMODULE_MAX]
                                                            [(UBase_t) EEPROM_enINT_MAX]=
{
 {
    &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy,
    &MCU_vIRQSourceHandler_Dummy
 },
};

EEPROM_pvfIRQSourceHandler_t EEPROM__pvfGetIRQSourceHandler(EEPROM_nMODULE enModuleArg,
                                                            EEPROM_nINT enInterruptSourceArg)
{
    EEPROM_pvfIRQSourceHandler_t pvfFunctionReg;

    pvfFunctionReg = (EEPROM_pvfIRQSourceHandler_t) 0;
    if((EEPROM_enMODULE_MAX > enModuleArg) && (EEPROM_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = EEPROM_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}


EEPROM_pvfIRQSourceHandler_t* EEPROM__pvfGetIRQSourceHandlerPointer(EEPROM_nMODULE enModuleArg,
                                                                    EEPROM_nINT enInterruptSourceArg)
{
    EEPROM_pvfIRQSourceHandler_t* pvfFunctionReg;

    pvfFunctionReg = (EEPROM_pvfIRQSourceHandler_t*) 0;
    if((EEPROM_enMODULE_MAX > enModuleArg) && (EEPROM_enINT_MAX > enInterruptSourceArg))
    {
        pvfFunctionReg = &EEPROM_vIRQSourceHandler[(UBase_t) enModuleArg][(UBase_t) enInterruptSourceArg];
    }
    return (pvfFunctionReg);
}

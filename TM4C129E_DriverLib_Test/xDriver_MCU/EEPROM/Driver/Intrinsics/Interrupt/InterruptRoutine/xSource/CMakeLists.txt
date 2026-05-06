tm4c129e_driverlib_add_unit_test(
    EEPROM_InterruptRoutine_Source_Test
    STATIC_TEST_DISCOVERY
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/EEPROM_InterruptRoutine_Source_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xDriver_MCU/EEPROM/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/EEPROM_InterruptRoutine_Source.c
)
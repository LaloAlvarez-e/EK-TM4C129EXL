tm4c129e_driverlib_add_unit_test(
    FLASH_InterruptRoutine_Source_Test
    STATIC_TEST_DISCOVERY
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/FLASH_InterruptRoutine_Source_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/FLASH_InterruptRoutine_Source.c
)
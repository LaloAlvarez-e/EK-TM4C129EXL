tm4c129e_driverlib_add_unit_test(
    I2C_Master_InterruptRoutine_Source_Test
    STATIC_TEST_DISCOVERY
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/I2C_Master_InterruptRoutine_Source_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/I2C_Master_InterruptRoutine_Source.c
)

tm4c129e_driverlib_add_unit_test(
    I2C_Slave_InterruptRoutine_Source_Test
    STATIC_TEST_DISCOVERY
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/I2C_Slave_InterruptRoutine_Source_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/I2C_Slave_InterruptRoutine_Source.c
)
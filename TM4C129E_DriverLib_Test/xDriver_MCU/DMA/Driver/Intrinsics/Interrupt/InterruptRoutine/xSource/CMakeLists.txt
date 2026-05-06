tm4c129e_driverlib_add_unit_test(
    DMA_InterruptRoutine_Source_Software_Test
    STATIC_TEST_DISCOVERY
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/DMA_InterruptRoutine_Source_Software_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xDriver_MCU/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/DMA_InterruptRoutine_Source_Software.c
)
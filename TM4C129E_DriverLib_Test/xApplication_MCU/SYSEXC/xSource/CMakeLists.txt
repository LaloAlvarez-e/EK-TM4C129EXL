tm4c129e_driverlib_add_unit_test(
    SYSEXC_Report_Test
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/SYSEXC_Report_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xApplication_MCU/SYSEXC/xSource/SYSEXC_Report.c
)

tm4c129e_driverlib_add_unit_test(
    SYSEXC_Init_Test
    TEST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/SYSEXC_Init_Test.cpp
    ORIGINAL_SOURCES
        ${TM4C129E_DRIVERLIB_ROOT}/xApplication_MCU/SYSEXC/xSource/SYSEXC_Init.c
    MOCK_SOURCES
        ${TM4C129E_DRIVERLIB_TEST_ROOT}/support/src/SYSEXC_InitDriverMock.cpp
)
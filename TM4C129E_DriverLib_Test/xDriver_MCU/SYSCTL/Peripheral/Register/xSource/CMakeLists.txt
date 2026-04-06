include(GoogleTest)

add_executable(SYSCTL_PowerModeRegisters_Test
    ${CMAKE_CURRENT_LIST_DIR}/SYSCTL_PowerModeRegisters_Test.cpp
)

add_executable(SYSCTL_ModulePowerRegisters_Test
    ${CMAKE_CURRENT_LIST_DIR}/SYSCTL_ModulePowerRegisters_Test.cpp
)

add_executable(SYSCTL_NonVolatileRegisters_Test
    ${CMAKE_CURRENT_LIST_DIR}/SYSCTL_NonVolatileRegisters_Test.cpp
)

target_include_directories(SYSCTL_PowerModeRegisters_Test PRIVATE
    ${TM4C129E_DRIVERLIB_TEST_ROOT}/support/include
    ${TM4C129E_DRIVERLIB_ROOT}
    ${TM4C129E_APPLICATIONLIB_ROOT}
)

target_include_directories(SYSCTL_ModulePowerRegisters_Test PRIVATE
    ${TM4C129E_DRIVERLIB_TEST_ROOT}/support/include
    ${TM4C129E_DRIVERLIB_ROOT}
    ${TM4C129E_APPLICATIONLIB_ROOT}
)

target_include_directories(SYSCTL_NonVolatileRegisters_Test PRIVATE
    ${TM4C129E_DRIVERLIB_TEST_ROOT}/support/include
    ${TM4C129E_DRIVERLIB_ROOT}
    ${TM4C129E_APPLICATIONLIB_ROOT}
)

target_link_libraries(SYSCTL_PowerModeRegisters_Test PRIVATE
    GTest::gtest
    GTest::gtest_main
)

target_link_libraries(SYSCTL_ModulePowerRegisters_Test PRIVATE
    GTest::gtest
    GTest::gtest_main
)

target_link_libraries(SYSCTL_NonVolatileRegisters_Test PRIVATE
    GTest::gtest
    GTest::gtest_main
)

if(MSVC)
    target_compile_definitions(SYSCTL_PowerModeRegisters_Test PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_definitions(SYSCTL_ModulePowerRegisters_Test PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_definitions(SYSCTL_NonVolatileRegisters_Test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

set_property(GLOBAL APPEND PROPERTY TM4C129E_DRIVERLIB_TEST_TARGETS SYSCTL_PowerModeRegisters_Test)
set_property(GLOBAL APPEND PROPERTY TM4C129E_DRIVERLIB_TEST_TARGETS SYSCTL_ModulePowerRegisters_Test)
set_property(GLOBAL APPEND PROPERTY TM4C129E_DRIVERLIB_TEST_TARGETS SYSCTL_NonVolatileRegisters_Test)

gtest_add_tests(TARGET SYSCTL_PowerModeRegisters_Test)
gtest_add_tests(TARGET SYSCTL_ModulePowerRegisters_Test)
gtest_add_tests(TARGET SYSCTL_NonVolatileRegisters_Test)
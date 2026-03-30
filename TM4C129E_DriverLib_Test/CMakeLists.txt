cmake_minimum_required(VERSION 3.21)

project(TM4C129E_DriverLib_Test LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(TM4C129E_DRIVERLIB_TEST_FETCH_GTEST "Fetch GoogleTest and GoogleMock when they are not available locally." ON)

set(TM4C129E_DRIVERLIB_TEST_ROOT "${CMAKE_CURRENT_LIST_DIR}")
set(TM4C129E_DRIVERLIB_ROOT "${CMAKE_CURRENT_LIST_DIR}/../TM4C129E_DriverLib")
set(TM4C129E_APPLICATIONLIB_ROOT "${CMAKE_CURRENT_LIST_DIR}/../TM4C129E_ApplicationLib")

if(NOT EXISTS "${TM4C129E_DRIVERLIB_ROOT}")
    message(FATAL_ERROR "TM4C129E_DriverLib was not found next to TM4C129E_DriverLib_Test.")
endif()

enable_testing()

include(cmake/GoogleTestBootstrap.cmake)
include(cmake/TM4C129E_DriverLibTestFunctions.cmake)
include(cmake/OpenCppCoverage.cmake)

add_subdirectory(xDriver_MCU)
add_subdirectory(xApplication_MCU)

get_property(TM4C129E_DRIVERLIB_TEST_TARGETS GLOBAL PROPERTY TM4C129E_DRIVERLIB_TEST_TARGETS)

if(TM4C129E_DRIVERLIB_TEST_TARGETS)
    add_custom_target(driverlib_test_build DEPENDS ${TM4C129E_DRIVERLIB_TEST_TARGETS})
else()
    add_custom_target(driverlib_test_build
        COMMAND ${CMAKE_COMMAND} -E echo "No DriverLib unit-test targets are registered yet."
        COMMENT "Build all registered DriverLib host-test targets"
    )
endif()

tm4c129e_driverlib_configure_coverage_targets()
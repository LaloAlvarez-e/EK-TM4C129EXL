include(GoogleTest)

function(tm4c129e_driverlib_add_unit_test TARGET_NAME)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs TEST_SOURCES ORIGINAL_SOURCES MOCK_SOURCES INCLUDE_DIRS)

    cmake_parse_arguments(TM4CDLT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT TM4CDLT_TEST_SOURCES)
        message(FATAL_ERROR "tm4c129e_driverlib_add_unit_test(${TARGET_NAME}) requires TEST_SOURCES.")
    endif()

    if(NOT TM4CDLT_ORIGINAL_SOURCES)
        message(FATAL_ERROR "tm4c129e_driverlib_add_unit_test(${TARGET_NAME}) requires ORIGINAL_SOURCES.")
    endif()

    add_executable(${TARGET_NAME}
        ${TM4CDLT_TEST_SOURCES}
        ${TM4CDLT_ORIGINAL_SOURCES}
        ${TM4CDLT_MOCK_SOURCES}
    )

    set_source_files_properties(${TM4CDLT_ORIGINAL_SOURCES} PROPERTIES LANGUAGE C)

    target_include_directories(${TARGET_NAME} PRIVATE
        ${TM4C129E_DRIVERLIB_TEST_ROOT}/support/include
        ${TM4C129E_DRIVERLIB_ROOT}
        ${TM4C129E_APPLICATIONLIB_ROOT}
        ${TM4CDLT_INCLUDE_DIRS}
    )

    target_link_libraries(${TARGET_NAME} PRIVATE
        GTest::gmock
        GTest::gtest
        GTest::gtest_main
    )

    if(MSVC)
        target_compile_definitions(${TARGET_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS)
    endif()

    set_property(GLOBAL APPEND PROPERTY TM4C129E_DRIVERLIB_TEST_TARGETS ${TARGET_NAME})

    gtest_discover_tests(${TARGET_NAME} DISCOVERY_TIMEOUT 60)
endfunction()
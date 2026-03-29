find_program(TM4C129E_DRIVERLIB_TEST_OPENCOVERAGE_EXECUTABLE
    NAMES OpenCppCoverage OpenCppCoverage.exe opencppcoverage
    HINTS
    "$ENV{ProgramW6432}/OpenCppCoverage"
        "$ENV{ProgramFiles}/OpenCppCoverage"
    "C:/Program Files/OpenCppCoverage"
    "C:/Program Files (x86)/OpenCppCoverage"
)

function(tm4c129e_driverlib_configure_coverage_targets)
    if(NOT TARGET driverlib_test_build)
        message(FATAL_ERROR "driverlib_test_build must exist before configuring coverage targets.")
    endif()

    set(TM4C129E_DRIVERLIB_TEST_GAP_TRACKER
        "${TM4C129E_DRIVERLIB_TEST_ROOT}/coverage/TM4C129E_DriverLib_Test_GapTracker.md")

    add_custom_target(driverlib_test_gap_tracker
        COMMAND ${CMAKE_COMMAND} -E echo "Gap tracker: ${TM4C129E_DRIVERLIB_TEST_GAP_TRACKER}"
        COMMENT "Show the DriverLib host-test gap tracker location"
    )

    if(TM4C129E_DRIVERLIB_TEST_OPENCOVERAGE_EXECUTABLE)
        set(TM4C129E_DRIVERLIB_TEST_COVERAGE_DIR
            "${TM4C129E_DRIVERLIB_TEST_ROOT}/coverage/opencppcoverage")
        set(TM4C129E_DRIVERLIB_TEST_COVERAGE_HTML_DIR
            "${TM4C129E_DRIVERLIB_TEST_COVERAGE_DIR}/html")
        set(TM4C129E_DRIVERLIB_TEST_COVERAGE_XML_FILE
            "${TM4C129E_DRIVERLIB_TEST_COVERAGE_DIR}/coverage.xml")

        get_filename_component(TM4C129E_DRIVERLIB_TEST_COVERAGE_SOURCE_DIR_REAL "${TM4C129E_DRIVERLIB_ROOT}" REALPATH)
        get_filename_component(TM4C129E_DRIVERLIB_TEST_COVERAGE_EXCLUDED_DIR_REAL "${TM4C129E_DRIVERLIB_TEST_ROOT}" REALPATH)

        file(TO_NATIVE_PATH "${TM4C129E_DRIVERLIB_TEST_COVERAGE_SOURCE_DIR_REAL}" TM4C129E_DRIVERLIB_TEST_COVERAGE_SOURCE_DIR_NATIVE)
        file(TO_NATIVE_PATH "${TM4C129E_DRIVERLIB_TEST_COVERAGE_EXCLUDED_DIR_REAL}" TM4C129E_DRIVERLIB_TEST_COVERAGE_EXCLUDED_DIR_NATIVE)
        file(TO_NATIVE_PATH "${TM4C129E_DRIVERLIB_TEST_COVERAGE_HTML_DIR}" TM4C129E_DRIVERLIB_TEST_COVERAGE_HTML_DIR_NATIVE)
        file(TO_NATIVE_PATH "${TM4C129E_DRIVERLIB_TEST_COVERAGE_XML_FILE}" TM4C129E_DRIVERLIB_TEST_COVERAGE_XML_FILE_NATIVE)
        file(TO_NATIVE_PATH "${CMAKE_CTEST_COMMAND}" TM4C129E_DRIVERLIB_TEST_CTEST_COMMAND_NATIVE)
        file(TO_NATIVE_PATH "${CMAKE_BINARY_DIR}" TM4C129E_DRIVERLIB_TEST_BINARY_DIR_NATIVE)

        add_custom_target(driverlib_test_coverage
            COMMAND ${CMAKE_COMMAND} -E make_directory "${TM4C129E_DRIVERLIB_TEST_COVERAGE_DIR}"
            COMMAND "${TM4C129E_DRIVERLIB_TEST_OPENCOVERAGE_EXECUTABLE}"
                    --cover_children
                    --sources "${TM4C129E_DRIVERLIB_TEST_COVERAGE_SOURCE_DIR_NATIVE}"
                    --excluded_sources "${TM4C129E_DRIVERLIB_TEST_COVERAGE_EXCLUDED_DIR_NATIVE}"
                    --export_type cobertura:"${TM4C129E_DRIVERLIB_TEST_COVERAGE_XML_FILE_NATIVE}"
                    --export_type html:"${TM4C129E_DRIVERLIB_TEST_COVERAGE_HTML_DIR_NATIVE}"
                    -- "${TM4C129E_DRIVERLIB_TEST_CTEST_COMMAND_NATIVE}" --test-dir "${TM4C129E_DRIVERLIB_TEST_BINARY_DIR_NATIVE}" -C $<CONFIG> --output-on-failure
            DEPENDS driverlib_test_build
            USES_TERMINAL
            COMMENT "Generate OpenCppCoverage coverage report for TM4C129E_DriverLib_Test"
        )
    else()
        add_custom_target(driverlib_test_coverage
            COMMAND ${CMAKE_COMMAND} -E echo "OpenCppCoverage was not found. Install it with: winget install --id OpenCppCoverage.OpenCppCoverage -e"
            COMMAND ${CMAKE_COMMAND} -E echo "After installation, reconfigure CMake and run the driverlib_test_coverage target again."
            COMMENT "OpenCppCoverage is required for tool-generated coverage output"
        )
    endif()
endfunction()
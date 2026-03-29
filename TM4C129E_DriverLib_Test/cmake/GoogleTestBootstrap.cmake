include(FetchContent)

find_package(GTest CONFIG QUIET)

if(NOT TARGET GTest::gtest)
    if(NOT TM4C129E_DRIVERLIB_TEST_FETCH_GTEST)
        message(FATAL_ERROR "GoogleTest was not found and TM4C129E_DRIVERLIB_TEST_FETCH_GTEST is OFF.")
    endif()

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
    )
    FetchContent_MakeAvailable(googletest)
endif()
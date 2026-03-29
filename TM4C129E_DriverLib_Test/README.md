# TM4C129E DriverLib Test

Host-based GoogleTest and GoogleMock coverage for `TM4C129E_DriverLib`.

## Goals

- keep the source under test as the original production `.c` file
- mirror the production path under `TM4C129E_DriverLib_Test`
- use overlay headers and mock bridges to isolate hardware-facing dependencies
- expand chapter coverage without copying the driver implementation into the test tree

## Layout

- `cmake/`
  reusable CMake bootstrap and helper functions
- `coverage/`
  tool-generated coverage output plus the handwritten gap tracker
- `support/include/`
  overlay headers and C++ mock bridge headers
- `support/src/`
  `extern "C"` bridge implementations used by GoogleMock
- `xDriver_MCU/...`
  test sources that mirror the production DriverLib path

## Current Example

- `xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/xSource/SYSEXC_InterruptSource_Test.cpp`

This target compiles the original production source:

- `../TM4C129E_DriverLib/xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/xSource/SYSEXC_InterruptSource.c`

and replaces only the narrow dependency seam needed for host testing.

## Coverage Tool

Free alternative selected for the current Windows plus MSVC host-test path:

- `OpenCppCoverage`

Install with:

```powershell
winget install --id OpenCppCoverage.OpenCppCoverage -e
```

Generate coverage with:

```powershell
cmake --build TM4C129E_DriverLib_Test/build --config Debug --target driverlib_test_coverage
```

Generated coverage outputs:

- `coverage/opencppcoverage/coverage.xml`
- `coverage/opencppcoverage/html/`

## Gap Tracker

- `coverage/TM4C129E_DriverLib_Test_GapTracker.md`

Use this tracker to record:

- sources currently covered by host tests
- important uncovered behavior
- blockers such as missing production code or missing seams
- the next smallest targets to implement

## Adding a New Test

1. Mirror the production path inside `TM4C129E_DriverLib_Test`.
2. Add the test source near that mirrored path.
3. Add overlay headers only for the heavy dependencies the source under test cannot bring to the host build.
4. Add a GoogleMock bridge source if the production C file calls C functions that need interception.
5. Add a full Doxygen-style comment block above every test describing the summary, inputs, outputs, return behavior, and dependencies.
6. Update the gap tracker.
7. Register the target through `tm4c129e_driverlib_add_unit_test(...)`.

## Configure

```powershell
cmake -S TM4C129E_DriverLib_Test -B TM4C129E_DriverLib_Test/build
cmake --build TM4C129E_DriverLib_Test/build --config Debug
ctest --test-dir TM4C129E_DriverLib_Test/build -C Debug --output-on-failure
cmake --build TM4C129E_DriverLib_Test/build --config Debug --target driverlib_test_coverage
```

GoogleTest is resolved with `find_package(GTest)` first and falls back to `FetchContent` when enabled.
Host build outputs are generated under `TM4C129E_DriverLib_Test/build`.

---
name: tm4c129e-driverlib-unit-testing
description: "Use when building or extending TM4C129E_DriverLib_Test, adding GoogleTest or GoogleMock coverage for TM4C129E_DriverLib, mirroring DriverLib paths in tests, compiling original C sources under test, or creating mock overlay headers and C/C++ bridge shims."
---

# TM4C129E DriverLib Unit Testing

## Purpose

Use this skill when the goal is host-based unit testing of `TM4C129E_DriverLib` without copying production `.c` files into the test tree.

Primary test workspace:

- `TM4C129E_DriverLib_Test`

Primary production sources under test:

- `TM4C129E_DriverLib`

## Core Rules

1. Compile the original production `.c` file into the host test target whenever possible.
2. Mirror the production path in `TM4C129E_DriverLib_Test` so each test stays traceable to its production module.
3. Prefer overlay headers and mock bridge sources over edits to production code.
4. If a seam cannot be created with an overlay header, document why before changing production headers.
5. Keep reusable host-test support in shared test-support folders, not inside production trees.
6. Use a tool-generated coverage report for line coverage; in this workspace the preferred free tool is OpenCppCoverage for the MSVC host-test path.
7. Maintain a separate living gap tracker under `TM4C129E_DriverLib_Test/coverage/` that states what is covered, what is missing, and the next implementation targets.
8. Add a full Doxygen-style comment block above every `TEST`, `TEST_F`, or equivalent test case, including summary, inputs, outputs, return behavior, and dependencies.

## Recommended Layout

- `TM4C129E_DriverLib_Test/CMakeLists.txt`
- `TM4C129E_DriverLib_Test/cmake/` for GoogleTest bootstrap and reusable CMake helpers
- `TM4C129E_DriverLib_Test/support/include/` for overlay headers and mock bridge headers
- `TM4C129E_DriverLib_Test/support/src/` for `extern "C"` mock bridge implementations
- `TM4C129E_DriverLib_Test/xDriver_MCU/...` mirroring the production path for test sources
- `TM4C129E_DriverLib_Test/xApplication_MCU/...` mirroring higher-level wrapper coverage later

## Mocking Pattern

Use this pattern when the source under test calls C helper functions:

1. Keep the original production header for the public API under test.
2. Override only the heavy dependency headers with test-overlay headers placed earlier on the include path.
3. In C++ test support, expose a GoogleMock class.
4. Implement `extern "C"` bridge functions that forward the production C calls into the GoogleMock object.
5. Reset the global mock between tests with a small scope helper.

## Build Pattern

1. Use CMake in `TM4C129E_DriverLib_Test`.
2. Prefer `find_package(GTest CONFIG QUIET)` first.
3. Fall back to `FetchContent` for GoogleTest and GoogleMock if they are not already installed.
4. Keep the test target mixed-language: C for original sources, C++ for test sources and mocks.
5. Prefer OpenCppCoverage as the free Windows coverage tool for the MSVC host-test flow.

## Chapter Workflow

When validating a completed chapter:

1. pick the narrowest production source with valuable behavior
2. identify the smallest dependency seam
3. create overlay headers only for that seam
4. compile the original source file directly
5. add focused assertions around masks, offsets, status translation, callbacks, and error paths
6. only after one test target works, widen coverage module by module

## Coverage Tool Pattern

Keep tool-generated coverage output under `TM4C129E_DriverLib_Test/coverage/opencppcoverage/`.

Preferred tool in this workspace:

- `OpenCppCoverage`
- installable with `winget install --id OpenCppCoverage.OpenCppCoverage -e`

Expected outputs:

- `coverage.xml`
- `html/`

## Gap Tracker Pattern

Keep a markdown gap tracker under `TM4C129E_DriverLib_Test/coverage/`.

Each update should include:

1. current source-under-test coverage
2. current test target names
3. uncovered production files or behaviors
4. blockers such as missing production code or unavailable host seams
5. the next smallest useful targets to implement

## Things To Avoid

- copying production `.c` files into the test tree
- mixing host-only code into `TM4C129E_DriverLib`
- replacing all includes with mocks when only one dependency seam is needed
- introducing a test structure that cannot be mapped back to the original driver path
- treating a handwritten markdown plan as if it were a tool-generated coverage result
- creating tests without full Doxygen-style comment blocks that force future readers to infer intent from assertions alone

## Progress Logging

- Log each framework decision, scaffold step, mock seam decision, and validation result under `progress/`.
- Use one file per event with the pattern `progress/YYYY-MM-DD_HH-mm-ss_action-summary.log`.
- Record the original source under test, the mock seam chosen, and any build limitations.
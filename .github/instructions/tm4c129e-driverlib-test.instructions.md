---
description: "Use when editing host-based unit tests in TM4C129E_DriverLib_Test. Covers GoogleTest and GoogleMock setup, mirrored DriverLib test paths, original-source-under-test policy, and overlay header plus mock-bridge patterns."
name: "TM4C129E DriverLib Test Patterns"
applyTo: "TM4C129E_DriverLib_Test/**/*.{c,h,cpp,hpp,cmake,txt,md}"
---

# TM4C129E DriverLib Test Patterns

- Keep host-based unit tests under `TM4C129E_DriverLib_Test`.
- Mirror the original `TM4C129E_DriverLib` directory layout for test sources so each test maps cleanly back to the source under test.
- Compile original production `.c` files directly into the test target whenever possible instead of copying them.
- Keep test-only seams in overlay headers under shared test support include roots.
- Use GoogleMock bridge sources with `extern "C"` wrappers when a production C dependency must be intercepted from C++ tests.
- Keep production driver code unchanged unless an overlay seam is insufficient and the reason is documented.
- Put reusable test support under shared support folders and module-specific assertions under the mirrored module path.
- Prefer small focused test targets that validate one production source at a time.
- Use a tool-generated coverage report for measured coverage; in this workspace prefer OpenCppCoverage for the MSVC host-test flow.
- Maintain a separate gap tracker under `TM4C129E_DriverLib_Test/coverage/` that identifies covered sources, missing coverage, blockers, and next targets.
- Maintain `TM4C129E_DriverLib_Test/coverage/TM4C129E_DriverLib_Test_RequirementTraceability.md` so every `TEST`, `TEST_F`, or equivalent case is linked to either a direct manual requirement or a clearly labeled derived software requirement.
- When a test is manual-backed, record the manual source, chapter or register family, and page context in the traceability matrix. When the behavior is software-only, label it as derived instead of forcing a false manual citation.
- Add a full Doxygen-style comment block above every `TEST`, `TEST_F`, or equivalent test case, including `@brief`, summary/details, inputs, outputs, return behavior, and dependencies.
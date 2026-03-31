# TM4C129E Copilot Instructions

- Record every request, investigation, implementation step, file edit, validation result, and blocker under `progress/`.
- Use one progress file per logged event.
- Use the file name pattern `progress/YYYY-MM-DD_HH-mm-ss_action-summary.log`.
- The first line of each progress file must start with the timestamp in the form `[YYYY-MM-DD HH:MM:SS]` followed immediately by the action being logged.
- Progress logging applies to read-only analysis as well as code changes.
- Before and after implementing a slice, inspect the surrounding implementation for missing companion paths, stale seams, incomplete coverage, or follow-on changes still required, and record those findings under `progress/`.
- Maintain host-test requirement traceability under `TM4C129E_DriverLib_Test/coverage/TM4C129E_DriverLib_Test_RequirementTraceability.md`.
- Every host test case must be linked to either a direct manual requirement with manual, chapter or register context, and page information when available, or to a clearly labeled derived software requirement when the manuals do not define the behavior directly.
- Before finishing a substantial task, ensure the corresponding progress file was created.

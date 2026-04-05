# TM4C129E Workspace Agent Rules

## Progress Logging

- Every request, investigation, design decision, code change, implementation step, validation result, and blocker must be logged under `progress/`.
- Use one file per logged event with the pattern `progress/YYYY-MM-DD_HH-mm-ss_action-summary.log`.
- The first line of each progress file must begin with the timestamp in the form `[YYYY-MM-DD HH:MM:SS]` followed immediately by the action being logged.
- Each progress file should capture, at minimum, the request or action, the key decision or change, the affected files if any, and the validation status or blocker.
- If the task is read-only or analysis-only, log it anyway.
- Do not delete or rewrite previous progress files unless the user explicitly asks for log cleanup.
- Before finishing a substantial task, ensure the corresponding progress entry was recorded.

## Scope Discipline

- When a broad audit or cleanup finds no additional live matches for the requested bug class, stop widening scope instead of inventing adjacent cleanup work.
- If the user asks to pause a side task and return to an earlier subsystem or topic, log the stopping point, preserve the conclusion, and immediately resume the earlier requested scope.

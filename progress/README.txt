Progress Log Convention

- Folder purpose: persistent task and implementation history for this workspace.
- Log file pattern: `progress/YYYY-MM-DD_HH-mm-ss_action-summary.log`.
- The first line of each progress file must start with `[YYYY-MM-DD HH:MM:SS]` followed by the action being logged.
- Minimum content per progress file:
  - request or task
  - action taken
  - files changed or reviewed
  - validation, result, or blocker
- Read-only research and documentation checks must also be logged.
- Keep progress files append-free by default; create a new file for each event unless the user explicitly asks for another convention.
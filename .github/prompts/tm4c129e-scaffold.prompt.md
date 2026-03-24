---
description: "Use when scaffolding a new TM4C129E driver feature, utility helper, or project task in this repository."
name: "TM4C129E Scaffold"
argument-hint: "Describe the layer, module name, feature name, and intended API"
agent: "agent"
---

Scaffold a new TM4C129E module or feature in this repository using the established patterns from the workspace.

Interpret the user input as:

- target layer such as `TM4C129E_ApplicationLib`, `TM4C129E_DriverLib/xDriver_MCU`, `TM4C129E_DriverLib/xApplication_MCU`, or `TM4C129E_Project/xTask`
- module or peripheral name
- feature or task name
- expected public API or task behavior

Execution rules:

1. Inspect nearby files in the target area before editing.
2. Match the local naming, include guard, file banner, and folder structure conventions.
3. For drivers, prefer `xHeader/` and `xSource/` feature pairs instead of large monolithic files.
4. For project tasks, use `void TaskName(void* pvParams)` and the existing `xOS` APIs.
5. Keep new code minimal and consistent with the surrounding module.
6. If the request is underspecified, infer the narrowest useful scaffold instead of inventing a large subsystem.

Expected output:

- create or update the needed files in the correct layer
- preserve the TM4C129E repository style
- summarize which files were created and why they belong there

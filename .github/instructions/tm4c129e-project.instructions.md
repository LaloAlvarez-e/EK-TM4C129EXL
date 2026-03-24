---
description: "Use when editing C files in TM4C129E_Project. Covers startup composition, xOS internals, xTask modules, and project-level application orchestration."
name: "TM4C129E Project Patterns"
applyTo: "TM4C129E_Project/**/*.{c,h}"
---

# TM4C129E Project Patterns

- Keep project composition explicit: initialization order, peripheral bring-up, queue and semaphore creation, task creation, and scheduler start should remain easy to follow.
- Keep RTOS infrastructure in `xOS` and project behavior in `xTask` or project-level `xApplication` modules.
- For task code, preserve the entry pattern `void xTaskN_Name(void* pvParams)` and use `OS_Task__...`, `OS_Queue__...`, and `OS_Semaphore__...` interfaces instead of bypassing the abstraction.
- Keep task implementations periodic and deterministic when that is the local pattern, especially when `OS_Task__uxGetTickCount()` and `OS_Task__vDelayUntil()` are already used.
- Treat top-level startup files, linker scripts, and boot wiring as integration surfaces and avoid incidental edits there.
- Preserve module-prefixed API names, Doxygen-style file headers, and long include guards used by surrounding files.
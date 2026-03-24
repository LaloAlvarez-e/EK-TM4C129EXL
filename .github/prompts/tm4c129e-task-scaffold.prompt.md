---
description: "Use when creating or scaffolding a new TM4C129E xTask module in TM4C129E_Project."
name: "TM4C129E xTask Scaffold"
argument-hint: "Describe the task number, task name, inputs, periodic behavior, and any queues or semaphores used"
agent: "agent"
---

Create or scaffold a new `xTask` module for `TM4C129E_Project` using the existing repository patterns.

Interpret the request as:

- task number and task name
- runtime purpose
- periodic timing behavior
- dependencies on queues, semaphores, peripherals, displays, or application modules

Execution rules:

1. Inspect nearby `xTask/xHeader` and `xTask/xSource` files before editing.
2. Create the header in `TM4C129E_Project/xTask/xHeader/` and the source in `TM4C129E_Project/xTask/xSource/`.
3. Preserve the task entry point form `void xTaskN_Name(void* pvParams)`.
4. Use `xOS` abstractions such as `OS_Task__...`, `OS_Queue__...`, and `OS_Semaphore__...` rather than bypassing them.
5. Keep the task deterministic and periodic when the request fits the local pattern, using `OS_Task__uxGetTickCount()` and `OS_Task__vDelayUntil()`.
6. Match Doxygen banners, include guards, include style, and identifier naming from nearby task modules.
7. If the request does not specify integration in `main.c`, scaffold only the task module unless the user explicitly asks for task registration too.

Expected output:

- create the xTask header and source files in the correct directories
- preserve project task conventions
- summarize what was scaffolded and any integration points still needed

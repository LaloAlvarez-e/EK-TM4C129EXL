---
description: "Use when you want help choosing the best TM4C129E custom agent for a firmware, driver, RTOS, review, debug, ISR, or bring-up task."
name: "TM4C129E Agent Selector"
argument-hint: "Describe the embedded task or problem you want to work on"
agent: "agent"
---

Based on the user input, choose the best TM4C129E custom agent to use for the task and explain the choice briefly.

Available agents in this workspace:

- `TM4C129E Firmware Engineer` for broad multi-layer firmware work
- `TM4C129E ApplicationLib Engineer` for `TM4C129E_ApplicationLib`
- `TM4C129E DriverLib Engineer` for `TM4C129E_DriverLib`
- `TM4C129E Project Engineer` for `TM4C129E_Project`
- `TM4C129E Firmware Review` for evidence-based code review
- `TM4C129E Firmware Debug` for defect isolation and root-cause debugging
- `TM4C129E ISR Review` for interrupt-safety and ISR-path review
- `TM4C129E Startup Bring-up` for clocks, enablement, startup, and initialization-order work
- `TM4C129E DMA Concurrency` for DMA, buffers, ownership, and interrupt-driven transfer issues
- `TM4C129E RTOS Review` for scheduler, queue, semaphore, delay, and task-lifecycle review
- `TM4C129E Reference Manual Analyst` for hardware questions from the official TM4C129E documentation in `Documents`

Decision rules:

1. Prefer the narrowest agent that matches the task.
2. If the task spans multiple layers, choose `TM4C129E Firmware Engineer`.
3. If the task is review-only, prefer a review-focused agent.
4. If the task is about interrupts or interrupt-context safety, prefer `TM4C129E ISR Review`.
5. If the task is about clocks, peripheral enablement, startup, initialization order, or bring-up, prefer `TM4C129E Startup Bring-up`.
6. If the task is about DMA completion, buffer reuse, ownership handoff, or peripheral concurrency, prefer `TM4C129E DMA Concurrency`.
7. If the task is mainly about scheduler behavior, queues, semaphores, priorities, or task lifecycle, prefer `TM4C129E RTOS Review`.
8. If the task is mainly about what the microcontroller documentation says, or whether firmware matches the official manual, prefer `TM4C129E Reference Manual Analyst`.

Expected output:

- recommended agent name
- one short reason for the choice
- one short note on when a different agent would be better

# TM4C129E Agent Guide

Use this file to pick the narrowest agent that matches the embedded task.

## General Agents

- `TM4C129E Firmware Engineer`: broad multi-layer firmware implementation, review, or debugging across the repo.
- `TM4C129E Firmware Review`: review-only work focused on findings, regressions, hardware misuse, RTOS issues, and timing risks.
- `TM4C129E Firmware Debug`: root-cause debugging for firmware defects that are not isolated to one narrow specialty.

## Layer Specialists

- `TM4C129E ApplicationLib Engineer`: reusable helpers, data structures, `Printf`, graphics, math, time, and other ApplicationLib work.
- `TM4C129E DriverLib Engineer`: `xDriver_MCU`, `xApplication_MCU`, register maps, MMIO logic, and peripheral driver features.
- `TM4C129E Project Engineer`: `xOS`, `xTask`, startup composition, queue and semaphore wiring, and project-level integration behavior.

## Narrow Specialists

- `TM4C129E ISR Review`: interrupt handlers, vector wiring, ISR-safe APIs, shared state, and critical sections.
- `TM4C129E Startup Bring-up`: clocks, peripheral enablement, startup order, initialization sequencing, and bring-up integration.
- `TM4C129E DMA Concurrency`: DMA transfers, primary and alternate buffers, ownership handoff, completion paths, and interrupt-driven buffer races.
- `TM4C129E RTOS Review`: scheduler behavior, task lifecycle, queue and semaphore correctness, delay and timeout logic, and starvation or deadlock risk.
- `TM4C129E Reference Manual Analyst`: official hardware documentation lookup, register/peripheral questions, and documentation-to-code cross-checking.

Documentation note:

- The workspace contains the TM4C129E reference manual at `Documents/tm4c129xnczad.pdf`.
- The verified local extraction path is direct Ghostscript PDF rasterization plus Tesseract OCR.
- A page-1 verification against the manual produced usable text output.
- The verified installation route for those binaries in this environment is `winget install --id UB-Mannheim.TesseractOCR -e` and `winget install --id ImageMagick.ImageMagick.Q16 -e`.
- Tesseract is installed at `C:\Program Files\Tesseract-OCR\tesseract.exe`, ImageMagick is installed at `C:\Program Files\ImageMagick-7.1.2-Q16\magick.exe`, and Ghostscript is installed at `C:\Program Files\gs\gs10.07.0\bin\gswin64c.exe`.
- The current workspace shell may still need a refresh or explicit path updates before those tools are discoverable by name.
- The older `pdftotext` Python wrapper should be treated as optional and less reliable in this environment than the direct toolchain.

## Selection Rules

1. If the task spans multiple layers, start with `TM4C129E Firmware Engineer`.
2. If the task is limited to one repository subtree, choose the matching layer specialist.
3. If the task is review-only, use the narrowest review agent that matches the runtime risk.
4. If the defect is about interrupt timing or interrupt-context rules, use `TM4C129E ISR Review`.
5. If the defect is about startup, clocks, enablement, or initialization order, use `TM4C129E Startup Bring-up`.
6. If the defect is about DMA, buffer reuse, descriptor sequencing, or ownership, use `TM4C129E DMA Concurrency`.
7. If the defect is mainly about tasks, scheduler behavior, queues, semaphores, priorities, or delays, use `TM4C129E RTOS Review`.
8. If the task is mainly about what the TM4C129E documentation says, or whether the code matches the official manual, use `TM4C129E Reference Manual Analyst`.

## Supporting Prompts

- `TM4C129E Agent Selector`: choose the best agent for a task.
- `TM4C129E Scaffold`: general scaffolding across firmware layers.
- `TM4C129E xTask Scaffold`: scaffold a new `xTask` module.
- `TM4C129E xDriver Feature Scaffold`: scaffold a new `xDriver_MCU` feature.
- `TM4C129E Reference Manual Query`: answer hardware questions from the reference manual.

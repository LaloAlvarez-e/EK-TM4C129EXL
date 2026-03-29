---
name: tm4c129e-reference-manual
description: "Use when reading the TM4C129E microcontroller reference manual in Documents, answering hardware questions from the official documentation, or cross-checking firmware code against documented peripheral behavior."
---

# TM4C129E Reference Manual Workflow

## Purpose

Use this skill when the task depends on the official TM4C129E documentation rather than only on the firmware source tree.

Primary manual in this workspace:

- `Documents/tm4c129xnczad.pdf`

Verified local tooling state:

- `py` is available, but only Python 3.14 is currently registered in the launcher.
- A `pdftotext.exe` wrapper exists under the user's Python 3.13 scripts directory, but the matching 3.13 runtime is not currently registered, so that path should be treated as secondary.
- Tesseract is installed at `C:\Program Files\Tesseract-OCR\tesseract.exe`.
- ImageMagick is installed at `C:\Program Files\ImageMagick-7.1.2-Q16\magick.exe`.
- Ghostscript is installed at `C:\Program Files\gs\gs10.07.0\bin\gswin64c.exe`.
- The current workspace shell may not yet see those binaries on `PATH`.
- End-to-end local extraction has been verified with the direct pipeline `Ghostscript -> PNG -> Tesseract OCR`.
- A verification pass against page 1 of `Documents/tm4c129xnczad.pdf` produced usable text output.

Verified Windows installation path:

- install Tesseract with `winget install --id UB-Mannheim.TesseractOCR -e`
- install ImageMagick with `winget install --id ImageMagick.ImageMagick.Q16 -e`
- install Ghostscript from its Windows distribution so `gswin64c.exe` is available for PDF rasterization
- then re-verify `tesseract`, `magick`, and `gswin64c` from a new terminal session or call them by explicit path

## What This Skill Is For

- register and peripheral questions
- chapter or section lookups in the reference manual
- reset behavior, clocking, interrupts, DMA, GPIO, UART, ADC, SSI, PWM, EEPROM, timer, and system-control documentation
- cross-checking whether firmware code matches documented hardware behavior
- summarizing relevant parts of the manual for a specific coding task

## Ground Rules

1. Prefer the official manual over memory or generic TM4C assumptions.
2. Do not invent details that were not confirmed from the documentation.
3. Separate three categories in your reasoning:
   - manual fact
   - codebase fact
   - inference
4. If the PDF is not directly readable with available tools, say so and use the best available fallback.
5. When possible, preserve the trace back to the manual by naming the chapter, peripheral block, register, or page context.
6. Do not assume package installation means extraction is working until the actual extraction path has been verified.

## Recommended Workflow

1. Clarify the exact hardware question.
2. Search the workspace for any existing notes, extracted text, or related references.
3. Check whether local extraction tools are available.
4. If extraction is possible, work from the narrowest relevant portion of the manual.
5. Cross-check the relevant firmware files if the question is about whether the code matches the manual.
6. Report the answer with explicit evidence and limitations.

## Extraction Strategy

Use the least fragile approach available in the current environment.

Preferred order:

1. existing extracted text or notes in the workspace
2. direct local extraction with Ghostscript for PDF rasterization and Tesseract for OCR
3. local command-line PDF extraction tools if present
4. `py` plus the installed `pdftotext` Python package, but only if its Windows dependencies and matching runtime are actually available
4. user-provided excerpt, page number, or narrower section if direct extraction is not feasible

If extraction quality is poor, do not overstate certainty.
If Tesseract, ImageMagick, or Ghostscript are unavailable to the current shell, use explicit full paths or treat the extraction path as unavailable.

## Code Cross-Check Strategy

When the question relates to firmware correctness:

1. identify the documented peripheral behavior
2. identify the relevant firmware layer
3. inspect the nearest driver or project code
4. compare documented sequencing, flags, enablement, masks, or field meaning against the code
5. state whether the code appears aligned, ambiguous, or inconsistent

## Answer Style

Prefer this structure:

1. direct answer
2. documentation basis
3. relevant code evidence, if applicable
4. uncertainty or extraction limits

## Things To Avoid

- answering from memory when the manual is the source of truth
- copying broad generic MCU advice without confirming it applies to this device
- confusing application-level repo behavior with hardware-defined behavior
- claiming page-accurate or section-accurate evidence when it was not actually obtained

## Progress Logging

- Log every documentation lookup, extraction step, code cross-check, and resulting decision under `progress/`.
- Use one file per event with the pattern `progress/YYYY-MM-DD_HH-mm-ss_action-summary.log`.
- The first line of each progress file must begin with `[YYYY-MM-DD HH:MM:SS]` followed by the action being logged.
- Record the request, the source checked, files reviewed or changed, and any validation limits or blockers.

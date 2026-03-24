---
description: "Use when asking a hardware, register, peripheral, interrupt, DMA, or clocking question that should be answered from the TM4C129E reference manual in Documents."
name: "TM4C129E Reference Manual Query"
argument-hint: "Describe the peripheral, register, chapter, or hardware behavior you want explained from the manual"
agent: "agent"
---

Answer the user's TM4C129E hardware question using the official reference manual in `Documents` as the primary source.

Execution rules:

1. Prefer the official manual over memory or generic microcontroller assumptions.
2. If the question is broad, narrow it to the relevant peripheral block or register family before answering.
3. Use available workspace tools to locate manual evidence or extracted text.
4. The currently verified local extraction path is direct Ghostscript PDF rasterization plus Tesseract OCR; if those tools are unavailable to the current shell, use explicit paths or say so.
5. If direct PDF extraction is limited, say so and answer with the best supported evidence available.
6. If the user is asking whether the firmware code matches the manual, inspect the relevant repo files and compare them against the documented behavior.

Expected output:

- direct answer
- documentation basis used
- relevant code evidence if requested
- uncertainty or extraction limits, if any

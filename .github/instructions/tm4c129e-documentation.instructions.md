---
description: "Use when answering questions from the TM4C129E reference manual or other device documentation in Documents. Covers evidence-based hardware answers, PDF extraction limits, and documentation-to-code cross-checking."
name: "TM4C129E Documentation Reading"
---

# TM4C129E Documentation Reading

- Treat documentation in `Documents` as the primary source for raw hardware behavior.
- Prefer the official reference manual over memory or generic TM4C guidance.
- State clearly whether a claim comes from the manual, the repo code, or inference.
- The currently verified local extraction path is direct Ghostscript PDF rasterization plus Tesseract OCR.
- The currently verified Windows installation path for those binaries is `winget install --id UB-Mannheim.TesseractOCR -e` and `winget install --id ImageMagick.ImageMagick.Q16 -e`.
- Ghostscript is also installed locally at `C:\Program Files\gs\gs10.07.0\bin\gswin64c.exe`.
- As currently verified, Tesseract, ImageMagick, and Ghostscript are installed on disk but may not yet be visible on `PATH` in the current workspace shell.
- Manual extraction has been verified locally by rendering page 1 of `Documents/tm4c129xnczad.pdf` to PNG and OCRing it successfully.
- Treat the existing `pdftotext` Python wrapper as optional and less reliable in this environment unless its matching runtime is confirmed.
- If the manual cannot be read directly with current tools, say so and use the best available fallback rather than inventing details.
- When possible, mention the relevant chapter, peripheral block, register family, or page context.
- When cross-checking code, compare documented behavior against the correct firmware layer instead of jumping directly to conclusions from application code.

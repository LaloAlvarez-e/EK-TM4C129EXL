---
description: "Use when editing C files in TM4C129E_ApplicationLib. Covers reusable utilities, xUtils patterns, xApplication organization, and thin helper implementations."
name: "TM4C129E ApplicationLib Patterns"
applyTo: "TM4C129E_ApplicationLib/**/*.{c,h}"
---

# TM4C129E ApplicationLib Patterns

- Keep this layer MCU-agnostic unless the local module already depends on MCU-specific types through a stable interface.
- Prefer reusable helpers, data structures, formatting, math, graphics primitives, and common support code here.
- Follow the split `xHeader/` and `xSource/` organization used by `xUtils` and `xApplication` modules.
- Keep implementations narrow and composable, similar to queue and linked-list wrappers.
- Preserve module-prefixed function names and typed arguments such as `Queue__enInit`, `pstQueue`, and `pvfDestroyArg`.
- Use top-level module headers as aggregators, not as large implementation surfaces.
- Preserve Doxygen-style file banners and path-derived include guards where the local module already uses them.

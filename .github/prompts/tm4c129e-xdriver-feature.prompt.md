---
description: "Use when creating or scaffolding a new TM4C129E xDriver_MCU peripheral feature in DriverLib."
name: "TM4C129E xDriver Feature Scaffold"
argument-hint: "Describe the peripheral, feature name, public API, and whether registers, enums, or intrinsics are needed"
agent: "agent"
---

Create or scaffold a new `xDriver_MCU` peripheral feature in `TM4C129E_DriverLib` using the existing repository patterns.

Interpret the request as:

- peripheral or module name such as `GPIO`, `UART`, `ADC`, or `EEPROM`
- feature name and public API
- whether the feature belongs in `Driver/`, `Peripheral/`, `Intrinsics/`, or a combination of these
- any needed enum, register, or configuration additions

Execution rules:

1. Inspect the target peripheral module before editing.
2. Prefer narrow feature files under `Driver/xHeader/` and `Driver/xSource/`.
3. Place hardware definitions in `Peripheral/` and internal helpers in `Intrinsics/` instead of mixing layers.
4. Preserve module-prefixed API names, typed parameter names, Doxygen banners, include guards, and include style.
5. Reuse module-specific enums and error codes such as `MODULE_nERROR`, `MODULE_nMODULE`, and existing `_UNDEF` conventions.
6. Keep register structs `volatile` and preserve union-based raw-register and bitfield access when the feature touches peripheral layout.
7. If the feature can be added without changing umbrella headers, avoid incidental edits; otherwise update aggregation in the smallest compatible way.

Expected output:

- create or update the correct driver files for the new feature
- preserve the repo's driver decomposition style
- summarize where the feature was placed and which additional integration points may remain
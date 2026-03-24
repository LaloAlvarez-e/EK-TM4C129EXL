---
description: "Use when editing C files in TM4C129E_DriverLib. Covers xDriver_MCU raw peripheral structure, xApplication_MCU wrappers, register access patterns, and module-prefixed driver APIs."
name: "TM4C129E DriverLib Patterns"
applyTo: "TM4C129E_DriverLib/**/*.{c,h}"
---

# TM4C129E DriverLib Patterns

- Keep raw register access, register defines, enums, and MMIO structs in `xDriver_MCU`.
- Keep convenience wrappers and higher-level peripheral setup in `xApplication_MCU`.
- Preserve fine-grained module decomposition: feature declarations in `Driver/xHeader/`, implementations in `Driver/xSource/`, low-level helpers in `Intrinsics/`, and hardware definitions in `Peripheral/`.
- Keep register structs `volatile`, preserve raw-register and bitfield union access, and keep reserved memory gaps explicit.
- Reuse module-specific enums and error types such as `GPIO_nERROR`, `UART_nMODULE`, and `_UNDEF` sentinels.
- Do not collapse a peripheral module into a single file when the existing module is split by feature.
- Preserve module-prefixed APIs and typed argument names such as `enModuleArg`, `uxAddressArg`, `pu8DataArg`, and `puxValueArg`.

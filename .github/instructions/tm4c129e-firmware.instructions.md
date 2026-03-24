---
description: "Use when editing TM4C129E firmware C files in TM4C129E_ApplicationLib, TM4C129E_DriverLib, or TM4C129E_Project. Enforces the layered architecture, module-prefixed APIs, xHeader/xSource layout, Doxygen headers, and RTOS/task conventions."
name: "TM4C129E Firmware Patterns"
applyTo: "TM4C129E_ApplicationLib/**/*.{c,h}, TM4C129E_DriverLib/**/*.{c,h}, TM4C129E_Project/**/*.{c,h}"
---

# TM4C129E Firmware Patterns

- Keep code in the correct layer: generic utilities in `TM4C129E_ApplicationLib`, raw MCU driver code in `TM4C129E_DriverLib/xDriver_MCU`, MCU convenience wrappers in `TM4C129E_DriverLib/xApplication_MCU`, and composed application behavior in `TM4C129E_Project`.
- Preserve module-prefixed APIs such as `GPIO__enSetDataByNumber`, `OS_Task__uxCreate`, and `OS_Semaphore__boGive`.
- Preserve typed names for arguments and locals such as `enModuleArg`, `uxValueArg`, `pstConfigArg`, `pvParams`, and `puxCount`.
- Use module-prefixed typedefs and enum values such as `GPIO_nERROR`, `UART_t`, `GPIO_enLEVEL_HIGH`, and `_UNDEF` sentinels where the local module already uses them.
- Add declarations under `xHeader/` and implementations under `xSource/`.
- Keep top-level module headers as aggregators rather than filling them with unrelated implementation logic.
- Preserve Doxygen-style file headers and long uppercase include guards in files that already use them.
- Use root-relative angle-bracket includes such as `#include <xOS/xOS.h>` and `#include <xDriver_MCU/GPIO/GPIO.h>`.
- Keep low-level register structs `volatile`, preserve raw-register and bitfield union access, and keep reserved spacing explicit.
- In project task code, prefer RTOS-facing APIs from `xOS` and keep periodic tasks structured around `OS_Task__uxGetTickCount()` and `OS_Task__vDelayUntil()` when that pattern fits the module.
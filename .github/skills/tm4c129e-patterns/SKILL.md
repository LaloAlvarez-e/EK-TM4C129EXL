---
name: tm4c129e-patterns
description: "Use when working in TM4C129E_ApplicationLib, TM4C129E_DriverLib, or TM4C129E_Project. Preserves the repo's layered TM4C129E architecture, module-prefixed C APIs, xHeader/xSource layout, Doxygen file headers, typed parameter prefixes, and RTOS/task organization."
---

# TM4C129E Repository Patterns

## Purpose

Use this skill when modifying or extending the TM4C129E code in this workspace.

The goal is to preserve the existing design instead of introducing a new style.

## Repository Shape

The repository uses a layered embedded architecture.

1. `TM4C129E_ApplicationLib`
   General reusable utilities and application-level components such as `Printf`, graphics, math, time, and data structures.
2. `TM4C129E_DriverLib`
   MCU-specific code split between a low-level driver layer and a higher-level MCU application layer.
3. `TM4C129E_Project`
   Final composed firmware application with startup files, linker scripts, RTOS code, application modules, images, and user tasks.

Respect these boundaries:

- Put generic utilities in `TM4C129E_ApplicationLib`.
- Put peripheral register access, register definitions, bitfields, and low-level feature control in `TM4C129E_DriverLib/xDriver_MCU`.
- Put MCU convenience wrappers in `TM4C129E_DriverLib/xApplication_MCU`.
- Put product behavior, tasks, queues, semaphores, displays, and composed runtime flows in `TM4C129E_Project`.

## Naming Rules

### Functions

Functions are module-prefixed and usually encode the return type in the function name.

Pattern:

`MODULE__prefixVerbNoun(...)`

Common prefixes:

- `v` for `void`
- `en` for enum return values or status codes
- `ux` for unsigned base-sized values
- `x` for complex return types when already established in the module
- `bo` for boolean results
- `pst` for pointer-to-struct returns
- `pv` for generic pointer returns

Examples already present in the repo:

- `GPIO__enSetDataByNumber`
- `SYSCTL__enEnableRunMode`
- `OS_Task__uxCreate`
- `OS_Semaphore__boGive`
- `MAIN__pstGetPrimaryTransferStruct`

Do not introduce snake_case or unprefixed function names in these modules.

### Types

Use module-prefixed typedefs.

- Enums: `MODULE_nTYPE`
- Structs: `MODULE_TYPE_t` or specialized forms such as `MODULE_Register_t`
- Handles and aliases follow subsystem naming such as `OS_Task_Handle_t`

Examples:

- `GPIO_nERROR`
- `GPIO_nPORT`
- `UART_t`
- `DMA_CH_CTL_t`
- `OS_Task_Handle_t`

### Parameters and Local Variables

Use typed prefixes consistently.

- `en...Arg` for enum parameters
- `ux...Arg` for unsigned base-sized values
- `u8`, `u16`, `u32` for fixed-width unsigned values
- `x`, `sx` for signed values when already established in the module
- `bo...` for boolean values
- `pst...` for struct pointers
- `pv...` for `void*`
- `pc...` for `char*`
- `pux...`, `pu8...`, `pen...` for typed pointers
- `st...` for local struct values

Examples:

- `UART_nMODULE enModuleArg`
- `const uint8_t* pu8DataArg`
- `UBase_t* puxCount`
- `OS_Task_Parameters_t* pstTaskParametersArg`

## File and Folder Structure

Prefer the existing split-by-feature layout.

### Driver modules

Driver modules are decomposed by feature and by responsibility.

Typical layout:

- `Module.h` as the top-level public include
- `Driver/` for behavior APIs
- `Driver/xHeader/` for declarations
- `Driver/xSource/` for implementations
- `Driver/Intrinsics/` for internal helpers and primitives
- `App/` for higher-level configuration helpers around the same peripheral
- `Peripheral/` for enums, register addresses, register defines, and hardware structs
- `Peripheral/Struct/` for register and peripheral struct layouts
- `Peripheral/Register/` for address and mask definitions

When adding a new capability, prefer adding a narrowly scoped header/source pair in the existing feature area instead of expanding a monolithic file.

### Application and utility modules

`TM4C129E_ApplicationLib` also follows split-by-feature organization.

- Aggregator headers at module root
- `xHeader/` and `xSource/` pairs
- `Intrinsics/` for internal data structure helpers
- `Common/` for shared enums, defines, and parameter checks

### Project modules

`TM4C129E_Project` is composed by subsystem.

- `xOS/` for RTOS internals
- `xTask/` for application task entry points
- `xApplication/` for project-level device/application modules
- `xImages/` for static image assets in C form
- top-level startup files and linker scripts remain at project root

Task files are named by function and often by task number, for example `xTask1_AccelerometerLog`.

## Header Style

Preserve the Doxygen-style file banner used across the repo.

Expected elements:

- `@file`
- `@copyright`
- `@par Responsibility`
- `@version`
- `@date`
- `@author`
- `@par Change History`

Also preserve the long include guards using the current path-derived uppercase convention.

## Include Style

Use project-root style includes with angle brackets, for example:

- `#include <xDriver_MCU/GPIO/GPIO.h>`
- `#include <xOS/xOS.h>`
- `#include <xApplication/Printf/Printf.h>`

Do not switch these modules to relative include paths unless the surrounding code already does so.

## Implementation Patterns

### Low-level register access

For peripheral register structures:

- Use `volatile` structs for MMIO representations.
- Preserve unions that expose both raw register access and bitfield views.
- Keep reserved gaps explicit with `reserved` arrays.
- Keep bitbanding variants as separate, explicit structures when the subsystem already uses them.

### Error handling

- Return module-specific enum error codes such as `GPIO_nERROR`.
- Reuse shared `MCU_en...` values through casting when following an existing enum family.
- Preserve `UNDEF_VALUE` and explicit `_UNDEF` enumerators where the subsystem already uses them.

### Initialization flow

In composed firmware code, initialization is explicit and ordered.

Common sequence:

1. Configure system clock and enable peripheral run modes.
2. Initialize low-level modules.
3. Initialize board/application devices.
4. Create queues, semaphores, and RTOS objects.
5. Create tasks.
6. Start the scheduler.

Keep this style when extending startup behavior.

### RTOS and task code

- Keep task entry points as `void TaskName(void* pvParams)`.
- Use `OS_Task__...`, `OS_Queue__...`, and `OS_Semaphore__...` APIs rather than bypassing the abstraction.
- Keep periodic tasks structured around a wake time and `OS_Task__vDelayUntil` when that pattern already exists.

## Change Guidelines

When making changes in this repo:

1. Match the existing layer before choosing where code belongs.
2. Reuse an existing module prefix instead of introducing a new naming family.
3. Add declarations under `xHeader/` and implementations under `xSource/`.
4. Preserve Doxygen headers and include guards.
5. Preserve typedef and parameter prefixes.
6. Avoid collapsing fine-grained modules into large files.
7. Avoid introducing C++-style abstractions or dynamic patterns not already used in the module.
8. When an audit or cleanup request is exhausted for the requested bug class, stop there unless the user explicitly asks to broaden scope.
9. If the user redirects back to an earlier subsystem, preserve the current audit conclusion and resume the earlier subsystem instead of continuing the side task.

## Progress Logging

- For every request, code change, implementation step, or meaningful investigation, create a progress file under `progress/`.
- Use the file pattern `progress/YYYY-MM-DD_HH-mm-ss_action-summary.log`.
- The first line of each progress file must begin with `[YYYY-MM-DD HH:MM:SS]` followed by the action being logged.
- Include the request or action, the decision or change made, affected files, and validation or blocker status.

## Quick Placement Guide

- New generic queue or list helper: `TM4C129E_ApplicationLib/xUtils/...`
- New raw TM4C129E peripheral feature: `TM4C129E_DriverLib/xDriver_MCU/...`
- New high-level MCU convenience wrapper: `TM4C129E_DriverLib/xApplication_MCU/...`
- New product task, semaphore orchestration, or application behavior: `TM4C129E_Project/...`

## Scaffolding Templates

Use these templates as structural guidance. Adapt names to the target module and keep the surrounding style aligned with nearby files.

### New driver capability

When adding a new low-level peripheral capability, prefer a narrow feature pair under `Driver/xHeader` and `Driver/xSource`.

Header pattern:

```c
/**
 *
 * @file MODULE_Feature.h
 * @copyright
 * @verbatim InDeviceMex 2020 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim DD mon. YYYY @endverbatim
 *
 * @author
 * @verbatim vyldram @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author     Version     Description
 * DD mon. YYYY   vyldram    1.0         initial Version@endverbatim
 */

#ifndef XDRIVER_MCU_MODULE_DRIVER_XHEADER_MODULE_FEATURE_H_
#define XDRIVER_MCU_MODULE_DRIVER_XHEADER_MODULE_FEATURE_H_

#include <xDriver_MCU/MODULE/Peripheral/xHeader/MODULE_Enum.h>

MODULE_nERROR MODULE__enSetFeature(MODULE_nMODULE enModuleArg, UBase_t uxValueArg);
MODULE_nERROR MODULE__enGetFeature(MODULE_nMODULE enModuleArg, UBase_t* puxValueArg);

#endif /* XDRIVER_MCU_MODULE_DRIVER_XHEADER_MODULE_FEATURE_H_ */
```

Source pattern:

```c
/** banner matching local style */
#include <xDriver_MCU/MODULE/Driver/xHeader/MODULE_Feature.h>

MODULE_nERROR MODULE__enSetFeature(MODULE_nMODULE enModuleArg, UBase_t uxValueArg)
{
   MODULE_nERROR enErrorReg;

   enErrorReg = MODULE_enERROR_OK;
   /* validate arguments and write register state here */

   return (enErrorReg);
}
```

### New utility helper

For reusable utility logic in `TM4C129E_ApplicationLib`, follow the same `xHeader` and `xSource` pairing and keep wrappers thin when they delegate to lower-level structures.

Header pattern:

```c
/** banner matching local style */
#ifndef XUTILS_SUBSYSTEM_XHEADER_SUBSYSTEM_ACTION_H_
#define XUTILS_SUBSYSTEM_XHEADER_SUBSYSTEM_ACTION_H_

#include <xUtils/SubSystem/xHeader/SubSystem_Struct.h>

SubSystem_nERROR SubSystem__enAction(SubSystem_t* pstObjectArg, UBase_t uxValueArg);

#endif /* XUTILS_SUBSYSTEM_XHEADER_SUBSYSTEM_ACTION_H_ */
```

Source pattern:

```c
/** banner matching local style */
#include <xUtils/SubSystem/xHeader/SubSystem_Action.h>

SubSystem_nERROR SubSystem__enAction(SubSystem_t* pstObjectArg, UBase_t uxValueArg)
{
   SubSystem_nERROR enErrorReg;

   enErrorReg = SubSystem_enERROR_OK;
   /* preserve small focused implementation style */

   return (enErrorReg);
}
```

### New task module

Project task modules belong under `TM4C129E_Project/xTask` and keep the task entry point minimal, periodic, and RTOS-driven.

Header pattern:

```c
/** banner matching local style */
#ifndef XTASK_XHEADER_XTASKN_EXAMPLE_H_
#define XTASK_XHEADER_XTASKN_EXAMPLE_H_

void xTaskN_Example(void* pvParams);

#endif /* XTASK_XHEADER_XTASKN_EXAMPLE_H_ */
```

Source pattern:

```c
/** banner matching local style */
#include <xTask/xHeader/xTaskN_Example.h>

#include <xOS/xOS.h>

void xTaskN_Example(void* pvParams)
{
   UBase_t uxLastWakeTime;
   UBase_t uxPeriodTask;

   uxPeriodTask = (UBase_t) pvParams;
   uxLastWakeTime = OS_Task__uxGetTickCount();

   while(1UL)
   {
      /* task body */
      OS_Task__vDelayUntil(&uxLastWakeTime, uxPeriodTask);
   }
}
```

## Worked Example

If a new GPIO readback helper were needed, the repo pattern suggests:

1. Put the declarations in `TM4C129E_DriverLib/xDriver_MCU/GPIO/Driver/xHeader/`.
2. Put the implementation in the matching `xSource/` directory.
3. Reuse `GPIO_nERROR`, `GPIO_nPORT`, `GPIO_nPIN`, and `GPIO_nLEVEL` instead of inventing new generic types.
4. Keep `GPIO.h` as the umbrella include and expose the feature through the existing driver aggregation path.
5. If the feature requires register definitions, place those changes under `Peripheral/` rather than mixing them into the driver file.

## Agent Checklist

Before finalizing a change, verify:

- The file is placed in the right layer.
- Function and type names match the module prefix style.
- Header/source placement matches the local convention.
- Includes use the repo's include path style.
- Any new enums, structs, and arguments follow the existing prefix rules.
- Startup, linker, and RTOS wiring were only changed when required by the task.
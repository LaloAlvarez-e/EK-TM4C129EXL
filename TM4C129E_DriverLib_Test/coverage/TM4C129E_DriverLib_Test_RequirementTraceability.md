# TM4C129E DriverLib Test Requirement Traceability

## Purpose

This matrix links the current host-based unit tests in `TM4C129E_DriverLib_Test` to explicit requirements.

Each test case is traced to one of the following:

- a direct requirement from the official reference manuals
- a mixed requirement that combines manual register semantics with repository wrapper policy
- a derived software requirement when the manuals do not define the callback, pointer-safety, sequencing, or error-propagation behavior being validated

Manual basis is declared at the test-file section level. Each test row inherits that section context unless the row is explicitly marked `derived`.

## Source Legend

- `tm4c`: `Documents/tm4c129xnczad.pdf`
- `cortex`: `Documents/cortex-m4.pdf`
- `both`: both manuals contribute direct hardware context
- `mixed`: direct manual hardware context plus repository-specific wrapper policy
- `derived`: repository software requirement with no direct manual paragraph defining the behavior

## Current Covered Suite

Path: `xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/xSource/SYSEXC_InterruptSource_Test.cpp`
Manual basis: `tm4c`, Chapter 6 Processor Support and Exception Module, `SYSEXCIM` p.559, `SYSEXCMIS` p.561, `SYSEXCIC` p.563.

- `REQ-SYSEXC-INTSRC-001` -> `EnableInterruptSourceByNumberUsesExpectedRegisterShift` | `tm4c` | The interrupt-source enable helper shall program the documented source bit position in `SYSEXCIM`.
- `REQ-SYSEXC-INTSRC-002` -> `GetInterruptSourceStateByMaskRejectsNullPointer` | `derived` | The interrupt-source getter shall reject a null output pointer before touching the SYSEXC register block.
- `REQ-SYSEXC-INTSRC-003` -> `StatusMaskedInterruptSourceByNumberReadsMaskedStatusRegister` | `tm4c` | The masked-status helper shall read source state from `SYSEXCMIS`.
- `REQ-SYSEXC-INTSRC-004` -> `ClearInterruptSourceByMaskWritesWholeInterruptMask` | `tm4c` | The clear helper shall write the selected mask to `SYSEXCIC` to clear the corresponding exception source.

Path: `xDriver_MCU/SYSEXC/Driver/Intrinsics/Primitives/xSource/SYSEXC_RegisterPrimitives_Test.cpp`
Manual basis: `tm4c`, Chapter 6 register block context, Table 6-1 and SYSEXC base-address map around p.556.

- `REQ-SYSEXC-PRIM-001` -> `ReadRegisterRejectsNullPointer` | `derived` | The SYSEXC read primitive shall reject a null register descriptor.
- `REQ-SYSEXC-PRIM-002` -> `ReadRegisterAddsBlockBaseBeforeMCUAccess` | `tm4c` | The SYSEXC read primitive shall add the documented SYSEXC block base address to the caller offset before MCU access.
- `REQ-SYSEXC-PRIM-003` -> `WriteRegisterAddsBlockBaseBeforeMCUAccess` | `tm4c` | The SYSEXC write primitive shall add the documented SYSEXC block base address to the caller offset before MCU access.
- `REQ-SYSEXC-PRIM-004` -> `WriteRegisterPropagatesModuleValidationError` | `derived` | The SYSEXC write primitive shall propagate module-validation failures without attempting a register write.

Path: `xApplication_MCU/SYSEXC/xSource/SYSEXC_Report_Test.cpp`
Manual basis: `derived`, repository callback/reporting contract informed by the SYSEXC functional context in Chapter 6.

- `REQ-SYSEXC-REPORT-001` -> `RegisterReportHandlerRejectsNullCallback` | `derived` | Report-handler registration shall reject a null callback and leave report dispatch disabled.
- `REQ-SYSEXC-REPORT-002` -> `RegisterReportHandlerDispatchesReportWithContext` | `derived` | Report-handler registration shall preserve the caller context pointer and dispatch the same report pointer to the registered callback.
- `REQ-SYSEXC-REPORT-003` -> `UnregisterAndNullReportPreventDispatch` | `derived` | Unregister and null-report paths shall suppress callback dispatch.

Path: `xApplication_MCU/SYSEXC/xSource/SYSEXC_Init_Test.cpp`
Manual basis: `derived`, initialization policy built around the SYSEXC controller described in `tm4c` Chapter 6.

- `REQ-SYSEXC-INIT-001` -> `InitPropagatesModuleValidationError` | `derived` | The SYSEXC initialization path shall propagate module-validation errors without continuing setup.
- `REQ-SYSEXC-INIT-002` -> `InitPerformsExpectedOrderedSetup` | `derived` | The SYSEXC initialization path shall perform the expected ordered setup of handlers and source configuration.
- `REQ-SYSEXC-INIT-003` -> `InitStopsWhenClearAllSourcesFails` | `derived` | The SYSEXC initialization path shall stop on the first clear-source failure.

Path: `xApplication_MCU/SYSEXC/Interrupt/InterruptRoutine/xSource/SYSEXC_InterruptRoutine_Vector_Test.cpp`
Manual basis: `both`, `tm4c` Chapter 6 `SYSEXCMIS` p.561 and `SYSEXCIC` p.563, plus `cortex` SCB `ICSR` context in section 4.3.3, pp.4-13 to 4-15.

- `REQ-SYSEXC-VECTOR-001` -> `ReportHandlerBuildsSoftwareReportFromContext` | `mixed` | The vector-report helper shall synthesize a software report from stacked context and current exception-state information when no architected MIS bit is asserted.
- `REQ-SYSEXC-VECTOR-002` -> `ReportHandlerEmitsOneReportPerAssertedSource` | `mixed` | The vector-report helper shall emit one report per asserted MIS source while preserving the original masked-status context.
- `REQ-SYSEXC-VECTOR-003` -> `CustomHandlerDispatchesSoftwareCallbackWhenNoBitsAreSet` | `derived` | The custom vector path shall dispatch the software-source callback when no architected source bit is set.
- `REQ-SYSEXC-VECTOR-004` -> `CustomHandlerClearsAndDispatchesEachAssertedSource` | `mixed` | The custom vector path shall clear each asserted source through `SYSEXCIC` and dispatch the corresponding callback in source order.

Path: `xDriver_MCU/Core/NVIC/Driver/Intrinsics/Primitives/xSource/NVIC_RegisterPrimitives_Test.cpp`
Manual basis: `both`, `tm4c` Chapter 3 register map p.158 and `cortex` Table 4-2 p.4-3.

- `REQ-NVIC-PRIM-001` -> `ReadRegisterRejectsNullPointer` | `derived` | The NVIC read primitive shall reject a null register descriptor.
- `REQ-NVIC-PRIM-002` -> `ReadRegisterAddsBlockBaseBeforeMCUAccess` | `both` | The NVIC read primitive shall add the documented NVIC block base address to the caller offset before MCU access.
- `REQ-NVIC-PRIM-003` -> `WriteRegisterAddsBlockBaseBeforeMCUAccess` | `both` | The NVIC write primitive shall add the documented NVIC block base address to the caller offset before MCU access.
- `REQ-NVIC-PRIM-004` -> `WriteRegisterPropagatesModuleValidationError` | `derived` | The NVIC write primitive shall propagate module-validation failures without attempting a register write.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_RegisterAccess_Test.cpp`
Manual basis: `both`, `cortex` sections 4.2.2 to 4.2.3, pp.4-4 to 4-5, with `tm4c` section 3.4 p.165 for device mapping context.

- `REQ-NVIC-REGACC-001` -> `ReadValueRejectsNullPointer` | `derived` | The NVIC value-read helper shall reject a null output pointer.
- `REQ-NVIC-REGACC-002` -> `ReadValueUsesExpectedRegisterOffsetAndBit` | `both` | The NVIC value-read helper shall map the selected vector to the documented ISER word and bit position.
- `REQ-NVIC-REGACC-003` -> `WriteValueUsesExpectedRegisterOffsetAndBit` | `both` | The NVIC value-write helper shall map the selected vector to the documented ICER word and bit position.
- `REQ-NVIC-REGACC-004` -> `WriteValuePropagatesVectorValidationError` | `derived` | The NVIC value-write helper shall propagate vector-validation failures without touching the register block.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_Enable_Test.cpp`
Manual basis: `both`, `cortex` ISER/ICER pp.4-4 to 4-5 and IPR p.4-7.

- `REQ-NVIC-ENABLE-001` -> `GetVectorStateUsesISERReadPath` | `both` | The vector-state getter shall read enable state from the documented ISER register family.
- `REQ-NVIC-ENABLE-002` -> `SetVectorStateUsesICERForDisable` | `both` | The vector-state setter shall route disabled state requests through the documented ICER register family.
- `REQ-NVIC-ENABLE-003` -> `SetVectorStateUsesISERForEnable` | `both` | The vector-state setter shall route enabled state requests through the documented ISER register family.
- `REQ-NVIC-ENABLE-004` -> `EnableVectorProgramsPriorityBeforeEnablingState` | `mixed` | The enable wrapper shall program interrupt priority before issuing the NVIC enable operation.
- `REQ-NVIC-ENABLE-005` -> `EnableVectorStopsWhenPriorityProgrammingFails` | `derived` | The enable wrapper shall stop on the first priority-programming failure.
- `REQ-NVIC-ENABLE-006` -> `DisableVectorUsesDisableStatePath` | `derived` | The disable wrapper shall delegate through the disable-state helper path.
- `REQ-NVIC-ENABLE-007` -> `SetVectorStateUsesDisablePathForUndefinedState` | `derived` | Undefined vector-state inputs shall follow the repository disable-state policy.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_Pending_Test.cpp`
Manual basis: `both`, `cortex` sections 4.2.4 to 4.2.5, pp.4-5 to 4-6.

- `REQ-NVIC-PENDING-001` -> `IsVectorPendingUsesISPRReadPath` | `both` | The pending-state getter shall read from the documented ISPR register family.
- `REQ-NVIC-PENDING-002` -> `SetPendingVectorStateUsesISPRForTrue` | `both` | Setting pending state true shall write to the documented ISPR register family.
- `REQ-NVIC-PENDING-003` -> `SetPendingVectorStateUsesICPRForFalse` | `both` | Setting pending state false shall write to the documented ICPR register family.
- `REQ-NVIC-PENDING-004` -> `SetPendingVectorUsesSetPath` | `derived` | The set-pending wrapper shall delegate through the set-state path.
- `REQ-NVIC-PENDING-005` -> `ClearPendingVectorUsesClearPath` | `derived` | The clear-pending wrapper shall delegate through the clear-state path.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_Active_Test.cpp`
Manual basis: `both`, `cortex` section 4.2.6, p.4-7.

- `REQ-NVIC-ACTIVE-001` -> `GetActiveVectorUsesIABRReadPath` | `both` | The active-state getter shall read from the documented IABR register family.
- `REQ-NVIC-ACTIVE-002` -> `GetActiveVectorPropagatesReadError` | `derived` | The active-state getter shall propagate register-read failures without modifying caller state.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_Priority_Test.cpp`
Manual basis: `both`, `cortex` section 4.2.7, p.4-7.

- `REQ-NVIC-PRI-001` -> `GetVectorPriorityRejectsNullPointer` | `derived` | The priority getter shall reject a null output pointer.
- `REQ-NVIC-PRI-002` -> `GetVectorPriorityUsesExpectedRegisterOffsetAndBit` | `both` | The priority getter shall map the selected vector to the documented IPR register byte lane.
- `REQ-NVIC-PRI-003` -> `SetVectorPriorityUsesExpectedRegisterOffsetAndBit` | `both` | The priority setter shall map the selected vector to the documented IPR register byte lane.
- `REQ-NVIC-PRI-004` -> `SetVectorPriorityPropagatesVectorValidationError` | `derived` | The priority setter shall propagate vector-validation failures without issuing a register write.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_Trigger_Test.cpp`
Manual basis: `both`, `cortex` section 4.2.8, p.4-8.

- `REQ-NVIC-TRIG-001` -> `TriggerVectorWritesSTIRIntidField` | `both` | The software-trigger helper shall program the documented STIR `INTID` field for the selected vector.
- `REQ-NVIC-TRIG-002` -> `TriggerVectorPropagatesValidationError` | `derived` | The software-trigger helper shall reject invalid vectors before the STIR write path.

Path: `xDriver_MCU/Core/NVIC/Driver/xSource/NVIC_DeInitInterrupts_Test.cpp`
Manual basis: `both`, `tm4c` Chapter 3 register map p.158 and `cortex` ISER/ICER pp.4-4 to 4-5.

- `REQ-NVIC-DEINIT-001` -> `DisableAllInterruptsIteratesAcrossAllVectors` | `derived` | The deinitialization helper shall iterate across the implemented vector range and disable each interrupt.
- `REQ-NVIC-DEINIT-002` -> `DisableAllInterruptsStopsOnDisableError` | `derived` | The deinitialization helper shall stop on the first disable error.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_PriorityGroup_Test.cpp`
Manual basis: `both`, `cortex` section 4.3.5, pp.4-16 to 4-18, and `tm4c` section 3.5 p.175.

- `REQ-SCB-PRIGROUP-001` -> `SetPriorityGroupUsesWriteKeyAndBarrierSequence` | `mixed` | The priority-group helper shall write the keyed AIRCR `PRIGROUP` field and preserve the repository barrier sequence around the update.
- `REQ-SCB-PRIGROUP-002` -> `GetPriorityGroupRejectsNullPointer` | `derived` | The priority-group getter shall reject a null output pointer.
- `REQ-SCB-PRIGROUP-003` -> `GetPriorityGroupUsesExpectedMaskAndShift` | `both` | The priority-group getter shall read and decode the documented AIRCR `PRIGROUP` field.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_VectorOffset_Test.cpp`
Manual basis: `both`, `cortex` section 4.3.4, p.4-16.

- `REQ-SCB-VTOR-001` -> `SetVectorOffsetUsesInterruptGuardAndBarrier` | `mixed` | The vector-offset helper shall program the documented VTOR offset field while preserving the repository interrupt-guard and barrier sequence.
- `REQ-SCB-VTOR-002` -> `GetVectorOffsetRejectsNullPointer` | `derived` | The vector-offset getter shall reject a null output pointer.
- `REQ-SCB-VTOR-003` -> `GetVectorOffsetUsesExpectedMask` | `both` | The vector-offset getter shall read and mask the documented VTOR offset field.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_SleepMode_Test.cpp`
Manual basis: `both`, `cortex` section 4.3.6, p.4-19.

- `REQ-SCB-SLEEP-001` -> `SetSleepModeUsesSleepDeepField` | `both` | The sleep-mode setter shall program the documented SCR `SLEEPDEEP` field.
- `REQ-SCB-SLEEP-002` -> `GetSleepModeUsesSleepDeepField` | `both` | The sleep-mode getter shall read the documented SCR `SLEEPDEEP` field.
- `REQ-SCB-SLEEP-003` -> `EnterDeepSleepProgramsModeBeforeWaiting` | `mixed` | The deep-sleep helper shall set the requested sleep mode before the wait-for-interrupt stage.
- `REQ-SCB-SLEEP-004` -> `SleepOnExitUsesExpectedField` | `both` | The sleep-on-exit helper shall access the documented SCR `SLEEPONEXIT` field.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_WakeUp_Test.cpp`
Manual basis: `both`, `cortex` section 4.3.6, p.4-19.

- `REQ-SCB-WAKE-001` -> `SetWakeUpSourceUsesSevOnPendField` | `both` | The wake-up setter shall program the documented SCR `SEVONPEND` field.
- `REQ-SCB-WAKE-002` -> `GetWakeUpSourceUsesSevOnPendField` | `both` | The wake-up getter shall read the documented SCR `SEVONPEND` field.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_StackAligment_Test.cpp`
Manual basis: `both`, `cortex` section 4.3.7, pp.4-19 to 4-20.

- `REQ-SCB-STKALIGN-001` -> `SetStackAligmentUsesExpectedField` | `both` | The stack-alignment setter shall program the documented CCR `STKALIGN` field.
- `REQ-SCB-STKALIGN-002` -> `GetStackAligmentUsesExpectedField` | `both` | The stack-alignment getter shall read the documented CCR `STKALIGN` field.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_SoftwareInterruptTrigger_Test.cpp`
Manual basis: `both`, `cortex` CCR `USERSETMPEND` section 4.3.7 p.4-20 with STIR context at section 4.2.8 p.4-8.

- `REQ-SCB-USERSETMPEND-001` -> `SetUnprivilegedSWTriggerUsesExpectedField` | `both` | The unprivileged software-trigger gate shall program the documented CCR `USERSETMPEND` field.
- `REQ-SCB-USERSETMPEND-002` -> `EnableAndDisableWrappersDelegateToStateSetter` | `derived` | The enable and disable wrappers shall delegate through the shared state-setter path.
- `REQ-SCB-USERSETMPEND-003` -> `GetUnprivilegedSWTriggerUsesExpectedField` | `both` | The getter shall read the documented CCR `USERSETMPEND` field.

Path: `xDriver_MCU/Core/SCB/Driver/xSource/SCB_SysReset_Test.cpp`
Manual basis: `both`, `cortex` AIRCR section 4.3.5, pp.4-16 to 4-18, and `tm4c` SCB reset context under section 3.5.

- `REQ-SCB-SYSRESET-001` -> `RequestSystemResetRejectsUnexpectedVectkeyRead` | `derived` | The system-reset helper shall reject unexpected AIRCR key readback before issuing the reset request.
- `REQ-SCB-SYSRESET-002` -> `RequestSystemResetWritesExpectedAircrValue` | `both` | The system-reset helper shall write the keyed AIRCR `SYSRESETREQ` composition required by the manuals.
- `REQ-SCB-SYSRESET-003` -> `RequestSystemResetDebugWritesExpectedAircrValue` | `both` | The debug-reset helper shall write the expected AIRCR debug-reset composition used by this repository.

Path: `xDriver_MCU/Core/SCB/Driver/Traps/xSource/SCB_DivisionTrap_Test.cpp`
Manual basis: `both`, `cortex` CCR section 4.3.7, p.4-20.

- `REQ-SCB-DIVTRP-001` -> `SetDivisionTrapUsesExpectedField` | `both` | The divide-by-zero trap setter shall program the documented CCR `DIV_0_TRP` field.
- `REQ-SCB-DIVTRP-002` -> `EnableAndDisableDivisionTrapDelegateToStateSetter` | `derived` | The divide-by-zero enable and disable wrappers shall delegate through the shared state-setter path.
- `REQ-SCB-DIVTRP-003` -> `GetDivisionTrapUsesExpectedField` | `both` | The divide-by-zero trap getter shall read the documented CCR `DIV_0_TRP` field.

Path: `xDriver_MCU/Core/SCB/Driver/Traps/xSource/SCB_UnalignTrap_Test.cpp`
Manual basis: `both`, `cortex` CCR section 4.3.7, p.4-20.

- `REQ-SCB-UNALIGN-001` -> `SetUnalignTrapUsesExpectedField` | `both` | The unaligned-access trap setter shall program the documented CCR `UNALIGN_TRP` field.
- `REQ-SCB-UNALIGN-002` -> `EnableAndDisableUnalignTrapDelegateToStateSetter` | `derived` | The unaligned-access enable and disable wrappers shall delegate through the shared state-setter path.
- `REQ-SCB-UNALIGN-003` -> `GetUnalignTrapUsesExpectedField` | `both` | The unaligned-access trap getter shall read the documented CCR `UNALIGN_TRP` field.

Path: `xApplication_MCU/Core/SYSTICK/xSource/SYSTICK_Calibration_Test.cpp`
Manual basis: `cortex`, Table 4-32 p.4-33 and sections 4.4.2 to 4.4.4, pp.4-34 to 4-35.

- `REQ-SYSTICK-CAL-001` -> `GetTickTimingPsFallsBackWhenCalibrationIsNotTrusted` | `mixed` | The calibration helper shall fall back to nominal timing when the calibration source is not trusted.
- `REQ-SYSTICK-CAL-002` -> `GetTickTimingPsUsesTrustedReferenceCalibrationWhenSystemClockDiffers` | `mixed` | The timing helper shall correct nominal tick timing by the trusted `TENMS` reference ratio when the system clock differs from the nominal reference.
- `REQ-SYSTICK-CAL-003` -> `GetTrustedCalibrationInfoAcceptsExactReferenceCountDeviation` | `mixed` | Exact external-reference calibration counts that differ from the nominal 40000-tick example shall still be treated as trusted when the reference conditions are satisfied.
- `REQ-SYSTICK-CAL-004` -> `GetCalibrationInfoTreatsTenMsValueAsTickCount` | `cortex` | The calibration helper shall interpret `TENMS` as a direct tick-count value, not a reload-minus-one value.
- `REQ-SYSTICK-CAL-005` -> `GetCalibrationReloadUsUsesTenMsCountExample` | `mixed` | The reload conversion helper shall preserve the documented `TENMS` tick-count semantics when converting to a 1 ms reload example.
- `REQ-SYSTICK-CAL-006` -> `GetCalibrationTimeUsUsesInverseTenMsCountExample` | `mixed` | The inverse time helper shall preserve the documented `TENMS` tick-count semantics when converting back to time.
- `REQ-SYSTICK-CAL-007` -> `GetTickCountUsFallsBackWhenCalibrationIsNotTrusted` | `mixed` | The microseconds-to-ticks helper shall fall back to nominal conversion when calibration is not trusted.
- `REQ-SYSTICK-CAL-008` -> `GetTickCountUsUsesTrustedCalibrationConversion` | `mixed` | The microseconds-to-ticks helper shall use the trusted calibration ratio when the measured reference is below nominal.
- `REQ-SYSTICK-CAL-009` -> `GetTickCountUsUsesTrustedCalibrationConversionAboveNominal` | `mixed` | The microseconds-to-ticks helper shall use the trusted calibration ratio when the measured reference is above nominal.

Path: `xDriver_MCU/SYSCTL/Driver/Intrinsics/Primitives/xSource/SYSCTL_RegisterPrimitives_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, Table 5-11 register map p.260.

- `REQ-SYSCTL-PRIM-001` -> `ReadRegisterRejectsNullPointer` | `derived` | The SYSCTL read primitive shall reject a null register descriptor.
- `REQ-SYSCTL-PRIM-002` -> `ReadRegisterAddsBlockBaseBeforeMCUAccess` | `tm4c` | The SYSCTL read primitive shall add the documented SYSCTL block base address to the caller offset before MCU access.
- `REQ-SYSCTL-PRIM-003` -> `WriteRegisterAddsBlockBaseBeforeMCUAccess` | `tm4c` | The SYSCTL write primitive shall add the documented SYSCTL block base address to the caller offset before MCU access.
- `REQ-SYSCTL-PRIM-004` -> `WriteRegisterPropagatesModuleValidationError` | `derived` | The SYSCTL write primitive shall propagate module-validation failures without attempting a register write.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_AlternateClock_Test.cpp`
Manual basis: `tm4c`, `ALTCLKCFG` p.293.

- `REQ-SYSCTL-ALTCLK-001` -> `SetAlternateClockSourceUsesExpectedALTCLKCFGField` | `tm4c` | The alternate-clock setter shall program the documented `ALTCLKCFG.ALTCLK` field.
- `REQ-SYSCTL-ALTCLK-002` -> `GetAlternateClockSourceRejectsNullPointer` | `derived` | The alternate-clock getter shall reject a null output pointer.
- `REQ-SYSCTL-ALTCLK-003` -> `GetAlternateClockSourceUsesExpectedALTCLKCFGField` | `tm4c` | The alternate-clock getter shall read the documented `ALTCLKCFG.ALTCLK` field.
- `REQ-SYSCTL-ALTCLK-004` -> `GetAlternateClockSourcePropagatesReadError` | `derived` | The alternate-clock getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_OutputClock_Test.cpp`
Manual basis: `tm4c`, `DIVSCLK` p.297.

- `REQ-SYSCTL-DIVSCLK-001` -> `SetOutputClockStateUsesExpectedDIVSCLKEnableField` | `tm4c` | The output-clock state setter shall program the documented `DIVSCLK.EN` field.
- `REQ-SYSCTL-DIVSCLK-002` -> `SetOutputClockSourceUsesExpectedDIVSCLKSourceField` | `tm4c` | The output-clock source setter shall program the documented `DIVSCLK.SRC` field.
- `REQ-SYSCTL-DIVSCLK-003` -> `SetOutputClockDivisorUsesExpectedDIVSCLKDivField` | `tm4c` | The output-clock divisor setter shall program the documented `DIVSCLK.DIV` field.
- `REQ-SYSCTL-DIVSCLK-004` -> `GetOutputClockStateRejectsNullPointer` | `derived` | The output-clock state getter shall reject a null output pointer.
- `REQ-SYSCTL-DIVSCLK-005` -> `GetOutputClockStateUsesExpectedDIVSCLKEnableField` | `tm4c` | The output-clock state getter shall read the documented `DIVSCLK.EN` field.
- `REQ-SYSCTL-DIVSCLK-006` -> `GetOutputClockSourceUsesExpectedDIVSCLKSourceField` | `tm4c` | The output-clock source getter shall read the documented `DIVSCLK.SRC` field.
- `REQ-SYSCTL-DIVSCLK-007` -> `GetOutputClockDivisorUsesExpectedDIVSCLKDivField` | `tm4c` | The output-clock divisor getter shall read the documented `DIVSCLK.DIV` field.
- `REQ-SYSCTL-DIVSCLK-008` -> `SetOutputClockConfigUsesDisableDivisorSourceStateOrdering` | `mixed` | The composite output-clock setter shall preserve the repository ordering of disable, divisor, source, and final state updates around `DIVSCLK`.
- `REQ-SYSCTL-DIVSCLK-009` -> `SetOutputClockConfigStopsOnFirstWriteError` | `derived` | The composite output-clock setter shall stop on the first write error.
- `REQ-SYSCTL-DIVSCLK-010` -> `GetOutputClockConfigUsesDivisorSourceStateOrdering` | `mixed` | The composite output-clock getter shall preserve the repository ordering of divisor, source, and state reads.
- `REQ-SYSCTL-DIVSCLK-011` -> `GetOutputClockConfigStopsOnFirstReadError` | `derived` | The composite output-clock getter shall stop on the first read error.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_ResetCause_Test.cpp`
Manual basis: `tm4c`, `RESC` p.280.

- `REQ-SYSCTL-RESC-001` -> `GetResetCauseRejectsNullPointer` | `derived` | The reset-cause getter shall reject a null output pointer.
- `REQ-SYSCTL-RESC-002` -> `GetResetCauseUsesExpectedRESCRegisterMask` | `tm4c` | The reset-cause getter shall read the documented reset-cause bits from `RESC`.
- `REQ-SYSCTL-RESC-003` -> `GetResetCausePropagatesReadError` | `derived` | The reset-cause getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-RESC-004` -> `ClearResetCauseUsesExpectedRESCRegisterMask` | `tm4c` | The reset-cause clearer shall write the selected reset-cause bit mask through `RESC` as defined by the manual.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_NMICause_Test.cpp`
Manual basis: `tm4c`, `NMIC` p.284.

- `REQ-SYSCTL-NMIC-001` -> `GetNMICauseRejectsNullPointer` | `derived` | The NMI-cause getter shall reject a null output pointer.
- `REQ-SYSCTL-NMIC-002` -> `GetNMICauseUsesExpectedNMICRegisterMask` | `tm4c` | The NMI-cause getter shall read the documented `NMIC` status bits.
- `REQ-SYSCTL-NMIC-003` -> `GetNMICausePropagatesReadError` | `derived` | The NMI-cause getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-NMIC-004` -> `ClearNMICauseUsesExpectedNMICRegisterMask` | `mixed` | The NMI-cause clearer shall target the documented `NMIC` bit mask even though the full hardware clear sequence requires additional underlying-source clearing steps beyond this wrapper.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_ResetBehavior_Test.cpp`
Manual basis: `tm4c`, `RESBEHAVCTL` p.322.

- `REQ-SYSCTL-RESBEHAV-001` -> `SetResetBehaviorExternalUsesExpectedField` | `tm4c` | The external-reset behavior setter shall program the documented `RESBEHAVCTL.EXTRES` field.
- `REQ-SYSCTL-RESBEHAV-002` -> `GetResetBehaviorExternalRejectsNullPointer` | `derived` | The external-reset behavior getter shall reject a null output pointer.
- `REQ-SYSCTL-RESBEHAV-003` -> `GetResetBehaviorExternalUsesExpectedField` | `tm4c` | The external-reset behavior getter shall read the documented `RESBEHAVCTL.EXTRES` field.
- `REQ-SYSCTL-RESBEHAV-004` -> `SetResetBehaviorBORUsesExpectedField` | `tm4c` | The BOR behavior setter shall program the documented `RESBEHAVCTL.BOR` field.
- `REQ-SYSCTL-RESBEHAV-005` -> `GetResetBehaviorBORUsesExpectedField` | `tm4c` | The BOR behavior getter shall read the documented `RESBEHAVCTL.BOR` field.
- `REQ-SYSCTL-RESBEHAV-006` -> `SetResetBehaviorWDG0UsesExpectedField` | `tm4c` | The Watchdog 0 behavior setter shall program the documented `RESBEHAVCTL.WDOG0` field.
- `REQ-SYSCTL-RESBEHAV-007` -> `GetResetBehaviorWDG0UsesExpectedField` | `tm4c` | The Watchdog 0 behavior getter shall read the documented `RESBEHAVCTL.WDOG0` field.
- `REQ-SYSCTL-RESBEHAV-008` -> `SetResetBehaviorWDG1UsesExpectedField` | `tm4c` | The Watchdog 1 behavior setter shall program the documented `RESBEHAVCTL.WDOG1` field.
- `REQ-SYSCTL-RESBEHAV-009` -> `GetResetBehaviorWDG1UsesExpectedField` | `tm4c` | The Watchdog 1 behavior getter shall read the documented `RESBEHAVCTL.WDOG1` field.
- `REQ-SYSCTL-RESBEHAV-010` -> `GetResetBehaviorWDG1PropagatesReadError` | `derived` | The reset-behavior getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralPresent_Test.cpp`
Manual basis: `tm4c`, `PP` register family start p.335 and Table 5-11 p.260.

- `REQ-SYSCTL-PP-001` -> `IsPeripheralPresentRejectsNullPointer` | `derived` | The peripheral-present getter shall reject a null output pointer.
- `REQ-SYSCTL-PP-002` -> `IsPeripheralPresentUsesExpectedPeripheralRead` | `tm4c` | The peripheral-present helper shall route the selected peripheral through the documented `PP` register family.
- `REQ-SYSCTL-PP-003` -> `IsPeripheralPresentPropagatesReadError` | `derived` | The peripheral-present helper shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralReady_Test.cpp`
Manual basis: `tm4c`, `PR` register family start p.525 and Table 5-11 p.260.

- `REQ-SYSCTL-PR-001` -> `IsPeripheralReadyRejectsNullPointer` | `derived` | The peripheral-ready getter shall reject a null output pointer.
- `REQ-SYSCTL-PR-002` -> `IsPeripheralReadyUsesExpectedPeripheralRead` | `tm4c` | The peripheral-ready helper shall route the selected peripheral through the documented `PR` register family.
- `REQ-SYSCTL-PR-003` -> `IsPeripheralReadyPropagatesReadError` | `derived` | The peripheral-ready helper shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralPower_Test.cpp`
Manual basis: `tm4c`, `PC` register family start p.475 and Table 5-11 p.260.

- `REQ-SYSCTL-PC-001` -> `SetPowerControlStateUsesExpectedPeripheralWrite` | `tm4c` | The power-control setter shall route the selected peripheral through the documented `PC` register family.
- `REQ-SYSCTL-PC-002` -> `PowerOnUsesEnabledState` | `derived` | The power-on wrapper shall delegate through the shared setter using the enabled state value.
- `REQ-SYSCTL-PC-003` -> `PowerOffUsesDisabledState` | `derived` | The power-off wrapper shall delegate through the shared setter using the disabled state value.
- `REQ-SYSCTL-PC-004` -> `GetPowerControlStateRejectsNullPointer` | `derived` | The power-control getter shall reject a null output pointer.
- `REQ-SYSCTL-PC-005` -> `GetPowerControlStateUsesExpectedPeripheralRead` | `tm4c` | The power-control getter shall route the selected peripheral through the documented `PC` register family.
- `REQ-SYSCTL-PC-006` -> `GetPowerControlStatePropagatesReadError` | `derived` | The power-control getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralReset_Test.cpp`
Manual basis: `tm4c`, Chapter 5, section 5.2.2.6 Software Reset, `SRx` register family beginning at offset `0x500` with `SRWD` anchored at p.354, plus `PR` semantics p.525.

- `REQ-SYSCTL-SR-001` -> `SetPeripheralResetUsesAssertThenReleaseWriteOrderingAndReadyPoll` | `mixed` | The peripheral-reset helper shall assert and release the documented `SRx` bit and then poll the ready status until the peripheral reports ready.
- `REQ-SYSCTL-SR-002` -> `SetPeripheralResetStopsWhenAssertWriteFails` | `derived` | The peripheral-reset helper shall stop immediately when the reset-assert write fails.
- `REQ-SYSCTL-SR-003` -> `SetPeripheralResetStopsWhenReleaseWriteFails` | `derived` | The peripheral-reset helper shall stop immediately when the reset-release write fails.
- `REQ-SYSCTL-SR-004` -> `SetPeripheralResetPropagatesReadyReadError` | `derived` | The peripheral-reset helper shall propagate ready-read failures without continuing the poll loop.
- `REQ-SYSCTL-SR-005` -> `IsPeripheralOnResetRejectsNullPointer` | `derived` | The peripheral-reset state getter shall reject a null output pointer.
- `REQ-SYSCTL-SR-006` -> `IsPeripheralOnResetUsesExpectedPeripheralRead` | `tm4c` | The peripheral-reset state getter shall route the selected peripheral through the documented `SRx` register family.
- `REQ-SYSCTL-SR-007` -> `IsPeripheralOnResetPropagatesReadError` | `derived` | The peripheral-reset state getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralSleepMode_Test.cpp`
Manual basis: `tm4c`, Chapter 5 Sleep Mode Clock Gating Control register family, `SCGCx` registers beginning at offset `0x700`, with `PR` semantics p.525.

- `REQ-SYSCTL-SCGC-001` -> `SetSleepModeStateUsesExpectedPeripheralWriteAndReadyPoll` | `mixed` | The sleep-mode helper shall write the documented `SCGCx` bit for the selected peripheral and then poll ready status until the peripheral reports ready.
- `REQ-SYSCTL-SCGC-002` -> `EnableSleepModeUsesEnabledState` | `derived` | The sleep-mode enable wrapper shall delegate through the shared setter using the enabled state.
- `REQ-SYSCTL-SCGC-003` -> `DisableSleepModeUsesDisabledState` | `derived` | The sleep-mode disable wrapper shall delegate through the shared setter using the disabled state.
- `REQ-SYSCTL-SCGC-004` -> `SetSleepModeStatePropagatesReadyReadError` | `derived` | The sleep-mode setter shall propagate ready-read failures without continuing the poll loop.
- `REQ-SYSCTL-SCGC-005` -> `GetSleepModeStateRejectsNullPointer` | `derived` | The sleep-mode getter shall reject a null output pointer.
- `REQ-SYSCTL-SCGC-006` -> `GetSleepModeStateUsesExpectedPeripheralRead` | `tm4c` | The sleep-mode getter shall route the selected peripheral through the documented `SCGCx` register family.
- `REQ-SYSCTL-SCGC-007` -> `GetSleepModeStatePropagatesReadError` | `derived` | The sleep-mode getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralRunMode_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control run-mode clock-gating semantics around p.239 and Table 5-11 `RCGCx` family start p.250, with `PR` semantics p.525.

- `REQ-SYSCTL-RCGC-001` -> `SetRunModeStateUsesExpectedPeripheralWriteAndReadyPoll` | `mixed` | The run-mode helper shall write the documented `RCGCx` bit for the selected peripheral and then poll ready status until the peripheral reports ready.
- `REQ-SYSCTL-RCGC-002` -> `EnableRunModeUsesEnabledState` | `derived` | The run-mode enable wrapper shall delegate through the shared setter using the enabled state.
- `REQ-SYSCTL-RCGC-003` -> `DisableRunModeUsesDisabledState` | `derived` | The run-mode disable wrapper shall delegate through the shared setter using the disabled state.
- `REQ-SYSCTL-RCGC-004` -> `SetRunModeStatePropagatesReadyReadError` | `derived` | The run-mode setter shall propagate ready-read failures without continuing the poll loop.
- `REQ-SYSCTL-RCGC-005` -> `GetRunModeStateRejectsNullPointer` | `derived` | The run-mode getter shall reject a null output pointer.
- `REQ-SYSCTL-RCGC-006` -> `GetRunModeStateUsesExpectedPeripheralRead` | `tm4c` | The run-mode getter shall route the selected peripheral through the documented `RCGCx` register family.
- `REQ-SYSCTL-RCGC-007` -> `GetRunModeStatePropagatesReadError` | `derived` | The run-mode getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PeripheralDeepSleepMode_Test.cpp`
Manual basis: `tm4c`, Chapter 5 deep-sleep clock-gating semantics around pp.239-240 and Table 5-11 `DCGCx` family start p.252, with `PR` semantics p.525.

- `REQ-SYSCTL-DCGC-001` -> `SetDeepSleepModeStateUsesExpectedPeripheralWriteAndReadyPoll` | `mixed` | The deep-sleep helper shall write the documented `DCGCx` bit for the selected peripheral and then poll ready status until the peripheral reports ready.
- `REQ-SYSCTL-DCGC-002` -> `EnableDeepSleepModeUsesEnabledState` | `derived` | The deep-sleep enable wrapper shall delegate through the shared setter using the enabled state.
- `REQ-SYSCTL-DCGC-003` -> `DisableDeepSleepModeUsesDisabledState` | `derived` | The deep-sleep disable wrapper shall delegate through the shared setter using the disabled state.
- `REQ-SYSCTL-DCGC-004` -> `SetDeepSleepModeStatePropagatesReadyReadError` | `derived` | The deep-sleep setter shall propagate ready-read failures without continuing the poll loop.
- `REQ-SYSCTL-DCGC-005` -> `GetDeepSleepModeStateRejectsNullPointer` | `derived` | The deep-sleep getter shall reject a null output pointer.
- `REQ-SYSCTL-DCGC-006` -> `GetDeepSleepModeStateUsesExpectedPeripheralRead` | `tm4c` | The deep-sleep getter shall route the selected peripheral through the documented `DCGCx` register family.
- `REQ-SYSCTL-DCGC-007` -> `GetDeepSleepModeStatePropagatesReadError` | `derived` | The deep-sleep getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_GatingClock_Test.cpp`
Manual basis: `tm4c`, `RSCLKCFG` register map Table 5-11 p.260, register description pp.288-289, and run/sleep clocking context pp.252-253.

- `REQ-SYSCTL-RSCLKCFG-001` -> `UpdateMemoryTimingUsesExpectedField` | `tm4c` | The memory-timing updater shall write the documented `RSCLKCFG.MEMTIMU` update field.
- `REQ-SYSCTL-RSCLKCFG-002` -> `UpdatePLLValuesUsesExpectedField` | `tm4c` | The PLL-value updater shall write the documented `RSCLKCFG.NEWFREQ` update field.
- `REQ-SYSCTL-RSCLKCFG-003` -> `AllowChangeToSleepModeUsesExpectedField` | `tm4c` | The sleep-mode gating selector shall program the documented `RSCLKCFG.ACG` field.
- `REQ-SYSCTL-RSCLKCFG-004` -> `IsAllowedChangeToSleepModeRejectsNullPointer` | `derived` | The sleep-mode gating selector getter shall reject a null output pointer.
- `REQ-SYSCTL-RSCLKCFG-005` -> `IsAllowedChangeToSleepModeUsesExpectedField` | `tm4c` | The sleep-mode gating selector getter shall read the documented `RSCLKCFG.ACG` field.
- `REQ-SYSCTL-RSCLKCFG-006` -> `IsAllowedChangeToSleepModePropagatesReadError` | `derived` | The sleep-mode gating selector getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-RSCLKCFG-007` -> `SetSystemClockSourceUsesExpectedField` | `tm4c` | The system-clock source setter shall program the documented `RSCLKCFG.USEPLL` field.
- `REQ-SYSCTL-RSCLKCFG-008` -> `GetSystemClockSourceRejectsNullPointer` | `derived` | The system-clock source getter shall reject a null output pointer.
- `REQ-SYSCTL-RSCLKCFG-009` -> `GetSystemClockSourceUsesExpectedField` | `tm4c` | The system-clock source getter shall read the documented `RSCLKCFG.USEPLL` field.
- `REQ-SYSCTL-RSCLKCFG-010` -> `GetSystemClockSourcePropagatesReadError` | `derived` | The system-clock source getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-RSCLKCFG-011` -> `SetPLLClockSourceUsesExpectedField` | `tm4c` | The PLL-clock source setter shall program the documented `RSCLKCFG.PLLSRC` field.
- `REQ-SYSCTL-RSCLKCFG-012` -> `GetPLLClockSourceRejectsNullPointer` | `derived` | The PLL-clock source getter shall reject a null output pointer.
- `REQ-SYSCTL-RSCLKCFG-013` -> `GetPLLClockSourceUsesExpectedField` | `tm4c` | The PLL-clock source getter shall read the documented `RSCLKCFG.PLLSRC` field.
- `REQ-SYSCTL-RSCLKCFG-014` -> `GetPLLClockSourcePropagatesReadError` | `derived` | The PLL-clock source getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-RSCLKCFG-015` -> `SetOscillatorClockSourceUsesExpectedField` | `tm4c` | The oscillator-clock source setter shall program the documented `RSCLKCFG.OSCSRC` field.
- `REQ-SYSCTL-RSCLKCFG-016` -> `GetOscillatorClockSourceRejectsNullPointer` | `derived` | The oscillator-clock source getter shall reject a null output pointer.
- `REQ-SYSCTL-RSCLKCFG-017` -> `GetOscillatorClockSourceUsesExpectedField` | `tm4c` | The oscillator-clock source getter shall read the documented `RSCLKCFG.OSCSRC` field.
- `REQ-SYSCTL-RSCLKCFG-018` -> `GetOscillatorClockSourcePropagatesReadError` | `derived` | The oscillator-clock source getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-RSCLKCFG-019` -> `SetOscillatorClockDivisorUsesExpectedField` | `tm4c` | The oscillator-clock divisor setter shall program the documented `RSCLKCFG.OSYSDIV` field.
- `REQ-SYSCTL-RSCLKCFG-020` -> `GetOscillatorClockDivisorRejectsNullPointer` | `derived` | The oscillator-clock divisor getter shall reject a null output pointer.
- `REQ-SYSCTL-RSCLKCFG-021` -> `GetOscillatorClockDivisorUsesExpectedField` | `tm4c` | The oscillator-clock divisor getter shall read the documented `RSCLKCFG.OSYSDIV` field.
- `REQ-SYSCTL-RSCLKCFG-022` -> `GetOscillatorClockDivisorPropagatesReadError` | `derived` | The oscillator-clock divisor getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-RSCLKCFG-023` -> `SetPLLClockDivisorUsesExpectedField` | `tm4c` | The PLL-clock divisor setter shall program the documented `RSCLKCFG.PSYSDIV` field.
- `REQ-SYSCTL-RSCLKCFG-024` -> `GetPLLClockDivisorRejectsNullPointer` | `derived` | The PLL-clock divisor getter shall reject a null output pointer.
- `REQ-SYSCTL-RSCLKCFG-025` -> `GetPLLClockDivisorUsesExpectedField` | `tm4c` | The PLL-clock divisor getter shall read the documented `RSCLKCFG.PSYSDIV` field.
- `REQ-SYSCTL-RSCLKCFG-026` -> `GetPLLClockDivisorPropagatesReadError` | `derived` | The PLL-clock divisor getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_DeepSleepGatingClock_Test.cpp`
Manual basis: `tm4c`, `DSCLKCFG` register map Table 5-11 p.260, register description pp.294-296, and deep-sleep clocking context pp.253-254.

- `REQ-SYSCTL-DSCLKCFG-001` -> `SetPIOSCStateOnDeepSleepUsesDisabledFieldEncoding` | `mixed` | The deep-sleep PIOSC setter shall translate the public disabled state into the documented `DSCLKCFG.PIOSCPD` field encoding.
- `REQ-SYSCTL-DSCLKCFG-002` -> `SetPIOSCStateOnDeepSleepUsesEnabledFieldEncoding` | `mixed` | The deep-sleep PIOSC setter shall translate the public enabled state into the documented `DSCLKCFG.PIOSCPD` field encoding.
- `REQ-SYSCTL-DSCLKCFG-003` -> `GetPIOSCStateOnDeepSleepRejectsNullPointer` | `derived` | The deep-sleep PIOSC getter shall reject a null output pointer.
- `REQ-SYSCTL-DSCLKCFG-004` -> `GetPIOSCStateOnDeepSleepMapsEnabledFieldEncoding` | `mixed` | The deep-sleep PIOSC getter shall translate the documented enabled `DSCLKCFG.PIOSCPD` field value into the public enabled state.
- `REQ-SYSCTL-DSCLKCFG-005` -> `GetPIOSCStateOnDeepSleepMapsDisabledFieldEncoding` | `mixed` | The deep-sleep PIOSC getter shall translate the documented disabled `DSCLKCFG.PIOSCPD` field value into the public disabled state.
- `REQ-SYSCTL-DSCLKCFG-006` -> `GetPIOSCStateOnDeepSleepPropagatesReadError` | `derived` | The deep-sleep PIOSC getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-DSCLKCFG-007` -> `AllowDisableMOSCOnFailureUsesExpectedField` | `tm4c` | The MOSC-failure deep-sleep selector shall program the documented `DSCLKCFG.MOSCDPD` field.
- `REQ-SYSCTL-DSCLKCFG-008` -> `IsAllowedDisableMOSCOnFailureRejectsNullPointer` | `derived` | The MOSC-failure deep-sleep getter shall reject a null output pointer.
- `REQ-SYSCTL-DSCLKCFG-009` -> `IsAllowedDisableMOSCOnFailureUsesExpectedField` | `tm4c` | The MOSC-failure deep-sleep getter shall read the documented `DSCLKCFG.MOSCDPD` field.
- `REQ-SYSCTL-DSCLKCFG-010` -> `IsAllowedDisableMOSCOnFailurePropagatesReadError` | `derived` | The MOSC-failure deep-sleep getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-DSCLKCFG-011` -> `SetDeepSleepOscillatorClockSourceUsesExpectedField` | `tm4c` | The deep-sleep oscillator source setter shall program the documented `DSCLKCFG.DSOSCSRC` field.
- `REQ-SYSCTL-DSCLKCFG-012` -> `GetDeepSleepOscillatorClockSourceRejectsNullPointer` | `derived` | The deep-sleep oscillator source getter shall reject a null output pointer.
- `REQ-SYSCTL-DSCLKCFG-013` -> `GetDeepSleepOscillatorClockSourceUsesExpectedField` | `tm4c` | The deep-sleep oscillator source getter shall read the documented `DSCLKCFG.DSOSCSRC` field.
- `REQ-SYSCTL-DSCLKCFG-014` -> `GetDeepSleepOscillatorClockSourcePropagatesReadError` | `derived` | The deep-sleep oscillator source getter shall propagate read failures without modifying caller state.
- `REQ-SYSCTL-DSCLKCFG-015` -> `SetDeepSleepOscillatorClockDivisorUsesExpectedField` | `tm4c` | The deep-sleep oscillator divisor setter shall program the documented `DSCLKCFG.DSSYSDIV` field.
- `REQ-SYSCTL-DSCLKCFG-016` -> `GetDeepSleepOscillatorClockDivisorRejectsNullPointer` | `derived` | The deep-sleep oscillator divisor getter shall reject a null output pointer.
- `REQ-SYSCTL-DSCLKCFG-017` -> `GetDeepSleepOscillatorClockDivisorUsesExpectedField` | `tm4c` | The deep-sleep oscillator divisor getter shall read the documented `DSCLKCFG.DSSYSDIV` field.
- `REQ-SYSCTL-DSCLKCFG-018` -> `GetDeepSleepOscillatorClockDivisorPropagatesReadError` | `derived` | The deep-sleep oscillator divisor getter shall propagate read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_MemoryTiming_Test.cpp`
Manual basis: `tm4c`, system clock frequency change guidance requiring `MEMTIM0` updates before divisor changes p.247, System Control register map Table 5-11 p.260, and Table 5-12 `MEMTIM0` Register Configuration versus Frequency p.277.

- `REQ-SYSCTL-MEMTIM0-001` -> `SetMemoryHighTimeWritesFlashThenEEPROM` | `mixed` | The memory high-time setter shall program the documented `MEMTIM0.FLASHBCHT` and `MEMTIM0.EEPROMBCHT` fields with the same public value.
- `REQ-SYSCTL-MEMTIM0-002` -> `SetMemoryHighTimePropagatesWriteFailures` | `derived` | The memory high-time setter shall propagate primitive write failures without masking the first failing status.
- `REQ-SYSCTL-MEMTIM0-003` -> `GetMemoryFieldGettersRejectNullPointer` | `derived` | The individual BCHT, wait-state, and clock-edge getters shall reject null output pointers.
- `REQ-SYSCTL-MEMTIM0-004` -> `GetMemoryHighTimeUsesMatchingFlashAndEEPROMValues` | `mixed` | The memory high-time getter shall read the documented FLASH and EEPROM BCHT fields and return the shared value only when both fields match.
- `REQ-SYSCTL-MEMTIM0-005` -> `GetMemoryHighTimePropagatesFlashReadErrorAndRejectsMismatchedFields` | `mixed` | The memory high-time getter shall propagate FLASH-field read failures and reject mismatched FLASH versus EEPROM BCHT values.
- `REQ-SYSCTL-MEMTIM0-006` -> `SetMemoryWaitStateWritesFlashThenEEPROM` | `mixed` | The memory wait-state setter shall program the documented `MEMTIM0.FLASHWS` and `MEMTIM0.EEPROMWS` fields with the same public value.
- `REQ-SYSCTL-MEMTIM0-007` -> `GetMemoryWaitStateUsesMatchingFlashAndEEPROMValues` | `mixed` | The memory wait-state getter shall read the documented FLASH and EEPROM wait-state fields and return the shared value only when both fields match.
- `REQ-SYSCTL-MEMTIM0-008` -> `GetMemoryWaitStatePropagatesEEPROMReadError` | `derived` | The memory wait-state getter shall propagate EEPROM-field read failures without modifying caller state.
- `REQ-SYSCTL-MEMTIM0-009` -> `SetMemoryClockEdgeWritesFlashThenEEPROM` | `mixed` | The memory clock-edge setter shall program the documented `MEMTIM0.FLASHBCE` and `MEMTIM0.EEPROMBCE` fields with the same public value.
- `REQ-SYSCTL-MEMTIM0-010` -> `GetMemoryClockEdgeUsesMatchingFlashAndEEPROMValues` | `mixed` | The memory clock-edge getter shall read the documented FLASH and EEPROM BCE fields and return the shared value only when both fields match.
- `REQ-SYSCTL-MEMTIM0-011` -> `GetMemoryClockEdgeRejectsMismatchedFields` | `mixed` | The memory clock-edge getter shall reject mismatched FLASH versus EEPROM BCE values instead of returning an incoherent public state.
- `REQ-SYSCTL-MEMTIM0-012` -> `SetMemoryTimingUses16MHzEntry` | `mixed` | The composite memory-timing setter shall select the documented 16 MHz `MEMTIM0` table entry and apply the paired BCHT, wait-state, and clock-edge fields in setter order.
- `REQ-SYSCTL-MEMTIM0-013` -> `SetMemoryTimingUses120MHzEntry` | `mixed` | The composite memory-timing setter shall select the documented 120 MHz `MEMTIM0` table entry and apply the paired BCHT, wait-state, and clock-edge fields in setter order.
- `REQ-SYSCTL-MEMTIM0-014` -> `SetMemoryTimingRejectsOutOfRangeFrequencyAndStopsOnWaitStateError` | `mixed` | The composite memory-timing setter shall reject frequencies above the documented table range and stop on the first failing stage.
- `REQ-SYSCTL-MEMTIM0-015` -> `GetMemoryTimingUsesHighWaitStateClockEdgeOrderingAndStopsOnFirstError` | `derived` | The composite memory-timing getter shall read high-time, wait state, and clock edge in order and stop on the first failing stage.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_InternalOsc_Test.cpp`
Manual basis: `tm4c`, Section 5.2.5.3 Precision Internal Oscillator Operation (PIOSC) p.236, including `PIOSCCAL` calibration control and `PIOSCSTAT` result reporting context p.237.

- `REQ-SYSCTL-PIOSC-001` -> `PIOSCStatusValueGettersRejectNullPointer` | `derived` | The PIOSC calibration-result, current-trim, and default-trim getters shall reject null output pointers.
- `REQ-SYSCTL-PIOSC-002` -> `GetPIOSCCalibrationResultUsesPIOSCSTATResultField` | `tm4c` | The PIOSC calibration-result getter shall read the documented `PIOSCSTAT.RESULT` field.
- `REQ-SYSCTL-PIOSC-003` -> `GetPIOSCCalibrationResultPropagatesReadError` | `derived` | The PIOSC calibration-result getter shall propagate primitive read failures without modifying caller state.
- `REQ-SYSCTL-PIOSC-004` -> `GetPIOSCCalibrationValueAndDefaultValueUsePIOSCSTATFields` | `tm4c` | The PIOSC current-trim and default-trim getters shall read the documented `PIOSCSTAT.CT` and `PIOSCSTAT.DT` fields.
- `REQ-SYSCTL-PIOSC-005` -> `SetAndGetPIOSCUserCalibrationValueUsePIOSCCALUTField` | `tm4c` | The user-calibration setter and getter shall access the documented `PIOSCCAL.UT` field.
- `REQ-SYSCTL-PIOSC-006` -> `PIOSCUserTrimAndStatusGettersRejectNullPointer` | `derived` | The user-calibration value getter and the UTEN, UPDATE, and CAL status getters shall reject null output pointers.
- `REQ-SYSCTL-PIOSC-007` -> `UsePIOSCUserCalibrationValueUsesPIOSCCALUTENField` | `tm4c` | The user-calibration enable setter shall program the documented `PIOSCCAL.UTEN` field.
- `REQ-SYSCTL-PIOSC-008` -> `IsPIOSCUserCalibrationValueUsedUsesPIOSCCALUTENField` | `tm4c` | The user-calibration enable-status getter shall read the documented `PIOSCCAL.UTEN` field.
- `REQ-SYSCTL-PIOSC-009` -> `UpdatePIOSCCalibrationValueAndStatusUseUpdateField` | `tm4c` | The update helper and update-status getter shall access the documented `PIOSCCAL.UPDATE` field.
- `REQ-SYSCTL-PIOSC-010` -> `StartPIOSCCalibrationUsesCalField` | `tm4c` | The calibration-start helper shall program the documented `PIOSCCAL.CAL` field.
- `REQ-SYSCTL-PIOSC-011` -> `IsPIOCCalibrationOngoingUsesCalField` | `tm4c` | The calibration-status getter shall read the documented `PIOSCCAL.CAL` field.

## Update Rule

Whenever a new host test case is added:

1. add a new traceability row in the matching test-file section
2. if the source has no section yet, add a new section with manual basis and source classification
3. use direct manual chapter/register/page context when a hardware requirement exists
4. mark pointer validation, error propagation, callback, and wrapper-policy assertions as `derived` or `mixed` when the manuals do not define them directly

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

Path: `xApplication_MCU/SYSCTL/xSource/SYSCTL_Init_Test.cpp`
Manual basis: `derived`, initialization policy built around the SYSCTL controller and interrupt path described in `tm4c` Chapter 5.

- `REQ-SYSCTL-INIT-001` -> `InitPropagatesModuleValidationError` | `derived` | The SYSCTL initialization path shall propagate module-validation errors without continuing setup.
- `REQ-SYSCTL-INIT-002` -> `InitPerformsExpectedOrderedSetupWithVectorEnable` | `derived` | The SYSCTL initialization path shall perform the expected ordered handler registration and interrupt-source setup, then enable the vector when the requested interrupt mask is non-zero.
- `REQ-SYSCTL-INIT-003` -> `InitStopsWhenIRQRegistrationFails` | `derived` | The SYSCTL initialization path shall stop and propagate IRQ-registration failures before any interrupt-source configuration begins.
- `REQ-SYSCTL-INIT-004` -> `InitDisablesVectorWhenInterruptMaskIsNone` | `derived` | The SYSCTL initialization path shall disable the interrupt vector when the requested interrupt mask is `SYSCTL_enINTMASK_NONE` after completing the ordered source-setup sequence.
- `REQ-SYSCTL-INIT-005` -> `InitPropagatesVectorEnableFailure` | `derived` | The SYSCTL initialization path shall propagate interrupt-vector enable failures after completing the ordered source-setup sequence for a non-zero requested mask.
- `REQ-SYSCTL-INIT-006` -> `InitPropagatesVectorDisableFailure` | `derived` | The SYSCTL initialization path shall propagate interrupt-vector disable failures on the `SYSCTL_enINTMASK_NONE` branch after completing the ordered source-setup sequence.
- `REQ-SYSCTL-INIT-007` -> `InitStopsWhenClearAllSourcesFails` | `derived` | The SYSCTL initialization path shall stop on the first clear-source failure and avoid later source-enable or vector-selection steps.

Path: `xDriver_MCU/SYSCTL/App/xSource/SYSCTL_Ready_Test.cpp`
Manual basis: `derived`, repository SYSCTL app-layer ready sequencing and error-propagation policy above the Chapter 5 run-mode and reset helpers.

- `REQ-SYSCTL-READY-001` -> `SetReadyOnRunModePropagatesReadyQueryError` | `derived` | The SYSCTL ready-on-run helper shall propagate the peripheral-ready query error without attempting later run-mode or reset operations.
- `REQ-SYSCTL-READY-002` -> `SetReadyOnRunModeEnablesRunModeThenResets` | `derived` | The SYSCTL ready-on-run helper shall enable run mode and then assert peripheral reset when the selected peripheral is not yet ready.
- `REQ-SYSCTL-READY-003` -> `ClearReadyOnRunModeResetsThenDisablesRunMode` | `derived` | The SYSCTL clear-ready-on-run helper shall assert peripheral reset and then disable run mode when the selected peripheral is currently ready.
- `REQ-SYSCTL-READY-004` -> `ResetPropagatesPeripheralResetError` | `derived` | The SYSCTL app-layer reset helper shall propagate the underlying peripheral-reset write error when reset assertion fails for a ready peripheral.
- `REQ-SYSCTL-READY-005` -> `IsReadyDelegatesToPeripheralReady` | `derived` | The SYSCTL app-layer ready wrapper shall forward its arguments to the peripheral-ready query and return the resulting status unchanged.

Path: `xDriver_MCU/SYSCTL/App/xSource/SYSCTL_DeInitClockGates_Test.cpp`
Manual basis: `derived`, repository SYSCTL clock-gate deinitialization policy built on the app-layer ready-clear helper.

- `REQ-SYSCTL-DEINIT-001` -> `DeInitClockGatesIteratesAllPeripheralsInOrder` | `derived` | The SYSCTL clock-gate deinitialization helper shall visit the current peripheral inventory in source order and delegate each entry through the ready-clear helper.
- `REQ-SYSCTL-DEINIT-002` -> `DeInitClockGatesStopsOnFirstError` | `derived` | The SYSCTL clock-gate deinitialization helper shall stop at the first ready-clear failure and return that error without attempting later peripherals.

Path: `xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/xSource/SYSCTL_InterruptRoutine_Test.cpp`
Manual basis: `derived`, repository SYSCTL vector-handler storage policy for the application interrupt wrapper.

- `REQ-SYSCTL-IRQROUT-001` -> `IRQVectorHandlerGetterReturnsInstalledHandler` | `derived` | The SYSCTL IRQ routine getter shall return the currently installed SYSCTL IRQ vector handler.
- `REQ-SYSCTL-IRQROUT-002` -> `IRQVectorHandlerPointerExposesWritableInstalledHandlerStorage` | `derived` | The SYSCTL IRQ routine pointer getter shall expose the writable installed-handler storage used by the SYSCTL IRQ registration layer.

Path: `xApplication_MCU/SYSCTL/Interrupt/InterruptRoutine/xSource/SYSCTL_InterruptRoutine_Vector_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, `MISC` p.279 and SYSCTL register-map context Table 5-11 p.260.

- `REQ-SYSCTL-VECTOR-001` -> `IRQVectorHandlerDispatchesSoftwareCallbackWhenNoBitsAreSet` | `derived` | The SYSCTL application interrupt routine shall dispatch the software-source callback when no architected `MISC` source bit is asserted.
- `REQ-SYSCTL-VECTOR-002` -> `IRQVectorHandlerClearsAndDispatchesEachAssertedSource` | `mixed` | The SYSCTL application interrupt routine shall clear each asserted `MISC` source and dispatch the corresponding callback in source order for the active BOR, MOSC failure, PLL lock, and MOSC power-up bits.

Path: `xApplication_MCU/SYSCTL/Interrupt/InterruptRegister/xSource/SYSCTL_InterruptRegisterIRQVector_Test.cpp`
Manual basis: `derived`, repository SCB registration policy for the fixed SYSCTL interrupt vector.

- `REQ-SYSCTL-IRQREG-001` -> `RegisterIRQVectorHandlerDelegatesFixedSYSCTLVectorToSCB` | `derived` | The SYSCTL IRQ-register wrapper shall delegate non-null handler registration through SCB using the fixed SYSCTL vector selector and the SYSCTL installed-handler storage pointer.
- `REQ-SYSCTL-IRQREG-002` -> `RegisterIRQVectorHandlerSkipsNullHandler` | `derived` | The SYSCTL IRQ-register wrapper shall skip SCB registration when the caller supplies a null handler pointer.
- `REQ-SYSCTL-IRQREG-003` -> `RegisterIRQVectorHandlerPropagatesSCBError` | `derived` | The SYSCTL IRQ-register wrapper shall propagate the SCB registration error status for the fixed SYSCTL vector.

Path: `xApplication_MCU/SYSCTL/Interrupt/xSource/SYSCTL_InterruptVector_Test.cpp`
Manual basis: `derived`, repository SYSCTL-to-NVIC wrapper policy for the fixed SYSCTL interrupt vector.

- `REQ-SYSCTL-IRQVEC-001` -> `EnInterruptVectorMasksPriorityAndUsesSYSCTLVector` | `derived` | The SYSCTL interrupt-vector enable wrapper shall mask the public priority to three bits, delegate to the fixed SYSCTL NVIC vector, and return the resulting status.
- `REQ-SYSCTL-IRQVEC-002` -> `EnableInterruptVectorPropagatesNVICError` | `derived` | The SYSCTL interrupt-vector enable wrapper shall propagate the NVIC enable-vector error status.
- `REQ-SYSCTL-IRQVEC-003` -> `DisInterruptVectorUsesSYSCTLVector` | `derived` | The SYSCTL interrupt-vector disable wrapper shall delegate to the fixed SYSCTL NVIC vector and return the resulting status.
- `REQ-SYSCTL-IRQVEC-004` -> `DisableInterruptVectorPropagatesNVICError` | `derived` | The SYSCTL interrupt-vector disable wrapper shall propagate the NVIC disable-vector error status.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_DeviceID_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.2.1 Device Identification, `DID0` p.268 and `DID1` p.270.

- `REQ-SYSCTL-DID-001` -> `GetDID0MinorRevisionRejectsNullPointer` | `derived` | The SYSCTL DID getter family shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-DID-002` -> `GettersUseExpectedDIDOffsetsMasksAndShifts` | `tm4c` | The SYSCTL DID getter family shall read the documented DID0 and DID1 fields using the corresponding register offsets, masks, and shifts, and return the decoded field value.
- `REQ-SYSCTL-DID-003` -> `GetDID1VersionPropagatesReadError` | `derived` | The SYSCTL DID getter family shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_NonVolatileMemoryInfo_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.5 System Control Register Descriptions, `NVMSTAT` p.312.

- `REQ-SYSCTL-NVMSTAT-001` -> `IsFlashWriteBufferAvailableRejectsNullPointer` | `derived` | The SYSCTL NVMSTAT getter shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-NVMSTAT-002` -> `IsFlashWriteBufferAvailableUsesExpectedOffsetMaskAndShift` | `tm4c` | The SYSCTL NVMSTAT getter shall read the documented `NVMSTAT.FWB` field using the corresponding register offset, mask, and shift, and return the flash-write-buffer availability state as a boolean value.
- `REQ-SYSCTL-NVMSTAT-003` -> `IsFlashWriteBufferAvailablePropagatesReadError` | `derived` | The SYSCTL NVMSTAT getter shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_BootConfig_Test.cpp`
Manual basis: `tm4c`, Chapter 8 Internal Memory, section 8.6 Memory Register Descriptions (System Control Offset), `BOOTCFG` pp.706-709.

- `REQ-SYSCTL-BOOTCFG-001` -> `GetBootConfigDebug0RejectsNullPointer` | `derived` | The SYSCTL BOOTCFG state getter family shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-BOOTCFG-002` -> `GetBootConfigGPIOPinRejectsNullPointer` | `derived` | The SYSCTL BOOTCFG numeric getter family shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-BOOTCFG-003` -> `StateGettersUseExpectedBOOTCFGMasksAndShifts` | `tm4c` | The SYSCTL BOOTCFG one-bit field getters shall read the documented BOOTCFG fields using the corresponding register offset, masks, and shifts, and return each raw field state as a boolean value.
- `REQ-SYSCTL-BOOTCFG-004` -> `ValueGettersUseExpectedBOOTCFGMasksAndShifts` | `tm4c` | The SYSCTL BOOTCFG multi-bit field getters shall read the documented BOOTCFG fields using the corresponding register offset, masks, and shifts, and return each decoded numeric field value unchanged.
- `REQ-SYSCTL-BOOTCFG-005` -> `GetBootConfigNotWrittenPropagatesReadError` | `derived` | The SYSCTL BOOTCFG state getter family shall propagate SYSCTL primitive read errors without modifying the caller output value.
- `REQ-SYSCTL-BOOTCFG-006` -> `GetBootConfigGPIOPortPropagatesReadError` | `derived` | The SYSCTL BOOTCFG numeric getter family shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_UserRegisters_Test.cpp`
Manual basis: `tm4c`, Chapter 8 Internal Memory, section 8.6 Memory Register Descriptions (System Control Offset), `USER_REG0` through `USER_REG3` p.710, with section 8.2.3.12 Non-Volatile Register Programming for staged readback semantics.

- `REQ-SYSCTL-USERREG-001` -> `GetUserRegister0RejectsNullPointer` | `derived` | The SYSCTL USER_REG getter family shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-USERREG-002` -> `GettersUseExpectedUserRegisterOffsetsMasksAndShifts` | `tm4c` | The SYSCTL USER_REG getter family shall read the documented USER_REG0 through USER_REG3 fields using the corresponding register offsets, masks, and shifts, and return each 32-bit register value unchanged.
- `REQ-SYSCTL-USERREG-003` -> `GetUserRegister2PropagatesReadError` | `derived` | The SYSCTL USER_REG getter family shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_ResetVectorPointer_Test.cpp`
Manual basis: `tm4c`, Chapter 8 Internal Memory, section 8.6 Memory Register Descriptions (System Control Offset), `RVP` p.701.

- `REQ-SYSCTL-RVP-001` -> `GetResetVectorPointerRejectsNullPointer` | `derived` | The SYSCTL reset-vector-pointer getter shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-RVP-002` -> `GetResetVectorPointerUsesExpectedOffsetMaskAndShift` | `tm4c` | The SYSCTL reset-vector-pointer getter shall read the documented `RVP.RV` field using the corresponding register offset, mask, and shift, and return the raw reset-vector address unchanged.
- `REQ-SYSCTL-RVP-003` -> `GetResetVectorPointerPropagatesReadError` | `derived` | The SYSCTL reset-vector-pointer getter shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_SystemProperties_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.5 System Control Register Descriptions, `SYSPROP` p.299, with section 5.2.6.4 Dynamic Power Management p.254 for capability semantics.

- `REQ-SYSCTL-SYSPROP-001` -> `IsFPUPresentRejectsNullPointer` | `derived` | The SYSCTL system-properties getter family shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-SYSPROP-002` -> `GettersUseExpectedSYSPROPMasksAndShifts` | `tm4c` | The SYSCTL system-properties getter family shall read the documented `SYSPROP` capability bits using the corresponding register offset, masks, and shifts, and return each support state as a boolean value.
- `REQ-SYSCTL-SYSPROP-003` -> `IsLDOSleepModeSupportedPropagatesReadError` | `derived` | The SYSCTL system-properties getter family shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_UniqueID_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.5 System Control Register Descriptions, `UNIQUEID0` through `UNIQUEID3` p.554.

- `REQ-SYSCTL-UNIQUEID-001` -> `GetUniqueID0RejectsNullPointer` | `derived` | The SYSCTL Unique ID getter family shall reject a null destination pointer before issuing the register read.
- `REQ-SYSCTL-UNIQUEID-002` -> `GettersUseExpectedUniqueIDOffsetsMasksAndShifts` | `tm4c` | The SYSCTL Unique ID getter family shall read the documented `UNIQUEID0` through `UNIQUEID3` raw identifier fields using the corresponding register offsets, masks, and shifts, and return each 32-bit identifier slice unchanged.
- `REQ-SYSCTL-UNIQUEID-003` -> `GetUniqueID2PropagatesReadError` | `derived` | The SYSCTL Unique ID getter family shall propagate SYSCTL primitive read errors without modifying the caller output value.

Path: `xDriver_MCU/SYSCTL/Peripheral/Register/xSource/SYSCTL_PowerModeRegisters_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.5 System Control Register Descriptions, `SLPPWRCFG` pp.308-309, `DSLPPWRCFG` pp.309-311, `SDPMST` pp.319-321, and `RESBEHAVCTL` pp.321-323 for the adjacent typed raw register macro.

- `REQ-SYSCTL-PWRREG-001` -> `SleepPowerConfigurationUsesDocumentedOffsetShiftAndBitbandAliases` | `tm4c` | The raw `SLPPWRCFG` surface shall expose the documented offset, `FLASHPM` mask plus shift, and bit-band alias routing for bits 5:4.
- `REQ-SYSCTL-PWRREG-002` -> `DeepSleepPowerConfigurationUsesDocumentedOffsetsAndWritableBitAliases` | `tm4c` | The raw `DSLPPWRCFG` surface shall expose the documented `FLASHPM`, `TSPD`, and `LDOSM` field positions and writable bit-band aliases for the programmable deep-sleep bits.
- `REQ-SYSCTL-PWRREG-003` -> `StatusAndResetTypedPointerMacrosUseDocumentedOffsets` | `tm4c` | The raw `SDPMST` surface shall expose the documented status-bit positions while the adjacent `RESBEHAVCTL` typed pointer macros shall route to the documented offset with writable raw-register access semantics.

Path: `xDriver_MCU/SYSCTL/Peripheral/Register/xSource/SYSCTL_ModulePowerRegisters_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.5 System Control Register Descriptions, `USBPDS` p.325, `USBMPC` p.326, `EMACPDS` p.327, `EMACMPC` p.328, `CAN0PDS` p.331, `CAN0MPC` p.332, `CAN1PDS` p.333, and `CAN1MPC` p.334.

- `REQ-SYSCTL-MODPWR-001` -> `UsbModulePowerRegistersUseDocumentedOffsetsValuesAndMutability` | `tm4c` | The raw `USBPDS` and `USBMPC` surfaces shall expose the documented offsets, field encodings, typed raw access mutability, and bit-band alias routing for the USB SRAM power block.
- `REQ-SYSCTL-MODPWR-002` -> `EmacModulePowerRegistersUseDocumentedOffsetsValuesAndMutability` | `tm4c` | The raw `EMACPDS` and `EMACMPC` surfaces shall expose the documented offsets, field encodings, typed raw access mutability, and bit-band alias routing for the EMAC SRAM power block.
- `REQ-SYSCTL-MODPWR-003` -> `CanModulePowerRegistersUseDocumentedOffsetsValuesAndMutability` | `tm4c` | The raw `CAN0PDS/CAN0MPC` and `CAN1PDS/CAN1MPC` surfaces shall expose the documented offsets, field encodings, typed raw access mutability, and bit-band alias routing for both CAN SRAM power blocks.

Path: `xDriver_MCU/SYSCTL/Peripheral/Register/xSource/SYSCTL_NonVolatileRegisters_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control, section 5.5 System Control Register Descriptions, `NVMSTAT` p.312, plus Chapter 8 Internal Memory, section 8.6 Memory Register Descriptions (System Control Offset), `BOOTCFG` pp.706-709 and `USER_REG0` through `USER_REG3` p.710.

- `REQ-SYSCTL-NVREG-001` -> `NvmStatusRawSurfaceUsesDocumentedOffsetAndReadOnlyAliases` | `tm4c` | The raw `NVMSTAT` surface shall expose the documented offset, `FWB` bit position, read-only typed raw access, and read-only bit-band alias routing for the flash-write-buffer status bit.
- `REQ-SYSCTL-NVREG-002` -> `BootConfigRawSurfaceUsesDocumentedOffsetsMasksAndBitAliases` | `tm4c` | The raw `BOOTCFG` surface shall expose the documented offset, one-bit and multi-bit field locations plus encodings, writable typed raw access, and bit-band alias routing for the individually addressable control bits.
- `REQ-SYSCTL-NVREG-003` -> `UserRegistersRawSurfaceUsesDocumentedOffsetsMasksAndBitbandBases` | `tm4c` | The raw `USER_REG0` through `USER_REG3` surface shall expose the documented staged offsets, full-width data mask, writable typed raw access, and bit-band word-alias base routing for the four user-register slots.

Path: `xApplication_MCU/TIMER/xSource/TIMER_Init_Test.cpp`
Manual basis: `derived`, repository TIMER initialization policy for application IRQ-vector registration.

- `REQ-TIMER-INIT-001` -> `InitRegistersAllTimerVectorsInOrder` | `derived` | The TIMER initialization path shall obtain and register the application IRQ vector handler for each TIMER0A through TIMER7B slot in order.
- `REQ-TIMER-INIT-002` -> `InitStopsWhenRegistrationFails` | `derived` | The TIMER initialization path shall stop and propagate the first IRQ-registration failure without attempting later TIMER slots.

Path: `xApplication_MCU/TIMER/Interrupt/InterruptRegister/xSource/TIMER_InterruptRegisterIRQVector_Test.cpp`
Manual basis: `derived`, repository SCB registration policy for mapped TIMER interrupt vectors.

- `REQ-TIMER-IRQREG-001` -> `RegisterIRQVectorHandlerDelegatesMappedTimerVectorToSCB` | `derived` | The TIMER IRQ-register wrapper shall map the caller module to the corresponding SCB timer vector, use the installed-handler storage pointer for that slot, and return the SCB registration status.
- `REQ-TIMER-IRQREG-002` -> `RegisterIRQVectorHandlerPropagatesSCBError` | `derived` | The TIMER IRQ-register wrapper shall propagate the SCB registration error for the selected mapped timer vector.
- `REQ-TIMER-IRQREG-003` -> `RegisterIRQVectorHandlerSkipsNullHandler` | `derived` | The TIMER IRQ-register wrapper shall skip SCB registration when the caller supplies a null handler pointer.

Path: `xApplication_MCU/TIMER/Interrupt/xSource/TIMER_InterruptVector_Test.cpp`
Manual basis: `derived`, repository TIMER-to-NVIC wrapper policy for mapped timer vectors.

- `REQ-TIMER-IRQVEC-001` -> `EnableInterruptVectorMapsWideTimerToTimerAVector` | `derived` | The TIMER interrupt-vector enable wrapper shall map wide-timer modules to the corresponding A-side NVIC vector and return the delegated status.
- `REQ-TIMER-IRQVEC-002` -> `EnableInterruptVectorPropagatesNVICError` | `derived` | The TIMER interrupt-vector enable wrapper shall propagate the NVIC enable-vector error status for the selected mapped timer vector.
- `REQ-TIMER-IRQVEC-003` -> `DisableInterruptVectorUsesMappedTimerVector` | `derived` | The TIMER interrupt-vector disable wrapper shall route the caller module to the mapped TIMER NVIC vector and return the delegated status.
- `REQ-TIMER-IRQVEC-004` -> `DisableInterruptVectorPropagatesNVICError` | `derived` | The TIMER interrupt-vector disable wrapper shall propagate the NVIC disable-vector error status for the selected mapped timer vector.

Path: `xApplication_MCU/ACMP/xSource/ACMP_Init_Test.cpp`
Manual basis: `derived`, repository ACMP initialization policy for application IRQ-vector registration.

- `REQ-ACMP-INIT-001` -> `InitPropagatesReadyError` | `derived` | The ACMP initialization path shall propagate ready-state setup errors without attempting comparator IRQ-handler lookup or registration.
- `REQ-ACMP-INIT-002` -> `InitRegistersAllComparatorsInOrder` | `derived` | The ACMP initialization path shall obtain and register the application IRQ vector handler for comparators 0 through 2 in order after ready-state setup succeeds.
- `REQ-ACMP-INIT-003` -> `InitStopsWhenComparatorRegistrationFails` | `derived` | The ACMP initialization path shall stop and propagate the first comparator IRQ-registration failure without attempting later comparator registrations.

Path: `xDriver_MCU/ACMP/Driver/Intrinsics/Primitives/xSource/ACMP_RegisterPrimitives_Test.cpp`
Manual basis: `derived`, repository ACMP primitive register-wrapper policy around the documented ACMP block base.

- `REQ-ACMP-PRIM-001` -> `ReadRegisterRejectsNullPointer` | `derived` | The ACMP read primitive shall reject a null register descriptor.
- `REQ-ACMP-PRIM-002` -> `ReadRegisterAddsBlockBaseBeforeMCUAccess` | `derived` | The ACMP read primitive shall validate the module and add the ACMP block base address before MCU register access.
- `REQ-ACMP-PRIM-003` -> `WriteRegisterAddsBlockBaseBeforeMCUAccess` | `derived` | The ACMP write primitive shall validate the module and add the ACMP block base address before MCU register access.
- `REQ-ACMP-PRIM-004` -> `WriteRegisterPropagatesModuleValidationError` | `derived` | The ACMP write primitive shall propagate module-validation failures without attempting a register write.

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

Path: `xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/xSource/SYSCTL_InterruptSource_Test.cpp`
Manual basis: `tm4c`, System Control Register 4 `RIS`, Register 5 `IMC`, and Register 6 `MISC` around pp.277-279.

- `REQ-SYSCTL-INTSRC-001` -> `EnableAndDisableInterruptSourceByNumberUseSingleBitIMCField` | `mixed` | The by-number interrupt enable and disable helpers shall map the selected SYSCTL source to the documented `IMC` bit position and use a single-bit logical field through the primitive seam.
- `REQ-SYSCTL-INTSRC-002` -> `SetAndGetInterruptSourceStateByMaskUseWholeIMCField` | `tm4c` | The by-mask interrupt-state helpers shall access the documented `IMC` mask bits selected by the caller.
- `REQ-SYSCTL-INTSRC-003` -> `GetInterruptSourceStateByNumberUsesSingleBitIMCField` | `mixed` | The by-number interrupt-state getter shall read the selected `IMC` source bit as a single-bit logical field and return the decoded public state.
- `REQ-SYSCTL-INTSRC-004` -> `InterruptSourceGettersRejectNullPointers` | `derived` | The SYSCTL interrupt getter family shall reject null output pointers before touching the register block.
- `REQ-SYSCTL-INTSRC-005` -> `ClearInterruptSourceWrappersUseMISCRegister` | `tm4c` | The SYSCTL interrupt clear helpers shall write the requested raw source bits through the documented `MISC` RW1C path.
- `REQ-SYSCTL-INTSRC-006` -> `StatusInterruptSourceWrappersReadRISRegister` | `tm4c` | The SYSCTL raw-status helpers shall read the documented `RIS` register family for by-mask and by-number queries.
- `REQ-SYSCTL-INTSRC-007` -> `StatusMaskedInterruptSourceWrappersReadMISCRegister` | `tm4c` | The SYSCTL masked-status helpers shall read the documented `MISC` register family for by-mask and by-number queries.
- `REQ-SYSCTL-INTSRC-008` -> `InterruptSourceHelpersPropagateValidationAndPrimitiveErrors` | `derived` | Invalid SYSCTL interrupt selections shall stop at parameter validation and valid helpers shall propagate primitive read and write failures unchanged.

Path: `xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/SYSCTL_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned SYSCTL source-handler table used by the chapter interrupt dispatch path.

- `REQ-SYSCTL-INTROUTSRC-001` -> `AllInterruptSourcesDefaultToDummyHandler` | `derived` | The internal SYSCTL source-handler table shall initialize every defined SYSCTL source slot to the shared dummy source handler.
- `REQ-SYSCTL-INTROUTSRC-002` -> `InterruptSourceHandlerPointerExposesWritableSourceSlot` | `derived` | The internal SYSCTL source-handler pointer helper shall expose writable per-source storage and the getter shall reflect updates to that storage.
- `REQ-SYSCTL-INTROUTSRC-003` -> `InterruptSourceGetterRejectsInvalidSelections` | `derived` | The internal SYSCTL source-handler getter shall return a null handler for module or source selections outside `SYSCTL_enMODULE_MAX` and `SYSCTL_enINT_MAX`.
- `REQ-SYSCTL-INTROUTSRC-004` -> `InterruptSourceHandlerPointerRejectsInvalidSelections` | `derived` | The internal SYSCTL source-handler pointer helper shall return a null storage pointer for module or source selections outside `SYSCTL_enMODULE_MAX` and `SYSCTL_enINT_MAX`.

Path: `xDriver_MCU/SYSCTL/Driver/Intrinsics/Interrupt/InterruptRegister/xSource/SYSCTL_InterruptRegisterIRQSource_Test.cpp`
Manual basis: `derived`, software-owned SYSCTL source-handler registration helper.

- `REQ-SYSCTL-INTREGSRC-001` -> `RegisterIRQSourceRejectsInvalidModule` | `derived` | The internal SYSCTL source-handler registration helper shall reject module selections outside `SYSCTL_enMODULE_MAX`.
- `REQ-SYSCTL-INTREGSRC-002` -> `RegisterIRQSourceRejectsInvalidInterruptSource` | `derived` | The internal SYSCTL source-handler registration helper shall reject source selections outside `SYSCTL_enINT_MAX`.
- `REQ-SYSCTL-INTREGSRC-003` -> `RegisterIRQSourceRejectsNullHandlerPointerWithoutClobberingExistingSlot` | `derived` | The internal SYSCTL source-handler registration helper shall propagate null-handler rejection from the MCU registration primitive without modifying the selected slot.
- `REQ-SYSCTL-INTREGSRC-004` -> `RegisterIRQSourceStoresEncodedHandlerInSelectedSlotOnly` | `derived` | The internal SYSCTL source-handler registration helper shall write the encoded handler pointer into only the selected source slot.

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

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PLLCLock_Test.cpp`
Manual basis: `tm4c`, Section 6.2.5.5 PLL pp.236-238, system-clock initialization sequence p.246, and `PLLFREQ0`, `PLLFREQ1`, and `PLLSTAT` register context.

- `REQ-SYSCTL-PLL-001` -> `SetPLLClockStateUsesExpectedField` | `mixed` | The PLL state setter shall program the documented `PLLFREQ0.PLLPWR` field using the public enabled and disabled state encodings.
- `REQ-SYSCTL-PLL-002` -> `PLLStateAndValueGettersRejectNullPointer` | `derived` | The PLL state, divider-value, and lock-status getters shall reject null output pointers.
- `REQ-SYSCTL-PLL-003` -> `GetPLLClockStateUsesExpectedField` | `mixed` | The PLL state getter shall read the documented `PLLFREQ0.PLLPWR` field and return the decoded public state.
- `REQ-SYSCTL-PLL-004` -> `SetAndGetPLLClockIntegerValueMUseExpectedField` | `tm4c` | The MINT setter and getter shall access the documented `PLLFREQ0.MINT` field.
- `REQ-SYSCTL-PLL-005` -> `SetAndGetPLLClockFractionalValueMUseExpectedField` | `tm4c` | The MFRAC setter and getter shall access the documented `PLLFREQ0.MFRAC` field.
- `REQ-SYSCTL-PLL-006` -> `SetAndGetPLLClockValueQUseExpectedField` | `tm4c` | The Q-divider setter and getter shall access the documented `PLLFREQ1.Q` field.
- `REQ-SYSCTL-PLL-007` -> `SetAndGetPLLClockValueNUseExpectedField` | `tm4c` | The N-divider setter and getter shall access the documented `PLLFREQ1.N` field.
- `REQ-SYSCTL-PLL-008` -> `IsPLLClockLockedUsesExpectedField` | `tm4c` | The PLL lock-status getter shall read the documented `PLLSTAT.LOCK` field.
- `REQ-SYSCTL-PLL-009` -> `PLLStateAndValueGettersPropagateReadErrors` | `derived` | The PLL state, divider-value, and lock-status getters shall propagate primitive read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_MainOsc_Test.cpp`
Manual basis: `tm4c`, Section 6.2.5.4 Main Oscillator (MOSC) p.236, main-oscillator verification and failure behavior p.236, initialization sequence pp.246-247, and `MOSCCTL` register context.

- `REQ-SYSCTL-MOSCCTL-001` -> `SetMOSCMonitorStateUsesExpectedField` | `tm4c` | The MOSC monitor setter shall program the documented `MOSCCTL.CVAL` field.
- `REQ-SYSCTL-MOSCCTL-002` -> `SetMOSCFailureActionUsesExpectedField` | `tm4c` | The MOSC failure-action setter shall program the documented `MOSCCTL.MOSCIM` field.
- `REQ-SYSCTL-MOSCCTL-003` -> `SetMOSCStateMapsPublicStateToNOXTALField` | `mixed` | The MOSC state setter shall translate the public enabled and disabled states into the documented `MOSCCTL.NOXTAL` field encodings.
- `REQ-SYSCTL-MOSCCTL-004` -> `SetMOSCPowerStateMapsPublicStateToPWRDNField` | `mixed` | The MOSC power-state setter shall translate the public enabled and disabled states into the documented `MOSCCTL.PWRDN` field encodings.
- `REQ-SYSCTL-MOSCCTL-005` -> `SetMOSCFrequencyRangeUsesExpectedField` | `tm4c` | The MOSC frequency-range setter shall program the documented `MOSCCTL.OSCRNG` field.
- `REQ-SYSCTL-MOSCCTL-006` -> `MOSCGettersRejectNullPointer` | `derived` | The MOSC monitor, failure-action, state, power-state, and frequency-range getters shall reject null output pointers.
- `REQ-SYSCTL-MOSCCTL-007` -> `GetMOSCMonitorStateUsesExpectedField` | `tm4c` | The MOSC monitor getter shall read the documented `MOSCCTL.CVAL` field.
- `REQ-SYSCTL-MOSCCTL-008` -> `GetMOSCFailureActionUsesExpectedField` | `tm4c` | The MOSC failure-action getter shall read the documented `MOSCCTL.MOSCIM` field.
- `REQ-SYSCTL-MOSCCTL-009` -> `GetMOSCStateMapsNOXTALFieldToPublicState` | `mixed` | The MOSC state getter shall translate the documented `MOSCCTL.NOXTAL` encodings into public enabled and disabled states.
- `REQ-SYSCTL-MOSCCTL-010` -> `GetMOSCPowerStateMapsPWRDNFieldToPublicState` | `mixed` | The MOSC power-state getter shall translate the documented `MOSCCTL.PWRDN` encodings into public enabled and disabled states.
- `REQ-SYSCTL-MOSCCTL-011` -> `GetMOSCFrequencyRangeUsesExpectedField` | `tm4c` | The MOSC frequency-range getter shall read the documented `MOSCCTL.OSCRNG` field.
- `REQ-SYSCTL-MOSCCTL-012` -> `MOSCGettersPropagateReadError` | `derived` | The MOSC monitor, failure-action, state, power-state, and frequency-range getters shall propagate primitive read failures without modifying caller state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_SystemClock_Test.cpp`
Manual basis: `tm4c`, Section 6.2.5.5 PLL pp.237-238, including the documented PIOSC and MOSC PLL reference selection through `RSCLKCFG.PLLSRC`, the VCO calculation using `PLLFREQ0` and `PLLFREQ1`, and the PLL output divisor in `RSCLKCFG.PLLSYSDIV`.

- `REQ-SYSCTL-SYSCLK-001` -> `GetVCOAndPLLClockFrequencyRejectNullPointer` | `derived` | The VCO and PLL clock frequency getters shall reject null output pointers.
- `REQ-SYSCTL-SYSCLK-002` -> `GetVCOClockFrequencyUsesPIOSCReferenceWithoutMOSCDependency` | `mixed` | When `RSCLKCFG.PLLSRC` selects PIOSC, the VCO frequency helper shall use the documented PIOSC reference path independently of MOSC state and apply the programmed `PLLFREQ0.MINT`, `PLLFREQ0.MFRAC`, `PLLFREQ1.N`, and `PLLFREQ1.Q` values.
- `REQ-SYSCTL-SYSCLK-003` -> `GetPLLClockFrequencyUsesDerivedVCOAndPllDivisor` | `mixed` | The PLL clock frequency helper shall divide the derived VCO frequency by the documented `RSCLKCFG.PLLSYSDIV + 1` factor.
- `REQ-SYSCTL-SYSCLK-004` -> `GetVCOClockFrequencyUsesMOSCReferenceOnlyWhenMOSCAvailable` | `mixed` | When `RSCLKCFG.PLLSRC` selects MOSC, the VCO frequency helper shall only use the nominal MOSC reference when the crystal is connected and the MOSC power state is enabled.
- `REQ-SYSCTL-SYSCLK-005` -> `GetOscillatorFrequencyReturnsZeroWhenMOSCIsUnavailable` | `derived` | When the oscillator clock source selects MOSC but MOSC is unavailable, the oscillator frequency helper shall return `0` rather than the nominal MOSC frequency.
- `REQ-SYSCTL-SYSCLK-006` -> `GetOutputClockFrequencyReturnsZeroWhenMOSCIsUnavailable` | `derived` | When the output clock source selects MOSC but MOSC is unavailable, the output clock frequency helper shall return `0` rather than the nominal MOSC frequency.
- `REQ-SYSCTL-SYSCLK-007` -> `SetSystemClockRejectsInvalidValueAndNullConfig` | `derived` | The composite system-clock setter shall reject zero or out-of-range requested clock values and reject a null configuration pointer before starting clock reconfiguration.
- `REQ-SYSCTL-SYSCLK-008` -> `SetSystemClockPLLReentryIgnoresPreviousDivisorState` | `mixed` | On re-entry after a prior PLL configuration, the PLL system-clock path shall derive the new `RSCLKCFG.PLLSYSDIV` value from the configured VCO frequency and shall not depend on the stale previously programmed divider state.
- `REQ-SYSCTL-SYSCLK-009` -> `SetSystemClockTimesOutWhileWaitingForMOSCPowerUpStatus` | `mixed` | For MOSC-based system-clock requests, the composite setter shall monitor the documented MOSC power-up interrupt status and return a timeout when the source never becomes ready within the caller-provided limit.
- `REQ-SYSCTL-SYSCLK-010` -> `SetSystemClockPLLRefreshesValuesWhenAlreadyEnabled` | `mixed` | When the PLL is already enabled, the PLL system-clock path shall latch the newly programmed PLL parameters through the documented `RSCLKCFG.NEW_PLLFREQ` update path rather than re-enabling PLL power.
- `REQ-SYSCTL-SYSCLK-011` -> `SetSystemClockTimesOutWhileWaitingForPLLLock` | `mixed` | For PLL-based system-clock requests, the composite setter shall return a timeout when `PLLSTAT.LOCK` never asserts within the caller-provided limit after PLL configuration.
- `REQ-SYSCTL-SYSCLK-012` -> `GetStaticClockHelpersReturnExpectedNominalValuesAndRejectNullPointers` | `mixed` | The direct PIOSC, board MOSC, and LFIOSC nominal-frequency helpers shall reject null output pointers and return the expected fixed reference frequencies used by the SystemClock module.
- `REQ-SYSCTL-SYSCLK-013` -> `GetAlternateClockFrequencyRejectsNullPointer` | `derived` | The alternate clock frequency helper shall reject a null output pointer.
- `REQ-SYSCTL-SYSCLK-014` -> `GetAlternateClockFrequencyUsesAllDocumentedSourcesAndRejectsInvalidSource` | `mixed` | The alternate clock frequency helper shall return the documented PIOSC, RTCOSC, or LFIOSC frequency for the programmed `ALTCLKCFG.ALTCLK` source and reject unsupported source values.
- `REQ-SYSCTL-SYSCLK-015` -> `GetOscillatorFrequencyRejectsNullPointer` | `derived` | The oscillator frequency helper shall reject a null output pointer.
- `REQ-SYSCTL-SYSCLK-016` -> `GetOscillatorFrequencyUsesNonMOSCSourcesAndRejectsInvalidSource` | `mixed` | The oscillator frequency helper shall apply the programmed `RSCLKCFG.OSYSDIV + 1` divisor to the selected PIOSC, RTCOSC, or LFIOSC source and reject unsupported oscillator source values.
- `REQ-SYSCTL-SYSCLK-017` -> `GetSystemClockFrequencyRejectsNullPointerAndDelegatesBySource` | `mixed` | The system clock frequency helper shall reject a null output pointer and delegate to the oscillator or PLL frequency path according to the programmed `RSCLKCFG.USEPLL` selection.
- `REQ-SYSCTL-SYSCLK-018` -> `GetOutputClockFrequencyRejectsNullPointerAndDelegatesBySelectedSource` | `mixed` | The output clock frequency helper shall reject a null output pointer, apply the programmed `DIVSCLK.DIV + 1` divisor to the selected PIOSC or SYSCLK source, and reject unsupported output source values.
- `REQ-SYSCTL-SYSCLK-019` -> `SetSystemClockRejectsUnsupportedPLLSourceAndInvalidMOSCCrystal` | `derived` | The composite system-clock setter shall reject unsupported PLL source selections and reject MOSC configurations whose crystal selection falls outside the accepted range.
- `REQ-SYSCTL-SYSCLK-020` -> `SetSystemClockUsesOSCCLKPIOSCPathAndDisablesPLL` | `mixed` | For PIOSC-driven OSCCLK requests, the composite setter shall complete the safe staging sequence, program the final oscillator divisor, disable the PLL path, and select OSCCLK as the final system source.
- `REQ-SYSCTL-SYSCLK-021` -> `SetSystemClockUsesOSCCLKMOSCPathAfterSuccessfulPowerUp` | `mixed` | For the 25 MHz EK-TM4C129EXL MOSC path, the composite setter shall enable and confirm MOSC readiness, then commit the final MOSC-based OSCCLK system-clock configuration with the corresponding memory-timing update.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_LDOVoltage_Test.cpp`
Manual basis: `tm4c`, System Control Register 25 through Register 28 on pp.313-318, including the documented `LDOSPCTL`, `LDOSPCAL`, `LDODPCTL`, and `LDODPCAL` `VLDO`, `VADJEN`, `NOPLL`, `WITHPLL`, and `30KHZ` fields.

- `REQ-SYSCTL-LDO-001` -> `SetLDOCustomVoltageWrappersUseExpectedFields` | `tm4c` | The sleep and deep-sleep custom LDO voltage setters shall program the documented `LDOSPCTL.VLDO` and `LDODPCTL.VLDO` fields.
- `REQ-SYSCTL-LDO-002` -> `LDOVoltageGettersRejectNullPointer` | `derived` | The custom-voltage, default-voltage, and custom-use getters shall reject null output pointers.
- `REQ-SYSCTL-LDO-003` -> `GetLDOCustomVoltageWrappersUseExpectedFields` | `tm4c` | The sleep and deep-sleep custom LDO voltage getters shall read the documented `LDOSPCTL.VLDO` and `LDODPCTL.VLDO` fields.
- `REQ-SYSCTL-LDO-004` -> `GetLDODefaultVoltageWrappersUseExpectedFields` | `tm4c` | The default-voltage getters shall read the documented `LDOSPCAL.WITHPLL`, `LDOSPCAL.NOPLL`, `LDODPCAL.30KHZ`, and `LDODPCAL.NOPLL` fields.
- `REQ-SYSCTL-LDO-005` -> `UseLDOCustomVoltageWrappersUseSingleBitMask` | `mixed` | The custom-voltage use setters shall program the documented `LDOSPCTL.VADJEN` and `LDODPCTL.VADJEN` fields as single-bit logical values through the primitive seam.
- `REQ-SYSCTL-LDO-006` -> `IsLDOCustomVoltageUsedWrappersUseSingleBitMask` | `mixed` | The custom-voltage use getters shall read the documented `LDOSPCTL.VADJEN` and `LDODPCTL.VADJEN` fields as single-bit logical values through the primitive seam.
- `REQ-SYSCTL-LDO-007` -> `LDOVoltageGettersPropagateReadErrors` | `derived` | The LDO getter family shall propagate primitive read failures without modifying caller output state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_PowerMode_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control Register 22 `SLPPWRCFG` pp.308-309, Register 23 `DSLPPWRCFG` pp.309-311, and Register 29 `SDPMST` pp.319-321.

- `REQ-SYSCTL-PWRMODE-001` -> `SetPowerModeFieldWrappersUseExpectedSleepAndDeepSleepFields` | `tm4c` | The public power-mode setters shall program the documented `SLPPWRCFG.SRAMPM`, `SLPPWRCFG.FLASHPM`, `DSLPPWRCFG.SRAMPM`, `DSLPPWRCFG.FLASHPM`, `DSLPPWRCFG.TSPD`, and `DSLPPWRCFG.LDOSM` fields.
- `REQ-SYSCTL-PWRMODE-002` -> `PowerModeIndividualGettersRejectNullPointer` | `derived` | The individual power-mode, deep-sleep state, and SDPMST status getters shall reject null output pointers before issuing primitive reads.
- `REQ-SYSCTL-PWRMODE-003` -> `GetPowerModeFieldWrappersUseExpectedSleepAndDeepSleepFields` | `tm4c` | The public power-mode getters shall read the documented `SLPPWRCFG` and `DSLPPWRCFG` fields and return the decoded mode or logical state values.
- `REQ-SYSCTL-PWRMODE-004` -> `SleepPowerModeGroupedWrappersSequenceAndPropagateErrors` | `mixed` | The grouped sleep power-mode wrappers shall route SRAM before Flash and shall propagate the first primitive error while preserving any output state that has not yet been updated.
- `REQ-SYSCTL-PWRMODE-005` -> `DeepSleepPowerModeGroupedWrappersSequenceAndPropagateErrors` | `mixed` | The grouped deep-sleep power-mode wrappers shall route SRAM before Flash and shall propagate the first primitive error while preserving any output state that has not yet been updated.
- `REQ-SYSCTL-PWRMODE-006` -> `PowerModeStatusGettersUseExpectedStatusBits` | `tm4c` | The SDPMST status getters shall read the documented error, warning, and live-status bits using the corresponding masks and shifts.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_ModulePower_Test.cpp`
Manual basis: `tm4c`, Chapter 5 System Control Register 32 `USBPDS` pp.324-325, Register 33 `USBMPC` pp.325-326, Register 34 `EMACPDS` pp.326-327, Register 35 `EMACMPC` pp.327-328, Register 38 `CAN0PDS` pp.330-331, Register 39 `CAN0MPC` pp.331-332, Register 40 `CAN1PDS` pp.332-333, and Register 41 `CAN1MPC` pp.333-334.

- `REQ-SYSCTL-MODPWR-001` -> `SetModuleMemoryPowerControlStateUsesExpectedModuleControlRegisters` | `tm4c` | The public module-memory power-control setter shall program the documented `USBMPC.PWRCTL`, `EMACMPC.PWRCTL`, `CAN0MPC.PWRCTL`, or `CAN1MPC.PWRCTL` field according to the selected module.
- `REQ-SYSCTL-MODPWR-002` -> `ModuleMemoryControlWrappersUseExpectedValuesAndRejectUnsupportedRetention` | `mixed` | The public ON, OFF, and retention wrappers shall delegate through the documented module-memory control field shape, and retention requests shall be rejected for modules whose manual descriptions only allow OFF and ON.
- `REQ-SYSCTL-MODPWR-003` -> `ModuleMemoryGettersRejectInvalidSelectorsAndNullPointers` | `derived` | The public module-memory control and status getters shall reject null output pointers and unsupported peripheral selectors before attempting primitive register access.
- `REQ-SYSCTL-MODPWR-004` -> `GetModuleMemoryPowerControlAndStatesUseExpectedRegisters` | `tm4c` | The public module-memory getters shall read the documented `USBMPC.PWRCTL`, `PDS.PWRSTAT`, and `PDS.MEMSTAT` fields and return the decoded control or status values for the selected module.
- `REQ-SYSCTL-MODPWR-005` -> `ModuleMemoryReadGettersPropagateErrorsAndPreserveCallerState` | `derived` | The public module-memory getters shall propagate primitive read failures without modifying caller output state.

Path: `xDriver_MCU/SYSCTL/Driver/xSource/SYSCTL_Voltage_Test.cpp`
Manual basis: `tm4c`, System Control Register 3 `PTBOCTL` register context pp.272-273, Register 6 `MISC` pp.278-279 for the separate combined BOR interrupt clear path, and Register 8 `PWRTC` p.283 for the per-rail RW1C brown-out cause bits.

- `REQ-SYSCTL-VOLT-001` -> `SetBrownOutEventActionFieldWrappersUseExpectedFields` | `tm4c` | The VDD and VDDA brown-out action setters shall program the documented `PTBOCTL.VDD_UBOR` and `PTBOCTL.VDDA_UBOR` fields.
- `REQ-SYSCTL-VOLT-002` -> `BrownOutIndividualGettersRejectNullPointer` | `derived` | The individual brown-out action and trip-status getters shall reject null output pointers.
- `REQ-SYSCTL-VOLT-003` -> `GetBrownOutEventActionFieldWrappersUseExpectedFields` | `tm4c` | The VDD and VDDA brown-out action getters shall read the documented `PTBOCTL.VDD_UBOR` and `PTBOCTL.VDDA_UBOR` fields.
- `REQ-SYSCTL-VOLT-004` -> `SetBrownOutEventActionGroupedWrapperSequencesAndPropagatesErrors` | `mixed` | The grouped brown-out action setter shall program VDD first and then VDDA, returning the first primitive write failure unchanged.
- `REQ-SYSCTL-VOLT-005` -> `GetBrownOutEventActionGroupedWrapperSequencesAndPropagatesErrors` | `mixed` | The grouped brown-out action getter shall read VDD first and then VDDA, propagating primitive read failures while preserving any output that has not yet been updated.
- `REQ-SYSCTL-VOLT-006` -> `BrownOutTripStatusGettersUsePWRTCFields` | `tm4c` | The brown-out trip-status getters shall read the documented `PWRTC.VDD_UBOR` and `PWRTC.VDDA_UBOR` cause bits.
- `REQ-SYSCTL-VOLT-007` -> `ClearBrownOutStatusWrappersUsePWRTCRW1CValues` | `tm4c` | The brown-out cause clear helpers shall write the documented `PWRTC` RW1C bits for VDD, VDDA, or both causes.
- `REQ-SYSCTL-VOLT-008` -> `BrownOutTripStatusGettersPropagateReadErrors` | `derived` | The brown-out trip-status getters shall propagate primitive read failures without modifying caller output state.

Path: `xDriver_MCU/ACMP/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/ACMP_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned ACMP SW and comparator source-handler tables used by the interrupt dispatch path.

- `REQ-ACMP-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The ACMP SW and comparator source-handler getters shall expose the expected default handler for every valid module and comparator slot.
- `REQ-ACMP-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The ACMP SW and comparator source-handler getters shall return a null handler when the caller selects a module or comparator outside `ACMP_enMODULE_MAX` and `ACMP_enCOMP_MAX`.
- `REQ-ACMP-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The ACMP SW and comparator source-handler pointer helpers shall return a null storage pointer when the caller selects a module or comparator outside `ACMP_enMODULE_MAX` and `ACMP_enCOMP_MAX`.
- `REQ-ACMP-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The ACMP SW and comparator source-handler pointer helpers shall expose writable storage and the paired getters shall reflect updates written through those pointers.

Path: `xDriver_MCU/ADC/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/ADC_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned ADC SW, sequencer, and comparator source-handler tables used by the interrupt dispatch path.

- `REQ-ADC-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The ADC SW, sequencer, and comparator source-handler getters shall expose the expected default handler for every valid module, sequencer, interrupt-type, and comparator slot.
- `REQ-ADC-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The ADC SW, sequencer, and comparator source-handler getters shall return a null handler when the caller selects a module, sequencer, interrupt type, or comparator outside the documented public maxima.
- `REQ-ADC-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The ADC SW, sequencer, and comparator source-handler pointer helpers shall return a null storage pointer when the caller selects a module, sequencer, interrupt type, or comparator outside the documented public maxima.
- `REQ-ADC-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The ADC SW, sequencer, and comparator source-handler pointer helpers shall expose writable storage and the paired getters shall reflect updates written through those pointers.

Path: `xDriver_MCU/DMA/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/DMA_InterruptRoutine_Source_Software_Test.cpp`
Manual basis: `derived`, software-owned DMA error and software source-handler tables used by the interrupt dispatch path.

- `REQ-DMA-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The DMA error and software source-handler getters shall expose the expected default handler for every valid module, error source, and software-channel slot.
- `REQ-DMA-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The DMA error and software source-handler getters shall return a null handler when the caller selects a module, error source, or software channel outside the documented public maxima.
- `REQ-DMA-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The DMA error and software source-handler pointer helpers shall return a null storage pointer when the caller selects a module, error source, or software channel outside the documented public maxima.
- `REQ-DMA-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The DMA error and software source-handler pointer helpers shall expose writable storage and the paired getters shall reflect updates written through those pointers.

Path: `xDriver_MCU/EEPROM/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/EEPROM_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned EEPROM source-handler table used by the interrupt dispatch path.

- `REQ-EEPROM-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The EEPROM source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-EEPROM-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The EEPROM source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `EEPROM_enMODULE_MAX` and `EEPROM_enINT_MAX`.
- `REQ-EEPROM-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The EEPROM source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `EEPROM_enMODULE_MAX` and `EEPROM_enINT_MAX`.
- `REQ-EEPROM-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The EEPROM source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/FLASH/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/FLASH_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned FLASH source-handler table used by the interrupt dispatch path.

- `REQ-FLASH-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The FLASH source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-FLASH-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The FLASH source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `FLASH_enMODULE_MAX` and `FLASH_enINT_MAX`.
- `REQ-FLASH-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The FLASH source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `FLASH_enMODULE_MAX` and `FLASH_enINT_MAX`.
- `REQ-FLASH-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The FLASH source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/GPIO/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/GPIO_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned GPIO general, DMA, SW, and PQ source-handler tables used by the interrupt dispatch path.

- `REQ-GPIO-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The GPIO general, DMA, SW, and PQ source-handler getters shall expose the expected default handler for every valid port and pin combination supported by each family.
- `REQ-GPIO-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The GPIO general, DMA, SW, and PQ source-handler getters shall return a null handler when the caller selects a port or pin outside the valid family-specific bounds.
- `REQ-GPIO-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The GPIO general, DMA, SW, and PQ source-handler pointer helpers shall return a null storage pointer when the caller selects a port or pin outside the valid family-specific bounds.
- `REQ-GPIO-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The GPIO general, DMA, SW, and PQ source-handler pointer helpers shall expose writable storage and the paired getters shall reflect updates written through those pointers.

Path: `xDriver_MCU/HIB/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/HIB_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned HIB source-handler table used by the interrupt dispatch path.

- `REQ-HIB-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The HIB source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-HIB-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The HIB source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `HIB_enMODULE_MAX` and `HIB_enINT_MAX`.
- `REQ-HIB-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The HIB source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `HIB_enMODULE_MAX` and `HIB_enINT_MAX`.
- `REQ-HIB-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The HIB source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/I2C_Master_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned I2C master source-handler table used by the interrupt dispatch path.

- `REQ-I2CMASTER-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The I2C master source-handler getter shall expose the expected default handler for every valid module and master interrupt slot.
- `REQ-I2CMASTER-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The I2C master source-handler getter shall return a null handler when the caller selects a module or master interrupt source outside `I2C_enMODULE_MAX` and `I2C_enMASTER_INT_MAX`.
- `REQ-I2CMASTER-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The I2C master source-handler pointer helper shall return a null storage pointer when the caller selects a module or master interrupt source outside `I2C_enMODULE_MAX` and `I2C_enMASTER_INT_MAX`.
- `REQ-I2CMASTER-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The I2C master source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/I2C/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/I2C_Slave_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned I2C slave source-handler table used by the interrupt dispatch path.

- `REQ-I2CSLAVE-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The I2C slave source-handler getter shall expose the expected default handler for every valid module and slave interrupt slot.
- `REQ-I2CSLAVE-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The I2C slave source-handler getter shall return a null handler when the caller selects a module or slave interrupt source outside `I2C_enMODULE_MAX` and `I2C_enSLAVE_INT_MAX`.
- `REQ-I2CSLAVE-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The I2C slave source-handler pointer helper shall return a null storage pointer when the caller selects a module or slave interrupt source outside `I2C_enMODULE_MAX` and `I2C_enSLAVE_INT_MAX`.
- `REQ-I2CSLAVE-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The I2C slave source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/PWM/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/PWM_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned PWM generator, fault SW, fault input, and fault digital-comparator source-handler tables used by the interrupt dispatch path.

- `REQ-PWM-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The PWM generator, fault SW, fault input, and fault digital-comparator source-handler getters shall expose the expected default handler for every valid module, generator, event, input, and digital-comparator slot.
- `REQ-PWM-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The PWM generator, fault SW, fault input, and fault digital-comparator source-handler getters shall return a null handler when the caller selects a module, generator, event, input, or digital-comparator slot outside the documented public maxima.
- `REQ-PWM-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The PWM generator, fault SW, fault input, and fault digital-comparator source-handler pointer helpers shall return a null storage pointer when the caller selects a module, generator, event, input, or digital-comparator slot outside the documented public maxima.
- `REQ-PWM-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The PWM generator, fault SW, fault input, and fault digital-comparator source-handler pointer helpers shall expose writable storage and the paired getters shall reflect updates written through those pointers.

Path: `xDriver_MCU/QEI/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/QEI_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned QEI source-handler table used by the interrupt dispatch path.

- `REQ-QEI-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The QEI source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-QEI-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The QEI source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `QEI_enMODULE_MAX` and `QEI_enINT_MAX`.
- `REQ-QEI-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The QEI source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `QEI_enMODULE_MAX` and `QEI_enINT_MAX`.
- `REQ-QEI-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The QEI source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/SSI/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/SSI_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned SSI source-handler table used by the interrupt dispatch path.

- `REQ-SSI-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The SSI source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-SSI-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The SSI source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `SSI_enMODULE_MAX` and `SSI_enINT_MAX`.
- `REQ-SSI-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The SSI source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `SSI_enMODULE_MAX` and `SSI_enINT_MAX`.
- `REQ-SSI-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The SSI source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/SYSEXC/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/SYSEXC_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned SYSEXC source-handler table used by the interrupt dispatch path.

- `REQ-SYSEXC-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The SYSEXC source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-SYSEXC-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The SYSEXC source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `SYSEXC_enMODULE_MAX` and `SYSEXC_enINT_MAX`.
- `REQ-SYSEXC-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The SYSEXC source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `SYSEXC_enMODULE_MAX` and `SYSEXC_enINT_MAX`.
- `REQ-SYSEXC-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The SYSEXC source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/UART/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/UART_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned UART source-handler table used by the interrupt dispatch path.

- `REQ-UART-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The UART source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-UART-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The UART source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `UART_enMODULE_MAX` and `UART_enINT_MAX`.
- `REQ-UART-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The UART source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `UART_enMODULE_MAX` and `UART_enINT_MAX`.
- `REQ-UART-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The UART source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

Path: `xDriver_MCU/WDT/Driver/Intrinsics/Interrupt/InterruptRoutine/xSource/WDT_InterruptRoutine_Source_Test.cpp`
Manual basis: `derived`, software-owned WDT source-handler table used by the interrupt dispatch path.

- `REQ-WDT-INTROUTSRC-001` -> `InterruptSourceHandlersExposeExpectedDefaultHandlers` | `derived` | The WDT source-handler getter shall expose the expected default handler for every valid module and interrupt slot.
- `REQ-WDT-INTROUTSRC-002` -> `InterruptSourceGettersRejectInvalidSelections` | `derived` | The WDT source-handler getter shall return a null handler when the caller selects a module or interrupt source outside `WDT_enMODULE_MAX` and `WDT_enINT_MAX`.
- `REQ-WDT-INTROUTSRC-003` -> `InterruptSourceHandlerPointersRejectInvalidSelections` | `derived` | The WDT source-handler pointer helper shall return a null storage pointer when the caller selects a module or interrupt source outside `WDT_enMODULE_MAX` and `WDT_enINT_MAX`.
- `REQ-WDT-INTROUTSRC-004` -> `InterruptSourceHandlerPointersExposeWritableSlots` | `derived` | The WDT source-handler pointer helper shall expose writable storage and the getter shall reflect updates written through that pointer.

## Update Rule

Whenever a new host test case is added:

1. add a new traceability row in the matching test-file section
2. if the source has no section yet, add a new section with manual basis and source classification
3. use direct manual chapter/register/page context when a hardware requirement exists
4. mark pointer validation, error propagation, callback, and wrapper-policy assertions as `derived` or `mixed` when the manuals do not define them directly

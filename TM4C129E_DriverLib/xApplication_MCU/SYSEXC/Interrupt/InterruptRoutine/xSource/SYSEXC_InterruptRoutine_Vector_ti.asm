
 	.sect 	".text"
 	.align 	4
	.thumb
	.clink

	.global SYSEXC__vIRQVectorHandler

 	.align 	4
SYSEXC__vIRQVectorHandler:
    PUSH {R4-R7}
    ubfx    R4, LR, #2, #1
    cmp    R4, #0
    beq    MainStackMemory
    b    ProcessStackMemory

    .global SYSEXC_puxContext
MainStackMemory:
    mrs    R4, MSP
    movw R6, SYSEXC_puxContext
    movt R6, SYSEXC_puxContext
    ldr R5, [R4, #0X10]
    str R5, [R6, #0x0]
    ldr R5, [R4, #0x14]
    str R5, [R6, #0x4]
    ldr R5, [R4, #0x18]
    str R5, [R6, #0x8]
    ldr R5, [R4, #0x1C]
    str R5, [R6, #0xC]
    ldr R5, [R4, #0x20]
    str R5, [R6, #0x10]
    ldr R5, [R4, #0x24]
    str R5, [R6, #0x14]
    ldr R5, [R4, #0x28]
    str R5, [R6, #0x18]
    ldr R5, [R4, #0x2C]
    str R5, [R6, #0x1C]
    b    ProcessMemory

ProcessStackMemory:
    mrs    R4, PSP
    movw R6, SYSEXC_puxContext
    movt R6, SYSEXC_puxContext
    ldr R5, [R4, #0X0]
    str R5, [R6, #0x0]
    ldr R5, [R4, #0x4]
    str R5, [R6, #0x4]
    ldr R5, [R4, #0x8]
    str R5, [R6, #0x8]
    ldr R5, [R4, #0xC]
    str R5, [R6, #0xC]
    ldr R5, [R4, #0x10]
    str R5, [R6, #0x10]
    ldr R5, [R4, #0x14]
    str R5, [R6, #0x14]
    ldr R5, [R4, #0x18]
    str R5, [R6, #0x18]
    ldr R5, [R4, #0x1C]
    str R5, [R6, #0x1C]

ProcessMemory:
    pop {R4-R7}
    push {R0,R1,R2,LR}
    .global SYSEXC__vSendValues
    .global SYSEXC__vIRQVectorHandlerCustom
    movw R2, SYSEXC__vSendValues
    movt R2, SYSEXC__vSendValues
    blx R2
    movw R0, #0x9000
    movt R0, #0x400F
    movw R1, SYSEXC_puxContext
    movt R1, SYSEXC_puxContext
    movw R2, SYSEXC__vIRQVectorHandlerCustom
    movt R2, SYSEXC__vIRQVectorHandlerCustom
    blx R2
    pop {R0,R1,R2,LR}
    BX LR


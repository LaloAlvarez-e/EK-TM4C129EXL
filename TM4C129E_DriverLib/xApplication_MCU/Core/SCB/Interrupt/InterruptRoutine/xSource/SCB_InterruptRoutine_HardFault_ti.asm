
 	.sect 	".text"
 	.align 	4
	.thumb
	.clink

	.global HardFault__vIRQVectorHandler

 	.align 	4
HardFault__vIRQVectorHandler:
    PUSH {R4-R7}
    ubfx    R4, LR, #2, #1
    cmp    R4, #0
    beq    MainStackHard
    b    ProcessStackHard

    .global SCB_HardFault_puxContext
MainStackHard:
    mrs    R4, MSP
    movw R6, SCB_HardFault_puxContext
    movt R6, SCB_HardFault_puxContext
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
    b    ProcessHard

ProcessStackHard:
    mrs    R4, PSP
    movw R6, SCB_HardFault_puxContext
    movt R6, SCB_HardFault_puxContext
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

ProcessHard:
    pop {R4-R7}
    push {R0,R1,R2,LR}
    .global HardFault__vIRQVectorHandlerReport
    .global HardFault__vIRQVectorHandlerCustom
    movw R0, #0xE000
    movt R0, #0xE000
    movw R1, SCB_HardFault_puxContext
    movt R1, SCB_HardFault_puxContext
    movw R2, HardFault__vIRQVectorHandlerReport
    movt R2, HardFault__vIRQVectorHandlerReport
    blx R2
    movw R0, #0xE000
    movt R0, #0xE000
    movw R1, SCB_HardFault_puxContext
    movt R1, SCB_HardFault_puxContext
    movw R2, HardFault__vIRQVectorHandlerCustom
    movt R2, HardFault__vIRQVectorHandlerCustom
    blx R2
    pop {R0,R1,R2,LR}
    BX LR

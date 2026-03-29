/******************************************************************************
 *
 * Default Linker script for the Texas Instruments TM4C129ENCPDT
 *
 * This is derived from revision 15071 of the TivaWare Library.
 *
 *****************************************************************************/

MEMORY
{

    FLASH_VTABLE (RX)   : ORIGIN = 0x00000000, LENGTH = 0x00000400
    FLASH_BANK01 (RX) : ORIGIN = 0x00000400, LENGTH = 0x0007FC00
    FLASH_BANK23 (RX) : ORIGIN = 0x00080000, LENGTH = 0x00080000
    SRAM_VTABLE (RWX) : ORIGIN = 0x20000000, LENGTH = 0x00000400 /*1K*/
    SRAM_DMA (RW) : ORIGIN = 0x20000400, LENGTH = 0x00000400
    SRAM_CODE (RWX) : ORIGIN = 0x20000800, LENGTH = 0x00001800 /*5K*/
    SRAM (RW) : ORIGIN = 0x20002000, LENGTH = 0x00020000
    SRAM_DYNAMIC (RW) : ORIGIN = 0x20022000, LENGTH = 0x0001C800 /*32K*/
    SRAM_MAIN_STACK (RW) : ORIGIN = 0x2003F800, LENGTH = 0x00000800 /*1.5K*/
}

ENTRY(ResetISR);

SECTIONS {

    PROVIDE (_intvecs_base_address = 0x0);

    .intvecs (_intvecs_base_address) : AT (_intvecs_base_address) {
        __intvec_start__ = .;
        KEEP (*(.intvecs))
        __intvec_end__ = .;
    } > FLASH_VTABLE

    PROVIDE (_vtable_base_address = 0x20000000);

    .vtable (_vtable_base_address) : AT (_vtable_base_address) {
        __vtable_start__ = .;
        . = ALIGN(4);
        KEEP (*(.vtable))
        . = ALIGN(4);
        __vtable_end__ = .;
    } > SRAM_VTABLE

    .text : {
        CREATE_OBJECT_SYMBOLS
        . = ALIGN(4);
        *(.text)
        *(.text.*)
        . = ALIGN(0x4);
        KEEP (*(.ctors))
        . = ALIGN(0x4);
        KEEP (*(.dtors))
        . = ALIGN(0x4);
        __init_array_start = .;
        KEEP (*(.init_array*))
        __init_array_end = .;
        *(.init)
        *(.fini*)
    } > FLASH_BANK01

    PROVIDE (__etext = .);
    PROVIDE (_etext = .);
    PROVIDE (etext = .);

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > FLASH_BANK01

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH_BANK01

    __flash_exec_end__ = .;


    .ramcode : {
        . = ALIGN(4);
        __ramcode_load__ = LOADADDR (.ramcode);
        __ramcode_start__ = .;
        *(.RamFunc)        /* .RamFunc sections */
        *(.RamFunc*)       /* .RamFunc* sections */
        *(.ramcode)
        *(.ramcode*)
        . = ALIGN (4);
        __ramcode_end__ = .;
    } > SRAM_CODE AT> FLASH_BANK23

    .rodata : {
        *(.rodata)
        *(.rodata*)
    } > FLASH_BANK23

    .data : ALIGN (4) {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        *(.data)
        *(.data*)
        . = ALIGN (4);
        __data_end__ = .;
    } > SRAM AT> FLASH_BANK23

    __data_load_end__ = LOADADDR (.data) + SIZEOF(.data);

    .dma : {
        . = ALIGN(4);
        __dma_start__ = .;
        *(.shdma)
        *(.dma)
        *(.dma.*)
        . = ALIGN (4);
        __dma_end__ = .;
    } > SRAM_DMA

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN (4);
        __bss_end__ = .;
    } > SRAM

    .heap (NOLOAD) : {
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        KEEP(*(.heap))
        . = ORIGIN(SRAM_DYNAMIC) + LENGTH(SRAM_DYNAMIC);
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > SRAM_DYNAMIC

/*
    .stack_process : ALIGN(0x8) {
        _stack_process = .;
        __stack_process = .;
        KEEP(*(.stack_process))
        __stack_process_end__ = .;
    } > SRAM_PROCESS_STACK
*/

    .stack : ALIGN(0x8) {
        _stack = .;
        __stack = .;
        KEEP(*(.stack))
        __stack_end__ = .;
    } > SRAM_MAIN_STACK

    __stack_end__ = __stack + LENGTH(SRAM_MAIN_STACK);
    __stack_size__ = LENGTH(SRAM_MAIN_STACK);

}


FLASH_VTABLE 0x0000 0x0400 ; Name of load region (FLASH_VTABLE),
 ; Start address for load region (0x0000),
 ; Maximum size of load region (0x0400)
{
	intvecs 0x0000 FIXED ; Name of first exec region (intvecs),
	; Start address for exec region (0x0000),
	{
		* (.intvecs) ; Place all intvecs into
		; this exec region
	}
}

FLASH_BANK01 0x00000400 0x0007FC00 ; Name of load region (FLASH_VTABLE),
 ; Start address for load region (0x00000400),
 ; Maximum size of load region (0x0007FC00)
{
	CODE +0 ALIGNALL 4 ;Name of first exec region (SRAM_VTABLE),
	; Start address for exec region (0x0000),
	{
        *(+RO)
        *(.text)
        *(.text.*)
	}
	
	SRAMVTABLE 0x20000000 0x00000400 ;Name of first exec region (SRAM_VTABLE),
	; Start address for exec region (0x0000),
	{
		* (.vtable) ; Place all intvecs into
		; this exec region
	}
}

FLASH_BANK23 0x00080000 0x00080000 ; Name of load region (FLASH_VTABLE),
 ; Start address for load region (0x00000400),
 ; Maximum size of load region (0x0007FC00)
{
	CONSTANT 0x00080000 ALIGNALL 4 ;Name of first exec region (SRAM_VTABLE),
	; Start address for exec region (0x0000),
	{
		* (+RO-DATA) ; Place all intvecs into
        *(.rodata)
        *(.rodata*)
		; this exec region
	}
	RAM_CODE 0x20000800 0x00001800 ;Name of first exec region (SRAM_VTABLE),
	; Start address for exec region (0x0000),
	{
		; this exec region
        *(.RamFunc)        /* .RamFunc sections */
        *(.RamFunc*)       /* .RamFunc* sections */
        *(.ramcode)
        *(.ramcode*)
		; this exec region
	}
	RAM_DATA +0
	; Start address for exec region (0x0000),
	{
        *(+RW)
        *(.data)
        *(.data*)
    }
	RAM_BSS +0 ;Name of first exec region (SRAM_VTABLE),
	; Start address for exec region (0x0000),
	{
        *(+ZI)
        *(.shbss)
        *(.bss)
        *(.bss.*)
        *(COMMON)
		; this exec region
	}
	DMA 0x20000400 0x00000400 ;Name of first exec region (SRAM_VTABLE),
	; Start address for exec region (0x0000),
	{
        *(.shdma)
        *(.dma)
        *(.dma.*)
		; this exec region
	}
    ARM_LIB_STACK 0x2003F800 EMPTY -0x00000800 ; Stack region growing down
    {
    }
    ARM_LIB_HEAP 0x20022000 EMPTY 0x0001C800 ; Heap region growing up
    {
    }
	__stack_end__ = __stack + SIZE(SRAM_MAIN_STACK);
	__stack_size__ = SIZE(SRAM_MAIN_STACK);
}



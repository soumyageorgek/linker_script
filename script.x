MEMORY {
	RAM (rwx): ORIGIN = 0x0200, LENGTH = 128
	FLASH (rx): ORIGIN = 0xF800, LENGTH = 2K
	VECTORS (rx): ORIGIN = 0XFFE0, LENGTH = 32
}

SECTIONS {
	.text : {
		. = ALIGN(2);
		*(.text)
		. = ALIGN(2);
		_etext = .;
	} >FLASH
	.vectors : {
		. = ALIGN(2);
		*(.vectors)
		. = ALIGN(2);
	} >VECTORS
	.data : AT (_etext) {
		. = ALIGN(2);
		_sdata = .;
		*(.data)
		. = ALIGN(2);
		_edata = .;
	} >RAM
	.bss : {
		. = ALIGN(2);
		_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(2);
		_ebss = .;
	} >RAM
	PROVIDE (__stack = 0x280) ;
}

/* Label for the program's entry point */
ENTRY(reset_handler)

/* End of RAM/Start of stack */
/* (2KB SRAM) */
_estack = 0x20000800;

/* Set minimum size for stack and dynamic memory. */
/* (The linker will generate an error if there is
 * less than this much RAM leftover.) */
/* (0.5KB) */
_Min_Leftover_RAM = 0x200;

MEMORY
{
    FLASH ( rx )      : ORIGIN = 0x00000000, LENGTH = 16K
    RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 2K
}

INCLUDE "sections.ld"

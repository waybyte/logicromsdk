/* Copyright (C) 2018 RDA Technologies Limited and/or its affiliates("RDA").
 * All rights reserved.
 *
 * This software is supplied "AS IS" without any warranties.
 * RDA assumes no responsibility or liability for the use of the software,
 * conveys no license or title under any patent, copyright, or mask work
 * right to the product. RDA reserves the right to make changes in the
 * software without notification.  RDA also make no representation or
 * warranty that such application will be suitable for the specified use
 * without further testing or modification.
 */

/* external application on flash link script */

#undef mips
#define mips mips
OUTPUT_ARCH(mips)
ENTRY(main)
EXTERN(main)

#define ROTEXT() .text .text.* .gnu.linkonce.t.* .glue_7 .glue_7t vtable
#define RODATA() .plt .rdata .rodata .rodata.* .gnu.linkonce.r.* .constdata .constdata.*
#define DATA() .data_begin .data_begin.* .data .data.* .gnu.linkonce.d.* .got.plt .got .shdata .data_end .data_end.* .sdata .sdata.*
#define BSS() .bss_begin .bss_begin.* .shbss .bss .bss.* COMMON .scommon .sbss .sbss.* .sbss2 .sbss2.* .gnu.linkonce.b.* .bss_end .bss_end.*

MEMORY {
    flash (rx): ORIGIN = 0xFFFFFFFF88250000, LENGTH = 0x90000
    ram (rwx): ORIGIN = 0xFFFFFFFF82302000, LENGTH = 0xFE000
}

SECTIONS {
    . = ORIGIN(flash);
    __flash_start = .;

    .appheader : {
        LONG(0x41505031)
        LONG(0) /* App Size */
        LONG(0) /* App CRC */
        LONG(0)

        LONG(2)
        LONG(__sdkstub_load_start - __flash_start)
        LONG(__sdkstub_end - __sdkstub_start)
        LONG(__sdkstub_start)

        LONG(1)
        LONG(__data_load_start - __flash_start)
        LONG(__data_end - __data_start)
        LONG(__data_start)

        LONG(3)
        LONG(0)
        LONG(__bss_end - __bss_start)
        LONG(__bss_start)

        LONG(0)
        LONG(0)
        LONG(0)
        LONG(0)

        LONG(0)
        LONG(0)
        LONG(0)
        LONG(0)

        LONG(0)
        LONG(0)
        LONG(0)
        LONG(0)

        LONG(0)
        LONG(0)
        LONG(0)
        LONG(0)
    } > flash

    .initdata ALIGN(0x10) : {
        KEEP(*(.appinit));
    } > flash

    .text ALIGN(0x10) : {
        __text_start = .;
        *(ROTEXT() RODATA())
        __text_end = .;
    } > flash

    .ll ALIGN(0x10) : {
        PROVIDE_HIDDEN (__ll_entry_start = .);
        KEEP( *(SORT(.ll_entry_cmdlist*)) );
        PROVIDE_HIDDEN (__ll_entry_end = .);
    } > flash

    .init_array ALIGN(0x10) : {
        __init_array_start = .;
        KEEP(*(.init_array .init_array.*))
        __init_array_end = .;
        __init_array_load_start = LOADADDR(.init_array);
    } > flash

    __text_load_start = LOADADDR(.text);

    . = ORIGIN(ram);
    __ram_start = .;

    .sdkstub ALIGN(0x10) : {
        __sdkstub_start = .;
        *(.sdkstub.*)
        __sdkstub_end = .;
    } AT>flash

    __sdkstub_load_start = LOADADDR(.sdkstub);

    .data ALIGN(0x10) : {
        __data_start = .;
        *(DATA())
        __data_end = .;
    } AT>flash

    __data_load_start = LOADADDR(.data);

    __flash_end = LOADADDR(.data) + SIZEOF(.data);

    .bss ALIGN(0x10) : {
        __bss_start = .;
        *(BSS())
        __bss_end = .;
    }

    __ram_end = .;

    ASSERT(__flash_end <= ORIGIN(flash) + LENGTH(flash), "FLASH overflow")
    ASSERT(__ram_end <= ORIGIN(ram) + LENGTH(ram), "RAM overflow")

    .comment 0 : { *(.comment) }
    /DISCARD/ : { *(.dynstr*) }
    /DISCARD/ : { *(.dynamic*) }
    /DISCARD/ : { *(.plt*) }
    /DISCARD/ : { *(.interp*) }
    /DISCARD/ : { *(.gnu*) }
    /DISCARD/ : {
        *(.MIPS.abiflags)
        *(.rel.dyn)
    }
}

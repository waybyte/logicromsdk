OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

ENTRY(appimg_enter)
EXTERN(appimg_enter)
EXTERN(appimg_exit)
EXTERN(appimg_get_param)
EXTERN(appimg_set_param)
PROVIDE(appimg_get_param = 0);
PROVIDE(appimg_set_param = 0);

#define ALIGNMENT           ALIGN(0x20)
#define HEADER_APP_IMG      LONG(0x4D4F524C) \
                            LONG(0) \
                            LONG(0) \
                            KEEP(*(.rodata.core_stub.header))
#define HEADER_LOAD(t, n)   LONG(t) \
                            LONG(__##n##_load_start - __flash_start) \
                            LONG(__##n##_end - __##n##_start) \
                            LONG(__##n##_start)
#define HEADER_CLEAR(n)     LONG(3) \
                            LONG(0) \
                            LONG(__##n##_end - __##n##_start) \
                            LONG(__##n##_start)
#define HEADER_DUMMY        LONG(0) LONG(0) LONG(0) LONG(0)

#ifdef FLASHSZ_16M
#define APP_FLASH_ORIGIN 0x7e810000
#define APP_FLASH_SZ 0x100000
#elif defined(FLASHSZ_8M)
#define APP_FLASH_ORIGIN 0x7e810000
#define APP_FLASH_SZ 0x80000
#else
#error "Flash size not set"
#endif

#define DEF_RO .text .text.* .gnu.linkonce.t.* .plt .rdata .rodata .rodata.* .constdata .constdata.* .gnu.linkonce.r.* .glue_7 .glue_7t .vfp11_veneer .v4_bx vtable
#define DEF_RW .data_begin .data_begin.* .data .data.* .gnu.linkonce.d.* .got.plt .got .shdata .data_end .data_end.*
#define DEF_ZI .bss_begin .bss_begin.* .shbss .bss .bss.* COMMON .scommon .sbss .sbss.* .sbss2 .sbss2.* .gnu.linkonce.b.* .bss_end .bss_end.*

MEMORY {
    flash (rx): ORIGIN = APP_FLASH_ORIGIN, LENGTH = APP_FLASH_SZ
    ram (rwx): ORIGIN = 0x7e910000, LENGTH = 0x00080000
}

SECTIONS {
    . = ORIGIN(flash);
    __flash_start = .;

    .imageheader : {
        HEADER_APP_IMG
        HEADER_LOAD(2, corestub)
        HEADER_LOAD(4, text)
        HEADER_LOAD(4, init_array)
        HEADER_LOAD(1, data)
        HEADER_CLEAR(bss)
        HEADER_DUMMY
    } > flash

    ASSERT(SIZEOF(.imageheader) == 128, "invalid app image header")
    .initdata ALIGNMENT : {
        KEEP(*(.appinit));
    } > flash

    . = ORIGIN(ram);
    __ram_start = .;

    .corestub ALIGNMENT : {
        __corestub_start = .;
        *(.text.core_stub.*)
        __corestub_end = .;
        . = ALIGNMENT;
        __corestub_load_start = LOADADDR(.corestub);
    } AT>flash

    .data ALIGNMENT : {
        __data_start = .;
        *(DEF_RW)
        __data_end = .;
        . = ALIGNMENT;
        __data_load_start = LOADADDR(.data);
    } AT>flash

    .bss ALIGNMENT : {
        __bss_start = .;
        *(DEF_ZI)
        __bss_end = .;
        . = ALIGNMENT;
    }

    . = LOADADDR(.corestub) + SIZEOF(.corestub) + SIZEOF(.data);

    .text ALIGNMENT : {
        __text_start = .;
        *(DEF_RO)
        KEEP(*(.eh_frame*))
        __text_end = .;
        . = ALIGNMENT;
        __text_load_start = LOADADDR(.text);
    } > flash

    .ll ALIGNMENT : {
        PROVIDE_HIDDEN (__ll_entry_start = .);
        KEEP( *(SORT(.ll_entry_cmdlist*)) );
        PROVIDE_HIDDEN (__ll_entry_end = .);
    } > flash

    /* ARM magic sections */
    .ARM.extab ALIGNMENT : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > flash

    __exidx_start = .;
    .ARM.exidx ALIGNMENT : {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > flash
    __exidx_end = .;

    .init_array ALIGNMENT : {
        __init_array_start = .;
        KEEP(*(.init_array .init_array.*))
        __init_array_end = .;
        . = ALIGNMENT;
        __init_array_load_start = LOADADDR(.init_array);
    } > flash

    __flash_end = ADDR(.init_array) + SIZEOF(.init_array);
    __ram_end = ADDR(.bss) + SIZEOF(.bss);

    ASSERT(__flash_end <= ORIGIN(flash) + LENGTH(flash), "FLASH overflow")
    ASSERT(__ram_end <= ORIGIN(ram) + LENGTH(ram), "RAM overflow")

    .comment 0 : { *(.comment) }
    /DISCARD/ : { *(.dynstr*) }
    /DISCARD/ : { *(.dynamic*) }
    /DISCARD/ : { *(.plt*) }
    /DISCARD/ : { *(.interp*) }
    /DISCARD/ : { *(.gnu*) }
}

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

#include "hal_config.h"

#ifdef CONFIG_CPU_MIPS
#undef mips
#define mips mips
OUTPUT_ARCH(mips)
#endif

#ifdef CONFIG_CPU_ARM
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
#endif

ENTRY(appimg_enter)
EXTERN(appimg_enter)
EXTERN(appimg_exit)
EXTERN(appimg_get_param)
EXTERN(appimg_set_param)
PROVIDE(appimg_get_param = 0);
PROVIDE(appimg_set_param = 0);

#define ALIGNMENT           ALIGN(0x20)
#define HEADER_APP_IMG      LONG(0x41505032) \
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

#define DEF_RO .text .text.* .gnu.linkonce.t.* .plt .rdata .rodata .rodata.* .constdata .constdata.* .gnu.linkonce.r.* .glue_7 .glue_7t .vfp11_veneer .v4_bx vtable
#define DEF_RW .data_begin .data_begin.* .data .data.* .gnu.linkonce.d.* .got.plt .got .shdata .data_end .data_end.*
#define DEF_ZI .bss_begin .bss_begin.* .shbss .bss .bss.* COMMON .scommon .sbss .sbss.* .sbss2 .sbss2.* .gnu.linkonce.b.* .bss_end .bss_end.*

/* Core mapped symbols */
strtol = _strtol;
strtoll = _strtoll;
strtoul = _strtoul;
strtoull = _strtoll;
strtok_r = _strtok_r;
_strtol_r = __strtol_r;
_strtoll_r = __strtoll_r;
_strtoul_r = __strtoul_r;
_strtoull_r = __strtoull_r;
_strtod_l = __strtod_l;
_strerror_r = __strerror_r;
_svfprintf_r = __svfprintf_r;
_vsnprintf_r = __vsnprintf_r;
_fflush_r = __fflush_r;
__ssvfiscanf_r = ___ssvfiscanf_r;
_vfprintf_r = __vfprintf_r;
_svfiprintf_r = __svfiprintf_r;
__ssvfscanf_r = ___ssvfscanf_r;
__sflush_r = ___sflush_r;
__sfvwrite_r = ___sfvwrite_r;
_fclose_r = __fclose_r;
_strerror_r = __strerror_r;
_strtod_l = __strtod_l;
_tzset_unlocked_r = __tzset_unlocked_r;
__tzcalc_limits = ___tzcalc_limits;
gmtime_r = _gmtime_r;

MEMORY {
    flash (rx): ORIGIN = CONFIG_APPIMG_FLASH_ADDRESS, LENGTH = CONFIG_APPIMG_FLASH_SIZE
    ram (rwx): ORIGIN = CONFIG_RAM_PHY_ADDRESS+CONFIG_APP_FLASHIMG_RAM_OFFSET, LENGTH = CONFIG_APP_FLASHIMG_RAM_SIZE
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
		KEEP(*(.appinit));
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

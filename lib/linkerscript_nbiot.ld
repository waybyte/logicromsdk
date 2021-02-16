/* Memory address for MT2625 */
TARGET_ROM_ORIGIN = 0x082D4040;
TARGET_ROM_LEN = 0x00032000;
TARGET_RAM_ORIGIN = 0x101E8000;
TARGET_RAM_LEN = 0x00018000;

/* Core provided symbols - for firmware size reduction */
strtod = _strtod;
strtof = _strtof;
strtol = _strtol;
strtoul = _strtoul;
_svfprintf_r = __svfprintf_r;
_vsnprintf_r = __vsnprintf_r;
_fflush_r = __fflush_r;
_vfprintf_r = __vfprintf_r;
__ssvfscanf_r = ___ssvfscanf_r;
_strerror_r = __strerror_r;

INCLUDE linkerscript_common.lds

MEMORY
{
	RTCRAM (rw) : ORIGIN = 0x04301F00, LENGTH = 0x00000100
}

SECTIONS
{
	.rtcdata : ALIGN(4)
	{
		PROVIDE_HIDDEN (__rtc_data_load = LOADADDR(.rtcdata));
		PROVIDE_HIDDEN (__rtc_data_start = .);
		*(.rtcdata .rtcdata.*)
		PROVIDE_HIDDEN (__rtc_data_end = .);
		. = ALIGN(4);
	} > RTCRAM  AT > ROM

	.rtcbss : ALIGN(4)
	{
		PROVIDE_HIDDEN (__rtc_bss_start__ = .);
		*(.rtcbss .rtcbss.*)
		PROVIDE_HIDDEN (__rtc_bss_end__ = .);
		. = ALIGN(4);
	} > RTCRAM
}

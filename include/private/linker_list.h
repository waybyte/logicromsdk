#ifndef __LINKER_LIST_H__
#define __LINKER_LIST_H__

/* NOTE: these macros were inspired by those found in linker_lists.h of the U-Boot project */

/* WARNING: these macros are designed to be used in conjunction with a linker script
            the following basic script can be used, in conjunction with passing the
            appropriate linker script arguments: ld -T link.lds

        SECTIONS {
          __ll_entry_start = .;
          .lga : {
            KEEP(*(SORT(.ll_entry_*)));
          }
	        __ll_entry_end = .;
        }
        INSERT BEFORE .bss;
*/

/* this macro associates a variable with an ELF section and is not intended to be used by the user */
#define __ll_entry_attrib(section_name) \
	__attribute__((unused, section(".ll_entry_"#section_name)))

/* ll_entry_el(type, array_name, element_name)
   ll_entry_terminator(type, array_name, element_name)

   is used to declare a linker-generated array element
   this macro will declare the variable for you
   you can retrieve the specific element using ll_entry_get_element() later

   ll_entry_terminator() is designed for placing an element at the end of an array

   example usage:
     ll_entry_el(type, numbers, special_number) = 12;
*/
#define ll_entry_el(type, array_name, element_name) \
	type _ll_entry_##array_name##_##element_name \
			__attribute__((unused, section(".ll_entry_"#array_name"_2_"#element_name)))
			//__ll_entry_attrib(#array_name"_2_"#element_name)
#define ll_entry_terminator(type, array_name, element_name) \
	type _ll_entry_##array_name##_##element_name \
			__attribute__((unused, section(".ll_entry_"#array_name"_3_"#element_name)))
			//__ll_entry_attrib(array_name"_3_"#element_name)

/* _ll_entry_el(array_name)
   _ll_entry_terminator(array_name)

   is used to TAG a variable as a member of a linker-generated array
   this marco will not declare the variable for you
   you can't retrieve the specific element later

   _ll_entry_terminator() is designed for placing an element at the end of an array

   example usage:
     int myInt _ll_entry_el(numbers) = 10;
*/
#define _ll_entry_el(array_name) \
	__attribute__((unused, section(".ll_entry_"#array_name"_2")))
	//__ll_entry_attrib(array_name"_2")
#define _ll_entry_terminator(array_name) \
	__attribute__((unused, section(".ll_entry_"#array_name"_3")))
	//__ll_entry_attrib(array_name"_3")

/* ll_entry_get_array(array_name)

   is used to get the first element of a linker-generated array
   this macro is for use within a function, as it is not valid at file-scope
   for file-scope access, see _ll_entry_get_array()

   example usage:
     int *x = ll_entry_get_array(numbers);
*/
#define ll_entry_get_array(array_name) \
	({ \
		static char a[0] __attribute__((unused, section(".ll_entry_"#array_name"_1"))); \
		(void*)&a; \
	})

/* _ll_entry_get_array(array_name)

   is used to declare an access variable for the array
   this macro should be used at file-scope, as ll_entry_get_array() is invalid there

   example usage:
     _ll_entry_get_array(int, numbers, numberArray);

     void func(void) {
       printf("number[0]: %d\n", numberArray[0]);
     }
*/
#define _ll_entry_get_array(type, array_name, variable_name) \
	static char __ll_entry_##variable_name[0] __attribute__((unused, section(".ll_entry_"#array_name"_1"))) \
	type *variable_name = (type*)&__ll_entry_##variable_name;
#define _ll_entry_get_array_static(type, array_name, variable_name) \
	static char __ll_entry_##variable_name[0] __attribute__((unused, section(".ll_entry_"#array_name"_1"))) \
	static type *variable_name = (type*)&__ll_entry_##variable_name;

/* ll_entry_get_element(type, array_name, element_name)

   is used to retrieve the address of a specific element
   the element must have been declared using ll_entry_el()

   example usage:
     int *el = ll_entry_get_element(int, numbers, special_number);
*/
#define ll_entry_get_element(type, array_name, element_name) \
	({ \
		extern type _ll_entry_##array_name##_##element_name; \
		(type *)&_ll_entry_##array_name##_##element_name; \
	})

/* ll_entry_get_array_end(type, array_name)

   is used to retrieve the address of the end of an array
   the pointer should not be dereferenced, but may be used for comparison

   example usage:
     int *el;
     for (el = ll_entry_get_array(array); el < ll_entry_get_array_end(numbers); el++) {
       ...
     }
*/
#define ll_entry_get_array_end(array_name) \
	({ \
		static char a[0] __attribute__((unused, section(".ll_entry_"#array_name"_4"))); \
		(void*)&a; \
	})

/* ll_entry_get_array_size(array_name)

   is used to determine the size of an array IN BYTES

   example usage:
     size_t sz = ll_entry_get_array_size(numbers);
*/
#define ll_entry_get_array_size(array_name) \
	({ \
		void *s = ll_entry_get_array(array_name); \
		void *e = ll_entry_get_array_end(array_name); \
		size_t size = e - s; \
		size; \
	})

/* ll_entry_get_array_length(type, array_name)

   is used to determine the number of elements in an array

   example usage:
     int count = ll_entry_get_array_length(int, numbers);
*/
#define ll_entry_get_array_length(type, array_name) \
	({ \
		size_t len = ll_entry_get_array_size(array_name); \
		len /= sizeof(type); \
		len; \
	})

#endif /* __LINKER_LIST_H__ */

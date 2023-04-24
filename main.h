#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_DASH 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZE */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - is a data structure
 * @frmt: the format
 * @fn: function pointer
 */
struct frmt
{
char frmt;
int (*fn))(va_list, char[], int, int, int, int);
};
typedef struct frmt frm_t;
int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i, va_listlist,
char buffer[], int flags, int width,
int precision, int size);                         /* FUNCTION PROTOTYPES*/
int print_char(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
/*function to print numbers*/
int print_int(va_list coversions, char buffer[], int flags,
int width, int precision, int size);
int print_binary(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list conversions, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
/**function to print memory address*/
int print_pointer(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
/*functions to handle othe  specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
/**function to print a string in reverse*/
int print_reverse(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
/**function to print a string in rot 13*/
int print_rot13string(va_list conversions, char buffer[],
int flags, int width, int precision, int size);
/** withd handler*/
int write_char(char c, char buffer[], int flags, int width,
int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char buff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width,
int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);
/**UTILS*/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
#endif /*MAIN_H*/

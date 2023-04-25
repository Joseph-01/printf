#include "main.h"
/***
  * handle_print - Prints an argument based on its type
  * @fmt: Formatted string in which to print the arguments.
  * @args: List of arguments to be p i
  * @ind: ind.
  * @buffer: Buffer array to handle print.
  * @flags: Calculates active flags
  * @width: get width.
  * @precision: Precision specification
  * @size: Size specifier
  * Return: 1 or 2;
  */
int print_handler(const char *frmt, int *ind, va_list args, char buffer[],
int flags, int width, int precision, int size)
{
int i, unknow_len = 0, printed_chars = -1;
frmt_t frmt_conversions[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (i = 0; frmt_conversions[i].frmt != '\0'; i++)
if (frmt[*ind] == frmt_conversions[i].frmt)
return (frmt_conversions[i].fn(args, buffer, flags, width, precision, size));
if (frmt_conversions[i].frmt == '\0')
{
if (frmt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (frmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (frmt[*ind] != ' ' && frmt[*ind] != '%')
--(*ind);
if (frmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &frmt[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}

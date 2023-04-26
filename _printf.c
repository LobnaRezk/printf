#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
convert_match print [] = {
{"%s", printf_string}, {"%c", printf_char},
{"%%", printf_37},
{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
{"%S", printf_exclusive_string}, {"%p", printf_pointer}
};
int i, j, len = 0;
va_list ap;
va_start(ap, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
Here:
for (i = 0; format[i] != '\0'; i++)
{
for (j = 13; j >= 0; j--)
{
if (print[j].specifiers[0] == format[i]
&& print[j].specifiers[1] == format[i + 1])
{
len += print[j].f(ap);
i = i + 2;
goto Here;
}
}
putchar(format[i]);
len++;
i++;
}
va_end(ap);
return (len);
}

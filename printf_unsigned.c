#include "main.h"
#include <ctype.h>
/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
for (; num > 0; num /= 10)
buffer[i--] = (num % 10) + '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width,
int precision, int size)
{
int length = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0);/* printf(".0d", 0)  no char is printed */
if (precision > 0 && precision < length)
padd = ' ';
for (; precision > length; length++)
buffer[--ind] = '0';
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (i = 0; i < width - length; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
}
else /* Asign extra char to left of padding [padd>buffer]*/
{
return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}

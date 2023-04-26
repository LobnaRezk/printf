#include "main.h"
/**
 * printf_char - prints a char.
 * @ap: argument of function printf_char
 * Return: 1.
 */
int printf_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	putchar(c);
	return (1);
}

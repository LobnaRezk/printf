#include "main.h"
#include "holberton.h"
/**
 * printf_string - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int printf_string(va_list val)
{
char *ch;
int j, length;
ch = va_arg(val, char *);
if (ch == NULL)
{
ch = "(null)";
length = _strlen(ch);
j = 0;
while (j < length)
{
_putchar(ch[j]);
j++;
}
return (length);
}
else
{
length = _strlen(ch);
j = 0;
while (j < length)
{
_putchar(ch[j]);
j++;
}
return (length);
}

}

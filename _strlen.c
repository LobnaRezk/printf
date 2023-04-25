#include "main.h"
#include<stdio.h>
/**
 *  _strlen -   function that returns the length of a stringe
 * @s: input of function is pointer
 * Return: return length of a string
 */
int _strlen(char *s)
{
int len = 0;
while (*s != '\0')
{
len++;
s++;
}
return (len);
}

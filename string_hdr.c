#include "main.h"

/**
 * dup_str - returns a pointer to a temply allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @string: pointer to a string
 * Return: pointer string
 */
char *dup_str(char *string)
{
	char *temp;
	int i, m;

	if (!string)
	{
		return (NULL);
	}
	m = 0;
	while (string[m] != '\0')
	{
		m++;
	}
	temp = malloc(sizeof(char) * m + 1);
	if (!temp)
	{
		return (NULL);
	}
	for (i = 0; i < m; i++)
	{
		temp[i] = string[i];
	}
	temp[m] = '\0';
	return (temp);
}

/**
 * str_copy - copy a string
 * @dest: destination buffer
 * @src: source buffer
 *
 * Description: copies the string pointed to by @src
 *
 * Return: pointer to @dest
 */
char *str_copy(char *dest, char *src)
{
	char *to = dest; /* save the address of dest */

	for (; (*to = *src); src++, to++)
		;
	return (dest);
}

/**
 * concatenate - concats 3 strings in a newly allocated memory
 * @str1: first string
 * @str2: second string
 * @str3: Third string
 * Return: pointer to the new string
 */
char *concatenate(char *str1, char *str2, char *str3)
{
	char *result;
	int lenth1, length2, length3, i, k;

	lenth1 = str_len_func(str1);
	length2 = str_len_func(str2);
	length3 = str_len_func(str3);

	result = malloc(lenth1 + length2 + length3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; str1[i]; i++)
		result[i] = str1[i];
	k = i;

	for (i = 0; str2[i]; i++)
		result[k + i] = str2[i];
	k = k + i;

	for (i = 0; str3[i]; i++)
		result[k + i] = str3[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

/**
 * str_len_func - it gives the length of a string
 * @str: pointer to the string
 * Return: the length of string
 */
int str_len_func(char *str)
{
	int i = 0;

	for ( ; *(str + i) != '\0'; i++)
		;

	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstr - prints a string
 * @string: pointer to string
 */

void _printstr(char *string)
{
	int i = 0;

	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
}

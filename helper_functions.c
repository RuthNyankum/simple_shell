#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success, returns the number of characters printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printstr - Prints a string to stdout
 * @str: The string to be printed
 * Return: On success the number of characters printed.
 */
int _printstr(char *str)
{
	int n = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (str[n])
	{
		_putchar(str[n]);
		n++;
	}
	return (n);
}

/**
 * _strdup - dupplicate a string and returns it
 * @str: the string to be duplicated
 * Return: on success the duplicated string
 */
char *_strdup(char *str)
{
	size_t length = _strlen(str) + 1;
	char *str_cp = NULL;

	str_cp = malloc(length);
	if (str_cp != NULL)
	{
		str_cp = _memcpy(str_cp, str, length);
		/*Copy the content of the input string to the duplicate*/
	}
	return (str_cp);
}
/**
 * _memcpy - copies the content at a memory location
 * @dest: destination memory
 * @src: source memory where is copied from
 * @n: number of bytes to be copied
 * Return: copied dest memory with n bytes
 */
char *_memcpy(char *dest, char *src, size_t n)
{
	size_t i = n, r = 0;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @str: the string
 * Return: returns the length of str
 */
size_t _strlen(char *str)
{
	size_t str_len = 0;

	while (*str != '\0')
	{
		str_len++;
		str++;
	}

	return (str_len);
}


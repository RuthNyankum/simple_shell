#include "main.h"
/**
 * _free - frees array
 * @argv: array
 *
 * Return: nothing
 */
void _free(char **argv)
{
	int i = 0;

	for (; argv[i]; i++)
		free(argv[i]);
	free(argv);
}

/**
 * *_strcat - concatenates @src to @dest
 * @src: the source string to append
 * @dest: the destination
 * Return: pointer to string resulted
 */
char *_strcat(char *dest, char *src)
{
	int index = 0;
	int dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];

	dest[dest_len] = '\0';
	return (dest);
}

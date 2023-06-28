#include "main.h"
/**
 * string_tokenize - parses a string into an array of
 * smaller strings
 * @lineptr: the string to be tokenized
 * @argv: command line argument which will store the tokens
 * Return - returns argv
 */
char **string_tokenize(char *lineptr, char **argv)
{
	char *lineptr_cp = NULL, *token;
	size_t token_count = 0;
	char *delim = " \n\t";
	int i;

	/*Dynamic memory allocation */
	/*copying the string read by getline*/
	lineptr_cp = _strdup(lineptr);
	/*starting Tokenisation*/
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	/*Memory Allocation for the array that will hold tokenized strings */
	argv = malloc(sizeof(char *) * (token_count + 1));
	if (argv == NULL)
	{
		perror("argv: memory allocation failled");
	}
	/* Store each token in the argv array */
	token = strtok(lineptr_cp, delim);
	for (i = 0; token != NULL; i++)
	{
		/*Memory alloc for the array that will hold each token*/
		argv[i] = malloc(sizeof(char) * _strlen(token));
		/*strcpy(argv[i], token);*/
		argv[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_cp);
	return (argv);
}


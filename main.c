#include "main.h"
/**
* main - this is the main function my main
* @ac: arguments counts
* @argv: command line arguments
* Return: 0
*/
int main(int ac __attribute__((unused)), char **argv)
{
	char *prompt = "$ ", *lineptr = NULL;
	size_t n = 0;
	pid_t mypid;

	while (2)
	{
		if (isatty(STDIN_FILENO))
			_printstr(prompt);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(EXIT_FAILURE);
		}
		argv = string_tokenize(lineptr, argv);
		if (argv)
		{
			mypid = fork();
			if (mypid == -1)
				perror("unable to fork");
			else if (mypid == 0)
				execmd(argv);
			else
				wait(NULL);
		}
		else
		{
			perror("argv mem alloc failed");
			free(lineptr);
			_free(argv);
			argv = NULL;
			return (-1);
		}
	}
	free(lineptr);
	_free(argv);
	argv = NULL;
	return (0);
}

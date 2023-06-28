#include "main.h"
/**
* main - this is the main function my main
* @ac: arguments counts
* @argv: command line arguments
* Return - 0
*/
int main(int ac, char **argv)
{
	char *prompt = "$ ", *lineptr = NULL;
	size_t n = 0;
	ssize_t count_char;
	pid_t mypid;
	(void) ac;

	while (2)
	{
		_printstr(prompt);
		count_char = getline(&lineptr, &n, stdin);
		if (count_char == -1)
		{
			_printstr("Exiting shell ...\n");
			free(lineptr);
			return (-1);
		}
		argv = string_tokenize(lineptr, argv);
		if (argv)
		{
			mypid = fork();
			if (mypid == -1)
			{
				perror("unable to fork");
			}
			else if (mypid == 0)
			{
				execmd(argv);
			}
			else
			{
				wait(NULL);
			}
		}
		else
		{
			perror("argv mem alloc failed");
			free(lineptr);
			free(argv);
			return (-1);
		}
	}
	free(lineptr);
	free(argv);
	return (0);
}

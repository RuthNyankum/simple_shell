#include "main.h"
/**
* execmd -this function executes a command
* @argv: command line argument
* Return - no return
*/
void execmd(char **argv)
{
	char *command = NULL, *real_command = NULL;

	if (argv)
	{
		command = argv[0];
		/*assign the actual path to the real_command variable*/
		/*if (strcmp(command,"exit") == 0)*/
		/*exit (0);*/
		/*else*/
		real_command = get_location(command);
		if (execve(real_command, argv, environ) == -1)
		{
			perror("Error:");
		}
	}
}


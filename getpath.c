#include "main.h"
/**
 * get_location - gets the location of the command file
 * @command: the command to be located
 *
 * Return: returns the command path if it exists
 */
char *get_location(char *command)
{
	char *path, *path_cp = NULL, *path_token = NULL;
	char *file_path = NULL;
	size_t command_lenght;
	int directory_lenght;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_cp = _strdup(path);
		command_lenght = _strlen(command);
		path_token = strtok(path_cp, ":");
		while (path_token != NULL)
		{
			directory_lenght = _strlen(path_token);
			file_path = malloc(command_lenght + directory_lenght + 2);
			_strcat(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)/*testing the path we created exists*/
			{
				free(path_cp);
				return (file_path);
			}
			else/* let's check the next path*/
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cp);/* checking the command it's self */
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}


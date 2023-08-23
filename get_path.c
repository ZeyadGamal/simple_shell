#include "shell.h"

/**
 * get_PATH - gets path of a command
 * @command: command entered
 *
 * Return: the path
 */
char *get_PATH(char *command)
{
	char *path, *path_duplicate, *path_token, *file_path;
	int command_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_duplicate = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_duplicate, ":");

		while (path_token)
		{
			dir_len = strlen(path_token);
			file_path = malloc(command_len + dir_len + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_duplicate);
				return (file_path);
			}
			free(file_path);
			path_token = strtok(NULL, ":");
		}
		free(path_duplicate);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}

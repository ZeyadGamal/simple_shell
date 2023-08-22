#include "shell.h"

/**
 * execute_command - uses execve to execute command
 * @argv: commands
 */
void execute_command(char **argv)
{
	pid_t child_process;
	char *command = NULL;
	char *command_actual = NULL;
	int status;

	if (argv)
	{
		command = argv[0];
		command_actual = get_path(command);

		if (strcmp(command, "exit") == 0)
		{
			printf("Exiting Shell\n");
			exit(0);
		}
		if (command_actual)
		{
			child_process = fork();
			if (child_process == -1)
			{
				exit(EXIT_FAILURE);
			}
			if (child_process == 0)
			{

				if (execve(command_actual, argv, NULL) == -1)
				{
					printf("%s: No such file or directory\n", command);
				}
			}
			else
				wait(&status);
		}
		else
		{
			printf("Error");
		}
	}
}

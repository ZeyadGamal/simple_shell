#include "shell.h"

/**
 * execute_command - uses execve to execute command
 * @av: commands
 * @envp: environmental variables
 * @comm: argv[0]
 * @str: string
 */
void execute_command(char *av[], char *envp[], char *comm, char **str)
{
	pid_t child_process;
	char *command = NULL;
	char *command_actual = NULL;
	int status;

	if (av)
	{
		command = av[0];
		if (command == NULL)
			return;
		command_actual = get_PATH(command);
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
				free(*str);
				exit(0);
			}
			if (child_process == 0)
			{

				if (execve(command_actual, av, envp) == -1)
				{
					printf("%s: No such file or directory\n", comm);
				}
			}
			else
				wait(&status);
		}
		else
		{
			printf("%s: 1: %s: not found\n", comm, command);
		}
	}
}

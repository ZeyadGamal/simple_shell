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
		command_actual = get_PATH(command);

		if (command_actual)
		{
			child_process = fork();
			if (child_process == -1)
			{
				free(*str);
				exit(EXIT_FAILURE);
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
			printf("%s: command not found\n", comm);
		}
	}
}

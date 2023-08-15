#include "shell.h"

/**
 * execute_command - uses execve to execute command
 * @av: commands
 * @envp: environmental variables
 */
void execute_command(char *av[], char *envp[], char *comm)
{
	char *command = NULL;
	char *command_actual = NULL;

	if (av)
	{
		command = av[0];
		command_actual = get_PATH(command);

		if (execve(command_actual, av, envp) == -1)
		{
			printf("%s: No such file or directory\n", comm);
		}
	}
}

#include "shell.h"
#include <sys/wait.h>

/**
 * display_prompt - displays the interactive prompt
 * @argv: array of arguments
 * @envp: enviornmental variables
 */
void display_prompt(char *argv[], char *envp[])
{
	char *str;
	int i, status, j;
	size_t n = 0;
	ssize_t char_num = 0;
	pid_t child_process;
	char *av[MAX_COMM];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		char_num = getline(&str, &n, stdin);
		if (char_num == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		i = 0;

		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		av[0] = strtok(str, " ");
		j = 0;
		while (av[j])
		{
			++j;
			av[j] = strtok(NULL, " ");
		}
		child_process = fork();
		if (child_process == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_process == 0)
		{
			execute_command(av, envp, argv[0]);
		}
		else
			wait(&status);
	}
}

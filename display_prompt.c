#include "shell.h"

/**
 * display_prompt - displays the interactive prompt
 * @argv: array of arguments
 * @envp: enviornmental variables
 */
void display_prompt(char *argv[], char *envp[])
{
	char *str = NULL;
	char *str_copy = NULL;
	int i, j;
	size_t n = 0;
	ssize_t char_num = 0;
	char *av[MAX_COMM];

	while (1)
	{
		str = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		char_num = getline(&str, &n, stdin);
		if (char_num == -1)
		{
			free(str);
			exit(0);
		}
		str_copy = malloc(sizeof(char) * char_num);
		if (str_copy == NULL)
		{
			perror("Memory Allocation error");
		}
		strcpy(str_copy, str);
		i = 0;
		while (str_copy[i])
		{
			if (str_copy[i] == '\n')
				str_copy[i] = 0;
			i++;
		}
		av[0] = strtok(str_copy, " ");
		if (av[0] == NULL)
		{
			free(str);
			continue;
		}
		j = 0;
		while (av[j])
		{
			++j;
			av[j] = strtok(NULL, " ");
		}
		execute_command(av, envp, argv[0], &str_copy);
	}
}

#include "shell.h"

/**
 * display_prompt - displays the interactive prompt
 * @argv: array of arguments
 * @envp: enviornmental variables
 */
void display_prompt(char *argv[], char *envp[])
{
	char *str_temp = NULL, *av[MAX_COMM], *str;
	int i, j;
	size_t n = 0;
	ssize_t char_num = 0;

	while (1)
	{
		str_temp = NULL;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		char_num = getline(&str_temp, &n, stdin);
		if (char_num == -1)
		{
			free(str_temp);
			exit(0);
		}
		if (str_temp == NULL)
			perror("Memory Allocation error");
		str = malloc((sizeof(char) * char_num) + 1);
		if (str == NULL)
		{
			free(str);
			exit(1);
		}
		strcpy(str, str_temp);
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		av[0] = strtok(str, " ");
		if (av[0] == NULL)
		{
			free(str_temp);
			free(str);
			continue;
		}
		j = 0;
		while (av[j])
		{
			++j;
			av[j] = strtok(NULL, " ");
		}
		execute_command(av, envp, argv[0], &str);
		free(str);
		free(str_temp);
	}
}

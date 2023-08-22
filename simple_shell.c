#include "shell.h"

/**
 * main - main entry to simple shell program
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: -1
 */
int main(int argc, char **argv)
{
	char *str = NULL, *str_copy = NULL, *token;
	size_t n = 0;
	ssize_t num_chars;
	int num_tokens = 0, i;

	(void)argc;

	while (1)
	{
		printf("simple_shell $");
		num_chars = getline(&str, &n, stdin);
		if (num_chars == -1)
		{
			printf("Exiting simple_shell \n");
			return (-1);
		}
		str_copy = malloc(sizeof(char) * num_chars);
		if (str_copy == NULL)
		{
			perror("Error");
			return (-1);
		}
		strcpy(str_copy, str);
		token = strtok(str, " \n");
		while (token != NULL)
		{
			token = strtok(NULL, " \n");
			num_tokens++;
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(str_copy, " \n");
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;
		execute_command(argv);
	}
	free(str);
	free(str_copy);

	return (0);
}

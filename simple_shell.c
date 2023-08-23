#include "shell.h"
/**
 * main - main entry to the program
 * @argc: number of arguments passed
 * @argv: array of arguments
 * @envp: array of environmental variables
 *
 * Return: 1
 */
int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
		display_prompt(argv, envp);

	return (0);
}

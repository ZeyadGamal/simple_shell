#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMM 5
#define BUFFER_SIZE 1024

void display_prompt(char *argv[], char *envp[]);
char *get_PATH(char *command);
void execute_command(char *av[], char *envp[], char *comm, char **str);

#endif

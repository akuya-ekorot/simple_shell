#include "main.h"

/**
 * execute - executes command
 * @prog_name: name of the program
 * @av: arguements provided to execute
 */
void execute(char *prog_name, char **av)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
			perror(prog_name);
	}
	else
	{
		wait(&status);
	}
}

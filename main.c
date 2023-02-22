#include "main.h"

/**
 * main - simple shell. works exactly like sh
 * @ac: count of command-line arguments
 * @av: list of strings of the command-line arguments
 * @env: pointer to environment
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	char *prog_name;
	char **argv;
	int i, j;

	if (ac == 1)
	{
		loop(av[0]);
	}
	else
	{
		argv = malloc(sizeof(char *) * (ac - 1));

		if (argv == NULL)
		{
			exit(EXIT_FAILURE);
		}

		i = 0, j = 0;
		prog_name = av[i++];

		while (av[i])
		{
			argv[j++] = av[i++];
		}

		execute(prog_name, argv);
	}

	return (0);
}

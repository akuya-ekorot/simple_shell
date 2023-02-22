#include "main.h"

/**
 * prompt - displays prompt, reads and returns user input
 *
 * Return: string of characters read from stdin
 */
static char *prompt(void)
{
	char *line;
	size_t size;
	ssize_t size_read;

	/* initialize line and size. getline() will handle memory allocation */
	line = NULL, size = 0;

	printf("($) ");
	size_read = getline(&line, &size, stdin);

	if (size_read == -1)
		exit(EXIT_FAILURE);
	else if (strcmp(line, "exit\n") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	else
		return (line);
}

/**
 * get_av - splits line into tokens and returns NULL terminated list of strings
 * @line: input from user in interactive mode
 *
 * Return: NULL terminated list of tokens
 */
static char **get_av(char *line)
{
	int ac, i;
	char **av, *token;

	ac = 0;
	av = malloc(sizeof(char *) * 2);
	av[ac] = malloc(sizeof(char) * 64);
	av[ac++] = strtok(line, " \n");

	while (true)
	{
		av = realloc(av, (ac + 1) * sizeof(char *));
		av[ac] = malloc(sizeof(char) * 64);
		av[ac] = strtok(NULL, " \n");

		if (av[ac] == NULL)
			break;

		ac++;
	}

	av[ac] = NULL;

	return (av);
}

/**
 * loop - infinity loop to create prompt and read input from user
 */
void loop(char *prog_name)
{
	char *line, **av;

	while (true)
	{
		line = prompt();
		av = get_av(line);
		/* TODO: get environment */
		execute(prog_name, av);
	}
}

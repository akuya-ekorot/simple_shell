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
	else
		return (line);
}

/**
 * loop - infinity loop to create prompt and read input from user
 */
void loop(void)
{
	char *line, **av, *token;
	int ac;

	while (true)
	{
		line = prompt();

		/* check if line is "exit" and exits the program if so */
		if (strcmp(line, "exit\n") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		/* split line into tokens */
		ac = 0;

		token = strtok(line, " \t\r\n");

		av = malloc(sizeof(char *));

		while (token != NULL)
		{
			av = realloc(av, (ac + 1) * sizeof(char *));
			av[ac] = token;
			ac++;
			token = strtok(NULL, " \t\r\n");
		}

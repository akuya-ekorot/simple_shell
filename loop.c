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

	line = NULL, size = 0;

	printf("($) ");
	size_read = getline(&line, &size, stdin);

	if (size_read == -1)
		exit(EXIT_FAILURE);
	else
		return (line);
}

/**
 * loop - infinity loop to create prompt
 */
void loop(void)
{
	char *line;

	while (true)
	{
		line = prompt();
	}
}


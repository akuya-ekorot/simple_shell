#include "main.h"

/**
 * get_help - function that retrieves help messages according to builtin
 * @datash: data structure
 *
 * Return: 0
 */
int get_help(data_shell *datash)
{
	char *data = datash->args[1];

	if (data == 0)
		aux_help_general();
	else if (_strcmp(data, "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(data, "env") == 0)
		aux_help_env();
	else if (_strcmp(data, "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(data, "help") == 0)
		aux_help();
	else if (_strcmp(data, "exit") == 0)
		aux_help_exit();
	else if (_strcmp(data, "cd") == 0)
		aux_help_cd();
	else if (_strcmp(data, "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, datash->args[0], _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}

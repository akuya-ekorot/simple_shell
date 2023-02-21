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

	/**
	 * check if environment variables have been passed
	 * this determines whether we run the program in
	 * interactive mode or non-interactive mode.
	 */
	if (ac == 1)
	{
		/* interactive mode */

		/**
		 * program goes into a loop
		 * prints a prompt and reads input from stdin
		 */
		loop();
	}
	else
	{
		/* non-interactive mode */
	}

	return (0);
}

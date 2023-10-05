#include "simple_shell.h"

/**
 * exit_error - Function that print error and exits
 * @av: argument vetor
 * @stat: exit status
 */

void exit_error(char *av, int stat)
{
	(void)stat;
	perror(av);
	exit(0);
}

/**
 * our_exit - Function that handles the exit cmd.
 * @args: arguments taken.
 * @env: env vars
 * Return: success: 1
 */
int our_exit(char **args, char **env)
{
	int stat;
	(void)env;

	stat = 0;
	if (args[1])
		stat = _atoi(args[1]);/*convert to integer*/
	clear_array(args);
	exit(stat);
}


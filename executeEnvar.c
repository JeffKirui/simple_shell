#include "simple_shell.h"

/**
 * executeEnvVar - Function that prints environment variables
 * @args: array of arguments
 * @env: array of environment variables
 * Return: 1 (Success)
 */
int executeEnvVar(char **args, char **env)
{
	int len, index = 0;

	while (env[index])
	{
		len = my_strlen(env[index]);/*calculate the string length*/
		write(STDOUT_FILENO, env[index], len);
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	clear_array(args);
	return (1);
}


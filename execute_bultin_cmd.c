#include "simple_shell.h"

/**
 * execute_builtin_cmd - Function that executes built-in commands
 * @args: array of arguments
 * @env: array of env vars
 * Return: 1 (Success)
 */
int execute_builtin_cmd(char **args, char **env)
{
	built_cmd funcs[] = {
		{"env", executeEnvVar},
		{"exit", our_exit},
		{NULL, NULL}
	};
	int index;

	if (args[0] == NULL)/*check for errors*/
		return (0);
	for (index = 0; index < 2; index++)
	{
		if (strn_cmp(args[0], funcs[index].cmd) == 0)
		{
			return (funcs[index].f(args, env));
		}
	}
	return (0);
}

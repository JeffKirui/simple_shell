#include "simple_shell.h"

/**
 * get_env - Function that gets environment variables
 * @var_name: environment variable name
 * @env: list of environment variables
 * Return: pointer to environment variable
 */
char *get_env(const char *var_name, char **env)
{
	int index = 0, y = 0;
	int len, result;

	while (env[index] != NULL)
	{
		result = str_cmp(var_name, (const char *)env[index]);
		if (result == 1)
		{
			len = my_strlen(env[index]);
			while (env[index][y] != '=')
				y++;
			len -= y;
			return (env[index] + y + 1);
		}
		index++;
	}
	return (NULL);
}


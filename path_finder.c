#include "simple_shell.h"

/**
 * path_finder - Function that checks if cmd is in path dir.
 * @s: strings checked
 * @env: env variables
 */
void path_finder(char **s, char **env)
{
	char *s1, *s2, *path;
	int index, current, link;

	s1 = string_concat("/", s[0]);
	path = get_env("PATH", env);
	if (path == NULL)
	{
		free(s1);
		exit(0);
	}
	current = index = link = 0;
	while (path[index])
	{
		if (path[index] == ':' || path[index + 1] == '\0')
		{
			if (path[index + 1] == '\0')
			{
				index++;
				link = 1;
			}
			else
				path[index] = '\0';
			s2 = string_concat(path + current, s1);
			if (access(s2, F_OK) == 0)
			{
				free(s[0]);
				s[0] = s2;
				free(s1);
				return;
			}
			free(s2);
			if (link)
				break;
			path[index] = ':';
			current = index + 1;
		}
		index += 1;
	}
	free(s1);
}




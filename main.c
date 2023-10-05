#include "simple_shell.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: list of arguments
 * @env: list of env vars
 * Return: Always 0 (Success)
 */

int main(int ac, char *av[], char **env)
{
	char *pointer = NULL;
	char **s = NULL;
	int status;
	pid_t ppid;
	(void)ac;
	/*create a loop using while*/
	while (1)
	{
		pointer = NULL;
		signal(SIGINT, prompt_signal);
		if (prompt(&pointer) == -1)
			continue;
		s = _strntok(pointer);
		if (!s)
		{
			clear_string(99, 1, pointer);
			continue;/*memory management*/
		}
		clear_string(99, 1, pointer);
		if (execute_builtin_cmd(s, env))
			continue;
		ppid = fork();
		if (ppid == 0)
		{
			path_finder(s, env);
			if (execve(s[0], s, NULL) == -1)
			{
				perror(*av);
				clear_array(s);
				exit(0);
			}
		}
		else
		{
			clear_array(s);
			if (!wait(&status))
				break;
		}
	}
	return (0);
}

#include "simple_shell.h"

/**
 * prompt - Function that prompts commands from our user
 * @pointer: string of commands
 * Return: 1 (Success)
 */

int prompt(char **pointer)
{
	size_t buf = 0;
	int result;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	result = getline(pointer, &buf, stdin);
	if (result == EOF)
		clear_string(-1, 1, *pointer);
	(*pointer)[result - 1] = '\0';
	if (*(*pointer) == '\0' || (*(*pointer) == '.' && (*pointer)[1] == '\0'))
	{
		clear_string(99, 1, *pointer);
		return (-1);
	}
	else
		return (1);
}

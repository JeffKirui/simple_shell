#include "simple_shell.h"

/**
 * prompt_signal - Displays  prompt on ctrl+C.
 * @sign: signal number
 */
void prompt_signal(int sign)
{
	if (sign == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "$ ", 2);
	}
}

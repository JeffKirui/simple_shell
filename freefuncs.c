#include "simple_shell.h"


/**
 * clear_array - Function that frees array pointers
 * @ar: pointer array
 */
void clear_array(char **ar)
{
	int index = 0;

	if (!ar)
		exit(0);

	while (ar[index])
	{
		free(ar[index]);
		index++;/*increment index*/
	}
	free(ar);
}

/**
 * clear_string - frees strings.
 * @stat: exit status.
 * @n: the number of strings to free
 */
void clear_string(int stat, const unsigned int n, ...)
{
	unsigned int index;
	va_list args;
	char *pointer;

	va_start(args, n);


	for (index = 0; index < n; index++)
	{
		pointer = va_arg(args, char *);/*takes a character argument*/
		free(pointer);
	}

	va_end(args);
	if (stat == 99)
		return;
	exit(0);
}


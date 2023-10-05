#include "simple_shell.h"

/**
 * word_length - Function that counts the number of words in string
 * @s: pointer to the string
 * Return: number of words in string
 */

int word_length(char *s)
{
	unsigned int length, i;
	int word_count;

	if (s == NULL || *s == '\0')
		return (-1);

	word_count = i = length = 0;

	if (s[1] == '\0' && *s == ' ')
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i + 1] == '\0')
		{
			if (s[i] != ' ')
				word_count = 1;
			if (word_count)
			{
				length += 1;
				word_count = 0;
			}
			i += 1;
			continue;
		}
		else
			word_count = 1;
		i += 1;
	}
	return (length);
}

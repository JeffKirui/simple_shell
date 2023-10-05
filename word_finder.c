#include "simple_shell.h"

/**
 * word_finder - Function that gets a word from a string
 * @words: array of words
 * @s: pointer to the string
 * Return: array of words
 */
void word_finder(char **words, char *s)
{
	int i, current, word_count, length;

	length = i = current = word_count = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i + 1] == '\0')
		{
			if (s[i] != ' ')
			{
				i += 1;
				word_count = 1;
			}
			if (word_count)
			{
				string_cpy(i - current, s + current, words + length);
				if (!(words + length))
					exit(0);
				length += 1;
				current = i + 1;
				word_count = 0;
			}
			if (s[i] == '\0')
				continue;
			i += 1;
			current += 1;
			continue;
		}
		else
		{
			if (!word_count)
				current = i;
			word_count = 1;
		}
		i += 1;
	}
	words[length] = NULL;
}

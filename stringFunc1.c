#include "simple_shell.h"

/**
 * _strntok - splits a string into words
 * @s: a pointer to the string
 * Return: a pointer to an array
 */

char **_strntok(char *s)
{
	char **buf;
	int length;

	length = word_length(s);
	if (length <= 0)
		return (NULL);

	buf = malloc(sizeof(char *) * (length + 1));
	if (!buf)
		return (NULL);
	word_finder(buf, s);

	return (buf);
}

/**
 * string_cpy - copies a word from a string
 * @dest: the dest of the word
 * @s: the string to clip the word from
 * @mem: the array to store the word in
 */

void string_cpy(int dest, char *s, char **mem)

{
	int index;

	(*mem) = malloc(sizeof(char) * dest + 1);
	if (!(*mem))
	{
		perror("Error: malloc\n");
		free(mem);
		exit(0);
	}

	for (index = 0; index < dest; index++)
		(*mem)[index] = s[index];
	(*mem)[index] = '\0';
}

/**
 * _atoi - Function that converts a str to an int
 * @s: str checked.
 * Return: An integer
 */
int _atoi(char *s)
{
	int index, att;
	unsigned int n;

	n = index = 0;
	att = 1;
	while ((s[index] < '0' || s[index] > '9') && s[index] != '\0')
	{
		if (s[index] == '-')
			att *= -1;
		index++;
	}
	for (; s[index] != '\0' && s[index] >= '0' && s[index] <= '9'; index++)
	{
		n = n * 10 + (s[index] - '0');
	}
	n *= att;
	return (n);
}

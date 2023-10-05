#include "simple_shell.h"

/**
 * str_cmp - Function that compares 2 strngs
 * @s1: First strng
 * @s2: Second strng
 * Return: -ve value if s1 < s2, 0 if s1 == s2, else +ve
 */
int str_cmp(const char *s1, const char *s2)
{
	int index = 0;

	while (s1[index] == s2[index])
		index += 1;
	if (s1[index] == '\0')
		return (1);
	else
		return (-1);
}

/**
 * strn_cmp - Function that compares 2 strngs
 * @s1: First strng
 * @s2: Second strng
 * Return: -ve value if s1 < s2, 0 if s1 == s2, else +ve
 */
int strn_cmp(const char *s1, const char *s2)
{
	int index, total;

	for (index = 0; s1[index] != '\0' || s2[index] != '\0'; index++)
	{
		total = s1[index] - s2[index];
		if (total == 0)
			continue;
		else
			break;
	}
	if (s1[index] == '\0' || s2[index] != '\0')
		total = s1[index] - s2[index];

	return (total);
}

/**
 * my_strlen - Function that checks length of str.
 * @s: String checked
 * Return: Length of the str
 */
int my_strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}


/**
 * string_concat - Function that concatenates 2 strings
 * @s1: string1
 * @s2: string 2 to appended to string1
 * Return: pointer to the concatenated string; else NULL
 */
char *string_concat(char *s1, char *s2)
{
	char *s3;
	int x, y;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (x = 0; s1[x] != '\0'; x++)
		;
	for (y = 0; s2[y] != '\0'; y++)
		;
	s3 = malloc((sizeof(char) * x) + (sizeof(char) * y) + 1);
	if (s3 == NULL)
		exit(0);
	for (x = 0; s1[x] != '\0'; x++)
		s3[x] = s1[x];
	for (y = 0; s2[y] != '\0'; y++)
		s3[x + y] = s2[y];
	s3[x + y] = '\0';
	return (s3);
}

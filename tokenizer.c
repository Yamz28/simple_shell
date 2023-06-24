#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int itr, jtr, ktr, mtr, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (itr = 0; str[itr] != '\0'; itr++)
		if (!is_delim(str[itr], d) && (is_delim(str[itr + 1], d) || !str[itr + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (itr = 0, jtr = 0; jtr < numwords; jtr++)
	{
		while (is_delim(str[itr], d))
			itr++;
		ktr = 0;
		while (!is_delim(str[itr + ktr], d) && str[itr + ktr])
			ktr++;
		s[jtr] = malloc((ktr + 1) * sizeof(char));
		if (!s[jtr])
		{
			for (ktr = 0; ktr < jtr; ktr++)
				free(s[ktr]);
			free(s);
			return (NULL);
		}
		for (mtr = 0; mtr < ktr; mtr++)
			s[jtr][mtr] = str[itr++];
		s[jtr][mtr] = 0;
	}
	s[jtr] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

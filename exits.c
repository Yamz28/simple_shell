#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@m: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int i, j;
	char *t = dest;

	i = 0;
	while (src[i] != '\0' && i < m - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < m)
	{
		j = i;
		while (j < m)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (t);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@m: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int i, j;
	char *t = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < m)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < m)
		dest[i] = '\0';
	return (t);
}

/**
 **_strchr - locates a character in a string
 *@t: the string to be parsed
 *@a: the character to look for
 *Return: (t) a pointer to the memory area t
 */
char *_strchr(char *t, char a)
{
	do {
		if (*t == a)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}

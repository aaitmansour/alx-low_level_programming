#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat -  concatenates two strings.
 * @s1: input string
 * @s2: input sring
 * @n: number of bytes of s2
 * Return: a pointer to newly allocated space
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;

	unsigned int len1, len2, i, j;

	len1 = len2 = i = j = 0;

	while (s1 && s1[len1])
		len1++;

	while (s2 && s2[len2])
		len2++;

	if (n >= len2)
		str = malloc(sizeof(char) * (len1 + len2 + 1));
	else
		str = malloc(sizeof(char) * (len1 + n + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		str[i] = s1[i];
	}

	while (n < len2 && i < (len1 + n))
		str[i++] = s2[j++];
	while (n >= len2 && i < (len1 + len2))
		str[i++] = s2[j++];

	str[i] = '\0';

	return (str);
}

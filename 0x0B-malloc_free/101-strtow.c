#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * wordscount - counts the number of words in a string
 * @sc: string to count
 * Return: int of number of words
 */
int wordscount(char *sc)
{
	int i, num = 0;

	for (i = 0; sc[i]; i++)
	{
		if (sc[i] == ' ')
		{
			if (sc[i + 1] != ' ' && sc[i + 1] != '\0')
				num++;
		}
		else if (i == 0)
			num++;
	}
	num++;
	return (num);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 * Return: If str = NULL, str = "", or the function fails - NULL.
 * Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int i, j, k, l, n = 0, wc = 0;
	char **word;

	if (str == NULL || *str == '\0')
		return (NULL);
	n = wordscount(str);
	if (n == 1)
		return (NULL);
	word = (char **)malloc(n * sizeof(char *));
	if (word == NULL)
		return (NULL);
	word[n - 1] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			word[wc] = (char *)malloc(j * sizeof(char));
			j--;
			if (word[wc] == NULL)
			{
				for (k = 0; k < wc; k++)
					free(word[k]);
				free(word[n - 1]);
				free(word);
				return (NULL);
			}
			for (l = 0; l < j; l++)
				word[wc][l] = str[i + l];
			word[wc][l] = '\0';
			wc++;
			i += j;
		}
		else
			i++;
	}
	return (word);
}

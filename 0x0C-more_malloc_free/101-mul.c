#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * big_multiply - multiply two big number strings
 * @s1: the first big number string
 * @s2: the second big number string
 * Return: the product big number string
 */
char *big_multiply(char *s1, char *s2)
{
	char *r;
	int len1, len2, a, b, c, x;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	r = malloc(a = x = len1 + len2);
	if (!r)
		printf("Error\n"), exit(98);
	while (a--)
		r[a] = 0;

	for (len1--; len1 >= 0; len1--)
	{
		if (!_isdigit(s1[len1]))
		{
			free(r);
			printf("Error\n"), exit(98);
		}
		a = s1[len1] - '0';
		c = 0;

		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			if (!_isdigit(s2[len2]))
			{
				free(r);
				printf("Error\n"), exit(98);
			}
			b = s2[len2] - '0';
			c += r[len1 + len2 + 1] + (a * b);
			r[len1 + len2 + 1] = c % 10;

			c /= 10;
		}
		if (c)
			r[len1 + len2 + 1] += c;
	}
	return (r);
}

/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *r;
	int a, b, c;

	if (argc != 3)
		printf("Error\n"), exit(98);

	c = _strlen(argv[1]) + _strlen(argv[2]);
	r = big_multiply(argv[1], argv[2]);
	b = 0;
	a = 0;
	while (b < c)
	{
		if (r[b])
			a = 1;
		if (a)
			_putchar(r[b] + '0');
		b++;
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(r);
	return (0);
}

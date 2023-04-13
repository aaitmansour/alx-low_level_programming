#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * @s: pointer to a memory area
 * @b: a constant byte
 * @n: number of bytes of memory to be filled
 * Return: a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;

	while (i < n)
	{
		*(s + i) = b;
		i++;
	}

	return (s);
}

/**
 * _calloc - llocates memory for an array, using malloc.
 * @nmemb: number of array elements
 * @size: the size of each element
 * Return: a pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *dynamicptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	dynamicptr = malloc(size * nmemb);

	if (dynamicptr == NULL)
		return (NULL);

	_memset(dynamicptr, 0, nmemb * size);

	return (dynamicptr);
}

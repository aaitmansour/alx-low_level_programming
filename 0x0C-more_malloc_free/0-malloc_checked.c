#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory using malloc.
 * @b: input
 * Return: a pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *dynamicptr;

	dynamicptr = malloc(b);

	if (dynamicptr == NULL)
		exit(98);

	return (dynamicptr);

}

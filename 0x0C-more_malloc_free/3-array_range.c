#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers.
 * @min: minimum range value
 * @max: maximum range value
 * Return: the pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *dynamicArray;

	int i;

	if (min > max)
		return (NULL);

	dynamicArray = malloc(sizeof(int) * (max - min + 1));

	if (dynamicArray == NULL)
		return (NULL);

	i = 0;

	while (min <= max)
	{
		dynamicArray[i] = min++;
		i++;
	}

	return (dynamicArray);
}

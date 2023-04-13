#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 * Return: pointer to the newly allocated space
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *my_ptr;

	char *old_ptr;

	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));

	my_ptr = malloc(new_size);

	if (my_ptr == NULL)
		return (NULL);
	old_ptr = ptr;

	if (old_size > new_size)
	{
		for (i = 0; i < new_size; i++)
			my_ptr[i] = old_ptr[i];
	}
	if (old_size < new_size)
	{
		for (i = 0; i < old_size; i++)
			my_ptr[i] = old_ptr[i];
	}
	free(ptr);
	return (my_ptr);
}

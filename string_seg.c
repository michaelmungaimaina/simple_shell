#include "main.h"


/**
 * seg_str - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: the delimiter
 * Return: array of pointers to words
 */

char **seg_str(char *str, const char *delim)
{
	int i, k;
	char **arr;
	char *token;
	char *cpy;

	cpy = malloc(str_len_func(str) + 1);
	if (cpy == NULL)
	{
		perror(sys_env("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';

	token = strtok(cpy, delim);
	arr = malloc((sizeof(char *) * 2));
	arr[0] = dup_str(token);

	i = 1;
	k = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		arr = _realloc(arr, (sizeof(char *) * (k - 1)), (sizeof(char *) * k));
		arr[i] = dup_str(token);
		i++;
		k++;
	}
	free(cpy);
	return (arr);
}

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *old;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}
	return (new);
}

/**
 * free_arr - frees the array of pointers arv
 *@arr: array of pointers
 */

void free_arr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
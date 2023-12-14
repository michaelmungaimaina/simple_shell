#include "main.h"

/**
 * new_end_node - adds a new node at the end of a list_t list
 * @head: pointer to pointer to our linked list
 * @str: pointer to string in previous first node
 * Return: address of the new element/node
 */

path_list *new_end_node(path_list **head, char *str)
{

	path_list *tmp;
	path_list *new;

	new = malloc(sizeof(path_list));

	if (!new || !str)
	{
		return (NULL);
	}

	new->dir = str;

	new->p = '\0';
	if (!*head)
	{
		*head = new;
	}
	else
	{
		tmp = *head;

		while (tmp->p)
		{

			tmp = tmp->p;
		}

		tmp->p = new;
	}

	return (*head);
}


/**
 * path_join - creates a linked list for path directories
 * @path: string of path value
 * Return: pointer to the created linked list
 */
path_list *path_join(char *path)
{
	path_list *head = '\0';
	char *token;
	char *cpath = dup_str(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = new_end_node(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * path_search - finds the pathname of a filename
 * @filename: name of file or command
 * @head: head of linked list of path directories
 * Return: pathname of filename or NULL if no match
 */
char *path_search(char *filename, path_list *head)
{
	struct stat st;
	char *string;

	path_list *tmp = head;

	while (tmp)
	{

		string = concatenate(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_path_list - frees a list_t
 *@head: pointer to our linked list
 */
void free_path_list(path_list *head)
{
	path_list *storage;

	while (head)
	{
		storage = head->p;
		free(head->dir);
		free(head);
		head = storage;
	}

}


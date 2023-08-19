#include "linkedlist.h"

/**
 * add - adds a new node to the start of the linked list
 * @head: pointer to start of the list
 * @node: node
 * @data: data of node
 *
 * Return: pointer to new list
 */
list_t *add(list_t **head, void *node, void *data)
{
	list_t *new_list = NULL;
	new_list = malloc(sizeof(list_t));
	if (!new_list)
	{
		free(new_list);
		exit(98);
	}

	new_list->node = NULL;
	new_list->data = NULL;
	new_list->next = *head;

	if (node)
		new_list->node = node;
	if (data)
		new_list->data = data;
	*head = new_list;

	return (new_list);
}

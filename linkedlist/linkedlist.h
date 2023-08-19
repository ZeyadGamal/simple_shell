#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

/**
 * struct list_s - singly linked list
 * @node: node
 * @data: value of the node
 * @next: points to next node
 *
 * Description: singly linked list
 */
typedef struct list_s
{
	void *node;
	void *data;
	struct list_s *next;
} list_t;

list_t *add(list_t **head, void *node, void *data);

#endif

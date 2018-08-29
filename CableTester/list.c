#include "list.h"
#include <stdlib.h>

void list_init(list *l)
{
	l->head = NULL;
	l->size = 0;
	return;
}

int list_size(list *l)
{
	return l->size;
}

int list_empty(list *l)
{
	return list_size(l) == 0;
}

int list_push_front(list * l, void * data)
{
	list_node *node = (list_node *)malloc(sizeof(list_node));
	if (node == NULL)
		return -1;
	node->data = data;
	node->next = NULL;
	if (list_empty(l))
		l->head = node;
	else
	{
		node->next = l->head;
		l->head = node;
	}
	l->size++;
	return 0;
}

int list_push_back(list *l, void *data)
{
	list_node *node = (list_node *)malloc(sizeof(list_node));
	if (node == NULL)
		return -1;
	node->data = data;
	node->next = NULL;
	if (list_empty(l))
		l->head = node;
	else
	{
		list_node *n = l->head;
		while (n->next != NULL)
		{
			n = n->next;
		}
		n->next = node;
	}
	l->size++;
	return 0;
}

list_node* list_find(list *l, void *data, int (*equal)(const void *, const void *))
{
	if (list_empty(l))
		return NULL;
	list_node *n = l->head;
	do
	{
		if (equal(n->data, data))
			return n;
		n = n->next;
	} while (n != NULL);
	return NULL;
}

void list_destroy(list *l)
{
	if (list_empty(l))
		return;
	list_node *n = l->head, *temp;
	while (n != NULL)
	{
		temp = n->next;
		free(n);
		n = temp;
	}
}
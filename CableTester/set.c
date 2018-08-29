#include "set.h"
#include <stdlib.h>

void set_init(set * s)
{
	list_init(s);
}

int set_size(set * s)
{
	return list_size(s);
}

int set_empty(set * s)
{
	return list_empty(s);
}

int set_insert(set * s, void * data, int(*equal)(const void *, const void *), int(*cmp)(const void *, const void *))
{
	if (list_find(s, data, equal) != NULL)
		return 1;
	list_node *node = (list_node *)malloc(sizeof(list_node));
	if (node == NULL)
		return -1;
	node->data = data;
	node->next = NULL;
	if (list_empty(s))
	{
		s->size++;
		s->head = node;
	}
	else
	{
		s->size++;
		list_node *curr = s->head, *pre = curr;
		if (!cmp(curr->data, data))
		{
			node->next = curr;
			s->head = node;
			return 0;
		}
		while (curr != NULL && cmp(curr->data, data))
		{
			pre = curr;
			curr = curr->next;
		}
		if (curr == NULL)
		{
			pre->next = node;
			return 0;
		}
		node->next = curr;
		pre->next = node;
	}
	return 0;
}

set_node * set_find(set * s, void * data, int(*equal)(const void *, const void *))
{
	return list_find(s, data, equal);
}

void set_destroy(set * s)
{
	list_destroy(s);
}

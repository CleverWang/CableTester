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
	if (list_empty(l)) // Ϊ�յ�������
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
	if (list_empty(l)) // Ϊ�յ�������
		l->head = node;
	else
	{
		// ���뵽ĩβ
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
	l->head = NULL;
	l->size = 0;
}

void list_list_destroy(list * ll)
{
	if (list_empty(ll))
		return;
	for (list_node *node = ll->head; node != NULL; node = node->next)
	{
		list *l = (list *)node->data;
		list_destroy(l);
		free(l);
	}
	list_destroy(ll);
}

int list_erase(list * l, list_node * node)
{
	if (node == NULL)
		return 1;
	if (list_empty(l))
		return 1;
	if (node == l->head)  // Ϊͷ�ڵ㵥������
	{
		list_node *temp = l->head;
		l->head = temp->next;
		free(temp);
		l->size--;
		return 0;
	}
	list_node *nd = l->head->next, *pre = l->head;
	for (; nd != NULL; nd = nd->next)
	{
		if (nd == node)
		{
			pre->next = nd->next;
			free(nd);
			l->size--;
			return 0;
		}
		pre = nd;
	}
	return 1;
}

void * list_at(list * l, int idx)
{
	if (idx < 0 || idx >= list_size(l))
	{
		printf_s("bad list index!\n");
		return NULL;
	}
	list_node *node = l->head;
	for (int i = 0; i < idx; i++)
	{
		node = node->next;
	}
	return node->data;
}

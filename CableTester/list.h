#ifndef LIST_H
#define LIST_H

struct list_element;
typedef struct list_element *list_next_type;
typedef struct list_element
{
	void* data;
	list_next_type next;
} list_node;

typedef struct
{
	int size;
	list_node* head;
} list;

void list_init(list *l);
int list_size(list *l);
int list_empty(list *l);
int list_push_front(list *l, void *data);
int list_push_back(list *l, void *data);
list_node* list_find(list *l, void *data, int(*cmp)(const void *, const void *));
void list_destroy(list *l);

#endif // !LIST_H


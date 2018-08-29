#ifndef SET_H
#define SET_H

#include "list.h"

typedef list set;
typedef list_node set_node;

void set_init(set *s);
int set_size(set *s);
int set_empty(set *s);
int set_insert(set *s, void *data, int(*equal)(const void *, const void *), int(*cmp)(const void *, const void *));
set_node *set_find(set *s, void *data, int(*equal)(const void *, const void *));
void set_destroy(set *s);

#endif // !SET_H


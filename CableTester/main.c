#include "global.h"

//int equal(const void *data1, const void *data2)
//{
//	return *(int *)data1 == *(int *)data2;
//}
//
//int cmp(const void *data1, const void *data2)
//{
//	return *(int *)data1 < *(int *)data2;
//}

void test_pin_traversal()
{
	CURRENT_SIDE = SIDE_B;
	list *T = (list *)malloc(sizeof(list));
	if (T == NULL)
		printf_s("no memory!");
	list_init(T);
	pin pins[10];
	for (int i = 0; i < 10; i++)
	{
		pins[i].number = i + 1;
		list_push_back(T, &pins[i]);
	}

	list *C = (list *)malloc(sizeof(list));
	if (C == NULL)
		printf_s("no memory!");
	list_init(C);

	list *U = (list *)malloc(sizeof(list));
	if (U == NULL)
		printf_s("no memory!");
	list_init(U);

	pin_traversal(T, C, U);

	printf_s("T: ");
	for (list_node *node = T->head; node != NULL; node = node->next)
	{
		printf_s("%d ", ((pin *)node->data)->number);
	}
	printf_s("\n\nC: { ");
	for (list_node *node = C->head; node != NULL; node = node->next)
	{
		printf_s("{ ");
		list *conn = (list *)node->data;
		for (list_node *nd = conn->head; nd != NULL; nd = nd->next)
		{
			printf_s("%d ", ((pin *)nd->data)->number);
		}
		printf_s(" }");
	}
	printf_s(" } \n\nU: ");
	for (list_node *node = U->head; node != NULL; node = node->next)
	{
		printf_s("%d ", ((pin *)node->data)->number);
	}
}

int main(int argc, char **argv)
{
	/*list *l = (list *)malloc(sizeof(list));
	list_init(l);
	printf_s("list size: %d\n", list_size(l));
	printf_s("list empty: %d\n", list_empty(l));
	int data[5] = { 2,1,5,6,2 };
	for (int i = 0; i < 5; i++)
		list_push_back(l, &data[i]);
	printf_s("after inserted!!!\n");
	printf_s("list size: %d\n", list_size(l));
	printf_s("list empty: %d\n", list_empty(l));
	list_node *node = l->head;
	while (node)
	{
		printf_s("%d ", *(int *)node->data);
		node = node->next;
	}
	printf_s("\nfind: %d\n", *(int *)list_find(l, &data[1], equal)->data);
	list_destroy(l);
	free(l);

	set *s = (set *)malloc(sizeof(set));
	set_init(s);
	printf_s("\nset size: %d\n", set_size(s));
	printf_s("set empty: %d\n", set_empty(s));
	for (int i = 0; i < 5; i++)
		set_insert(s, &data[i], equal, cmp);
	printf_s("after inserted!!!\n");
	printf_s("set size: %d\n", set_size(s));
	printf_s("set empty: %d\n", set_empty(s));
	set_node *n = s->head;
	while (n)
	{
		printf_s("%d ", *(int *)n->data);
		n = n->next;
	}
	printf_s("\nfind: %d\n", *(int *)set_find(s, &data[1], equal)->data);
	set_destroy(s);
	free(s);*/

	/*int *test = (int *)malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
		test[i] = i;
	for (int i = 0; i < 5; i++)
	{
		printf_s("%d ", test[i]);
	}*/

	/*int res = get_input_lua(3, 6, 0);
	printf_s("result: %d\n", res);
	res = get_input_lua(7, 8, 1);
	printf_s("result: %d", res);*/

	test_pin_traversal();

	return 0;
}
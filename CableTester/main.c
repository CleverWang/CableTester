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

void test_list_and_set()
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
}

void test_pin_traversal()
{
	//CURRENT_SIDE = SIDE_A; // 设置当前遍历端

	//// 待测针脚集合
	//list *T = (list *)malloc(sizeof(list));
	//if (T == NULL)
	//	printf_s("no memory!");
	//list_init(T);
	//pin pins[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	pins[i].number = i + 1;
	//	list_push_back(T, &pins[i]);
	//}

	//// 连通针脚集合
	//list *C = (list *)malloc(sizeof(list));
	//if (C == NULL)
	//	printf_s("no memory!");
	//list_init(C);

	//// 未连通针脚集合
	//list *U = (list *)malloc(sizeof(list));
	//if (U == NULL)
	//	printf_s("no memory!");
	//list_init(U);

	//// 针脚遍历
	//pin_traversal(T, C, U);

	//// 打印结果
	//printf_s("T: ");
	//for (list_node *node = T->head; node != NULL; node = node->next)
	//{
	//	printf_s("%d ", ((pin *)node->data)->number);
	//}
	//printf_s("\n\nC: { ");
	//for (list_node *node = C->head; node != NULL; node = node->next)
	//{
	//	printf_s("{");
	//	list *conn = (list *)node->data;
	//	for (list_node *nd = conn->head; nd != NULL; nd = nd->next)
	//	{
	//		printf_s("%d,", ((pin *)nd->data)->number);
	//	}
	//	printf_s("},");
	//}
	//printf_s(" } \n\nU: ");
	//for (list_node *node = U->head; node != NULL; node = node->next)
	//{
	//	printf_s("%d ", ((pin *)node->data)->number);
	//}

	//// 回收内存
	//list_destroy(T);
	//for (list_node *node = C->head; node != NULL; node = node->next)
	//{
	//	list *conn = (list *)node->data;
	//	list_destroy(conn);
	//	free(conn);
	//} // C是集合的集合，需要先回收集合内的集合
	//list_destroy(C);
	//list_destroy(U);
	//free(T);
	//free(C);
	//free(U);
}

pin *PinsA, *PinsB;
list *TestA, *TestB;
list *Short_A, *Short_B;
list *RemoveA;
list *Disconnect_A, *Disconnect_B;
list *Interconnect;
list *Temp;

int init()
{
	TestA = (list *)malloc(sizeof(list));
	TestB = (list *)malloc(sizeof(list));
	Short_A = (list *)malloc(sizeof(list));
	Short_B = (list *)malloc(sizeof(list));
	RemoveA = (list *)malloc(sizeof(list));
	Disconnect_A = (list *)malloc(sizeof(list));
	Disconnect_B = (list *)malloc(sizeof(list));
	Interconnect = (list *)malloc(sizeof(list));
	Temp = (list *)malloc(sizeof(list));
	if (TestA == NULL || TestB == NULL || Short_A == NULL || Short_B == NULL || RemoveA == NULL || Disconnect_A == NULL || Disconnect_B == NULL || Interconnect == NULL || Temp == NULL)
		return -1;
	return 0;
}

int step1()
{
	int pin_cnt = get_pin_count_lua();
	PinsA = (pin *)malloc(sizeof(pin) * pin_cnt);
	PinsB = (pin *)malloc(sizeof(pin) * pin_cnt);
	if (PinsA == NULL || PinsB == NULL)
		return -1;
	for (int i = 0; i < pin_cnt; i++)
	{
		PinsA[i].number = i + 1;
		PinsB[i].number = i + 1;
		list_push_back(TestA, &PinsA[i]);
		list_push_back(TestB, &PinsB[i]);
	}
	return 0;
}

int step2()
{
	CURRENT_SIDE = SIDE_A;
	pin_traversal(TestA, Short_A, Temp);
	list_destroy(Temp);
	for (list_node *node = Short_A->head; node != NULL; node = node->next)
	{
		list *conn = (list *)node->data;
		if (list_size(conn) == 1)
			continue;
		for (list_node *nd = conn->head->next; nd != NULL; nd = nd->next)
		{
			// TODO：移除TestA中的相应针脚

			list_push_back(RemoveA, nd->data);
		}
	}
}

int main(int argc, char **argv)
{
	test_list_and_set();
	test_pin_traversal();

	return 0;
}
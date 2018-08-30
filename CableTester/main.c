#include "global.h"

//int equal(const void *data1, const void *data2)
//{
//	return *(int *)data1 == *(int *)data2;
//}

void test_list()
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
	*/
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

void print_list(char *msg, list *l)
{
	printf_s("%s: ", msg);
	for (list_node *node = l->head; node != NULL; node = node->next)
	{
		printf_s("%d ", ((pin *)node->data)->number);
	}
	printf_s("\n");
}

void print_list_list(char *msg, list *l)
{
	printf_s("%s: { ", msg);
	for (list_node *node = l->head; node != NULL; node = node->next)
	{
		printf_s("{");
		list *conn = (list *)node->data;
		for (list_node *nd = conn->head; nd != NULL; nd = nd->next)
		{
			printf_s("%d,", ((pin *)nd->data)->number);
		}
		printf_s("},");
	}
	printf_s(" }\n");
}

int equal(const void *data1, const void *data2)
{
	return ((pin *)data1)->number == ((pin *)data2)->number;
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
	printf_s("initializing...\n\n");

	TestA = (list *)malloc(sizeof(list));
	TestB = (list *)malloc(sizeof(list));
	Short_A = (list *)malloc(sizeof(list));
	Short_B = (list *)malloc(sizeof(list));
	RemoveA = (list *)malloc(sizeof(list));
	Disconnect_A = (list *)malloc(sizeof(list));
	Disconnect_B = (list *)malloc(sizeof(list));
	Interconnect = (list *)malloc(sizeof(list));
	Temp = (list *)malloc(sizeof(list));
	if (TestA == NULL || TestB == NULL || Short_A == NULL || Short_B == NULL || RemoveA == NULL 
		|| Disconnect_A == NULL || Disconnect_B == NULL || Interconnect == NULL || Temp == NULL)
		return -1;

	list_init(TestA);
	list_init(TestB);
	list_init(Short_A);
	list_init(Short_B);
	list_init(RemoveA);
	list_init(Disconnect_A);
	list_init(Disconnect_B);
	list_init(Interconnect);
	list_init(Temp);

	STEP = "";

	return 0;
}

int step1()
{
	printf_s("step 1:\n");

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

	print_list("TestA", TestA);
	print_list("TestB", TestB);
	printf_s("\n");
	return 0;
}

int step2()
{
	printf_s("step 2:\n");

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
			list_push_back(RemoveA, nd->data);
			list_erase(TestA, list_find(TestA, nd->data, equal));
		}
	}

	print_list_list("Short_A", Short_A);
	print_list("TestA", TestA);
	print_list("RemoveA", RemoveA);
	printf_s("\n");
	return 0;
}

int step3()
{
	printf_s("step 3:\n");

	CURRENT_SIDE = SIDE_B;
	pin_traversal(TestB, Short_B, Temp);
	list_destroy(Temp);
	for (list_node *node = Short_B->head; node != NULL; node = node->next)
	{
		list *conn = (list *)node->data;
		if (list_size(conn) == 1)
			continue;
		for (list_node *nd = conn->head->next; nd != NULL; nd = nd->next)
		{
			list_erase(TestB, list_find(TestB, nd->data, equal));
		}
	}

	print_list_list("Short_B", Short_B);
	print_list("TestB", TestB);
	printf_s("\n");
	return 0;
}

int step4()
{
	printf_s("step 4:\n");

	STEP = "DisA";
	CURRENT_SIDE = SIDE_A;
	pin_traversal(TestA, Temp, Disconnect_A);
	list_destroy(Temp);
	for (list_node *node = Disconnect_A->head; node != NULL; node = node->next)
	{
		list_erase(TestA, list_find(TestA, node->data, equal));
	}

	print_list("Disconnect_A", Disconnect_A);
	print_list("TestA", TestA);
	printf_s("\n");
	return 0;
}

int step5()
{
	printf_s("step 5:\n");

	STEP = "DisB";
	CURRENT_SIDE = SIDE_B;
	pin_traversal(TestB, Temp, Disconnect_B);
	list_destroy(Temp);
	for (list_node *node = Disconnect_B->head; node != NULL; node = node->next)
	{
		list_erase(TestB, list_find(TestB, node->data, equal));
	}

	print_list("Disconnect_B", Disconnect_B);
	print_list("TestB", TestB);
	printf_s("\n");
	return 0;
}

int step6()
{
	printf_s("step 6:\n");

	CURRENT_SIDE = SIDE_A;
	for (list_node *node = RemoveA->head; node != NULL; node = node->next)
	{
		set_output((pin *)node->data);
	}

	print_list("disconnect wire jumper", RemoveA);

	for (list_node *node = RemoveA->head; node != NULL; node = node->next)
	{
		stop_output((pin *)node->data);
	}

	printf_s("\n");
	return 0;
}

int step7()
{
	printf_s("step 7:\n");

	STEP = "Inter";
	CURRENT_SIDE = SIDE_B;
	int *Cnt = (int *)malloc(sizeof(int) * list_size(TestB));
	if (Cnt == NULL)
		return -1;
	memset(Cnt, 0, sizeof(int) * list_size(TestB));
	int index = 0;
	for (list_node *node = TestB->head; node != NULL; node = node->next, index++)
	{
		set_output((pin *)node->data);
		for (list_node *nd = TestB->head; nd != NULL; nd = nd->next)
		{
			if (nd == node)
				continue;
			if (get_input((pin *)nd->data))
				Cnt[index]++;
		}
	}

	printf_s("Cnt: ");
	for (int i = 0; i < list_size(TestB); i++)
	{
		printf_s("%d ", Cnt[i]);
	}
	printf_s("\n");

	index = 0;
	for (list_node *node = TestB->head; node != NULL; node = node->next, index++)
	{
		list *inter = (list *)malloc(sizeof(list));
		if (inter == NULL)
			return -1;
		list_init(inter);
		list_push_back(inter, node->data);
		list_push_back(inter, list_at(TestA, Cnt[index]));
		list_push_back(Interconnect, inter);
	}
	free(Cnt);

	print_list_list("Interconnect", Interconnect);
	printf_s("\n");
	return 0;
}

int step8()
{
	printf_s("step 8:\n");
	print_list_list("Short_A", Short_A);
	print_list("Disconnect_A", Disconnect_A);
	print_list_list("Short_B", Short_B);
	print_list("Disconnect_B", Disconnect_B);
	print_list_list("Interconnect", Interconnect);
}

void gc()
{
	free(PinsA);
	free(PinsB);
	list_destroy(TestA);
	list_destroy(TestB);
	list_list_destroy(Short_A);
	list_list_destroy(Short_B);
	list_destroy(RemoveA);
	list_destroy(Disconnect_A);
	list_destroy(Disconnect_B);
	list_list_destroy(Interconnect);
	list_destroy(Temp);
	free(TestA);
	free(TestB);
	free(Short_A);
	free(Short_B);
	free(RemoveA);
	free(Disconnect_A);
	free(Disconnect_B);
	free(Interconnect);
	free(Temp);
}

int main(int argc, char **argv)
{
	// test_list();
	// test_pin_traversal();

	init();
	step1();
	step2();
	step3();
	step4();
	step5();
	step6();
	step7();
	step8();
	gc();


	return 0;
}
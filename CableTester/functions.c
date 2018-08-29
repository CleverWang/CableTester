#include "global.h"

int set_output(pin *p)
{
	OUTPUT_PIN = p;
	printf_s("pin %d starts output.\n", OUTPUT_PIN->number);
	return 0;
}

int stop_output(pin * p)
{
	OUTPUT_PIN = NULL;
	printf_s("pin %d stops output.\n\n", p->number);
	return 0;
}

int get_input(pin *p)
{
	int res = get_input_lua(OUTPUT_PIN->number, p->number, CURRENT_SIDE);
	printf_s("pin %d get input: %d\n", p->number, res);
	return res == 1;
}

int pin_traversal(list *T, list *C, list *U)
{
	int pin_cnt = list_size(T) + 1; // 针脚数，+1为了使下标从1开始
	int *connected_flags = (int *)malloc(sizeof(int) * pin_cnt); // 已连通标志
	if (connected_flags == NULL)
		return -1;
	memset(connected_flags, 0, sizeof(int) * pin_cnt);
	int idx = 1; // 当前针脚序号，针脚序号统一从1开始
	for (list_node *node = T->head; node != NULL; node = node->next, idx++)
	{
		if (connected_flags[idx]) // 已连通的针脚不再处理
			continue;
		set_output((pin *)node->data); // 设置当前针脚为输出模式
		list *conn = (list *)malloc(sizeof(list));
		if (conn == NULL)
			return -1;
		list_init(conn);
		int indx = 1; // 遍历针脚序号
		// 遍历其他针脚
		for (list_node *nd = T->head; nd != NULL; nd = nd->next, indx++)
		{
			if (idx == indx) // 跳过处于输出模式的针脚
				continue;
			if (get_input((pin *)nd->data)) // 是否能收到输入
			{
				connected_flags[indx] = 1; // 设置已连通标志
				list_push_back(conn, nd->data);
				// printf_s("\n\n%d\n\n", ((pin *)nd->data)->number);
			}
		}
		stop_output((pin *)node->data); // 停止输出
		if (!set_empty(conn)) // 不为空，说明有其他针脚与输出模式的针脚连通
		{
			connected_flags[idx] = 1;
			list_push_front(conn, node->data);
			// printf_s("\n\n%d\n\n", ((pin *)node->data)->number);
			list_push_back(C, conn);
			/*for (list_node *nd = conn->head; nd != NULL; nd = nd->next)
			{
				printf_s("%d ", ((pin *)nd->data)->number);
			}
			printf_s("\n");*/
		}
		else
			free(conn);
	}
	/*for (int i = 1; i < pin_cnt; i++)
		printf_s("%d ", connected_flags[i]);
	printf_s("\n");*/
	idx = 1;
	for (list_node *node = T->head; node != NULL; node = node->next, idx++)
	{
		if (!connected_flags[idx]) // 已连通标志未设置说明未连通
		{
			list_push_back(U, node->data);
		}
	}
	free(connected_flags);
	return 0;
}
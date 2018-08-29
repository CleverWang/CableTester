#include "global.h"

int set_output(pin *p)
{
	OUTPUT_PIN = p;
	printf_s("set pin %d output mode.\n", OUTPUT_PIN->number);
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
	int pin_cnt = list_size(T) + 1;
	int *connected_flags = (int *)malloc(sizeof(int) * pin_cnt);
	if (connected_flags == NULL)
		return -1;
	memset(connected_flags, 0, sizeof(int) * pin_cnt);
	int idx = 1;
	for (list_node *node = T->head; node != NULL; node = node->next, idx++)
	{
		if (connected_flags[idx])
			continue;
		set_output((pin *)node->data);
		list *conn = (list *)malloc(sizeof(list));
		if (conn == NULL)
			return -1;
		list_init(conn);
		int indx = 1;
		for (list_node *nd = T->head; nd != NULL; nd = nd->next, indx++)
		{
			if (nd == node)
				continue;
			if (get_input((pin *)nd->data))
			{
				connected_flags[indx] = 1;
				list_push_back(conn, nd->data);
				// printf_s("\n\n%d\n\n", ((pin *)nd->data)->number);
			}
		}
		if (!set_empty(conn))
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
		if (!connected_flags[idx])
		{
			list_push_back(U, node->data);
		}
	}
	free(connected_flags);
	return 0;
}
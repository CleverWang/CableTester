#ifndef LIST_H
#define LIST_H

struct list_element;
typedef struct list_element *list_next_type;
typedef struct list_element
{
	void* data; // ʹ��void*�Դ洢�������������
	list_next_type next; // ��һ�ڵ�ָ��
} list_node; // ����ڵ�

typedef struct
{
	int size; // ������
	list_node* head; // ����ͷ�ڵ�ָ��
} list; // ����

// ��ʼ������
void list_init(list *l);

// ������
int list_size(list *l);

// �����Ƿ�Ϊ��
int list_empty(list *l);

// ������ͷ�����½ڵ�
int list_push_front(list *l, void *data);

// ������ĩβ�����½ڵ�
int list_push_back(list *l, void *data);

// �������в���
list_node* list_find(list *l, void *data, int(*equal)(const void *, const void *));

// ���������е�����list_node������list��Ҫ�ֶ��ͷ�
void list_destroy(list *l);

// �Ƴ������е�ָ���ڵ�
int list_erase(list *l, list_node *node);

#endif // !LIST_H


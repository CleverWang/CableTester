#ifndef LIST_H
#define LIST_H

struct list_element;
typedef struct list_element *list_next_type;
typedef struct list_element
{
	void* data; // 使用void*以存储任意的数据类型
	list_next_type next; // 下一节点指针
} list_node; // 链表节点

typedef struct
{
	int size; // 链表长度
	list_node* head; // 链表头节点指针
} list; // 链表

// 初始化链表
void list_init(list *l);

// 链表长度
int list_size(list *l);

// 链表是否为空
int list_empty(list *l);

// 在链表开头根据数据插入新节点
int list_push_front(list *l, void *data);

// 在链表末尾根据数据插入新节点
int list_push_back(list *l, void *data);

// 在链表中查找指定数据，返回节点指针
list_node* list_find(list *l, void *data, int(*equal)(const void *, const void *));

// 移除链表中的指定节点
int list_erase(list *l, list_node *node);

// 获取链表中指定位置的数据
void *list_at(list *l, int idx);

// 销毁链表中的所有list_node，恢复list初始状态，list需要手动释放
void list_destroy(list *l);

// 销毁链表的链表
void list_list_destroy(list *ll);

#endif // !LIST_H


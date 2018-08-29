#ifndef SET_H
#define SET_H

#include "list.h"

typedef list set; // 集合实现于链表
typedef list_node set_node; // 集合节点实现于链表节点

// 初始化集合
void set_init(set *s);

// 集合长度
int set_size(set *s);

// 集合是否为空
int set_empty(set *s);

// 在集合中插入新节点
int set_insert(set *s, void *data, int(*equal)(const void *, const void *), int(*cmp)(const void *, const void *));

// 在集合中查找
set_node *set_find(set *s, void *data, int(*equal)(const void *, const void *));

//销毁集合中的所有set_node，但是set需要手动释放
void set_destroy(set *s);

#endif // !SET_H


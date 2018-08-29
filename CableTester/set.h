#ifndef SET_H
#define SET_H

#include "list.h"

typedef list set; // ����ʵ��������
typedef list_node set_node; // ���Ͻڵ�ʵ��������ڵ�

// ��ʼ������
void set_init(set *s);

// ���ϳ���
int set_size(set *s);

// �����Ƿ�Ϊ��
int set_empty(set *s);

// �ڼ����в����½ڵ�
int set_insert(set *s, void *data, int(*equal)(const void *, const void *), int(*cmp)(const void *, const void *));

// �ڼ����в���
set_node *set_find(set *s, void *data, int(*equal)(const void *, const void *));

//���ټ����е�����set_node������set��Ҫ�ֶ��ͷ�
void set_destroy(set *s);

#endif // !SET_H


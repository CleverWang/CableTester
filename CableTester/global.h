#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "list.h"
#include "set.h"
#include "pin.h"
#include "interact_with_lua.h"

// ���µ�������������+1Ϊ��ʹ����±��1��ʼ
//const int MAX_PIN_CNT = 128 + 1;

// �������˱�ʶ
enum side {SIDE_A = 0, SIDE_B = 1};

// ��ǰ���¶�
int CURRENT_SIDE;

// ��ǰ�������ģʽ�����
pin *OUTPUT_PIN;

// ���������Ϊ���ģʽ
int set_output(pin *p);

// ���������Ϊ����ģʽ
int get_input(pin *p);

// ��ű���
int pin_traversal(list *T, list *C, list *U);

#endif // !GLOBAL_H
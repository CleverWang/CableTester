#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "list.h"
#include "pin.h"
#include "cable_mock.h"
#include "functions.h"

// �������˱�ʶ
enum side { SIDE_A = 0, SIDE_B = 1 };

// ��ǰ���¶�
int CURRENT_SIDE;

// ��ǰ�������ģʽ�����
pin *OUTPUT_PIN;

// ��ǰ����
char *STEP;

#endif // !GLOBAL_H
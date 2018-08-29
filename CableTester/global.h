#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "list.h"
#include "set.h"
#include "pin.h"
#include "interact_with_lua.h"

// 线缆单侧最大针脚数，+1为了使针脚下标从1开始
//const int MAX_PIN_CNT = 128 + 1;

// 线缆两端标识
enum side {SIDE_A = 0, SIDE_B = 1};

// 当前线缆端
int CURRENT_SIDE;

// 当前处于输出模式的针脚
pin *OUTPUT_PIN;

// 将针脚设置为输出模式
int set_output(pin *p);

// 将针脚设置为输入模式
int get_input(pin *p);

// 针脚遍历
int pin_traversal(list *T, list *C, list *U);

#endif // !GLOBAL_H
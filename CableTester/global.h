#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "list.h"
#include "pin.h"
#include "cable_mock.h"
#include "functions.h"

// 线缆两端标识
enum side { SIDE_A = 0, SIDE_B = 1 };

// 当前线缆端
int CURRENT_SIDE;

// 当前处于输出模式的针脚
pin *OUTPUT_PIN;

// 当前步骤
char *STEP;

#endif // !GLOBAL_H
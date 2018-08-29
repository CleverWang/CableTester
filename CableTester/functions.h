#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// 将针脚设置为输出模式
int set_output(pin *p);

// 停止针脚的输出
int stop_output(pin *p);

// 将针脚设置为输入模式
int get_input(pin *p);

// 针脚遍历
int pin_traversal(list *T, list *C, list *U);

#endif // !FUNCTIONS_H


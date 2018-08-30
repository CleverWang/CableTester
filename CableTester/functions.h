#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// 将针脚设置为输出模式，并输出方波
int set_output(pin *p);

// 停止针脚的输出
int stop_output(pin *p);

/*
将针脚设置为输入模式，接收方波
p：接收方波的针脚
return：1收到，0未收到，-1出错
*/
int get_input(pin *p);

/*
针脚遍历
T：待测针脚集
C：待测针脚集中互相连接的针脚的集合
U：待测针脚集中独立（未相互连接）针脚的集合
*/
int pin_traversal(list *T, list *C, list *U);

#endif // !FUNCTIONS_H


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// ���������Ϊ���ģʽ�����������
int set_output(pin *p);

// ֹͣ��ŵ����
int stop_output(pin *p);

/*
���������Ϊ����ģʽ�����շ���
p�����շ��������
return��1�յ���0δ�յ���-1����
*/
int get_input(pin *p);

/*
��ű���
T��������ż�
C��������ż��л������ӵ���ŵļ���
U��������ż��ж�����δ�໥���ӣ���ŵļ���
*/
int pin_traversal(list *T, list *C, list *U);

#endif // !FUNCTIONS_H


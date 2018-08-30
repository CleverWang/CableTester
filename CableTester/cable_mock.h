#ifndef CABLE_MOCK
#define CABLE_MOCK

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

// lua�ļ���
#define FILENAME "CableTools.lua"

// ȫ��lua״̬��
lua_State *L;

// ����lua�ļ�������lua״̬��
void load_lua();

// �ر�lua״̬��
void close_lua();

/*
��������Ƿ��յ�����
out_pin���������ģʽ�����
in_pin����ǰ������ţ����Ƿ���յ�����
side��A�˻�B�ˣ�ֵ��0��ʾA�ˣ�1��ʾB��
step����ǰ���裬ֵ��"DisA"��"DisB"��"Inter", ""
return��1�յ���0δ�յ���-1����
*/
int get_input_lua(int out_pin, int in_pin, int side, char *step);

// ��ȡ�������
int get_pin_count_lua();

#endif // !INTERACTWITHLUA_H


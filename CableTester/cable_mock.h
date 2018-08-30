#ifndef CABLE_MOCK
#define CABLE_MOCK

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

// �����ļ�������lua�ļ�������lua״̬��
lua_State *load_lua_file(char *filename);

/*
��������Ƿ��յ�����
out_pin���������ģʽ�����
in_pin����ǰ�������
side��A�˻�B��
step����ǰ����
*/
int get_input_lua(int out_pin, int in_pin, int side, char *step);

// ��ȡ�������
int get_pin_count_lua();

#endif // !INTERACTWITHLUA_H


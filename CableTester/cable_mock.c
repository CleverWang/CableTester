#include "cable_mock.h"
#include <string.h>

void load_lua()
{
	L = luaL_newstate();
	luaL_openlibs(L);
	if (luaL_loadfile(L, FILENAME) || lua_pcall(L, 0, 0, 0)) {
		printf_s("load lua file failed: %s\n", lua_tostring(L, -1));
		L = NULL;
	}
}

void close_lua()
{
	lua_close(L);
}

int get_input_lua(int out_pin, int in_pin, int side, char * step)
{
	if (L == NULL)
		return -1;
	lua_getglobal(L, "get_input"); // ��ȡCableTools�е�get_input����
	lua_pushinteger(L, out_pin); // �������������
	lua_pushinteger(L, in_pin); // ������������±�
	// ����˱�־
	if (side == 0)
		lua_pushstring(L, "A");
	else if (side == 1)
		lua_pushstring(L, "B");
	// ���벽���־
	if (!strcmp(step, "DisA")) // ����Disconnect_Aʱ
	{
		lua_pushstring(L, "DisA");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else if (!strcmp(step, "DisB")) // ����Disconnect_Bʱ
	{
		lua_pushstring(L, "DisB");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else if (!strcmp(step, "Inter")) // ����Interconnectʱ
	{
		lua_pushstring(L, "Inter");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else // ��������ʱ
	{
		if (lua_pcall(L, 3, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	int result = (int)lua_tointeger(L, -1);
	return result;
}

int get_pin_count_lua()
{
	if (L == NULL)
		return -1;
	lua_getglobal(L, "get_pin_count");
	if (lua_pcall(L, 0, 1, 0) != 0)
	{
		printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
		return -1;
	}
	int result = (int)lua_tointeger(L, -1);
	return result;
}

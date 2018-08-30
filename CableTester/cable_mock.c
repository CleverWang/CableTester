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
	lua_getglobal(L, "get_input"); // 获取CableTools中的get_input函数
	lua_pushinteger(L, out_pin); // 置入输出针脚序号
	lua_pushinteger(L, in_pin); // 置入输入针脚下标
	// 置入端标志
	if (side == 0)
		lua_pushstring(L, "A");
	else if (side == 1)
		lua_pushstring(L, "B");
	// 置入步骤标志
	if (!strcmp(step, "DisA")) // 计算Disconnect_A时
	{
		lua_pushstring(L, "DisA");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else if (!strcmp(step, "DisB")) // 计算Disconnect_B时
	{
		lua_pushstring(L, "DisB");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else if (!strcmp(step, "Inter")) // 计算Interconnect时
	{
		lua_pushstring(L, "Inter");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else // 其他步骤时
	{
		if (lua_pcall(L, 3, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	int result = lua_tointeger(L, -1);
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
	int result = lua_tointeger(L, -1);
	return result;
}

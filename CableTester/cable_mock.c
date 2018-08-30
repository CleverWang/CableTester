#include "cable_mock.h"
#include <string.h>

lua_State * load_lua_file(char * filename)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	if (luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0)) {
		printf_s("load lua file failed: %s\n", lua_tostring(L, -1));
		return NULL;
	}
	return L;
}

int get_input_lua(int out_pin, int in_pin, int side, char * step)
{
	char *filename = "CableTools.lua";
	lua_State *L = load_lua_file(filename);
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
	if (!strcmp(step, "DisA"))
	{
		lua_pushstring(L, "DisA");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else if (!strcmp(step, "DisB"))
	{
		lua_pushstring(L, "DisB");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else if (!strcmp(step, "Inter"))
	{
		lua_pushstring(L, "Inter");
		if (lua_pcall(L, 4, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	else
	{
		if (lua_pcall(L, 3, 1, 0) != 0)
		{
			printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
			return -1;
		}
	}
	int result = lua_tointeger(L, -1);
	lua_close(L);
	return result;
}

int get_pin_count_lua()
{
	char *filename = "CableTools.lua";
	lua_State *L = load_lua_file(filename);
	if (L == NULL)
		return -1;
	lua_getglobal(L, "get_pin_count");
	if (lua_pcall(L, 0, 1, 0) != 0)
	{
		printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
		return -1;
	}
	int result = lua_tointeger(L, -1);
	lua_close(L);
	return result;
}

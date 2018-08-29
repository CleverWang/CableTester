#include "interact_with_lua.h"

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

int get_input_lua(int out_pin, int in_pin, int side)
{
	char *filename = "CableTools.lua";
	lua_State *L = load_lua_file(filename);
	if (L == NULL)
		return -1;
	lua_getglobal(L, "get_input");
	lua_pushinteger(L, out_pin);
	lua_pushinteger(L, in_pin);
	if (side == 0)
		lua_pushstring(L, "A");
	else if (side == 1)
		lua_pushstring(L, "B");
	if (lua_pcall(L, 3, 1, 0) != 0)
	{
		printf_s("lua_pcall failed: %s\n", lua_tostring(L, -1));
		return -1;
	}
	int result = lua_tointeger(L, -1);
	lua_close(L);
	return result;
}

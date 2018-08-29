#ifndef CABLE_MOCK
#define CABLE_MOCK

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

// 根据文件名加载lua文件，返回lua状态机
lua_State *load_lua_file(char *filename);

/*
测试针脚是否收到方波
out_pin：处于输出模式的针脚
in_pin：当前测试针脚
side：A端或B端
*/
int get_input_lua(int out_pin, int in_pin, int side);

#endif // !INTERACTWITHLUA_H


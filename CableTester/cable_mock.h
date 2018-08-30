#ifndef CABLE_MOCK
#define CABLE_MOCK

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

// lua文件名
#define FILENAME "CableTools.lua"

// 全局lua状态机
lua_State *L;

// 加载lua文件，生成lua状态机
void load_lua();

// 关闭lua状态机
void close_lua();

/*
测试针脚是否收到方波
out_pin：处于输出模式的针脚
in_pin：当前测试针脚，看是否接收到方波
side：A端或B端，值：0表示A端，1表示B端
step：当前步骤，值："DisA"，"DisB"，"Inter", ""
return：1收到，0未收到，-1出错
*/
int get_input_lua(int out_pin, int in_pin, int side, char *step);

// 获取针脚数量
int get_pin_count_lua();

#endif // !INTERACTWITHLUA_H


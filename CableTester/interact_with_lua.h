#ifndef INTERACTWITHLUA_H
#define INTERACTWITHLUA_H

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

lua_State *load_lua_file(char *filename);

int get_input_lua(int out_pin, int in_pin, int side);

#endif // !INTERACTWITHLUA_H


#include "lua_Script.h"

using namespace std;
lua_Script::lua_Script(void)
{
	L=luaL_newstate();
	lua_State *state = L;
	luaL_openlibs(L);
	//luabind::open(state);
}

lua_Script::~lua_Script(void)
{
}
//loads a lua file
void lua_Script::Load(const char* fileName){
	luaL_dofile(L, fileName);
}

void lua_Script::Close(){
	lua_close(L);
}

//reads in a int from a lua file
int lua_Script::Read_Variable_Int(const char* varName){
	lua_settop(L,0);
	lua_getglobal(L, varName);
	int intVar = (int)lua_tonumber(L, 1);
	lua_pop(L, 1);
	return(intVar);
}
//reads in a string from a lua file
string lua_Script::Read_Variable_String(const char* varName){
	lua_settop(L,0);
	lua_getglobal(L, varName);
	string stringVar = (string)lua_tostring(L, 1);
	lua_pop(L, 1);
	return(stringVar);
}
//reads in a float from a lua file
float lua_Script::Read_Variable_Float(const char* varName){
	lua_settop(L,0);
	lua_getglobal(L, varName);
	float numVar = (float)lua_tonumber(L, 1);
	lua_pop(L, 1);
	return(numVar);
}
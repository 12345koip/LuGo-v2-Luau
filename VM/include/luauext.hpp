/*
This file was created by
12345koip for the LuGo executor
on 05/01/2026. See LICENSE and README
for details.
*/

#pragma once
#include "lua.h"
#include "lualib.h"
#include "Luau/VM/src/lapi.h"

#define lua_totable(L, i) hvalue(index2addr(L, i))
#define lua_rawpush(L, o) {lua_rawcheckstack(L, 1); setobj((L), (L)->top, o); api_incr_top((L));}
#define lua_pushtable(L, t) {lua_rawcheckstack(L, 1); sethvalue((L), (L)->top, t); api_incr_top((L));}
#define luaL_refbyptr(L, p) lua_rawsetp((L), LUA_REGISTRYINDEX, (p))
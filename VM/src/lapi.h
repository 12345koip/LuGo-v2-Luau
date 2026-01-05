// This file is part of the Luau programming language and is licensed under MIT License; see LICENSE.txt for details
// This code is based on Lua 5.x implementation licensed under MIT License; see lua_LICENSE.txt for details
#pragma once

#include "lobject.h"

LUAI_FUNC const TValue* luaA_toobject(lua_State* L, int idx);
LUAI_FUNC void luaA_pushobject(lua_State* L, const TValue* o);

//no thanks, we need our index2addr.
LUAI_FUNC TValue* index2addr(lua_State* L, int idx);


//and we need these too. let's keep them all in the header.
#define api_checknelems(L, n) api_check(L, (n) <= (L->top - L->base))

#define api_checkvalidindex(L, i) api_check(L, (i) != luaO_nilobject)

#define api_incr_top(L) \
{ \
api_check(L, L->top < L->ci->top); \
L->top++; \
}

#define api_update_top(L, p) \
{ \
api_check(L, p >= L->base && p < L->ci->top); \
L->top = p; \
}

#define updateatom(L, ts) \
{ \
if (ts->atom == ATOM_UNDEF) \
ts->atom = L->global->cb.useratom ? L->global->cb.useratom(ts->data, ts->len) : -1; \
}
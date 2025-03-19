#include <SDL2/SDL.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <glib.h>

typedef struct Position {
    int x;
    int y;
    lua_State *L;
    int callback_ref;
} Position;

void Position_pushMetaTable(lua_State *L);
int Position_new(lua_State *L);
int Position_toString(lua_State *L);
int Position_index(lua_State *L);
int Position_newIndex(lua_State *L);

void Position_pushMetaTable(lua_State *L) {
    luaL_newmetatable(L, "Position");

    lua_pushcfunction(L, Position_index);
    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, Position_newIndex);
    lua_setfield(L, -2, "__newindex");

    lua_setmetatable(L, -2);
}

int Position_new(lua_State *L) {
    Position *pos = (Position *)lua_newuserdata(L, sizeof(Position));
    pos->x = luaL_checkinteger(L, 1);
    pos->y = luaL_checkinteger(L, 2);
    pos->L = L;

    Position_pushMetaTable(L);
    return 1;
}

int Position_toString(lua_State *L) {
    Position *pos = (Position *)luaL_checkudata(L, 1, "Position");
    char result[50];
    snprintf(result, sizeof(result), "Position(%d, %d)", pos->x, pos->y);
    lua_pushstring(L, result);
    return 1;
}

int Position_index(lua_State *L) {
    Position *pos = (Position *)luaL_checkudata(L, 1, "Position");
    const char *key = luaL_checkstring(L, 2);

    if (strcmp(key, "x") == 0) {
        lua_pushinteger(L, pos->x);
    } else if (strcmp(key, "y") == 0) {
        lua_pushinteger(L, pos->y);
    } else if (strcmp(key, "to_string") == 0) {
        lua_pushcfunction(L, Position_toString);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int Position_newIndex(lua_State *L) {
    Position *pos = (Position *)luaL_checkudata(L, 1, "Position");
    const char *key = luaL_checkstring(L, 2);

    if (strcmp(key, "x") == 0) {
        pos->x = luaL_checkinteger(L, 3);
    } else if (strcmp(key, "y") == 0) {
        pos->y = luaL_checkinteger(L, 3);
    } else if (strcmp(key, "callback") == 0) {
        if (lua_isfunction(L, 3)) {
            lua_pushvalue(L, 3);
            pos->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
        } else {
            luaL_error(L, "Expected a function for callback");
        }
    } else {
        luaL_error(L, "Invalid key for Position: %s", key);
    }
    return 0;
}

int main() {
    Position *pos = nullptr;
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    luaL_Reg positionLib[] = {{"new", Position_new}, {NULL, NULL}};
    luaL_newlib(L, positionLib);
    lua_setglobal(L, "Position");

    luaL_loadfile(L, "game-scripts/main.lua");
    if (lua_pcall(L, 0, 1, 0) != LUA_OK) {
        const char *error = lua_tostring(L, -1);
        printf("Error: %s\n", error);
        lua_pop(L, 1);
    } else {
        pos = (Position *)luaL_checkudata(L, 1, "Position");
        printf("Position returned from lua: (%d, %d)\n", pos->x, pos->y);
        // Call the callback function if it exists
        pos->x += 1;

        if (pos->callback_ref != LUA_NOREF) {
            lua_rawgeti(L, LUA_REGISTRYINDEX, pos->callback_ref);

            // push the position itself as an argument

            lua_pushlightuserdata(L, pos);
            Position_pushMetaTable(L);

            lua_pushinteger(L, pos->x);
            lua_pushinteger(L, pos->y);
            if (lua_pcall(L, 3, 0, 0) != LUA_OK) {
                const char *error = lua_tostring(L, -1);
                printf("Error calling callback: %s\n", error);
                lua_pop(L, 1);
            }
        }
    }

    lua_close(L);

    printf("Exiting...\n");
    return 0;
}

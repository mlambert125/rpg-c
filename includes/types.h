#include <SDL2/SDL.h>
#include <lua.h>


typedef struct TileDefinition {
    char name[255];
    bool walkable;
    SDL_Texture* texture;
    // script for default action
} TileDefinition;

typedef struct CharacterSprite {
    SDL_Texture* textureUp1;
    SDL_Texture* textureUp2;
    SDL_Texture* textureDown1;
    SDL_Texture* textureDown2;
    SDL_Texture* textureLeft1;
    SDL_Texture* textureLeft2;
    SDL_Texture* textureRight1;
    SDL_Texture* textureRight2;
} CharacterSprite;

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Enemy {
    char name[255];
    int health;
    int defense;
    int strength;
    int speed;
    int level;
    int experience;
    int gold;
    SDL_Texture* texture;
    int onInitializeCallback;
    int onFightCallback;
    int onTurnCallback;
    int onDeathCallback;
} Enemy;

typedef struct Npc {
    char name[255];
    char dialogue[10][255];
    Position startingPosition;
    Position* walkableTiles;
    int characterSpriteIndex;
    int onStartConversationCallback;
    int onEndConversationCallback;
} Npc;

typedef struct RpgMap {
    char name[255];
    int width;
    int height;
    int **tiles;
    Npc *npcs;
    int onInitializeCallback;
    int onEnterCallback;
    int onLeaveCallback;
    int onEnterTileCallback;
    int onLeaveTileCallback;
    int onStartConversationCallback;
    int onEndConversationCallback;
    int onStartBattleCallback;
    int onEndBattleCallback;
    int onExitCallback;
} RpgMap;

typedef struct Encounter {
    lua_State *L;
    int enemyIndeces[9];
    int onInitializeCallback;
    int onStartFightCallback;
    int onVictoryCallback;
    int onDefeatCallback;
} Encounter;


#include <SDL2/SDL.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <glib.h>

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
    // script for initializing the enemy (setting stats, etc.)
    // script for starting fight
    // script for taking a turn (attacks are all here)
    // script for dying (words, etc.)
} Enemy;

typedef struct Encounter {
    Enemy* enemies;
    // script for initializing the encounter (setting up enemies, etc.)
    // script for starting fight
    // script for victory (words, etc.)
} Encounter;


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

typedef struct Npc {
    char name[255];
    char dialogue[10][255];
    Position* walkableTiles;
    CharacterSprite* sprite;
    // script for starting a conversation (some kind of invocable menu here for shops, etc.)
    // script for ending a conversation
} Npc;

typedef struct RpgMap {
    char name[255];
    int width;
    int height;
    int **tiles;
    Npc *npcs;
    // script for initializing the map (setting tiles, creating npcs, etc.)
    // script for entering the map
    // script for entering a tile
    // script for leaving a tile
    // script for starting to talk to an npc
    // script for ending a conversation
    // script for starting a battle
    // script for ending a battle
    // script for exiting the map
} RpgMap;


int main() {
    return 0;
}

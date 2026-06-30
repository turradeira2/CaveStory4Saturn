#include <srl.hpp>

#define TILE_SIZE 16

#define TILE_EMPTY 0
#define TILE_SOLID 1

#define TILE_PLAYER_SPAWN '@'

enum CollisionType
{
    COL_EMPTY = 0,
    COL_SOLID = 1,
};

struct Level
{
    const uint8_t* collision;
    int width;
    int height;
};

extern Level CurrLevel;

uint8_t GetTile(int tx, int ty);

bool IsSolidPixel(int worldX, int worldY);
#include <srl.hpp>

const int TILE_SIZE = 16;

struct Level
{
    const uint8_t* Collision;
    int width;
    int height;
};

extern Level CurrLevel;

uint8_t GetTile(int tx,int ty);

enum CollisionType
{
    COL_EMPTY = 0,
    COL_SOLID,
    COL_SLOPE_UP,
    COL_SLOPE_DOWN,
    COL_SPIKES
};


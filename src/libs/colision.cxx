#include <srl.hpp>

#include "colision.h"

using namespace SRL::Types;
using namespace SRL::Math::Types;

Level CurrLevel;

uint8_t GetTile(int tx, int ty)
{
    if (tx < 0 || tx >= CurrLevel.width)
        return COL_SOLID;

    if (ty < 0 || ty >= CurrLevel.height)
        return COL_SOLID;

    return CurrLevel.collision[ty * CurrLevel.width + tx];
}

bool IsSolidPixel(int worldX, int worldY)
{
    int tileX = worldX / TILE_SIZE;
    int tileY = worldY / TILE_SIZE;

    return GetTile(tileX, tileY) == COL_SOLID;
}

/*
Tile COLISION TYPES
0 - EMPTY
1 - SOLID
2 - SLOPE UP LEFT   0,0  16,-8
3 - SLOPE UP RIGHT
4 - SLOPE DOWN LEFT
5 - SLOPE DOWN RIGHT
6 - HIGH SLOPE UP LEFT (+8 PIXEL IN HEIGHT COMPARED TO NORMAL SLOPE)
6 - HIGH SLOPE UP RIGHT (+8 PIXEL IN HEIGHT COMPARED TO NORMAL SLOPE)

8 - PLAYER SPAWN
*/
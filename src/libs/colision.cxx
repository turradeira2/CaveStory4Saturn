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

CollisionType GetCollisionAtPixel(Fxp worldX,Fxp worldY)
{
    int tx = (worldX.As<int16_t>() + 160) / TILE_SIZE;
    int ty = (worldY.As<int16_t>() + 120) / TILE_SIZE;
    return (CollisionType)GetTile(tx, ty);
    SRL::Debug::Print(1, 15,"tx=%d ty=%d",tx,ty);
}

bool IsSolidPixel(Fxp worldX, Fxp worldY)
{
    return GetCollisionAtPixel(worldX, worldY) == COL_SOLID;
    
    /*
    switch (GetCollisionAtPixel(worldX, worldY))
    {
        case COL_SOLID:
            return true;
            
        default:
            return false;
    }
    */
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

/*
return GetTile(tileX, tileY) == COL_SOLID;

    int tileX = worldX.As<int16_t>() / TILE_SIZE;
    int tileY = worldY.As<int16_t>() / TILE_SIZE;
*/
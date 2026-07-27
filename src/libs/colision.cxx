//collision.cxx

#include <srl.hpp>

#include "colision.h"

using namespace SRL::Types;
using namespace SRL::Math::Types;

LvlCollision CurrLevel;

uint8_t GetTile(int tx, int ty)
{
    if (tx < 0 || tx >= CurrLevel.width)
        return COL_SOLID;

    if (ty < 0 || ty >= CurrLevel.height)
        return COL_SOLID;

    return CurrLevel.collision[ty * CurrLevel.width + tx];
}

int GetLocalX(Fxp worldX)
{
    return (worldX.As<int16_t>() + 160) & 15;
}

int GetLocalY(Fxp worldY)
{
    return (worldY.As<int16_t>() + 120) & 15;
}

CollisionType GetCollisionAtPixel(Fxp worldX,Fxp worldY)
{
    int tx = (worldX.As<int16_t>() + 160) / TILE_SIZE;
    int ty = (worldY.As<int16_t>() + 120) / TILE_SIZE;
    return (CollisionType)GetTile(tx, ty);
}

int GetSlopeFloorY(Fxp worldX, Fxp worldY)
{
    int tx = (worldX.As<int16_t>() + 160) / TILE_SIZE;
    int ty = (worldY.As<int16_t>() + 120) / TILE_SIZE;

    CollisionType type = (CollisionType)GetTile(tx, ty);

    SRL::Debug::Print(1, 2, "tx=%d ty=%d type=%d",
        tx, ty, (int)type);

    int localX = GetLocalX(worldX);
    int tileTop = ty * TILE_SIZE - 120;

    switch (type)
    {
        case COL_SLOPE_UP_LEFT:
            return tileTop + FloorLeft[localX];

        case COL_SLOPE_UP_RIGHT:
            return tileTop + FloorRight[localX];

        default:
            return -1;
    }
}

bool IsSolidPixel(Fxp worldX, Fxp worldY)
{
    return GetCollisionAtPixel(worldX,worldY) == COL_SOLID;
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

    int tileX = worldX.As<int16_t>() / TILE_SIZE;
    int tileY = worldY.As<int16_t>() / TILE_SIZE;
*/

/*
    CollisionType type = GetCollisionAtPixel(worldX,worldY);
    int localX = GetLocalX(worldX);
    int localY = GetLocalY(worldY);
    switch (type)
    {
        case COL_SOLID:
            return true;

        case COL_SLOPE_UP_LEFT:
            return localY >= FloorLeft[localX];

        case COL_SLOPE_UP_RIGHT: 
            return localY >= FloorRight[localX];

        default:
            return false;        
    }
    */
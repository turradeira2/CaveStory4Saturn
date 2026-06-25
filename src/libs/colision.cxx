#include <srl.hpp>

#include "colision.h"

using namespace SRL::Types;
using namespace SRL::Math::Types;

Level CurrLevel = { nullptr, 0, 0 };

BoundingBox player_bounding_box;


uint8_t GetColision(int tx,int ty)
{
    if(tx<0 || tx>= CurrLevel.width)
    {
        return COL_SOLID;
    }
    
    if (ty < 0 || ty >= CurrLevel.height)
    {
        return COL_SOLID;
    }
    
    return CurrLevel.Collision[ty * CurrLevel.width + tx];
}

static inline bool IsSolid(uint8_t t)
{
    return t == COL_SOLID;
}
/*
COLISION TYPES
0 - EMPTY
1 - SOLID
2 - SLOPE UP LEFT   0,0  16,-8
3 - SLOPE UP RIGHT
4 - SLOPE DOWN LEFT
5 - SLOPE DOWN RIGHT
6 - WATER
*/
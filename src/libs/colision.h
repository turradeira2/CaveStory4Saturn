//collision.h
#include <srl.hpp>

#define TILE_SIZE 16

using namespace SRL::Math::Types;

int GetLocalX(Fxp worldX);
int GetLocalY(Fxp worldY);

int GetSlopeFloorY(Fxp worldX, Fxp worldY);

constexpr uint8_t FloorRight[16] =
{
    15,15,
    14,14,
    13,13,
    12,12,
    11,11,
    10,10,
     9, 9,
     8, 8
};

constexpr uint8_t FloorLeft[16] =
{
     8, 8,
     9, 9,
    10,10,
    11,11,
    12,12,
    13,13,
    14,14,
    15,15
};

constexpr uint8_t FloorLeftHigh[16] =
{
    0,0,
    1,1,
    2,2,
    3,3,
    4,4,
    5,5,
    6,6,
    7,7
};

constexpr uint8_t FloorRightHigh[16] =
{
    7,7,
    6,6,
    5,5,
    4,4,
    3,3,
    2,2,
    1,1,
    0,0
};

enum CollisionType
{
    COL_EMPTY = 0,
    COL_SOLID,               //1
    COL_SLOPE_UP_LEFT,       //2
    COL_SLOPE_UP_RIGHT,      //3
    COL_HIGH_SLOPE_UP_LEFT,  //4
    COL_HIGH_SLOPE_UP_RIGHT, //5
    COL_SLOPE_DOWN_LEFT,     //6
    COL_SLOPE_DOWN_RIGHT,    //7
    COL_WATER
};

struct LvlCollision
{
    const uint8_t* collision;
    int width;
    int height;
};

extern LvlCollision CurrLevel;

uint8_t GetTile(int tx, int ty);

bool IsSolidPixel(Fxp worldX, Fxp worldY);

CollisionType GetCollisionAtPixel(Fxp worldX,Fxp worldY);
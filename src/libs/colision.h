#include <srl.hpp>

//using namespace SRL::Math::Types;

#pragma region COLLISION TYPES
    //#define COL_EMPTY 0
    //#define COL_SOLID 1
    //#define SLOPE_UP_LEFT 2 
    //#define SLOPE_UP_RIGHT 3
    //#define SLOPE_DOWN_LEFT 4
    //#define SLOPE_DOWN_RIGHT 5
    //#define WATER 6
#pragma endregion

enum COLLISION_TYPES{
    COL_EMPTY = 0,
    COL_SOLID,
    SLOPE_UP_LEFT,
    SLOPE_UP_RIGHT,
    SLOPE_DOWN_LEFT,
    SLOPE_DOWN_RIGHT,
    WATER
};

#define TILE_SIZE 16

struct Level
{
    const uint8_t* Collision;
    int width;
    int height;
};

typedef struct
{
    Fxp min_X,min_Y;
    Fxp max_X,max_Y;
    Fxp width,height;
} BoundingBox;


extern Level CurrLevel;

uint8_t GetColision(int tx,int ty);


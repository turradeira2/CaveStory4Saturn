#include <srl.hpp>

#pragma region COLLISION TYPES
    #define COL_EMPTY 0
    #define COL_SOLID 1
    #define SLOPE_UP_LEFT 2 
    #define SLOPE_UP_RIGHT 3
    #define SLOPE_DOWN_LEFT 4
    #define SLOPE DOWN RIGHT 5
    #define WATER 6
#pragma endregion

const int TILE_SIZE = 16;

struct Level
{
    const uint8_t* Collision;
    int width;
    int height;
};

extern Level CurrLevel;

uint8_t GetColision(int tx,int ty);


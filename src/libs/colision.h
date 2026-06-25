#include <srl.hpp>

//using namespace SRL::Math::Types;

enum TILE_TYPES{
    COL_EMPTY = 0,
    COL_SOLID,
    SLOPE_UP_LEFT,
    SLOPE_UP_RIGHT,
    SLOPE_DOWN_LEFT,
    SLOPE_DOWN_RIGHT,
    WATER
};

#define TILE_SIZE 16
#define TILE_SIZE_FXP SRL::Math::Types::Fxp(TILE_SIZE)

struct Level
{
    const uint8_t* Collision;
    int width;
    int height;
};

struct BoundingBox
{
    //SRL::Math::
    Fxp min_X,min_Y;
    Fxp max_X,max_Y;
    Fxp width,height;
};

extern BoundingBox player_bounding_box;

extern Level CurrLevel;

uint8_t GetColision(int tx,int ty);


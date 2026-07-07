#include <srl.hpp>



#define TILE_SIZE 16

enum CollisionType
{
    COL_EMPTY = 0,
    COL_SOLID,
    COL_SLOPE_UP_LEFT,
    COL_SLOPE_UP_RIGHT,
    COL_SLOPE_DOWN_LEFT,
    COL_SLOPE_DOWN_RIGHT,
    COL_WATER
};

struct Level
{
    const uint8_t* collision;
    int width;
    int height;
};

extern Level CurrLevel;

uint8_t GetTile(int tx, int ty);

bool IsSolidPixel(SRL::Math::Types::Fxp worldX, SRL::Math::Types::Fxp worldY);

CollisionType GetCollisionAtPixel(SRL::Math::Types::Fxp worldX,SRL::Math::Types::Fxp worldY);
#include <srl.hpp>

#include "test_room.h"
#include "../libs/camera.h"
#include "../libs/colision.h"
#include "../objects/player.h"

using namespace SRL::Types;
using namespace SRL::Math::Types;
using namespace SRL::Input;
using namespace SRL::Tilemap;

#define ROOM_SIZE_X 21
#define ROOM_SIZE_Y 15


static const uint8_t Level[ROOM_SIZE_Y][ROOM_SIZE_X] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
        
    };

void LoadTileMap()
{
    SRL::Core::Initialize(HighColor(0,0,32));
    SRL::Bitmap::TGA*  tilesheet = new SRL::Bitmap::TGA("PRTCAVE.TGA");
    SRL::Tilemap::Interfaces::Bmp2Tile* bgtile = new SRL::Tilemap::Interfaces::Bmp2Tile(*tilesheet,2);
    delete tilesheet;

    CurrLevel.collision = &Level[0][0];
    CurrLevel.width = ROOM_SIZE_X;
    CurrLevel.height = ROOM_SIZE_Y;

    for(int y=0;y< ROOM_SIZE_Y;y++)
    {
        for (int x = 0; x < ROOM_SIZE_X; x++)
        {
            uint8_t tile =Level[y][x];
            uint8_t srcX = tile % 16;
            uint8_t srcY = tile / 16;
            bgtile->CopyMap(0,Coord(srcX,srcY),Coord(srcX,srcY),1,Coord(x,y));
        }
    }
    SRL::VDP2::NBG0::LoadTilemap(*bgtile);
    SRL::VDP2::NBG0::SetMapLayout(1,1,1,1);
    delete bgtile;
}

void TestRoom()
{
    LoadTileMap();
    InitCamera();
    InitPlayer();
    
    SRL::VDP2::NBG0::SetPriority(SRL::VDP2::Priority::Layer2);
    SRL::VDP2::NBG0::ScrollEnable();
    
    while(1)
    {
        UpdatePlayer();
        SRL::Core::Synchronize(); // Refresh screen
    }
}
#include <srl.hpp>
#include "player.h"
#include "../libs/physics.h"
#include "../libs/colision.h"


using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

Player player;

uint8_t PlayerColision[16][16] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0}
};

int32_t LoadPlayerSprite(char* filename)
{
    SRL::Bitmap::TGA* quote = new SRL::Bitmap::TGA(filename);
    int32_t quoteID = SRL::VDP1::TryLoadTexture(quote);
    delete quote;
    return quoteID;
}

void UpdatePlayer()
{
    Digital port(0);
    int32_t SpriteId = 0;
    SpriteId = LoadPlayerSprite("QUOTE.TGA");

    Vector2D spritePos = Vector2D(0,0);

    while(1)
	{
        //GetColision(PlayerColision);
        if(port.IsConnected())
        {
            if(port.IsHeld(Digital::Button::Up))
            {
                spritePos.Y = spritePos.Y - 1 ;
            }
            if(port.IsHeld(Digital::Button::Down))
            {
                spritePos.Y = spritePos.Y + 1 ;
            }
            if(port.IsHeld(Digital::Button::Left))
            {
                spritePos.X = spritePos.X - 1 ;
            }
            if(port.IsHeld(Digital::Button::Right))
            {
                spritePos.X = spritePos.X + 1 ;
            }
            if(port.IsHeld(Digital::Button::Y))
            {
                spritePos.X = 0;
                spritePos.Y = 0;
            }
        }

        SRL::Scene2D::DrawSprite(SpriteId, Vector3D(spritePos, 500));
        SRL::Core::Synchronize(); // Refresh screen
	}
}
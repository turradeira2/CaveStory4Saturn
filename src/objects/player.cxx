#include <srl.hpp>
#include "player.h"
#include "../libs/physics.h"
#include "../libs/tiles_colision.h"
//#include "../libs/math.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

extern physics_params physics;
quote player;

#define TILE_SIZE 16

int32_t LoadPlayerSprite(char* filename)
{
    SRL::Bitmap::TGA* quote = new SRL::Bitmap::TGA(filename);
    int32_t quoteID = SRL::VDP1::TryLoadTexture(quote);
    delete quote;
    return quoteID;
}

/*
bool verticall_collision(void)
{
    player.can_jump = false;
    if(physics.speed_y < 0)
    {
        physics.is_in_air = true;
        return false;
    }
    int dist;
}ss
*/
void Player()
{
    Digital port(0);
    int32_t SpriteId = 0;
    SpriteId = LoadPlayerSprite("QUOTE.TGA");

    Vector2D spritePos = Vector2D(0.0);

    while(1) // Main program loop
	{
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

        //SRL::Debug::Print(1,1, "POS X = %f POS Y = %f",spritePos.X,spritePos.Y);
        SRL::Scene2D::DrawSprite(SpriteId, Vector3D(spritePos, 500));
        SRL::Core::Synchronize(); // Refresh screen
	}
}
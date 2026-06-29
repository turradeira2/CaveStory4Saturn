#include <srl.hpp>
#include "player.h"
#include "../libs/physics.h"
#include "../libs/colision.h"


using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;



int32_t LoadPlayerSprite()
{
    SRL::Bitmap::TGA* tga = new SRL::Bitmap::TGA("TEST.TGA");
    int32_t index = SRL::VDP1::TryLoadTexture(tga);
    delete tga;
    return index;
}

void UpdatePlayer()
{
    Digital port(0);
    int32_t SpriteID = 0;
    SpriteID = LoadPlayerSprite();

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

        SRL::Scene2D::DrawSprite(SpriteID, Vector3D(spritePos, 500));
        SRL::Core::Synchronize(); // Refresh screen
	}
}
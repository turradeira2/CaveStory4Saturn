#include <srl.hpp>
#include "player.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

int32_t LoadPlayerSprite(char* filename)
{
    SRL::Bitmap::TGA* quote = new SRL::Bitmap::TGA(filename);
    int32_t quoteID = SRL::VDP1::TryLoadTexture(quote);
    delete quote;
    return quoteID;
}

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
            SRL::Debug::Print(1,2,"CONNECTED");
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
        }
        else
        {
            SRL::Debug::Print(1,2,"NOT CONNECTED");
        }   
        SRL::Scene2D::DrawSprite(SpriteId, Vector3D(spritePos, 500));
        SRL::Core::Synchronize(); // Refresh screen
	}
}
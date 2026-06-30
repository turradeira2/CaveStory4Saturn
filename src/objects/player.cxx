#include <srl.hpp>

#include "player.h"

#include "../libs/physics.h"
#include "../libs/colision.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

PhysicsBody player;
void InitPlayer()
{
    player.box.cx = Fxp(100);
    player.box.cy = Fxp(100);

    player.box.w = Fxp(10);
    player.box.h = Fxp(16);

    player.velX = Fxp();
    player.velY = Fxp();

    player.onGround = false;
}

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

    //Vector2D spritePos = Vector2D(0,0);
    
    

    while(1)
	{
        player.velX = Fxp(0);
        player.velY = Fxp(0);
        
        if(port.IsConnected())
        {
            if(port.IsHeld(Digital::Button::Up))
            {
                player.velY = Fxp(-2);
                //spritePos.Y = spritePos.Y - 1 ;
            }
            if(port.IsHeld(Digital::Button::Down))
            {
                player.velY = Fxp(2);
                //spritePos.Y = spritePos.Y + 1 ;
            }
            if(port.IsHeld(Digital::Button::Left))
            {
                player.velX = Fxp(-2);
                //spritePos.X = spritePos.X - 1 ;
            }
            if(port.IsHeld(Digital::Button::Right))
            {
                player.velX = Fxp(2);
                //spritePos.X = spritePos.X + 1 ;
            }
        }

        player.box.cx += player.velX;
        player.box.cy += player.velY;

        SRL::Scene2D::DrawSprite(SpriteID, Vector3D(player.box.cx, player.box.cy, 500));
        SRL::Core::Synchronize(); // Refresh screen
	}
}

/*
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
        }
*/
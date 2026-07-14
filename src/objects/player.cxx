#include <srl.hpp>

#include "player.h"

#include "../libs/camera.h"
#include "../libs/physics.h"
#include "../libs/colision.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

PhysicsBody player;
int32_t SpriteID;


int32_t LoadPlayerSprite()
{
    SRL::Bitmap::TGA* tga = new SRL::Bitmap::TGA("TEST.TGA");
    int32_t index = SRL::VDP1::TryLoadTexture(tga);
    delete tga;
    return index;
}

void InitPlayer()
{
    InitPhysics(player);

    player.box.cx = Fxp(0);
    player.box.cy = Fxp(0);

    player.box.w = Fxp(10);
    player.box.h = Fxp(16);

    player.velX = Fxp(0);
    player.velY = Fxp(0);

    player.onGround = false;

    SpriteID = LoadPlayerSprite();
}


void UpdatePlayer()
{
    static Digital port(0);
    SRL::Debug::Print(1,1,"Connected: %d",port.IsConnected());

    player.velX = Fxp(0);
    player.velY = Fxp(0);
    
    if(port.IsConnected())
    {
        
        if(port.IsHeld(Digital::Button::Up))
        {
            player.velY = Fxp(-2);
        }
        if(port.IsHeld(Digital::Button::Down))
        {
            player.velY = Fxp(2);
        }
        if(port.IsHeld(Digital::Button::Left))
        {
            player.velX = Fxp(-2);
            //player.box.cx -= Fxp(2);
        }
        if(port.IsHeld(Digital::Button::Right))
        {
            player.velX = Fxp(2);
            //player.box.cx += Fxp(2);
        }
    }
        
    MoveBody(player);

    CenterCamera(player.box.cx,player.box.cy);
    ApplyCamera();
    SRL::Scene2D::DrawSprite(SpriteID, Vector3D(player.box.cx - MainCamera.x, player.box.cy - MainCamera.y , 500));
}

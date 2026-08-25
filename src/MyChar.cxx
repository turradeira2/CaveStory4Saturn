// THIS IS DECOMPILED PROPRIETARY CODE - USE AT YOUR OWN RISK.
//
// The original code belongs to Daisuke "Pixel" Amaya.
//
// Modifications and custom code are under the MIT licence.
// See LICENCE.txt for details.
//
// SEGA SATURN Port by da_toaster

#include "MyChar.h"

#include <srl.hpp>

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

MYCHAR gMC;

int32_t SpriteID;
int32_t LoadPlayerSprite()
{
    SRL::Bitmap::TGA* tga = new SRL::Bitmap::TGA("TEST.TGA");
    int32_t index = SRL::VDP1::TryLoadTexture(tga);
    delete tga;
    return index;
}

void InitMyChar(void)
{
	memset(&gMC, 0, sizeof(MYCHAR));
	gMC.cond = 0x80;
	gMC.direct = 2;

	gMC.view.back = 8 * 0x200;
	gMC.view.top = 8 * 0x200;
	gMC.view.front = 8 * 0x200;
	gMC.view.bottom = 8 * 0x200;

	gMC.hit.back = 5 * 0x200;
	gMC.hit.top = 8 * 0x200;
	gMC.hit.front = 5 * 0x200;
	gMC.hit.bottom = 8 * 0x200;

	gMC.life = 3;
	gMC.max_life = 3;
	gMC.unit = 0;
}
/*
void UpdatePlayer()
{
    
    static Digital port(0); 

    // Get speeds and accelerations
	int max_dash;
	int gravity1;
	int gravity2;
	int jump;
	int dash1;
	int dash2;
	int resist;
    
    int a, x;

	if (player.cond & 2)
		return;

	if (player.flag & 0x100)
	{
		max_dash = 0x32C / 2;
		max_move = 0x5FF / 2;
		gravity1 = 0x50 / 2;
		gravity2 = 0x20 / 2;
		jump = 0x500 / 2;
		dash1 = 0x200 / 6 / 2;
		dash2 = 0x200 / 16 / 2;
		resist = 0x200 / 10 / 2;
	}
	else
	{
		max_dash = 0x32C;
		max_move = 0x5FF;
		gravity1 = 0x50;
		gravity2 = 0x20;
		jump = 0x500;
		dash1 = 0x200 / 6;
		dash2 = 0x200 / 16;
		resist = 0x200 / 10;
	}

    player.ques = FALSE;

    if(port.IsConnected())
    {
        if(port.IsHeld(Digital::Button::Up))
        {
            //player.velY = Fxp(-2);
            //change to aim up later
        }
        if(port.IsHeld(Digital::Button::Down))
        {
            //player.velY = Fxp(2);
            //change to aim down later
        }
        if(port.IsHeld(Digital::Button::Left))
        {
            
        }
        if(port.IsHeld(Digital::Button::Right))
        {
            
        }
        if(port.WasPressed(Digital::Button::B) && player.onGround)
        {


        }
    }
    MoveBody(player);
    CenterCamera(player.hBox.cx,player.hBox.cy);
    ApplyCamera();
    SRL::Scene2D::DrawSprite(SpriteID, Vector3D(player.hBox.cx - MainCamera.x, player.hBox.cy - MainCamera.y , 500));
}
*/
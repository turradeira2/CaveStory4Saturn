#include <srl.hpp>

#include "physics.h"
#include "colision.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Math::Types;

//PhysicsBody body;

void InitPhysics(PhysicsBody& body)
{
    body.velX = Fxp(0);
    body.velY = Fxp(0);
}


void MoveBody(PhysicsBody& body)
{
    Fxp newX = body.box.cx + body.velX;
    Fxp newY = body.box.cy + body.velY;

    Fxp left   = newX - body.box.w / 2;
    Fxp right  = newX + body.box.w / 2;

    Fxp top    = newY - body.box.h / 2;
    Fxp bottom = newY + body.box.h / 2;

    #pragma region Check Horizontal Collision
    if(body.velX > Fxp(0))
    {
        if (IsSolidPixel(right, top) || IsSolidPixel(right, bottom))
        {
            body.velX = Fxp(0);
        }
        else
        {
            body.box.cx = newX;
        }
    }
    else if(body.velX < Fxp(0))
    {
        if (IsSolidPixel(left, top) || IsSolidPixel(left, bottom))
        {
            body.velX = Fxp(0);
        }
        else
        {
            body.box.cx = newX;
        }
    }
    #pragma endregion

    #pragma region Check Vertical Collision
    if (body.velY > Fxp(0))
    {
        if (IsSolidPixel(left,bottom) || IsSolidPixel(right,bottom))
        {
            body.velY = Fxp(0);
        }
        else
        {
            body.box.cy = newY;
        }
    }
    else if (body.velY < Fxp(0))
    {
        if (IsSolidPixel(left,top) || IsSolidPixel(right,top))
        {
            body.velY = Fxp(0);
        }
        else
        {
            body.box.cy = newY;
        }
    }
    #pragma endregion
}

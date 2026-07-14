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

void MoveHorizontal(PhysicsBody& body)
{
    Fxp newX = body.box.cx + body.velX;

    Fxp left   = newX - body.box.w / 2;
    Fxp right  = newX + body.box.w / 2;

    Fxp top    = body.box.cy - body.box.h / 2;
    Fxp bottom = body.box.cy + body.box.h / 2;

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
}

void MoveVertical(PhysicsBody& body)
{
    Fxp newY = body.box.cy + body.velY;

    Fxp left   = body.box.cx - body.box.w / 2;
    Fxp right  = body.box.cx + body.box.w / 2;

    Fxp top    = newY - body.box.h / 2;
    Fxp bottom = newY + body.box.h / 2;
    
    if (body.velY > Fxp(0))
    {
        if (IsSolidPixel(left,bottom) || IsSolidPixel(right,bottom))
        {
            body.velY = Fxp(0);
            body.onGround = true;
        }
        else
        {
            body.box.cy = newY;
            body.onGround = false;
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
}

void MoveBody(PhysicsBody& body)
{
    body.velY += GRAVITY;

    if(body.velY > MAX_FALL)
    {
        body.velY = MAX_FALL;
    }
    
    MoveHorizontal(body);
    MoveVertical(body);
}

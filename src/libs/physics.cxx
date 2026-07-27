//physics.cxx
#include <srl.hpp>

#include "physics.h"
#include "colision.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Math::Types;

//PhysicsBody body;

bool ResolveSlopeCollision(PhysicsBody& body)
{
    Fxp feetX = body.box.cx + body.velX;
    Fxp feetY = body.box.cy + body.velY + body.box.h / 2;

    int worldFloor = GetSlopeFloorY(feetX, feetY);
    SRL::Debug::Print(1, 1,"Feet=%d Floor=%d",feetY.As<int16_t>(),worldFloor);

    // Not standing on a slope.
    if (worldFloor == -1)
        return false;

    if (feetY >= Fxp::Convert(worldFloor))
    {
        body.box.cy = Fxp::Convert(worldFloor) - body.box.h / 2;
        body.velY = Fxp(0);
        body.onGround = true;
        return true;
    }

    return false;
}

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

void CheckGround(PhysicsBody& body)
{
    Fxp feetY = body.box.cy + body.box.h / 2 + Fxp(1);

    Fxp left   = body.box.cx - body.box.w / 2 + Fxp(1);
    Fxp right  = body.box.cx + body.box.w / 2 - Fxp(1);

    body.onGround = IsSolidPixel(left,feetY) || IsSolidPixel(right,feetY);
}

void ApplyGravity(PhysicsBody& body)
{
    if(body.onGround == false)
    {
        body.velY += GRAVITY;

        if(body.velY > MAX_FALL)
        {
            body.velY = MAX_FALL;            
        }
    }
}

void MoveBody(PhysicsBody& body)
{
    ApplyGravity(body);
    MoveHorizontal(body);
    if (!ResolveSlopeCollision(body))
    {
        MoveVertical(body);
    }
    CheckGround(body);
}
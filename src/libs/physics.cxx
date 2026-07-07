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

    Fxp top    = body.box.cy - body.box.h / 2;
    Fxp bottom = body.box.cy + body.box.h / 2;

    SRL::Debug::Print(
    1, 8,
    "R=%d T=%d S=%d",
    right.As<int16_t>(),
    top.As<int16_t>(),
    IsSolidPixel(right, top));

    SRL::Debug::Print(
    1, 10,
    "newX=%d solid=%d",
    newX.As<int16_t>(),
    IsSolidPixel(right, top));

    if (IsSolidPixel(right, top) || IsSolidPixel(right, bottom))
    {
        body.velX = Fxp(0);
    }
    else
    {
        body.box.cx = newX;

    SRL::Debug::Print(
    1, 11,
    "Moved to %d",
    body.box.cx.As<int16_t>());
        body.box.cx = newX;
        body.box.cy = newY;
    }
    SRL::Debug::Print(
    1,10,
    "L=%d R=%d T=%d B=%d",
    IsSolidPixel(left, top),
    IsSolidPixel(right, top),
    IsSolidPixel(left, bottom),
    IsSolidPixel(right, bottom)
    );

}

/*
    void MoveBody(PhysicsBody& body)
{
    Fxp newX = body.box.cx + body.velX;
    Fxp newY = body.box.cy + body.velY;

    Fxp left   = newX - body.box.w / 2;
    Fxp right  = newX + body.box.w / 2;

    Fxp top    = body.box.cy - body.box.h / 2;
    Fxp bottom = body.box.cy + body.box.h / 2;

    SRL::Debug::Print(
    1, 8,
    "R=%d T=%d S=%d",
    right.As<int16_t>(),
    top.As<int16_t>(),
    IsSolidPixel(right, top));

    SRL::Debug::Print(
    1, 10,
    "newX=%d solid=%d",
    newX.As<int16_t>(),
    IsSolidPixel(right, top));

    if (IsSolidPixel(right, top) || IsSolidPixel(right, bottom))
    {
        body.velX = Fxp(0);
    }
    else
    {
        body.box.cx = newX;

    SRL::Debug::Print(
    1, 11,
    "Moved to %d",
    body.box.cx.As<int16_t>());
        body.box.cx = newX;
        body.box.cy = newY;
    }
    SRL::Debug::Print(
    1,10,
    "L=%d R=%d T=%d B=%d",
    IsSolidPixel(left, top),
    IsSolidPixel(right, top),
    IsSolidPixel(left, bottom),
    IsSolidPixel(right, bottom)
    );

}
*/
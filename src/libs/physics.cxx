#include <srl.hpp>

#include "physics.h"
#include "colision.h"

using namespace SRL::Types;
using namespace SRL::Math;

PhysicsBody body;

void InitPhysics()
{
    body.velX = Fxp(0);
    body.velY = Fxp(0);
}

void MoveBody(PhysicsBody& body)
{

    body.box.cx += body.velX;
    body.box.cy += body.velY;

}

/*
    if(body.velX < 0)
    {
        //IsSolidPixel(left);
    }
*/
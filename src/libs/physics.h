#pragma once

#include <srl.hpp>

#include "../libs/physics.h"

using namespace SRL::Math::Types;

struct HitBox
{
    Fxp cx;
    Fxp cy;

    Fxp w;
    Fxp h;
};

struct PhysicsBody
{
    HitBox box;
    //AABB box;

    Fxp velX;
    Fxp velY;

    bool onGround;
};

void InitPhysics();
void MoveBody(PhysicsBody& body);
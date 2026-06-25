#pragma once

#include <srl.hpp>
#include "colision.h"

#define GRAVITY_LAND SRL::Math::Types::Fxp(0.1f)

#define FRICTION_LAND   SRL::Math::Types::Fxp(0.5f)

#define WALK_MAX_LAND   SRL::Math::Types::Fxp(3)

struct PhysicsBody
{
    AABB bb;
    Fxp velX, velY;

    bool grounded : 1;
    //bool flyer;
};

void ApplyGravity(PhysicsBody& body);
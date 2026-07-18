#pragma once

#include <srl.hpp>

#include "../libs/physics.h"

using namespace SRL::Math::Types;

constexpr Fxp GRAVITY    = Fxp(0.2);
constexpr Fxp JUMP_SPEED = Fxp(-3.5);
constexpr Fxp MAX_FALL   = Fxp(4.0);

constexpr Fxp WALK_ACCEL = Fxp(0.15);
constexpr Fxp WALK_DECEL = Fxp(0.2);
constexpr Fxp MAX_SPEED = Fxp(2);

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

    Fxp velX;
    Fxp velY;

    bool onGround;
};

void InitPhysics(PhysicsBody& body);
void MoveBody(PhysicsBody& body);
void MoveHorizontal(PhysicsBody& body);
void MoveVertical(PhysicsBody& body);
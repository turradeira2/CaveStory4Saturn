#pragma once

#include <srl.hpp>

#include "../libs/physics.h"

using namespace SRL::Math::Types;

constexpr Fxp GRAVITY = Fxp(0.5);
constexpr Fxp JUMP_SPEED = Fxp(-55);
constexpr Fxp MAX_FALL = Fxp(4);

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
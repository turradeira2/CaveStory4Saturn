#pragma once

#include "../libs/physics.h"

using namespace SRL::Math::Types;

struct Player
{
    PhysicsBody player;
};

void InitPlayer();
void UpdatePlayer();

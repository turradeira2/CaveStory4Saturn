#pragma once

#include <srl.hpp>
#include "../libs/physics.h"

#define PLAYER_W 12
#define PLAYER_h 16

struct Player
{
    PhysicsBody body;
    int32_t spriteID;
    int velX;
    int velY;
};

extern Player player;

void InitPlayer(SRL:Math::Types::Fxp startX,SRL:Math::Types::Fxp startY);

void UpdatePlayer();
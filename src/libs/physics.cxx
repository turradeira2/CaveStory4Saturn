#include <srl.hpp>

#include "physics.h"
#include "colision.h"

#define GRAVITY 1;
const int MAX_FALL_SPEED = 16;

using namespace SRL::Types;
using namespace SRL::Math;

void ApplyGravity(PhysicsBody& body)
{
    if(body.velY < MAX_FALL_SPEED )
    {
        body.velY++;
    }
}

void MoveHorizontal();
void MoveVertical();
bool CheckGround();
#include <srl.hpp>

#include "physics.h"

using namespace SRL::Types;
using namespace SRL::Math;

void ApplyGravity(PhysicsBody& body);
void MoveHorizontal();
void MoveVertical();
bool CheckGround();
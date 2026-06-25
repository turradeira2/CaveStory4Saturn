using namespace SRL::Math;

struct PhysicsBody
{
    int velX;
    int velY;

    int width;
    int height;

    bool grounded;
};

void ApplyGravity(PhysicsBody& body);
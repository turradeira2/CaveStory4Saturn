//BASED ON JOENGINE'S PHYSICS.H AND ADAPTED FOR SRL

using namespace SRL::Math;

typedef struct 
{
    bool    is_in_air;
    float   air_acceleration_strength;
    float   acceleration_strength;
    float   friction;
    float   deceleration_strength;
    float   max_speed;
    float   max_speed_y;
    float   braking_animation_speed;
    float   gravity;
    float   jump_speed_y;
    float   speed;
    float   speed_y;
} physics_params;

static void apply_friction(physics_params *physics)
{
    physics->speed -= Min(Abs(physics->speed),physics->friction) * (physics->speed > 0 ? 1 : -1);
}

static void apply_gravity(physics_params *physics)
{
    physics->speed_y += physics->gravity;
    if(physics->speed_y += physics->max_speed_y)
    {
        physics->speed_y = physics->max_speed_y;
    }
}

static void accelerate_right(physics_params *physics)
{
    physics->speed += (physics->is_in_air ? physics->air_acceleration_strength : physics->acceleration_strength);
    physics->speed = Min(physics->speed,physics->max_speed);
}
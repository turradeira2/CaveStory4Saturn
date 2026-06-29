#include <srl.hpp>

#include "./scenes/test_room.h"
#include "./objects/player.h"
//Resolution 320 x 240

using namespace SRL::Types;
using namespace SRL::Math::Types;
using namespace SRL::Input;
using namespace SRL::Tilemap;

// Main program entry
int main()
{
    SRL::Core::Initialize(HighColor::Colors::Black);
    
    TestRoom();

    SRL::Debug::Print(1,28,"Cave Story for Sega Saturn Port Test");
    
    // Main program loop
    while(1)
    {
        SRL::Core::Synchronize(); // Refresh screen
    }
    
    return 0;
}
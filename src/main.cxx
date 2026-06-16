#include <srl.hpp>

#include "main.h"
#include "./scenes/title_screen.h"
#include "./scenes/start_cave.h"

//Resolution 320 x 240

// Using to shorten names for Vector and HighColor
using namespace SRL::Types;
using namespace SRL::Math::Types;
using namespace SRL::Input;


// Main program entry
int main()
{
    //SRL::Core::Initialize(HighColor(0,0,0) );
    Digital port0(0);
    
    //title();
    start_cave();

    SRL::Core::Initialize(HighColor(0,0,0) );
    
    SRL::Debug::Print(1,28,"Cave Story for Sega Saturn Port Test 0");

    // Main program loop
    while(1)
    {
        SRL::Core::Synchronize(); // Refresh screen
    }
    
    return 0;
}
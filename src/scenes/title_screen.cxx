#include <srl.hpp>

#define CaveTitle (0)

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

#include "./title_screen.h"

void LoadGraphics()
{
    SRL::Bitmap::TGA* cavetitle = new SRL::Bitmap::TGA("TITLE.TGA");
    SRL::VDP1::TryLoadTexture(cavetitle);
    delete cavetitle;
}

void title()
{
    SRL::Core::Initialize(HighColor(32,32,32));
    SRL::Debug::Print(7,27,"Cave Story for Sega Saturn");
    SRL::Debug::Print(14,16,"Press Start");    

    // Load graphics
    LoadGraphics();

    // Initialize gamepad on port 0
    Digital port0(0);

    // Main program loop
    while (1)
    {
        SRL::Scene2D::DrawSprite(CaveTitle, Vector3D(0, -46, 500));
        if (port0.WasPressed(Digital::Button::START))
        {
            break;
        }
        
        SRL::Core::Synchronize(); // Refresh screen
    }
}

/*

TODO

Cave Story Menu
Music
Load Save


*/
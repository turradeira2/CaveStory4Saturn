#include <srl.hpp>

#include "../objects/player.h"

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

void LoadCaveGraphics()
{
    SRL::Bitmap::TGA*  bg1 = new SRL::Bitmap::TGA("PRTCAVE.TGA");
    SRL::VDP2::NBG1::LoadBitmap(bg1);
    delete bg1;
}

void start_cave()
{
    SRL::Core::Initialize(HighColor(0,0,32));
    SRL::Debug::Print(1,1, "08_Tutorial");
    SRL::Debug::Print(1,28,"Cave Story Saturn Port First Room Test");
    
    LoadCaveGraphics();
    Vector2D pos(8,8);
    SRL::VDP2::NBG1::SetPosition(pos);

    SRL::VDP2::NBG1::SetPriority(SRL::VDP2::Priority::Layer2);
    SRL::VDP2::NBG1::ScrollEnable();

    while(1)
    {       
        Player();
        SRL::Core::Synchronize();
    }

}
#include <srl.hpp>

using namespace SRL::Types;
using namespace SRL::Math;
using namespace SRL::Input;

void LoadSprite()
{
    SRL::Bitmap::TGA* quote = new SRL::Bitmap::TGA("QUOTE.TGA");
    int32_t quoteF1 = SRL::VDP1::TryLoadTexture(quote);
    delete quote;
}
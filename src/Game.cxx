#include <srl.hpp>

#include "Main.h"
#include "NpChar.h"

using namespace SRL::Math;

int g_GameFlags;
int gCounter;

static bool bContinue;

SRL::Math::Random<int> gRandom(12345);

int Random(int min, int max)
{
    return gRandom.GetNumber(min,max);
}

void PutNumber4(int x, int y, int value, bool bZero)
{
    // Define rects
    RECT rcClient = {0,0,VERTICAL_RES,HORIZONTAL_RES};

    RECT rect[10] = {
        {0, 56, 8, 64},
		{8, 56, 16, 64},
		{16, 56, 24, 64},
		{24, 56, 32, 64},
		{32, 56, 40, 64},
		{40, 56, 48, 64},
		{48, 56, 56, 64},
		{56, 56, 64, 64},
		{64, 56, 72, 64},
		{72, 56, 80, 64},
    };

    //Digits
    int tbl[4] = {1000,100,10,1};

	int a;
	int sw;
	int offset;
	
	// Limit value
	if(value > 9999)
	{
		value = 9999;
	}

	offset = 0;
	sw = 0;
	while (offset < 4)
	{
		// Get the digit that this is
		a = 0;
		
		while(value >= tbl[offset])
		{
			value -= tbl[offset];
			++a;
			--sw;
		}
		
		//Draw Digit
		if((bZero && offset == 2) || sw != 0 || offset == 3)
		{
			PutBitmap3(&rcClient, x + 8 * offset,y, &rect[a], SURFACE_ID_TEXT_BOX);
		}

		//Go to next digit
		++offset;
	}
}

static int ModeOpening(void)
{
	int frame_x;
	int frame_y;
	unsigned int wait;

	InitNpChar();
	InitCaret();
}
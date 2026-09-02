// THIS IS DECOMPILED PROPRIETARY CODE - USE AT YOUR OWN RISK.
//
// The original code belongs to Daisuke "Pixel" Amaya.
//
// Modifications and custom code are under the MIT licence.
// See LICENCE.txt for details.
//
// SEGA SATURN Port by da_toaster
// THIS IS DECOMPILED PROPRIETARY CODE - USE AT YOUR OWN RISK.
//
// The original code belongs to Daisuke "Pixel" Amaya.
//
// Modifications and custom code are under the MIT licence.
// See LICENCE.txt for details.
//
// SEGA SATURN Port by da_toaster

#pragma once

#include <srl.hpp>

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

enum Collisions
{
	COLL_LEFT_WALL = 1,     
	COLL_CEILING = 2,       
	COLL_RIGHT_WALL = 4,    
	COLL_GROUND = 8         

};

enum Direction
{
	DIR_LEFT = 0,
	DIR_UP = 1,
	DIR_RIGHT = 2,
	DIR_DOWN = 3,
	DIR_AUTO = 4,
	DIR_OTHER = 5
};

struct RECT
{
	long left;
	long top;
	long right;
	long bottom;
};

struct OTHER_RECT	// The original name for this struct is unknown
{
	int front;
	int top;
	int back;
	int bottom;
};

// THIS IS DECOMPILED PROPRIETARY CODE - USE AT YOUR OWN RISK.
//
// The original code belongs to Daisuke "Pixel" Amaya.
//
// Modifications and custom code are under the MIT licence.
// See LICENCE.txt for details.
//
// SEGA SATURN Port by da_toaster

#pragma once
#include <stdio.h>

#include <srl.hpp>

#define HORIZONTAL_RES (320)
#define VERTICAL_RES (240)
#define SCREEN_WIDTH  Fxp(HORIZONTAL_RES)
#define SCREEN_HEIGHT  Fxp(VERTICAL_RES)
#define SCREEN_RIGHT  Fxp(HORIZONTAL_RES/2)
#define SCREEN_LEFT  Fxp(-HORIZONTAL_RES/2)
#define SCREEN_MIDDLE  Fxp(0)
#define SCREEN_TOP Fxp(-VERTICAL_RES/2)
#define SCREEN_BOTTOM Fxp(VERTICAL_RES/2)


struct RECT
{
	long left;
	long top;
	long right;
	long bottom;
};

//#include <stdio.h>
//#include <string>


/*

extern std::string gModulePath;
extern std::string gDataPath;

extern BOOL bFullscreen;
extern BOOL gbUseJoystick;

extern int gJoystickButtonTable[8];

//extern BOOL gbUseJoystick;

void PutFramePerSecound(void);

BOOL SystemTask(void);
*/
#pragma once

#include <srl.hpp>

#include "CommonDefines.h"

#define HORIZONTAL_RES (320)
#define VERTICAL_RES (240)
#define SCREEN_WIDTH  Fxp(HORIZONTAL_RES)
#define SCREEN_HEIGHT  Fxp(VERTICAL_RES)
#define SCREEN_RIGHT  Fxp(HORIZONTAL_RES/2)
#define SCREEN_LEFT  Fxp(-HORIZONTAL_RES/2)
#define SCREEN_MIDDLE  Fxp(0)
#define SCREEN_TOP Fxp(-VERTICAL_RES/2)
#define SCREEN_BOTTOM Fxp(VERTICAL_RES/2)



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
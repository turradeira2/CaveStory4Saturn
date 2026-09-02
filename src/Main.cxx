#include <srl.hpp>

#include "Main.h"

#include "Input.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
//#include <string>

#include "WindowsWrapper.h"
/*
//#include "Backends/Misc.h"
#include "Bitmap.h"
#include "CommonDefines.h"
#include "Config.h"
#include "Draw.h"
#include "Game.h"
#include "Generic.h"
#include "KeyControl.h"
#include "MyChar.h"
#include "Organya.h"
#include "Profile.h"
#include "Resource.h"
#include "Sound.h"
#include "Triangle.h"
*/
//Resolution 320 x 240
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

using namespace SRL::Types;
using namespace SRL::Math::Types;
using namespace SRL::Input;
using namespace SRL::Tilemap;

void InactiveWindow(void);
void ActiveWindow(void);

//std::string gModulePath = "";
//std::string gDataPath = "/data";

//std::string gModulePath;
//std::string gDataPath;

//BOOL bFullscreen;
BOOL gbUseJoystick = FALSE;

int gJoystickButtonTable[8];

static BOOL bActive = TRUE;
static BOOL bFPS = FALSE;

static int windowWidth = 320;
static int windowHeight = 240;

#ifdef JAPANESE
static const char* const lpWindowName = "洞窟物語";	// "Cave Story"
#else
static const char* const lpWindowName = "Cave Story ~ Doukutsu Monogatari";
#endif
/*
static void DragAndDropCallback(const char *path)
{
	LoadProfile(path);
}


static void WindowFocusCallback(bool focus)
{
	if (focus)
		ActiveWindow();
	else
		InactiveWindow();
}

// Framerate stuff
static unsigned long CountFramePerSecound(void)
{
	unsigned long current_tick;	// The original name for this variable is unknown
	static BOOL first = TRUE;
	static unsigned long max_count;
	static unsigned long count;
	static unsigned long wait;

	if (first)
	{
		wait = Backend_GetTicks();
		first = FALSE;
	}

	current_tick = Backend_GetTicks();
	++count;

	if (wait + 1000 <= current_tick)
	{
		wait += 1000;
		max_count = count;
		count = 0;
	}

	return max_count;
}

void PutFramePerSecound(void)
{
	if (bFPS)
	{
		const unsigned long fps = CountFramePerSecound();
		PutNumber4(WINDOW_WIDTH - 40, 8, fps, FALSE);
	}
}
*/


// Main program entry
int main(int argc, char *argv[])
{
	SRL::Core::Initialize(HighColor(0,0,0), SRL::TV::Resolutions::Normal320x240);
	SRL::Debug::Print(1,1,"Cave Story for Sega Saturn Port Test");
	
	InitInput();
	
	while (1)
	{
		if(SRL::Cd::IsTrayOpen())
		{
			SYS_Exit(0);
		}
		/* code */
	}
	

	//(void)argc;
	
	//int i;

	// Get executable's path, and path of the data folder
	/*
	if (!Backend_GetPaths(&gModulePath, &gDataPath))
	{
		// Fall back on argv[0] if the backend cannot provide a path
		gModulePath = argv[0];

		for (size_t i = gModulePath.length();; --i)
		{
			if (i == 0 || gModulePath[i] == '\\' || gModulePath[i] == '/')
			{
				gModulePath.resize(i);
				break;
			}
		}

		gDataPath = "/data";
		//gDataPath = gModulePath + "/data";
	}
		

	CONFIGDATA conf;
	if (!LoadConfigData(&conf))
		DefaultConfigData(&conf);
		

	// Apply keybinds
	// Swap X and Z buttons
	switch (conf.attack_button_mode)
	{
		case 0:
			gKeyJump = KEY_Z;
			gKeyShot = KEY_X;
			break;

		case 1:
			gKeyJump = KEY_X;
			gKeyShot = KEY_Z;
			break;
	}

	// Swap Okay and Cancel buttons
	switch (conf.ok_button_mode)
	{
		case 0:
			gKeyOk = gKeyJump;
			gKeyCancel = gKeyShot;
			break;

		case 1:
			gKeyOk = gKeyShot;
			gKeyCancel = gKeyJump;
			break;
	}

	// Swap left and right weapon switch keys
	if (IsKeyFile("s_reverse"))
	{
		gKeyArms = KEY_ARMSREV;
		gKeyArmsRev = KEY_ARMS;
	}

	// Alternate movement keys
	switch (conf.move_button_mode)
	{
		case 0:
			gKeyLeft = KEY_LEFT;
			gKeyUp = KEY_UP;
			gKeyRight = KEY_RIGHT;
			gKeyDown = KEY_DOWN;
			break;

		case 1:
			gKeyLeft = KEY_ALT_LEFT;
			gKeyUp = KEY_ALT_UP;
			gKeyRight = KEY_ALT_RIGHT;
			gKeyDown = KEY_ALT_DOWN;
			break;
	}
*/
    
    // Main program loop
    
    
    return 0;
}
/*
void InactiveWindow(void)
{
	if (bActive)
	{
		bActive = FALSE;
		StopOrganyaMusic();
		SleepNoise();
	}

	PlaySoundObject(7, SOUND_MODE_STOP);
}

void ActiveWindow(void)
{
	if (!bActive)
	{
		bActive = TRUE;
		StopOrganyaMusic();
		PlayOrganyaMusic();
		ResetNoise();
	}

	PlaySoundObject(7, SOUND_MODE_PLAY_LOOP);
}

void JoystickProc(void);

BOOL SystemTask(void) 
{
	static bool previous_keyboard_state[BACKEND_KEYBOARD_TOTAL];

	do
	{
		if (!Backend_SystemTask(bActive))
		{
			StopOrganyaMusic();
			return FALSE;
		}
	} while(!bActive);

	bool keyboard_state[BACKEND_KEYBOARD_TOTAL];
	Backend_GetKeyboardState(keyboard_state);

	for (unsigned int i = 0; i < BACKEND_KEYBOARD_TOTAL; ++i)
	{
		if (keyboard_state[i] && !previous_keyboard_state[i])
		{
			switch (i)
			{
				case BACKEND_KEYBOARD_ESCAPE:
					gKey |= KEY_ESCAPE;
					break;

				case BACKEND_KEYBOARD_W:
					gKey |= KEY_MAP;
					break;

				case BACKEND_KEYBOARD_LEFT:
					gKey |= KEY_LEFT;
					break;

				case BACKEND_KEYBOARD_RIGHT:
					gKey |= KEY_RIGHT;
					break;

				case BACKEND_KEYBOARD_UP:
					gKey |= KEY_UP;
					break;

				case BACKEND_KEYBOARD_DOWN:
					gKey |= KEY_DOWN;
					break;

				case BACKEND_KEYBOARD_X:
					gKey |= KEY_X;
					break;

				case BACKEND_KEYBOARD_Z:
					gKey |= KEY_Z;
					break;

				case BACKEND_KEYBOARD_S:
					gKey |= KEY_ARMS;
					break;

				case BACKEND_KEYBOARD_A:
					gKey |= KEY_ARMSREV;
					break;

				case BACKEND_KEYBOARD_LEFT_SHIFT:
				case BACKEND_KEYBOARD_RIGHT_SHIFT:
					gKey |= KEY_SHIFT;
					break;

				case BACKEND_KEYBOARD_F1:
					gKey |= KEY_F1;
					break;

				case BACKEND_KEYBOARD_F2:
					gKey |= KEY_F2;
					break;

				case BACKEND_KEYBOARD_Q:
					gKey |= KEY_ITEM;
					break;

				case BACKEND_KEYBOARD_COMMA:
					gKey |= KEY_ALT_LEFT;
					break;

				case BACKEND_KEYBOARD_PERIOD:
					gKey |= KEY_ALT_DOWN;
					break;

				case BACKEND_KEYBOARD_FORWARD_SLASH:
					gKey |= KEY_ALT_RIGHT;
					break;

				case BACKEND_KEYBOARD_L:
					gKey |= KEY_L;
					break;

				case BACKEND_KEYBOARD_EQUALS:
					gKey |= KEY_PLUS;
					break;

				case BACKEND_KEYBOARD_F5:
					gbUseJoystick = FALSE;
					break;
			}
		}
		else if (!keyboard_state[i] && previous_keyboard_state[i])
		{
			switch (i)
			{
				case BACKEND_KEYBOARD_ESCAPE:
					gKey &= ~KEY_ESCAPE;
					break;

				case BACKEND_KEYBOARD_W:
					gKey &= ~KEY_MAP;
					break;

				case BACKEND_KEYBOARD_LEFT:
					gKey &= ~KEY_LEFT;
					break;

				case BACKEND_KEYBOARD_RIGHT:
					gKey &= ~KEY_RIGHT;
					break;

				case BACKEND_KEYBOARD_UP:
					gKey &= ~KEY_UP;
					break;

				case BACKEND_KEYBOARD_DOWN:
					gKey &= ~KEY_DOWN;
					break;

				case BACKEND_KEYBOARD_X:
					gKey &= ~KEY_X;
					break;

				case BACKEND_KEYBOARD_Z:
					gKey &= ~KEY_Z;
					break;

				case BACKEND_KEYBOARD_S:
					gKey &= ~KEY_ARMS;
					break;

				case BACKEND_KEYBOARD_A:
					gKey &= ~KEY_ARMSREV;
					break;

				case BACKEND_KEYBOARD_LEFT_SHIFT:
				case BACKEND_KEYBOARD_RIGHT_SHIFT:
					gKey &= ~KEY_SHIFT;
					break;

				case BACKEND_KEYBOARD_F1:
					gKey &= ~KEY_F1;
					break;

				case BACKEND_KEYBOARD_F2:
					gKey &= ~KEY_F2;
					break;

				case BACKEND_KEYBOARD_Q:
					gKey &= ~KEY_ITEM;
					break;

				case BACKEND_KEYBOARD_COMMA:
					gKey &= ~KEY_ALT_LEFT;
					break;

				case BACKEND_KEYBOARD_PERIOD:
					gKey &= ~KEY_ALT_DOWN;
					break;

				case BACKEND_KEYBOARD_FORWARD_SLASH:
					gKey &= ~KEY_ALT_RIGHT;
					break;

				case BACKEND_KEYBOARD_L:
					gKey &= ~KEY_L;
					break;

				case BACKEND_KEYBOARD_EQUALS:
					gKey &= ~KEY_PLUS;
					break;
			}
		}
	}

	memcpy(previous_keyboard_state, keyboard_state, sizeof(keyboard_state));

	// Run joystick code
	if (gbUseJoystick)
		JoystickProc();

	return TRUE;
}

void JoystickProc(void)
{
	int i;
	DIRECTINPUTSTATUS status;

	if (!GetJoystickStatus(&status))
		return;

	gKey &= (KEY_ESCAPE | KEY_F1 | KEY_F2);

	// Set movement buttons
	if (status.bLeft)
		gKey |= gKeyLeft;
	else
		gKey &= ~gKeyLeft;

	if (status.bRight)
		gKey |= gKeyRight;
	else
		gKey &= ~gKeyRight;

	if (status.bUp)
		gKey |= gKeyUp;
	else
		gKey &= ~gKeyUp;

	if (status.bDown)
		gKey |= gKeyDown;
	else
		gKey &= ~gKeyDown;

	// Clear held buttons
	for (i = 0; i < 8; ++i)
		gKey &= ~gJoystickButtonTable[i];

	// Set held buttons
	for (i = 0; i < 8; ++i)
		if (status.bButton[i])
			gKey |= gJoystickButtonTable[i];
}
*/
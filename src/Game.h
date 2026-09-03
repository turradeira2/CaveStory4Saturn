#pragma once

enum GameFlagsValues
{
    GAME_FLAG_IS_CONTROL_ENABLED = 2
};

extern int g_GameFlags;
extern int gCounter;

int GetRandom(int min, int max);
void PutNumber4(int x, int y, int value, bool bZero);
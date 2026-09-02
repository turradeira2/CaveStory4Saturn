#pragma once

#include "CommonDefines.h"

typedef struct MAP_DATA
{
	unsigned char *data;
	unsigned char atrb[0x100];
	short width;
	short length;
} MAP_DATA;

extern MAP_DATA gMap;

bool InitMapData2(void);
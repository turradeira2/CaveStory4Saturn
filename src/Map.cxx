#include "Map.h"

#include <srl.hpp>

#include "CommonDefines.h"
#include "Draw.h"
#include "File.h"
#include "Main.h"
#include "NpChar.h"

#define PXM_BUFFER_SIZE 0x4B000

MAP_DATA gMap;

const char *code_pxma = "PXM";

bool InitMapData2(void)
{
    gMap.data = (unsigned char*)malloc(PXM_BUFFER_SIZE);
	return true;
}

bool LoadMapData2(const char *path_map)
{}
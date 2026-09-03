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
{
    char path[256];

    // Build path
    strcpy(path, DATA_PATH);
    strcat(path, path_map);

    // Open File
    SRL::Cd::File file(path);

    if(!file.IsOpen())
    {
        return false;
    }

    // Make sure file begins with "PXM"
    char check[3];

    if(file.Read(3, check) != 3)
    {
        file.Close();
        return false;
    }

    if(memcmp(check, code_pxma, 3) != 0)
    {
        file.Close();
        return false;
    }

    unsigned char dum;

    if (file.Read(1, &dum) != 1)
    {
        file.Close();
        return false;
    }

    // Get width and height
    gMap.width  = File_ReadLE16(file);
    gMap.length = File_ReadLE16(file);

    if (gMap.data == NULL)
    {
        file.Close();
        return false;
    }

    // Read tile data
    size_t data_size = (size_t)gMap.width * (size_t)gMap.length;

    if (data_size > PXM_BUFFER_SIZE)
    {
        file.Close();
        return false;
    }

    if (file.Read((int32_t)data_size, gMap.data) != (int32_t)data_size)
    {
        file.Close();
        return false;
    }

    file.Close();

    return true;
}

bool LoadAttributeData(const char *path_atrb)
{
    char path[256];

    // Build path
    strcpy(path, DATA_PATH);
    strcat(path, path_map);

    // Open File
    SRL::Cd::File file(path);

    if(!file.IsOpen())
    {
        return false;
    }

}

void EndMapData(void)
{
	free(gMap.data);
}

void ReleasePartsImage(void)
{
	ReleaseSurface(SURFACE_ID_LEVEL_TILESET);
}
#include "File.h"

#include <srl.hpp>

unsigned char* LoadFileToMemory(const char *file_path, size_t *file_size)
{
    SRL::Cd::File file(file_path);

    if(!file.IsOpen())
    {
        return = NULL;
    }

    const size_t size = file.Size.Size;

    unsigned char *buffer = (unsigned char* )malloc(size);

    if(buffer == NULL)
    {
        file.Close();
        return NULL;
    }

    if(file.Read((int32_t)size, buffer) != (int32_t)size)
    {
        free(buffer);
        file.Close();
        return NULL;
    }

    file.Close();

    *file_size = size;
    
    return buffer;
}

uint16_t File_ReadBE16(SRL::Cd::File& file)
{
    uint8_t bytes[2];

    if (file.Read(2, bytes) != 2)
    {
        return 0;
    }

    return ((uint16_t)bytes[0] << 8) | (uint16_t)bytes[1];
}

uint16_t File_ReadLE16(SRL::Cd::File& file)
{
    uint8_t bytes[2];

    if (file.Read(2, bytes) != 2)
    {
        return 0;
    }

    return ((uint16_t)bytes[1] << 8) | (uint16_t)bytes[0];
}

uint32_t File_ReadBE32(SRL::Cd::File& file)
{
    uint8_t bytes[4];

    if (file.Read(4, bytes) != 4)
    {
        return 0;
    }
    
    return ((uint32_t)bytes[0] << 24) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[2] << 8) | (uint32_t)bytes[3];
}

uint32_t File_ReadLE32(SRL::Cd::File& file)
{
    uint8_t bytes[4];

    if (file.Read(4, bytes) != 4)
    {
        return 0;
    }

    return ((uint32_t)bytes[3] << 24) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[1] << 8) | (uint32_t)bytes[0];
}
#pragma once

unsigned char* LoadFileToMemory(const char *file_path,size_t *file_size);

uint16_t File_ReadBE16(SRL::Cd::File& file);
uint32_t File_ReadBE32(SRL::Cd::File& file);

uint16_t File_ReadLE16(SRL::Cd::File& file);
uint32_t File_ReadLE32(SRL::Cd::File& file);
#ifndef FILE_defined
#define FILE_defined 

//struct _IO_FILE;

/* The opaque type of streams.  This is the definition used elsewhere.  */
//typedef struct _IO_FILE FILE;


unsigned char* LoadFileToMemory(const char *file_path,size_t *file_size);

uint16_t File_ReadBE16(SRL::Cd::File& file);
uint32_t File_ReadBE32(SRL::Cd::File& file);

uint16_t File_ReadLE16(SRL::Cd::File& file);
uint32_t File_ReadLE32(SRL::Cd::File& file);

#endif
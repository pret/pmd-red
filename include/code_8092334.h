#ifndef GUARD_CODE_8092334_H
#define GUARD_CODE_8092334_H

// size: 0x10
typedef struct DataSerializer
{
    u8 *stream;
    u8 *end; // exclusive end of the stream
    u32 count; // Used to count bits between ReadBits functions, or count bytes between ReadBytes functions
    u32 unkC; // Seems to be a temporary 32 bit storage
} DataSerializer;

void nullsub_102(DataSerializer *seri);
void ReadBits(DataSerializer *seri, void *dst, s32 numBits);
void WriteBits(DataSerializer *seri, void *src, s32 numBits);
void InitBitReader(DataSerializer *seri, u8 *buffer, s32 bufLen);
void InitBitWriter(DataSerializer *seri, u8 *buffer, s32 bufLen);

#endif // GUARD_CODE_8092334_H
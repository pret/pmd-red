#ifndef GUARD_DATA_SERIALIZER_H
#define GUARD_DATA_SERIALIZER_H

// size: 0x10
typedef struct DataSerializer
{
    /* 0x0 */ u8 *stream;
    /* 0x4 */ u8 *end; // Exclusive end of the stream
    /* 0x8 */ u32 count; // Used to count bits between ReadBits functions, or count bytes between ReadBytes functions
    /* 0xC */ u32 unkC; // Seems to be a temporary 32 bit storage
} DataSerializer;

void FinishBitSerializer(DataSerializer *seri);
void InitBitReader(DataSerializer *seri, u8 *buffer, s32 bufLen);
void InitBitWriter(DataSerializer *seri, u8 *buffer, s32 bufLen);
void ReadBits(DataSerializer *seri, void *dst, s32 numBits);
void WriteBits(DataSerializer *seri, void *src, s32 numBits);

#endif // GUARD_DATA_SERIALIZER_H

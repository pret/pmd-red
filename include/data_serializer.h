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

#endif // GUARD_DATA_SERIALIZER_H

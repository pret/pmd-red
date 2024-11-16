#ifndef GUARD_DATA_SERIALIZER_H
#define GUARD_DATA_SERIALIZER_H

// size: 0x10
typedef struct DataSerializer
{
    u8 *stream;
    u8 *end; // Exclusive end of the stream
    u32 count; // Used to count bits between ReadBits functions, or count bytes between ReadBytes functions
    u32 unkC; // Seems to be a temporary 32 bit storage
} DataSerializer;

#endif // GUARD_DATA_SERIALIZER_H
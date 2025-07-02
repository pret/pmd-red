#ifndef GUARD_RGB_H
#define GUARD_RGB_H

typedef struct RGB
{
    u8 r;
    u8 g;
    u8 b;
    u8 unk4; // Never read, always 0x80. Unused transparency/alpha flag?
} RGB;

#define RGB_R 0
#define RGB_G 1
#define RGB_B 2
#define RGB_UNK 3
#define RGB_FIELDS_COUNT 4

typedef struct RGB_Array
{
    u8 c[RGB_FIELDS_COUNT];
} RGB_Array;

typedef union RGB_Union
{
    RGB_Array asArr;
    RGB separate;
} RGB_Union;

#endif // GUARD_RGB_H

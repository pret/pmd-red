#ifndef GUARD_RGB_H
#define GUARD_RGB_H

typedef struct RGB
{
    u8 r;
    u8 g;
    u8 b;
} RGB;

typedef struct Palette32
{
    RGB pal[16];
} Palette32;

#endif // GUARD_RGB_H

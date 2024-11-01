#ifndef GUARD_RGB_H
#define GUARD_RGB_H

typedef struct Rgb32
{
    u8 r;
    u8 g;
    u8 b;
} Rgb32;

typedef struct Palette32
{
    Rgb32 pal[16];
} Palette32;

#endif // GUARD_RGB_H

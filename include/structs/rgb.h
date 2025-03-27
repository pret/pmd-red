#ifndef GUARD_RGB_H
#define GUARD_RGB_H

typedef struct RGB
{
    u8 r;
    u8 g;
    u8 b;
    u8 unk4; // Never read, always 0x80. Unused transparency/alpha flag?
} RGB;

#endif // GUARD_RGB_H

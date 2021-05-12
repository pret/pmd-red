#ifndef ITEMS_H
#define ITEMS_H

struct Item
{
    /* 0x0 */ u8 *namePointer;
    /* 0x4 */ u32 buyPrice;
    /* 0x8 */ u32 sellPrice;
    /* 0xC */ u8 type;
    /* 0xD */ u8 icon;
    /* 0xE */ u16 fill;
    /* 0x10 */ u8 *descriptionPointer;
    /* 0x14 */ bool8 unkFood1[2];
    /* 0x16 */ u8 throwDmg;
    /* 0x17 */ u8 fill2;
    /* 0x18 */ s16 move;
    /* 0x1A */ u8 order; // Numbered order they are in storage
    /* 0x1B */ u8 unkThrow1B[2];
    /* 0x1D */ u8 palette;
    /* 0x1E */ u8 subtype; // category in PMDe??
    /* 0x1F */ u8 fill3;
};

#endif

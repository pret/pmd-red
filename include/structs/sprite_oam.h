#ifndef GUARD_SPRITE_OAM_H
#define GUARD_SPRITE_OAM_H

// size: 0xC
// This is probably used for blue/gold rescue team to convert from GBA OAM to their platform's OAM in AddSprite()
typedef struct unkStruct_2039DB0
{
    u16 unk0; // SpriteOAM attrib1 mask
    u16 unk2; // SpriteOAM attrib2 mask
    u16 unk4; // SpriteOAM attrib3 mask
    u16 unk6; // SpriteOAM attrib1 value
    u16 unk8; // SpriteOAM attrib2 value
    u16 unkA; // SpriteOAM attrib3 value
} unkStruct_2039DB0;

// size: 0x8. Similar to struct OamData but unk6 is not copied to OAM
typedef struct SpriteOAM
{
    // y:8  affineMode1:1  affineMode2:1  objMode:2  mosaic:1  bpp:1  shape:2
    /* 0x0 */ u16 attrib1;
    // x:9  matrixNum:5  size:2
    /* 0x2 */ u16 attrib2;
    // tileNum:10  priority:2  paletteNum:4
    /* 0x4 */ u16 attrib3;
    // unk6_0:1  unk6_1:1  unk6_2:1  unk6_3:1  unk6_4:12
    u16 unk6;
} SpriteOAM;

// The SpriteOAM struct is handled with macros most likely.
// Most funcs that deal with it look the same and do some weird bit manipulations one by one on the attributes.
// It seems like there is a macro to initialize the structure to some default values...

// attrib1

#define SPRITEOAM_MAX_Y 0xFF
#define SPRITEOAM_SHIFT_Y 0
#define SPRITEOAM_MASK_Y (SPRITEOAM_MAX_Y << SPRITEOAM_SHIFT_Y) // ~ 0xFF00

#define SPRITEOAM_MAX_AFFINEMODE1 1
#define SPRITEOAM_SHIFT_AFFINEMODE1 8
#define SPRITEOAM_MASK_AFFINEMODE1 (SPRITEOAM_MAX_AFFINEMODE1 << SPRITEOAM_SHIFT_AFFINEMODE1) // ~ 0xFEFF

#define SPRITEOAM_MAX_AFFINEMODE2 1
#define SPRITEOAM_SHIFT_AFFINEMODE2 9
#define SPRITEOAM_MASK_AFFINEMODE2 (SPRITEOAM_MAX_AFFINEMODE2 << SPRITEOAM_SHIFT_AFFINEMODE2) // ~ 0xFDFF

#define SPRITEOAM_MAX_OBJMODE 3
#define SPRITEOAM_SHIFT_OBJMODE 10
#define SPRITEOAM_MASK_OBJMODE (SPRITEOAM_MAX_OBJMODE << SPRITEOAM_SHIFT_OBJMODE) // ~ 0xF3FF

#define SPRITEOAM_MAX_MOSAIC 1
#define SPRITEOAM_SHIFT_MOSAIC 12
#define SPRITEOAM_MASK_MOSAIC (SPRITEOAM_MAX_MOSAIC << SPRITEOAM_SHIFT_MOSAIC) // ~ 0xEFFF

#define SPRITEOAM_MAX_BPP 1
#define SPRITEOAM_SHIFT_BPP 13
#define SPRITEOAM_MASK_BPP (SPRITEOAM_MAX_BPP << SPRITEOAM_SHIFT_BPP) // ~ 0xDFFF

#define SPRITEOAM_MAX_SHAPE 3
#define SPRITEOAM_SHIFT_SHAPE 14
#define SPRITEOAM_MASK_SHAPE (SPRITEOAM_MAX_SHAPE << SPRITEOAM_SHIFT_SHAPE) // ~ 0x3FFF

// attrib2

#define SPRITEOAM_MAX_X 0x1FF
#define SPRITEOAM_SHIFT_X 0
#define SPRITEOAM_MASK_X (SPRITEOAM_MAX_X << SPRITEOAM_SHIFT_X) // ~ 0xFE00

#define SPRITEOAM_MAX_MATRIXNUM 31
#define SPRITEOAM_SHIFT_MATRIXNUM 9
#define SPRITEOAM_MASK_MATRIXNUM (SPRITEOAM_MAX_MATRIXNUM << SPRITEOAM_SHIFT_MATRIXNUM) // ~ 0xC1FF

#define SPRITEOAM_MAX_SIZE 3
#define SPRITEOAM_SHIFT_SIZE 14
#define SPRITEOAM_MASK_SIZE (SPRITEOAM_MAX_SIZE << SPRITEOAM_SHIFT_SIZE) // ~ 0x3FFF

// attrib3

#define SPRITEOAM_MAX_TILENUM 0x3FF
#define SPRITEOAM_SHIFT_TILENUM 0
#define SPRITEOAM_MASK_TILENUM (SPRITEOAM_MAX_TILENUM << SPRITEOAM_SHIFT_TILENUM) // ~ 0xFC00

#define SPRITEOAM_MAX_PRIORITY 3
#define SPRITEOAM_SHIFT_PRIORITY 10
#define SPRITEOAM_MASK_PRIORITY (SPRITEOAM_MAX_PRIORITY << SPRITEOAM_SHIFT_PRIORITY) // ~ 0xF3FF

#define SPRITEOAM_MAX_PALETTENUM 15
#define SPRITEOAM_SHIFT_PALETTENUM 12
#define SPRITEOAM_MASK_PALETTENUM (SPRITEOAM_MAX_PALETTENUM << SPRITEOAM_SHIFT_PALETTENUM) // ~ 0xFFF

// unk6

#define SPRITEOAM_MAX_UNK6_0 1
#define SPRITEOAM_SHIFT_UNK6_0 0
#define SPRITEOAM_MASK_UNK6_0 (SPRITEOAM_MAX_UNK6_0 << SPRITEOAM_SHIFT_UNK6_0) // ~ 0xFFFE

#define SPRITEOAM_MAX_UNK6_1 1
#define SPRITEOAM_SHIFT_UNK6_1 1
#define SPRITEOAM_MASK_UNK6_1 (SPRITEOAM_MAX_UNK6_1 << SPRITEOAM_SHIFT_UNK6_1) // ~ 0xFFFD

#define SPRITEOAM_MAX_UNK6_2 1
#define SPRITEOAM_SHIFT_UNK6_2 2
#define SPRITEOAM_MASK_UNK6_2 (SPRITEOAM_MAX_UNK6_2 << SPRITEOAM_SHIFT_UNK6_2) // ~ 0xFFFB

/* Not seen yet
#define SPRITEOAM_MAX_UNK6_3 1
#define SPRITEOAM_SHIFT_UNK6_3 3
#define SPRITEOAM_MASK_UNK6_3 (SPRITEOAM_MAX_UNK6_3 << SPRITEOAM_SHIFT_UNK6_3) // ~ 0xFFF7
*/

// Seems to be the "working" Y coord. Gets copied to attrib1's Y coord in `AddSprite()`.
// kermalis is too lazy to rename it atm since we're still figuring things out
#define SPRITEOAM_MAX_UNK6_4 0xFFF
#define SPRITEOAM_SHIFT_UNK6_4 4
#define SPRITEOAM_MASK_UNK6_4 (SPRITEOAM_MAX_UNK6_4 << SPRITEOAM_SHIFT_UNK6_4) // ~ 0xF

// These seems to work most of the time when dealing with sprite pointers. However, these DO NOT match when dealing with local variables, for example a Sprite struct on the stack.
// These have to be macros, because static inlines WON'T match.

#define SpriteSetAffine1(spritePtr, _affine1) \
{ \
    u32 affine1 = _affine1; \
    affine1 &= SPRITEOAM_MAX_AFFINEMODE1; \
    affine1 <<= SPRITEOAM_SHIFT_AFFINEMODE1; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1; \
    (spritePtr)->attrib1 |= affine1; \
}

#define SpriteSetAffine2(spritePtr, _affine2) \
{ \
    u32 affine2 = _affine2; \
    affine2 &= SPRITEOAM_MAX_AFFINEMODE2; \
    affine2 <<= SPRITEOAM_SHIFT_AFFINEMODE2; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2; \
    (spritePtr)->attrib1 |= affine2; \
}

#define SpriteSetObjMode(spritePtr, _objMode) \
{ \
    u32 objMode = _objMode; \
    objMode &= SPRITEOAM_MAX_OBJMODE; \
    objMode <<= SPRITEOAM_SHIFT_OBJMODE; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_OBJMODE; \
    (spritePtr)->attrib1 |= objMode; \
}

#define SpriteSetMosaic(spritePtr, _mosaic) \
{ \
    u32 mosaic = _mosaic; \
    mosaic &= SPRITEOAM_MAX_MOSAIC; \
    mosaic <<= SPRITEOAM_SHIFT_MOSAIC; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_MOSAIC; \
    (spritePtr)->attrib1 |= mosaic; \
}

#define SpriteSetBpp(spritePtr, _bpp) \
{ \
    u32 bpp = _bpp; \
    bpp &= SPRITEOAM_MAX_BPP; \
    bpp <<= SPRITEOAM_SHIFT_BPP; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_BPP; \
    (spritePtr)->attrib1 |= bpp; \
}

#define SpriteSetShape(spritePtr, _shape) \
{ \
    u32 shape = _shape; \
    shape &= SPRITEOAM_MAX_SHAPE; \
    shape <<= SPRITEOAM_SHIFT_SHAPE; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_SHAPE; \
    (spritePtr)->attrib1 |= shape; \
}

#define SpriteSetTileNum(spritePtr, _tileNum) \
{ \
    u32 tileNum = _tileNum; \
    tileNum &= SPRITEOAM_MAX_TILENUM; \
    tileNum <<= SPRITEOAM_SHIFT_TILENUM; \
    (spritePtr)->attrib3 &= ~SPRITEOAM_MASK_TILENUM; \
    (spritePtr)->attrib3 |= tileNum; \
}

#define SpriteSetPriority(spritePtr, _priority) \
{ \
    u32 priority = _priority; \
    priority &= SPRITEOAM_MAX_PRIORITY; \
    priority <<= SPRITEOAM_SHIFT_PRIORITY; \
    (spritePtr)->attrib3 &= ~SPRITEOAM_MASK_PRIORITY; \
    (spritePtr)->attrib3 |= priority; \
}

#define SpriteSetPalNum(spritePtr, _palNum)                \
{                                                       \
    u32 palNum = _palNum;                               \
    palNum &= SPRITEOAM_MAX_PALETTENUM;                \
    palNum <<= SPRITEOAM_SHIFT_PALETTENUM;                \
    (spritePtr)->attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;            \
    (spritePtr)->attrib3 |= palNum;                        \
}

#define SpriteSetMatrixNum(spritePtr, _matrixNum)                \
{                                                       \
    u32 matrixNum = _matrixNum;                               \
    matrixNum &= SPRITEOAM_MAX_MATRIXNUM;                \
    matrixNum <<= SPRITEOAM_SHIFT_MATRIXNUM;                \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;            \
    (spritePtr)->attrib2 |= matrixNum;                        \
}

#define SpriteSetSize(spritePtr, _size)                \
{                                                       \
    u32 size = _size;                               \
    size &= SPRITEOAM_MAX_SIZE;                \
    size <<= SPRITEOAM_SHIFT_SIZE;                \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_SIZE;            \
    (spritePtr)->attrib2 |= size;                        \
}

#define SpriteSetX(spritePtr, _x)                \
{               \
    u32 xSpriteVal = _x;               \
    xSpriteVal &= SPRITEOAM_MAX_X;               \
    xSpriteVal <<= SPRITEOAM_SHIFT_X;               \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_X;               \
    (spritePtr)->attrib2 |= xSpriteVal;               \
}

// Hacky way of matching functions in menu_input.c AddMenuCursorSprite_, sub_801332C sub_8013470
#define SpriteSetX_MatrixNumSize0(spritePtr, _x)                \
{               \
    u32 xSpriteVal = _x;               \
    xSpriteVal &= SPRITEOAM_MAX_X;               \
    xSpriteVal <<= SPRITEOAM_SHIFT_X;               \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_X;               \
    (spritePtr)->attrib2 = xSpriteVal;               \
}

#define SpriteGetY(spritePtr, _y)             \
{                                            \
    _y = (spritePtr)->unk6;                \
    _y >>= SPRITEOAM_SHIFT_UNK6_4;            \
    _y &= SPRITEOAM_MAX_UNK6_4;            \
}

#define SpriteSetY(spritePtr, _y) \
{ \
    u32 ySpriteVal = _y; \
    ySpriteVal &= SPRITEOAM_MAX_UNK6_4; \
    ySpriteVal <<= SPRITEOAM_SHIFT_UNK6_4; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_4; \
    (spritePtr)->unk6 |= ySpriteVal; \
}

#define SpriteAddY(spritePtr, addVal)         \
{                                                \
    u32 _yVal;                                \
    SpriteGetY(spritePtr, _yVal);            \
    _yVal += (addVal);                        \
    SpriteSetY(spritePtr, _yVal);              \
}

#define SpriteSetUnk6_0(spritePtr, _unk6_0) \
{ \
    u32 unk6_0 = _unk6_0; \
    unk6_0 &= SPRITEOAM_MAX_UNK6_0; \
    unk6_0 <<= SPRITEOAM_SHIFT_UNK6_0; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_0; \
    (spritePtr)->unk6 |= unk6_0; \
}

#define SpriteSetUnk6_1(spritePtr, _unk6_1) \
{ \
    u32 unk6_1 = _unk6_1; \
    unk6_1 &= SPRITEOAM_MAX_UNK6_1; \
    unk6_1 <<= SPRITEOAM_SHIFT_UNK6_1; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_1; \
    (spritePtr)->unk6 |= unk6_1; \
}

#define SpriteSetUnk6_2(spritePtr, _unk6_2) \
{ \
    u32 unk6_2 = _unk6_2; \
    unk6_2 &= SPRITEOAM_MAX_UNK6_2; \
    unk6_2 <<= SPRITEOAM_SHIFT_UNK6_2; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_2; \
    (spritePtr)->unk6 |= unk6_2; \
}

#endif // GUARD_SPRITE_OAM_H

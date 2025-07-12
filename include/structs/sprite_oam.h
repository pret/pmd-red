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

#define DEFAULT_UNK_2039DB0_MASKS (unkStruct_2039DB0) {0xFFFF, 0xFFFF, 0xFFFF, 0, 0, 0}

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

// It's the "working" Y coord. Gets copied to attrib1's Y coord in `AddSprite()`.
#define SPRITEOAM_MAX_WORKING_Y 0xFFF
#define SPRITEOAM_SHIFT_WORKING_Y 4
#define SPRITEOAM_MASK_WORKING_Y (SPRITEOAM_MAX_WORKING_Y << SPRITEOAM_SHIFT_WORKING_Y) // ~ 0xF

// These seem to work most(all?) of the time.
// These have to be macros, because static inlines WON'T match.

#define SpriteSetOamY(spritePtr, _oamY) \
{ \
    u32 _oamYSpriteVal = _oamY; \
    _oamYSpriteVal &= SPRITEOAM_MAX_Y; \
    _oamYSpriteVal <<= SPRITEOAM_SHIFT_Y; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_Y; \
    (spritePtr)->attrib1 |= _oamYSpriteVal; \
}

#define SpriteSetAffine1(spritePtr, _affine1) \
{ \
    u32 _affine1Val = _affine1; \
    _affine1Val &= SPRITEOAM_MAX_AFFINEMODE1; \
    _affine1Val <<= SPRITEOAM_SHIFT_AFFINEMODE1; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1; \
    (spritePtr)->attrib1 |= _affine1Val; \
}

#define SpriteSetAffine2(spritePtr, _affine2) \
{ \
    u32 _affine2Val = _affine2; \
    _affine2Val &= SPRITEOAM_MAX_AFFINEMODE2; \
    _affine2Val <<= SPRITEOAM_SHIFT_AFFINEMODE2; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2; \
    (spritePtr)->attrib1 |= _affine2Val; \
}

#define SpriteSetObjMode(spritePtr, _objMode) \
{ \
    u32 _objModeVal = _objMode; \
    _objModeVal &= SPRITEOAM_MAX_OBJMODE; \
    _objModeVal <<= SPRITEOAM_SHIFT_OBJMODE; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_OBJMODE; \
    (spritePtr)->attrib1 |= _objModeVal; \
}

#define SpriteSetMosaic(spritePtr, _mosaic) \
{ \
    u32 _mosaicVal = _mosaic; \
    _mosaicVal &= SPRITEOAM_MAX_MOSAIC; \
    _mosaicVal <<= SPRITEOAM_SHIFT_MOSAIC; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_MOSAIC; \
    (spritePtr)->attrib1 |= _mosaicVal; \
}

#define SpriteSetBpp(spritePtr, _bpp) \
{ \
    u32 _bppVal = _bpp; \
    _bppVal &= SPRITEOAM_MAX_BPP; \
    _bppVal <<= SPRITEOAM_SHIFT_BPP; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_BPP; \
    (spritePtr)->attrib1 |= _bppVal; \
}

#define SpriteSetShape(spritePtr, _shape) \
{ \
    u32 _shapeVal = _shape; \
    _shapeVal &= SPRITEOAM_MAX_SHAPE; \
    _shapeVal <<= SPRITEOAM_SHIFT_SHAPE; \
    (spritePtr)->attrib1 &= ~SPRITEOAM_MASK_SHAPE; \
    (spritePtr)->attrib1 |= _shapeVal; \
}

#define SpriteGetTileNum_LocalVar(spritePtr, _tileNum)             \
{                                            \
    _tileNum = (spritePtr)->attrib3;                \
    _tileNum >>= SPRITEOAM_SHIFT_TILENUM;            \
    _tileNum &= SPRITEOAM_MAX_TILENUM;            \
}

#define SpriteSetTileNum(spritePtr, _tileNum) \
{ \
    u32 _tileNumVal = _tileNum; \
    _tileNumVal &= SPRITEOAM_MAX_TILENUM; \
    _tileNumVal <<= SPRITEOAM_SHIFT_TILENUM; \
    (spritePtr)->attrib3 &= ~SPRITEOAM_MASK_TILENUM; \
    (spritePtr)->attrib3 |= _tileNumVal; \
}

#define SpriteAddTileNum(spritePtr, addVal)         \
{                                                \
    u32 _tileNumValAdd;                                \
    SpriteGetTileNum_LocalVar(spritePtr, _tileNumValAdd);            \
    _tileNumValAdd += (addVal);                        \
    SpriteSetTileNum(spritePtr, _tileNumValAdd);              \
}

#define SpriteSetPriority(spritePtr, _priority) \
{ \
    u32 _priorityVal = _priority; \
    _priorityVal &= SPRITEOAM_MAX_PRIORITY; \
    _priorityVal <<= SPRITEOAM_SHIFT_PRIORITY; \
    (spritePtr)->attrib3 &= ~SPRITEOAM_MASK_PRIORITY; \
    (spritePtr)->attrib3 |= _priorityVal; \
}

#define SpriteSetPalNum(spritePtr, _palNum)                \
{                                                       \
    u32 _palNumVal = _palNum;                               \
    _palNumVal &= SPRITEOAM_MAX_PALETTENUM;                \
    _palNumVal <<= SPRITEOAM_SHIFT_PALETTENUM;                \
    (spritePtr)->attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;            \
    (spritePtr)->attrib3 |= _palNumVal;                        \
}

#define SpriteSetMatrixNum(spritePtr, _matrixNum)                \
{                                                       \
    u32 _matrixNumVal = _matrixNum;                               \
    _matrixNumVal &= SPRITEOAM_MAX_MATRIXNUM;                \
    _matrixNumVal <<= SPRITEOAM_SHIFT_MATRIXNUM;                \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;            \
    (spritePtr)->attrib2 |= _matrixNumVal;                        \
}

#define SPRITEOAM_SHIFT_H_FLIP_MATRIXNUM (3)
#define SPRITEOAM_SHIFT_V_FLIP_MATRIXNUM (4)

// Horizontal flip shares the same bits as matrixNum.
#define SpriteSetVFlip(spritePtr, _flip)                \
{                                                       \
    SpriteSetMatrixNum(spritePtr, (_flip << SPRITEOAM_SHIFT_V_FLIP_MATRIXNUM))         \
}

// Needed for TryCreateModeArrows. No difference to SpriteSetMatrixNum other than not creating one additional local variable.
#define SpriteSetMatrixNumFlips(spritePtr, _flips)                \
{                                                       \
    _flips &= SPRITEOAM_MAX_MATRIXNUM;                \
    _flips <<= SPRITEOAM_SHIFT_MATRIXNUM;                \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;            \
    (spritePtr)->attrib2 |= _flips;                        \
}

#define SpriteSetSize(spritePtr, _size)                \
{                                                       \
    u32 _sizeVal = _size;                               \
    _sizeVal &= SPRITEOAM_MAX_SIZE;                \
    _sizeVal <<= SPRITEOAM_SHIFT_SIZE;                \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_SIZE;            \
    (spritePtr)->attrib2 |= _sizeVal;                        \
}

#define SpriteGetX(spritePtr)(((spritePtr)->attrib2 >> SPRITEOAM_SHIFT_X) & SPRITEOAM_MAX_X)

#define SpriteSetX(spritePtr, _x)                \
{               \
    u32 _xSpriteVal = _x;               \
    _xSpriteVal &= SPRITEOAM_MAX_X;               \
    _xSpriteVal <<= SPRITEOAM_SHIFT_X;               \
    (spritePtr)->attrib2 &= ~SPRITEOAM_MASK_X;               \
    (spritePtr)->attrib2 |= _xSpriteVal;               \
}

#define SpriteGetY(spritePtr)(((spritePtr)->unk6 >> SPRITEOAM_SHIFT_WORKING_Y) & SPRITEOAM_MAX_WORKING_Y)

#define SpriteGetY_LocalVar(spritePtr, _y)             \
{                                            \
    _y = (spritePtr)->unk6;                \
    _y >>= SPRITEOAM_SHIFT_WORKING_Y;            \
    _y &= SPRITEOAM_MAX_WORKING_Y;            \
}

#define SpriteSetY(spritePtr, _y) \
{ \
    u32 _ySpriteVal = _y; \
    _ySpriteVal &= SPRITEOAM_MAX_WORKING_Y; \
    _ySpriteVal <<= SPRITEOAM_SHIFT_WORKING_Y; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_WORKING_Y; \
    (spritePtr)->unk6 |= _ySpriteVal; \
}

#define SpriteAddY(spritePtr, addVal)         \
{                                                \
    u32 _yVal;                                \
    SpriteGetY_LocalVar(spritePtr, _yVal);            \
    _yVal += (addVal);                        \
    SpriteSetY(spritePtr, _yVal);              \
}

#define SpriteSetUnk6_0(spritePtr, _unk6_0) \
{ \
    u32 _unk6_0Val = _unk6_0; \
    _unk6_0Val &= SPRITEOAM_MAX_UNK6_0; \
    _unk6_0Val <<= SPRITEOAM_SHIFT_UNK6_0; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_0; \
    (spritePtr)->unk6 |= _unk6_0Val; \
}

#define SpriteGetUnk6_1(spritePtr)(((spritePtr)->unk6 >> SPRITEOAM_SHIFT_UNK6_1) & SPRITEOAM_MAX_UNK6_1)

#define SpriteSetUnk6_1(spritePtr, _unk6_1) \
{ \
    u32 _unk6_1Val = _unk6_1; \
    _unk6_1Val &= SPRITEOAM_MAX_UNK6_1; \
    _unk6_1Val <<= SPRITEOAM_SHIFT_UNK6_1; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_1; \
    (spritePtr)->unk6 |= _unk6_1Val; \
}

#define SpriteSetUnk6_2(spritePtr, _unk6_2) \
{ \
    u32 _unk6_2Val = _unk6_2; \
    _unk6_2Val &= SPRITEOAM_MAX_UNK6_2; \
    _unk6_2Val <<= SPRITEOAM_SHIFT_UNK6_2; \
    (spritePtr)->unk6 &= ~SPRITEOAM_MASK_UNK6_2; \
    (spritePtr)->unk6 |= _unk6_2Val; \
}

#endif // GUARD_SPRITE_OAM_H

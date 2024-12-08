#ifndef GUARD_SPRITE_OAM_TEMP_H
#define GUARD_SPRITE_OAM_TEMP_H

#include "sprite_oam.h"

// This file is here for temporary decomp notes about SpriteOAM. It can be deleted later when we figure it out.
// SpriteOAM initialization is handled by inlines. Potentially has inlines for other scenarios [for example: AddSprite() and AddAxSprite()]

// There is lots of testing done and evidence that it most likely is not handled by macros.
// Some funcs (such as sub_8039174) can be fakematched with "{} while(0);" contexts and a temp var. Note that it's not a "do {} while(0)" but just a "{} while(0)".
// However, that does not work for most funcs, and does not produce some of the register preloading we get with inlines.
// Also, the inlines I (kermalis) have tested with DO produce the behavior we see in all of the funcs. It just doesn't match 100% yet.

// Most of the special work seems to be done on the first two u16 of SpriteOAM.
// They are usually loaded/stored separately from the second half of the struct.
// There doesn't seem to be a logical reason for SpriteOAM to be split into two substructs, but the evidence points to it.
// AddSprite() and AddAxSprite() still haven't been matched (I'm writing this Dec 4 2024), because they suggest SpriteOAM is actually two separate substructs.
// "volatile u32/u16" was the first thing we tried, but it produces horrible asm and doesn't make sense for Chunsoft to have used it in this context.
// The main breakthrough came from producing 99% similar asm through attrib1/attrib2 being a substruct.

// Proposed struct definition:
typedef struct SpriteOAM2_Sub1
{
    u16 attrib1;
    u16 attrib2;
} SpriteOAM2_Sub1;

typedef struct SpriteOAM2_Sub2
{
    u16 attrib3;
    u16 unk6;
} SpriteOAM2_Sub2;

typedef struct SpriteOAM2
{
    SpriteOAM2_Sub1 unk0;
    SpriteOAM2_Sub2 unk2;
} SpriteOAM2;
// (It's called SpriteOAM2 temporarily to avoid conflicts with the current one)

// There seem to be 3 ways of handling SpriteOAM that I have found so far.
// #1 - When a SpriteOAM is initialized on the stack, certain inlines set its fields. This produces heavily inefficient asm but that's what they did.
// #2 - When a SpriteOAM is initialized from ram, it uses different inlines that produce way better asm. They're still known to be inlines because of the register preloading.
// #3 - Sometimes neither of the above 2's inlines are used for attrib1. It appears to be a third set of inlines (didn't attempt yet, feel free to).

// For type #3, way more testing needs to be done.
// The thing is, in all 3 scenarios, an identical order of operations is usually applied.
// The asm being nearly identical each time also makes it unlikely to be done manually without some macros or inlines.
// And this is why we haven't "real" matched many (any?) SpriteOAM funcs in the years this decomp has existed.

// Here are some helpful decomp.me links with examples.
// Type #1 - Main func (sub_8013F84) - Initializes a SpriteOAM on the stack [https://decomp.me/scratch/KYLmA]
// Type #2 - Complex fast init func (sub_8052FB8) - Loop func that initializes many SpriteOAM from ram [https://decomp.me/scratch/RX3cp]
// Type #3 - Fast init func (sub_8039174) - Initializes a SpriteOAM from ram [https://decomp.me/scratch/4qs37]



// Type #1 attrib1 inlines:

static inline void SetAttrib1(SpriteOAM2_Sub1 *sub, u32 attrib1)
{
    SpriteOAM2_Sub1 nSub = *sub;
    nSub.attrib1 = attrib1;
    *sub = nSub;
	// The only issue with this is the fact that the "ldr" happens before the "0xFFFF0000" mask is loaded.
	// The only way we have gotten the mask to load before the "ldr" is with something like this:
	//     *sub = (SpriteOAM2_Sub){ value, sub->attrib2 };
	// However, that produces bad asm. So the solution is to somehow make it a one liner like the above, while still loading from the entire "*sub" somehow.
	// This func can also be changed to simply return a SpriteOAM2_Sub1 instead of replacing the value.
	
	// BTW, making a "{} while(0)" macro for this actually folds the constants together unlike this... which is more efficient asm. Not what we want for matching lol.
	// Matching this will be a huge deal!
}

static inline void SetAffineMode1(SpriteOAM2 *s, u32 mode1)
{
    u32 valueM = mode1 & SPRITEOAM_MAX_AFFINEMODE1;
    u32 value = valueM << SPRITEOAM_SHIFT_AFFINEMODE1;

    SetAttrib1(&s->unk0, s->unk0.attrib1 & (u16)~SPRITEOAM_MASK_AFFINEMODE1);
    SetAttrib1(&s->unk0, s->unk0.attrib1 | value);
}
static inline void SetAffineMode2(SpriteOAM2 *s, u32 mode2)
{
    u32 valueM = mode2 & SPRITEOAM_MAX_AFFINEMODE2;
    u32 value = valueM << SPRITEOAM_SHIFT_AFFINEMODE2;

    SetAttrib1(&s->unk0, s->unk0.attrib1 & (u16)~SPRITEOAM_MASK_AFFINEMODE2);
    SetAttrib1(&s->unk0, s->unk0.attrib1 | value);
}
static inline void SetObjMode(SpriteOAM2 *s, u32 mode)
{
    u32 valueM = mode & SPRITEOAM_MAX_OBJMODE;
    u32 value = valueM << SPRITEOAM_SHIFT_OBJMODE;

    SetAttrib1(&s->unk0, s->unk0.attrib1 & (u16)~SPRITEOAM_MASK_OBJMODE);
    SetAttrib1(&s->unk0, s->unk0.attrib1 | value);
}
static inline void SetMosaic(SpriteOAM2 *s, u32 mosaic)
{
    u32 valueM = mosaic & SPRITEOAM_MAX_MOSAIC;
    u32 value = valueM << SPRITEOAM_SHIFT_MOSAIC;

    SetAttrib1(&s->unk0, s->unk0.attrib1 & (u16)~SPRITEOAM_MASK_MOSAIC);
    SetAttrib1(&s->unk0, s->unk0.attrib1 | value);
}
static inline void SetBPP(SpriteOAM2 *s, u32 bpp)
{
    u32 valueM = bpp & SPRITEOAM_MAX_BPP;
    u32 value = valueM << SPRITEOAM_SHIFT_BPP;

    SetAttrib1(&s->unk0, s->unk0.attrib1 & (u16)~SPRITEOAM_MASK_BPP);
    SetAttrib1(&s->unk0, s->unk0.attrib1 | value);
}
static inline void SetShape(SpriteOAM2 *s, u32 shape)
{
    u32 valueM = shape & SPRITEOAM_MAX_SHAPE;
    u32 value = valueM << SPRITEOAM_SHIFT_SHAPE;

    SetAttrib1(&s->unk0, s->unk0.attrib1 & (u16)~SPRITEOAM_MASK_SHAPE);
    SetAttrib1(&s->unk0, s->unk0.attrib1 | value);
}

// Type #2 attrib1 inlines:

static inline void FastSetAffineMode1(SpriteOAM2 *s, u32 mode1)
{
    u32 value;
    
    value = mode1 & SPRITEOAM_MAX_AFFINEMODE1;
    s->unk0.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1;
    s->unk0.attrib1 |= value << SPRITEOAM_SHIFT_AFFINEMODE1;
}
static inline void FastSetAffineMode2(SpriteOAM2 *s, u32 mode2)
{
    u32 value;
    
    value = mode2 & SPRITEOAM_MAX_AFFINEMODE2;
    s->unk0.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
    s->unk0.attrib1 |= value << SPRITEOAM_SHIFT_AFFINEMODE2;
}
static inline void FastSetObjMode(SpriteOAM2 *s, u32 mode)
{
    u32 value;
    
    value = mode & SPRITEOAM_MAX_OBJMODE;
    s->unk0.attrib1 &= ~SPRITEOAM_MASK_OBJMODE;
    s->unk0.attrib1 |= value << SPRITEOAM_SHIFT_OBJMODE;
}
static inline void FastSetMosaic(SpriteOAM2 *s, u32 mosaic)
{
    u32 value;
    
    value = mosaic & SPRITEOAM_MAX_MOSAIC;
    s->unk0.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
    s->unk0.attrib1 |= value << SPRITEOAM_SHIFT_MOSAIC;
}
static inline void FastSetBPP(SpriteOAM2 *s, u32 bpp)
{
    u32 value;
    
    value = bpp & SPRITEOAM_MAX_BPP;
    s->unk0.attrib1 &= ~SPRITEOAM_MASK_BPP;
    s->unk0.attrib1 |= value << SPRITEOAM_SHIFT_BPP;
}
static inline void FastSetShape(SpriteOAM2 *s, u32 shape)
{
    u32 value;
    
    value = shape & SPRITEOAM_MAX_SHAPE;
    s->unk0.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
    s->unk0.attrib1 |= value << SPRITEOAM_SHIFT_SHAPE;
}

// attrib2 inlines:
// These pretty much match in every scenario.
// Trying to macro-ify or make a sub-inline will remove some register preloading we rely on.

static inline void SetX(SpriteOAM2 *s, u32 x)
{
    u32 value;
    u32 valueS;
    
    value = x & SPRITEOAM_MAX_X;
    valueS = value << SPRITEOAM_SHIFT_X;
    s->unk0.attrib2 &= ~SPRITEOAM_MASK_X;
    s->unk0.attrib2 |= valueS;
}

static inline void SetMatrixNum(SpriteOAM2 *s, u32 matNum)
{
    u32 value;
    u32 valueS;
    
    value = matNum & SPRITEOAM_MAX_MATRIXNUM;
    valueS = value << SPRITEOAM_SHIFT_MATRIXNUM;
    s->unk0.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
    s->unk0.attrib2 |= valueS;
}

static inline void SetSize(SpriteOAM2 *s, u32 size)
{
    u32 value;
    u32 valueS;
    
    value = size & SPRITEOAM_MAX_SIZE;
    valueS = value << SPRITEOAM_SHIFT_SIZE;
    s->unk0.attrib2 &= ~SPRITEOAM_MASK_SIZE;
    s->unk0.attrib2 |= valueS;
}

// attrib3 inline:
// For some reason this one is all combined. Also matches pretty much every time.
// It's possible the attrib1 ones are also combined like this, but not the attrib2 ones since they're called out of order or omitted.
// And just like the attrib2 inlines, attempting to macro or inline further results in removed preloading.

static inline void SetAttrib3(SpriteOAM2 *s, u32 tileNum, u32 prio, u32 palNum)
{
    u32 value;
    u32 valueS;

    value = tileNum & SPRITEOAM_MAX_TILENUM;
    valueS = value << SPRITEOAM_SHIFT_TILENUM;
    s->unk2.attrib3 &= ~SPRITEOAM_MASK_TILENUM;
    s->unk2.attrib3 |= valueS;

    value = prio & SPRITEOAM_MAX_PRIORITY;
    valueS = value << SPRITEOAM_SHIFT_PRIORITY;
    s->unk2.attrib3 &= ~SPRITEOAM_MASK_PRIORITY;
    s->unk2.attrib3 |= valueS;

    value = palNum & SPRITEOAM_MAX_PALETTENUM;
    valueS = value << SPRITEOAM_SHIFT_PALETTENUM;
    s->unk2.attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
    s->unk2.attrib3 |= valueS;
}

// unk6 inlines:
// Basically same situation as attrib2 inlines. Can't be altered past this or combined, and matches like this.

static inline void SetUnk6_0(SpriteOAM2 *s, u32 part0)
{
    u32 value;
    u32 valueS;
    
    value = part0 & SPRITEOAM_MAX_UNK6_0;
    valueS = value << SPRITEOAM_SHIFT_UNK6_0;
    s->unk2.unk6 &= ~SPRITEOAM_MASK_UNK6_0;
    s->unk2.unk6 |= valueS;
}
static inline void SetUnk6_1(SpriteOAM2 *s, u32 part1)
{
    u32 value;
    u32 valueS;
    
    value = part1 & SPRITEOAM_MAX_UNK6_1;
    valueS = value << SPRITEOAM_SHIFT_UNK6_1;
    s->unk2.unk6 &= ~SPRITEOAM_MASK_UNK6_1;
    s->unk2.unk6 |= valueS;
}
static inline void SetUnk6_2(SpriteOAM2 *s, u32 part2)
{
    u32 value;
    u32 valueS;
    
    value = part2 & SPRITEOAM_MAX_UNK6_2;
    valueS = value << SPRITEOAM_SHIFT_UNK6_2;
    s->unk2.unk6 &= ~SPRITEOAM_MASK_UNK6_2;
    s->unk2.unk6 |= valueS;
}
// Not seen yet
/*static inline void SetUnk6_3(SpriteOAM2 *s, u32 part3)
{
    u32 value;
    u32 valueS;
    
    value = part3 & SPRITEOAM_MAX_UNK6_3;
    valueS = value << SPRITEOAM_SHIFT_UNK6_3;
    s->unk2.unk6 &= ~SPRITEOAM_MASK_UNK6_3;
    s->unk2.unk6 |= valueS;
}*/
static inline void SetUnk6_4(SpriteOAM2 *s, u32 part4)
{
    u32 value;
    u32 valueS;
    
    value = part4 & SPRITEOAM_MAX_UNK6_4;
    valueS = value << SPRITEOAM_SHIFT_UNK6_4;
    s->unk2.unk6 &= ~SPRITEOAM_MASK_UNK6_4;
    s->unk2.unk6 |= valueS;
}

#endif // GUARD_SPRITE_OAM_TEMP_H
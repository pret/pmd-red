#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

// size: 0x8
struct unkSprite
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

// size: 0x8
struct UnkSpriteLink
{
    struct UnkSpriteLink *unk0;
    struct UnkSpriteLink *unk4;
};
// size: 0x8
struct UnkSpriteLink2
{
    struct unkSprite *unk0;
    struct unkSprite *unk4;
};

// size: 0x808
struct SpriteList
{
    struct UnkSpriteLink sprites[256];
    u32 unk800;
    u32 unk804;
};

// size: 0xC
struct unkStruct_2039DB0
{
    u16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
};

void InitSprites(void);
void ResetSprites(bool8);
void sub_8004E8C(struct unkStruct_2039DB0 *);
void sub_8005180(void);

// sprite.s
extern void AddSprite(struct unkSprite *, s32, u32 *, struct unkStruct_2039DB0 *);
extern void BlinkSavingIcon(void);
extern void SetSavingIconCoords(u32);

#endif // GUARD_SPRITE_H
#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

// size: 0x8
struct UnkSpriteLink
{
    struct UnkSpriteLink *unk0;
    struct UnkSpriteLink *unk4;
};
// size: 0x808
struct SpriteList
{
    struct UnkSpriteLink sprites[16][16];
    u32 unk800;
    u32 unk804;
};

void InitSprites(void);
void ResetSprites(bool8);

// sprite.s
extern void BlinkSavingIcon(void);
extern void SetSavingIconCoords(u32);

#endif // GUARD_SPRITE_H
#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

void InitSprites(void);

// sprite.s
extern void BlinkSavingIcon(void);
extern void ResetSprites(bool32);
extern void SetSavingIconCoords(u32);

#endif // GUARD_SPRITE_H
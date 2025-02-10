#ifndef GUARD_CODE_805D8C8_H
#define GUARD_CODE_805D8C8_H

#include "file_system.h"

void CloseAllSpriteFiles(void);

void OpenDungeonPaletteFile(void);
void CloseDungeonPaletteFile(void);
void LoadDungeonPokemonSprites(void);
void LoadDungeonActivePokemonSprites(void);
void sub_80687AC(void);
OpenedFile *GetSpriteData(s32 _species);
void LoadPokemonSprite(s16 id, bool32);

#endif // GUARD_CODE_805D8C8_H

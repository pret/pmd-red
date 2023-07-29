#include "global.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "text.h"

extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];

// size: 0x1E0
struct unkStruct_203B27C
{
    bool32 isAsleep;
    s32 state;
    u32 unk8;
    s16 unkC;
    struct PokemonStruct *unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u32 unk18;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u8 fill22[0x64 - 0x22];
    u16 unk64[4];
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    struct MenuItem unk7C[8];
    u16 unkBC[8];
    struct MenuStruct unkCC;
    u8 fill11C[0x16C - 0x11C];
    struct OpenedFile *unk16C;
    u8 *unk170;
    u16 unk174;
    u16 unk176;
    u8 unk178;
    u8 unk179;
    u8 unk17A;
    struct OpenedFile **unk17C;
    struct UnkTextStruct2 unk180[4];
};

extern struct unkStruct_203B27C *gUnknown_203B27C;
void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_801FDA8(s32);

bool8 sub_801FB50(bool32 isAsleep)
{
  char *name;
  struct OpenedFile *faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B27C = MemoryAlloc(0x1E0, 0x8);
  gUnknown_203B27C->unk70 = 0;
  gUnknown_203B27C->unk74 = 0;
  gUnknown_203B27C->unk78 = 0;
  gUnknown_203B27C->isAsleep = isAsleep;
  gUnknown_203B27C->unk15 = 0;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_GULPIN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_GULPIN);
  name = GetMonSpecies(MONSTER_GULPIN);
  strcpy(gUnknown_202E1C8 - 0x50, name);
  PrintPokeNameToBuffer(gUnknown_202E1C8 - 0xF0, GetPlayerPokemonStruct());
  if (gUnknown_203B27C->isAsleep == 1) {
    gUnknown_203B27C->unk17C = 0x0;
  }
  else {
    gUnknown_203B27C->unk17C = &gUnknown_203B27C->unk16C;
  }
  faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
  gUnknown_203B27C->unk16C = faceFile;
  gUnknown_203B27C->unk170 = faceFile->data;
  gUnknown_203B27C->unk178 = '\0';
  gUnknown_203B27C->unk179 = '\0';
  gUnknown_203B27C->unk17A = '\0';
  gUnknown_203B27C->unk174 = 2;
  gUnknown_203B27C->unk176 = 8;
  sub_801FDA8(0);
  return TRUE;
}



#include "global.h"
#include "file_system.h"
#include "input.h"
#include "pokemon.h"
#include "constants/species.h"
#include "wonder_mail.h"


extern void* MemoryAlloc(u32 a, u32 b);
extern void MemoryFill8(u8 *dest, u8 value, s32 size);
extern void sub_800641C(void *r0, u8, u8);

extern struct WonderMailStruct_203B2C0 *gUnknown_203B2C0;
extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern void sub_8029B34();
extern void sub_8029AD8();
extern void sub_8029AF4();
extern void sub_8029A88();
extern void sub_8029AB0();
extern void sub_80297B8();
extern void sub_80297D4();
extern void sub_8029884();
extern void sub_8029944();
extern void sub_80299AC();
extern void sub_80299D8();
extern void sub_8029A6C();
extern void sub_8028CE0();
extern void sub_8028BF0();
extern void sub_8029A18();
extern void sub_80295A8();
extern void sub_8029668();
extern void sub_8029684();
extern void sub_8029740();
extern void sub_80295D8();
extern void sub_802979C();
extern void sub_8029358();
extern void sub_8029374();
extern void sub_802939C();
extern void sub_8028F58();
extern void sub_8028F30();
extern void sub_8028F04();
extern void sub_8028ED4();
extern void sub_80293D8();
extern void sub_80293F4();
extern void sub_8028DE8(u32);
extern void sub_8028EAC();
extern void sub_802955C();
extern void sub_80292A4();
extern void sub_80292EC();
extern void sub_802933C();
extern void sub_802958C();
extern void sub_8029208();
extern void sub_8028E84();
extern void sub_8028F80();
extern void sub_8028FC0();
extern void sub_8028FDC();
extern void sub_8028E54();
extern void sub_8028E24();
extern void sub_8028E08();
extern void sub_80290D4();
extern void sub_80290F0();
extern void sub_80291AC();
extern void sub_8029044();
extern void sub_8028CFC();
extern void sub_8028D4C();

u32 sub_8027F88(void)
{
  char *monName;
  struct OpenedFile *faceFile;
  s32 counter;

  ResetUnusedInputStruct();
  sub_800641C(0, 1, 1);
  gUnknown_203B2C0 = MemoryAlloc(sizeof(struct WonderMailStruct_203B2C0), 8);
  MemoryFill8((u8 *)gUnknown_203B2C0, 0, sizeof(struct WonderMailStruct_203B2C0));
  gUnknown_203B2C0->unk53C = 0;
  gUnknown_203B2C0->unk218 = -1;
  gUnknown_203B2C0->unk544 = -1;
  CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_PELIPPER);
  monName = GetMonSpecies(SPECIES_PELIPPER);
  strcpy(gAvailablePokemonNames, monName);
  faceFile = GetDialogueSpriteDataPtr(SPECIES_PELIPPER);
  gUnknown_203B2C0->faceFile = faceFile;
  gUnknown_203B2C0->faceData = faceFile->data;
  gUnknown_203B2C0->unk42C = 0;
  gUnknown_203B2C0->unk42D = 0;
  gUnknown_203B2C0->unk42E = 0;
  gUnknown_203B2C0->unk428 = 2;
  gUnknown_203B2C0->unk42A = 8;
  for(counter = 0; counter < 0x36; counter++){
    gUnknown_203B2C0->unk8[counter] = 0;
  }
  gUnknown_203B2C0->unk0 = 0x3D;
  sub_8028B04(0); // Set initial state to 0?
  return 1;
}

#include "global.h"
#include "file_system.h"
#include "input.h"
#include "pokemon.h"
#include "wonder_mail.h"
#include "memory.h"


extern struct WonderMailStruct_203B2C0 *gUnknown_203B2C0;
extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];

extern void sub_8029B34(void);
extern void sub_8029AD8(void);
extern void sub_8029AF4(void);
extern void sub_8029A88(void);
extern void sub_8029AB0(void);
extern void sub_80297B8(void);
extern void sub_80297D4(void);
extern void sub_8029884(void);
extern void sub_8029944(void);
extern void sub_80299AC(void);
extern void sub_80299D8(void);
extern void sub_8029A6C(void);
extern void sub_8028CE0(void);
extern void sub_8028BF0(void);
extern void sub_8029A18(void);
extern void sub_80295A8(void);
extern void sub_8029668(void);
extern void sub_8029684(void);
extern void sub_8029740(void);
extern void sub_80295D8(void);
extern void sub_802979C(void);
extern void sub_8029358(void);
extern void sub_8029374(void);
extern void sub_802939C(void);
extern void sub_8028F58(void);
extern void sub_8028F30(void);
extern void sub_8028F04(void);
extern void sub_8028ED4(void);
extern void sub_80293D8(void);
extern void sub_80293F4(void);
extern void sub_8028DE8(u32);
extern void sub_8028EAC(void);
extern void sub_802955C(void);
extern void sub_80292A4(void);
extern void sub_80292EC(void);
extern void sub_802933C(void);
extern void sub_802958C(void);
extern void sub_8029208(void);
extern void sub_8028E84(void);
extern void sub_8028F80(void);
extern void sub_8028FC0(void);
extern void sub_8028FDC(void);
extern void sub_8028E54(void);
extern void sub_8028E24(void);
extern void sub_8028E08(void);
extern void sub_80290D4(void);
extern void sub_80290F0(void);
extern void sub_80291AC(void);
extern void sub_8029044(void);
extern void sub_8028CFC(void);
extern void sub_8028D4C(void);
extern void sub_8031E10(void);
extern void sub_8023C60(void);
extern void sub_803084C(void);
extern void sub_80155F0(void);
extern void sub_80310B4(void);
extern void sub_8030DE4(void);
extern void sub_802453C(void);

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
  for(counter = 0; counter < PASSWORD_BUFFER_SIZE; counter++){
    gUnknown_203B2C0->passwordBuffer[counter] = 0;
  }
  gUnknown_203B2C0->unk0 = 0x3D;
  sub_8028B04(0); // Set initial state to 0?
  return 1;
}

u32 sub_8028078(void)
{
  
  switch(gUnknown_203B2C0->state) {
    case 0x3c:
        sub_8029B34();
        break;
    case 0x3a:
        sub_8029AD8();
        break;
    case 0x3b:
        sub_8029AF4();
        break;
    case 0x38:
        sub_8029A88();
        break;
    case 0x37:
        sub_8029AB0();
        break;
    case 0x32:
        sub_80297B8();
        break;
    case 0x33:
        sub_80297D4();
        break;
    case 0x34:
        sub_8029884();
        break;
    case 0x35:
        sub_8029944();
        break;
    case 0x31:
        sub_80299AC();
        break;
    case 0x36:
        sub_80299D8();
        break;
    case 0x30:
        sub_8029A6C();
        break;
    case 0x2e:
        sub_8029A18();
        break;
    case 0x2d:
        sub_80295A8();
        break;
    case 0x29:
        sub_8029668();
        break;
    case 0x2b:
        sub_8029684();
        break;
    case 0x2c:
        sub_8029740();
        break;
    case 0x2a:
        sub_80295D8();
        break;
    case 0x2f:
        sub_802979C();
        break;
    case 9:
        sub_8029358();
        break;
    case 0x23:
        sub_8029374();
        break;
    case 0x24:
        sub_802939C();
        break;
    case 0x26:
        sub_80293D8();
        break;
    case 0x27:
        sub_80293F4();
        break;
    case 0x28:
        sub_802955C();
        break;
    case 4:
        sub_80292A4();
        break;
    case 6:
        sub_80292EC();
        break;
    case 7:
        sub_802933C();
        break;
    case 5:
        sub_802958C();
        break;
    case 8:
        sub_8029208();
        break;
    case 0x1a:
        sub_8028DE8(1);
        break;
    case 0x1b:
        sub_8028F80();
        break;
    case 0x1c:
    case 0x1d:
        sub_8028FC0();
        break;
    case 0x22:
        sub_8028FDC();
        break;
    case 0x1e:
        sub_80290D4();
        break;
    case 0x20:
        sub_80290F0();
        break;
    case 0x21:
        sub_80291AC();
        break;
    case 0x1f:
        sub_8029044();
        break;
    case 10:
        sub_8028CFC();
        break;
    case 0xb:
        sub_8028D4C();
        break;
    case 0xd:
    case 0xf:
        sub_8028DE8(10);
        break;
    case 0x11:
        sub_8028E08();
        break;
    case 0xc:
    case 0xe:
    case 0x10:
        sub_8028DE8(0x19);
        break;
    case 0x12:
        sub_8028E24();
        break;
    case 0x13:
        sub_8028E54();
        break;
    case 0x17:
        sub_8028E84();
        break;
    case 0x18:
        sub_8028EAC();
        break;
    case 0x19:
        sub_8028ED4();
        break;
    case 0x14:
        sub_8028F04();
        break;
    case 0x15:
        sub_8028F30();
        break;
    case 0x16:
        sub_8028F58();
        break;
    case 0:
    case 1:
        sub_8028BF0();
        break;
    case 2:
    case 0x25:
    case 0x39:
        sub_8028CE0();
        break;
    case 3:
        return 3;
  }
  return 0;
}

s32 sub_80282DC(u8 *r0)
{
    *r0 = gUnknown_203B2C0->unk218;
    return gUnknown_203B2C0->unk53C;
}

void sub_80282FC(void)
{
  if (gUnknown_203B2C0 != NULL) {
    CloseFile(gUnknown_203B2C0->faceFile);
    MemoryFree(gUnknown_203B2C0);
    gUnknown_203B2C0 = NULL;
    sub_8031E10();
    sub_8023C60();
    sub_803084C();
    sub_80155F0();
    sub_80310B4();
    sub_8030DE4();
    sub_802453C();
  }
}

void nullsub_130(void)
{
}

#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "memory.h"
#include "text.h"
#include "input.h"

struct unkStruct_Gulpin
{
    u8 fill0[0x22];
    u16 unk22;
};

struct unkStruct_203B26C
{
// size: 0x18C
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s16 unkC;
    u8 unkE;
    struct unkStruct_Gulpin * unk10;
    u8 fill14[0x1C - 0x14];
    u16 unk1C;
    u8 fill20[0x28 - 0x20];
    u32 unk28;
    u8 fill2C[0x118 - 0x2C];
    /* 0x118 */ struct OpenedFile *faceFile;
    /* 0x11C */ u8 *faceData;
    /* 0x120 */ u16 unk120;
    u16 unk122;
    u8 unk124;
    u8 unk125;
    u8 unk126;
    u8 unk127;
    struct OpenedFile **unk128;
    struct UnkTextStruct2 unk12C[4]; 
};
extern struct unkStruct_203B26C *gUnknown_203B26C;
extern const struct UnkTextStruct2 gUnknown_80DC11C;
extern const struct UnkTextStruct2 gUnknown_80DC134;

extern void UpdateGulpinShopState(u32);
extern void sub_801ECBC();
extern void sub_801ED28();
extern void sub_801EDA4();
extern void sub_801EDC0();
extern void sub_801E980();
extern void sub_801EA28();
extern void sub_8012CAC(struct UnkTextStruct2 *, u32 *);
extern void sub_801EBC4();

u32 DisplayGulpinDialogueSprite(s32 param_1,s16 param_2,struct unkStruct_Gulpin *param_3)
{
  struct OpenedFile *faceFile;
  s32 param2_32;

  param2_32 = param_2; // dumb cast needed to get lsr/asr combo
  
  gUnknown_203B26C = MemoryAlloc(0x18c,8);
  gUnknown_203B26C->unk0 = param_1;
  gUnknown_203B26C->unkC = param2_32;
  gUnknown_203B26C->unk10 = param_3;
  gUnknown_203B26C->unk1C = param_3->unk22;

  if (param_1 == 0) {
   gUnknown_203B26C->unk128 = &gUnknown_203B26C->faceFile;
  }
  else {
    gUnknown_203B26C->unk128 = NULL;
  }
  faceFile = GetDialogueSpriteDataPtr(SPECIES_GULPIN);
  gUnknown_203B26C->faceFile = faceFile;
  gUnknown_203B26C->faceData = faceFile->data;

  gUnknown_203B26C->unk124 = 0;
  gUnknown_203B26C->unk125 = 0;
  gUnknown_203B26C->unk126 = 0;

  gUnknown_203B26C->unk120 = 2;
  gUnknown_203B26C->unk122 = 8;
  UpdateGulpinShopState(0);
  return 1;
}

u32 sub_801E8C0(void)
{
    switch(gUnknown_203B26C->unk4)
    {
        case 0:
        case 1:
            sub_801ECBC();
            break;
        case 2:
            sub_801ED28();
            break;
        case 3:
            sub_801EDA4();
            break;
        case 4:
            sub_801EDC0();
            if(gUnknown_203B26C->unk4 == 5)
                return 3;
            break;
        case 5:
            return 3;
        case 6:
            return 2;
    }
  return 0;
}

u8 sub_801E930(void)
{
    return gUnknown_203B26C->unkE;
}

void sub_801E93C(void)
{
    if(gUnknown_203B26C != NULL)
    {
        CloseFile(gUnknown_203B26C->faceFile);
        MemoryFree(gUnknown_203B26C);
        gUnknown_203B26C = NULL;
    }
}

void UpdateGulpinShopState(u32 newState)
{
    gUnknown_203B26C->unk4 = newState;
    sub_801E980();
    sub_801EA28();
}

void sub_801E980(void)
{
    s32 iVar2;

    sub_8006518(gUnknown_203B26C->unk12C);
    switch(gUnknown_203B26C->unk4)
    {
        case 2:
            sub_801EBC4();
            gUnknown_203B26C->unk12C[1] = gUnknown_80DC11C;
            gUnknown_203B26C->unk12C[2] = gUnknown_80DC134;
            sub_8012CAC(&gUnknown_203B26C->unk12C[2], &gUnknown_203B26C->unk28);
            break;
        default:
            for(iVar2 = 0; iVar2 < 4; iVar2++)
            {
                gUnknown_203B26C->unk12C[iVar2] = gUnknown_80DC11C;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B26C->unk12C, 1, 1);
}

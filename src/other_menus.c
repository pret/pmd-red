#include "global.h"
#include "input.h"
#include "main_menu.h"

struct unkData
{
    u8 unk0[14];
    u16 unkD;
    u16 unk10;
    u16 unk12;
    u8 *unk14;
};


struct unkStruct_203B35C
{
    // size: 0x504
    u32 unk0;
    u32 unk4; // link status?
    u32 unk8; // state var?
    u8 fillC[0x1C - 0xC];
    u32 unk1C;
    u8 fill20[0x15C - 0x20];
    struct unkData unk15C[4];
    u8 unk1BC[4];
    u32 unk1C0[9];
};
extern struct unkStruct_203B35C *gUnknown_203B35C;

extern struct unkData gUnknown_80E653C;

extern u32 gUnknown_80E66BC;
extern u32 gUnknown_80E66D4;
extern u32 gUnknown_80E6748;
extern u32 gUnknown_80E6760;
extern u32 gUnknown_80E67D4;
extern u32 gUnknown_80E67EC;
extern u32 gUnknown_80E689C;
extern u32 gUnknown_80E68B4;
extern u32 gUnknown_80E6938;
extern u32 gUnknown_80E6950;
extern u32 gUnknown_80E69B0;
extern u32 gUnknown_80E69C8;
extern u32 gUnknown_80E6A10;
extern u32 gUnknown_80E6A28;
extern u32 gUnknown_80E6A74;
extern u32 gUnknown_80E6A8C;
extern u32 gUnknown_80E6B78;
extern u32 gUnknown_80E6B90;
extern u32 gUnknown_80E6BF4;
extern u32 gUnknown_80E6C0C;
extern u32 gUnknown_80E6C50;
extern u32 gUnknown_80E6C68;
extern u32 gUnknown_80E6CD0;
extern u32 gUnknown_80E6CE8;
extern u32 gUnknown_80E6DDC;
extern u32 gUnknown_80E6DF4;
extern u32 gUnknown_80E6D54;
extern u32 gUnknown_80E6D6C;

struct unkStruct_8035D94
{
    u8 unk0;
    u8 fill[0x3];
    u32 unk4;
};

extern struct unkStruct_8035D94 *sub_8035D94();

struct unkStruct_203B460
{
    u8 unk0[0x50];
    u16 unk50[10];
};
extern struct unkStruct_203B460 *gUnknown_203B460; // TODO unify this

extern void sub_8037400(void);
extern void sub_800641C(void *, u32, u32);
extern void ResetSprites(u32);
extern void *MemoryAlloc(u32, u32);
extern void MemoryFill8(u8 *, u8, s32);
extern void MemoryFree(void *);
extern void sub_8035CF4(u32 *,u32, u32);
extern void sub_80376CC();
extern void sub_8035CC0(void *, u32);

extern u8 sub_80130A8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern u32 sub_8037C10(u32);
extern void sub_8037748(void);
extern void sub_80371B8(void);
extern void sub_8037900(void);
extern void PlayMenuSoundEffect(u32);
extern u32 sub_8037798(void);
extern void SetMenuItems(void *, void *, u32, u32 *, u32 *, u32, u32, u32);
extern void sub_8005838(u32, u32);
extern void sub_80060EC();
extern void sub_800CB20();
extern void TransferBGPaletteBuffer();
extern void xxx_call_update_bg_vram();
extern void sub_8009908();
extern void xxx_call_update_bg_sound_input();


#ifdef NONMATCHING
void sub_8036FDC(s32 param_1)
{
  int iVar3;
  int iVar4;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  ResetSprites(0);
  if (gUnknown_203B35C == NULL) {
    gUnknown_203B35C = MemoryAlloc(0x504,8);
    MemoryFill8((u8 *)gUnknown_203B35C,0,0x504);
  }

  gUnknown_203B35C->unk0 = param_1;
  gUnknown_203B35C->unk4 = 0;
  gUnknown_203B35C->unk8 = 0;
  iVar3 = 0;
  do {
    gUnknown_203B35C->unk1C0[iVar3 * 2] = 0;
    // Add statements of index flip but ends in same result
    gUnknown_203B35C->unk1BC[iVar3 * 8] = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  for(iVar4 = 0; iVar4 < 4; iVar4++){
    gUnknown_203B35C->unk15C[iVar4] = gUnknown_80E653C;
  }
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B35C->unk15C,1,1);
  SetMenuItems(&gUnknown_203B35C->unk1C,gUnknown_203B35C->unk15C,0,&gUnknown_80E6CD0,&gUnknown_80E6CE8,0,
               6,0);
  sub_8035CF4(&gUnknown_203B35C->unk1C,0,1);
  sub_80376CC();
}
#else
NAKED
void sub_8036FDC(s32 param_1)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tsub sp, 0x10\n"
	"\tadds r6, r0, 0\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tmovs r0, 0\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tmovs r0, 0\n"
	"\tbl ResetSprites\n"
	"\tldr r5, _080370C0\n"
	"\tldr r0, [r5]\n"
	"\tcmp r0, 0\n"
	"\tbne _08037016\n"
	"\tldr r4, _080370C4\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0x8\n"
	"\tbl MemoryAlloc\n"
	"\tstr r0, [r5]\n"
	"\tmovs r1, 0\n"
	"\tadds r2, r4, 0\n"
	"\tbl MemoryFill8\n"
"_08037016:\n"
	"\tldr r0, [r5]\n"
	"\tstr r6, [r0]\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [r0, 0x4]\n"
	"\tstr r1, [r0, 0x8]\n"
	"\tmovs r3, 0\n"
	"\tadds r7, r5, 0\n"
	"\tmovs r6, 0xE0\n"
	"\tlsls r6, 1\n"
	"\tmovs r4, 0\n"
	"\tmovs r5, 0xDE\n"
	"\tlsls r5, 1\n"
"_0803702E:\n"
	"\tldr r0, [r7]\n"
	"\tlsls r2, r3, 3\n"
	"\tadds r1, r0, r6\n"
	"\tadds r1, r2\n"
	"\tstr r4, [r1]\n"
	"\tadds r0, r2\n"
	"\tadds r0, r5\n"
	"\tstrb r4, [r0]\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0x1\n"
	"\tble _0803702E\n"
	"\tldr r0, _080370C0\n"
	"\tmov r12, r0\n"
	"\tmovs r5, 0xAE\n"
	"\tlsls r5, 1\n"
	"\tmov r8, r5\n"
	"\tldr r4, _080370C8\n"
	"\tmovs r3, 0\n"
	"\tmovs r2, 0x3\n"
"_08037054:\n"
	"\tmov r6, r12\n"
	"\tldr r1, [r6]\n"
	"\tadds r1, r3\n"
	"\tadd r1, r8\n"
	"\tadds r0, r4, 0\n"
	"\tldm r0!, {r5-r7}\n"
	"\tstm r1!, {r5-r7}\n"
	"\tldm r0!, {r5-r7}\n"
	"\tstm r1!, {r5-r7}\n"
	"\tadds r3, 0x18\n"
	"\tsubs r2, 0x1\n"
	"\tcmp r2, 0\n"
	"\tbge _08037054\n"
	"\tmovs r6, 0\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r5, _080370C0\n"
	"\tldr r0, [r5]\n"
	"\tmovs r4, 0xAE\n"
	"\tlsls r4, 1\n"
	"\tadds r0, r4\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r1, [r5]\n"
	"\tadds r0, r1, 0\n"
	"\tadds r0, 0x1C\n"
	"\tadds r1, r4\n"
	"\tldr r3, _080370CC\n"
	"\tldr r2, _080370D0\n"
	"\tstr r2, [sp]\n"
	"\tstr r6, [sp, 0x4]\n"
	"\tmovs r2, 0x6\n"
	"\tstr r2, [sp, 0x8]\n"
	"\tstr r6, [sp, 0xC]\n"
	"\tmovs r2, 0\n"
	"\tbl SetMenuItems\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0x1C\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_8035CF4\n"
	"\tbl sub_80376CC\n"
	"\tadd sp, 0x10\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_080370C0: .4byte gUnknown_203B35C\n"
"_080370C4: .4byte 0x00000504\n"
"_080370C8: .4byte gUnknown_80E653C\n"
"_080370CC: .4byte gUnknown_80E6CD0\n"
"_080370D0: .4byte gUnknown_80E6CE8");
}
#endif

void sub_80370D4(void)
{
    if(gUnknown_203B35C != NULL)
    {
        MemoryFree(gUnknown_203B35C);
        gUnknown_203B35C = NULL;
    }
}

// Unused
u32 sub_80370F0(void)
{
  u32 nextMenu;
  int local_10;

  local_10 = 4;
  nextMenu = MENU_NO_SCREEN_CHANGE;
  switch(gUnknown_203B35C->unk8){
      case 0:
        if (sub_80130A8(&gUnknown_203B35C->unk1C) == '\0') {
            sub_8013114(&gUnknown_203B35C->unk1C,&local_10);
        }
        if (local_10 == 4) {
            sub_8037748();
        }
        else {
            gUnknown_203B35C->unk8 = 1;
            sub_8037900();
        }
        break;
      case 1:
        sub_80376CC();
        gUnknown_203B35C->unk8 = 2;
        sub_80371B8();
        break;
      case 2:
        if (((gUnknown_203B35C->unk0 < 2) && (gUnknown_203B35C->unk4 == 0)) && (sub_8037C10(0) == 0) ) {
          return 0x29; // TODO: what screen is this?
        }
        else {
          if (sub_80130A8(&gUnknown_203B35C->unk1C) == '\0') {
            sub_8013114(&gUnknown_203B35C->unk1C,&local_10);
          }
          if (local_10 != 4) {
            PlayMenuSoundEffect(3);
            nextMenu = sub_8037798();
            gUnknown_203B35C->unk8 = 4;
          }
          sub_8037748();
        }
        break;
  }
  return nextMenu;
}

void sub_80371B8(void)
{
  struct unkStruct_8035D94 *pbVar2;
  u32 *ppuVar4;
  u32 *puVar5;
  
  puVar5 = NULL;
  ppuVar4 = NULL;
  sub_8037400();
  if ((gUnknown_203B35C->unk0 < 2) &&(gUnknown_203B35C->unk4 == 0)) {
    if (sub_8037C10(0) != 0) {
      sub_80376CC();
      sub_8035CC0(&gUnknown_203B35C->unk15C,0);
      SetMenuItems(&gUnknown_203B35C->unk1C, gUnknown_203B35C->unk15C, 0, &gUnknown_80E6C50,
                   &gUnknown_80E6C68, 0, 6, 0);
      sub_8035CF4(&gUnknown_203B35C->unk1C, 0, 1);
    }
  }
  else {
    sub_80376CC();
    sub_8035CC0(&gUnknown_203B35C->unk15C, 0);
    switch(gUnknown_203B35C->unk4) {
        case 0:
          puVar5 = &gUnknown_80E66BC;
          ppuVar4 = &gUnknown_80E66D4;
          break;
        case 3:
          puVar5 = &gUnknown_80E6D54;
          ppuVar4 = &gUnknown_80E6D6C;
          break;
        case 2:
          puVar5 = &gUnknown_80E6DDC;
          ppuVar4 = &gUnknown_80E6DF4;
          break;
        case 4:
          puVar5 = &gUnknown_80E67D4;
          ppuVar4 = &gUnknown_80E67EC;
          break;
        case 1:
        case 5:
          puVar5 = &gUnknown_80E6748;
          ppuVar4 = &gUnknown_80E6760;
          break;
        case 6:
          puVar5 = &gUnknown_80E689C;
          ppuVar4 = &gUnknown_80E68B4;
          break;
        case 7:
          puVar5 = &gUnknown_80E6938;
          ppuVar4 = &gUnknown_80E6950;
          break;
        case 9:
          puVar5 = &gUnknown_80E69B0;
          ppuVar4 = &gUnknown_80E69C8;
          break;
        case 0xb:
          puVar5 = &gUnknown_80E6A10;
          ppuVar4 = &gUnknown_80E6A28;
          break;
        case 0xd:
          puVar5 = &gUnknown_80E6A74;
          ppuVar4 = &gUnknown_80E6A8C;
          break;
        case 0xe:
          puVar5 = &gUnknown_80E6B78;
          ppuVar4 = &gUnknown_80E6B90;
          break;
        case 0xf:
          puVar5 = &gUnknown_80E6BF4;
          ppuVar4 = &gUnknown_80E6C0C;
          break;
    }
    SetMenuItems(&gUnknown_203B35C->unk1C, gUnknown_203B35C->unk15C, 0, puVar5, ppuVar4, 0, 6, 0);
    sub_8035CF4(&gUnknown_203B35C->unk1C, 0, 1);
    // TODO clean this if statement up...
    if ((((gUnknown_203B35C->unk4 != 0) &&(gUnknown_203B35C->unk0 == 0)) &&
        (pbVar2 = sub_8035D94(), pbVar2->unk0 != 0)) && (pbVar2->unk4 != 0)) {
        // We received something..
      gUnknown_203B460->unk50[pbVar2->unk0] += pbVar2->unk4;
    }
  }
}

void sub_80373C4(void)
{
  sub_8005838(0,0);
  sub_80060EC();
  sub_800CB20();
  LoadBufferedInputs();
  TransferBGPaletteBuffer();
  xxx_call_update_bg_vram();
  sub_8009908();
  xxx_call_update_bg_sound_input();
  ResetSprites(0);
}

// Unused
struct unkStruct_203B35C *sub_80373F4(void)
{
    return gUnknown_203B35C;
}

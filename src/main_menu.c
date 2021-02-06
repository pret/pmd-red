#include "global.h"

struct MainMenuSub
{
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
};

struct MainMenu
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 padding[0x20];
    /* 0x2C */ struct MainMenuSub sub;
    u32 unk30;
    u32 unk34;
    s16 unk38;
    u8 unk3A;
    u8 unk3B;
    s32 unk3C;
};

extern struct MainMenu *gUnknown_203B348;
extern void* MemoryAlloc(u32 a, u32 b);
extern void MemoryFill8(u8 *dest, u8 value, s32 size);
void sub_8035DA0(void);
extern void MemoryFree(void *);

extern void sub_8094C14(void);
extern void sub_8099690(u32);
extern void sub_8035E10(void);
extern void CreateDebugMenu(void);
extern void sub_8036400(void);
extern void sub_8036FDC(void);
extern void sub_803A1E4(void);
extern void sub_803225C(void);
extern void sub_803A1D8(void);
extern void sub_80398AC(void);
extern void sub_80382A0(void);
extern void sub_8039254(u32);
extern void sub_8035DB4(u32);
extern void sub_8038900(u32);
extern void sub_803850C(u32);
extern s32 sub_8035EEC(void);
extern s32 sub_803941C(void);
extern s32 sub_8036448(void);
extern s32 sub_8032318(void);
extern s32 sub_8039928(void);
extern s32 sub_803A1DC(void);
extern s32 sub_803A1E8(void);
extern s32 sub_8038A90(void);
extern s32 sub_80382C0(void);
extern s32 sub_80383D4(void);
extern s32 sub_8038630(void);
extern s32 sub_803A2A4(void);

extern void sub_8035EC0(void);
extern void sub_80393F0(void);
extern void sub_8036B04(void);
extern void sub_80370D4(void);
extern void sub_80327E4(void);
extern void sub_80399E4(void);
extern void nullsub_55(void);
extern void sub_803A1EC(void);
extern void sub_8038A5C(void);
extern void sub_80382AC(void);
extern void sub_80383A8(void);
extern void sub_8038604(void);
extern void DeleteDebugMenu(void);

void InitMainMenu(void)
{
  if (gUnknown_203B348 == NULL) {
    gUnknown_203B348 = MemoryAlloc(sizeof(struct MainMenu),8);
    MemoryFill8((u8 *)gUnknown_203B348, 0, sizeof(struct MainMenu));
  }
  gUnknown_203B348->unk0 = 0xffdc;
  gUnknown_203B348->unk4 = 1;
  gUnknown_203B348->unk8 = 1;
  gUnknown_203B348->unk38 = -1;
  gUnknown_203B348->unk3C = -1;
  gUnknown_203B348->sub.unk2E = 0;
  gUnknown_203B348->sub.unk2C = 1;
  gUnknown_203B348->sub.unk2D = 0;
  sub_8035DA0();
  gUnknown_203B348->unk3A = 0;
}

void DeleteMainMenu(void)
{
    if(gUnknown_203B348){
        MemoryFree(gUnknown_203B348);
        gUnknown_203B348 = NULL;
    }
}

void SetUpMenu(void)
{
  if (gUnknown_203B348->unk0 != gUnknown_203B348->unk4) {
    switch(gUnknown_203B348->unk4) {
        case 1:
            sub_8094C14();
            sub_8099690(0);
            sub_8035E10();
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            sub_8039254(gUnknown_203B348->unk4);
            break;
        case 0xc:
            sub_8036400();
            break;
        case 0x13:
        case 0x14:
            sub_8035DB4(gUnknown_203B348->unk4);
            sub_8036FDC();
            break;
        case 0xb:
            sub_803225C();
            break;
        case 0xd:
            sub_80398AC();
            break;
        case 0xe:
            sub_803A1D8();
            break;
        case 0xf:
            sub_803A1E4();
            break;
        case 0x21:
        case 0x22:
            sub_8038900(gUnknown_203B348->unk4);
            break;
        case 0xA:
            sub_80382A0();
            break;
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
            sub_803850C(gUnknown_203B348->unk4);
            break;
        case 0x10:
            CreateDebugMenu();
            break;
    }
    gUnknown_203B348->unk0 = gUnknown_203B348->unk4;
  }
}

s32 UpdateMenu(void)
{
  s32 iVar1;
  s32 iVar2;

  iVar2 = 0xffdc;
  switch(gUnknown_203B348->unk4) {
    case 1:
        iVar2 = sub_8035EEC();
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        iVar2 = sub_803941C();
        break;
    case 0xc:
        iVar1 = sub_8036448();
        iVar2 = 1;
        if (iVar1 != 3) {
            iVar2 = 0xffdc;
        }
        break;
    case 0xb:
        iVar1 = sub_8032318();
        iVar2 = 1;
        if (iVar1 != 3) {
            iVar2 = 0xffdc;
        }
        break;
    case 0xd:
        iVar1 = sub_8039928();
        iVar2 = 1;
        if (iVar1 != 3) {
            iVar2 = 0xffdc;
        }
        break;
    case 0xe:
        iVar1 = sub_803A1DC();
        iVar2 = 1;
        if (iVar1 != 3) {
            iVar2 = 0xffdc;
        }
        break;
    case 0xf:
        iVar1 = sub_803A1E8();
        iVar2 = 5;
        if ((iVar1 != 3) && (iVar2 = 0xffdc, iVar1 == 2)) {
            iVar2 = 1;
        }
        break;
    case 0x21:
    case 0x22:
        iVar2 = sub_8038A90();
        break;
    case 10:
        iVar2 = sub_80382C0();
        break;
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
        iVar2 = sub_80383D4();
        break;
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
        iVar2 = sub_8038630();
        break;
    case 0x10:
        iVar2 = sub_803A2A4();
        break;
  }
  if (iVar2 != 0xffdc) {
    gUnknown_203B348->unk4 = iVar2;
  }
  return iVar2;
}

void CleanUpMenu(void)
{
  if (gUnknown_203B348->unk8 != gUnknown_203B348->unk4) {
    switch(gUnknown_203B348->unk8) {
    case 1:
      sub_8035EC0();
      break;
    case 6:
    case 7:
    case 8:
    case 9:
      sub_80393F0();
      break;
    case 0xc:
      sub_8036B04();
      break;
    case 0x13:
    case 0x14:
      sub_80370D4();
      break;
    case 0xb:
      sub_80327E4();
      break;
    case 0xd:
      sub_80399E4();
      break;
    case 0xe:
      nullsub_55();
      break;
    case 0xf:
      sub_803A1EC();
      break;
    case 0x21:
    case 0x22:
      sub_8038A5C();
      break;
    case 10:
      sub_80382AC();
      break;
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
      sub_80383A8();
      break;
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
      sub_8038604();
      break;
    case 0x10:
      DeleteDebugMenu();
      break;
    }
    gUnknown_203B348->unk8 = gUnknown_203B348->unk4;
  }
}

// Unused
void sub_8035C00(struct MainMenuSub *param)
{
    gUnknown_203B348->sub = *param;
}

// Unused
struct MainMenuSub *sub_8035C10(void)
{
   return &gUnknown_203B348->sub;
}

void sub_8035C1C(void)
{
    gUnknown_203B348->sub.unk2E = 0;
    gUnknown_203B348->sub.unk2C = 1;
    gUnknown_203B348->sub.unk2D = 0;
}

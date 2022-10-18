#include "global.h"
#include "debug.h"


extern u32 gUnknown_8116588;
extern u32 gUnknown_8116538;
extern u32 gUnknown_8116560;

extern u8 gUnknown_8116594[];
extern u8 gUnknown_8116544[];
extern u8 gUnknown_811656C[];


struct GroundScript_ExecutePP_3
{
    // size: 0xC
    u32 unk0;
    s16 scriptType;
    s16 unk6;
    u8 unk8;
};

struct GroundScript_ExecutePP_1_sub
{
    // size: 0x60
    /* 0x0 */ s16 scriptType;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u32 unk8;
    /* 0xC */ u16 unkC;
    /* 0xE */ u8 unkE;
    /* 0xF */ u8 fillF;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u8 fill3C[0x26 - 0x18];
    /* 0x26 */ u32 unk26;
    u8 fill50[0x60 - 0x2A];
} __attribute__((packed));

typedef void (*Callback)(u32, void *);
struct GroundScript_ExecutePP_1_sub2
{
    Callback callbacks[10]; // IDK the size..
};

struct GroundScript_ExecutePP_1
{
    struct GroundScript_ExecutePP_1_sub2 *unk0;
    u32 unk4;
    u32 fill8;
    u32 unkC;
    u32 fill10;
    u8 fill18[0x24 - 0x14];
    struct GroundScript_ExecutePP_1_sub unk24;
    struct GroundScript_ExecutePP_1_sub unk84;
};

extern void sub_809D520(void *);
extern void sub_809D568(void *);
extern void sub_809D6E4(struct GroundScript_ExecutePP_1 *, struct GroundScript_ExecutePP_3 *, s32);
void FatalError(u32 *, const char *, ...) __attribute__((noreturn));

bool8 GroundScript_ExecutePP(struct GroundScript_ExecutePP_1 *param_1, s32 *param_2, struct GroundScript_ExecutePP_3 *param_3, struct DebugLocation *unused)
{
  if ((param_3 == NULL) || (param_3->unk0 == 0)) {
    return FALSE;
  }
  switch(param_3->scriptType) {
    case 2:
    case 3:
        if (param_1->unk24.scriptType == 1) {
            memcpy(&param_1->unk84, &param_1->unk24, 0x60);
            break;
        }
        if (param_1->unk24.scriptType == 5) {
            sub_809D568(&param_1->unk84);
        }
        break;
    case 5:
        if (param_1->unk24.scriptType != 2) {
            // "execute script type error B"
            FatalError(&gUnknown_8116538, gUnknown_8116544);
        }
        if (param_1->unk84.scriptType != -1) {
            // "execute script type error C"
            FatalError(&gUnknown_8116560, gUnknown_811656C);
        }
        memcpy(&param_1->unk84, &param_1->unk24, 0x60);
        break;
    case 0:
        if (param_1->unk24.scriptType != 1) goto _0809D84A;
        memcpy(&param_1->unk84, &param_1->unk24, 0x60);
        break;
    case 1:
_0809D84A:
        sub_809D568(&param_1->unk84);
        break;
    default:
        // "execute script type error %d"
        FatalError(&gUnknown_8116588, gUnknown_8116594, param_3->scriptType);
  }
  sub_809D568(&param_1->unk24);
  if (param_2 != NULL) {
    param_1->unkC = param_2[0];
  }
  else {
    sub_809D520(&param_1->unkC);
  }
  param_1->unk24.scriptType = param_3->scriptType;
  param_1->unk24.unk2 = 3;
  param_1->unk24.unkC = param_3->unk6;
  param_1->unk24.unkE = param_3->unk8;
  param_1->unk24.unk4 = param_3->unk0;
  param_1->unk24.unk8 = param_3->unk0;
  param_1->unk24.unk10 = 0;
  param_1->unk24.unk14 = 0;

  if (param_1->unk0->callbacks[5] != 0) {
    param_1->unk0->callbacks[5](param_1->unk4, &param_1->unk24.unk26);
  }
  return TRUE;
}

bool8 sub_809D8C0(struct GroundScript_ExecutePP_1 *param_1, s32 *param_2, s16 param_3, struct DebugLocation *debug)
{
  struct GroundScript_ExecutePP_3 auStack28;
  
  sub_809D6E4(param_1,&auStack28,param_3);
  return GroundScript_ExecutePP(param_1, param_2, &auStack28, debug);
}

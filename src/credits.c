#include "global.h"
#include "code_8098DBC.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"

// size: 0x6C
struct unkCreditsStruct_203B340
{
    UnkTextStruct2 unk0[4];
    s32 unk60; // Unsure if s32/u32/ptr
    s32 unk64;
    /* 0x68 */ s32 creditsCategoryIndex;
};

// size: 0x8
struct unkCreditsStruct_203B344
{
    /* 0x0 */ u32 state; // state variable
    u32 unk4; // timer?
};

// size: 0xC
struct CreditsData
{
    /* 0x0 */ s16 type;
    s16 x;
    s16 y;
    /* 0x8 */ u8 *text;
};

EWRAM_DATA_2 struct unkCreditsStruct_203B340 *gUnknown_203B340 = {0};
EWRAM_DATA_2 struct unkCreditsStruct_203B344 *gUnknown_203B344 = {0};

extern UnkTextStruct2 gUnknown_80E4A10;
extern UnkTextStruct2 gUnknown_80E4A28;
extern const u32 gUnknown_80E4A40[];
extern struct CreditsData* gCreditsTable[27];
extern u16 gUnknown_80E5990[];

extern void sub_80015C0(u32, u32);
extern void sub_8099A5C(u32, u32, u32);
extern void sub_8099AFC(u32, u32, u32);
extern u8 sub_8099B94();

// Unsure if param_2 is a s32/u32/ptr
s32 DrawCredits(s32 creditsCategoryIndex, s32 param_2)
{
    s32 i;
    s32 x;
    s32 y;
    struct CreditsData *cred;
    u8 *srcText;
    u8 *destText1;
    u8 *destText2;
    u8 curChar;
    u8 buffer[128];
    
    gUnknown_203B340 = MemoryAlloc(sizeof(struct unkCreditsStruct_203B340), 8);
    gUnknown_203B340->unk60 = 0;
    gUnknown_203B340->unk64 = param_2;
    gUnknown_203B340->creditsCategoryIndex = creditsCategoryIndex;

    for (i = 0; i < 4; i++)
        gUnknown_203B340->unk0[i] = gUnknown_80E4A10;
    gUnknown_203B340->unk0[0] = gUnknown_80E4A28;

    ResetUnusedInputStruct();
    sub_800641C(&gUnknown_203B340->unk0[0], TRUE, TRUE);
    sub_8099690(2);
    sub_80073B8(0);

    cred = creditsCategoryIndex[gCreditsTable]; // WTF
    y = 0;
    while (cred->text != NULL) {
        srcText = cred->text;
        if (cred->y >= 0)
            y = cred->y;
        else
            y -= cred->y;
        x = cred->x;

        switch (cred->type) {
            case 1:
                destText1 = buffer;
                while ((curChar = *srcText) != 0) {
                    *destText1 = curChar;
                    srcText++;
                    destText1++;
                }
                *destText1 = 0;
                srcText = buffer;
                break;
            case 2:
                destText2 = buffer;
                while ((curChar = *srcText) != 0) {
                    *destText2 = curChar;
                    srcText++;
                    destText2++;
                }
                *destText2 = 0;
                srcText = buffer;
                break;
        }

        xxx_call_draw_string(x, y, srcText, 0, 0);
        cred++;
    }
    
    sub_80073E0(0);
    SelectCharmap(0);
    do {
        const u32 *a = gUnknown_80E4A40;
        int b = 9;
        unsigned long long c = b;
        sub_8099AFC(c, 0, a[0]);
    } while(0);
    return 1;
}

s32 sub_8035574(void)
{
    #ifdef NONMATCHING
    u32 const *p;
    #else
    register u32 const *p asm("r2");
    #endif

    switch (gUnknown_203B340->unk60) {
        case 0:
            if (sub_8099B94() == 0) {
                gUnknown_203B340->unk60 = 1;
                p = gUnknown_80E4A40;
                sub_8099A5C(9, 30, p[0]); // Probably same/similar macro from the above func - Kermalis
            }
            break;
        case 1:
            if (sub_8099B94() == 0)
                gUnknown_203B340->unk60 = 2;
            break;
        case 2:
            if (gUnknown_203B340->unk64 < 1) {
                gUnknown_203B340->unk60 = 3;
                p = gUnknown_80E4A40;
                sub_8099AFC(9, 30, p[0]);
            }
            gUnknown_203B340->unk64--;
            break;
        case 3:
            if (sub_8099B94() == 0) {
                ResetUnusedInputStruct();
                sub_800641C(NULL, TRUE, TRUE);
                gUnknown_203B340->unk60 = 4;
            }
            break;
        case 4:
            sub_8099690(0);
            p = gUnknown_80E4A40;
            sub_8099A5C(1, 0, p[0]);
            return 3;
    }
    return 0;
}

// Frees gUnknown_203B340
void sub_803565C(void)
{
    if (gUnknown_203B340 != NULL) {
        MemoryFree(gUnknown_203B340);
        gUnknown_203B340 = NULL;
    }
}

u32 sub_8035678(void)
{
    gUnknown_203B344 = MemoryAlloc(sizeof(struct unkCreditsStruct_203B344), 8);
    gUnknown_203B344->state = 0;
    gUnknown_203B344->unk4 = 0;
    sub_80015C0(0, 0x39);
    return 1;
}

u32 sub_80356A0(void)
{
  u16 uVar1;
  u16 held_input;

  held_input = gRealInputs.held;
  uVar1 = gUnknown_80E5990[gUnknown_203B344->unk4];

  switch (gUnknown_203B344->state) {
      case 0:
        gUnknown_203B344->state = 3;
        break;
      case 1:
        if (uVar1 == 0)
          gUnknown_203B344->state = 4;
        else {
          if (held_input == uVar1)
            gUnknown_203B344->state = 2;
          else {
            // NOTE: couldn't match with OR'd condition so split up to match
            if ((uVar1 & held_input) != held_input)
                gUnknown_203B344->state = 3;
            else
            {
                if (gUnknown_203B344->unk4 == 0)
                    gUnknown_203B344->state = 3;
            }
          }
        }
        break;
      case 2:
        if (held_input == 0) {
          gUnknown_203B344->state = 1;
          gUnknown_203B344->unk4++;
        }
        else {
          if ((uVar1 & held_input) != held_input)
              gUnknown_203B344->state = 3;
        }
        break;
      case 3:
        return 2;
      case 4:
        return 3; // sub_809C478 clears the flash data when this is returned
  }

  if (sub_8001658(0, 0x39) != 0) {
    gUnknown_203B344->state = 3;
    return 2;
  }
  else
    return 0;
}

// Frees gUnknown_203B344
void sub_8035758(void)
{
    if (gUnknown_203B344 != NULL) {
        MemoryFree(gUnknown_203B344);
        gUnknown_203B344 = NULL;
    }
}

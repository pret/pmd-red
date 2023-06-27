#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"

#define MAX_HINTS 5

struct Hints
{
    u8 *heading;
    u8 *body;
};

struct unkStruct_203B268
{
    // size: 0xA0
    struct MenuInputStruct input;
    u32 unk34;
    struct UnkTextStruct2 *unk38;
    struct UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

struct unkStruct_203B264
{
    // size: 0x9C
    struct MenuInputStruct input;
    u32 unk34;
    struct UnkTextStruct2 *unk38;
    struct UnkTextStruct2 unk3C[4];
};

extern struct unkStruct_203B264 *gUnknown_203B264;

extern struct unkStruct_203B268 *gUnknown_203B268;

extern struct UnkTextStruct2 gUnknown_80DC0A0;
extern struct UnkTextStruct2 gUnknown_80DC0BC;
extern struct UnkTextStruct2 gUnknown_80DC0E4;
extern struct UnkTextStruct2 gUnknown_80DC0FC;
extern struct Hints gGameHints[MAX_HINTS];
extern u8 gUnknown_80DC0D4[MAX_HINTS];

extern void sub_801E714(void);
extern void sub_8013818(void *, u32, u32, u32);
extern bool8 sub_8013938(void *);
extern s32 GetKeyPress(void *);
extern void PlayMenuSoundEffect(u32);
extern void sub_801E714(void);
extern void sub_801E76C(void);
extern void DisplayChosenHint(void);
extern void xxx_call_draw_string(s32, u32, u8 *, u32, u32);
extern void sub_80073E0(u32);
extern void sub_80073B8(u32);
extern s32 sub_8013800(void *, u32);
extern void sub_8008C54(u32);
void DrawHintSelectionMenu(void);
void sub_801E594(void);
void sub_8013984(void *);
void AddMenuCursorSprite(struct MenuInputStruct *);
extern u8 sub_80138B8(struct MenuInputStruct *, u32);
extern void sub_8013660(struct MenuInputStruct *);
extern void sub_8012D08(struct UnkTextStruct2 *, u32);

u32 sub_801E3F0(u32 r0)
{
    if(gUnknown_203B264 == NULL)
        gUnknown_203B264 = MemoryAlloc(sizeof(struct unkStruct_203B264), 8);
    gUnknown_203B264->unk34 = r0;
    gUnknown_203B264->unk38 = &gUnknown_203B264->unk3C[r0];
    sub_8006518(gUnknown_203B264->unk3C);
    gUnknown_203B264->unk3C[gUnknown_203B264->unk34] = gUnknown_80DC0BC;
    sub_8012D08(gUnknown_203B264->unk38, 0xA);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B264->unk3C, 1, 1);
    sub_8013818(gUnknown_203B264, 0x5, 0xA, r0);
    sub_801E594();
    DrawHintSelectionMenu();
    return 1;
}

u32 sub_801E474(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B264->input);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B264->input))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if(sub_80138B8(&gUnknown_203B264->input, 1))
            {
                sub_801E594();
                DrawHintSelectionMenu();
                return 1;
            }
            else
                return 0;
    }
}

s32 GetChosenHintIndex(void)
{
    return (gUnknown_203B264->input.unk1E * gUnknown_203B264->input.unk1C) + gUnknown_203B264->input.menuIndex;
}

void CreateHintSelectionScreen(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B264->unk3C, 0, 0);
    sub_8013984(gUnknown_203B264);
    sub_801E594();
    DrawHintSelectionMenu();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B264->input);
}

void sub_801E54C(void)
{
    if(gUnknown_203B264 != NULL)
    {
        gUnknown_203B264->unk3C[gUnknown_203B264->unk34] = gUnknown_80DC0A0;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B264->unk3C, 1, 1);
        MemoryFree(gUnknown_203B264);
        gUnknown_203B264 = NULL;
    }
}

NAKED
void sub_801E594(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _0801E5E4\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x1A\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x34]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x4A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x4C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801E5E4: .4byte gUnknown_203B264");
}

void DrawHintSelectionMenu(void)
{
    s32 hintIndex;
    s32 y;

    sub_8008C54(gUnknown_203B264->unk34);
    sub_80073B8(gUnknown_203B264->unk34);
    xxx_call_draw_string(16, 0, gUnknown_80DC0D4, gUnknown_203B264->unk34, 0);
    for(hintIndex = 0; hintIndex < MAX_HINTS; hintIndex++)
    {
        y = sub_8013800(gUnknown_203B264, hintIndex);
        xxx_call_draw_string(10, y, gGameHints[hintIndex].heading, gUnknown_203B264->unk34, 0);
    }
    sub_80073E0(gUnknown_203B264->unk34);
}

u32 CreateHintDisplayScreen(u32 index)
{
    gUnknown_203B268 = MemoryAlloc(sizeof(struct unkStruct_203B268), 8);
    gUnknown_203B268->unk34 = 0;
    gUnknown_203B268->unk38 = gUnknown_203B268->unk3C;
    sub_8006518(gUnknown_203B268->unk3C);
    gUnknown_203B268->unk3C[gUnknown_203B268->unk34] = gUnknown_80DC0FC;
    gUnknown_203B268->unk38->unk14 = gUnknown_203B268->unk9C;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B268->unk3C, 1, 1);
    sub_8013818(gUnknown_203B268, 5, 1, gUnknown_203B268->unk34);
    gUnknown_203B268->input.unk1E = index;
    sub_801E714();

    return 1;
}

u32 HandleHintDisplayScreenInput(void)
{
    switch(GetKeyPress(gUnknown_203B268))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if(sub_8013938(gUnknown_203B268)){
                sub_801E714();
                return 1;
            }
            else
                return 0;
    }
}

void sub_801E714(void)
{
    sub_801E76C();
    DisplayChosenHint();
}

void DestroyHintDisplayScreen(void)
{
    if(gUnknown_203B268 != NULL)
    {
        gUnknown_203B268->unk3C[gUnknown_203B268->unk34] = gUnknown_80DC0E4;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B268->unk3C, 1, 1);
        MemoryFree(gUnknown_203B268);
        gUnknown_203B268 = NULL;
    }
}

void sub_801E76C(void)
{
    gUnknown_203B268->unk9C[0] = gUnknown_203B268->input.unk20;
    gUnknown_203B268->unk9C[1] = gUnknown_203B268->input.unk1E;
    gUnknown_203B268->unk9C[2] = 0xF;
    gUnknown_203B268->unk9C[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B268->unk3C, 1, 1);
}

void DisplayChosenHint(void)
{
    sub_80073B8(gUnknown_203B268->unk34);
    xxx_call_draw_string((gUnknown_203B268->input.unk1E << 3) + 0x10, 0, gGameHints[gUnknown_203B268->input.unk1E].heading, gUnknown_203B268->unk34, 0);
    xxx_call_draw_string(0xA, 0x14, gGameHints[gUnknown_203B268->input.unk1E].body, gUnknown_203B268->unk34, 0);
    sub_80073E0(gUnknown_203B268->unk34);
}

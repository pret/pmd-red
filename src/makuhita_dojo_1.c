#include "global.h"
#include "constants/colors.h"
#include "constants/dungeon.h"
#include "constants/input.h"
#include "code_800D090.h"
#include "dungeon.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "makuhita_dojo.h"
#include "menu_input.h"

// size: 0xD0
struct unkStruct_203B31C
{
    s16 unk0[NUM_DUNGEON_MAZE];
    /* 0x30 */ struct MenuInputStruct input;
    u32 unk64;
    struct UnkTextStruct2 *unk68;
    struct UnkTextStruct2 unk6C[4];
    u8 unkCC[4];
};

extern struct unkStruct_203B31C *gUnknown_203B31C;
extern struct unkStruct_203B318 *gUnknown_203B318;

static const u8 makuhita_dojo_fill[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80E07EC = {
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};
const struct UnkTextStruct2 gUnknown_80E0804 = {
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x0E, 0x0E,
    0x0E, 0x00,
    NULL
};

const u8 gMakuhitaDojoHeader[] = "Courses";
ALIGNED(4) const u8 gUnknown_80E0824[] = _("{STAR_BULLET}");
ALIGNED(4) const u8 gMakuhitaCoursePlaceholder[] = _("{COLOR_2}%c%s{END_COLOR_TEXT_2}");
static const u8 makuhita_dojo_fill2[] = "pksdir0";

extern u8 gMakuhitaDojoGoTrain[];
extern u8 *gUnknown_80D4934[];
extern u8 *gUnknown_80D4970[];

extern bool8 sub_8097504(s16);
extern s16 sub_80A26CC(s16 r0);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u8 sub_80A2740(s32 r0);
extern s16 sub_80A2668(u32 r0);
extern s32 sub_8013800(void *, u32);
extern bool8 IsMazeCompleted(s32);
extern s32 sub_8030668(void);
extern void sub_8013984(void *);
extern void sub_80304C8();
extern void AddMenuCursorSprite(struct MenuInputStruct *);
extern void DrawDojoCourseList(void);

extern u8 sub_80138B8(void *, u32);
extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(void *);
extern void sub_8013660(void *);
extern void sub_8013818(void *, u32, u32, u32);
extern void sub_803053C(void);
extern u8 sub_80306A4(void);
extern s32 sub_80144A4(s32 *);
void UpdateMakuhitaState(s32);
extern u32 sub_801B6AC(void);
extern void sub_801B72C(void);
extern s16 sub_8030418(void);
extern u32 sub_80303AC(u8);
extern void sub_8030480(void);


void DrawMakuhitaMainMenu(void) {

    s32 loopMax;

    gUnknown_203B318->menuAction = 2;
    loopMax = 0;
    gUnknown_203B318->unk18[loopMax].text = gMakuhitaDojoGoTrain;
    gUnknown_203B318->unk18[loopMax].menuAction = 2;
    if (sub_80306A4()) {
        gUnknown_203B318->unk18[loopMax].menuAction = -1;
        gUnknown_203B318->menuAction = 1;
    }
    loopMax += 1;
    gUnknown_203B318->unk18[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B318->unk18[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B318->unk18[loopMax].text = *gUnknown_80D4934;
    gUnknown_203B318->unk18[loopMax].menuAction = 1;
    loopMax += 1;
    gUnknown_203B318->unk18[loopMax].text = NULL;
    gUnknown_203B318->unk18[loopMax].menuAction = 1;
}

void sub_8030208(void)
{
    s32 menuAction;
    if (sub_80144A4(&menuAction) == 0) {
        gUnknown_203B318->menuAction = menuAction;
        switch (menuAction) {
            case 2:
                UpdateMakuhitaState(3);
                break;
            case 3:
                UpdateMakuhitaState(12);
                break;
            case 1:
                UpdateMakuhitaState(2);
                break;
        }
    }
}

void sub_8030258(void)
{
    switch (sub_80303AC(1)) {
        case 3:
            gUnknown_203B318->unk10 = sub_8030418();
            sub_8030480();
            UpdateMakuhitaState(5);
            break; 
        case 2:
            sub_8030480();
            gUnknown_203B318->unk10 = -1;
            UpdateMakuhitaState(1);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_80302A8(void)
{
    switch (sub_801B6AC()) {
        case 2:
        case 3:
            sub_801B72C();
            UpdateMakuhitaState(0xA);
            break;
        case 0:
        case 1:
            break;
    }
}

void GotoMakuhitaFallbackState(void)
{
    s32 temp;
    if (sub_80144A4(&temp) == 0)
        UpdateMakuhitaState(gUnknown_203B318->fallbackState);
}

bool8 sub_80302E8(int param_1, struct UnkTextStruct2_sub *param_2, u32 param_3)
{
    if (sub_80306A4())
        return 0;

    if (gUnknown_203B31C == NULL)
        gUnknown_203B31C = MemoryAlloc(sizeof(struct unkStruct_203B31C), 8);

    gUnknown_203B31C->unk64 = param_1;
    gUnknown_203B31C->unk68 = &gUnknown_203B31C->unk6C[param_1];
    sub_8006518(gUnknown_203B31C->unk6C);
    gUnknown_203B31C->unk6C[gUnknown_203B31C->unk64] = gUnknown_80E0804;
    gUnknown_203B31C->unk68->unk14 = gUnknown_203B31C->unkCC;

    if (param_2 != NULL)
        gUnknown_203B31C->unk6C[gUnknown_203B31C->unk64].unk8 = *param_2;

    sub_8012D08(gUnknown_203B31C->unk68,param_3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B31C->unk6C,1,1);
    sub_8013818(&gUnknown_203B31C->input,sub_8030668(),param_3,param_1);
    sub_80304C8();
    DrawDojoCourseList();
    return 1;
}

u32 sub_80303AC(u8 param_1)
{
  if (param_1 == 0) {
    sub_8013660(&gUnknown_203B31C->input);
    return 0;
  }

  switch (GetKeyPress(&gUnknown_203B31C->input)) {
    case INPUT_B_BUTTON:
        PlayMenuSoundEffect(1);
        return 2;
    case INPUT_A_BUTTON:
        PlayMenuSoundEffect(0);
        return 3;
    default:
        if (sub_80138B8(&gUnknown_203B31C->input, 1)) {
            sub_80304C8();
            DrawDojoCourseList();
            return 1;
        }
        else
            return 0;
  }
}

s16 sub_8030418(void)
{
    return gUnknown_203B31C->unk0[(gUnknown_203B31C->input.unk1E * gUnknown_203B31C->input.unk1C) + gUnknown_203B31C->input.menuIndex];
}

void sub_8030444(u8 r0)
{
    gUnknown_203B31C->input.unk22 = sub_8030668();
    sub_8013984(&gUnknown_203B31C->input);
    sub_80304C8();
    DrawDojoCourseList();
    if (r0)
       AddMenuCursorSprite(&gUnknown_203B31C->input);
}

void sub_8030480(void)
{
    if (gUnknown_203B31C != NULL) {
        gUnknown_203B31C->unk6C[gUnknown_203B31C->unk64] = gUnknown_80E07EC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B31C->unk6C, 1, 1);
        MemoryFree(gUnknown_203B31C);
        gUnknown_203B31C = NULL;
    }
}

NAKED
void sub_80304C8(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _08030538\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xCC\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xCD\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xCE\n"
	"\tmovs r1, 0x8\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xCF\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x4A\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x64]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x7A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x64]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x7C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x6C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08030538: .4byte gUnknown_203B31C");
}

void DrawDojoCourseList(void)
{
    u8 dungeonIndex;
    s32 mazeIndex;
    s32 y;
    s32 iVar6;
    u32 color;
    s32 index;
    u8 buffer[256];

    sub_8008C54(gUnknown_203B31C->unk64);
    sub_80073B8(gUnknown_203B31C->unk64);
    xxx_call_draw_string(10, 0, gMakuhitaDojoHeader,gUnknown_203B31C->unk64, 0); // Courses
    sub_8012BC4(gUnknown_203B31C->unkCC[2] * 8 + 4, 0, gUnknown_203B31C->input.unk1E + 1, 2, 7, gUnknown_203B31C->unk64);

    for (index = 0; index < gUnknown_203B31C->input.unk1A; index++) {
        iVar6 = gUnknown_203B31C->unk0[gUnknown_203B31C->input.unk1E * gUnknown_203B31C->input.unk1C + index];
        dungeonIndex = sub_80A2740(iVar6);

        mazeIndex = sub_80A2668(iVar6);

        y = sub_8013800(&gUnknown_203B31C->input, index);
        color = COLOR_WHITE_2; // COLOR_WHITE again?
        if (IsMazeCompleted(mazeIndex)) {
            xxx_call_draw_string(8, y, gUnknown_80E0824, gUnknown_203B31C->unk64, 0); // Draw Star symbol
            color = COLOR_GREEN;
        }
        sprintfStatic(buffer, gMakuhitaCoursePlaceholder, color, GetDungeonName1(dungeonIndex)); // "#c%c%s#r"
        xxx_call_draw_string(0x10, y, buffer, gUnknown_203B31C->unk64, 0);
    }
    sub_80073E0(gUnknown_203B31C->unk64);
}

s32 sub_8030668(void)
{
  s32 index;
  s32 counter;
  
  counter = 0;

  for (index = 0; index < NUM_DUNGEON_MAZE; index++) {
    if (sub_8097504(index)) {
      gUnknown_203B31C->unk0[counter] = sub_80A26CC(index);
      counter++;
    }
  }
  return counter;
}

bool8 sub_80306A4(void)
{
    return FALSE;
}
#include "global.h"
#include "sprite.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text.h"
#include "code_8009804.h"
#include "bg_palette_buffer.h"
#include "string_format.h"
#include "code_800D090.h"
#include "friend_area.h"
#include "bg_control.h"
#include "code_800558C.h"
#include "game_options.h"
#include "play_time.h"
#include "code_80118A4.h"
#include "code_800C9CC.h"
#include "pokemon.h"
#include "decompress.h"
#include "constants/direction.h"

extern u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_);
extern void sub_801178C(void);
extern void sub_80117C4(void);
extern void PlayCancelSoundEffect(void);
extern void PlayAcceptSoundEffect(void);
extern void PlayCursorUpDownSoundEffect(void);
extern s32 sprintf(char *, const char *, ...);
extern void sub_800CB20(void);
extern void xxx_call_update_bg_sound_input(void);
extern void CopyDungeonName1toBuffer(u8 *buffer, DungeonLocation *dungeonLocation);
extern s32 Atan2_4096(PixelPos *a);
extern void sub_80117AC(void);
extern void sub_8011760(void);

struct UnkStruct_Sub1
{
    u8 unk0;
    DungeonPos unk4;
    axdata unk8;
};

struct UnkStruct_203B0E8
{
    struct UnkStruct_Sub1 unk0[64];
    OpenedFile *unk1100[5];
    u16 unk1114[64][64];
    u16 unk3114[64][64];
    axdata unk5114;
    unkStruct_202EE8C unk5150[16];
    s32 unk52D0;
    s32 unk52D4;
    DungeonPos unk52D8;
    DungeonPos unk52DC;
    u16 unk52E0[1500];
    u8 unk5E98[1500];
};

struct FiendArea
{
    const u8 *name;
    DungeonPos unk4;
    u8 unk8[8];
    s16 unk10[8];
};

struct UnkStruct_4018
{
    u8 unk4018;
    s16 unk2[8];
    axdata unk14;
};

// size: 0x4DD8
struct UnkBgStruct
{
    OpenedFile *unk0[5];
    u16 unk14[64][64];
    u16 unk2014[64][64];
    const struct FiendArea *unk4014;
    struct UnkStruct_4018 unk4018[32];
    s32 unk4A18;
    s32 unk4A1C;
    s32 unk4A20;
    s32 unk4A24;
    s32 unk4A28;
    u8 unk4A2C;
    axdata arrowSprites[NUM_DIRECTIONS];
    axdata unk4C10;
    unkStruct_202EE8C unk4C4C[16];
    s32 unk4DCC;
    u32 unk4DD0;
    DungeonPos bgPos;
    DungeonPos monSpritePos;
    s32 unk4DDC;
    s32 unk4DE0;
    s32 unk4DE4;
    s32 unk4DE8;
    u8 unk4DEC[8];
    u8 unk4DF4;
    s32 unk4DF8;
    MenuInputStruct menu;
};

EWRAM_INIT struct UnkBgStruct *gUnknown_203B0E4 = NULL;
EWRAM_INIT struct UnkStruct_203B0E8 *gUnknown_203B0E8 = NULL;
EWRAM_INIT Windows gUnknown_203B0EC = {
    .a0 = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 10},
            .width = 26,
            .height = 9,
            .unk10 = 9,
        },
        [1] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {23, 6},
            .width = 5,
            .height = 3,
            .unk10 = 3,
        },
        [2] = { .type = WINDOW_TYPE_NORMAL,},
        [3] = { .type = WINDOW_TYPE_NORMAL,},
    }
};

static inline bool8 CheckAxFlag8000(axdata *ptr)
{
    return (ptr->flags & 0x8000) != 0;
}

static inline bool8 ResetFlags(axdata *ptr)
{
    return ptr->flags = 0;
}


extern u8 *const gUnknown_80D4014[];
extern const FileArchive gTitleMenuFileArchive;
extern const FileArchive gMonsterFileArchive;
extern const u8 gUnknown_80D40E4[];
extern const u8 gUnknown_80D40EC[];
extern const u8 gUnknown_80D405C[];
extern const u8 gUnknown_80D40FC[];
extern const u8 gUnknown_80D4104[];
extern const u8 gUnknown_80D4120[];
extern const u8 gUnknown_80D3EFC[];
extern const u8 gUnknown_80D40F4[];
extern const u8 gUnknown_80D4064[];
extern const u8 gUnknown_80D406C[];
extern const u8 gUnknown_80D407C[];
extern const u8 gUnknown_80D4080[];
extern const u8 gUnknown_80D4074[];
extern const DungeonPos gDungeonCoordinates[];

struct UnkStruct_sub_8010494
{
    DungeonLocation unk0;
    DungeonLocation unk4;
    u8 pad1[8];
    u8 unk10;
    u8 pad2[0xA];
    s16 unk1C;
    u8 pad3[0x6E - 0x20];
    u8 unk6C;
    u8 unk6D[63];
};

struct UnkStruct_sub_8010268
{
    u8 fill0[4];
    struct UnkStruct_sub_8010494 unk4;
    struct UnkStruct_203B0E8 *unkB0;
    u8 unkB4;
};

static void sub_8010950(void);
static void sub_8010A88(bool8 a0);
static bool8 sub_8010A00(void);
static void nullsub_24(void);
void PrintAvailableSubAreas(void);
void sub_8010960(void);
void sub_8010798(void);
void sub_8010858(void);
void sub_8010494(struct UnkStruct_sub_8010494 *r9);
void sub_8010344(u8 id1, u8 id2);
void sub_801059C(void);
bool8 sub_8010C58(u8 *str);
void sub_8010C10(const u8 *text);
void sub_801091C(void);
void PrintCurrAreaName(void);
void sub_801073C(void);
void sub_8010B74(DungeonLocation *dungLocation);
void RunFrameActions(void);
void UpdateBg(void);
void sub_8010EF0(void);
void ShowDirectionArrows(void);
void UpdateMonSpritePosition(void);
bool8 sub_800FFE8(u8 friendAreaId);
void HideTextWindowAndArrows(void);
void MoveToNewArea(s32 a0, s32 a1, s32 count);
u8 GetNewSelectedArea(void);
s32 ChooseArea(s32 *a0, s32 *newAreaId);
bool8 ChooseSubArea(void);
void sub_800FC28(void);
void sub_800FC5C(u8 a0);
void sub_8010DA4(void);

extern u16 gUnknown_2026E4E;
extern u8 gUnknown_202DE18;
extern u8 gUnknown_202DE19;

extern const struct FiendArea gFriendAreaLocations[];

extern const u8 gUnknown_80D3EDC[];
extern const u8 gUnknown_80D3EEC[];

struct TestStruct
{
    s16 max;
    s16 min;
};

extern const struct TestStruct gUnknown_80D3EBC[];

struct struct_unk800F990
{
    u32 unk0;
    u8 unk4;
    u8 unk5;
    struct UnkBgStruct *unk8;
    u8 unkC;
};

void sub_800F990(struct struct_unk800F990 *param_1)
{
    gUnknown_203B0E4 = param_1->unk8;
    gUnknown_2026E4E = 0x1010;
    sub_80095CC(0,0x14);
    UpdateFadeInTile(2);
    gUnknown_203B0E4->unk4014 = gFriendAreaLocations;
    gUnknown_203B0E4->unk4A2C = param_1->unk5;
    sub_8010DA4();
    gUnknown_203B0E4->unk4A28 = -1;
    gUnknown_203B0E4->unk4A1C = -1;
    sub_800FC5C(param_1->unk4);
    gUnknown_203B0E4->unk4A20 = gUnknown_203B0E4->unk4A24;
    gUnknown_202DE18 = 0xff;
    gUnknown_202DE19 = 0;
    sub_8011760();
    while (1) {
        s32 local_1c = 0;
        s32 newAreaId = 0;
        s32 iVar2 = ChooseArea(&local_1c, &newAreaId);

        if (iVar2 == 1) {
            MoveToNewArea(local_1c, newAreaId, 0x32);
        }
        else if (iVar2 == 2) {
            if (!ChooseSubArea())
                continue;
            param_1->unkC = gUnknown_203B0E4->unk4DF4;
            break;
        }
        else if (iVar2 == 3) {
            if (gUnknown_203B0E4->unk4A18 == gUnknown_203B0E4->unk4A20) {
                param_1->unkC = 0;
                break;
            }
            MoveToNewArea(gUnknown_203B0E4->unk4A20,0,10);
        }
    }

    sub_800FC28();
    sub_8010EF0();
    nullsub_16();
}

s32 ChooseArea(s32 *a0, s32 *newAreaId)
{
    s32 ret = 0;

    ShowDirectionArrows();
    PrintCurrAreaName();
    while (ret == 0) {
        s32 areaId;

        RunFrameActions();
        areaId = GetNewSelectedArea();
        if (areaId != 0xFF) {
            s32 r4 = gUnknown_203B0E4->unk4A18;
            struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[r4];

            if (ptr->unk2[areaId] >= 0) {
                s32 id = ptr->unk2[areaId];
                struct UnkStruct_4018 *ptr2 = &gUnknown_203B0E4->unk4018[id];

                if (ptr2->unk4018 != 0) {
                    ret = 1;
                    *a0 = id;
                    *newAreaId = areaId;
                    gUnknown_203B0E4->unk4A28 = areaId;
                    gUnknown_203B0E4->unk4A1C = r4;
                }
            }
        }

        if (gRealInputs.pressed & A_BUTTON) {
            PlayAcceptSoundEffect();
            ret = 2;
        }
        if (gRealInputs.pressed & B_BUTTON) {
            PlayCancelSoundEffect();
            ret = 3;
        }
    }
    return ret;
}

bool8 ChooseSubArea(void)
{
    bool8 ret = FALSE;

    PrintAvailableSubAreas();
    while (1) {
        MenuInputStruct *menuPtr = &gUnknown_203B0E4->menu;

        AddMenuCursorSprite(menuPtr);
        RunFrameActions();
        if (gRealInputs.repeated & DPAD_DOWN) {
            MoveMenuCursorDown(menuPtr);
            PlayCursorUpDownSoundEffect();
        }
        if (gRealInputs.repeated & DPAD_UP) {
            MoveMenuCursorUp(menuPtr);
            PlayCursorUpDownSoundEffect();
        }

        if ((gRealInputs.pressed & A_BUTTON) || menuPtr->unk28.a_button) {
            PlayAcceptSoundEffect();
            gUnknown_203B0E4->unk4DF4 = gUnknown_203B0E4->unk4DEC[menuPtr->menuIndex];
            ret = TRUE;
            break;
        }
        if ((gRealInputs.pressed & B_BUTTON) || menuPtr->unk28.b_button) {
            PlayCancelSoundEffect();
            break;
        }
    }

    return ret;
}

void sub_800FC28(void)
{
    s32 i;

    HideTextWindowAndArrows();
    sub_80117AC();
    for (i = 0; i < 60; i++) {
        gUnknown_203B0E4->unk4DCC -= 2;
        RunFrameActions();
    }
}

void sub_800FC5C(u8 a0)
{
    s32 var_48 = 0;
    s32 i, j, k;

    for (i = 0; i < 32; i++) {
        bool8 r7 = FALSE;
        bool8 r10 = FALSE;
        struct UnkStruct_4018 *r6 = &gUnknown_203B0E4->unk4018[i];
        const struct FiendArea *r2 = &gUnknown_203B0E4->unk4014[i];

        for (j = 0; j < 8; j++) {
            r6->unk2[j] = 0xFFFF;
        }
        for (j = 0; j < 8; j++) {
            if (sub_800FFE8(r2->unk8[j])) {
                if (r2->unk8[j] == a0) {
                    var_48 = i;
                }
                if (r2->unk8[j] == 0) {
                    gUnknown_203B0E4->unk4A24 = i;
                    r10 = TRUE;
                }
                r7 = TRUE;
            }
        }

        if (r7) {
            r6->unk4018 = 1;
            AxResInitFile(&r6->unk14, gUnknown_203B0E4->unk0[2], (r10) ? 12 : 1, 0, 0x40, 0, 1);
        }
        else {
            r6->unk4018 = 0;
        }
    }

    for (i = 0; i < 32; i++) {
        s32 var1, var2;
        struct UnkStruct_4018 *r3 = &gUnknown_203B0E4->unk4018[i];
        const struct FiendArea *var_44 = &gUnknown_203B0E4->unk4014[i];

        if (!r3->unk4018) {
            continue;
        }

        for (j = 0; j < 8; j++) {
            r3->unk2[j] = 0xFFFF;
            if (var_44->unk10[j] >= 0) {
                struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[var_44->unk10[j]];
                if (ptr->unk4018) {
                    r3->unk2[j] = var_44->unk10[j];
                }
            }
        }

        var1 = gUnknown_203B0E4->unk4A28;
        var2 = gUnknown_203B0E4->unk4A1C;
        if (var1 >= 0 && var2 >= 0) {
            struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[var2];
            if (ptr->unk4018) {
                var1 += 4;
                var1 &= 7;
                r3->unk2[var1] = var2;
            }
        }

        for (j = 0; j < 8; j++) {
            s32 var_40 = -1;
            s32 var_3C = 999999;

            if (r3->unk2[j] >= 0)
                continue;

            for (k = 0; k < 32; k++) {
                bool8 r7;
                PixelPos pixelPos;
                s32 atanVal;
                struct UnkStruct_4018 *ptr2_18 = &gUnknown_203B0E4->unk4018[k];
                const struct FiendArea *ptr2_14 = &gUnknown_203B0E4->unk4014[k];

                if (k == i)
                    continue;
                if (ptr2_18->unk4018 == 0)
                    continue;

                pixelPos.x = (ptr2_14->unk4.x - var_44->unk4.x) << 8;
                pixelPos.y = (ptr2_14->unk4.y - var_44->unk4.y) << 8;
                atanVal = Atan2_4096(&pixelPos);
                pixelPos.x /= 4;
                pixelPos.y /= 4;
                pixelPos.x /= 256;
                pixelPos.y /= 256;
                if (pixelPos.x == 0) {
                    pixelPos.x = 1;
                }
                if (pixelPos.y == 0) {
                    pixelPos.y = 1;
                }

                r7 = FALSE;
                if (j == 2) {
                    while (atanVal >= 0x1000) {
                        atanVal -= 0x1000;
                    }
                    while (atanVal < 0) {
                        atanVal += 0x1000;
                    }
                    if (gUnknown_80D3EBC[j].max < atanVal || gUnknown_80D3EBC[j].min > atanVal) {
                        r7 = TRUE;
                    }
                }
                else {
                    if (gUnknown_80D3EBC[j].max <= atanVal && gUnknown_80D3EBC[j].min > atanVal) {
                        r7 = TRUE;
                    }
                }

                if (r7) {
                    s32 sum = (pixelPos.x * pixelPos.x) + (pixelPos.y * pixelPos.y);
                    if (var_3C > sum) {
                        var_3C = sum;
                        var_40 = k;
                    }
                }
            }

            if (var_40 >= 0) {
                r3->unk2[j] = var_40;
            }
        }
    }

    AxResInitFile(&gUnknown_203B0E4->unk4C10, gUnknown_203B0E4->unk0[3], 0, 0, 0, 0, TRUE);
    gUnknown_203B0E4->unk4A18 = var_48;
    gUnknown_203B0E4->monSpritePos = gUnknown_203B0E4->unk4014[var_48].unk4;
    gUnknown_203B0E4->bgPos.x = gUnknown_203B0E4->monSpritePos.x - 120;
    gUnknown_203B0E4->bgPos.y = gUnknown_203B0E4->monSpritePos.y - 80;
    UpdateMonSpritePosition();
    UpdateBg();
}

bool8 sub_800FFE8(u8 friendAreaId)
{
    if (friendAreaId > 57) return FALSE;
    if (friendAreaId == 0) return TRUE;
    if (gFriendAreas[friendAreaId]) return TRUE;

    return FALSE;
}

u8 GetNewSelectedArea(void)
{
    u8 sp1[16];
    u8 sp2[16];
    u8 *table;
    u32 flag;

    memcpy(sp1, gUnknown_80D3EDC, 16);
    memcpy(sp2, gUnknown_80D3EEC, 16);
    flag = 0;
    table = (gRealInputs.held & R_BUTTON) ? sp2 : sp1;

    if (gRealInputs.held & DPAD_DOWN) {
        flag |= 1;
    }
    if (gRealInputs.held & DPAD_RIGHT) {
        flag |= 2;
    }
    if (gRealInputs.held & DPAD_UP) {
        flag |= 4;
    }
    if (gRealInputs.held & DPAD_LEFT) {
        flag |= 8;
    }

    if (gUnknown_202DE18 == table[flag]) {
        if (++gUnknown_202DE19 >= 3) {
            return table[flag];
        }
    }
    else {
        gUnknown_202DE18 = table[flag];
        gUnknown_202DE19 = 0;
    }
    return 0xFF;
}

void MoveToNewArea(s32 a0, s32 a1, s32 count)
{
    s32 i, arrayId;
    DungeonPos pos1, pos2;

    AxResInitFile(&gUnknown_203B0E4->unk4C10, gUnknown_203B0E4->unk0[3], 0, a1 & 7, 0, 0, TRUE);
    HideTextWindowAndArrows();

    arrayId = gUnknown_203B0E4->unk4A18;
    pos1 = gUnknown_203B0E4->unk4014[arrayId].unk4;
    pos2 = gUnknown_203B0E4->unk4014[a0].unk4;

    PlayCursorUpDownSoundEffect();
    for (i = 0; i < count; i++) {
        gUnknown_203B0E4->monSpritePos.x = ((((pos2.x - pos1.x) * (i << 8)) / count) / 256) + pos1.x;
        gUnknown_203B0E4->monSpritePos.y = ((((pos2.y - pos1.y) * (i << 8)) / count) / 256) + pos1.y;

        UpdateMonSpritePosition();
        UpdateBg();
        RunFrameActions();
    }

    gUnknown_203B0E4->unk4A18 = a0;
    gUnknown_203B0E4->monSpritePos = gUnknown_203B0E4->unk4014[a0].unk4;
    UpdateMonSpritePosition();
    UpdateBg();
    RunFrameActions();
    AxResInitFile(&gUnknown_203B0E4->unk4C10, gUnknown_203B0E4->unk0[3], 0, 0, 0, 0, TRUE);
}

void sub_80101F8(u8 *strBuffer, u8 index)
{
    if (index == 0) {
        FormatString(gUnknown_80D3EFC, strBuffer, strBuffer + 0x50, 0);
    }
    else {
        WriteFriendAreaName(strBuffer, index, FALSE);
    }
}

void sub_8010224(u8 unk8, DungeonPos *dst)
{
    s32 i, j;

    for (i = 0; i < 32; i++) {
        const struct FiendArea *friendArea = &gFriendAreaLocations[i];
        for (j = 0; j < 8; j++) {
            if (friendArea->unk8[j] == unk8) {
                dst->x = friendArea->unk4.x;
                dst->y = friendArea->unk4.y;
                return;
            }
        }
    }
    dst->x = 0;
    dst->y = 0;
}

void sub_8010268(struct UnkStruct_sub_8010268 *r5)
{
    s32 i, speciesId, var;
    u8 text[1000];

    gUnknown_203B0E8 = r5->unkB0;
    gUnknown_2026E4E = 2566;
    sub_80095CC(0, 0x14);
    UpdateFadeInTile(2);
    sub_801059C();
    sub_8010494(&r5->unk4);
    sub_801178C();
    for (i = 0; i < 60; i++) {
        sub_8010960();
    }
    sub_8010344(r5->unk4.unk0.id, r5->unk4.unk4.id);
    sub_8010B74(&r5->unk4.unk4);
    for (i = 0; i < 60; i++) {
        sub_8010960();
    }

    if (r5->unk4.unk10) {
        speciesId = r5->unk4.unk1C;
        ASM_MATCH_TRICK(speciesId);
    }
    else {
        speciesId = 0;
    }

    var = sub_809034C(r5->unk4.unk4.id, speciesId, text, r5->unk4.unk6C, FALSE);
    if (var == 0) {
        r5->unkB4 = 1;
    }
    else if (var == 1) {
        sub_8010C10(text);
        r5->unkB4 = 0;
    }
    else if (var == 2) {
        if (sub_8010C58(text)) {
            r5->unkB4 = 1;
        }
        else {
            r5->unkB4 = 0;
        }
    }

    sub_801091C();
    sub_801073C();
    nullsub_16();
}

// Heavy math function.
void sub_8010344(u8 id1, u8 id2)
{
    s32 i, valMax, r3;
    PixelPos pixelPos;
    DungeonPos pos1 = gDungeonCoordinates[id1];
    DungeonPos pos2 = gDungeonCoordinates[id2];

    valMax = max(abs(pos2.x - pos1.x), abs(pos2.y - pos1.y));
    valMax /= 2;

    pixelPos.x = pos1.x - pos2.x;
    pixelPos.y = pos2.y - pos1.y;
    r3 = Atan2_4096(&pixelPos) - 1024;
    if (r3 < 0) {
        r3 += 511;
    }
    r3 >>= 9;
    r3 &= 7;
    AxResInitFile(&gUnknown_203B0E8->unk5114, gUnknown_203B0E8->unk1100[3], 0, r3, 0, 0, TRUE);

    for (i = 0; i < valMax; i++) {
        gUnknown_203B0E8->unk52DC.x = ((((pos2.x - pos1.x) * (i << 8)) / valMax) / 256) + pos1.x;
        gUnknown_203B0E8->unk52DC.y = ((((pos2.y - pos1.y) * (i << 8)) / valMax) / 256) + pos1.y;
        sub_8010798();
        sub_8010858();
        sub_8010960();
        if (gRealInputs.pressed & A_BUTTON)
            break;
        if (gRealInputs.pressed & B_BUTTON)
            break;
    }

    gUnknown_203B0E8->unk52DC = pos2;
    sub_8010798();
    sub_8010858();
    sub_8010960();
}

void sub_8010494(struct UnkStruct_sub_8010494 *r9)
{
    s32 i;
    for (i = 0; i < 64; i++) {
        struct UnkStruct_Sub1 *structPtr = &gUnknown_203B0E8->unk0[i];
        u8 r0;

        if (i < 63) {
            r0 = r9->unk6D[i];
        }
        else {
            r0 = 1;
        }

        if (r0) {
            structPtr->unk0 = 1;
            AxResInitFile(&structPtr->unk8, gUnknown_203B0E8->unk1100[2], (i == 63) ? 12 : 1, 0, 0x40, 0, 1);
            structPtr->unk4 = gDungeonCoordinates[i];
        }
        else {
            structPtr->unk0 = 0;
        }
    }

    AxResInitFile(&gUnknown_203B0E8->unk5114, gUnknown_203B0E8->unk1100[3], 0, 0, 0, 0, TRUE);
    gUnknown_203B0E8->unk52DC = gDungeonCoordinates[r9->unk0.id];
    gUnknown_203B0E8->unk52D8.x = gUnknown_203B0E8->unk52DC.x - 120;
    gUnknown_203B0E8->unk52D8.y = gUnknown_203B0E8->unk52DC.y - 80;
    sub_8010798();
    sub_8010858();
}

void sub_801059C(void)
{
    u8 filename[0xC];
    s32 i, size;

    PokemonStruct1 *pokeStruct = GetPlayerPokemonStruct();
    OpenedFile *file = OpenFileAndGetFileDataPtr(gUnknown_80D4014[0], &gTitleMenuFileArchive);
    OpenedFile *file2 = OpenFileAndGetFileDataPtr(gUnknown_80D4014[1], &gTitleMenuFileArchive);

    sprintf(filename, gUnknown_80D405C, pokeStruct->speciesNum);
    gUnknown_203B0E8->unk1100[3] = OpenFileAndGetFileDataPtr(filename, &gMonsterFileArchive);
    gUnknown_203B0E8->unk1100[2] = OpenFileAndGetFileDataPtr(gUnknown_80D4064, &gTitleMenuFileArchive);
    gUnknown_203B0E8->unk1100[4] = OpenFileAndGetFileDataPtr(gUnknown_80D4014[2], &gTitleMenuFileArchive);
    gUnknown_203B0E8->unk1100[1] = OpenFileAndGetFileDataPtr(gUnknown_80D406C, &gMonsterFileArchive);
    gUnknown_203B0E8->unk1100[0] = OpenFileAndGetFileDataPtr(gUnknown_80D4014[3], &gTitleMenuFileArchive);
    gUnknown_203B0E8->unk52D4 = GetPokemonOverworldPalette(pokeStruct->speciesNum, 0);

    sub_8005610(gUnknown_203B0E8->unk1100[2], 0x40, 0x1F, 0);

    DecompressATGlobalFile((u32 *)(VRAM + 0x8000), 0x0, file);
    sub_8004AA4(gUnknown_203B0E8->unk5150, gUnknown_203B0E8->unk1100[4], 0x10);
    size = 0x4000;
    DecompressATFile((u8 *) &gUnknown_203B0E8->unk1114, size, file2);

    gUnknown_203B0E8->unk52D0 = 0;
    gUnknown_203B0E8->unk52D8.x = 0;
    gUnknown_203B0E8->unk52D8.y = 0;

    for (i = 0; i < 1500; i++) {
        gUnknown_203B0E8->unk52E0[i] |= 0xFFFF;
        gUnknown_203B0E8->unk5E98[i] = 0;
    }

    CloseFile(file);
    CloseFile(file2);
    xxx_call_save_unk_text_struct_800641C(NULL, 1, 1);
}

void sub_801073C(void)
{
    CloseFile(gUnknown_203B0E8->unk1100[4]);
    CloseFile(gUnknown_203B0E8->unk1100[3]);
    CloseFile(gUnknown_203B0E8->unk1100[2]);
    CloseFile(gUnknown_203B0E8->unk1100[0]);
    CloseFile(gUnknown_203B0E8->unk1100[1]);
}

void sub_8010798(void)
{
    if (gUnknown_203B0E8->unk52DC.x - gUnknown_203B0E8->unk52D8.x < 48) {
        gUnknown_203B0E8->unk52D8.x = gUnknown_203B0E8->unk52DC.x - 48;
    }
    else if (gUnknown_203B0E8->unk52DC.x - gUnknown_203B0E8->unk52D8.x > 192) {
        gUnknown_203B0E8->unk52D8.x = gUnknown_203B0E8->unk52DC.x - 192;
    }

    if (gUnknown_203B0E8->unk52DC.y - gUnknown_203B0E8->unk52D8.y < 48) {
        gUnknown_203B0E8->unk52D8.y = gUnknown_203B0E8->unk52DC.y - 48;
    }
    else if (gUnknown_203B0E8->unk52DC.y - gUnknown_203B0E8->unk52D8.y > 112) {
        gUnknown_203B0E8->unk52D8.y = gUnknown_203B0E8->unk52DC.y - 112;
    }

    if (gUnknown_203B0E8->unk52D8.x < 0) {
        gUnknown_203B0E8->unk52D8.x = 0;
    }
    if (gUnknown_203B0E8->unk52D8.y < 0) {
        gUnknown_203B0E8->unk52D8.y = 0;
    }
    if (gUnknown_203B0E8->unk52D8.x >= 240) {
        gUnknown_203B0E8->unk52D8.x = 240;
    }
    if (gUnknown_203B0E8->unk52D8.y >= 160) {
        gUnknown_203B0E8->unk52D8.y = 160;
    }
}

void sub_8010858(void)
{
    s32 i, j;
    s32 y1 = gUnknown_203B0E8->unk52D8.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gUnknown_203B0E8->unk52D8.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gUnknown_202B038[2][y1][x1] = gUnknown_203B0E8->unk3114[y2][x2];
            gUnknown_202B038[3][y1][x1] = gUnknown_203B0E8->unk1114[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    sub_80098F8(2);
    sub_80098F8(3);
}

static void nullsub_24(void)
{

}

void sub_801091C(void)
{
    s32 i;

    sub_8010950();
    sub_80117C4();
    for (i = 0; i < 60; i++) {
        gUnknown_203B0E8->unk52D0 -= 2;
        sub_8010960();
    }
}

static void sub_8010950(void)
{
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
}

void sub_8010960(void)
{
    SetBG2RegOffsets(gUnknown_203B0E8->unk52D8.x, gUnknown_203B0E8->unk52D8.y);
    SetBG3RegOffsets(gUnknown_203B0E8->unk52D8.x, gUnknown_203B0E8->unk52D8.y);
    sub_8010A88(TRUE);
    sub_8010A00();
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    nullsub_24();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_8011860();
    ResetSprites(FALSE);
}

static bool8 sub_8010A00(void)
{
    bool8 ret = FALSE;

    if (gUnknown_203B0E8->unk52D0 < 31) {
        s32 i;
        RGB *color = (void *) gUnknown_203B0E8->unk1100[0]->data;

        if (++gUnknown_203B0E8->unk52D0 >= 31) {
            gUnknown_203B0E8->unk52D0 = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gUnknown_203B0E8->unk52D0, NULL);
        }

        color = (void *) gUnknown_203B0E8->unk1100[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gUnknown_203B0E8->unk52D0, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

static void sub_8010A88(bool8 a0)
{
    s32 i;
    unkStruct_2039DB0 var_2C;
    DungeonPos pos;

    sub_8004E8C(&var_2C);
    var_2C.unk4 = 0xF3FF;
    var_2C.unkA = 0x800;
    pos = gUnknown_203B0E8->unk52D8;
    RunAxAnimationFrame(&gUnknown_203B0E8->unk5114);
    if (a0) {
        DoAxFrame_800558C(&gUnknown_203B0E8->unk5114, gUnknown_203B0E8->unk52DC.x - pos.x, gUnknown_203B0E8->unk52DC.y - pos.y, 3, gUnknown_203B0E8->unk52D4, &var_2C);
    }

    for (i = 0; i < 64; i++) {
        struct UnkStruct_Sub1 *structPtr = &gUnknown_203B0E8->unk0[i];
        if (structPtr->unk0) {
            axdata *axPtr = &structPtr->unk8;

            RunAxAnimationFrame(axPtr);
            if (a0) {
                DoAxFrame_800558C(axPtr, structPtr->unk4.x - pos.x, structPtr->unk4.y - pos.y, 1, 0, &var_2C);
            }
        }
    }
}

void sub_8010B74(DungeonLocation *dungLocation)
{
    const s32 x = 12;
    Windows spTxtStruct = {
        .a0 = {
            [0] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {x, 2},
                .width = 16,
                .height = 2,
                .unk10 = 2,
            },
            [1] = {.type = WINDOW_TYPE_NORMAL},
            [2] = {.type = WINDOW_TYPE_NORMAL},
            [3] = {.type = WINDOW_TYPE_NORMAL},
        }
    };

    if (gUnknown_203B0E8->unk52DC.y - gUnknown_203B0E8->unk52D8.y <= 80) {
        spTxtStruct.a0[0].pos.y = 17;
    }
    else {
        spTxtStruct.a0[0].pos.y = 1;
    }

    xxx_call_save_unk_text_struct_800641C(&spTxtStruct, TRUE, TRUE);
    sub_80073B8(0);
    CopyDungeonName1toBuffer(gFormatBuffer_Monsters[0], dungLocation);
    PrintFormattedStringOnWindow(12, 2, _("{CENTER_ALIGN}{POKEMON_0}"), 0, '\0');
    sub_80073E0(0);
}

void sub_8010C10(const u8 *text)
{
    s32 i, a;
    CreateMenuDialogueBoxAndPortrait(text, NULL, 0, NULL, NULL, 3, 0, NULL, 0x301);
    do {
        DrawDialogueBoxString();
        sub_8010960();
    } while (sub_80144A4(&a) != 0);

    for (i = 0; i < 10; i++) {
        sub_8010960();
    }
}

bool8 sub_8010C58(u8 *str)
{
    s32 r2, i;
    MenuInputStruct menuInput;

    r2 = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            r2 += 12;
        }
    }
    r2 += 11;
    r2 /= 8;

    gUnknown_203B0EC.a0[0].pos.y = 19 - r2;
    gUnknown_203B0EC.a0[0].unk10 = r2;
    gUnknown_203B0EC.a0[0].height = r2;
    gUnknown_203B0EC.a0[1].pos.y = 14 - r2;
    xxx_call_save_unk_text_struct_800641C(&gUnknown_203B0EC, TRUE, TRUE);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(4, 0, str, 0, '\0');
    sub_80073E0(0);
    sub_80073B8(1);
    PrintFormattedStringOnWindow(10, 0, "Yes", 1, '\0');
    PrintFormattedStringOnWindow(10, 12, "No", 1, '\0');
    sub_80073E0(1);

    menuInput.menuIndex = 1;
    menuInput.unk1A = 2;
    menuInput.unk1C = 2;
    menuInput.unk1E = 0;
    menuInput.unk20 = 0;
    menuInput.unk4 = 0;
    menuInput.unk6 = 0;
    menuInput.unk0 = 1;
    menuInput.unkC = 0;
    menuInput.unkE = 0;
    menuInput.unk14.x = 0;
    menuInput.unk14.y = 0;
    menuInput.unk8.x = 8;
    menuInput.unk8.y = 8;
    sub_80137B0(&menuInput, 24);
    sub_801317C(&menuInput.unk28);
    while (1) {
        AddMenuCursorSprite(&menuInput);
        sub_8010960();
        if (gRealInputs.repeated & DPAD_DOWN) {
            MoveMenuCursorDown(&menuInput);
            PlayCursorUpDownSoundEffect();
        }
        if (gRealInputs.repeated & DPAD_UP) {
            MoveMenuCursorUp(&menuInput);
            PlayCursorUpDownSoundEffect();
        }
        if ((gRealInputs.pressed & A_BUTTON) || menuInput.unk28.a_button) {
            PlayAcceptSoundEffect();
            break;
        }
    }

    if (menuInput.menuIndex == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void sub_8010D8C(u8 id, DungeonPos *pos)
{
    pos->x = gDungeonCoordinates[id].x;
    pos->y = gDungeonCoordinates[id].y;
}

UNUSED static const char sPksDir2[] = "pksdir0";

static char *const gUnknown_80D408C[] =
{
    "wmapfont",
    "wmapmcc",
    "wmapcani",
    "wmappal",
};

static const DungeonPos gUnknown_80D40C4[] =
{
    {0, 24},
    {24, 24},
    {24, 0},
    {24, -24},
    {0, -24},
    {-24, -24},
    {-24, 0},
    {-24, 24},
};

void sub_8010DA4(void)
{
    u8 filename[0xC];
    s32 i, size;

    PokemonStruct1 *pokeStruct = GetPlayerPokemonStruct();
    OpenedFile *file = OpenFileAndGetFileDataPtr(gUnknown_80D408C[0], &gTitleMenuFileArchive);
    OpenedFile *file2 = OpenFileAndGetFileDataPtr(gUnknown_80D408C[1], &gTitleMenuFileArchive);

    sprintf(filename, "ax%03d", pokeStruct->speciesNum);
    gUnknown_203B0E4->unk0[3] = OpenFileAndGetFileDataPtr(filename, &gMonsterFileArchive);
    gUnknown_203B0E4->unk0[2] = OpenFileAndGetFileDataPtr("wmapspr", &gTitleMenuFileArchive);
    gUnknown_203B0E4->unk0[4] = OpenFileAndGetFileDataPtr(gUnknown_80D408C[2], &gTitleMenuFileArchive);
    gUnknown_203B0E4->unk0[1] = OpenFileAndGetFileDataPtr("palet", &gMonsterFileArchive);
    gUnknown_203B0E4->unk0[0] = OpenFileAndGetFileDataPtr(gUnknown_80D408C[3], &gTitleMenuFileArchive);
    gUnknown_203B0E4->unk4DD0 = GetPokemonOverworldPalette(pokeStruct->speciesNum, 0);

    sub_8005610(gUnknown_203B0E4->unk0[2], 0x40, 0x1F, 0);

    DecompressATGlobalFile((u32 *)(VRAM + 0x8000), 0x0, file);
    sub_8004AA4(gUnknown_203B0E4->unk4C4C, gUnknown_203B0E4->unk0[4], 0x10);
    size = 0x4000;
    DecompressATFile((u8 *) &gUnknown_203B0E4->unk14, size, file2);

    gUnknown_203B0E4->unk4DCC = 0;
    gUnknown_203B0E4->bgPos.x = 0;
    gUnknown_203B0E4->bgPos.y = 0;

    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gUnknown_203B0E4->arrowSprites[i]);
    }

    CloseFile(file);
    CloseFile(file2);
    xxx_call_save_unk_text_struct_800641C(NULL, 1, 1);
}

void sub_8010EF0(void)
{
    CloseFile(gUnknown_203B0E4->unk0[4]);
    CloseFile(gUnknown_203B0E4->unk0[2]);
    CloseFile(gUnknown_203B0E4->unk0[3]);
    CloseFile(gUnknown_203B0E4->unk0[0]);
    CloseFile(gUnknown_203B0E4->unk0[1]);
}

void sub_8010F28(void)
{
    s32 i;
    unkStruct_2039DB0 var_30;
    DungeonPos pos;

    sub_8004E8C(&var_30);
    var_30.unk4 = 0xF3FF;
    var_30.unkA = 0x800;
    pos = gUnknown_203B0E4->bgPos;
    RunAxAnimationFrame(&gUnknown_203B0E4->unk4C10);
    DoAxFrame_800558C(&gUnknown_203B0E4->unk4C10, gUnknown_203B0E4->monSpritePos.x - pos.x, gUnknown_203B0E4->monSpritePos.y - pos.y, 3, gUnknown_203B0E4->unk4DD0, &var_30);

    for (i = 0; i < 32; i++) {
        struct UnkStruct_4018 *r0 = &gUnknown_203B0E4->unk4018[i];
        const struct FiendArea *r5 = &gUnknown_203B0E4->unk4014[i];
        if (r0->unk4018 != 0) {
            RunAxAnimationFrame(&r0->unk14);
            DoAxFrame_800558C(&r0->unk14, r5->unk4.x - pos.x, r5->unk4.y- pos.y, 1, 0, &var_30);
        }
    }

{
    s32 i;
    for (i = 0; i < NUM_DIRECTIONS; i++) {
        if (CheckAxFlag8000(&gUnknown_203B0E4->arrowSprites[i])) {
            RunAxAnimationFrame(&gUnknown_203B0E4->arrowSprites[i]);
            if (!(gRealInputs.held & R_BUTTON) || (i % 2) != 0) {
                DoAxFrame_800558C(&gUnknown_203B0E4->arrowSprites[i],
                                  (gUnknown_80D40C4[i].x + gUnknown_203B0E4->monSpritePos.x) - pos.x,
                                  (gUnknown_80D40C4[i].y + gUnknown_203B0E4->monSpritePos.y) - pos.y,
                                  2, 0, &var_30);
            }
        }
    }
}
}

void UpdateBg(void)
{
    s32 i, j;
    s32 y1 = gUnknown_203B0E4->bgPos.y >> 3;
    s32 y2 = y1;

    for (i = 0; i < 21; i++) {
        s32 x1 = gUnknown_203B0E4->bgPos.x >> 3;
        s32 x2 = x1;

        for (j = 0; j < 31; j++) {
            x1 &= 0x1F;
            y1 &= 0x1F;

            gUnknown_202B038[2][y1][x1] = gUnknown_203B0E4->unk2014[y2][x2];
            gUnknown_202B038[3][y1][x1] = gUnknown_203B0E4->unk14[y2][x2];
            x2++;
            x1++;
        }
        y2++;
        y1++;
    }

    sub_80098F8(2);
    sub_80098F8(3);
}

void HideTextWindowAndArrows(void)
{
    s32 i;

    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gUnknown_203B0E4->arrowSprites[i]);
    }
}

bool8 sub_80111C4(void)
{
    bool8 ret = FALSE;

    if (gUnknown_203B0E4->unk4DCC < 31) {
        s32 i;
        RGB *color = (void *) gUnknown_203B0E4->unk0[0]->data;

        if (++gUnknown_203B0E4->unk4DCC >= 31) {
            gUnknown_203B0E4->unk4DCC = 31;
        }

        for (i = 0; i < 224; color++, i++) {
            SetBGPaletteBufferColorRGB(i, color, gUnknown_203B0E4->unk4DCC, NULL);
        }

        color = (void *) gUnknown_203B0E4->unk0[1]->data;
        for (i = 0; i < 240; color++, i++) {
            SetBGPaletteBufferColorRGB(i + 256, color, gUnknown_203B0E4->unk4DCC, NULL);
        }

        ret = TRUE;
    }

    return ret;
}

void UpdateMonSpritePosition(void)
{
    if (gUnknown_203B0E4->monSpritePos.x - gUnknown_203B0E4->bgPos.x < 48) {
        gUnknown_203B0E4->bgPos.x = gUnknown_203B0E4->monSpritePos.x - 48;
    }
    else if (gUnknown_203B0E4->monSpritePos.x - gUnknown_203B0E4->bgPos.x > 192) {
        gUnknown_203B0E4->bgPos.x = gUnknown_203B0E4->monSpritePos.x - 192;
    }

    if (gUnknown_203B0E4->monSpritePos.y - gUnknown_203B0E4->bgPos.y < 48) {
        gUnknown_203B0E4->bgPos.y = gUnknown_203B0E4->monSpritePos.y - 48;
    }
    else if (gUnknown_203B0E4->monSpritePos.y - gUnknown_203B0E4->bgPos.y > 112) {
        gUnknown_203B0E4->bgPos.y = gUnknown_203B0E4->monSpritePos.y - 112;
    }

    if (gUnknown_203B0E4->bgPos.x < 0) {
        gUnknown_203B0E4->bgPos.x = 0;
    }
    if (gUnknown_203B0E4->bgPos.y < 0) {
        gUnknown_203B0E4->bgPos.y = 0;
    }
    if (gUnknown_203B0E4->bgPos.x > 239) {
        gUnknown_203B0E4->bgPos.x = 239;
    }
    if (gUnknown_203B0E4->bgPos.y > 151) {
        gUnknown_203B0E4->bgPos.y = 151;
    }
}

void ShowDirectionArrows(void)
{
    s32 i;
    struct UnkStruct_4018 *r9 = &gUnknown_203B0E4->unk4018[gUnknown_203B0E4->unk4A18];

    for (i = 0; i < NUM_DIRECTIONS; i++) {
        ResetFlags(&gUnknown_203B0E4->arrowSprites[i]);
        if (r9->unk2[i] >= 0) {
            struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[r9->unk2[i]];
            if (ptr->unk4018 != 0) {
                AxResInitFile(&gUnknown_203B0E4->arrowSprites[i], gUnknown_203B0E4->unk0[2], i + 4, 0, 0x40, 0, TRUE);
            }
        }
    }
}

void PrintCurrAreaName(void)
{
    u8 txt[200];
    s32 id = gUnknown_203B0E4->unk4A18;
    const struct FiendArea *r6 = &gUnknown_203B0E4->unk4014[id];
    Windows spTxtStruct = {0};

    spTxtStruct.a0[0].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.a0[0].pos.x = 7;
    spTxtStruct.a0[0].pos.y = 2;
    spTxtStruct.a0[0].width = 21;
    spTxtStruct.a0[0].height = 2;
    spTxtStruct.a0[0].unk10 = 2;
    spTxtStruct.a0[1].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.a0[2].type = WINDOW_TYPE_NORMAL;
    spTxtStruct.a0[3].type = WINDOW_TYPE_NORMAL;

    if (gUnknown_203B0E4->monSpritePos.y - gUnknown_203B0E4->bgPos.y <= 80) {
        spTxtStruct.a0[0].pos.y = 17;
    }
    else {
        spTxtStruct.a0[0].pos.y = 1;
    }

    xxx_call_save_unk_text_struct_800641C(&spTxtStruct, TRUE, TRUE);
    sub_80073B8(0);
    sprintfStatic(txt, _("{CENTER_ALIGN}%s"), r6->name);
    PrintFormattedStringOnWindow(12, 2, txt, 0, '\0');
    sub_80073E0(0);
    gUnknown_203B0E4->unk4DDC = (spTxtStruct.a0[0].pos.x * 8) - 5;
    gUnknown_203B0E4->unk4DE0 = (spTxtStruct.a0[0].pos.y * 8) + 5;
    gUnknown_203B0E4->unk4DE4 = (spTxtStruct.a0[0].width * 8) + 10;
    gUnknown_203B0E4->unk4DE8 = (spTxtStruct.a0[0].height * 8) + 10;
}

void PrintAvailableSubAreas(void)
{
    s32 i, count, var;
    s32 id = gUnknown_203B0E4->unk4A18;
    const struct FiendArea *r8 = &gUnknown_203B0E4->unk4014[id];
    MenuInputStruct *menuInput = &gUnknown_203B0E4->menu;
    WindowHeader header;
    Windows spTxtStruct = {
        .a0 = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {7, 2},
                .width = 21,
                .height = 2,
                .unk10 = 2,
                .unk14 = &header,
            },
            [1] = {
                .type = WINDOW_TYPE_NORMAL,
            },
            [2] = {
                .type = WINDOW_TYPE_NORMAL,
            },
            [3] = {
                .type = WINDOW_TYPE_NORMAL,
            },
        }
    };

    count = 0;
    for (i = 0; i < 8; i++) {
        if (sub_800FFE8(r8->unk8[i])) {
            gUnknown_203B0E4->unk4DEC[count] = r8->unk8[i];
            count++;
        }
    }

    gUnknown_203B0E4->unk4DF8 = count;
    header.f0 = 1;
    header.f1 = 0;
    header.f2 = 18;
    header.f3 = 0;
    menuInput->menuIndex = 0;
    menuInput->unk1A = count;
    menuInput->unk1C = count;
    menuInput->unk1E = 0;
    menuInput->unk20 = 0;
    menuInput->unk4 = 0;
    menuInput->unk6 = 16;
    menuInput->unk0 = 0;
    menuInput->unkC = 0;
    menuInput->unkE = 0;
    menuInput->unk14.x = 0;
    menuInput->unk14.y = 0;
    menuInput->unk8.x = 8;
    menuInput->unk8.y = 8;
    sub_801317C(&menuInput->unk28);
    var = sub_80095E4(menuInput->unk1C, 0);
    spTxtStruct.a0[0].unk10 = spTxtStruct.a0[0].height = var + 2;
    sub_80137B0(menuInput, var * 8);

    xxx_call_save_unk_text_struct_800641C(&spTxtStruct, TRUE, TRUE);

    gUnknown_203B0E4->unk4DDC = 0;
    gUnknown_203B0E4->unk4DE0 = 0;
    gUnknown_203B0E4->unk4DE4 = 0;
    gUnknown_203B0E4->unk4DE8 = 0;
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, _("Where would you like to go?"), 0, '\0');

    for (i = 0; i < count; i++) {
        unkStruct_8092638 unkFriendAreaStruct;
        s32 r4 = sub_8013800(menuInput, i);
        u8 r5 = gUnknown_203B0E4->unk4DEC[i];

        sub_80101F8(gFormatBuffer_Items[0], r5);
        if (r5 == 0) {
            PrintFormattedStringOnWindow(12, r4, _("{MOVE_ITEM_0}"), 0, '\0');
        }
        else {
            sub_80926F8(r5, &unkFriendAreaStruct, gUnknown_203B0E4->unk4A2C);
            gFormatArgs[0] = unkFriendAreaStruct.unk2;
            gFormatArgs[1] = unkFriendAreaStruct.numPokemon;
            PrintFormattedStringOnWindow(12, r4, _("{MOVE_ITEM_0}($v02／$v12)"), 0, '\0');
        }
    }

    sub_80073E0(0);
}

void RunFrameActions(void)
{
    SetBG2RegOffsets(gUnknown_203B0E4->bgPos.x, gUnknown_203B0E4->bgPos.y);
    SetBG3RegOffsets(gUnknown_203B0E4->bgPos.x, gUnknown_203B0E4->bgPos.y);
    sub_8010F28();
    sub_8004AF0(sub_80111C4(), gUnknown_203B0E4->unk4C4C, 0xB0, 16, gUnknown_203B0E4->unk4DCC, NULL);
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_8011860();
    ResetSprites(FALSE);
}

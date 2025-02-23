#include "global.h"
#include "friend_areas_map.h"
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
#include "code_80118A4.h"
#include "code_800C9CC.h"
#include "pokemon.h"
#include "decompress.h"

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

EWRAM_INIT struct UnkBgStruct *gUnknown_203B0E4 = NULL;


extern const struct FriendAreaLocation gFriendAreaLocations[];
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

void sub_8010960(void);
void sub_8010798(void);
void sub_8010858(void);
void sub_8010344(u8 id1, u8 id2);
void sub_801059C(void);
bool8 sub_8010C58(u8 *str);
void sub_8010C10(const u8 *text);
void sub_801091C(void);
void sub_801073C(void);
void sub_8010B74(DungeonLocation *dungLocation);
void MoveToNewArea(s32 a0, s32 a1, s32 count);
u8 GetNewSelectedArea(void);
s32 ChooseArea(s32 *a0, s32 *newAreaId);
bool8 ChooseSubArea(void);
void sub_800FC28(void);
void sub_800FC5C(u8 a0);

extern u16 gUnknown_2026E4E;
extern u8 gUnknown_202DE18;
extern u8 gUnknown_202DE19;

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
    gUnknown_203B0E4->locations = gFriendAreaLocations;
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

    FriendAreasMap_ShowDirectionArrows();
    FriendAreasMap_PrintCurrAreaName();
    while (ret == 0) {
        s32 areaId;

        FriendAreasMap_RunFrameActions();
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

    FriendAreasMap_PrintAvailableSubAreas();
    while (1) {
        MenuInputStruct *menuPtr = &gUnknown_203B0E4->menu;

        AddMenuCursorSprite(menuPtr);
        FriendAreasMap_RunFrameActions();
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

    FriendAreasMap_HideTextWindowAndArrows();
    sub_80117AC();
    for (i = 0; i < 60; i++) {
        gUnknown_203B0E4->brightness -= 2;
        FriendAreasMap_RunFrameActions();
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
        const struct FriendAreaLocation *location = &gUnknown_203B0E4->locations[i];

        for (j = 0; j < 8; j++) {
            r6->unk2[j] = 0xFFFF;
        }
        for (j = 0; j < 8; j++) {
            if (sub_800FFE8(location->unk8[j])) {
                if (location->unk8[j] == a0) {
                    var_48 = i;
                }
                if (location->unk8[j] == 0) {
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
        const struct FriendAreaLocation *location = &gUnknown_203B0E4->locations[i];

        if (!r3->unk4018) {
            continue;
        }

        for (j = 0; j < 8; j++) {
            r3->unk2[j] = 0xFFFF;
            if (location->unk10[j] >= 0) {
                struct UnkStruct_4018 *ptr = &gUnknown_203B0E4->unk4018[location->unk10[j]];
                if (ptr->unk4018) {
                    r3->unk2[j] = location->unk10[j];
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
                const struct FriendAreaLocation *location2 = &gUnknown_203B0E4->locations[k];

                if (k == i)
                    continue;
                if (ptr2_18->unk4018 == 0)
                    continue;

                pixelPos.x = (location2->unk4.x - location->unk4.x) << 8;
                pixelPos.y = (location2->unk4.y - location->unk4.y) << 8;
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

    AxResInitFile(&gUnknown_203B0E4->monAxSprite, gUnknown_203B0E4->unk0[3], 0, 0, 0, 0, TRUE);
    gUnknown_203B0E4->unk4A18 = var_48;
    gUnknown_203B0E4->monSpritePos = gUnknown_203B0E4->locations[var_48].unk4;
    gUnknown_203B0E4->bgPos.x = gUnknown_203B0E4->monSpritePos.x - 120;
    gUnknown_203B0E4->bgPos.y = gUnknown_203B0E4->monSpritePos.y - 80;
    FriendAreasMap_UpdateMonSpritePosition();
    FriendAreasMap_UpdateBg();
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

    AxResInitFile(&gUnknown_203B0E4->monAxSprite, gUnknown_203B0E4->unk0[3], 0, a1 & 7, 0, 0, TRUE);
    FriendAreasMap_HideTextWindowAndArrows();

    arrayId = gUnknown_203B0E4->unk4A18;
    pos1 = gUnknown_203B0E4->locations[arrayId].unk4;
    pos2 = gUnknown_203B0E4->locations[a0].unk4;

    PlayCursorUpDownSoundEffect();
    for (i = 0; i < count; i++) {
        gUnknown_203B0E4->monSpritePos.x = ((((pos2.x - pos1.x) * (i << 8)) / count) / 256) + pos1.x;
        gUnknown_203B0E4->monSpritePos.y = ((((pos2.y - pos1.y) * (i << 8)) / count) / 256) + pos1.y;

        FriendAreasMap_UpdateMonSpritePosition();
        FriendAreasMap_UpdateBg();
        FriendAreasMap_RunFrameActions();
    }

    gUnknown_203B0E4->unk4A18 = a0;
    gUnknown_203B0E4->monSpritePos = gUnknown_203B0E4->locations[a0].unk4;
    FriendAreasMap_UpdateMonSpritePosition();
    FriendAreasMap_UpdateBg();
    FriendAreasMap_RunFrameActions();
    AxResInitFile(&gUnknown_203B0E4->monAxSprite, gUnknown_203B0E4->unk0[3], 0, 0, 0, 0, TRUE);
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
        const struct FriendAreaLocation *location = &gFriendAreaLocations[i];
        for (j = 0; j < 8; j++) {
            if (location->unk8[j] == unk8) {
                dst->x = location->unk4.x;
                dst->y = location->unk4.y;
                return;
            }
        }
    }
    dst->x = 0;
    dst->y = 0;
}


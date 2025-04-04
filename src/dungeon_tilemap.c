#include "global.h"
#include "globaldata.h"
#include "constants/item.h"
#include "constants/status.h"
#include "structs/str_202EDE8.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800E9E4.h"
#include "code_801602C.h"
#include "dungeon_vram.h"
#include "code_803E724.h"
#include "code_806CD90.h"
#include "dungeon.h"
#include "dungeon_items.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_logic.h"
#include "dungeon_range.h"
#include "dungeon_util.h"
#include "game_options.h"
#include "input.h"
#include "menu_input.h"
#include "sprite.h"
#include "text_1.h"
#include "play_time.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "dungeon_strings.h"

extern s32 gDungeonFramesCounter;

extern void ShowWholeRevealedDungeonMap(void);
extern void sub_80400D4(void);
extern void sub_8041888(u8 param_1);
extern void sub_803F7BC(void);
extern void ShowWholeRevealedDungeonMap();

void sub_803EC94(void);
s32 sub_803EF90(s32 a0, u8 a1);
void sub_803F580(u8 a0);
void sub_803F7BC(void);
void sub_803F38C(void);
void sub_803FB74(void);
void sub_803FE30(s32 a0, u16 *a1, bool8 a2, bool8 a3);
void sub_803FF18(s32 a0, u16 *a1, bool8 a2);

static EWRAM_DATA u32 gUnknown_202EDFC = 0;

void sub_803F27C(bool8 a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->cameraPixelPos.x = 0;
    strPtr->cameraPixelPos.y = 0;
    strPtr->cameraPos.x = 0;
    strPtr->cameraPos.y = 0;
    strPtr->cameraPixelPosMirror.x = 0;
    strPtr->cameraPixelPosMirror.y = 0;
    strPtr->cameraPosMirror.x = 0;
    strPtr->cameraPosMirror.y = 0;

    strPtr->unk181FC = 0;
    strPtr->unk18216 = 0;
    strPtr->unk18217 = 1;
    strPtr->unk18218 = 1;
    strPtr->unk18219 = 0;

    strPtr->unk18200 = 0;
    strPtr->unk18204 = 0;
    if (!a0) {
        strPtr->blinded = 0;
        strPtr->hallucinating = 0;
        strPtr->showInvisibleTrapsMonsters = 0;
        strPtr->unk1820D = FALSE;
        strPtr->unk18211 = 0;
        strPtr->showAllFloorItems = FALSE;
        strPtr->allTilesRevealed = 0;
        strPtr->unk1820C = 0;
    }

    strPtr->cameraTarget = NULL;
    strPtr->priority = 3;
    strPtr->unk1821A = 0;
    strPtr->unk18212 = 0;
    strPtr->rotateModeDirection = 0;
    strPtr->prevRotateModeDirection = 0;
    strPtr->inFloorMapMode = 0;
    strPtr->unk18215 = 1;
    sub_803F38C();

    gUnknown_202EDFC = 0xFFFF;
    if (!a0) {
        strPtr->visibilityRange = gDungeon->floorProperties.unk16 & 3;
        if (strPtr->visibilityRange == 0) {
            strPtr->unk1820C = 1;
        }
    }
}

void sub_803F38C(void)
{
    s32 palId;
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->unk3A = -1;
    strPtr->unk3C = -1;
    strPtr->unk3E = -1;
    strPtr->unk40 = -1;
    strPtr->unk36 = -1;
    strPtr->unk38 = -1;

    palId = (gGameOptionsRef->playerGender != MALE) ? 4 : 0;

    SetBGPaletteBufferColorArray(0xFD, &gFontPalette[16 * palId + 13]);
    SetBGPaletteBufferColorArray(0xFE, &gFontPalette[16 * palId + 14]);
    SetBGPaletteBufferColorArray(0xFF, &gFontPalette[16 * palId + 15]);

    nullsub_5(0xFD, &gFontPalette[16 * palId + 13]);
    nullsub_5(0xFE, &gFontPalette[16 * palId + 14]);
    nullsub_5(0xFF, &gFontPalette[16 * palId + 15]);
}

bool8 sub_803F428(DungeonPos *pos)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    Entity *cameraEntity = strPtr->cameraTarget;

    if (abs(strPtr->cameraPos.x - pos->x) <= 6 && abs(strPtr->cameraPos.y - pos->y) <= 5) {
        if (strPtr->allTilesRevealed == 0 && strPtr->unk1820C == 0 && cameraEntity != NULL) {
            return IsPositionActuallyInSight(&strPtr->cameraPos, pos);
        }
        return TRUE;
    }

    return FALSE;
}

void sub_803F4A0(Entity *a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->cameraTarget = a0;
    if (a0 == NULL) {
        strPtr->unk18216 = 0;
    }
    else if (!GetEntInfo(a0)->isTeamLeader) {
        strPtr->unk18216 = 0;
    }
    else {
        strPtr->unk18216 = 1;
    }

    sub_803F580(0);
    sub_803F38C();
    if (gDungeon->unk1356C == 0) {
        sub_806CD90();
    }
}

// Very similar to the one above
void sub_803F508(Entity *a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    if (a0 == NULL) {
        strPtr->unk18216 = 0;
    }
    else if (!GetEntInfo(a0)->isTeamLeader) {
        strPtr->unk18216 = 0;
    }
    else {
        strPtr->unk18216 = 1;
    }
    strPtr->cameraTarget = a0;

    sub_803F580(0);
    sub_803F38C();
    if (gDungeon->unk1356C == 0) {
        sub_806CD90();
    }
    sub_8049ED4();
    ShowWholeRevealedDungeonMap();
}

void sub_803F580(u8 a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    Entity *cameraTarget = strPtr->cameraTarget;

    if (cameraTarget != NULL && EntityIsValid(cameraTarget)) {
        s32 i;
        u32 before, inFloorMapMode;
        EntityInfo *info = GetEntInfo(cameraTarget);

        strPtr->cameraPixelPosMirror = strPtr->cameraPixelPos;
        strPtr->cameraPosMirror = strPtr->cameraPos;
        strPtr->cameraPos.x = cameraTarget->pos.x;
        strPtr->cameraPos.y = cameraTarget->pos.y;

        strPtr->cameraPixelPos.x = (cameraTarget->pixelPos.x / 256) - 120;
        strPtr->cameraPixelPos.y = (cameraTarget->pixelPos.y / 256) - 96;

        if (HasHeldItem(cameraTarget, ITEM_X_RAY_SPECS) && info->isTeamLeader) {
            strPtr->unk1820D = TRUE;
            strPtr->showAllFloorItems = TRUE;
        }
        else {
            strPtr->unk1820D = info->powerEars;
            strPtr->showAllFloorItems = info->scanning;
        }

        strPtr->unk18211 = info->stairSpotter;
        before = strPtr->blinded;
        inFloorMapMode = strPtr->inFloorMapMode;
        if (inFloorMapMode == 0) {
            u32 unkVar;
            if (info->blinkerClassStatus.status == STATUS_BLINKER) {
                strPtr->blinded = 1;
                unkVar = 0xE;
            }
            else {
                strPtr->blinded = inFloorMapMode;
                unkVar = 0;
            }

            if (gUnknown_202EDFC != unkVar) {
                gUnknown_202EDFC = unkVar;
                SetBGOBJEnableFlags(unkVar);
            }
        }
        else {
            gUnknown_202EDFC = 0xFFFF;
        }

        if (before != strPtr->blinded) {
            sub_8041888(0);
        }

        before = strPtr->hallucinating;
        if (info->blinkerClassStatus.status == STATUS_CROSS_EYED) {
            strPtr->hallucinating = 1;
        }
        else {
            strPtr->hallucinating = 0;
        }

        if (before != strPtr->hallucinating) {
            sub_806CC70();
            sub_8041888(0);
        }

        before = strPtr->showInvisibleTrapsMonsters;
        if (CanSeeInvisibleMonsters(cameraTarget)) {
            strPtr->showInvisibleTrapsMonsters = 1;
        }
        else {
            strPtr->showInvisibleTrapsMonsters = 0;
        }

        if (before != strPtr->showInvisibleTrapsMonsters) {
            sub_8049ED4();
            ShowWholeRevealedDungeonMap();
            sub_8041888(0);
        }

        if (a0 && strPtr->unk18213 == 0) {
            if (abs(strPtr->cameraPixelPosMirror.x - strPtr->cameraPixelPos.x) > 7 || abs(strPtr->cameraPixelPosMirror.y - strPtr->cameraPixelPos.y) > 7) {
                sub_8049ED4();
                strPtr->unk18213 = 1;
            }
            else {
                if (strPtr->cameraPixelPosMirror.x < strPtr->cameraPixelPos.x) {
                    sub_804A1F0(240, 0);
                }
                else if (strPtr->cameraPixelPosMirror.x > strPtr->cameraPixelPos.x) {
                    sub_804A1F0(0, 0);
                }

                if (strPtr->cameraPixelPosMirror.y < strPtr->cameraPixelPos.y) {
                    sub_804A49C(0, 160);
                }
                else if (strPtr->cameraPixelPosMirror.y > strPtr->cameraPixelPos.y) {
                    sub_804A49C(0, 0);
                }
            }
        }

        if (strPtr->cameraPos.x != strPtr->cameraPosMirror.x || strPtr->cameraPos.y != strPtr->cameraPosMirror.y) {
            for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
                Entity *mon = gDungeon->activePokemon[i];
                if (EntityIsValid(mon)) {
                    ShowDungeonMapAtPos(mon->pos.x, mon->pos.y);
                }
            }
        }
    }

    sub_80400D4();
    sub_803F7BC();
}

void sub_803F7BC(void)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    const Tile *tile = GetTile(strPtr->cameraPos.x, strPtr->cameraPos.y);
    u32 roomId = tile->room;

    if (strPtr->allTilesRevealed != 0 || strPtr->unk1820C != 0 || strPtr->unk18217 != 0) {
        sub_8005838(NULL, 0);
    }
    else if (roomId == CORRIDOR_ROOM) {
        u32 kind = (strPtr->visibilityRange == 2) ? 1 : 2;
        sub_8005838(NULL, kind);
    }
    else {
        s32 sp[4];
        RoomData *room = &gDungeon->roomData[roomId];

        sp[0] = room->unkC - strPtr->cameraPixelPos.x;
        sp[1] = room->unk10 - strPtr->cameraPixelPos.y;
        sp[2] = room->unk14 - strPtr->cameraPixelPos.x;
        sp[3] = room->unk18 - strPtr->cameraPixelPos.y;
        sub_8005838(sp, 3);
    }
}

void sub_803F878(s32 a0, s32 a1)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->cameraPixelPosMirror = strPtr->cameraPixelPos;
    strPtr->cameraPosMirror = strPtr->cameraPos;
    strPtr->cameraPixelPos.x = (a0 / 256) - 120;
    strPtr->cameraPixelPos.y = (a1 / 256) - 96;
    strPtr->cameraPos.x = a0 / 6144;
    strPtr->cameraPos.y = a1 / 6144;
    strPtr->unk1820D = FALSE;
    strPtr->showAllFloorItems = FALSE;
    strPtr->unk18211 = 0;
    strPtr->unk18216 = 0;

    if (gUnknown_202EDFC != 0) {
        gUnknown_202EDFC = 0;
        SetBGOBJEnableFlags(0);
    }

    if (abs(strPtr->cameraPixelPosMirror.x - strPtr->cameraPixelPos.x) > 7 || abs(strPtr->cameraPixelPosMirror.y - strPtr->cameraPixelPos.y) > 7) {
        sub_8049ED4();
        strPtr->unk18213 = 1;
    }
    else {
        if (strPtr->cameraPixelPosMirror.x < strPtr->cameraPixelPos.x) {
            sub_804A1F0(240, 0);
        }
        else if (strPtr->cameraPixelPosMirror.x > strPtr->cameraPixelPos.x) {
            sub_804A1F0(0, 0);
        }

        if (strPtr->cameraPixelPosMirror.y < strPtr->cameraPixelPos.y) {
            sub_804A49C(0, 160);
        }
        else if (strPtr->cameraPixelPosMirror.y > strPtr->cameraPixelPos.y) {
            sub_804A49C(0, 0);
        }
    }

    sub_803F7BC();
}

s32 GetCameraXPos(void)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    return (strPtr->cameraPixelPos.x + 120) * 256;
}

s32 GetCameraYPos(void)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    return (strPtr->cameraPixelPos.y + 96) * 256;
}

void sub_803F9CC(void)
{
    s32 i;
    Entity *cameraTarget = gDungeon->unk181e8.cameraTarget;
    bool32 r5 = FALSE;

    if (gDungeon->unk1356C != 0 || gDungeon->unk181e8.unk18218 != 0 || sub_800EC74() != 0) {
        r5 = FALSE;
    }
    else if (cameraTarget != NULL && GetEntityType(cameraTarget) == ENTITY_MONSTER) {
        r5 = TRUE;
    }

    if (!r5) {
        for (i = 1; i < 30; i++) {
            gBgTilemaps[0][0][i] = 0;
        }
        sub_803F38C();
    }
    else {
        sub_803FB74();
    }

    gUnknown_20274A5 = TRUE;
}

IWRAM_DATA static u32 gUnknown_3001018[96] = {0};

void sub_803FA4C(s32 a0, s32 a1, bool8 a2)
{
    s32 i;
    s32 r5;
    u32 r10, r9;
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    u32 *dst = gUnknown_3001018;
    u32 sp[9] = {0, 0xF, 0xFF, 0xFFF, 0xFFFF, 0xFFFFF, 0xFFFFFF, 0xFFFFFFF, 0xFFFFFFFF};

    r10 = 0x22222222;
    r9 = 0x44444444;
    if (a0 == strPtr->unk3E && a1 == strPtr->unk40)
        return;
    if (!a2) {
        r9 = 0x55555555;
    }

    strPtr->unk3E = a0;
    strPtr->unk40 = a1;
    r5 = a1;
    if (r5 >= 96) {
        r5 = 96;
        a0 = (a0 * 96) / a1;
    }

    for (i = 0; i < 96; i += 8) {
        u32 val0, val1;
        u32 val6 = 0x77777777;
        s32 id1 = a0;
        s32 id2 = r5;

        if (a0 >= 8) {
            id1 = 8;
        }
        if (r5 >= 8) {
            id2 = 8;
        }

        val1 = sp[id2] & ~(sp[id1]);
        val1 &= r10;
        val0 = (sp[id1] & r9) | val1;
        val6 = sp[id2] & val6;
        *(dst++) = 0;
        *(dst++) = val6;
        *(dst++) = val0;
        *(dst++) = val0;
        *(dst++) = val0;
        *(dst++) = val0;
        *(dst++) = val6;
        *(dst++) = 0;

        a0 -= 8;
        r5 -= 8;
        if (a0 < 0) {
            a0 = 0;
        }
        if (r5 < 0) {
            r5 = 0;
        }
    }
    sub_80098BC((void *) VRAM + 0x5980, gUnknown_3001018, sizeof(gUnknown_3001018));
}

void sub_803FB74(void)
{
    s32 i;
    u16 *arrPtr;
    s32 r5, r6, unkFloor;
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    bool32 lowHp = FALSE;
    bool32 hungry = FALSE;
    EntityInfo *entInfo = GetEntInfo(strPtr->cameraTarget);
    s32 hp = entInfo->HP;
    s32 maxHp = entInfo->maxHPStat;
    s32 level = entInfo->level;

    if (entInfo->HP > 0 && entInfo->HP <= entInfo->maxHPStat / 4) {
        lowHp = TRUE;
    }
    // reloaded again
    entInfo = GetEntInfo(strPtr->cameraTarget);
    if (FixedPointToInt(entInfo->belly) == 0) {
        hungry = TRUE;
    }

    if (lowHp && (gDungeonFramesCounter & 16) != 0) {
        r5 = 32, r6 = 32;
    }
    else {
        r5 = 0, r6 = 0;
    }

    if (hungry && (gDungeonFramesCounter & 16) != 0) {
        r5 = 48, r6 = 48;
    }

    if (r5 == 0) {
        if (strPtr->unk18212 != 0) {
            r5 = 96;
        }
        else if (gGameOptionsRef->playerGender != MALE) {
            r5 = 64;
        }
    }

    if (r6 == 0) {
        if (gGameOptionsRef->playerGender != MALE) {
            r6 = 64;
        }
    }

    if (strPtr->unk36 != r5) {
        strPtr->unk36 = r5;
        SetBGPaletteBufferColorArray(0xFC, &gFontPalette[12 + r5]);
        SetBGPaletteBufferColorArray(0xFD, &gFontPalette[13 + r5]);
        SetBGPaletteBufferColorArray(0xFE, &gFontPalette[14 + r5]);
        SetBGPaletteBufferColorArray(0xFF, &gFontPalette[15 + r5]);
    }

    if (strPtr->unk38 != r6) {
        strPtr->unk38 = r6;
        nullsub_5(0xFC, &gFontPalette[12 + r6]);
        nullsub_5(0xFD, &gFontPalette[13 + r6]);
        nullsub_5(0xFE, &gFontPalette[14 + r6]);
        nullsub_5(0xFF, &gFontPalette[15 + r6]);
    }

    arrPtr = gBgTilemaps[0][0];
    unkFloor = gDungeon->unk14 + gDungeon->unk644.dungeonLocation.floor;
    if (strPtr->unk3A != unkFloor) {
        strPtr->unk3A = unkFloor;
        if (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id)) {
            arrPtr[1] = 0;
        }
        else {
            arrPtr[1] = 0xF2BE;
        }

        if (unkFloor < 10) {
            sub_803FE30(unkFloor, &arrPtr[2], strPtr->unk18216, 1);
            arrPtr[3] = 0xF2B8;
        }
        else {
            sub_803FE30(unkFloor, &arrPtr[2], strPtr->unk18216, 0);
            arrPtr[4] = 0xF2B8;
        }
    }

    if (strPtr->unk3C != level) {
        strPtr->unk3C = level;
        arrPtr[5] = 0xF2B9;
        arrPtr[6] = 0xF2BA;
        sub_803FE30(level, &arrPtr[7], strPtr->unk18216, 0);
    }

    if (strPtr->unk3E != hp) {
        arrPtr[9] = 0xF2BB;
        arrPtr[10] = 0xF2BC;
        sub_803FF18(hp, &arrPtr[11], strPtr->unk18216);
    }

    if (strPtr->unk40 != maxHp) {
        arrPtr[14] = 0xF2BD;
        sub_803FF18(maxHp, &arrPtr[15], strPtr->unk18216);
    }

    sub_803FA4C(hp, maxHp, strPtr->unk18216);
    strPtr->unk40 = maxHp;
    strPtr->unk3E = hp;
    strPtr->unk42 = maxHp / 8;
    if (maxHp % 8 != 0) {
        strPtr->unk42++;
    }

    if (strPtr->unk42 >= 12) {
        strPtr->unk42 = 12;
    }

    for (i = 0; i < 12; i++) {
        gBgTilemaps[0][0][18 + i] = (0x2CC + i) | 0xF000;
    }
}

static const s32 gUnknown_80F64B4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
static const u16 gUnknown_80F64D8[][9] = {
    [0] = {0xF291, 0xF290, 0xF28F, 0xF28E, 0xF28D, 0xF28C, 0xF28B, 0xF28A, 0xF289},
    [1] = {0xF2C8, 0xF2C7, 0xF2C6, 0xF2C5, 0xF2C4, 0xF2C3, 0xF2C2, 0xF2C1, 0xF2C0},
};

void sub_803FE30(s32 a0, u16 *a1, bool8 a2, bool8 a3)
{
    s32 var = (a2) ? 0 : 55;

    if (a0 > 100) {
        if (a2) {
            a1[0] = 0xF291;
            a1[1] = 0xF291;
        }
        else {
            a1[0] = 0xF2C8;
            a1[1] = 0xF2C8;
        }
        return;
    }

    if (a0 == 100) {
        a1[0] = 0xF294;
        a1[1] = 0xF295;
        return;
    }
    // This is a fakematch, I was actually to decompile this function for Blue(https://decomp.me/scratch/tqonk), but agbcc doesn't want to cooperate...
    else {
        // I thought 'ptr' was a compiler generated variable, but I couldn't match the function without declaring it.
        u16 *ptr = a1 + 1;
        s32 varAdd = var + 48;

        if (a0 >= 10) {
            s32 i;
            s32 arrId = (!a2) ? 1 : 0;

            for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80F64B4); i++) {
                ASM_MATCH_TRICK(a1);
                if (gUnknown_80F64B4[i] <= a0) {
                    *a1 = gUnknown_80F64D8[arrId][i];
                    *ptr  = (((a0 - gUnknown_80F64B4[i]) + varAdd) + 0x258) | 0xF000;
                    return;
                }
            }
        }
        if (!a3) {
            *(a1++) = 0xF278;
        }

        *a1 = (a0 + varAdd + 0x258) | 0xF000;
    }
}

static const s32 gUnknown_80F64FC[] = {900, 800, 700, 600, 500, 400, 300, 200, 100};
static const s32 gUnknown_80F6520[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
static const u16 gUnknown_80F6544[][9] = {
    [0] = {0xF291, 0xF290, 0xF28F, 0xF28E, 0xF28D, 0xF28C, 0xF28B, 0xF28A, 0xF289},
    [1] = {0xF2C8, 0xF2C7, 0xF2C6, 0xF2C5, 0xF2C4, 0xF2C3, 0xF2C2, 0xF2C1, 0xF2C0},
};

void sub_803FF18(s32 a0, u16 *a1, bool8 a2)
{
    s32 arrId = (!a2) ? 1 : 0;
    s32 var = (a2) ? 0 : 55;

    if (a0 > 999) {
        u16 val = gUnknown_80F6544[arrId][0];
        *(a1++) = val;
        *(a1++) = val;
        *a1 = val;
    }
    else {
        u8 toAdd = 32;
        s32 i = 0;
        s32 varAdd = var + 48;

        for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80F64FC); i++) {
            if (gUnknown_80F64FC[i] <= a0) {
                *(a1++) = gUnknown_80F6544[arrId][i];
                a0 -= gUnknown_80F64FC[i];
                toAdd = varAdd;
                break;
            }
        }
        if (i == 9) {
            *(a1++) = (toAdd + 0x258) | 0xF000;
        }

        for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80F6520); i++) {
            if (gUnknown_80F6520[i] <= a0) {
                *(a1++) = gUnknown_80F6544[arrId][i];
                a0 -= gUnknown_80F6520[i];
                break;
            }
        }
        if (i == 9) {
            *(a1++) = (toAdd + 0x258) | 0xF000;
        }

        *a1 = (a0 + varAdd + 0x258) | 0xF000;
    }
}

void HandleLuminousOrbAction(Entity *pokemon)
{
  int XCoord;
  int YCoord;

  gDungeon->unk181e8.allTilesRevealed = TRUE;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      Tile *mapTile = GetTileMut(XCoord, YCoord);
      mapTile->spawnOrVisibilityFlags |= VISIBILITY_FLAG_REVEALED;
    }
  }
  sub_803F580(0);
  sub_8049ED4();
  ShowWholeRevealedDungeonMap();
  LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD040);
}

void sub_8040094(u8 r0)
{
    gDungeon->unk181e8.unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    xxx_call_update_bg_sound_input();
    UpdateDungeonMusic();
    sub_8011860();
}

static const s32 gUnknown_80F6568[] = {
    0, -1, 1, -1, 1, -1, 1, -2, 1, -2, 2, -2, 2, -2, 2, -3, 3, -3, 3, -3, 4, -4, 4, -4, 4, -5, 4, -5, 4, -5, 4, -5
};

void sub_80400D4(void)
{
    s32 temp;
    temp = gDungeon->unk181e8.unk18200;
    if(temp == 0)
        return;
    if(temp >= 0x1F)
        temp = 0x1F;
    gDungeon->unk181e8.unk181FC = gUnknown_80F6568[temp];
    gDungeon->unk181e8.unk18200--;
    if(gDungeon->unk181e8.unk18200 == 0)
        gDungeon->unk181e8.unk18200 = gDungeon->unk181e8.unk18204;
}

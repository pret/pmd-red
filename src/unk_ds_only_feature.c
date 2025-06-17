#include "global.h"
#include "globaldata.h"
#include "unk_ds_only_feature.h"
#include "memory.h"
#include "game_options.h"
#include "event_flag.h"
#include "ground_main.h"
#include "ground_place.h"
#include "code_80A26CC.h"
#include "constants/ground_map.h"
#include "constants/friend_area.h"

// This file effectively does nothing on GBA. If I were to guess I'd say it's bottom/top screen related.

struct unkStruct_3001B68
{
     u32 unk0;
     u32 unk4;
     u16 unk8;
     u16 unkA;
     u8  unkC;
     u8  unkD;
     u8  unkE;
     u32 unk10;
     s16 mapId;
     s16 groundPlaceId;
     u8  friendAreaId;
     u8  unk19;
     u32 unk1C;
     u8  unk20;
};

static IWRAM_INIT struct unkStruct_3001B68 *sUnknown_3001B68 = {NULL};

UNUSED static const u8 sUnused[4] = {0};

static void nullsub_107();
static void nullsub_108();
static void nullsub_109();
static void nullsub_110();
static void nullsub_111();
static void nullsub_112();
static void nullsub_113();
static void nullsub_114();
static void nullsub_115();
static void nullsub_116();

void sub_809C5C4(void)
{
    sUnknown_3001B68 = MemoryAlloc(sizeof(struct unkStruct_3001B68), 6);
    sUnknown_3001B68->unk0 = 0;
    sUnknown_3001B68->unk4 = 0;
    sUnknown_3001B68->unk8 = 0;
    sUnknown_3001B68->unkA = 0;
    sUnknown_3001B68->unkD = 0;
    sUnknown_3001B68->unkE = 0;
    sUnknown_3001B68->unk10 = 0;
    sUnknown_3001B68->mapId = -1;
    sUnknown_3001B68->groundPlaceId = GROUND_PLACE_DIRECTION;
    sUnknown_3001B68->friendAreaId = 0;
    sUnknown_3001B68->unk19 = 0x3f;
    sUnknown_3001B68->unk1C = 0;
    sUnknown_3001B68->unk20 = 0;
    nullsub_107();
    sub_809C63C();
}

void sub_809C618(void)
{
    sub_809C63C();
    nullsub_107();
    nullsub_108();
    FREE_AND_SET_NULL(sUnknown_3001B68);
}

void sub_809C63C(void)
{
    nullsub_108();
    sUnknown_3001B68->unk1C = 0;
    sUnknown_3001B68->unk20 = 0;
}

void sub_809C658(void)
{
    switch (sUnknown_3001B68->unkA) {
        case 3:
            nullsub_111();
            nullsub_112();
            nullsub_113();
            break;
        case 4:
            nullsub_114();
            nullsub_115();
            nullsub_116();
            break;
        case 2:
            nullsub_109();
            nullsub_110();
            break;
        case 5:
            nullsub_107();
            nullsub_108();
            break;
        case 0:
        case 1:
            nullsub_107();
            nullsub_108();
            break;
    }
}

void sub_809C6CC(u16 param_1)
{
    if (sUnknown_3001B68->unk8 != param_1) {
        sUnknown_3001B68->unk8 = param_1;
        sUnknown_3001B68->unkE = 0;
    }
}

void sub_809C6EC(void)
{
    if (sub_8098F88() == 0) {
        if (gGameOptionsRef->unkC == 0) {
            sub_809C6CC(4);
        }
        else {
            sub_809C6CC(3);
        }
    }
    else {
        sub_809C6CC(5);
    }
}

UNUSED static u16 sub_809C724(void)
{
    return sUnknown_3001B68->unk8;
}

bool8 sub_809C730(void)
{
    return sub_809C740();
}

bool8 sub_809C740(void)
{
    if (sUnknown_3001B68->unk0 == 0)
        return TRUE;
    else
        return FALSE;
}

// Called in a number of places, like when the player changes the team leader in sub_80278B4().
void nullsub_104(void)
{

}

void sub_809C760(void)
{
    sUnknown_3001B68->unkE = 1;
}

void sub_809C770(s16 mapId_, s16 groundPlaceId_)
{
    u8 friendAreaId;
    u8 uVar3;
    s32 iVar5;
    u32 uVar6;
    s32 mapId = mapId_;
    s32 groundPlaceId = groundPlaceId_;

    if (sUnknown_3001B68->unkE != 0) {
        sUnknown_3001B68->unkE = 0;
        return;
    }
    if (sUnknown_3001B68->unk8 == 0) {
        sub_809C6EC();
    }
    friendAreaId = sUnknown_3001B68->friendAreaId;
    uVar3 = sUnknown_3001B68->unk19;
    switch (groundPlaceId) {
        case GROUND_PLACE_FRIEND_AREAS:
            friendAreaId = MapIdToFriendAreaId(mapId);
            if (friendAreaId == FRIEND_AREA_NONE) {
                return;
            }
            uVar6 = 1;
            break;
        case GROUND_PLACE_SQUARE:
        case GROUND_PLACE_SQUARE_2:
        case GROUND_PLACE_POKEMON_SQUARE:
        case GROUND_PLACE_WHISCASH_POND:
        case GROUND_PLACE_PELIPPER_POST_OFFICE:
        case GROUND_PLACE_PELIPPER_POST_OFFICE_INSIDE:
        case GROUND_PLACE_MAKUHITA_DOJO:
        case GROUND_PLACE_MAKUHITA_DOJO_INSIDE:
        case GROUND_PLACE_LUMINOUS_CAVE:
        case GROUND_PLACE_TEAM_BASE:
        case GROUND_PLACE_TEAM_BASE_INSIDE:
            uVar6 = 1;
            friendAreaId = FRIEND_AREA_NONE;
            break;
        case GROUND_PLACE_DIRECTION:
            switch((s16)(mapId)) {
                case MAP_FUGITIVES_FISSURE:
                case MAP_FUGITIVES_FIRE:
                case MAP_FUGITIVES_SNOW_ROAD:
                case MAP_FUGITIVES_SNOW_FOREST:
                case MAP_FUGITIVES_BLIZZARD_ROAD:
                case MAP_NIGHTMARE:
                case MAP_NIGHT_SKY_1:
                case MAP_NIGHT_SKY_2:
                case MAP_THE_END:
                    uVar6 = 0;
                    break;
                default:
                    return;
            }
            break;
        case GROUND_PLACE_NEW_GAME:
        case GROUND_PLACE_SCENE:
        case GROUND_PLACE_INVALIDITY:
            uVar6 = 0;
            break;
        default:
            switch((s16)(groundPlaceId)) {
                case GROUND_PLACE_TINY_WOODS:
                    iVar5 = 0;
                    break;
                case GROUND_PLACE_MT_THUNDER:
                case GROUND_PLACE_MT_THUNDER_MID:
                    iVar5 = 7;
                    break;
                case GROUND_PLACE_GREAT_CANYON:
                case GROUND_PLACE_HILL_OF_THE_ANCIENTS:
                    iVar5 = 9;
                    break;
                case GROUND_PLACE_LAPIS_CAVE:
                    iVar5 = 10;
                    break;
                case GROUND_PLACE_MT_BLAZE:
                case GROUND_PLACE_MT_BLAZE_MID:
                    iVar5 = 0xb;
                    break;
                case GROUND_PLACE_FROSTY_FOREST:
                case GROUND_PLACE_FROSTY_CLEARING:
                    iVar5 = 0xd;
                    break;
                case GROUND_PLACE_MT_FREEZE:
                case GROUND_PLACE_MT_FREEZE_MID:
                    iVar5 = 0xf;
                    break;
                case GROUND_PLACE_MAGMA_CAVERN:
                case GROUND_PLACE_MAGMA_CAVERN_MID:
                    iVar5 = 0x11;
                    break;
                case GROUND_PLACE_SKY_TOWER:
                case GROUND_PLACE_SKY_TOWER_MID:
                    iVar5 = 0x13;
                    break;
                case GROUND_PLACE_WESTERN_CAVE:
                    iVar5 = 0x20;
                    break;
                case GROUND_PLACE_DUNGEON:
                default:
                    iVar5 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
                    break;

            }
            if (iVar5 == -1) {
                return;
            }
            uVar3 = sub_80A2740(iVar5);
            uVar6 = 2;
            break;
    }

    if (sUnknown_3001B68->unk10 != uVar6) {
        sUnknown_3001B68->unk0 = 2;
        sUnknown_3001B68->unkC = 1;
        sUnknown_3001B68->unk20 = 1;
    }
    else {
        if (uVar6 == 1) {
            if (friendAreaId != sUnknown_3001B68->friendAreaId || sUnknown_3001B68->mapId != mapId) {
                sUnknown_3001B68->unkC = 1;
                sUnknown_3001B68->unk20 = 1;
            }
            else {
                if (friendAreaId == FRIEND_AREA_NONE && sUnknown_3001B68->groundPlaceId != groundPlaceId) {
                    sUnknown_3001B68->unkC = 1;
                }
            }
        }
        else if (uVar6 == 2 &&
            (uVar3 != sUnknown_3001B68->unk19 || (sUnknown_3001B68->groundPlaceId != groundPlaceId)))
        {
            sUnknown_3001B68->unkC = 1;
            sUnknown_3001B68->unk20 = 1;
        }
    }

    if (sUnknown_3001B68->unkC != 0) {
        sUnknown_3001B68->unk10 = uVar6;
        sUnknown_3001B68->mapId = mapId;
        sUnknown_3001B68->groundPlaceId = groundPlaceId;
        sUnknown_3001B68->friendAreaId = friendAreaId;
        sUnknown_3001B68->unk19 = uVar3;
        if (sUnknown_3001B68->unk8 != 4) {
            sUnknown_3001B68->unkC = 0;
            sUnknown_3001B68->unk20 = 0;
        }
    }
}

void nullsub_105(void)
{

}

void sub_809CA20(void)
{
    if (sUnknown_3001B68->unk0 != 0) {
        sUnknown_3001B68->unk0 = 0;
        sUnknown_3001B68->unk4 = 0x1f;
        sUnknown_3001B68->unkC = 1;
    }
    if (sUnknown_3001B68->unkC != 0) {
        sUnknown_3001B68->unkA = sUnknown_3001B68->unk8;
        if (sUnknown_3001B68->unk8 == 4 && sUnknown_3001B68->unk10 == 0) {
            sUnknown_3001B68->unkA = 2;
            sUnknown_3001B68->unk1C = 0;
            sUnknown_3001B68->unk20 = 0;
        }
        switch (sUnknown_3001B68->unkA) {
            case 3:
                nullsub_111();
                nullsub_113();
                nullsub_112();
                sUnknown_3001B68->unkD = 1;
                break;
            case 4:
                nullsub_114();
                nullsub_115();
                nullsub_116();
                break;
            case 2:
                nullsub_109();
                nullsub_110();
                break;
            case 5:
                nullsub_107();
                nullsub_108();
                break;
            case 0:
            case 1:
                nullsub_107();
                nullsub_108();
                break;
        }
        sUnknown_3001B68->unkC = 0;
    }
    else {
        switch (sUnknown_3001B68->unkA) {
            case 3:
                nullsub_113();
                break;
            case 4:
                nullsub_116();
            case 0:
            case 1:
            case 2:
            case 5:
                break;
        }
    }
}

void nullsub_106(void)
{

}

static void nullsub_107(void)
{

}

static void nullsub_108(void)
{

}

static void nullsub_109(void)
{

}

static void nullsub_110(void)
{

}

static void nullsub_111(void)
{

}

static void nullsub_112(void)
{

}

static void nullsub_113(void)
{

}

static void nullsub_114(void)
{

}

static void nullsub_115(void)
{

}

static void nullsub_116(void)
{

}

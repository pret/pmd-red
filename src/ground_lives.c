#include "global.h"
#include "globaldata.h"
#include "ground_lives.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "ground_event.h"
#include "ground_main.h"
#include "memory.h"
#include "event_flag.h"
#include "pokemon.h"
#include "friend_area.h"
#include "random.h"
#include "code_80958E8.h"
#include "debug.h"
#include "other_random.h"
#include "text_util.h"
#include "code_8002774.h"
#include "friend_area_dialogue.h"
#include "ground_lives_helper.h"
#include "ground_sprite_monster.h"
#include "ground_object.h"
#include "code_809D148.h"

struct GroundLivesMeta_Sub1
{
    // size: 0xC
    s32 unk0;
    u32 unk4;
    s32 unk8;
};

struct GroundLivesMeta_Sub2C
{
    s32 unk0;
    PixelPos unk4;
};

#define GROUND_LIVES_META_UNK0_COUNT 3
#define GROUND_LIVES_META_UNK2C_COUNT 64

struct unkStruct_3001B80
{
    // size: 0x338
    struct GroundLivesMeta_Sub1 unk0[GROUND_LIVES_META_UNK0_COUNT];
    s32 unk24;
    s8 unk28;
    struct GroundLivesMeta_Sub2C unk2C[GROUND_LIVES_META_UNK2C_COUNT];
    ScriptInfoSmall unk32C;
};
IWRAM_INIT struct unkStruct_3001B80 *gGroundLivesMeta = NULL;

struct GroundLive
{
    // size: 0x1F0
    s16 id; // ID in the gGroundLives array
    s16 unk2;
    s16 unk4;
    s8 unk6;
    s16 speciesId;
    PixelPos unkC;
    PixelPos unk14;
    s8 unk1C;
    PixelPos unk20;
    PixelPos unk28;
    PixelPos unk30;
    Action action;
    u32 flags;
    struct GroundLives_Sub120 unk120;
    s16 unk13C;
    s16 unk13E;
    s16 friendAreaDialogueId;
    s8 direction1;
    PixelPos unk144;
    PixelPos unk14C;
    PixelPos unk154;
    bool8 directionRelated;
    s8 direction2;
    u16 unk15E;
    u16 unk160;
    s32 unk164;
    s16 unk168;
    s16 unk16A;
    s32 unk16C;
    struct UnkGroundSpriteStruct unk170;
};

#define UNK_3001B84_ARR_COUNT 0x18

struct GroundLives
{
    struct GroundLive array[UNK_3001B84_ARR_COUNT];
};

IWRAM_INIT struct GroundLives *gGroundLives = NULL;

struct GroundLiveTypeData
{
    s16 unk0;
    s16 unk2;
    const char *unk4;
    u8 unk8;
    u8 unk9;
};

extern const struct GroundLiveTypeData gGroundLivesTypeData_811E63C[];

extern s32 sub_8002984(s32 _direction1, u32 caseID);
extern bool8 sub_80A66F8(struct UnkGroundSpriteStruct *ptr);
extern bool8 sub_80A671C(struct UnkGroundSpriteStruct *ptr);
extern bool8 sub_80A595C(u32 a0, PixelPos *pixelPosArg1, PixelPos *pixelPosArg2);
extern PixelPos SetVecFromDirectionSpeed(s32 r1, u32 r2);
extern u8 sub_80A5934(s32 param_1, PixelPos *, PixelPos *);
extern bool8 CheckMapCollision_80A585C(PixelPos *, PixelPos *);
extern bool8 sub_80A58C8(PixelPos *, PixelPos *);
extern bool8 sub_809B1C0(s32 a0, u32 kind, Pokemon *a2);
extern Pokemon *sub_80A8D54(s32);
extern bool8 GetCurrentDungeonBounds(PixelPos *a0, PixelPos *a1);
extern const struct GroundScriptHeader *GetGroundScript(s16 a0, const DebugLocation *);

static s32 sub_80A7B94(s16 *a0);
static s32 GroundLives_Add(s32 id_, const GroundLivesData *ptr, s32 group_, s32 sector_);
static void GroundLives_Delete(s32 id_);
static bool8 sub_80A9750(struct GroundLive *ptr, u16 a1);
static s32 sub_80A9F20(struct GroundLive *livesPtr, PixelPos *pixelPosArg);
static bool8 sub_80AA3F8(struct GroundLive *livesPtr, s32 a1_);
static void sub_80AAF68(struct GroundLive *livesPtr, u32 unused);
static s16 CallbackLivesGetIndex(void *livesPtr_);
static void CallbackLivesGetSize(void *livesPtr_, PixelPos *out);
static void CallbackLivesSetHitboxPos(void *livesPtr_, PixelPos *posOrNull);
static void CallbackLivesSetPositionBounds(void *livesPtr_, PixelPos *from, PixelPos *to);
static void CallbackLivesGetHitboxCenter(void *livesPtr_, PixelPos *out);
static s32 CallbackLivesMoveReal(void *livesPtr_, PixelPos *pos);
static void CallbackLivesGetPosHeightAndUnk(void *livesPtr_, u32 *height, u32 *unk);
static void CallbackLivesSetPosHeight(void *livesPtr_, u32 height);
static void CallbackLivesGetDirection(void *livesPtr_, s8 *dir);
static void CallbackLivesSetDirection(void *livesPtr_, s32 dir_);
static void CallbackLivesSetEventIndex(void *livesPtr_, u16 a1);
static void CallbackLivesSetUnk_80AB194(void *livesPtr_, s32 a1_, s32 a2);
static void nullsub_211(void *livesPtr_, u16 a1);
static bool8 CallbackLivesSpriteRelatedCheck_80AB1C0(void *livesPtr_);
static bool8 CallbackLivesSpriteRelated_80AB1E4(void *livesPtr_);
static void CallbackLivesGetFlags(void *livesPtr_, u32 *flags);
static void CallbackLivesSetFlags(void *livesPtr_, u32 flags);
static void CallbackLivesClearFlags(void *livesPtr_, u32 flags);
static void CallbackLivesSpriteRelated_80AB238(void *livesPtr_, s32 a1);
static s32 CallbackLivesMoveRelative(void *livesPtr_, PixelPos *pos);
static void sub_80AB5A4(void);
static void sub_80AB5D4(struct GroundLive *livesPtr);
static s32 sub_80ABA00(s32 a0);

static const CallbackData gGroundLivesCallbacks = {
    .maybeId = 1,
    .getIndex = CallbackLivesGetIndex,
    .getSize = CallbackLivesGetSize,
    .getHitboxCenter = CallbackLivesGetHitboxCenter,
    .getPosHeightAndUnk = CallbackLivesGetPosHeightAndUnk,
    .getDirection = CallbackLivesGetDirection,
    .getFlags = CallbackLivesGetFlags,
    .setHitboxPos = CallbackLivesSetHitboxPos,
    .setPositionBounds = CallbackLivesSetPositionBounds,
    .moveReal = CallbackLivesMoveReal,
    .setPosHeight = CallbackLivesSetPosHeight,
    .setDirection = CallbackLivesSetDirection,
    .setEventIndex = CallbackLivesSetEventIndex,
    .livesOnlyNullsub = nullsub_211,
    .func38 = CallbackLivesSetUnk_80AB194,
    .setFlags = CallbackLivesSetFlags,
    .clearFlags = CallbackLivesClearFlags,
    .func44_livesOnlySpriteRelated = CallbackLivesSpriteRelated_80AB238,
    .moveRelative = CallbackLivesMoveRelative,
    .func4C_spriteRelatedCheck = CallbackLivesSpriteRelatedCheck_80AB1C0,
    .func50_spriteRelated = CallbackLivesSpriteRelated_80AB1E4,
};

static const s16 gUnknown_8117F64[] = {
    -1, 0x800, 0x300, 0x300, 0x807, 0x800, 0x805, 0x302,
    0x306, 0x80B, 0x307, 0x1006, 0x1002, 0x1001, 0x1008,
    0x100C, 0x1009, 0x100A, 0x1003, 0x1004, 0x803, 0x804,
    0x100D, 0x100E, 0x100F, 0x1010, 0x1011, 0x1012, 0x1013,
    0x1014, 0x80D, 0x80E, 0x80F, 0x810, 0x811, 0x812, 0x813,
    0x814, 0x80D, 0x100E, 0x100F, 0x1010, 0x1011, 0x812,
    0x1013, 0x1014, 0x1015, 0x1016, 0x1017, 0x818, 0x1019, 0x81A, 0x81B
};

static const s16 sStarterMons[] = {
    MONSTER_PIKACHU, MONSTER_MEOWTH, MONSTER_EEVEE, MONSTER_SKITTY, MONSTER_SQUIRTLE, MONSTER_TOTODILE,
    MONSTER_MUDKIP, MONSTER_PSYDUCK, MONSTER_CHARMANDER, MONSTER_TORCHIC, MONSTER_CYNDAQUIL, MONSTER_CUBONE,
    MONSTER_MACHOP, MONSTER_BULBASAUR, MONSTER_CHIKORITA, MONSTER_TREECKO,
    MONSTER_NONE
};

static const s32 gUnknown_8117FF0[] = {
    0x600, 0x441, 0x600, 0x441, 0x600, 0x441, 0x600, 0x441
};

static const s32 gUnknown_8118010[] = {
    0x2000, 0x16B1, 0x2000, 0x16B1, 0x2000, 0x16B1, 0x2000, 0x16B1
};

static const s32 gUnknown_8118030[] = {
    0x800, 0x5AC, 0x800, 0x5AC, 0x800, 0x5AC, 0x800, 0x5AC
};

static const s32 gUnknown_8118050[] = {
    0x1400, 0x1400, 0x1800
};

void AllocGroundLives(void)
{
    s32 index;
    struct GroundLive *ptr;

    gGroundLivesMeta = MemoryAlloc(sizeof(*gGroundLivesMeta),6);
    gGroundLives = MemoryAlloc(sizeof(*gGroundLives),6);

    for (index = 0, ptr = &gGroundLives->array[index]; index < UNK_3001B84_ARR_COUNT; index = (s16)(index + 1), ptr++) {
        ptr->unk2 = -1;
    }
    GetFunctionScript(0,&gGroundLivesMeta->unk32C,0x19);
    gGroundLivesMeta->unk32C.state = 1;
    DeleteGroundLives();
}

void DeleteGroundLives(void)
{
    int i;
    struct GroundLive *iVar4;

    iVar4 = &gGroundLives->array[0];
    for (i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), iVar4++) {
        if (iVar4->unk2 != -1) {
            GroundLives_Delete(i);
        }
    }

    gGroundLivesMeta->unk24 = -1;
    gGroundLivesMeta->unk28 = -1;

    for (i = 0; i < GROUND_LIVES_META_UNK0_COUNT; i++) {
        struct GroundLivesMeta_Sub1 *ptr0 = &gGroundLivesMeta->unk0[i];
        ptr0->unk8 = -1;
        ptr0->unk0 = 0;
        ptr0->unk4 = 0;
    }


    for (i = 0; i < GROUND_LIVES_META_UNK2C_COUNT; i++) {
        struct GroundLivesMeta_Sub2C *ptr2C = &gGroundLivesMeta->unk2C[i];
        ptr2C->unk0 = 0;
        ptr2C->unk4.x = 0;
        ptr2C->unk4.y = 0;
    }
}

void FreeGroundLives(void)
{
    DeleteGroundLives();
    MemoryFree(gGroundLives);
    gGroundLives = NULL;
    MemoryFree(gGroundLivesMeta);
    gGroundLivesMeta = NULL;
}

void GroundLives_Select(s32 scriptID, s32 group, s32 sector)
{
    const struct GroundScriptHeader *scriptPtr;
    const struct GroundScriptSector *sectorPtr;
    const struct GroundScriptGroup *groupPtr;

    s32 i;
    s32 size;
    const GroundLivesData *livesData;
    s32 sector_s32;
    s32 group_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    group_s32 = (s16)group;
    sector_s32 = (s8)sector;
    scriptPtr = GetGroundScript(scriptID_s32, DEBUG_LOC_PTR("../ground/ground_lives.c", 542, "GroundLives_Select"));
    Log('\0',"GroundLives Select %3d  %3d  %3d", scriptID_s32, group_s32, sector_s32);

    groupPtr = &scriptPtr->groups[group_s32];
    sectorPtr = &groupPtr->sectors[sector_s32];
    livesData = sectorPtr->lives;

    size = sectorPtr->nLives;
    for (i = 0; i < size; i++, livesData++)
    {
        GroundLives_Add(-1,livesData,group_s32,sector_s32);
    }
}

void GroundLives_Cancel(s32 scriptID, s32 sector)
{
    s32 index;
    struct GroundLive *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',"GroundLives Cancel %3d  %3d", scriptID_s32, sector_s32);

    index = 0;
    ptr = &gGroundLives->array[0];
    for(; index < UNK_3001B84_ARR_COUNT; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk2 != -1) && (ptr->unk4 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unk6 == sector_s32)
                GroundLives_Delete(index);
    }
}

void GroundLives_CancelBlank_1(void)
{
    s32 i;
    struct GroundLive *ptr;

    Log(0, "GroundLives CancelBlank");
    for (i = 0, ptr = &gGroundLives->array[0]; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1) {
            PixelPos pixelPos;

            pixelPos.x = ptr->unk144.x + ptr->unk14.x;
            pixelPos.y = ptr->unk144.y + ptr->unk14.y;
            if (!IsOnscreen_80A675C(&ptr->unk170, &pixelPos)) {
                GroundLives_Delete(i);
            }
        }
    }
}

void GroundLives_CancelBlank_2(void)
{
    s32 i;
    struct GroundLive *ptr;

    Log(0, "GroundLives CancelBlank");
    for (i = 0, ptr = &gGroundLives->array[0]; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1) {
            if (ptr->flags & 0x800) {
                ptr->unk13E = FindGroundEvent(0x20, &ptr->unk144, &ptr->unk14C);
            }
            else {
                ptr->unk13E = -1;
            }
        }
    }
}

s32 sub_80A7AE8(s16 a0)
{
    s32 i;
    struct GroundLive *ptr;
    s16 sp = a0;

    sub_80A7B94(&sp);
    if (sp != -1) {
        for (i = 0, ptr = &gGroundLives->array[0]; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), ptr++) {
            if (ptr->unk2 == sp) {
                return i;
            }
        }
    }

    return -1;
}

UNUSED static s16 sub_80A7B40(s32 a0_)
{
    s32 i;
    struct GroundLive *ptr;
    s32 a0 = (s16) a0_;

    for (i = 0, ptr = &gGroundLives->array[0]; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1 && ptr->unk13C == a0) {
            return i;
        }
    }

    return -1;
}

static s32 sub_80A7B94(s16 *a0)
{
    s32 id = *a0;
    const struct GroundLiveTypeData *dataPtr = &gGroundLivesTypeData_811E63C[id];
    s32 ret = -1;

    if (dataPtr->unk0 == 1) {
        if (*a0 == 0) {
            switch (GetScriptVarValue(NULL, PLAYER_KIND)) {
                case 0:
                    *a0 = 1;
                    break;
                case 1:
                    *a0 = 2;
                    break;
                case 2: {
                    Pokemon *playerMonStruct = GetPlayerPokemonStruct();
                    if (sub_808D3BC() == playerMonStruct) {
                        *a0 = 1;
                    }
                    else if (sub_808D3F8() == playerMonStruct) {
                        *a0 = 2;
                    }
                    else {
                        *a0 = 3;
                    }
                    break;
                default:
                    *a0 = -1;
                    return -1;
                }
            }
        }
        ret = 0;
    }
    else if (dataPtr->unk0 == 2) {
        u32 partner;
        s32 partner1 = GetScriptVarValue(NULL, PARTNER1_KIND);
        s32 partner2 = GetScriptVarValue(NULL, PARTNER2_KIND);

        if (*a0 == 4 || *a0 == 5) {
            if (*a0 == 4) {
                partner = partner1;
                if (partner == 0) {
                    partner = partner2;
                }
            }
            else {
                partner = 0;
                if (partner1 != 0) {
                    partner = partner2;
                }
            }

            switch (partner) {
                case 1:
                    *a0 = 6;
                    break;
                case 2:
                    *a0 = 7;
                    break;
                case 3: {
                    Pokemon *playerMonStruct = GetPlayerPokemonStruct();
                    if (sub_808D3BC() == playerMonStruct) {
                        *a0 = 6;
                    }
                    else if (sub_808D3F8() == playerMonStruct) {
                        *a0 = 7;
                    }
                    else {
                        *a0 = 8;
                    }
                    break;
                default:
                    *a0 = -1;
                    return -1;
                }
            }
        }

        switch (*a0) {
            case 6:
                ret = 2;
                if (GetPlayerPokemonStruct() == sub_808D3BC()) {
                    *a0 = 6;
                }
                break;
            case 7:
                ret = 1;
                if (GetPlayerPokemonStruct() == sub_808D3F8()) {
                    *a0 = 6;
                }
                break;
            case 8:
                ret = 2;
                break;
            default:
            *a0 = -1;
            return -1;
        }
    }
    else if (dataPtr->unk0 == 3) {
        if (*a0 >= 10 && *a0 <= 13) {
            s32 val;
            s32 sp[4];
            s32 id = *a0 - 10;

            if (sub_8098F88()) {
                return -1;
            }

            if (sub_80023E4(9)) {
                val = sub_808D6A4(sp);
            }
            else {
                val = sub_808D654(sp);
            }

            if (id < val) {
                return -1;
            }
        }
        else if (*a0 >= 14 && *a0 <= 29) {
            FriendAreaCapacity fAreaCapacity;
            u8 map = MapIdToFriendAreaId(GetScriptVarValue(NULL, GROUND_MAP));

            if (map != 0) {
                s32 id = *a0 - 14;
                GetFriendAreaCapacity2(map, &fAreaCapacity, FALSE, FALSE);
                if (id < fAreaCapacity.maxPokemon) {
                    Pokemon *monStrPtr = &gRecruitedPokemonRef->pokemon[fAreaCapacity.unk8 + id];
                    if (sub_80023E4(9)) {
                        if (PokemonExists(monStrPtr) && !monStrPtr->isTeamLeader) {
                            return -1;
                        }
                    }
                    else {
                        if (PokemonExists(monStrPtr) && !monStrPtr->isTeamLeader && !IsMonPartner(monStrPtr)) {
                            return -1;
                        }
                    }
                }
            }
        }
        *a0 = -1;
        return -1;
    }
    else if (id == 0x23) {
        Pokemon *playerMonStruct = GetPlayerPokemonStruct();
        if (sub_808D3BC() == playerMonStruct) {
            *a0 = 0x21;
        }
        else if (sub_808D3F8() == playerMonStruct) {
            *a0 = 0x22;
        }
    }

    return ret;
}

static const s16 gUnknown_81180F0[] = {MONSTER_ONIX, MONSTER_NIDOKING, MONSTER_PIDGEY, MONSTER_RATTATA, MONSTER_SANDSHREW, MONSTER_ZUBAT};

s32 sub_80A7DDC(s16 *a0, s16 *speciesDst)
{
    const struct GroundLiveTypeData *dataPtr;
    s32 ret = (s16) sub_80A7B94(a0);

    *speciesDst = MONSTER_NONE;
    if (*a0 == -1) {
        return -1;
    }

    dataPtr = &gGroundLivesTypeData_811E63C[*a0];
    if (dataPtr->unk0 == 3) {
        if (*a0 >= 10 && *a0 < 14) {
            s32 val;
            s32 sp[4];
            s32 id = *a0 - 10;

            if (sub_8098F88()) {
                *speciesDst = gUnknown_81180F0[id];
                if (*speciesDst == 0) {
                    *a0 = -1;
                }
                return -1;
            }

            if (sub_80023E4(9)) {
                val = sub_808D6A4(sp);
            }
            else {
                val = sub_808D654(sp);
            }

            if (id < val) {
                Pokemon *monStrPtr = &gRecruitedPokemonRef->pokemon[sp[id]];
                *speciesDst = monStrPtr->speciesNum;
                return -1;
            }
        }
        else if (*a0 >= 14 && *a0 <= 29) {
            FriendAreaCapacity fAreaCapacity;
            u8 map = MapIdToFriendAreaId(GetScriptVarValue(NULL, GROUND_MAP));

            if (map != 0) {
                s32 id = *a0 - 14;
                GetFriendAreaCapacity2(map, &fAreaCapacity, FALSE, FALSE);
                if (id < fAreaCapacity.maxPokemon) {
                    Pokemon *monStrPtr = &gRecruitedPokemonRef->pokemon[fAreaCapacity.unk8 + id];
                    if (sub_80023E4(9)) {
                        if (PokemonExists(monStrPtr) && !monStrPtr->isTeamLeader) {
                            *speciesDst = monStrPtr->speciesNum;
                            return -1;
                        }
                    }
                    else {
                        if (PokemonExists(monStrPtr) && !monStrPtr->isTeamLeader && !IsMonPartner(monStrPtr)) {
                            *speciesDst = monStrPtr->speciesNum;
                            return -1;
                        }
                    }
                }
            }
        }

        *a0 = -1;
        return -1;
    }
    else {
        switch (*a0) {
            case 1:
            case 6:
            case 33:
                *speciesDst = sub_808D3BC()->speciesNum;
                break;
            case 2:
            case 7:
            case 34:
                *speciesDst = sub_808D3F8()->speciesNum;
                break;
            case 3:
            case 8:
            case 35:
                *speciesDst = GetPlayerPokemonStruct()->speciesNum;
                break;
            case 36: {
                // Identical to sStarterMons table
                static const s16 starterSpecies[] = { MONSTER_PIKACHU, MONSTER_MEOWTH, MONSTER_EEVEE, MONSTER_SKITTY, MONSTER_SQUIRTLE, MONSTER_TOTODILE,
                    MONSTER_MUDKIP, MONSTER_PSYDUCK, MONSTER_CHARMANDER, MONSTER_TORCHIC, MONSTER_CYNDAQUIL, MONSTER_CUBONE,
                    MONSTER_MACHOP, MONSTER_BULBASAUR, MONSTER_CHIKORITA, MONSTER_TREECKO
                };

                *speciesDst = starterSpecies[RandInt(ARRAY_COUNT(starterSpecies) - 1)]; // For some reason it ignores the last entry
                return -1;
            }

            case 32: {
                s32 friendSpecies = (s16) GetScriptVarValue(NULL, NEW_FRIEND_KIND);
                if (friendSpecies != MONSTER_NONE) {
                    *speciesDst = friendSpecies;
                }
                else {
                    *a0 = -1;
                }
                return -1;
            }
            case 30:
            case 31: {
                u8 dungId;
                u32 outMain, outSub;
                struct unkStruct_8096AF8 unkStruct;

                *speciesDst = MONSTER_PORYGON;
                if (sub_8099328(&dungId)) {
                    GetScriptVarScenario(SCENARIO_SELECT, &outMain, &outSub);
                    sub_8096AF8(&unkStruct, outSub, dungId);
                    if (unkStruct.unk0) {
                        if (*a0 == 30) {
                            *speciesDst = unkStruct.clientSpecies;
                        }
                        else {
                            *speciesDst = unkStruct.targetSpecies;
                        }
                    }

                    if (*speciesDst == 0) {
                        *a0 = -1;
                    }
                }
                return -1;
            }
        default:
            if (*speciesDst == 0) {
                *speciesDst = dataPtr->unk2;
            }
            break;
        }
    }

    return ret;
}

static s32 GroundLives_Add(s32 id_, const GroundLivesData *ptr, s32 group_, s32 sector_)
{
    s32 id = (s16) id_;
    s32 group = (s16) group_;
    s32 sector = (s8) sector_;
    struct GroundLive *livesPtr;
    const struct GroundLiveTypeData *typeDataPtr;
    const ScriptCommand *scrCommand;
    s16 sp12, species;
    bool8 var24;
    bool8 r8;
    s32 r7;

    sp12 = ptr->kind;
    r8 = FALSE;
    r7 = (s16) sub_80A7DDC(&sp12, &species);

    if (sp12 == -1)
        return -1;

    switch (r7) {
        case 0:
            id = 0;
            break;
        case 1:
            id = 1;
            break;
        case 2:
            if (GetScriptVarValue(NULL, PARTNER1_KIND) == 0) {
                r7 = 1;
            }
            id = 2;
            break;
    }

    typeDataPtr = &gGroundLivesTypeData_811E63C[sp12];
    if (id < 0) {
        switch (sp12) {
            case 0x21:
                if (gGroundLives->array[0].unk2 == 1)
                    return -1;
                id = sub_80A7AE8(sp12);
                break;
            case 0x23:
                if (gGroundLives->array[0].unk2 == 3)
                    return -1;
                id = sub_80A7AE8(sp12);
                break;
            default:
                id = sub_80A7AE8(sp12);
                break;
        }

        if (id < 0) {
            s32 i = 3;
            livesPtr = &gGroundLives->array[3];

            for (; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
                if (livesPtr->unk2 == -1) {
                    id = i;
                    break;
                }
            }
        }

        if (id < 0) {
            return -1;
        }
    }

    livesPtr = &gGroundLives->array[id];
    Log(0, "GroundLive Add id %3d  kind %3d  type %3d  group %3d  sector %3d", id, sp12, typeDataPtr->unk0, group, sector);
    var24 = (livesPtr->unk2 == -1);
    livesPtr->id = id;
    livesPtr->unk2 = sp12;
    livesPtr->unk4 = group;
    livesPtr->unk6 = sector;
    livesPtr->speciesId = species;
    sub_809CD68(&livesPtr->unk120);
    livesPtr->unk120.unk0 = 9;

    switch (typeDataPtr->unk0) {
        case 1:
            livesPtr->flags = 0x2300181D;
            livesPtr->unk120.unk0 = 1;
            break;
        case 2:
            livesPtr->flags = 0x23001000;
            break;
        case 3:
            livesPtr->flags = 0x2300068D;
            break;
        case 6:
            livesPtr->flags = 0x2000000D;
            break;
        case 7:
            livesPtr->flags = 0x20000;
            break;
        case 8:
            livesPtr->flags = 0;
            break;
        case 9:
            livesPtr->flags = 0xC0000;
            break;
        case 10:
            livesPtr->flags = 0x20010000;
            break;
        default:
            livesPtr->flags = 0x2300068D;
            break;
    }

    livesPtr->unkC.x = typeDataPtr->unk8 << 11;
    livesPtr->unkC.y = typeDataPtr->unk9 << 11;
    livesPtr->unk14.x = livesPtr->unkC.x / 2;
    livesPtr->unk14.y = livesPtr->unkC.y / 2;
    livesPtr->unk1C = ptr->unk1;
    SetUnkInGroundEvent(&ptr->pos, &livesPtr->unk20);
    if (var24) {
        struct GroundLivesMeta_Sub1 *metaPtr;

        livesPtr->direction1 = livesPtr->unk1C;
        livesPtr->unk144.x = livesPtr->unk20.x - livesPtr->unk14.x;
        livesPtr->unk14C.x = livesPtr->unk20.x + livesPtr->unk14.x;
        livesPtr->unk144.y = livesPtr->unk20.y - livesPtr->unk14.y;
        livesPtr->unk14C.y = livesPtr->unk20.y + livesPtr->unk14.y;
        livesPtr->unk154.x = livesPtr->unk154.y = 0;
        livesPtr->unk13C = r7;
        metaPtr = &gGroundLivesMeta->unk0[r7];
        metaPtr->unk8 = -1;
        metaPtr->unk0 = 0;
        metaPtr->unk4 = 0;
        if (livesPtr->unk2 >= 14 && livesPtr->unk2 <= 29) {
            livesPtr->friendAreaDialogueId = OtherRandInt(FRIEND_AREA_DIALOGUES_COUNT);
        }
        else {
            livesPtr->friendAreaDialogueId = 0;
        }
    }

    if (livesPtr->flags & 0x800) {
        livesPtr->unk13E = FindGroundEvent(0x20, &livesPtr->unk144, &livesPtr->unk14C);
    }
    else {
        livesPtr->unk13E = -1;
    }

    GetCurrentDungeonBounds(&livesPtr->unk28, &livesPtr->unk30);
    if (var24) {
        livesPtr->direction2 = -1;
        livesPtr->unk15E = 0x300;
        livesPtr->unk160 = 1;
        livesPtr->unk164 = 0;
        livesPtr->unk168 = 0x807;
        livesPtr->directionRelated = TRUE;
        livesPtr->unk16A = 0;
        sub_80A7428(&livesPtr->unk170, livesPtr->unk2, livesPtr->speciesId, livesPtr->flags);
    }

    if (!var24) {
        if (sub_809D684(&livesPtr->action, &gGroundLivesMeta->unk32C)) {
            s32 r10;
            s32 r9;
            // Note: these ptr variables are unfortunately a fakematch, but I was not able to match the function without them...
            u16 *ptr1;
            s8 *ptr2;

            if (livesPtr->action.scriptData2.savedState != 0) {
                r10 = livesPtr->action.scriptData2.unk24;
                r9 = livesPtr->action.scriptData2.unk26;

                ptr1 = &livesPtr->action.scriptData.unk24;
                ptr2 = &livesPtr->action.scriptData.unk26;
            }
            else {
                r10 = livesPtr->action.scriptData.unk24;
                r9 = livesPtr->action.scriptData.unk26;

                ptr1 = &livesPtr->action.scriptData.unk24;
                ptr2 = &livesPtr->action.scriptData.unk26;
            }

            InitAction2(&livesPtr->action);
            InitActionWithParams(&livesPtr->action, &gGroundLivesCallbacks, livesPtr, group, sector);
            GroundScript_ExecutePP(&livesPtr->action, NULL, &gGroundLivesMeta->unk32C, DEBUG_LOC_PTR("../ground/ground_lives.c", 1417, "GroundLives_Add"));
            ASM_MATCH_TRICK(ptr2);
            *ptr1 = r10;
            *ptr2 = r9;
            r8 = TRUE;
        }
        else {
            InitAction2(&livesPtr->action);
            InitActionWithParams(&livesPtr->action, &gGroundLivesCallbacks, livesPtr, group, sector);
        }
    }
    else {
        InitActionWithParams(&livesPtr->action, &gGroundLivesCallbacks, livesPtr, group, sector);
    }

    scrCommand = ptr->scripts[1];
    if (scrCommand == NULL) {
        scrCommand = gFunctionScriptTable[19].script;
    }
    SetPredefinedScript(&livesPtr->action, 1, scrCommand);

    scrCommand = ptr->scripts[2];
    if (scrCommand == NULL) {
        scrCommand = gFunctionScriptTable[4].script;
    }
    SetPredefinedScript(&livesPtr->action, 2, scrCommand);

    scrCommand = ptr->scripts[3];
    if (scrCommand == NULL) {
        scrCommand = gFunctionScriptTable[6].script;
    }
    SetPredefinedScript(&livesPtr->action, 3, scrCommand);

    if (ptr->scripts[0] != NULL) {
        SetPredefinedScript(&livesPtr->action, 0, ptr->scripts[0]);
        if (!var24 && !r8 && !(livesPtr->flags & 0x1800)) {
            GroundScript_ExecutePP(&livesPtr->action, NULL, &gGroundLivesMeta->unk32C, DEBUG_LOC_PTR("../ground/ground_lives.c", 1460, "GroundLives_Add"));
            livesPtr->action.scriptData.unk24 = livesPtr->unk160 | livesPtr->unk15E;
            livesPtr->action.scriptData.unk26 = livesPtr->direction1;
        }
        ExecutePredefinedScript(&livesPtr->action, NULL, 0, DEBUG_LOC_PTR("../ground/ground_lives.c", 1466, "GroundLives_Add"));
    }
    else if (r8) {
        livesPtr->directionRelated = TRUE;
        livesPtr->direction1 = livesPtr->action.scriptData.unk26;
        sub_80A9750(livesPtr, livesPtr->action.scriptData.unk24);
    }

    if (typeDataPtr->unk0 == 1 && var24) {
        sub_809D170(1, id);
    }

    return id;
}

static void GroundLives_Delete(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    Log(0, "GroundLives Delete id %3d", id);
    sub_80A74E4(&livesPtr->unk170);
    InitAction2(&livesPtr->action);
    livesPtr->unk2 = -1;
}

void sub_80A86C8(s32 id_, u32 flags)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        if (livesPtr->unk13C == 0) {
            if (flags & 0x3000) {
                sub_80AB5A4();
            }
        }
        else {
            if (flags & 0x1000) {
                struct GroundLivesMeta_Sub1 *metaPtr = &gGroundLivesMeta->unk0[livesPtr->unk13C];

                metaPtr->unk8 = -1;
                metaPtr->unk0 = 0;
                metaPtr->unk4 = 0;
            }
        }

        livesPtr->flags |= flags;
        sub_80A6688(&livesPtr->unk170, livesPtr->flags);
    }
}

static void sub_80A8750(s32 id_, u32 flags)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        if (livesPtr->unk13C == 0) {
            if (flags & 0x3000) {
                sub_80AB5A4();
            }
        }

        livesPtr->flags &= ~(flags);
        sub_80A6688(&livesPtr->unk170, livesPtr->flags);
    }
}

void sub_80A87AC(s32 id_, s32 a1)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        sub_809CD8C(&livesPtr->unk120, a1);
    }
}

bool8 sub_80A87E0(s32 id_, Pokemon *a1)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1 && sub_809B1C0(7, 0, a1)) {
        sub_809CD8C(&livesPtr->unk120, 5);
        return TRUE;
    }

    return FALSE;
}

Action *sub_80A882C(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return &livesPtr->action;
    }

    return NULL;
}

UNUSED static bool8 sub_80A885C(s32 id_, ScriptInfoSmall *scriptInfo, s32 a2_)
{
    s32 id = (s16) id_;
    s32 a2 = (s16) a2_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return GetPredefinedScript(&livesPtr->action, scriptInfo, a2);
    }

    return FALSE;
}

UNUSED static bool8 sub_80A88A0(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return sub_809D678(&livesPtr->action);
    }

    return FALSE;
}

bool8 GroundLives_ExecuteScript(s32 id_, ActionUnkIds *a1, ScriptInfoSmall *scriptInfo)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    Log(0, "GroundLives Execute %3d  kind %3d  %p", id, livesPtr->unk2, scriptInfo);

    if (livesPtr->unk2 != -1) {
        GroundScript_ExecutePP(&livesPtr->action, a1, scriptInfo, DEBUG_LOC_PTR("../ground/ground_lives.c", 1703, "GroundLives_ExecuteScript"));
        livesPtr->directionRelated = TRUE;
        return TRUE;
    }

    return FALSE;
}

static bool8 _ExecutePlayerScript(struct GroundLive *livesPtr, ActionUnkIds *a1, ScriptInfoSmall *scriptInfo)
{
    livesPtr->unk15E = 0x300;
    livesPtr->unk160 = 1;
    livesPtr->unk164 = 0;
    if (livesPtr->unk168 != 0x807) {
        livesPtr->unk168 = 0x807;
        livesPtr->directionRelated = TRUE;
    }

    if (scriptInfo != NULL) {
        return GroundScript_ExecutePP(&livesPtr->action, a1, scriptInfo, DEBUG_LOC_PTR("../ground/ground_lives.c", 1736, "_ExecutePlayerScript"));
    }

    return FALSE;
}

UNUSED static bool8 sub_80A89AC(s32 id_, ActionUnkIds *a1, ScriptInfoSmall *scriptInfo)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    return _ExecutePlayerScript(livesPtr, a1, scriptInfo);
}

bool8 GroundLives_ExecutePlayerScriptActionLives(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 >= 0 && id2 >= 0) {
        ScriptInfoSmall scriptInfo;
        struct GroundLive *livesPtr1 = &gGroundLives->array[id1];
        struct GroundLive *livesPtr2 = &gGroundLives->array[id2];

        if (livesPtr1->unk2 != -1 && livesPtr2->unk2 != -1 && GetPredefinedScript(&livesPtr2->action, &scriptInfo, 2)) {
            ActionUnkIds sp = {1, id2};

            ExecutePredefinedScript(&livesPtr2->action, &livesPtr1->action.unk8, 3, DEBUG_LOC_PTR("../ground/ground_lives.c", 1785, "GroundLives_ExecutePlayerScriptActionLives"));
            return _ExecutePlayerScript(livesPtr1, &sp, &scriptInfo);
        }
    }

    return FALSE;
}

static bool8 sub_80A8A5C(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 >= 0 && id2 >= 0) {
        ScriptInfoSmall scriptInfo1;
        struct GroundLive *livesPtr1 = &gGroundLives->array[id1];

        if (GroundObject_GetScript(id2, &scriptInfo1, 2)) {
            ScriptInfoSmall scriptInfo2;
            ActionUnkIds sp = {2, id2};

            GroundObject_GetScript(id2, &scriptInfo2, 3);
            GroundObject_ExecuteScript(id2, &livesPtr1->action.unk8, &scriptInfo2);
            return _ExecutePlayerScript(livesPtr1, &sp, &scriptInfo1);
        }
    }

    return FALSE;
}

static bool8 sub_80A8ACC(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 >= 0 && id2 >= 0) {
        ScriptInfoSmall scriptInfo;
        struct GroundLive *livesPtr1 = &gGroundLives->array[id1];

        if (sub_80ADC64(id2, &scriptInfo)) {
            return _ExecutePlayerScript(livesPtr1, NULL, &scriptInfo);
        }
    }

    return FALSE;
}

bool8 GroundLivesNotifyAll(s32 a0_)
{
    s32 i;
    s32 a0 = (s16) a0_;
    struct GroundLive *livesPtr = &gGroundLives->array[0];
    bool8 ret = FALSE;

    for (i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
        if (livesPtr->unk2 != -1) {
            ret |= GroundScriptNotify(&livesPtr->action, a0);
        }
    }

    return ret;
}

bool8 GroundLivesCancelAll(void)
{
    s32 i;
    struct GroundLive *livesPtr = &gGroundLives->array[0];
    bool8 ret = FALSE;

    for (i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
        if (livesPtr->unk2 != -1) {
            ret |= GroundScript_Cancel(&livesPtr->action);
        }
    }

    return ret;
}

s32 sub_80A8BBC(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    return livesPtr->unk2;
}

s32 sub_80A8BD8(s32 id_, u32 *a1)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    *a1 = livesPtr->flags;
    return livesPtr->unk2;
}

s32 sub_80A8BFC(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return livesPtr->speciesId;
    }

    return 0;
}

s32 sub_80A8C2C(s32 a0)
{
    s16 sp = a0;
    s16 species;

    sub_80A7DDC(&sp, &species);
    return species;
}

s32 sub_80A8C4C(s32 id_, DungeonLocation *dungLoc)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        Pokemon *monStrPtr = sub_80A8D54(livesPtr->unk2);
        if (monStrPtr != NULL) {
            *dungLoc = monStrPtr->dungeonLocation;
        }
        else {
            dungLoc->id = NUM_DUNGEONS + 1;
            dungLoc->floor = 0;
        }

        return livesPtr->speciesId;
    }

    return 0;
}

bool8 GroundLives_IsStarterMon(s32 id_)
{
    const s16 *arr;
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        for (arr = sStarterMons; *arr != MONSTER_NONE; arr++) {
            if (*arr == livesPtr->speciesId) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool8 IsStarterMonster(s32 monsterId_)
{
    const s16 *arr;
    s32 monsterId = (s16) monsterId_;

    for (arr = sStarterMons; *arr != MONSTER_NONE; arr++) {
        if (*arr == (s16) monsterId) {
            return TRUE;
        }
    }

    return FALSE;
}

bool8 sub_80A8D20(void)
{
    s32 id = (s16) sub_80A7AE8(0);
    struct GroundLive *livesPtr = &gGroundLives->array[id];
    s32 val = sub_809CDB8(&livesPtr->unk120);

    return (val == 1);
}

Pokemon *sub_80A8D54(s32 a0)
{
    s16 sp = a0;

    sub_80A7B94(&sp);
    if (sp == 1 || sp == 6 || sp == 33) {
        return sub_808D3BC();
    }
    if (sp == 2 || sp == 7 || sp == 34) {
        return sub_808D3F8();
    }
    if (sp == 3 || sp == 8 || sp == 35) {
        return GetPlayerPokemonStruct();
    }

    if (sp >= 10 && sp <= 13) {
        s32 val;
        s32 spArray[4];
        s32 id = sp - 10;

        if (sub_8098F88())
            return NULL;

        if (sub_80023E4(9)) {
            val = sub_808D6A4(spArray);
        }
        else {
            val = sub_808D654(spArray);
        }

        if (id >= val)
            return NULL;

        return &gRecruitedPokemonRef->pokemon[spArray[id]];
    }
    else if (sp >= 14 && sp <= 29) {
        Pokemon *monPtr;
        s32 id;
        FriendAreaCapacity fAreaCapacity;
        u8 map = MapIdToFriendAreaId(GetScriptVarValue(NULL, GROUND_MAP));

        if (map == 0)
            return NULL;

        id = sp - 14;
        GetFriendAreaCapacity2(map, &fAreaCapacity, FALSE, FALSE);
        if (id >= fAreaCapacity.maxPokemon)
            return NULL;

        monPtr = &gRecruitedPokemonRef->pokemon[fAreaCapacity.unk8 + id];
        if (sub_80023E4(9)) {
            if (PokemonExists(monPtr) && !monPtr->isTeamLeader) {
                return monPtr;
            }
        }
        else {
            if (PokemonExists(monPtr) && !monPtr->isTeamLeader && !IsMonPartner(monPtr)) {
                return monPtr;
            }
        }
    }

    return NULL;
}

Pokemon *sub_80A8E9C(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    return sub_80A8D54(livesPtr->unk2);
}

void sub_80A8EC0(u8 *buffer, s32 a1)
{
    s16 sp = a1;
    s16 species;
    Pokemon *monStruct;

    sub_80A7DDC(&sp, &species);
    monStruct = sub_80A8D54(sp);
    if (monStruct != NULL) {
        StrncpyCustom(buffer, monStruct->name, POKEMON_NAME_LENGTH);
    }
    else if (sp == 32) {
        CopyMonsterNameToBuffer(buffer, species);
    }
    else if (sp != -1) {
        const struct GroundLiveTypeData *dataPtr = &gGroundLivesTypeData_811E63C[sp];

        switch (sp) {
            case 52:
            case 100:
                strcpy(buffer, dataPtr->unk4);
                break;
            default:
                CopyMonsterNameToBuffer(buffer, dataPtr->unk2);
                break;
        }
    }
    else {
        InlineStrcpy(buffer, _("{COLOR RED_W}invalidity{RESET}"));
    }
}

void sub_80A8F50(u8 *buffer, s32 a1_, s32 size)
{
    u8 text[0x80];
    s32 a1 = (s16) a1_;

    sub_80A8EC0(text, a1);
    BoundedCopyStringtoBuffer(buffer, text, size);
}

UNUSED static void sub_80A8F74(s32 id_, u8 *buffer)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    sub_80A8EC0(buffer, livesPtr->unk2);
}

s32 sub_80A8F9C(s32 id_, PixelPos *pixelPos)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 == -1) {
        pixelPos->x = 0;
        pixelPos->y = 0;
    }
    else {
        *pixelPos = livesPtr->unkC;
    }

    return livesPtr->unk2;
}

s32 sub_80A8FD8(s32 id_, PixelPos *pixelPos)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 == -1) {
        pixelPos->x = 0;
        pixelPos->y = 0;
    }
    else {
        pixelPos->x = livesPtr->unk144.x + livesPtr->unk14.x;
        pixelPos->y = livesPtr->unk144.y + livesPtr->unk14.y;
    }

    return livesPtr->unk2;
}

UNUSED static s32 sub_80A9028(s32 id_, PixelPos *pixelPos)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    sub_80A9F20(livesPtr, pixelPos);
    return livesPtr->unk2;
}

s32 sub_80A9050(s32 id_, s8 *a1)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 == -1) {
        *a1 = -1;
    }
    else {
        *a1 = livesPtr->direction1;
    }

    return livesPtr->unk2;
}

s32 sub_80A9090(s32 id_, s32 a1_)
{
    s32 id = (s16) id_;
    s32 a1 = (s8) a1_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        livesPtr->direction1 = a1;
    }

    return livesPtr->unk2;
}

s16 GetFriendAreaDialogueId(s32 id_)
{
    s32 id = (s16) id_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];

    return livesPtr->friendAreaDialogueId;
}

UNUSED static bool8 sub_80A90E8(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 != id2) {
        struct GroundLive *livesPtr1 = &gGroundLives->array[id1];
        struct GroundLive *livesPtr2 = &gGroundLives->array[id2];

        if (livesPtr1->unk2 != -1 && livesPtr2->unk2 != -1) {
            s32 dir;
            PixelPos pixelPos1, pixelPos2;

            pixelPos1.x = livesPtr1->unk144.x + livesPtr1->unk14.x;
            pixelPos1.y = livesPtr1->unk144.y + livesPtr1->unk14.y;

            pixelPos2.x = livesPtr2->unk144.x + livesPtr2->unk14.x;
            pixelPos2.y = livesPtr2->unk144.y + livesPtr2->unk14.y;

            if (livesPtr1->unk2 <= 36) {
                dir = SizedDeltaDirection8(&pixelPos1, &livesPtr1->unkC, &pixelPos2, &livesPtr2->unkC);
            }
            else {
                dir = SizedDeltaDirection4(&pixelPos1, &livesPtr1->unkC, &pixelPos2, &livesPtr2->unkC);
            }

            if (dir != -1) {
                livesPtr1->direction1 = dir;
                return TRUE;
            }
        }
    }

    return FALSE;
}

UNUSED static bool8 sub_80A91A0(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 != id2) {
        struct GroundLive *livesPtr1 = &gGroundLives->array[id1];
        struct GroundLive *livesPtr2 = &gGroundLives->array[id2];

        if (livesPtr1->unk2 != -1 && livesPtr2->unk2 != -1) {
            s32 dir1, dir2;
            PixelPos pixelPos1, pixelPos2;

            pixelPos1.x = livesPtr1->unk144.x + livesPtr1->unk14.x;
            pixelPos1.y = livesPtr1->unk144.y + livesPtr1->unk14.y;

            pixelPos2.x = livesPtr2->unk144.x + livesPtr2->unk14.x;
            pixelPos2.y = livesPtr2->unk144.y + livesPtr2->unk14.y;

            dir1 = SizedDeltaDirection8(&pixelPos1, &livesPtr1->unkC, &pixelPos2, &livesPtr2->unkC);
            dir2 = SizedDeltaDirection4(&pixelPos1, &livesPtr1->unkC, &pixelPos2, &livesPtr2->unkC);

            if (dir1 != -1 && dir2 != -1) {
                if (livesPtr1->unk2 <= 36) {
                    livesPtr1->direction1 = dir1;
                }
                else {
                    livesPtr1->direction1 = dir2;
                }

                if (livesPtr2->unk2 <= 37) {
                    livesPtr2->direction1 = sub_8002984(dir1, 5);
                }
                else {
                    livesPtr2->direction1 = sub_8002984(dir2, 5);
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

s32 GetLivesCollision_80A92A0(s32 id_, u32 flags, PixelPos *pixelPos1, PixelPos *pixelPos2)
{
    s32 i;
    struct GroundLive *livesPtr;
    s32 id = (s16) id_;

    for (livesPtr = &gGroundLives->array[0], i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
        if (i != id
            && livesPtr->unk2 != -1
            && livesPtr->flags & flags
            && livesPtr->unk144.x < pixelPos2->x
            && livesPtr->unk14C.x > pixelPos1->x
            && livesPtr->unk144.y < pixelPos2->y
            && livesPtr->unk14C.y > pixelPos1->y)
        {
            return i;
        }
    }
    return -1;
}

static s32 sub_80A9344(s32 id_, u32 flags, PixelPos *pixelPos1, PixelPos *pixelPos2)
{
    s32 i;
    struct GroundLive *livesPtr;
    s32 id = (s16) id_;

    for (livesPtr = &gGroundLives->array[0], i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
        if (i != id && livesPtr->unk2 != -1 && livesPtr->flags & flags) {
            PixelPos resultPos = {0};
            resultPos.x = livesPtr->unk144.x + livesPtr->unk14.x;
            resultPos.y = livesPtr->unk144.y + livesPtr->unk14.y;
            if (resultPos.x < pixelPos2->x
                && resultPos.x > pixelPos1->x
                && resultPos.y < pixelPos2->y
                && resultPos.y > pixelPos1->y)
            {
                return i;
            }
        }
    }
    return -1;
}

static u8 sub_80A93F0(s32 id_, s32 a1_)
{
    s32 id = (s16) id_;
    s32 a1 = (u8) a1_;
    struct GroundLive *livesPtr = &gGroundLives->array[id];
    PixelPos pixPos1 = {livesPtr->unk144.x / 2048, livesPtr->unk144.y / 2048};
    PixelPos posTemp = {((livesPtr->unk14C.x - 1) / 2048), ((livesPtr->unk14C.y - 1) / 2048)};
    PixelPos pixPos2 = {(posTemp.x- pixPos1.x) + 1, (posTemp.y -pixPos1.y) + 1};

    return sub_80A5934(a1, &pixPos1, &pixPos2);
}

static s32 sub_80A9488(struct GroundLive *livesPtr, PixelPos *posArg1, PixelPos *posArg2)
{
    PixelPos pixPos1 = {posArg1->x / 2048, posArg1->y / 2048};
    PixelPos posTemp = {((posArg2->x - 1) / 2048), ((posArg2->y - 1) / 2048)};
    PixelPos pixPos2 = {(posTemp.x- pixPos1.x) + 1, (posTemp.y -pixPos1.y) + 1};

    if (livesPtr->flags & 1) {
        if (CheckMapCollision_80A585C(&pixPos1, &pixPos2))
            return 1;
    }
    if (livesPtr->flags & 2) {
        if (sub_80A58C8(&pixPos1, &pixPos2))
            return 1;
    }
    if (livesPtr->flags & 4) {
        if ((s16) GetLivesCollision_80A92A0(livesPtr->id, 4, posArg1, posArg2) >= 0)
            return 4;
    }
    if (livesPtr->flags & 8) {
        if ((s16) sub_80AC4C8(4, posArg1, posArg2) >= 0)
            return 8;
    }
    if (livesPtr->flags & 0x10) {
        if ((s16) FindGroundEvent(0x40, posArg1, posArg2) >= 0)
            return 0x10;
    }

    return 0;
}

static s32 sub_80A95AC(struct GroundLive *livesPtr, PixelPos *posArg1, PixelPos *posArg2)
{
    PixelPos pixPos1 = {posArg1->x / 2048, posArg1->y / 2048};
    PixelPos posTemp = {((posArg2->x - 1) / 2048), ((posArg2->y - 1) / 2048)};
    PixelPos pixPos2 = {(posTemp.x- pixPos1.x) + 1, (posTemp.y -pixPos1.y) + 1};

    if (livesPtr->flags & 1) {
        if (CheckMapCollision_80A585C(&pixPos1, &pixPos2))
            return 1;
    }
    if (livesPtr->flags & 2) {
        if (sub_80A58C8(&pixPos1, &pixPos2))
            return 1;
    }
    if (livesPtr->flags & 4) {
        s32 id2 = (s16) GetLivesCollision_80A92A0(livesPtr->id, 0x44, posArg1, posArg2);
        // Needed for matching.
        s32 id2_ = id2;
        if (id2 >= 0) {
            struct GroundLive *ptr2 = &gGroundLives->array[id2];

            if (ptr2->flags & 0x40) {
                if (ptr2->flags & 0x200) {
                    ptr2->direction1 = sub_8002984(livesPtr->direction1, 5);
                }
                if (GroundLives_ExecutePlayerScriptActionLives(livesPtr->id, id2_))
                    return 2;
            }
            return 1;
        }
    }
    if (livesPtr->flags & 8) {
        s32 id2 = (s16) sub_80AC4C8(0x44, posArg1, posArg2);
        if (id2 >= 0) {
            s32 sp;

            GroundObject_GetFlags(id2, &sp);
            if ((sp & 0x40) && sub_80A8A5C(livesPtr->id, id2))
                return 2;
            return 1;
        }
    }
    if (livesPtr->flags & 0x10) {
        s32 id2 = (s16) FindGroundEvent(0x40, posArg1, posArg2);
        if (id2 >= 0) {
            if (sub_80A8ACC(livesPtr->id, id2))
                return 2;
            return 1;
        }
    }

    return 0;
}

static bool8 sub_80A9750(struct GroundLive *livesPtr, u16 a1)
{
    s32 r2;
    u16 f1 = a1 & 0xFF;
    u16 f2 = (a1 & 0xF00);

    if (f1 != 0) {
        livesPtr->unk160 = f1;
    }
    if (f2 != 0) {
        livesPtr->unk15E = f2;
    }

    if (livesPtr->unk160 == 1) {
        if (a1 == 0x1000) {
            livesPtr->unk164 = 4;
            r2 = 0x800;
        }
        else {
            if (livesPtr->unk164 > 0) {
                r2 = 0x800;
            }
            else {
                r2 = 0x807;
            }
        }
    }
    else if (livesPtr->unk160 == 2) {
        if (a1 == 0x1000) {
            livesPtr->unk164 = 4;
            r2 = 0x800;
        }
        else {
            if (livesPtr->unk164 > 0) {
                r2 = 0x800;
            }
            else {
                // Peak programming right here
                switch (livesPtr->speciesId) {
                    case 12: case 15: case 22: case 41: case 42: case 49: case 72: case 73: case 74: case 81: case 82:
                    case 91: case 92: case 93: case 109: case 110: case 116: case 117: case 118: case 119: case 130:
                    case 133: case 137: case 142: case 144: case 145: case 146: case 150: case 151: case 165: case 166:
                    case 169: case 170: case 171: case 187: case 188: case 189: case 190: case 191: case 193: case 198:
                    case 230: case 232: case 236: case 248: case 251: case 255: case 258: case 271: case 275: case 276:
                    case 292: case 294: case 303: case 304: case 309: case 316: case 317: case 332: case 343: case 344:
                    case 345: case 346: case 355: case 358: case 362: case 363: case 364: case 365: case 368: case 369:
                    case 374: case 376: case 377: case 378: case 379: case 381: case 383: case 386: case 390: case 395:
                    case 396: case 397: case 398: case 402: case 403: case 406: case 408: case 409: case 410: case 200:
                    case 201: case 202: case 203: case 204: case 205: case 206: case 207: case 208: case 209: case 210:
                    case 211: case 212: case 213: case 214: case 215: case 216: case 217: case 218: case 219: case 220:
                    case 221: case 222: case 223: case 224: case 225: case 226: case 412: case 413: case 414: case 415:
                    case 416: case 417: case 418: case 419:
                        r2 = 0x807;
                        break;
                    case 50: case 51: case 53: case 58: case 59: case 98: case 99: case 134: case 135: case 161: case 162:
                    case 164: case 252: case 277: case 286: case 287: case 323: case 326: case 338: case 339: case 354:
                    case 359: case 360: case 391: case 401:
                        r2 = 0x307;
                        break;
                    case 65:
                        if (livesPtr->unk168 != 0x807 && livesPtr->unk168 != 0x307) {
                            r2 = 0x300;
                        }
                        else {
                            r2 = 0x807;
                        }
                        break;
                    default:
                        r2 = 0x300;
                }
            }
        }
    }
    else {
        r2 = gUnknown_8117F64[livesPtr->unk160];
    }

    if (!(r2 & 0x700)) {
        switch (livesPtr->unk15E) {
            case 0x100:
                r2 = (s16) (r2 | 0x300);
                break;
            case 0x200:
                r2 = (s16) (r2 | 0x100);
                break;
            case 0x300:
                break;
            case 0x400:
                r2 = (s16) (r2 | 0x200);
                break;
            case 0x800:
                r2 = (s16) (r2 | 0x400);
                break;
        }
    }

    if (livesPtr->unk168 != (s16) r2) {
        livesPtr->unk168 = r2;
        livesPtr->directionRelated = TRUE;
    }
    else if (livesPtr->unk168 & 0x1000) {
        livesPtr->directionRelated = TRUE;
    }

    return FALSE;
}

static s32 sub_80A9F20(struct GroundLive *livesPtr, PixelPos *pixelPosArg)
{
    s32 ret;
    PixelPos pixPos1, pixPos2;

    pixPos1.x = pixelPosArg->x - livesPtr->unk14.x;
    pixPos1.y = pixelPosArg->y - livesPtr->unk14.y;

    pixPos2.x = pixelPosArg->x + livesPtr->unk14.x;
    pixPos2.y = pixelPosArg->y + livesPtr->unk14.y;

    if (pixPos1.x < livesPtr->unk28.x || pixPos2.x >= livesPtr->unk30.x
        || pixPos1.y < livesPtr->unk28.y || pixPos2.y >= livesPtr->unk30.y)
    {
        return TRUE;
    }

    ret = sub_80A9488(livesPtr, &pixPos1, &pixPos2);
    if (ret != 0) {
        return ret;
    }
    else {
        livesPtr->unk144 = pixPos1;
        livesPtr->unk14C = pixPos2;
        return 0;
    }
}

static s32 sub_80A9F94(struct GroundLive *livesPtr, PixelPos *pixelPosArg)
{
    s32 ret;
    bool8 changed;
    PixelPos pixPos1, pixPos2;

    pixPos1.x = livesPtr->unk144.x + pixelPosArg->x;
    pixPos1.y = livesPtr->unk144.y + pixelPosArg->y;

    pixPos2.x = livesPtr->unk14C.x + pixelPosArg->x;
    pixPos2.y = livesPtr->unk14C.y + pixelPosArg->y;

    changed = FALSE;
    if (pixPos1.x < livesPtr->unk28.x) {
        pixPos1.x = livesPtr->unk28.x;
        pixPos2.x = livesPtr->unk28.x + livesPtr->unkC.x;
        changed = TRUE;
    }
    else if (pixPos2.x >= livesPtr->unk30.x) {
        pixPos1.x = livesPtr->unk30.x - livesPtr->unkC.x;
        pixPos2.x = livesPtr->unk30.x;
        changed = TRUE;
    }

    if (pixPos1.y < livesPtr->unk28.y) {
        pixPos1.y = livesPtr->unk28.y;
        pixPos2.y = livesPtr->unk28.y + livesPtr->unkC.y;
        changed = TRUE;
    }
    else if (pixPos2.y >= livesPtr->unk30.y) {
        pixPos1.y = livesPtr->unk30.y - livesPtr->unkC.y;
        pixPos2.y = livesPtr->unk30.y;
        changed = TRUE;
    }

    ret = sub_80A9488(livesPtr, &pixPos1, &pixPos2);
    if (ret != 0) {
        sub_80AAF68(livesPtr, 0);
        return ret;
    }

    livesPtr->unk144 = pixPos1;
    livesPtr->unk14C = pixPos2;
    if (changed) {
        sub_80AAF68(livesPtr, 0);
        return 1;
    }
    else {
        sub_80AAF68(livesPtr, 1);
        return 0;
    }
}

static s32 sub_80AA074(struct GroundLive *livesPtr, PixelPos *pixelPosArg)
{
    s32 ret;
    PixelPos pixPos1, pixPos2;

    pixPos1.x = livesPtr->unk144.x + pixelPosArg->x;
    pixPos1.y = livesPtr->unk144.y + pixelPosArg->y;

    pixPos2.x = livesPtr->unk14C.x + pixelPosArg->x;
    pixPos2.y = livesPtr->unk14C.y + pixelPosArg->y;

    if (pixPos1.x < livesPtr->unk28.x) {
        pixPos1.x = livesPtr->unk28.x;
        pixPos2.x = livesPtr->unk28.x + livesPtr->unkC.x;
    }
    else if (pixPos2.x >= livesPtr->unk30.x) {
        pixPos1.x = livesPtr->unk30.x - livesPtr->unkC.x;
        pixPos2.x = livesPtr->unk30.x;
    }

    if (pixPos1.y < livesPtr->unk28.y) {
        pixPos1.y = livesPtr->unk28.y;
        pixPos2.y = livesPtr->unk28.y + livesPtr->unkC.y;
    }
    else if (pixPos2.y >= livesPtr->unk30.y) {
        pixPos1.y = livesPtr->unk30.y - livesPtr->unkC.y;
        pixPos2.y = livesPtr->unk30.y;
    }

    ret = sub_80A95AC(livesPtr, &pixPos1, &pixPos2);
    if (ret == 0) {
        livesPtr->unk144 = pixPos1;
        livesPtr->unk14C = pixPos2;
        if (livesPtr->flags & 0x10) {
            s32 id = (s16) FindGroundEvent(0x20, &pixPos1, &pixPos2);
            if (id >= 0) {
                if (livesPtr->unk13E != id && sub_80A8ACC(livesPtr->id, id)) {
                    livesPtr->unk13E = id;
                    ret = 2;
                }
            }
            else {
                livesPtr->unk13E = -1;
            }
        }
        ASM_MATCH_TRICK(ret);
    }

    return ret;
}

static s32 sub_80AA180(struct GroundLive *livesPtr, u32 flags, PixelPos *pixelPosArg1, PixelPos *pixelPosArg2)
{
    PixelPos pixPos1, pixPos2;

    if (flags & 4) {
        s32 id = (s16) sub_80A9344(livesPtr->id, 0x80, pixelPosArg1, pixelPosArg2);
        if (id >= 0) {
            s32 dir;

            sub_80A8FD8(id, &pixPos1);
            pixPos2.x = pixPos1.x - (livesPtr->unk144.x + livesPtr->unk14.x);
            pixPos2.y = pixPos1.y - (livesPtr->unk144.y + livesPtr->unk14.y);
            dir = (s8) VecDirection8Radial(&pixPos2);
            if (dir != -1) {
                // s8 memes
                s8 *dirDst = &livesPtr->direction1;
                s8 dirS8 = (s8) dir;
                *dirDst = dirS8;
                if (livesPtr->direction2 != livesPtr->direction1) {
                    livesPtr->directionRelated = TRUE;
                }
                if (sub_80AA3F8(livesPtr, livesPtr->direction1))
                    return 3;
            }
            return 0;
        }
    }
    if (flags & 8) {
        s32 id = (s16) sub_80AC554(0x80, pixelPosArg1, pixelPosArg2);
        if (id >= 0) {
            s32 dir;

            sub_80AC448(id, &pixPos1);
            pixPos2.x = pixPos1.x - (livesPtr->unk144.x + livesPtr->unk14.x);
            pixPos2.y = pixPos1.y - (livesPtr->unk144.y + livesPtr->unk14.y);
            dir = (s8) VecDirection8Radial(&pixPos2);
            if (dir != -1) {
                // s8 memes
                s8 *dirDst = &livesPtr->direction1;
                s8 dirS8 = (s8) dir;
                *dirDst = dirS8;
                if (livesPtr->direction2 != livesPtr->direction1) {
                    livesPtr->directionRelated = TRUE;
                }
                if (sub_80AA3F8(livesPtr, livesPtr->direction1))
                    return 3;
            }
            return 0;
        }
    }

    return 0;
}

static s32 sub_80AA2BC(struct GroundLive *livesPtr, u32 flags, PixelPos *pixelPosArg1, PixelPos *pixelPosArg2)
{
    PixelPos pixPos1, pixPos2, pixPos3;
    PixelPos posTemp;
    PixelPos pixPos4;

    pixPos1 = *pixelPosArg1;
    pixPos3 = *pixelPosArg2;

    pixPos2.x = pixPos1.x / 2048;
    pixPos2.y = pixPos1.y / 2048;
    posTemp = (PixelPos) {((pixPos3.x - 1) / 2048), ((pixPos3.y - 1) / 2048)};
    pixPos4 = (PixelPos) {(posTemp.x- pixPos2.x) + 1, (posTemp.y -pixPos2.y) + 1};

    if (flags & 4) {
        s32 id2 = (s16) GetLivesCollision_80A92A0(livesPtr->id, 0x80, &pixPos1, &pixPos3);
        if (id2 >= 0) {
            struct GroundLive *ptr2 = &gGroundLives->array[id2];
            if (ptr2->flags & 0x200) {
                ptr2->direction1 = sub_8002984(livesPtr->direction1, 5);
            }
            if (GroundLives_ExecutePlayerScriptActionLives(livesPtr->id, id2))
                return 3;
        }
    }
    if (flags & 8) {
        s32 id2 = (s16) sub_80AC4C8(0x80, &pixPos1, &pixPos3);
        if (id2 >= 0) {
            if (sub_80A8A5C(livesPtr->id, id2))
                return 3;
        }
    }
    if (sub_80A595C(0x10, &pixPos2, &pixPos4)) {
        return 6;
    }

    return 0;
}

static bool8 sub_80AA3F8(struct GroundLive *livesPtr, s32 a1_)
{
    s32 i;
    s32 a1 = (s8) a1_;
    PixelPos pixPos1 = SetVecFromDirectionSpeed(a1, 0x100);
    PixelPos pixPos2 = { livesPtr->unk144.x + pixPos1.x, livesPtr->unk144.y + pixPos1.y };
    PixelPos pixPos3 = { livesPtr->unk14C.x + pixPos1.x, livesPtr->unk14C.y + pixPos1.y };
    PixelPos pixPos4, pixPos5, pixPos6;
    s32 r7 = sub_80AA2BC(livesPtr, 0xC, &pixPos2, &pixPos3);
    s32 var_2C, var_28, var_24;

    if (r7 == 3)
        return TRUE;

    pixPos6.x = (((livesPtr->unkC.x / 2) + 0x200) * pixPos1.x) / 256;
    pixPos6.y = (((livesPtr->unkC.y / 2) + 0x200) * pixPos1.y) / 256;

    pixPos4.x = (livesPtr->unk144.x + livesPtr->unk14.x + pixPos6.x) - 768;
    pixPos4.y = (livesPtr->unk144.y + livesPtr->unk14.y + pixPos6.y) - 768;

    pixPos5 = (PixelPos) { pixPos4.x + 0x600,  pixPos4.y + 0x600};

    var_2C = gUnknown_8117FF0[a1];
    var_28 = gUnknown_8118010[a1];
    var_24 = gUnknown_8118030[a1];

    for (i = 0x200; i < var_2C; i += 0x100) {
        if (pixPos4.x < livesPtr->unk28.x || pixPos5.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos4.y < livesPtr->unk28.y || pixPos5.y >= livesPtr->unk30.y)
            return FALSE;

        r7 = sub_80AA2BC(livesPtr, 0xC, &pixPos4, &pixPos5);
        if (r7 == 3)
            return TRUE;

        pixPos4.x += pixPos1.x;
        pixPos4.y += pixPos1.y;
        pixPos5.x += pixPos1.x;
        pixPos5.y += pixPos1.y;

        if (r7 == 6)
            break;
    }
    if (r7 != 6)
        return FALSE;

    for (; i < var_28; i += 0x100) {
        if (pixPos4.x < livesPtr->unk28.x || pixPos5.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos4.y < livesPtr->unk28.y || pixPos5.y >= livesPtr->unk30.y)
            return FALSE;

        r7 = sub_80AA2BC(livesPtr, 4, &pixPos4, &pixPos5);
        if (r7 == 3)
            return TRUE;

        pixPos4.x += pixPos1.x;
        pixPos4.y += pixPos1.y;
        pixPos5.x += pixPos1.x;
        pixPos5.y += pixPos1.y;

        if (r7 != 6)
            break;
    }
    if (r7 == 6)
        return FALSE;

    for (i = 0; i < var_24; i += 0x100) {
        if (pixPos4.x < livesPtr->unk28.x || pixPos5.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos4.y < livesPtr->unk28.y || pixPos5.y >= livesPtr->unk30.y)
            return FALSE;

        r7 = sub_80AA2BC(livesPtr, 4, &pixPos4, &pixPos5);
        if (r7 == 3)
            return TRUE;
        if (r7 == 6)
            return FALSE;

        pixPos4.x += pixPos1.x;
        pixPos4.y += pixPos1.y;
        pixPos5.x += pixPos1.x;
        pixPos5.y += pixPos1.y;
    }

    return FALSE;
}

static s32 sub_80AA660(struct GroundLive *livesPtr, PixelPos *pixelPosArg1, PixelPos *pixelPosArg2)
{
    s32 id = (s16) sub_80AC4C8(0x100, pixelPosArg1, pixelPosArg2);

    if (id >= 0) {
        if (sub_80A8A5C(livesPtr->id, id))
            return 4;
    }

    return 0;
}

static bool8 sub_80AA690(struct GroundLive *livesPtr, s32 a1_)
{
    s32 i;
    s32 a1 = (s8) a1_;
    PixelPos pixPos1 = SetVecFromDirectionSpeed(a1, 0x100);
    PixelPos tempPos = { (((livesPtr->unkC.x / 2) + 0x200) * pixPos1.x) / 256, (((livesPtr->unkC.y / 2) + 0x200) * pixPos1.y) / 256 };
    PixelPos pixPos2 = { (livesPtr->unk144.x + livesPtr->unk14.x + tempPos.x) - 768, (livesPtr->unk144.y + livesPtr->unk14.y + tempPos.y) - 768 };
    PixelPos pixPos3 = { pixPos2.x + 0x600,  pixPos2.y + 0x600 };
    s32 var;

    var = gUnknown_8117FF0[a1];
    for (i = 0x200; i < var; i += 0x100) {
        u32 unk;

        if (pixPos2.x < livesPtr->unk28.x || pixPos3.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos2.y < livesPtr->unk28.y || pixPos3.y >= livesPtr->unk30.y)
            return FALSE;

        unk = sub_80AA660(livesPtr, &pixPos2, &pixPos3);
        switch (unk) {
            case 0:
                return FALSE;
            case 4:
                return TRUE;
            case 6:
                break;
            default:
                break;
        }

        pixPos2.x += pixPos1.x;
        pixPos2.y += pixPos1.y;
        pixPos3.x += pixPos1.x;
        pixPos3.y += pixPos1.y;
    }

    return FALSE;
}

static s32 sub_80AA7B0(struct GroundLive *livesPtr, s16 *a1, u32 flags, PixelPos *pixelPosArg1, PixelPos *pixelPosArg2)
{
    PixelPos pixPos1 = *pixelPosArg1;
    PixelPos pixPos3 = *pixelPosArg2;
    PixelPos pixPos2 = {pixPos1.x / 2048, pixPos1.y / 2048};
    PixelPos tempPos = {(pixPos3.x - 1) / 2048, (pixPos3.y - 1) / 2048};
    PixelPos pixPos4 = {(tempPos.x - pixPos2.x) + 1, (tempPos.y - pixPos2.y) + 1};

    if (flags & 4) {
        s32 id2 = (s16) GetLivesCollision_80A92A0(livesPtr->id, 0x80, &pixPos1, &pixPos3);
        if (id2 >= 0) {
            s16 var = (s16) sub_80A8BBC(id2);
            if (var >= 14 && var < 30 && sub_80A8E9C(id2) != NULL) {
                *a1 = id2;
                sub_80A9090(id2, (s8) sub_8002984(livesPtr->direction1, 5));
                return 5;
            }
        }
    }

    *a1 = -1;
    if (sub_80A595C(0x10, &pixPos2, &pixPos4)) {
        return 6;
    }

    return 0;
}

static bool8 sub_80AA8BC(struct GroundLive *livesPtr, s16 *a1, s32 dir_)
{
    s32 i;
    s32 dir = (s8) dir_;
    PixelPos pixPos1 = SetVecFromDirectionSpeed(dir, 0x100);
    PixelPos pixPos5 = { (((livesPtr->unkC.x / 2) + 0x200) * pixPos1.x) / 256, (((livesPtr->unkC.y / 2) + 0x200) * pixPos1.y) / 256 };
    PixelPos pixPos2 = { (livesPtr->unk144.x + livesPtr->unk14.x + pixPos5.x) - 768, (livesPtr->unk144.y + livesPtr->unk14.y + pixPos5.y) - 768 };
    PixelPos pixPos3 = { pixPos2.x + 0x600,  pixPos2.y + 0x600 };
    s32 r10 = gUnknown_8117FF0[dir];
    s32 var_28 = gUnknown_8118010[dir];
    s32 var_24 = gUnknown_8118030[dir];
    s32 unk = 0;

    *a1 = -1;
    for (i = 0x200; i < r10; i += 0x100) {
        if (pixPos2.x < livesPtr->unk28.x || pixPos3.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos2.y < livesPtr->unk28.y || pixPos3.y >= livesPtr->unk30.y)
            return FALSE;

        unk = sub_80AA7B0(livesPtr, a1, 0xC, &pixPos2, &pixPos3);
        if (unk == 5)
            return TRUE;

        pixPos2.x += pixPos1.x;
        pixPos2.y += pixPos1.y;
        pixPos3.x += pixPos1.x;
        pixPos3.y += pixPos1.y;

        if (unk == 6)
            break;
    }
    if (unk != 6)
        return FALSE;

    for (; i < var_28; i += 0x100) {
        if (pixPos2.x < livesPtr->unk28.x || pixPos3.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos2.y < livesPtr->unk28.y || pixPos3.y >= livesPtr->unk30.y)
            return FALSE;

        unk = sub_80AA7B0(livesPtr, a1, 4, &pixPos2, &pixPos3);
        if (unk == 5)
            return TRUE;

        pixPos2.x += pixPos1.x;
        pixPos2.y += pixPos1.y;
        pixPos3.x += pixPos1.x;
        pixPos3.y += pixPos1.y;

        if (unk != 6)
            break;
    }
    if (unk == 6)
        return FALSE;

    for (i = 0; i < var_24; i += 0x100) {
        if (pixPos2.x < livesPtr->unk28.x || pixPos3.x >= livesPtr->unk30.x)
            return FALSE;
        if (pixPos2.y < livesPtr->unk28.y || pixPos3.y >= livesPtr->unk30.y)
            return FALSE;

        unk = sub_80AA7B0(livesPtr, a1, 4, &pixPos2, &pixPos3);
        if (unk == 5)
            return TRUE;
        if (unk == 6)
            return FALSE;

        pixPos2.x += pixPos1.x;
        pixPos2.y += pixPos1.y;
        pixPos3.x += pixPos1.x;
        pixPos3.y += pixPos1.y;
    }

    return FALSE;
}

static void sub_80AAAE8(struct GroundLive *livesPtr, u32 a1, s32 dir_, s32 unused)
{
    s32 unk;
    s32 dir = (s8) dir_;
    s32 var_28 = -1;

    livesPtr->unk15E = 0x300;
    livesPtr->unk160 = 1;
    if (dir != -1) {
        livesPtr->direction1 = dir;
    }

    switch (a1) {
        case 2:
            livesPtr->unk164 = 0;
            var_28 = 0x807;
            sub_80AAF68(livesPtr, 0);
            break;
        case 1:
            livesPtr->unk164 = 0;
            var_28 = 0x300;
            sub_80AAF68(livesPtr, 0);
            break;
        case 6:
        case 7:
        case 8:
            if (dir != -1) {
                s32 i;
                s32 n;
                PixelPos pixPos, pixPos2, pixPos3;

                unk = 0;
                livesPtr->unk164 = 4;
                switch (a1) {
                    case 6:
                        var_28 = 0x900;
                        n = 1;
                        break;
                    case 7:
                        var_28 = 0x800;
                        n = 2;
                        break;
                    case 8:
                        var_28 = 0xA00;
                        n = 4;
                        break;
                    // Impossible case
                    default:
                        livesPtr->unk164 = 0;
                        var_28 = 0x807;
                        n = 0;
                        break;
                }
                pixPos = SetVecFromDirectionSpeed(dir, 0x100);
                for (i = 0; i < n; i++) {
                    unk = sub_80AA074(livesPtr, &pixPos);
                    if (unk == 2)
                        break;
                    if (unk != 1)
                        continue;

                    pixPos2.x = 0;
                    pixPos2.y = pixPos.y;
                    unk = sub_80AA074(livesPtr, &pixPos2);
                    if (unk == 2)
                        break;
                    if (unk != 1)
                        continue;

                    pixPos3.x = pixPos.x;
                    pixPos3.y = 0;
                    unk = sub_80AA074(livesPtr, &pixPos3);
                    if (unk == 2)
                        break;
                }
                if (unk == 2) {
                    var_28 = -1;
                    sub_80AAF68(livesPtr, 0);
                }
                else {
                    sub_80AAF68(livesPtr, 1);
                }
            }
            else {
                livesPtr->unk164 = 0;
                var_28 = 0x807;
                sub_80AAF68(livesPtr, 0);
            }
            break;
        case 3:
        case 4:
        case 5:
            if (dir != -1) {
                s32 i;
                s32 n;
                PixelPos pixPos, pixPos2, pixPos3;

                livesPtr->unk164 = 4;
                switch (a1) {
                    case 3:
                        var_28 = 0x900;
                        n = 1;
                        break;
                    case 4:
                        var_28 = 0x800;
                        n = 2;
                        break;
                    case 5:
                        var_28 = 0xA00;
                        n = 4;
                        break;
                    // Impossible
                    default:
                        livesPtr->unk164 = 0;
                        var_28 = 0x807;
                        n = 0;
                        break;
                }
                pixPos = SetVecFromDirectionSpeed(dir, 0x100);
                for (i = 0; i < n; i++) {
                    if (sub_80A9F94(livesPtr, &pixPos) != 0) {
                        pixPos2.x = 0;
                        pixPos2.y = pixPos.y;
                        if (sub_80A9F94(livesPtr, &pixPos2) != 0) {
                            pixPos3.x = pixPos.x;
                            pixPos3.y = 0;
                            if (sub_80A9F94(livesPtr, &pixPos3) != 0) {
                                n = 0;
                            }
                        }
                    }
                }
                sub_80AAF68(livesPtr, n);
            }
            else {
                livesPtr->unk164 = 0;
                var_28 = 0x807;
                sub_80AAF68(livesPtr, 0);
            }
            break;
        case 9:
            if (livesPtr->flags & 0x1000) {
                gGroundLivesMeta->unk28 = dir;
            }
            else {
                gGroundLivesMeta->unk28 = -1;
            }
            livesPtr->unk164 = 0;
            var_28 = 0x800;
            livesPtr->direction1 = 4;
            if (dir != -1) {
                PixelPos pixPos = SetVecFromDirectionSpeed(dir, 0x100);
                if (sub_80AA074(livesPtr, &pixPos) == 2) {
                    var_28 = -1;
                }
            }
            break;
        case 10:
            sub_80AA3F8(livesPtr, livesPtr->direction1);
            break;
        case 11:
            if (!sub_80AA690(livesPtr, livesPtr->direction1)) {
                ScriptInfoSmall scriptInfo;

                GetFunctionScript(NULL, &scriptInfo, 9);
                _ExecutePlayerScript(livesPtr, NULL, &scriptInfo);
            }
            break;
        case 19: {
            s16 sp;

            if (sub_80AA8BC(livesPtr, &sp, livesPtr->direction1)) {
                ScriptInfoSmall scriptInfo;

                GetFunctionScript(NULL, &scriptInfo, 6);
                GroundLives_ExecuteScript(sp, (void *) &livesPtr->action.unk8, &scriptInfo);
                _ExecutePlayerScript(livesPtr, NULL, NULL);
                sub_809B1C0(7, 0, sub_80A8E9C(sp));
            }
            else {
                sub_809B1C0(7, 0, NULL);
            }
            sub_809CD8C(&livesPtr->unk120, 5);
            break;
        }
        case 20: {
            ScriptInfoSmall scriptInfo;

            GetFunctionScript(NULL, &scriptInfo, 0x195);
            _ExecutePlayerScript(livesPtr, NULL, &scriptInfo);
            break;
        }
        default:
            sub_80AAF68(livesPtr, 0);
            break;
    }

    if (var_28 != -1 && var_28 != livesPtr->unk168) {
        struct UnkGroundSpriteStruct *groundSpritePtr;

        livesPtr->directionRelated = FALSE;
        groundSpritePtr = &livesPtr->unk170;
        livesPtr->unk168 = var_28;
        livesPtr->direction2 = livesPtr->direction1;
        sub_80A6EFC(groundSpritePtr, var_28, livesPtr->direction1);
        return;
    }

    if (livesPtr->directionRelated || livesPtr->direction2 != livesPtr->direction1) {
        struct UnkGroundSpriteStruct *groundSpritePtr;
        s32 unk168;

        livesPtr->directionRelated = FALSE;
        groundSpritePtr = &livesPtr->unk170;
        unk168 = livesPtr->unk168;
        livesPtr->direction2 = livesPtr->direction1;
        sub_80A6EFC(groundSpritePtr, unk168, livesPtr->direction1);
    }
}

static void sub_80AAF68(struct GroundLive *livesPtr, u32 unused)
{
    if (livesPtr->flags & 0x4000) {
        if (sub_80A93F0(livesPtr->id, 1)) {
            if (livesPtr->unk170.unk58 == 0) {
                livesPtr->unk16A = 438;
                livesPtr->unk16C = -1;
            }
            else if (livesPtr->unk170.unk58 != 438) {
                livesPtr->unk16A = 448;
                livesPtr->unk16C = -1;
            }
            sub_80A8750(livesPtr->id, 0x1000000);
        }
        else {
            if (livesPtr->unk170.unk58 == 438) {
                livesPtr->unk16A = 448;
                livesPtr->unk16C = -1;
            }
            sub_80A86C8(livesPtr->id, 0x1000000);
        }
    }
}

static s16 CallbackLivesGetIndex(void *livesPtr_)
{
    struct GroundLive *livesPtr = livesPtr_;

    return livesPtr->id;
}

static void CallbackLivesGetSize(void *livesPtr_, PixelPos *out)
{
    struct GroundLive *livesPtr = livesPtr_;

    *out = livesPtr->unkC;
}

static void CallbackLivesSetHitboxPos(void *livesPtr_, PixelPos *posOrNull)
{
    struct GroundLive *livesPtr = livesPtr_;

    if (posOrNull != NULL) {
        livesPtr->unk144.x = posOrNull->x - livesPtr->unk14.x;
        livesPtr->unk14C.x = posOrNull->x + livesPtr->unk14.x;
        livesPtr->unk144.y = posOrNull->y - livesPtr->unk14.y;
        livesPtr->unk14C.y = posOrNull->y + livesPtr->unk14.y;
    }
    else {
        livesPtr->unk144.x = livesPtr->unk20.x - livesPtr->unk14.x;
        livesPtr->unk14C.x = livesPtr->unk20.x + livesPtr->unk14.x;
        livesPtr->unk144.y = livesPtr->unk20.y - livesPtr->unk14.y;
        livesPtr->unk14C.y = livesPtr->unk20.y + livesPtr->unk14.y;
        livesPtr->unk154.x = livesPtr->unk154.y = 0;
        if (livesPtr->direction1 != livesPtr->unk1C) {
            livesPtr->directionRelated = TRUE;
        }
        livesPtr->direction1 = livesPtr->unk1C;
    }
}

static void CallbackLivesSetPositionBounds(void *livesPtr_, PixelPos *from, PixelPos *to)
{
    struct GroundLive *livesPtr = livesPtr_;

    livesPtr->unk28 = *from;
    livesPtr->unk30 = *to;
}

static void CallbackLivesGetHitboxCenter(void *livesPtr_, PixelPos *out)
{
    struct GroundLive *livesPtr = livesPtr_;

    out->x = livesPtr->unk144.x + livesPtr->unk14.x;
    out->y = livesPtr->unk144.y + livesPtr->unk14.y;
}

static s32 CallbackLivesMoveReal(void *livesPtr_, PixelPos *pos)
{
    struct GroundLive *livesPtr = livesPtr_;

    return sub_80A9F20(livesPtr, pos);
}

static void CallbackLivesGetPosHeightAndUnk(void *livesPtr_, u32 *height, u32 *unk)
{
    struct GroundLive *livesPtr = livesPtr_;

    *height = livesPtr->unk154.x;
    *unk = livesPtr->unk154.y;
}

static void CallbackLivesSetPosHeight(void *livesPtr_, u32 height)
{
    struct GroundLive *livesPtr = livesPtr_;

    livesPtr->unk154.x = height;
}

static void CallbackLivesGetDirection(void *livesPtr_, s8 *dir)
{
    struct GroundLive *livesPtr = livesPtr_;

    *dir = livesPtr->direction1;
}

static void CallbackLivesSetDirection(void *livesPtr_, s32 dir_)
{
    struct GroundLive *livesPtr = livesPtr_;
    s32 dir = (s8) dir_;

    if (dir != -1) {
        // s8 memes
        s8 *dirDst = &livesPtr->direction1;
        s8 dirS8 = (s8) dir;
        *dirDst = dirS8;
        if (livesPtr->direction2 != livesPtr->direction1) {
            livesPtr->directionRelated = TRUE;
        }
    }
}

static void CallbackLivesSetEventIndex(void *livesPtr_, u16 a1)
{
    struct GroundLive *livesPtr = livesPtr_;

    sub_80A9750(livesPtr, a1);
}

// s16 memes forced a fakematch https://decomp.me/scratch/x2ALy
static void CallbackLivesSetUnk_80AB194(void *livesPtr_, s32 a1_, s32 a2)
{
    struct GroundLive *livesPtr = livesPtr_;
    s32 a1Match = (s16) a1_;
    #ifndef NONMATCHING
    register s16 a1 asm("r3") = a1Match;
    #else
    s32 a1 = a1Match;
    #endif

    if (a1Match == 0) {
        a1 = 448;
    }

    livesPtr->unk16A = a1;
    livesPtr->unk16C = a2;
}

static void nullsub_211(void *livesPtr_, u16 a1)
{

}

static bool8 CallbackLivesSpriteRelatedCheck_80AB1C0(void *livesPtr_)
{
    struct GroundLive *livesPtr = livesPtr_;

    if (livesPtr->directionRelated) {
        return TRUE;
    }
    else {
        return sub_80A66F8(&livesPtr->unk170);
    }
}

static bool8 CallbackLivesSpriteRelated_80AB1E4(void *livesPtr_)
{
    struct GroundLive *livesPtr = livesPtr_;

    if (livesPtr->unk16A != 0) {
        return TRUE;
    }
    else {
        return sub_80A671C(&livesPtr->unk170);
    }
}

static void CallbackLivesGetFlags(void *livesPtr_, u32 *flags)
{
    struct GroundLive *livesPtr = livesPtr_;

    *flags = livesPtr->flags;
}

static void CallbackLivesSetFlags(void *livesPtr_, u32 flags)
{
    struct GroundLive *livesPtr = livesPtr_;

    sub_80A86C8(livesPtr->id, flags);
}

static void CallbackLivesClearFlags(void *livesPtr_, u32 flags)
{
    struct GroundLive *livesPtr = livesPtr_;

    sub_80A8750(livesPtr->id, flags);
}

static void CallbackLivesSpriteRelated_80AB238(void *livesPtr_, s32 a1)
{
    struct GroundLive *livesPtr = livesPtr_;

    sub_80A6EC8(&livesPtr->unk170, a1);
}

static s32 CallbackLivesMoveRelative(void *livesPtr_, PixelPos *pos)
{
    struct GroundLive *livesPtr = livesPtr_;

    return sub_80A9F94(livesPtr, pos);
}

void GroundLives_Action(void)
{
    s32 i;
    struct GroundLive *livesPtr;
    struct GroundLivesMeta_Sub1 *metaPtr;

    for (livesPtr = &gGroundLives->array[0], i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
        if (livesPtr->unk2 != -1) {
            s32 actionResult = (s16) HandleAction(&livesPtr->action, DEBUG_LOC_PTR("../ground/ground_lives.c", 4514, "GroundLives_Action"));
            switch (actionResult) {
                case 4:
                    GroundLives_Delete(i);
                    continue;
                case 0:
                    if (livesPtr->flags & 0x800) {
                        PixelPos var_44;
                        u32 var_4C = actionResult;
                        s8 dir = -1;
                        s32 var_48 = actionResult;
                        u32 unkVar = sub_809CDC8(&livesPtr->unk120, &var_4C, &dir, &var_48, &var_44, livesPtr->flags);

                        switch (unkVar) {
                            case 1:
                            case 2:
                            case 5:
                            case 8:
                                sub_80AAAE8(livesPtr, var_4C, dir, var_48);
                                break;
                            case 3: {
                                PixelPos var_34;
                                PixelPos pixPos;
                                PixelPos resultPos;
                                PixelPos var_2C;
                                PixelPos var_24;

                                sub_809D248(&pixPos);
                                resultPos.x = pixPos.x + var_44.x;
                                resultPos.y = pixPos.y + var_44.y;
                                var_34 = (PixelPos) { resultPos.x - ((livesPtr->unk144.x + livesPtr->unk14.x) / 256 ), resultPos.y - ((livesPtr->unk144.y + livesPtr->unk14.y) / 256 ) };
                                var_2C.x = (resultPos.x - 16) * 256;
                                var_24.x = (resultPos.x + 16) * 256;
                                var_2C.y = (resultPos.y - 4) * 256;
                                var_24.y = (resultPos.y + 28) * 256;
                                if (var_4C == 0xC) {
                                    if (!sub_80AA180(livesPtr, 0xC, &var_2C, &var_24)) {
                                        if (var_34.x >= -16 && var_34.x <= 16 && var_34.y >= -28 && var_34.y <= 4) {
                                            sub_80AAAE8(livesPtr, 19, -1, 0);
                                        }
                                    }
                                }
                                else {
                                    if (!(var_34.x >= -16 && var_34.x <= 16 && var_34.y >= -28 && var_34.y <= 4)) {
                                        s32 newDir = VecDirection8Radial(&var_34);
                                        dir = newDir;

                                        if (CMP_S8_NOT_MINUS1(newDir)) {
                                            switch (var_4C) {
                                                case 16:
                                                    sub_80AAAE8(livesPtr, 6, dir, 0);
                                                    break;
                                                case 17:
                                                    sub_80AAAE8(livesPtr, 7, dir, 0);
                                                    break;
                                                case 18:
                                                    sub_80AAAE8(livesPtr, 8, dir, 0);
                                                    break;
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                        }
                    }
                    else if (livesPtr->flags & 0x1000) {
                        sub_80AB5D4(livesPtr);
                    }
                    else {
                        ExecutePredefinedScript(&livesPtr->action, NULL, 1, DEBUG_LOC_PTR("../ground/ground_lives.c", 4622, "GroundLives_Action"));
                    }
                    break;
            }
            if (livesPtr->directionRelated) {
                livesPtr->directionRelated = FALSE;
                sub_80A6EFC(&livesPtr->unk170, livesPtr->unk168, (livesPtr->direction2 = livesPtr->direction1));
            }
        }
    }

    metaPtr = &gGroundLivesMeta->unk0[0];
    livesPtr = &gGroundLives->array[0];
    metaPtr->unk0 = 0;
    metaPtr->unk4 = 0;

    if (livesPtr->unk2 == -1) {
        sub_80AB5A4();
    }
    else if (livesPtr->flags & 0x2000) {
        sub_80AB5A4();
    }
    else if (livesPtr->flags & 0x1000) {
        s32 prevUnk24 = gGroundLivesMeta->unk24;
        if (prevUnk24 < 0) {
            s32 i;
            struct GroundLivesMeta_Sub1 *loopPtr;
            struct GroundLivesMeta_Sub2C *metaSub = &gGroundLivesMeta->unk2C[0];

            gGroundLivesMeta->unk24 = 0;
            gGroundLivesMeta->unk2C[0].unk0 = 0;
            metaSub->unk4.x = livesPtr->unk144.x + livesPtr->unk14.x;
            metaSub->unk4.y = livesPtr->unk144.y + livesPtr->unk14.y;
            loopPtr = &gGroundLivesMeta->unk0[0];
            for (i = 0; i < GROUND_LIVES_META_UNK0_COUNT; i++, loopPtr++) {
                loopPtr->unk8 = 0;
                loopPtr->unk0 = 0;
                loopPtr->unk4 = 0;
            }
        }
        else {
            PixelPos subbed, absed;
            struct GroundLivesMeta_Sub2C *prev;
            struct GroundLivesMeta_Sub2C *metaSub;
            s32 nextUnk24 = (prevUnk24 + 1) % 64;
            gGroundLivesMeta->unk24 = nextUnk24;
            metaSub = &gGroundLivesMeta->unk2C[gGroundLivesMeta->unk24];
            metaSub->unk4.x = livesPtr->unk144.x + livesPtr->unk14.x;
            metaSub->unk4.y = livesPtr->unk144.y + livesPtr->unk14.y;

            prev = &gGroundLivesMeta->unk2C[prevUnk24];
            subbed = (PixelPos) {metaSub->unk4.x - prev->unk4.x, metaSub->unk4.y - prev->unk4.y};
            absed = (PixelPos) {abs(subbed.x), abs(subbed.y)};

            metaSub->unk0 = max(absed.x, absed.y);
            if (metaSub->unk0 <= 0) {
                gGroundLivesMeta->unk24 = prevUnk24;
            }
            else {
                gGroundLivesMeta->unk0[0].unk0 = metaSub->unk0;
            }
        }
    }
    else {
        sub_80AB5A4();
    }
}

static void sub_80AB5A4(void)
{
    struct GroundLivesMeta_Sub1 *loopPtr;
    s32 i;

    gGroundLivesMeta->unk24 = -1;
    gGroundLivesMeta->unk28 = -1;

    loopPtr = &gGroundLivesMeta->unk0[0];
    for (i = 0; i < GROUND_LIVES_META_UNK0_COUNT; i++, loopPtr++) {
        loopPtr->unk8 = -1;
        loopPtr->unk0 = 0;
        loopPtr->unk4 = 0;
    }
}

static void sub_80AB5D4(struct GroundLive *livesPtr)
{
    struct GroundLivesMeta_Sub1 *metaPtr = &gGroundLivesMeta->unk0[livesPtr->unk13C];

    if (livesPtr->unk13C == 0)
        return;

    livesPtr->unk15E = 0x300;
    livesPtr->unk160 = 1;
    if (livesPtr->flags & 0x2000) {
        if (livesPtr->direction1 != 4 || livesPtr->unk168 != 0x800) {
            livesPtr->unk164 = 0;
            livesPtr->unk168 = 0x800;
            livesPtr->direction1 = 4;
            livesPtr->directionRelated = TRUE;
        }
        if (gGroundLivesMeta->unk28 != -1) {
            PixelPos pixPos = SetVecFromDirectionSpeed(gGroundLivesMeta->unk28, 0x100);
            sub_80A9F94(livesPtr, &pixPos);
        }
        if (metaPtr->unk8 < 0 && gGroundLivesMeta->unk24 >= 0) {
            metaPtr->unk8 = gGroundLivesMeta->unk24;
            metaPtr->unk0 = 0;
            metaPtr->unk4 = 0;
        }
    }
    else {
        PixelPos subbed, absed;
        struct GroundLivesMeta_Sub2C *unkMeta;
        s32 r12;
        s32 r6;
        s32 r7;
        bool8 loop;
        PixelPos pixPos32 = { livesPtr->unk144.x + livesPtr->unk14.x, livesPtr->unk144.y + livesPtr->unk14.y };
        PixelPos pixPos16 = pixPos32;

        if (metaPtr->unk8 < 0) {
            if (gGroundLivesMeta->unk24 < 0)
                return;
            metaPtr->unk8 = gGroundLivesMeta->unk24;
            metaPtr->unk0 = 0;
            metaPtr->unk4 = 0;
        }

        r7 = metaPtr->unk0;
        loop = TRUE;
        while (loop) {
            s32 r1;
            struct GroundLivesMeta_Sub2C *meta2CPtr = &gGroundLivesMeta->unk2C[metaPtr->unk8];
            PixelPos subbedPos = { meta2CPtr->unk4.x - pixPos16.x, meta2CPtr->unk4.y - pixPos16.y };

            if (subbedPos.x > 0) {
                if (subbedPos.x > r7) {
                    pixPos16.x = r7 + pixPos16.x;
                    loop = FALSE;
                }
                else {
                    pixPos16.x = meta2CPtr->unk4.x;
                }
                r1 = subbedPos.x;
            }
            else if (subbedPos.x < 0) {
                if (subbedPos.x < -r7) {
                    pixPos16.x -= r7;
                    loop = FALSE;
                }
                else {
                    pixPos16.x = meta2CPtr->unk4.x;
                }
                r1 = -subbedPos.x;
            }
            else {
                r1 = 0;
            }

            if (subbedPos.y > 0) {
                if (subbedPos.y > r7) {
                    pixPos16.y += r7;
                    loop = FALSE;
                }
                else {
                    pixPos16.y = meta2CPtr->unk4.y;
                    if (subbedPos.y > r1) {
                        r1 = subbedPos.y;
                    }
                }
            }
            else if (subbedPos.y < 0) {
                if (subbedPos.y < -r7) {
                    pixPos16.y -= r7;
                    loop = FALSE;
                }
                else {
                    pixPos16.y = meta2CPtr->unk4.y;
                    if (subbedPos.y < -r1) {
                        r1 = -subbedPos.y;
                    }
                }
            }

            if (loop) {
                r7 -= r1;
                if (r7 <= 0) {
                    loop = FALSE;
                }
                else if (metaPtr->unk8 != gGroundLivesMeta->unk24) {
                    metaPtr->unk8 = (metaPtr->unk8 + 1) % 64;
                }
                else {
                    loop = FALSE;
                }
            }
        }

        r6 = sub_80ABA00(metaPtr->unk8);
        r12 = gGroundLivesMeta->unk0[livesPtr->unk13C - 1].unk4 + gUnknown_8118050[livesPtr->unk13C];
        unkMeta = &gGroundLivesMeta->unk2C[metaPtr->unk8];
        subbed = (PixelPos) {unkMeta->unk4.x - pixPos16.x, unkMeta->unk4.y - pixPos16.y};
        absed = (PixelPos) {abs(subbed.x), abs(subbed.y)};

        r6 += max(absed.x, absed.y);
        metaPtr->unk4 = r6;
        if (r6 <= r12) {
            if (metaPtr->unk0 > 0) {
                metaPtr->unk0 -= 256;
            }
        }
        else if (r6 <= livesPtr->unk13C * 0x1800) {
            if (metaPtr->unk0 < 256) {
                metaPtr->unk0 += 256;
            }
        }
        else {
            s32 val = gGroundLivesMeta->unk0[livesPtr->unk13C - 1].unk0;
            if (val < 256) {
                val = 256;
            }
            if (metaPtr->unk0 < val) {
                metaPtr->unk0 += 256;
            }
        }

        if (((gGroundLivesMeta->unk24 + 64) - metaPtr->unk8) % 64 >= 60) {
            metaPtr->unk8 = (gGroundLivesMeta->unk24 + 5) % 64;
            pixPos16 = gGroundLivesMeta->unk2C[metaPtr->unk8].unk4;
        }

        if (sub_80A9F20(livesPtr, &pixPos16) == 0) {
            s32 r4;
            PixelPos pixPos24 = { pixPos16.x - pixPos32.x, pixPos16.y - pixPos32.y};
            livesPtr->direction1 = sub_8002B04(livesPtr->direction1, (s8) VecDirection8Radial(&pixPos24));
            if (metaPtr->unk0 > 0) {
                s16 asS16;

                livesPtr->unk164 = 4;
                asS16 = (metaPtr->unk0 > 0x200) ? 0xA00 : 0x800;
                r4 = asS16;
                sub_80AAF68(livesPtr, 1);
            }
            else {
                r4 = 0x807;
                livesPtr->unk164 = 0;
                sub_80AAF68(livesPtr, 0);
            }

            if (livesPtr->directionRelated || r4 != livesPtr->unk168 || livesPtr->direction2 != livesPtr->direction1) {
                struct UnkGroundSpriteStruct *groundSpritePtr;

                livesPtr->directionRelated = FALSE;
                groundSpritePtr = &livesPtr->unk170;
                livesPtr->unk168 = r4;
                sub_80A6EFC(groundSpritePtr, r4, (livesPtr->direction2 = livesPtr->direction1));
            }
        }
    }
}

static s32 sub_80ABA00(s32 a0)
{
    s32 i;
    s32 ret = 0;

    if (gGroundLivesMeta->unk24 > a0) {
        for (i = a0 + 1; i < gGroundLivesMeta->unk24; i++) {
            struct GroundLivesMeta_Sub2C *ptr2C = &gGroundLivesMeta->unk2C[i];
            ret += ptr2C->unk0;
        }
    }
    else if (gGroundLivesMeta->unk24 < a0) {
        for (i = a0 + 1; i < GROUND_LIVES_META_UNK2C_COUNT; i++) {
            struct GroundLivesMeta_Sub2C *ptr2C = &gGroundLivesMeta->unk2C[i];
            ret += ptr2C->unk0;
        }
        for (i = 0; i < gGroundLivesMeta->unk24; i++) {
            struct GroundLivesMeta_Sub2C *ptr2C = &gGroundLivesMeta->unk2C[i];
            ret += ptr2C->unk0;
        }
    }

    return ret;
}

void sub_80ABA7C(void)
{
    s32 i;
    struct GroundLive *livesPtr;

    for (livesPtr = &gGroundLives->array[0], i = 0; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), livesPtr++) {
        if (livesPtr->unk2 != -1) {
            PixelPos pixPos = { livesPtr->unk144.x + livesPtr->unk14.x, livesPtr->unk144.y + livesPtr->unk14.y };
            s32 r7 = livesPtr->unk154.x + livesPtr->unk154.y;

            if (livesPtr->unk164 > 0 && --livesPtr->unk164 <= 0 && (livesPtr->unk160 == 2 || livesPtr->unk160 == 1)) {
                sub_80A9750(livesPtr, livesPtr->unk160);
            }
            if (sub_80A66D4(&livesPtr->unk170)) {
                livesPtr->directionRelated = FALSE;
                sub_80A6EFC(&livesPtr->unk170, livesPtr->unk168, livesPtr->direction2);
            }
            if (livesPtr->unk16A != 0) {
                sub_80A74F0(&livesPtr->unk170, livesPtr->unk16A, livesPtr->direction1, livesPtr->unk16C);
                livesPtr->unk16A = 0;
            }
            sub_80A7524(&livesPtr->unk170, livesPtr->speciesId, &pixPos, r7);
        }
    }
}

#include "global.h"
#include "ground_script.h"
#include "ground_sprite.h"
#include "ground_event.h"
#include "ground_lives.h"
#include "ground_main.h"
#include "memory.h"
#include "event_flag.h"
#include "pokemon.h"
#include "friend_area.h"
#include "random.h"
#include "code_8099328.h"
#include "code_80958E8.h"
#include "debug.h"
#include "other_random.h"

struct GroundLivesMeta_Sub1
{
    // size: 0xC
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

struct unkStruct_3001B80
{
    // size: 0x338
   struct GroundLivesMeta_Sub1 unk0[3];
    u32 unk24;
    u8 unk28;
    struct GroundLivesMeta_Sub1 unk2C[0x40];
    ScriptInfoSmall unk32C;
};
IWRAM_INIT struct unkStruct_3001B80 *gGroundLivesMeta = NULL;

struct unkStruct_3001B84_sub
{
    // size: 0x1F0
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s8 unk6;
    s16 unk8;
    s32 unkC;
    s32 unk10;
    PixelPos unk14;
    s8 unk1C;
    PixelPos unk20;
    PixelPos unk28;
    PixelPos unk30;
    Action unk38;
    u32 unk11C;
    struct Struct3001B84_sub120 unk120;
    s16 unk13C;
    s16 unk13E;
    s16 unk140;
    s8 unk142;
    PixelPos unk144;
    PixelPos unk14C;
    PixelPos unk154;
    u8 unk15C;
    s8 unk15D;
    u16 unk15E;
    u16 unk160;
    s32 unk164;
    s16 unk168;
    u16 unk16A;
    u8 fill16C[1];
    struct UnkGroundSpriteStruct unk170;
};

#define UNK_3001B84_ARR_COUNT 0x18

struct unkStruct_3001B84
{
    struct unkStruct_3001B84_sub array[UNK_3001B84_ARR_COUNT];
};

IWRAM_INIT struct unkStruct_3001B84 *gGroundLives = NULL;

extern void DeleteGroundLives(void);
void GroundLives_Delete(s32);
s32 GroundLives_Add(s32 id_, const GroundLivesData *ptr, s32 group_, s32 sector_);
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
extern DebugLocation gUnknown_811808C;
extern u8 gUnknown_8118098[];
extern u8 gUnknown_81180BC[];
extern u8 gUnknown_81181B0[];

void AllocGroundLives(void)
{
    s32 index;
    struct unkStruct_3001B84_sub *ptr;

    gGroundLivesMeta = MemoryAlloc(sizeof(struct unkStruct_3001B80),6);
    gGroundLives = MemoryAlloc(sizeof(struct unkStruct_3001B84),6);

    for(index = 0, ptr = &gGroundLives->array[index]; index < UNK_3001B84_ARR_COUNT; index = (s16)(index + 1), ptr++)
    {
        ptr->unk2 = -1;
    }
    GetFunctionScript(0,&gGroundLivesMeta->unk32C,0x19);
    gGroundLivesMeta->unk32C.state = 1;
    DeleteGroundLives();
}

void DeleteGroundLives(void)
{
  int index;
  struct unkStruct_3001B84_sub *iVar4;
  struct GroundLivesMeta_Sub1 *ptr;


  iVar4 = &gGroundLives->array[0];
  for(index = 0; index < UNK_3001B84_ARR_COUNT; index = (s16)(index + 1), iVar4++)
  {
    if (iVar4->unk2 != -1) {
      GroundLives_Delete(index);
    }
  }

  gGroundLivesMeta->unk24 = -1;
  gGroundLivesMeta->unk28 = -1;


  for(index = 0; index < 3; ptr++, index++)
  {
      ptr = &gGroundLivesMeta->unk0[index];
      ptr->unk8 = -1;
      ptr->unk0 = 0;
      ptr->unk4 = 0;
  }


  for(index = 0; index < 0x40; ptr++, index++)
  {
     ptr = &gGroundLivesMeta->unk2C[index];
      ptr->unk0 = 0;
      ptr->unk4 = 0;
      ptr->unk8 = 0;
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
    scriptPtr = GetGroundScript(scriptID_s32, &gUnknown_811808C);
    Log('\0',gUnknown_8118098, scriptID_s32, group_s32, sector_s32);

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
    struct unkStruct_3001B84_sub *ptr;
    s32 sector_s32;
    s32 scriptID_s32;

    scriptID_s32 = (s16)scriptID;
    sector_s32 = (s8) sector;


    Log('\0',gUnknown_81180BC, scriptID_s32, sector_s32);

    index = 0;
    ptr = &gGroundLives->array[0];
    for(; index < UNK_3001B84_ARR_COUNT; index = (s16)(index + 1), ptr++)
    {
        if((ptr->unk2 != -1) && (ptr->unk4 == scriptID_s32))
            if(sector_s32 < 0 || ptr->unk6 == sector_s32)
                GroundLives_Delete(index);
    }
}

extern const char gUnknown_81180D8[];

void GroundLives_CancelBlank_1(void)
{
    s32 i;
    struct unkStruct_3001B84_sub *ptr;

    Log(0, gUnknown_81180D8);
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
    struct unkStruct_3001B84_sub *ptr;

    Log(0, gUnknown_81180D8);
    for (i = 0, ptr = &gGroundLives->array[0]; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1) {
            if (ptr->unk11C & 0x800) {
                ptr->unk13E = FindGroundEvent(0x20, &ptr->unk144, &ptr->unk14C);
            }
            else {
                ptr->unk13E = -1;
            }
        }
    }
}

s32 sub_80A7B94(s16 *a0);

s32 sub_80A7AE8(s16 a0)
{
    s32 i;
    struct unkStruct_3001B84_sub *ptr;
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
    struct unkStruct_3001B84_sub *ptr;
    s32 a0 = (s16) a0_;

    for (i = 0, ptr = &gGroundLives->array[0]; i < UNK_3001B84_ARR_COUNT; i = (s16)(i + 1), ptr++) {
        if (ptr->unk2 != -1 && ptr->unk13C == a0) {
            return i;
        }
    }

    return -1;
}

struct GroundLiveTypeData
{
    s16 unk0;
    s16 unk2;
    const char *unk4;
    u8 unk8;
    u8 unk9;
};

extern const struct GroundLiveTypeData gGroundLivesTypeData_811E63C[];

extern s32 sub_808D6A4(s32 *ptr);
extern s32 sub_808D654(s32 *ptr);

s32 sub_80A7B94(s16 *a0)
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
                    PokemonStruct1 *playerMonStruct = GetPlayerPokemonStruct();
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
                    PokemonStruct1 *playerMonStruct = GetPlayerPokemonStruct();
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
            u8 map = sub_8002658(GetScriptVarValue(NULL, GROUND_MAP));

            if (map != 0) {
                s32 id = *a0 - 14;
                GetFriendAreaCapacity2(map, &fAreaCapacity, FALSE, FALSE);
                if (id < fAreaCapacity.maxPokemon) {
                    PokemonStruct1 *monStrPtr = &gRecruitedPokemonRef->pokemon[fAreaCapacity.unk8 + id];
                    if (sub_80023E4(9)) {
                        if (PokemonFlag1(monStrPtr) && !monStrPtr->isTeamLeader) {
                            return -1;
                        }
                    }
                    else {
                        if (PokemonFlag1(monStrPtr) && !monStrPtr->isTeamLeader && !IsMonPartner(monStrPtr)) {
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
        PokemonStruct1 *playerMonStruct = GetPlayerPokemonStruct();
        if (sub_808D3BC() == playerMonStruct) {
            *a0 = 0x21;
        }
        else if (sub_808D3F8() == playerMonStruct) {
            *a0 = 0x22;
        }
    }

    return ret;
}

extern const s16 gUnknown_81180F0[];
extern const s16 gUnknown_81180FC[];

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
                PokemonStruct1 *monStrPtr = &gRecruitedPokemonRef->pokemon[sp[id]];
                *speciesDst = monStrPtr->speciesNum;
                return -1;
            }
        }
        else if (*a0 >= 14 && *a0 <= 29) {
            FriendAreaCapacity fAreaCapacity;
            u8 map = sub_8002658(GetScriptVarValue(NULL, GROUND_MAP));

            if (map != 0) {
                s32 id = *a0 - 14;
                GetFriendAreaCapacity2(map, &fAreaCapacity, FALSE, FALSE);
                if (id < fAreaCapacity.maxPokemon) {
                    PokemonStruct1 *monStrPtr = &gRecruitedPokemonRef->pokemon[fAreaCapacity.unk8 + id];
                    if (sub_80023E4(9)) {
                        if (PokemonFlag1(monStrPtr) && !monStrPtr->isTeamLeader) {
                            *speciesDst = monStrPtr->speciesNum;
                            return -1;
                        }
                    }
                    else {
                        if (PokemonFlag1(monStrPtr) && !monStrPtr->isTeamLeader && !IsMonPartner(monStrPtr)) {
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
            case 36:
                *speciesDst = gUnknown_81180FC[RandInt(15)];
                return -1;
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

extern const char gUnknown_811811C[];
extern const char gUnknown_8118194[];

extern void sub_809CD68(struct Struct3001B84_sub120 *dst);

extern bool8 GetCurrentDungeonBounds(PixelPos *a0, PixelPos *a1);
extern void sub_80A7428(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 monsterId_, s32 a3);
extern void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3);
extern bool8 ExecutePredefinedScript(Action *param_1, s32 *param_2, s16 index, const DebugLocation *debug);
extern void sub_809D170(s32 r0, s32 r1);
extern void sub_80A74E4(struct UnkGroundSpriteStruct *ptr);

extern const CallbackData gGroundLivesCallbacks[];
extern const DebugLocation gUnknown_8118170;
extern const DebugLocation gUnknown_811817C;
extern const DebugLocation gUnknown_8118188;
extern const DebugLocation gUnknown_81181F4;
extern const DebugLocation gUnknown_8118218;
extern const DebugLocation gUnknown_8118250;

void sub_80A9750(struct unkStruct_3001B84_sub *ptr, u16 a1);

s32 GroundLives_Add(s32 id_, const GroundLivesData *ptr, s32 group_, s32 sector_)
{
    s32 id = (s16) id_;
    s32 group = (s16) group_;
    s32 sector = (s8) sector_;
    struct unkStruct_3001B84_sub *livesPtr;
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
    Log(0, gUnknown_811811C, id, sp12, typeDataPtr->unk0, group, sector);
    var24 = (livesPtr->unk2 == -1);
    livesPtr->unk0 = id;
    livesPtr->unk2 = sp12;
    livesPtr->unk4 = group;
    livesPtr->unk6 = sector;
    livesPtr->unk8 = species;
    sub_809CD68(&livesPtr->unk120);
    livesPtr->unk120.unk0 = 9;

    switch (typeDataPtr->unk0) {
        case 1:
            livesPtr->unk11C = 0x2300181D;
            livesPtr->unk120.unk0 = 1;
            break;
        case 2:
            livesPtr->unk11C = 0x23001000;
            break;
        case 3:
            livesPtr->unk11C = 0x2300068D;
            break;
        case 6:
            livesPtr->unk11C = 0x2000000D;
            break;
        case 7:
            livesPtr->unk11C = 0x20000;
            break;
        case 8:
            livesPtr->unk11C = 0;
            break;
        case 9:
            livesPtr->unk11C = 0xC0000;
            break;
        case 10:
            livesPtr->unk11C = 0x20010000;
            break;
        default:
            livesPtr->unk11C = 0x2300068D;
            break;
    }

    livesPtr->unkC = typeDataPtr->unk8 << 11;
    livesPtr->unk10 = typeDataPtr->unk9 << 11;
    livesPtr->unk14.x = livesPtr->unkC / 2;
    livesPtr->unk14.y = livesPtr->unk10 / 2;
    livesPtr->unk1C = ptr->unk1;
    SetUnkInGroundEvent(&ptr->pos, &livesPtr->unk20);
    if (var24) {
        struct GroundLivesMeta_Sub1 *metaPtr;

        livesPtr->unk142 = livesPtr->unk1C;
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
            livesPtr->unk140 = OtherRandInt(0x12);
        }
        else {
            livesPtr->unk140 = 0;
        }
    }

    if (livesPtr->unk11C & 0x800) {
        livesPtr->unk13E = FindGroundEvent(0x20, &livesPtr->unk144, &livesPtr->unk14C);
    }
    else {
        livesPtr->unk13E = -1;
    }

    GetCurrentDungeonBounds(&livesPtr->unk28, &livesPtr->unk30);
    if (var24) {
        livesPtr->unk15D = -1;
        livesPtr->unk15E = 0x300;
        livesPtr->unk160 = 1;
        livesPtr->unk164 = 0;
        livesPtr->unk168 = 0x807;
        livesPtr->unk15C = 1;
        livesPtr->unk16A = 0;
        sub_80A7428(&livesPtr->unk170, livesPtr->unk2, livesPtr->unk8, livesPtr->unk11C);
    }

    if (!var24) {
        if (sub_809D684(&livesPtr->unk38, &gGroundLivesMeta->unk32C)) {
            s32 r10;
            s32 r9;
            // Note: these ptr variables are unfortunately a fakematch, but I was not able to match the function without them...
            u16 *ptr1;
            s8 *ptr2;

            if (livesPtr->unk38.scriptData2.savedState != 0) {
                r10 = livesPtr->unk38.scriptData2.unk24;
                r9 = livesPtr->unk38.scriptData2.unk26;

                ptr1 = &livesPtr->unk38.scriptData.unk24;
                ptr2 = &livesPtr->unk38.scriptData.unk26;
            }
            else {
                r10 = livesPtr->unk38.scriptData.unk24;
                r9 = livesPtr->unk38.scriptData.unk26;

                ptr1 = &livesPtr->unk38.scriptData.unk24;
                ptr2 = &livesPtr->unk38.scriptData.unk26;
            }

            InitAction2(&livesPtr->unk38);
            InitActionWithParams(&livesPtr->unk38, gGroundLivesCallbacks, livesPtr, group, sector);
            GroundScript_ExecutePP(&livesPtr->unk38, NULL, &gGroundLivesMeta->unk32C, &gUnknown_8118170);
            ptr2++;ptr2--;
            *ptr1 = r10;
            *ptr2 = r9;
            r8 = TRUE;
        }
        else {
            InitAction2(&livesPtr->unk38);
            InitActionWithParams(&livesPtr->unk38, gGroundLivesCallbacks, livesPtr, group, sector);
        }
    }
    else {
        InitActionWithParams(&livesPtr->unk38, gGroundLivesCallbacks, livesPtr, group, sector);
    }

    scrCommand = ptr->scripts[1];
    if (scrCommand == NULL) {
        scrCommand = gFunctionScriptTable[19].script;
    }
    SetPredefinedScript(&livesPtr->unk38, 1, scrCommand);

    scrCommand = ptr->scripts[2];
    if (scrCommand == NULL) {
        scrCommand = gFunctionScriptTable[4].script;
    }
    SetPredefinedScript(&livesPtr->unk38, 2, scrCommand);

    scrCommand = ptr->scripts[3];
    if (scrCommand == NULL) {
        scrCommand = gFunctionScriptTable[6].script;
    }
    SetPredefinedScript(&livesPtr->unk38, 3, scrCommand);

    if (ptr->scripts[0] != NULL) {
        SetPredefinedScript(&livesPtr->unk38, 0, ptr->scripts[0]);
        if (!var24 && !r8 && !(livesPtr->unk11C & 0x1800)) {
            GroundScript_ExecutePP(&livesPtr->unk38, NULL, &gGroundLivesMeta->unk32C, &gUnknown_811817C);
            livesPtr->unk38.scriptData.unk24 = livesPtr->unk160 | livesPtr->unk15E;
            livesPtr->unk38.scriptData.unk26 = livesPtr->unk142;
        }
        ExecutePredefinedScript(&livesPtr->unk38, NULL, 0, &gUnknown_8118188);
    }
    else if (r8) {
        livesPtr->unk15C = 1;
        livesPtr->unk142 = livesPtr->unk38.scriptData.unk26;
        sub_80A9750(livesPtr, livesPtr->unk38.scriptData.unk24);
    }

    if (typeDataPtr->unk0 == 1 && var24) {
        sub_809D170(1, id);
    }

    return id;
}

void GroundLives_Delete(s32 id_)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    Log(0, gUnknown_8118194, id);
    sub_80A74E4(&livesPtr->unk170);
    InitAction2(&livesPtr->unk38);
    livesPtr->unk2 = -1;
}

extern void sub_80A6688(struct UnkGroundSpriteStruct *ptr, s32 a0);
extern void sub_80AB5A4(void);

void sub_80A86C8(s32 id_, u32 flags)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

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

        livesPtr->unk11C |= flags;
        sub_80A6688(&livesPtr->unk170, livesPtr->unk11C);
    }
}

void sub_80A8750(s32 id_, u32 flags)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        if (livesPtr->unk13C == 0) {
            if (flags & 0x3000) {
                sub_80AB5A4();
            }
        }

        livesPtr->unk11C &= ~(flags);
        sub_80A6688(&livesPtr->unk170, livesPtr->unk11C);
    }
}

extern void sub_809CD8C(struct Struct3001B84_sub120 *dst, s32 a1);
extern bool8 sub_809B1C0(s32 a0, u32 kind, u8 *a2);
extern bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index);
extern bool8 sub_809D678(Action *action);

void sub_80A87AC(s32 id_, s32 a1)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        sub_809CD8C(&livesPtr->unk120, a1);
    }
}

bool8 sub_80A87E0(s32 id_, u8 *a1)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1 && sub_809B1C0(7, 0, a1)) {
        sub_809CD8C(&livesPtr->unk120, 5);
        return TRUE;
    }

    return FALSE;
}

Action *sub_80A882C(s32 id_)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return &livesPtr->unk38;
    }

    return NULL;
}

UNUSED static bool8 sub_80A885C(s32 id_, ScriptInfoSmall *scriptInfo, s32 a2_)
{
    s32 id = (s16) id_;
    s32 a2 = (s16) a2_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return GetPredefinedScript(&livesPtr->unk38, scriptInfo, a2);
    }

    return FALSE;
}

UNUSED static bool8 sub_80A88A0(s32 id_)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    if (livesPtr->unk2 != -1) {
        return sub_809D678(&livesPtr->unk38);
    }

    return FALSE;
}

bool8 GroundLives_ExecuteScript(s32 id_, s32 *a1, ScriptInfoSmall *scriptInfo)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    Log(0, gUnknown_81181B0, id, livesPtr->unk2, scriptInfo);

    if (livesPtr->unk2 != -1) {
        GroundScript_ExecutePP(&livesPtr->unk38, a1, scriptInfo, &gUnknown_81181F4);
        livesPtr->unk15C = 1;
        return TRUE;
    }

    return FALSE;
}

bool8 _ExecutePlayerScript(struct unkStruct_3001B84_sub *livesPtr, s32 *a1, ScriptInfoSmall *scriptInfo)
{
    livesPtr->unk15E = 0x300;
    livesPtr->unk160 = 1;
    livesPtr->unk164 = 0;
    if (livesPtr->unk168 != 0x807) {
        livesPtr->unk168 = 0x807;
        livesPtr->unk15C = 1;
    }

    if (scriptInfo != NULL) {
        return GroundScript_ExecutePP(&livesPtr->unk38, a1, scriptInfo, &gUnknown_8118218);
    }

    return FALSE;
}

UNUSED static bool8 sub_80A89AC(s32 id_, s32 *a1, ScriptInfoSmall *scriptInfo)
{
    s32 id = (s16) id_;
    struct unkStruct_3001B84_sub *livesPtr = &gGroundLives->array[id];

    return _ExecutePlayerScript(livesPtr, a1, scriptInfo);
}

bool8 GroundLives_ExecutePlayerScriptActionLives(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 >= 0 && id2 >= 0) {
        ScriptInfoSmall scriptInfo;
        struct unkStruct_3001B84_sub *livesPtr1 = &gGroundLives->array[id1];
        struct unkStruct_3001B84_sub *livesPtr2 = &gGroundLives->array[id2];

        if (livesPtr1->unk2 != -1 && livesPtr2->unk2 != -1 && GetPredefinedScript(&livesPtr2->unk38, &scriptInfo, 2)) {
            s32 sp = 1;

            sp |= (id2 << 0x10);
            ExecutePredefinedScript(&livesPtr2->unk38, (void *) &livesPtr1->unk38.unk8, 3, &gUnknown_8118250); // TODO: fix unk8 field?
            return _ExecutePlayerScript(livesPtr1, &sp, &scriptInfo);
        }
    }

    return FALSE;
}

extern bool8 sub_80AC274(s32 a0, ScriptInfoSmall *scriptInfo, s32 a2);
extern void GroundObject_ExecuteScript(s32, void *, ScriptInfoSmall *);
extern bool8 sub_80ADC64(s32 id, ScriptInfoSmall *dst);

bool8 sub_80A8A5C(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 >= 0 && id2 >= 0) {
        ScriptInfoSmall scriptInfo1;
        struct unkStruct_3001B84_sub *livesPtr1 = &gGroundLives->array[id1];

        if (sub_80AC274(id2, &scriptInfo1, 2)) {
            s32 sp = 2;
            ScriptInfoSmall scriptInfo2;

            sp |= (id2 << 0x10);
            sub_80AC274(id2, &scriptInfo2, 3);
            GroundObject_ExecuteScript(id2, &livesPtr1->unk38.unk8, &scriptInfo2);
            return _ExecutePlayerScript(livesPtr1, &sp, &scriptInfo1);
        }
    }

    return FALSE;
}

bool8 sub_80A8ACC(s32 id1_, s32 id2_)
{
    s32 id1 = (s16) id1_;
    s32 id2 = (s16) id2_;

    if (id1 >= 0 && id2 >= 0) {
        ScriptInfoSmall scriptInfo;
        struct unkStruct_3001B84_sub *livesPtr1 = &gGroundLives->array[id1];

        if (sub_80ADC64(id2, &scriptInfo)) {
            return _ExecutePlayerScript(livesPtr1, NULL, &scriptInfo);
        }
    }

    return FALSE;
}

//

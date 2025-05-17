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

struct GroundLivesMeta_Sub1
{
    // size: 0xC
    u32 unk0;
    u32 unk4;
    u32 unk8;
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
    u8 fill8[0x14 - 0x8];
    PixelPos unk14;
    u8 fill1C[0x11C-0x1C];
    u32 unk11C;
    u8 fill120[0x13C - 0x120];
    s16 unk13C;
    s16 unk13E;
    u8 fill140[4];
    PixelPos unk144;
    PixelPos unk14C;
    u8 fill14C[0x170-0x154];
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
s16 GroundLives_Add(s32 id, const GroundLivesData*, s32 group, s32 sector);
const struct GroundScriptHeader *GetGroundScript(s16 a0, DebugLocation *);
extern DebugLocation gUnknown_811808C;
extern u8 gUnknown_8118098[];
extern u8 gUnknown_81180BC[];

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

s16 sub_80A7AE8(s16 a0)
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
    u8 fill2[4];
    const char *unk4;
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

//

#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/item.h"
#include "constants/monster.h"
#include "constants/wonder_mail.h"
#include "structs/str_802C39C.h"
#include "code_803C1D0.h"
#include "code_80958E8.h"
#include "pokemon_mail.h"

static s32 sub_803B600(WonderMail *);
extern s32 sub_803B628(WonderMail *);
extern s32 sub_803B66C(WonderMail *);


typedef struct unkStruct_80E7F94
{
    /* 0x0 */ WonderMail mail;
    u8 *unk14;
    u8 *unk18;
} unkStruct_80E7F94;

extern u8 sUnknown_80E8020[];
extern u8 sUnknown_80E8038[];
extern u8 sUnknown_80E8048[];
extern u8 sUnknown_80E8060[];
extern u8 sUnknown_80E8070[];
extern u8 sUnknown_80E8088[];

const unkStruct_80E7F94 gUnknown_80E7F94[5] = {

    {
        {0x5, MISSION_TYPE_FIND_ITEM, 0x4, DUNGEON_ODDITY_CAVE, 0xC, 0x123456, MONSTER_PIKACHU, MONSTER_CHIMECHO, ITEM_SITRUS_BERRY, ITEM1_EXTRA, ITEM_REVIVER_SEED, FRIEND_AREA_NONE},
        sUnknown_80E8088,
        sUnknown_80E8070,
    },
    {
        {0x5, MISSION_TYPE_FIND_ITEM, 0x4, DUNGEON_REMAINS_ISLAND, 0x11, 0x123456,MONSTER_CHARMANDER, MONSTER_TREECKO, ITEM_SITRUS_BERRY, ITEM1_EXTRA, ITEM_REVIVER_SEED, FRIEND_AREA_NONE},
        sUnknown_80E8060,
        sUnknown_80E8048,
    },
    {
        {0x5, MISSION_TYPE_FIND_ITEM, 0x4, DUNGEON_MARVELOUS_SEA, 0x11, 0x123456,MONSTER_BULBASAUR, MONSTER_TORCHIC, ITEM_SITRUS_BERRY, ITEM1_EXTRA, ITEM_REVIVER_SEED, FRIEND_AREA_NONE},
        sUnknown_80E8038,
        sUnknown_80E8020,
    },
    {
        {0x5, MISSION_TYPE_FIND_ITEM, 0x0, DUNGEON_FANTASY_STRAIT, 0x1B, 0x123456, MONSTER_SQUIRTLE, MONSTER_CYNDAQUIL, ITEM_SITRUS_BERRY, ITEM1_EXTRA, ITEM_REVIVER_SEED, FRIEND_AREA_NONE},
        NULL,
        NULL,
    },
    {
        {0x5, MISSION_TYPE_FIND_ITEM, 0x0, DUNGEON_SINISTER_WOODS, 0x9, 0x123456, MONSTER_CHIKORITA, MONSTER_TOTODILE, ITEM_SITRUS_BERRY, ITEM1_EXTRA, ITEM_REVIVER_SEED, FRIEND_AREA_NONE},
        NULL,
        NULL,
    },
};

// TODO: unkStruct_803B344 isn't what we thought it is
const unkStruct_80E7F94 *sub_803B344(s32 _r0)
{
    u32 r0 = (u8)_r0;
    
    return &gUnknown_80E7F94[r0];
}

void sub_803B35C(WonderMail *mail, unkStruct_802C39C *param_2)
{
  u8 uVar2;
  
  sub_803C21C(mail, &param_2->unk18);
  switch(mail->unk2) {
      case '\x01':
        param_2->mailTitleType = 0;
        param_2->mailDescriptionType = 0;
        param_2->mailMissionType = MISSION_TYPE_SPECIAL_MISSION;
        param_2->unk18.rewardType = 5;
        break;
      case '\x02':
        param_2->mailTitleType = 1;
        param_2->mailDescriptionType = 1;
        param_2->mailMissionType = MISSION_TYPE_SPECIAL_MISSION;
        param_2->unk18.rewardType = 5;
        break;
      case '\x03':
        param_2->mailTitleType = 2;
        param_2->mailDescriptionType = 2;
        param_2->mailMissionType = MISSION_TYPE_SPECIAL_MISSION;
        param_2->unk18.rewardType = 5;
        break;
      case '\x04':
        param_2->mailTitleType = 3;
        param_2->mailDescriptionType = 3;
        param_2->mailMissionType = MISSION_TYPE_SPECIAL_MISSION;
        param_2->unk4C = sub_8096DD8();
        param_2->unk50 = sub_8096DE8();
        break;
      case '\x05':
        if (mail->missionType == MISSION_TYPE_RESCUE_CLIENT) {
          param_2->mailTitleType = '\v';
          param_2->mailMissionType = MISSION_TYPE_FIND_ITEM;
        }
        else {
          param_2->mailTitleType = '\f';
          param_2->mailMissionType = MISSION_TYPE_DELIVER_ITEM;
        }
        
        param_2->mailDescriptionType = 4;
        break;
      case '\x06':
        if (mail->missionType == 3) {
          param_2->mailTitleType = '\v';
            param_2->mailMissionType = MISSION_TYPE_FIND_ITEM;
        }
        else {
          param_2->mailTitleType = '\f';
            param_2->mailMissionType = MISSION_TYPE_DELIVER_ITEM;
        }
        
        param_2->mailDescriptionType = 5;
        break;
      case '\a':
        param_2->unk0[1] = sub_803B600(mail);
        if (param_2->unk0[1] == -1) {
            param_2->mailTitleType = 9;
        }
        else {
            param_2->mailTitleType = 4;
        }
        
        param_2->mailDescriptionType = 6;
        param_2->mailMissionType = MISSION_TYPE_RESCUE_TARGET;
        break;
      case '\b':
        param_2->unk0[1] = sub_803B628(mail);
        if (param_2->unk0[1] == -1) {
            param_2->mailTitleType = 9;
        }
        else {
            param_2->mailTitleType = 5;
        }  
        param_2->mailDescriptionType = 7;
        param_2->mailMissionType = MISSION_TYPE_RESCUE_TARGET;
        break;
      case '\t':
        param_2->unk0[1] = sub_803B66C(mail);
        if (param_2->unk0[1] == -1) {
              param_2->mailTitleType = 0xA;
        }
        else {
              param_2->mailTitleType = 6;
        }
      
        param_2->mailDescriptionType = '\b';
        param_2->mailMissionType = MISSION_TYPE_ESCORT_CLIENT;
        break;
      default:
        switch(mail->missionType)
        {
            case 1:
                param_2->mailTitleType = '\t';
                param_2->mailDescriptionType = '\r';
                param_2->mailMissionType = MISSION_TYPE_RESCUE_TARGET;
                break;
            case 2:
                param_2->mailTitleType = '\n';
                param_2->mailDescriptionType = '\x0e';
                param_2->mailMissionType = MISSION_TYPE_ESCORT_CLIENT;
                break;

            case 3:
                param_2->mailTitleType = '\v';
                param_2->mailDescriptionType = '\x0f';
                param_2->mailMissionType = MISSION_TYPE_FIND_ITEM;
                break;
            case 4:
                param_2->mailTitleType = '\f';
                param_2->mailDescriptionType = '\x10';
                param_2->mailMissionType = MISSION_TYPE_DELIVER_ITEM;
                break;
            default:
                param_2->mailTitleType = 8;
                param_2->mailDescriptionType = 0xC;
                param_2->mailMissionType = MISSION_TYPE_RESCUE_CLIENT;
                break;
        }
        break;

  }
  param_2->dungeonSeed = &mail->dungeonSeed;
  param_2->playerName = NULL;
  uVar2 = 0;
  param_2->clientSpecies = mail->clientSpecies;
  param_2->targetSpecies = mail->targetSpecies;
  param_2->targetItem = mail->targetItem;
  switch(mail->mailType) {
      case 2:
      case 3:
      case 4:
      case 5:
        param_2->unk43 = 1;
        param_2->mailStatus = 1;
        break;
      case 7:
        param_2->unk43 = 0;
        param_2->mailStatus = 3;
        break;
      case 6:
      case 8:
      case 9:
        param_2->unk43 = 3;
        param_2->mailStatus = 2;
        break;

      default:
        param_2->unk43 = uVar2;
        param_2->mailStatus = uVar2;
        break;


  }
  param_2->mail = mail;
  return;
}

static s32 sub_803B600(WonderMail *mail)
{
    s32 index;
    const unkStruct_80E9920 *ptr;

    for(ptr = &gUnknown_80E9920[0], index = 0; index < ARRAY_COUNT_INT(gUnknown_80E9920); ptr++, index++)
    {
        if ((ptr->parentSpecies == mail->clientSpecies) && (ptr->childSpecies == mail->targetSpecies)) {
            return index;
        }
    }

    return -1;
}


s32 sub_803B628(WonderMail *param_1) 
{
  const unkStruct_80E9F8C *ptr;
  s32 i;
  
    ptr = &gUnknown_80E9F8C[0];
    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80E9F8C); ptr++, i++) {
        if (ptr->species.speciesA == param_1->clientSpecies && ptr->species.speciesB == param_1->targetSpecies)
            return i;
        if (ptr->species.speciesB == param_1->clientSpecies && ptr->species.speciesA == param_1->targetSpecies)
            return i;
    }
    return -1;

}

s32 sub_803B66C(WonderMail *param_1) 
{
  const struct PokemonPair *ptr;
  s32 i;
  
    ptr = &gUnknown_80E8168[0];
    for (i = 0; i < ARRAY_COUNT_INT(gUnknown_80E8168); ptr++, i++) {
        if (ptr->speciesA == param_1->clientSpecies && ptr->speciesB == param_1->targetSpecies)
            return i;
        if (ptr->speciesB == param_1->clientSpecies && ptr->speciesA == param_1->targetSpecies)
            return i;
    }
    return -1;
}

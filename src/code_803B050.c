#include "global.h"
#include "code_8012A18_1.h"
#include "code_803B050.h"
#include "constants/colors.h"
#include "constants/wonder_mail.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "code_8094F88.h"
#include "text_util.h"
#include "text2.h"
#include "code_800D090.h"
#include "menu_input.h"
#include "dungeon.h"

// This file was originally 7 files. Check data_80E7D40.s

extern s16 gUnknown_80E80E0[];
extern s16 gUnknown_80E8126[];
extern u8 gUnknown_80E888C[]; 
extern u8 *gUnknown_80E8BCC[];
extern u8 gMankeyMissionDescription[];
extern u8 gSmeargleMissionDescription[];
extern u8 gMedichamMissionDescription[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_80E8968[];
extern u8 gUnknown_80E89B0[];
extern u8 gAvailablePokemonNames[];
extern u8 gDifficultyText[];
extern u8 gPlaceText[];
extern u8 gUnknown_80E8AD0[];
extern u8 gUnknown_80E8AE0[];
extern u8 gUnknown_80E8AEC[];
extern u8 gUnknown_80E8B10[];
extern u8 gUnknown_80E8AFC[];
extern u8 gUnknown_80E8B20[];
extern u8 gUnknown_80E8B40[];
extern u8 gUnknown_80E8B2C[];
extern u8 *gUnknown_80EB220[];
extern u8 gRewardText[];
extern u8 *gMissionRewardText[];
extern u8 gUnknown_80E8B7C[];
extern u8 *gUnknown_80EB2F0[];
extern u8 gUnknown_80E89FC[];
extern u8 gUnknown_80E8A40[];
extern u8 gUnknown_80E8A7C[];
extern u8 *gUnknown_80E8DE4[];
extern u8 *gUnknown_80E8FB0[];
extern u8 *gUnknown_80E91D4[];
extern u8 *gUnknown_80E9820[10];
extern u8 *gUnknown_80EAEB8[];
extern u8 gSpecialMissionText[];
extern u8 *gUnknown_80EB198[];
extern u8 *gUnknown_80EB3F8[];
extern u8 *gUnknown_80EB72C[22];
extern u8 gUnknown_80E8AC8[];
extern u8 gUnknown_80E8884[];
extern u8 gMankeyMission[];
extern u8 gSmeargleMission[];
extern u8 gMedichamMission[];
extern u8 gUnknown_80E8830[];
extern u8 gUnknown_80E8848[];
extern u8 gUnknown_80E885C[];
extern u8 gUnknown_80E8AC8[];
extern u8 *gUnknown_80E910C[];
extern u8 *gUnknown_80E8C98[];
extern u8 gUnknown_80E886C[];
extern u8 *gUnknown_80EAE5C[];
extern unkStruct_80E9F8C gUnknown_80E9F8C[10];
extern unkStruct_80E9920 gUnknown_80E9920[10];
extern u8 *gUnknown_80E8B94[];

extern PokemonStruct1 *sub_808D378(void);

extern void PrintDungeonLocationtoBuffer(u8 *, void *);
extern u8 sub_803C1D0(WonderMailSub *, u8);
extern u8 *sub_803C1F0(u8);
void sub_803D414(u8 *, WonderMail *);

void sub_803B6B0(s32 x, s32 y, u8 index, u32 param_4)
{
    xxx_call_draw_string(x,y,gUnknown_80E8B94[index],param_4,0);
}

void CreateRescueTitle(unkStruct_802C39C *param_1)
{
    u8 buf_1[200];
    u8 buf_2[20];
    u8 buf_3[100];
    u8 *monName;
    u8 uVar1;

    sub_803B6B0(10,param_1->y,param_1->unk43,param_1->unk0[0]);
    switch(param_1->mailTitleType) {
        case 3:
            xxx_call_draw_string(0x15,param_1->y,param_1->unk4C,param_1->unk0[0],0);
            break;
        case 0:
            xxx_call_draw_string(0x15,param_1->y,gMankeyMission,param_1->unk0[0],0);
            break;
        case 1:
            xxx_call_draw_string(0x15,param_1->y,gSmeargleMission,param_1->unk0[0],0);
            break;
        case 2:
            xxx_call_draw_string(0x15,param_1->y,gMedichamMission,param_1->unk0[0],0);
            break;
        case 7:
            PrintYellowDungeonNametoBuffer(buf_1, &param_1->unk8->dungeon);
            xxx_call_draw_string(0x15,param_1->y,buf_1,param_1->unk0[0],0);
            break;
        case 12:
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80E8830,gUnknown_202DE58);
            xxx_call_draw_string(0x15,param_1->y,buf_1,param_1->unk0[0],0);
            break;
        case 11:
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80E8848,gUnknown_202DE58);
            xxx_call_draw_string(0x15,param_1->y,buf_1,param_1->unk0[0],0);
            break;
        case 4:
            xxx_call_draw_string(0x15,param_1->y,gUnknown_80E885C,param_1->unk0[0],0);
            break;
        case 5:
            xxx_call_draw_string(0x15,param_1->y,gUnknown_80E9F8C[param_1->unk0[1]].text1,param_1->unk0[0],0);
            break;
        case 6:
            xxx_call_draw_string(0x15,param_1->y,gUnknown_80E886C,param_1->unk0[0],0);
            break;
        case 10: {
            u8 bVar2 =  param_1->unk8->seed + param_1->unk8->dungeon.id;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80EAE5C[(bVar2 & 3)],gAvailablePokemonNames);
            xxx_call_draw_string(0x15,param_1->y,buf_1,param_1->unk0[0],0);
            break;
        }
        case 9: {
            u8 bVar2 =  param_1->unk8->seed + param_1->unk8->dungeon.id;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E910C[(bVar2 % 0xA)],gAvailablePokemonNames);
            xxx_call_draw_string(0x15,param_1->y,buf_1,param_1->unk0[0],0);
            break;
        }
        default: {
            u8 bVar2 =  param_1->unk8->seed + param_1->unk8->dungeon.id;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E8C98[(bVar2 % 0xf)],gAvailablePokemonNames);
            xxx_call_draw_string(0x15,param_1->y,buf_1,param_1->unk0[0],0);
            break;
        }
    }

    if (param_1->mailTitleType == 7) {
        if (param_1->playerName == NULL) {
            xxx_call_draw_string(0xb2 - sub_8016028(),param_1->y,GetMonSpecies(param_1->clientSpecies),param_1->unk0[0],0);
        }
        else {
            sub_80922B4(buf_2,param_1->playerName,POKEMON_NAME_LENGTH);
            xxx_call_draw_string(0xb2 - sub_8016028(),param_1->y,buf_2,param_1->unk0[0],0);
        }
    }
    else {
        if (param_1->mailMissionType == MISSION_TYPE_FIND_ITEM) {
            PrintDungeonLocationtoBuffer(buf_3, param_1->unk8);
            sprintfStatic(buf_1,gUnknown_80E8884,buf_3); // Near %s
        }
        else {
            PrintDungeonLocationtoBuffer(buf_1, param_1->unk8);
        }
        xxx_call_draw_string(0x1d,param_1->y + 0xc,buf_1,param_1->unk0[0],0);
    }
    if (param_1->mailTitleType == 7) {
        uVar1 = sub_803C1D0(param_1->unk8,0);
    }
    else {
        uVar1 = sub_803C1D0(param_1->unk8,param_1->mail->missionType);
    }
    xxx_call_draw_string(0xb4,param_1->y,sub_803C1F0(uVar1),param_1->unk0[0],0);
}

void CreateRescueDescription(unkStruct_802C39C *param_1)
{
    u8 uVar3;
    int x;
    int counter;
    u32 color;
    s32 y;
    char buf_1 [300];
    char buf_2 [40];
    char buf_3 [20];
    char buf_4 [20];
    char buf_5 [100];
    u8 local_34 [24];
    u8 *monName;

    y = 0;

    xxx_call_draw_string(10,y,gUnknown_80E888C,param_1->unk0[0],0);
    xxx_call_draw_string(0x6c,y,gUnknown_80E8BCC[param_1->mailStatus],param_1->unk0[0],0);
    y += 0x10;
    switch(param_1->mailDescriptionType) {
        case 3:
            xxx_call_draw_string(10,y,param_1->unk50,param_1->unk0[0],0);
            break;
        case 0:
            xxx_call_draw_string(10,y,gMankeyMissionDescription,param_1->unk0[0],0);
            break;
        case 1:
            xxx_call_draw_string(10,y,gSmeargleMissionDescription,param_1->unk0[0],0);
            break;
        case 2:
            xxx_call_draw_string(10,y,gMedichamMissionDescription,param_1->unk0[0],0);
            break;
        case 4:
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80E8968,gUnknown_202DE58);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            break;
        case 5:
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80E89B0,gUnknown_202DE58);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            break;
        case 6:
            xxx_call_draw_string(10,y,gUnknown_80E9920[param_1->unk0[1]].text,param_1->unk0[0],0);
            break;
        case 7:
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E9F8C[param_1->unk0[1]].text2,gAvailablePokemonNames,gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            break;
        case 9:
            xxx_call_draw_string(10,y,gUnknown_80E89FC,param_1->unk0[0],0); // This is a rescue through communication. Get a friend to help you!
            break;
        case 10:
            xxx_call_draw_string(10,y,gUnknown_80E8A40,param_1->unk0[0],0); // This is a rescue through communication. Rescue a friend!
            break;
        case 11:
            xxx_call_draw_string(10,y,gUnknown_80E8A7C,param_1->unk0[0],0); // This is a rescue through communication. Send your thanks to a friend!
            break;
        case 15:
        case 16: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80EB3F8[(bVar2 % 0x16)],gUnknown_202DE58);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y += 0xC;
            sprintfStatic(buf_1,gUnknown_80EB72C[(bVar3 % 0x16)],gUnknown_202DE58);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y -= 0xC;
            break;
        }
        case 14: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80EAEB8[(bVar2 % 0x14)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y += 0xC;
            sprintfStatic(buf_1,(gUnknown_80EB198)[(bVar3 & 3)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y -= 0xC;
            break;
        }
        case 8: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80EB220[(bVar2 % 6)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y += 0xC;
            sprintfStatic(buf_1,gUnknown_80EB2F0[(bVar3 % 0x6)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y -= 0xC;
            break;
        }
        case 13: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E91D4[(bVar2 % 0x2d)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y += 0xC;
            sprintfStatic(buf_1,gUnknown_80E9820[(bVar3 % 10)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y -= 0xC;
            break;
        }
        default: {
            u8 bVar2 =  param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->clientSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E8DE4[(bVar2 % 0xd)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y += 0xC;
            sprintfStatic(buf_1,gUnknown_80E8FB0[(bVar3 % 0xd)],gAvailablePokemonNames);
            xxx_call_draw_string(10,y,buf_1,param_1->unk0[0],0);
            y -= 0xC;
            break;
        }
    }
    y  += 0x1C;
    xxx_call_draw_string(10,y,gUnknown_80E8AC8,param_1->unk0[0],0);
    if (param_1->playerName == NULL) {
        xxx_call_draw_string(0x44,y,GetMonSpecies(param_1->clientSpecies),param_1->unk0[0],0);
    }
    else {
        sub_80922B4(buf_3,param_1->playerName,POKEMON_NAME_LENGTH);
        sub_808D930(buf_4,param_1->clientSpecies);
        sprintfStatic(buf_2,gUnknown_80E8AD0,buf_3,buf_4);
        xxx_call_draw_string(0x44,y,buf_2,param_1->unk0[0],0);
    }

    y += 0xC;
    xxx_call_draw_string(10,y,gUnknown_80E8AE0,param_1->unk0[0],0);
    switch(param_1->mailMissionType) {
        case MISSION_TYPE_FRIEND_RESCUE:
            xxx_call_draw_string(0x44,y,gUnknown_80E8AEC,param_1->unk0[0],0); // Friend Rescue
            break;
        case MISSION_TYPE_DELIVER_ITEM:
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80E8AFC,gUnknown_202DE58); // Deliver #C4%s#R. 
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case MISSION_TYPE_FIND_ITEM:
            BufferItemName(gUnknown_202DE58,param_1->targetItem,NULL);
            sprintfStatic(buf_1,gUnknown_80E8B10,gUnknown_202DE58); // Find #C4%s#R.
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case MISSION_TYPE_RESCUE_CLIENT:
            xxx_call_draw_string(0x44,y,gUnknown_80E8B20,param_1->unk0[0],0); // Help me.
            break;
        case MISSION_TYPE_ESCORT_CLIENT:
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E8B2C,gAvailablePokemonNames); // Escort to #C6%s#R.
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case MISSION_TYPE_RESCUE_TARGET:
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gAvailablePokemonNames,monName);
            sprintfStatic(buf_1,gUnknown_80E8B40,gAvailablePokemonNames);
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case MISSION_TYPE_SPECIAL_MISSION:
        default:
            xxx_call_draw_string(0x44,y,gSpecialMissionText,param_1->unk0[0],0);
            break;
    }
    y += 0xC;
    xxx_call_draw_string(10,y,gPlaceText,param_1->unk0[0],0);
    
    // NOTE: check with TRUE is needed to match
    if (param_1->mailMissionType == MISSION_TYPE_FIND_ITEM) {
        PrintDungeonLocationtoBuffer(buf_5,param_1->unk8);
        sprintfStatic(buf_1,gUnknown_80E8884,buf_5); // Near %s
    }
    else {
        PrintDungeonLocationtoBuffer(buf_1,param_1->unk8);
    }
    xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
    if (param_1->mailMissionType == MISSION_TYPE_FRIEND_RESCUE) {
        uVar3 = sub_803C1D0(param_1->unk8, 0);
    }
    else {
        uVar3 = sub_803C1D0(param_1->unk8,param_1->mail->missionType);
    }

    y += 0xC;
    xxx_call_draw_string(10,y,gDifficultyText,param_1->unk0[0],0);
    xxx_call_draw_string(0x44,y,sub_803C1F0(uVar3),param_1->unk0[0],0);
    y += 0xC;
    xxx_call_draw_string(10,y,gRewardText,param_1->unk0[0],0);

    switch(param_1->rewardType) {
        case 0:
            sprintfStatic(buf_1,gMissionRewardText[param_1->rewardType],param_1->unk30);
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case 1:
            sprintfStatic(buf_1,gMissionRewardText[param_1->rewardType],param_1->unk30);
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case 2: // Item
        case 3: // Item + ?
            BufferItemName(gUnknown_202DE58,param_1->rewardItem,NULL);
            sprintfStatic(buf_1,gMissionRewardText[param_1->rewardType],gUnknown_202DE58);
            xxx_call_draw_string(0x44,y,buf_1,param_1->unk0[0],0);
            break;
        case 4: // Friend Area
            xxx_call_draw_string(0x44,y,gMissionRewardText[param_1->rewardType],param_1->unk0[0],0);
            break;
        default: 
            xxx_call_draw_string(0x44,y,gMissionRewardText[param_1->rewardType],param_1->unk0[0],0);
            break;
    }

    // Draw the Password
    y += 0xC;
    if (((2 < (u8)(param_1->mailDescriptionType - 9)) && (param_1->mailDescriptionType != 3)) && (param_1->mail->mailType == 5))
    {
        xxx_call_draw_string(10,y,gUnknown_80E8B7C,param_1->unk0[0],0); // Wonder Mail: 
        sub_803D414(local_34,param_1->mail);
        for(counter = 0; counter < 24; counter++)
        {
            if (counter == 12) {
                y += 12;
            }
            color = COLOR_WHITE_2;
            if (((3 < counter) && (color = COLOR_YELLOW, 7 < counter)) && ((color = COLOR_WHITE_2))) 
            {
                if(counter > 15)
                {
                    if(counter < 20)
                    {
                        color = COLOR_YELLOW;
                    }
                }

            }
            x = counter % 12;
            sub_8012C60(x * 10 + 0x54,y,local_34[counter],color,param_1->unk0[0]);
        }
    }
}

bool8 sub_803C0DC(s16 species)
{
  s32 baseSpecies;
  s32 index;
  
  baseSpecies = GetBaseSpecies(species);
  index = 0;
  if (gUnknown_80E80E0[index] != MONSTER_NONE)
  {
      while(gUnknown_80E80E0[index] != MONSTER_NONE) {
        if (gUnknown_80E80E0[index] == baseSpecies) {
            return FALSE;
        }
        index++;
      }
  }
  return TRUE;
}

bool8 sub_803C110(s16 index)
{
  PokemonStruct1 *pokeStruct;
  s16 *psVar5;
  s16 *psVar6;
  s32 species_s32;
  
  species_s32 = (s32)index;
  if ((!sub_8098134(index)) || (index != GetBaseSpecies(index)) || (!sub_803C0DC(index))) {
    return FALSE;
  }
  else {
    if (!sub_80023E4(6)) {
      psVar5 = &gUnknown_80E8126[0];
      if (*psVar5 != 0) {
        psVar6 = &gUnknown_80E8126[0];
        do {
          if (*psVar6 == species_s32) return FALSE;
          psVar5++;
          psVar6++;
        } while (*psVar5 != MONSTER_NONE);
      }
      pokeStruct = GetPlayerPokemonStruct();
      if ((pokeStruct->speciesNum == species_s32) ||
         (pokeStruct = sub_808D378(), pokeStruct->speciesNum == species_s32)) return FALSE;
    }
    return TRUE;
  }
}

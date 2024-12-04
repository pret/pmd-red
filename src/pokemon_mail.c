#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_8012A18_1.h"
#include "code_803C1D0.h"
#include "constants/colors.h"
#include "code_803D0D8.h"
#include "dungeon.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "items.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "pokemon_mail.h"
#include "pokemon_mail_pre.h"
#include "text_util.h"
#include "text.h"
#include "string_format.h"

#include "data/pokemon_mail.h"

// There are possibly more funcs in asm currently that belong to this file...

void sub_803B6B0(s32 x, s32 y, u8 index, u32 a3)
{
    PrintStringOnWindow(x, y, sUnknown_80E8B94[index], a3, 0);
}

void CreateRescueTitle(unkStruct_802C39C *param_1)
{
    u8 buf_1[200];
    u8 buf_2[20];
    u8 buf_3[100];
    u8 *monName;
    u8 uVar1;

    sub_803B6B0(10, param_1->y, param_1->unk43, param_1->unk0[0]);

    switch (param_1->mailTitleType) {
        case 3:
            PrintStringOnWindow(21, param_1->y, param_1->unk4C, param_1->unk0[0], 0);
            break;
        case 0:
            PrintStringOnWindow(21, param_1->y, gMankeyMission, param_1->unk0[0], 0);
            break;
        case 1:
            PrintStringOnWindow(21, param_1->y, gSmeargleMission, param_1->unk0[0], 0);
            break;
        case 2:
            PrintStringOnWindow(21, param_1->y, gMedichamMission, param_1->unk0[0], 0);
            break;
        case 7:
            PrintYellowDungeonNametoBuffer(buf_1, &param_1->unk8->dungeon);
            PrintStringOnWindow(21, param_1->y, buf_1, param_1->unk0[0], 0);
            break;
        case 12:
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80E8830, gFormatBuffer_Items[0]);
            PrintStringOnWindow(21, param_1->y, buf_1, param_1->unk0[0], 0);
            break;
        case 11:
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80E8848, gFormatBuffer_Items[0]);
            PrintStringOnWindow(21, param_1->y, buf_1, param_1->unk0[0], 0);
            break;
        case 4:
            PrintStringOnWindow(21, param_1->y, gUnknown_80E885C, param_1->unk0[0], 0);
            break;
        case 5:
            PrintStringOnWindow(21, param_1->y, gUnknown_80E9F8C[param_1->unk0[1]].headline, param_1->unk0[0], 0);
            break;
        case 6:
            PrintStringOnWindow(21, param_1->y, gUnknown_80E886C, param_1->unk0[0],0);
            break;
        case 10: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80EAE5C[bVar2 % 4], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(21, param_1->y, buf_1, param_1->unk0[0], 0);
            break;
        }
        case 9: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E910C[bVar2 % 10], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(21, param_1->y, buf_1, param_1->unk0[0], 0);
            break;
        }
        default: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E8C98[bVar2 % 15], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(21, param_1->y, buf_1, param_1->unk0[0], 0);
            break;
        }
    }

    if (param_1->mailTitleType == 7) {
        if (param_1->playerName == NULL)
            PrintStringOnWindow(178 - sub_8016028(), param_1->y, GetMonSpecies(param_1->clientSpecies), param_1->unk0[0], 0);
        else {
            sub_80922B4(buf_2, param_1->playerName, POKEMON_NAME_LENGTH);
            PrintStringOnWindow(178 - sub_8016028(), param_1->y, buf_2, param_1->unk0[0], 0);
        }
    }
    else {
        if (param_1->mailMissionType == MISSION_TYPE_FIND_ITEM) {
            PrintDungeonLocationtoBuffer(buf_3, &param_1->unk8->dungeon);
            sprintfStatic(buf_1, gUnknown_80E8884, buf_3);
        }
        else
            PrintDungeonLocationtoBuffer(buf_1, &param_1->unk8->dungeon);

        PrintStringOnWindow(29, param_1->y + 12, buf_1, param_1->unk0[0], 0);
    }

    if (param_1->mailTitleType == 7)
        uVar1 = sub_803C1D0(&param_1->unk8->dungeon, 0);
    else
        uVar1 = sub_803C1D0(&param_1->unk8->dungeon, param_1->mail->missionType);

    PrintStringOnWindow(180, param_1->y, sub_803C1F0(uVar1), param_1->unk0[0], 0);
}

void CreateRescueDescription(unkStruct_802C39C *param_1)
{
    u8 uVar3;
    s32 x;
    s32 counter;
    u32 color;
    s32 y;
    u8 buf_1[300];
    u8 buf_2[40];
    u8 buf_3[20];
    u8 buf_4[20];
    u8 buf_5[100];
    u8 local_34[24];
    u8 *monName;

    y = 0;

    PrintStringOnWindow(10, y, gUnknown_80E888C, param_1->unk0[0], 0);
    PrintStringOnWindow(108, y, sUnknown_80E8BCC[param_1->mailStatus], param_1->unk0[0], 0);
    y += 16;

    switch (param_1->mailDescriptionType) {
        case 3:
            PrintStringOnWindow(10, y, param_1->unk50, param_1->unk0[0], 0);
            break;
        case 0:
            PrintStringOnWindow(10, y, gMankeyMissionDescription, param_1->unk0[0], 0);
            break;
        case 1:
            PrintStringOnWindow(10, y, gSmeargleMissionDescription, param_1->unk0[0], 0);
            break;
        case 2:
            PrintStringOnWindow(10, y, gMedichamMissionDescription, param_1->unk0[0], 0);
            break;
        case 4:
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80E8968, gFormatBuffer_Items[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            break;
        case 5:
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80E89B0, gFormatBuffer_Items[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            break;
        case 6:
            PrintStringOnWindow(10, y, gUnknown_80E9920[param_1->unk0[1]].text, param_1->unk0[0], 0);
            break;
        case 7:
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E9F8C[param_1->unk0[1]].text, gFormatBuffer_Monsters[0], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            break;
        case 9:
            PrintStringOnWindow(10, y, gUnknown_80E89FC, param_1->unk0[0], 0);
            break;
        case 10:
            PrintStringOnWindow(10, y, gUnknown_80E8A40, param_1->unk0[0], 0);
            break;
        case 11:
            PrintStringOnWindow(10, y, gUnknown_80E8A7C, param_1->unk0[0], 0);
            break;
        case 15:
        case 16: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80EB3F8[bVar2 % 22], gFormatBuffer_Items[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y += 12;

            sprintfStatic(buf_1, gUnknown_80EB72C[bVar3 % 22], gFormatBuffer_Items[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y -= 12;
            break;
        }
        case 14: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80EAEB8[bVar2 % 20], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y += 12;

            sprintfStatic(buf_1, gUnknown_80EB198[bVar3 % 4], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y -= 12;
            break;
        }
        case 8: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80EB220[bVar2 % 6], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y += 12;

            sprintfStatic(buf_1, gUnknown_80EB2F0[bVar3 % 6], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y -= 12;
            break;
        }
        case 13: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E91D4[bVar2 % 45], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y += 12;

            sprintfStatic(buf_1, gUnknown_80E9820[bVar3 % 10], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y -= 12;
            break;
        }
        default: {
            u8 bVar2 = param_1->unk8->seed + param_1->unk8->dungeon.id;
            u8 bVar3 = param_1->unk8->seed + param_1->unk8->dungeon.floor;
            monName = GetMonSpecies(param_1->clientSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E8DE4[bVar2 % 13], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y += 12;

            sprintfStatic(buf_1, gUnknown_80E8FB0[bVar3 % 13], gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(10, y, buf_1, param_1->unk0[0], 0);
            y -= 12;
            break;
        }
    }

    y += 28;
    PrintStringOnWindow(10, y, gUnknown_80E8AC8, param_1->unk0[0], 0);

    if (param_1->playerName == NULL)
        PrintStringOnWindow(68, y, GetMonSpecies(param_1->clientSpecies), param_1->unk0[0], 0);
    else {
        sub_80922B4(buf_3, param_1->playerName, POKEMON_NAME_LENGTH);
        sub_808D930(buf_4, param_1->clientSpecies);
        sprintfStatic(buf_2, gUnknown_80E8AD0, buf_3, buf_4);
        PrintStringOnWindow(68, y, buf_2, param_1->unk0[0], 0);
    }

    y += 12;
    PrintStringOnWindow(10, y, gUnknown_80E8AE0, param_1->unk0[0], 0);

    switch (param_1->mailMissionType) {
        case MISSION_TYPE_FRIEND_RESCUE:
            PrintStringOnWindow(68, y, gUnknown_80E8AEC, param_1->unk0[0], 0);
            break;
        case MISSION_TYPE_DELIVER_ITEM:
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80E8AFC, gFormatBuffer_Items[0]);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case MISSION_TYPE_FIND_ITEM:
            BufferItemName(gFormatBuffer_Items[0], param_1->targetItem, NULL);
            sprintfStatic(buf_1, gUnknown_80E8B10, gFormatBuffer_Items[0]);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case MISSION_TYPE_RESCUE_CLIENT:
            PrintStringOnWindow(68, y, gUnknown_80E8B20, param_1->unk0[0], 0);
            break;
        case MISSION_TYPE_ESCORT_CLIENT:
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E8B2C, gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case MISSION_TYPE_RESCUE_TARGET:
            monName = GetMonSpecies(param_1->targetSpecies);
            strcpy(gFormatBuffer_Monsters[0], monName);
            sprintfStatic(buf_1, gUnknown_80E8B40, gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case MISSION_TYPE_SPECIAL_MISSION:
        default:
            PrintStringOnWindow(68, y, gSpecialMissionText, param_1->unk0[0], 0);
            break;
    }

    y += 12;
    PrintStringOnWindow(10, y, gPlaceText, param_1->unk0[0], 0);

    if (param_1->mailMissionType == MISSION_TYPE_FIND_ITEM) {
        PrintDungeonLocationtoBuffer(buf_5, &param_1->unk8->dungeon);
        sprintfStatic(buf_1, gUnknown_80E8884, buf_5);
    }
    else
        PrintDungeonLocationtoBuffer(buf_1, &param_1->unk8->dungeon);

    PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);

    if (param_1->mailMissionType == MISSION_TYPE_FRIEND_RESCUE)
        uVar3 = sub_803C1D0(&param_1->unk8->dungeon, 0);
    else
        uVar3 = sub_803C1D0(&param_1->unk8->dungeon, param_1->mail->missionType);

    y += 12;
    PrintStringOnWindow(10, y, gDifficultyText, param_1->unk0[0], 0);
    PrintStringOnWindow(68, y, sub_803C1F0(uVar3), param_1->unk0[0], 0);

    y += 12;
    PrintStringOnWindow(10, y, gRewardText, param_1->unk0[0], 0);

    switch (param_1->rewardType) {
        case MONEY:
            sprintfStatic(buf_1, gMissionRewardText[param_1->rewardType], param_1->unk30);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case MONEY_EXTRA:
            sprintfStatic(buf_1, gMissionRewardText[param_1->rewardType], param_1->unk30);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case ITEM: // Item
        case ITEM_EXTRA: // Item + ?
            BufferItemName(gFormatBuffer_Items[0], param_1->rewardItem, NULL);
            sprintfStatic(buf_1, gMissionRewardText[param_1->rewardType], gFormatBuffer_Items[0]);
            PrintStringOnWindow(68, y, buf_1, param_1->unk0[0], 0);
            break;
        case 4: // Friend Area
            PrintStringOnWindow(68, y, gMissionRewardText[param_1->rewardType], param_1->unk0[0], 0);
            break;
        default:
            PrintStringOnWindow(68, y, gMissionRewardText[param_1->rewardType], param_1->unk0[0], 0);
            break;
    }

    // Draw the Password
    y += 12;
    if ((2 < (u8)(param_1->mailDescriptionType - 9)) && param_1->mailDescriptionType != 3 && param_1->mail->mailType == 5) {
        PrintStringOnWindow(10, y, gUnknown_80E8B7C, param_1->unk0[0], 0);
        sub_803D414(local_34, param_1->mail);

        for (counter = 0; counter < 24; counter++) {
            if (counter == 12)
                y += 12;

            color = COLOR_WHITE_2;
            if (counter > 3) {
                color = COLOR_YELLOW;
                if (counter > 7 && (color = COLOR_WHITE_2)) { // ?
                    if (counter > 15) {
                        if (counter < 20)
                            color = COLOR_YELLOW;
                    }
                }
            }

            x = counter % 12;
            sub_8012C60((x * 10) + 84, y, local_34[counter], color, param_1->unk0[0]);
        }
    }
}

bool8 sub_803C0DC(s16 species)
{
    s32 baseSpecies;
    s32 index;

    baseSpecies = GetBaseSpecies(species);
    index = 0;

    //if (gUnknown_80E80E0[index] != MONSTER_NONE) {
        while (gUnknown_80E80E0[index] != MONSTER_NONE) {
            if (gUnknown_80E80E0[index] == baseSpecies)
                return FALSE;

            index++;
        }
    //}

    return TRUE;
}

bool8 sub_803C110(s16 index)
{
    PokemonStruct1 *pokeStruct;
    const s16 *psVar5;
    const s16 *psVar6;
    s32 species_s32;

    species_s32 = (s32)index;

    if (!sub_8098134(index) || index != GetBaseSpecies(index) || !sub_803C0DC(index))
        return FALSE;

    if (!sub_80023E4(6)) {
        psVar5 = &gUnknown_80E8126[0]; // TODO: Un-ugly this
        if (*psVar5 != MONSTER_NONE) {
            psVar6 = &gUnknown_80E8126[0];
            do {
                if (*psVar6 == species_s32)
                    return FALSE;
                psVar5++;
                psVar6++;
            } while (*psVar5 != MONSTER_NONE);
        }

        pokeStruct = GetPlayerPokemonStruct();
        if (pokeStruct->speciesNum == species_s32)
            return FALSE;
        pokeStruct = sub_808D378();
        if (pokeStruct->speciesNum == species_s32)
            return FALSE;
    }
    return TRUE;
}

const u8 *GetPokemonMailHeadline(u8 index)
{
    return sPokemonMail[index].headline;
}

const u8 *GetPokemonMailText(u8 index)
{
    return sPokemonMail[index].text;
}

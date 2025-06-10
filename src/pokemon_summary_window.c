#include "global.h"
#include "globaldata.h"
#include "pokemon_summary_window.h"
#include "string_format.h"
#include "strings.h"
#include "pokemon_3.h"
#include "pokemon_evolution.h"
#include "text_1.h"
#include "items.h"
#include "pokemon_types.h"
#include "pokemon_abilities.h"
#include "friend_area.h"
#include "dungeon_info.h"
#include "dungeon_data.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/colors.h"

void ShowPokemonSummaryWindow(s32 which, s32 currSubWindowId, struct MonSummaryInfo *monInfo, struct UnkInfoTabStruct *param_4, u32 windowId)
{
    s32 i, y;
    s32 j;

    sub_80073B8(windowId);
    strncpy(gFormatBuffer_Monsters[0],monInfo->nameBuffer,0x14);
    y = 0x20;
    switch (which) {
        case SUB_WINDOW_NONE:
            break;
        case SUB_WINDOW_STATS: {
            const u8 *str;
            s32 iVar8;
            LevelData levelData;

            PrintFormattedStringOnWindow(currSubWindowId * 8 + 0x10,0,_("Stats"),windowId,'\0');
            gFormatArgs[0] = monInfo->level;
            gFormatArgs[1] = monInfo->exp;
            PrintFormattedStringOnWindow(4,y,gText_LevelUnkMacro,windowId,'\0');
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,gText_ExpPtsUnkMacro,windowId,'\0');
            y += 0xA;
            if (monInfo->level < 100) {
                GetPokemonLevelData(&levelData,monInfo->species,monInfo->level + 1);
                gFormatArgs[0] = levelData.expRequired - monInfo->exp;
                PrintFormattedStringOnWindow(4,y,gText_ToNextLevel,windowId,'\0');
            }
            y += 0xC;
            gFormatArgs[0] = monInfo->HP1;
            gFormatArgs[1] = monInfo->HP2;
            PrintFormattedStringOnWindow(4,y,gUnknown_810DDD0,windowId,'\0');
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,gUnknown_810DDE4,windowId,'\0');
            str = gUnknown_810DE0C;
            gFormatArgs[0] = monInfo->offense.att[0];
            if (monInfo->atkBoost != 0) {
                gFormatArgs[0] = gFormatArgs[0] + monInfo->atkBoost;
                str = gUnknown_810DE20;
            }
            PrintFormattedStringOnWindow(4,y,str,windowId,'\0');
            if (monInfo->defBoost != 0) {
                gFormatArgs[0] = monInfo->offense.def[0] + monInfo->defBoost;
                PrintFormattedStringOnWindow(4,y,gUnknown_810DE4C,windowId,'\0');
            }
            else {
                gFormatArgs[0] = monInfo->offense.def[0];
                PrintFormattedStringOnWindow(4,y,gUnknown_810DE38,windowId,'\0');
            }
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,gUnknown_810DDFC,windowId,'\0');
            str = gUnknown_810DE24;
            gFormatArgs[0] = monInfo->offense.att[1];
            if (monInfo->spAtkBoost != 0) {
                gFormatArgs[0] = gFormatArgs[0] + monInfo->spAtkBoost;
                str = gUnknown_810DE28;
            }
            PrintFormattedStringOnWindow(4,y,str,windowId,'\0');
            if (monInfo->spDefBoost != 0) {
                gFormatArgs[0] = monInfo->offense.def[1] + monInfo->spDefBoost;
                PrintFormattedStringOnWindow(4,y,gUnknown_810DE54,windowId,'\0');
            }
            else {
                gFormatArgs[0] = monInfo->offense.def[1];
                PrintFormattedStringOnWindow(4,y,gUnknown_810DE50,windowId,'\0');
            }
            y += 0xA;
            if (ItemExists(&monInfo->item)) {
                 sub_8090E14(gFormatBuffer_Items[0],&monInfo->item,0);
            }
            else {
                strcpy(gFormatBuffer_Items[0],gUnknown_810DE58);
            }
            PrintFormattedStringOnWindow(4,y,gUnknown_810DE6C,windowId,'\0');
            y += 0xC;
            gFormatArgs[0] = monInfo->IQ;
            iVar8 = monInfo->IQ / 10;
            if (iVar8 < 0) {
                iVar8 = 0;
            }
            if (0x62 < iVar8) {
                iVar8 = 99;
            }

            InlineStrcpy(gFormatBuffer_Monsters[0],gUnknown_8115718[iVar8]);
            PrintFormattedStringOnWindow(4,y,gUnknown_810DE80,windowId,'\0');
            y += 0xA;
            if (!monInfo->isTeamLeader)
            {
                CopyTacticsNameToBuffer(gFormatBuffer_Monsters[0],monInfo->tactic);
                PrintFormattedStringOnWindow(4,y,gUnknown_810DE98,windowId,'\0');
            }
            y += 0xA;
            break;
        }
        case SUB_WINDOW_FEATUERS: {
            PrintFormattedStringOnWindow(currSubWindowId * 8 + 0x10,0,_("Features"),windowId,'\0');
            PrintFormattedStringOnWindow(4,y,_("Type:"),windowId,'\0');
            PrintFormattedStringOnWindow(0x38,y,GetFormattedTypeString(monInfo->types[0]),windowId,'\0');
            if (monInfo->types[1] != TYPE_NONE) {
                PrintFormattedStringOnWindow(0x60,y,GetFormattedTypeString(monInfo->types[1]),windowId,'\0');
            }
            y += 0xC;
            PrintFormattedStringOnWindow(4,y,_("Special Abilities:"),windowId,'\0');
            y += 0xC;
            PrintFormattedStringOnWindow2(4,y,GetAbilityDescription(monInfo->abilities[0]),windowId,'\0',0xb);
            y += 0x21;
            if (monInfo->abilities[1] != ABILITY_UNKNOWN) {
                PrintFormattedStringOnWindow2(4,y,GetAbilityDescription(monInfo->abilities[1]),windowId,'\0',0xb);
            }
            break;
        }
        case SUB_WINDOW_STATUS: {
            s32 iVar11;
            bool8 bVar10;

            PrintFormattedStringOnWindow(currSubWindowId * 8 + 0x10,0,gUnknown_810DD58,windowId,'\0');
            iVar11 = monInfo->unk56 - 1;
            y -= 0xC;
            bVar10 = FALSE;

            for (i = 0; i < 9; i++) {
                param_4->unkC[i] = 0;
            }

            for (j = 0; j < 10; j++, iVar11++, y += 0xC) {
                if (-1 < iVar11) {
                    if (0xb < iVar11)
                        break;
                    if (monInfo->unk58[iVar11] != 0) {
                        bVar10 = TRUE;
                        InlineStrncpy(gFormatBuffer_Items[1],gStatusNames[monInfo->unk58[iVar11]],0x50);
                        PrintFormattedStringOnWindow(0xc,y,_("{MOVE_ITEM_1}"),windowId,'\0');
                        if (0 < j) {
                            param_4->unkC[j - 1] = monInfo->unk58[iVar11];
                        }
                    }
                }
            }

            if (!bVar10) {
                PrintFormattedStringOnWindow(0xc,0x20,gUnknown_810DF78,windowId,'\0');
            }
            break;
        }
        case SUB_WINDOW_IQ: {
            s32 iVar13;
            bool8 bVar11;
            u8 iqSkillBuffer[24];

            PrintFormattedStringOnWindow(currSubWindowId * 8 + 0x10,0,gText_IqSkills,windowId,'\0');
            GetNumAvailableIQSkills(iqSkillBuffer,monInfo->IQ);
            iVar13 = monInfo->unk40 - 1;

            for (i = 0; i < 9; i++) {
                param_4->unk0[i] = 0;
            }
            y -= 0xC;
            bVar11 = FALSE;

            for(j = 0; j < 10; j++, iVar13++, y += 0xC) {
                if (-1 < iVar13) {
                    if (0x17 < iVar13)
                        break;
                    if (iqSkillBuffer[iVar13] != 0) {
                        const u8 *iqSkillName;

                        bVar11 = TRUE;
                        iqSkillName = GetIQSkillName(iqSkillBuffer[iVar13]);
                        strncpy(gFormatBuffer_Items[1],iqSkillName,0x50);
                        if (IsIQSkillSet(&monInfo->IQSkills,1 << iqSkillBuffer[iVar13])) {
                            InlineStrcpy(gFormatBuffer_Items[0],_("{STAR_BULLET}"));
                        }
                        else {
                            InlineStrcpy(gFormatBuffer_Items[0],_("{ICON_BLANK}"));
                        }
                        if (j >= 1) {
                            param_4->unk0[j - 1] = iqSkillBuffer[iVar13];
                        }
                        PrintFormattedStringOnWindow(0xc,y,_("{MOVE_ITEM_0}{MOVE_ITEM_1}"),windowId,'\0');
                    }
                }
            }

            if (!bVar11) {
                PrintFormattedStringOnWindow(0xc,0x20,gUnknown_810DF84,windowId,'\0');
            }
            break;
        }
        case SUB_WINDOW_INFO: {
            PrintFormattedStringOnWindow(currSubWindowId * 8 + 0x10,0,_("Info"),windowId,'\0');
            CopyMonsterNameToBuffer(gFormatBuffer_Monsters[0],monInfo->species);
            gFormatArgs[0] = monInfo->species;
            PrintFormattedStringOnWindow(4,y,gUnknown_810DEB4,windowId,'\0');
            y += 0xA;
            InlineStrncpy(gFormatBuffer_Items[0],GetFriendAreaName(GetFriendArea(monInfo->species)),0x50);
            PrintFormattedStringOnWindow(4,y,gUnknown_810DEC8,windowId,'\0');
            y += 0xA;
            PrintFormattedStringOnWindow(4,y,gUnknown_810DEDC,windowId,'\0');
            y += 0xD;
            PrintFormattedStringOnWindow(4,y,gUnknown_810DFB4,windowId,'\0');
            y += 0xA;
            PrintYellowDungeonNametoBuffer(gFormatBuffer_Items[0],&monInfo->dungeonLocation);
            PrintFormattedStringOnWindow(4,y,gUnknown_810DFC8,windowId,'\0');
            y += 0xD;
            strncpy(gFormatBuffer_Monsters[0],GetCategoryString(monInfo->species),0x14);
            PrintFormattedStringOnWindow(4,y,gUnknown_810DEF4,windowId,'\0');
            y += 0xD;
            strcpy(gFormatBuffer_Monsters[0],gUnknown_810E02C[GetBodySize(monInfo->species)]);
            PrintFormattedStringOnWindow(4,y,gUnknown_810DF98,windowId,'\0');
            y += 0xD;
            PrintFormattedStringOnWindow(4,y,gEvolutionStrings[monInfo->evoStringId],windowId,'\0');
            break;
        }
    }
    sub_80073E0(windowId);
}

void SetMonSummaryInfo(struct MonSummaryInfo *dst, struct PokemonStruct1 *pokemon, bool8 param_3)
{
    s32 index;

    PrintColoredPokeNameToBuffer(dst->nameBuffer, pokemon, COLOR_WHITE);
    dst->species = pokemon->speciesNum;
    dst->HP1 = pokemon->pokeHP;
    dst->HP2 = pokemon->pokeHP;
    dst->level = pokemon->level;
    dst->exp = pokemon->currExp;
    for(index = 0; index < 2; index++)
    {
        dst->offense.att[index] = pokemon->offense.att[index];
        dst->offense.def[index] = pokemon->offense.def[index];
        dst->types[index] = GetPokemonType(pokemon->speciesNum,index);
        dst->abilities[index] = GetPokemonAbility(pokemon->speciesNum,index);
    }
    dst->isTeamLeader = pokemon->isTeamLeader;
    dst->atkBoost = 0;
    dst->spAtkBoost = 0;
    dst->defBoost = 0;
    dst->spDefBoost = 0;

    if (pokemon->heldItem.id != 0) {
        if (pokemon->heldItem.id == ITEM_POWER_BAND) {
            dst->atkBoost += gUnknown_810AC60;
        }
        if (pokemon->heldItem.id == ITEM_SPECIAL_BAND) {
            dst->spAtkBoost+= gUnknown_810AC62;
        }
        if (pokemon->heldItem.id == ITEM_MUNCH_BELT) {
            dst->atkBoost += gUnknown_810AC68;
        }
        if (pokemon->heldItem.id == ITEM_MUNCH_BELT) {
            dst->spAtkBoost+= gUnknown_810AC68;
        }
        if (pokemon->heldItem.id == ITEM_DEF_SCARF) {
            dst->defBoost += gUnknown_810AC64;
        }
        if (pokemon->heldItem.id == ITEM_ZINC_BAND) {
            dst->spDefBoost += gUnknown_810AC66;
        }
    }
    dst->tactic = pokemon->tacticIndex;
    HeldItemToSlot(&dst->item,&pokemon->heldItem);
    dst->IQ = pokemon->IQ;
    dst->dungeonLocation = pokemon->dungeonLocation;
    dst->unk44[0] = pokemon->unkC[0];
    dst->unk44[1] = pokemon->unkC[1];
    dst->IQSkills = pokemon->IQSkills;
    if (param_3) {
        dst->evoStringId = GetMonSummaryScreenEvoStringId(pokemon);
    }
    else {
        dst->evoStringId = EVO_STRING_EMPTY;
    }

    for(index = 0; index < 0xC; index++)
    {
        dst->unk58[index] = 0;
    }
}

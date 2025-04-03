#include "global.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_leader.h"
#include "code_8084778.h"
#include "string_format.h"
#include "code_80958E8.h"
#include "mailbox.h"
#include "pokemon_mid.h"
#include "structs/str_dungeon.h"
#include "constants/dungeon.h"

extern const u8 gUnknown_8107224[];

extern void sub_8042A34(DungeonPos *r0);
extern void sub_804178C(u32);

void sub_80842F0(void)
{
    s32 i;

    gDungeon->unk644.unk33 = 0;
    gDungeon->unk644.unk46 = 0;
    if (gDungeon->unk644.unk34 != 2)
        return;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        WonderMail *jobSlot = GetJobSlotInfo(i);
        if (jobSlot->mailType == MAIL_TYPE_TAKEN_JOB) {
            if (gDungeon->unk644.dungeonLocation.id == jobSlot->unk4.dungeon.id
                && gDungeon->unk644.dungeonLocation.floor == jobSlot->unk4.dungeon.floor
                && jobSlot->missionType != 3)
            {
                if (jobSlot->missionType == 4) {
                    gDungeon->unk644.unk46 = jobSlot->targetItem;
                    gDungeon->unk644.unk44 = jobSlot->targetSpecies;
                    gDungeon->unk9 = 1;
                }
                else if (jobSlot->missionType == 0 || jobSlot->missionType == 2 || jobSlot->missionType == 1) {
                    gDungeon->unk644.unk44 = jobSlot->targetSpecies;
                    if (jobSlot->missionType == 2) {
                        gDungeon->unk644.unk33 = 1;
                    }
                    gDungeon->unk9 = 1;
                }
            }
        }
    }
}

void sub_80843BC(s32 id)
{
    s32 i;
    s32 id_s32 = (s16) id;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        WonderMail *jobSlot = GetJobSlotInfo(i);
        if (jobSlot->mailType == MAIL_TYPE_TAKEN_JOB) {
            if (gDungeon->unk644.dungeonLocation.id == jobSlot->unk4.dungeon.id
                && (gDungeon->unk644.dungeonLocation.floor == jobSlot->unk4.dungeon.floor)
                && (jobSlot->missionType == 0 || jobSlot->missionType == 4 || jobSlot->missionType == 2 || jobSlot->missionType == 1)
                && id_s32 == jobSlot->targetSpecies) {
                    jobSlot->mailType = MAIL_TYPE_UNK8;
                }
            }
    }
}

void sub_8084424(void)
{
    s32 i;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        WonderMail *jobSlot = GetJobSlotInfo(i);
        if (jobSlot->mailType == MAIL_TYPE_UNK8) {
            jobSlot->mailType = MAIL_TYPE_UNK9;
        }
    }
}

void sub_8084448(Entity *pokemon)
{
    int i;
    const u8 *str;
    EntityInfo *entInfo = GetEntInfo(pokemon);

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],pokemon,0);
    if (!sub_8070BC0(pokemon)) {
        DisplayDungeonMessage(0,gUnknown_80FA464,1);
        return;
    }

    if (gDungeon->unk644.unk46 != 0) {
        if (DisplayDungeonYesNoMessage(0, gUnknown_80FA32C, 1) != 1)
            return;
        BufferItemName(gFormatBuffer_Items[0], gDungeon->unk644.unk46, 0);
        for (i = 0; i < INVENTORY_SIZE; i++) {
            Item *item = &gTeamInventoryRef->teamItems[i];
            if (ItemExists(item)
                && !(item->flags & ITEM_FLAG_IN_SHOP)
                && !(item->flags & ITEM_FLAG_STICKY && (item->flags & ITEM_FLAG_SET))
                && item->id == gDungeon->unk644.unk46)
            {
                break;
            }
        }

        if (i == INVENTORY_SIZE) {
            DisplayDungeonMessage(0, gUnknown_80FA448, 1);
            return;
        }
        ZeroOutItem(&gTeamInventoryRef->teamItems[i]);
        FillInventoryGaps();
        DisplayDungeonMessage(0, gUnknown_80FA2B0, 1);
        str = gUnknown_80FA370;
    }
    else {
        if (DisplayDungeonYesNoMessage(0, gUnknown_80FA2F0, 1) != 1)
            return;
        DisplayDungeonMessage(0, gUnknown_80FA260, 1);
        str = gUnknown_80FA36C;
    }

    sub_80843BC(entInfo->id);
    sub_8042A34(&pokemon->pos);
    sub_8068FE0(pokemon,0x21c,0);
    sub_804178C(1);
    while(1) {
        if (DisplayDungeonYesNoMessage(0,str,1) == 1) {
            if (DisplayDungeonYesNoMessage(0,gUnknown_80FA394,0) == 1) {
                gDungeon->unk4 = 1;
                gDungeon->unk11 = 2;
                return;
            }
        }
        else if (DisplayDungeonYesNoMessage(0,gUnknown_80FA3B8,0) == 1) {
            return;
        }
    }
}

void sub_80845E0(Entity *pokemon)
{
    int i;
    EntityInfo *info1 = GetEntInfo(pokemon);
    Entity *entity = NULL;
    EntityInfo *info2 = NULL;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],pokemon,0);
    if (!sub_8070BC0(pokemon)) {
        DisplayDungeonMessage(0,gUnknown_80FA530,1);
        return;
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            if (IsExperienceLocked(GetEntInfo(teamMon)->joinedAt.id)) {
                entity = teamMon;
                info2 = GetEntInfo(teamMon);
                break;
            }
        }
    }
    if (entity == NULL) {
        DisplayDungeonMessage(0,gUnknown_80FA52C,1);
        return;
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[2],entity,0);
    if (!sub_8070BC0(entity)) {
        DisplayDungeonMessage(0,gUnknown_80FA54C,1);
        return;
    }
    if (!CanSeeTarget(pokemon,entity)) {
        DisplayDungeonMessage(0,gUnknown_80FA500,1);
        return;
    }

    DisplayDungeonMessage(0,gUnknown_80FA4D4,1);
    sub_80843BC(info1->id);
    info2->joinedAt.id = gDungeon->unk644.dungeonLocation.id;
    sub_8042A34(&pokemon->pos);
    sub_8042A34(&entity->pos);
    sub_8068FE0(pokemon,0x21c,0);
    sub_8068FE0(entity,0x21c,0);
    sub_804178C(1);
    while(1) {
        if (DisplayDungeonYesNoMessage(0,gUnknown_80FA4D8,1) == 1) {
            if (DisplayDungeonYesNoMessage(0,gUnknown_80FA394,0) == 1) {
                gDungeon->unk4 = 1;
                gDungeon->unk11 = 2;
                return;
            }
        }
        else if (DisplayDungeonYesNoMessage(0,gUnknown_80FA3B8,0) == 1) {
            return;
        }
    }
}

void sub_8084778(void)
{
    s32 i;
    WonderMail *wm;

    strcpy(gFormatBuffer_Monsters[3], gUnknown_8107224);

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        wm = GetJobSlotInfo(i);
        if (wm->mailType == MAIL_TYPE_TAKEN_JOB && gDungeon->unk644.dungeonLocation.id == wm->unk4.dungeon.id && wm->missionType == WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT) {
            CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[3], wm->targetSpecies);
            break;
        }
    }
}

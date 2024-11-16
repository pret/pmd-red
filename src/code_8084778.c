#include "global.h"
#include "code_8084778.h"
#include "string_format.h"
#include "code_80958E8.h"
#include "mailbox.h"
#include "pokemon_mid.h"
#include "structs/str_dungeon.h"

extern const u8 gUnknown_8107224[];

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

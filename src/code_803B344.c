#include "global.h"
#include "globaldata.h"
#include "structs/str_802C39C.h"
#include "code_803C1D0.h"
#include "code_80958E8.h"
#include "pokemon_mail.h"

static s32 sub_803B600(WonderMail *);
extern s32 sub_803B628(WonderMail *);
extern s32 sub_803B66C(WonderMail *);


NAKED
unkStruct_803B344 *sub_803B344(u8 r0)
{
    asm_unified(
	"\tadds r1, r0, 0\n"
	"\tlsls r1, 24\n"
	"\tlsrs r1, 24\n"
	"\tlsls r0, r1, 3\n"
	"\tsubs r0, r1\n"
	"\tlsls r0, 2\n"
	"\tldr r1, _0803B358\n"
	"\tadds r0, r1\n"
	"\tbx lr\n"
	"\t.align 2, 0\n"
"_0803B358: .4byte gUnknown_80E7F94");
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


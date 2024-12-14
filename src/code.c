#include "global.h"
#include "structs/str_dungeon_8042F6C.h"
#include "structs/str_wonder_mail.h"
#include "code_80118A4.h"
#include "code_80A26CC.h"
#include "code_8099360.h"
#include "event_flag.h"
#include "items.h"
#include "memory.h"
#include "pokemon.h"
#include "quick_save_read.h"
#include "quick_save_write.h"
#include "random.h"
#include "save.h"
#include "string_format.h"
#include "text_util.h"

extern void NDS_LoadOverlay_GroundMain();
extern u32 xxx_script_related_8098468(u32);
extern u8 sub_80992E0(s16 *, s16 *);
extern bool8 sub_8099328(u8 *dungeonId);
extern bool8 sub_8099360(u8 *);
extern u8 sub_8099394(u8 *);
extern void GeneratePelipperJobs();
extern void sub_8043D50(s32 *a0, s32 *a1);
extern void xxx_update_stuff(u32);
extern void sub_80961B4();
extern void sub_808ED00();
extern void SetDungeonLocationInfo(DungeonLocation *dl);
extern void sub_808CE74(s16, bool32, u8*);

void xxx_dungeon_8001340(struct UnkStruct_xxx_dungeon_8042F6C *r0);
void sub_80011E8(u8 *param_1);
void sub_809542C(WonderMailSub *param_1);

struct unkTalkTable
{
    u32 unk0;
    s16 species;
};

extern struct unkTalkTable gTalkKindTable[];
extern struct unkTalkTable gBaseKindTable[];

// size: 0x30
struct PersonalityRelated
{
    u8 fill0[4];
    s16 speciesID1;
    s16 speciesID2;
    u8 speciesName1[0x14];
    u8 speciesName2[0x14];
};
struct PersonalityRelated gPersonalityRelated_203B040;
extern u32 gUnknown_203B03C;

void SaveLoadRelated_8000EDC(struct UnkStruct_xxx_dungeon_8042F6C *param_1)
{
    u8 quickSaveValid;
    s32 quickSaveStatus;
    s32 local_1c; // 0x4800
    s32 local_18; // sizeof(Dungeon)

    quickSaveValid = TRUE;
    gUnknown_203B03C = 1;
    sub_800A8F8(3);
    sub_8014144();
    sub_8043D50(&local_1c,&local_18);
    param_1->unk74 =  MemoryAlloc(local_1c,7); // size: 0x4800
    param_1->unk78 = MemoryAlloc(local_18,7); // size: sizeof(Dungeon)
    if (param_1->unk8) {
        PrepareQuickSaveRead(param_1->unk74,local_1c);
        while( TRUE ) {
            if (!ReadQuickSave()) break;
            xxx_update_stuff(0);
        }
        quickSaveValid = IsQuickSaveValid();
        FinishQuickSaveRead();
        sub_8011830();
        if (quickSaveValid) {
            sub_80121E0(0xf1208);
        }
        else {
            sub_80121E0(0xf1209);
        }
        xxx_call_start_bg_music();
    }
    else {
        GeneratePelipperJobs();
        sub_80961B4();
        sub_808ED00();
    }
    if (quickSaveValid) {
        xxx_dungeon_8001340(param_1);
        sub_8099648();
        SetWindowBGColor();
        sub_8099690(0);
    }
    else {
        param_1->unk7C = 5;
    }
    if (param_1->unk7C == -2) {
        sub_809542C(&param_1->unk84);
    }
    if ((param_1->unk7C == 3) || (param_1->unk7C == -2)) {
        SetDungeonLocationInfo(&param_1->unk80);
        xxx_call_stop_bgm();
        if (param_1->unk7C == -2) {
            PrepareQuickSaveWrite(param_1->unk74,local_1c,1);
        }
        else {
            PrepareQuickSaveWrite(param_1->unk74,local_1c,0);
        }
        while ((quickSaveStatus = WriteQuickSave(), (quickSaveStatus != 2))) {
            if (quickSaveStatus == 3) break;
            if (quickSaveStatus == 1) {
                MemoryFree(param_1->unk78);
                MemoryFree(param_1->unk74);
            }
            xxx_update_stuff(0);
        }
        FinishQuickSaveWrite();
    }
    else {
        sub_808ED00();
        MemoryFree(param_1->unk78);
        MemoryFree(param_1->unk74);
    }
}

void sub_8001024(struct PersonalityRelated *r0)
{
    *r0 = gPersonalityRelated_203B040;
}

void sub_8001044(struct PersonalityRelated *r0)
{
    gPersonalityRelated_203B040 = *r0;
}

void sub_8001064(void)
{
    struct unkTalkTable *psVar2;
    u8 buffer2 [20];
    u8 buffer1 [20];

    if (GetPlayerPokemonStruct() == NULL) {
        if (gPersonalityRelated_203B040.speciesName1[0] == '\0') {
            CopyMonsterNameToBuffer(buffer1,gPersonalityRelated_203B040.speciesID1);
            CopyStringtoBuffer(buffer2,buffer1);
            sub_808CE74(gPersonalityRelated_203B040.speciesID1,TRUE,buffer2);
        }
        else {
            sub_808CE74(gPersonalityRelated_203B040.speciesID1,TRUE,gPersonalityRelated_203B040.speciesName1);
        }
    }
    if (sub_808D378() == NULL) {
        if (gPersonalityRelated_203B040.speciesName2[0] == '\0') {
            CopyMonsterNameToBuffer(buffer1,gPersonalityRelated_203B040.speciesID2);
            CopyStringtoBuffer(buffer2,buffer1);
            sub_808CE74(gPersonalityRelated_203B040.speciesID2,FALSE,buffer2);
        }
        else {
            sub_808CE74(gPersonalityRelated_203B040.speciesID2,FALSE,gPersonalityRelated_203B040.speciesName2);
        }
    }
    if (gPersonalityRelated_203B040.speciesID1 != MONSTER_NONE) {
        psVar2 = &gBaseKindTable[0];
        while ((psVar2->species != MONSTER_NONE && (gPersonalityRelated_203B040.speciesID1 != psVar2->species))) {
            psVar2++;
        }
        SetScriptVarValue(NULL,BASE_KIND,psVar2->unk0);
    }
    if (gPersonalityRelated_203B040.speciesID2 != MONSTER_NONE) {
        psVar2 = &gTalkKindTable[0];
        while ((psVar2->species != MONSTER_NONE && (gPersonalityRelated_203B040.speciesID2 != psVar2->species))) {
            psVar2++;
        }
        SetScriptVarValue(NULL,PARTNER_TALK_KIND,psVar2->unk0);
    }
}

u8 sub_8001170(void)
{
    s16 local_10;
    s16 auStack_e;
    u8 dungeonID;
    u8 auStack_b;

    dungeonID = 0x63;
    if (sub_80992E0(&local_10,&auStack_e) != 0) {
        dungeonID = sub_80A2740(local_10);
    }
    else {
        if (!sub_8099328(&dungeonID) && (!sub_8099360(&dungeonID) && sub_8099394(&auStack_b) != 0)) {
            dungeonID = 0x3F;
        }
    }
    return dungeonID;
}

void sub_80011CC(u8 *param_1,u8 param_2)
{
    u32 zero = 0;
    param_1[0] = param_2;
    param_1[1] = zero;
    sub_80011E8(param_1);
    param_1[0xb] = 0;
    param_1[4] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
}

void sub_80011E8(u8 *param_1)
{
    param_1[5] = sub_80023E4(8);
    param_1[6] = sub_80023E4(3);
    param_1[8] = sub_80023E4(7);
    param_1[9] = sub_80023E4(0);
    param_1[10] = sub_80023E4(5);
    if (sub_80023E4(0x18) && sub_80023E4(0x19) && sub_80023E4(0x1a)) {
        param_1[7] = 1;
    }
    else {
        param_1[7] = 0;
    }
}

void sub_8001248(void)
{
    s32 index;
    s32 counter;

    for(index = 0; index < INVENTORY_SIZE; index++)
    {
        counter = RandInt(100);
        if(counter < 50)
            ZeroOutItem(&gTeamInventoryRef->teamItems[index]);
    }
    FillInventoryGaps();
    for(index = 0; index < NUM_MONSTERS; index++)
    {
        PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[index];
        if(PokemonFlag1(mon) && PokemonFlag2(mon))
            mon->heldItem.id = ITEM_NOTHING;
    }
    gTeamInventoryRef->teamMoney = 0;
}

void sub_80012C0(void)
{
    s32 index;

    for(index = 0; index < INVENTORY_SIZE; index++)
    {
        ZeroOutItem(&gTeamInventoryRef->teamItems[index]);
    }
    FillInventoryGaps();
    for(index = 0; index < NUM_MONSTERS; index++)
    {
        PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[index];
        if(PokemonFlag1(mon) && PokemonFlag2(mon))
            mon->heldItem.id = ITEM_NOTHING;
    }
    gTeamInventoryRef->teamMoney = 0;
}

void NDS_LoadOverlay_GroundMain()
{

}

void nullsub_2(struct UnkStruct_xxx_dungeon_8042F6C *r0)
{

}

u32 xxx_script_related_8001334(u32 r0)
{
    return xxx_script_related_8098468(r0);
}

void xxx_dungeon_8001340(struct UnkStruct_xxx_dungeon_8042F6C *r0)
{
    nullsub_2(r0);
    xxx_dungeon_8042F6C(r0);
    NDS_LoadOverlay_GroundMain();
}

void nullsub_3(s32 a0, s32 a1)
{

}

/////////////////////////////////
/// TODO merge with event_flag
/////////////////////////////////

extern void sub_80972F4(void);
extern void nullsub_128(void);

void ThoroughlyResetScriptVars(void)
{
  s32 iVar1;
  s32 iVar3;
  u16 uVar2;
  struct ScriptVarInfo *puVar1;
  
  for(iVar3 = 0; iVar3 < 0x400; iVar3++)
  {
    gScriptVarBuffer[iVar3] = 0;
  }

  for(iVar1 = 0; iVar1 < 0x51; iVar1 = (iVar1 + 1) * 0x10000 >> 0x10)
  {
    puVar1 = &gScriptVarInfo[iVar1];
    if (((puVar1->type != 0) && ((puVar1->type != 8)))) {
      for (uVar2 = 0; uVar2 < puVar1->arrayLen; uVar2++) {
        SetScriptVarArrayValue(NULL, iVar1, uVar2, puVar1->defaultValue);
      }
    }
  }
  ClearScriptVarArray(NULL, CONDITION);
  ScenarioCalc(SCENARIO_SELECT,0,0);
  ScenarioCalc(SCENARIO_MAIN,0,0);
  ScenarioCalc(SCENARIO_SUB1,0,0);
  ScenarioCalc(SCENARIO_SUB2,0,0);
  ScenarioCalc(SCENARIO_SUB3,0,0);
  ScenarioCalc(SCENARIO_SUB4,0,0);
  ScenarioCalc(SCENARIO_SUB5,0,0);
  ScenarioCalc(SCENARIO_SUB6,0,0);
  ScenarioCalc(SCENARIO_SUB7,0,0);
  ScenarioCalc(SCENARIO_SUB8,0,0);
  ScenarioCalc(SCENARIO_SUB9,0,0);
  SetScriptVarValue(NULL,GROUND_ENTER,0xa2);
  SetScriptVarValue(NULL,GROUND_ENTER_LINK,0);
  SetScriptVarValue(NULL,GROUND_GETOUT,0xa2);
  SetScriptVarValue(NULL,GROUND_MAP,-1);
  SetScriptVarValue(NULL,GROUND_PLACE,0x24);
  SetScriptVarValue(NULL,DUNGEON_SELECT,-1);
  SetScriptVarValue(NULL,DUNGEON_ENTER,0);
  SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX,-1);
  SetScriptVarValue(NULL,DUNGEON_RESULT,0);
  SetScriptVarValue(NULL,START_MODE,0);
  SetScriptVarValue(NULL,CLEAR_COUNT,0);
  SetScriptVarValue(NULL,WEATHER_KIND,-1);
  SetScriptVarValue(NULL,PLAYER_KIND,0);
  SetScriptVarValue(NULL,PARTNER1_KIND,0);
  SetScriptVarValue(NULL,PARTNER2_KIND,0);
  SetScriptVarValue(NULL,NEW_FRIEND_KIND,0);
  ClearScriptVarArray(NULL,WARP_LIST);
  SetScriptVarValue(NULL,WARP_LOCK,0);
  SetScriptVarValue(NULL,PARTNER_TALK_KIND,0);
  SetScriptVarValue(NULL,BASE_KIND,0);
  SetScriptVarValue(NULL,BASE_LEVEL,0);
  SetScriptVarValue(NULL,FLAG_KIND,0);
  SetScriptVarValue(NULL,FLAG_KIND_CHANGE_REQUEST,0);
  ClearScriptVarArray(NULL,RESCUE_SCENARIO_ORDER_LIST);
  ClearScriptVarArray(NULL,RESCUE_SCENARIO_JOB_LIST);
  ClearScriptVarArray(NULL,RESCUE_SCENARIO_CONQUEST_LIST);
  ClearScriptVarArray(NULL,TRAINING_CONQUEST_LIST);
  ClearScriptVarArray(NULL,TRAINING_PRESENT_LIST);
  ClearScriptVarArray(NULL,DUNGEON_ENTER_LIST);
  ClearScriptVarArray(NULL,DUNGEON_CLEAR_LIST);
  ClearScriptVarArray(NULL,EVENT_S08E01);
  sub_80972F4();
}

void sub_8001564(void)
{
    nullsub_128();
}

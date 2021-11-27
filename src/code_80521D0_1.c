#include "global.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "friend_area.h"
#include "constants/friend_area.h"
#include "pokemon.h"
#include "constants/direction.h"
#include "map.h"

extern struct DungeonEntity *xxx_call_GetLeaderEntity(void);
extern struct DungeonEntity *sub_8085680(u32);
extern char gUnknown_202E038[0x50];
extern struct DungeonGlobalData *gDungeonGlobalData;
extern u32 gUnknown_202EDC8;

extern u32 gUnknown_81062A8;
extern u32 gUnknown_8106074;
extern u32 gUnknown_81060BC;
extern u32 gUnknown_8106104;
extern u32 gUnknown_8106140;
extern u32 gUnknown_8106214;
extern u32 gUnknown_8106244;
extern u32 gUnknown_810627C;
extern u32 gUnknown_810697C;
extern u64 gUnknown_8107544[];
extern u32 gUnknown_8106778;
extern u32 gUnknown_81067BC;
extern u32 gUnknown_81067E0;
extern u32 gUnknown_8106834;
extern u32 gUnknown_810688C;
extern u32 gUnknown_81068D0;
extern u32 gUnknown_8106918;
extern u32 gUnknown_8106934;
extern u32 gUnknown_8106720;

extern u32 gUnknown_810663C;
extern u32 gUnknown_81063D0;
extern u32 gUnknown_8106400;
extern u32 gUnknown_810643C;
extern u32 gUnknown_8106468;
extern u32 gUnknown_810648C;
extern u32 gUnknown_81064BC;
extern u32 gUnknown_8106500;
extern u32 gUnknown_8106534;
extern u32 gUnknown_8106560;
extern u32 *gPtrPurityForestAllowCelebiToJoinText;
extern u32 gPurityForestAllowCelebiToJoinPrompt;
extern u32 *gPtrPurityForestRefuseCelebiConfirmText;
extern u32 gPurityForestRefuseCelebiConfirmPrompt;
extern u32 gUnknown_81062B4;
extern u32 gUnknown_81062E8;
extern u32 gUnknown_8106368;
extern u32 gUnknown_8106390;
extern u32 gUnknown_81063C4;
extern u32 gUnknown_8106068;
extern u32 gUnknown_8105E88;
extern u32 gUnknown_8105EF8;
extern u32 gUnknown_8105F38;
extern u32 gUnknown_8105F74;
extern u32 gUnknown_8105FA0;
extern u32 gUnknown_8105FD8;
extern u32 gUnknown_8106024;

extern u32 gUnknown_81058C4;
extern u32 gUnknown_81058A8;
extern u8 sub_800E9A8(u32);
extern void sub_800DC14(u32);
extern void sub_808BAA4();

extern void sub_8086A3C(struct DungeonEntity *r0);
extern void sub_8083E88(u32);
extern void sub_80854D4(void);
extern void sub_80855E4(void *);
extern void sub_8085930(u32);
extern void sub_8068FE0(struct DungeonEntity *, u32, u32);
extern void sub_8085860(s16 r0, u32 r1);
extern void sub_80866C4(u32 *);
extern void sub_8083EA8(u32, u32);
extern void sub_8086448();
extern void sub_80866C4(u32 *r0);

extern void sub_803E708(u32, u32);
extern void sub_8086448(void);
extern void sub_8086598(void);
extern void SpriteLookAroundEffect(struct DungeonEntity *);
extern void sub_80862BC(struct DungeonEntity *);
extern void PlaySoundEffect(u32);
extern void sub_806CDD4(struct DungeonEntity *, u32, u32);
extern void sub_80869E4(struct DungeonEntity *, u32, u32, u32);
extern void sub_806CE68(struct DungeonEntity *, u32);
extern void sub_804539C(struct DungeonEntity *, u32, u32);
extern void sub_803E46C(u32);
extern void sub_8042B0C(struct DungeonEntity *);
extern void SetFacingDirection(struct DungeonEntity *, u32);
extern void DisplayDungeonDialogue(u32 *);
extern void sub_803E708(u32, u32);
extern u8 EntityExists(struct DungeonEntity *);
extern u8 HasRecruitedMon(u32);
extern u8 sub_806FD18(struct DungeonEntity *);
extern u8 sub_8083E74(u32);
extern s32 sub_8052C68(u32 *, u32 *, u32 *, u32);
extern void sub_8083F14();
extern void sub_80861D4(struct DungeonEntity *, u32, u32);
extern void sub_806FDF4(struct DungeonEntity *, struct DungeonEntity *, struct DungeonEntity **);
extern u32 sub_80861F8(u32, struct DungeonEntity *, u32);
extern void sub_8083ED8(u32);
extern u32 sub_803F994();
extern s32 sub_803F9B0();
extern void sub_803F878(u32, s32);
extern void SetupBossFightHP(struct DungeonEntity *, u32, u32);
extern void sub_8085C54(u32, u32, u32, u32, u32);
extern void sub_803E9D0(void);
extern void DeoxysScreenFlash(void);
extern void sub_8085EB0();
extern void sub_808563C(void *);
extern void sub_80858AC(u32 *, u32);

void SetupDeoxysFightHP(struct DungeonEntity *r0);
void sub_808C550(void);
void sub_808C590(struct DungeonEntity *r0);
void SetupDeoxysFacingDirection(struct DungeonEntity *r0);
void sub_808C9B0();
void sub_808C8E0(struct DungeonEntity *param_1);
void sub_808C360(void);
void KyogreScreenFlash();

void sub_808C0CC();
void sub_808BFA0();
void sub_808C02C();
extern void sub_80861B8(struct DungeonEntity *, u32, u32);

void nullsub_99();
extern u32 DungeonRandomCapped(s32);
extern bool8 *gFriendAreas;

extern void sub_8049884();
extern void sub_8049B8C();
extern void sub_8049ED4();
extern void sub_8040A84();
extern void sub_8086A54(struct DungeonEntity *);

extern struct MapTile *GetMapEntity(u32, u32);
extern void sub_806BFC0(struct DungeonEntityData *, u32);

void sub_808BBA8(struct DungeonEntity *param_1)
{
  sub_806BFC0(param_1->entityData,0);
}

void sub_808BBB8(struct DungeonEntity *param_1)
{
  s32 iVar1;
  s32 iVar2;

  sub_80861F8(0x1b,param_1,0);
  sub_8086A54(param_1);
  sub_80861B8(param_1,0xe,0);
  iVar1 = 0xa000;
  iVar2 = 0x200;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar1 = iVar1 - iVar2;
    if (iVar1 < 0x1800) {
      iVar2 = 0x100;
    }
    if (iVar1 < 0) break;
    param_1->entityData->unk174 = iVar1;
    sub_803E46C(0x46);
  }
 param_1->entityData->unk174 = 0;
}

void sub_808BC20(struct DungeonEntity * param_1)
{
  s32 uVar1;

  PlaySoundEffect(0x298);
  for(uVar1 = 0; uVar1 < 0x19; uVar1++){
    SetFacingDirection(param_1,uVar1 & DIRECTION_MASK);
    sub_803E708(3,0x46);
  }
  param_1->entityData->unk15E = 1;
  PlaySoundEffect(0x27f);
  sub_80861F8(99,param_1,1);
}

void JirachiWishGrantDialogue(struct DungeonEntity *param_1)
{
  u32 uVar2;

  param_1->entityData->unk15D = 1;
  // Nnnnnnnnnn!
  DisplayDungeonDialogue(&gUnknown_81058A8);
  PlaySoundEffect(0x375);
  sub_80861F8(0x67,param_1,1);
  PlaySoundEffect(0x2a8);
  uVar2 = sub_80861F8(0x68,param_1,0);
  // Taaaaaaaah!
  DisplayDungeonDialogue(&gUnknown_81058C4);
  if (sub_800E9A8(uVar2) != 0) {
    sub_800DC14(uVar2);
  }
  sub_803E708(10,0x46);
  sub_808BAA4();
}

void sub_808BCE4(void)
{
  struct MapTile *puVar1;

  puVar1 = GetMapEntity(gDungeonGlobalData->unkE23C, gDungeonGlobalData->unkE23E);
  puVar1->MapTileUnion.tileFlags_u16 &= 0xfffc;
  puVar1->MapTileUnion.tileFlags_u16 |= TILE_TYPE_MAP_EDGE;
  puVar1->MapTileUnion.tileFlags_u16 &= 0xfdff;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  sub_8040A84();
}

void sub_808BD38(void)
{
  struct MapTile *puVar1;

  puVar1 = GetMapEntity(gDungeonGlobalData->unkE23C, gDungeonGlobalData->unkE23E);
  puVar1->MapTileUnion.tileFlags_u16 &= 0xfffc;
  puVar1->MapTileUnion.tileFlags_u16 |= TILE_TYPE_FLOOR;
  puVar1->MapTileUnion.tileFlags_u16 &= 0xffef;
  puVar1->MapTileUnion.tileFlags_u16 |= TILE_TYPE_STAIRS;
  puVar1->unk8 = 1;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  sub_8040A84();
}

u8 JirachiFriendAreaSearch(void)
{
  u8 unlockCondition;
  s32 friendAreaCounter;
  s32 numUnlockableAreas;
  u8 friendAreas[NUM_FRIEND_AREAS];
  u32 friendAreaIndex;

  // Build a copy of friend area list and keep track of
  // how many are only Story Unlockable
  numUnlockableAreas = 0;
  for(friendAreaCounter = 1; friendAreaCounter < NUM_FRIEND_AREAS; friendAreaCounter++){
    unlockCondition = GetFriendAreaUnlockCondition(friendAreaCounter);
    if (!(unlockCondition == UNLOCK_LEGENDARY_REQUEST)){
        if (!(unlockCondition == UNLOCK_WONDER_MAIL)){
            if(!gFriendAreas[friendAreaCounter]) {
                friendAreas[numUnlockableAreas] = friendAreaCounter;
                numUnlockableAreas++;
            }
        }
    }
  }

  if (numUnlockableAreas == 0) {
    return NUM_FRIEND_AREAS;
  }
  else {
      // Randomly pick 1
    friendAreaIndex = DungeonRandomCapped(numUnlockableAreas);
    return friendAreas[friendAreaIndex];
  }
}

void sub_808BDEC(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * LugiaEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  LugiaEntity = sub_8085680(0x1b);
  sub_8083F14();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(SPECIES_LUGIA)) {
    sub_8083E88(0x23);
    sub_8068FE0(LugiaEntity,0x21c,0);
  }
  else {
    gDungeonGlobalData->unk7 = 1;
    SetFacingDirection(LugiaEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->posWorldX,LeaderEntity->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LUGIA);
}

void sub_808BE70(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x33) && (param_1 == 0x1B)) {
    gDungeonGlobalData->unk2 = 1;
  }
}


void LugiaPreFightDialogue(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * LugiaEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  LugiaEntity = sub_8085680(0x1b);
  if (HasRecruitedMon(SPECIES_LUGIA)) {
    sub_8086448();
    sub_80866C4(&gUnknown_8106068);
  }
  else {
    sub_8083F14();
    sub_8086448();
    DisplayDungeonDialogue(&gUnknown_8105E88);
    sub_8083EA8(0x23,0x3c);
    sub_808C0CC();
    DisplayDungeonDialogue(&gUnknown_8105EF8);
    sub_808BFA0();
    DisplayDungeonDialogue(&gUnknown_8105F38);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gUnknown_8105F74);
    PlaySoundEffect(0x1f8);
    sub_80861D4(LugiaEntity,0xd,0);
    sub_803E708(0x2b,0x46);
    sub_80861B8(LugiaEntity,0,0);
    DisplayDungeonDialogue(&gUnknown_8105FA0);
    sub_808BFA0();
    DisplayDungeonDialogue(&gUnknown_8105FD8);
    sub_808C02C();
    sub_8085C54(0xffffff06,0xffffff06,0xffffff06,1,0);
    sub_8083F14();
    sub_80861D4(LugiaEntity,7,0);
    DisplayDungeonDialogue(&gUnknown_8106024);
    sub_808BFA0();
    SetupBossFightHP(LugiaEntity,800,0x20);
    sub_8083E88(0x23);
    sub_80858AC(&LeaderEntity->posPixelX,0x10);
  }
}

void sub_808BFA0(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    sub_8085C54(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    sub_8085C54(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    sub_8085C54(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C02C(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    sub_8085C54(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    sub_8085C54(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(4,0x46);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    sub_8085C54(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    sub_8085C54(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C0CC(void)
{
  gUnknown_202EDC8 = 0x1f;
  sub_8085C54(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeonGlobalData->unk7 = 0;
  sub_808BFA0();
}

void sub_808C10C(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * KyogreEntity;

  u32 uVar3;
  s32 iVar2;

  LeaderEntity = xxx_call_GetLeaderEntity();
  KyogreEntity = sub_8085680(0x1c);
  sub_8083F14();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(SPECIES_KYOGRE)) {
    sub_8068FE0(KyogreEntity,0x21c,0);
  }
  else {
    gDungeonGlobalData->unk7 = 1;
    SetFacingDirection(KyogreEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->posWorldX,LeaderEntity->posWorldY);
  uVar3 = sub_803F994();
  iVar2 = sub_803F9B0();
  sub_803F878(uVar3,iVar2 + -0x1000);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_KYOGRE);
  // TODO: gUnknown_202E088 doesn't match but gUnknown_202E038 + 0x50 does
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_GROUDON);
}

void sub_808C1A4(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x34) && (param_1 == 0x1C)) {
    gDungeonGlobalData->unk2 = 1;
    sub_8083E88(0x23);
  }
}

void KyogrePreFightDialogue(void)
{
  struct DungeonEntity *LeaderEntity;
  struct DungeonEntity *KyogreEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  KyogreEntity = sub_8085680(0x1c);
  sub_8083F14();
  if (HasRecruitedMon(SPECIES_KYOGRE)) {
    sub_8083EA8(0x23,0x3c);
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gUnknown_81062A8);
    sub_803E708(10,0x46);
    gDungeonGlobalData->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gUnknown_8106074);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gUnknown_81060BC);
    sub_803E708(10,0x46);
    nullsub_99();
    sub_803E708(10,0x46);
    // Gwwwwwooooooooh
    DisplayDungeonDialogue(&gUnknown_8106104);
    sub_803E708(10,0x46);
    sub_8083EA8(0x23,0x3c);
    sub_808C360();
    // My duels against {ARG_POKEMON_3} (Groudon) left us both exhausted
    DisplayDungeonDialogue(&gUnknown_8106140);
    KyogreScreenFlash();
    // I am {ARG_POKEMON_2} (Kyogre)!
    // The lord of the sea!
    DisplayDungeonDialogue(&gUnknown_8106214);
    KyogreScreenFlash();
    // Witness the destructive force of my waves!
    DisplayDungeonDialogue(&gUnknown_8106244);
    KyogreScreenFlash();
    // Marvel at my awesome
    // power!
    DisplayDungeonDialogue(&gUnknown_810627C);
    sub_803E708(10,0x46);
    SetupBossFightHP(KyogreEntity,600,0xb);
    sub_8083E88(0x23);
    sub_80858AC(&LeaderEntity->posPixelX,0x10);
  }
}

void nullsub_99(void)
{
}

void KyogreScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f8);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    sub_8085C54(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    sub_8085C54(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    sub_8085C54(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C360(void)
{
  gUnknown_202EDC8 = 0x1f;
  sub_8085C54(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeonGlobalData->unk7 = 0;
  KyogreScreenFlash();
}

void sub_808C3A0(void)
{
  struct DungeonEntity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  sub_8083F14();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(SPECIES_DEOXYS_NORMAL)) {
    sub_808563C(sub_808C590);
  }
  else {
    gDungeonGlobalData->unk7 = 1;
    sub_808563C(SetupDeoxysFacingDirection);
  }
  sub_8085860(LeaderEntity->posWorldX,LeaderEntity->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_DEOXYS_NORMAL);
}

void sub_808C414(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x35) && (param_1 == 0x1D)) {
    gDungeonGlobalData->unk2 = 1;
    sub_8083E88(0x1a);
  }
}

void DeoxysPreFightDialogue(void)
{
  struct DungeonEntity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  sub_8086448();
  if (HasRecruitedMon(SPECIES_DEOXYS_NORMAL)) {
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gUnknown_81063C4);
  }
  else {
    DisplayDungeonDialogue(&gUnknown_81062B4);
    sub_8083EA8(0x1a,0x3c);
    sub_808C550();
    DisplayDungeonDialogue(&gUnknown_81062E8);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(&gUnknown_8106368);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(&gUnknown_8106390);
    sub_803E708(10,0x46);
    sub_808563C(SetupDeoxysFightHP);
    sub_80858AC(&LeaderEntity->posPixelX,0x10);
  }
}

void DeoxysScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    sub_8085C54(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    sub_8085C54(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    sub_8085C54(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C550(void)
{
  gUnknown_202EDC8 = 0x1f;
  sub_8085C54(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeonGlobalData->unk7 = 0;
  DeoxysScreenFlash();
}

void sub_808C590(struct DungeonEntity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void SetupDeoxysFacingDirection(struct DungeonEntity *r0)
{
    SetFacingDirection(r0, DIRECTION_SOUTH);
}

void SetupDeoxysFightHP(struct DungeonEntity *r0)
{
    SetupBossFightHP(r0, 950, 0x20);
}

void sub_808C5C0(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * CelebiEntity;

  u32 uVar3;
  s32 iVar2;

  LeaderEntity = xxx_call_GetLeaderEntity();
  CelebiEntity = sub_8085680(0x1e);
  sub_8083E88(0x7f);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(CelebiEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->posWorldX,LeaderEntity->posWorldY);
  uVar3 = sub_803F994();
  iVar2 = sub_803F9B0();
  sub_803F878(uVar3,iVar2 + 0xfffff000);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_CELEBI);
}

// Dummy Celebi Fight Dialogue??
void nullsub_100(u32 r0, u32 r1, u32 r2)
{
}

#ifdef NONMATCHING
void CelebiJoinDialogue(void)
{
  struct DungeonEntity *LeaderEntity;
  s32 state;
  s32 menuChoice;
  struct DungeonEntity *CelebiEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  CelebiEntity = sub_8085680(0x1e);
  if ((HasRecruitedMon(SPECIES_CELEBI)) || (sub_806FD18(CelebiEntity) == '\0'))
  {
    sub_8068FE0(local_1c,0x21c,0);
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    // .........
    DisplayDungeonDialogue(&gUnknown_810663C);
  }
  else
  {
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    sub_80862BC(LeaderEntity);
    sub_803E708(10,0x46);
    // Oh? There's someone there.
    DisplayDungeonDialogue(&gUnknown_81063D0);
    sub_803E708(10,0x46);
    sub_8086598();
    sub_8086598();
    sub_8086598();
    sub_8086598();
    // The Time-Traveling Pokemon {ARG_POKEMON_2} (Celebi)!
    DisplayDungeonDialogue(&gUnknown_8106400);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(CelebiEntity,10,DIRECTION_SOUTH);
    sub_803E708(0x14,0x46);
    sub_806CE68(CelebiEntity, DIRECTION_SOUTH);
    sub_803E708(4,0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(CelebiEntity,10,DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gUnknown_810643C);
    sub_803E708(10,0x46);
    state = 0;
    do {
      switch(state)
      {
       case 0:
            do {
                // NOTE: 0 and Load of ptr switch order in compiler but else matches
                menuChoice = sub_8052C68(0,gPtrPurityForestAllowCelebiToJoinText,
                                &gPurityForestAllowCelebiToJoinPrompt,0x701);
            } while (menuChoice < 1);
            sub_803E708(10,0x46);
            if (menuChoice == 1)
            {
                sub_8083F14();
                PlaySoundEffect(0xcc);
                while (sub_8083E74(0xcc) != 0) {
                    sub_803E46C(0x46);
                }
                sub_8083E88(0x7f);
                PlaySoundEffect(0x1c7);
                sub_80861D4(CelebiEntity,0xd,0);
                sub_803E708(0x37,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1a,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1c,0x46);
                DisplayDungeonDialogue(&gUnknown_8106468);
                sub_803E708(10,0x46);
                sub_806FDF4(LeaderEntity,CelebiEntity,&CelebiEntity);
                sub_8083E88(0x7f);
                DisplayDungeonDialogue(&gUnknown_810648C);
                sub_803E708(10,0x46);
                PlaySoundEffect(0x1c7);
                sub_80861D4(CelebiEntity,0xd,0);
                sub_803E708(0x37,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1a,0x46);
                PlaySoundEffect(0x1d5);
                sub_803E708(0x1b,0x46);
                DisplayDungeonDialogue(&gUnknown_81064BC);
                sub_803E708(10,0x46);
                state = 2;
            }
            else
            {
                state = 1;
            }
            break;
        case 1:
            do {
                // NOTE: 0 and Load of ptr switch order in compiler but else matches
                menuChoice = sub_8052C68(0,gPtrPurityForestRefuseCelebiConfirmText,
                                    &gPurityForestRefuseCelebiConfirmPrompt,0x701);
            } while (menuChoice < 1);
            if (menuChoice == 1)
                state = 0;
            else
            {
                sub_803E708(10,0x46);
                DisplayDungeonDialogue(&gUnknown_8106500);
                sub_80861F8(0x3e,CelebiEntity,1);
                sub_803E708(0x18,0x46);
                sub_80861F8(0x3e,CelebiEntity,1);
                sub_803E708(0xe,0x46);
                DisplayDungeonDialogue(&gUnknown_8106534);
                sub_803E708(10,0x46);
                sub_808C8E0(CelebiEntity);
                DisplayDungeonDialogue(&gUnknown_8106560);
                sub_803E708(10,0x46);
                state = 2;
            }
            break;
      }
    } while (state != 2);
  }
  sub_8083ED8(0x1e);
  sub_803E708(0x1e,0x46);
  gDungeonGlobalData->unk2 = 1;
}
#else
NAKED
void CelebiJoinDialogue(void)
{
        asm_unified(
        "\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tsub sp, 0x4\n"
	"\tbl xxx_call_GetLeaderEntity\n"
	"\tadds r7, r0, 0\n"
	"\tmovs r0, 0x1E\n"
	"\tbl sub_8085680\n"
	"\tstr r0, [sp]\n"
	"\tmovs r0, 0x8A\n"
	"\tlsls r0, 1\n"
	"\tbl HasRecruitedMon\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808C658\n"
	"\tldr r0, [sp]\n"
	"\tbl sub_806FD18\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808C680\n"
"_0808C658:\n"
	"\tmovs r1, 0x87\n"
	"\tlsls r1, 2\n"
	"\tldr r0, [sp]\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8068FE0\n"
	"\tadds r0, r7, 0\n"
	"\tbl SpriteLookAroundEffect\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C67C\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tb _0808C8AC\n"
	"\t.align 2, 0\n"
"_0808C67C: .4byte gUnknown_810663C\n"
"_0808C680:\n"
	"\tadds r0, r7, 0\n"
	"\tbl SpriteLookAroundEffect\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r7, 0\n"
	"\tbl sub_80862BC\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C71C\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tbl sub_8086598\n"
	"\tbl sub_8086598\n"
	"\tbl sub_8086598\n"
	"\tbl sub_8086598\n"
	"\tldr r0, _0808C720\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tldr r4, _0808C724\n"
	"\tadds r0, r4, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xA\n"
	"\tmovs r2, 0\n"
	"\tbl sub_806CDD4\n"
	"\tmovs r0, 0x14\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0\n"
	"\tbl sub_806CE68\n"
	"\tmovs r0, 0x4\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r4, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xA\n"
	"\tmovs r2, 0\n"
	"\tbl sub_806CDD4\n"
	"\tldr r0, _0808C728\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r0, 0\n"
	"\tmov r8, r4\n"
	"\tldr r6, _0808C72C\n"
"_0808C70E:\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808C730\n"
	"\tcmp r0, 0x1\n"
	"\tbne _0808C718\n"
	"\tb _0808C828\n"
"_0808C718:\n"
	"\tb _0808C8A6\n"
	"\t.align 2, 0\n"
"_0808C71C: .4byte gUnknown_81063D0\n"
"_0808C720: .4byte gUnknown_8106400\n"
"_0808C724: .4byte 0x000001c7\n"
"_0808C728: .4byte gUnknown_810643C\n"
"_0808C72C: .4byte 0x000001d5\n"
"_0808C730:\n"
	"\tldr r5, _0808C75C\n"
"_0808C732:\n"
	"\tmovs r0, 0\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _0808C760\n"
	"\tldr r3, _0808C764\n"
	"\tbl sub_8052C68\n"
	"\tadds r4, r0, 0\n"
	"\tcmp r4, 0\n"
	"\tble _0808C732\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tcmp r4, 0x1\n"
	"\tbne _0808C824\n"
	"\tbl sub_8083F14\n"
	"\tmovs r0, 0xCC\n"
	"\tbl PlaySoundEffect\n"
	"\tb _0808C76E\n"
	"\t.align 2, 0\n"
"_0808C75C: .4byte gPtrPurityForestAllowCelebiToJoinText\n"
"_0808C760: .4byte gPurityForestAllowCelebiToJoinPrompt\n"
"_0808C764: .4byte 0x00000701\n"
"_0808C768:\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
"_0808C76E:\n"
	"\tmovs r0, 0xCC\n"
	"\tbl sub_8083E74\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808C768\n"
	"\tmovs r0, 0x7F\n"
	"\tbl sub_8083E88\n"
	"\tmov r0, r8\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xD\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80861D4\n"
	"\tmovs r0, 0x37\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1A\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1C\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C818\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r1, [sp]\n"
	"\tadds r0, r7, 0\n"
	"\tmov r2, sp\n"
	"\tbl sub_806FDF4\n"
	"\tmovs r0, 0x7F\n"
	"\tbl sub_8083E88\n"
	"\tldr r0, _0808C81C\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmov r0, r8\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, [sp]\n"
	"\tmovs r1, 0xD\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80861D4\n"
	"\tmovs r0, 0x37\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1A\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tadds r0, r6, 0\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r0, 0x1B\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C820\n"
	"\tb _0808C898\n"
	"\t.align 2, 0\n"
"_0808C818: .4byte gUnknown_8106468\n"
"_0808C81C: .4byte gUnknown_810648C\n"
"_0808C820: .4byte gUnknown_81064BC\n"
"_0808C824:\n"
	"movs r0, 0x1\n"
	"b _0808C8A6\n"
"_0808C828:\n"
	"\tldr r5, _0808C844\n"
"_0808C82A:\n"
	"\tmovs r0, 0\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _0808C848\n"
	"\tldr r3, _0808C84C\n"
	"\tbl sub_8052C68\n"
	"\tadds r4, r0, 0\n"
	"\tcmp r4, 0\n"
	"\tble _0808C82A\n"
	"\tcmp r4, 0x1\n"
	"\tbne _0808C850\n"
	"\tmovs r0, 0\n"
	"\tb _0808C8A6\n"
	"\t.align 2, 0\n"
"_0808C844: .4byte gPtrPurityForestRefuseCelebiConfirmText\n"
"_0808C848: .4byte gPurityForestRefuseCelebiConfirmPrompt\n"
"_0808C84C: .4byte 0x00000701\n"
"_0808C850:\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C8D0\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tldr r1, [sp]\n"
	"\tmovs r0, 0x3E\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_80861F8\n"
	"\tmovs r0, 0x18\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r1, [sp]\n"
	"\tmovs r0, 0x3E\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_80861F8\n"
	"\tmovs r0, 0xE\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C8D4\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, [sp]\n"
	"\tbl sub_808C8E0\n"
	"\tldr r0, _0808C8D8\n"
"_0808C898:\n"
	"\tbl DisplayDungeonDialogue\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r0, 0x2\n"
"_0808C8A6:\n"
	"\tcmp r0, 0x2\n"
	"\tbeq _0808C8AC\n"
	"\tb _0808C70E\n"
"_0808C8AC:\n"
	"\tmovs r0, 0x1E\n"
	"\tbl sub_8083ED8\n"
	"\tmovs r0, 0x1E\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _0808C8DC\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tadd sp, 0x4\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808C8D0: .4byte gUnknown_8106500\n"
"_0808C8D4: .4byte gUnknown_8106534\n"
"_0808C8D8: .4byte gUnknown_8106560\n"
"_0808C8DC: .4byte gDungeonGlobalData");
}
#endif

void sub_808C8E0(struct DungeonEntity *param_1)
{
  s32 iVar1;

  PlaySoundEffect(0x1a5);
  sub_806CDD4(param_1, 0, DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 16; iVar1++){
    param_1->entityData->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  for(iVar1 = 16; iVar1 < 200; iVar1 += 4){
    param_1->entityData->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  sub_8086A3C(param_1);
}

void sub_808C938(void)
{
    sub_80855E4(sub_808C9B0);
}

void sub_808C948(struct DungeonEntity *param_1, u8 param_2)
{
  bool8 flag;
  s32 iVar3;
  struct DungeonEntity *iVar2;

  if (param_2 == 0x37) {
    flag = FALSE;
    for(iVar3 = 0; iVar3 < DUNGEON_MAX_WILD_POKEMON; iVar3++){
      iVar2 = gDungeonGlobalData->wildPokemon[iVar3];
      if ((iVar2 != param_1) && (EntityExists(iVar2) != 0)) {
        flag = TRUE;
        break;
      }
    }
    if (!flag) {
      gDungeonGlobalData->unk2 = 1;
    }
  }
}

void sub_808C998(void)
{
    // Defeat the opposing team to win
    // Be careful, your opponents are tough
    DisplayDungeonDialogue(&gUnknown_8106720);
    sub_803E708(0xA, 0x46);
}

void sub_808C9B0(struct DungeonEntity *param_1)
{
    param_1->entityData->facingDir = DIRECTION_NORTH;
    sub_806CE68(param_1, DIRECTION_NORTH);
}

void sub_808C9C4(void)
{
    struct DungeonEntity *LeaderEntity;
    struct DungeonEntity *MedichamEntity;

    LeaderEntity = xxx_call_GetLeaderEntity();
    MedichamEntity = sub_8085680(7);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(MedichamEntity, DIRECTION_SOUTH);
    sub_8085860(LeaderEntity->posWorldX, LeaderEntity->posWorldY - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MEDICHAM);
}

// Medicham Rescue Dialogue?
void MedichamRescueDialogue(void)
{
    struct DungeonEntity *MedichamEntity;
    s32 counter;

    MedichamEntity = sub_8085680(7);
    SpriteLookAroundEffect(MedichamEntity);
    sub_803E708(0xA, 0x46);
    // Oh my I can't seem to find a way out...
    DisplayDungeonDialogue(&gUnknown_8106778);
    sub_803E708(0xA, 0x46);
    sub_80869E4(MedichamEntity, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // What am I to do...?
    DisplayDungeonDialogue(&gUnknown_81067BC);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    sub_80862BC(MedichamEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(MedichamEntity, 4, 2, 0);
    DisplayDungeonDialogue(&gUnknown_81067E0);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(MedichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(MedichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(MedichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Yes Yes
    // I am so lucky
    //
    // There appears to be no one here
    DisplayDungeonDialogue(&gUnknown_8106834);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(MedichamEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(MedichamEntity, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(MedichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(MedichamEntity);
    sub_8068FE0(MedichamEntity, 0x21C, 0);
    gDungeonGlobalData->unk4 = 1;
    gDungeonGlobalData->unk11 = 4;
}

void sub_808CB5C(void)
{
    struct DungeonEntity *LeaderEntity;
    struct DungeonEntity *MedichamEntity;

    LeaderEntity = xxx_call_GetLeaderEntity();
    MedichamEntity = sub_8085680(7);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_8068FE0(MedichamEntity, 0x21C, 0);
    sub_8085860(LeaderEntity->posWorldX, LeaderEntity->posWorldY);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MEDICHAM);
}

void DummyFightDialogue(void)
{
}

void sub_808CBB0(void)
{
    struct DungeonEntity *LeaderEntity;
    struct DungeonEntity *SmeargleEntity;

    LeaderEntity = xxx_call_GetLeaderEntity();
    SmeargleEntity = sub_8085680(0x1F);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(SmeargleEntity, DIRECTION_SOUTH);
    sub_8085860(LeaderEntity->posWorldX, LeaderEntity->posWorldY - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SMEARGLE);
}

// Smeargle Rescue dialogue scene
void SmeargleRescueDialogue(void)
{
    struct DungeonEntity *SmeargleEntity;
    s32 counter;

    SmeargleEntity = sub_8085680(0x1F);
    SpriteLookAroundEffect(SmeargleEntity);
    sub_803E708(0xA, 0x46);
    // Ohhh...
    // I've lost my bearings
    DisplayDungeonDialogue(&gUnknown_810688C);
    sub_803E708(0xA, 0x46);
    sub_80869E4(SmeargleEntity, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // I can't get out...
    // I'm hungry...
    // I'm in trouble
    DisplayDungeonDialogue(&gUnknown_81068D0);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    sub_80862BC(SmeargleEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(SmeargleEntity, 4, 2, 0);
    // Oh! You are?
    DisplayDungeonDialogue(&gUnknown_8106918);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(SmeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(SmeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(SmeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Did you maybe come to rescue me?
    // Am I glad to see you
    DisplayDungeonDialogue(&gUnknown_8106934);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(SmeargleEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(SmeargleEntity, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(SmeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(SmeargleEntity);
    sub_8068FE0(SmeargleEntity, 0x21C, 0);
    gDungeonGlobalData->unk4 = 1;
    gDungeonGlobalData->unk11 = 4;

}

void sub_808CD44(void)
{
    struct DungeonEntity *LeaderEntity;
    struct DungeonEntity *SmeargleEntity;

    LeaderEntity = xxx_call_GetLeaderEntity();
    SmeargleEntity = sub_8085680(0x1F);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    sub_8068FE0(SmeargleEntity, 0x21C, 0);
    sub_8085860(LeaderEntity->posWorldX, LeaderEntity->posWorldY - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SMEARGLE);
}

void sub_808CD9C(u8 r0)
{
    sub_8086448();
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gUnknown_810697C);
}

u64 *sub_808CDB0(u8 r0)
{
    return &gUnknown_8107544[r0];
}

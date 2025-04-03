#include "global.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_80861A8.h"
#include "code_806CD90.h"
#include "code_80869E4.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "position_util.h"
#include "trap.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_boss_dialogue.h"

extern u32 gDungeonBrightness;

extern const struct MenuItem gUnknown_810579C[];
extern const u64 gUnknown_8107544[];
extern const u8 *const gUnknown_8105798;




extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F878(u32, s32);
extern void BgColorCallNullsub4(void);
extern void sub_8085EB0(void);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void ShowWholeRevealedDungeonMap(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern u8 sub_80860A8(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void sub_80464C8(Entity *, DungeonPos *, Item *);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern u32 sub_8085EC8(u32, u32, u32, DungeonPos *, u32);
extern void sub_807EAA0(u32, u32);
extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374(void);
extern u32 GetRandomFloorItem(u32);
extern bool8 sub_8085B80(struct_8085B80 *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);


void sub_808BBA8(Entity * );
void DeoxysScreenFlash(void);
void sub_8086A54(Entity *);
void ZapdosScreenFlash(s32 numFlashes);
void ZapdosDropInEffect(Entity *);
void SetupDeoxysFightHP(Entity *r0);
void sub_808C550(void);
void sub_808C590(Entity *r0);
void SetupDeoxysFacingDirection(Entity *r0);
void sub_808C9B0(Entity *);
void sub_808C8E0(Entity *param_1);
void sub_808C360(void);
void KyogreScreenFlash(void);
void sub_808C0CC(void);
void LugiaScreenFlash(void);
void LugiaScreenFlash2(void);
void nullsub_99(void);
void JirachiWish(void);
void JirachiSpinEffect(Entity *jirachiEntity);
void JirachiWishGrantDialogue(Entity *jirachiEntity);
void JirachiDropInEffect(Entity *jirachiEntity);
u8 JirachiFriendAreaSearch(void);
void sub_808B1CC(u8 itemID);
void CreateJirachiWishWarpTile(void);
void EnteiScreenFlash(void);
void RaikouScreenFlash(void);
void sub_808A528(Entity * param_1);
void SuicuneScreenFlash(void);
void HoOhDropInEffect(Entity * param_1);
void HoOhScreenFlash(void);
void LatiosScreenFlash(void);
void SetupRegiFacingDirection(Entity *entity);
void SetupRegirockFightHP(Entity *entity);
void SetupRegiceFightHP(Entity *entity);
void SetupRegisteelFightHP(Entity *entity);
void sub_808B50C(void);
void MewtwoDropInEffect(Entity *param_1);
void MewtwoScreenFlash(void);
void sub_80898F8(Entity *entity);
void sub_8089908(Entity *entity);
void RayquazaDropInEffect(Entity *param_1);
void RayquazaScreenFlash(void);
void sub_80891F0(void);
void sub_8089294(void);
void GroudonScreenFlash2(void);
void SceneGroudonMovement(Entity * param_1);
void GroudonScreenFlash(void);
void ArticunoScreenFlash(void);
void sub_8088484(Entity *param_1);
void sub_8088574(void);
void MoltresDropInEffect(Entity * param_1);
void MoltresScreenFlash1(s32 r0, s32 r1);
void MoltresScreenFlash2(s32 r0, s32 r1);
void MoltresScreenFlash3(void);
void MoltresScreenDarken(void);
void EnableJirachiWishWarpTile(void);
void sub_808BB3C(DungeonPos *pos);
void sub_8087144();
void SkarmoryEntry(Entity *);


// FILE SPLIT


// FILE SPLIT


// FILE SPLIT



// SPLIT



// File Split



//

void sub_808862C(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(alakazamEntity, DIRECTION_NORTH);
  sub_80861D4(alakazamEntity,0xd,DIRECTION_NORTH);
  SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(groudonEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_80886C4(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = xxx_call_GetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  PlaySoundEffect(0x3e5);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8068FE0(alakazamEntity,0x21c,0);
  SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(groudonEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_808875C(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_80867F4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(alakazamEntity,0x21c,0);
  if (sub_8086AE4(MONSTER_GROUDON)) {
    sub_8068FE0(groudonEntity,0x21c,0);
  }
  else {
    sub_8072008(groudonEntity,groudonEntity,gGroudonConfigLevel,0,0);
    SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
    sub_80861D4(groudonEntity,0xf,DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088818(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x12 || param_2 == 0x13 || param_2 == 0x14) && (param_1 == 0xE)) {
    sub_8097FA8(0xC);
    gDungeon->unk2 = 1;
  }
}

void sub_8088848(void)
{
    sub_8086854();
}

void GroudonPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * partnerEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086448();
  DisplayDungeonDialogue(GroudonPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_808682C();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_4);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  DisplayDungeonDialogue(&GroudonPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_6);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_80861B8(alakazamEntity,6,DIRECTION_NORTH);
  PlaySoundEffect(0x205);
  sub_8086738();
  sub_8068FE0(alakazamEntity,0x21c,0);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_8);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_9);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  sub_803E708(0x28,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(GroudonPreFightDialogue_10);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_11);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  GroudonScreenFlash2();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_12);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_13);
  sub_803E708(10,0x46);
  sub_803E708(0x1e,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(GroudonPreFightDialogue_14);
  sub_803E708(10,0x46);
  sub_8086A54(groudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void GroudonReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_1);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_2);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_3);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  DisplayDungeonDialogue(gGroudonReFightDialogue_4);
  sub_803E708(10,0x46);
  sub_8086A54(groudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void GroudonPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086448();
  if (sub_8086AE4(MONSTER_GROUDON)) {
      sub_80866C4(&gUnknown_8103488);
  }
  else{
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    SceneGroudonMovement(groudonEntity);
    SceneGroudonMovement(groudonEntity);
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_2);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_3);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_4);
    sub_803E708(10,0x46);
    SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

// Moves Groudon down in a walking fashion
void SceneGroudonMovement(Entity * groudonEntity)
{
  int iVar1;

  sub_8086848(0x18,0x10);
  sub_806CDD4(groudonEntity,0,DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 0x2C; iVar1++)
  {
    if ((iVar1 == 10) || (iVar1 == 0x20)) {
      PlaySoundEffect(0x1f9);
      sub_8086838(0,1,0);
      sub_808680C();
    }
    if ((iVar1 - 10U < 0xc) || (iVar1 > 0x1f)) {
      IncreaseEntityPixelPos(groudonEntity,0,0x100);
    }
    DungeonRunFrameActions(0x46);
  }
  sub_80856C8(groudonEntity,groudonEntity->pos.x,groudonEntity->pos.y + 1);
  sub_80861D4(groudonEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(0x22,0x46);
}

void GroudonScreenFlash(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void GroudonScreenFlash2(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

// FILE SPLIT


void sub_8088DC0(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(groudonEntity);
  sub_806CDD4(groudonEntity,0xe,DIRECTION_SOUTH);
  sub_8086A3C(alakazamEntity);
  sub_806CDD4(alakazamEntity,0xe,DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088E5C(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(groudonEntity,0x21c,0);
  sub_8068FE0(alakazamEntity,0x21c,0);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088EE8(void)
{
    sub_8086854();
}


void MagmaCavernMidDialogue(void)
{
  Entity * leaderEntity;
  Entity * partnerEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;
  s16 IDStack [2];
  PixelPos pos;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_8052D44(IDStack,leaderEntity,partnerEntity);
  sub_8086448();
  SpriteLookAroundEffect(partnerEntity);
  // Let's see..
  // I wonder where we are?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  // I know we've come pretty
  // far...
  //
  // I'm certain we've come quite
  // far already..
  DisplayDungeonDialogue(MagmaCavernMidDialogue_2);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0x28,0x46);
  // Waaah!
  // Qu-quake!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_3);
  sub_803E708(0x78,0x46);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_803E708(0x14,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(10,0x46);
  // Whew!
  // It settled down.
  //
  // Whew
  // It's over.
  DisplayDungeonDialogue(MagmaCavernMidDialogue_4);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  PlaySoundEffect(0x1c7);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  // Hey! {POKEMON_0}!
  // Over there!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_5);
  GetEntInfo(groudonEntity)->unk15E = 0;
  GetEntInfo(alakazamEntity)->unk15E =0;
  pos.x = (groudonEntity->pixelPos.x + alakazamEntity->pixelPos.x) / 2;
  pos.y = (groudonEntity->pixelPos.y + alakazamEntity->pixelPos.y) / 2 + 0x800;
  ShiftCameraToPosition(&pos,0x20);
  sub_803E708(0x3c,0x46);
  sub_80891F0();
  // Hey!
  // Are you OK?!
  //
  // Hey!
  // Snap out of it!
  DisplayDungeonDialogue(MagmaCavernMidDialogue_6);
  sub_803E708(10,0x46);
  // Urrrrgh...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_7);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,2,DIRECTION_NORTHWEST);
  // What happened to you?
  //
  // What happened here?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_8);
  sub_803E708(10,0x46);
  // We challenged..
  // {POKEMON_2}...
  // And wiped out..
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_9);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_10);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTHEAST);
  sub_80869E4(partnerEntity,4,1,DIRECTION_NORTHEAST);
  // Grrgh..
  // We... It crushed us
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_11);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  // That's right...
  // What happened to {POKEMON_3}?
  // Where is {POKEMON_3}?
  //
  // Wait...
  // What about {POKEMON_3}?
  // Where did {POKEMON_3} go?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_12);
  sub_803E708(0x1e,0x46);
  // {POKEMON_3} is...
  // Still battling {POKEMON_2}...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_13);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);

  // {POKEMON_0}!
  // We've got to hurry!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_14);
  sub_8089294();
  // Be careful!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_15);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void sub_8089168(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(leaderEntity);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808919C(Entity *r0)
{
    IncreaseEntityPixelPos(r0, 0, 0xfffffe00);
}

void sub_80891B0(Entity *r0)
{
    sub_806CDD4(r0, 0, DIRECTION_NORTH);
    GetEntInfo(r0)->unk15F = 1;
}


void sub_80891D0(Entity *r0)
{
    sub_806CDD4(r0, 7, DIRECTION_NORTH);
    GetEntInfo(r0)->unk15F = 0;
}

void sub_80891F0(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 < 0x30; iVar1++)
  {
    sub_80855E4(sub_808919C);
    DungeonRunFrameActions(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_8089224(Entity * entity)
{
  s32 xPixelPos;

  if (entity->pixelPos.y < 0x9001) {
    return;
  }
  xPixelPos = entity->pixelPos.x;

  if(xPixelPos < 0xE400)
  {
      if(xPixelPos <= 0xB400)
      {
          // 0 - 0xB400
          IncreaseEntityPixelPos(entity, 0, 0xfffffe00);
      }
      else
      {
          // 0xB401 - 0xE3FF
           IncreaseEntityPixelPos(entity, 0xfffffe00, 0);
      }
  }
  else
  {
      if(xPixelPos < 0xFC00)
      {
            IncreaseEntityPixelPos(entity, 0, 0xfffffe00);
      }
      else
      {
          if(xPixelPos <= 0x11400)
          {
              IncreaseEntityPixelPos(entity, 0x200, 0);
          }
          else
          {
              IncreaseEntityPixelPos(entity, 0, 0xfffffe00);
          }
      }
  }
}

void sub_8089294(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 <= 0x77; iVar1++)
  {
    sub_80855E4(sub_8089224);
    DungeonRunFrameActions(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_80892C8(void)
{
  Entity * leaderEntity;
  Entity * RayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(RayquazaEntity, DIRECTION_SOUTH);
  sub_8086A3C(RayquazaEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_RAYQUAZA);
}

void sub_8089328(void)
{
  Entity * leaderEntity;
  Entity * rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_8068FE0(rayquazaEntity,0x21c,0);
  }
  else {
    sub_8072008(rayquazaEntity,rayquazaEntity,gRayquazaConfigLevel,0,0);
    sub_8086A3C(rayquazaEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_RAYQUAZA);
}

void sub_80893B4(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x17 || param_2 == 0x18 || param_2 == 0x19) && (param_1 == 0xF)) {
    sub_8097FA8(0xF);
    gDungeon->unk2 = 1;
  }
}

void RayquazaPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_2);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  SpriteLookAroundEffect(partnerEntity);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_3);
  sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_6);
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_7);
  RayquazaDropInEffect(rayquazaEntity);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_8);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_9);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_10);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_11);
  SetupBossFightHP(rayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RayquazaReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_7);
  sub_803E708(10,0x46);
  RayquazaDropInEffect(rayquazaEntity);
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_2);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_3);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_4);
  SetupBossFightHP(rayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RayquazaPostStoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_80866C4(&gRayquazaPostStoryPreFightDialogue_6);
  }
  else {
    PlaySoundEffect(0x1da); // Rayquaza Cry
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_1);
    RayquazaDropInEffect(rayquazaEntity);
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_2);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_3);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_4);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_5);
    SetupBossFightHP(rayquazaEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void RayquazaDropInEffect(Entity *rayquazaEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(rayquazaEntity)->unk15E = 0;
  iVar2 = IntToF248_2(200);
  iVar1 = IntToF248_2(6);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw = iVar2.raw - iVar1.raw; // must be .raw
    iVar1 = F248_Sub(iVar1, FloatToF248_2(3./32.));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(rayquazaEntity)->unk174 = iVar2;
    DungeonRunFrameActions(0x46);
  }
  GetEntInfo(rayquazaEntity)->unk174 = IntToF248_2(0);
}

void RayquazaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, 0, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}


void sub_808970C(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_TINY_WOODS);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
}

void sub_808974C(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
}

void sub_8089788(Entity *entity, u8 param_2, u8 param_3)
{
  Entity *monEntity;
  s32 index;
  u32 unk1;

  unk1 = 0;

  if (param_3 == 0x1A || param_3 == 0x1B) {
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
      monEntity = gDungeon->wildPokemon[index];
      if ((EntityIsValid(monEntity)) && (monEntity != entity) && (GetEntInfo(monEntity)->monsterBehavior == param_2)) {
        return;
      }
    }
    // WTF is this??
    if(!unk1){
        sub_8097FA8(0x11);
        gDungeon->unk2 = 1;
    }
  }
}

void sub_80897F0(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103BD8);
  // We don't like to brag or
  // nothing, but
  DisplayDungeonDialogue(&gUnknown_8103C00);
  // We get furious real easy
  // You know that?!
  DisplayDungeonDialogue(&gUnknown_8103C3C);
  // What really irritates us is
  // when we see some dim witted face
  DisplayDungeonDialogue(&gUnknown_8103C74);
  // .........
  // Wrooooooar!
  // That vacant expression
  DisplayDungeonDialogue(&gUnknown_8103CC4);
  // Gwoooh
  // It's ticking me off!
  // I'm seeing red!
  DisplayDungeonDialogue(&gUnknown_8103D0C);
  // Mukkkeeeeeh
  // Get 'em! It's frenzy time!
  DisplayDungeonDialogue(&gUnknown_8103D50);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}



void sub_8089878(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103D8C);
  DisplayDungeonDialogue(&gUnknown_8103D98);
  DisplayDungeonDialogue(&gUnknown_8103DD8);
  DisplayDungeonDialogue(&gUnknown_8103E28);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8103E34);
}

void sub_80898F8(Entity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void sub_8089908(Entity *r0)
{
    SetFacingDirection(r0, DIRECTION_NORTH);
}

void sub_8089914(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
  sub_8086A3C(MewtwoEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MEWTWO);
}

void sub_8089978(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if(HasRecruitedMon(MONSTER_MEWTWO)){
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8068FE0(MewtwoEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
    sub_8086A3C(MewtwoEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MEWTWO);
}

void sub_8089A00(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x1d || param_2 == 0x1e || param_2 == 0x1f) && (param_1 == 0x11)) {
    sub_8097FA8(0x13);
    gDungeon->unk2 = 1;
  }
}

void MewtwoPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  sub_8086448();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_1);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  sub_8086794();
  sub_803E708(0x1e,0x46);
  MewtwoDropInEffect(MewtwoEntity);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_2);
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_3);
  sub_803E708(10,0x46);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_4);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void MewtwoReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  sub_8086448();
  if(HasRecruitedMon(MONSTER_MEWTWO)) {
    sub_80866C4(&gMewtwoReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_1);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8086794();
    MewtwoDropInEffect(MewtwoEntity);
    sub_803E708(0x3c,0x46);
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_2);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_3);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_4);
    SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void MewtwoDropInEffect(Entity *mewtwoEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(mewtwoEntity)->unk15E = 0;
  iVar2 = IntToF248_2(200);
  iVar1 = IntToF248_2(4);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248_2(0.045));
    if (F248LessThanFloat(iVar1, 0.12)) {
      iVar1 = FloatToF248_2(0.12);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(mewtwoEntity)->unk174 = iVar2;
    DungeonRunFrameActions(0x46);
  }
  GetEntInfo(mewtwoEntity)->unk174 = IntToF248_2(0);
}

void MewtwoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_8089C44(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ENTEI);
}


void sub_8089C90(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
      sub_8068FE0(EnteiEntity,0x21c,0);
  }
  else {
      SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ENTEI);
}

void sub_8089CFC(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x20 || param_2 == 0x21 || param_2 == 0x22) && (param_1 == 0x12)) {
    sub_8097FA8(0x15);
    gDungeon->unk2 = 1;
  }
}

void EnteiPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void EnteiReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void EnteiPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
    sub_80866C4(&gEnteiPostStoryPreFightDialogue_4);
  }
  else {
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_1);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_2);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void EnteiScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, 0, 0, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_8089EFC(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}


void sub_8089F44(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}


void sub_8089F8C(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
      sub_8068FE0(RaikouEntity,0x21c,0);
  }
  else {
      SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}

void sub_8089FF0(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x23 || param_2 == 0x24 || param_2 == 0x25) && (param_1 == 0x13)) {
    sub_8097FA8(0x17);
    gDungeon->unk2 = 1;
  }
}

void RaikouPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_2);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_3);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_4);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_5);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_2);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
    sub_80866C4(&gRaikouPostStoryPreFightDialogue_4);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_RAIN;
    sub_807EAA0(0,1);
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_1);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_2);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A264(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8086A3C(SuicuneEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A2C0(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A308(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
     sub_8068FE0(SuicuneEntity,0x21c,0);
  }
  else {
     SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A36C(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x26 || param_2 == 0x27 || param_2 == 0x28) && (param_1 == 0x14)) {
    sub_8097FA8(0x19);
    gDungeon->unk2 = 1;
  }
}

void SuicunePreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  sub_8086448();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_2);
  sub_803E708(10,70);
  sub_80426C8(1,2);
  sub_803E708(0x3c,70);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_3);
  sub_803E708(10,70);
  sub_808A528(SuicuneEntity);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_4);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_5);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_6);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_7);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SuicuneReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_1);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_2);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SuicunePostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
    sub_80866C4(&gSuicunePostStoryPreFightDialogue_4);
  }
  else {
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_1);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_2);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void sub_808A528(Entity * param_1)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(param_1)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(12);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248(0.375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248_2(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(param_1)->unk174 = iVar2;
    DungeonRunFrameActions(70);
  }
  GetEntInfo(param_1)->unk174 = IntToF248_2(0);
}

void SuicuneScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A608(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
  sub_8086A3C(HoOhEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -6);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_HO_OH);
}

void sub_808A668(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_8068FE0(HoOhEntity,0x21c,0);
  }
  else {
    SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
    sub_8086A3C(HoOhEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 6);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_HO_OH);
}

void sub_808A6E8(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x29 || param_2 == 0x2A) && (param_1 == 0x15)) {
    sub_8097FA8(0x1A);
    gDungeon->unk2 = 1;
  }
}

void sub_808A718(void)
{
    sub_8086854();
}

void HoOhPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;
  PixelPos local_14;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  local_14.x = leaderEntity->pixelPos.x;
  local_14.y = leaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_1);
  sub_803E708(10,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_2);
  sub_803E708(10,70);
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0xfa,70);
  HoOhDropInEffect(HoOhEntity);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_3);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_4);
  sub_803E708(0x1e,70);
  sub_803E708(0x1e,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_5);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void HoOhReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;
  PixelPos local_14;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);

  local_14.x = leaderEntity->pixelPos.x;
  local_14.y = leaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_80866C4(&HoOhReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&HoOhReFightDialogue_1);
    HoOhScreenFlash();
    sub_80855E4(sub_80868F4);
    sub_808680C();
    sub_803E708(10,70);
    HoOhDropInEffect(HoOhEntity);
    sub_808682C();
    sub_80855E4(sub_8086910);
    sub_8085930(DIRECTION_NORTH);
    DisplayDungeonDialogue(&HoOhReFightDialogue_2);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_3);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_4);
    sub_803E708(10,70);
    SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void HoOhDropInEffect(Entity * param_1)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(param_1)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(12);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248(0.375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248_2(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(param_1)->unk174 = iVar2;
    DungeonRunFrameActions(70);
  }
  GetEntInfo(param_1)->unk174 = IntToF248_2(0);
}

void HoOhScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A9E4(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 4);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AA3C(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AA94(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(LatiosEntity,0x21c,0);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AAF0(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x2B || param_2 == 0x2C || param_2 == 0x2D) && (param_1 == 0x16)) {
    sub_8097FA8(0x1C);
    gDungeon->unk2 = 1;
  }
}

void LatiosPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;
  PixelPos local_18;
  DungeonPos local_19;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);

  local_18.x = LatiosEntity->pixelPos.x;
  local_18.y = LatiosEntity->pixelPos.y + (0x80 << 6);
  local_19.y = 0x70;
  local_19.x = 0xFC;
  sub_8085EC8(0x1bd,0,0,&local_19,1);

  sub_803E708(0x1e,70);
  sub_8086448();
  ShiftCameraToPosition(&local_18,0x18);
  sub_803E708(2,70);
  SpriteShockEffect(LatiosEntity);
  sub_803E708(0x20,70);
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void LatiosReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  sub_8086448();
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosReFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808AC3C(void)
{
    sub_8086448();
    // There appears to be no one here
    sub_80866C4(&gUnknown_8104FC8);
}

void LatiosScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  gDungeonBrightness = 0x1f;
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808ACC0(void)
{
  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGIROCK)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGIROCK);
    sub_8068FE0(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ROCK_PART);
  }
  else if (sub_80860A8(ITEM_ROCK_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGIROCK);
  }
}

void sub_808AD48(void)
{
  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGICE)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGICE);
    sub_8068FE0(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ICE_PART);
  }
  else if (sub_80860A8(ITEM_ICE_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGICE);
  }
}

void sub_808ADCC(void)
{

  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGISTEEL)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGISTEEL);
    sub_8068FE0(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_STEEL_PART);
  }
  else if (sub_80860A8(ITEM_STEEL_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGISTEEL);
  }
}

void sub_808AE54(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      ItemIdToSlot(&item,ITEM_ROCK_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      DisplayDungeonDialogue(&gRegirockPostFightDialogue_1);
    }
  }
}


void sub_808AEC8(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      ItemIdToSlot(&item,ITEM_ICE_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      DisplayDungeonDialogue(&gRegicePostFightDialogue_1);
    }
  }
}

void sub_808AF3C(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      ItemIdToSlot(&item,ITEM_STEEL_PART,0);
      sub_80464C8(GetLeader(),param_3, &item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      DisplayDungeonDialogue(&gRegisteelPostFightDialogue_1);
    }
  }
}

void sub_808AFB0(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x2E) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_ROCK_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    // {POKEMON_0} obtained the Rock Part that Regirock was guarding
    DisplayDungeonDialogue(&gRegirockPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B030(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x2F) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_ICE_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    // {POKEMON_0} obtained the Ice Part that Regice was guarding
    DisplayDungeonDialogue(&gRegicePostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B0B0(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x30) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_STEEL_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
    // {POKEMON_0} obtained the Steel Part that Registeel was guarding
    DisplayDungeonDialogue(&gRegisteelPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void RegirockPreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegirockPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegirockFightHP);
  }
}

void RegicePreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegicePreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegiceFightHP);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegisteelPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegisteelFightHP);
  }
}

void sub_808B1CC(u8 itemID)
{
    Entity *entity;
    Tile *tile;
    DungeonPos pos;
    Item item;

    pos.x = gDungeon->unk644.unk40;
    pos.y = gDungeon->unk644.unk42;
    if ((pos.x < 0) || (pos.y  < 0)) {
        entity = GetLeader();
        if (entity == NULL) {
            gDungeon->unk2 = 1;
            return;
        }
        pos.x = entity->pos.x;
        pos.y = entity->pos.y;
    }
    sub_807FE04(&pos, 0);
    tile = GetTileMut(pos.x, pos.y);
    tile->terrainType = tile->terrainType | TERRAIN_TYPE_STAIRS;
    if (((itemID != ITEM_NOTHING) && (sub_80860A8(itemID) == 0)) &&
        (sub_80860A8(ITEM_MUSIC_BOX) == 0)) {
        ItemIdToSlot(&item,itemID,0);
        pos.y--;
        AddItemToDungeonAt(&pos,&item,1);
    }
    sub_8049ED4();
    ShowWholeRevealedDungeonMap();
}

void SetupRegiFacingDirection(Entity *regiEntity)
{
    GetEntInfo(regiEntity)->action.direction = DIRECTION_NORTH;
    sub_806CE68(regiEntity, DIRECTION_NORTH);
}


void SetupRegirockFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}


void SetupRegiceFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}


void SetupRegisteelFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}









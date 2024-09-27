#include "global.h"
#include "code_800E9A8.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_804267C.h"
#include "code_8045A00.h"
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
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "position_util.h"
#include "exclusive_pokemon.h"
#include "trap.h"

extern u32 gUnknown_202EDC8;
extern u8 gUnknown_202E038[0x50];
extern u8 gAvailablePokemonNames[0x58];
extern u8 gFormatItems[];

extern const s16 gUnknown_80F57CA;
extern const s16 gUnknown_80F57D2;
extern const s16 gUnknown_80F57D0;
extern const s16 gUnknown_80F57CE;

extern const u8 gUnknown_8103D8C[];
extern const u8 gUnknown_8103D98[];
extern const u8 gUnknown_8103DD8[];
extern const u8 gUnknown_8103E28[];
extern const u8 gUnknown_8103BD8[];
extern const u8 gUnknown_8103C00[];
extern const u8 gUnknown_8103C3C[];
extern const u8 gUnknown_8103C74[];
extern const u8 gUnknown_8103CC4[];
extern const u8 gUnknown_8103D0C[];
extern const u8 gUnknown_8103D50[];
extern const u8 gRayquazaPostStoryPreFightDialogue_6[];
extern const u8 gRayquazaPostStoryPreFightDialogue_1[];
extern const u8 gRayquazaPostStoryPreFightDialogue_2[];
extern const u8 gRayquazaPostStoryPreFightDialogue_3[];
extern const u8 gRayquazaPostStoryPreFightDialogue_4[];
extern const u8 gRayquazaPostStoryPreFightDialogue_5[];
extern const u8 gRayquazaPreFightDialogue_7[];
extern const u8 gRayquazaReFightDialogue_1[];
extern const u8 gRayquazaReFightDialogue_2[];
extern const u8 gRayquazaReFightDialogue_3[];
extern const u8 gRayquazaReFightDialogue_4[];
extern const u8 gRayquazaPreFightDialogue_1[];
extern const u8 gRayquazaPreFightDialogue_2[];
extern const u8 gRayquazaPreFightDialogue_3[];
extern const u8 gRayquazaPreFightDialogue_4[];
extern const u8 gRayquazaPreFightDialogue_5[];
extern const u8 gRayquazaPreFightDialogue_6[];
extern const u8 gRayquazaPreFightDialogue_7[];
extern const u8 gRayquazaPreFightDialogue_8[];
extern const u8 gRayquazaPreFightDialogue_9[];
extern const u8 gRayquazaPreFightDialogue_10[];
extern const u8 gRayquazaPreFightDialogue_11[];
extern const u8 MagmaCavernMidDialogue_5[];
extern const u8 MagmaCavernMidDialogue_6[];
extern const u8 MagmaCavernMidDialogue_7[];
extern const u8 MagmaCavernMidDialogue_8[];
extern const u8 MagmaCavernMidDialogue_9[];
extern const u8 MagmaCavernMidDialogue_10[];
extern const u8 MagmaCavernMidDialogue_11[];
extern const u8 MagmaCavernMidDialogue_12[];
extern const u8 MagmaCavernMidDialogue_13[];
extern const u8 MagmaCavernMidDialogue_14[];
extern const u8 MagmaCavernMidDialogue_15[];
extern const u8 MagmaCavernMidDialogue_4[];
extern const u8 MagmaCavernMidDialogue_3[];
extern const u8 MagmaCavernMidDialogue_2[];
extern const u8 MagmaCavernMidDialogue_1[];
extern const u8 gUnknown_8103488[];
extern const u8 gGroudonPostStoryPreFightDialogue_1[];
extern const u8 gGroudonPostStoryPreFightDialogue_2[];
extern const u8 gGroudonPostStoryPreFightDialogue_3[];
extern const u8 gGroudonPostStoryPreFightDialogue_4[];
extern const u8 gGroudonReFightDialogue_1[];
extern const u8 gGroudonReFightDialogue_2[];
extern const u8 gGroudonReFightDialogue_3[];
extern const u8 gGroudonReFightDialogue_4[];
extern const u8 GroudonPreFightDialogue_1[];
extern const u8 GroudonPreFightDialogue_2[];
extern const u8 GroudonPreFightDialogue_3[];
extern const u8 GroudonPreFightDialogue_4[];
extern const u8 GroudonPreFightDialogue_5[];
extern const u8 GroudonPreFightDialogue_6[];
extern const u8 GroudonPreFightDialogue_7[];
extern const u8 GroudonPreFightDialogue_8[];
extern const u8 GroudonPreFightDialogue_9[];
extern const u8 GroudonPreFightDialogue_10[];
extern const u8 GroudonPreFightDialogue_11[];
extern const u8 GroudonPreFightDialogue_12[];
extern const u8 GroudonPreFightDialogue_13[];
extern const u8 GroudonPreFightDialogue_14[];
extern const u8 gUnknown_8102B10[];
extern const u8 gRegisteelPostFightDialogue_2[];
extern const u8 gRegicePostFightDialogue_2[];
extern const u8 gRegirockPostFightDialogue_2[];
extern const u8 gRegisteelPostFightDialogue_1[];
extern const u8 gRegicePostFightDialogue_1[];
extern const u8 gRegirockPostFightDialogue_1[];
extern const u8 gUnknown_810554C[];
extern const u8 gUnknown_8105558[];
extern const u8 gUnknown_81055F4[];
extern const u8 gRegicePreFightDialogue_1[];
extern const u8 gRegirockPreFightDialogue_1[];
extern const u8 gSuicuneReFightDialogue_1[];
extern const u8 gSuicuneReFightDialogue_2[];
extern const u8 gSuicuneReFightDialogue_3[];
extern const u8 gRegisteelPreFightDialogue_1[];
extern const u8 gJirachiPreFightDialogue_1[];
extern const u8 gJirachiPreFightDialogue_2[];
extern const u8 gJirachiPreFightDialogue_3[];
extern const u8 gJirachiPreFightDialogue_4[];
extern const u8 gLatiosReFightDialogue_1[];
extern const u8 gLatiosPreFightDialogue_2[];
extern const u8 gLatiosPreFightDialogue_3[];
extern const u8 gLatiosPreFightDialogue_1[];
extern const u8 HoOhReFightDialogue_1[];
extern const u8 HoOhReFightDialogue_2[];
extern const u8 HoOhReFightDialogue_3[];
extern const u8 HoOhReFightDialogue_4[];
extern const u8 HoOhReFightDialogue_5[];
extern const u8 gHoOhPreFightDialogue_1[];
extern const u8 gHoOhPreFightDialogue_2[];
extern const u8 gHoOhPreFightDialogue_3[];
extern const u8 gHoOhPreFightDialogue_4[];
extern const u8 gHoOhPreFightDialogue_5[];
extern const u8 gHoOhPreFightDialogue_6[];
extern const u8 gSuicunePostStoryPreFightDialogue_4[];
extern const u8 gSuicunePostStoryPreFightDialogue_1[];
extern const u8 gSuicunePostStoryPreFightDialogue_2[];
extern const u8 gSuicunePostStoryPreFightDialogue_3[];
extern const u8 gSuicunePreFightDialogue_1[];
extern const u8 gSuicunePreFightDialogue_2[];
extern const u8 gSuicunePreFightDialogue_3[];
extern const u8 gSuicunePreFightDialogue_4[];
extern const u8 gSuicunePreFightDialogue_5[];
extern const u8 gSuicunePreFightDialogue_6[];
extern const u8 gSuicunePreFightDialogue_7[];
extern const u8 gRaikouPostStoryPreFightDialogue_3[];
extern const u8 gRaikouPostStoryPreFightDialogue_4[];
extern const u8 gRaikouPostStoryPreFightDialogue_1[];
extern const u8 gRaikouPostStoryPreFightDialogue_2[];
extern const u8 gRaikouReFightDialogue_1[];
extern const u8 gRaikouReFightDialogue_2[];
extern const u8 gRaikouReFightDialogue_3[];
extern const u8 gRaikouPreFightDialogue_1[];
extern const u8 gRaikouPreFightDialogue_2[];
extern const u8 gRaikouPreFightDialogue_3[];
extern const u8 gRaikouPreFightDialogue_4[];
extern const u8 gRaikouPreFightDialogue_5[];
extern const u8 gRaikouPreFightDialogue_6[];
extern const u8 gEnteiPostStoryPreFightDialogue_4[];
extern const u8 gEnteiPostStoryPreFightDialogue_1[];
extern const u8 gEnteiPostStoryPreFightDialogue_2[];
extern const u8 gEnteiPostStoryPreFightDialogue_3[];
extern const u8 gEnteiReFightDialogue_1[];
extern const u8 gEnteiReFightDialogue_2[];
extern const u8 gEnteiReFightDialogue_3[];
extern const u8 gUnknown_8104FC8[];
extern const u8 gEnteiPreFightDialogue_1[];
extern const u8 gEnteiPreFightDialogue_2[];
extern const u8 gEnteiPreFightDialogue_3[];
extern const u8 gMewtwoReFightDialogue_5[];
extern const u8 gMewtwoReFightDialogue_4[];
extern const u8 gMewtwoReFightDialogue_3[];
extern const u8 gMewtwoReFightDialogue_2[];
extern const u8 gMewtwoReFightDialogue_1[];
extern const u8 gMewtwoPreFightDialogue_5[];
extern const u8 gMewtwoPreFightDialogue_1[];
extern const u8 gMewtwoPreFightDialogue_2[];
extern const u8 gMewtwoPreFightDialogue_3[];
extern const u8 gMewtwoPreFightDialogue_4[];
extern const u8 gUnknown_8103E34[];
extern const u8 gUnknown_8102A9C[];
extern const u8 gArticunoPostStoryPreFightDialogue_1[];
extern const u8 gArticunoPostStoryPreFightDialogue_2[];
extern const u8 gArticunoPostStoryPreFightDialogue_3[];
extern const u8 gArticunoPostStoryPreFightDialogue_4[];
extern const u8 gArticunoPostStoryPreFightDialogue_5[];
extern const u8 gArticunoReFightDialogue_1[];
extern const u8 gArticunoReFightDialogue_2[];
extern const u8 gArticunoReFightDialogue_3[];
extern const u8 gArticunoPreFightDialogue_1[];
extern const u8 gArticunoPreFightDialogue_2[];
extern const u8 gArticunoPreFightDialogue_3[];
extern const u8 gArticunoPreFightDialogue_4[];
extern const u8 gArticunoPreFightDialogue_5[];
extern const u8 gArticunoPreFightDialogue_6[];
extern const u8 gArticunoPreFightDialogue_7[];
extern const u8 gArticunoPreFightDialogue_8[];
extern const u8 gArticunoPreFightDialogue_9[];
extern const u8 gArticunoPreFightDialogue_10[];
extern const u8 gArticunoPreFightDialogue_11[];
extern const u8 gArticunoPreFightDialogue_12[];
extern const u8 gMoltresPostStoryPreFightDialogue_1[];
extern const u8 gMoltresPostStoryPreFightDialogue_2[];
extern const u8 gMoltresPostStoryPreFightDialogue_3[];
extern const u8 gMoltresPostStoryPreFightDialogue_4[];
extern const u8 gMoltresPostStoryPreFightDialogue_5[];
extern const u8 gUnknown_8100D3C[];
extern const u8 gMoltresReFightDialogue_1[];
extern const u8 gMoltresReFightDialogue_2[];
extern const u8 gMoltresReFightDialogue_3[];
extern const u8 gMoltresReFightDialogue_4[];
extern const u8 gMoltresReFightDialogue_5[];
extern const u8 gMoltresPreFightDialogue_1[];
extern const u8 gMoltresPreFightDialogue_2[];
extern const u8 gMoltresPreFightDialogue_3[];
extern const u8 gMoltresPreFightDialogue_4[];
extern const u8 gMoltresPreFightDialogue_5[];
extern const u8 gMoltresPreFightDialogue_6[];
extern const u8 gMoltresPreFightDialogue_7[];
extern const u8 gMoltresPreFightDialogue_8[];
extern const u8 gMoltresPreFightDialogue_9[];
extern const u8 gMoltresPreFightDialogue_10[];
extern const u8 gMoltresPreFightDialogue_11[];
extern const u8 gMoltresPreFightDialogue_12[];
extern const u8 gZapdosPostStoryPreFightDialogue_1[];
extern const u8 gZapdosPostStoryPreFightDialogue_2[];
extern const u8 gZapdosPostStoryPreFightDialogue_3[];
extern const u8 gZapdosPostStoryPreFightDialogue_4[];
extern const u8 gZapdosPostStoryPreFightDialogue_5[];
extern const u8 gZapdosPostStoryPreFightDialogue_6[];
extern const u8 gUnknown_8105668[];
extern const u8 gUnknown_8105674[];
extern const u8 gUnknown_81056B8[];
extern const u8 gUnknown_81056DC[];
extern const u8 gUnknown_810579C[];
extern const u8 gUnknown_8105974[];
extern const u8 gUnknown_810581C[];

extern const u8 gUnknown_8105BF4[];
extern const u8 gUnknown_8105D2C[];
extern const u8 gUnknown_8105D80[];
extern const u8 gUnknown_8105D9C[];
extern const u8 gUnknown_81058E0[];
extern const u8 gUnknown_810593C[];
extern const u8 gUnknown_8105A08[];
extern const u8 gUnknown_8105AD4[];
extern const u8 gUnknown_8105B20[];
extern const u8 gUnknown_8105B68[];
extern const u8 gUnknown_8105BA8[];
extern const u8 *gUnknown_8105798[];
extern const u8 gJirachiReFightDialogue_1[];

extern const u8 gKyogrePreFightDialogue_8[];
extern const u8 gKyogrePreFightDialogue_1[];
extern const u8 gKyogrePreFightDialogue_2[];
extern const u8 gKyogrePreFightDialogue_3[];
extern const u8 gKyogrePreFightDialogue_4[];
extern const u8 gKyogrePreFightDialogue_5[];
extern const u8 gKyogrePreFightDialogue_6[];
extern const u8 gKyogrePreFightDialogue_7[];
extern const u8 gUnknown_810697C[];
extern const u64 gUnknown_8107544[];
extern const u8 gMedichamRescueDialogue_1[];
extern const u8 gMedichamRescueDialogue_2[];
extern const u8 gMedichamRescueDialogue_3[];
extern const u8 gMedichamRescueDialogue_4[];
extern const u8 gSmeargleRescueDialogue_1[];
extern const u8 gSmeargleRescueDialogue_2[];
extern const u8 gSmeargleRescueDialogue_3[];
extern const u8 gSmeargleRescueDialogue_4[];
extern const u8 gUnknown_8106720[];

extern const u8 gCelebiJoinDialogue_10[];
extern const u8 gCelebiJoinDialogue_1[];
extern const u8 gCelebiJoinDialogue_2[];
extern const u8 gCelebiJoinDialogue_3[];
extern const u8 gCelebiJoinDialogue_4[];
extern const u8 gCelebiJoinDialogue_5[];
extern const u8 gCelebiJoinDialogue_6[];
extern const u8 gCelebiJoinDialogue_7[];
extern const u8 gCelebiJoinDialogue_8[];
extern const u8 gCelebiJoinDialogue_9[];
extern const u8 *const gPtrPurityForestAllowCelebiToJoinText;
extern const u8 gPurityForestAllowCelebiToJoinPrompt;
extern const u8 *const gPtrPurityForestRefuseCelebiConfirmText;
extern const u8 gPurityForestRefuseCelebiConfirmPrompt;
extern const u8 gDeoxysPreFightDialogue_1[];
extern const u8 gDeoxysPreFightDialogue_2[];
extern const u8 gDeoxysPreFightDialogue_3[];
extern const u8 gDeoxysPreFightDialogue_4[];
extern const u8 gDeoxysPreFightDialogue_5[];
extern const u8 gLugiaPreFightDialogue_8[];
extern const u8 gLugiaPreFightDialogue_1[];
extern const u8 gLugiaPreFightDialogue_2[];
extern const u8 gLugiaPreFightDialogue_3[];
extern const u8 gLugiaPreFightDialogue_4[];
extern const u8 gLugiaPreFightDialogue_5[];
extern const u8 gLugiaPreFightDialogue_6[];
extern const u8 gLugiaPreFightDialogue_7[];
extern const u8 gZapdosReFightDialogue_1[];
extern const u8 gUnknown_81015A0[];
extern const u8 gZapdosReFightDialogue_2[];
extern const u8 gZapdosReFightDialogue_3[];
extern const u8 gZapdosReFightDialogue_4[];

extern const u8 gUnknown_81058C4[];
extern const u8 gUnknown_81058A8[];

extern const u8 gUnknown_81074FC[];

extern void sub_800DC14(u32);

extern void sub_8086A3C(Entity *r0);
extern void sub_8068FE0(Entity *, u32, u32);

extern void sub_8086448(void);
extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern u32 sub_80861F8(u32, Entity *, u32);
extern s32 GetCameraXPos();
extern s32 GetCameraYPos();
extern void sub_803F878(u32, s32);
extern void SetupBossFightHP(Entity *, u32, u32);
extern void sub_803E9D0(void);
extern void DeoxysScreenFlash(void);
extern void sub_8085EB0();

void SetupDeoxysFightHP(Entity *r0);
void sub_808C550(void);
void sub_808C590(Entity *r0);
void SetupDeoxysFacingDirection(Entity *r0);
void sub_808C9B0(Entity *);
void sub_808C8E0(Entity *param_1);
void sub_808C360(void);
void KyogreScreenFlash();

void sub_808C0CC();
void LugiaScreenFlash();
void LugiaScreenFlash2();

void nullsub_99();

extern void sub_8049884();
extern void sub_8049B8C();
extern void sub_8049ED4();
extern void sub_8040A84();
extern void sub_8086A54(Entity *);

extern void sub_806BFC0(EntityInfo *, u32);

extern void sub_808BBA8(Entity * );
extern void sub_8041888(u32);
extern void DisplayDungeonDialogue(const u8 *r0);

extern u32 sub_80861F8(u32, Entity *, u32);


extern void JirachiWish();
extern void JirachiSpinEffect(Entity *);
extern void JirachiWishGrantDialogue(Entity *jirachiEntity);
extern void JirachiWishGrantFlash();
extern void JirachiDropInEffect(Entity *param_1);
extern u8 JirachiFriendAreaSearch(void);

extern u8 sub_80860A8(u32);
extern void sub_8049ED4();
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void sub_80421C0(Entity *, u32);
extern void sub_808B1CC(u8);
extern void sub_80464C8(Entity *, u32 *, Item *);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);

extern u32 sub_8085EC8(u32, u32, u32, Position *, u32);
extern void sub_807EAA0(u32, u32);

extern void CreateJirachiWishWarpTile(void);

void EnteiScreenFlash(void);
void RaikouScreenFlash(void);
void sub_808A528(Entity * param_1);
void SuicuneScreenFlash();
void HoOhDropInEffect(Entity * param_1);
void HoOhScreenFlash(void);
void LatiosScreenFlash(void);
void SetupRegiFacingDirection(Entity *r0);
void SetupRegirockFightHP(Entity *r0);
void SetupRegiceFightHP(Entity *r0);
void SetupRegisteelFightHP(Entity *r0);
void sub_808B50C(void);
void MewtwoDropInEffect(Entity *param_1);
void MewtwoScreenFlash(void);
void sub_80898F8(Entity *r0);
void sub_8089908(Entity *r0);
void RayquazaDropInEffect(Entity *param_1);
void RayquazaScreenFlash(void);
void sub_80891F0(void);
void sub_8089294(void);
void GroudonScreenFlash2(void);

extern u8 sub_8086AE4(s16);

extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374();

extern void sub_803F878(u32,s32);

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
void ZapdosDropInEffect(Entity *param_1);
void ZapdosScreenFlash(int param_1);

extern s32 sub_8052C68(u32, const u8 *, const u8 *, u32);
extern void sub_8045C28(Item *, u8 , u8 *);
extern void EnableJirachiWishWarpTile(void);
extern void sub_808BB3C(Position *);
extern void sub_8046860(Entity *, Position *, Item *, u32);
extern u32 sub_803D73C(u32);

extern void sub_80460F8(Position *, Item *, u8);

void ZapdosReFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *ZapdosEntity;

  LeaderEntity = xxx_call_GetLeader();
  ZapdosEntity = GetEntityFromClientType(8);
  sub_8086448();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gZapdosReFightDialogue_1);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(gUnknown_81015A0);
  sub_803E708(10,0x46);
  ZapdosDropInEffect(ZapdosEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gZapdosReFightDialogue_2);
  ZapdosScreenFlash(1);
  DisplayDungeonDialogue(gZapdosReFightDialogue_3);
  ZapdosScreenFlash(2);
  DisplayDungeonDialogue(gZapdosReFightDialogue_4);
  SetupBossFightHP(ZapdosEntity,300,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void ZapdosPostStoryPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * ZapdosEntity;

  LeaderEntity = xxx_call_GetLeader();
  ZapdosEntity = GetEntityFromClientType(8);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ZAPDOS)) {
    sub_80866C4(gZapdosPostStoryPreFightDialogue_6);
  }
  else {
    ZapdosScreenFlash(1);
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(gZapdosPostStoryPreFightDialogue_1);
    ZapdosDropInEffect(ZapdosEntity);
    DisplayDungeonDialogue(gZapdosPostStoryPreFightDialogue_2);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue(gZapdosPostStoryPreFightDialogue_3);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(gZapdosPostStoryPreFightDialogue_4);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(gZapdosPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(ZapdosEntity,300,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}


void ZapdosDropInEffect(Entity *zapdosEntity)
{
  int iVar1;

  zapdosEntity->axObj.info->unk15C = 1;
  zapdosEntity->axObj.info->unk15E = 0;
  zapdosEntity->axObj.info->unk174 = 200;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    zapdosEntity->axObj.info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
}

void ZapdosScreenFlash(s32 numFlashes)
{
  s32 iVar1;
  s32 iVar2;

  PlaySoundEffect(0x1f6);
  if (2 < numFlashes) {
    for(iVar2 = 250; iVar2 > 199; iVar2 -= 10)
    {
      SetDungeonBGColorRGB(iVar2,iVar2,iVar2 / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  if (1 < numFlashes) {
    for(iVar2 = 250; iVar2 > 199; iVar2 -= 10)
    {
      SetDungeonBGColorRGB(iVar2,iVar2,iVar2 / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  for(iVar2 = 250; iVar2 >= 0; iVar2 -= 10)
  {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 3;
    }
    SetDungeonBGColorRGB(iVar2,iVar2,iVar1 >> 2,1,1);
    sub_803E46C(0x46);
  }
  sub_8085EB0();
}

void sub_80877E8(void)
{
  Entity * LeaderEntity;
  Entity * MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  MoltresEntity = GetEntityFromClientType(9);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MoltresEntity, DIRECTION_SOUTH);
  sub_8086A3C(MoltresEntity);
  sub_8085860(LeaderEntity->pos.x + -3,LeaderEntity->pos.y + -2);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_MOLTRES);
}

void sub_8087848(void)
{
  Entity *LeaderEntity;
  Entity *MoltresEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  MoltresEntity = GetEntityFromClientType(9);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8068FE0(MoltresEntity,0x21c,0);
  }
  else {
    sub_8072008(MoltresEntity,MoltresEntity,gUnknown_80F57CE,0,0);
    SetFacingDirection(MoltresEntity, DIRECTION_SOUTH);
    sub_8086A3C(MoltresEntity);
  }
  sub_8085860(LeaderEntity->pos.x - 5, LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos, YPos + -0x1000);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_MOLTRES);
}

void sub_80878F4(u8 param_1, u8 param_2)
{
  if ((param_2 == 0xA || param_2 == 0xB || param_2 == 0xC) && (param_1 == 0x9)) {
    sub_8097FA8(0x7);
    gDungeon->unk2 = 1;
  }
}

void MoltresPreFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *PartnerEntity;
  Entity *MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  MoltresEntity = GetEntityFromClientType(9);
  MoltresScreenFlash1(0xc,5);
  sub_8086500();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,5);
  sub_803E708(4,0x46);
  SpriteLookAroundEffect(PartnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_2);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_4);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,2,6);
  sub_8086690();
  DisplayDungeonDialogue(gMoltresPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  PlaySoundEffect(0x2f2);
  DungeonStopBGM();
  MoltresScreenDarken();
  DisplayDungeonDialogue(gMoltresPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1cf);
  sub_80856E0(PartnerEntity, DIRECTION_NORTH);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_8);
  sub_803E708(10,0x46);
  MoltresScreenFlash3();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_9);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(9,5);
  MoltresScreenFlash2(0xb,5);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_10);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  MoltresDropInEffect(MoltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(gMoltresPreFightDialogue_11);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_12);
  sub_803E708(10,0x46);
  SetupBossFightHP(MoltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}


void MoltresReFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *PartnerEntity;
  Entity *MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  MoltresEntity = GetEntityFromClientType(9);
  MoltresScreenFlash1(10,5);
  sub_8086500();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(PartnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresReFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(gMoltresReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,2,6);
  sub_80869E4(LeaderEntity,4,2,6);
  sub_8086690();
  MoltresScreenDarken();
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  MoltresDropInEffect(MoltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(gMoltresReFightDialogue_3);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(gMoltresReFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresReFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(MoltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void MoltresPostStoryPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * MoltresEntity;

  LeaderEntity = xxx_call_GetLeader();
  MoltresEntity = GetEntityFromClientType(9);
  MoltresScreenFlash1(0xc,5);
  sub_808654C();
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    sub_803E708(4,0x46);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(gUnknown_8100D3C);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(gMoltresPostStoryPreFightDialogue_1);
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    MoltresDropInEffect(MoltresEntity);
    DisplayDungeonDialogue(gMoltresPostStoryPreFightDialogue_2);
    MoltresScreenFlash1(0xc,5);
    MoltresScreenFlash2(9,5);
    DisplayDungeonDialogue(gMoltresPostStoryPreFightDialogue_3);
    MoltresScreenFlash3();
    DisplayDungeonDialogue(gMoltresPostStoryPreFightDialogue_4);
    MoltresScreenFlash2(0xb,6);
    DisplayDungeonDialogue(gMoltresPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(MoltresEntity,400,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void MoltresDropInEffect(Entity * moltresEntity)
{
  s32 iVar1;

  moltresEntity->axObj.info->unk15C = 1;
  moltresEntity->axObj.info->unk15E = 0;
  moltresEntity->axObj.info->unk174 = 0xc800;
  PlaySoundEffect(0x1f8);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    moltresEntity->axObj.info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
}

NAKED
void MoltresScreenFlash1(s32 r0, s32 r1)
{
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0x8\n"
	"\tadds r3, r1, 0\n"
	"\tlsls r1, r0, 1\n"
	"\tadds r1, r0\n"
	"\tlsls r1, 11\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 4\n"
	"\tadds r0, r1, r2\n"
	"\tcmp r0, 0\n"
	"\tbge _08087D98\n"
	"\tadds r0, 0xFF\n"
"_08087D98:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tldr r1, _08087DE0\n"
	"\tldr r2, [sp, 0x4]\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 11\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 5\n"
	"\tadds r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbge _08087DB8\n"
	"\tadds r0, 0xFF\n"
"_08087DB8:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tlsls r0, 16\n"
	"\tldr r1, _08087DE4\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r0, 0xB9\n"
	"\tlsls r0, 1\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [sp]\n"
	"\tmovs r1, 0x10\n"
	"\tmovs r2, 0\n"
	"\tadd r3, sp, 0x4\n"
	"\tbl sub_8085EC8\n"
	"\tadd sp, 0x8\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08087DE0: .4byte 0xffff0000\n"
"_08087DE4: .4byte 0x0000ffff");
}

NAKED
void MoltresScreenFlash2(s32 r0, s32 r1)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tsub sp, 0x8\n"
	"\tadds r3, r1, 0\n"
	"\tlsls r1, r0, 1\n"
	"\tadds r1, r0\n"
	"\tlsls r1, 11\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 4\n"
	"\tadds r0, r1, r2\n"
	"\tcmp r0, 0\n"
	"\tbge _08087E00\n"
	"\tadds r0, 0xFF\n"
"_08087E00:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tldr r1, _08087EA8\n"
	"\tldr r2, [sp, 0x4]\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 11\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 5\n"
	"\tadds r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbge _08087E20\n"
	"\tadds r0, 0xFF\n"
"_08087E20:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tlsls r0, 16\n"
	"\tldr r1, _08087EAC\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r0, 0xB9\n"
	"\tlsls r0, 1\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [sp]\n"
	"\tmovs r1, 0x16\n"
	"\tmovs r2, 0\n"
	"\tadd r3, sp, 0x4\n"
	"\tbl sub_8085EC8\n"
	"\tadds r6, r0, 0\n"
	"\tmovs r0, 0xF6\n"
	"\tlsls r0, 1\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r4, 0xFA\n"
	"\tmovs r5, 0x1\n"
"_08087E4E:\n"
	"\tstr r5, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl SetDungeonBGColorRGB\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
	"\tsubs r4, 0xA\n"
	"\tcmp r4, 0x13\n"
	"\tbgt _08087E4E\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r4, 0xFA\n"
	"\tmovs r5, 0x1\n"
"_08087E74:\n"
	"\tstr r5, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl SetDungeonBGColorRGB\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
	"\tsubs r4, 0xA\n"
	"\tcmp r4, 0\n"
	"\tbge _08087E74\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tbl sub_8085EB0\n"
	"\tadds r0, r6, 0\n"
	"\tbl sub_8085F44\n"
	"\tadd sp, 0x8\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08087EA8: .4byte 0xffff0000\n"
"_08087EAC: .4byte 0x0000ffff");
}

void MoltresScreenFlash3(void)
{
  int iVar1;

  PlaySoundEffect(0x1ed);
  iVar1 = 0xfa;
  for(iVar1 = 250; iVar1 > 9; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  sub_8085EB0();
}

void MoltresScreenDarken(void)
{
  s32 iVar1;

  for(iVar1 = 0; iVar1 >= -80; iVar1 -= 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}


void sub_8087F54(void)
{
  Entity  *LeaderEntity;
  Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(ArticunoEntity, DIRECTION_SOUTH);
  sub_8086A3C(ArticunoEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ARTICUNO);
}

void sub_8087FB4(void)
{
  Entity  *ArticunoEntity;

  ArticunoEntity = GetEntityFromClientType(0xd);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(ArticunoEntity, DIRECTION_SOUTH);
  sub_806CDD4(ArticunoEntity, 0xF, DIRECTION_SOUTH);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ARTICUNO);
}

void sub_8087FF8(void)
{
  Entity  *LeaderEntity;
  Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_8068FE0(ArticunoEntity,0x21c,0);
  }
  else {
    sub_8072008(ArticunoEntity,ArticunoEntity,gUnknown_80F57D0,0,0);
    SetFacingDirection(ArticunoEntity, DIRECTION_SOUTH);
    sub_8086A3C(ArticunoEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ARTICUNO);
}

void sub_8088088(u8 param_1, u8 param_2)
{
  if ((param_2 == 0xD || param_2 == 0xE || param_2 == 0xF) && (param_1 == 0xD)) {
    sub_8097FA8(0x9);
    gDungeon->unk2 = 1;
  }
}

void ArticunoPreFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *PartnerEntity;
  Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  ArticunoEntity = GetEntityFromClientType(0xd);
  sub_8086448();
  SpriteLookAroundEffect(PartnerEntity);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_8086598();
  DungeonStopBGM();
  DisplayDungeonDialogue(gArticunoPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_3);
  sub_803E708(10,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_SOUTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(LeaderEntity, DIRECTION_WEST);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_80869E4(LeaderEntity,4,1,4);
  sub_80869E4(PartnerEntity,4,2,4);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(LeaderEntity);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0); // snow flurry
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  PlaySoundEffect(0x1ee); // flash effect?
  sub_8088574();
  DisplayDungeonDialogue(gArticunoPreFightDialogue_8);
  sub_803E708(10,0x46);
  ArticunoScreenFlash();
  sub_8086738();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_9);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1ea);
  sub_8088484(ArticunoEntity);
  sub_80865E8();
  ArticunoScreenFlash();
  DisplayDungeonDialogue(gArticunoPreFightDialogue_10);
  sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(gArticunoPreFightDialogue_11);
  sub_806CDD4(ArticunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(gArticunoPreFightDialogue_12);
  sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x10,0x46);
  SetupBossFightHP(ArticunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void ArticunoReFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gArticunoReFightDialogue_1);
  sub_806CDD4(ArticunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(gArticunoReFightDialogue_2);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(gArticunoReFightDialogue_3);
  sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x28,0x46);
  SetupBossFightHP(ArticunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void ArticunoPostStoryPreFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *ArticunoEntity;

  LeaderEntity = xxx_call_GetLeader();
  ArticunoEntity = GetEntityFromClientType(0xd);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_80866C4(gUnknown_8102A9C);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_SNOW;
    sub_807EAA0(0,1);
    ArticunoScreenFlash();
    sub_8086738();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(gArticunoPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    sub_8088484(ArticunoEntity);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(gArticunoPostStoryPreFightDialogue_2);
    sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(gArticunoPostStoryPreFightDialogue_3);
    sub_806CDD4(ArticunoEntity,0x10,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(gArticunoPostStoryPreFightDialogue_4);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(gArticunoPostStoryPreFightDialogue_5);
    sub_806CDD4(ArticunoEntity,0xf,DIRECTION_SOUTH);
    sub_803E708(0x28,0x46);
    SetupBossFightHP(ArticunoEntity,0x1c2,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void sub_8088484(Entity *param_1)
{
  int iVar1;

  param_1->axObj.info->unk15C = 1;
  param_1->axObj.info->unk15E = 0;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 5)
  {
    param_1->axObj.info->unk174 = iVar1 * 256;
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,0);
    sub_803E46C(0x46);
  }
}

void ArticunoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x2ad);
  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  sub_8085EB0();
}

void sub_8088574(void)
{
  int iVar1;

  for(iVar1 = 0; iVar1 <= 80; iVar1 += 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}

void sub_80885A0(void)
{
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
}

void sub_80885C4(void)
{
  Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
}

void sub_8088608(void)
{
    gDungeon->unk2 = 1;
}

void sub_8088618(void)
{
    sub_8086448();
    // The mountain's summit...
    // But there is no one here
    // It's time to go back
    sub_80866C4(gUnknown_8102B10);
}

void sub_808862C(void)
{
  Entity * LeaderEntity;
  Entity * AlakazamEntity;
  Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(AlakazamEntity, DIRECTION_NORTH);
  sub_80861D4(AlakazamEntity,0xd,DIRECTION_NORTH);
  SetFacingDirection(GroudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(GroudonEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_80886C4(void)
{
  Entity * LeaderEntity;
  Entity * AlakazamEntity;
  Entity * GroudonEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  PlaySoundEffect(0x3e5);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8068FE0(AlakazamEntity,0x21c,0);
  SetFacingDirection(GroudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(GroudonEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_808875C(void)
{
  Entity * LeaderEntity;
  Entity * AlakazamEntity;
  Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_80867F4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(AlakazamEntity,0x21c,0);
  if (sub_8086AE4(MONSTER_GROUDON)) {
    sub_8068FE0(GroudonEntity,0x21c,0);
  }
  else {
    sub_8072008(GroudonEntity,GroudonEntity,gUnknown_80F57D2,0,0);
    SetFacingDirection(GroudonEntity, DIRECTION_SOUTH);
    sub_80861D4(GroudonEntity,0xf,DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
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
  Entity * LeaderEntity;
  Entity * PartnerEntity;
  Entity * AlakazamEntity;
  Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  AlakazamEntity = GetEntityFromClientType(10);
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_8086448();
  DisplayDungeonDialogue(GroudonPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_808682C();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_4);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  DisplayDungeonDialogue(GroudonPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_6);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  DisplayDungeonDialogue(GroudonPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_80861B8(AlakazamEntity,6,DIRECTION_NORTH);
  PlaySoundEffect(0x205);
  sub_8086738();
  sub_8068FE0(AlakazamEntity,0x21c,0);
  DisplayDungeonDialogue(GroudonPreFightDialogue_8);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_9);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  sub_803E708(0x28,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
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
  DisplayDungeonDialogue(GroudonPreFightDialogue_12);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_13);
  sub_803E708(10,0x46);
  sub_803E708(0x1e,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(GroudonPreFightDialogue_14);
  sub_803E708(10,0x46);
  sub_8086A54(GroudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(GroudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void GroudonReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_1);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_2);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_3);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  DisplayDungeonDialogue(gGroudonReFightDialogue_4);
  sub_803E708(10,0x46);
  sub_8086A54(GroudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(GroudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void GroudonPostStoryPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * GroudonEntity;

  LeaderEntity = xxx_call_GetLeader();
  GroudonEntity = GetEntityFromClientType(0xe);
  sub_8086448();
  if (sub_8086AE4(MONSTER_GROUDON)) {
      sub_80866C4(gUnknown_8103488);
  }
  else{
    DisplayDungeonDialogue(gGroudonPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    SceneGroudonMovement(GroudonEntity);
    SceneGroudonMovement(GroudonEntity);
    DisplayDungeonDialogue(gGroudonPostStoryPreFightDialogue_2);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(gGroudonPostStoryPreFightDialogue_3);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(gGroudonPostStoryPreFightDialogue_4);
    sub_803E708(10,0x46);
    SetupBossFightHP(GroudonEntity,500,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

// Moves Groudon down in a walking fashion
void SceneGroudonMovement(Entity * GroudonEntity)
{
  int iVar1;

  sub_8086848(0x18,0x10);
  sub_806CDD4(GroudonEntity,0,DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 0x2C; iVar1++)
  {
    if ((iVar1 == 10) || (iVar1 == 0x20)) {
      PlaySoundEffect(0x1f9);
      sub_8086838(0,1,0);
      sub_808680C();
    }
    if ((iVar1 - 10U < 0xc) || (iVar1 > 0x1f)) {
      IncreaseEntityPixelPos(GroudonEntity,0,0x100);
    }
    sub_803E46C(0x46);
  }
  sub_80856C8(GroudonEntity,GroudonEntity->pos.x,GroudonEntity->pos.y + 1);
  sub_80861D4(GroudonEntity,0xf,DIRECTION_SOUTH);
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
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
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
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}


void sub_8088DC0(void)
{
  Entity * LeaderEntity;
  Entity * uVar2;
  Entity * uVar3;

  LeaderEntity = xxx_call_GetLeader();
  uVar2 = GetEntityFromClientType(0xb);
  uVar3 = GetEntityFromClientType(0xc);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(uVar2);
  sub_806CDD4(uVar2,0xe,DIRECTION_SOUTH);
  sub_8086A3C(uVar3);
  sub_806CDD4(uVar3,0xe,DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_8088E5C(void)
{
  Entity * LeaderEntity;
  Entity * uVar2;
  Entity * uVar3;

  LeaderEntity = xxx_call_GetLeader();
  uVar2 = GetEntityFromClientType(0xb);
  uVar3 = GetEntityFromClientType(0xc);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(uVar2,0x21c,0);
  sub_8068FE0(uVar3,0x21c,0);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_GROUDON);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ALAKAZAM);
}

void sub_8088EE8(void)
{
    sub_8086854();
}


void MagmaCavernMidDialogue(void)
{
  Entity * LeaderEntity;
  Entity * PartnerEntity;
  Entity * iVar3;
  Entity * iVar4;
  s16 IDStack [2];
  Position32 local_20;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  iVar3 = GetEntityFromClientType(0xb);
  iVar4 = GetEntityFromClientType(0xc);
  sub_8052D44(IDStack,LeaderEntity,PartnerEntity);
  sub_8086448();
  SpriteLookAroundEffect(PartnerEntity);
  // Let's see..
  // I wonder where we are?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
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
  DisplayDungeonDialogue(MagmaCavernMidDialogue_3);
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
  SpriteLookAroundEffect(PartnerEntity);
  PlaySoundEffect(0x1c7);
  sub_80856E0(PartnerEntity, DIRECTION_NORTH);
  // Hey! {ARG_POKEMON_0}!
  // Over there!
  DisplayDungeonDialogue(MagmaCavernMidDialogue_5);
  iVar3->axObj.info->unk15E = 0;
  iVar4->axObj.info->unk15E =0;
  local_20.x = (iVar3->pixelPos.x + iVar4->pixelPos.x) / 2;
  local_20.y = (iVar3->pixelPos.y + iVar4->pixelPos.y) / 2 + 0x800;
  ShiftCameraToPosition(&local_20,0x20);
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
  DisplayDungeonDialogue(MagmaCavernMidDialogue_7);
  sub_803E708(10,0x46);
  sub_80869E4(LeaderEntity,4,2,5);
  // What happened to you?
  //
  // What happened here?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_8);
  sub_803E708(10,0x46);
  // We challenged..
  // {ARG_POKEMON_2}...
  // And wiped out..
  DisplayDungeonDialogue(MagmaCavernMidDialogue_9);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(MagmaCavernMidDialogue_10);
  sub_803E708(10,0x46);
  sub_80869E4(LeaderEntity,4,1,3);
  sub_80869E4(PartnerEntity,4,1,3);
  // Grrgh..
  // We... It crushed us
  DisplayDungeonDialogue(MagmaCavernMidDialogue_11);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(PartnerEntity);
  // That's right...
  // What happened to {ARG_POKEMON_3}?
  // Where is {ARG_POKEMON_3}?
  //
  // Wait...
  // What about {ARG_POKEMON_3}?
  // Where did {ARG_POKEMON_3} go?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_12);
  sub_803E708(0x1e,0x46);
  // {ARG_POKEMON_3} is...
  // Still battling {ARG_POKEMON_2}...
  DisplayDungeonDialogue(MagmaCavernMidDialogue_13);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  // {ARG_POKEMON_0}!
  // We've got to hurry!
  DisplayDungeonDialogue(MagmaCavernMidDialogue_14);
  sub_8089294();
  // Be careful!
  DisplayDungeonDialogue(MagmaCavernMidDialogue_15);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void sub_8089168(void)
{
  Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(LeaderEntity);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_808919C(Entity *r0)
{
    IncreaseEntityPixelPos(r0, 0, 0xfffffe00);
}

void sub_80891B0(Entity *r0)
{
    sub_806CDD4(r0, 0, DIRECTION_NORTH);
    r0->axObj.info->unk15F = 1;
}


void sub_80891D0(Entity *r0)
{
    sub_806CDD4(r0, 7, DIRECTION_NORTH);
    r0->axObj.info->unk15F = 0;
}

void sub_80891F0(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 < 0x30; iVar1++)
  {
    sub_80855E4(sub_808919C);
    sub_803E46C(0x46);
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
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_80892C8(void)
{
  Entity * LeaderEntity;
  Entity * RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(RayquazaEntity, DIRECTION_SOUTH);
  sub_8086A3C(RayquazaEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_RAYQUAZA);
}

void sub_8089328(void)
{
  Entity * LeaderEntity;
  Entity * RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_8068FE0(RayquazaEntity,0x21c,0);
  }
  else {
    sub_8072008(RayquazaEntity,RayquazaEntity,gUnknown_80F57CA,0,0);
    sub_8086A3C(RayquazaEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_RAYQUAZA);
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
  Entity *LeaderEntity;
  Entity *PartnerEntity;
  Entity *RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  PartnerEntity = GetPartnerEntity();
  RayquazaEntity = GetEntityFromClientType(0xf);
  sub_8086448();
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_2);
  sub_80856E0(PartnerEntity, DIRECTION_NORTH);
  SpriteLookAroundEffect(PartnerEntity);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_3);
  sub_80869E4(PartnerEntity,4,2,4);
  sub_80869E4(LeaderEntity,4,1,4);
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_6);
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_7);
  RayquazaDropInEffect(RayquazaEntity);
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_8);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_9);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_10);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_11);
  SetupBossFightHP(RayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RayquazaReFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  sub_8086448();
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(gRayquazaPreFightDialogue_7);
  sub_803E708(10,0x46);
  RayquazaDropInEffect(RayquazaEntity);
  DisplayDungeonDialogue(gRayquazaReFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaReFightDialogue_2);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaReFightDialogue_3);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(gRayquazaReFightDialogue_4);
  SetupBossFightHP(RayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RayquazaPostStoryPreFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *RayquazaEntity;

  LeaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromClientType(0xf);
  sub_8086448();
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_80866C4(gRayquazaPostStoryPreFightDialogue_6);
  }
  else {
    PlaySoundEffect(0x1da); // Rayquaza Cry
    DisplayDungeonDialogue(gRayquazaPostStoryPreFightDialogue_1);
    RayquazaDropInEffect(RayquazaEntity);
    DisplayDungeonDialogue(gRayquazaPostStoryPreFightDialogue_2);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(gRayquazaPostStoryPreFightDialogue_3);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(gRayquazaPostStoryPreFightDialogue_4);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(gRayquazaPostStoryPreFightDialogue_5);
    SetupBossFightHP(RayquazaEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void RayquazaDropInEffect(Entity *rayquazaEntity)
{
  s32 iVar1;
  s32 iVar2;

  rayquazaEntity->axObj.info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x600;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 0x18;
    if (iVar1 < 0x14) {
      iVar1 = 0x14;
    }
    if (iVar2 < 0) break;
    rayquazaEntity->axObj.info->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  rayquazaEntity->axObj.info->unk174 = 0;
}

void RayquazaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}


void sub_808970C(void)
{
  Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_TINY_WOODS);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
}

void sub_808974C(void)
{
  Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -3);
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
      if ((EntityExists(monEntity)) && (monEntity != entity) && (monEntity->axObj.info->clientType == param_2)) {
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
  Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(gUnknown_8103BD8);
  // We don't like to brag or
  // nothing, but
  DisplayDungeonDialogue(gUnknown_8103C00);
  // We get furious real easy
  // You know that?!
  DisplayDungeonDialogue(gUnknown_8103C3C);
  // What really irritates us is
  // when we see some dim witted face
  DisplayDungeonDialogue(gUnknown_8103C74);
  // .........
  // Wrooooooar!
  // That vacant expression
  DisplayDungeonDialogue(gUnknown_8103CC4);
  // Gwoooh
  // It's ticking me off!
  // I'm seeing red!
  DisplayDungeonDialogue(gUnknown_8103D0C);
  // Mukkkeeeeeh
  // Get 'em! It's frenzy time!
  DisplayDungeonDialogue(gUnknown_8103D50);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}



void sub_8089878(void)
{
  Entity *LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(gUnknown_8103D8C);
  DisplayDungeonDialogue(gUnknown_8103D98);
  DisplayDungeonDialogue(gUnknown_8103DD8);
  DisplayDungeonDialogue(gUnknown_8103E28);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(gUnknown_8103E34);
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
  Entity *LeaderEntity;
  Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
  sub_8086A3C(MewtwoEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_MEWTWO);
}

void sub_8089978(void)
{
  Entity *LeaderEntity;
  Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
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
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_MEWTWO);
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
  Entity *LeaderEntity;
  Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  sub_8086448();
  DisplayDungeonDialogue(gMewtwoPreFightDialogue_1);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  sub_8086794();
  sub_803E708(0x1e,0x46);
  MewtwoDropInEffect(MewtwoEntity);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(gMewtwoPreFightDialogue_2);
  DisplayDungeonDialogue(gMewtwoPreFightDialogue_3);
  sub_803E708(10,0x46);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(gMewtwoPreFightDialogue_4);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(gMewtwoPreFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void MewtwoReFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *MewtwoEntity;

  LeaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromClientType(0x11);
  sub_8086448();
  if(HasRecruitedMon(MONSTER_MEWTWO)) {
    sub_80866C4(gMewtwoReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(gMewtwoReFightDialogue_1);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8086794();
    MewtwoDropInEffect(MewtwoEntity);
    sub_803E708(0x3c,0x46);
    DisplayDungeonDialogue(gMewtwoReFightDialogue_2);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(gMewtwoReFightDialogue_3);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(gMewtwoReFightDialogue_4);
    SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void MewtwoDropInEffect(Entity *mewtwoEntity)
{
  s32 iVar1;
  s32 iVar2;

  mewtwoEntity->axObj.info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x400;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 11;
    if (iVar1 < 0x1e) {
      iVar1 = 0x1e;
    }
    if (iVar2 < 0) break;
    mewtwoEntity->axObj.info->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  mewtwoEntity->axObj.info->unk174 = 0;
}

void MewtwoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_8089C44(void)
{
  Entity * LeaderEntity;
  Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ENTEI);
}


void sub_8089C90(void)
{
  Entity * LeaderEntity;
  Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
      sub_8068FE0(EnteiEntity,0x21c,0);
  }
  else {
      SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_ENTEI);
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
  Entity * LeaderEntity;
  Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  EnteiScreenFlash();
  DisplayDungeonDialogue(gEnteiPreFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(gEnteiPreFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(gEnteiPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void EnteiReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  EnteiScreenFlash();
  DisplayDungeonDialogue(gEnteiReFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(gEnteiReFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(gEnteiReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void EnteiPostStoryPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * EnteiEntity;

  LeaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromClientType(0x12);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
    sub_80866C4(gEnteiPostStoryPreFightDialogue_4);
  }
  else {
    EnteiScreenFlash();
    DisplayDungeonDialogue(gEnteiPostStoryPreFightDialogue_1);
    EnteiScreenFlash();
    DisplayDungeonDialogue(gEnteiPostStoryPreFightDialogue_2);
    EnteiScreenFlash();
    DisplayDungeonDialogue(gEnteiPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void EnteiScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, 0, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_8089EFC(void)
{
  Entity * LeaderEntity;
  Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_RAIKOU);
}


void sub_8089F44(void)
{
  Entity * LeaderEntity;
  Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_RAIKOU);
}


void sub_8089F8C(void)
{
  Entity * LeaderEntity;
  Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
      sub_8068FE0(RaikouEntity,0x21c,0);
  }
  else {
      SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_RAIKOU);
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
  Entity * LeaderEntity;
  Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  DisplayDungeonDialogue(gRaikouPreFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouPreFightDialogue_2);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(gRaikouPreFightDialogue_3);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouPreFightDialogue_4);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouPreFightDialogue_5);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RaikouReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouReFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouReFightDialogue_2);
  RaikouScreenFlash();
  DisplayDungeonDialogue(gRaikouReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void RaikouPostStoryPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * RaikouEntity;

  LeaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromClientType(0x13);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
    sub_80866C4(gRaikouPostStoryPreFightDialogue_4);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_RAIN;
    sub_807EAA0(0,1);
    DisplayDungeonDialogue(gRaikouPostStoryPreFightDialogue_1);
    RaikouScreenFlash();
    DisplayDungeonDialogue(gRaikouPostStoryPreFightDialogue_2);
    RaikouScreenFlash();
    DisplayDungeonDialogue(gRaikouPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A264(void)
{
  Entity * LeaderEntity;
  Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8086A3C(SuicuneEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SUICUNE);
}

void sub_808A2C0(void)
{
  Entity * LeaderEntity;
  Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SUICUNE);
}

void sub_808A308(void)
{
  Entity * LeaderEntity;
  Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
     sub_8068FE0(SuicuneEntity,0x21c,0);
  }
  else {
     SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SUICUNE);
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
  Entity * LeaderEntity;
  Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  sub_8086448();
  DisplayDungeonDialogue(gSuicunePreFightDialogue_1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(gSuicunePreFightDialogue_2);
  sub_803E708(10,70);
  sub_80426C8(1,2);
  sub_803E708(0x3c,70);
  DisplayDungeonDialogue(gSuicunePreFightDialogue_3);
  sub_803E708(10,70);
  sub_808A528(SuicuneEntity);
  DisplayDungeonDialogue(gSuicunePreFightDialogue_4);
  DisplayDungeonDialogue(gSuicunePreFightDialogue_5);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(gSuicunePreFightDialogue_6);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(gSuicunePreFightDialogue_7);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void SuicuneReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  DisplayDungeonDialogue(gSuicuneReFightDialogue_1);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(gSuicuneReFightDialogue_2);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(gSuicuneReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void SuicunePostStoryPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * SuicuneEntity;

  LeaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromClientType(0x14);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
    sub_80866C4(gSuicunePostStoryPreFightDialogue_4);
  }
  else {
    DisplayDungeonDialogue(gSuicunePostStoryPreFightDialogue_1);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(gSuicunePostStoryPreFightDialogue_2);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(gSuicunePostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void sub_808A528(Entity * param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->axObj.info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->axObj.info->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->axObj.info->unk174 = 0;
}

void SuicuneScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A608(void)
{
  Entity * LeaderEntity;
  Entity * HoOhEntity;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
  sub_8086A3C(HoOhEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -6);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_HO_OH);
}

void sub_808A668(void)
{
  Entity * LeaderEntity;
  Entity * HoOhEntity;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);
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
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 6);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_HO_OH);
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
  Entity * LeaderEntity;
  Entity * HoOhEntity;
  Position32 local_14;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);
  local_14.x = LeaderEntity->pixelPos.x;
  local_14.y = LeaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(gHoOhPreFightDialogue_1);
  sub_803E708(10,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(gHoOhPreFightDialogue_2);
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
  DisplayDungeonDialogue(gHoOhPreFightDialogue_3);
  DisplayDungeonDialogue(gHoOhPreFightDialogue_4);
  sub_803E708(0x1e,70);
  sub_803E708(0x1e,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(gHoOhPreFightDialogue_5);
  HoOhScreenFlash();
  DisplayDungeonDialogue(gHoOhPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void HoOhReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * HoOhEntity;
  Position32 local_14;

  LeaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromClientType(0x15);

  local_14.x = LeaderEntity->pixelPos.x;
  local_14.y = LeaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_80866C4(HoOhReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(HoOhReFightDialogue_1);
    HoOhScreenFlash();
    sub_80855E4(sub_80868F4);
    sub_808680C();
    sub_803E708(10,70);
    HoOhDropInEffect(HoOhEntity);
    sub_808682C();
    sub_80855E4(sub_8086910);
    sub_8085930(DIRECTION_NORTH);
    DisplayDungeonDialogue(HoOhReFightDialogue_2);
    HoOhScreenFlash();
    DisplayDungeonDialogue(HoOhReFightDialogue_3);
    HoOhScreenFlash();
    DisplayDungeonDialogue(HoOhReFightDialogue_4);
    sub_803E708(10,70);
    SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void HoOhDropInEffect(Entity * param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->axObj.info->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->axObj.info->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->axObj.info->unk174 = 0;
}

void HoOhScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A9E4(void)
{
  Entity * LeaderEntity;
  Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 4);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LATIOS);
}

void sub_808AA3C(void)
{
  Entity * LeaderEntity;
  Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LATIOS);
}

void sub_808AA94(void)
{
  Entity * LeaderEntity;
  Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(LatiosEntity,0x21c,0);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LATIOS);
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
  Entity * LeaderEntity;
  Entity * LatiosEntity;
  Position32 local_18;
  Position local_19;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);

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
  DisplayDungeonDialogue(gLatiosPreFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void LatiosReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * LatiosEntity;

  LeaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromClientType(0x16);
  sub_8086448();
  sub_808692C();
  DisplayDungeonDialogue(gLatiosReFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_808AC3C(void)
{
    sub_8086448();
    // There appears to be no one here
    sub_80866C4(gUnknown_8104FC8);
}

void LatiosScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  gUnknown_202EDC8 = 0x1f;
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808ACC0(void)
{
  Entity * uVar2;

  if (HasRecruitedMon(MONSTER_REGIROCK)) {
    uVar2 = GetEntityFromClientType(0x17);
    sub_8068FE0(uVar2,0x21c,0);
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
        CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_REGIROCK);
  }
}

void sub_808AD48(void)
{
  Entity * uVar2;

  if (HasRecruitedMon(MONSTER_REGICE)) {
    uVar2 = GetEntityFromClientType(0x18);
    sub_8068FE0(uVar2,0x21c,0);
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
        CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_REGICE);
  }
}

void sub_808ADCC(void)
{

  Entity * uVar2;

  if (HasRecruitedMon(MONSTER_REGISTEEL)) {
    uVar2 = GetEntityFromClientType(0x19);
    sub_8068FE0(uVar2,0x21c,0);
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
        CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_REGISTEEL);
  }
}

void sub_808AE54(char param_1,char param_2,u32 *param_3)
{
  Entity * LeaderEntity;
  s16 IDStack[2];
  Item item;


  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(ITEM_NOTHING);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&item,ITEM_ROCK_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      DisplayDungeonDialogue(gRegirockPostFightDialogue_1);
    }
  }
}


void sub_808AEC8(char param_1,char param_2,u32 *param_3)
{
  Entity * LeaderEntity;
  s16 IDStack[2];
  Item item;


  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(ITEM_NOTHING);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&item,ITEM_ICE_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      DisplayDungeonDialogue(gRegicePostFightDialogue_1);
    }
  }
}

void sub_808AF3C(char param_1,char param_2,u32 *param_3)
{
  Entity * LeaderEntity;
  s16 IDStack[2];
  Item item;


  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(ITEM_NOTHING);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&item,ITEM_STEEL_PART,0);
      sub_80464C8(GetLeader(),param_3, &item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      DisplayDungeonDialogue(gRegisteelPostFightDialogue_1);
    }
  }
}

void sub_808AFB0(char param_1)
{
  Entity * LeaderEntity;
  s16 IDStack [2];

  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2E) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ROCK_PART) != 0)) {
    sub_8097FD0(0x1d);
    SetMessageArgument(gAvailablePokemonNames,GetLeader(),0);
    // {ARG_POKEMON_0} obtained the Rock Part that Regirock was guarding
    DisplayDungeonDialogue(gRegirockPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B030(char param_1)
{
  Entity * LeaderEntity;
  s16 IDStack [2];

  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2F) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ICE_PART) != 0)) {
    sub_8097FD0(0x1d);
    SetMessageArgument(gAvailablePokemonNames,GetLeader(),0);
    // {ARG_POKEMON_0} obtained the Ice Part that Regice was guarding
    DisplayDungeonDialogue(gRegicePostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B0B0(char param_1)
{
  Entity * LeaderEntity;
  s16 IDStack [2];

  LeaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,LeaderEntity,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x30) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_STEEL_PART) != 0)) {
    sub_8097FD0(0x1d);
    SetMessageArgument(gAvailablePokemonNames, GetLeader(), 0);
    // {ARG_POKEMON_0} obtained the Steel Part that Registeel was guarding
    DisplayDungeonDialogue(gRegisteelPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void RegirockPreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(gRegirockPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegirockFightHP);
  }
}

void RegicePreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(gRegicePreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegiceFightHP);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(gRegisteelPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegisteelFightHP);
  }
}

void sub_808B1CC(u8 itemID)
{
    Entity *entity;
    Tile *tile;
    Position pos;
    Item item;

    pos.x = gDungeon->unk684;
    pos.y = gDungeon->unk686;
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
    tile = GetTileSafe(pos.x, pos.y);
    tile->terrainType = tile->terrainType | TERRAIN_TYPE_STAIRS;
    if (((itemID != ITEM_NOTHING) && (sub_80860A8(itemID) == 0)) &&
        (sub_80860A8(ITEM_MUSIC_BOX) == 0)) {
        xxx_init_itemslot_8090A8C(&item,itemID,0);
        pos.y--;
        sub_80460F8(&pos,&item,1);
    }
    sub_8049ED4();
    sub_8040A84();
}

void SetupRegiFacingDirection(Entity *regiEntity)
{
    regiEntity->axObj.info->action.direction = DIRECTION_NORTH;
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

void sub_808B2F4(void)
{
  Entity * LeaderEntity;
  Entity * JirachiEntity;

  LeaderEntity = xxx_call_GetLeader();
  JirachiEntity = GetEntityFromClientType(0x1a);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  CreateJirachiWishWarpTile();
  sub_8049ED4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(JirachiEntity, DIRECTION_SOUTH);
  sub_8086A3C(JirachiEntity);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
}

void sub_808B35C(void)
{
  Entity * LeaderEntity;
  Entity * JirachiEntity;

  LeaderEntity = xxx_call_GetLeader();
  JirachiEntity = GetEntityFromClientType(0x1a);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_JIRACHI)) {
    sub_8068FE0(JirachiEntity,0x21c,0);
  }
  else {
    SetFacingDirection(JirachiEntity, DIRECTION_SOUTH);
    sub_8086A3C(JirachiEntity);
    CreateJirachiWishWarpTile();
    sub_8049ED4();

  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
}

void sub_808B3E4(u8 param_1, u8 param_2, u8 param_3)
{
  u8 uVar1;
  if ((param_2 == 0x31 || param_2 == 0x32) && (param_1 == 0x1A)) {
    sub_8097FA8(0x1E);
    if(param_3 != 0)
    {
        gDungeon->unk2 = 1;
    }
    else {
        uVar1 = gDungeon->unk1356C;
        if(sub_80860A8(0x36) != 0)
        {
            JirachiWish();
        }
        else
        {
            sub_808B50C();
        }
        gDungeon->unk1356C = uVar1;
        sub_8040A84();
    }
  }
}

void JirachiPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * JirachiEntity;

  LeaderEntity = xxx_call_GetLeader();
  JirachiEntity = GetEntityFromClientType(0x1a);
  sub_8086448();
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(gJirachiPreFightDialogue_1);
  sub_803E708(10,70);
  SpriteLookAroundEffect(LeaderEntity);
  sub_803E708(10,70);
  DisplayDungeonDialogue(gJirachiPreFightDialogue_2);
  sub_80861F8(0x37,JirachiEntity,1);
  sub_80855E4(SpriteShockEffect);
  sub_803E708(0x3c,70);
  JirachiDropInEffect(JirachiEntity);
  sub_803E708(0x5a,70);
  DisplayDungeonDialogue(gJirachiPreFightDialogue_3);
  sub_803E708(10,70);
  DisplayDungeonDialogue(gJirachiPreFightDialogue_4);
  sub_803E708(10,70);
  SetupBossFightHP(JirachiEntity,0x15e,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void sub_808B50C(void)
{
  Entity * JirachiEntity;

  JirachiEntity = GetEntityFromClientType(0x1a);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(JirachiEntity);
  sub_8041888(0);
  JirachiEntity->axObj.info->unk15C = 1;
  JirachiEntity->axObj.info->unk15E = 0;
  sub_80861B8(JirachiEntity,0xe,DIRECTION_SOUTH);
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,70);
  // Fwaaaahhhh
  DisplayDungeonDialogue(gUnknown_810554C);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  // I think I had a dream, and I was fighting in it
  // Did I imagine it?
  // I'm sleepy so I'm going back to sleep.
  DisplayDungeonDialogue(gUnknown_8105558);
  sub_803E708(10,70);
  JirachiSpinEffect(JirachiEntity);
  DisplayDungeonDialogue(gUnknown_81055F4);
  sub_803E708(10,70);
  gDungeon->unk2 = 1;
}

void JirachiWish(void)
{
  u8 friendArea;
  Entity *JirachiEntity;
  Position *LeaderPos;
  Entity *LeaderEntity;
  s32 wishChoice;
  s32 counter;
  u32 direction;
  s32 index;
  Item auStack152 [9];
  Item itemStack [9];
  Item strengthItems [9];
  Position pos1;
  Position pos2;
  Position pos3;

  JirachiEntity = GetEntityFromClientType(0x1a);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(JirachiEntity);
  sub_8041888(0);
  JirachiEntity->axObj.info->unk15C = 1;
  JirachiEntity->axObj.info->unk15E = 0;
  sub_80861B8(JirachiEntity,0xe,DIRECTION_SOUTH);
  sub_80855E4(sub_80861A8);
  gDungeon->unk1356C = 1;
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(gUnknown_8105668);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1a7);
  sub_803E708(0x96,0x46);
  SpriteShockEffect(JirachiEntity);
  DisplayDungeonDialogue(gUnknown_8105674);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_803E708(10,0x46);
  sub_80856E0(JirachiEntity, DIRECTION_SOUTH);
  PlaySoundEffect(0x16a);
  DisplayDungeonDialogue(gUnknown_81056B8);
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(JirachiEntity);
  DisplayDungeonDialogue(gUnknown_81056DC);
  sub_803E708(10,0x46);
  while( 1 ) {
    while (1) {
#ifndef NONMATCHING
        register s32 r0 asm("r0");
        asm("mov\t%0, #0":"=r"(r0));
#else
        s32 r0 = 0;
#endif
        wishChoice = sub_8052C68(r0,*gUnknown_8105798,gUnknown_810579C,0x705);
        if (wishChoice >= 1) break;
    }
    sub_803E708(10,0x46);
    if (wishChoice == 1) {
      s32 r8;
      // Lots of Money
      DisplayDungeonDialogue(gUnknown_810581C);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(JirachiEntity);

      for(counter = 0; counter < 6; counter = r8)
      {
        r8 = counter + 1;
        for(index = 0; index < 9; index++)
        {
          sub_8045C28(&auStack152[index], ITEM_POKE, 0);
        }
        pos1.x = (JirachiEntity->pos.x + DungeonRandInt(3) - 1);
        pos1.y = (JirachiEntity->pos.y + DungeonRandInt(3) + -1);
        if ((GetTileSafe(pos1.x, pos1.y)->terrainType & 3) != 0) {
          PlaySoundEffect(0x14c);
          sub_808BB3C(&pos1);
          sub_8046860(JirachiEntity,&pos1,auStack152,9);
        }
      }
      JirachiEntity->axObj.info->unk15D  = 0;
    }
    if (wishChoice == 2) {
      // Lots of Items
      DisplayDungeonDialogue(gUnknown_8105974);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(JirachiEntity);

      for(counter = 0; counter < 6; counter++)
      {
#ifndef NONMATCHING
        asm("":::"sl");
#endif
        for(index = 0; index < 9; index++)
        {
          sub_8045C28(&itemStack[index], sub_803D73C(0),0);
        }
        pos2.x = (JirachiEntity->pos.x + DungeonRandInt(3) - 1);
        pos2.y = (JirachiEntity->pos.y + DungeonRandInt(3) + -1);

        if ((GetTileSafe(pos2.x, pos2.y)->terrainType & 3) != 0) {
          PlaySoundEffect(400);
          sub_808BB3C(&pos2);
          sub_8046860(JirachiEntity,&pos2,itemStack,9);
        }
      }
      JirachiEntity->axObj.info->unk15D = 0;
    }

    if (wishChoice == 3)
    {
        // A Friend Area
        friendArea = JirachiFriendAreaSearch();
        if (friendArea == NUM_FRIEND_AREAS)
        {
            // You want a friend area? But you already have many friend areas...
            DisplayDungeonDialogue(gUnknown_8105A08);
            sub_803E708(10,0x46);
            continue;
        }
        else
        {
        // You want a friend area? As you wish..
          DisplayDungeonDialogue(gUnknown_8105AD4);
          sub_803E708(10,0x46);
          JirachiWishGrantDialogue(JirachiEntity);
          JirachiEntity->axObj.info->unk15D  = 0;
          DisplayDungeonDialogue(gUnknown_8105B20);
          UnlockFriendArea(friendArea);
          PlaySoundEffect(0xd4);
          LeaderEntity = GetLeader();
          SetMessageArgument(gAvailablePokemonNames,LeaderEntity,0);
          WriteFriendAreaName(gFormatItems,friendArea,FALSE);
          // Obtained the friend area!
          DisplayDungeonDialogue(gUnknown_8105B68);
        }
    }
    if (wishChoice == 4) {
        // More Strength..
        DisplayDungeonDialogue(gUnknown_8105BA8);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(JirachiEntity);

        for(counter = 0; counter < 5; counter++)
        {

          for(index = 0; index < 4; index++)
          {
            sub_8045C28(&strengthItems[index],gUnknown_81074FC[DungeonRandInt(8)],0);
          }

          pos3.x = (JirachiEntity->pos.x + DungeonRandInt(3) - 1);
          pos3.y = (JirachiEntity->pos.y + DungeonRandInt(3) + -1);

          if ((GetTileSafe(pos3.x, pos3.y)->terrainType & 3) != 0) {
            PlaySoundEffect(400);
            sub_808BB3C(&pos3);
            sub_8046860(JirachiEntity,&pos3,strengthItems,4);
          }
        }
        JirachiEntity->axObj.info->unk15D  = 0;
        DisplayDungeonDialogue(gUnknown_8105BF4);
        sub_803E708(10,0x46);
    }
    if (wishChoice == 5) {
        // Something Good...
        DisplayDungeonDialogue(gUnknown_8105D2C);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(JirachiEntity);
        JirachiEntity->axObj.info->unk15D  = 0;
        DisplayDungeonDialogue(gUnknown_8105D80);
        sub_803E708(10,0x46);
        LeaderPos = &GetLeader()->pos;
        direction = GetDirectionTowardsPosition(&JirachiEntity->pos,LeaderPos);
        SetFacingDirection(JirachiEntity,direction);
        sub_803E708(10,0x46);
        DisplayDungeonDialogue(gUnknown_8105D9C);
        sub_803E708(10,0x46);
        gDungeon->unk674 = 1;
    }
    break;
  }

  DisplayDungeonDialogue(gUnknown_81058E0);
  JirachiSpinEffect(JirachiEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gUnknown_810593C);
  sub_803E708(10,0x46);
  EnableJirachiWishWarpTile();
}

void JirachiReFightDialogue(void)
{
    if(HasRecruitedMon(MONSTER_JIRACHI))
    {
        sub_8086448();
        sub_80866C4(gJirachiReFightDialogue_1);
    }
    else
    {
        JirachiPreFightDialogue();
    }
}

void JirachiWishGrantFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  gUnknown_202EDC8 = 0x1f;

  for(iVar1 = 0xFA; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 > 0xC7; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808BB3C(Position *param_1)
{
#ifndef NONMATCHING
  register s32 iVar1 asm("r0");
#else
  s32 iVar1;
#endif
  Position local_8;

  iVar1 = param_1->x * 0x1800 + 0xc00;
  local_8.x = iVar1 / 256;

  iVar1 = param_1->y * 0x1800 + 0x1000;

  local_8.y = iVar1 / 256;
  sub_8085EC8(100,0,0,&local_8,0);
}

void sub_808BBA8(Entity *jirachiEntity)
{
  sub_806BFC0(jirachiEntity->axObj.info,0);
}

void JirachiDropInEffect(Entity *jirachiEntity)
{
  s32 iVar1;
  s32 iVar2;

  sub_80861F8(0x1b,jirachiEntity,0);
  sub_8086A54(jirachiEntity);
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  iVar1 = 0xa000;
  iVar2 = 0x200;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar1 = iVar1 - iVar2;
    if (iVar1 < 0x1800) {
      iVar2 = 0x100;
    }
    if (iVar1 < 0) break;
    jirachiEntity->axObj.info->unk174 = iVar1;
    sub_803E46C(0x46);
  }
 jirachiEntity->axObj.info->unk174 = 0;
}

void JirachiSpinEffect(Entity * jirachiEntity)
{
  s32 uVar1;

  PlaySoundEffect(0x298);
  for(uVar1 = 0; uVar1 < 25; uVar1++){
    SetFacingDirection(jirachiEntity, uVar1 & DIRECTION_MASK);
    sub_803E708(3,0x46);
  }
  jirachiEntity->axObj.info->unk15E = 1;
  PlaySoundEffect(0x27f);
  sub_80861F8(99,jirachiEntity,1);
}

void JirachiWishGrantDialogue(Entity *jirachiEntity)
{
  u32 uVar2;

  jirachiEntity->axObj.info->unk15D = 1;
  // Nnnnnnnnnn!
  DisplayDungeonDialogue(gUnknown_81058A8);
  PlaySoundEffect(0x375);
  sub_80861F8(0x67,jirachiEntity,1);
  PlaySoundEffect(0x2a8);
  uVar2 = sub_80861F8(0x68,jirachiEntity,0);
  // Taaaaaaaah!
  DisplayDungeonDialogue(gUnknown_81058C4);
  if (sub_800E9A8(uVar2)) {
    sub_800DC14(uVar2);
  }
  sub_803E708(10,0x46);
  JirachiWishGrantFlash();
}

// Warp Tile is created but not enabled until the Wish is done with EnableJirachiWishWarpTile
void CreateJirachiWishWarpTile(void)
{
  struct Tile *tile;

  tile = GetTileSafe(gDungeon->unkE220[7].x, gDungeon->unkE220[7].y);
  tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
  tile->terrainType &= ~TERRAIN_TYPE_STAIRS;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  sub_8040A84();
}

void EnableJirachiWishWarpTile(void)
{
  struct Tile *tile;

  tile = GetTileSafe(gDungeon->unkE220[7].x, gDungeon->unkE220[7].y);
  tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  tile->terrainType |= TERRAIN_TYPE_NORMAL;
  tile->terrainType &= ~TERRAIN_TYPE_IMPASSABLE_WALL;
  tile->terrainType |= TERRAIN_TYPE_STAIRS;
  tile->unk8 = 1;
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
    friendAreaIndex = DungeonRandInt(numUnlockableAreas);
    return friendAreas[friendAreaIndex];
  }
}

void sub_808BDEC(void)
{
  Entity * LeaderEntity;
  Entity * LugiaEntity;

  LeaderEntity = xxx_call_GetLeader();
  LugiaEntity = GetEntityFromClientType(0x1b);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8068FE0(LugiaEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(LugiaEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_LUGIA);
}

void sub_808BE70(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x33) && (param_1 == 0x1B)) {
    gDungeon->unk2 = 1;
  }
}


void LugiaPreFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * LugiaEntity;

  LeaderEntity = xxx_call_GetLeader();
  LugiaEntity = GetEntityFromClientType(0x1b);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    sub_8086448();
    sub_80866C4(gLugiaPreFightDialogue_8);
  }
  else {
    DungeonStopBGM();
    sub_8086448();
    DisplayDungeonDialogue(gLugiaPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C0CC();
    DisplayDungeonDialogue(gLugiaPreFightDialogue_2);
    LugiaScreenFlash();
    DisplayDungeonDialogue(gLugiaPreFightDialogue_3);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(gLugiaPreFightDialogue_4);
    PlaySoundEffect(0x1f8);
    sub_80861D4(LugiaEntity,0xd,DIRECTION_SOUTH);
    sub_803E708(0x2b,0x46);
    sub_80861B8(LugiaEntity,0,DIRECTION_SOUTH);
    DisplayDungeonDialogue(gLugiaPreFightDialogue_5);
    LugiaScreenFlash();
    DisplayDungeonDialogue(gLugiaPreFightDialogue_6);
    LugiaScreenFlash2();
    SetDungeonBGColorRGB(0xffffff06,0xffffff06,0xffffff06,1,0);
    DungeonStopBGM();
    sub_80861D4(LugiaEntity,7,DIRECTION_SOUTH);
    DisplayDungeonDialogue(gLugiaPreFightDialogue_7);
    LugiaScreenFlash();
    SetupBossFightHP(LugiaEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void LugiaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void LugiaScreenFlash2(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(4,0x46);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C0CC(void)
{
  gUnknown_202EDC8 = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  LugiaScreenFlash();
}

void sub_808C10C(void)
{
  Entity * LeaderEntity;
  Entity * KyogreEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  KyogreEntity = GetEntityFromClientType(0x1c);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    sub_8068FE0(KyogreEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(KyogreEntity, DIRECTION_SOUTH);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_KYOGRE);
  // TODO: gUnknown_202E088 doesn't match but gUnknown_202E038 + 0x50 does
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_GROUDON);
}

void sub_808C1A4(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x34) && (param_1 == 0x1C)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  }
}

void KyogrePreFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *KyogreEntity;

  LeaderEntity = xxx_call_GetLeader();
  KyogreEntity = GetEntityFromClientType(0x1c);
  DungeonStopBGM();
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    SpriteLookAroundEffect(LeaderEntity);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(gKyogrePreFightDialogue_8);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(gKyogrePreFightDialogue_1);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(gKyogrePreFightDialogue_2);
    sub_803E708(10,0x46);
    nullsub_99();
    sub_803E708(10,0x46);
    // Gwwwwwooooooooh
    DisplayDungeonDialogue(gKyogrePreFightDialogue_3);
    sub_803E708(10,0x46);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C360();
    // My duels against {ARG_POKEMON_3} (Groudon) left us both exhausted
    DisplayDungeonDialogue(gKyogrePreFightDialogue_4);
    KyogreScreenFlash();
    // I am {ARG_POKEMON_2} (Kyogre)!
    // The lord of the sea!
    DisplayDungeonDialogue(gKyogrePreFightDialogue_5);
    KyogreScreenFlash();
    // Witness the destructive force of my waves!
    DisplayDungeonDialogue(gKyogrePreFightDialogue_6);
    KyogreScreenFlash();
    // Marvel at my awesome
    // power!
    DisplayDungeonDialogue(gKyogrePreFightDialogue_7);
    sub_803E708(10,0x46);
    SetupBossFightHP(KyogreEntity,600,MUS_BOSS_BATTLE);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
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
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C360(void)
{
  gUnknown_202EDC8 = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  KyogreScreenFlash();
}

void sub_808C3A0(void)
{
  Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    sub_808563C(sub_808C590);
  }
  else {
    gDungeon->unk7 = 1;
    sub_808563C(SetupDeoxysFacingDirection);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_DEOXYS_NORMAL);
}

void sub_808C414(u8 param_1,u8 param_2)
{
  if ((param_2 == 0x35) && (param_1 == 0x1D)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  }
}

void DeoxysPreFightDialogue(void)
{
  Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_8086448();
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(gDeoxysPreFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(gDeoxysPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_RAYQUAZAS_DOMAIN, 0x3c);
    sub_808C550();
    DisplayDungeonDialogue(gDeoxysPreFightDialogue_2);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(gDeoxysPreFightDialogue_3);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(gDeoxysPreFightDialogue_4);
    sub_803E708(10,0x46);
    sub_808563C(SetupDeoxysFightHP);
    ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  }
}

void DeoxysScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C550(void)
{
  gUnknown_202EDC8 = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  sub_803E9D0();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  DeoxysScreenFlash();
}

void sub_808C590(Entity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void SetupDeoxysFacingDirection(Entity *deoxysEntity)
{
    SetFacingDirection(deoxysEntity, DIRECTION_SOUTH);
}

void SetupDeoxysFightHP(Entity *deoxysEntity)
{
    SetupBossFightHP(deoxysEntity, 950, MUS_BATTLE_WITH_RAYQUAZA);
}

void sub_808C5C0(void)
{
  Entity * LeaderEntity;
  Entity * CelebiEntity;

  u32 XPos;
  s32 YPos;

  LeaderEntity = xxx_call_GetLeader();
  CelebiEntity = GetEntityFromClientType(0x1e);
  DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(CelebiEntity, DIRECTION_SOUTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + 0xfffff000);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_CELEBI);
}

void nullsub_100(u8 r0, u8 r1, u32 r2)
{
}

void CelebiJoinDialogue(void)
{
    Entity *LeaderEntity;
    s32 state;
    s32 menuChoice;
    Entity *CelebiEntity;

    LeaderEntity = xxx_call_GetLeader();
    CelebiEntity = GetEntityFromClientType(0x1e);
    if ((HasRecruitedMon(MONSTER_CELEBI)) || (sub_806FD18(CelebiEntity) == '\0'))
    {
        sub_8068FE0(CelebiEntity,0x21c,0);
        SpriteLookAroundEffect(LeaderEntity);
        sub_803E708(10,0x46);
        // .........
        DisplayDungeonDialogue(gCelebiJoinDialogue_10);
    }
    else
    {
        SpriteLookAroundEffect(LeaderEntity);
        sub_803E708(10,0x46);
        SpriteShockEffect(LeaderEntity);
        sub_803E708(10,0x46);
        // Oh? There's someone there.
        DisplayDungeonDialogue(gCelebiJoinDialogue_1);
        sub_803E708(10,0x46);
        sub_8086598();
        sub_8086598();
        sub_8086598();
        sub_8086598();
        // The Time-Traveling Pokemon {ARG_POKEMON_2} (Celebi)!
        DisplayDungeonDialogue(gCelebiJoinDialogue_2);
        PlaySoundEffect(0x1c7);
        sub_806CDD4(CelebiEntity,10,DIRECTION_SOUTH);
        sub_803E708(0x14,0x46);
        sub_806CE68(CelebiEntity, DIRECTION_SOUTH);
        sub_803E708(4,0x46);
        PlaySoundEffect(0x1c7);
        sub_806CDD4(CelebiEntity,10,DIRECTION_SOUTH);
        DisplayDungeonDialogue(gCelebiJoinDialogue_3);
        sub_803E708(10,0x46);
        state = 0;

        do
        {
            switch(state)
            {
            case 0:
                do
                {
                    menuChoice = sub_8052C68(0,gPtrPurityForestAllowCelebiToJoinText, &gPurityForestAllowCelebiToJoinPrompt,0x701);
                } while (menuChoice < 1);

                sub_803E708(10,0x46);

                if (menuChoice == 1)
                {
                    DungeonStopBGM();
                    PlaySoundEffect(0xcc);
                    while (IsFanfareSEPlaying_2(0xcc) != 0) {
                        sub_803E46C(0x46);
                    }
                    DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                    PlaySoundEffect(0x1c7);
                    sub_80861D4(CelebiEntity,0xd,DIRECTION_SOUTH);
                    sub_803E708(0x37,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1a,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1c,0x46);
                    DisplayDungeonDialogue(gCelebiJoinDialogue_4);
                    sub_803E708(10,0x46);
                    sub_806FDF4(LeaderEntity,CelebiEntity,&CelebiEntity);
                    DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                    DisplayDungeonDialogue(gCelebiJoinDialogue_5);
                    sub_803E708(10,0x46);
                    PlaySoundEffect(0x1c7);
                    sub_80861D4(CelebiEntity,0xd,DIRECTION_SOUTH);
                    sub_803E708(0x37,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1a,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1b,0x46);
                    DisplayDungeonDialogue(gCelebiJoinDialogue_6);
                    sub_803E708(10,0x46);
                    state = 2;
                }
                else
                {
                    state = 1;
                }
                break;
            case 1:
                do
                {
                    menuChoice = sub_8052C68(0,gPtrPurityForestRefuseCelebiConfirmText, &gPurityForestRefuseCelebiConfirmPrompt,0x701);
                } while (menuChoice < 1);
                if (menuChoice == 1)
                {
                    state = 0;
                }
                else
                {
                    sub_803E708(10,0x46);
                    DisplayDungeonDialogue(gCelebiJoinDialogue_7);
                    sub_80861F8(0x3e,CelebiEntity,1);
                    sub_803E708(0x18,0x46);
                    sub_80861F8(0x3e,CelebiEntity,1);
                    sub_803E708(0xe,0x46);
                    DisplayDungeonDialogue(gCelebiJoinDialogue_8);
                    sub_803E708(10,0x46);
                    sub_808C8E0(CelebiEntity);
                    DisplayDungeonDialogue(gCelebiJoinDialogue_9);
                    sub_803E708(10,0x46);
                    state = 2;
                }
                break;
            }
        } while (state != 2);
    }
    DungeonFadeOutBGM(0x1e);
    sub_803E708(0x1e,0x46);
    gDungeon->unk2 = 1;
}

void sub_808C8E0(Entity *param_1)
{
  s32 iVar1;

  PlaySoundEffect(0x1a5);
  sub_806CDD4(param_1, 0, DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 16; iVar1++){
    param_1->axObj.info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  for(iVar1 = 16; iVar1 < 200; iVar1 += 4){
    param_1->axObj.info->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  sub_8086A3C(param_1);
}

void sub_808C938(void)
{
    sub_80855E4(sub_808C9B0);
}

void sub_808C948(Entity *entity, u8 param_2)
{
  bool8 flag;
  s32 index;
  Entity *pokeEntity;

  if (param_2 == 0x37) {
    flag = FALSE;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++){
      pokeEntity = gDungeon->wildPokemon[index];
      if ((pokeEntity != entity) && (EntityExists(pokeEntity))) {
        flag = TRUE;
        break;
      }
    }
    if (!flag) {
      gDungeon->unk2 = 1;
    }
  }
}

void sub_808C998(void)
{
    // Defeat the opposing team to win
    // Be careful, your opponents are tough
    DisplayDungeonDialogue(gUnknown_8106720);
    sub_803E708(0xA, 0x46);
}

void sub_808C9B0(Entity *param_1)
{
    param_1->axObj.info->action.direction = DIRECTION_NORTH;
    sub_806CE68(param_1, DIRECTION_NORTH);
}

void sub_808C9C4(void)
{
    Entity *LeaderEntity;
    Entity *MedichamEntity;

    LeaderEntity = xxx_call_GetLeader();
    MedichamEntity = GetEntityFromClientType(7);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(MedichamEntity, DIRECTION_SOUTH);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_MEDICHAM);
}

// Medicham Rescue Dialogue?
void MedichamRescueDialogue(void)
{
    Entity *MedichamEntity;
    s32 counter;

    MedichamEntity = GetEntityFromClientType(7);
    SpriteLookAroundEffect(MedichamEntity);
    sub_803E708(0xA, 0x46);
    // Oh my I can't seem to find a way out...
    DisplayDungeonDialogue(gMedichamRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(MedichamEntity, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // What am I to do...?
    DisplayDungeonDialogue(gMedichamRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(MedichamEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(MedichamEntity, 4, 2, 0);
    DisplayDungeonDialogue(gMedichamRescueDialogue_3);
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
    DisplayDungeonDialogue(gMedichamRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(MedichamEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        IncreaseEntityPixelPos(MedichamEntity, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(MedichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(MedichamEntity);
    sub_8068FE0(MedichamEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;
}

void sub_808CB5C(void)
{
    Entity *LeaderEntity;
    Entity *MedichamEntity;

    LeaderEntity = xxx_call_GetLeader();
    MedichamEntity = GetEntityFromClientType(7);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_8068FE0(MedichamEntity, 0x21C, 0);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_MEDICHAM);
}

void DummyFightDialogue(void)
{
}

void sub_808CBB0(void)
{
    Entity *LeaderEntity;
    Entity *SmeargleEntity;

    LeaderEntity = xxx_call_GetLeader();
    SmeargleEntity = GetEntityFromClientType(0x1F);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(SmeargleEntity, DIRECTION_SOUTH);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SMEARGLE);
}

// Smeargle Rescue dialogue scene
void SmeargleRescueDialogue(void)
{
    Entity *SmeargleEntity;
    s32 counter;

    SmeargleEntity = GetEntityFromClientType(0x1F);
    SpriteLookAroundEffect(SmeargleEntity);
    sub_803E708(0xA, 0x46);
    // Ohhh...
    // I've lost my bearings
    DisplayDungeonDialogue(gSmeargleRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(SmeargleEntity, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // I can't get out...
    // I'm hungry...
    // I'm in trouble
    DisplayDungeonDialogue(gSmeargleRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(SmeargleEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(SmeargleEntity, 4, 2, 0);
    // Oh! You are?
    DisplayDungeonDialogue(gSmeargleRescueDialogue_3);
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
    DisplayDungeonDialogue(gSmeargleRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(SmeargleEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        IncreaseEntityPixelPos(SmeargleEntity, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(SmeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(SmeargleEntity);
    sub_8068FE0(SmeargleEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;

}

void sub_808CD44(void)
{
    Entity *LeaderEntity;
    Entity *SmeargleEntity;

    LeaderEntity = xxx_call_GetLeader();
    SmeargleEntity = GetEntityFromClientType(0x1F);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    sub_8068FE0(SmeargleEntity, 540, 0);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SMEARGLE);
}

void sub_808CD9C(u8 r0)
{
    sub_8086448();
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(gUnknown_810697C);
}

const u64 *sub_808CDB0(u8 r0)
{
    return &gUnknown_8107544[r0];
}

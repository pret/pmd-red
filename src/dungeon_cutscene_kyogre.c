#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_806CD90.h"
#include "code_80869E4.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
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
#include "dungeon_tilemap.h"
#include "dungeon_map.h"

extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);

static void nullsub_99(void);
static void KyogreScreenFlash(void);
static void sub_808C360(void);

void sub_808C10C(void)
{
  Entity * leaderEntity;
  Entity * kyogreEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = CutsceneGetLeader();
  kyogreEntity = GetEntityFromMonsterBehavior(BEHAVIOR_KYOGRE);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    HandleFaint(kyogreEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(kyogreEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_KYOGRE);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GROUDON);
}

void sub_808C1A4(u8 param_1,u8 param_2,u8 param_3)
{
  if ((param_2 == 0x34) && (param_1 == 0x1C)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  }
}

void KyogrePreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *KyogreEntity;

  leaderEntity = CutsceneGetLeader();
  KyogreEntity = GetEntityFromMonsterBehavior(BEHAVIOR_KYOGRE);
  DungeonStopBGM();
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    SpriteLookAroundEffect(leaderEntity);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_8);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_1);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_2);
    sub_803E708(10,0x46);
    nullsub_99();
    sub_803E708(10,0x46);
    // Gwwwwwooooooooh
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_3);
    sub_803E708(10,0x46);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C360();
    // My duels against {POKEMON_3} (Groudon) left us both exhausted
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_4);
    KyogreScreenFlash();
    // I am {POKEMON_2} (Kyogre)!
    // The lord of the sea!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_5);
    KyogreScreenFlash();
    // Witness the destructive force of my waves!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_6);
    KyogreScreenFlash();
    // Marvel at my awesome
    // power!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_7);
    sub_803E708(10,0x46);
    SetupBossFightHP(KyogreEntity,600,MUS_BOSS_BATTLE);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void nullsub_99(void)
{
}

static void KyogreScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f8);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

static void sub_808C360(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  BgColorCallNullsub4();
  DungeonRunFrameActions(0x46);
  gDungeon->unk7 = 0;
  KyogreScreenFlash();
}

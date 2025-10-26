#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "dungeon_8041AD0.h"
#include "dungeon_mon_sprite_render.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/dungeon_exit.h"
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
#include "weather.h"
#include "dungeon_mon_recruit.h"


static void sub_808C8E0(Entity *entity);
static void sub_808C9B0(Entity *param_1);

void sub_808C5C0(void)
{
  Entity * leaderEntity;
  Entity * celebiEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = CutsceneGetLeader();
  celebiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_CELEBI);
  DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(celebiEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos - 0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_CELEBI);
}

void nullsub_100(u8 r0, u8 r1, u8 r3)
{
}

void CelebiJoinDialogue(void)
{
    Entity *leaderEntity;
    s32 state;
    s32 menuChoice;
    Entity *celebiEntity;

    leaderEntity = CutsceneGetLeader();
    celebiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_CELEBI);
    if ((HasRecruitedMon(MONSTER_CELEBI)) || (!CanEntityBeRecruited(celebiEntity)))
    {
        HandleFaint(celebiEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
        SpriteLookAroundEffect(leaderEntity);
        sub_803E708(10,0x46);
        // .........
        DisplayDungeonDialogue(&gCelebiJoinDialogue_10);
    }
    else
    {
        SpriteLookAroundEffect(leaderEntity);
        sub_803E708(10,0x46);
        SpriteShockEffect(leaderEntity);
        sub_803E708(10,0x46);
        // Oh? There's someone there.
        DisplayDungeonDialogue(&gCelebiJoinDialogue_1);
        sub_803E708(10,0x46);
        sub_8086598();
        sub_8086598();
        sub_8086598();
        sub_8086598();
        // The Time-Traveling Pokemon {POKEMON_2} (Celebi)!
        DisplayDungeonDialogue(&gCelebiJoinDialogue_2);
        PlaySoundEffect(0x1c7);
        sub_806CDD4(celebiEntity,10,DIRECTION_SOUTH);
        sub_803E708(0x14,0x46);
        sub_806CE68(celebiEntity, DIRECTION_SOUTH);
        sub_803E708(4,0x46);
        PlaySoundEffect(0x1c7);
        sub_806CDD4(celebiEntity,10,DIRECTION_SOUTH);
        DisplayDungeonDialogue(&gCelebiJoinDialogue_3);
        sub_803E708(10,0x46);
        state = 0;

        do
        {
            switch(state)
            {
            case 0:
                do
                {
                    menuChoice = DisplayDungeonMenuMessage(0,gPtrPurityForestAllowCelebiToJoinText, gPurityForestAllowCelebiToJoinPrompt,0x701);
                } while (menuChoice < 1);

                sub_803E708(10,0x46);

                if (menuChoice == 1)
                {
                    DungeonStopBGM();
                    PlaySoundEffect(0xcc);
                    while (IsFanfareSEPlaying_2(0xcc) != 0) {
                        DungeonRunFrameActions(0x46);
                    }
                    DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                    PlaySoundEffect(0x1c7);
                    sub_80861D4(celebiEntity,0xd,DIRECTION_SOUTH);
                    sub_803E708(0x37,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1a,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1c,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_4);
                    sub_803E708(10,0x46);
                    HandleSpecialEntityJoinSequence(leaderEntity,celebiEntity,&celebiEntity);
                    DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_5);
                    sub_803E708(10,0x46);
                    PlaySoundEffect(0x1c7);
                    sub_80861D4(celebiEntity,0xd,DIRECTION_SOUTH);
                    sub_803E708(0x37,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1a,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1b,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_6);
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
                    menuChoice = DisplayDungeonMenuMessage(0,gPtrPurityForestRefuseCelebiConfirmText, gPurityForestRefuseCelebiConfirmPrompt,0x701);
                } while (menuChoice < 1);
                if (menuChoice == 1)
                {
                    state = 0;
                }
                else
                {
                    sub_803E708(10,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_7);
                    sub_80861F8(0x3e,celebiEntity,1);
                    sub_803E708(0x18,0x46);
                    sub_80861F8(0x3e,celebiEntity,1);
                    sub_803E708(0xe,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_8);
                    sub_803E708(10,0x46);
                    sub_808C8E0(celebiEntity);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_9);
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

static void sub_808C8E0(Entity *entity)
{
  s32 iVar1;

  PlaySoundEffect(0x1a5);
  sub_806CDD4(entity, 0, DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 16; iVar1++){
    GetEntInfo(entity)->unk174 = IntToF248_2(iVar1);
    DungeonRunFrameActions(0x46);
  }
  for(iVar1 = 16; iVar1 < 200; iVar1 += 4){
    GetEntInfo(entity)->unk174 = IntToF248_2(iVar1);
    DungeonRunFrameActions(0x46);
  }
  sub_8086A3C(entity);
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
      if ((pokeEntity != entity) && (EntityIsValid(pokeEntity))) {
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
    DisplayDungeonDialogue(&gUnknown_8106720);
    sub_803E708(0xA, 0x46);
}

static void sub_808C9B0(Entity *param_1)
{
    GetEntInfo(param_1)->action.direction = DIRECTION_NORTH;
    sub_806CE68(param_1, DIRECTION_NORTH);
}

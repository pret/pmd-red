#include "global.h"
#include "constants/weather.h"
#include "constants/dungeon.h"
#include "constants/direction.h"
#include "constants/dungeon.h"
#include "structs/str_dungeon.h"
#include "structs/str_806B7F8.h"
#include "dungeon_cutscenes.h"
#include "dungeon_music.h"
#include "dungeon_logic.h"
#include "dungeon_util_1.h"
#include "exclusive_pokemon.h"
#include "weather.h"
#include "pokemon.h"
#include "dungeon_util.h"
#include "dungeon_map_access.h"
#include "dungeon_misc.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_806CD90.h"
#include "code_80861A8.h"
#include "code_8085E98.h"
#include "dungeon_leader.h"
#include "random.h"
#include "math.h"
#include "code_8004AA0.h"
#include "bg_palette_buffer.h"

extern s32 gUnknown_202F3D8;

extern const u8 gUnknown_8107358[25];
extern const DungeonPos gUnknown_80F4598[];

extern void ShowWholeRevealedDungeonMap(void);
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F4A0(u32);
extern void sub_803F878(s32, s32);

struct unkData_8107234
{
    u8 unk0[8];
};

extern struct unkData_8107234 gUnknown_8107234[];

void sub_8084854(struct unkData_8107234 *);

void sub_80847D4(void)
{
    u32 fixedRoomNumber;
    s32 index;

    gDungeon->unk3A0D = 0;
    gDungeon->unk1356C = 0;
    ShowWholeRevealedDungeonMap();
    for(index = 0; index < 0x3e7 && gUnknown_8107234[index].unk0[0] != 0;  index++) {
        fixedRoomNumber = gDungeon->fixedRoomNumber;
        if (fixedRoomNumber - 0x1c < 0x16) {
            fixedRoomNumber = 0x1b;
        }
        if (fixedRoomNumber == gUnknown_8107234[index].unk0[0])
        {
            sub_8084854(&gUnknown_8107234[index]);
            break;
        }
    }
    sub_8097FF8();
}

void sub_8084854(struct unkData_8107234 *param_1)
{
  if (gDungeon->unk644.unk34 != 0) {
       gDungeon->unk3A0D = param_1->unk0[5];
  }
  else
  {
    if (sub_8098100(param_1->unk0[4]) != 0) {
        gDungeon->unk3A0D = param_1->unk0[5];
    }
    else
    {
      if (sub_8098100(param_1->unk0[2]) != 0) {
        gDungeon->unk3A0D = param_1->unk0[3];
      }
      else
      {
        gDungeon->unk3A0D = param_1->unk0[1];
        if (param_1->unk0[2] != 0x40) {
          sub_8097FA8(param_1->unk0[2]);
        }
      }
    }
  }
  gDungeon->unk644.unk31 = 1;
  sub_807E5E4(WEATHER_CLEAR);
}

u32 sub_80848EC(void)
{
    return 1;
}

void sub_80848F0(void)
{
  gDungeon->unk1356C = 1;
  switch(gDungeon->unk3A0D) {
    case 0:
    case 0x3c:
        gDungeon->unk1356C = 0;
        break;
    case 1:
    case 2:
        sub_8086B14();
        break;
    case 3:
        sub_8086B94();
        break;
    case 4:
    case 5:
        sub_8086E9C();
        break;
    case 6:
        sub_8086F00();
        break;
    case 7:
    case 8:
        sub_8087230();
        break;
    case 9:
        sub_808729C();
        break;
    case 10:
    case 0xb:
        sub_80877E8();
        break;
    case 0xc:
        sub_8087848();
        break;
    case 0xd:
        sub_8087F54();
        break;
    case 0xe:
        sub_8087FB4();
        break;
    case 0xf:
        sub_8087FF8();
        break;
    case 0x10:
        sub_80885A0();
        break;
    case 0x11:
        sub_80885C4();
        break;
    case 0x12:
        sub_808862C();
        break;
    case 0x13:
        sub_80886C4();
        break;
    case 0x14:
        sub_808875C();
        break;
    case 0x15:
        sub_8088DC0();
        break;
    case 0x16:
        sub_8088E5C();
        break;
    case 0x17:
    case 0x18:
        sub_80892C8();
        break;
    case 0x19:
        sub_8089328();
        break;
    case 0x1a:
    case 0x1b:
        sub_808970C();
        break;
    case 0x1c:
        sub_808974C();
        break;
    case 0x1d:
    case 0x1e:
        sub_8089914();
        break;
    case 0x1f:
        sub_8089978();
        break;
    case 0x20:
    case 0x21:
        sub_8089C44();
        break;
    case 0x22:
        sub_8089C90();
        break;
    case 0x23:
        sub_8089EFC();
        break;
    case 0x24:
        sub_8089F44();
        break;
    case 0x25:
        sub_8089F8C();
        break;
    case 0x26:
        sub_808A264();
        break;
    case 0x27:
        sub_808A2C0();
        break;
    case 0x28:
        sub_808A308();
        break;
    case 0x29:
        sub_808A608();
        break;
    case 0x2a:
        sub_808A668();
        break;
    case 0x2b:
        sub_808A9E4();
        break;
    case 0x2c:
        sub_808AA3C();
        break;
    case 0x2d:
        sub_808AA94();
        break;
    case 0x2e:
        sub_808ACC0();
        break;
    case 0x2f:
        sub_808AD48();
        break;
    case 0x30:
        sub_808ADCC();
        break;
    case 0x31:
        sub_808B2F4();
        break;
    case 0x32:
        sub_808B35C();
        break;
    case 0x33:
        sub_808BDEC();
        break;
    case 0x34:
        sub_808C10C();
        break;
    case 0x35:
        sub_808C3A0();
        break;
    case 0x36:
        sub_808C5C0();
        break;
    case 0x37:
        sub_808C938();
        break;
    case 0x38:
        sub_808C9C4();
        break;
    case 0x39:
        sub_808CB5C();
        break;
    case 0x3a:
        sub_808CBB0();
        break;
    case 0x3b:
        sub_808CD44();
        break;
  }
  sub_8097FF8();
}

void DisplayPreFightDialogue(void)
{
  switch(gDungeon->unk3A0D) {
      case 0:
        break;
      case 1:
        SkarmoryPreFightDialogue();
        break;
      case 2:
        SkarmoryReFightDialogue();
        break;
      case 3:
        sub_8086E40();
        break;
      case 4:
        TeamMeaniesPreFightDialogue();
        break;
      case 5:
        TeamMeaniesReFightDialogue();
        break;
      case 6:
        sub_8087130();
        break;
      case 7:
        ZapdosPreFightDialogue();
        break;
      case 8:
        ZapdosReFightDialogue();
        break;
      case 9:
        ZapdosPostStoryPreFightDialogue();
        break;
      case 10:
        MoltresPreFightDialogue();
        break;
      case 0xb:
        MoltresReFightDialogue();
        break;
      case 0xc:
        MoltresPostStoryPreFightDialogue();
        break;
      case 0xd:
        ArticunoPreFightDialogue();
        break;
      case 0xe:
        ArticunoReFightDialogue();
        break;
      case 0xf:
        ArticunoPostStoryPreFightDialogue();
        break;
      case 0x10:
        sub_8088608();
        break;
      case 0x11:
        sub_8088618();
        break;
      case 0x12:
        GroudonPreFightDialogue();
        break;
      case 0x13:
        GroudonReFightDialogue();
        break;
      case 0x14:
        GroudonPostStoryPreFightDialogue();
        break;
      case 0x15:
        MagmaCavernMidDialogue();
        break;
      case 0x16:
        sub_8089168();
        break;
      case 0x17:
        RayquazaPreFightDialogue();
        break;
      case 0x18:
        RayquazaReFightDialogue();
        break;
      case 0x19:
        RayquazaPostStoryPreFightDialogue();
        break;
      case 0x1a:
        sub_80897F0();
        break;
      case 0x1b:
        sub_8089878();
        break;
      case 0x1c:
        sub_80898E4();
        break;
      case 0x1d:
      case 0x1e:
        MewtwoPreFightDialogue();
        break;
      case 0x1f:
        MewtwoReFightDialogue();
        break;
      case 0x20:
        EnteiPreFightDialogue();
        break;
      case 0x21:
        EnteiReFightDialogue();
        break;
      case 0x22:
        EnteiPostStoryPreFightDialogue();
        break;
      case 0x23:
        RaikouPreFightDialogue();
        break;
      case 0x24:
        RaikouReFightDialogue();
        break;
      case 0x25:
        RaikouPostStoryPreFightDialogue();
        break;
      case 0x26:
        SuicunePreFightDialogue();
        break;
      case 0x27:
        SuicuneReFightDialogue();
        break;
      case 0x28:
        SuicunePostStoryPreFightDialogue();
        break;
      case 0x29:
        HoOhPreFightDialogue();
        break;
      case 0x2a:
        HoOhReFightDialogue();
        break;
      case 0x2b:
        LatiosPreFightDialogue();
        break;
      case 0x2c:
        LatiosReFightDialogue();
        break;
      case 0x2d:
        sub_808AC3C();
        break;
      case 0x2e:
        RegirockPreFightDialogue();
        break;
      case 0x2f:
        RegicePreFightDialogue();
        break;
      case 0x30:
        RegisteelPreFightDialogue();
        break;
      case 0x31:
        JirachiPreFightDialogue();
        break;
      case 0x32:
        JirachiReFightDialogue();
        break;
      case 0x33:
        LugiaPreFightDialogue();
        break;
      case 0x34:
        KyogrePreFightDialogue();
        break;
      case 0x35:
        DeoxysPreFightDialogue();
        break;
      case 0x36:
        CelebiJoinDialogue();
        break;
      case 0x37:
        sub_808C998();
        break;
      case 0x38:
        MedichamRescueDialogue();
        break;
      case 0x39:
        DummyFightDialogue();
        break;
      case 0x3a:
        SmeargleRescueDialogue();
        break;
      case 0x3b:
        sub_808CD9C();
        break;
      case 0x3C:
        break;
  }
  sub_8085764();
  sub_80857B8();
  gDungeon->unk1356C = 0;
  sub_8097FF8();
}

void sub_8084E00(Entity *entity, u8 param_2, u8 param_3)
{
  if (param_2 != 0) {
    switch(gDungeon->unk3A0D) {
        case 0:
            break;
        case 1:
        case 2:
            sub_8086BDC(param_2,gDungeon->unk3A0D);
            break;
        case 4:
        case 5:
            sub_8086F54(param_2,gDungeon->unk3A0D);
            break;
        case 7:
        case 8:
        case 9:
            sub_8087334(param_2,gDungeon->unk3A0D);
            break;
        case 10:
        case 0xb:
        case 0xc:
            sub_80878F4(param_2,gDungeon->unk3A0D);
            break;
        case 0xd:
        case 0xe:
        case 0xf:
            sub_8088088(param_2,gDungeon->unk3A0D);
            break;
        case 0x12:
        case 0x13:
        case 0x14:
            sub_8088818(param_2,gDungeon->unk3A0D);
            break;
        case 0x17:
        case 0x18:
        case 0x19:
            sub_80893B4(param_2,gDungeon->unk3A0D);
            break;
        case 0x1a:
        case 0x1b:
            sub_8089788(entity,param_2,gDungeon->unk3A0D);
            break;
        case 0x1d:
        case 0x1e:
        case 0x1f:
            sub_8089A00(param_2,gDungeon->unk3A0D);
            break;
        case 0x20:
        case 0x21:
        case 0x22:
            sub_8089CFC(param_2,gDungeon->unk3A0D);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
            sub_8089FF0(param_2,gDungeon->unk3A0D);
            break;
        case 0x26:
        case 0x27:
        case 0x28:
            sub_808A36C(param_2,gDungeon->unk3A0D);
            break;
        case 0x29:
        case 0x2a:
            sub_808A6E8(param_2,gDungeon->unk3A0D);
            break;
        case 0x2b:
        case 0x2c:
        case 0x2d:
            sub_808AAF0(param_2,gDungeon->unk3A0D);
            break;
        case 0x2e:
            sub_808AE54(param_2,gDungeon->unk3A0D,&entity->pos);
            break;
        case 0x2f:
            sub_808AEC8(param_2,gDungeon->unk3A0D,&entity->pos);
            break;
        case 0x30:
            sub_808AF3C(param_2,gDungeon->unk3A0D,&entity->pos);
            break;
        case 0x31:
        case 0x32:
            sub_808B3E4(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x33:
            sub_808BE70(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x34:
            sub_808C1A4(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x35:
            sub_808C414(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x36:
            nullsub_100(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x37:
            sub_808C948(entity,gDungeon->unk3A0D);
            break;
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
            break;
    }
    if ((param_3 == 0) && (gDungeon->unk2 != 0)) {
      DungeonStartNewBGM(999);
    }
  }
}

void sub_8085140(void)
{
    switch(gDungeon->unk3A0D) {
        // NOTE: shortcut way to generate all cases from 0 - 0x3C properly
        default:
        case 0:
        case 1:
        case 0x3C:
            break;
        case 0x2e:
            sub_808AFB0(gDungeon->unk3A0D);
            break;
        case 0x2f:
            sub_808B030(gDungeon->unk3A0D);
            break;
        case 0x30:
            sub_808B0B0(gDungeon->unk3A0D);
            break;
  }
}

u8 sub_808529C(s32 speciesId_)
{
    s32 r3;
    s32 speciesId = 0;

    // This line serves no purpose other than generating the right asm. Feel free to remove it.
    speciesId += (s16) speciesId_;

    speciesId = (s16) speciesId_;
    r3 = 0x40;

    switch (speciesId) {
        case MONSTER_SKARMORY:
            r3 = 1;
            break;
        case MONSTER_EKANS:
            r3 = 3;
            break;
        case MONSTER_GENGAR:
            r3 = 3;
            break;
        case MONSTER_MEDICHAM:
            r3 = 3;
            break;
        case MONSTER_ZAPDOS:
            r3 = 5;
            break;
        case MONSTER_MOLTRES:
            r3 = 7;
            break;
        case MONSTER_ARTICUNO:
            r3 = 9;
            break;
        case MONSTER_GROUDON:
            r3 = 0xC;
            break;
        case MONSTER_RAYQUAZA:
            r3 = 0xF;
            break;
        case MONSTER_MEWTWO:
            r3 = 0x13;
            break;
        case MONSTER_ENTEI:
            r3 = 0x15;
            break;
        case MONSTER_RAIKOU:
            r3 = 0x17;
            break;
        case MONSTER_SUICUNE:
            r3 = 0x19;
            break;
        case MONSTER_HO_OH:
            r3 = 0x1A;
            break;
        case MONSTER_MANKEY:
            r3 = 0x11;
            break;
        case MONSTER_REGIROCK:
            r3 = 0x1D;
            break;
        case MONSTER_REGICE:
            r3 = 0x1D;
            break;
        case MONSTER_REGISTEEL:
            r3 = 0x1D;
            break;
    }

    if (r3 != 0x40 && !sub_8098100(r3))
        return FALSE;
    return TRUE;
}

void sub_8085374(void)
{
    const Tile *tile;
    Entity *entity;
    DungeonPos pos;
    s32 i, j;
    s32 temp;
    Entity *leaderEntity = NULL;
    Entity *partnerEntity = NULL;
    s32 species = sub_808D3F8()->speciesNum;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            if (GetEntInfo(entity)->isTeamLeader)
                leaderEntity = entity;
            if (GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
                partnerEntity = entity;
        }
    }

    if (leaderEntity == NULL || partnerEntity != NULL || gDungeon->unk644.unk18 != 0)
        return;

    j = 0;
    while ((pos = gUnknown_80F4598[j]).x != 99) {
        pos.x += leaderEntity->pos.x;
        pos.y += leaderEntity->pos.y;
        tile = GetTile(pos.x, pos.y);
        temp = sub_807034C(species, tile);
        if (temp == 0) {
            struct unkStruct_806B7F8 local_30;

            local_30.species = species;
            local_30.level = 1;
            local_30.unk2 = 2;
            local_30.pos = pos;
            local_30.unk4 = temp;
            local_30.unk10 = 0;
            sub_806B7F8(&local_30, 1);
            break;
        }
        j++;
    }
}

Entity *xxx_call_GetLeader(void)
{
    return GetLeader();
}

Entity *GetPartnerEntity(void)
{
    s32 counter;
    Entity *entity;
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        entity = gDungeon->teamPokemon[counter];
        if(EntityIsValid(entity) && GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            return entity;
        }
    }
    return GetEntityFromMonsterBehavior(BEHAVIOR_ALLY);
}

void sub_80854D4(void)
{
    Entity *stack1[MAX_TEAM_MEMBERS];
    Entity *stack2[MAX_TEAM_MEMBERS];
    s32 counter = 0;
    s32 index;
    Entity *entity;
    Entity *entity2;
    Entity *entity3;
    Entity *entity4;
    Entity *entity5;

    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityIsValid(entity))
        {
            stack1[counter] = entity;
            counter++;
        }
    }
    for(; counter < MAX_TEAM_MEMBERS; counter++)
    {
        stack1[counter] = NULL;
    }
    counter = 0;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity2 = stack1[index];
        if(entity2 != NULL && GetEntInfo(entity2)->isTeamLeader)
        {
            stack1[index] = NULL;
            stack2[counter] = entity2;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity3 = stack1[index];
        if(entity3 != NULL && GetEntInfo(entity3)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            stack1[index] = NULL;
            stack2[counter] = entity3;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity4 = stack1[index];
        if(entity4 != NULL)
        {
            stack1[index] = NULL;
            stack2[counter] = entity4;
            counter++;
        }
    }
    for(; counter < MAX_TEAM_MEMBERS; counter++)
    {
        stack2[counter] = NULL;
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity5 = stack2[index];
        if(entity5 != NULL)
            sub_80856C8(entity5, gDungeon->unkE220[index].x, gDungeon->unkE220[index].y);
    }
}

void sub_80855E4(DungeonCallback func)
{
    bool8 flag;
    Entity * entity;
    Entity * partnerEntity;
    s32 index;

    flag = FALSE;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if (EntityIsValid(entity)) {
            if (GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER) {
                flag = TRUE;
            }
            func(entity);
        }
    }
    if ((!flag) && (partnerEntity = GetPartnerEntity(), partnerEntity != NULL)) {
        func(partnerEntity);
    }
}

void sub_808563C(DungeonCallback func)
{
    Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->joinedAt.id != 0x41)) {
            func(entity);
        }
    }
}

Entity *GetEntityFromMonsterBehavior(u8 entityType)
{
    Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->monsterBehavior == entityType)) return entity;
    }
    return NULL;
}

void sub_80856C8(Entity * pokemon, s32 x, s32 y)
{
    sub_80694C0(pokemon, x, y, 1);
    sub_804535C(pokemon,NULL);
}

void sub_80856E0(Entity * pokemon, s32 direction)
{
    EntityInfo *entityInfo;
    s32 counter;

    entityInfo = GetEntInfo(pokemon);
    sub_80861D4(pokemon, 6, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 = F248_Add(entityInfo->unk174, IntToF248(2));
        DungeonRunFrameActions(0x46);
    }
    entityInfo->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 = F248_Sub(entityInfo->unk174, IntToF248(2));
        DungeonRunFrameActions(0x46);
    }
    entityInfo->unk174.raw = 0; // weird one that doesn't match with struct assignment
    DungeonRunFrameActions(0x46);
}

void sub_8085764(void)
{
    Entity *entity;
    s32 index;
    Entity stackEntity;

    sub_80457DC(&stackEntity);
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->monsterBehavior == BEHAVIOR_ALLY)) {
            sub_8068FE0(entity,0x207,&stackEntity);
        }
    }
}

void sub_80857B8(void)
{
    u8 *direction;
    EntityInfo *entityInfo;
    Entity *entity;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity)) {
            entityInfo = GetEntInfo(entity);
            if ((gDungeon->unk4 == 0) && (gDungeon->unk2 == 0)) {
                sub_804535C(entity, 0);
                entityInfo->unk15C = 0;
                entityInfo->unkFE = 99;
                direction = &entityInfo->action.direction;
                entityInfo->targetPos.x = gAdjacentTileOffsets[*direction].x + entity->pos.x;
                entityInfo->targetPos.y = gAdjacentTileOffsets[*direction].y + entity->pos.y;
                sub_806CE68(entity,*direction);
            }
        }
    }
}

void sub_8085860(s32 x, s32 y)
{
  sub_803F4A0(0);
  sub_803F878(X_POS_TO_PIXELPOS(x), Y_POS_TO_PIXELPOS(y));
}

UNUSED static void sub_8085890(s32 x, s32 y)
{
    sub_803F4A0(0);
    sub_803F878(x, y);
}

void ShiftCameraToPosition(PixelPos *posStruct, s32 cameraSteps)
{
  s32 XPos;
  s32 YPos;
  s32 XIncrement;
  s32 YIncrement;

  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  XIncrement = (posStruct->x - XPos) / cameraSteps;
  YIncrement = (posStruct->y - YPos) / cameraSteps;
  sub_803F4A0(0);
  if (0 < cameraSteps) {
    do {
      XPos += XIncrement;
      YPos += YIncrement;
      sub_803F878(XPos,YPos);
      DungeonRunFrameActions(0x46);
      cameraSteps--;
    } while (cameraSteps != 0);
  }
  sub_803F878(posStruct->x,posStruct->y);
  DungeonRunFrameActions(0x46);
}

void SetFacingDirection(Entity *pokemon, s32 direction)
{
    GetEntInfo(pokemon)->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);
}

void sub_8085930(s32 direction)
{
    s32 index;
    Entity *entity;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityIsValid(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityIsValid(entity))
        {
            if(GetEntInfo(entity)->monsterBehavior == BEHAVIOR_ALLY)
            {
                if(direction >= NUM_DIRECTIONS)
                {
                    sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
                }
                else
                {
                    GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                    sub_806CE68(entity, direction);
                }
            }
        }
    }
}

void sub_80859F0(s32 direction)
{
    s32 index;
    Entity *entity;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityIsValid(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
}

bool8 ShouldRunMonsterAI(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    switch (pokemonInfo->monsterBehavior)
    {
        case BEHAVIOR_RESCUE_TARGET:
        case BEHAVIOR_SKARMORY:
        case BEHAVIOR_GENGAR:
        case BEHAVIOR_EKANS:
        case BEHAVIOR_MEDICHAM:
        case BEHAVIOR_ZAPDOS:
        case BEHAVIOR_MOLTRES:
        case BEHAVIOR_ARTICUNO:
        case BEHAVIOR_GROUDON_2:
        case BEHAVIOR_RAYQUAZA:
        case BEHAVIOR_MANKEY:
        case BEHAVIOR_MEWTWO:
        case BEHAVIOR_ENTEI:
        case BEHAVIOR_RAIKOU:
        case BEHAVIOR_SUICUNE:
        case BEHAVIOR_HO_OH:
        case BEHAVIOR_LATIOS:
        case BEHAVIOR_REGIROCK:
        case BEHAVIOR_REGICE:
        case BEHAVIOR_REGISTEEL:
        case BEHAVIOR_JIRACHI:
        case BEHAVIOR_LUGIA:
        case BEHAVIOR_KYOGRE:
        case BEHAVIOR_29:
        case BEHAVIOR_CELEBI:
        case BEHAVIOR_SMEARGLE:
        case BEHAVIOR_32:
        case BEHAVIOR_33:
        case BEHAVIOR_34:
        case BEHAVIOR_35:
        case BEHAVIOR_MAZE_BOSS:
            return TRUE;
        case BEHAVIOR_FIXED_ENEMY:
        case BEHAVIOR_ALLY:
        case BEHAVIOR_DIGLETT:
        case BEHAVIOR_ALAKAZAM_1:
        case BEHAVIOR_GROUDON_1:
        case BEHAVIOR_ALAKAZAM_2:
        default:
            return FALSE;
    }
}

UNUSED static void sub_8085B0C(Entity *pokemon)
{
  s32 index;
  u8 local_28 [25];

  index = 0;

  memcpy(local_28, gUnknown_8107358, 25);
  while (local_28[index] != 0) {
    SetFacingDirection(pokemon, local_28[index]);
    sub_803E708(6,0x46);
    index++;
  }
}

void sub_8085B4C(struct_8085B80 a0[], s16 *a1[], Entity *a2[], s32 a3)
{
    s32 i;

    gUnknown_202F3D8 = a3;

    for (i = 0; i < a3; i++) {
        a0[i].unk0 = 1;
        a0[i].unk4 = a2[i];
        a0[i].unkC = a1[i];
        a0[i].unk8 = a1[i][2];
    }
}

bool8 sub_8085B80(struct_8085B80 *a0)
{
    s16 *unkCPtr;
    int i;
    bool8 ret = FALSE;

    for (i = 0; i < gUnknown_202F3D8; i++) {
        Entity *entity = a0[i].unk4;
        EntityInfo *enInfo = GetEntInfo(entity);
        unkCPtr = a0[i].unkC;
        if (a0[i].unk0 != 0) {
            ret = TRUE;
            if (a0[i].unk8 == 0) {
                unkCPtr = unkCPtr + 4;
                if (unkCPtr[2] == 0) {
                    a0[i].unk0 = 0;
                    enInfo->action.direction = unkCPtr[0] & DIRECTION_MASK;
                    sub_806CDD4(entity, 7, unkCPtr[0]);
                    sub_80856C8(entity, unkCPtr[5], unkCPtr[6]);
                    continue;
                }
                a0[i].unk8 = unkCPtr[2];
                a0[i].unkC = unkCPtr;
              enInfo->action.direction = unkCPtr[0] & DIRECTION_MASK;
                sub_806CDD4(entity, 0, (int)*unkCPtr);
            }

            a0[i].unk8--;
            IncreaseEntityPixelPos(entity,
                gAdjacentTileOffsets[*unkCPtr].x * unkCPtr[1] * 0x100,
                gAdjacentTileOffsets[*unkCPtr].y * unkCPtr[1] * 0x100);
        }
    }
    return ret;
}

extern OpenedFile *gDungeonPaletteFile;

struct RgbS16
{
    s16 r;
    s16 g;
    s16 b;
};

extern bool8 sub_8004C00(unkStruct_202EE8C *a0, s32 a1, s32 a2, s32 brightness, const RGB *ramp, struct RgbS16 *a5);

extern s32 gDungeonBrightness;
extern RGB gUnknown_202ECA4[];

void SetDungeonBGColorRGB(s32 r, s32 g, s32 b, bool8 a3, bool8 a4)
{
    s32 i, palIndex, n;
    const RGB *colorPtr;
    RGB color;
    struct RgbS16 colorS16;

    n = 160;
    sub_8085E98();
    palIndex = 0;
    colorPtr = gDungeonPaletteFile->data;
    if (a4) {
        if (r >= 0) { r /= 2; }
        if (g >= 0) { g /= 2; }
        if (b >= 0) { b /= 2; }
    }

    color.r = 0;
    color.g = 0;
    color.b = 0;
    SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, gDungeon->colorRamp);
    colorPtr++;
    palIndex++;

    for (i = 1; i < n; i++) {
        s32 newR = colorPtr->r + r;
        s32 newG = colorPtr->g + g;
        s32 newB = colorPtr->b + b;

        if (newR > 0xFF) { newR = 0xFF; }
        if (newG > 0xFF) { newG = 0xFF; }
        if (newB > 0xFF) { newB = 0xFF; }

        if (newR < 0)       { newR = 0; }
        if (newG < 0)       { newG = 0; }
        if (newB < 0)       { newB = 0; }

        color.r = newR;
        color.g = newG;
        color.b = newB;
        SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, gDungeon->colorRamp);
        colorPtr++;
        palIndex++;
    }

    colorS16.r = r;
    colorS16.g = g;
    colorS16.b = b;
    sub_8004C00(gUnknown_202EE8C, 160, 32, gDungeonBrightness, gDungeon->colorRamp, &colorS16);
    palIndex += 32;

    colorPtr = gUnknown_202ECA4;
    n = 32;
    for (i = 0; i < n; i++) {
        s32 newR = colorPtr->r + r;
        s32 newG = colorPtr->g + g;
        s32 newB = colorPtr->b + b;

        if (newR > 0xFF) { newR = 0xFF; }
        if (newG > 0xFF) { newG = 0xFF; }
        if (newB > 0xFF) { newB = 0xFF; }

        if (newR < 0)       { newR = 0; }
        if (newG < 0)       { newG = 0; }
        if (newB < 0)       { newB = 0; }

        color.r = newR;
        color.g = newG;
        color.b = newB;
        SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, gDungeon->colorRamp);
        colorPtr++;
        palIndex++;
    }

    if (a3) {
        colorPtr = gDungeon->paletFile->data;
        palIndex = 256;
        n = 208;
        for (i = 0; i < n; i++) {
            s32 newR = colorPtr->r + r;
            s32 newG = colorPtr->g + g;
            s32 newB = colorPtr->b + b;

            if (newR > 0xFF) { newR = 0xFF; }
            if (newG > 0xFF) { newG = 0xFF; }
            if (newB > 0xFF) { newB = 0xFF; }

            if (newR < 0)       { newR = 0; }
            if (newG < 0)       { newG = 0; }
            if (newB < 0)       { newB = 0; }

            color.r = newR;
            color.g = newG;
            color.b = newB;
            SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, NULL);
            colorPtr++;
            palIndex++;
        }
    }
}

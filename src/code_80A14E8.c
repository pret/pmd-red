#include "global.h"
#include "ground_script.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/item.h"
#include "constants/monster.h"
#include "constants/move_id.h"
#include "code_80118A4.h"
#include "code_8099360.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_80972F4.h"
#include "code_80A26CC.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "ground_lives.h"
#include "ground_main.h"
#include "input.h"
#include "items.h"
#include "main_loops.h"
#include "music.h"
#include "other_random.h"
#include "random.h"
#include "string_format.h"
#include "structs/str_wonder_mail.h"
#include "text_util.h"
#include "pokemon.h"

void sub_8098C58(void);
void sub_8098CC8(void);
bool8 sub_80961D8(void);
void ResetMailbox(void);
void sub_80963FC(void);
void sub_8096488(void);
bool8 sub_80964B4(void);
extern void nullsub_104(void);
s16 sub_80A8C4C();
s16 sub_80A90C8();
bool8 sub_8097640();
u8 sub_80964E4();
s32 sub_80A8E9C();
u8 sub_80A8D20();
bool8 sub_80A87E0();
s16 sub_80A8BFC(s16);
void sub_80A8F50(const u8 *buffer, s32, s32 size);

extern const u8 *gFriendAreaDialogue[];
extern struct unkStruct_808D144 gUnknown_8116710;
extern struct unkStruct_808D144 gUnknown_8116760;
extern struct unkStruct_808D144 gUnknown_8116794;
extern struct unkStruct_808D144 gUnknown_81167BC;
extern struct unkStruct_808D144 gUnknown_8116738;
extern struct unkStruct_808D144 gUnknown_811681C;
extern DungeonLocation gUnknown_81167E8;
extern DungeonLocation gUnknown_8116788;
extern DungeonLocation gUnknown_811678C;
extern DungeonLocation gUnknown_8116790;
extern u16 gUnknown_2039DA8;
extern u8 gUnknown_2039D98[POKEMON_NAME_LENGTH];

PokemonStruct1 *sub_808D278(s32 species);
PokemonStruct1 *sub_808D2E8(s32 species, u8 *name, u32 _itemID, DungeonLocation *location, u16 *moveID);
bool8 HasRecruitedMon(s32 species);
extern Item gUnknown_8116844;
extern Item gUnknown_81167E4;
bool8 sub_809124C(u8 id, u8 param_3);
extern const u8 gUnknown_81167EC[];
void sub_80A56A0(s32, s32);
void sub_80A56F0();
void sub_80A5704();
void sub_809C760(void);
void sub_809C6EC(void);
void sub_809C6CC(u16 param_1);
void sub_80A86C8(s16, s32);
void sub_80AC1B0(s16, s32);
void sub_80AD0C8(s16, s32);
s32 sub_80A5984();
void sub_80A59A0(s32, s32 *, u16);
void GroundSprite_ExtendPaletteAdd(u32, u16);
void GroundSprite_ExtendPaletteDelete(u32);
extern void sub_80997F4(u16, u16);
s32 sub_809CFE8(u16 param_1);
extern bool8 sub_80A579C(PixelPos *a0, PixelPos *a1);

// save.h
void sub_8011C40(s32 x);
s32 sub_8011C34(void);
extern void sub_8011C28(u32);

bool8 ScriptPrintText(s32, s16, const char*);
PokemonStruct1 *sub_80A8D54(s16);
void IncrementAdventureNumJoined(void); // sub_8097848

// resuce_team_info
u8 GetRescueTeamRank(void);
void AddToTeamRankPts(s32);
s32 GetPtsToNextRank(void);
const u8 *GetTeamRankString(s32);

PixelPos SetVecFromDirectionSpeed(s8 r1, u32 r2);

s16 GroundEffect_Add(s16 id, GroundEffectData*, s16 group, s8 sector);
extern Action *sub_80AD158(s16);

s32 sub_80A14E8(Action *action, u8 idx, u32 r2, s32 r3)
{
    switch(idx)
    {
        case 1:
            sub_8098C58();
            return 0;
        case 2:
            if(sub_8011C34() == -1)
                sub_8011C40(Rand32Bit());
            sub_8011C28(1);
            sub_8001064();
            sub_809965C();
            return 0;
        case 3:
            sub_8098CC8();
            return 0;
        case 4:
            return sub_80961D8() == 0 ? 0 : 1;
        case 5:
            ResetMailbox();
            return 0;
        case 6:
            sub_80963FC();
            return 0;
        case 7:
            sub_8096488();
            return 0;
        case 8:
            return sub_80964B4() == 0 ? 0 : 1;
        case 9:
            {
                u8 var;
                if (sub_80023E4(8) == 0) {
                    var = sub_808D4B0();
                }
                else {
                    var =  sub_808D500();
                }
                nullsub_104();
                return var != 0;
            }
            break;
        case 0xA:
            {
                s32 ret;
                s32 ret2;
                if ((action->unkC).arr[0] == 1)
                {
                    u8 text[0x100];
                    DungeonLocation dungLocation;
                    ret = sub_80A8C4C((action->unkC).arr[1], &dungLocation);
                    if(ret != 0)
                    {
                        if (dungLocation.id == 0x44 && ret == 0x104) {
                            return 2;
                        }
                        
                        ret2 = sub_80A90C8((action->unkC).arr[1]);
                        InlineStrcpy(text, gFriendAreaDialogue[ret2]);
                        if (ScriptPrintText(0, 1, text) != 0)
                            return 1;
                    }
                }
            }
            return 0;
        case 0xB:
            return (CountJobsinDungeon(sub_80A2740(GetScriptVarValue(0, 0x14))) > 0);
        case 0xC:
            {
                u8 sp_104;
                if(sub_8099394(&sp_104) != 0)
                {
                    unkStruct_203B480 *p = gUnknown_203B480;
                    p += sp_104;
                    if(p->rescuesAllowed > 0)
                        return 1;
                }
            }
            return 0;
        case 0xD:
            return sub_8097640() ? 1 : 0;
            break;
        case 0xE:
            { 
                s32 index;
                for(index = 0x11; index < NUM_DUNGEON_MAZE; index++)
                {
                    if (IsMazeCompleted((s16) index)) {
                        if (!GetScriptVarArrayValue(0, 0x2F, (u16) index)) {
                            SetScriptVarArrayValue(0, 0x2F, (u16) index, 1);
                            return index - 0x10;
                        }
                    }
                }
                return 0;
            }
        case 0xF:
            return sub_80964E4() == 0 ? 0 : 1;
        case 0x10:
            if(action->unk8[0] == 1)
                if(action->unk8[1] == 0)
                    if(action->unkC.arr[0] == 1)
                    {
                        if(sub_80A87E0(action->unk8[1], sub_80A8E9C(action->unkC.arr[1])) != 0)
                            return 1;
                    }
            return 0;
        case 0x11:
            return sub_80A8D20() == 0 ? 0 : 1;
        case 0x12:
            {
                s32 held = gRealInputs.held;
                if((held & (R_BUTTON | L_BUTTON)))
                    return 1;
                else
                    return 0;
            }
            
        case 0x13:
            {
                PokemonStruct1 *ptr;
                
                ptr = sub_80A8D54(r2);
                if(ptr)
                    return PokemonFlag2(ptr);
            }
            return 0;
        case 0x14:
            if(action->unk8[0] == 1)  {
                if(GetCanMoveFlag(sub_80A8BFC(action->unk8[1])))
                    return 1;
            }
            return 0;
        case 0x15:
            {
                s32 r4;
                PixelPos sp_318;
                PixelPos sp_320;
                s32 r5 = sub_80A7AE8(r2);
                if(r5 >= 0) {
                    r4 = (r3 << 8);
                    action->callbacks->getHitboxCenter(action->parentObject, &sp_318);
                    sub_80A8FD8(r5, &sp_320);
            
                    if(sp_318.x - r4 <= sp_320.x
                        && sp_318.x + r4 >= sp_320.x
                        && sp_318.y - r4 <= sp_320.y
                        && sp_318.y + r4 >= sp_320.y)
                    {
                        return 1;
                    }
                }
            }
            return 0;
        case 0x16:
            {
                s32 index;
                PokemonStruct1 *ptr; ptr = sub_80A8D54(1);
                if(ptr)
                {
                    for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                    {
                        ptr->name[index] = 0;
                    }
                    return 1;
                }
            }
            return 0;
        case 0x17:
            UnlockFriendArea(WILD_PLAINS);
            UnlockFriendArea(MIST_RISE_FOREST);
            return 0;
        case 0x18:
            sub_80A8F50(gUnknown_2039D98, 0x3C, POKEMON_NAME_LENGTH);
            return 0;
        case 0x19:
            {
                struct unkStruct_808D144 sp_4;
                PokemonStruct1 sp_2c;
                PokemonStruct1 *ptr;
                s32 index;
                
                
                UnlockFriendArea(GetFriendArea(MONSTER_MAGNEMITE));
                sp_4 = gUnknown_8116710;
                sub_808D144(&sp_2c, &sp_4);
                ptr = sub_808D1DC(&sp_2c);
                if (ptr == NULL) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    ptr->name[index] = gUnknown_2039D98[index];
                }
                sub_80922B4(gFormatBuffer_Names[r2], gUnknown_2039D98, POKEMON_NAME_LENGTH);
                IncrementAdventureNumJoined();
                return 0;
            }
            break;

        case 0x1A:
            sub_80A8F50(gUnknown_2039D98, 0x53, POKEMON_NAME_LENGTH);
            return 0;

         case 0x1B:
             {
                PokemonStruct1 *pokemon;
                 struct unkStruct_808D144 sp_84;
                 PokemonStruct1 sp_ac;
                 
                UnlockFriendArea(GetFriendArea(MONSTER_ABSOL));
                sp_84 = gUnknown_8116738;
                sub_808D144(&sp_ac, &sp_84);
                pokemon = sub_808D1DC(&sp_ac);
                if(pokemon == NULL) return 1;
                IncrementAdventureNumJoined();
                pokemon->unk0 |= FLAG_ON_TEAM;
                return 0;
             }
        case 0x1C:
            {
                PokemonStruct1 *pokemon = sub_808D434(MONSTER_ABSOL, 0);
                if(pokemon == NULL) return 1;
                pokemon->unk0 |= FLAG_ON_TEAM;
                return 0;
            }
        case 0x1D:
            {
                if( sub_808D278(MONSTER_SMEARGLE) == 0)
                    return 1;
                else
                    return 0;
            }
        case 0x1E:
             sub_80A8F50(gUnknown_2039D98, 0x7C, POKEMON_NAME_LENGTH);
             return 0;
        
        case 0x1F:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                struct unkStruct_808D144 sp_108;
                PokemonStruct1 sp_130;
                
                sp_108 = gUnknown_8116760;
                sub_808D144(&sp_130, &sp_108);
                pokemon = sub_808D1DC(&sp_130);
                if(!pokemon) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    pokemon->name[index] = gUnknown_2039D98[index];
                }
                sub_80922B4(gFormatBuffer_Names[r2], gUnknown_2039D98, POKEMON_NAME_LENGTH);
                IncrementAdventureNumJoined();
                return 0;
               
            }
            break;

        case 0x20:
            {
                sub_80026E8(0x9E, 0x1);
                if(sub_808D434(MONSTER_ZAPDOS, 0) == NULL)
                {
                    if(sub_808D2E8(MONSTER_ZAPDOS, NULL, ITEM_NOTHING, &gUnknown_8116788, NULL))
                        IncrementAdventureNumJoined();
                }
                if(sub_808D434(MONSTER_MOLTRES, 0) == NULL)
                {
                    if(sub_808D2E8(MONSTER_MOLTRES, NULL, ITEM_NOTHING, &gUnknown_811678C, NULL))
                        IncrementAdventureNumJoined();
                }
                if(sub_808D434(MONSTER_ARTICUNO, 0) == NULL)
                {
                    if(sub_808D2E8(MONSTER_ARTICUNO, NULL, ITEM_NOTHING, &gUnknown_8116790, NULL))
                        IncrementAdventureNumJoined();
                }
                return 0;
            }
            break;
        

        case 0x21:
            if(HasRecruitedMon(MONSTER_ARTICUNO))
                if(HasRecruitedMon(MONSTER_ZAPDOS))
                    if(HasRecruitedMon(MONSTER_MOLTRES))
                        return 1;
            return 0;
        case 0x22:
            {
                PokemonStruct1 *pokemon = GetPlayerPokemonStruct();
                
                if(pokemon->speciesNum != MONSTER_ARTICUNO && pokemon->speciesNum != MONSTER_ZAPDOS && pokemon->speciesNum != MONSTER_MOLTRES)
                    return 1;
            }
            return 0;
         case 0x23:
            {
                PokemonStruct1 *pokemon;
                pokemon = GetPlayerPokemonStruct();
                if (pokemon != NULL && pokemon->speciesNum == MONSTER_HO_OH)
                    return 2;
                else if (sub_8098134(MONSTER_HO_OH) != 0)
                    return 1;
            }
            return 0;
        case 0x24:
            sub_80A8F50(gUnknown_2039D98, 0x79, POKEMON_NAME_LENGTH);
            return 0;

        case 0x25:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                struct unkStruct_808D144 sp_188;
                PokemonStruct1 sp_1b0;
                
                if(!GetFriendAreaStatus(GetFriendArea(MONSTER_LATIOS)))
                    UnlockFriendArea(GetFriendArea(MONSTER_LATIOS));
                sp_188 = gUnknown_8116794;
                sub_808D144(&sp_1b0, &sp_188);
                pokemon = sub_808D1DC(&sp_1b0);
                if(pokemon == NULL) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    pokemon->name[index] = gUnknown_2039D98[index];
                }
                IncrementAdventureNumJoined();
                return 0;
            }
            
            break;
        case 0x26:
            sub_80A8F50(gUnknown_2039D98, 0x7A, POKEMON_NAME_LENGTH);
            return 0;
        case 0x27:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                struct unkStruct_808D144 sp_208;
                PokemonStruct1 sp_230;
                
                sp_208 = gUnknown_81167BC;
                sub_808D144(&sp_230, &sp_208);
                pokemon = sub_808D1DC(&sp_230);
                if(pokemon == NULL) return 1;
                for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                {
                    pokemon->name[index] = gUnknown_2039D98[index];
                }
                IncrementAdventureNumJoined();
                return 0;
            }
            break;

        case 0x28:
            {
                if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                {
                    Item *item = &gUnknown_81167E4;
                    s32 id = item->id;
                    if(IsNotMoneyOrUsedTMItem(id))
                        if(gTeamInventoryRef->teamStorage[id] < 999)
                            gTeamInventoryRef->teamStorage[id] += 1;
                        
                }
                else
                {
                    Item *item = &gUnknown_81167E4;
                    sub_809124C(item->id, 0);
                    FillInventoryGaps();
                }
            }
            return 0;

        case 0x29:
            {
                s32 index = (s16)(RandInt(0x1A2) + 1);
                s32 r4 = RandInt(0x20);
                s32 r7 = 0x1A4;
                s32 r6 = 0;

                while (1)
                {
                    s16 indexS16;
                    index = (s16)(index + 1);
                    if (index >= 0x1a4) {
                        index = 1;
                    }
                    if (--r7 < 0) {
                        if (r6 == 0) {
                            SetScriptVarValue(NULL, 0x1F, 0);
                            return 0;
                        }
                        if (r4 >= r6) {
                            r4 = RandInt(r6);
                            r7 = 0x1A4;
                        }
                    }
                    // S16 memes AGAIN...
                    indexS16 = index;
                    index = indexS16;
                    if (indexS16 == MONSTER_ARTICUNO || indexS16 == MONSTER_ZAPDOS || indexS16 == MONSTER_MOLTRES
                        || indexS16 == MONSTER_GROUDON
                        || indexS16 == MONSTER_RAYQUAZA
                        || indexS16 == MONSTER_RAYQUAZA_CUTSCENE
                        || indexS16 == MONSTER_KYOGRE
                        || indexS16 == MONSTER_LUGIA
                        || indexS16 == MONSTER_CASTFORM_SNOWY
                        || indexS16 == MONSTER_CASTFORM_SUNNY
                        || indexS16 == MONSTER_CASTFORM_RAINY
                        || indexS16 == MONSTER_DEOXYS_NORMAL
                        || indexS16 == MONSTER_DEOXYS_ATTACK
                        || indexS16 == MONSTER_DEOXYS_DEFENSE
                        || indexS16 == MONSTER_DEOXYS_SPEED
                        || indexS16 == MONSTER_MEWTWO
                        || indexS16 == MONSTER_JIRACHI
                        || indexS16 == MONSTER_MEW
                        || indexS16 == MONSTER_LATIAS
                        || indexS16 == MONSTER_LATIOS
                        || indexS16 == MONSTER_ENTEI
                        || indexS16 == MONSTER_RAIKOU
                        || indexS16 == MONSTER_SUICUNE
                        || indexS16 == MONSTER_HO_OH
                        || indexS16 == MONSTER_REGIROCK
                        || indexS16 == MONSTER_REGICE
                        || indexS16 == MONSTER_REGISTEEL
                        || indexS16 == MONSTER_CELEBI
                        ) 
                        continue;
                    if(!IsExclusivePokemonUnlocked(index)) continue;
                    if(GetFriendAreaStatus(GetFriendArea(index))) {
                        if(HasRecruitedMon(index)) continue;
                        if(sub_808D278(index) == 0) continue;
                    }

                    r6++;
                    r4--;
                    if (r4 < 0)
                        break;
                }
                
                SetScriptVarValue(NULL, 0x1F, index); // NEW_FRIEND_KIND
                WriteFriendAreaName(gFormatBuffer_FriendArea, GetFriendArea(index), 0);
                if (GetFriendAreaStatus(GetFriendArea(index)) != 0)
                    return 1;
                else
                    return 2;
            }
        case 0x2A:
            {
                s32 id = (s16) GetScriptVarValue(0, 0x1F); // NEW_FRIEND_KIND
                WriteFriendAreaName(gFormatBuffer_FriendArea,(GetFriendArea(id)), 0);
                if (id == 0) 
                    return 0;
                else if(GetFriendAreaStatus(GetFriendArea(id)) != 0)
                   return 1;
                else
                   return 2;
            }
            break;
        case 0x2B:
            sub_80A8F50(gUnknown_2039D98, 0x20, POKEMON_NAME_LENGTH);
            return 0;
        case 0x2C:
            {
                PokemonStruct1 *pokemon;
                s32 index;
                  if(r2 != 0)
                  {
                    s32 id = (s16) GetScriptVarValue(0, 0x1F); // NEW_FRIEND_KIND
                      s32 matchMe = id;
                     WriteFriendAreaName(gFormatBuffer_FriendArea,(GetFriendArea((s16) id)), FALSE);
                    if(id == 0) 
                        return 0;
                
                    if(!GetFriendAreaStatus(GetFriendArea(id)))
                        UnlockFriendArea(GetFriendArea(id));
                    pokemon = sub_808D2E8(matchMe, NULL ,ITEM_NOTHING, &gUnknown_81167E8, MOVE_NOTHING);
                    if(pokemon == NULL)
                        return 0;
                    
                    for(index = 0; index < POKEMON_NAME_LENGTH; index++)
                        pokemon->name[index] = gUnknown_2039D98[index];
                    IncrementAdventureNumJoined();
                    return 1;
                  }
                  else
                  {
                      SetScriptVarValue(NULL, 0x1F, 0); // NEW_FRIEND_KIND
                      return 0;
                  }
            }

        case 0x2D:
            if(GetPtsToNextRank() > 0)
                return 1;
            else
                return 0;
        case 0x2E:
            {
                s32 rankBefore = GetRescueTeamRank();
                s32 points = GetPtsToNextRank();
                if(points > 0) {
                    s32 rankAfter;
                    AddToTeamRankPts(points);
                    rankAfter = GetRescueTeamRank();
                    InlineStrcpy(gFormatBuffer_Items[0], GetTeamRankString(rankBefore));
                    InlineStrcpy(gFormatBuffer_Items[1], GetTeamRankString(rankAfter));
                    if(ScriptPrintText(0, -1, gUnknown_81167EC) != 0)
                        return 1;
                }
                else {
                    return 0;
                }
            }
        // breakthrough
        case 0x2F:
            AddToTeamMoney(0x2710);
            return 0;
        case 0x30:
            {
                if(sub_808D278(MONSTER_GARDEVOIR) == 0)
                    return 1;
                else
                    return 0;
            }
            break;
        case 0x31:
            sub_80A8F50(gUnknown_2039D98, 0x52, POKEMON_NAME_LENGTH);
            return 0;

        case 0x32:
            {   
                struct unkStruct_808D144 sp_288;
                PokemonStruct1 sp_2b0;
                sp_288 = gUnknown_811681C;
                sub_808D144(&sp_2b0, &sp_288);
                if(sub_808D1DC(&sp_2b0) == 0) {
                    return 1;
                }
                else {
                    IncrementAdventureNumJoined();
                    return 0;
                }
            }
        case 0x33:
            if(ScriptVarScenarioAfter(3, 0x12, -1))
            {
                if(GetScriptVarValue(0, 0xF) != 4)
                {
                    if (GetScriptVarArrayValue(0, 0x42, 0) <= 0)
                    {
                        if(OtherRandInt(0x100) == 0)
                        {
                            SetScriptVarArrayValue(0, 0x42, 0, 4);  
                            return 1;
                        }
                        else
                            SetScriptVarArrayValue(0, 0x42, 0, 1);
                    }
                }
            }
            return 0;
        
        case 0x34:
            {
                s32 index;
                s32 id;
                Item *item = &gUnknown_8116844;
                for(index = 0; index < 3; index++)
                {
                    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                    {
                        id = item->id;
                        if(IsNotMoneyOrUsedTMItem(id))
                            if(gTeamInventoryRef->teamStorage[id] < 999)
                                gTeamInventoryRef->teamStorage[id] += 1;
                        
                    }
                    else
                    {
                        sub_809124C(item->id, 0);
                        FillInventoryGaps();
                    }
                }
            }
            return 0;
        case 0x35:
            {
                PokemonStruct1 *pokemon = GetPlayerPokemonStruct();
                if(pokemon != NULL && pokemon->speciesNum == MONSTER_CHANSEY)
                    return 2;
                else
                    if(sub_8098134(MONSTER_CHANSEY) != 0)
                        return 1;
                    else
                        return 0;
            }
            break;

        case 0x38:
            sub_80A56A0(0, 1);
            return 0;
        case 0x36: {
            s32 sp_328[2];
            sp_328[0] = r2;
            sp_328[1] = r3;
            sub_80A56F0(sp_328);
            return 0;
        }
        case 0x37: {
            s32 sp_330[2];
            sp_330[0] = r2;
            sp_330[1] = r3;
            sub_80A5704(sp_330);
            return 0;
        }
        case 0x39:
            sub_809C6CC(r2);
            return 0;
        case 0x3A:
            sub_809C6EC();
            return 0;
        case 0x3B:
            sub_809C760();
            return 0;
        case 0x3C:
            {
                s32 index;
                index = 0;
                for(index = 0; index < 0x18; index = (s16)(index + 1))
                {
                    sub_80A86C8(index, 0x400000);
                }
                for (index = 0; index < 0x10; index = (s16)(index + 1))
                {
                    sub_80AC1B0(index, 0x400000);
                }
                for (index = 0; index < 0x10; index = (s16)(index + 1))
                {
                    sub_80AD0C8(index, 0x400000);
                }
            }
            return 0;
        case 0x3D: {
            s32 sp_338[2];
            sp_338[0] = r2;
            sp_338[1] = r3;
            sub_80A59A0(0, sp_338, sub_80A5984(1, sp_338));
            return 0;
        }
        case 0x3E:
            {
                s32 ret;
                Action *r7;
                GroundEffectData sp_308;
                PixelPos sp_340;
                PixelPos sp_348;
                PixelPos sp_350;
                PixelPos sp_358;
                
                sp_308.kind = 1;
                sp_308.unk1 = 0;
                sp_308.width = 1;
                sp_308.height = 1;
                sp_308.pos = (CompactPos) {0};
                sp_308.script = gFunctionScriptTable[0x196].script;
                ret = GroundEffect_Add(-1, &sp_308, r2, r3);
                if(ret < 0) break;
                r7 = sub_80AD158(ret);
                sub_80A579C(&sp_340, &sp_348);
                sp_340.y += 0xC00;
                sp_348.y += 0xC00;
                action->callbacks->getHitboxCenter(action->parentObject, &sp_350);
                if(sp_350.x < sp_340.x)
                    sp_350.x = sp_340.x;
                else if (sp_350.x >= sp_348.x)
                    sp_350.x = sp_348.x - 1;
                if(sp_350.y < sp_340.y)
                    sp_350.y = sp_340.y;
                else if (sp_350.y >= sp_348.y)
                    sp_350.y = sp_348.y - 1;

                sp_340.x -= 1024;
                sp_340.y -= 1024;
                sp_348.x += (0x80 << 3);
                sp_348.y += (0x80 << 3);

                r7->callbacks->setPositionBounds(r7->parentObject, &sp_340, &sp_348);
                r7->callbacks->moveReal(r7->parentObject, &sp_350);
                sp_358 = (PixelPos) {0};
                r7->callbacks->moveRelative(r7->parentObject, &sp_358);
                return 1;
            }
            break;

        case 0x3F:
            {
                s32 index;
                s32 ret;
                s32 held = gRealInputs.held;
                s32 pressed = gRealInputs.pressed;
                if(!(pressed & (START_BUTTON | SELECT_BUTTON)))
                {
                    PixelPos sp_368;
                    ret = sub_809CFE8(held);
                    if((s8)ret != -1)
                    {
                        s32 to;
                        sp_368 = SetVecFromDirectionSpeed(ret,0x100);

                        to = 2;
                        if(held & B_BUTTON) {
                            to = 4;
                        }
                        
                        for(index = 0; index < to; index++)
                        {
                            if(action->callbacks->moveRelative(action->parentObject, &sp_368) != 0)
                            {
                                PixelPos pixelPos = {0, sp_368.y};
                                if(action->callbacks->moveRelative(action->parentObject, &pixelPos) != 0)
                                {
                                    PixelPos pixelPos = {sp_368.x, 0};
                                    action->callbacks->moveRelative(action->parentObject, &pixelPos);
                                }
                            }
                        }             
                    }
                    return -1;
                }
            }
            break;
        
        case 0x40:
            sub_80993C0(r2 == 0 ? 0 : 1);
            return 0;
        case 0x42:
            sub_8011C28(1);
            GroundMainGameEndRequest(r2);
            FadeOutAllMusic(r2);
            return 0;
        case 0x41:
            GroundMainGameEndRequest(r2);
            FadeOutAllMusic(r2);
            return 0;
        case 0x43:
            gUnknown_2039DA8 = GetCurrentBGSong();
            if(gUnknown_2039DA8 != STOP_BGM) 
                return 1;
            return 0;
        case 0x44:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                xxx_call_start_new_bgm(gUnknown_2039DA8);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x45:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                xxx_call_fade_in_new_bgm(gUnknown_2039DA8, r2);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x46:
            if (gUnknown_2039DA8 != STOP_BGM)
            {
                xxx_call_queue_bgm(gUnknown_2039DA8);
                gUnknown_2039DA8 = STOP_BGM;
                return 1;
            }
            return 0;
        case 0x47:
            sub_80997F4(r2, r3);
            return 0;
        case 0x48:
            sub_80997F4(0x1E, r2);
            return 0;
        case 0x49:
            GroundSprite_ExtendPaletteAdd(0, r2);
            return 0;
        case 0x4A:
            GroundSprite_ExtendPaletteDelete(0);
            return 0;
    }

    return 0;
}


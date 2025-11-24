//#ifndef GUARD_DATA_SCRIPT_H
//#define GUARD_DATA_SCRIPT_H

#include "constants/bg_music.h"
#include "constants/cutscenes.h"
#include "constants/direction.h"
#include "constants/event_flag.h"
#include "constants/ground_map.h"
#include "constants/item.h"
#include "constants/rescue_dungeon_id.h"
#include "constants/script_dungeon_id.h"
#include "constants/script_cmd.h"
#include "constants/script_id.h"
#include "structs/str_ground_script.h"
#include "ground_place.h"
#include "portrait_placement.h"

#define LPARRAY(x) (ARRAY_COUNT(x)), x

#define CPOS_HALFTILE 0x2
#define CPOS_CURRENT  0x4

// 01..07: complex map/dungeon selection/check commands

// TODO: CMD_BYTE_01

// Seems to be a general command for setting up which dungeon to enter next.
// u: Unknown.
// d: enum "ScriptDungeonId".
#define NEXT_DUNGEON(u, d)              { CMD_BYTE_02, 0, u, d, 0, NULL }

// TODO: CMD_BYTE_03

// TODO: CMD_BYTE_04

// TODO: CMD_BYTE_05

// TODO: CMD_BYTE_06

// TODO: CMD_BYTE_07

// m: enum "GroundMapID".
#define SELECT_MAP(m)                   { CMD_BYTE_08, 0, 0, m, 0, NULL }

#define SELECT_GROUND(m)                { CMD_BYTE_09, 0, 0, m, 0, NULL }

#define SELECT_DUNGEON(m, d, f, b)      { CMD_BYTE_0A, b, f, d, m, NULL }

#define SELECT_WEATHER(w)               { CMD_BYTE_0B, 0, 0, w, 0, NULL }

// Uses the map from SELECT_MAP.
// Does GroundLives_Select(), GroundObject_Select(), GroundEffect_Select(), and GroundEvent_Select().
// g: Group. -1 will use the ScriptInfo group.
// s: Sector. -1 will use the ScriptInfo sector.
#define SELECT_ENTITIES(g, s)           { CMD_BYTE_0C, s, g, 0, 0, NULL }

#define SELECT_LIVES(g,s)               { CMD_BYTE_0D, s, g, 0, 0, NULL }

#define SELECT_OBJECTS(g,s)             { CMD_BYTE_0E, s, g, 0, 0, NULL }

#define SELECT_EFFECTS(g,s)             { CMD_BYTE_0F, s, g, 0, 0, NULL }

#define SELECT_EVENTS(g,s)              { CMD_BYTE_10, s, g, 0, 0, NULL }

#define CANCEL_ENTITIES(g,s)            { CMD_BYTE_11, s, g, 0, 0, NULL }

#define CANCEL_LIVES(g,s)               { CMD_BYTE_12, s, g, 0, 0, NULL }

#define CANCEL_OBJECTS(g,s)             { CMD_BYTE_13, s, g, 0, 0, NULL }

#define CANCEL_EFFECTS(g,s)             { CMD_BYTE_14, s, g, 0, 0, NULL }

#define CANCEL_EVENTS(g,s)              { CMD_BYTE_15, s, g, 0, 0, NULL }

#define CANCEL_OFFSCREEN_LIVES          { CMD_BYTE_16, 0, 0, 0, 0, NULL }

#define CANCEL_OFFSCREEN_OBJECTS        { CMD_BYTE_17, 0, 0, 0, 0, NULL }

#define CANCEL_OFFSCREEN_EFFECTS        { CMD_BYTE_18, 0, 0, 0, 0, NULL }

#define SPAWN_OBJECT(k,d,g,s)           { CMD_BYTE_19, s, g, d, k, NULL }

#define SPAWN_EFFECT(k,d,g,s)           { CMD_BYTE_1A, s, g, d, k, NULL }

// f: enum "ScriptID".
#define EXECUTE_FUNCTION(f)             { CMD_BYTE_1B, 0, f, 0, 0, NULL }

// f: enum "ScriptID".
#define EXECUTE_SUBROUTINE(f)           { CMD_BYTE_1C, 0, f, 0, 0, NULL }

#define EXECUTE_STATION(m,g,s)          { CMD_BYTE_1D, s, g, m, 0, NULL }

#define EXECUTE_SUBSTATION(m,g,s)       { CMD_BYTE_1E, s, g, m, 0, NULL }

#define RESCUE_SELECT                   { CMD_BYTE_1F, 0, 0, 0, 0, NULL }

// TODO: CMD_BYTE_20: execute script as parented object, maybe? Unused in ROM

// TODO: CMD_BYTE_21: follow object/make object follow/get parented?

// TODO: CMD_BYTE_22

// TODO: CMD_BYTE_23

// TODO: CMD_BYTE_24

// TODO: CMD_BYTE_25

// TODO: CMD_BYTE_26

// TODO: CMD_BYTE_27

// TODO: CMD_BYTE_28

// TODO: CMD_BYTE_29

// TODO: CMD_BYTE_2A

// Waits specified number of frames, then automatically does a button press without waiting for player's input.
// -1 disables it.
#define TEXTBOX_AUTO_PRESS(endF, midF)  { CMD_BYTE_2B, 0, 0, endF, midF, NULL}

// TODO: CMD_BYTE_2C

// TODO: CMD_BYTE_2D

// Sets up portrait data for the specified speaker
// Note for the spriteId: first 4 bits(0xF) are the actual spriteId, but sometimes a 0x40 flag is attached to it, but it has no practical use.
// Could be different in Blue?
#define PORTRAIT(place, id, sprite)     { CMD_BYTE_2E, place, id, sprite, 0, NULL }

// Same as the above, but it assumes the last used placement for the speaker.
// Useful in long scripts, where you don't need to remember all the placements.
#define PORTRAIT_REP(id, sprite)        { CMD_BYTE_2E, PLACEMENT_COUNT, id, sprite, 0, NULL }

// Sets portrait delta position, which modifies the portrait's position on the screen.
#define PORTRAIT_POS(id, x, y)          { CMD_BYTE_2F, 0, id, x, y, NULL }

#define TEXTBOX_CLEAR                   { CMD_BYTE_30, 0, 0, 0, 0, NULL }

// Used rarely. I don't think there's a functional difference from TEXTBOX_CLEAR.
#define TEXTBOX_CLEAR2                  { CMD_BYTE_31, 0, 0, 0, 0, NULL }

#define MSG_INSTANT(msg)                { CMD_BYTE_32, 0, -1, 0, 0, msg }

// TODO: CMD_BYTE_33

// ID is portrait id of the npc. -1 means no portrait
#define MSG_NPC(id, msg)                { CMD_BYTE_34, 0, id, 0, 0, msg }

#define MSG_LETTER(msg)                 { CMD_BYTE_35, 0, -1, 0, 0, msg }

// TODO: CMD_BYTE_36

// Prints raw text on bg without any windows.
// Used for the intro portal messages.
// To advance the text, the player needs to press a button.
#define MSG_ON_BG(msg)                  { CMD_BYTE_37, 0, -1, 0, 0, msg }

// Identical to the above, used literally once for just a newline.
#define MSG_ON_BG2(msg)                 { CMD_BYTE_38, 0, -1, 0, 0, msg }

// Similar to the above, but the message appears and fades automatically, without any player's input.
// Used for narration text.
// The short argument isn't really used, but needs to be greater than 0.
#define MSG_ON_BG_AUTO(u, msg)          { CMD_BYTE_39, 0, u, 0, 0, msg }

// TODO: CMD_BYTE_3A: yes/no choice (only used for saving)

// TODO: CMD_BYTE_3B: uber command (conditional jump)
// k=0x30 checks if gardevoir has space to join by checking its friend area
// k=0x31 names gardevoir?
// k=0x32 tries to recruit Gardevoir

// k: See enum "SpecialTextKind"
// i: ???
// t: ???
#define SPECIAL_TEXT(k, i, t)           { CMD_BYTE_3C, k, 0, i, t, NULL }

#define RENAME_ALLY(id)                 { CMD_BYTE_3D, 0, 0, id, 0, NULL }

#define RENAME_TEAM                     { CMD_BYTE_3E, 0, 0, 0, 0, NULL }

// TODO: CMD_BYTE_3F: input box?

// TODO: CMD_BYTE_40: unused?

#define REMOVE_ITEMSTACK(i)             { CMD_BYTE_41, 0, i, 0, 0, NULL }

#define MUSIC_STOP_ALL                  { CMD_BYTE_42, 0, 0, 0, 0, NULL }

#define MUSIC_FADEOUT_ALL(f)            { CMD_BYTE_43, 0, f, 0, 0, NULL }

#define BGM_SWITCH(i)                   { CMD_BYTE_44, 0, 0, i, 0, NULL }

#define BGM_FADEIN(f,i)                 { CMD_BYTE_45, 0, f, i, 0, NULL }

#define BGM_QUEUE(i)                    { CMD_BYTE_46, 0, 0, i, 0, NULL }

#define BGM_STOP                        { CMD_BYTE_47, 0, 0, 0, 0, NULL }

#define BGM_FADEOUT(f)                  { CMD_BYTE_48, 0, f, 0, 0, NULL }

#define FANFARE_PLAY(i)                 { CMD_BYTE_49, 0, 0, i, 0, NULL }

#define FANFARE_STOP(i)                 { CMD_BYTE_4A, 0, 0, i, 0, NULL }

#define FANFARE_FADEOUT(f,i)            { CMD_BYTE_4B, 0, f, i, 0, NULL }

#define FANFARE_PLAY2(i)                { CMD_BYTE_4C, 0, 0, i, 0, NULL }

#define FANFARE_STOP2(i)                { CMD_BYTE_4D, 0, 0, i, 0, NULL }

#define FANFARE_FADEOUT2(f,i)           { CMD_BYTE_4E, 0, f, i, 0, NULL }

// TODO: CMD_BYTE_4F

// TODO: CMD_BYTE_50

// TODO: CMD_BYTE_51

// TODO: CMD_BYTE_52

// TODO: CMD_BYTE_53

#define SELECT_ANIMATION(id)            { CMD_BYTE_54, 0, id, 0, 0, NULL }

// TODO: CMD_BYTE_55

// TODO: CMD_BYTE_56

// TODO: CMD_BYTE_57

// TODO: CMD_BYTE_58

// TODO: CMD_BYTE_59

// TODO: CMD_BYTE_5A

// For WARP/WALK, every map has a list of predefined locations.
#define WARP_WAYPOINT(u,w)              { CMD_BYTE_5B, u, 0, w, 0, NULL }

// TODO: CMD_BYTE_5C

// TODO: CMD_BYTE_5D

// TODO: CMD_BYTE_5E

// TODO: CMD_BYTE_5F

// TODO: CMD_BYTE_60

// TODO: CMD_BYTE_61

// TODO: CMD_BYTE_62

// TODO: CMD_BYTE_63

// TODO: CMD_BYTE_64

// TODO: CMD_BYTE_65

// TODO: CMD_BYTE_66

// TODO: CMD_BYTE_67

// TODO: CMD_BYTE_68

// TODO: CMD_BYTE_69

#define WALK_RELATIVE(spd,h,v)          { CMD_BYTE_6A, 0, spd, h, v, NULL }

#define WALK_GRID(spd,w)                { CMD_BYTE_6B, 0, spd, w, 0, NULL }

// TODO: CMD_BYTE_6C

// TODO: CMD_BYTE_6D

// TODO: CMD_BYTE_6E

// TODO: CMD_BYTE_6F

// TODO: CMD_BYTE_70

// TODO: CMD_BYTE_71

// TODO: CMD_BYTE_72

// TODO: CMD_BYTE_73

// TODO: CMD_BYTE_74

// TODO: CMD_BYTE_75

// TODO: CMD_BYTE_76

// TODO: CMD_BYTE_77

// TODO: CMD_BYTE_78

// TODO: CMD_BYTE_79

#define WALK_DIRECT(spd,w)              { CMD_BYTE_7A, 0, spd, w, 0, NULL }

// TODO: CMD_BYTE_7B

// TODO: CMD_BYTE_7C

// TODO: CMD_BYTE_7D

// TODO: CMD_BYTE_7E

// TODO: CMD_BYTE_7F

// TODO: CMD_BYTE_80

// TODO: CMD_BYTE_81

// TODO: CMD_BYTE_82

// TODO: CMD_BYTE_83

// TODO: CMD_BYTE_84

// TODO: CMD_BYTE_85

#define CAMERA_PAN(u1,u2)               { CMD_BYTE_86, 0, u1, u2, 0, NULL }

// TODO: CMD_BYTE_87

// TODO: CMD_BYTE_88

// TODO: CMD_BYTE_89

#define CMD_UNK_8A(a,b,t)               { CMD_BYTE_8A, a, b, t, 0, NULL }

#define CMD_UNK_8C(a,t,c)               { CMD_BYTE_8C, a, t, c, 0, NULL }

#define CMD_UNK_8D(a,t)                 { CMD_BYTE_8D, a, t, 0, 0, NULL }

#define CMD_UNK_8E(a,t,c)               { CMD_BYTE_8E, a, t, c, 0, NULL }

#define CMD_UNK_8F(a,t,c)               { CMD_BYTE_8F, a, t, c, 0, NULL }

#define CMD_UNK_90(a,t,c)               { CMD_BYTE_90, a, t, c, 0, NULL }

// o: Final orientation
#define ROTATE_TO(spd,t,o)              { CMD_BYTE_91, spd, t, o, 0, NULL }

#define CMD_UNK_92(a,b,t)               { CMD_BYTE_92, a, b, t, 0, NULL }

#define CMD_UNK_93(a,t,c)               { CMD_BYTE_93, a, t, c, 0, NULL }

#define CMD_UNK_94(a,t,c)               { CMD_BYTE_94, a, t, c, 0, NULL }

#define CMD_UNK_95(a,t,c)               { CMD_BYTE_95, a, t, c, 0, NULL }

// TODO: CMD_BYTE_96

// TODO: CMD_BYTE_97

#define CAMERA_INIT_PAN                 { CMD_BYTE_98, 0, 0, 0, 0, NULL }

#define CAMERA_END_PAN                  { CMD_BYTE_99, 0, 0, 0, 0, NULL }

// TODO: CMD_BYTE_9A

// TODO: CMD_BYTE_9B

// TODO: CMD_BYTE_9C

// TODO: CMD_BYTE_9D

// TODO: CMD_BYTE_9E

// TODO: CMD_BYTE_9F

// TODO: CMD_BYTE_A0

// TODO: CMD_BYTE_A1

// TODO: CMD_BYTE_A2

// TODO: CMD_BYTE_A3

#define RESET_ARRAY(v)                  { CMD_BYTE_A4, 0, v, 0, 0, NULL }

#define CLEAR_ARRAY(v)                  { CMD_BYTE_A5, 0, v, 0, 0, NULL }

#define UPDATE_VARINT(o,v,i)            { CMD_BYTE_A6, o, v, i, 0, NULL }

#define UPDATE_VARVAR(o,a,b)            { CMD_BYTE_A7, o, a, b, 0, NULL }

#define SET_ARRAYVAL(v,i,x)             { CMD_BYTE_A8, 0, v, i, x, NULL }

#define SCENARIO_CALC(v,a,b)            { CMD_BYTE_A9, 0, v, a, b, NULL }

#define SCENARIO_ADVANCE(v,a)           { CMD_BYTE_AA, 0, v, a, 0, NULL }

// r is the value to put in DUNGEON_RESULT.
// e is the value to put in DUNGEON_ENTER.
#define SET_DUNGEON_RES(r,e)            { CMD_BYTE_AB, 0, r, e, 0, NULL }

#define SET_PLAYER_KIND(k)              { CMD_BYTE_AC, 0, k, 0, 0, NULL }

#define UNLOCK_FRIEND_AREA(a)           { CMD_BYTE_AD, TRUE, a, 0, 0, NULL }

#define CMD_UNK_AE(r)                   { CMD_BYTE_AE, TRUE, r, 0, 0, NULL }

#define CMD_UNK_AF(r, b)                { CMD_BYTE_AF, b, r, 0, 0, NULL }

#define SET_RESCUE_CONQUERED(s)         { CMD_BYTE_B0, TRUE, s, 0, 0, NULL }

// TODO: CMD_BYTE_B1

// TODO: CMD_BYTE_B2

#define JUMPIF_EQUAL(v,i,l)             { CMD_BYTE_B3, l, v, i, 0, NULL }

#define JUMPIF(o,v,i,l)                 { CMD_BYTE_B4, o, l, v, i, NULL }

#define JUMPIF_2(o,a,b,l)               { CMD_BYTE_B5, o, l, a, b, NULL }

#define JUMPIF_ARRAY(v,i,l)             { CMD_BYTE_B6, 0, l, v, i, NULL }

#define JUMPIF_SUM(o,v,i,l)             { CMD_BYTE_B7, o, l, v, i, NULL }

#define JUMPIF_SCENE_LT(v,a,b,l)        { CMD_BYTE_B8, l, v, a, b, NULL }

#define JUMPIF_SCENE_EQ(v,a,b,l)        { CMD_BYTE_B9, l, v, a, b, NULL }

#define JUMPIF_SCENE_GT(v,a,b,l)        { CMD_BYTE_BA, l, v, a, b, NULL }

// Jumps to a label if `CheckQuest(i)` returns TRUE.
// i: The quest to check. See enum "MainQuest".
// l: The label to jump to.
#define JUMPIF_SCENARIOCHECK(i,l)       { CMD_BYTE_BB, l, i, 0, 0, NULL }

#define JUMPIF_CUTSCENE_FLAG(f,l)       { CMD_BYTE_BC, l, f, 0, 0, NULL }

#define JUMPIF_UNK_BD(i,l)              { CMD_BYTE_BD, l, 0, i, 0, NULL }

#define JUMPIF_UNK_BE(l)                { CMD_BYTE_BE, l, 0, 0, 0, NULL }

#define JUMPIF_HASITEM(i,l)             { CMD_BYTE_BF, l, i, 0, 0, NULL }

#define CJUMP_VAR(v)                    { CMD_BYTE_C0, 0, v, 0, 0, NULL }

#define CJUMP_CALC_VI(o,v,i)            { CMD_BYTE_C1, o, v, i, 0, NULL }

#define CJUMP_CALC_VV(o,a,b)            { CMD_BYTE_C2, o, a, b, 0, NULL }

#define CJUMP_RANDOM(h)                 { CMD_BYTE_C3, 0, h, 0, 0, NULL }

#define CJUMP_SCENARIO_0(v)             { CMD_BYTE_C4, 0, v, 0, 0, NULL }

#define CJUMP_SCENARIO_1(v)             { CMD_BYTE_C5, 0, v, 0, 0, NULL }

#define CJUMP_UNK_C6(a)                 { CMD_BYTE_C6, 0, 0, a, 0, NULL }

#define CJUMP_DIRECTION                 { CMD_BYTE_C7, 0, 0, 0, 0, NULL }

// C8: distance calculation with that weird 80A7AE8
#define CJUMP_UNK_C8(a)                 { CMD_BYTE_C8, 0, 0, a, 0, NULL }

// C9: ditto, but with one hardcoded pos of four
#define CJUMP_UNK_C9(a)                 { CMD_BYTE_C9, 0, 0, a, 0, NULL }

#define CJUMP_DIR_TO_LINK(l)            { CMD_BYTE_CA, 0, 0, l, 0, NULL }

#define CJUMP_UNK_CB(h)                 { CMD_BYTE_CB, 0, h, 0, 0, NULL }

#define COND_EQUAL(v,t)                 { CMD_BYTE_CC, 0, t, v, 0, NULL }

#define COND(o,v,t)                     { CMD_BYTE_CD, o, t, v, 0, NULL }

#define COND_VAR(o,v,t)                 { CMD_BYTE_CE, o, t, v, 0, NULL }

#define MSG_VAR(b,v,a)                  { CMD_BYTE_CF, b, v, a, 0, NULL }

#define VARIANT(c,s)                    { CMD_BYTE_D0, 0, c, 0, 0, s    }

#define VARIANT_DEFAULT(s)              { CMD_BYTE_D1, 0, 0, 0, 0, s    }

#define ASK_DEBUG(b,h,a,s)              { CMD_BYTE_D2, b, h, a, 0, s    }

#define ASK1(b,h,a,s)                   { CMD_BYTE_D3, b, h, a, 0, s    }

#define ASK2(b,h,a,s)                   { CMD_BYTE_D4, b, h, a, 0, s    }

#define ASK3(b,h,a,s)                   { CMD_BYTE_D5, b, h, a, 0, s    }

#define ASK1_VAR(b,h,a,v)               { CMD_BYTE_D6, b, h, a, v, NULL }

#define ASK2_VAR(b,h,a,v)               { CMD_BYTE_D7, b, h, a, v, NULL }

#define ASK3_VAR(b,h,a,v)               { CMD_BYTE_D8, b, h, a, v, NULL }

#define CHOICE(h,s)                     { CMD_BYTE_D9, 0, h, 0, 0, s    }

// TODO: CMD_BYTE_DA

#define WAIT(f)                         { CMD_BYTE_DB, 0, f, 0, 0, NULL }

#define WAIT_RANDOM(a,b)                { CMD_BYTE_DC, 0, a, b, 0, NULL }

#define STOP_ANIMATION_ON_CURRENT_FRAME { CMD_BYTE_DD, 0, 0, 0, 0, NULL }

// TODO: CMD_BYTE_DE

// TODO: CMD_BYTE_DF

// TODO: CMD_BYTE_E0

#define WAIT_FANFARE1(id)               { CMD_BYTE_E1, 0, id, 0, 0, NULL }

#define WAIT_FANFARE2(id)               { CMD_BYTE_E2, 0, id, 0, 0, NULL }

#define AWAIT_CUE(id)                   { CMD_BYTE_E3, 0, id, 0, 0, NULL }

#define ALERT_CUE(id)                   { CMD_BYTE_E4, 0, id, 0, 0, NULL }

// a: Value to place in script's `branchDiscriminant`.
// b: Value to place in `gUnlockBranchLabels[a]`.
#define CMD_UNK_E5(a, b)                { CMD_BYTE_E5, b, a, 0, 0, NULL }

#define CALL_LABEL(x)                   { CMD_BYTE_E6, 0, x, 0, 0, NULL }

#define JUMP_LABEL(x)                   { CMD_BYTE_E7, 0, x, 0, 0, NULL }

#define CALL_SCRIPT(x)                  { CMD_BYTE_E8, 0, x, 0, 0, NULL }

#define JUMP_SCRIPT(x)                  { CMD_BYTE_E9, 0, x, 0, 0, NULL }

#define CALL_STATION(g,s)               { CMD_BYTE_EA, s, g,-1, 0, NULL }

#define JUMP_STATION(g,s)               { CMD_BYTE_EB, s, g,-1, 0, NULL }

#define EXECUTE_MAP_VAR(v)              { CMD_BYTE_EC, 0, v, 0, 0, NULL }

#define RESET_CALLER                    { CMD_BYTE_ED, 0, 0, 0, 0, NULL }

#define RET_DIRECT                      { CMD_BYTE_EE, 0, 0, 0, 0, NULL }

#define RET                             { CMD_BYTE_EF, 0, 0, 0, 0, NULL }

#define HALT                            { CMD_BYTE_F0, 0, 0, 0, 0, NULL }

#define END_DELETE                      { CMD_BYTE_F1, 0, 0, 0, 0, NULL }

// Unused
#define CMD_F2                          { CMD_BYTE_F2, 0, 0, 0, 0, NULL }

// Unused
#define CMD_F3                          { CMD_BYTE_F3, 0, 0, 0, 0, NULL }

// Serves as an offset which the script can reference for jumps.
#define LABEL(x)                        { CMD_BYTE_F4, 0, x, 0, 0, NULL }

// Unused
#define CMD_F5                          { CMD_BYTE_F5, 0, 0, 0, 0, NULL }

#ifdef NONMATCHING
#define DEBUGINFO                       { CMD_BYTE_F6, 0, __LINE__, 0, 0, __FILE__ }
#define DEBUGINFO_O(originalLineNum)    DEBUGINFO
#else
#define DEBUGINFO_O(originalLineNum)    { CMD_BYTE_F6, 0, originalLineNum, 0, 0, FAKE_FILENAME }
#endif

//#endif // GUARD_DATA_SCRIPT_H

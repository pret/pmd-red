#include "ground_script.h"
#include "event_flag.h"
#include "constants/item.h"
#define LPARRAY(x) (sizeof(x)/sizeof(*(x))), x

#define CPOS_HALFTILE 0x2
#define CPOS_CURRENT  0x4

// 01..07: complex map/dungeon selection/check commands
#define SELECT_MAP(m)           { 0x08, 0, 0, m, 0, NULL }
#define SELECT_GROUND(m)        { 0x09, 0, 0, m, 0, NULL }
#define SELECT_DUNGEON(m,d,f,b) { 0x0A, b, f, d, m, NULL }
#define SELECT_WEATHER(w)       { 0x0B, 0, 0, w, 0, NULL }
#define SELECT_ENTITIES(g,s)    { 0x0C, s, g, 0, 0, NULL }
#define SELECT_LIVES(g,s)       { 0x0D, s, g, 0, 0, NULL }
#define SELECT_OBJECTS(g,s)     { 0x0E, s, g, 0, 0, NULL }
#define SELECT_EFFECTS(g,s)     { 0x0F, s, g, 0, 0, NULL }
#define SELECT_EVENTS(g,s)      { 0x10, s, g, 0, 0, NULL }
#define CANCEL_ENTITIES(g,s)    { 0x11, s, g, 0, 0, NULL }
#define CANCEL_LIVES(g,s)       { 0x12, s, g, 0, 0, NULL }
#define CANCEL_OBJECTS(g,s)     { 0x13, s, g, 0, 0, NULL }
#define CANCEL_EFFECTS(g,s)     { 0x14, s, g, 0, 0, NULL }
#define CANCEL_EVENTS(g,s)      { 0x15, s, g, 0, 0, NULL }
#define CANCEL_OFFSCREEN_LIVES  { 0x16, 0, 0, 0, 0, NULL }
#define CANCEL_OFFSCREEN_OBJECTS {0x17, 0, 0, 0, 0, NULL }
#define CANCEL_OFFSCREEN_EFFECTS {0x18, 0, 0, 0, 0, NULL }
#define SPAWN_OBJECT(k,d,g,s)   { 0x19, s, g, d, k, NULL }
#define SPAWN_EFFECT(k,d,g,s)   { 0x1A, s, g, d, k, NULL }
#define EXECUTE_FUNCTION(f)     { 0x1B, 0, f, 0, 0, NULL }
#define EXECUTE_SUBROUTINE(f)   { 0x1C, 0, f, 0, 0, NULL }
#define EXECUTE_STATION(m,g,s)  { 0x1D, s, g, m, 0, NULL }
#define EXECUTE_SUBSTATION(m,g,s){0x1E, s, g, m, 0, NULL }
#define RESCUE_SELECT           { 0x1F, 0, 0, 0, 0, NULL }
// 20: execute script as parented object, maybe? Unused in ROM
// 21: follow object/make object follow/get parented?
// 22..2f: ???
// 30..39: various text printing
// 3a: yes/no choice (only used for saving)
// 3b: uber command (conditional jump)
// 3c: unknown textbox-related cjump
// 3d..3f: input boxes?
// 40: unused?
#define REMOVE_ITEMSTACK(i)     { 0x41, 0, i, 0, 0, NULL }
#define MUSIC_STOP_ALL          { 0x42, 0, 0, 0, 0, NULL }
#define MUSIC_FADEOUT_ALL(f)    { 0x43, 0, f, 0, 0, NULL }
#define BGM_SWITCH(i)           { 0x44, 0, 0, i, 0, NULL }
#define BGM_FADEIN(f,i)         { 0x45, 0, f, i, 0, NULL }
#define BGM_QUEUE(i)            { 0x46, 0, 0, i, 0, NULL }
#define BGM_STOP                { 0x47, 0, 0, 0, 0, NULL }
#define BGM_FADEOUT(f)          { 0x48, 0, f, 0, 0, NULL }
#define FANFARE_PLAY(i)         { 0x49, 0, 0, i, 0, NULL }
#define FANFARE_STOP(i)         { 0x4a, 0, 0, i, 0, NULL }
#define FANFARE_FADEOUT(f,i)    { 0x4b, 0, f, i, 0, NULL }
#define FANFARE_PLAY2(i)        { 0x4c, 0, 0, i, 0, NULL }
#define FANFARE_STOP2(i)        { 0x4d, 0, 0, i, 0, NULL }
#define FANFARE_FADEOUT2(f,i)   { 0x4e, 0, f, i, 0, NULL }
// 4f..57: more movement/position? Some sprite stuff?
// 58..95: position and movement-related
// 96: unused?
// 97..9a: ??? (maybe more camera?)
// 9b..a3: camera-related
#define RESET_ARRAY(v)          { 0xA4, 0, v, 0, 0, NULL }
#define CLEAR_ARRAY(v)          { 0xA5, 0, v, 0, 0, NULL }
#define UPDATE_VARINT(o,v,i)    { 0xA6, o, v, i, 0, NULL }
#define UPDATE_VARVAR(o,a,b)    { 0xA7, o, a, b, 0, NULL }
#define SET_ARRAYVAL(v,i,x)     { 0xA8, 0, v, i, x, NULL }
#define SCENARIO_CALC(v,a,b)    { 0xA9, 0, v, a, b, NULL }
#define SCENARIO_ADVANCE(v,a)   { 0xAA, 0, v, a, 0, NULL }
#define SET_DUNGEON_RES(r,e)    { 0xAB, 0, r, e, 0, NULL }
#define SET_PLAYER_KIND(k)      { 0xAC, 0, k, 0, 0, NULL }
// ad..b2: opaque functions
#define JUMPIF_EQUAL(v,i,l)     { 0xB3, l, v, i, 0, NULL }
#define JUMPIF(o,v,i,l)         { 0xB4, o, l, v, i, NULL }
#define JUMPIF_2(o,a,b,l)       { 0xB5, o, l, a, b, NULL }
#define JUMPIF_ARRAY(v,i,l)     { 0xB6, 0, l, v, i, NULL }
#define JUMPIF_SUM(o,v,i,l)     { 0xB7, o, l, v, i, NULL }
#define JUMPIF_SCENE_LT(v,a,b,l){ 0xB8, l, v, a, b, NULL }
#define JUMPIF_SCENE_EQ(v,a,b,l){ 0xB9, l, v, a, b, NULL }
#define JUMPIF_SCENE_GT(v,a,b,l){ 0xBA, l, v, a, b, NULL }
#define JUMPIF_SCENARIOCHECK(i,l){0xBB, l, i, 0, 0, NULL }
// functions need reversing
#define JUMPIF_UNK_BC(i,l)      { 0xBC, l, i, 0, 0, NULL }
#define JUMPIF_UNK_BD(i,l)      { 0xBD, l, 0, i, 0, NULL }
#define JUMPIF_UNK_BE(l)        { 0xBE, l, 0, 0, 0, NULL }
#define JUMPIF_HASITEM(i,l)     { 0xBF, l, i, 0, 0, NULL }
#define CJUMP_VAR(v)            { 0xC0, 0, v, 0, 0, NULL }
#define CJUMP_CALC_VI(o,v,i)    { 0xC1, o, v, i, 0, NULL }
#define CJUMP_CALC_VV(o,a,b)    { 0xC2, o, a, b, 0, NULL }
#define CJUMP_RANDOM(h)         { 0xC3, 0, h, 0, 0, NULL }
#define CJUMP_SCENARIO_0(v)     { 0xC4, 0, v, 0, 0, NULL }
#define CJUMP_SCENARIO_1(v)     { 0xC5, 0, v, 0, 0, NULL }
// wtf is c6
#define CJUMP_UNK_C6(a)         { 0xC6, 0, 0, a, 0, NULL }
#define CJUMP_DIRECTION         { 0xC7, 0, 0, 0, 0, NULL }
// C8: distance calculation with that weird 80A7AE8
#define CJUMP_UNK_C8(a)         { 0xC8, 0, 0, a, 0, NULL }
// C9: ditto, but with one hardcoded pos of four
#define CJUMP_UNK_C9(a)         { 0xC9, 0, 0, a, 0, NULL }
#define CJUMP_DIR_TO_LINK(l)    { 0xCA, 0, 0, l, 0, NULL }
// wtf is cb
#define CJUMP_UNK_CB(h)         { 0xCB, 0, h, 0, 0, NULL }
#define COND_EQUAL(v,t)         { 0xCC, 0, t, v, 0, NULL }
#define COND(o,v,t)             { 0xCD, o, t, v, 0, NULL }
#define COND_VAR(o,v,t)         { 0xCE, o, t, v, 0, NULL }
#define MSG_VAR(b,v,a)          { 0xCF, b, v, a, 0, NULL }
#define VARIANT(c,s)            { 0xD0, 0, c, 0, 0, s    }
#define VARIANT_DEFAULT(s)      { 0xD1, 0, 0, 0, 0, s    }
#define ASK_DEBUG(b,h,a,s)      { 0xD2, b, h, a, 0, s    }
#define ASK1(b,h,a,s)           { 0xD3, b, h, a, 0, s    }
#define ASK2(b,h,a,s)           { 0xD4, b, h, a, 0, s    }
#define ASK3(b,h,a,s)           { 0xD5, b, h, a, 0, s    }
#define ASK1_VAR(b,h,a,v)       { 0xD6, b, h, a, v, NULL }
#define ASK2_VAR(b,h,a,v)       { 0xD7, b, h, a, v, NULL }
#define ASK3_VAR(b,h,a,v)       { 0xD8, b, h, a, v, NULL }
#define CHOICE(h,s)             { 0xD9, 0, h, 0, 0, s    }
#define WAIT(f)                 { 0xDB, 0, f, 0, 0, NULL }
#define WAIT_RANDOM(a,b)        { 0xDC, 0, a, b, 0, NULL }
// dd..e2 - various HandleAction commands
// e3..e5 - locking/condvar commands
#define CALL_LABEL(x)           { 0xE6, 0, x, 0, 0, NULL }
#define JUMP_LABEL(x)           { 0xE7, 0, x, 0, 0, NULL }
#define CALL_SCRIPT(x)          { 0xE8, 0, x, 0, 0, NULL }
#define JUMP_SCRIPT(x)          { 0xE9, 0, x, 0, 0, NULL }
#define CALL_STATION(g,s)       { 0xEA, s, g,-1, 0, NULL }
#define JUMP_STATION(g,s)       { 0xEB, s, g,-1, 0, NULL }
#define EXECUTE_MAP_VAR(v)      { 0xEC, 0, v, 0, 0, NULL }
#define RESET_CALLER            { 0xED, 0, 0, 0, 0, NULL }
#define RET_DIRECT              { 0xEE, 0, 0, 0, 0, NULL }
#define RET                     { 0xEF, 0, 0, 0, 0, NULL }
#define HALT                    { 0xF0, 0, 0, 0, 0, NULL }
#define END_DELETE              { 0xF1, 0, 0, 0, 0, NULL }
#define LABEL(x)                { 0xF4, 0, x, 0, 0, NULL }
#ifdef NONMATCHING
#define DEBUGINFO               { 0xF6, 0, __LINE__, 0, 0, __FILE__ }
#else
#define DEBUGINFO               { 0xF6, 0, __LINE__, 0, 0, FAKE_FILENAME }
#endif

// function/trigger/script names
#define END_TALK 0
#define WAIT_END_TALK_FUNC 1
#define WAIT_END_EVENT_FUNC 2
#define WAIT_START_FUNC 3
#define INCOMPLETE_TALK 4
#define NORMAL_WAIT_END_TALK 5
#define LIVES_REPLY_NORMAL 6
#define LIVES_REPLY 7
#define OBJECT_REPLY_NORMAL 8
#define EXAMINE_MISS 9
#define ENTER_WAIT_FUNC 10
#define UNIT_TALK 11
#define HABITAT_TALK 12
#define HABITAT_TALK_S01E02A 13
#define HABITAT_MOVE1 14
#define HABITAT_MOVE2 15
#define HABITAT_MOVE_PAUSE 16
#define HABITAT_MOVE_STAY_FIX 17
#define HABITAT_MOVE_STAY_TURN 18
#define LIVES_MOVE_NORMAL 19
#define LIVES_MOVE_CHANGE 20
#define OBJECT_MOVE_NORMAL 21
#define OBJECT_MOVE_CHANGE 22
#define EFFECT_MOVE_NORMAL 23
#define EFFECT_MOVE_CHANGE 24
#define MOVE_INIT 25
#define MOVE_PAUSE 26
#define MOVE_STAY 27
#define MOVE_SLEEP 28
#define MOVE_RANDOM 29
#define MOVE_BOY 30
#define MOVE_GIRL 31
#define WAKEUP_FUNC 32
#define LOOK_AROUND_FUNC 33
#define LOOK_AROUND_DOWN_FUNC 34
#define LOOK_AROUND_RIGHT_FUNC 35
#define LOOK_AROUND_LEFT_FUNC 36
#define JUMP_HAPPY_FUNC 37
#define JUMP_SURPRISE_FUNC 38
#define JUMP_ANGRY_FUNC 39
#define NOTICE_FUNC 40
#define QUESTION_FUNC 41
#define SWEAT_FUNC 42
#define SHOCK_FUNC 43
#define SPREE_START_FUNC 44
#define SPREE_END_FUNC 45
#define SMILE_START_FUNC 46
#define SMILE_END_FUNC 47
#define ANGRY_START_FUNC 48
#define ANGRY_END_FUNC 49
#define MOVE_PLAZA_SLEEP 50
#define INIT_PLAZA_SLEEP_STAY_FUNC 51
#define INIT_PLAZA_SLEEP_TALK_FUNC 52
#define INIT_SLEEP_FUNC 53
#define INIT_BASE_FUNC 54
#define INIT_DEBUG_HABITAT 55
#define NORMAL_MESSAGE 56
#define NORMAL_EVENT 57
#define NORMAL_CAMERA 58
#define DISMISSAL_SALLY_MEMBER_FUNC 59
#define DISMISSAL_SALLY_MEMBER2_FUNC 60
#define DISMISSAL_SALLY_MEMBER3_FUNC 61
#define DISMISSAL_SALLY_MEMBER4_FUNC 62
#define NEXT_SAVE_FUNC 63
#define NEXT_SAVE2_FUNC 64
#define SAVE_POINT 65
#define WAREHOUSE_POINT 66
#define SAVE_AND_WAREHOUSE_POINT 67
#define WORLD_MAP_POINT 68
#define FORMATION_HERO 69
#define EVOLUTION_HERO 70
#define WARP_LIVES_START 71
#define WARP_LIVES_START2 72
#define WARP_LIVES_START3 73
#define WARP_LIVES_ARRIVE 74
#define WARP_LIVES_ARRIVE2 75
#define WARP_LIVES_ARRIVE3 76
#define LIVES_WARP_START_FUNC 77
#define LIVES_WARP_START2_FUNC 78
#define LIVES_WARP_START3_FUNC 79
#define LIVES_WARP_START_SUB 80
#define LIVES_WARP_ARRIVE_FUNC 81
#define LIVES_WARP_ARRIVE2_FUNC 82
#define LIVES_WARP_ARRIVE3_FUNC 83
#define LIVES_WARP_ARRIVE_SUB 84
#define GET_ITEM_FUNC 85
#define GET_ITEM_WAIT_FUNC 86
#define GET_ITEM2_FUNC 87
#define GET_ITEM2_WAIT_FUNC 88
#define JOIN_FUNC 89
#define LODGE_START_FUNC 90
#define LODGE_WAIT_FUNC 91
#define LODGE_END_FUNC 92
#define LODGE_SOUND_FUNC 93
#define SAVE_START_FUNC 94
#define SAVE_WAIT_FUNC 95
#define SAVE_END_FUNC 96
#define SAVE_SOUND_FUNC 97
#define EFFECT_TEST1 98
#define EFFECT_TEST2 99
#define EFFECT_MOVE_DIVE 100
#define EFFECT_MOVE_WAVE 101
#define EVENT_DIVIDE 102
#define EVENT_DIVIDE_NEXT 103
#define EVENT_DIVIDE_INIT_FUNC 104
#define EVENT_DIVIDE_NEXT_DAY_FUNC 105
#define EVENT_DIVIDE_NEXT_DAY2_FUNC 106
#define EVENT_DIVIDE_FIRST 107
#define EVENT_DIVIDE_SECOND 108
#define EVENT_DIVIDE_AFTER 109
#define EVENT_DIVIDE_WARP_LOCK_FUNC 110
#define EVENT_RESCUE_ENTER_CHECK 111
#define EVENT_RESCUE 112
#define DEBUG_SCRIPT 113
#define DEMO_CANCEL 114
#define DEMO_01 115
#define DEMO_02 116
#define DEMO_03 117
#define DEMO_04 118
#define EVENT_M00E01A_L001 119
#define EVENT_M01E01A_L001 120
#define EVENT_M01E01A_L002 121
#define EVENT_M01E01A_L003 122
#define EVENT_M01E02A_L001 123
#define EVENT_M01E02A_L001B 124
#define EVENT_M01E02A_L001C 125
#define EVENT_M01E02A_L002 126
#define EVENT_M01E02A_L003 127
#define EVENT_M01E02A_L004 128
#define EVENT_M01E02A_L005 129
#define EVENT_M01E02A_L006 130
#define EVENT_M01E02B_L001 131
#define EVENT_M01E02B_L002 132
#define EVENT_M01E02B_L003 133
#define EVENT_M01E02B_L004 134
#define EVENT_M01E02B_L004B 135
#define EVENT_M01E02B_L005 136
#define EVENT_M01E02B_L006 137
#define EVENT_M01E02B_L007 138
#define EVENT_M01E02B_L008 139
#define EVENT_M01E03A_L000 140
#define EVENT_M01E03A_L001 141
#define EVENT_M01E03A_L002 142
#define EVENT_M01E03A_L003 143
#define EVENT_M01E03A_L004 144
#define EVENT_M01E03A_L005 145
#define EVENT_M01E03A_L006 146
#define EVENT_M01E03A_L007 147
#define EVENT_M01E03A_L008 148
#define EVENT_M01E03A_L009 149
#define EVENT_M01E03A_L010 150
#define EVENT_M01E03A_L011 151
#define EVENT_M01E04A_L000 152
#define EVENT_M01E04A_L001 153
#define EVENT_M01E04A_L002 154
#define EVENT_M01E04A_L003 155
#define EVENT_M01E04A_L004 156
#define EVENT_M01E04A_L005 157
#define EVENT_M01E04A_L006 158
#define EVENT_M01E04B_L000 159
#define EVENT_M01E04B_L001 160
#define EVENT_M01E04B_L002 161
#define EVENT_M01E04B_L003 162
#define EVENT_M01E04B_L004 163
#define EVENT_M01E04B_L005 164
#define EVENT_M01E04B_L006 165
#define EVENT_M01E04B_L007 166
#define EVENT_M01E05A_L000 167
#define EVENT_M01E05A_L001 168
#define EVENT_M01E05A_L002 169
#define EVENT_M01E05A_L003 170
#define EVENT_M01E05A_L004 171
#define EVENT_M01E05A_L005 172
#define EVENT_M01E05A_L006 173
#define EVENT_M01E05B_L000 174
#define EVENT_M01E05B_L001 175
#define EVENT_M01E05B_L002 176
#define EVENT_M01E05B_L003 177
#define EVENT_M01E05B_L004 178
#define EVENT_M01E05B_L005 179
#define EVENT_M01E06A_L001 180
#define EVENT_M01E06A_L002 181
#define EVENT_M01E06A_L003 182
#define EVENT_M01E07A_L001 183
#define EVENT_M01E07A_L002 184
#define EVENT_M01E07A_L003 185
#define EVENT_M01E07A_L004 186
#define EVENT_M01E07A_L005 187
#define EVENT_M01E07A_T001 188
#define EVENT_M01E07A_T002 189
#define EVENT_M01E07B_L001 190
#define EVENT_M01E07B_L002 191
#define EVENT_M01E07B_L003 192
#define EVENT_M01E07B_L004 193
#define EVENT_M01E07B_L005 194
#define EVENT_M01E07B_T001 195
#define EVENT_M01E07B_T002 196
#define EVENT_M01E08A_L001 197
#define EVENT_M01E08A_L002 198
#define EVENT_M01E08A_L003 199
#define EVENT_M01E08A_L004 200
#define EVENT_M01E08A_L005 201
#define EVENT_M01E08A_T001 202
#define EVENT_M01E08A_T002 203
#define EVENT_M01E08B_L001 204
#define EVENT_M01E08B_L002 205
#define EVENT_M01E08B_L003 206
#define EVENT_M01E08B_L004 207
#define EVENT_M01E08B_L005 208
#define EVENT_M01E08B_L006 209
#define EVENT_M01E08B_T001 210
#define EVENT_M01E08B_T002 211
#define EVENT_M01E09A_L001 212
#define EVENT_M01E09A_L002 213
#define EVENT_M01E09A_L003 214
#define EVENT_M01E09A_L004 215
#define EVENT_M01E09A_L005 216
#define EVENT_M01E09A_L006 217
#define EVENT_M01E09A_L007 218
#define EVENT_M01E09A_L008 219
#define EVENT_M01E09A_L009 220
#define EVENT_M01E09A_L010 221
#define EVENT_M01E09A_L011 222
#define EVENT_M01E09A_L012 223
#define EVENT_M01E09A_L013 224
#define EVENT_M01E09A_L014 225
#define EVENT_M01E09A_L015 226
#define EVENT_M01E10A_L001 227
#define EVENT_M01E10A_L002 228
#define EVENT_M01E10A_L003 229
#define EVENT_M01E10A_L004 230
#define EVENT_M01E10A_L005 231
#define EVENT_M01E10A_L006 232
#define EVENT_M01E10A_L007 233
#define EVENT_M01E10A_L008 234
#define EVENT_M01END_L001 235
#define EVENT_M01END_L002 236
#define EVENT_M02E01A_L001 237
#define EVENT_M02E01A_L002 238
#define EVENT_M02E01A_L003 239
#define EVENT_M02E02A_L001 240
#define EVENT_M02E02B_L001 241
#define EVENT_M02E02C_L001 242
#define EVENT_M02E02D_L001 243
#define EVENT_M02E02E_L001 244
#define EVENT_M02E02F_L001 245
#define EVENT_M02E02G_L001 246
#define EVENT_M02E02H_L001 247
#define EVENT_M02END_L001 248
#define EVENT_S00E01A_L001 249
#define EVENT_S00E01A_L002 250
#define EVENT_S00E01A_L003 251
#define EVENT_S00E01A_L004 252
#define EVENT_S01E01A_START 253
#define EVENT_S01E01A_CONTINUE 254
#define EVENT_S01E01A_END 255
#define EVENT_S01E01A_L001 256
#define EVENT_S01E01A_L002 257
#define EVENT_S01E01A_L003 258
#define EVENT_S01E01B_L001 259
#define EVENT_S01E01B_L001L 260
#define EVENT_S01E01C_L001 261
#define EVENT_S01E02A_START 262
#define EVENT_S01E02A_END 263
#define EVENT_S01E02A_L001 264
#define EVENT_S01E02A_L002 265
#define EVENT_S01E02A_L002L 266
#define EVENT_S01E02B_L001 267
#define EVENT_S01E02B_L002 268
#define EVENT_S02E01A_START 269
#define EVENT_S02E01A_END 270
#define EVENT_S02E01A_L001 271
#define EVENT_S02E01A_L002 272
#define EVENT_S02E01A_L003 273
#define EVENT_S02E01A_L004 274
#define EVENT_S02E01A_L004L 275
#define EVENT_S02E02A_START 276
#define EVENT_S02E02A_END 277
#define EVENT_S02E02A_L001 278
#define EVENT_S02E02A_L002 279
#define EVENT_S02E02A_L003 280
#define EVENT_S02E02A_L003L 281
#define EVENT_S03E01A_START 282
#define EVENT_S03E01A_CONTINUE 283
#define EVENT_S03E01A_END 284
#define EVENT_S03E01A_L001 285
#define EVENT_S03E01A_L002 286
#define EVENT_S03E01A_L002L 287
#define EVENT_S04E01A_START 288
#define EVENT_S04E01A_LAST 289
#define EVENT_S04E01A_END 290
#define EVENT_S04E01A_L001 291
#define EVENT_S04E01A_L002 292
#define EVENT_S04E01A_L002L 293
#define EVENT_S04E01B_L001 294
#define EVENT_S04E01B_L001L 295
#define EVENT_S04E01C_L001 296
#define EVENT_S04E01C_L001L 297
#define EVENT_S04E01D_L001 298
#define EVENT_S04E01D_L001L 299
#define EVENT_S04E01E_L001 300
#define EVENT_S04E01E_L001L 301
#define EVENT_S04E01F_L001 302
#define EVENT_S05E01A_START 303
#define EVENT_S05E01A_CONTINUE 304
#define EVENT_S05E01A_END 305
#define EVENT_S05E01A_L001 306
#define EVENT_S05E01A_L002 307
#define EVENT_S05E01A_L002L 308
#define EVENT_S06E01A_START 309
#define EVENT_S06E01A_CONTINUE 310
#define EVENT_S06E01A_END 311
#define EVENT_S06E01A_L001 312
#define EVENT_S06E01A_L002 313
#define EVENT_S06E01A_L002L 314
#define EVENT_S06E01B_L001 315
#define EVENT_S06E01B_L002 316
#define EVENT_S06E01B_L002L 317
#define EVENT_S07E01A_START 318
#define EVENT_S07E01A_END 319
#define EVENT_S07E01A_L001 320
#define EVENT_S07E01A_L002 321
#define EVENT_S07E01A_L003 322
#define EVENT_S07E01A_L003L 323
#define EVENT_S08E01A_START 324
#define EVENT_S08E01A_END 325
#define EVENT_S08E01A_L001 326
#define EVENT_S08E01A_L002 327
#define EVENT_S08E01A_L003 328
#define EVENT_S08E01A_L004 329
#define EVENT_S08E01A_L005 330
#define EVENT_S08E01A_L005B 331
#define EVENT_S08E01A_L006 332
#define EVENT_S08E01A_L006L 333
#define EVENT_S08E01A_L007 334
#define EVENT_S08E01A_L008 335
#define EVENT_S08E01A_L008L 336
#define EVENT_S08E01A_L008A 337
#define EVENT_S08E01A_L008B 338
#define EVENT_S08E01A_L008C 339
#define EVENT_S09E01A_START 340
#define EVENT_S09E01A_END 341
#define EVENT_S09E01A_L001 342
#define EVENT_S09E01A_L002 343
#define EVENT_S09E01A_L003 344
#define EVENT_S09E01A_L004 345
#define EVENT_S09E01A_L004B 346
#define EVENT_S09E01A_L005 347
#define EVENT_S09E01A_L005L 348
#define EVENT_S09E01B_L001 349
#define EVENT_S09E01B_L001B 350
#define EVENT_S09E01B_L002 351
#define EVENT_S09E01B_L002L 352
#define EVENT_S09E01C_L001 353
#define EVENT_R00E01A_L001 354
#define COMMON_ENTER 355
#define DEBUG_ENTER 356
#define GETOUT_NORMAL 357
#define GETOUT_HABITAT 358
#define GETOUT_M01E01A 359
#define GETOUT_M01E02A 360
#define GETOUT_M01E02B 361
#define GETOUT_M01E03A 362
#define GETOUT_M01E04A 363
#define GETOUT_M01E04B 364
#define GETOUT_M01E05A 365
#define GETOUT_M01E07A 366
#define GETOUT_M01E07B 367
#define GETOUT_M01E08A 368
#define GETOUT_M01E08B 369
#define GETOUT_M01E09A 370
#define GETOUT_M01E10A 371
#define GETOUT_S00E01A 372
#define GETOUT_S01E01A 373
#define GETOUT_S01E02A 374
#define GETOUT_S02E01A 375
#define GETOUT_S02E02A 376
#define GETOUT_S03E01A 377
#define GETOUT_S04E01A 378
#define GETOUT_S04E01B 379
#define GETOUT_S04E01C 380
#define GETOUT_S04E01D 381
#define GETOUT_S04E01E 382
#define GETOUT_S05E01A 383
#define GETOUT_S06E01A 384
#define GETOUT_S06E01B 385
#define GETOUT_S07E01A 386
#define GETOUT_S08E01A 387
#define GETOUT_S09E01A 388
#define GETOUT_S09E01B 389
#define GETOUT_D62E01A 390
#define GETOUT_D43E01A 391
#define GETOUT_D44E01A 392
#define GETOUT_D45E01A 393
#define GETOUT_D46E01A 394
#define GETOUT_U00E01A 395
#define GETOUT_R00E01A 396
#define GETOUT_T00E01A 397
#define GETOUT_M01E07T 398
#define GETOUT_M01E08T 399
#define EVENT_CONTROL 400
#define EVENT_WAKEUP 401
#define EVENT_STATION 402
#define STATION_CONTROL 403
#define ENTER_CONTROL 404
#define SETUP_DEBUG_CAMERA 405
#define MOVE_DEBUG_CAMERA 406

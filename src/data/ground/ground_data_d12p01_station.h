











static const struct ScriptCommand s_gs204_g0_s0_station_sref_script[] = { /* 0x825ce34 */
    DEBUGINFO_O(14),
    SELECT_MAP(MAP_MAGMA_CAVERN_ENTRY),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 15, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMP_LABEL(1),
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(START_MODE, STARTMODE_CONTINUE_GAME, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, STARTMODE_3, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, STARTMODE_GROUND, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, STARTMODE_DUNGEON_WON, /* to label */ 4),
    JUMP_LABEL(2),
  LABEL(4), /* = 0x04 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 5),
    JUMP_LABEL(5),
  LABEL(2), /* = 0x02 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(6),
  LABEL(3), /* = 0x03 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(6),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(6),
  LABEL(6), /* = 0x06 */
    BGM_SWITCH(MUS_MAGMA_CAVERN),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const ScriptRef s_gs204_g0_s0_station_sref = { ENTER_CONTROL, SCRIPT_TYPE_01, NULL, s_gs204_g0_s0_station_sref_script }; /* 0x825d030 */

static const struct ScriptCommand s_gs204_g0_s1_lives0_dlg0[] = { /* 0x825d03c */
    DEBUGINFO_O(48),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs204_g0_s1_lives1_dlg0[] = { /* 0x825d07c */
    DEBUGINFO_O(55),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs204_g0_s3_lives0_dlg0[] = { /* 0x825d0bc */
    DEBUGINFO_O(62),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs204_g0_s3_lives1_dlg0[] = { /* 0x825d0fc */
    DEBUGINFO_O(69),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs204_g0_s4_lives0_dlg0[] = { /* 0x825d13c */
    DEBUGINFO_O(76),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs204_g0_s4_lives1_dlg0[] = { /* 0x825d16c */
    DEBUGINFO_O(82),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs204_g1_s0_station_sref_script[] = { /* 0x825d19c */
    DEBUGINFO_O(88),
    SELECT_MAP(MAP_MAGMA_CAVERN_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MAGMA_CAVERN),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_MAGMA_CAVERN),
    RET,
};

static const ScriptRef s_gs204_g1_s0_station_sref = { EVENT_CONTROL, SCRIPT_TYPE_07, NULL, s_gs204_g1_s0_station_sref_script }; /* 0x825d21c */

static const struct ScriptCommand s_gs204_g1_s0_lives0_dlg0[] = { /* 0x825d228 */
    DEBUGINFO_O(101),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000067,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    WALK_GRID(256, 0),
    WAIT(10),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So this is it...{WAIT_PRESS}\nThe underground cavern where\n{NAME_2} is...")),
    VARIANT(/* == */  1, _(" Look at the flowing\nstreams of lava...")),
    VARIANT(/* == */  1, _(" It wouldn't surprise me if\nthe dungeon is scorching hot...")),
    VARIANT_DEFAULT(_(" This must be it...{WAIT_PRESS}\n{NAME_2} is in this underground\ncavern.")),
    VARIANT_DEFAULT(_(" Whew...\nLook at the streams of lava.")),
    VARIANT_DEFAULT(_(" It's going to be scorching\nhot in the dungeon, I think.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    WAIT(5),
    CMD_UNK_93(4, DIR_TRANS_11, 34),
    WAIT(15),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Other rescue teams should\nalready be inside.")),
    VARIANT(/* == */  1, _(" Let's get in there and give\nit our best!")),
    VARIANT(/* == */  3, _(" Other rescue teams\nshould already be here.")),
    VARIANT(/* == */  3, _(" Let's get going and try our\nbest!")),
    VARIANT_DEFAULT(_(" There should be other\nrescue teams making their way through\neven now.")),
    VARIANT_DEFAULT(_(" Let's try our best like\nalways!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    WALK_GRID(256, 3),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs204_g1_s0_lives1_dlg0[] = { /* 0x825d6dc */
    DEBUGINFO_O(142),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 1),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_11, 0),
    AWAIT_CUE(6),
    WALK_GRID(256, 2),
    HALT,
};

static const struct ScriptCommand s_gs204_g2_s0_station_sref_script[] = { /* 0x825d78c */
    DEBUGINFO_O(156),
    SELECT_MAP(MAP_MAGMA_CAVERN_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_MAGMA_CAVERN),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(30, SCRIPT_DUNGEON_MAGMA_CAVERN),
    RET,
};

static const ScriptRef s_gs204_g2_s0_station_sref = { EVENT_CONTROL, SCRIPT_TYPE_07, NULL, s_gs204_g2_s0_station_sref_script }; /* 0x825d80c */

static const struct ScriptCommand s_gs204_g2_s0_lives0_dlg0[] = { /* 0x825d818 */
    DEBUGINFO_O(169),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000058,  0x00000000, NULL },
    ALERT_CUE(6),
    WALK_GRID(256, 0),
    CMD_UNK_93(4, DIR_TRANS_11, 34),
    WAIT(15),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This time, we'll rescue\n{NAME_2}'s team!\nLet's get it done!")),
    VARIANT_DEFAULT(_(" This time, we have to\nrescue {NAME_2}'s team!\nLet's not blow it!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    WALK_GRID(256, 3),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs204_g2_s0_lives1_dlg0[] = { /* 0x825d9bc */
    DEBUGINFO_O(191),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_GRID(256, 1),
    CMD_UNK_93(4, DIR_TRANS_11, 0),
    AWAIT_CUE(6),
    WALK_GRID(256, 2),
    HALT,
};

static const struct GroundLivesData s_gs204_g0_s1_lives[] = { /* 0x825da4c */
    /*  0 */ {   0,   4,   0,   0, {  26,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  26,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs204_g0_s3_lives[] = { /* 0x825da7c */
    /*  0 */ {   0,   4,   0,   0, {  26,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  26,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs204_g0_s4_lives[] = { /* 0x825daac */
    /*  0 */ {   0,   4,   0,   0, {  26,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  26,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs204_g1_s0_lives[] = { /* 0x825dadc */
    /*  0 */ {   0,   2,   0,   0, {  28,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  23,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs204_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs204_g2_s0_lives[] = { /* 0x825db0c */
    /*  0 */ {   0,   2,   0,   0, {  28,  35, 0, CPOS_HALFTILE }, {
        [0] = s_gs204_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  23,  34, 0, CPOS_HALFTILE }, {
        [0] = s_gs204_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs204_g1_s0_effs[] = { /* 0x825db3c */
    /*  0 */ {   0,   0,   1,   1, {  26,  17, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs204_g2_s0_effs[] = { /* 0x825db48 */
    /*  0 */ {   0,   0,   1,   1, {  26,  17, 0, CPOS_HALFTILE }, NULL },
};

static const ScriptRef * const (sStationScripts[]) = { /* 0x825db54 */
    &s_gs204_g0_s0_station_sref,
    &s_gs204_g1_s0_station_sref,
    &s_gs204_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs204_g0_sectors[] = { /* 0x825db60 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
    { LPARRAY(s_gs204_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs204_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs204_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs204_g1_sectors[] = { /* 0x825dc28 */
    { LPARRAY(s_gs204_g1_s0_lives), 0,NULL, LPARRAY(s_gs204_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs204_g2_sectors[] = { /* 0x825dc50 */
    { LPARRAY(s_gs204_g2_s0_lives), 0,NULL, LPARRAY(s_gs204_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs204_groups[] = { /* 0x825dc78 */
    { LPARRAY(s_gs204_g0_sectors) },
    { LPARRAY(s_gs204_g1_sectors) },
    { LPARRAY(s_gs204_g2_sectors) },
    {},
};

static const struct GroundLink s_gs204_links[] = { /* 0x825dc98 */
    /* link   0 */ { { /*x*/  28, /*y*/  19, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  23, /*y*/  19, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  26, /*y*/  10, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  26, /*y*/  11, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

const GroundScriptHeader gGroundScript_gs204 = { LPARRAY(s_gs204_groups), s_gs204_links }; /* 0x825dcb8 */

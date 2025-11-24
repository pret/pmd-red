












static const struct ScriptCommand s_gs191_g0_s0_station_sref_script[] = { /* 0x823d7dc */
    DEBUGINFO_O(15),
    SELECT_MAP(MAP_GREAT_CANYON_ENTRY),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs191_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs191_g0_s0_station_sref_script }; /* 0x823d848 */

static const struct ScriptCommand s_gs191_g1_s0_station_sref_script[] = { /* 0x823d854 */
    DEBUGINFO_O(24),
    SELECT_MAP(MAP_GREAT_CANYON_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_GREAT_CANYON),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(0, SCRIPT_DUNGEON_GREAT_CANYON),
    RET,
};

static const struct ScriptRef s_gs191_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs191_g1_s0_station_sref_script }; /* 0x823d8d4 */

static const struct ScriptCommand s_gs191_g1_s0_lives0_dlg0[] = { /* 0x823d8e0 */
    DEBUGINFO_O(37),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000061,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WALK_GRID(256, 1),
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_NPC(1, _(" This is the {COLOR YELLOW_D}Great Canyon{RESET}...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" The peak is called the\n{COLOR CYAN}Hill of the Ancients{RESET}.")),
    ALERT_CUE(6),
    WAIT(10),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_NORTHEAST),
    { 0x2d, 0x0a,  0x0000,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_2} said that\nthe {COLOR CYAN}Hill of the Ancients{RESET} is on {VALUE_0}F.")),
    VARIANT(/* == */  1, _(" That's where we'll find\n{NAME_3}.{WAIT_PRESS}\n{NAME_0}, let's give it our best!")),
    VARIANT_DEFAULT(_(" According to {NAME_2},\nthe {COLOR CYAN}Hill of the Ancients{RESET} is on {VALUE_0}F.")),
    VARIANT_DEFAULT(_(" {NAME_3} should be\nthere.{WAIT_PRESS}\n{NAME_0}, let's do our best!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    WALK_GRID(128, 2),
    HALT,
};


static const struct ScriptCommand s_gs191_g1_s0_lives1_dlg0[] = { /* 0x823dc10 */
    DEBUGINFO_O(71),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WALK_GRID(256, 0),
    WAIT(20),
    AWAIT_CUE(6),
    { 0x69, 0x00,  0x0100,  0x000000e8,  0x00000068, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    WAIT(20),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_SOUTHWEST),
    AWAIT_CUE(6),
    WALK_GRID(128, 3),
    HALT,
};

static const struct ScriptCommand s_gs191_g2_s0_station_sref_script[] = { /* 0x823dd20 */
    DEBUGINFO_O(91),
    SELECT_MAP(MAP_GREAT_CANYON_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_GREAT_CANYON),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(0, SCRIPT_DUNGEON_GREAT_CANYON),
    RET,
};

static const struct ScriptRef s_gs191_g2_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs191_g2_s0_station_sref_script }; /* 0x823dda0 */

static const struct ScriptCommand s_gs191_g2_s0_lives0_dlg0[] = { /* 0x823ddac */
    DEBUGINFO_O(104),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000058,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000061,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WALK_GRID(256, 1),
    WAIT(30),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_EAST),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}!\nThis time we'll make it to the peak,\nall right?")),
    VARIANT(/* == */  1, _(" We'll meet {NAME_3}\nand ask about you, {NAME_0}.")),
    VARIANT(/* == */  1, _(" Let's give it our best!")),
    VARIANT_DEFAULT(_(" {NAME_0}!\nLet's make it to the peak this time!")),
    VARIANT_DEFAULT(_(" We have to meet\n{NAME_3} and get some information\non you, {NAME_0}.")),
    VARIANT_DEFAULT(_(" Let's do our best!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    { 0x23, 0x00,  0x0028,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    WALK_GRID(128, 2),
    HALT,
};

static const struct ScriptCommand s_gs191_g2_s0_lives1_dlg0[] = { /* 0x823e038 */
    DEBUGINFO_O(131),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WALK_GRID(256, 0),
    WAIT(30),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_WEST),
    AWAIT_CUE(6),
    WALK_GRID(204, 4),
    WALK_GRID(204, 3),
    HALT,
};

static const struct GroundLivesData s_gs191_g1_s0_lives[] = { /* 0x823e0f8 */
    /*  0 */ {   0,   4,   0,   0, {  26,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs191_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs191_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs191_g2_s0_lives[] = { /* 0x823e128 */
    /*  0 */ {   0,   4,   0,   0, {  26,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs191_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs191_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs191_g1_s0_effs[] = { /* 0x823e158 */
    /*  0 */ {   0,   0,   1,   1, {  30,  15, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs191_g2_s0_effs[] = { /* 0x823e164 */
    /*  0 */ {   0,   0,   1,   1, {  30,  15, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x823e170 */
    &s_gs191_g0_s0_station_sref,
    &s_gs191_g1_s0_station_sref,
    &s_gs191_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs191_g0_sectors[] = { /* 0x823e17c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs191_g1_sectors[] = { /* 0x823e1a4 */
    { LPARRAY(s_gs191_g1_s0_lives), 0,NULL, LPARRAY(s_gs191_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs191_g2_sectors[] = { /* 0x823e1cc */
    { LPARRAY(s_gs191_g2_s0_lives), 0,NULL, LPARRAY(s_gs191_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs191_groups[] = { /* 0x823e1f4 */
    { LPARRAY(s_gs191_g0_sectors) },
    { LPARRAY(s_gs191_g1_sectors) },
    { LPARRAY(s_gs191_g2_sectors) },
};

static const struct GroundLink s_gs191_links[] = { /* 0x823e20c */
    /* link   0 */ { { /*x*/  31, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  26, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  29, /*y*/   6, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  30, /*y*/   7, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/  30, /*y*/  11, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

const GroundScriptHeader gGroundScript_gs191 = { LPARRAY(s_gs191_groups), s_gs191_links }; /* 0x823e234 */

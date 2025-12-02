











static const struct ScriptCommand s_gs180_g0_s0_station_sref_script[] = { /* 0x82302f8 */
    DEBUGINFO_O(14),
    SELECT_MAP(MAP_THUNDERWAVE_CAVE_ENTRY),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs180_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs180_g0_s0_station_sref_script }; /* 0x8230364 */

static const struct ScriptCommand s_gs180_g1_s0_station_sref_script[] = { /* 0x8230370 */
    DEBUGINFO_O(23),
    SELECT_MAP(MAP_THUNDERWAVE_CAVE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_THUNDERWAVE_CAVE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(0, SCRIPT_DUNGEON_THUNDERWAVE_CAVE),
    RET,
};

static const struct ScriptRef s_gs180_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs180_g1_s0_station_sref_script }; /* 0x82303f0 */

static const struct ScriptCommand s_gs180_g1_s0_eff0_script[] = { /* 0x82303fc */
    DEBUGINFO_O(36),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    WAIT(30),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs180_g1_s0_lives0_dlg0[] = { /* 0x823047c */
    DEBUGINFO_O(47),
    SELECT_ANIMATION(2),
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x2d, 0x0a,  0x0000,  0x00000001,  0x00000000, NULL },
    PORTRAIT(PLACEMENT_MIDLEFT_TOP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" OH, YOU ARE HERE.\nBZBZBZZ!")),
    MSG_NPC(2, _(" MY FRIENDS ARE IN THIS\nCAVERN. BZBZBZZ.")),
    MSG_NPC(2, _(" MY FRIENDS SHOULD BE\nON B{VALUE_0}F. PLEASE HELP THEM!\nBZBZBZZZT!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 34),
    WAIT(30),
    { 0x54, 0x00,  0x002f,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    WAIT(15),
    ROTATE_TO(8, DIR_TRANS_10, DIRECTION_NORTH),
    WAIT(15),
    ALERT_CUE(7),
    ALERT_CUE(8),
    WAIT(30),
    ALERT_CUE(4),
    ALERT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(153, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs180_g1_s0_lives1_dlg0[] = { /* 0x8230758 */
    DEBUGINFO_O(88),
    SELECT_ANIMATION(2),
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    WAIT(30),
    { 0x54, 0x00,  0x002f,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(2),
    WAIT(15),
    ROTATE_TO(8, DIR_TRANS_10, DIRECTION_NORTH),
    WAIT(15),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(15),
    WALK_GRID(153, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs180_g1_s0_lives2_dlg0[] = { /* 0x82308a8 */
    DEBUGINFO_O(112),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x62, 0x00,  0x0080, -0x00000010,  0x00000000, NULL },
    CMD_UNK_93(4, DIR_TRANS_10, 65),
    HALT,
};

static const struct ScriptCommand s_gs180_g1_s0_lives3_dlg0[] = { /* 0x8230948 */
    DEBUGINFO_O(125),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_SOUTH),
    AWAIT_CUE(8),
    { 0x62, 0x00,  0x0080,  0x00000010,  0x00000000, NULL },
    CMD_UNK_93(4, DIR_TRANS_10, 64),
    HALT,
};

static const struct ScriptCommand s_gs180_g2_s0_station_sref_script[] = { /* 0x82309d8 */
    DEBUGINFO_O(137),
    SELECT_MAP(MAP_THUNDERWAVE_CAVE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_THUNDERWAVE_CAVE),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    NEXT_DUNGEON(0, SCRIPT_DUNGEON_THUNDERWAVE_CAVE),
    RET,
};

static const struct ScriptRef s_gs180_g2_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs180_g2_s0_station_sref_script }; /* 0x8230a58 */

static const struct ScriptCommand s_gs180_g2_s0_eff0_script[] = { /* 0x8230a64 */
    DEBUGINFO_O(150),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    WAIT(30),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs180_g2_s0_lives0_dlg0[] = { /* 0x8230ae4 */
    DEBUGINFO_O(161),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x0000003c,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    AWAIT_CUE(5),
    WAIT(10),
    ALERT_CUE(7),
    ALERT_CUE(8),
    WAIT(30),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0001, 0x00000000),
    MSG_NPC(1, _(" The {NAME_2} are in\nthere somewhere.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    CMD_UNK_93(4, DIR_TRANS_10, 34),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's give it our best\nand rescue them {NAME_0}!")),
    VARIANT_DEFAULT(_(" Let's do our best to rescue\nthem, {NAME_0}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(153, 1),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs180_g2_s0_lives1_dlg0[] = { /* 0x8230d64 */
    DEBUGINFO_O(197),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x59, 0x00,  0x0000,  0x00000064,  0x00000000, NULL },
    AWAIT_CUE(6),
    WALK_RELATIVE(256, 0, -100),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CMD_UNK_93(4, DIR_TRANS_10, 0),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(15),
    WALK_GRID(153, 1),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs180_g2_s0_lives2_dlg0[] = { /* 0x8230e64 */
    DEBUGINFO_O(216),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ROTATE_TO(20, DIR_TRANS_SPINLEFT1, DIRECTION_NORTHEAST),
    HALT,
};

static const struct ScriptCommand s_gs180_g2_s0_lives3_dlg0[] = { /* 0x8230ef4 */
    DEBUGINFO_O(228),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_SOUTH),
    AWAIT_CUE(8),
    ROTATE_TO(20, DIR_TRANS_SPINRIGHT1, DIRECTION_NORTHWEST),
    HALT,
};

static const struct ScriptCommand s_gs180_g3_s0_station_sref_script[] = { /* 0x8230f74 */
    DEBUGINFO_O(239),
    SELECT_MAP(MAP_THUNDERWAVE_CAVE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(MUS_A_SUCCESSFUL_RESCUE),
    WAIT(30),
    FLASH_FROM(TRUE, PALUTIL_KIND_01, 60, RGB_U32(0xFF, 0xFF, 0xFF)),
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs180_g3_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs180_g3_s0_station_sref_script }; /* 0x8231014 */

static const struct ScriptCommand s_gs180_g3_s0_lives0_dlg0[] = { /* 0x8231020 */
    DEBUGINFO_O(254),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    PORTRAIT(PLACEMENT_RIGHT_BOTTOM_FLIP, 0x0003, 0x00000001),
    PORTRAIT(PLACEMENT_MIDLEFT_TOP, 0x0004, 0x00000001),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, 0x0005, 0x00000001),
    ALERT_CUE(9),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" OUR BODIES SEPARATED.\nBZBZBZZ. REJOICE! BZBZBZZT!")),
    ALERT_CUE(9),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    MSG_NPC(5, _(" YAY! BZBZBZZT!")),
    ALERT_CUE(10),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(9),
    AWAIT_CUE(5),
    MSG_NPC(4, _(" YAY! BZBZBZZT!")),
    ALERT_CUE(9),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(3, _(" BE THANKFUL, YOU TWO.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(8),
    AWAIT_CUE(5),
    WAIT(30),
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDRIGHT_TOP_FLIP, 0x0002, 0x00000000),
    MSG_NPC(2, _(" YOU ARE OUR HERO.\nTHANK YOU. BZBZBZZ!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    SPECIAL_TEXT(SPECIAL_TEXT_ITEM_REWARD, 3, 1),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_2C, 58, 1),
    SPECIAL_TEXT(SPECIAL_TEXT_UNK_2C, 63, 1),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(9),
    ALERT_CUE(10),
    WAIT(30),
    ALERT_CUE(6),
    ROTATE_TO(8, DIR_TRANS_SPINLEFT1, DIRECTION_SOUTH),
    WAIT(90),
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs180_g3_s0_lives1_dlg0[] = { /* 0x8231478 */
    DEBUGINFO_O(321),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    ROTATE_TO(8, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    HALT,
};

static const struct ScriptCommand s_gs180_g3_s0_lives2_dlg0[] = { /* 0x8231518 */
    DEBUGINFO_O(334),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_WEST),
    AWAIT_CUE(7),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    WALK_GRID(256, 3),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs180_g3_s0_lives3_dlg0[] = { /* 0x82315e8 */
    DEBUGINFO_O(350),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(8),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_WEST),
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_START_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    CALL_SCRIPT(SMILE_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_SOUTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    WALK_GRID(256, 3),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs180_g3_s0_lives4_dlg0[] = { /* 0x8231718 */
    DEBUGINFO_O(372),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_START_FUNC),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_NORTH),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_NORTH),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_START_FUNC),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_NORTH),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    CALL_SCRIPT(SMILE_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(9),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_SOUTH),
    AWAIT_CUE(9),
    WALK_GRID(256, 2),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs180_g3_s0_lives5_dlg0[] = { /* 0x82318d8 */
    DEBUGINFO_O(403),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    AWAIT_CUE(10),
    CALL_SCRIPT(SMILE_START_FUNC),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_NORTH),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTH),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    CALL_SCRIPT(SMILE_END_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(10),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(10),
    WALK_GRID(256, 2),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs180_g1_s0_lives[] = { /* 0x82319f8 */
    /*  0 */ {   0,   4,   0,   0, {  23,  19, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  27,  19, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  64,   4,   0,   0, {  23,  16, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  65,   4,   0,   0, {  27,  16, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g1_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs180_g2_s0_lives[] = { /* 0x8231a58 */
    /*  0 */ {   0,   4,   0,   0, {  23,  19, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  27,  19, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  64,   4,   0,   0, {  21,  16, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g2_s0_lives2_dlg0,
    } },
    /*  3 */ {  65,   4,   0,   0, {  29,  16, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g2_s0_lives3_dlg0,
    } },
};

static const struct GroundLivesData s_gs180_g3_s0_lives[] = { /* 0x8231ab8 */
    /*  0 */ {   0,   4,   0,   0, {  23,  20, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  27,  20, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g3_s0_lives1_dlg0,
    } },
    /*  2 */ {  64,   0,   0,   0, {  26,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs180_g3_s0_lives2_dlg0,
    } },
    /*  3 */ {  65,   0,   0,   0, {  29,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g3_s0_lives3_dlg0,
    } },
    /*  4 */ {  61,   0,   0,   0, {  23,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs180_g3_s0_lives4_dlg0,
    } },
    /*  5 */ {  62,   0,   0,   0, {  21,  17, 0, CPOS_HALFTILE }, {
        [0] = s_gs180_g3_s0_lives5_dlg0,
    } },
};

static const struct GroundEffectData s_gs180_g1_s0_effs[] = { /* 0x8231b48 */
    /*  0 */ {   0,   0,   1,   1, {  25,  18, 0, CPOS_HALFTILE }, s_gs180_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs180_g2_s0_effs[] = { /* 0x8231b54 */
    /*  0 */ {   0,   0,   1,   1, {  25,  18, 0, CPOS_HALFTILE }, s_gs180_g2_s0_eff0_script },
};

static const struct GroundEffectData s_gs180_g3_s0_effs[] = { /* 0x8231b60 */
    /*  0 */ {   0,   0,   1,   1, {  25,  18, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8231b6c */
    &s_gs180_g0_s0_station_sref,
    &s_gs180_g1_s0_station_sref,
    &s_gs180_g2_s0_station_sref,
    &s_gs180_g3_s0_station_sref,
};

static const struct GroundScriptSector s_gs180_g0_sectors[] = { /* 0x8231b7c */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs180_g1_sectors[] = { /* 0x8231ba4 */
    { LPARRAY(s_gs180_g1_s0_lives), 0,NULL, LPARRAY(s_gs180_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs180_g2_sectors[] = { /* 0x8231bcc */
    { LPARRAY(s_gs180_g2_s0_lives), 0,NULL, LPARRAY(s_gs180_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs180_g3_sectors[] = { /* 0x8231bf4 */
    { LPARRAY(s_gs180_g3_s0_lives), 0,NULL, LPARRAY(s_gs180_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs180_groups[] = { /* 0x8231c1c */
    { LPARRAY(s_gs180_g0_sectors) },
    { LPARRAY(s_gs180_g1_sectors) },
    { LPARRAY(s_gs180_g2_sectors) },
    { LPARRAY(s_gs180_g3_sectors) },
};

static const struct GroundLink s_gs180_links[] = { /* 0x8231c3c */
    /* link   0 */ { { /*x*/  24, /*y*/  10, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   1 */ { { /*x*/  24, /*y*/  10, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   2 */ { { /*x*/  18, /*y*/  33, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  31, /*y*/  33, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

const GroundScriptHeader gGroundScript_gs180 = { LPARRAY(s_gs180_groups), s_gs180_links }; /* 0x8231c5c */

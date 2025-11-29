
#define NPC_PARTNER 1
#define NPC_RAYQUAZA 2





static const struct ScriptCommand s_gs209_g0_s0_station_sref_script[] = { /* 0x82620a8 */
    DEBUGINFO_O(10),
    SELECT_MAP(MAP_SKY_TOWER_END),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs209_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs209_g0_s0_station_sref_script }; /* 0x8262114 */

static const struct ScriptCommand s_gs209_g1_s0_station_sref_script[] = { /* 0x8262120 */
    DEBUGINFO_O(19),
    SELECT_MAP(MAP_SKY_TOWER_END),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_RAYQUAZAS_DOMAIN),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    FANFARE_FADEOUT2(16, 512),
    RET,
};

static const struct ScriptRef s_gs209_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs209_g1_s0_station_sref_script }; /* 0x82621b0 */

static const struct ScriptCommand s_gs209_g1_s0_eff0_script[] = { /* 0x82621bc */
    DEBUGINFO_O(33),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    CAMERA_INIT_PAN,
    { 0x89, 0x20,  0x0500,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs209_g1_s0_lives0_dlg0[] = { /* 0x826223c */
    DEBUGINFO_O(44),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(5),
    MSG_OVERHEARD(_("Gyaaaaaaaaaaaaaaaah!")),
    WAIT(30),
    FANFARE_PLAY2(493),
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(5),
    { 0x27, 0x00,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(20),
    FANFARE_PLAY2(493),
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(5),
    { 0x27, 0x00,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(120),
    TEXTBOX_CLEAR2,
    FANFARE_PLAY2(848),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x2e, 0x0f,  0x0002, -0x00000002,  0x00000000, NULL },
    MSG_OVERHEARD(_(" ...Gwaargh!")),
    WAIT(90),
    TEXTBOX_CLEAR,
    WAIT(60),
    ALERT_CUE(7),
    ALERT_CUE(6),
    ALERT_CUE(10),
    CALL_SCRIPT(SHOCK_FUNC),
    AWAIT_CUE(5),
    { 0x28, 0x01,  0x0005,  0x0000001e,  0x00ffffff, NULL },
    WAIT(30),
    FANFARE_PLAY2(512),
    { 0x27, 0x00,  0x0005,  0x00000010,  0x00ffffff, NULL },
    { 0x97, 0x00,  0x0002,  0x00000005,  0x00000002, NULL },
    WAIT(40),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000001, NULL },
    ALERT_CUE(6),
    ALERT_CUE(10),
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(60),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, NPC_PARTNER, 12),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wh-wh-what?! Quake?!{WAIT_PRESS}\nIt can't be!")),
    VARIANT(/* == */  1, _(" We're up on clouds...")),
    VARIANT_DEFAULT(_(" Wh-wh-what?!\nAn earthquake?!{WAIT_PRESS}\nIt's not possible!")),
    VARIANT_DEFAULT(_(" We're on top of clouds...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDRIGHT_TOP_FLIP, NPC_RAYQUAZA, 0),
    MSG_NPC(NPC_RAYQUAZA, _(" These are shock waves!{WAIT_PRESS}\nAnd they're huge!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's it! I get it now!{WAIT_PRESS}\nLook straight up, {NAME_2}!")),
    VARIANT_DEFAULT(_(" That's it! I got it!{WAIT_PRESS}\nLook straight up, {NAME_2}!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(10),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    WAIT(20),
    ALERT_CUE(4),
    ALERT_CUE(3),
    HALT,
};





static const struct ScriptCommand s_gs209_g1_s0_lives1_dlg0[] = { /* 0x826282c */
    DEBUGINFO_O(124),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(6),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs209_g1_s0_lives2_dlg0[] = { /* 0x826290c */
    DEBUGINFO_O(141),
    SELECT_ANIMATION(2),
    AWAIT_CUE(10),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(10),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(10),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs209_g1_s0_lives3_dlg0[] = { /* 0x82629ac */
    DEBUGINFO_O(154),
    SELECT_ANIMATION(2),
    AWAIT_CUE(10),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(10),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    AWAIT_CUE(10),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTH),
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs209_g1_s0_lives4_dlg0[] = { /* 0x8262a4c */
    DEBUGINFO_O(167),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(9),
    AWAIT_CUE(7),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(22),
    FANFARE_PLAY2(652),
    { 0x97, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(8),
    { 0x97, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    FANFARE_PLAY2(672),
    { 0x62, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(2),
    { 0x62, 0x00,  0x0100, -0x00000001,  0x00000000, NULL },
    WAIT(2),
    { 0x62, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    WAIT(2),
    { 0x62, 0x00,  0x0100, -0x00000001,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(672),
    { 0x62, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100, -0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100, -0x00000002,  0x00000000, NULL },
    { 0x62, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    WAIT(1),
    { 0x62, 0x00,  0x0100, -0x00000002,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(774),
    SELECT_ANIMATION(23),
    MSG_OVERHEARD(_("Gyaaaaaaaaaaaaaah!")),
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(5),
    { 0x27, 0x00,  0x0005,  0x00000008,  0x00ffffff, NULL },
    WAIT(90),
    TEXTBOX_CLEAR2,
    SELECT_ANIMATION(24),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    FANFARE_PLAY2(517),
    { 0x28, 0x01,  0x0005,  0x00000004,  0x00ffffff, NULL },
    WAIT(3),
    { 0x27, 0x00,  0x0005,  0x00000004,  0x00ffffff, NULL },
    SELECT_ANIMATION(25),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    CALL_SCRIPT(NOTICE_FUNC),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x001b,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_station_sref_script[] = { /* 0x8262e10 */
    DEBUGINFO_O(229),
    SELECT_MAP(MAP_SKY_TOWER_END),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_RAYQUAZAS_DOMAIN),
    { 0x97, 0x00,  0x0002,  0x00000001,  0x00000001, NULL },
    WAIT(15),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x28, 0x01,  0x0005,  0x00000010,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs209_g2_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs209_g2_s0_station_sref_script }; /* 0x8262eb0 */

static const struct ScriptCommand s_gs209_g2_s0_eff0_script[] = { /* 0x8262ebc */
    DEBUGINFO_O(244),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    WAIT(10),
    CAMERA_INIT_PAN,
    { 0x89, 0x14,  0x0500,  0x00000004,  0x00000000, NULL },
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs209_g2_s0_lives0_dlg0[] = { /* 0x8262f4c */
    DEBUGINFO_O(256),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(465),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDRIGHT_TOP_FLIP, NPC_RAYQUAZA, 0),
    MSG_NPC(NPC_RAYQUAZA, _(" What is that?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, NPC_PARTNER, 12),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" It's a shooting star!\nAnd it's gigantic!")),
    VARIANT(/* == */  1, _(" It's going to destroy\nthe world if it isn't stopped!")),
    VARIANT_DEFAULT(_(" It's a shooting star!\nAnd it's enormous!")),
    VARIANT_DEFAULT(_(" It will destroy the world\nif it continues on its path!")),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" That's why we came,\n{NAME_2}. We need you to destroy\nthat falling star!")),
    VARIANT(/* == */  3, _(" That's why we came,\n{NAME_2}.\nPlease, destroy the falling star!")),
    VARIANT_DEFAULT(_(" That's why we came,\n{NAME_2}.\nPlease, destroy the falling star!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(15),
    MSG_NPC(NPC_RAYQUAZA, _(" ...So, that is why...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Yes! Hurry!\nDestroy it!")),
    VARIANT_DEFAULT(_(" Yes!\nPlease hurry and destroy it!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(NPC_RAYQUAZA, _(" ............{WAIT_PRESS}Before I try...{WAIT_PRESS}\nI need to know your resolve.")),
    MSG_NPC(NPC_RAYQUAZA, _(" The star has come too close.")),
    MSG_NPC(NPC_RAYQUAZA, _(" If I were to loose my\nHyper Beam here...")),
    MSG_NPC(NPC_RAYQUAZA, _(" You would not escape\nunscathed!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" So what?!{WAIT_PRESS}\nWe knew that right from the start!")),
    VARIANT_DEFAULT(_(" So?!{WAIT_PRESS}\nWe accepted that from the start!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(NPC_RAYQUAZA, _(" Well said!")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    BGM_FADEOUT(120),
    FANFARE_PLAY2(664),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    MSG_NPC(NPC_RAYQUAZA, _(" Take charge of your destiny!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(7),
    AWAIT_CUE(5),
    FANFARE_PLAY2(513),
    ALERT_CUE(8),
    ALERT_CUE(4),
    WAIT(10),
    ALERT_CUE(3),
    HALT,
};








static const struct ScriptCommand s_gs209_g2_s0_lives1_dlg0[] = { /* 0x8263660 */
    DEBUGINFO_O(331),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_lives2_dlg0[] = { /* 0x82636a0 */
    DEBUGINFO_O(338),
    SELECT_ANIMATION(2),
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_lives3_dlg0[] = { /* 0x82636e0 */
    DEBUGINFO_O(345),
    SELECT_ANIMATION(2),
    AWAIT_CUE(10),
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_lives4_dlg0[] = { /* 0x8263720 */
    DEBUGINFO_O(352),
    { 0x54, 0x00,  0x001b,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(24),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    ALERT_CUE(8),
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs209_g2_s0_eff1_script[] = { /* 0x8263860 */
    DEBUGINFO_O(375),
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x0000006f,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000070,  0x00000000, NULL },
    WAIT(120),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    AWAIT_CUE(8),
    { 0x59, 0x00,  0x0000, -0x0000001a,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x00000133,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000134,  0x00000000, NULL },
    AWAIT_CUE(8),
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_station_sref_script[] = { /* 0x8263980 */
    DEBUGINFO_O(396),
    SELECT_MAP(MAP_SKY_TOWER_END),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(MUS_RAYQUAZAS_DOMAIN),
    { 0x97, 0x00,  0x0002,  0x00000005,  0x00000002, NULL },
    WAIT(15),
    { 0x27, 0x00,  0x0005,  0x00000010,  0x00ffffff, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x28, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    WAIT(120),
    TEXTBOX_CLEAR2,
    TEXTBOX_AUTO_PRESS(-1, -1),
    WAIT(240),
    RET,
};

static const struct ScriptRef s_gs209_g3_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs209_g3_s0_station_sref_script }; /* 0x8263a70 */

static const struct ScriptCommand s_gs209_g3_s0_lives0_dlg0[] = { /* 0x8263a7c */
    DEBUGINFO_O(416),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(30),
    TEXTBOX_AUTO_PRESS(15, 15),
    PORTRAIT(PLACEMENT_LEFT_BOTTOM_2, NPC_PARTNER, 12),
    MSG_NPC(NPC_PARTNER, _(" Waaaaaaaaaaaaaaaaaah!")),
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs209_g3_s0_lives1_dlg0[] = { /* 0x8263b44 */
    DEBUGINFO_O(431),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_lives2_dlg0[] = { /* 0x8263b84 */
    DEBUGINFO_O(438),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_lives3_dlg0[] = { /* 0x8263bb4 */
    DEBUGINFO_O(444),
    SELECT_ANIMATION(2),
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_lives4_dlg0[] = { /* 0x8263be4 */
    DEBUGINFO_O(450),
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs209_g3_s0_eff1_script[] = { /* 0x8263c24 */
    DEBUGINFO_O(457),
    { 0x56, 0x00,  0x0000,  0x00000134,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs209_g1_s0_lives[] = { /* 0x8263c54 */
    /*  0 */ {   0,   4,   0,   0, {  37,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  34,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g1_s0_lives3_dlg0,
    } },
    /*  4 */ { 108,   0,   0,   0, {  34,  34, CPOS_HALFTILE, 0 }, {
        [0] = s_gs209_g1_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs209_g2_s0_lives[] = { /* 0x8263ccc */
    /*  0 */ {   0,   4,   0,   0, {  37,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  34,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g2_s0_lives3_dlg0,
    } },
    /*  4 */ { 108,   0,   0,   0, {  34,  34, CPOS_HALFTILE, 0 }, {
        [0] = s_gs209_g2_s0_lives4_dlg0,
    } },
};

static const struct GroundLivesData s_gs209_g3_s0_lives[] = { /* 0x8263d44 */
    /*  0 */ {   0,   4,   0,   0, {  37,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  32,  37, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives1_dlg0,
    } },
    /*  2 */ {  10,   4,   0,   0, {  34,  42, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives2_dlg0,
    } },
    /*  3 */ {  11,   4,   0,   0, {  38,  41, 0, CPOS_HALFTILE }, {
        [0] = s_gs209_g3_s0_lives3_dlg0,
    } },
    /*  4 */ { 108,   0,   0,   0, {  34,  34, CPOS_HALFTILE, 0 }, {
        [0] = s_gs209_g3_s0_lives4_dlg0,
    } },
};

static const struct GroundEffectData s_gs209_g1_s0_effs[] = { /* 0x8263dbc */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs209_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs209_g2_s0_effs[] = { /* 0x8263dc8 */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs209_g2_s0_eff0_script },
    /*  1 */ {   4,   4,   1,   1, {  35,  31, 0, 0 }, s_gs209_g2_s0_eff1_script },
};

static const struct GroundEffectData s_gs209_g3_s0_effs[] = { /* 0x8263de0 */
    /*  0 */ {   0,   0,   1,   1, {  34,  35, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
    /*  1 */ {   3,   0,   1,   1, {  35,  28, 0, 0 }, s_gs209_g3_s0_eff1_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8263df8 */
    &s_gs209_g0_s0_station_sref,
    &s_gs209_g1_s0_station_sref,
    &s_gs209_g2_s0_station_sref,
    &s_gs209_g3_s0_station_sref,
};

static const struct GroundScriptSector s_gs209_g0_sectors[] = { /* 0x8263e08 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs209_g1_sectors[] = { /* 0x8263e30 */
    { LPARRAY(s_gs209_g1_s0_lives), 0,NULL, LPARRAY(s_gs209_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs209_g2_sectors[] = { /* 0x8263e58 */
    { LPARRAY(s_gs209_g2_s0_lives), 0,NULL, LPARRAY(s_gs209_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs209_g3_sectors[] = { /* 0x8263e80 */
    { LPARRAY(s_gs209_g3_s0_lives), 0,NULL, LPARRAY(s_gs209_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs209_groups[] = { /* 0x8263ea8 */
    { LPARRAY(s_gs209_g0_sectors) },
    { LPARRAY(s_gs209_g1_sectors) },
    { LPARRAY(s_gs209_g2_sectors) },
    { LPARRAY(s_gs209_g3_sectors) },
};

static const struct GroundLink s_gs209_links[] = { /* 0x8263ec8 */
    {},
};

const GroundScriptHeader gGroundScript_gs209 = { LPARRAY(s_gs209_groups), s_gs209_links }; /* 0x8263ed0 */

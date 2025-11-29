







static const struct ScriptCommand s_gs170_g0_s0_station_sref_script[] = { /* 0x821d1e4 */
    DEBUGINFO_O(10),
    SELECT_MAP(170),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs170_g0_s0_station_sref = { ENTER_CONTROL , 1, NULL, s_gs170_g0_s0_station_sref_script }; /* 0x821d250 */

static const struct ScriptCommand s_gs170_g1_s0_station_sref_script[] = { /* 0x821d25c */
    DEBUGINFO_O(19),
    SELECT_MAP(170),
    SELECT_ENTITIES(-1, 0),
    BGM_FADEIN(30, 36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    FANFARE_PLAY2(506),
    { 0x28, 0x01,  0x0005,  0x00000010,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs170_g1_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs170_g1_s0_station_sref_script }; /* 0x821d2ec */

static const struct ScriptCommand s_gs170_g1_s0_lives0_dlg0[] = { /* 0x821d2f8 */
    DEBUGINFO_O(33),
    SELECT_ANIMATION(5),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(120),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    MSG_QUIET(0, _("(This icy mountain path seems to go\non forever...)")),
    MSG_QUIET(0, _("(We've walked a long way here...)")),
    MSG_QUIET(0, _("({NAME_1} looks exhausted, too...)")),
    MSG_QUIET(0, _("(We've been running all this time out\nof desperation...)")),
    MSG_QUIET(0, _("(What's in store for us ahead?)")),
    MSG_QUIET(0, _("(Are we really doing the right thing?)")),
    TEXTBOX_CLEAR,
    WAIT(30),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT_FLIP, 0x0001, 0x00000002),
    PORTRAIT_POS(1, 0, 2),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Brr... It's too cold!{WAIT_PRESS}\nThere's only snow around us now.")),
    VARIANT(/* == */  1, _(" The scenery hasn't changed\nat all for a while now...")),
    VARIANT(/* == */  1, _(" Are we even getting\nsomewhere?")),
    VARIANT_DEFAULT(_(" Brr... This is too cold!{WAIT_PRESS}\nThere's nothing but snow now.")),
    VARIANT_DEFAULT(_(" The scenery's been\nthe same for a while...")),
    VARIANT_DEFAULT(_(" I wonder if we're really\nmaking progress...")),
    TEXTBOX_CLEAR,
    WAIT(60),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Hey, {NAME_0}?\nYou know what I'm thinking...?")),
    VARIANT(/* == */  1, _(" I think we've finally reached\na place where there's no one else but us.")),
    VARIANT(/* == */  1, _(" I also have this feeling\nthere's nothing ahead of us here...")),
    VARIANT(/* == */  1, _(" And, I'm feeling pretty\nbeat...")),
    VARIANT(/* == */  3, _(" ...Um, {NAME_0}?\nI was thinking...")),
    VARIANT(/* == */  3, _(" It looks like we've finally\nreached somewhere that's deserted...")),
    VARIANT(/* == */  3, _(" I also have a feeling that\nthere isn't anything ahead...")),
    VARIANT(/* == */  3, _(" And, I am pretty tired...")),
    VARIANT_DEFAULT(_(" ...Hey, {NAME_0}?\nI was thinking...")),
    VARIANT_DEFAULT(_(" I think we've come to\na place that's empty except for us...")),
    VARIANT_DEFAULT(_(" I have this feeling there's\nnothing ahead of here, even if we keep\nmoving...")),
    VARIANT_DEFAULT(_(" And I'm getting exhausted...")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000005),
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" We two...\nWhat's going to happen to us?")),
    VARIANT(/* == */  3, _(" The two of us...\nWhat's going to happen to us?")),
    VARIANT_DEFAULT(_(" We two...\nWhat's going to happen to us?")),
    CHOICE(/* label */  3, _("Don't worry. We'll be fine!")),
    CHOICE(/* label */  4, _("I don't know...")),
  LABEL(3), /* = 0x03 */
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0001, 0x00000000),
    PORTRAIT_POS(1, 0, 2),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............{WAIT_PRESS}\nYeah, you're right.")),
    VARIANT(/* == */  1, _(" We came out here.\nThere's no point wondering about it.")),
    VARIANT(/* == */  1, _(" Sorry, {NAME_0}.{WAIT_PRESS}\nI got to feeling sorry for myself.")),
    VARIANT(/* == */  1, _(" {NAME_0}, I came out\nhere because I believed in you.")),
    VARIANT(/* == */  1, _(" And that's not changing.\nI'll keep believing in you, {NAME_0}...")),
    VARIANT(/* == */  3, _(" ............{WAIT_PRESS}\nYou're right.")),
    VARIANT(/* == */  3, _(" There isn't any point in\nwondering about what we did.\nNot after all this.")),
    VARIANT(/* == */  3, _(" Sorry, {NAME_0}.{WAIT_PRESS}\nI was just getting down on myself.")),
    VARIANT(/* == */  3, _(" {NAME_0}, I believed in\nyou, and that's what got me this far.")),
    VARIANT(/* == */  3, _(" And that's not changing.\nI have faith in you, {NAME_0}...")),
    VARIANT_DEFAULT(_(" ............{WAIT_PRESS}\nSure, that's right.")),
    VARIANT_DEFAULT(_(" There isn't any point in\nwondering about what might happen.\nNot after coming this far.")),
    VARIANT_DEFAULT(_(" Sorry, {NAME_0}.{WAIT_PRESS}\nI was just feeling sorry for myself.")),
    VARIANT_DEFAULT(_(" I have faith in you, \n{NAME_0}.\nThat's what brought me here.")),
    VARIANT_DEFAULT(_(" And that's not changing.\nI still have faith in you, {NAME_0}...")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll go wherever you go.")),
    VARIANT(/* == */  3, _(" I'll go with you, always.")),
    VARIANT_DEFAULT(_(" I'll keep going wherever\nyou go.")),
    TEXTBOX_CLEAR,
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    ALERT_CUE(6),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTHEAST),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0001, 0x00000000),
    PORTRAIT_POS(1, 0, 2),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" .........{WAIT_PRESS}Sorry.{WAIT_PRESS}\nI shouldn't have said that.\nIt doesn't help scaring you like that.")),
    VARIANT(/* == */  1, _(" We came out here.\nThere's no point wondering about it.")),
    VARIANT(/* == */  1, _(" Even if we don't know\nwhat's ahead...{WAIT_PRESS}\nWe just have to keep going.")),
    VARIANT(/* == */  1, _(" Don't worry!\nThere's got to be something ahead.")),
    VARIANT(/* == */  1, _(" {NAME_0}, I came out\nhere because I believed in you.")),
    VARIANT(/* == */  1, _(" And that's not changing.\nI'll keep believing in you, {NAME_0}...")),
    VARIANT(/* == */  3, _(" .........{WAIT_PRESS}I'm sorry.{WAIT_PRESS}\nI shouldn't have said anything to bring\nyou down...")),
    VARIANT(/* == */  3, _(" There isn't any point in\nwondering about what we did.\nNot after all this.")),
    VARIANT(/* == */  3, _(" Even though we don't know\nwhat's ahead...{WAIT_PRESS}\nWe'll find out if we keep moving!")),
    VARIANT(/* == */  3, _(" Don't worry!\nThere's got to be something ahead.")),
    VARIANT(/* == */  3, _(" {NAME_0}, I believed in\nyou, and that's what got me this far.")),
    VARIANT(/* == */  3, _(" And that's not changing.\nI have faith in you, {NAME_0}...")),
    VARIANT_DEFAULT(_(" .........{WAIT_PRESS}I'm sorry.{WAIT_PRESS}\nI said something stupid to frighten you...")),
    VARIANT_DEFAULT(_(" There isn't any point in\nwondering about what might happen.\nNot after coming this far.")),
    VARIANT_DEFAULT(_(" Even though we don't know\nwhat's ahead...{WAIT_PRESS}\nWe'll only know by pressing on!")),
    VARIANT_DEFAULT(_(" Don't worry!\nThere's got to be something ahead.")),
    VARIANT_DEFAULT(_(" I have faith in you, \n{NAME_0}.\nThat's what brought me here.")),
    VARIANT_DEFAULT(_(" And that's not changing.\nI still have faith in you, {NAME_0}...")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll go wherever you go.")),
    VARIANT(/* == */  3, _(" I'll go with you, always.")),
    VARIANT_DEFAULT(_(" I'll keep going wherever\nyou go.")),
    TEXTBOX_CLEAR,
  LABEL(5), /* = 0x05 */
    ALERT_CUE(6),
    WAIT(45),
    MSG_QUIET(0, _("(Yes...)")),
    MSG_QUIET(0, _("({NAME_1} trusts me without any\ndoubt.)")),
    MSG_QUIET(0, _("(I can't afford to be indecisive.)")),
    MSG_QUIET(0, _("(I have to believe in myself more.)")),
    TEXTBOX_CLEAR,
    WAIT(30),
    BGM_FADEOUT(30),
    FANFARE_PLAY2(476),
    { 0x28, 0x01,  0x0007,  0x00000004,  0x00806040, NULL },
    SELECT_ANIMATION(9),
    { 0x54, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x28, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x27, 0x01,  0x0007,  0x0000000c,  0x00806040, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    WAIT(60),
    PORTRAIT_REP(0x0000, 0x00000002),
    MSG_QUIET(0, _("(...{WAIT_PRESS}Wh-what?{WAIT_PRESS} What was that?)")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(476),
    { 0x28, 0x01,  0x0007,  0x00000004,  0x00806040, NULL },
    SELECT_ANIMATION(9),
    { 0x54, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x28, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x27, 0x01,  0x0007,  0x0000000c,  0x00806040, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    MSG_QUIET(0, _("(...D-dizzy?{WAIT_PRESS} Or what?)")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(469),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    PORTRAIT_POS(1, 0, 2),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh?{WAIT_PRESS} What's the matter?\n{NAME_0}?")),
    VARIANT_DEFAULT(_(" Huh?{WAIT_PRESS} Is something wrong?\n{NAME_0}?")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(476),
    { 0x28, 0x01,  0x0007,  0x00000004,  0x00806040, NULL },
    SELECT_ANIMATION(9),
    { 0x54, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x28, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x27, 0x01,  0x0007,  0x0000000c,  0x00806040, NULL },
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    MSG_NPC(-1, _(" ...Finally.")),
    MSG_NPC(-1, _(" ...Finally, you have arrived...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_QUIET(0, _("(Someone...{WAIT_PRESS}\nSomeone is talking to me...)")),
    MSG_QUIET(0, _("({NAME_1}...?{WAIT_PRESS} No.\nThis voice isn't {NAME_1}...)")),
    MSG_QUIET(0, _("(This voice...{WAIT_PRESS}\nI've heard it somewhere...)")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(477),
    SELECT_ENTITIES(-1, 1),
    { 0x27, 0x01,  0x0005,  0x00000030,  0x00000000, NULL },
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_EAST),
    WAIT(30),
    MSG_NPC(-1, _(" Finally...")),
    MSG_NPC(-1, _(" You have arrived...")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};








static const struct ScriptCommand s_gs170_g1_s0_lives1_dlg0[] = { /* 0x821ec08 */
    DEBUGINFO_O(233),
    SELECT_ANIMATION(5),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_NORTHWEST),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(QUESTION_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs170_g1_s0_lives2_dlg0[] = { /* 0x821ed08 */
    DEBUGINFO_O(252),
    SELECT_ANIMATION(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs170_g1_s1_lives0_dlg0[] = { /* 0x821ed78 */
    DEBUGINFO_O(262),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    RET,
};

static const struct ScriptCommand s_gs170_g2_s0_station_sref_script[] = { /* 0x821edd8 */
    DEBUGINFO_O(271),
    SELECT_MAP(170),
    SELECT_ENTITIES(-1, 0),
    { 0x27, 0x00,  0x0005,  0x00000020,  0x00ffffff, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(120),
    { 0x23, 0x01,  0x0078,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs170_g2_s0_station_sref = { EVENT_CONTROL, 7, NULL, s_gs170_g2_s0_station_sref_script }; /* 0x821ee58 */

static const struct ScriptCommand s_gs170_g2_s0_lives0_dlg0[] = { /* 0x821ee64 */
    DEBUGINFO_O(284),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ALERT_CUE(7),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" I am so glad.{WAIT_PRESS}\nFinally, we get to meet.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    MSG_QUIET(0, _("...You're...{WAIT_PRESS} What...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_RIGHT, 0x0001, 0x00000004),
    PORTRAIT_POS(1, 0, 2),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}.\nWhat's up with you?")),
    VARIANT(/* == */  1, _(" Talking to yourself like\nthat...")),
    VARIANT_DEFAULT(_(" {NAME_0}, is something\nthe matter?")),
    VARIANT_DEFAULT(_(" Why are you talking to\nyourself?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ROTATE_TO(4, DIR_TRANS_SPINRIGHT1, DIRECTION_SOUTHEAST),
    WAIT(64),
    ROTATE_TO(4, DIR_TRANS_SPINLEFT1, DIRECTION_EAST),
    WAIT(16),
    MSG_NPC(2, _(" I cannot be seen by others.")),
    MSG_NPC(2, _(" I am visible only to you.")),
    TEXTBOX_CLEAR,
    WAIT(64),
    MSG_NPC(2, _(" A little farther ahead...")),
    MSG_NPC(2, _(" There is a jagged mountain\nrange topped by {COLOR YELLOW_D}Mt. Freeze{RESET}.")),
    MSG_NPC(2, _(" Inside its peak...{WAIT_PRESS}\nNinetales lives.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    PORTRAIT_REP(0x0000, 0x0000000c),
    MSG_QUIET(0, _("...Ninetales?!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" Ninetales awaits your\narrival.")),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    ALERT_CUE(7),
    MSG_NPC(2, _(" Beware...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_QUIET(0, _("Oh! W-wait...!")),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(60),
    PORTRAIT_REP(0x0000, 0x00000005),
    MSG_QUIET(0, _("..................")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}!\nCome on, {NAME_0}!")),
    VARIANT(/* == */  1, _(" What were you doing?{WAIT_PRESS}\nWhat just happened to you...?")),
    VARIANT_DEFAULT(_(" Hey, {NAME_0}!\n{NAME_0}!")),
    VARIANT_DEFAULT(_(" What's the matter?{WAIT_PRESS}\nWhat happened...?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(3),
    HALT,
};








static const struct ScriptCommand s_gs170_g2_s0_lives1_dlg0[] = { /* 0x821f534 */
    DEBUGINFO_O(362),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs170_g2_s0_lives2_dlg0[] = { /* 0x821f5e4 */
    DEBUGINFO_O(376),
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    ROTATE_TO(4, DIR_TRANS_10, DIRECTION_NORTHEAST),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs170_g2_s0_lives3_dlg0[] = { /* 0x821f684 */
    DEBUGINFO_O(389),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
  LABEL(0), /* = 0x00 */
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(1),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 0),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(1),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(1),
    SELECT_ANIMATION(23),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    WAIT(1),
    SELECT_ANIMATION(24),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    END_DELETE,
};

static const struct GroundLivesData s_gs170_g1_s0_lives[] = { /* 0x821f804 */
    /*  0 */ {   0,   2,   0,   0, { 100,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, { 103,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  83,   2,   0,   0, {  96,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g1_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs170_g1_s1_lives[] = { /* 0x821f84c */
    /*  0 */ {  82,   6,   0,   0, { 106,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g1_s1_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs170_g2_s0_lives[] = { /* 0x821f864 */
    /*  0 */ {   0,   2,   0,   0, { 100,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   5,   0,   0, { 103,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  83,   3,   0,   0, {  96,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g2_s0_lives2_dlg0,
    } },
    /*  3 */ {  82,   6,   0,   0, { 106,  15, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs170_g2_s0_lives3_dlg0,
    } },
};

static const struct GroundEffectData s_gs170_g1_s0_effs[] = { /* 0x821f8c4 */
    /*  0 */ {   0,   0,   1,   1, { 103,  15, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs170_g2_s0_effs[] = { /* 0x821f8d0 */
    /*  0 */ {   0,   0,   1,   1, { 103,  15, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x821f8dc */
    &s_gs170_g0_s0_station_sref,
    &s_gs170_g1_s0_station_sref,
    &s_gs170_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs170_g0_sectors[] = { /* 0x821f8e8 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs170_g1_sectors[] = { /* 0x821f910 */
    { LPARRAY(s_gs170_g1_s0_lives), 0,NULL, LPARRAY(s_gs170_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
    { LPARRAY(s_gs170_g1_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs170_g2_sectors[] = { /* 0x821f960 */
    { LPARRAY(s_gs170_g2_s0_lives), 0,NULL, LPARRAY(s_gs170_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs170_groups[] = { /* 0x821f988 */
    { LPARRAY(s_gs170_g0_sectors) },
    { LPARRAY(s_gs170_g1_sectors) },
    { LPARRAY(s_gs170_g2_sectors) },
};

static const struct GroundLink s_gs170_links[] = { /* 0x821f9a0 */
    {},
};

const GroundScriptHeader gGroundScript_gs170 = { LPARRAY(s_gs170_groups), s_gs170_links }; /* 0x821f9a8 */

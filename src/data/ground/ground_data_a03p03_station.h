







static const struct ScriptCommand s_gs170_g0_s0_station_sref_script[] = { /* 0x821d1e4 */
    DEBUGINFO,
    SELECT_MAP(170),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs170_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs170_g0_s0_station_sref_script }; /* 0x821d250 */

static const struct ScriptCommand s_gs170_g1_s0_station_sref_script[] = { /* 0x821d25c */
    DEBUGINFO,
    SELECT_MAP(170),
    SELECT_ENTITIES(-1, 0),
    BGM_FADEIN(30, 36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(506),
    { 0x28, 0x01,  0x0005,  0x00000010,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs170_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs170_g1_s0_station_sref_script }; /* 0x821d2ec */

static const struct ScriptCommand s_gs170_g1_s0_lives0_dlg0[] = { /* 0x821d2f8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    WAIT(120),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(This icy mountain path seems to go\non forever...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(We've walked a long way here...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("($n1 looks exhausted, too...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(We've been running all this time out\nof desperation...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(What's in store for us ahead?)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Are we really doing the right thing?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x14,  0x0001,  0x00000002,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001,  0x00000000,  0x00000002, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Brr... It's too cold!#W\nThere's only snow around us now.")),
    VARIANT(/* == */  1, _(" The scenery hasn't changed\nat all for a while now...")),
    VARIANT(/* == */  1, _(" Are we even getting\nsomewhere?")),
    VARIANT_DEFAULT(_(" Brr... This is too cold!#W\nThere's nothing but snow now.")),
    VARIANT_DEFAULT(_(" The scenery's been\nthe same for a while...")),
    VARIANT_DEFAULT(_(" I wonder if we're really\nmaking progress...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Hey, $n0?\nYou know what I'm thinking...?")),
    VARIANT(/* == */  1, _(" I think we've finally reached\na place where there's no one else but us.")),
    VARIANT(/* == */  1, _(" I also have this feeling\nthere's nothing ahead of us here...")),
    VARIANT(/* == */  1, _(" And, I'm feeling pretty\nbeat...")),
    VARIANT(/* == */  3, _(" ...Um, $n0?\nI was thinking...")),
    VARIANT(/* == */  3, _(" It looks like we've finally\nreached somewhere that's deserted...")),
    VARIANT(/* == */  3, _(" I also have a feeling that\nthere isn't anything ahead...")),
    VARIANT(/* == */  3, _(" And, I am pretty tired...")),
    VARIANT_DEFAULT(_(" ...Hey, $n0?\nI was thinking...")),
    VARIANT_DEFAULT(_(" I think we've come to\na place that's empty except for us...")),
    VARIANT_DEFAULT(_(" I have this feeling there's\nnothing ahead of here, even if we keep\nmoving...")),
    VARIANT_DEFAULT(_(" And I'm getting exhausted...")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" We two...\nWhat's going to happen to us?")),
    VARIANT(/* == */  3, _(" The two of us...\nWhat's going to happen to us?")),
    VARIANT_DEFAULT(_(" We two...\nWhat's going to happen to us?")),
    CHOICE(/* label */  3, _("Don't worry. We'll be fine!")),
    CHOICE(/* label */  4, _("I don't know...")),
  LABEL(3), /* = 0x03 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001,  0x00000000,  0x00000002, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............#W\nYeah, you're right.")),
    VARIANT(/* == */  1, _(" We came out here.\nThere's no point wondering about it.")),
    VARIANT(/* == */  1, _(" Sorry, $n0.#W\nI got to feeling sorry for myself.")),
    VARIANT(/* == */  1, _(" $n0, I came out\nhere because I believed in you.")),
    VARIANT(/* == */  1, _(" And that's not changing.\nI'll keep believing in you, $n0...")),
    VARIANT(/* == */  3, _(" ............#W\nYou're right.")),
    VARIANT(/* == */  3, _(" There isn't any point in\nwondering about what we did.\nNot after all this.")),
    VARIANT(/* == */  3, _(" Sorry, $n0.#W\nI was just getting down on myself.")),
    VARIANT(/* == */  3, _(" $n0, I believed in\nyou, and that's what got me this far.")),
    VARIANT(/* == */  3, _(" And that's not changing.\nI have faith in you, $n0...")),
    VARIANT_DEFAULT(_(" ............#W\nSure, that's right.")),
    VARIANT_DEFAULT(_(" There isn't any point in\nwondering about what might happen.\nNot after coming this far.")),
    VARIANT_DEFAULT(_(" Sorry, $n0.#W\nI was just feeling sorry for myself.")),
    VARIANT_DEFAULT(_(" I have faith in you, \n$n0.\nThat's what brought me here.")),
    VARIANT_DEFAULT(_(" And that's not changing.\nI still have faith in you, $n0...")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll go wherever you go.")),
    VARIANT(/* == */  3, _(" I'll go with you, always.")),
    VARIANT_DEFAULT(_(" I'll keep going wherever\nyou go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(5),
  LABEL(4), /* = 0x04 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001,  0x00000000,  0x00000002, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" .........#WSorry.#W\nI shouldn't have said that.\nIt doesn't help scaring you like that.")),
    VARIANT(/* == */  1, _(" We came out here.\nThere's no point wondering about it.")),
    VARIANT(/* == */  1, _(" Even if we don't know\nwhat's ahead...#W\nWe just have to keep going.")),
    VARIANT(/* == */  1, _(" Don't worry!\nThere's got to be something ahead.")),
    VARIANT(/* == */  1, _(" $n0, I came out\nhere because I believed in you.")),
    VARIANT(/* == */  1, _(" And that's not changing.\nI'll keep believing in you, $n0...")),
    VARIANT(/* == */  3, _(" .........#WI'm sorry.#W\nI shouldn't have said anything to bring\nyou down...")),
    VARIANT(/* == */  3, _(" There isn't any point in\nwondering about what we did.\nNot after all this.")),
    VARIANT(/* == */  3, _(" Even though we don't know\nwhat's ahead...#W\nWe'll find out if we keep moving!")),
    VARIANT(/* == */  3, _(" Don't worry!\nThere's got to be something ahead.")),
    VARIANT(/* == */  3, _(" $n0, I believed in\nyou, and that's what got me this far.")),
    VARIANT(/* == */  3, _(" And that's not changing.\nI have faith in you, $n0...")),
    VARIANT_DEFAULT(_(" .........#WI'm sorry.#W\nI said something stupid to frighten you...")),
    VARIANT_DEFAULT(_(" There isn't any point in\nwondering about what might happen.\nNot after coming this far.")),
    VARIANT_DEFAULT(_(" Even though we don't know\nwhat's ahead...#W\nWe'll only know by pressing on!")),
    VARIANT_DEFAULT(_(" Don't worry!\nThere's got to be something ahead.")),
    VARIANT_DEFAULT(_(" I have faith in you, \n$n0.\nThat's what brought me here.")),
    VARIANT_DEFAULT(_(" And that's not changing.\nI still have faith in you, $n0...")),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I'll go wherever you go.")),
    VARIANT(/* == */  3, _(" I'll go with you, always.")),
    VARIANT_DEFAULT(_(" I'll keep going wherever\nyou go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(5), /* = 0x05 */
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Yes...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("($n1 trusts me without any\ndoubt.)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I can't afford to be indecisive.)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I have to believe in myself more.)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    BGM_FADEOUT(30),
    FANFARE_PLAY2(476),
    { 0x28, 0x01,  0x0007,  0x00000004,  0x00806040, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x28, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x27, 0x01,  0x0007,  0x0000000c,  0x00806040, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x15,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...#WWh-what?#W What was that?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(476),
    { 0x28, 0x01,  0x0007,  0x00000004,  0x00806040, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x28, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x27, 0x01,  0x0007,  0x0000000c,  0x00806040, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(...D-dizzy?#W Or what?)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(469),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001,  0x00000000,  0x00000002, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh?#W What's the matter?\n$n0?")),
    VARIANT_DEFAULT(_(" Huh?#W Is something wrong?\n$n0?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(476),
    { 0x28, 0x01,  0x0007,  0x00000004,  0x00806040, NULL },
    { 0x54, 0x00,  0x0009,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x27, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x28, 0x01,  0x0007,  0x00000008,  0x00806040, NULL },
    { 0x27, 0x01,  0x0007,  0x0000000c,  0x00806040, NULL },
    { 0x28, 0x01,  0x0005,  0x00000008,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Finally.") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" ...Finally, you have arrived...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Someone...#W\nSomeone is talking to me...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("($n1...?#W No.\nThis voice isn't $n1...)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(This voice...#W\nI've heard it somewhere...)") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(477),
    SELECT_ENTITIES(-1, 1),
    { 0x27, 0x01,  0x0005,  0x00000030,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(30),
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" Finally...") },
    { 0x34, 0x00, -0x0001,  0x00000000,  0x00000000, _(" You have arrived...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};








static const struct ScriptCommand s_gs170_g1_s0_lives1_dlg0[] = { /* 0x821ec08 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000005,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(QUESTION_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs170_g1_s0_lives2_dlg0[] = { /* 0x821ed08 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0002,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs170_g1_s1_lives0_dlg0[] = { /* 0x821ed78 */
    DEBUGINFO,
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_gs170_g2_s0_station_sref_script[] = { /* 0x821edd8 */
    DEBUGINFO,
    SELECT_MAP(170),
    SELECT_ENTITIES(-1, 0),
    { 0x27, 0x00,  0x0005,  0x00000020,  0x00ffffff, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    BGM_FADEOUT(120),
    { 0x23, 0x01,  0x0078,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs170_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs170_g2_s0_station_sref_script }; /* 0x821ee58 */

static const struct ScriptCommand s_gs170_g2_s0_lives0_dlg0[] = { /* 0x821ee64 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I am so glad.#W\nFinally, we get to meet.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...You're...#W What...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x0f,  0x0001,  0x00000004,  0x00000000, NULL },
    { 0x2f, 0x00,  0x0001,  0x00000000,  0x00000002, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0.\nWhat's up with you?")),
    VARIANT(/* == */  1, _(" Talking to yourself like\nthat...")),
    VARIANT_DEFAULT(_(" $n0, is something\nthe matter?")),
    VARIANT_DEFAULT(_(" Why are you talking to\nyourself?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    { 0x91, 0x04,  0x0001,  0x00000001,  0x00000000, NULL },
    WAIT(64),
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(16),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I cannot be seen by others.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" I am visible only to you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(64),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" A little farther ahead...") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" There is a jagged mountain\nrange topped by #CDMt. Freeze#R.") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Inside its peak...#W\nNinetales lives.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x2e, 0x15,  0x0000,  0x0000000c,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Ninetales?!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Ninetales awaits your\narrival.") },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Beware...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("Oh! W-wait...!") },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    WAIT(60),
    { 0x2e, 0x15,  0x0000,  0x00000005,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, $n0!\nCome on, $n0!")),
    VARIANT(/* == */  1, _(" What were you doing?#W\nWhat just happened to you...?")),
    VARIANT_DEFAULT(_(" Hey, $n0!\n$n0!")),
    VARIANT_DEFAULT(_(" What's the matter?#W\nWhat happened...?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};








static const struct ScriptCommand s_gs170_g2_s0_lives1_dlg0[] = { /* 0x821f534 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs170_g2_s0_lives2_dlg0[] = { /* 0x821f5e4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_RIGHT_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    { 0x91, 0x04,  0x000a,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs170_g2_s0_lives3_dlg0[] = { /* 0x821f684 */
    DEBUGINFO,
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 0),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0017,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x54, 0x00,  0x0018,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
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

/*extern*/ const struct GroundScriptHeader gGroundScript_gs170 = { LPARRAY(s_gs170_groups), s_gs170_links }; /* 0x821f9a8 */

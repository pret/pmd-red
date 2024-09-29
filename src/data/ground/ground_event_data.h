











static const struct ScriptCommand s_script_END_TALK[] = { /* 0x811ee64 */
    DEBUGINFO,
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_WAIT_END_TALK_FUNC[] = { /* 0x811eec8 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_WAIT_END_EVENT_FUNC[] = { /* 0x811eef8 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_WAIT_START_FUNC[] = { /* 0x811ef28 */
    DEBUGINFO,
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_INCOMPLETE_TALK[] = { /* 0x811ef58 */
    DEBUGINFO,
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#CWUnregistered dialog script#R") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_script_NORMAL_WAIT_END_TALK[] = { /* 0x811efa8 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_LIVES_REPLY_NORMAL[] = { /* 0x811efd8 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(12),
    RET,
};

static const struct ScriptCommand s_script_LIVES_REPLY[] = { /* 0x811f048 */
    DEBUGINFO,
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(12),
    RET,
};

static const struct ScriptCommand s_script_OBJECT_REPLY_NORMAL[] = { /* 0x811f0a8 */
    DEBUGINFO,
    { 0xe3, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    RET,
};

static const struct ScriptCommand s_script_EXAMINE_MISS[] = { /* 0x811f0e8 */
    DEBUGINFO,
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("$n0 checked underfoot.") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("But there was nothing to be found...") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_script_ENTER_WAIT_FUNC[] = { /* 0x811f168 */
    DEBUGINFO,
    RET_DIRECT,
};

static const struct ScriptCommand s_script_UNIT_TALK[] = { /* 0x811f188 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("Let's go.") },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_script_HABITAT_TALK[] = { /* 0x811f214 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0001, -0x00000002,  0x00000000, NULL },
    { 0x3b, 0x0a,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(2, /* to label */ 1),
    { 0xe3, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x10,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _("Pleased to meet you.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x10,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(HABITAT_TALK_S01E02A),
};

static const struct ScriptCommand s_script_HABITAT_TALK_S01E02A[] = { /* 0x811f36c */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x2e, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMPIF_EQUAL(FLAG_KIND_CHANGE_REQUEST, 0, /* to label */ 0),
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I will dedicate myself to\ncreating a fantastic new design.\nPlease check the rescue team flag later!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If my design fails to\nimpress you, please let me know.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If so, I will change the\ndesign to one perhaps more to your liking.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x10,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(0), /* = 0x00 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hello!") },
    ASK3(FALSE, /*default*/ 1, /* speaker */ 1, _(" Oh?#W Did you perhaps wish\nto change the team flag's design?")),
    CHOICE(/* label */  1, _("No need to change.")),
    CHOICE(/* label */  2, _("Yes, please.")),
  LABEL(1), /* = 0x01 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I see.#W If you would like the\nflag's design changed, please tell me.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x10,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
  LABEL(2), /* = 0x02 */
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Ah, very well!#W\nI may be unknown, but nonetheless, I am\nan artist.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" I will do my best to create\na splendid design for you!\nPlease check the rescue team flag later!") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If my design fails to\nimpress you, please let me know.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" If so, I will change the\ndesign to one perhaps more to your liking.") },
    UPDATE_VARINT(CALC_SET, FLAG_KIND_CHANGE_REQUEST, 1),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x10,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_HABITAT_MOVE1[] = { /* 0x811f7c0 */
    DEBUGINFO,
    { 0x3b, 0x14,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    JUMP_SCRIPT(HABITAT_MOVE_STAY_TURN),
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x8a, 0x18,  0x0100,  0x00000009,  0x00000000, NULL },
    WAIT_RANDOM(24, 48),
    JUMP_LABEL(1),
};

static const struct ScriptCommand s_script_HABITAT_MOVE2[] = { /* 0x811f860 */
    DEBUGINFO,
    { 0x3b, 0x14,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 0),
    JUMP_SCRIPT(HABITAT_MOVE_STAY_TURN),
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x8a, 0x18,  0x0100,  0x00000009,  0x00000000, NULL },
    WAIT_RANDOM(24, 48),
    JUMP_LABEL(1),
};

static const struct ScriptCommand s_script_HABITAT_MOVE_PAUSE[] = { /* 0x811f920 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_HABITAT_MOVE_STAY_FIX[] = { /* 0x811f990 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_HABITAT_MOVE_STAY_TURN[] = { /* 0x811fa00 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x8d, 0x01,  0x0009,  0x00000000,  0x00000000, NULL },
    WAIT_RANDOM(24, 48),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_LIVES_MOVE_NORMAL[] = { /* 0x811fa70 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_LIVES_MOVE_CHANGE[] = { /* 0x811fad0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_OBJECT_MOVE_NORMAL[] = { /* 0x811fb30 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_OBJECT_MOVE_CHANGE[] = { /* 0x811fb80 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_EFFECT_MOVE_NORMAL[] = { /* 0x811fbd0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_EFFECT_MOVE_CHANGE[] = { /* 0x811fc20 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_MOVE_INIT[] = { /* 0x811fc70 */
    DEBUGINFO,
    WAIT(12),
    RET,
};

static const struct ScriptCommand s_script_MOVE_PAUSE[] = { /* 0x811fca0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_MOVE_STAY[] = { /* 0x811fd10 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_MOVE_SLEEP[] = { /* 0x811fd80 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_MOVE_RANDOM[] = { /* 0x811fde0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x8a, 0x18,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT(48),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_MOVE_BOY[] = { /* 0x811fe40 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x8a, 0x18,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT_RANDOM(24, 48),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_MOVE_GIRL[] = { /* 0x811fea0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x8a, 0x10,  0x0100,  0x00000008,  0x00000000, NULL },
    WAIT_RANDOM(16, 24),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_WAKEUP_FUNC[] = { /* 0x811ff00 */
    DEBUGINFO,
    JUMPIF_UNK_BE(/* to label */ 0), /* something sleep related?*/
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x3c,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0026,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x3c,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0027,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LOOK_AROUND_FUNC[] = { /* 0x8120000 */
    DEBUGINFO,
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    { 0x92, 0x04,  0x0001,  0x00000005,  0x00000000, NULL },
    WAIT(15),
    { 0x92, 0x04,  0x0002,  0x00000004,  0x00000000, NULL },
    WAIT(15),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LOOK_AROUND_DOWN_FUNC[] = { /* 0x8120080 */
    DEBUGINFO,
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LOOK_AROUND_RIGHT_FUNC[] = { /* 0x81200f0 */
    DEBUGINFO,
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LOOK_AROUND_LEFT_FUNC[] = { /* 0x8120160 */
    DEBUGINFO,
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0002,  0x00000002,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x0001,  0x00000006,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_JUMP_HAPPY_FUNC[] = { /* 0x81201d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_JUMP_SURPRISE_FUNC[] = { /* 0x8120240 */
    DEBUGINFO,
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x0000000a,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_JUMP_ANGRY_FUNC[] = { /* 0x81202c0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0200,  0x00000006,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    WAIT(2),
    { 0x70, 0x00,  0x0200,  0x00000006,  0x00000000, NULL },
    WAIT(1),
    { 0x70, 0x00,  0x0200,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_NOTICE_FUNC[] = { /* 0x8120370 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_QUESTION_FUNC[] = { /* 0x81203b0 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000059,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SWEAT_FUNC[] = { /* 0x81203f0 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x0000005c,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SHOCK_FUNC[] = { /* 0x8120430 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SPREE_START_FUNC[] = { /* 0x8120470 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SPREE_END_FUNC[] = { /* 0x81204a0 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SMILE_START_FUNC[] = { /* 0x81204d0 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SMILE_END_FUNC[] = { /* 0x8120500 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_ANGRY_START_FUNC[] = { /* 0x8120530 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x0000005e,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_ANGRY_END_FUNC[] = { /* 0x8120560 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_MOVE_PLAZA_SLEEP[] = { /* 0x8120590 */
    DEBUGINFO,
    CALL_SCRIPT(INIT_PLAZA_SLEEP_STAY_FUNC),
    { 0x8d, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    WAIT(240),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_script_INIT_PLAZA_SLEEP_STAY_FUNC[] = { /* 0x81205f0 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(4, /* to label */ 0),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_INIT_PLAZA_SLEEP_TALK_FUNC[] = { /* 0x8120670 */
    DEBUGINFO,
    JUMPIF_SCENARIOCHECK(4, /* to label */ 0),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_INIT_SLEEP_FUNC[] = { /* 0x81206e0 */
    DEBUGINFO,
    JUMPIF_UNK_BE(/* to label */ 0), /* something sleep related?*/
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    { 0x54, 0x00,  0x0026,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x3c,  0x0002,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_INIT_BASE_FUNC[] = { /* 0x8120770 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_INIT_DEBUG_HABITAT[] = { /* 0x81207d0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x000001e0,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00000010,  0x00000000, NULL },
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_script_NORMAL_CAMERA[] = { /* 0x8120840 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_script_DISMISSAL_SALLY_MEMBER_FUNC[] = { /* 0x8120880 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("DISMISSAL_SALLY_MEMBER_FUNC\n") },
    { 0x3b, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The rescue team member(s)\n#+dispersed to the Friend Area(s).") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+If you want to add members to\n#+the rescue team, go visit\n#+them in their Friend Areas.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const struct ScriptCommand s_script_DISMISSAL_SALLY_MEMBER2_FUNC[] = { /* 0x81209cc */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("DISMISSAL_SALLY_MEMBER2_FUNC\n") },
    { 0x3b, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The rescue team member(s)\n#+dispersed to the Friend Area(s).") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+If you want to add members to\n#+the rescue team, go visit\n#+them in their Friend Areas.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const struct ScriptCommand s_script_DISMISSAL_SALLY_MEMBER3_FUNC[] = { /* 0x8120a7c */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("DISMISSAL_SALLY_MEMBER3_FUNC\n") },
    { 0x3b, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The rescue team member(s)\n#+dispersed to the Friend Area(s).") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+If you want to add members to\n#+the rescue team, go visit\n#+them in their Friend Areas.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const struct ScriptCommand s_script_DISMISSAL_SALLY_MEMBER4_FUNC[] = { /* 0x8120b2c */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("DISMISSAL_SALLY_MEMBER4_FUNC\n") },
    { 0x3b, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The rescue team member(s)\n#+dispersed to the Friend Area(s).") },
    { 0x32, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+If you want to add members to\n#+the rescue team, go visit\n#+them in their Friend Areas.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    RET_DIRECT,
};

static const struct ScriptCommand s_script_NEXT_SAVE_FUNC[] = { /* 0x8120bdc */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("NEXT_SAVE_FUNC\n") },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Would you like to save your adventure?")),
    CHOICE(/* label */  0, _("Yes")),
    CHOICE(/* label */  1, _("*No")),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x3c, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_NEXT_SAVE2_FUNC[] = { /* 0x8120cdc */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("NEXT_SAVE2_FUNC\n") },
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Would you like to save your adventure?")),
    CHOICE(/* label */  0, _("Yes")),
    CHOICE(/* label */  1, _("*No")),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    { 0x3c, 0x0f,  0x0000,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SAVE_POINT[] = { /* 0x8120db0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3a, 0x00,  0x0000,  0x00000000, -0x00000001, _("Would you like to save your adventure?") },
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_START_FUNC),
    { 0x3c, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_END_FUNC),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_script_WAREHOUSE_POINT[] = { /* 0x8120e60 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x3c, 0x11,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_script_SAVE_AND_WAREHOUSE_POINT[] = { /* 0x8120ec0 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    ASK1( TRUE, /*default*/ 0, /* speaker */ -1, _("What would you like to do?")),
    CHOICE(/* label */  0, _("Check storage.")),
    CHOICE(/* label */  1, _("Save.")),
    JUMP_SCRIPT(END_TALK),
  LABEL(0), /* = 0x00 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3c, 0x11,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(END_TALK),
  LABEL(1), /* = 0x01 */
    { 0x3a, 0x00,  0x0002,  0x00000000, -0x00000001, _("Would you like to save your adventure?") },
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_START_FUNC),
    { 0x3c, 0x0e,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SAVE_END_FUNC),
    JUMP_SCRIPT(END_TALK),
};

static const struct ScriptCommand s_script_WORLD_MAP_POINT[] = { /* 0x8121034 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(228, 1, 0),
    EXECUTE_SUBSTATION(12, 1, 1),
    HALT,
};

static const struct ScriptCommand s_script_FORMATION_HERO[] = { /* 0x8121074 */
    DEBUGINFO,
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 19, 2, /* to label */ 0),
    SCENARIO_CALC(SCENARIO_MAIN, 19,  2),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
  LABEL(0), /* = 0x00 */
    UPDATE_VARVAR(CALC_SET, GROUND_GETOUT, GROUND_ENTER),
    UPDATE_VARINT(CALC_SET, START_MODE, 2),
    EXECUTE_FUNCTION(EVENT_DIVIDE),
    HALT,
};

static const struct ScriptCommand s_script_EVOLUTION_HERO[] = { /* 0x8121124 */
    DEBUGINFO,
    EXECUTE_STATION(8, 1, 1),
    HALT,
};

static const struct ScriptCommand s_script_WARP_LIVES_START[] = { /* 0x8121154 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_START_FUNC),
    HALT,
};

static const struct ScriptCommand s_script_WARP_LIVES_START2[] = { /* 0x8121184 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_START2_FUNC),
    HALT,
};

static const struct ScriptCommand s_script_WARP_LIVES_START3[] = { /* 0x81211b4 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_START3_FUNC),
    HALT,
};

static const struct ScriptCommand s_script_WARP_LIVES_ARRIVE[] = { /* 0x81211e4 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_script_WARP_LIVES_ARRIVE2[] = { /* 0x8121214 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_script_WARP_LIVES_ARRIVE3[] = { /* 0x8121244 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE3_FUNC),
    RET,
};

static const struct ScriptCommand s_script_LIVES_WARP_START_FUNC[] = { /* 0x8121274 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    WAIT(6),
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000020,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x2000,  0x000000c0,  0x00000000, NULL },
    RET_DIRECT,
    { 0x68, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000020,  0x00000000, NULL },
    { 0x68, 0x00,  0x1800,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x2000,  0x000000c0,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_LIVES_WARP_START2_FUNC[] = { /* 0x81213c4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    WAIT(6),
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000020,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x2000,  0x000000c0,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LIVES_WARP_START3_FUNC[] = { /* 0x81214b4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    WAIT(6),
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000002,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000020,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x2000,  0x000000c0,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LIVES_WARP_START_SUB[] = { /* 0x81215a4 */
    DEBUGINFO,
    { 0x60, 0x00,  0x0000,  0x00000060,  0x00000000, NULL },
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_script_LIVES_WARP_ARRIVE_FUNC[] = { /* 0x81215f4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x000000c0,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(6),
    { 0x68, 0x00,  0x2000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000020,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x53, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    RET_DIRECT,
    { 0x68, 0x00,  0x4000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x2000,  0x00000020,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000004,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000002,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_LIVES_WARP_ARRIVE2_FUNC[] = { /* 0x81217a4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x00,  0x0000,  0x000000c0,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    WAIT(6),
    { 0x68, 0x00,  0x2000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000020,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LIVES_WARP_ARRIVE3_FUNC[] = { /* 0x81218d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x60, 0x28,  0x0000,  0x000000c0,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    WAIT(6),
    { 0x68, 0x00,  0x2000,  0x00000040,  0x00000000, NULL },
    { 0x68, 0x00,  0x1000,  0x00000020,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x68, 0x00,  0x0800,  0x00000010,  0x00000000, NULL },
    { 0x68, 0x00,  0x0400,  0x00000008,  0x00000000, NULL },
    { 0x68, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0x68, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    WAIT(10),
    { 0x54, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LIVES_WARP_ARRIVE_SUB[] = { /* 0x8121a04 */
    DEBUGINFO,
    { 0x60, 0x00,  0x0000,  0x00000060,  0x00000000, NULL },
    { 0x54, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0xdd, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_script_GET_ITEM_FUNC[] = { /* 0x8121a54 */
    DEBUGINFO,
    FANFARE_PLAY(203),
    { 0xe1, 0x00,  0x00cb,  0x00000000,  0x00000000, NULL },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_GET_ITEM_WAIT_FUNC[] = { /* 0x8121aa4 */
    DEBUGINFO,
    FANFARE_PLAY(203),
    { 0xe1, 0x00,  0x00cb,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_GET_ITEM2_FUNC[] = { /* 0x8121af4 */
    DEBUGINFO,
    FANFARE_PLAY(203),
    { 0xe1, 0x00,  0x00cb,  0x00000000,  0x00000000, NULL },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_GET_ITEM2_WAIT_FUNC[] = { /* 0x8121b44 */
    DEBUGINFO,
    FANFARE_PLAY(203),
    { 0xe1, 0x00,  0x00cb,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_JOIN_FUNC[] = { /* 0x8121b94 */
    DEBUGINFO,
    FANFARE_PLAY(204),
    { 0xe1, 0x00,  0x00cc,  0x00000000,  0x00000000, NULL },
    { 0x31, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LODGE_START_FUNC[] = { /* 0x8121be4 */
    DEBUGINFO,
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LODGE_WAIT_FUNC[] = { /* 0x8121c14 */
    DEBUGINFO,
    WAIT(60),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LODGE_END_FUNC[] = { /* 0x8121c44 */
    DEBUGINFO,
    WAIT(60),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_LODGE_SOUND_FUNC[] = { /* 0x8121c84 */
    DEBUGINFO,
    WAIT(60),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SAVE_START_FUNC[] = { /* 0x8121cb4 */
    DEBUGINFO,
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x43,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(50),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SAVE_WAIT_FUNC[] = { /* 0x8121d04 */
    DEBUGINFO,
    { 0xe0, 0x00,  0x0032,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x45,  0x001e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SAVE_END_FUNC[] = { /* 0x8121d44 */
    DEBUGINFO,
    { 0xe0, 0x00,  0x0032,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x45,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_SAVE_SOUND_FUNC[] = { /* 0x8121d94 */
    DEBUGINFO,
    { 0x3b, 0x43,  0x0000,  0x00000000,  0x00000000, NULL },
    BGM_SWITCH(50),
    { 0xe0, 0x00,  0x0032,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x45,  0x001e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EFFECT_TEST1[] = { /* 0x8121df4 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000019,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000001c,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000001d,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_script_EFFECT_TEST2[] = { /* 0x8121e74 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000008,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000009,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000000a,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000000b,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_script_EFFECT_MOVE_DIVE[] = { /* 0x8121f14 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_script_EFFECT_MOVE_WAVE[] = { /* 0x8121f54 */
    DEBUGINFO,
    { 0x56, 0x00,  0x0000,  0x000001b6,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_script_EVENT_DIVIDE[] = { /* 0x8121f94 */
    DEBUGINFO,
    CJUMP_SCENARIO_0(SCENARIO_SELECT),
    COND(JUDGE_EQ, 0, /* to label */ 0),
    COND(JUDGE_EQ, 57, /* to label */ 1),
    COND(JUDGE_EQ, 56, /* to label */ 2),
    COND(JUDGE_EQ, 30, /* to label */ 3),
    COND(JUDGE_EQ, 31, /* to label */ 4),
    COND(JUDGE_EQ, 33, /* to label */ 5),
    COND(JUDGE_EQ, 34, /* to label */ 6),
    COND(JUDGE_EQ, 36, /* to label */ 7),
    COND(JUDGE_EQ, 38, /* to label */ 8),
    COND(JUDGE_EQ, 39, /* to label */ 9),
    COND(JUDGE_EQ, 40, /* to label */ 10),
    COND(JUDGE_EQ, 41, /* to label */ 11),
    COND(JUDGE_EQ, 42, /* to label */ 12),
    COND(JUDGE_EQ, 44, /* to label */ 13),
    COND(JUDGE_EQ, 46, /* to label */ 14),
    COND(JUDGE_EQ, 47, /* to label */ 15),
    COND(JUDGE_EQ, 49, /* to label */ 16),
    COND(JUDGE_EQ, 51, /* to label */ 17),
    COND(JUDGE_EQ, 52, /* to label */ 18),
    COND(JUDGE_EQ, 53, /* to label */ 19),
    COND(JUDGE_EQ, 54, /* to label */ 20),
    COND(JUDGE_EQ, 58, /* to label */ 21),
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 0, /* to label */ 22),
    COND(JUDGE_EQ, 1, /* to label */ 22),
    COND(JUDGE_EQ, 58, /* to label */ 21),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_LE, 10, /* to label */ 24),
    COND(JUDGE_LE, 17, /* to label */ 25),
    COND(JUDGE_LE, 27, /* to label */ 26),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(22), /* = 0x16 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    SCENARIO_CALC(SCENARIO_MAIN,  1,  0),
    JUMP_SCRIPT(EVENT_M00E01A_L001),
  LABEL(24), /* = 0x18 */
    JUMP_SCRIPT(EVENT_DIVIDE_FIRST),
  LABEL(25), /* = 0x19 */
    JUMP_SCRIPT(EVENT_DIVIDE_SECOND),
  LABEL(26), /* = 0x1a */
    JUMP_SCRIPT(EVENT_DIVIDE_AFTER),
  LABEL(1), /* = 0x01 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_R00E01A_L001),
  LABEL(3), /* = 0x03 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S01E01B_L001L),
  LABEL(4), /* = 0x04 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S01E02A_L002L),
  LABEL(5), /* = 0x05 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S02E01A_L004L),
  LABEL(6), /* = 0x06 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S02E02A_L003L),
  LABEL(7), /* = 0x07 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S03E01A_L002L),
  LABEL(8), /* = 0x08 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S04E01A_L002L),
  LABEL(9), /* = 0x09 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S04E01B_L001L),
  LABEL(10), /* = 0x0a */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S04E01C_L001L),
  LABEL(11), /* = 0x0b */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S04E01D_L001L),
  LABEL(12), /* = 0x0c */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S04E01E_L001L),
  LABEL(13), /* = 0x0d */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S05E01A_L002L),
  LABEL(14), /* = 0x0e */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S06E01A_L002L),
  LABEL(15), /* = 0x0f */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S06E01B_L002L),
  LABEL(16), /* = 0x10 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S07E01A_L003L),
  LABEL(17), /* = 0x11 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S08E01A_L006L),
  LABEL(18), /* = 0x12 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S08E01A_L008L),
  LABEL(19), /* = 0x13 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S09E01A_L005L),
  LABEL(20), /* = 0x14 */
    SCENARIO_CALC(SCENARIO_SELECT,  0,  0),
    JUMP_SCRIPT(EVENT_S09E01B_L002L),
  LABEL(21), /* = 0x15 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 27),
    JUMP_LABEL(28),
  LABEL(27), /* = 0x1b */
    SCENARIO_CALC(SCENARIO_SELECT, 58,  1),
    SCENARIO_CALC(SCENARIO_MAIN, 58,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 0),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 0),
  LABEL(28), /* = 0x1c */
    EXECUTE_MAP_VAR(GROUND_ENTER),
};


static const struct ScriptCommand s_script_EVENT_DIVIDE_NEXT[] = { /* 0x81226e4 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 3, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_DIVIDE_INIT_FUNC[] = { /* 0x8122724 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("EVENT_DIVIDE_INIT_FUNC\n") },
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    CLEAR_ARRAY(WARP_LIST),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    SET_PLAYER_KIND(2),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    CLEAR_ARRAY(CLEAR_COUNT),
    { 0x3b, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_DIVIDE_NEXT_DAY_FUNC[] = { /* 0x812281c */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("EVENT_DIVIDE_NEXT_DAY_FUNC\n") },
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 15, 7, /* to label */ 0),
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 18, 4, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 31, 0, /* to label */ 3),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 2, /* to label */ 4),
  LABEL(3), /* = 0x03 */
    RET_DIRECT,
  LABEL(4), /* = 0x04 */
    EXECUTE_FUNCTION(EVENT_DIVIDE),
    HALT,
  LABEL(1), /* = 0x01 */
    SCENARIO_CALC(SCENARIO_MAIN, 19,  1),
  LABEL(2), /* = 0x02 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 2, /* to label */ 5),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 4, /* to label */ 6),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 6, /* to label */ 7),
    JUMP_LABEL(8),
  LABEL(5), /* = 0x05 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  3),
    JUMP_LABEL(8),
  LABEL(6), /* = 0x06 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  5),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  7),
    { 0xae, 0x01,  0x001c,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 2, /* to label */ 9),
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 4, /* to label */ 10),
    JUMP_LABEL(11),
  LABEL(9), /* = 0x09 */
    SCENARIO_CALC(SCENARIO_SUB9, 53,  3),
    JUMP_LABEL(11),
  LABEL(10), /* = 0x0a */
    SCENARIO_CALC(SCENARIO_SUB9, 53,  5),
    JUMP_LABEL(11),
  LABEL(11), /* = 0x0b */
    JUMPIF_SCENE_EQ(SCENARIO_SUB3, 36, 1, /* to label */ 12),
    JUMP_LABEL(13),
  LABEL(12), /* = 0x0c */
    EXECUTE_FUNCTION(EVENT_S03E01A_L001),
    HALT,
  LABEL(13), /* = 0x0d */
    JUMPIF_SCENE_EQ(SCENARIO_SUB5, 44, 1, /* to label */ 14),
    JUMP_LABEL(15),
  LABEL(14), /* = 0x0e */
    EXECUTE_FUNCTION(EVENT_S05E01A_L001),
    HALT,
  LABEL(15), /* = 0x0f */
    JUMPIF_SCENE_EQ(SCENARIO_SUB6, 46, 1, /* to label */ 16),
    JUMP_LABEL(17),
  LABEL(16), /* = 0x10 */
    EXECUTE_FUNCTION(EVENT_S06E01A_L001),
    HALT,
  LABEL(17), /* = 0x11 */
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_DIVIDE_NEXT_DAY2_FUNC[] = { /* 0x8122bf8 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0002,  0x00000000,  0x00000000, _("EVENT_DIVIDE_NEXT_DAY2_FUNC\n") },
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 15, 7, /* to label */ 0),
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 18, 4, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 31, 0, /* to label */ 3),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 2, /* to label */ 4),
  LABEL(3), /* = 0x03 */
    RET_DIRECT,
  LABEL(4), /* = 0x04 */
    EXECUTE_FUNCTION(EVENT_DIVIDE),
    HALT,
  LABEL(1), /* = 0x01 */
    SCENARIO_CALC(SCENARIO_MAIN, 19,  1),
  LABEL(2), /* = 0x02 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 2, /* to label */ 5),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 4, /* to label */ 6),
    JUMPIF_SCENE_EQ(SCENARIO_SUB8, 51, 6, /* to label */ 7),
    JUMP_LABEL(8),
  LABEL(5), /* = 0x05 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  3),
    JUMP_LABEL(8),
  LABEL(6), /* = 0x06 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  5),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  7),
    { 0xae, 0x01,  0x001c,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 2, /* to label */ 9),
    JUMPIF_SCENE_EQ(SCENARIO_SUB9, 53, 4, /* to label */ 10),
    JUMP_LABEL(11),
  LABEL(9), /* = 0x09 */
    SCENARIO_CALC(SCENARIO_SUB9, 53,  3),
    JUMP_LABEL(11),
  LABEL(10), /* = 0x0a */
    SCENARIO_CALC(SCENARIO_SUB9, 53,  5),
    JUMP_LABEL(11),
  LABEL(11), /* = 0x0b */
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_DIVIDE_FIRST[] = { /* 0x8122eb8 */
    DEBUGINFO,
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 2, /* to label */ 0),
    COND(JUDGE_EQ, 3, /* to label */ 1),
    COND(JUDGE_EQ, 4, /* to label */ 2),
    COND(JUDGE_EQ, 5, /* to label */ 3),
    COND(JUDGE_EQ, 6, /* to label */ 4),
    COND(JUDGE_EQ, 7, /* to label */ 5),
    COND(JUDGE_EQ, 8, /* to label */ 6),
    COND(JUDGE_EQ, 9, /* to label */ 7),
    COND(JUDGE_EQ, 10, /* to label */ 8),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(0), /* = 0x00 */
    CLEAR_ARRAY(WARP_LIST),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 9),
    COND_EQUAL(1, /* to label */ 10),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(9), /* = 0x09 */
    SCENARIO_CALC(SCENARIO_MAIN,  2,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 178),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 178),
  LABEL(10), /* = 0x0a */
    JUMP_SCRIPT(EVENT_M01E01A_L001),
  LABEL(1), /* = 0x01 */
    CLEAR_ARRAY(WARP_LIST),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 11),
    COND_EQUAL(1, /* to label */ 12),
    COND_EQUAL(3, /* to label */ 13),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(11), /* = 0x0b */
    SCENARIO_CALC(SCENARIO_MAIN,  3,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
  LABEL(12), /* = 0x0c */
    JUMP_SCRIPT(EVENT_M01E02A_L001),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(EVENT_M01E02A_L001C),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 14),
    COND_EQUAL(1, /* to label */ 15),
    COND_EQUAL(3, /* to label */ 16),
    COND_EQUAL(4, /* to label */ 17),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(14), /* = 0x0e */
    SCENARIO_CALC(SCENARIO_MAIN,  4,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
  LABEL(15), /* = 0x0f */
    JUMP_SCRIPT(EVENT_M01E02B_L001),
  LABEL(16), /* = 0x10 */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 3),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(17), /* = 0x11 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 2, /* to label */ 18),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(18), /* = 0x12 */
    JUMP_SCRIPT(EVENT_M01E02B_L004),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 20),
    COND_EQUAL(1, /* to label */ 21),
    COND(JUDGE_LE, 4, /* to label */ 22),
    COND_EQUAL(5, /* to label */ 23),
    COND(JUDGE_LE, 7, /* to label */ 24),
    COND(JUDGE_LE, 9, /* to label */ 25),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(20), /* = 0x14 */
    SCENARIO_CALC(SCENARIO_MAIN,  5,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 26),
    JUMP_SCRIPT(EVENT_M01E03A_L000),
  LABEL(21), /* = 0x15 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 26),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(26), /* = 0x1a */
    JUMP_SCRIPT(EVENT_M01E03A_L001),
  LABEL(22), /* = 0x16 */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 4),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(23), /* = 0x17 */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 3, /* to label */ 27),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(27), /* = 0x1b */
    JUMP_SCRIPT(EVENT_M01E03A_L004),
  LABEL(24), /* = 0x18 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 2, /* to label */ 28),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(28), /* = 0x1c */
    JUMP_SCRIPT(EVENT_M01E03A_L006),
  LABEL(25), /* = 0x19 */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(4), /* = 0x04 */
    CLEAR_ARRAY(WARP_LIST),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 29),
    COND_EQUAL(1, /* to label */ 30),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(29), /* = 0x1d */
    SCENARIO_CALC(SCENARIO_MAIN,  6,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 31),
    JUMP_SCRIPT(EVENT_M01E04A_L000),
  LABEL(30), /* = 0x1e */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 31),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(31), /* = 0x1f */
    JUMP_SCRIPT(EVENT_M01E04A_L001),
  LABEL(5), /* = 0x05 */
    CLEAR_ARRAY(WARP_LIST),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 32),
    COND_EQUAL(1, /* to label */ 33),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(32), /* = 0x20 */
    SCENARIO_CALC(SCENARIO_MAIN,  7,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 34),
    JUMP_SCRIPT(EVENT_M01E04B_L000),
  LABEL(33), /* = 0x21 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 34),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(34), /* = 0x22 */
    JUMP_SCRIPT(EVENT_M01E04B_L001),
  LABEL(6), /* = 0x06 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 35),
    COND_EQUAL(1, /* to label */ 36),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(35), /* = 0x23 */
    SCENARIO_CALC(SCENARIO_MAIN,  8,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 37),
    JUMP_SCRIPT(EVENT_M01E05A_L000),
  LABEL(36), /* = 0x24 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 37),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(37), /* = 0x25 */
    JUMP_SCRIPT(EVENT_M01E05A_L001),
  LABEL(7), /* = 0x07 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 38),
    COND_EQUAL(1, /* to label */ 39),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(38), /* = 0x26 */
    SCENARIO_CALC(SCENARIO_MAIN,  9,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 40),
    JUMP_SCRIPT(EVENT_M01E05B_L000),
  LABEL(39), /* = 0x27 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 0, /* to label */ 40),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(40), /* = 0x28 */
    JUMP_SCRIPT(EVENT_M01E05B_L001),
  LABEL(8), /* = 0x08 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 41),
    COND_EQUAL(1, /* to label */ 42),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(41), /* = 0x29 */
    SCENARIO_CALC(SCENARIO_MAIN, 10,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
  LABEL(42), /* = 0x2a */
    JUMP_SCRIPT(EVENT_M01E06A_L001),
};


static const struct ScriptCommand s_script_EVENT_DIVIDE_SECOND[] = { /* 0x8123a18 */
    DEBUGINFO,
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 11, /* to label */ 0),
    COND(JUDGE_EQ, 12, /* to label */ 1),
    COND(JUDGE_EQ, 13, /* to label */ 2),
    COND(JUDGE_EQ, 14, /* to label */ 3),
    COND(JUDGE_EQ, 15, /* to label */ 4),
    COND(JUDGE_EQ, 16, /* to label */ 5),
    COND(JUDGE_EQ, 17, /* to label */ 6),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 7),
    COND_EQUAL(1, /* to label */ 8),
    COND_EQUAL(2, /* to label */ 9),
    COND_EQUAL(3, /* to label */ 9),
    COND_EQUAL(4, /* to label */ 10),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(7), /* = 0x07 */
    SCENARIO_CALC(SCENARIO_MAIN, 11,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 9),
  LABEL(8), /* = 0x08 */
    JUMP_SCRIPT(EVENT_M01E07A_L001),
  LABEL(9), /* = 0x09 */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 5),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(10), /* = 0x0a */
    JUMP_SCRIPT(EVENT_M01E07A_L003),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 11),
    COND_EQUAL(1, /* to label */ 12),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(11), /* = 0x0b */
    SCENARIO_CALC(SCENARIO_MAIN, 12,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 195),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 195),
  LABEL(12), /* = 0x0c */
    JUMP_SCRIPT(EVENT_M01E07B_L001),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 13),
    COND_EQUAL(1, /* to label */ 14),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(13), /* = 0x0d */
    SCENARIO_CALC(SCENARIO_MAIN, 13,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 198),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 198),
  LABEL(14), /* = 0x0e */
    JUMP_SCRIPT(EVENT_M01E08A_L001),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 15),
    COND_EQUAL(1, /* to label */ 16),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(15), /* = 0x0f */
    SCENARIO_CALC(SCENARIO_MAIN, 14,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 201),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 201),
  LABEL(16), /* = 0x10 */
    JUMP_SCRIPT(EVENT_M01E08B_L001),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 17),
    COND_EQUAL(1, /* to label */ 18),
    COND_EQUAL(2, /* to label */ 19),
    COND_EQUAL(3, /* to label */ 20),
    COND_EQUAL(4, /* to label */ 19),
    COND_EQUAL(5, /* to label */ 21),
    COND_EQUAL(6, /* to label */ 19),
    COND_EQUAL(7, /* to label */ 22),
    COND_EQUAL(8, /* to label */ 19),
    COND_EQUAL(9, /* to label */ 23),
  LABEL(19), /* = 0x13 */
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(17), /* = 0x11 */
    SCENARIO_CALC(SCENARIO_MAIN, 15,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
  LABEL(18), /* = 0x12 */
    JUMP_SCRIPT(EVENT_M01E09A_L001),
  LABEL(20), /* = 0x14 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 3, /* to label */ 24),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(24), /* = 0x18 */
    JUMP_SCRIPT(EVENT_M01E09A_L003),
  LABEL(21), /* = 0x15 */
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 4, /* to label */ 25),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(25), /* = 0x19 */
    JUMP_SCRIPT(EVENT_M01E09A_L005),
  LABEL(22), /* = 0x16 */
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 31, 0, /* to label */ 19),
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 2, /* to label */ 26),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(26), /* = 0x1a */
    JUMP_SCRIPT(EVENT_M01E09A_L007),
  LABEL(23), /* = 0x17 */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 6),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 27),
    COND_EQUAL(1, /* to label */ 28),
    COND_EQUAL(2, /* to label */ 29),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(27), /* = 0x1b */
    SCENARIO_CALC(SCENARIO_MAIN, 16,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 1),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 1),
    SET_ARRAYVAL(WARP_LIST,  1,  1),
  LABEL(28), /* = 0x1c */
    JUMP_SCRIPT(EVENT_M01E10A_L001),
  LABEL(29), /* = 0x1d */
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 7),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(6), /* = 0x06 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 30),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(30), /* = 0x1e */
    SCENARIO_CALC(SCENARIO_MAIN, 17,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E01A_END),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 1),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 1),
    JUMP_SCRIPT(EVENT_M01END_L001),
};

static const struct ScriptCommand s_script_EVENT_DIVIDE_AFTER[] = { /* 0x8124268 */
    DEBUGINFO,
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 18, /* to label */ 0),
    COND(JUDGE_EQ, 19, /* to label */ 1),
    COND(JUDGE_EQ, 20, /* to label */ 2),
    COND(JUDGE_EQ, 21, /* to label */ 3),
    COND(JUDGE_EQ, 22, /* to label */ 4),
    COND(JUDGE_EQ, 23, /* to label */ 5),
    COND(JUDGE_EQ, 24, /* to label */ 6),
    COND(JUDGE_EQ, 25, /* to label */ 7),
    COND(JUDGE_EQ, 26, /* to label */ 8),
    COND(JUDGE_EQ, 27, /* to label */ 9),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 10),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(10), /* = 0x0a */
    SCENARIO_CALC(SCENARIO_MAIN, 18,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E01A_END),
    JUMP_SCRIPT(EVENT_M02E01A_L001),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 11),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(11), /* = 0x0b */
    SCENARIO_CALC(SCENARIO_MAIN, 19,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E01A_END),
    JUMP_SCRIPT(EVENT_M02E02A_L001),
  LABEL(2), /* = 0x02 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 12),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(12), /* = 0x0c */
    SCENARIO_CALC(SCENARIO_MAIN, 20,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E01A_END),
    JUMP_SCRIPT(EVENT_M02E02B_L001),
  LABEL(3), /* = 0x03 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 13),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(13), /* = 0x0d */
    SCENARIO_CALC(SCENARIO_MAIN, 21,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E01A_END),
    CALL_SCRIPT(EVENT_S04E01A_START),
    JUMP_SCRIPT(EVENT_M02E02C_L001),
  LABEL(4), /* = 0x04 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 14),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(14), /* = 0x0e */
    SCENARIO_CALC(SCENARIO_MAIN, 22,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E01A_END),
    CALL_SCRIPT(EVENT_S04E01A_LAST),
    CALL_SCRIPT(EVENT_S05E01A_START),
    JUMP_SCRIPT(EVENT_M02E02D_L001),
  LABEL(5), /* = 0x05 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 15),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(15), /* = 0x0f */
    SCENARIO_CALC(SCENARIO_MAIN, 23,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E01A_END),
    CALL_SCRIPT(EVENT_S04E01A_LAST),
    CALL_SCRIPT(EVENT_S05E01A_CONTINUE),
    CALL_SCRIPT(EVENT_S06E01A_START),
    JUMP_SCRIPT(EVENT_M02E02E_L001),
  LABEL(6), /* = 0x06 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 16),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(16), /* = 0x10 */
    SCENARIO_CALC(SCENARIO_MAIN, 24,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E02A_START),
    CALL_SCRIPT(EVENT_S04E01A_END),
    CALL_SCRIPT(EVENT_S05E01A_CONTINUE),
    CALL_SCRIPT(EVENT_S06E01A_END),
    CALL_SCRIPT(EVENT_S08E01A_START),
    JUMP_SCRIPT(EVENT_M02E02F_L001),
  LABEL(7), /* = 0x07 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 17),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(17), /* = 0x11 */
    SCENARIO_CALC(SCENARIO_MAIN, 25,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E02A_END),
    CALL_SCRIPT(EVENT_S04E01A_END),
    CALL_SCRIPT(EVENT_S05E01A_CONTINUE),
    CALL_SCRIPT(EVENT_S06E01A_END),
    CALL_SCRIPT(EVENT_S08E01A_START),
    CALL_SCRIPT(EVENT_S03E01A_START),
    JUMP_SCRIPT(EVENT_M02E02G_L001),
  LABEL(8), /* = 0x08 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 18),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(18), /* = 0x12 */
    SCENARIO_CALC(SCENARIO_MAIN, 26,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_START),
    CALL_SCRIPT(EVENT_S02E02A_END),
    CALL_SCRIPT(EVENT_S04E01A_END),
    CALL_SCRIPT(EVENT_S05E01A_CONTINUE),
    CALL_SCRIPT(EVENT_S06E01A_END),
    CALL_SCRIPT(EVENT_S08E01A_END),
    CALL_SCRIPT(EVENT_S03E01A_CONTINUE),
    CALL_SCRIPT(EVENT_S09E01A_START),
    JUMP_SCRIPT(EVENT_M02E02H_L001),
  LABEL(9), /* = 0x09 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND_EQUAL(0, /* to label */ 19),
    EXECUTE_MAP_VAR(GROUND_ENTER),
  LABEL(19), /* = 0x13 */
    SCENARIO_CALC(SCENARIO_MAIN, 27,  1),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    CALL_SCRIPT(EVENT_S01E02A_END),
    CALL_SCRIPT(EVENT_S02E02A_END),
    CALL_SCRIPT(EVENT_S04E01A_END),
    CALL_SCRIPT(EVENT_S05E01A_END),
    CALL_SCRIPT(EVENT_S06E01A_END),
    CALL_SCRIPT(EVENT_S07E01A_END),
    CALL_SCRIPT(EVENT_S08E01A_END),
    CALL_SCRIPT(EVENT_S03E01A_END),
    CALL_SCRIPT(EVENT_S09E01A_END),
    { 0xb0, 0x01,  0x001f,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0020,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0021,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0022,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0023,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0024,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0025,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0027,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0028,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0029,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(EVENT_M02END_L001),
};

static const struct ScriptCommand s_script_EVENT_DIVIDE_WARP_LOCK_FUNC[] = { /* 0x8124bb8 */
    DEBUGINFO,
    CJUMP_VAR(WARP_LOCK),
    COND_EQUAL(3, /* to label */ 0),
    COND_EQUAL(4, /* to label */ 1),
    COND_EQUAL(5, /* to label */ 2),
    COND_EQUAL(6, /* to label */ 3),
    COND_EQUAL(7, /* to label */ 3),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh?\nAre you going home already?")),
    VARIANT(/* == */  1, _(" We haven't gone to the\n#C5Pelipper Post Office#R yet?")),
    VARIANT(/* == */  1, _(" You can go home after we\ngo to the #C5Pelipper Post Office#R.")),
    VARIANT_DEFAULT(_(" Huh?\nYou want to go home already?")),
    VARIANT_DEFAULT(_(" We're already here.\nLet me show you around a bit more.")),
    VARIANT_DEFAULT(_(" Let's go to the #C5Pelipper\nPost Office#R at least.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
  LABEL(1), /* = 0x01 */
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nYou want to go home already?") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nAre you ready to leave?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
  LABEL(2), /* = 0x02 */
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nAre you ready to leave?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
  LABEL(3), /* = 0x03 */
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nAre you ready to leave?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Huh?\nAre you ready to leave?") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};



static const struct ScriptCommand s_script_EVENT_RESCUE_ENTER_CHECK[] = { /* 0x8124f80 */
    DEBUGINFO,
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x07, 0x00,  0x001e, -0x00000001,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_RESCUE[] = { /* 0x8124fc0 */
    DEBUGINFO,
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    RESCUE_SELECT,
    RET,
};

static const struct ScriptCommand s_script_DEBUG_SCRIPT[] = { /* 0x8125000 */
    DEBUGINFO,
    { 0x3c, 0x2a,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 0),
    HALT,
  LABEL(0), /* = 0x00 */
    { 0x3b, 0x41,  0x003c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_DEMO_CANCEL[] = { /* 0x8125070 */
    DEBUGINFO,
    HALT,
};

static const struct ScriptCommand s_script_DEMO_01[] = { /* 0x8125090 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(227, 1, 0),
    { 0x3b, 0x41,  0x003c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_DEMO_02[] = { /* 0x81250d0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(226, 1, 0),
    { 0x3b, 0x41,  0x003c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_DEMO_03[] = { /* 0x8125110 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(5, 5, 0),
    EXECUTE_SUBSTATION(4, 29, 0),
    EXECUTE_SUBSTATION(225, 1, 0),
    EXECUTE_SUBSTATION(224, 3, 0),
    { 0x3b, 0x41,  0x003c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_DEMO_04[] = { /* 0x8125180 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(224, 4, 0),
    { 0x3b, 0x41,  0x003c,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_EVENT_M00E01A_L001[] = { /* 0x81251c0 */
    DEBUGINFO,
    BGM_STOP,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(223, 1, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  2,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E01A_L001[] = { /* 0x8125230 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(178, 1, 0),
    { 0xaf, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E01A_L002[] = { /* 0x8125270 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(178, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E01A_L003[] = { /* 0x81252a0 */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0004,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(179, 1, 0),
    EXECUTE_SUBSTATION(178, 3, 0),
    EXECUTE_SUBSTATION(9, 17, 0),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(224, 2, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  3,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L001[] = { /* 0x8125350 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 15, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  3,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L001B[] = { /* 0x8125390 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN,  3,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L001C[] = { /* 0x81253c0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 17, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  3,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L002[] = { /* 0x8125400 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 18, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  3,  5),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L003[] = { /* 0x8125440 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(180, 1, 0),
    { 0xaf, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  3,  6),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L004[] = { /* 0x8125490 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 18, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L005[] = { /* 0x81254c0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(180, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02A_L006[] = { /* 0x81254f0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(181, 1, 0),
    EXECUTE_SUBSTATION(180, 3, 0),
    EXECUTE_SUBSTATION(9, 23, 0),
    { 0xb0, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  4,  0),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L001[] = { /* 0x8125580 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(162, 1, 0),
    EXECUTE_SUBSTATION(12, 19, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  4,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L002[] = { /* 0x81255e0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(1, 6, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  4,  3),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L003[] = { /* 0x8125630 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(4, 12, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  4,  4),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L004[] = { /* 0x8125680 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(162, 2, 0),
    EXECUTE_SUBSTATION(12, 20, 0),
    { 0xaf, 0x01,  0x0002,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  4,  5),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L004B[] = { /* 0x81256f0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 26, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  4,  6),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L005[] = { /* 0x8125730 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(182, 1, 0),
    { 0x02, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L006[] = { /* 0x8125770 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 21, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L007[] = { /* 0x81257a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(182, 2, 0),
    { 0x02, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E02B_L008[] = { /* 0x81257e0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(183, 1, 0),
    EXECUTE_SUBSTATION(9, 28, 0),
    { 0xb0, 0x01,  0x0002,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  5,  0),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L000[] = { /* 0x8125860 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 3, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L001[] = { /* 0x81258a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(162, 3, 0),
    EXECUTE_SUBSTATION(12, 22, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L002[] = { /* 0x8125900 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 29, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  3),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 4),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x01, 0x00, -0x0001,  0x00000001,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L003[] = { /* 0x81259b0 */
    DEBUGINFO,
    JUMPIF_EQUAL(SCRIPT_MODE, 1, /* to label */ 0),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    { 0x3b, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_GE, CLEAR_COUNT, 3, /* to label */ 0),
    EXECUTE_SUBSTATION(12, 3, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  5),
    RET,
  LABEL(0), /* = 0x00 */
    JUMP_SCRIPT(EVENT_M01E03A_L004),
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L004[] = { /* 0x8125a50 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 23, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  6),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L005[] = { /* 0x8125aa0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 30, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  7),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L006[] = { /* 0x8125af0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 24, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  5,  8),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L007[] = { /* 0x8125b30 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 31, 0),
    { 0xaf, 0x01,  0x0003,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  5,  9),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L008[] = { /* 0x8125b80 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(184, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L009[] = { /* 0x8125bb0 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    EXECUTE_SUBSTATION(12, 25, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L010[] = { /* 0x8125bf0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(184, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E03A_L011[] = { /* 0x8125c20 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(185, 1, 0),
    EXECUTE_SUBSTATION(9, 34, 0),
    { 0xb0, 0x01,  0x0003,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  6,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L000[] = { /* 0x8125cb0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 3, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  6,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L001[] = { /* 0x8125cf0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 26, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  6,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L002[] = { /* 0x8125d30 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 35, 0),
    { 0x3b, 0x3b,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(1, 12, 0),
    EXECUTE_SUBSTATION(9, 36, 0),
    { 0xaf, 0x01,  0x0004,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  6,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L003[] = { /* 0x8125db0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(186, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L004[] = { /* 0x8125de0 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    EXECUTE_SUBSTATION(12, 27, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L005[] = { /* 0x8125e20 */
    DEBUGINFO,
    { 0x02, 0x00,  0x001e,  0x00000006,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04A_L006[] = { /* 0x8125e50 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(187, 1, 0),
    EXECUTE_SUBSTATION(9, 39, 0),
    { 0xb0, 0x01,  0x0004,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  7,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L000[] = { /* 0x8125ee0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 3, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  7,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L001[] = { /* 0x8125f20 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 28, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  7,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L002[] = { /* 0x8125f60 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 40, 0),
    { 0xaf, 0x01,  0x0005,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  7,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L003[] = { /* 0x8125fb0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(188, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L004[] = { /* 0x8125fe0 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    EXECUTE_SUBSTATION(12, 29, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L005[] = { /* 0x8126020 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(188, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L006[] = { /* 0x8126050 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(189, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E04B_L007[] = { /* 0x8126080 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(190, 1, 0),
    { 0xb0, 0x01,  0x0005,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  8,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L000[] = { /* 0x8126100 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 3, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  8,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L001[] = { /* 0x8126140 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 30, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  8,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L002[] = { /* 0x8126180 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 43, 0),
    { 0xaf, 0x01,  0x0006,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  8,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L003[] = { /* 0x81261d0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(191, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L004[] = { /* 0x8126200 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    EXECUTE_SUBSTATION(12, 31, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L005[] = { /* 0x8126240 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(191, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05A_L006[] = { /* 0x8126270 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(192, 2, 0),
    { 0xb0, 0x01,  0x0006,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN,  9,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E05B_L000[] = { /* 0x81262f0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 3, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  9,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05B_L001[] = { /* 0x8126330 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 32, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  9,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05B_L002[] = { /* 0x8126370 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 45, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  9,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05B_L003[] = { /* 0x81263b0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN,  9,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05B_L004[] = { /* 0x81263e0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(2, 17, 0),
    SCENARIO_CALC(SCENARIO_MAIN,  9,  5),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E05B_L005[] = { /* 0x8126420 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 46, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 10,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E06A_L001[] = { /* 0x8126460 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(162, 4, 0),
    EXECUTE_SUBSTATION(12, 33, 0),
    { 0x3b, 0x3b,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(2, 18, 0),
    EXECUTE_SUBSTATION(12, 34, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 10,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E06A_L002[] = { /* 0x81264f0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 47, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 10,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E06A_L003[] = { /* 0x8126530 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(1, 20, 0),
    EXECUTE_SUBSTATION(1, 21, 0),
    EXECUTE_SUBSTATION(9, 48, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 11,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E07A_L001[] = { /* 0x8126590 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 49, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 11,  2),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 5),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07A_L002[] = { /* 0x81265e0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 11,  4),
    EXECUTE_SUBSTATION(9, 51, 0),
    EXECUTE_SUBSTATION(9, 52, 0),
    EXECUTE_SUBSTATION(9, 53, 0),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(164, 1, 0),
    EXECUTE_SUBSTATION(165, 1, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    { 0x3b, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E07A_L003[] = { /* 0x81266a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(193, 1, 0),
    { 0xaf, 0x01,  0x0007,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07A_L004[] = { /* 0x81266e0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(193, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07A_L005[] = { /* 0x8126710 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(194, 1, 0),
    EXECUTE_SUBSTATION(166, 1, 0),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(167, 1, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(166, 2, 0),
    { 0xb0, 0x01,  0x0007,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 12,  0),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 24),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E07A_T001[] = { /* 0x81267d0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(193, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07A_T002[] = { /* 0x8126800 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(193, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07B_L001[] = { /* 0x8126830 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(195, 1, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 12,  2),
    JUMP_SCRIPT(EVENT_M01E07B_L002),
};

static const struct ScriptCommand s_script_EVENT_M01E07B_L002[] = { /* 0x8126870 */
    DEBUGINFO,
    { 0xaf, 0x01,  0x0008,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07B_L003[] = { /* 0x81268a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(195, 3, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07B_L004[] = { /* 0x81268d0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(196, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07B_L005[] = { /* 0x8126900 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(197, 1, 0),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(167, 2, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0008,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 13,  0),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 26),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E07B_T001[] = { /* 0x81269a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(195, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E07B_T002[] = { /* 0x81269d0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(195, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08A_L001[] = { /* 0x8126a00 */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(168, 1, 0),
    EXECUTE_SUBSTATION(168, 2, 0),
    EXECUTE_SUBSTATION(169, 1, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 13,  2),
    JUMP_SCRIPT(EVENT_M01E08A_L002),
};

static const struct ScriptCommand s_script_EVENT_M01E08A_L002[] = { /* 0x8126a80 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(198, 1, 0),
    { 0xaf, 0x01,  0x0009,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08A_L003[] = { /* 0x8126ac0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(198, 3, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08A_L004[] = { /* 0x8126af0 */
    DEBUGINFO,
    JUMPIF_UNK_BC(8, /* to label */ 0),
    EXECUTE_SUBSTATION(199, 1, 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    EXECUTE_SUBSTATION(199, 2, 0),
  LABEL(1), /* = 0x01 */
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08A_L005[] = { /* 0x8126b70 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(200, 1, 0),
    { 0xb0, 0x01,  0x0009,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 14,  0),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 28),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E08A_T001[] = { /* 0x8126be0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(198, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08A_T002[] = { /* 0x8126c10 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(198, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08B_L001[] = { /* 0x8126c40 */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(170, 1, 0),
    EXECUTE_SUBSTATION(162, 5, 0),
    EXECUTE_SUBSTATION(170, 2, 0),
    { 0x3b, 0x39,  0x0000,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 14,  2),
    JUMP_SCRIPT(EVENT_M01E08B_L002),
};

static const struct ScriptCommand s_script_EVENT_M01E08B_L002[] = { /* 0x8126cc0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(201, 1, 0),
    { 0xaf, 0x01,  0x000a,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08B_L003[] = { /* 0x8126d00 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(201, 3, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08B_L004[] = { /* 0x8126d30 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(203, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08B_L005[] = { /* 0x8126d60 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(202, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08B_L006[] = { /* 0x8126d90 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(203, 2, 0),
    EXECUTE_SUBSTATION(203, 3, 0),
    { 0xb0, 0x01,  0x000a,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 15,  0),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 2),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E08B_T001[] = { /* 0x8126e10 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(201, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E08B_T002[] = { /* 0x8126e40 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(201, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L001[] = { /* 0x8126e70 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(1, 23, 0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    EXECUTE_SUBSTATION(12, 35, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L002[] = { /* 0x8126ed0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 55, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L003[] = { /* 0x8126f10 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(162, 6, 0),
    EXECUTE_SUBSTATION(12, 36, 0),
    EXECUTE_SUBSTATION(162, 7, 0),
    EXECUTE_SUBSTATION(12, 37, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L004[] = { /* 0x8126f90 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 57, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  5),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L005[] = { /* 0x8126fd0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 38, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  6),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L006[] = { /* 0x8127010 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 58, 0),
    EXECUTE_SUBSTATION(1, 26, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  7),
    EXECUTE_SUBSTATION(9, 59, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L007[] = { /* 0x8127070 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 39, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  8),
    JUMP_SCRIPT(EVENT_M01E09A_L008),
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L008[] = { /* 0x81270b0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(1, 28, 0),
    EXECUTE_SUBSTATION(9, 60, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  9),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 6),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L009[] = { /* 0x8127110 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(162, 8, 0),
    { 0x3b, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(12, 40, 0),
    { 0xaf, 0x01,  0x000b,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 15, 10),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L010[] = { /* 0x81271a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 62, 0),
    { 0xaf, 0x01,  0x000b,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 15, 11),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L011[] = { /* 0x81271f0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(204, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L012[] = { /* 0x8127220 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    EXECUTE_SUBSTATION(12, 41, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L013[] = { /* 0x8127260 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(204, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L014[] = { /* 0x8127290 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(205, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E09A_L015[] = { /* 0x81272c0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(206, 1, 0),
    { 0xb0, 0x01,  0x000b,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 16,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 2),
    CALL_SCRIPT(NEXT_SAVE_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L001[] = { /* 0x8127340 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 16,  1),
    EXECUTE_SUBSTATION(1, 31, 0),
    EXECUTE_SUBSTATION(171, 1, 0),
    EXECUTE_SUBSTATION(173, 1, 0),
    EXECUTE_SUBSTATION(171, 2, 0),
    EXECUTE_SUBSTATION(1, 32, 0),
    EXECUTE_SUBSTATION(1, 33, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 16,  2),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 7),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L002[] = { /* 0x81273f0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 16,  3),
    EXECUTE_SUBSTATION(12, 2, 0),
    EXECUTE_SUBSTATION(163, 1, 0),
    EXECUTE_SUBSTATION(12, 42, 0),
    EXECUTE_SUBSTATION(163, 2, 0),
    EXECUTE_SUBSTATION(162, 9, 0),
    { 0x3b, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(12, 43, 0),
    { 0xaf, 0x01,  0x000c,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L003[] = { /* 0x81274b0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 65, 0),
    { 0xaf, 0x01,  0x000c,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 16,  4),
    UPDATE_VARINT(CALC_SET, WARP_LOCK, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L004[] = { /* 0x8127510 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(171, 3, 0),
    EXECUTE_SUBSTATION(162, 10, 0),
    EXECUTE_SUBSTATION(171, 4, 0),
    EXECUTE_SUBSTATION(207, 1, 0),
    EXECUTE_SUBSTATION(172, 1, 0),
    EXECUTE_SUBSTATION(207, 2, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L005[] = { /* 0x8127590 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    EXECUTE_SUBSTATION(12, 44, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L006[] = { /* 0x81275d0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(207, 3, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L007[] = { /* 0x8127600 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(208, 1, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M01E10A_L008[] = { /* 0x8127630 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(209, 1, 0),
    EXECUTE_SUBSTATION(173, 2, 0),
    EXECUTE_SUBSTATION(209, 2, 0),
    EXECUTE_SUBSTATION(173, 3, 0),
    EXECUTE_SUBSTATION(209, 3, 0),
    { 0xb0, 0x01,  0x000c,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_MAIN, 17,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_M01END_L001[] = { /* 0x81276c0 */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(174, 1, 0),
    EXECUTE_SUBSTATION(171, 5, 0),
    EXECUTE_SUBSTATION(1, 37, 0),
    EXECUTE_SUBSTATION(2, 28, 0),
    EXECUTE_SUBSTATION(4, 27, 0),
    EXECUTE_SUBSTATION(171, 6, 0),
    EXECUTE_SUBSTATION(171, 7, 0),
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(175, 1, 0),
    EXECUTE_SUBSTATION(176, 1, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 18,  0),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    EXECUTE_SUBSTATION(175, 2, 0),
    EXECUTE_SUBSTATION(9, 68, 0),
    EXECUTE_SUBSTATION(177, 1, 0),
    { 0x3b, 0x42,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_EVENT_M01END_L002[] = { /* 0x81277f0 */
    DEBUGINFO,
    { 0x3b, 0x39,  0x0001,  0x00000000,  0x00000000, NULL },
    EXECUTE_SUBSTATION(175, 1, 0),
    EXECUTE_SUBSTATION(176, 1, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 18,  0),
    CALL_SCRIPT(EVENT_DIVIDE_INIT_FUNC),
    EXECUTE_SUBSTATION(175, 2, 0),
    EXECUTE_SUBSTATION(9, 68, 0),
    EXECUTE_SUBSTATION(177, 1, 0),
    { 0x3b, 0x42,  0x0000,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_script_EVENT_M02E01A_L001[] = { /* 0x81278a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 45, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 18,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E01A_L002[] = { /* 0x81278e0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 69, 0),
    EXECUTE_SUBSTATION(2, 29, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 18,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E01A_L003[] = { /* 0x8127930 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 72, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 18,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02A_L001[] = { /* 0x8127970 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 19,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02B_L001[] = { /* 0x81279c0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 20,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02C_L001[] = { /* 0x8127a10 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 21,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02D_L001[] = { /* 0x8127a60 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 22,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02E_L001[] = { /* 0x8127ab0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 23,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02F_L001[] = { /* 0x8127b00 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 24,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02G_L001[] = { /* 0x8127b50 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 25,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02E02H_L001[] = { /* 0x8127ba0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_MAIN, 26,  2),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 6, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_M02END_L001[] = { /* 0x8127bf0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 6, 0),
    SCENARIO_CALC(SCENARIO_MAIN, 27,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S00E01A_L001[] = { /* 0x8127c30 */
    DEBUGINFO,
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER3_FUNC),
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 7, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S00E01A_L002[] = { /* 0x8127c80 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 6, 0),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    SCENARIO_CALC(SCENARIO_SELECT, 57,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S00E01A_L003[] = { /* 0x8127cf0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S00E01A_L004[] = { /* 0x8127d20 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E01A_START[] = { /* 0x8127d50 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 29, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB1, 29,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S01E01A_CONTINUE[] = { /* 0x8127db0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 29, 2, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB1, 29,  2),
    { 0xae, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S01E01A_END[] = { /* 0x8127e20 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 31, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB1, 31,  0),
    { 0xb0, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 2),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S01E01A_L001[] = { /* 0x8127ea0 */
    DEBUGINFO,
    { 0xae, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB1, 29,  2),
    RET,
    SCENARIO_CALC(SCENARIO_MAIN, 15,  5),
    SCENARIO_CALC(SCENARIO_SUB1, 29,  1),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 9),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 2),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    EXECUTE_MAP_VAR(GROUND_ENTER),
};


static const struct ScriptCommand s_script_EVENT_S01E01A_L002[] = { /* 0x8127f60 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(4, 3, 0),
    { 0xaf, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB1, 29,  3),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 4),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 4),
    EXECUTE_SUBSTATION(4, 0, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E01A_L003[] = { /* 0x8127ff0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 75, 0),
    { 0xb0, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(EVENT_S01E01B_L001),
};

static const struct ScriptCommand s_script_EVENT_S01E01B_L001[] = { /* 0x8128030 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 1),
    EXECUTE_SUBSTATION(9, 76, 0),
    SCENARIO_CALC(SCENARIO_SUB1, 30,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 30,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S01E01B_L001L[] = { /* 0x81280c0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E01C_L001[] = { /* 0x81280f0 */
    DEBUGINFO,
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 2),
    EXECUTE_SUBSTATION(9, 78, 0),
    SCENARIO_CALC(SCENARIO_SUB1, 31,  0),
    { 0x3b, 0x03,  0x0000,  0x00000000,  0x00000000, NULL },
    EXECUTE_FUNCTION(EVENT_DIVIDE_NEXT),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E02A_START[] = { /* 0x8128160 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 31, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB1, 31,  1),
    { 0xae, 0x01,  0x000f,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xad, 0x01,  0x0076,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 2),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S01E02A_END[] = { /* 0x8128200 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB1, 32, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB1, 32,  2),
    { 0xb0, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x000f,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, BASE_LEVEL, 2),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S01E02A_L001[] = { /* 0x8128290 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(4, 5, 0),
    { 0xaf, 0x01,  0x000f,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB1, 31,  2),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 4),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 4),
    EXECUTE_SUBSTATION(4, 0, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E02A_L002[] = { /* 0x8128320 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB1, 32,  0),
    EXECUTE_SUBSTATION(9, 79, 0),
    { 0xb0, 0x01,  0x000f,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 31,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S01E02A_L002L[] = { /* 0x81283b0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY2_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E02B_L001[] = { /* 0x81283f0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB1, 32,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S01E02B_L002[] = { /* 0x8128420 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB1, 32,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E01A_START[] = { /* 0x8128450 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB2, 33, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB2, 33,  1),
    { 0xb0, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S02E01A_END[] = { /* 0x81284c0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB2, 34, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB2, 34,  0),
    { 0xb0, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S02E01A_L001[] = { /* 0x8128530 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB2, 33,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E01A_L002[] = { /* 0x8128560 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB2, 33,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E01A_L003[] = { /* 0x8128590 */
    DEBUGINFO,
    { 0xaf, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB2, 33,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E01A_L004[] = { /* 0x81285d0 */
    DEBUGINFO,
    { 0xb0, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB2, 34,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 33,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S02E01A_L004L[] = { /* 0x8128650 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E02A_START[] = { /* 0x8128690 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB2, 34, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB2, 34,  1),
    { 0x3b, 0x20,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S02E02A_END[] = { /* 0x8128710 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB2, 35, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB2, 35,  0),
    { 0xb0, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0011,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S02E02A_L001[] = { /* 0x8128790 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB2, 34,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E02A_L002[] = { /* 0x81287c0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(158, 2, 0),
    { 0xaf, 0x01,  0x0011,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB2, 34,  3),
    EXECUTE_SUBSTATION(12, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S02E02A_L003[] = { /* 0x8128820 */
    DEBUGINFO,
    { 0xb0, 0x01,  0x0011,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB2, 35,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 34,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S02E02A_L003L[] = { /* 0x81288a0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S03E01A_START[] = { /* 0x81288e0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB3, 36, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB3, 36,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S03E01A_CONTINUE[] = { /* 0x8128940 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB3, 36, 2, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB3, 36,  2),
    { 0xaf, 0x01,  0x0012,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S03E01A_END[] = { /* 0x81289b0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB3, 37, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB3, 37,  0),
    { 0xb0, 0x01,  0x0012,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S03E01A_L001[] = { /* 0x8128a20 */
    DEBUGINFO,
    { 0xaf, 0x01,  0x0012,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB3, 36,  2),
    EXECUTE_SUBSTATION(9, 81, 0),
    EXECUTE_SUBSTATION(12, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S03E01A_L002[] = { /* 0x8128a80 */
    DEBUGINFO,
    { 0xb0, 0x01,  0x0012,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB3, 37,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 36,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S03E01A_L002L[] = { /* 0x8128b00 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S04E01A_START[] = { /* 0x8128b40 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB4, 38, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB4, 38,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S04E01A_LAST[] = { /* 0x8128ba0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB4, 43, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB4, 43,  0),
    { 0xaf, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0015,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0017,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S04E01A_END[] = { /* 0x8128c50 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB4, 43, 2, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB4, 43,  2),
    { 0xaf, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0015,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x0017,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S04E01A_L001[] = { /* 0x8128d00 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 82, 0),
    EXECUTE_SUBSTATION(12, 9, 0),
    { 0xaf, 0x01,  0x0013,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 38,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S04E01A_L002[] = { /* 0x8128d60 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(192, 1, 0),
    { 0xaf, 0x00,  0x0013,  0x00000000,  0x00000000, NULL },
    { 0xaf, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 39,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 38,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01A_L002L[] = { /* 0x8128e00 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01B_L001[] = { /* 0x8128e30 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(212, 1, 0),
    { 0xb0, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    { 0xaf, 0x01,  0x0015,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 40,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 39,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01B_L001L[] = { /* 0x8128ed0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01C_L001[] = { /* 0x8128f00 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(213, 1, 0),
    { 0xb0, 0x01,  0x0015,  0x00000000,  0x00000000, NULL },
    { 0xaf, 0x01,  0x0016,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 41,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 40,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01C_L001L[] = { /* 0x8128fa0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01D_L001[] = { /* 0x8128fd0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(214, 1, 0),
    { 0xb0, 0x01,  0x0016,  0x00000000,  0x00000000, NULL },
    { 0xaf, 0x01,  0x0017,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 42,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 41,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01D_L001L[] = { /* 0x8129070 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01E_L001[] = { /* 0x81290a0 */
    DEBUGINFO,
    { 0xb0, 0x01,  0x0017,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB4, 43,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 42,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01E_L001L[] = { /* 0x8129120 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S04E01F_L001[] = { /* 0x8129150 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB4, 43,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S05E01A_START[] = { /* 0x8129180 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB5, 44, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB5, 44,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S05E01A_CONTINUE[] = { /* 0x81291e0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB5, 44, 2, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB5, 44,  2),
    { 0xaf, 0x01,  0x0018,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S05E01A_END[] = { /* 0x8129250 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB5, 45, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB5, 45,  0),
    { 0xb0, 0x01,  0x0018,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S05E01A_L001[] = { /* 0x81292c0 */
    DEBUGINFO,
    { 0xaf, 0x01,  0x0018,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB5, 44,  2),
    EXECUTE_SUBSTATION(216, 1, 0),
    EXECUTE_SUBSTATION(1, 46, 0),
    EXECUTE_SUBSTATION(12, 4, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S05E01A_L002[] = { /* 0x8129330 */
    DEBUGINFO,
    { 0xb0, 0x01,  0x0018,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB5, 45,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 44,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S05E01A_L002L[] = { /* 0x81293b0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S06E01A_START[] = { /* 0x81293e0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB6, 46, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB6, 46,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S06E01A_CONTINUE[] = { /* 0x8129440 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB6, 46, 2, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB6, 46,  2),
    { 0xaf, 0x01,  0x0019,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S06E01A_END[] = { /* 0x81294b0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB6, 48, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB6, 48,  0),
    { 0xb0, 0x01,  0x0019,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x001a,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x24,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x25,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x26,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x27,  0x0000,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S06E01A_L001[] = { /* 0x8129570 */
    DEBUGINFO,
    { 0xaf, 0x01,  0x0019,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB6, 46,  2),
    EXECUTE_SUBSTATION(12, 10, 0),
    EXECUTE_SUBSTATION(9, 83, 0),
    EXECUTE_SUBSTATION(12, 11, 0),
    EXECUTE_SUBSTATION(1, 47, 0),
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S06E01A_L002[] = { /* 0x8129600 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(217, 1, 0),
    { 0xb0, 0x01,  0x0019,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB6, 47,  2),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 2),
    SCENARIO_CALC(SCENARIO_SELECT, 46,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S06E01A_L002L[] = { /* 0x8129680 */
    DEBUGINFO,
    JUMP_SCRIPT(EVENT_S06E01B_L001),
};

static const struct ScriptCommand s_script_EVENT_S06E01B_L001[] = { /* 0x81296a0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(1, 48, 0),
    { 0xaf, 0x01,  0x001a,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB6, 47,  2),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S06E01B_L002[] = { /* 0x8129710 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(218, 1, 0),
    EXECUTE_SUBSTATION(1, 49, 0),
    { 0xb0, 0x01,  0x001a,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB6, 48,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 47,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S06E01B_L002L[] = { /* 0x81297b0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S07E01A_START[] = { /* 0x81297f0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 49, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB7, 49,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S07E01A_END[] = { /* 0x8129850 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB7, 50, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB7, 50,  0),
    { 0xb0, 0x01,  0x001b,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S07E01A_L001[] = { /* 0x81298c0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB7, 49,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S07E01A_L002[] = { /* 0x81298f0 */
    DEBUGINFO,
    { 0xaf, 0x01,  0x001b,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB7, 49,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S07E01A_L003[] = { /* 0x8129930 */
    DEBUGINFO,
    { 0xb0, 0x01,  0x001b,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB7, 50,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 49,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S07E01A_L003L[] = { /* 0x81299b0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_START[] = { /* 0x81299f0 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB8, 51, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB8, 51,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_END[] = { /* 0x8129a50 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB8, 52, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB8, 52,  0),
    { 0xb0, 0x01,  0x001c,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L001[] = { /* 0x8129ac0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB8, 51,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L002[] = { /* 0x8129af0 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB8, 51,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L003[] = { /* 0x8129b20 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB8, 51,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L004[] = { /* 0x8129b50 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB8, 51,  6),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L005[] = { /* 0x8129b80 */
    DEBUGINFO,
    { 0xae, 0x01,  0x001c,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB8, 51,  7),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L005B[] = { /* 0x8129bc0 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(4, 7, 0),
    { 0xaf, 0x01,  0x001c,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB8, 51,  8),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 4),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 4),
    EXECUTE_SUBSTATION(4, 0, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L006[] = { /* 0x8129c50 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 84, 0),
    { 0xb0, 0x01,  0x001c,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB8, 52,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 51,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L006L[] = { /* 0x8129ce0 */
    DEBUGINFO,
    CALL_SCRIPT(EVENT_DIVIDE_NEXT_DAY_FUNC),
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L007[] = { /* 0x8129d20 */
    DEBUGINFO,
    JUMP_SCRIPT(EVENT_S08E01A_L008),
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L008[] = { /* 0x8129d40 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0041,  0x00000000,  0x00000000, _("S08 SWITCH SELECT\n") },
    CJUMP_VAR(EVENT_S08E01),
    COND_EQUAL(2, /* to label */ 0),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 57,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(0), /* = 0x00 */
    CJUMP_RANDOM(2),
    COND_EQUAL(0, /* to label */ 1),
    COND_EQUAL(1, /* to label */ 2),
  LABEL(1), /* = 0x01 */
    { 0x3b, 0x29,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 3),
  LABEL(4), /* = 0x04 */
    EXECUTE_SUBSTATION(12, 12, 0),
    { 0x3b, 0x2a,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 5),
    EXECUTE_SUBSTATION(9, 85, 0),
    JUMP_LABEL(5),
  LABEL(2), /* = 0x02 */
    { 0x3b, 0x2d,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 3),
  LABEL(6), /* = 0x06 */
    EXECUTE_SUBSTATION(12, 13, 0),
    JUMP_LABEL(5),
  LABEL(3), /* = 0x03 */
    { 0x3b, 0x29,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 4),
    COND_EQUAL(2, /* to label */ 4),
    { 0x3b, 0x2d,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 6),
    EXECUTE_SUBSTATION(12, 14, 0),
    JUMP_LABEL(5),
  LABEL(5), /* = 0x05 */
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 52,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L008L[] = { /* 0x812a034 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L008A[] = { /* 0x812a064 */
    DEBUGINFO,
    { 0x3b, 0x29,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    EXECUTE_SUBSTATION(12, 12, 0),
    { 0x3b, 0x2a,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    EXECUTE_SUBSTATION(9, 85, 0),
  LABEL(0), /* = 0x00 */
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L008B[] = { /* 0x812a104 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 13, 0),
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S08E01A_L008C[] = { /* 0x812a144 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 14, 0),
    EXECUTE_SUBSTATION(12, 5, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_START[] = { /* 0x812a184 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB9, 53, 1, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB9, 53,  1),
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_END[] = { /* 0x812a1e4 */
    DEBUGINFO,
    JUMPIF_SCENE_LT(SCENARIO_SUB9, 55, 0, /* to label */ 0),
    RET_DIRECT,
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_SUB9, 55,  2),
    { 0xaf, 0x00,  0x001d,  0x00000000,  0x00000000, NULL },
    { 0xb0, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET_DIRECT,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L001[] = { /* 0x812a264 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB9, 53,  1),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L002[] = { /* 0x812a294 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB9, 53,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L003[] = { /* 0x812a2c4 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB9, 53,  4),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L004[] = { /* 0x812a2f4 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 86, 0),
    { 0xaf, 0x01,  0x001d,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB9, 53,  6),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L004B[] = { /* 0x812a344 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(201, 6, 0),
    { 0x02, 0x00,  0x0000,  0x00000025,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L005[] = { /* 0x812a384 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(203, 1, 0),
    EXECUTE_SUBSTATION(9, 88, 0),
    { 0xaf, 0x00,  0x001d,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB9, 54,  0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 53,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S09E01A_L005L[] = { /* 0x812a424 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01B_L001[] = { /* 0x812a454 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(9, 89, 0),
    { 0xaf, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB9, 54,  2),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01B_L001B[] = { /* 0x812a4a4 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(221, 1, 0),
    { 0x02, 0x00,  0x0000,  0x00000027,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01B_L002[] = { /* 0x812a4e4 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(220, 1, 0),
    EXECUTE_SUBSTATION(163, 3, 0),
    EXECUTE_SUBSTATION(220, 2, 0),
    EXECUTE_SUBSTATION(9, 91, 0),
    { 0xb0, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    SCENARIO_CALC(SCENARIO_SUB9, 55,  2),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 54,  0),
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_EVENT_S09E01B_L002L[] = { /* 0x812a5a4 */
    DEBUGINFO,
    EXECUTE_SUBSTATION(12, 8, 0),
    RET,
};

static const struct ScriptCommand s_script_EVENT_S09E01C_L001[] = { /* 0x812a5d4 */
    DEBUGINFO,
    SCENARIO_CALC(SCENARIO_SUB9, 55,  3),
    RET,
};

static const struct ScriptCommand s_script_EVENT_R00E01A_L001[] = { /* 0x812a604 */
    DEBUGINFO,
    CLEAR_ARRAY(EVENT_LOCAL),
  LABEL(0), /* = 0x00 */
    EXECUTE_SUBSTATION(4, 11, 0),
    CJUMP_SCENARIO_0(SCENARIO_SELECT),
    COND(JUDGE_EQ, 56, /* to label */ 0),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 1),
    JUMPIF_EQUAL(EVENT_LOCAL, 0, /* to label */ 2),
  LABEL(1), /* = 0x01 */
    EXECUTE_SUBSTATION(9, 6, 0),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(36, /* to label */ 3),
  LABEL(4), /* = 0x04 */
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, 12),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, 12),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    CALL_SCRIPT(DISMISSAL_SALLY_MEMBER_FUNC),
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    SCENARIO_CALC(SCENARIO_SELECT, 57,  0),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(EVENT_LOCAL, 0, /* to label */ 6),
  LABEL(5), /* = 0x05 */
    CALL_SCRIPT(NEXT_SAVE2_FUNC),
  LABEL(6), /* = 0x06 */
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(3), /* = 0x03 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 7),
    JUMP_LABEL(4),
  LABEL(7), /* = 0x07 */
    JUMP_SCRIPT(EVENT_S08E01A_L008),
};

static const struct ScriptCommand s_script_COMMON_ENTER[] = { /* 0x812a804 */
    DEBUGINFO,
    SELECT_EVENTS(0, 0),
    { 0x22, 0x00, -0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_DEBUG_ENTER[] = { /* 0x812a844 */
    DEBUGINFO,
    { 0x22, 0x00, -0x0001,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptCommand s_script_GETOUT_HABITAT[] = { /* 0x812a874 */
    DEBUGINFO,
    { 0x03, 0x00,  0x001e,  0x00000001,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 0),
    HALT,
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptCommand s_script_GETOUT_M01E01A[] = { /* 0x812a8d4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 2, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 2, 1, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_MAIN,  2,  2),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMP_SCRIPT(EVENT_M01E01A_L002),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_M01E01A_L003),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E02A[] = { /* 0x812aa14 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 3, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_M01E02A_L004),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(EVENT_M01E02A_L006),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E02B[] = { /* 0x812ab34 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(2, /* to label */ 0),
    COND_EQUAL(3, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 4, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 4, 6, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN,  4,  7),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E02B_L006),
  LABEL(6), /* = 0x06 */
    { 0x02, 0x00, -0x0001,  0x00000003,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 4, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 4, 7, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN,  4,  8),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E02B_L006),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E02B_L008),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(2, /* to label */ 10),
    COND_EQUAL(3, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
  LABEL(11), /* = 0x0b */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x02, 0x00, -0x0001,  0x00000003,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E03A[] = { /* 0x812ae04 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(4, /* to label */ 0),
    COND_EQUAL(5, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 5, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 5, 9, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN,  5, 10),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E03A_L009),
  LABEL(6), /* = 0x06 */
    { 0x02, 0x00, -0x0001,  0x00000005,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 5, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 5, 10, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN,  5, 11),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E03A_L009),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E03A_L011),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(4, /* to label */ 10),
    COND_EQUAL(5, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
  LABEL(11), /* = 0x0b */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x02, 0x00, -0x0001,  0x00000005,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E04A[] = { /* 0x812b0d4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(6, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 6, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 6, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_MAIN,  6,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_M01E04A_L004),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_M01E04A_L006),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E04B[] = { /* 0x812b224 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(7, /* to label */ 0),
    COND_EQUAL(8, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 7, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 7, 3, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN,  7,  4),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E04B_L004),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000bd,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 7, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 7, 4, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN,  7,  5),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E04B_L006),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E04B_L007),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(7, /* to label */ 10),
    COND_EQUAL(8, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 13),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x3b, 0x0b,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 11),
    { 0x01, 0x00, -0x0001,  0x000000bd,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E05A[] = { /* 0x812b554 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(9, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 8, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 8, 3, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_MAIN,  8,  4),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_M01E05A_L004),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_M01E05A_L006),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E07A[] = { /* 0x812b6a4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(10, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 11, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 11, 4, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_MAIN, 11,  5),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_M01E07A_L004),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_M01E07A_L005),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E07B[] = { /* 0x812b7f4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(11, /* to label */ 0),
    COND_EQUAL(12, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 12, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 12, 2, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN, 12,  3),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E07B_L003),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000c4,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 12, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 12, 3, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN, 12,  4),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E07B_L004),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E07B_L005),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(11, /* to label */ 10),
    COND_EQUAL(12, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 13),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x3b, 0x0b,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 11),
    { 0x01, 0x00, -0x0001,  0x000000c4,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E08A[] = { /* 0x812bb24 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(13, /* to label */ 0),
    COND_EQUAL(14, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 13, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 13, 2, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN, 13,  3),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E08A_L003),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000c7,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 13, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 13, 3, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN, 13,  4),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E08A_L004),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E08A_L005),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(13, /* to label */ 10),
    COND_EQUAL(14, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 13),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x3b, 0x0b,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 11),
    { 0x01, 0x00, -0x0001,  0x000000c7,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E08B[] = { /* 0x812be54 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(15, /* to label */ 0),
    COND_EQUAL(16, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 14, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 14, 2, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN, 14,  3),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E08B_L003),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000ca,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 14, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 8),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E08B_L005),
  LABEL(8), /* = 0x08 */
    JUMP_SCRIPT(EVENT_M01E08B_L006),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(15, /* to label */ 9),
    COND_EQUAL(16, /* to label */ 10),
    JUMP_LABEL(3),
  LABEL(9), /* = 0x09 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 11),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(12), /* = 0x0c */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    { 0x3b, 0x0b,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 10),
    { 0x01, 0x00, -0x0001,  0x000000ca,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E09A[] = { /* 0x812c154 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(17, /* to label */ 0),
    COND_EQUAL(18, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 15, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 15, 11, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN, 15, 12),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E09A_L012),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000cd,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 15, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 15, 8, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN, 15,  9),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E09A_L014),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E09A_L015),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(17, /* to label */ 10),
    COND_EQUAL(18, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 13),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x3b, 0x0b,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 11),
    { 0x01, 0x00, -0x0001,  0x000000cd,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_M01E10A[] = { /* 0x812c484 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(19, /* to label */ 0),
    COND_EQUAL(20, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 16, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 16, 4, /* to label */ 5),
    SCENARIO_CALC(SCENARIO_MAIN, 16,  5),
  LABEL(5), /* = 0x05 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E10A_L005),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000d0,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_MAIN, 16, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_SCENE_GT(SCENARIO_MAIN, 16, 5, /* to label */ 8),
    SCENARIO_CALC(SCENARIO_MAIN, 16,  6),
  LABEL(8), /* = 0x08 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 9),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E10A_L007),
  LABEL(9), /* = 0x09 */
    JUMP_SCRIPT(EVENT_M01E10A_L008),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(19, /* to label */ 10),
    COND_EQUAL(20, /* to label */ 11),
    JUMP_LABEL(3),
  LABEL(10), /* = 0x0a */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 12),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 13),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(13), /* = 0x0d */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(12), /* = 0x0c */
    { 0x3b, 0x0b,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(1, /* to label */ 11),
    { 0x01, 0x00, -0x0001,  0x000000d0,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S00E01A[] = { /* 0x812c7b4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(21, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 1),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    UPDATE_VARINT(CALC_SET, CLEAR_COUNT, 100),
    JUMP_SCRIPT(EVENT_S00E01A_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S01E01A[] = { /* 0x812c894 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(22, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB1, 29, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB1, 29, 3, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB1, 29,  4),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S01E01A_L003),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S01E02A[] = { /* 0x812c9e4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(23, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB1, 31, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB1, 31, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB1, 31,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S01E02A_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S02E01A[] = { /* 0x812cb34 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(24, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB2, 33, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 33, 4, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB2, 33,  5),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S02E01A_L004),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S02E02A[] = { /* 0x812cc84 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(25, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB2, 34, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB2, 34, 4, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB2, 34,  5),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S02E02A_L003),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S03E01A[] = { /* 0x812cdd4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(26, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB3, 36, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB3, 36, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB3, 36,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S03E01A_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S04E01A[] = { /* 0x812cf24 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(27, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB4, 38, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S04E01A_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};


static const struct ScriptCommand s_script_GETOUT_S04E01B[] = { /* 0x812d044 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(28, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB4, 39, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB4, 39, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB4, 39,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S04E01B_L001),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S04E01C[] = { /* 0x812d194 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(29, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB4, 40, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB4, 40, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB4, 40,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S04E01C_L001),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S04E01D[] = { /* 0x812d2e4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(30, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB4, 41, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB4, 41, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB4, 41,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S04E01D_L001),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S04E01E[] = { /* 0x812d434 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(31, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB4, 42, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB4, 42, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB4, 42,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S04E01E_L001),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S05E01A[] = { /* 0x812d584 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(32, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB5, 44, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB5, 44, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB5, 44,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S05E01A_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S06E01A[] = { /* 0x812d6d4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(33, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB6, 46, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB6, 46, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB6, 46,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S06E01A_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S06E01B[] = { /* 0x812d824 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(34, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB6, 47, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB6, 47, 2, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB6, 47,  3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S06E01B_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S07E01A[] = { /* 0x812d974 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(35, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB7, 49, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB7, 49, 3, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB7, 49,  4),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S07E01A_L003),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S08E01A[] = { /* 0x812dac4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(36, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB8, 51, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB8, 51, 8, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB8, 51,  9),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S08E01A_L006),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_S09E01A[] = { /* 0x812dc14 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(37, /* to label */ 0),
    COND_EQUAL(38, /* to label */ 1),
    COND_EQUAL(81, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB9, 53, /* to label */ 4),
    JUMP_LABEL(3),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(6), /* = 0x06 */
    { 0x01, 0x00, -0x0001,  0x000000ca,  0x00000000, NULL },
    HALT,
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(SCENARIO_SUB9, 53, /* to label */ 7),
    JUMP_LABEL(3),
  LABEL(7), /* = 0x07 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 8),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(8), /* = 0x08 */
    JUMP_SCRIPT(EVENT_S09E01A_L005),
  LABEL(2), /* = 0x02 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(37, /* to label */ 9),
    COND_EQUAL(38, /* to label */ 10),
    JUMP_LABEL(3),
  LABEL(9), /* = 0x09 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 11),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(10), /* = 0x0a */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(11), /* = 0x0b */
    { 0x01, 0x00, -0x0001,  0x000000ca,  0x00000000, NULL },
    HALT,
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};


static const struct ScriptCommand s_script_GETOUT_S09E01B[] = { /* 0x812dea4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(39, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(SCENARIO_SUB9, 54, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMPIF_SCENE_GT(SCENARIO_SUB9, 54, 3, /* to label */ 4),
    SCENARIO_CALC(SCENARIO_SUB9, 54,  4),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_S09E01B_L002),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(2), /* = 0x02 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_D62E01A[] = { /* 0x812dff4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(50, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    { 0xb0, 0x01,  0x0029,  0x00000000,  0x00000000, NULL },
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_D43E01A[] = { /* 0x812e0e4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(51, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    { 0xb0, 0x01,  0x002a,  0x00000000,  0x00000000, NULL },
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_D44E01A[] = { /* 0x812e1d4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(52, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    { 0xb0, 0x01,  0x002b,  0x00000000,  0x00000000, NULL },
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_D45E01A[] = { /* 0x812e2c4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(53, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    { 0xb0, 0x01,  0x002c,  0x00000000,  0x00000000, NULL },
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_D46E01A[] = { /* 0x812e3b4 */
    DEBUGINFO,
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(54, /* to label */ 0),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    { 0xb0, 0x01,  0x002d,  0x00000000,  0x00000000, NULL },
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(GETOUT_R00E01A),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_U00E01A[] = { /* 0x812e4a4 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0014,  0x00000000,  0x00000000, _("GETOUT U00E01A\n") },
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 18, 4, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_MAIN, 19,  1),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
  LABEL(1), /* = 0x01 */
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(80, /* to label */ 2),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_R00E01A[] = { /* 0x812e5c4 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0014,  0x00000000,  0x00000000, _("GETOUT R00E01A\n") },
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(81, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 2),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S00E01A_L001),
  LABEL(2), /* = 0x02 */
    SCENARIO_CALC(SCENARIO_SELECT, 56,  0),
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(1), /* = 0x01 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};

static const struct ScriptCommand s_script_GETOUT_T00E01A[] = { /* 0x812e6b4 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0013,  0x00000000,  0x00000000, _("GETOUT T00E01A\n") },
    JUMPIF_SCENE_EQ(SCENARIO_MAIN, 18, 4, /* to label */ 0),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SCENARIO_CALC(SCENARIO_MAIN, 19,  1),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
  LABEL(1), /* = 0x01 */
    CJUMP_VAR(DUNGEON_ENTER),
    COND_EQUAL(82, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(2), /* = 0x02 */
    { 0xf2, 0x00,  0x0014,  0x00000000,  0x00000000, _("GETOUT T00E01A 7&8\n") },
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(78, /* to label */ 4),
    COND_EQUAL(79, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 7),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    CJUMP_VAR(DUNGEON_ENTER_INDEX),
    COND_EQUAL(55, /* to label */ 9),
    COND_EQUAL(56, /* to label */ 10),
    COND_EQUAL(57, /* to label */ 11),
    COND_EQUAL(58, /* to label */ 12),
    COND_EQUAL(59, /* to label */ 13),
    COND_EQUAL(60, /* to label */ 14),
    COND_EQUAL(61, /* to label */ 15),
    COND_EQUAL(62, /* to label */ 16),
    COND_EQUAL(63, /* to label */ 17),
    COND_EQUAL(64, /* to label */ 18),
    COND_EQUAL(65, /* to label */ 19),
    COND_EQUAL(66, /* to label */ 20),
    COND_EQUAL(67, /* to label */ 21),
    COND_EQUAL(68, /* to label */ 22),
    COND_EQUAL(69, /* to label */ 23),
    COND_EQUAL(70, /* to label */ 24),
    COND_EQUAL(71, /* to label */ 25),
    COND_EQUAL(72, /* to label */ 26),
    COND_EQUAL(73, /* to label */ 27),
    COND_EQUAL(74, /* to label */ 28),
    COND_EQUAL(75, /* to label */ 29),
    COND_EQUAL(76, /* to label */ 30),
    COND_EQUAL(77, /* to label */ 31),
    JUMP_LABEL(3),
  LABEL(9), /* = 0x09 */
    { 0xb1, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(10), /* = 0x0a */
    { 0xb1, 0x01,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(11), /* = 0x0b */
    { 0xb1, 0x01,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(12), /* = 0x0c */
    { 0xb1, 0x01,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(13), /* = 0x0d */
    { 0xb1, 0x01,  0x0004,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(14), /* = 0x0e */
    { 0xb1, 0x01,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(15), /* = 0x0f */
    { 0xb1, 0x01,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(16), /* = 0x10 */
    { 0xb1, 0x01,  0x0007,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(17), /* = 0x11 */
    { 0xb1, 0x01,  0x0008,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(18), /* = 0x12 */
    { 0xb1, 0x01,  0x0009,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(19), /* = 0x13 */
    { 0xb1, 0x01,  0x000a,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(20), /* = 0x14 */
    { 0xb1, 0x01,  0x000b,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(21), /* = 0x15 */
    { 0xb1, 0x01,  0x000c,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(22), /* = 0x16 */
    { 0xb1, 0x01,  0x000d,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(23), /* = 0x17 */
    { 0xb1, 0x01,  0x000e,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(24), /* = 0x18 */
    { 0xb1, 0x01,  0x000f,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(25), /* = 0x19 */
    { 0xb1, 0x01,  0x0010,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(26), /* = 0x1a */
    { 0xb1, 0x01,  0x0011,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(27), /* = 0x1b */
    { 0xb1, 0x01,  0x0012,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(28), /* = 0x1c */
    { 0xb1, 0x01,  0x0013,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(29), /* = 0x1d */
    { 0xb1, 0x01,  0x0014,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(30), /* = 0x1e */
    { 0xb1, 0x01,  0x0015,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(32),
  LABEL(31), /* = 0x1f */
    JUMP_LABEL(32),
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(8), /* = 0x08 */
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(6), /* = 0x06 */
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(32), /* = 0x20 */
    JUMP_SCRIPT(EVENT_DIVIDE),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(GETOUT_M01E07T),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(GETOUT_M01E08T),
};

static const struct ScriptCommand s_script_GETOUT_M01E07T[] = { /* 0x812eeb8 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0013,  0x00000000,  0x00000000, _("GETOUT M01E07T\n") },
    JUMPIF_EQUAL(SCENARIO_MAIN, 11, /* to label */ 1),
    JUMPIF_EQUAL(SCENARIO_MAIN, 12, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E07A_T001),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(EVENT_M01E07A_T002),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E07B_T001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_M01E07B_T002),
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};


static const struct ScriptCommand s_script_GETOUT_M01E08T[] = { /* 0x812eff8 */
    DEBUGINFO,
    { 0xf2, 0x00,  0x0013,  0x00000000,  0x00000000, _("GETOUT M01E08T\n") },
    JUMPIF_EQUAL(SCENARIO_MAIN, 13, /* to label */ 1),
    JUMPIF_EQUAL(SCENARIO_MAIN, 14, /* to label */ 2),
    JUMP_LABEL(3),
  LABEL(1), /* = 0x01 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E08A_T001),
  LABEL(4), /* = 0x04 */
    JUMP_SCRIPT(EVENT_M01E08A_T002),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 3),
    JUMP_SCRIPT(EVENT_M01E08B_T001),
  LABEL(5), /* = 0x05 */
    JUMP_SCRIPT(EVENT_M01E08B_T002),
  LABEL(3), /* = 0x03 */
    JUMP_SCRIPT(EVENT_DIVIDE),
};


static const struct ScriptCommand s_script_SETUP_DEBUG_CAMERA[] = { /* 0x812f138 */
    DEBUGINFO,
    { 0x3b, 0x3e,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 0),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    RET,
};

static const struct ScriptCommand s_script_MOVE_DEBUG_CAMERA[] = { /* 0x812f198 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x3f,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x9a, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

/*extern*/ const struct ScriptRef gFunctionScriptTable[] = { /* 0x812f1f8 */
    { 0, 4, _("END_TALK"), s_script_END_TALK },
    { 1, 4, _("WAIT_END_TALK_FUNC"), s_script_WAIT_END_TALK_FUNC },
    { 2, 4, _("WAIT_END_EVENT_FUNC"), s_script_WAIT_END_EVENT_FUNC },
    { 3, 4, _("WAIT_START_FUNC"), s_script_WAIT_START_FUNC },
    { 4, 4, _("INCOMPLETE_TALK"), s_script_INCOMPLETE_TALK },
    { 5, 4, _("NORMAL_WAIT_END_TALK"), s_script_NORMAL_WAIT_END_TALK },
    { 6, 4, _("LIVES_REPLY_NORMAL"), s_script_LIVES_REPLY_NORMAL },
    { 7, 4, _("LIVES_REPLY"), s_script_LIVES_REPLY },
    { 8, 4, _("OBJECT_REPLY_NORMAL"), s_script_OBJECT_REPLY_NORMAL },
    { 9, 4, _("EXAMINE_MISS"), s_script_EXAMINE_MISS },
    { 10, 4, _("ENTER_WAIT_FUNC"), s_script_ENTER_WAIT_FUNC },
    { 11, 4, _("UNIT_TALK"), s_script_UNIT_TALK },
    { 12, 4, _("HABITAT_TALK"), s_script_HABITAT_TALK },
    { 13, 4, _("HABITAT_TALK_S01E02A"), s_script_HABITAT_TALK_S01E02A },
    { 14, 5, _("HABITAT_MOVE1"), s_script_HABITAT_MOVE1 },
    { 15, 5, _("HABITAT_MOVE2"), s_script_HABITAT_MOVE2 },
    { 16, 5, _("HABITAT_MOVE_PAUSE"), s_script_HABITAT_MOVE_PAUSE },
    { 17, 5, _("HABITAT_MOVE_STAY_FIX"), s_script_HABITAT_MOVE_STAY_FIX },
    { 18, 5, _("HABITAT_MOVE_STAY_TURN"), s_script_HABITAT_MOVE_STAY_TURN },
    { 19, 5, _("LIVES_MOVE_NORMAL"), s_script_LIVES_MOVE_NORMAL },
    { 20, 5, _("LIVES_MOVE_CHANGE"), s_script_LIVES_MOVE_CHANGE },
    { 21, 5, _("OBJECT_MOVE_NORMAL"), s_script_OBJECT_MOVE_NORMAL },
    { 22, 5, _("OBJECT_MOVE_CHANGE"), s_script_OBJECT_MOVE_CHANGE },
    { 23, 5, _("EFFECT_MOVE_NORMAL"), s_script_EFFECT_MOVE_NORMAL },
    { 24, 5, _("EFFECT_MOVE_CHANGE"), s_script_EFFECT_MOVE_CHANGE },
    { 25, 5, _("MOVE_INIT"), s_script_MOVE_INIT },
    { 26, 5, _("MOVE_PAUSE"), s_script_MOVE_PAUSE },
    { 27, 5, _("MOVE_STAY"), s_script_MOVE_STAY },
    { 28, 5, _("MOVE_SLEEP"), s_script_MOVE_SLEEP },
    { 29, 5, _("MOVE_RANDOM"), s_script_MOVE_RANDOM },
    { 30, 5, _("MOVE_BOY"), s_script_MOVE_BOY },
    { 31, 5, _("MOVE_GIRL"), s_script_MOVE_GIRL },
    { 32, 9, _("WAKEUP_FUNC"), s_script_WAKEUP_FUNC },
    { 33, 9, _("LOOK_AROUND_FUNC"), s_script_LOOK_AROUND_FUNC },
    { 34, 9, _("LOOK_AROUND_DOWN_FUNC"), s_script_LOOK_AROUND_DOWN_FUNC },
    { 35, 9, _("LOOK_AROUND_RIGHT_FUNC"), s_script_LOOK_AROUND_RIGHT_FUNC },
    { 36, 9, _("LOOK_AROUND_LEFT_FUNC"), s_script_LOOK_AROUND_LEFT_FUNC },
    { 37, 9, _("JUMP_HAPPY_FUNC"), s_script_JUMP_HAPPY_FUNC },
    { 38, 9, _("JUMP_SURPRISE_FUNC"), s_script_JUMP_SURPRISE_FUNC },
    { 39, 9, _("JUMP_ANGRY_FUNC"), s_script_JUMP_ANGRY_FUNC },
    { 40, 9, _("NOTICE_FUNC"), s_script_NOTICE_FUNC },
    { 41, 9, _("QUESTION_FUNC"), s_script_QUESTION_FUNC },
    { 42, 9, _("SWEAT_FUNC"), s_script_SWEAT_FUNC },
    { 43, 9, _("SHOCK_FUNC"), s_script_SHOCK_FUNC },
    { 44, 9, _("SPREE_START_FUNC"), s_script_SPREE_START_FUNC },
    { 45, 9, _("SPREE_END_FUNC"), s_script_SPREE_END_FUNC },
    { 46, 9, _("SMILE_START_FUNC"), s_script_SMILE_START_FUNC },
    { 47, 9, _("SMILE_END_FUNC"), s_script_SMILE_END_FUNC },
    { 48, 9, _("ANGRY_START_FUNC"), s_script_ANGRY_START_FUNC },
    { 49, 9, _("ANGRY_END_FUNC"), s_script_ANGRY_END_FUNC },
    { 50, 5, _("MOVE_PLAZA_SLEEP"), s_script_MOVE_PLAZA_SLEEP },
    { 51, 9, _("INIT_PLAZA_SLEEP_STAY_FUNC"), s_script_INIT_PLAZA_SLEEP_STAY_FUNC },
    { 52, 9, _("INIT_PLAZA_SLEEP_TALK_FUNC"), s_script_INIT_PLAZA_SLEEP_TALK_FUNC },
    { 53, 8, _("INIT_SLEEP_FUNC"), s_script_INIT_SLEEP_FUNC },
    { 54, 8, _("INIT_BASE_FUNC"), s_script_INIT_BASE_FUNC },
    { 55, 8, _("INIT_DEBUG_HABITAT"), s_script_INIT_DEBUG_HABITAT },
    { 56, 7, _("NORMAL_MESSAGE"), NULL },
    { 57, 7, _("NORMAL_EVENT"), NULL },
    { 58, 7, _("NORMAL_CAMERA"), s_script_NORMAL_CAMERA },
    { 59, 7, _("DISMISSAL_SALLY_MEMBER_FUNC"), s_script_DISMISSAL_SALLY_MEMBER_FUNC },
    { 60, 7, _("DISMISSAL_SALLY_MEMBER2_FUNC"), s_script_DISMISSAL_SALLY_MEMBER2_FUNC },
    { 61, 7, _("DISMISSAL_SALLY_MEMBER3_FUNC"), s_script_DISMISSAL_SALLY_MEMBER3_FUNC },
    { 62, 7, _("DISMISSAL_SALLY_MEMBER4_FUNC"), s_script_DISMISSAL_SALLY_MEMBER4_FUNC },
    { 63, 7, _("NEXT_SAVE_FUNC"), s_script_NEXT_SAVE_FUNC },
    { 64, 7, _("NEXT_SAVE2_FUNC"), s_script_NEXT_SAVE2_FUNC },
    { 65, 7, _("SAVE_POINT"), s_script_SAVE_POINT },
    { 66, 7, _("WAREHOUSE_POINT"), s_script_WAREHOUSE_POINT },
    { 67, 7, _("SAVE_AND_WAREHOUSE_POINT"), s_script_SAVE_AND_WAREHOUSE_POINT },
    { 68, 7, _("WORLD_MAP_POINT"), s_script_WORLD_MAP_POINT },
    { 69, 7, _("FORMATION_HERO"), s_script_FORMATION_HERO },
    { 70, 7, _("EVOLUTION_HERO"), s_script_EVOLUTION_HERO },
    { 71, 7, _("WARP_LIVES_START"), s_script_WARP_LIVES_START },
    { 72, 7, _("WARP_LIVES_START2"), s_script_WARP_LIVES_START2 },
    { 73, 7, _("WARP_LIVES_START3"), s_script_WARP_LIVES_START3 },
    { 74, 7, _("WARP_LIVES_ARRIVE"), s_script_WARP_LIVES_ARRIVE },
    { 75, 7, _("WARP_LIVES_ARRIVE2"), s_script_WARP_LIVES_ARRIVE2 },
    { 76, 7, _("WARP_LIVES_ARRIVE3"), s_script_WARP_LIVES_ARRIVE3 },
    { 77, 7, _("LIVES_WARP_START_FUNC"), s_script_LIVES_WARP_START_FUNC },
    { 78, 7, _("LIVES_WARP_START2_FUNC"), s_script_LIVES_WARP_START2_FUNC },
    { 79, 7, _("LIVES_WARP_START3_FUNC"), s_script_LIVES_WARP_START3_FUNC },
    { 80, 7, _("LIVES_WARP_START_SUB"), s_script_LIVES_WARP_START_SUB },
    { 81, 7, _("LIVES_WARP_ARRIVE_FUNC"), s_script_LIVES_WARP_ARRIVE_FUNC },
    { 82, 7, _("LIVES_WARP_ARRIVE2_FUNC"), s_script_LIVES_WARP_ARRIVE2_FUNC },
    { 83, 7, _("LIVES_WARP_ARRIVE3_FUNC"), s_script_LIVES_WARP_ARRIVE3_FUNC },
    { 84, 7, _("LIVES_WARP_ARRIVE_SUB"), s_script_LIVES_WARP_ARRIVE_SUB },
    { 85, 7, _("GET_ITEM_FUNC"), s_script_GET_ITEM_FUNC },
    { 86, 7, _("GET_ITEM_WAIT_FUNC"), s_script_GET_ITEM_WAIT_FUNC },
    { 87, 7, _("GET_ITEM2_FUNC"), s_script_GET_ITEM2_FUNC },
    { 88, 7, _("GET_ITEM2_WAIT_FUNC"), s_script_GET_ITEM2_WAIT_FUNC },
    { 89, 7, _("JOIN_FUNC"), s_script_JOIN_FUNC },
    { 90, 7, _("LODGE_START_FUNC"), s_script_LODGE_START_FUNC },
    { 91, 7, _("LODGE_WAIT_FUNC"), s_script_LODGE_WAIT_FUNC },
    { 92, 7, _("LODGE_END_FUNC"), s_script_LODGE_END_FUNC },
    { 93, 7, _("LODGE_SOUND_FUNC"), s_script_LODGE_SOUND_FUNC },
    { 94, 7, _("SAVE_START_FUNC"), s_script_SAVE_START_FUNC },
    { 95, 7, _("SAVE_WAIT_FUNC"), s_script_SAVE_WAIT_FUNC },
    { 96, 7, _("SAVE_END_FUNC"), s_script_SAVE_END_FUNC },
    { 97, 7, _("SAVE_SOUND_FUNC"), s_script_SAVE_SOUND_FUNC },
    { 98, 9, _("EFFECT_TEST1"), s_script_EFFECT_TEST1 },
    { 99, 9, _("EFFECT_TEST2"), s_script_EFFECT_TEST2 },
    { 100, 9, _("EFFECT_MOVE_DIVE"), s_script_EFFECT_MOVE_DIVE },
    { 101, 9, _("EFFECT_MOVE_WAVE"), s_script_EFFECT_MOVE_WAVE },
    { 102, 7, _("EVENT_DIVIDE"), s_script_EVENT_DIVIDE },
    { 103, 7, _("EVENT_DIVIDE_NEXT"), s_script_EVENT_DIVIDE_NEXT },
    { 104, 7, _("EVENT_DIVIDE_INIT_FUNC"), s_script_EVENT_DIVIDE_INIT_FUNC },
    { 105, 7, _("EVENT_DIVIDE_NEXT_DAY_FUNC"), s_script_EVENT_DIVIDE_NEXT_DAY_FUNC },
    { 106, 7, _("EVENT_DIVIDE_NEXT_DAY2_FUNC"), s_script_EVENT_DIVIDE_NEXT_DAY2_FUNC },
    { 107, 7, _("EVENT_DIVIDE_FIRST"), s_script_EVENT_DIVIDE_FIRST },
    { 108, 7, _("EVENT_DIVIDE_SECOND"), s_script_EVENT_DIVIDE_SECOND },
    { 109, 7, _("EVENT_DIVIDE_AFTER"), s_script_EVENT_DIVIDE_AFTER },
    { 110, 7, _("EVENT_DIVIDE_WARP_LOCK_FUNC"), s_script_EVENT_DIVIDE_WARP_LOCK_FUNC },
    { 111, 7, _("EVENT_RESCUE_ENTER_CHECK"), s_script_EVENT_RESCUE_ENTER_CHECK },
    { 112, 7, _("EVENT_RESCUE"), s_script_EVENT_RESCUE },
    { 113, 7, _("DEBUG_SCRIPT"), s_script_DEBUG_SCRIPT },
    { 114, 7, _("DEMO_CANCEL"), s_script_DEMO_CANCEL },
    { 115, 10, _("DEMO_01"), s_script_DEMO_01 },
    { 116, 10, _("DEMO_02"), s_script_DEMO_02 },
    { 117, 10, _("DEMO_03"), s_script_DEMO_03 },
    { 118, 10, _("DEMO_04"), s_script_DEMO_04 },
    { 119, 10, _("EVENT_M00E01A_L001"), s_script_EVENT_M00E01A_L001 },
    { 120, 10, _("EVENT_M01E01A_L001"), s_script_EVENT_M01E01A_L001 },
    { 121, 10, _("EVENT_M01E01A_L002"), s_script_EVENT_M01E01A_L002 },
    { 122, 10, _("EVENT_M01E01A_L003"), s_script_EVENT_M01E01A_L003 },
    { 123, 10, _("EVENT_M01E02A_L001"), s_script_EVENT_M01E02A_L001 },
    { 124, 12, _("EVENT_M01E02A_L001B"), s_script_EVENT_M01E02A_L001B },
    { 125, 10, _("EVENT_M01E02A_L001C"), s_script_EVENT_M01E02A_L001C },
    { 126, 10, _("EVENT_M01E02A_L002"), s_script_EVENT_M01E02A_L002 },
    { 127, 10, _("EVENT_M01E02A_L003"), s_script_EVENT_M01E02A_L003 },
    { 128, 10, _("EVENT_M01E02A_L004"), s_script_EVENT_M01E02A_L004 },
    { 129, 10, _("EVENT_M01E02A_L005"), s_script_EVENT_M01E02A_L005 },
    { 130, 10, _("EVENT_M01E02A_L006"), s_script_EVENT_M01E02A_L006 },
    { 131, 10, _("EVENT_M01E02B_L001"), s_script_EVENT_M01E02B_L001 },
    { 132, 10, _("EVENT_M01E02B_L002"), s_script_EVENT_M01E02B_L002 },
    { 133, 10, _("EVENT_M01E02B_L003"), s_script_EVENT_M01E02B_L003 },
    { 134, 10, _("EVENT_M01E02B_L004"), s_script_EVENT_M01E02B_L004 },
    { 135, 10, _("EVENT_M01E02B_L004B"), s_script_EVENT_M01E02B_L004B },
    { 136, 10, _("EVENT_M01E02B_L005"), s_script_EVENT_M01E02B_L005 },
    { 137, 10, _("EVENT_M01E02B_L006"), s_script_EVENT_M01E02B_L006 },
    { 138, 10, _("EVENT_M01E02B_L007"), s_script_EVENT_M01E02B_L007 },
    { 139, 10, _("EVENT_M01E02B_L008"), s_script_EVENT_M01E02B_L008 },
    { 140, 10, _("EVENT_M01E03A_L000"), s_script_EVENT_M01E03A_L000 },
    { 141, 10, _("EVENT_M01E03A_L001"), s_script_EVENT_M01E03A_L001 },
    { 142, 10, _("EVENT_M01E03A_L002"), s_script_EVENT_M01E03A_L002 },
    { 143, 10, _("EVENT_M01E03A_L003"), s_script_EVENT_M01E03A_L003 },
    { 144, 10, _("EVENT_M01E03A_L004"), s_script_EVENT_M01E03A_L004 },
    { 145, 10, _("EVENT_M01E03A_L005"), s_script_EVENT_M01E03A_L005 },
    { 146, 10, _("EVENT_M01E03A_L006"), s_script_EVENT_M01E03A_L006 },
    { 147, 10, _("EVENT_M01E03A_L007"), s_script_EVENT_M01E03A_L007 },
    { 148, 10, _("EVENT_M01E03A_L008"), s_script_EVENT_M01E03A_L008 },
    { 149, 10, _("EVENT_M01E03A_L009"), s_script_EVENT_M01E03A_L009 },
    { 150, 10, _("EVENT_M01E03A_L010"), s_script_EVENT_M01E03A_L010 },
    { 151, 10, _("EVENT_M01E03A_L011"), s_script_EVENT_M01E03A_L011 },
    { 152, 10, _("EVENT_M01E04A_L000"), s_script_EVENT_M01E04A_L000 },
    { 153, 10, _("EVENT_M01E04A_L001"), s_script_EVENT_M01E04A_L001 },
    { 154, 10, _("EVENT_M01E04A_L002"), s_script_EVENT_M01E04A_L002 },
    { 155, 10, _("EVENT_M01E04A_L003"), s_script_EVENT_M01E04A_L003 },
    { 156, 10, _("EVENT_M01E04A_L004"), s_script_EVENT_M01E04A_L004 },
    { 157, 12, _("EVENT_M01E04A_L005"), s_script_EVENT_M01E04A_L005 },
    { 158, 10, _("EVENT_M01E04A_L006"), s_script_EVENT_M01E04A_L006 },
    { 159, 10, _("EVENT_M01E04B_L000"), s_script_EVENT_M01E04B_L000 },
    { 160, 10, _("EVENT_M01E04B_L001"), s_script_EVENT_M01E04B_L001 },
    { 161, 10, _("EVENT_M01E04B_L002"), s_script_EVENT_M01E04B_L002 },
    { 162, 10, _("EVENT_M01E04B_L003"), s_script_EVENT_M01E04B_L003 },
    { 163, 10, _("EVENT_M01E04B_L004"), s_script_EVENT_M01E04B_L004 },
    { 164, 10, _("EVENT_M01E04B_L005"), s_script_EVENT_M01E04B_L005 },
    { 165, 10, _("EVENT_M01E04B_L006"), s_script_EVENT_M01E04B_L006 },
    { 166, 10, _("EVENT_M01E04B_L007"), s_script_EVENT_M01E04B_L007 },
    { 167, 10, _("EVENT_M01E05A_L000"), s_script_EVENT_M01E05A_L000 },
    { 168, 10, _("EVENT_M01E05A_L001"), s_script_EVENT_M01E05A_L001 },
    { 169, 10, _("EVENT_M01E05A_L002"), s_script_EVENT_M01E05A_L002 },
    { 170, 10, _("EVENT_M01E05A_L003"), s_script_EVENT_M01E05A_L003 },
    { 171, 10, _("EVENT_M01E05A_L004"), s_script_EVENT_M01E05A_L004 },
    { 172, 10, _("EVENT_M01E05A_L005"), s_script_EVENT_M01E05A_L005 },
    { 173, 10, _("EVENT_M01E05A_L006"), s_script_EVENT_M01E05A_L006 },
    { 174, 10, _("EVENT_M01E05B_L000"), s_script_EVENT_M01E05B_L000 },
    { 175, 10, _("EVENT_M01E05B_L001"), s_script_EVENT_M01E05B_L001 },
    { 176, 10, _("EVENT_M01E05B_L002"), s_script_EVENT_M01E05B_L002 },
    { 177, 12, _("EVENT_M01E05B_L003"), s_script_EVENT_M01E05B_L003 },
    { 178, 10, _("EVENT_M01E05B_L004"), s_script_EVENT_M01E05B_L004 },
    { 179, 10, _("EVENT_M01E05B_L005"), s_script_EVENT_M01E05B_L005 },
    { 180, 10, _("EVENT_M01E06A_L001"), s_script_EVENT_M01E06A_L001 },
    { 181, 10, _("EVENT_M01E06A_L002"), s_script_EVENT_M01E06A_L002 },
    { 182, 10, _("EVENT_M01E06A_L003"), s_script_EVENT_M01E06A_L003 },
    { 183, 10, _("EVENT_M01E07A_L001"), s_script_EVENT_M01E07A_L001 },
    { 184, 10, _("EVENT_M01E07A_L002"), s_script_EVENT_M01E07A_L002 },
    { 185, 10, _("EVENT_M01E07A_L003"), s_script_EVENT_M01E07A_L003 },
    { 186, 10, _("EVENT_M01E07A_L004"), s_script_EVENT_M01E07A_L004 },
    { 187, 10, _("EVENT_M01E07A_L005"), s_script_EVENT_M01E07A_L005 },
    { 188, 10, _("EVENT_M01E07A_T001"), s_script_EVENT_M01E07A_T001 },
    { 189, 10, _("EVENT_M01E07A_T002"), s_script_EVENT_M01E07A_T002 },
    { 190, 10, _("EVENT_M01E07B_L001"), s_script_EVENT_M01E07B_L001 },
    { 191, 10, _("EVENT_M01E07B_L002"), s_script_EVENT_M01E07B_L002 },
    { 192, 10, _("EVENT_M01E07B_L003"), s_script_EVENT_M01E07B_L003 },
    { 193, 10, _("EVENT_M01E07B_L004"), s_script_EVENT_M01E07B_L004 },
    { 194, 10, _("EVENT_M01E07B_L005"), s_script_EVENT_M01E07B_L005 },
    { 195, 10, _("EVENT_M01E07B_T001"), s_script_EVENT_M01E07B_T001 },
    { 196, 10, _("EVENT_M01E07B_T002"), s_script_EVENT_M01E07B_T002 },
    { 197, 10, _("EVENT_M01E08A_L001"), s_script_EVENT_M01E08A_L001 },
    { 198, 10, _("EVENT_M01E08A_L002"), s_script_EVENT_M01E08A_L002 },
    { 199, 10, _("EVENT_M01E08A_L003"), s_script_EVENT_M01E08A_L003 },
    { 200, 10, _("EVENT_M01E08A_L004"), s_script_EVENT_M01E08A_L004 },
    { 201, 10, _("EVENT_M01E08A_L005"), s_script_EVENT_M01E08A_L005 },
    { 202, 10, _("EVENT_M01E08A_T001"), s_script_EVENT_M01E08A_T001 },
    { 203, 10, _("EVENT_M01E08A_T002"), s_script_EVENT_M01E08A_T002 },
    { 204, 10, _("EVENT_M01E08B_L001"), s_script_EVENT_M01E08B_L001 },
    { 205, 10, _("EVENT_M01E08B_L002"), s_script_EVENT_M01E08B_L002 },
    { 206, 10, _("EVENT_M01E08B_L003"), s_script_EVENT_M01E08B_L003 },
    { 207, 10, _("EVENT_M01E08B_L004"), s_script_EVENT_M01E08B_L004 },
    { 208, 10, _("EVENT_M01E08B_L005"), s_script_EVENT_M01E08B_L005 },
    { 209, 10, _("EVENT_M01E08B_L006"), s_script_EVENT_M01E08B_L006 },
    { 210, 10, _("EVENT_M01E08B_T001"), s_script_EVENT_M01E08B_T001 },
    { 211, 10, _("EVENT_M01E08B_T002"), s_script_EVENT_M01E08B_T002 },
    { 212, 10, _("EVENT_M01E09A_L001"), s_script_EVENT_M01E09A_L001 },
    { 213, 10, _("EVENT_M01E09A_L002"), s_script_EVENT_M01E09A_L002 },
    { 214, 10, _("EVENT_M01E09A_L003"), s_script_EVENT_M01E09A_L003 },
    { 215, 10, _("EVENT_M01E09A_L004"), s_script_EVENT_M01E09A_L004 },
    { 216, 10, _("EVENT_M01E09A_L005"), s_script_EVENT_M01E09A_L005 },
    { 217, 10, _("EVENT_M01E09A_L006"), s_script_EVENT_M01E09A_L006 },
    { 218, 10, _("EVENT_M01E09A_L007"), s_script_EVENT_M01E09A_L007 },
    { 219, 10, _("EVENT_M01E09A_L008"), s_script_EVENT_M01E09A_L008 },
    { 220, 10, _("EVENT_M01E09A_L009"), s_script_EVENT_M01E09A_L009 },
    { 221, 10, _("EVENT_M01E09A_L010"), s_script_EVENT_M01E09A_L010 },
    { 222, 10, _("EVENT_M01E09A_L011"), s_script_EVENT_M01E09A_L011 },
    { 223, 10, _("EVENT_M01E09A_L012"), s_script_EVENT_M01E09A_L012 },
    { 224, 10, _("EVENT_M01E09A_L013"), s_script_EVENT_M01E09A_L013 },
    { 225, 10, _("EVENT_M01E09A_L014"), s_script_EVENT_M01E09A_L014 },
    { 226, 10, _("EVENT_M01E09A_L015"), s_script_EVENT_M01E09A_L015 },
    { 227, 10, _("EVENT_M01E10A_L001"), s_script_EVENT_M01E10A_L001 },
    { 228, 10, _("EVENT_M01E10A_L002"), s_script_EVENT_M01E10A_L002 },
    { 229, 10, _("EVENT_M01E10A_L003"), s_script_EVENT_M01E10A_L003 },
    { 230, 10, _("EVENT_M01E10A_L004"), s_script_EVENT_M01E10A_L004 },
    { 231, 10, _("EVENT_M01E10A_L005"), s_script_EVENT_M01E10A_L005 },
    { 232, 10, _("EVENT_M01E10A_L006"), s_script_EVENT_M01E10A_L006 },
    { 233, 10, _("EVENT_M01E10A_L007"), s_script_EVENT_M01E10A_L007 },
    { 234, 10, _("EVENT_M01E10A_L008"), s_script_EVENT_M01E10A_L008 },
    { 235, 10, _("EVENT_M01END_L001"), s_script_EVENT_M01END_L001 },
    { 236, 10, _("EVENT_M01END_L002"), s_script_EVENT_M01END_L002 },
    { 237, 10, _("EVENT_M02E01A_L001"), s_script_EVENT_M02E01A_L001 },
    { 238, 10, _("EVENT_M02E01A_L002"), s_script_EVENT_M02E01A_L002 },
    { 239, 10, _("EVENT_M02E01A_L003"), s_script_EVENT_M02E01A_L003 },
    { 240, 10, _("EVENT_M02E02A_L001"), s_script_EVENT_M02E02A_L001 },
    { 241, 10, _("EVENT_M02E02B_L001"), s_script_EVENT_M02E02B_L001 },
    { 242, 10, _("EVENT_M02E02C_L001"), s_script_EVENT_M02E02C_L001 },
    { 243, 10, _("EVENT_M02E02D_L001"), s_script_EVENT_M02E02D_L001 },
    { 244, 10, _("EVENT_M02E02E_L001"), s_script_EVENT_M02E02E_L001 },
    { 245, 10, _("EVENT_M02E02F_L001"), s_script_EVENT_M02E02F_L001 },
    { 246, 10, _("EVENT_M02E02G_L001"), s_script_EVENT_M02E02G_L001 },
    { 247, 10, _("EVENT_M02E02H_L001"), s_script_EVENT_M02E02H_L001 },
    { 248, 10, _("EVENT_M02END_L001"), s_script_EVENT_M02END_L001 },
    { 249, 10, _("EVENT_S00E01A_L001"), s_script_EVENT_S00E01A_L001 },
    { 250, 10, _("EVENT_S00E01A_L002"), s_script_EVENT_S00E01A_L002 },
    { 251, 10, _("EVENT_S00E01A_L003"), s_script_EVENT_S00E01A_L003 },
    { 252, 10, _("EVENT_S00E01A_L004"), s_script_EVENT_S00E01A_L004 },
    { 253, 11, _("EVENT_S01E01A_START"), s_script_EVENT_S01E01A_START },
    { 254, 11, _("EVENT_S01E01A_CONTINUE"), s_script_EVENT_S01E01A_CONTINUE },
    { 255, 11, _("EVENT_S01E01A_END"), s_script_EVENT_S01E01A_END },
    { 256, 12, _("EVENT_S01E01A_L001"), s_script_EVENT_S01E01A_L001 },
    { 257, 10, _("EVENT_S01E01A_L002"), s_script_EVENT_S01E01A_L002 },
    { 258, 10, _("EVENT_S01E01A_L003"), s_script_EVENT_S01E01A_L003 },
    { 259, 10, _("EVENT_S01E01B_L001"), s_script_EVENT_S01E01B_L001 },
    { 260, 12, _("EVENT_S01E01B_L001L"), s_script_EVENT_S01E01B_L001L },
    { 261, 10, _("EVENT_S01E01C_L001"), s_script_EVENT_S01E01C_L001 },
    { 262, 11, _("EVENT_S01E02A_START"), s_script_EVENT_S01E02A_START },
    { 263, 11, _("EVENT_S01E02A_END"), s_script_EVENT_S01E02A_END },
    { 264, 10, _("EVENT_S01E02A_L001"), s_script_EVENT_S01E02A_L001 },
    { 265, 10, _("EVENT_S01E02A_L002"), s_script_EVENT_S01E02A_L002 },
    { 266, 12, _("EVENT_S01E02A_L002L"), s_script_EVENT_S01E02A_L002L },
    { 267, 12, _("EVENT_S01E02B_L001"), s_script_EVENT_S01E02B_L001 },
    { 268, 12, _("EVENT_S01E02B_L002"), s_script_EVENT_S01E02B_L002 },
    { 269, 11, _("EVENT_S02E01A_START"), s_script_EVENT_S02E01A_START },
    { 270, 11, _("EVENT_S02E01A_END"), s_script_EVENT_S02E01A_END },
    { 271, 12, _("EVENT_S02E01A_L001"), s_script_EVENT_S02E01A_L001 },
    { 272, 12, _("EVENT_S02E01A_L002"), s_script_EVENT_S02E01A_L002 },
    { 273, 12, _("EVENT_S02E01A_L003"), s_script_EVENT_S02E01A_L003 },
    { 274, 12, _("EVENT_S02E01A_L004"), s_script_EVENT_S02E01A_L004 },
    { 275, 12, _("EVENT_S02E01A_L004L"), s_script_EVENT_S02E01A_L004L },
    { 276, 11, _("EVENT_S02E02A_START"), s_script_EVENT_S02E02A_START },
    { 277, 11, _("EVENT_S02E02A_END"), s_script_EVENT_S02E02A_END },
    { 278, 12, _("EVENT_S02E02A_L001"), s_script_EVENT_S02E02A_L001 },
    { 279, 10, _("EVENT_S02E02A_L002"), s_script_EVENT_S02E02A_L002 },
    { 280, 12, _("EVENT_S02E02A_L003"), s_script_EVENT_S02E02A_L003 },
    { 281, 12, _("EVENT_S02E02A_L003L"), s_script_EVENT_S02E02A_L003L },
    { 282, 11, _("EVENT_S03E01A_START"), s_script_EVENT_S03E01A_START },
    { 283, 11, _("EVENT_S03E01A_CONTINUE"), s_script_EVENT_S03E01A_CONTINUE },
    { 284, 11, _("EVENT_S03E01A_END"), s_script_EVENT_S03E01A_END },
    { 285, 10, _("EVENT_S03E01A_L001"), s_script_EVENT_S03E01A_L001 },
    { 286, 12, _("EVENT_S03E01A_L002"), s_script_EVENT_S03E01A_L002 },
    { 287, 12, _("EVENT_S03E01A_L002L"), s_script_EVENT_S03E01A_L002L },
    { 288, 11, _("EVENT_S04E01A_START"), s_script_EVENT_S04E01A_START },
    { 289, 11, _("EVENT_S04E01A_LAST"), s_script_EVENT_S04E01A_LAST },
    { 290, 11, _("EVENT_S04E01A_END"), s_script_EVENT_S04E01A_END },
    { 291, 10, _("EVENT_S04E01A_L001"), s_script_EVENT_S04E01A_L001 },
    { 292, 10, _("EVENT_S04E01A_L002"), s_script_EVENT_S04E01A_L002 },
    { 293, 12, _("EVENT_S04E01A_L002L"), s_script_EVENT_S04E01A_L002L },
    { 294, 10, _("EVENT_S04E01B_L001"), s_script_EVENT_S04E01B_L001 },
    { 295, 12, _("EVENT_S04E01B_L001L"), s_script_EVENT_S04E01B_L001L },
    { 296, 10, _("EVENT_S04E01C_L001"), s_script_EVENT_S04E01C_L001 },
    { 297, 12, _("EVENT_S04E01C_L001L"), s_script_EVENT_S04E01C_L001L },
    { 298, 10, _("EVENT_S04E01D_L001"), s_script_EVENT_S04E01D_L001 },
    { 299, 12, _("EVENT_S04E01D_L001L"), s_script_EVENT_S04E01D_L001L },
    { 300, 10, _("EVENT_S04E01E_L001"), s_script_EVENT_S04E01E_L001 },
    { 301, 12, _("EVENT_S04E01E_L001L"), s_script_EVENT_S04E01E_L001L },
    { 302, 12, _("EVENT_S04E01F_L001"), s_script_EVENT_S04E01F_L001 },
    { 303, 11, _("EVENT_S05E01A_START"), s_script_EVENT_S05E01A_START },
    { 304, 11, _("EVENT_S05E01A_CONTINUE"), s_script_EVENT_S05E01A_CONTINUE },
    { 305, 11, _("EVENT_S05E01A_END"), s_script_EVENT_S05E01A_END },
    { 306, 10, _("EVENT_S05E01A_L001"), s_script_EVENT_S05E01A_L001 },
    { 307, 12, _("EVENT_S05E01A_L002"), s_script_EVENT_S05E01A_L002 },
    { 308, 12, _("EVENT_S05E01A_L002L"), s_script_EVENT_S05E01A_L002L },
    { 309, 11, _("EVENT_S06E01A_START"), s_script_EVENT_S06E01A_START },
    { 310, 11, _("EVENT_S06E01A_CONTINUE"), s_script_EVENT_S06E01A_CONTINUE },
    { 311, 11, _("EVENT_S06E01A_END"), s_script_EVENT_S06E01A_END },
    { 312, 10, _("EVENT_S06E01A_L001"), s_script_EVENT_S06E01A_L001 },
    { 313, 10, _("EVENT_S06E01A_L002"), s_script_EVENT_S06E01A_L002 },
    { 314, 12, _("EVENT_S06E01A_L002L"), s_script_EVENT_S06E01A_L002L },
    { 315, 10, _("EVENT_S06E01B_L001"), s_script_EVENT_S06E01B_L001 },
    { 316, 10, _("EVENT_S06E01B_L002"), s_script_EVENT_S06E01B_L002 },
    { 317, 12, _("EVENT_S06E01B_L002L"), s_script_EVENT_S06E01B_L002L },
    { 318, 11, _("EVENT_S07E01A_START"), s_script_EVENT_S07E01A_START },
    { 319, 11, _("EVENT_S07E01A_END"), s_script_EVENT_S07E01A_END },
    { 320, 12, _("EVENT_S07E01A_L001"), s_script_EVENT_S07E01A_L001 },
    { 321, 12, _("EVENT_S07E01A_L002"), s_script_EVENT_S07E01A_L002 },
    { 322, 12, _("EVENT_S07E01A_L003"), s_script_EVENT_S07E01A_L003 },
    { 323, 12, _("EVENT_S07E01A_L003L"), s_script_EVENT_S07E01A_L003L },
    { 324, 11, _("EVENT_S08E01A_START"), s_script_EVENT_S08E01A_START },
    { 325, 11, _("EVENT_S08E01A_END"), s_script_EVENT_S08E01A_END },
    { 326, 12, _("EVENT_S08E01A_L001"), s_script_EVENT_S08E01A_L001 },
    { 327, 12, _("EVENT_S08E01A_L002"), s_script_EVENT_S08E01A_L002 },
    { 328, 12, _("EVENT_S08E01A_L003"), s_script_EVENT_S08E01A_L003 },
    { 329, 12, _("EVENT_S08E01A_L004"), s_script_EVENT_S08E01A_L004 },
    { 330, 12, _("EVENT_S08E01A_L005"), s_script_EVENT_S08E01A_L005 },
    { 331, 10, _("EVENT_S08E01A_L005B"), s_script_EVENT_S08E01A_L005B },
    { 332, 10, _("EVENT_S08E01A_L006"), s_script_EVENT_S08E01A_L006 },
    { 333, 12, _("EVENT_S08E01A_L006L"), s_script_EVENT_S08E01A_L006L },
    { 334, 12, _("EVENT_S08E01A_L007"), s_script_EVENT_S08E01A_L007 },
    { 335, 10, _("EVENT_S08E01A_L008"), s_script_EVENT_S08E01A_L008 },
    { 336, 12, _("EVENT_S08E01A_L008L"), s_script_EVENT_S08E01A_L008L },
    { 337, 10, _("EVENT_S08E01A_L008A"), s_script_EVENT_S08E01A_L008A },
    { 338, 10, _("EVENT_S08E01A_L008B"), s_script_EVENT_S08E01A_L008B },
    { 339, 10, _("EVENT_S08E01A_L008C"), s_script_EVENT_S08E01A_L008C },
    { 340, 11, _("EVENT_S09E01A_START"), s_script_EVENT_S09E01A_START },
    { 341, 11, _("EVENT_S09E01A_END"), s_script_EVENT_S09E01A_END },
    { 342, 12, _("EVENT_S09E01A_L001"), s_script_EVENT_S09E01A_L001 },
    { 343, 12, _("EVENT_S09E01A_L002"), s_script_EVENT_S09E01A_L002 },
    { 344, 12, _("EVENT_S09E01A_L003"), s_script_EVENT_S09E01A_L003 },
    { 345, 10, _("EVENT_S09E01A_L004"), s_script_EVENT_S09E01A_L004 },
    { 346, 10, _("EVENT_S09E01A_L004B"), s_script_EVENT_S09E01A_L004B },
    { 347, 10, _("EVENT_S09E01A_L005"), s_script_EVENT_S09E01A_L005 },
    { 348, 12, _("EVENT_S09E01A_L005L"), s_script_EVENT_S09E01A_L005L },
    { 349, 10, _("EVENT_S09E01B_L001"), s_script_EVENT_S09E01B_L001 },
    { 350, 10, _("EVENT_S09E01B_L001B"), s_script_EVENT_S09E01B_L001B },
    { 351, 10, _("EVENT_S09E01B_L002"), s_script_EVENT_S09E01B_L002 },
    { 352, 12, _("EVENT_S09E01B_L002L"), s_script_EVENT_S09E01B_L002L },
    { 353, 12, _("EVENT_S09E01C_L001"), s_script_EVENT_S09E01C_L001 },
    { 354, 7, _("EVENT_R00E01A_L001"), s_script_EVENT_R00E01A_L001 },
    { 355, 1, _("COMMON_ENTER"), s_script_COMMON_ENTER },
    { 356, 1, _("DEBUG_ENTER"), s_script_DEBUG_ENTER },
    { 357, 2, _("GETOUT_NORMAL"), NULL },
    { 358, 2, _("GETOUT_HABITAT"), s_script_GETOUT_HABITAT },
    { 359, 2, _("GETOUT_M01E01A"), s_script_GETOUT_M01E01A },
    { 360, 2, _("GETOUT_M01E02A"), s_script_GETOUT_M01E02A },
    { 361, 2, _("GETOUT_M01E02B"), s_script_GETOUT_M01E02B },
    { 362, 2, _("GETOUT_M01E03A"), s_script_GETOUT_M01E03A },
    { 363, 2, _("GETOUT_M01E04A"), s_script_GETOUT_M01E04A },
    { 364, 2, _("GETOUT_M01E04B"), s_script_GETOUT_M01E04B },
    { 365, 2, _("GETOUT_M01E05A"), s_script_GETOUT_M01E05A },
    { 366, 2, _("GETOUT_M01E07A"), s_script_GETOUT_M01E07A },
    { 367, 2, _("GETOUT_M01E07B"), s_script_GETOUT_M01E07B },
    { 368, 2, _("GETOUT_M01E08A"), s_script_GETOUT_M01E08A },
    { 369, 2, _("GETOUT_M01E08B"), s_script_GETOUT_M01E08B },
    { 370, 2, _("GETOUT_M01E09A"), s_script_GETOUT_M01E09A },
    { 371, 2, _("GETOUT_M01E10A"), s_script_GETOUT_M01E10A },
    { 372, 2, _("GETOUT_S00E01A"), s_script_GETOUT_S00E01A },
    { 373, 2, _("GETOUT_S01E01A"), s_script_GETOUT_S01E01A },
    { 374, 2, _("GETOUT_S01E02A"), s_script_GETOUT_S01E02A },
    { 375, 2, _("GETOUT_S02E01A"), s_script_GETOUT_S02E01A },
    { 376, 2, _("GETOUT_S02E02A"), s_script_GETOUT_S02E02A },
    { 377, 2, _("GETOUT_S03E01A"), s_script_GETOUT_S03E01A },
    { 378, 2, _("GETOUT_S04E01A"), s_script_GETOUT_S04E01A },
    { 379, 2, _("GETOUT_S04E01B"), s_script_GETOUT_S04E01B },
    { 380, 2, _("GETOUT_S04E01C"), s_script_GETOUT_S04E01C },
    { 381, 2, _("GETOUT_S04E01D"), s_script_GETOUT_S04E01D },
    { 382, 2, _("GETOUT_S04E01E"), s_script_GETOUT_S04E01E },
    { 383, 2, _("GETOUT_S05E01A"), s_script_GETOUT_S05E01A },
    { 384, 2, _("GETOUT_S06E01A"), s_script_GETOUT_S06E01A },
    { 385, 2, _("GETOUT_S06E01B"), s_script_GETOUT_S06E01B },
    { 386, 2, _("GETOUT_S07E01A"), s_script_GETOUT_S07E01A },
    { 387, 2, _("GETOUT_S08E01A"), s_script_GETOUT_S08E01A },
    { 388, 2, _("GETOUT_S09E01A"), s_script_GETOUT_S09E01A },
    { 389, 2, _("GETOUT_S09E01B"), s_script_GETOUT_S09E01B },
    { 390, 2, _("GETOUT_D62E01A"), s_script_GETOUT_D62E01A },
    { 391, 2, _("GETOUT_D43E01A"), s_script_GETOUT_D43E01A },
    { 392, 2, _("GETOUT_D44E01A"), s_script_GETOUT_D44E01A },
    { 393, 2, _("GETOUT_D45E01A"), s_script_GETOUT_D45E01A },
    { 394, 2, _("GETOUT_D46E01A"), s_script_GETOUT_D46E01A },
    { 395, 2, _("GETOUT_U00E01A"), s_script_GETOUT_U00E01A },
    { 396, 2, _("GETOUT_R00E01A"), s_script_GETOUT_R00E01A },
    { 397, 2, _("GETOUT_T00E01A"), s_script_GETOUT_T00E01A },
    { 398, 2, _("GETOUT_M01E07T"), s_script_GETOUT_M01E07T },
    { 399, 2, _("GETOUT_M01E08T"), s_script_GETOUT_M01E08T },
    { 400, 7, _("EVENT_CONTROL"), NULL },
    { 401, 7, _("EVENT_WAKEUP"), NULL },
    { 402, 7, _("EVENT_STATION"), NULL },
    { 403, 8, _("STATION_CONTROL"), NULL },
    { 404, 1, _("ENTER_CONTROL"), NULL },
    { 405, 7, _("SETUP_DEBUG_CAMERA"), s_script_SETUP_DEBUG_CAMERA },
    { 406, 5, _("MOVE_DEBUG_CAMERA"), s_script_MOVE_DEBUG_CAMERA },
};


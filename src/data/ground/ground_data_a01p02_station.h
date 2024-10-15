







static const struct ScriptCommand s_gs163_g0_s0_station_sref_script[] = { /* 0x82163d4 */
    DEBUGINFO,
    SELECT_MAP(163),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs163_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs163_g0_s0_station_sref_script }; /* 0x8216440 */

static const struct ScriptCommand s_gs163_g1_s0_station_sref_script[] = { /* 0x821644c */
    DEBUGINFO,
    BGM_STOP,
    SELECT_MAP(163),
    { 0x2d, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x02,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("............") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Urgggh...{WAIT_PRESS} I feel horrible...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    SELECT_ENTITIES(-1, -1),
    BGM_FADEIN(120, 29),
    { 0x22, 0x01,  0x005a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs163_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs163_g1_s0_station_sref_script }; /* 0x8216588 */


static const struct ScriptCommand s_gs163_g1_s0_lives0_dlg0[] = { /* 0x8216594 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x02,  0x0000,  0x00000002,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("This is a dream...{WAIT_PRESS} Isn't it...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...But why...?{WAIT_PRESS}\nWhy do I feel this terrible...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("This is...{WAIT_PRESS} The first time...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs163_g2_s0_station_sref_script[] = { /* 0x82166dc */
    DEBUGINFO,
    SELECT_MAP(163),
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x28, 0x01,  0x0005,  0x0000003c,  0x00ffffff, NULL },
    RET,
};

static const struct ScriptRef s_gs163_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs163_g2_s0_station_sref_script }; /* 0x821674c */

static const struct ScriptCommand s_gs163_g2_s0_lives0_dlg0[] = { /* 0x8216758 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    BGM_FADEOUT(120),
    { 0x2e, 0x02,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("..................") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......The pain......") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("......It's going away............") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};


static const struct ScriptCommand s_gs163_g3_s0_station_sref_script[] = { /* 0x8216898 */
    DEBUGINFO,
    SELECT_MAP(163),
    SELECT_ENTITIES(-1, -1),
    BGM_FADEIN(60, 37),
    { 0x22, 0x01,  0x005a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(506),
    BGM_FADEOUT(90),
    { 0x28, 0x01,  0x0005,  0x0000001e,  0x00ffffff, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs163_g3_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs163_g3_s0_station_sref_script }; /* 0x8216948 */

static const struct ScriptCommand s_gs163_g3_s0_lives0_dlg0[] = { /* 0x8216954 */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000052,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}If you fail to draw out {NAME_2}'s\n{CENTER_ALIGN}true feelings...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The curse will never be broken.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000046,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Gegege!\nHey, {NAME_0}!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Don't you dare fool around!\nI'll make you pay for it!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}You have but one chance.{WAIT_PRESS}\n{CENTER_ALIGN}{NAME_0},\n{CENTER_ALIGN}do your best.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Fine...{WAIT_PRESS} It is time.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}First of all...") },
  LABEL(2), /* = 0x02 */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}Why does {NAME_2} wish to\n{CENTER_ALIGN}break this curse?")),
    CHOICE(/* label */  4, _("To help {NAME_3}.")),
    CHOICE(/* label */  5, _("Just a whim.")),
  LABEL(5), /* = 0x05 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}............{WAIT_PRESS}Do you mean that?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}Do you truly...{WAIT_PRESS}\n{CENTER_ALIGN}truly believe that?")),
    CHOICE(/* label */  7, _("Yes.")),
    CHOICE(/* label */  8, _("No.")),
  LABEL(7), /* = 0x07 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}............{WAIT_PRESS}\n{CENTER_ALIGN}If that is truly how you feel...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}My questions\n{CENTER_ALIGN}will end now.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}You have\n{CENTER_ALIGN}no regrets?")),
    CHOICE(/* label */ 10, _("None.")),
    CHOICE(/* label */  8, _("I do.")),
  LABEL(8), /* = 0x08 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}............{WAIT_PRESS}\n{CENTER_ALIGN}Please be serious.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Let me ask you again.") },
    JUMP_LABEL(2),
  LABEL(4), /* = 0x04 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}That's a lie, isn't it?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Didn't {NAME_2} abandon\n{CENTER_ALIGN}{NAME_3} long ago?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}Why would {NAME_2}\n{CENTER_ALIGN}want to save Gardevoir now?")),
    CHOICE(/* label */ 12, _("For taking the curse.")),
    CHOICE(/* label */ 13, _("Came to understand {NAME_3}.")),
  LABEL(12), /* = 0x0c */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_3} certainly did protect\n{CENTER_ALIGN}{NAME_2} from the curse.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Sacrificing herself to do so.") },
  LABEL(14), /* = 0x0e */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}But what did {NAME_2}\n{CENTER_ALIGN}do then?")),
    CHOICE(/* label */  5, _("Tried to protect {NAME_3}.")),
    CHOICE(/* label */ 15, _("Abandoned Gardevoir and ran.")),
  LABEL(15), /* = 0x0f */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Yes...{WAIT_PRESS} {NAME_2} abandoned\n{CENTER_ALIGN}{NAME_3} and fled.") },
  LABEL(16), /* = 0x10 */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}Why did {NAME_2}\n{CENTER_ALIGN}abandon {NAME_3}?")),
    CHOICE(/* label */ 17, _("Gengar only cared about himself.")),
    CHOICE(/* label */  5, _("Gengar intended to help later.")),
  LABEL(17), /* = 0x11 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}That's right.{WAIT_PRESS}\n{CENTER_ALIGN}{NAME_2} didn't want to\n{CENTER_ALIGN}be cursed himself...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}And abandoned {NAME_3}.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}When {NAME_2} was a human,\n{CENTER_ALIGN}{NAME_3} was his partner.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}But to {NAME_2}, {NAME_3}\n{CENTER_ALIGN}was merely a tool.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}The bond between {NAME_2} and\n{CENTER_ALIGN}{NAME_3} was that flimsy...{WAIT_PRESS}\n{CENTER_ALIGN}Is that what I am hearing?")),
    CHOICE(/* label */ 19, _("Yes.")),
    CHOICE(/* label */ 20, _("No.")),
  LABEL(20), /* = 0x14 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}The bond between {NAME_2} and\n{CENTER_ALIGN}{NAME_3} you claim to be strong?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}But that makes no sense.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_3} saved {NAME_2} from\n{CENTER_ALIGN}the curse. That much is true.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}It was from her depth of\n{CENTER_ALIGN}feeling for {NAME_2}.") },
    JUMP_LABEL(14),
  LABEL(19), /* = 0x13 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}............{WAIT_PRESS}\n{CENTER_ALIGN}If that is truly how you feel...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}My questions\n{CENTER_ALIGN}will end now.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}You have\n{CENTER_ALIGN}no regrets?")),
    CHOICE(/* label */ 10, _("None.")),
    CHOICE(/* label */ 22, _("I do.")),
  LABEL(22), /* = 0x16 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}You claim that isn't true?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}But {NAME_2} abandoned\n{CENTER_ALIGN}{NAME_3}.") },
    JUMP_LABEL(16),
  LABEL(13), /* = 0x0d */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Came to understand\n{CENTER_ALIGN}{NAME_3}'s feelings?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}What is it you claim to understand?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}What do you claim to be\n{CENTER_ALIGN}{NAME_3}'s feelings?")),
    CHOICE(/* label */ 24, _("Caring for {NAME_2}.")),
    CHOICE(/* label */ 25, _("Hatred for {NAME_2}.")),
  LABEL(24), /* = 0x18 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Caring for {NAME_2}.{WAIT_PRESS}\n{CENTER_ALIGN}I see...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_3} became a presence\n{CENTER_ALIGN}without a physical form because\n{CENTER_ALIGN}she bore the curse...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}But even then, Gardevoir never\n{CENTER_ALIGN}stopped caring for {NAME_2}...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Having learned that, {NAME_2}\n{CENTER_ALIGN}now wants to save {NAME_3}...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}It makes sense...{WAIT_PRESS} However...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Until now, {NAME_2} had\n{CENTER_ALIGN}forgotten entirely about\n{CENTER_ALIGN}{NAME_3}, correct?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}But now Gengar wants to save\n{CENTER_ALIGN}Gardevoir. Isn't that asking a lot?")),
    CHOICE(/* label */ 27, _("Yes.")),
    CHOICE(/* label */ 28, _("No.")),
  LABEL(27), /* = 0x1b */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}I see...\n{CENTER_ALIGN}You say this because Gengar is\n{CENTER_ALIGN}willing to face the consequences?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gengar is coming to the help of\n{CENTER_ALIGN}Gardevoir because he wants to help...{WAIT_PRESS}\n{CENTER_ALIGN}Is that what you claim?") },
    JUMP_LABEL(10),
  LABEL(28), /* = 0x1c */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}You say that is not so...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}You believe that this is another matter?\n{CENTER_ALIGN}And to help is only natural?{WAIT_PRESS}\n{CENTER_ALIGN}That is what you believe?") },
    JUMP_LABEL(10),
  LABEL(25), /* = 0x19 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Hatred for {NAME_2}...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_3} felt hatred toward\n{CENTER_ALIGN}{NAME_2} for abandonment...{WAIT_PRESS}\n{CENTER_ALIGN}That is what you claim?") },
  LABEL(29), /* = 0x1d */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}In spite of that, {NAME_2}\n{CENTER_ALIGN}is trying to help Gardevoir...{WAIT_PRESS}\n{CENTER_ALIGN}Why should that be so?")),
    CHOICE(/* label */ 30, _("To clear up misunderstandings.")),
    CHOICE(/* label */ 31, _("To punish Gardevoir.")),
  LABEL(30), /* = 0x1e */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}I see.\n{CENTER_ALIGN}To clear up misunderstandings.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gengar hopes to help {NAME_3}\n{CENTER_ALIGN}and clear up misunderstandings...{WAIT_PRESS}\n{CENTER_ALIGN}That is what you claim?") },
    JUMP_LABEL(10),
  LABEL(31), /* = 0x1f */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Gengar would go through the trouble\n{CENTER_ALIGN}of helping {NAME_3} just so she\n{CENTER_ALIGN}could be punished?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Do you claim that seriously?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}If that is true...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}My queries will\n{CENTER_ALIGN}end now.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("{CENTER_ALIGN}May I finish now?")),
    CHOICE(/* label */ 10, _("Yes.")),
    CHOICE(/* label */ 33, _("No.")),
  LABEL(33), /* = 0x21 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}This isn't the end?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Is there anything else you wish to say?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Oh? You are confused?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}............{WAIT_PRESS}\n{CENTER_ALIGN}You must be more serious.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}Let me go back to my inquiry.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}{NAME_3} felt hatred toward\n{CENTER_ALIGN}{NAME_2} for abandonment...") },
    JUMP_LABEL(29),
  LABEL(10), /* = 0x0a */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("{CENTER_ALIGN}I understand now...\n{CENTER_ALIGN}My questions are finished.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};












static const struct ScriptCommand s_gs163_g3_s0_lives1_dlg0[] = { /* 0x8217f50 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(SHOCK_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs163_g1_s0_lives[] = { /* 0x8217fd0 */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs163_g1_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs163_g2_s0_lives[] = { /* 0x8217fe8 */
    /*  0 */ {   0,   0,   0,   0, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs163_g2_s0_lives0_dlg0,
    } },
};

static const struct GroundLivesData s_gs163_g3_s0_lives[] = { /* 0x8218000 */
    /*  0 */ {   0,   4,   0,   0, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs163_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   4,   0,   0, {  30,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs163_g3_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs163_g1_s0_effs[] = { /* 0x8218030 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs163_g2_s0_effs[] = { /* 0x821803c */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs163_g3_s0_effs[] = { /* 0x8218048 */
    /*  0 */ {   0,   0,   1,   1, {  30,  19, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8218054 */
    &s_gs163_g0_s0_station_sref,
    &s_gs163_g1_s0_station_sref,
    &s_gs163_g2_s0_station_sref,
    &s_gs163_g3_s0_station_sref,
};

static const struct GroundScriptSector s_gs163_g0_sectors[] = { /* 0x8218064 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs163_g1_sectors[] = { /* 0x821808c */
    { LPARRAY(s_gs163_g1_s0_lives), 0,NULL, LPARRAY(s_gs163_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs163_g2_sectors[] = { /* 0x82180b4 */
    { LPARRAY(s_gs163_g2_s0_lives), 0,NULL, LPARRAY(s_gs163_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptSector s_gs163_g3_sectors[] = { /* 0x82180dc */
    { LPARRAY(s_gs163_g3_s0_lives), 0,NULL, LPARRAY(s_gs163_g3_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs163_groups[] = { /* 0x8218104 */
    { LPARRAY(s_gs163_g0_sectors) },
    { LPARRAY(s_gs163_g1_sectors) },
    { LPARRAY(s_gs163_g2_sectors) },
    { LPARRAY(s_gs163_g3_sectors) },
};

static const struct GroundLink s_gs163_links[] = { /* 0x8218124 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs163 = { LPARRAY(s_gs163_groups), s_gs163_links }; /* 0x821812c */









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
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...Urgggh...#W I feel horrible...") },
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
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("This is a dream...#W Isn't it...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("...But why...?#W\nWhy do I feel this terrible...?") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("This is...#W The first time...") },
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
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+If you fail to draw out $n2's\n#+true feelings...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The curse will never be broken.") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0002,  0x00000046,  0x00000000, NULL },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Gegege!\nHey, $n0!") },
    { 0x34, 0x00,  0x0002,  0x00000000,  0x00000000, _(" Don't you dare fool around!\nI'll make you pay for it!") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+You have but one chance.#W\n#+$n0,\n#+do your best.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Fine...#W It is time.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+First of all...") },
  LABEL(2), /* = 0x02 */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+Why does $n2 wish to\n#+break this curse?")),
    CHOICE(/* label */  4, _("To help $n3.")),
    CHOICE(/* label */  5, _("Just a whim.")),
  LABEL(5), /* = 0x05 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+............#WDo you mean that?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+Do you truly...#W\n#+truly believe that?")),
    CHOICE(/* label */  7, _("Yes.")),
    CHOICE(/* label */  8, _("No.")),
  LABEL(7), /* = 0x07 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+............#W\n#+If that is truly how you feel...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+My questions\n#+will end now.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+You have\n#+no regrets?")),
    CHOICE(/* label */ 10, _("None.")),
    CHOICE(/* label */  8, _("I do.")),
  LABEL(8), /* = 0x08 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+............#W\n#+Please be serious.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Let me ask you again.") },
    JUMP_LABEL(2),
  LABEL(4), /* = 0x04 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+That's a lie, isn't it?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Didn't $n2 abandon\n#+$n3 long ago?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+Why would $n2\n#+want to save Gardevoir now?")),
    CHOICE(/* label */ 12, _("For taking the curse.")),
    CHOICE(/* label */ 13, _("Came to understand $n3.")),
  LABEL(12), /* = 0x0c */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n3 certainly did protect\n#+$n2 from the curse.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Sacrificing herself to do so.") },
  LABEL(14), /* = 0x0e */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+But what did $n2\n#+do then?")),
    CHOICE(/* label */  5, _("Tried to protect $n3.")),
    CHOICE(/* label */ 15, _("Abandoned Gardevoir and ran.")),
  LABEL(15), /* = 0x0f */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Yes...#W $n2 abandoned\n#+$n3 and fled.") },
  LABEL(16), /* = 0x10 */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+Why did $n2\n#+abandon $n3?")),
    CHOICE(/* label */ 17, _("Gengar only cared about himself.")),
    CHOICE(/* label */  5, _("Gengar intended to help later.")),
  LABEL(17), /* = 0x11 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+That's right.#W\n#+$n2 didn't want to\n#+be cursed himself...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+And abandoned $n3.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+When $n2 was a human,\n#+$n3 was his partner.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But to $n2, $n3\n#+was merely a tool.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+The bond between $n2 and\n#+$n3 was that flimsy...#W\n#+Is that what I am hearing?")),
    CHOICE(/* label */ 19, _("Yes.")),
    CHOICE(/* label */ 20, _("No.")),
  LABEL(20), /* = 0x14 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+The bond between $n2 and\n#+$n3 you claim to be strong?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But that makes no sense.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n3 saved $n2 from\n#+the curse. That much is true.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+It was from her depth of\n#+feeling for $n2.") },
    JUMP_LABEL(14),
  LABEL(19), /* = 0x13 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+............#W\n#+If that is truly how you feel...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+My questions\n#+will end now.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+You have\n#+no regrets?")),
    CHOICE(/* label */ 10, _("None.")),
    CHOICE(/* label */ 22, _("I do.")),
  LABEL(22), /* = 0x16 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+You claim that isn't true?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But $n2 abandoned\n#+$n3.") },
    JUMP_LABEL(16),
  LABEL(13), /* = 0x0d */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Came to understand\n#+$n3's feelings?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+What is it you claim to understand?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+What do you claim to be\n#+$n3's feelings?")),
    CHOICE(/* label */ 24, _("Caring for $n2.")),
    CHOICE(/* label */ 25, _("Hatred for $n2.")),
  LABEL(24), /* = 0x18 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Caring for $n2.#W\n#+I see...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n3 became a presence\n#+without a physical form because\n#+she bore the curse...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+But even then, Gardevoir never\n#+stopped caring for $n2...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Having learned that, $n2\n#+now wants to save $n3...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+It makes sense...#W However...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Until now, $n2 had\n#+forgotten entirely about\n#+$n3, correct?") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+But now Gengar wants to save\n#+Gardevoir. Isn't that asking a lot?")),
    CHOICE(/* label */ 27, _("Yes.")),
    CHOICE(/* label */ 28, _("No.")),
  LABEL(27), /* = 0x1b */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+I see...\n#+You say this because Gengar is\n#+willing to face the consequences?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Gengar is coming to the help of\n#+Gardevoir because he wants to help...#W\n#+Is that what you claim?") },
    JUMP_LABEL(10),
  LABEL(28), /* = 0x1c */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+You say that is not so...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+You believe that this is another matter?\n#+And to help is only natural?#W\n#+That is what you believe?") },
    JUMP_LABEL(10),
  LABEL(25), /* = 0x19 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Hatred for $n2...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n3 felt hatred toward\n#+$n2 for abandonment...#W\n#+That is what you claim?") },
  LABEL(29), /* = 0x1d */
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+In spite of that, $n2\n#+is trying to help Gardevoir...#W\n#+Why should that be so?")),
    CHOICE(/* label */ 30, _("To clear up misunderstandings.")),
    CHOICE(/* label */ 31, _("To punish Gardevoir.")),
  LABEL(30), /* = 0x1e */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+I see.\n#+To clear up misunderstandings.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Gengar hopes to help $n3\n#+and clear up misunderstandings...#W\n#+That is what you claim?") },
    JUMP_LABEL(10),
  LABEL(31), /* = 0x1f */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Gengar would go through the trouble\n#+of helping $n3 just so she\n#+could be punished?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Do you claim that seriously?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+If that is true...") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+My queries will\n#+end now.") },
    ASK2(FALSE, /*default*/ -1, /* speaker */ -1, _("#+May I finish now?")),
    CHOICE(/* label */ 10, _("Yes.")),
    CHOICE(/* label */ 33, _("No.")),
  LABEL(33), /* = 0x21 */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+This isn't the end?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Is there anything else you wish to say?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Oh? You are confused?") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+............#W\n#+You must be more serious.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+Let me go back to my inquiry.") },
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+$n3 felt hatred toward\n#+$n2 for abandonment...") },
    JUMP_LABEL(29),
  LABEL(10), /* = 0x0a */
    { 0x33, 0x00, -0x0001,  0x00000000,  0x00000000, _("#+I understand now...\n#+My questions are finished.") },
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

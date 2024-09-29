












static const struct ScriptCommand s_gs167_g0_s0_station_sref_script[] = { /* 0x8219784 */
    DEBUGINFO,
    SELECT_MAP(167),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs167_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs167_g0_s0_station_sref_script }; /* 0x82197f0 */

static const struct ScriptCommand s_gs167_g1_s0_station_sref_script[] = { /* 0x82197fc */
    DEBUGINFO,
    SELECT_MAP(167),
    SELECT_ENTITIES(-1, 0),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs167_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs167_g1_s0_station_sref_script }; /* 0x821986c */

static const struct ScriptCommand s_gs167_g2_s0_station_sref_script[] = { /* 0x8219878 */
    DEBUGINFO,
    SELECT_MAP(167),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(24),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0000,  0x00000021,  0x00000000, NULL },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+And so, $n0's\n#+harrowing journey continued.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Seeking refuge in\n#+even harsher places...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+They fled north.") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+They crossed row upon\n#+row of mountains...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Forded fetid swamps...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Scaled frozen cliffs...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+Till finally, $n0's tiny team\n#+arrived in a world of snow...") },
    { 0x39, 0x00,  0x001e,  0x00000000,  0x00000000, _("#+A frigid wasteland of\n#+driving blizzards.") },
    BGM_FADEOUT(120),
    { 0xe0, 0x00,  0x0018,  0x00000000,  0x00000000, NULL },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs167_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs167_g2_s0_station_sref_script }; /* 0x8219b4c */


static const struct ScriptCommand s_gs167_g2_s0_eff0_script[] = { /* 0x8219b58 */
    DEBUGINFO,
    { 0x99, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000003,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(45),
    { 0x23, 0x00,  0x005a,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs167_g2_s0_lives0_dlg0[] = { /* 0x8219c28 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    { 0x93, 0x04,  0x000b,  0x00000022,  0x00000000, NULL },
    WAIT(80),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Gasp, gasp...\nWe've done a lot of walking.")),
    VARIANT(/* == */  1, _(" I'm beat.\nLet's get some rest.")),
    VARIANT(/* == */  3, _(" Pant, pant...\nWe walked a lot, didn't we?")),
    VARIANT(/* == */  3, _(" I'm tired.\nLet's get a little rest.")),
    VARIANT_DEFAULT(_(" Pant, pant...\nWe sure walked a lot.")),
    VARIANT_DEFAULT(_(" I'm bushed.\nLet's rest up.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Haaah!\nThe view's great here.")),
    VARIANT_DEFAULT(_(" Mmm...\nThe view's fantastic.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(465),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Oh, hey!\n$n0, you have to see this!")),
    VARIANT_DEFAULT(_(" Oh, look!\n$n0, look over there!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Look at that.\nSee how small Mt. Blaze looks?")),
    VARIANT(/* == */  1, _(" We sure came a long way...")),
    VARIANT_DEFAULT(_(" See how small Mt. Blaze\nlooks from here?")),
    VARIANT_DEFAULT(_(" We've come a really long\nway, haven't we?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............#WHey, $n0.")),
    VARIANT(/* == */  3, _(" ............#WUm, $n0?")),
    VARIANT_DEFAULT(_(" ............#W$n0.")),
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" You remember how tough it\nwas getting over Mt. Blaze, right?")),
    VARIANT(/* == */  1, _(" I don't think many Pokémon\ncan get through there.")),
    VARIANT(/* == */  1, _(" And, after that, we\nreally went at it hard to get here.")),
    VARIANT(/* == */  1, _(" You know what I really\nthink?")),
    VARIANT(/* == */  3, _(" Wasn't it hard getting over\nMt. Blaze?")),
    VARIANT(/* == */  3, _(" I doubt that many Pokémon\nwill be able to get through it.")),
    VARIANT(/* == */  3, _(" And it wasn't easy coming\nthis far after that mountain.")),
    VARIANT(/* == */  3, _(" Do you want to know what\nI think?")),
    VARIANT_DEFAULT(_(" Do you remember how hard\nit was to get across Mt. Blaze?")),
    VARIANT_DEFAULT(_(" I don't think too many\nPokémon can get through there.")),
    VARIANT_DEFAULT(_(" And then we gave it our\nall to get out here.")),
    VARIANT_DEFAULT(_(" Do you know what I'm\nthinking?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001, -0x00000002,  0x00000000, NULL },
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Maybe there aren't any more\nPokémon that can chase us all the way\nhere.")),
    VARIANT(/* == */  3, _(" Do you think, maybe, that no\nPokémon will be able to get to us here?")),
    VARIANT_DEFAULT(_(" We've come so far, maybe\nthere aren't any more Pokémon that can\nget to us.")),
    CHOICE(/* label */  2, _("No. There are others.")),
    CHOICE(/* label */  3, _("You're right. No one can get us, hahaha...")),
  LABEL(2), /* = 0x02 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(455),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x03,  0x0001,  0x0000000c,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" What?#W There are others?")),
    VARIANT(/* == */  1, _(" Who might they be?")),
    VARIANT_DEFAULT(_(" Oh?#W There's someone else?")),
    VARIANT_DEFAULT(_(" Well, who do you mean?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x2e, 0x15,  0x0001,  0x00000005,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...#WOh, right.#W\nAlakazam's still out there.")),
    VARIANT(/* == */  1, _(" Their team should be able\nto get here...")),
    VARIANT_DEFAULT(_(" ...#WOh, I get it.#W\nThere's Alakazam.")),
    VARIANT_DEFAULT(_(" You're right.\nAlakazam's team should be able to get\nhere.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(4),
  LABEL(3), /* = 0x03 */
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0x2e, 0x03,  0x0001,  0x0000000b,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" I knew it!\nI knew you'd say that too, $n0!")),
    VARIANT_DEFAULT(_(" I thought so!\nYou think so too, $n0, right?!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Yeah, you're right.\nThere can't be anyone else.\nHahahahaha.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" All right!\nWe can say good-bye to living like\nfugitives.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" We don't have to keep\nrunning away anymore!\nHahahahaha.") },
    { 0x34, 0x00,  0x0001,  0x00000000,  0x00000000, _(" Hahahaha...#W Haha...") },
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x2e, 0x15,  0x0001,  0x00000002,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ..................#W\nThis is no good, $n0.")),
    VARIANT(/* == */  1, _(" We forgot about some\ntough customers.")),
    VARIANT(/* == */  1, _(" Alakazam.#W\nHis team won't drop the chase ever.")),
    VARIANT_DEFAULT(_(" ........................#W\nIt's no good, $n0.")),
    VARIANT_DEFAULT(_(" We've forgotten some\ntough customers.")),
    VARIANT_DEFAULT(_(" It's Alakazam's team.#W\nThey'll keep chasing us wherever we go.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_LABEL(4),
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 0),
  LABEL(4), /* = 0x04 */
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" We're not out of this yet.\nLet's get going.")),
    VARIANT(/* == */  1, _(" We'd better go somewhere\nnobody can get to.\nThat'd be best.")),
    VARIANT_DEFAULT(_(" Yup! We don't have a choice.\nWe have to keep going.")),
    VARIANT_DEFAULT(_(" I think we need to go\nsomewhere no one else can get to.")),
    { 0x2e, 0x15,  0x0001,  0x00000009,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Let's knuckle down and keep\ngoing.")),
    VARIANT_DEFAULT(_(" Let's be positive and keep\nmoving.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000000,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh?#W What's the matter?\nAren't you coming, $n0?")),
    VARIANT(/* == */  3, _(" Oh?#W What's wrong?\nAren't we going, $n0?")),
    VARIANT_DEFAULT(_(" Huh?#W What's the matter?\nAren't you coming, $n0?")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x0a,  0x000b,  0x00000007,  0x00000000, NULL },
    WAIT(30),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...#WWhat?#W\nAren't I tired, you're asking?")),
    VARIANT(/* == */  1, _(" We're being chased!\nWe can't rest.")),
    VARIANT(/* == */  1, _(" And...#W\nI told you, didn't I?")),
    VARIANT(/* == */  1, _(" I said I'd go with you,\n$n0.")),
    VARIANT(/* == */  3, _(" ...#WPardon?#W\nAm I tired?")),
    VARIANT(/* == */  3, _(" They're trying to catch us.\nWe don't have time to rest.")),
    VARIANT(/* == */  3, _(" And...#W\nRemember what I said?")),
    VARIANT(/* == */  3, _(" I said I would go with\nyou, $n0.")),
    VARIANT_DEFAULT(_(" ...#WHuh?#W\nAm I tired?")),
    VARIANT_DEFAULT(_(" They're chasing us down.\nWe can't afford to rest.\n")),
    VARIANT_DEFAULT(_(" And...#W\nI told you already.")),
    VARIANT_DEFAULT(_(" I said I would go with\nyou, $n0.")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2e, 0x15,  0x0001,  0x00000001,  0x00000000, NULL },
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...Don't look that way\nat me!\nI'm good. I'm good!")),
    VARIANT(/* == */  1, _(" Let's roll, $n0!\nI'll go with you wherever you go!")),
    VARIANT(/* == */  3, _(" ...Oh, please don't look\nlike that.\nHonest, I'm fine.")),
    VARIANT(/* == */  3, _(" Let's go, $n0!\nI'll always stick with you!")),
    VARIANT_DEFAULT(_(" ...Oh, come on.\nNo need for that long face.\nI'm fine.")),
    VARIANT_DEFAULT(_(" Let's go, $n0!\nI'll go wherever you go!")),
    { 0x30, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x6b, 0x00,  0x0099,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};



static const struct ScriptCommand s_gs167_g2_s0_lives1_dlg0[] = { /* 0x821b5d4 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WAIT(10),
    { 0x6b, 0x00,  0x0099,  0x00000002,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x002d,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x10,  0x0099,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(NOTICE_FUNC),
    WAIT(15),
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x000b,  0x00000007,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 1, /* to label */ 0),
    CALL_SCRIPT(JUMP_SURPRISE_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    JUMPIF(JUDGE_EQ, EVENT_LOCAL, 0, /* to label */ 1),
  LABEL(0), /* = 0x00 */
    CALL_SCRIPT(SMILE_START_FUNC),
    WAIT(30),
    CALL_SCRIPT(SMILE_END_FUNC),
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
  LABEL(1), /* = 0x01 */
    { 0x54, 0x00,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(160),
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000003,  0x00000000, NULL },
    WAIT(30),
    { 0x91, 0x04,  0x000b,  0x00000003,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0099,  0x00000004,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs167_g2_s0_lives[] = { /* 0x821b904 */
    /*  0 */ {   0,   6,   0,   0, {  29,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs167_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   6,   0,   0, {  31,  38, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs167_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs167_g1_s0_effs[] = { /* 0x821b934 */
    /*  0 */ {   0,   0,   1,   1, {  16,   8, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs167_g2_s0_effs[] = { /* 0x821b940 */
    /*  0 */ {   0,   0,   1,   1, {  16,   8, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs167_g2_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x821b94c */
    &s_gs167_g0_s0_station_sref,
    &s_gs167_g1_s0_station_sref,
    &s_gs167_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs167_g0_sectors[] = { /* 0x821b958 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs167_g1_sectors[] = { /* 0x821b980 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs167_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs167_g2_sectors[] = { /* 0x821b9a8 */
    { LPARRAY(s_gs167_g2_s0_lives), 0,NULL, LPARRAY(s_gs167_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs167_groups[] = { /* 0x821b9d0 */
    { LPARRAY(s_gs167_g0_sectors) },
    { LPARRAY(s_gs167_g1_sectors) },
    { LPARRAY(s_gs167_g2_sectors) },
};

static const struct GroundLink s_gs167_links[] = { /* 0x821b9e8 */
    /* link   0 */ { { /*x*/  16, /*y*/  37, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  14, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  18, /*y*/  38, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  12, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   4 */ { { /*x*/   1, /*y*/  40, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs167 = { LPARRAY(s_gs167_groups), s_gs167_links }; /* 0x821ba10 */

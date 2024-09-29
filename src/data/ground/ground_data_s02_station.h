


















static const struct ScriptCommand s_gs224_g0_s0_station_sref_script[] = { /* 0x826e29c */
    DEBUGINFO,
    SELECT_MAP(224),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs224_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs224_g0_s0_station_sref_script }; /* 0x826e308 */

static const struct ScriptCommand s_gs224_g1_s0_obj0_dlg1[] = { /* 0x826e314 */
    DEBUGINFO,
    { 0x54, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x5b, 0x00,  0x0000,  0x00000001,  0x00000000, NULL },
    WAIT(10),
    { 0x5b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(10),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_gs224_g2_s0_station_sref_script[] = { /* 0x826e3a4 */
    DEBUGINFO,
    SELECT_MAP(224),
    SELECT_ENTITIES(1, 0),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(46),
    WAIT(60),
    { 0x22, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(480),
    BGM_FADEOUT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs224_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs224_g2_s0_station_sref_script }; /* 0x826e454 */

static const struct ScriptCommand s_gs224_g3_s0_station_sref_script[] = { /* 0x826e460 */
    DEBUGINFO,
    SELECT_MAP(224),
    SELECT_ENTITIES(1, 0),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(43),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    SELECT_ENTITIES(-1, 1),
    SELECT_ENTITIES(-1, 2),
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, EVENT_LOCAL, 1),
    { 0x3b, 0x40,  0x0001,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe0, 0x00,  0x002b,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs224_g3_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs224_g3_s0_station_sref_script }; /* 0x826e570 */

static const struct ScriptCommand s_gs224_g3_s0_eff0_script[] = { /* 0x826e57c */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x5b, 0x00,  0x0000,  0x00000003,  0x00000000, NULL },
    WAIT(10),
    { 0x5b, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    WAIT(10),
    JUMP_LABEL(0),
};

static const struct ScriptCommand s_gs224_g3_s1_lives0_dlg0[] = { /* 0x826e60c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0200,  0x00000004,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs224_g3_s1_obj0_dlg0[] = { /* 0x826e6dc */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    WAIT(32),
    { 0x53, 0x00,  0x0000,  0x00400000,  0x00000000, NULL },
    { 0x54, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0400,  0x00000005,  0x00000000, NULL },
    { 0x54, 0x00,  0x000b,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0500,  0x00000006,  0x00000000, NULL },
    { 0x54, 0x00,  0x000c,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0600,  0x00000007,  0x00000000, NULL },
    { 0x54, 0x00,  0x000d,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0700,  0x00000008,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs224_g3_s2_obj0_dlg0[] = { /* 0x826e81c */
    DEBUGINFO,
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00080000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00040000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x54, 0x00,  0x0008,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0033,  0x00000009,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0x80, 0x00,  0x0033,  0x0000000a,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs224_g4_s0_station_sref_script[] = { /* 0x826e8bc */
    DEBUGINFO,
    SELECT_MAP(224),
    SELECT_ENTITIES(1, 0),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(43),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    { 0xe4, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xe0, 0x00,  0x002b,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs224_g4_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs224_g4_s0_station_sref_script }; /* 0x826e97c */

static const struct ScriptCommand s_gs224_g4_s0_eff0_script[] = { /* 0x826e988 */
    DEBUGINFO,
    { 0x98, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
  LABEL(0), /* = 0x00 */
    { 0x5b, 0x00,  0x0000,  0x00000003,  0x00000000, NULL },
    WAIT(10),
    { 0x5b, 0x00,  0x0000,  0x00000002,  0x00000000, NULL },
    WAIT(10),
    JUMP_LABEL(0),
};

static const struct GroundLivesData s_gs224_g3_s1_lives[] = { /* 0x826ea18 */
    /*  0 */ {  55,   6,   0,   0, {  35,   6, 0, CPOS_HALFTILE }, {
        [0] = s_gs224_g3_s1_lives0_dlg0,
    } },
};

static const struct GroundObjectData s_gs224_g1_s0_objs[] = { /* 0x826ea30 */
    /*  0 */ {  61,   0,   2,   1, {  18,  21, 0, 0 }, {
        [1] = s_gs224_g1_s0_obj0_dlg1,
    } },
};

static const struct GroundObjectData s_gs224_g3_s1_objs[] = { /* 0x826ea48 */
    /*  0 */ {  59,   6,   2,   1, {   1,  22, 0, CPOS_HALFTILE }, {
        [0] = s_gs224_g3_s1_obj0_dlg0,
    } },
};

static const struct GroundObjectData s_gs224_g3_s2_objs[] = { /* 0x826ea60 */
    /*  0 */ {  60,   0,   2,   1, {  26,   0, 0, CPOS_HALFTILE }, {
        [0] = s_gs224_g3_s2_obj0_dlg0,
    } },
};

static const struct GroundEffectData s_gs224_g2_s0_effs[] = { /* 0x826ea78 */
    /*  0 */ {   0,   0,   1,   1, {  18,  14, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs224_g3_s0_effs[] = { /* 0x826ea84 */
    /*  0 */ {   0,   0,   1,   1, {  18,  14, 0, CPOS_HALFTILE }, s_gs224_g3_s0_eff0_script },
};

static const struct GroundEffectData s_gs224_g4_s0_effs[] = { /* 0x826ea90 */
    /*  0 */ {   0,   0,   1,   1, {  18,  14, 0, CPOS_HALFTILE }, s_gs224_g4_s0_eff0_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x826ea9c */
    &s_gs224_g0_s0_station_sref,
    &s_gs224_g2_s0_station_sref,
    &s_gs224_g3_s0_station_sref,
    &s_gs224_g4_s0_station_sref,
};

static const struct GroundScriptSector s_gs224_g0_sectors[] = { /* 0x826eaac */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs224_g1_sectors[] = { /* 0x826ead4 */
    { 0,NULL, LPARRAY(s_gs224_g1_s0_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs224_g2_sectors[] = { /* 0x826eafc */
    { 0,NULL, 0,NULL, LPARRAY(s_gs224_g2_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs224_g3_sectors[] = { /* 0x826eb24 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs224_g3_s0_effs), 0,NULL, 1,&sStationScripts[2], },
    { LPARRAY(s_gs224_g3_s1_lives), LPARRAY(s_gs224_g3_s1_objs), 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, LPARRAY(s_gs224_g3_s2_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs224_g4_sectors[] = { /* 0x826eb9c */
    { 0,NULL, 0,NULL, LPARRAY(s_gs224_g4_s0_effs), 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptGroup s_gs224_groups[] = { /* 0x826ebc4 */
    { LPARRAY(s_gs224_g0_sectors) },
    { LPARRAY(s_gs224_g1_sectors) },
    { LPARRAY(s_gs224_g2_sectors) },
    { LPARRAY(s_gs224_g3_sectors) },
    { LPARRAY(s_gs224_g4_sectors) },
};

static const struct GroundLink s_gs224_links[] = { /* 0x826ebec */
    /* link   0 */ { { /*x*/  18, /*y*/  21, /*flags*/ 0, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  18, /*y*/  48, /*flags*/ 0, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   2 */ { { /*x*/  18, /*y*/  14, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   3 */ { { /*x*/  18, /*y*/  41, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   4 */ { { /*x*/   1, /*y*/   6, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   5 */ { { /*x*/  10, /*y*/  20, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   6 */ { { /*x*/  19, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   7 */ { { /*x*/  28, /*y*/  10, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   8 */ { { /*x*/  35, /*y*/   4, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link   9 */ { { /*x*/  26, /*y*/   6, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
    /* link  10 */ { { /*x*/  26, /*y*/  12, /*flags*/ 0, 0 }, /*w*/  1, /*h*/  1, /*ret*/ 2, /*?*/ 1 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs224 = { LPARRAY(s_gs224_groups), s_gs224_links }; /* 0x826ec44 */

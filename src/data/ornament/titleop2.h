static const axmain sAxMainTitleop2;
const SiroArchive gAxTitleop2 = {"SIRO", &sAxMainTitleop2};

static const ax_pose sTitleop2Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_1[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_2[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {1, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {2, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {3, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 0, .offset = {4, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {3, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {2, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {1, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {-1, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {-2, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {-3, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 0, .offset = {-4, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {-3, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {-2, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {-1, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_3[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_4[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_5[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_6[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_7[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_8[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sTitleop2Gfx1[] = INCBIN_U8("graphics/ornament/Titleop2/sprite_1.4bpp");
static const u8 sTitleop2Gfx1_2[] = INCBIN_U8("graphics/ornament/Titleop2/sprite_1_2.4bpp");
static const ax_sprite sTitleop2Sprites1[] = {
	{sTitleop2Gfx1, ARRAY_COUNT(sTitleop2Gfx1)},
	{NULL, 32},
	{sTitleop2Gfx1_2, ARRAY_COUNT(sTitleop2Gfx1_2)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesTitleop2[] = {
	sTitleop2Pose1,
};

static const ax_anim *const sTitleop2AnimTable1[] = {
	sTitleop2Anims_1_1,
	sTitleop2Anims_1_2,
	sTitleop2Anims_1_3,
	sTitleop2Anims_1_4,
	sTitleop2Anims_1_5,
	sTitleop2Anims_1_6,
	sTitleop2Anims_1_7,
	sTitleop2Anims_1_8,
};

static const ax_anim *const *const sAxAnimationsTitleop2[] = {
	sTitleop2AnimTable1,
};

static const ax_sprite *const sAxSpritesTitleop2[] = {
	sTitleop2Sprites1,
};

static const axmain sAxMainTitleop2 = {
	.poses = sAxPosesTitleop2,
	.animations = sAxAnimationsTitleop2,
	.animCount = ARRAY_COUNT(sAxAnimationsTitleop2),
	.spriteData = sAxSpritesTitleop2,
	.positions = NULL,
};
const RGB_Struct gTitleopPal[] = { INCBIN_RGB("graphics/ornament/pal/titleop.pmdpal") };

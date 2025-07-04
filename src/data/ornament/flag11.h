static const axmain sAxMainFlag114;
const SiroArchive gAxFlag114 = {"SIRO", &sAxMainFlag114};

static const ax_pose sFlag114Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag114Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag114Gfx1[] = INCBIN_U8("graphics/ornament/Flag114/sprite_1.4bpp");
static const ax_sprite sFlag114Sprites1[] = {
	{sFlag114Gfx1, ARRAY_COUNT(sFlag114Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx2[] = INCBIN_U8("graphics/ornament/Flag114/sprite_2.4bpp");
static const ax_sprite sFlag114Sprites2[] = {
	{sFlag114Gfx2, ARRAY_COUNT(sFlag114Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx3[] = INCBIN_U8("graphics/ornament/Flag114/sprite_3.4bpp");
static const ax_sprite sFlag114Sprites3[] = {
	{sFlag114Gfx3, ARRAY_COUNT(sFlag114Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx4[] = INCBIN_U8("graphics/ornament/Flag114/sprite_4.4bpp");
static const ax_sprite sFlag114Sprites4[] = {
	{sFlag114Gfx4, ARRAY_COUNT(sFlag114Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx5[] = INCBIN_U8("graphics/ornament/Flag114/sprite_5.4bpp");
static const ax_sprite sFlag114Sprites5[] = {
	{sFlag114Gfx5, ARRAY_COUNT(sFlag114Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx6[] = INCBIN_U8("graphics/ornament/Flag114/sprite_6.4bpp");
static const ax_sprite sFlag114Sprites6[] = {
	{sFlag114Gfx6, ARRAY_COUNT(sFlag114Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag114[] = {
	sFlag114Pose1,
	sFlag114Pose2,
	sFlag114Pose3,
	sFlag114Pose4,
	sFlag114Pose5,
	sFlag114Pose6,
};

static const ax_anim *const sFlag114AnimTable1[] = {
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag114[] = {
	sFlag114AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag114[] = {
	sFlag114Sprites1,
	sFlag114Sprites2,
	sFlag114Sprites3,
	sFlag114Sprites4,
	sFlag114Sprites5,
	sFlag114Sprites6,
};

static const axmain sAxMainFlag114 = {
	.poses = sAxPosesFlag114,
	.animations = sAxAnimationsFlag114,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag114),
	.spriteData = sAxSpritesFlag114,
	.positions = NULL,
};
const RGB gFlag11Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag11.pmdpal") };

static const axmain sAxMainFlag11;
const SiroArchive gAxFlag11 = {"SIRO", &sAxMainFlag11};

static const ax_pose sFlag11Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag11Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag11Gfx1[] = INCBIN_U8("graphics/ornament/Flag11/sprite_1.4bpp");
static const ax_sprite sFlag11Sprites1[] = {
	{sFlag11Gfx1, ARRAY_COUNT(sFlag11Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx2[] = INCBIN_U8("graphics/ornament/Flag11/sprite_2.4bpp");
static const ax_sprite sFlag11Sprites2[] = {
	{sFlag11Gfx2, ARRAY_COUNT(sFlag11Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx3[] = INCBIN_U8("graphics/ornament/Flag11/sprite_3.4bpp");
static const ax_sprite sFlag11Sprites3[] = {
	{sFlag11Gfx3, ARRAY_COUNT(sFlag11Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx4[] = INCBIN_U8("graphics/ornament/Flag11/sprite_4.4bpp");
static const ax_sprite sFlag11Sprites4[] = {
	{sFlag11Gfx4, ARRAY_COUNT(sFlag11Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx5[] = INCBIN_U8("graphics/ornament/Flag11/sprite_5.4bpp");
static const ax_sprite sFlag11Sprites5[] = {
	{sFlag11Gfx5, ARRAY_COUNT(sFlag11Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx6[] = INCBIN_U8("graphics/ornament/Flag11/sprite_6.4bpp");
static const ax_sprite sFlag11Sprites6[] = {
	{sFlag11Gfx6, ARRAY_COUNT(sFlag11Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag11[] = {
	sFlag11Pose1,
	sFlag11Pose2,
	sFlag11Pose3,
	sFlag11Pose4,
	sFlag11Pose5,
	sFlag11Pose6,
};

static const ax_anim *const sFlag11AnimTable1[] = {
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag11[] = {
	sFlag11AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag11[] = {
	sFlag11Sprites1,
	sFlag11Sprites2,
	sFlag11Sprites3,
	sFlag11Sprites4,
	sFlag11Sprites5,
	sFlag11Sprites6,
};

static const axmain sAxMainFlag11 = {
	.poses = sAxPosesFlag11,
	.animations = sAxAnimationsFlag11,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag11),
	.spriteData = sAxSpritesFlag11,
	.positions = NULL,
};

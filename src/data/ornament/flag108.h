const RGB gFlag108Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag108.pmdpal") };

static const axmain sAxMainFlag108;
const SiroArchive gAxFlag108 = {"SIRO", &sAxMainFlag108};

static const ax_pose sFlag108Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag108Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag108Gfx1[] = INCBIN_U8("graphics/ornament/Flag108/sprite_1.4bpp");
static const ax_sprite sFlag108Sprites1[] = {
	{sFlag108Gfx1, ARRAY_COUNT(sFlag108Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx2[] = INCBIN_U8("graphics/ornament/Flag108/sprite_2.4bpp");
static const ax_sprite sFlag108Sprites2[] = {
	{sFlag108Gfx2, ARRAY_COUNT(sFlag108Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx3[] = INCBIN_U8("graphics/ornament/Flag108/sprite_3.4bpp");
static const ax_sprite sFlag108Sprites3[] = {
	{sFlag108Gfx3, ARRAY_COUNT(sFlag108Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx4[] = INCBIN_U8("graphics/ornament/Flag108/sprite_4.4bpp");
static const ax_sprite sFlag108Sprites4[] = {
	{sFlag108Gfx4, ARRAY_COUNT(sFlag108Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx5[] = INCBIN_U8("graphics/ornament/Flag108/sprite_5.4bpp");
static const ax_sprite sFlag108Sprites5[] = {
	{sFlag108Gfx5, ARRAY_COUNT(sFlag108Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx6[] = INCBIN_U8("graphics/ornament/Flag108/sprite_6.4bpp");
static const ax_sprite sFlag108Sprites6[] = {
	{sFlag108Gfx6, ARRAY_COUNT(sFlag108Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag108[] = {
	sFlag108Pose1,
	sFlag108Pose2,
	sFlag108Pose3,
	sFlag108Pose4,
	sFlag108Pose5,
	sFlag108Pose6,
};

static const ax_anim *const sFlag108AnimTable1[] = {
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag108[] = {
	sFlag108AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag108[] = {
	sFlag108Sprites1,
	sFlag108Sprites2,
	sFlag108Sprites3,
	sFlag108Sprites4,
	sFlag108Sprites5,
	sFlag108Sprites6,
};

static const axmain sAxMainFlag108 = {
	.poses = sAxPosesFlag108,
	.animations = sAxAnimationsFlag108,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag108),
	.spriteData = sAxSpritesFlag108,
	.positions = NULL,
};

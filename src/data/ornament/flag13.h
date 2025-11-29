const RGB_Struct gFlag13Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag13.pmdpal") };

static const axmain sAxMainFlag13;
const SiroArchive gAxFlag13 = {"SIRO", &sAxMainFlag13};

static const ax_pose sFlag13Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag13Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag13Gfx1[] = INCBIN_U8("graphics/ornament/Flag13/sprite_1.4bpp");
static const ax_sprite sFlag13Sprites1[] = {
	{sFlag13Gfx1, ARRAY_COUNT(sFlag13Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx2[] = INCBIN_U8("graphics/ornament/Flag13/sprite_2.4bpp");
static const ax_sprite sFlag13Sprites2[] = {
	{sFlag13Gfx2, ARRAY_COUNT(sFlag13Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx3[] = INCBIN_U8("graphics/ornament/Flag13/sprite_3.4bpp");
static const ax_sprite sFlag13Sprites3[] = {
	{sFlag13Gfx3, ARRAY_COUNT(sFlag13Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx4[] = INCBIN_U8("graphics/ornament/Flag13/sprite_4.4bpp");
static const ax_sprite sFlag13Sprites4[] = {
	{sFlag13Gfx4, ARRAY_COUNT(sFlag13Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx5[] = INCBIN_U8("graphics/ornament/Flag13/sprite_5.4bpp");
static const ax_sprite sFlag13Sprites5[] = {
	{sFlag13Gfx5, ARRAY_COUNT(sFlag13Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx6[] = INCBIN_U8("graphics/ornament/Flag13/sprite_6.4bpp");
static const ax_sprite sFlag13Sprites6[] = {
	{sFlag13Gfx6, ARRAY_COUNT(sFlag13Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag13[] = {
	sFlag13Pose1,
	sFlag13Pose2,
	sFlag13Pose3,
	sFlag13Pose4,
	sFlag13Pose5,
	sFlag13Pose6,
};

static const ax_anim *const sFlag13AnimTable1[] = {
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag13[] = {
	sFlag13AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag13[] = {
	sFlag13Sprites1,
	sFlag13Sprites2,
	sFlag13Sprites3,
	sFlag13Sprites4,
	sFlag13Sprites5,
	sFlag13Sprites6,
};

static const axmain sAxMainFlag13 = {
	.poses = sAxPosesFlag13,
	.animations = sAxAnimationsFlag13,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag13),
	.spriteData = sAxSpritesFlag13,
	.positions = NULL,
};

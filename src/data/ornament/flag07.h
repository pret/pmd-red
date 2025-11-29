const RGB_Struct gFlag07Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag07.pmdpal") };

static const axmain sAxMainFlag07;
const SiroArchive gAxFlag07 = {"SIRO", &sAxMainFlag07};

static const ax_pose sFlag07Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag07Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag07Gfx1[] = INCBIN_U8("graphics/ornament/Flag07/sprite_1.4bpp");
static const ax_sprite sFlag07Sprites1[] = {
	{sFlag07Gfx1, ARRAY_COUNT(sFlag07Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx2[] = INCBIN_U8("graphics/ornament/Flag07/sprite_2.4bpp");
static const ax_sprite sFlag07Sprites2[] = {
	{sFlag07Gfx2, ARRAY_COUNT(sFlag07Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx3[] = INCBIN_U8("graphics/ornament/Flag07/sprite_3.4bpp");
static const ax_sprite sFlag07Sprites3[] = {
	{sFlag07Gfx3, ARRAY_COUNT(sFlag07Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx4[] = INCBIN_U8("graphics/ornament/Flag07/sprite_4.4bpp");
static const ax_sprite sFlag07Sprites4[] = {
	{sFlag07Gfx4, ARRAY_COUNT(sFlag07Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx5[] = INCBIN_U8("graphics/ornament/Flag07/sprite_5.4bpp");
static const ax_sprite sFlag07Sprites5[] = {
	{sFlag07Gfx5, ARRAY_COUNT(sFlag07Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx6[] = INCBIN_U8("graphics/ornament/Flag07/sprite_6.4bpp");
static const ax_sprite sFlag07Sprites6[] = {
	{sFlag07Gfx6, ARRAY_COUNT(sFlag07Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag07[] = {
	sFlag07Pose1,
	sFlag07Pose2,
	sFlag07Pose3,
	sFlag07Pose4,
	sFlag07Pose5,
	sFlag07Pose6,
};

static const ax_anim *const sFlag07AnimTable1[] = {
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag07[] = {
	sFlag07AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag07[] = {
	sFlag07Sprites1,
	sFlag07Sprites2,
	sFlag07Sprites3,
	sFlag07Sprites4,
	sFlag07Sprites5,
	sFlag07Sprites6,
};

static const axmain sAxMainFlag07 = {
	.poses = sAxPosesFlag07,
	.animations = sAxAnimationsFlag07,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag07),
	.spriteData = sAxSpritesFlag07,
	.positions = NULL,
};

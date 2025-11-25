const RGB_Struct gFlag06Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag06.pmdpal") };

static const axmain sAxMainFlag06;
const SiroArchive gAxFlag06 = {"SIRO", &sAxMainFlag06};

static const ax_pose sFlag06Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag06Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag06Gfx1[] = INCBIN_U8("graphics/ornament/Flag06/sprite_1.4bpp");
static const ax_sprite sFlag06Sprites1[] = {
	{sFlag06Gfx1, ARRAY_COUNT(sFlag06Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx2[] = INCBIN_U8("graphics/ornament/Flag06/sprite_2.4bpp");
static const ax_sprite sFlag06Sprites2[] = {
	{sFlag06Gfx2, ARRAY_COUNT(sFlag06Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx3[] = INCBIN_U8("graphics/ornament/Flag06/sprite_3.4bpp");
static const ax_sprite sFlag06Sprites3[] = {
	{sFlag06Gfx3, ARRAY_COUNT(sFlag06Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx4[] = INCBIN_U8("graphics/ornament/Flag06/sprite_4.4bpp");
static const ax_sprite sFlag06Sprites4[] = {
	{sFlag06Gfx4, ARRAY_COUNT(sFlag06Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx5[] = INCBIN_U8("graphics/ornament/Flag06/sprite_5.4bpp");
static const ax_sprite sFlag06Sprites5[] = {
	{sFlag06Gfx5, ARRAY_COUNT(sFlag06Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx6[] = INCBIN_U8("graphics/ornament/Flag06/sprite_6.4bpp");
static const ax_sprite sFlag06Sprites6[] = {
	{sFlag06Gfx6, ARRAY_COUNT(sFlag06Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag06[] = {
	sFlag06Pose1,
	sFlag06Pose2,
	sFlag06Pose3,
	sFlag06Pose4,
	sFlag06Pose5,
	sFlag06Pose6,
};

static const ax_anim *const sFlag06AnimTable1[] = {
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag06[] = {
	sFlag06AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag06[] = {
	sFlag06Sprites1,
	sFlag06Sprites2,
	sFlag06Sprites3,
	sFlag06Sprites4,
	sFlag06Sprites5,
	sFlag06Sprites6,
};

static const axmain sAxMainFlag06 = {
	.poses = sAxPosesFlag06,
	.animations = sAxAnimationsFlag06,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag06),
	.spriteData = sAxSpritesFlag06,
	.positions = NULL,
};
